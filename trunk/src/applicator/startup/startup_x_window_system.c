/*
 * $RCSfile: startup_x_window_system.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.18 $ $Date: 2007-01-14 22:06:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 *
 * A session (display) manager shows a graphical user login,
 * in which it offers a list of window managers to chose from.
 *
 * A window manager cares about all windows displayed on a screen.
 * This includes the resizing, moving, stacking or tiling of windows.
 *
 * CYBOI aims to become both at the same time,
 * a session- (display-) as well as a window manager.
 *
 * CAUTION! The x window system uses a number of synonymous types:
 * Display* == struct _XDisplay*
 * GC == struct _XGC*
 * Window == int
 * Colormap == int
 * Font (ID) == int
 */

#ifndef STARTUP_X_WINDOW_SYSTEM_SOURCE
#define STARTUP_X_WINDOW_SYSTEM_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Starts up the x window system.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_x_window_system(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Startup x window system.");

    // The display internal.
    struct _XDisplay** di = (struct _XDisplay**) &NULL_POINTER;

    // Get display internal.
    get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &di, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Only create display if not existent.
    if (*di == NULL_POINTER) {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char* dn = NULL_POINTER;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay* d = NULL_POINTER;
        // The screen number.
        int* sn = NULL_POINTER;
        // The screen.
//??        Screen* s = NULL_POINTER;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int* cm = NULL_POINTER;
        // The background pixel values.
        unsigned long* bg = NULL_POINTER;
        // The foreground pixel values.
        unsigned long* fg = NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int* r = NULL_POINTER;
        // The font name.
        char* fn = NULL_POINTER;
        // The font.
        XFontStruct* f = NULL_POINTER;
        // The font id.
//??        int fid = -1;
        // The size hint.
        XSizeHints sh;
        // The colours.
        XColor gray;
        XColor light_gray;
        XColor vlight_gray;
        XColor dark_gray;
        // The menu graphic context.
        struct _XGC* gc_menu = NULL_POINTER;
        // The menu border top graphic context.
        struct _XGC* gc_menu_border_top = NULL_POINTER;
        // The menu border bottom graphic context.
        struct _XGC* gc_menu_border_bottom = NULL_POINTER;
        // The menu font graphic context.
        struct _XGC* gc_menu_font = NULL_POINTER;
        // The window.
        int* w = NULL_POINTER;
        // The value mask for the graphics context.
        // It defines the attributes for the graphics context.
        // This argument is the bitwise inclusive OR of zero or more
        // of the valid graphic context component mask bits.
        unsigned long* vm = NULL_POINTER;
        // The values for the attributes defined in the value mask.
        XGCValues* v = NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC* gc = NULL_POINTER;

        // Allocate x window system internals.
        allocate((void*) &sn, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &cm, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &bg, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &fg, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &r, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &w, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        allocate((void*) &vm, (void*) PRIMITIVE_COUNT, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT);
//??        v = (struct XGCValues*) malloc(sizeof(struct XGCValues));

        // Initialise x window system internals.
        dn = "";
        d = XOpenDisplay(dn);
        *sn = DefaultScreen(d);
//??        s = XScreenOfDisplay(*d, *sn);
        *cm = XDefaultColormap(d, *sn);
        *bg = XWhitePixel(d, *sn);
        *fg = XBlackPixel(d, *sn);
        *r = DefaultRootWindow(d);
//??        *r = XRootWindowOfScreen(s);
/*??
        fn = "*-helvetica-*-12-*";
        f = XLoadQueryFont(d, fn);

        if (f != NULL_POINTER) {

            fid = f->fid;
        }
*/

        sh.x = 0;
        sh.y = 0;
        sh.width = 800;
        sh.height = 600;
        sh.flags = PPosition | PSize;
        *w = XCreateSimpleWindow(d, *r, sh.x, sh.y, sh.width, sh.height, 5, *fg, *bg);
        *vm = 0;
//??        *vm = GCCapStyle | GCJoinStyle;
//??        *v = CapButt | JoinBevel;
        gc = XCreateGC(d, *w, *vm, v);
        gray.red = 49125;
        gray.green = 49125;
        gray.blue = 49125;
        light_gray.red = 56000;
        light_gray.green = 58000;
        light_gray.blue = 60000;
        vlight_gray.red = 60000;
        vlight_gray.green = 61000;
        vlight_gray.blue = 62000;
        dark_gray.red = 32768;
        dark_gray.green = 32768;
        dark_gray.blue = 32768;
/*??
        gc_menu = XCreateGC(d, *w, 0, 0);
        gc_menu_border_top = XCreateGC(d, *w, 0, 0);
        gc_menu_border_bottom = XCreateGC(d, *w, 0, 0);
        gc_menu_font = XCreateGC(d, *w, 0, 0);
*/

        // Assign x window system internals.
        XSetStandardProperties(d, *w, "Application", "Icon", None, NULL_POINTER, 0, (void*) &sh);
        XAllocColor(d, *cm, &gray);
        XAllocColor(d, *cm, &light_gray);
        XAllocColor(d, *cm, &vlight_gray);
        XAllocColor(d, *cm, &dark_gray);
/*??
        XSetBackground(d, gc_menu, *bg);
        XSetForeground(d, gc_menu, light_gray.pixel);
        XSetBackground(d, gc_menu_border_top, *bg);
        XSetForeground(d, gc_menu_border_top, vlight_gray.pixel);
        XSetBackground(d, gc_menu_border_bottom, *bg);
        XSetForeground(d, gc_menu_border_bottom, dark_gray.pixel);
        XSetBackground(d, gc_menu_font, light_gray.pixel);
        XSetForeground(d, gc_menu_font, *fg);
*/
        XSetBackground(d, gc, *bg);
        XSetForeground(d, gc, *fg);
//??        XSetFont(d, gc, fid);

        // Set x window system internals.
        set(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
//??        set(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL, (void*) &gc_menu_border_bottom, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("WARNING: Could not startup x window system. The x window system is already running.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* STARTUP_X_WINDOW_SYSTEM_SOURCE */
#endif
