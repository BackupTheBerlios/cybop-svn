/*
 * $RCSfile: startup_x_window_system.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2005-03-30 17:04:08 $ $Author: christian $
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
 */

#ifndef STARTUP_X_WINDOW_SYSTEM_SOURCE
#define STARTUP_X_WINDOW_SYSTEM_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../creator/integer_creator.c"
#include "../../creator/unsigned_long_creator.c"
#include "../../global/integer_constants.c"
#include "../../global/structure_constants.c"
#include "../../global/variables.c"

/**
 * Starts up the x window system.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void startup_x_window_system(void* p0, const void* p1, const void* p2, const void* p3) {

    log_message_debug("Startup x window system.");

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
    } Anwendung;

    //// Konkrete Beispielwerte setzen
    Anwendung.size_x = 300;
    Anwendung.size_y = 200;

    strcpy (Anwendung.menu_bar1.menus[0].name, "File");
    strcpy (Anwendung.menu_bar1.menus[1].name, "View");
    strcpy (Anwendung.menu_bar1.menus[2].name, "Options");
    strcpy (Anwendung.menu_bar1.menus[3].name, "");
    strcpy (Anwendung.menu_bar1.menus[4].name, "");

    Anwendung.menu_bar1.menus[1].angeklickt = 1;

    strcpy (Anwendung.menu_bar1.menus[0].menu_items[0].name, "Open");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[1].name, "Save");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[2].name, "Close");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[3].name, "");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[4].name, "");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[5].name, "");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[6].name, "");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[7].name, "");
    strcpy (Anwendung.menu_bar1.menus[0].menu_items[8].name, "");

    strcpy (Anwendung.menu_bar1.menus[1].menu_items[0].name, "Symbol Bar");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[1].name, "Side Bars");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[2].name, "Reload");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[3].name, "Symbol Bars Task");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[4].name, "Side Bar Side Taskbar-Task");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[5].name, "Reload");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[6].name, "Symbol Bars");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[7].name, "Side Bar");
    strcpy (Anwendung.menu_bar1.menus[1].menu_items[8].name, "Reload");

    strcpy (Anwendung.menu_bar1.menus[2].menu_items[0].name, "Preferences");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[1].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[2].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[3].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[4].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[5].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[6].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[7].name, "");
    strcpy (Anwendung.menu_bar1.menus[2].menu_items[8].name, "");

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
//??    struct _XDisplay** d = NULL_POINTER;
    Display* d;

    // Get display.
//??    get_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) &d, (void*) POINTER_ARRAY);

//??    if (*d == NULL_POINTER) {

        // CAUTION!
        // The X window system types Window, Colormap, Font are simple integers!

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.net would be:
        // char* dn = "earth.cybop.net:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        char* dn = NULL_POINTER;
        // The screen number.
//??        int* sn = INTEGER_NULL_POINTER;
        int sn;
        // The screen.
//??        Screen* s = NULL_POINTER;
        // The background pixel values.
//??        unsigned long* bg = NULL_POINTER;
        unsigned long bg;
        // The foreground pixel values.
//??        unsigned long* fg = NULL_POINTER;
        unsigned long fg;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
//??        int* r = NULL_POINTER;
        // The default colormap id for allocation on the specified screen.
        // Most routine allocations of color should be made out of this colormap.
//??        int* cm = NULL_POINTER;
        Colormap cm;
        // The value mask for the graphic context.
        // It specifies which components in the graphic context are to be set
        // using the information in the specified values structure.
        // This argument is the bitwise inclusive OR of zero or more of the
        // valid graphic context component mask bits.
//??        unsigned long* vm = NULL_POINTER;
        // The values as specified by the value mask.
//??        XGCValues* v = NULL_POINTER;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
//??        struct _XGC* gc = NULL_POINTER;
        GC gc;
        // The font name.
//??        char* fn = NULL_POINTER;
        // The font id.
//??        int* f = NULL_POINTER;

/*??
        // Create x window system internals.
        create_integer((void*) &sn);
        create_unsigned_long((void*) &bg);
        create_unsigned_long((void*) &fg);
        create_integer((void*) &r);
        create_integer((void*) &cm);
        create_unsigned_long((void*) &vm);
        create_integer((void*) &f);
*/

        // Initialise x window system internals.
        dn = "";
//??        *d = XOpenDisplay(dn);
        d = XOpenDisplay(dn);

//??        *sn = 0;
        sn = DefaultScreen(d);
//??        s = XScreenOfDisplay(*d, *sn);
//??        *bg = XWhitePixel(*d, *sn);
        bg = XWhitePixel(d, sn);
//??        *fg = XBlackPixel(*d, *sn);
        fg = XBlackPixel(d, sn);
//??        *r = XRootWindowOfScreen(s);
//??        *cm = XDefaultColormap(*d, *sn);
        cm = XDefaultColormap(d, sn);
//??        *vm = 0;
//??        v = NULL_POINTER;

        // The size hint.
        XSizeHints sh;
        sh.x = 100;
        sh.y = 100;
        sh.width = 400;
        sh.height = 300;
        sh.flags = PPosition | PSize;

        // The window.
//??        int* w = XCreateSimpleWindow(*d, *r, sh.x, sh.y, sh.width, sh.height, 5, *fg, *bg);
        Window w = XCreateSimpleWindow(d, DefaultRootWindow(d), sh.x, sh.y, sh.width, sh.height, 5, fg, bg);
//??        XSetStandardProperties(*d, w, "Application", "Icon", None, NULL, 0, (void*) &sh);
        XSetStandardProperties(d, w, "Application", "Icon", None, NULL_POINTER, 0, (void*) &sh);

//??        gc = XCreateGC(*d, *r, *vm, v);
        gc = XCreateGC(d, w, 0, 0);
//??        XSetBackground(*d, gc, *bg);
        XSetBackground(d, gc, bg);
//??        XSetForeground(*d, gc, *fg);
        XSetForeground(d, gc, fg);
//??        fn = "Helvetica";
//??        *f = XLoadFont(*d, fn);
//??        XSetFont(*d, gc, f);

        XColor gray;
        gray.red = 49125;
        gray.green = 49125;
        gray.blue = 49125;
//??        XAllocColor(*d, *cm, &gray);
        XAllocColor(d, cm, &gray);

        XColor light_gray;
        light_gray.red = 56000;
        light_gray.green = 58000;
        light_gray.blue = 60000;
//??        XAllocColor(*d, *cm, &light_gray);
        XAllocColor(d, cm, &light_gray);

        XColor vlight_gray;
        vlight_gray.red = 60000;
        vlight_gray.green = 61000;
        vlight_gray.blue = 62000;
//??        XAllocColor(*d, *cm, &vlight_gray);
        XAllocColor(d, cm, &vlight_gray);

        XColor dark_gray;
        dark_gray.red = 32768;
        dark_gray.green = 32768;
        dark_gray.blue = 32768;
//??        XAllocColor(*d, *cm, &dark_gray);
        XAllocColor(d, cm, &dark_gray);

        // Create menu graphic context.
//??        GC gc_menu = XCreateGC(*d, w, 0, 0);
        GC gc_menu = XCreateGC(d, w, 0, 0);
//??        XSetBackground(*d, gc_menu, *bg);
        XSetBackground(d, gc_menu, bg);
//??        XSetForeground(*d, gc_menu, light_gray.pixel);
        XSetForeground(d, gc_menu, light_gray.pixel);

        // Create menu border graphic context.
//??        GC gc_menu_border_top = XCreateGC(*d, w, 0, 0);
        GC gc_menu_border_top = XCreateGC(d, w, 0, 0);
//??        XSetBackground(*d, gc_menu_border_top, *bg);
        XSetBackground(d, gc_menu_border_top, bg);
//??        XSetForeground(*d, gc_menu_border_top, vlight_gray.pixel);
        XSetForeground(d, gc_menu_border_top, vlight_gray.pixel);

        // Create menu border bottom graphic context.
//??        GC gc_menu_border_bottom = XCreateGC(*d, w, 0, 0);
        GC gc_menu_border_bottom = XCreateGC(d, w, 0, 0);
//??        XSetBackground(*d, gc_menu_border_bottom, *bg);
        XSetBackground(d, gc_menu_border_bottom, bg);
//??        XSetForeground(*d, gc_menu_border_bottom, dark_gray.pixel);
        XSetForeground(d, gc_menu_border_bottom, dark_gray.pixel);

        // Create menu font graphic context.
//??        GC gc_menu_font = XCreateGC(*d, w, 0, 0);
        GC gc_menu_font = XCreateGC(d, w, 0, 0);
//??        XSetBackground(*d, gc_menu_font, light_gray.pixel);
        XSetBackground(d, gc_menu_font, light_gray.pixel);
//??        XSetForeground(*d, gc_menu_font, *fg);
        XSetForeground(d, gc_menu_font, fg);

        // Request input events (signals) to be put into event queue.
//??        XSelectInput(*d, w, ButtonPressMask | KeyPressMask | ExposureMask);
        XSelectInput(d, w, ButtonPressMask | KeyPressMask | ExposureMask);

        // Map window.
        // This procedure changes the order of all sister windows,
        // so that the given window lies on top.
        // Afterwards, all windows are displayed on the screen.
//??        XMapRaised(*d, w);
        XMapRaised(d, w);

        // The window attributes.
        XWindowAttributes wa;

        // Draw window.
        XGetWindowAttributes(d, w, &wa);
        //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, "hello", strlen("hello"));
        //XRectangle (e.xexpose.display, e.xexpose.window, gc_menu, 2, 2, (wa.width-4), 30);

        // Draw menu bar.
        XDrawLine(d, w, gc_menu_border_bottom, 0, 21, wa.width, 21);
        XDrawLine(d, w, gc_menu_border_bottom, (wa.width-1), 1, (wa.width-1), 21);

        //?? TODO: From xlib tutorial.
        //?? Remove as soon as event loop (MappingNotify) functions!
//??        XFlushGC(*d, gc);

/*??
    XEvent e;
    KeySym k;
    char text[10];
    char str_test[1000];
    char str_zugriff[1000];
    char str_menubar[100];
    //??unsigned long //??double menu_foreground;
    // The temporary variables.
//??    int k;
    int menu_eintrage_ende;
    // Hauptschleife zum Lesen der Events
    int done = 0;
    int window;
    int i = 0, count_menu, count_item, indent_x, indent_y, indent_menu_item_x;

    while (done == 0) {
        
        // Event einlesen
        XNextEvent (d, &e);

        switch (e.type) {

        // Das Window nach einem Expose wiederherstellen
        case Expose:

            if (e.xexpose.count == 0) { // Bei mehreren Expose-Events nur der letzte beachtet

                XGetWindowAttributes (d, w, &wa);
                //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, "hello", strlen("hello"));
                //XRectangle (e.xexpose.display, e.xexpose.window, gc_menu, 2, 2, (wa.width-4), 30);
    
                /// Menuleiste zeichnen
                XDrawLine (d, w, gc_menu_border_bottom, 0, 21, wa.width, 21);
                XDrawLine (d, w, gc_menu_border_bottom, (wa.width-1), 1, (wa.width-1), 21);
                XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, 1, 1, (wa.width-2), 20);
    
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
            }

            break;
    
        // Abbildungsaenderungen der Tastatur verarbeiten
        case MappingNotify:

            XRefreshKeyboardMapping (&e);

            break;

        // Druecken der Maustaste verarbeiten
        case ButtonPress: {

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
        
            break;
        }

        // Tastatureingaben verarbeiten
        case KeyPress:

            i = XLookupString ( &e, text, 10, &k, 0);
            
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
            
            } else if ( i == 1 && text[0] == 'q') done = 1;

                break;
        }
    }
*/

        sleep(5);

        // Free memory.
//??        XFreeGC(*d, gc);
        XFreeGC(d, gc);
//??        XDestroyWindow(*d, w);
        XDestroyWindow(d, w);
//?? DELETE later! This belongs to shutdown_x_window_system!
        XCloseDisplay(d);

/*??
        // Set x window system internals.
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL, (void*) &dn, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        // CAUTION! Do NOT use reference for d, because it is of type (struct _XDisplay**)!
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL, (void*) d, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL, (void*) &sn, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) &s, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL, (void*) &bg, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL, (void*) &fg, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL, (void*) &r, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL, (void*) &cm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL, (void*) &vm, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL, (void*) &v, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL, (void*) &gc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_NAME_INTERNAL, (void*) &fn, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
        set_array_elements(p0, (void*) X_WINDOW_SYSTEM_FONT_INTERNAL, (void*) &f, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
*/

/*??
    } else {

        log_message_debug("WARNING: Could not startup x window system. The x window system is already running.");
    }
*/
}

/* STARTUP_X_WINDOW_SYSTEM_SOURCE */
#endif
