/*	$NetBSD: clnt_simple.c,v 1.15 1999/01/20 11:37:35 lukem Exp $	*/

/*
 * Sun RPC is a product of Sun Microsystems, Inc. and is provided for
 * unrestricted use provided that this legend is included on all tape
 * media and as a part of the software program in whole or part.  Users
 * may copy or modify Sun RPC without charge, but are not authorized
 * to license or distribute it to anyone else except as part of a product or
 * program developed by the user.
 * 
 * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE
 * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.
 * 
 * Sun RPC is provided with no support and without any obligation on the
 * part of Sun Microsystems, Inc. to assist in its use, correction,
 * modification or enhancement.
 * 
 * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE
 * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC
 * OR ANY PART THEREOF.
 * 
 * In no event will Sun Microsystems, Inc. be liable for any lost revenue
 * or profits or other special, indirect and consequential damages, even if
 * Sun has been advised of the possibility of such damages.
 * 
 * Sun Microsystems, Inc.
 * 2550 Garcia Avenue
 * Mountain View, California  94043
 */

#include <sys/cdefs.h>
#if defined(LIBC_SCCS) && !defined(lint)
#if 0
static char *sccsid = "@(#)clnt_simple.c 1.35 87/08/11 Copyr 1984 Sun Micro";
static char *sccsid = "@(#)clnt_simple.c	2.2 88/08/01 4.0 RPCSRC";
#else
__RCSID("$NetBSD: clnt_simple.c,v 1.15 1999/01/20 11:37:35 lukem Exp $");
#endif
#endif

/* 
 * clnt_simple.c
 * Simplified front end to rpc.
 *
 * Copyright (C) 1984, Sun Microsystems, Inc.
 */

#include "namespace.h"

#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <rpc/rpc.h>

#ifdef __weak_alias
__weak_alias(callrpc,_callrpc);
#endif

static struct callrpc_private {
	CLIENT	*client;
	int	socket;
	int	oldprognum, oldversnum, valid;
	char	*oldhost;
} *callrpc_private;

int
callrpc(host, prognum, versnum, procnum, inproc, in, outproc, out)
	char *host;
	int prognum, versnum, procnum;
	xdrproc_t inproc, outproc;
	char *in, *out;
{
	struct callrpc_private *crp = callrpc_private;
	struct sockaddr_in server_addr;
	enum clnt_stat clnt_stat;
	struct hostent *hp;
	struct timeval timeout, tottimeout;

	if (crp == 0) {
		crp = (struct callrpc_private *)calloc(1, sizeof (*crp));
		if (crp == 0)
			return (0);
		callrpc_private = crp;
	}
	if (crp->oldhost == NULL) {
		crp->oldhost = malloc(256);
		crp->oldhost[0] = 0;
		crp->socket = RPC_ANYSOCK;
	}
	if (crp->valid && crp->oldprognum == prognum
	    && crp->oldversnum == versnum && strcmp(crp->oldhost, host) == 0) {
		/* reuse old client */		
	} else {
		crp->valid = 0;
		if (crp->socket != -1)
			(void)close(crp->socket);
		crp->socket = RPC_ANYSOCK;
		if (crp->client) {
			clnt_destroy(crp->client);
			crp->client = NULL;
		}
		if ((hp = gethostbyname(host)) == NULL)
			return ((int) RPC_UNKNOWNHOST);
		timeout.tv_usec = 0;
		timeout.tv_sec = 5;
		memset(&server_addr, 0, sizeof(server_addr));
		if (hp->h_length > sizeof(struct sockaddr_in))
			hp->h_length = sizeof(struct sockaddr_in);
		memcpy(&server_addr.sin_addr.s_addr, hp->h_addr,
		    (size_t)hp->h_length);
		setsinlen(&server_addr);
		server_addr.sin_family = AF_INET;
		server_addr.sin_port =  0;
		if ((crp->client = clntudp_create(&server_addr, (u_long)prognum,
		    (u_long)versnum, timeout, &crp->socket)) == NULL)
			return ((int) rpc_createerr.cf_stat);
		crp->valid = 1;
		crp->oldprognum = prognum;
		crp->oldversnum = versnum;
		(void)strncpy(crp->oldhost, host, 256 - 1);
	}
	tottimeout.tv_sec = 25;
	tottimeout.tv_usec = 0;
	clnt_stat = clnt_call(crp->client, (unsigned long)procnum, inproc, in,
	    outproc, out, tottimeout);
	/* 
	 * if call failed, empty cache
	 */
	if (clnt_stat != RPC_SUCCESS)
		crp->valid = 0;
	return ((int) clnt_stat);
}