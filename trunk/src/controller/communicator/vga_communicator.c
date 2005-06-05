/*
 * $RCSfile: vga_communicator.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-06-05 00:08:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VGA_COMMUNICATOR_SOURCE
#define VGA_COMMUNICATOR_SOURCE

/**
 * Receives an expose x windows input.
 *
 * An expose leads to repainting the window.
 *
 * @param p0 the signal memory
 * @param p1 the internal x windows data
 * @param p2 the event
 */
void receive_expose_x_windows(void* p0, void* p1, void* p2) {

/*??
    struct x_windows* x = (struct x_windows*) p1;

    if (x != NULL_POINTER) {

        XEvent* e = (XEvent*) p2;

        if (e != NULL_POINTER) {

            XExposeEvent* exp = (XExposeEvent*) &(e->xexpose);

            if (exp != NULL_POINTER) {

                // Consider only last of many expose events; ignore those with nonzero counts.
                // Do not distinguish between window subareas and perform full redisplay.
                if (exp->count == 0) {

                    XGetWindowAttributes(x->display, x->window, &(x->window_attributes));
                    //XDrawImageString (exp->display, exp->window, x->gc, 50, 50, "hello", strlen("hello"));
                    //XRectangle (exp->display, exp->window, gc_menu, 2, 2, (window_attributes.width-4), 30);

                    // Draw menu bar.
                    XDrawLine(x->display, x->window, x->gc_menu_border_bottom, 0, 21, x->window_attributes.width, 21);
                    XDrawLine(x->display, x->window, x->gc_menu_border_bottom, (x->window_attributes.width - 1), 1, (x->window_attributes.width - 1), 21);
                    XFillRectangle(exp->display, exp->window, x->gc_menu, 1, 1, (x->window_attributes.width - 2), 20);

                    // Draw menu items.
                    int indent_x = 0;
                    int indent_y = 0;
                    int indent_menu_item_x = 0;
                    int count_menu;
                    int count_item;

                    for (count_menu = 0; count_menu < 5; count_menu++) {

                        if (strlen(Anwendung.menu_bar1.menus[count_menu].name) > 0) {

                            XDrawImageString(exp->display, exp->window, x->gc_menu_font, (5 + indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, strlen(Anwendung.menu_bar1.menus[count_menu].name));

                            for (count_item = 0; ((count_item < 9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt == 1)); count_item++) {

                                if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name) * 6) + 6 > indent_menu_item_x) {

                                    indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name) * 6) + 6;
                                }
                            }

                            for (count_item = 0; ((count_item < 9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt == 1)); count_item++) {

                                if (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name) > 0) {

                                    indent_y = indent_y + 17;

                                    //if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                    //  XFillRectangle (exp->display, exp->window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                                    //  indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                    //
                                    //}
                                    //XFillRectangle (exp->display, exp->window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);

                                    XFillRectangle(
                                        exp->display,
                                        exp->window,
                                        x->gc_menu,
                                        3 + indent_x,
                                        20 + (count_item * 17),
                                        indent_menu_item_x,
                                        19);

                                    XDrawImageString(
                                        exp->display,
                                        exp->window,
                                        x->gc_menu_font,
                                        5 + indent_x,
                                        33 + (count_item * 17),
                                        Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name,
                                        strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                                }

                            }

                            if (Anwendung.menu_bar1.menus[count_menu].angeklickt == 1) {

                                XDrawLine(x->display, x->window, x->gc_menu_border_bottom, (3 + indent_x), (21 + indent_y), (3 + indent_x + indent_menu_item_x), (21 + indent_y));
                                XDrawLine(x->display, x->window, x->gc_menu_border_bottom, (3 + indent_x + indent_menu_item_x), 20, (3 + indent_x + indent_menu_item_x), (21 + indent_y));
                                XDrawLine(x->display, x->window, x->gc_menu_border_top, (3 + indent_x), 19, (3 + indent_x + indent_menu_item_x), 19);
                                XDrawLine(x->display, x->window, x->gc_menu_border_top, (3 + indent_x), 19, (3 + indent_x), (20 + indent_y));
                            }

                            indent_x = indent_x + (strlen(Anwendung.menu_bar1.menus[count_menu].name) * 6) + 10;
                        }
                    }
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive expose x windows input. The expose event is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive expose x windows input. The event is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive expose x windows input. The x windows is null.");
    }
*/
}

/**
 * Receives a mapping notify x windows input.
 *
 * Processes keyboard mapping changes.
 *
 * @param p0 the event
 */
void receive_mapping_notify_x_windows_input(void* p0) {

//??    XRefreshKeyboardMapping((XMappingEvent*) p0);
}

/**
 * Receives a key press x windows input.
 *
 * Processes keyboard events.
 *
 * @param p0 the signal memory
 * @param p1 the internal x windows data
 * @param p2 the event
 */
void receive_key_press_x_windows_input(void* p0, void* p1, void* p2) {

/*??
    struct x_windows* x = (struct x_windows*) p1;

    if (x != NULL_POINTER) {

        XEvent* e = (XEvent*) p2;

        if (e != NULL_POINTER) {

            int i = XLookupString((XKeyEvent*) p2, x->text, 10, &(x->key), 0);

            // Create signal.
        //??    void* s = create_dynamics((void*) action, NULL, NULL, (void*) DYNAMICS_COMPOUND);

            // Add signal to signal memory.
        //??    add_signal(p0, s, (void*) DYNAMICS_COMPOUND, (void*) &NORMAL_PRIORITY);

            //?? Testing.
            //?? Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite,
            //?? bei c das Dritte.
            if (i == 1 && x->text[0] == 'a') {

                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && x->text[0] == 'b') {

                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && x->text[0] == 'c') {

                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;

            } if (i == 1 && x->text[0] == 'x') {

                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && x->text[0] == 'q') {

        //??        done = 1;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive key press x windows input. The event is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive key press x windows input. The x windows is null.");
    }
*/
}

/**
 * Receives a button press x windows input.
 *
 * Processes mouse events.
 *
 * @param p0 the signal memory
 * @param p1 the internal x windows data
 * @param p2 the event
 */
void receive_button_press_x_windows_input(void* p0, void* p1, void* p2) {

/*??
    struct x_windows* x = (struct x_windows*) p1;

    if (x != NULL_POINTER) {

        XEvent* e = (XEvent*) p2;

        if (e != NULL_POINTER) {

            //struct XButtonEvent w;
            //w = x->event.xbutton.window;
            //if ()
            //w = x->event.xbutton.x;
            //printf("%d", w);
            //XDrawImageString (exp->display, exp->window, gc_menu_font, 100, 100, w.xbutton.x, strlen(w.xbutton.x));
            //printf("%s", w.xbutton.x);

            if ((x->event.xbutton.x<30) && (x->event.xbutton.x>3) && (x->event.xbutton.y<21) && (x->event.xbutton.x>1)) {

                XClearArea (x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if ((x->event.xbutton.x<65) && (x->event.xbutton.x>38) && (x->event.xbutton.y<21) && (x->event.xbutton.x>1)) {

                XClearArea (x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if ((x->event.xbutton.x<120) && (x->event.xbutton.x>70) && (x->event.xbutton.y<21) && (x->event.xbutton.x>1)) {

                XClearArea (x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;

            } else {

                XClearArea (x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive button press x windows input. The event is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive button press x windows input. The x windows is null.");
    }
*/
}

/**
 * Receives a graphics array from a vga graphics adapter and translates it into
 * a serialised x window model.
 *
 * @param p0 the destination (serialised x window model) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (graphics adapter array)
 * @param p4 the source count
 */
void receive_vga(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

/*??
    struct x_windows* x = (struct x_windows*) p1;

    if (x != NULL_POINTER) {

        // Determine pointer to x event structure.
        XEvent* e = &(x->event);

        // Read x event.
        XNextEvent(x->display, e);

        if (e != NULL_POINTER) {

            int t = e->type;

            if (t == Expose) {

                receive_expose_x_windows_input(p0, p1, (void*) e);

            } else if (t == MappingNotify) {

                receive_mapping_notify_x_windows_input((void*) e);

            } else if (t == KeyPress) {

                receive_key_press_x_windows_input(p0, p1, (void*) e);

            } else if (t == ButtonPress) {

                receive_button_press_x_windows_input(p0, p1, (void*) e);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive x windows input. The event is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not receive x windows input. The x windows is null.");
    }
*/
}

//??
//?? Old signal handling. Delete this block later!
//??

/**
 * Handles the mouse clicked action.
 *
 * @param p0 the screen item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the action
 */
/*??
void mouse_clicked_action(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != NULL_POINTER) {

        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = NULL_POINTER;
        struct vector* position = NULL_POINTER;
        struct vector* expansion = NULL_POINTER;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = NULL_POINTER;

        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);

            if (child instanceof item) {

                expansion = (vector) get_item_element(child, "expansion");

                if (position != NULL_POINTER) {

                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != NULL_POINTER) {

                        // Determine child's expansion.
                        width = expansion->x;
                        height = expansion->y;
                        depth = expansion->z;

                        // Check if the given coordinates are in the child's screen area.
                        // The "if" conditions had to be inserted because in classical
                        // graphical user interfaces, the depth is normally 0 and
                        // such the boolean comparison would deliver "false".
                        // Using the conditions, the coordinates that are set to "0"
                        // are not considered for comparison.
                        contains = (x >= 0);
                        contains = contains && (x < width);
                        contains = contains && (y >= 0);
                        contains = contains && (y < height);
                        contains = contains && (z >= 0);
                        contains = contains && (z < depth);

                        if (contains == 1) {

                            // The given coordinates are in the child's screen area.
                            // Therefore, use the child's action.
                            action = mouse_clicked_action(child, x, y, z, p4);

                            break;
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. An expansion is null.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. A position is null.");
                }

            } else {

                log_message((void*) &INFO_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. A child is not of type Item.");
            }

            count++;
        }

        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != NULL_POINTER) {

            p4 = action;

        } else {

            // Determine the action of the given screen item.
            get_map_element(i->items, "mouse_clicked_action", p4);
        }

    } else {

        puts("ERROR: Could not handle mouse clicked action. The item is null.");
    }
}
*/

/**
 * Sends a serialised x window model in form of a graphics array to a
 * vga graphics adapter.
 *
 * @param p0 the destination (graphics array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (serialised x window model)
 * @param p4 the source count
 */
void send_vga(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* VGA_COMMUNICATOR_SOURCE */
#endif
