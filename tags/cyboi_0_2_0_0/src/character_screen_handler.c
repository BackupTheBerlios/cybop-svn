/*
 * $RCSfile: character_screen_handler.c,v $
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
 * This file handles a character screen.
 *
 * It contains functionality for the input and output of data using a
 * character-based screen.
 *
 * Synonyms and Keywords:
 * - Textual User Interface (TUI)
 * - Curses (termcap, ncurses)
 *
 * @version $Revision: 1.13 $ $Date: 2004-04-21 11:14:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_SCREEN_HANDLER_SOURCE
#define CHARACTER_SCREEN_HANDLER_SOURCE

#include <stdio.h>

//
// Character screen.
//

struct textual_screen {

    void* button;
};

struct button {

    void* size;
    void* label;
};

void create_test(void* p0) {

/*??
    struct textual_screen* s = (struct textual_screen*) p0;
    s->button = (void*) malloc(sizeof(struct button));

    struct button* b = (struct button*) s->button;
    b->size = (void*) malloc(sizeof(struct vector));

    struct vector* v = (struct vector*) b->size;
    v->x = 10;
    v->y = 3;
    v->z = 1;

    b->label = (void*) "Exit";
*/
}

void destroy_test(void* p0) {

/*??
    struct textual_screen* s = (struct textual_screen*) p0;
    struct button* b = (struct button*) s->button;
    struct vector* v = (struct vector*) b->size;

    free(v);
    free(b);
*/
}

void write_button_label(void* p0, void* p1) {

    char* c = (char*) p0;
    FILE* f = (FILE*) p1;

    fputs(c, f);
    fputc(10, stdout);
    fputc(10, stdout);
    fflush(stdout);
}

void paint_button(void* p0, void* p1) {

/*??
    struct vector* s = (struct vector*) p0;
    FILE* f = (FILE*) p1;
    int w = s->x;
    int h = s->y;
    int d = s->z;
    int x_pos = 8;
    int y_pos = 10;
    int z_pos = 0;
    int x = x_pos;
    int y = y_pos;
    int z = z_pos;

    while (z < (z_pos + d)) {

        while (y < (y_pos + h)) {

            while (x < (x_pos + w)) {

                fputc(95, f);

                x++;
            }

            y++;
        }

        z++;
    }

    fputc(10, stdout);
    fputc(10, stdout);
    fflush(stdout);
*/
}

void send_button(void* p0) {

/*??
    struct button* b = (struct button*) p0;
    paint_button(b->size, stdout);
    write_button_label(b->label, stdout);
*/
}

/**
 * Send character screen signal to communication partner (probably the human user).
 *
 * @param p0 the textual screen
 */
void send_textual_screen(void* p0) {

/*??
    struct textual_screen* s = (struct textual_screen*) p0;
    send_button(s->button);
*/
}

/**
 * Tests the textual screen.
 *
 * ?? Probably temporary; CYBOI should read hierarchy from CYBOL files later.
 */
void test_textual_screen() {

/*??
    void* s = (void*) malloc(sizeof(struct textual_screen));
    create_test(s);

    send_textual_screen(s);

    destroy_test(s);
    free(s);
*/
}

/* CHARACTER_SCREEN_HANDLER_SOURCE */
#endif
