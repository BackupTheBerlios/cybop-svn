/*
 * $RCSfile: x_window_system_translator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.7 $ $Date: 2005-10-07 13:13:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_TRANSLATOR_SOURCE
#define X_WINDOW_SYSTEM_TRANSLATOR_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Decodes the x window system model into a compound model.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory containing all x window system windows
 * @param p4 the source count
 */
void decode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the compound model into an x window system model.
 *
 * @param p0 the internal memory containing all x window system windows
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void encode_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Encode compound into x window system window.");

/*??
        // The source part abstraction, model, details.
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        void** m = &NULL_POINTER;
        // CAUTION! This must be int** because its value is used below.
        int** mc = (int**) &NULL_POINTER;
        void** ms = &NULL_POINTER;
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;
*/

        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay** d = (struct _XDisplay**) &NULL_POINTER;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int** cm = (int**) &NULL_POINTER;
        // The background pixel values.
        unsigned long** bg = (unsigned long**) &NULL_POINTER;
        // The foreground pixel values.
        unsigned long** fg = (unsigned long**) &NULL_POINTER;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int** r = (int**) &NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC** gc = (struct _XGC**) &NULL_POINTER;
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

        // Get x window system internals.
        get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Create x window system internals.
        allocate((void*) &w, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST 0 translator window: %i\n", *w);

        // Initialise x window system internals.
        sh.x = 100;
        sh.y = 100;
        sh.width = 400;
        sh.height = 300;
        sh.flags = PPosition | PSize;
        *w = XCreateSimpleWindow(*d, **r, sh.x, sh.y, sh.width, sh.height, 5, **fg, **bg);
        XSetStandardProperties(*d, *w, "Application", "Icon", None, NULL_POINTER, 0, (void*) &sh);
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
        XAllocColor(*d, **cm, &gray);
        XAllocColor(*d, **cm, &light_gray);
        XAllocColor(*d, **cm, &vlight_gray);
        XAllocColor(*d, **cm, &dark_gray);
        gc_menu = XCreateGC(*d, *w, 0, 0);
        gc_menu_border_top = XCreateGC(*d, *w, 0, 0);
        gc_menu_border_bottom = XCreateGC(*d, *w, 0, 0);
        gc_menu_font = XCreateGC(*d, *w, 0, 0);
        XSetBackground(*d, gc_menu, **bg);
        XSetForeground(*d, gc_menu, light_gray.pixel);
        XSetBackground(*d, gc_menu_border_top, **bg);
        XSetForeground(*d, gc_menu_border_top, vlight_gray.pixel);
        XSetBackground(*d, gc_menu_border_bottom, **bg);
        XSetForeground(*d, gc_menu_border_bottom, dark_gray.pixel);
        XSetBackground(*d, gc_menu_font, light_gray.pixel);
        XSetForeground(*d, gc_menu_font, **fg);

    fprintf(stderr, "TEST 1 translator window: %i\n", *w);

        // Set x window system internals.
        set(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        set(p0, (void*) X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL, (void*) &gc_menu_border_bottom, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("Could not encode x window system. The source count is null.");
    }
}

/* X_WINDOW_SYSTEM_TRANSLATOR_SOURCE */
#endif
