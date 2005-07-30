/*
 * $RCSfile: mapper.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-07-30 09:38:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MAPPER_SOURCE
#define MAPPER_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/mapper/terminal_background_mapper.c"
#include "../globals/mapper/terminal_foreground_mapper.c"
#include "../memoriser/array.c"

/**
 * Maps the name to its code.
 *
 * @param p0 the destination code
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
void mapto(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            mapto_terminal_background(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            mapto_terminal_foreground(p0, p1, p2, p3, p4);
        }
    }
}

/**
 * Maps the name from its code.
 *
 * @param p0 the destination name
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source code
 * @param p4 the source count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
void mapfrom(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            mapfrom_terminal_background(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            mapfrom_terminal_foreground(p0, p1, p2, p3, p4);
        }
    }
}

/* MAPPER_SOURCE */
#endif
