/*
 * $RCSfile: x_windows_handler.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file handles graphics using x windows.
 *
 * It controls the input and output of x windows.
 *
 * @version $Revision: 1.20 $ $Date: 2004-05-26 14:13:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOWS_HANDLER_SOURCE
#define X_WINDOWS_HANDLER_SOURCE

//?? #include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//?? #include <X11/X.h>
//?? #include <X11/Xatom.h>
//?? #include <X11/Xfuncs.h>
#include <X11/Xlib.h>
//?? #include <X11/Xos.h>
//?? #include <X11/Xproto.h>
//?? #include <X11/Xresource.h>
#include <X11/Xutil.h>
#include "../logger/logger.c"
#include "../x_windows/x_windows.c"

/**
 * Temporary! Initializes X-Windows testing variables.
 */
struct menu_item {
    int color;
    char name[50];
};

struct menu {
    int color;
    char name[50];
    int angeklickt;
    struct menu_item menu_items[20]; //max. 20 Items
};

struct menu_bar {
    int color;
    struct menu menus[5]; // max. 5 Menues
};

struct frame {
    int size_x;
    int size_y;
    /// color fehlt noch
    struct menu_bar menu_bar1;
};

struct frame Anwendung;

/**
 * ?? Testing! Init x windows.
 */
void init_x() {

    //// Konkrete Beispielwerte setzen
    Anwendung.size_x = 300;
    Anwendung.size_y = 200;

    strcpy(Anwendung.menu_bar1.menus[0].name, "File");
    strcpy(Anwendung.menu_bar1.menus[1].name, "View");
    strcpy(Anwendung.menu_bar1.menus[2].name, "Options");
    strcpy(Anwendung.menu_bar1.menus[3].name, "");
    strcpy(Anwendung.menu_bar1.menus[4].name, "");

    Anwendung.menu_bar1.menus[1].angeklickt = 1;

    strcpy(Anwendung.menu_bar1.menus[0].menu_items[0].name, "Open");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[1].name, "Save");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[2].name, "Close");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[3].name, "");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[4].name, "");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[5].name, "");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[6].name, "");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[7].name, "");
    strcpy(Anwendung.menu_bar1.menus[0].menu_items[8].name, "");

    strcpy(Anwendung.menu_bar1.menus[1].menu_items[0].name, "Symbol Bar");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[1].name, "Side Bars");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[2].name, "Reload");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[3].name, "Symbol Bars Task");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[4].name, "Side Bar Side Taskbar-Task");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[5].name, "Reload");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[6].name, "Symbol Bars");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[7].name, "Side Bar");
    strcpy(Anwendung.menu_bar1.menus[1].menu_items[8].name, "Reload");

    strcpy(Anwendung.menu_bar1.menus[2].menu_items[0].name, "Preferences");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[1].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[2].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[3].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[4].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[5].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[6].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[7].name, "");
    strcpy(Anwendung.menu_bar1.menus[2].menu_items[8].name, "");
}

//
// Output sending.
//

/**
 * Sends an x windows output.
 *
 * @param p0 the addressee
 * @param p1 the message
 * @param p2 the internals
 */
void send_x_windows_output(void* p0, void* p1, void* p2) {

    struct x_windows* x = (struct x_windows*) p2;

    if (x != NULL_POINTER) {

        // Get parameters from screen and set them on X.
        x->display = XOpenDisplay("");
        x->screen = DefaultScreen(x->display);

        // Voreinstellung fuer Pixelwerte
        x->background = WhitePixel(x->display, x->screen);
        x->foreground = BlackPixel(x->display, x->screen);

        // Window-position
        x->hint.x = 100;
        x->hint.y = 100;

        x->hint.width = Anwendung.size_x;
        x->hint.height = Anwendung.size_y;
        x->hint.flags = PPosition | PSize;

        x->window = XCreateSimpleWindow(
            x->display,
            DefaultRootWindow(x->display),
            x->hint.x,
            x->hint.y,
            x->hint.width,
            x->hint.height,
            5,
            x->foreground,
            x->background);

        XSetStandardProperties(
            x->display,
            x->window,
            "Application",
            "Icon",
            None,
            NULL,
            0,
            (void*) &(x->hint));

        // GCs fuer Menubar erzeugen
        x->cmap = DefaultColormap(x->display, x->screen);
        x->gray.red = 49125;
        x->gray.green = 49125;
        x->gray.blue = 49125;

        XAllocColor(x->display, x->cmap, &(x->gray));
        x->light_gray.red = 56000;
        x->light_gray.green = 58000;
        x->light_gray.blue = 60000;

        XAllocColor(x->display, x->cmap, &(x->light_gray));
        x->vlight_gray.red = 60000;
        x->vlight_gray.green = 61000;
        x->vlight_gray.blue = 62000;

        XAllocColor(x->display, x->cmap, &(x->vlight_gray));
        x->dark_gray.red = 32768;
        x->dark_gray.green = 32768;
        x->dark_gray.blue = 32768;

        XAllocColor(x->display, x->cmap, &(x->dark_gray));

        x->gc_menu = XCreateGC(x->display, x->window, 0, 0);
        XSetBackground(x->display, x->gc_menu, x->background);
        XSetForeground(x->display, x->gc_menu, x->light_gray.pixel);

        x->gc_menu_border_top = XCreateGC(x->display, x->window, 0, 0);
        XSetBackground(x->display, x->gc_menu_border_top, x->background);
        XSetForeground(x->display, x->gc_menu_border_top, x->vlight_gray.pixel);

        x->gc_menu_border_bottom = XCreateGC(x->display, x->window, 0, 0);
        XSetBackground(x->display, x->gc_menu_border_bottom, x->background);
        XSetForeground(x->display, x->gc_menu_border_bottom, x->dark_gray.pixel);

        x->gc_menu_font = XCreateGC(x->display, x->window, 0, 0);
        XSetBackground(x->display, x->gc_menu_font, x->light_gray.pixel);
        XSetForeground(x->display, x->gc_menu_font, x->foreground);

        // GC (graphic content) erzeugen
        GC gc = XCreateGC(x->display, x->window, 0, 0);

        XSetBackground(x->display, gc, x->background);
        XSetForeground(x->display, gc, x->foreground);

        // Request input signals.
        XSelectInput(x->display, x->window, ButtonPressMask | KeyPressMask | ExposureMask);

        // Map windows.
        XMapRaised(x->display, x->window);

        //?? From xlib tutorial. Remove later when event loop (MappingNotify) functions!
        XFlush(x->display);

        // Free memory.
        XFreeGC(x->display, gc);
        XDestroyWindow(x->display, x->window);
        XCloseDisplay(x->display);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle send x windows output. The x windows is null.");
    }
}

//
// Input reception.
//

/**
 * Receives an expose x windows input.
 *
 * An expose leads to repainting the window.
 *
 * @param p0 the signal memory
 * @param p1 the internal x windows data
 * @param p2 the event
 */
void receive_expose_x_windows_input(void* p0, void* p1, void* p2) {

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
}

/**
 * Receives a mapping notify x windows input.
 *
 * Processes keyboard mapping changes.
 *
 * @param p0 the event
 */
void receive_mapping_notify_x_windows_input(void* p0) {

    XRefreshKeyboardMapping((XMappingEvent*) p0);
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
}

/**
 * Receives an x windows input.
 *
 * @param p0 the signal memory
 * @param p1 the internal x windows data
 */
void receive_x_windows_input(void* p0, void* p1) {

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

/* X_WINDOWS_HANDLER_SOURCE */
#endif
