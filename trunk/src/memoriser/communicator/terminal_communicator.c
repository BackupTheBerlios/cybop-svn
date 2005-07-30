/*
 * $RCSfile: terminal_communicator.c,v $
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
 * This file contains the functionality to:
 * - receive a file stream into a byte array
 * - send a file stream from a byte array
 *
 * @version $Revision: 1.5 $ $Date: 2005-07-30 14:03:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_COMMUNICATOR_SOURCE
#define TERMINAL_COMMUNICATOR_SOURCE

#include <stdio.h>
//?? #include "../../globals/constants/character_constants.c"
//?? #include "../../globals/constants/constant.c"
//?? #include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
//?? #include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
//?? #include "../../memoriser/array.c"

/**
 * Reads the terminal into terminal control sequences.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source terminal
 * @param p4 the source count
 */
void read_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //?? getc(stdin);
}

/**
 * Writes the terminal control sequences into terminal.
 *
 * @param p0 the destination terminal (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source terminal control sequences
 * @param p4 the source count
 */
void write_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != NULL_POINTER) {

        char* s = (char*) p3;

        if (p0 != NULL_POINTER) {

            FILE** d = (FILE**) p0;

            log_message_debug("Write to terminal.");

            // Write to terminal.
            fputs(s, *d);

            //?? TODO: temporary. Move to receive loop into an own thread!?
            getc(stdin);

        } else {

            log_message_debug("Could not write to terminal. The destination terminal file is null.");
        }

    } else {

        log_message_debug("Could not write to terminal. The source terminal control sequences is null.");
    }

/*??
    char r = NULL_CONTROL_CHARACTER;
    int j = 0;
    char c = NULL_CONTROL_CHARACTER;

    while (1) {

        if (j >= **ds) {

            break;
        }

        if (r == EOF) {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. A write error occured.");

            break;
        }

        get_array_element(p0, (void*) &CHARACTER_ARRAY, (void*) &j, (void*) &c);

        r = fputc(c, f);
        j++;
    }
*/
}

/* TERMINAL_COMMUNICATOR_SOURCE */
#endif
