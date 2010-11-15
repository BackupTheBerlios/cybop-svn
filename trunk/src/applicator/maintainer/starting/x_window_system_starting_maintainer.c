/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: x_window_system_starting_maintainer.c,v $ $Revision: 1.9 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_STARTING_MAINTAINER_SOURCE
#define X_WINDOW_SYSTEM_STARTING_MAINTAINER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/x_window_system_type_size.c"

//
// CAUTION! The x window system uses a number of synonymous types:
// Display* == struct _XDisplay*
// GC == struct _XGC*
// Window == int
// Colormap == int
// Font (ID) == int
//

/**
 * Starts up the x window system.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void maintain_starting_x_window_system(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup x window system.");

    // The display internal.
    struct _XDisplay** di = (struct _XDisplay**) NULL_POINTER_MEMORY_MODEL;

    // Get display internal.
    get((void*) &di, p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // Only create display if not existent.
    if (*di == *NULL_POINTER_MEMORY_MODEL) {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char* dn = (char*) *NULL_POINTER_MEMORY_MODEL;
        // The display, which is a subsumption of
        // xserver, screens, hardware (input devices etc.).
        struct _XDisplay* d = (struct _XDisplay*) *NULL_POINTER_MEMORY_MODEL;
        // The screen number.
        int* sn = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The screen.
//??        Screen* s = (Screen*) *NULL_POINTER_MEMORY_MODEL;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        int* cm = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The background pixel values.
        unsigned long* bg = (unsigned long*) *NULL_POINTER_MEMORY_MODEL;
        // The foreground pixel values.
        unsigned long* fg = (unsigned long*) *NULL_POINTER_MEMORY_MODEL;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        int* r = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The font name.
        char* fn = (char*) *NULL_POINTER_MEMORY_MODEL;
        // The font.
        XFontStruct* f = (XFontStruct*) *NULL_POINTER_MEMORY_MODEL;
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
        struct _XGC* gc_menu = (struct _XGC*) *NULL_POINTER_MEMORY_MODEL;
        // The menu border top graphic context.
        struct _XGC* gc_menu_border_top = (struct _XGC*) *NULL_POINTER_MEMORY_MODEL;
        // The menu border bottom graphic context.
        struct _XGC* gc_menu_border_bottom = (struct _XGC*) *NULL_POINTER_MEMORY_MODEL;
        // The menu font graphic context.
        struct _XGC* gc_menu_font = (struct _XGC*) *NULL_POINTER_MEMORY_MODEL;
        // The window.
        int* w = (int*) *NULL_POINTER_MEMORY_MODEL;
        // The value mask for the graphics context.
        // It defines the attributes for the graphics context.
        // This argument is the bitwise inclusive OR of zero or more
        // of the valid graphic context component mask bits.
        unsigned long* vm = (unsigned long*) *NULL_POINTER_MEMORY_MODEL;
        // The values for the attributes defined in the value mask.
        XGCValues* v = (XGCValues*) *NULL_POINTER_MEMORY_MODEL;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        struct _XGC* gc = (struct _XGC*) *NULL_POINTER_MEMORY_MODEL;

        // Allocate x window system internals.
        allocate((void*) &sn, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &cm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &bg, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &fg, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &r, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &w, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        allocate((void*) &vm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION, (void*) UNSIGNED_LONG_MEMORY_ABSTRACTION_COUNT);
//??        v = (struct XGCValues*) malloc(*XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE);

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

        if (f != *NULL_POINTER_MEMORY_MODEL) {

            fid = f->fid;
        }
*/

        sh.x = *NUMBER_0_INTEGER_MEMORY_MODEL;
        sh.y = *NUMBER_0_INTEGER_MEMORY_MODEL;
        sh.width = *NUMBER_800_INTEGER_MEMORY_MODEL;
        sh.height = *NUMBER_600_INTEGER_MEMORY_MODEL;
        sh.flags = PPosition | PSize;
        *w = XCreateSimpleWindow(d, *r, sh.x, sh.y, sh.width, sh.height, *NUMBER_5_INTEGER_MEMORY_MODEL, *fg, *bg);
        *vm = *NUMBER_0_INTEGER_MEMORY_MODEL;
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
        gc_menu = XCreateGC(d, *w, *NUMBER_0_INTEGER_MEMORY_MODEL, *NUMBER_0_INTEGER_MEMORY_MODEL);
        gc_menu_border_top = XCreateGC(d, *w, *NUMBER_0_INTEGER_MEMORY_MODEL, *NUMBER_0_INTEGER_MEMORY_MODEL);
        gc_menu_border_bottom = XCreateGC(d, *w, *NUMBER_0_INTEGER_MEMORY_MODEL, *NUMBER_0_INTEGER_MEMORY_MODEL);
        gc_menu_font = XCreateGC(d, *w, *NUMBER_0_INTEGER_MEMORY_MODEL, *NUMBER_0_INTEGER_MEMORY_MODEL);
*/

        // Assign x window system internals.
        XSetStandardProperties(d, *w, "Application", "Icon", None, *NULL_POINTER_MEMORY_MODEL, *NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &sh);
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
        set_array_elements(p0, (void*) &dn, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &d, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &sn, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
//??        set_array_elements(p0, (void*) &s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &cm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &bg, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &fg, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &r, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &gc_menu_border_bottom, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &w, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &vm, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &v, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array_elements(p0, (void*) &gc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not startup x window system. The x window system is already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* X_WINDOW_SYSTEM_STARTING_MAINTAINER_SOURCE */
#endif
