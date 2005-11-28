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
 * @version $Revision: 1.5 $ $Date: 2005-11-28 13:42:53 $ $Author: christian $
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

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    struct _XDisplay** d = (struct _XDisplay**) &NULL_POINTER;
    // The menu border bottom graphic context.
    struct _XGC** gc_menu_border_bottom = NULL_POINTER;
    // The window.
    int** w = NULL_POINTER;
    // The graphic context. Each graphic element needs one.
    // It can be used with any destination drawable (window or pixmap)
    // having the same root and depth as the specified drawable.
    // Use with other drawables results in a BadMatch error.
    struct _XGC** gc = (struct _XGC**) &NULL_POINTER;

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

    fprintf(stderr, "TEST receive 4 type: %i\n", t);

        if (t == Expose) {

    fprintf(stderr, "TEST receive 5 expose: %i\n", t);

            // Repaint window after expose.
            // With multiple expose events, only the last one is considered.
            if (e.xexpose.count == 0) {

                // The window attributes.
                XWindowAttributes wa;

                // Draw window.
                XGetWindowAttributes(*d, **w, &wa);
                //XDrawImageString(e.xexpose.display, e.xexpose.window, gc, 50, 50, "hello", strlen("hello"));
                //XRectangle(e.xexpose.display, e.xexpose.window, gc_menu, 2, 2, (wa.width-4), 30);

                // Draw menu bar.
                XDrawLine(*d, **w, *gc_menu_border_bottom, 0, 21, wa.width, 21);
                XDrawLine(*d, **w, *gc_menu_border_bottom, (wa.width-1), 1, (wa.width-1), 21);
                XFillRectangle(*d, **w, *gc, 2, 2, 100, 30);
//??                XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, 1, 1, (wa.width-2), 20);

/*??
                /// Menueintraege zeichen
                //k=1;
                //while (menu_eintrage_ende==0) {
                    //str_test= Anwendung.menu_bar1.menu1.name; //+ IntToStr(k);
    //            char str_test[20];
                    //strcpy(str_test,"fick dich");
                    //strcpy(str_menubar,"menubar");
                    //strcat(str_menubar,"1");
                    //dort = &str_menubar;
                    //strcpy(str_test, Anwendung.*dort.menu1.menu_item1.name);
                    //,".menu1.name";
                    //printf("%s",dort);
                    //Anwendung.menu_bar1.Datei.menu_item1.name
                    //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.Datei.name, strlen(Anwendung.menu_bar1.Datei.name));
                    //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, str_test, strlen(str_test));
                    //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.menu1.name, strlen(Anwendung.menu_bar1.menu1.name));
                //}
                indent_x = 0;
                indent_y = 0;
                indent_menu_item_x = 0;

                for (count_menu=0;count_menu<5;count_menu++) {

                    if (strlen(Anwendung.menu_bar1.menus[count_menu].name)>0) {

                        XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, strlen(Anwendung.menu_bar1.menus[count_menu].name));

                        for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {
                            if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                            indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                            }
                        }

                        for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {

                            if (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)>0) {

                                indent_y = indent_y + 17;
                                //if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                //  XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                                //  indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                //
                                //}
                                //XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);
                                XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (3+indent_x), 20 + (count_item*17), indent_menu_item_x, 19);
                                XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 33 + (count_item*17), Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name, strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                            }
                        }

                        if (Anwendung.menu_bar1.menus[count_menu].angeklickt==1) {

                            XDrawLine (d, w, gc_menu_border_bottom, (3+indent_x), (21+indent_y), (3+indent_x+indent_menu_item_x), (21+indent_y));
                            XDrawLine (d, w, gc_menu_border_bottom, (3+indent_x+indent_menu_item_x), 20, (3+indent_x+indent_menu_item_x), (21+indent_y));
                            XDrawLine (d, w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x+indent_menu_item_x), 19);
                            XDrawLine (d, w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x), (20+indent_y));
                        }

                        indent_x = indent_x + (strlen(Anwendung.menu_bar1.menus[count_menu].name) * 6) +10;
                    }
                }
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
