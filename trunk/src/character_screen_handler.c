/*
 * $RCSfile: character_screen_handler.c,v $
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

#include <stdio.h>

/**
 * This is the character screen handler.
 *
 * It contains functionality for the input and output of data using a
 * character-based screen.
 *
 * Synonyms and Keywords:
 * - Textual User Interface (TUI)
 * - Curses (termcap, ncurses)
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Character screen.
//

/**
 * Send character screen signal to communication partner (probably the human user).
 */
static void send_character_screen() {
    
    fflush(stdout);
}

/**
 * Builds the character screen.
 *
 * ?? Probably temporary; CYBOI should read hierarchy from CYBOL files later.
 */
static void show_character_screen() {
    
    int i = 0;
    
    while (i < 30) {
        
        fputc(95, stdout);
        i++;
    }
    
    fputc(10, stdout);

    i = 0;
    
    while (i < 20) {
        
        fputc(95, stdout);
        i++;
    }

    fputc(10, stdout);

    send_character_screen();
}

