/*
 * $RCSfile: terminal_foreground_mapper.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.6 $ $Date: 2006-04-20 22:36:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_FOREGROUND_MAPPER_SOURCE
#define TERMINAL_FOREGROUND_MAPPER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Maps the terminal foreground colour name to its control sequence code.
 *
 * @param p0 the destination control sequence code
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source colour name
 * @param p4 the source count
 */
void mapto_terminal_foreground(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != NULL_POINTER) {

        int* dc = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** d = (void**) p0;

            // The comparison result.
            int r = 0;

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_BLACK_MODEL, TERMINAL_COLOUR_BLACK_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = BLACK_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *BLACK_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_RED_MODEL, TERMINAL_COLOUR_RED_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = RED_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *RED_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_GREEN_MODEL, TERMINAL_COLOUR_GREEN_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = GREEN_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *GREEN_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_YELLOW_MODEL, TERMINAL_COLOUR_YELLOW_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = YELLOW_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *YELLOW_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_BLUE_MODEL, TERMINAL_COLOUR_BLUE_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = BLUE_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *BLUE_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_MAGENTA_MODEL, TERMINAL_COLOUR_MAGENTA_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = MAGENTA_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *MAGENTA_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_COBALT_MODEL, TERMINAL_COLOUR_COBALT_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = COBALT_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *COBALT_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_WHITE_MODEL, TERMINAL_COLOUR_WHITE_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    *d = WHITE_FOREGROUND_CONTROL_SEQUENCE;
                    *dc = *WHITE_FOREGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

        } else {

            log_message_debug("Could not map terminal foreground colour name to its control sequence code. The destination is null.");
        }

    } else {

        log_message_debug("Could not map terminal foreground colour name to its control sequence code. The destination count is null.");
    }
}

/**
 * Maps the terminal foreground colour name from its control sequence code.
 *
 * @param p0 the destination colour name
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source control sequence code
 * @param p4 the source count
 */
void mapfrom_terminal_foreground(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* TERMINAL_FOREGROUND_MAPPER_SOURCE */
#endif
