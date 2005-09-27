/*
 * $RCSfile: x_window_system_communicator.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2005-09-27 08:57:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE
#define X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE

/*??
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../memoriser/array.c"
*/
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"

/**
 * Reads the x window system display into a window.
 *
 * @param p0 the destination window (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source display
 * @param p4 the source count
 */
void read_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Writes the window onto the x window system display.
 *
 * @param p0 the destination display (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source window
 * @param p4 the source count
 */
void write_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

//??            FILE** d = (FILE**) p0;

            log_message_debug("Write to x window system display.");

            // Write to display.

        } else {

            log_message_debug("Could not write to x window system display. The destination display is null.");
        }

    } else {

        log_message_debug("Could not write to x window system display. The source window count is null.");
    }
}

/* X_WINDOW_SYSTEM_COMMUNICATOR_SOURCE */
#endif
