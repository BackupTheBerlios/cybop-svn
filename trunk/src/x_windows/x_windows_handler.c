/*
 * $RCSfile: x_windows_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

#ifndef X_WINDOWS_HANDLER_SOURCE
#define X_WINDOWS_HANDLER_SOURCE

//?? #include <stdio.h>
//?? #include <stdlib.h>
//?? #include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include "x_windows.c"

/**
 * This is the x windows handler.
 *
 * It controls the input and output of x windows.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-17 17:16:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Sends an x windows output.
 *
 * @param p0 the addressee
 * @param p1 the message
 * @param p2 the x windows data
 */
void send_x_windows_output(void* p0, void* p1) {

/*??
    // Get parameters from screen and set them on X.
    Display* display = XOpenDisplay("");
    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(
        display,
        DefaultRootWindow(display),
        hint.x,
        hint.y,
        hint.width,
        hint.height,
        5,
        foreground,
        background);

    XSetStandardProperties(display, window, "Application", "Icon", None, argv, argc, &hint);
    
    GC gc = XCreateGC(display, window, 0, 0);
    
    XSetBackground(display, gc, background);
    XSetForeground(display, gc, foreground);

    // Request input signals.
    XSelectInput(display, window, ButtonPressMask | KeyPressMask | ExposureMask);
    
    // Map windows.
    XMapRaised(display, window);
*/
}

/**
 * Receives an x windows input.
 *
 * @param p0 the addressee
 * @param p1 the message
 * @param p2 the x windows data
 */
void receive_x_windows_input(void* p0) {

    struct x_windows* x = (struct x_windows*) p0;
    
    if (x != (void*) 0) {
        
/*??
        // Read signal.
        XNextEvent(x.display, &(x.event));
    
        if (x.event.type == Expose) {
            
            // Repaint window after an expose.
    
            // Bei mehreren Expose-Events nur der letzte beachtet
            if (x.event.xexpose.count == 0) {
                
                XGetWindowAttributes(x.display, x.window, &(x.window_attributes));
                //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, "hello", strlen("hello"));
                //XRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, 2, 2, (window_attributes.width-4), 30);
                
                // Menuleiste zeichnen
                XDrawLine(x.display, x.window, x.gc_menu_border_bottom, 0, 21, x.window_attributes.width, 21);
                XDrawLine(x.display, x.window, x.gc_menu_border_bottom, (x.window_attributes.width - 1), 1, (x.window_attributes.width - 1), 21);
                XFillRectangle(x.event.xexpose.display, x.event.xexpose.window, x.gc_menu, 1, 1, (x.window_attributes.width - 2), 20);
                
                // Menueintraege zeichen
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
                //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, Anwendung.menu_bar1.Datei.name, strlen(Anwendung.menu_bar1.Datei.name));
                //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, str_test, strlen(str_test));
                //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, Anwendung.menu_bar1.menu1.name, strlen(Anwendung.menu_bar1.menu1.name));
                //}
    
                indent_x = 0;
                indent_y = 0;
                indent_menu_item_x = 0;
                
                for (count_menu = 0; count_menu < 5; count_menu++) {
        
                    if (strlen(Anwendung.menu_bar1.menus[count_menu].name) > 0) {
                        
                        XDrawImageString(x.event.xexpose.display, x.event.xexpose.window, x.gc_menu_font, (5 + indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, strlen(Anwendung.menu_bar1.menus[count_menu].name));
                
                        for (count_item = 0; ((count_item < 9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt == 1)); count_item++) {
                            
                            if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name) * 6) + 6 > indent_menu_item_x) {
                                
                                indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name) * 6) + 6;
                            }
                        }
                
                        for (count_item = 0; ((count_item < 9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt == 1)); count_item++) {
    
                            if (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name) > 0) {
                        
                                indent_y = indent_y + 17;
    
                                //if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                //  XFillRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                                //  indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                //
                                //}
                                //XFillRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);

                                XFillRectangle(
                                    x.event.xexpose.display,
                                    x.event.xexpose.window,
                                    x.gc_menu,
                                    3 + indent_x,
                                    20 + (count_item * 17),
                                    indent_menu_item_x,
                                    19);
    
                                XDrawImageString(
                                    x.event.xexpose.display,
                                    x.event.xexpose.window,
                                    x.gc_menu_font,
                                    5 + indent_x,
                                    33 + (count_item * 17),
                                    Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name,
                                    strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                            }
                            
                        }
                
                        if (Anwendung.menu_bar1.menus[count_menu].angeklickt == 1) {
                
                            XDrawLine(x.display, x.window, x.gc_menu_border_bottom, (3 + indent_x), (21 + indent_y), (3 + indent_x + indent_menu_item_x), (21 + indent_y));
                            XDrawLine(x.display, x.window, x.gc_menu_border_bottom, (3 + indent_x + indent_menu_item_x), 20, (3 + indent_x + indent_menu_item_x), (21 + indent_y));
                            XDrawLine(x.display, x.window, x.gc_menu_border_top, (3 + indent_x), 19, (3 + indent_x + indent_menu_item_x), 19);
                            XDrawLine(x.display, x.window, x.gc_menu_border_top, (3 + indent_x), 19, (3 + indent_x), (20 + indent_y));
                        }
                        
                        indent_x = indent_x + (strlen(Anwendung.menu_bar1.menus[count_menu].name) * 6) + 10;
                    }
                }
            }
            
        } else if (x.event.type == MappingNotify) {
            
            // Process keyboard mapping changes.
            XRefreshKeyboardMapping(&x.event);
            
        } else if (x.event.type == ButtonPress) {
    
            // Process mouse events.
            
        } else if (x.event.type == KeyPress) {
    
            // Process keyboard events.
    
            i = XLookupString(&(x.event), text, 10, &(x.key), 0);
            
            //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
            //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte
            if (i == 1 && text[0] == 'a') {
    
                XClearArea(x.display, x.window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
            
            } else if (i == 1 && text[0] == 'b') {
                    
                XClearArea(x.display, x.window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
            
            } else if (i == 1 && text[0] == 'c') {
    
                XClearArea(x.display, x.window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;
            
            } if (i == 1 && text[0] == 'x') {
    
                XClearArea(x.display, x.window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
    
            } else if (i == 1 && text[0] == 'q') {
                
                done = 1;
            }
        }
*/
    
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not handle x windows signal. The x windows is null.");
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

    if (p0 != 0) {

        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = 0;
        struct vector* position = 0;
        struct vector* expansion = 0;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = 0;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != 0) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != 0) {

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
                        
                        log_message((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. An expansion is null.");
                    }

                } else {
                    
                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. A position is null.");
                }

            } else {
                
                log_message((void*) &INFO_LOG_LEVEL, "Could not handle mouse clicked action. A child is not of type Item.");
            }
            
            count++;
        }
        
        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != 0) {
            
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

