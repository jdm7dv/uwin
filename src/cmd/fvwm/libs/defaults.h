/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307	 USA
 */

/* File: defaults.h
 *
 * Description:
 *	#defines for default values shall go into this file as well as tunable
 *	parameters.
 *
 * Created:
 *	 23 Dec 1998 - Dominik Vogt <dominik_vogt@hp.com>
 */

#ifndef _DEFAULTS_
#define _DEFAULTS_

/*** event handling ***/
#define CLOCK_SKEW_MS		       30000 /* ms */


/*** grabbing the pointer ***/
#define NUMBER_OF_GRAB_ATTEMPTS          100
#define TIME_BETWEEN_GRAB_ATTEMPTS        10 /* ms */

/*** bindings and mouse buttons ***/
/* Fvwm needs at least 3 buttons. X currently supports up to 5 buttons, so you
 * can use 3, 4 or 5 here. */
#define NUMBER_OF_MOUSE_BUTTONS		   5
#define DEFAULT_ALL_BUTTONS_MASK	   \
((Button1Mask * (NUMBER_OF_MOUSE_BUTTONS >= 1)) | \
 (Button2Mask * (NUMBER_OF_MOUSE_BUTTONS >= 2)) | \
 (Button3Mask * (NUMBER_OF_MOUSE_BUTTONS >= 3)) | \
 (Button4Mask * (NUMBER_OF_MOUSE_BUTTONS >= 4)) | \
 (Button5Mask * (NUMBER_OF_MOUSE_BUTTONS >= 5)))
#define DEFAULT_ALL_BUTTONS_MOTION_MASK	   \
((Button1MotionMask * (NUMBER_OF_MOUSE_BUTTONS >= 1)) | \
 (Button2MotionMask * (NUMBER_OF_MOUSE_BUTTONS >= 2)) | \
 (Button3MotionMask * (NUMBER_OF_MOUSE_BUTTONS >= 3)) | \
 (Button4MotionMask * (NUMBER_OF_MOUSE_BUTTONS >= 4)) | \
 (Button5MotionMask * (NUMBER_OF_MOUSE_BUTTONS >= 5)))


/***************************************************************
 * These values may be adjusted to fine tune the menu looks.
 ***************************************************************/
/* The first option of the default menu style must be fvwm/win/mwm/....
 * fvwm may crash if not. */
#define DEFAULT_MENU_STYLE               \
 "MenuStyle * fvwm, Foreground black, Background grey, Greyed slategrey, " \
 "MenuColorset, ActiveColorset, GreyedColorset"
#define DEFAULT_CLICKTIME		 150 /* ms */
#define DEFAULT_POPUP_DELAY		  15 /* ms*10 */
#define DEFAULT_POPDOWN_DELAY		  15 /* ms*10 */
#define DEFAULT_MENU_CLICKTIME		   (3*DEFAULT_CLICKTIME)
#define DEFAULT_MOVE_THRESHOLD		   3 /* pixels */
#define MAX_MENU_COPIES			  10 /* menu copies */
#define MAX_MENU_ITEM_LABELS		   3 /* labels (max. 15) */
#define MAX_MENU_ITEM_MINI_ICONS	   2 /* mini icons (max. 15) */
#define DEFAULT_MENU_BORDER_WIDTH	   2 /* pixels */
#define MAX_MENU_BORDER_WIDTH		  50 /* pixels */
#define MAX_MENU_ITEM_RELIEF_THICKNESS	  50 /* pixels */
#define PARENT_MENU_FORCE_VISIBLE_WIDTH	  20 /* pixels */
#define MENU_POPUP_NOW_RATIO		0.75 /* % of item width */
/*   default item formats for left and right submenus. */
#define DEFAULT_MENU_ITEM_FORMAT	  "%s%.1|%.5i%.5l%.5l%.5r%.5i%2.3>%1|"
#define DEFAULT_LEFT_MENU_ITEM_FORMAT	  "%.1|%3.2<%5i%5l%5l%5r%5i%1|%s"
/*   size of the submenu triangle. */
#define MENU_TRIANGLE_WIDTH		   5 /* pixels */
#define MENU_TRIANGLE_HEIGHT		   9 /* pixels */
/*  menu underline parameters */
#define MENU_UNDERLINE_THICKNESS	   1 /* pixels */
#define MENU_UNDERLINE_GAP		   1 /* pixels */
#define MENU_UNDERLINE_HEIGHT  (MENU_UNDERLINE_THICKNESS + MENU_UNDERLINE_GAP)
/*   menu separator parameters */
#define MENU_SEPARATOR_SHORT_X_OFFSET	   5 /* pixels */
#define MENU_SEPARATOR_Y_OFFSET		   2 /* pixels */
#define MENU_SEPARATOR_HEIGHT		   2 /* pixels */
#define MENU_SEPARATOR_TOTAL_HEIGHT    \
	  (MENU_SEPARATOR_HEIGHT + MENU_SEPARATOR_Y_OFFSET)
/*   gap above item text */
#define DEFAULT_MENU_ITEM_TEXT_Y_OFFSET	   1 /* pixels */
/*   gap below item text */
#define DEFAULT_MENU_ITEM_TEXT_Y_OFFSET2   2 /* pixels */
/*   same for titles */
#define DEFAULT_MENU_TITLE_TEXT_Y_OFFSET   (DEFAULT_MENU_ITEM_TEXT_Y_OFFSET)
#define DEFAULT_MENU_TITLE_TEXT_Y_OFFSET2  (DEFAULT_MENU_ITEM_TEXT_Y_OFFSET2)
/* minimum for above value */
#define MIN_VERTICAL_SPACING            -100 /* pixels */
/* maximum for above value */
#define MAX_VERTICAL_SPACING             100 /* pixels */
/* width of a tab in the item format of a menu */
#define MENU_TAB_WIDTH                     8 /* spaces */
/* This is the tile width or height for V and H gradients. I guess this should
 * better be a power of two. A value of 5 definitely causes XFree 3.3.3.1 to
 * screw up the V_GRADIENT on an 8 bit display, but 4, 6, 7 etc. work well. */
#define DEFAULT_MENU_GRADIENT_PIXMAP_THICKNESS 4


/*** colours ***/
#define DEFAULT_FORE_COLOR                "black"
#define DEFAULT_BACK_COLOR                "gray"
#define DEFAULT_HILIGHT_COLOR             "white"
#define DEFAULT_SHADOW_COLOR              "black"
#define DEFAULT_CURSOR_FORE_COLOR         "black"
#define DEFAULT_CURSOR_BACK_COLOR         "white"

/*** pager ***/
#define DEFAULT_MOVE_THRESHOLD		   3 /* pixels */
#define DEFAULT_PAGER_WINDOW_BORDER_WIDTH  1 /* pixels */

/*** fonts ***/
#define EXTRA_TITLE_FONT_HEIGHT		   3 /* pixels */
#define MIN_FONT_HEIGHT			   (EXTRA_TITLE_FONT_HEIGHT + 2)
#define MAX_FONT_HEIGHT			 256 /* pixels */

/*** window geometry ***/
#define DEFAULT_MIN_MAX_WINDOW_WIDTH	 100 /* pixels */
#define DEFAULT_MIN_MAX_WINDOW_HEIGHT	 100 /* pixels */
#define DEFAULT_MAX_MAX_WINDOW_WIDTH   32767 /* pixels */
#define DEFAULT_MAX_MAX_WINDOW_HEIGHT  32767 /* pixels */
/* this value is used in a bugfix */
#define WINDOW_FREAKED_OUT_HEIGHT      65500 /* pixels */

/* geometry window */
#define GEOMETRY_WINDOW_BW                 2 /* pixels */
#define GEOMETRY_WINDOW_STRING             " +8888 x +8888 "
#define GEOMETRY_WINDOW_POS_STRING         " %+-4d %+-4d "
#define GEOMETRY_WINDOW_SIZE_STRING        " %4d x %-4d "

/*
 * window title layout
 */
/* height of stick lines */
#define WINDOW_TITLE_STICK_HEIGHT     1 /* pixels */
/* vertical distance between stick lines */
#define WINDOW_TITLE_STICK_VERT_DIST  4 /* pixels */
/* minimum width of stick lines */
#define WINDOW_TITLE_STICK_MIN_WIDTH  1 /* pixels */
/* gap between border of title window and stick lines */
#define WINDOW_TITLE_STICK_OFFSET     4 /* pixels */
/* gap between title and stick lines */
#define WINDOW_TITLE_TO_STICK_GAP     4 /* pixels */
/* gap between border of title window and text */
#define WINDOW_TITLE_TEXT_OFFSET     10 /* pixels */

/*** window placement (MinOverlap(Percent)Placement) ***/

/* The following factors represent the amount of area that these types of
 * windows are counted as.  For example, by default the area of ONTOP windows
 * is counted 5 times as much as normal windows.  So CleverPlacement will
 * cover 5 times as much area of another window before it will cover an ONTOP
 * window.  To treat ONTOP windows the same as other windows, set this to 1.
 * To really, really avoid putting windows under ONTOP windows, set this to a
 * high value, say 1000.  A value of 5 will try to avoid ONTOP windows if
 * practical, but if it saves a reasonable amount of area elsewhere, it will
 * place one there.  The same rules apply for the other "AVOID" factors. */
/* With the advent of layers, the meaning of ONTOP in the following
   explanation has changed to mean any window in a higher layer. */
#define PLACEMENT_AVOID_BELOW		   0.05
#define PLACEMENT_AVOID_STICKY		   1.0
#define PLACEMENT_AVOID_ONTOP		   5
#define PLACEMENT_AVOID_ICON              10
/* used in MinOverlapPercentPlacement to forbid complete covering (99%, 95%
   85% and 75%) of windows */
#define PLACEMENT_AVOID_COVER_99          12
#define PLACEMENT_AVOID_COVER_95           6
#define PLACEMENT_AVOID_COVER_85           4
#define PLACEMENT_AVOID_COVER_75           1

/*** general keyboard shortcuts used in move, resize, ... ***/
#define DEFAULT_KDB_SHORTCUT_MOVE_DISTANCE 5 /* pixels */
#define KDB_SHORTCUT_MOVE_DISTANCE_SMALL   1 /* pixels */
#define KDB_SHORTCUT_MOVE_DISTANCE_BIG	 100 /* pixels */


/*** movement ***/
#define DEFAULT_OPAQUE_MOVE_SIZE	   5 /* percent of window area */
#define DEFAULT_SNAP_ATTRACTION		   0
#define DEFAULT_SNAP_ATTRACTION_MODE	 0x3
#define DEFAULT_SNAP_GRID_X		   1 /* pixels */
#define DEFAULT_SNAP_GRID_Y		   1 /* pixels */


/*** paging ***/
#define DEFAULT_EDGE_SCROLL		 100 /* % of screen width/height */
/* Don't page if the pointer has moved for more than this many pixels between
 * two samples */
#define MAX_PAGING_MOVE_DISTANCE	   5 /* pixels */
#define DEFAULT_MOVE_RESISTANCE		   0 /* ms */
#define DEFAULT_XIMOVE_RESISTANCE	   0 /* pixels */
#define DEFAULT_SCROLL_RESISTANCE	   0 /* ms */


/*** layers ***/
#define DEFAULT_BOTTOM_LAYER		   2
#define DEFAULT_DEFAULT_LAYER		   4
#define DEFAULT_TOP_LAYER		   6
#define DEFAULT_ROOT_WINDOW_LAYER	  -1


/*** decorations ***/
#define NR_LEFT_BUTTONS			   5
#define NR_RIGHT_BUTTONS		   5
#define NUMBER_OF_BUTTONS		   (NR_LEFT_BUTTONS + NR_RIGHT_BUTTONS)


/*** window borders ***/
#define DEFAULT_BORDER_WIDTH		   1 /* pixels */
#define DEFAULT_HANDLE_WIDTH		   7 /* pixels */
#define MAX_BORDER_WIDTH		 500 /* pixels */
#define MAX_HANDLE_WIDTH		   (MAX_BORDER_WIDTH)


/*** module configuration ***/
#define DEFAULT_MODULE_TIMEOUT		  30 /* seconds */


/*** misc ***/
#define DEFAULT_EMULATE_MWM	       False
#define DEFAULT_EMULATE_WIN	       False

#define DEFAULT_USE_ACTIVE_DOWN_BUTTONS True
#define DEFAULT_USE_INACTIVE_BUTTONS	True

/*** Gradients ***/
#define MAX_GRADIENT_SEGMENTS		1000
#define MAX_GRADIENT_COLORS	       10000

/*** Xinerama ***/
#define DEFAULT_XINERAMA_ENABLED        True /* Xinerama on by default */
#define XINERAMA_CONFIG_STRING             "XineramaConfig"
/* Replace with -1 to switch off "primary screen" concept by default */
#define DEFAULT_PRIMARY_SCREEN             0

/*** Very long window names (600000 characters or more) seem to hang the X
 *** server. ***/
#define MAX_WINDOW_NAME_LEN		 200 /* characters */
#define MAX_ICON_NAME_LEN		 200 /* characters */
/* not tested if this hangs the server too */
#define MAX_RESOURCE_LEN   		 200 /* characters */
#define MAX_CLASS_LEN    		 200 /* characters */

#endif /* _DEFAULTS_ */
