/*
 * $RCSfile: x_windows_handler.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.25 $ $Date: 2005-03-18 00:42:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOWS_HANDLER_SOURCE
#define X_WINDOWS_HANDLER_SOURCE

#include "../global/includes.c"

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

/* X_WINDOWS_HANDLER_SOURCE */
#endif
