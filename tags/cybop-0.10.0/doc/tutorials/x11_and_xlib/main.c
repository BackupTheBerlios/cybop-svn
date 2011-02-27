/***************************************************************************
                          main.c  -  description
                             -------------------
    begin                : Wed Nov 26 16:45:50 CET 2003
    copyright            : (C) 2003 by MF
    email                : mf@openess.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

//main(argc,argv)
//  int argc;
//  char **argv;
//{
int main(int argc, char *argv[])
{
  /*struct menu_item {
    int color;
    char name[30];
  };

  struct menu {
    int color;
    char name[30];
    struct menu_item menu_item1;
    struct menu_item menu_item2;
    struct menu_item menu_item3;
  };

  struct menu_bar {
    int color;
    struct menu menu1;
    struct menu menu2;
    struct menu menu3;
    //struct menu menus[30];
  };

  struct frame {
    int size_x;
    int size_y;
    /// color fehlt noch
    struct menu_bar menu_bar1;
  };


  /// Konkretes Auffuellen der structs
  /// Ein Fenster mit der Groesse 200x300, einer Menu-bar mit 3 Menueeintraegen und jeweils 3 Items, Fraben jeweils 1
  struct frame Anwendung = {300,200,{1,{2,"Datei",{3,"Oeffnen"},{3,"Speichern"},{3,"Schliessen"}},{1},{1}}};
  //struct frame Anwendung = {300,200,{1,{2,[1]="Datei",{3,"Oeffnen"},{3,"Speichern"},{3,"Schliessen"}},{1},{1}}};
  //struct frame frame2 = {66,77,{88}};
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
  } Anwendung;



  //Anwendung.size_x = 300;
  //Anwendung.size_y = 200;

  //printf("x=");
  //printf("%d", Anwendung.size_y);

  Display *mydisplay;
  Window mywindow;
  GC mygc, gc_menu, gc_menu_border_top, gc_menu_border_bottom, gc_menu_font;
  XEvent myevent;
  KeySym mykey;
  XSizeHints myhint;
  char text[10];
  char str_test[1000], str_zugriff[1000], str_menubar[100];
  int myscreen;
  unsigned long myforeground, mybackground, menu_foreground;
  int i, k, menu_eintrage_ende = 0, count_menu, count_item, indent_x, indent_y, indent_menu_item_x, w;
  int done;

  //unsigned long w;

  Colormap cmap;
  XColor gray, light_gray, vlight_gray, dark_gray;

  XWindowAttributes window_attributes;

/*  cmap = DefaultColormap (mydisplay, Defaultscreen (myscreen));
  gray.red = 8192; gray.green = 8192; gray.blue = 8192;
  //gray.flags = DoRed | DoGreen | DoBlue;
  XAllocColor (mydisplay, cmap, &gray);
 */

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



  //Verbindung von Anwendung und Display (Display = I/O-Hardware + Screens + X-Server)
  mydisplay = XOpenDisplay("");

  // Defaultscreen des Displays als Int -> meist 0, beim zweiten Bildschirmen 1 usw.
  myscreen = DefaultScreen (mydisplay);

  // Voreinstellung fuer Pixelwerte
  mybackground = WhitePixel (mydisplay, myscreen);
  myforeground = BlackPixel (mydisplay, myscreen);


  // Window-position
  myhint.x = 100;
  myhint.y = 100;

  myhint.width = Anwendung.size_x;
  myhint.height = Anwendung.size_y;
  myhint.flags = PPosition | PSize;

  // Das Window erzeugen !!! - mit Nagbae des Rootwindow auch Screen festgelegt
  mywindow = XCreateSimpleWindow (mydisplay,
    DefaultRootWindow (mydisplay),
    myhint.x, myhint.y, myhint.width, myhint.height,
    5, myforeground, mybackground);
  XSetStandardProperties (mydisplay, mywindow, "Anwendung", "Anwendung_Icon",
    None, argv, argc, &myhint);


  // GCs fuer Menubar erzeugen
  cmap = DefaultColormap (mydisplay, myscreen);
  gray.red = 49125; gray.green = 49125; gray.blue = 49125;
  XAllocColor (mydisplay, cmap, &gray);
  light_gray.red = 56000; light_gray.green = 58000; light_gray.blue = 60000;
  XAllocColor (mydisplay, cmap, &light_gray);
  vlight_gray.red = 60000; vlight_gray.green = 61000; vlight_gray.blue = 62000;
  XAllocColor (mydisplay, cmap, &vlight_gray);
  dark_gray.red = 32768; dark_gray.green = 32768; dark_gray.blue = 32768;
  XAllocColor (mydisplay, cmap, &dark_gray);

  gc_menu = XCreateGC (mydisplay, mywindow, 0, 0);
  XSetBackground (mydisplay, gc_menu, mybackground);
  XSetForeground (mydisplay, gc_menu, light_gray.pixel);

  gc_menu_border_top = XCreateGC (mydisplay, mywindow, 0, 0);
  XSetBackground (mydisplay, gc_menu_border_top, mybackground);
  XSetForeground (mydisplay, gc_menu_border_top, vlight_gray.pixel);

  gc_menu_border_bottom = XCreateGC (mydisplay, mywindow, 0, 0);
  XSetBackground (mydisplay, gc_menu_border_bottom, mybackground);
  XSetForeground (mydisplay, gc_menu_border_bottom, dark_gray.pixel);

  gc_menu_font = XCreateGC (mydisplay, mywindow, 0, 0);
  XSetBackground (mydisplay, gc_menu_font, light_gray.pixel);
  XSetForeground (mydisplay, gc_menu_font, myforeground);

  // GC (graphic content) erzeugen
  mygc = XCreateGC (mydisplay, mywindow, 0, 0);
  XSetBackground (mydisplay, mygc, mybackground);
  XSetForeground (mydisplay, mygc, myforeground);

  // Eingabeevents anfordern
  XSelectInput (mydisplay, mywindow,
    ButtonPressMask | KeyPressMask | ExposureMask);

  // Windows abbliden
  XMapRaised (mydisplay, mywindow);

  //// Daten aus Anwendung malen
  /// Menubar zeichnen (nur eine moeglich in meinem Modell)
  //XFillRectangle (mydisplay, mywindow, mygc, 2, 2, 100, 30);
  //XDrawPoint (mydisplay, mywindow, mygc, 33, 44);


  // Hauptschleife zum Lesen der Events
  done = 0;
  while (done ==0) {
    // Event einlesen
    XNextEvent (mydisplay, &myevent);
    switch (myevent.type) {
      // Das Window nach einem Expose wiederherstellen
      case Expose:
        if (myevent.xexpose.count == 0) { // Bei mehreren Expose-Events nur der letzte beachtet
          XGetWindowAttributes (mydisplay, mywindow, &window_attributes);
          //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, "hello", strlen("hello"));
          //XRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, 2, 2, (window_attributes.width-4), 30);

          /// Menuleiste zeichnen
          XDrawLine (mydisplay, mywindow, gc_menu_border_bottom, 0, 21, window_attributes.width, 21);
          XDrawLine (mydisplay, mywindow, gc_menu_border_bottom, (window_attributes.width-1), 1, (window_attributes.width-1), 21);
          XFillRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, 1, 1, (window_attributes.width-2), 20);

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
            //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, Anwendung.menu_bar1.Datei.name, strlen(Anwendung.menu_bar1.Datei.name));
            //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, str_test, strlen(str_test));
            //XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, mygc, 50, 50, Anwendung.menu_bar1.menu1.name, strlen(Anwendung.menu_bar1.menu1.name));
          //}
          indent_x = 0;
          indent_y = 0;
          indent_menu_item_x = 0;
          for (count_menu=0;count_menu<5;count_menu++) {
            if (strlen(Anwendung.menu_bar1.menus[count_menu].name)>0) {
              XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, gc_menu_font, (5+indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, strlen(Anwendung.menu_bar1.menus[count_menu].name));

              for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {
                if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                  indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                }
              }

              for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {
                if (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)>0) {
                  indent_y = indent_y + 17;
                  //if ((strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                  //  XFillRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                  //  indent_menu_item_x = (strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                  //
                  //}
                  //XFillRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);
                  XFillRectangle (myevent.xexpose.display, myevent.xexpose.window, gc_menu, (3+indent_x), 20 + (count_item*17), indent_menu_item_x, 19);
                  XDrawImageString (myevent.xexpose.display, myevent.xexpose.window, gc_menu_font, (5+indent_x), 33 + (count_item*17), Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name, strlen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                }

              }
              if (Anwendung.menu_bar1.menus[count_menu].angeklickt==1) {
                XDrawLine (mydisplay, mywindow, gc_menu_border_bottom, (3+indent_x), (21+indent_y), (3+indent_x+indent_menu_item_x), (21+indent_y));
                XDrawLine (mydisplay, mywindow, gc_menu_border_bottom, (3+indent_x+indent_menu_item_x), 20, (3+indent_x+indent_menu_item_x), (21+indent_y));

                XDrawLine (mydisplay, mywindow, gc_menu_border_top, (3+indent_x), 19, (3+indent_x+indent_menu_item_x), 19);
                XDrawLine (mydisplay, mywindow, gc_menu_border_top, (3+indent_x), 19, (3+indent_x), (20+indent_y));

              }

              indent_x = indent_x + (strlen(Anwendung.menu_bar1.menus[count_menu].name) * 6) +10;
            }

          }
        }
        break;

      // Abbildungsaenderungen der Tastatur verarbeiten
      case MappingNotify:
        XRefreshKeyboardMapping (&myevent);
        break;

      // Druecken der Maustaste verarbeiten
      case ButtonPress: {
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
      break;
      }


      // Tastatureingaben verarbeiten
      case KeyPress:
        i = XLookupString ( &myevent, text, 10, &mykey, 0);
        //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
        //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte
        if (i == 1 && text[0] == 'a') {
          XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
          Anwendung.menu_bar1.menus[0].angeklickt = 1;
          Anwendung.menu_bar1.menus[1].angeklickt = 0;
          Anwendung.menu_bar1.menus[2].angeklickt = 0;
        }
        else if (i == 1 && text[0] == 'b') {
          XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
          Anwendung.menu_bar1.menus[0].angeklickt = 0;
          Anwendung.menu_bar1.menus[1].angeklickt = 1;
          Anwendung.menu_bar1.menus[2].angeklickt = 0;
        }
        else if (i == 1 && text[0] == 'c') {
          XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
          Anwendung.menu_bar1.menus[0].angeklickt = 0;
          Anwendung.menu_bar1.menus[1].angeklickt = 0;
          Anwendung.menu_bar1.menus[2].angeklickt = 1;
        }
        if (i == 1 && text[0] == 'x') {
          XClearArea (mydisplay, mywindow, 0, 0, 0, 0, True);
          Anwendung.menu_bar1.menus[0].angeklickt = 0;
          Anwendung.menu_bar1.menus[1].angeklickt = 0;
          Anwendung.menu_bar1.menus[2].angeklickt = 0;
        }
        else if ( i == 1 && text[0] == 'q') done = 1;
        break;

    } // switch (myevent.type)
  } // while

  // Terminierung
  XFreeGC (mydisplay, mygc);
  XDestroyWindow (mydisplay, mywindow);
  XCloseDisplay (mydisplay);

  exit(0);
}
