/*
 * $RCSfile: receive_x_window_system.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2005-11-28 22:55:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef RECEIVE_X_WINDOW_SYSTEM_SOURCE
#define RECEIVE_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include <pthread.h>
//?? #include "../../creator/integer_allocator.c"
//?? #include "../../creator/unsigned_long_allocator.c"
#include "../../globals/constants/abstraction_constants.c"
//?? #include "../../globals/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Receives x window system messages (events) in an own thread.
 *
 * @param p0 the internals memory
 */
void receive_x_window_system_thread(void* p0) {

    // The signal memory.
    void** s = (void**) &NULL_POINTER;
    void** sc = (void**) &NULL_POINTER;
    void** ss = (void**) &NULL_POINTER;
    // The x window system model reference internal.
    void** m = (void**) &NULL_POINTER;
    void** mc = (void**) &NULL_POINTER;
    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = (struct _XDisplay**) &NULL_POINTER;
    // The menu border bottom graphic context.
    struct _XGC** gc_menu_border_bottom = (struct _XGC**) &NULL_POINTER;
    // The window.
    int** w = (int**) &NULL_POINTER;
    // The graphic context. Each graphic element needs one.
    // It can be used with any destination drawable (window or pixmap)
    // having the same root and depth as the specified drawable.
    // Use with other drawables results in a BadMatch error.
    struct _XGC** gc = (struct _XGC**) &NULL_POINTER;

    // Get signal memory internals.
    get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system model reference internal.
    get(p0, (void*) X_WINDOW_SYSTEM_MODEL_REFERENCE_INTERNAL, (void*) &m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_MODEL_REFERENCE_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system internals.
    get(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_MENU_BORDER_BOTTOM_GC_INTERNAL, (void*) &gc_menu_border_bottom, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL, (void*) &w, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // The event.
    XEvent e;
    // The event type.
    int t;
    // The activation flag.
    int** f = (int**) &NULL_POINTER;

    while (1) {

    fprintf(stderr, "TEST receive 2: %i\n", t);

/*??
        // Get activation flag.
        get(p0, (void*) X_WINDOW_SYSTEM_ACTIVE_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if (**f == *NUMBER_1_INTEGER) {

            break;
        }
*/

    fprintf(stderr, "TEST receive 3: %i\n", t);

        // Get next event.
        // The XNextEvent function copies the first event from the event queue
        // into the specified XEvent structure and then removes it from the queue.
        // If the event queue is empty, XNextEvent flushes the output buffer
        // and blocks until an event is received.
        XNextEvent(*d, &e);

        // Assign event type.
        t = e.type;

        if (t == Expose) {

            // Repaint window after expose.
            // With multiple expose events, only the last one is considered.
            if (e.xexpose.count == 0) {

/*??
                //?? Add one more "destroy flag" to signals in signal memory!
                //?? Destroy all signals in signal_checker, whose destroy flag is set.
                //?? Mouse move events, for example, create MANY signals
                //?? which have to be destroyed somewhere.

                // The signal model, details.
                void* sm = NULL_POINTER;
                int* smc = NULL_POINTER;
                int* sms = NULL_POINTER;
                void* sd = NULL_POINTER;
                int* sdc = NULL_POINTER;
                int* sds = NULL_POINTER;

                // Allocate signal model, details.
                allocate((void*) &smc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                allocate((void*) &sms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                allocate((void*) &sdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                allocate((void*) &sds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                // Initialise signal model, details.
                *smc = 0;
                *sms = 0;
                *sdc = 0;
                *sds = 0;

                // Create signal model, details.
                create((void*) &sm, (void*) smc, (void*) sms,
                    p0, p1,
                    CYBOL_ABSTRACTION, CYBOL_ABSTRACTION_COUNT,
                    FILE_CHANNEL, FILE_CHANNEL_COUNT);
                create((void*) &sd, (void*) sdc, (void*) sds,
                    (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT,
                    (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                    (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

                // The signal id.
                int* id = NULL_POINTER;
                allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *id = 0;
                get_new_signal_id(s, (void*) sc, (void*) id);

                //?? A signal model needs to be created here, as send operation!
                //?? The actual knowledge model (gui) must be handed over in details,
                //?? as operation parameter!

                // Add send signal to signal memory.
                set_signal(*s, *sc, *ss, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, *m, *mc, NULL_POINTER, NULL_POINTER, (void*) NORMAL_PRIORITY, (void*) id);
*/
            }

        } else if (t == MappingNotify) {

            // Process mapping changes of keyboard.
//??            XRefreshKeyboardMapping(&e);

        } else if (t == ButtonPress) {

            // Process mouse button press.

/*??
            //struct XButtonEvent event;
            //event = e.xbutton.window;
            //if ()
            //event = e.xbutton.x;
            //printf("%d", event);
            //XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, 100, 100, event.xbutton.x, strlen(event.xbutton.x));
            //printf("%s", event.xbutton.x);

            if ((e.xbutton.x<30) && (e.xbutton.x>3) && (e.xbutton.y<21) && (e.xbutton.x>1)) {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if ((e.xbutton.x<65) && (e.xbutton.x>38) && (e.xbutton.y<21) && (e.xbutton.x>1)) {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if ((e.xbutton.x<120) && (e.xbutton.x>70) && (e.xbutton.y<21) && (e.xbutton.x>1)) {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;

            } else {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
            }
*/

        } else if (t == KeyPress) {

            // Process keyboard press.

/*??
            i = XLookupString(&e, text, 10, &k, 0);

            //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
            //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte

            if (i == 1 && text[0] == 'a') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'b') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'c') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;
            }

            if (i == 1 && text[0] == 'x') {

                XClearArea (d, w, 0, 0, 0, 0, True);

                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'q') {

                f = 1;
            }
*/
        }

//??    Check in xlibs!!
//??    XQueryPointer(display, w, root_return, child_return, root_x_return, root_y_return, win_x_return, win_y_return, mask_return);

/*??
    KeySym k;
    char text[10];
    char str_test[1000];
    char str_zugriff[1000];
    char str_menubar[100];
    //??unsigned long //??double menu_foreground;
    // The temporary variables.
//??    int k;
    int menu_eintrage_ende;
    int window;
    int i = 0, count_menu, count_item, indent_x, indent_y, indent_menu_item_x;
*/
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
}

/**
 * Receives x window system messages.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void receive_x_window_system(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Receive x window system message.");

    // The thread.
    pthread_t t;

    // Create thread.
    pthread_create(&t, (pthread_attr_t*) NULL_POINTER, (void*) &receive_x_window_system_thread, p0);
}

/* RECEIVE_X_WINDOW_SYSTEM_SOURCE */
#endif
