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
#include "../logger/log_handler.c"
#include "../x_windows/x_windows.c"

/**
 * This is the x windows handler.
 *
 * It controls the input and output of x windows.
 *
 * @version $Revision: 1.7 $ $Date: 2004-02-04 11:00:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Sends an x windows output.
 *
 * @param p0 the addressee
 * @param p1 the message
 * @param p2 the internals
 */
void send_x_windows_output(void* p0, void* p1, void* p2) {

/*??
    struct x_windows* x = (struct x_windows*) p2;
    
    if (x != (void*) 0) {
        
        //?? temp initialization!
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
            (void*) 0,
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

    } else {
        
        puts("ERROR: Could not handle send x windows output. The x windows is null.");
    }
*/
}

/**
 * Receives an x windows input.
 *
 * @param p0 the addressee
 * @param p1 the message
 * @param p2 the internals
 */
void receive_x_windows_input(void* p0) {

    struct x_windows* x = (struct x_windows*) p0;
    
    if (x != (void*) 0) {
        
/*??
        // Read signal.
        XNextEvent(x->display, &(x->event));
    
        if (x->event.type == Expose) {
            
            // Repaint window after an expose.

            // Bei mehreren Expose-Events nur der letzte beachtet
            if (x->event.xexpose.count == 0) {

                XGetWindowAttributes(x->display, x->window, &(x->window_attributes));
                //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, "hello", strlen("hello"));
                //XRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, 2, 2, (window_attributes.width-4), 30);

                // Menuleiste zeichnen
                XDrawLine(x->display, x->window, x->gc_menu_border_bottom, 0, 21, x->window_attributes.width, 21);
                XDrawLine(x->display, x->window, x->gc_menu_border_bottom, (x->window_attributes.width - 1), 1, (x->window_attributes.width - 1), 21);
                XFillRectangle(x->event.xexpose.display, x->event.xexpose.window, x->gc_menu, 1, 1, (x->window_attributes.width - 2), 20);
                
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
                        
                        XDrawImageString(x->event.xexpose.display, x->event.xexpose.window, x->gc_menu_font, (5 + indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, strlen(Anwendung.menu_bar1.menus[count_menu].name));
                
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
                                    x->event.xexpose.display,
                                    x->event.xexpose.window,
                                    x->gc_menu,
                                    3 + indent_x,
                                    20 + (count_item * 17),
                                    indent_menu_item_x,
                                    19);
    
                                XDrawImageString(
                                    x->event.xexpose.display,
                                    x->event.xexpose.window,
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
            
        } else if (x->event.type == MappingNotify) {
            
            // Process keyboard mapping changes.
            XRefreshKeyboardMapping(&x->event);
            
        } else if (x->event.type == ButtonPress) {
    
            // Process mouse events.
            
            //struct XButtonEvent w;
            //w = myevent.xbutton.window;
            //if ()
            //w = myevent.xbutton.x;
            //printf("%d", w);
            //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, gc_menu_font, 100, 100, w.xbutton.x, strlen(w.xbutton.x));
            //printf("%s", w.xbutton.x);
    
            if ((myevent.xbutton.x<30) && (myevent.xbutton.x>3) && (myevent.xbutton.y<21) && (myevent.xbutton.x>1)) {
              XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
              Anwendung.menu_bar1.menus[0].angeklickt = 1;
              Anwendung.menu_bar1.menus[1].angeklickt = 0;
              Anwendung.menu_bar1.menus[2].angeklickt = 0;
            }
            else if ((myevent.xbutton.x<65) && (myevent.xbutton.x>38) && (myevent.xbutton.y<21) && (myevent.xbutton.x>1)) {
              XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
              Anwendung.menu_bar1.menus[0].angeklickt = 0;
              Anwendung.menu_bar1.menus[1].angeklickt = 1;
              Anwendung.menu_bar1.menus[2].angeklickt = 0;
            }
            else if ((myevent.xbutton.x<120) && (myevent.xbutton.x>70) && (myevent.xbutton.y<21) && (myevent.xbutton.x>1)) {
              XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
              Anwendung.menu_bar1.menus[0].angeklickt = 0;
              Anwendung.menu_bar1.menus[1].angeklickt = 0;
              Anwendung.menu_bar1.menus[2].angeklickt = 1;
            }
            else {
              XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
              Anwendung.menu_bar1.menus[0].angeklickt = 0;
              Anwendung.menu_bar1.menus[1].angeklickt = 0;
              Anwendung.menu_bar1.menus[2].angeklickt = 0;
            }

        } else if (x->event.type == KeyPress) {
    
            // Process keyboard events.
    
            i = XLookupString(&(x->event), text, 10, &(x->key), 0);
            
            //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
            //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte
            if (i == 1 && text[0] == 'a') {
    
                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
            
            } else if (i == 1 && text[0] == 'b') {
                    
                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;
            
            } else if (i == 1 && text[0] == 'c') {
    
                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;
            
            } if (i == 1 && text[0] == 'x') {
    
                XClearArea(x->display, x->window, 0, 0, 0, 0, True);
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

    if (p0 != (void*) 0) {

        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = (void*) 0;
        struct vector* position = (void*) 0;
        struct vector* expansion = (void*) 0;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = (void*) 0;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != (void*) 0) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != (void*) 0) {

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
        if (action != (void*) 0) {
            
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
