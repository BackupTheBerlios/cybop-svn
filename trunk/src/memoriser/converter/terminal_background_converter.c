/*
 * $RCSfile: terminal_background_converter.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2008-05-04 00:18:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_BACKGROUND_CONVERTER_SOURCE
#define TERMINAL_BACKGROUND_CONVERTER_SOURCE

#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Decodes the control sequence code into a terminal background colour name.
 *
 * @param p0 the destination colour name
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source control sequence code
 * @param p4 the source count
 */
void decode_terminal_background(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the terminal background colour name into a control sequence code.
 *
 * @param p0 the destination control sequence code
 * @param p1 the destination control sequence code count
 * @param p2 the destination control sequence code size
 * @param p3 the source colour name
 * @param p4 the source colour name count
 */
void encode_terminal_background(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER) {

            void** d = (void**) p0;

            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_BLACK_MODEL, TERMINAL_COLOUR_BLACK_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = BLACK_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *BLACK_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_RED_MODEL, TERMINAL_COLOUR_RED_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = RED_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *RED_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_GREEN_MODEL, TERMINAL_COLOUR_GREEN_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = GREEN_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *GREEN_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_YELLOW_MODEL, TERMINAL_COLOUR_YELLOW_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = YELLOW_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *YELLOW_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_BLUE_MODEL, TERMINAL_COLOUR_BLUE_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = BLUE_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *BLUE_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_MAGENTA_MODEL, TERMINAL_COLOUR_MAGENTA_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = MAGENTA_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *MAGENTA_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_COBALT_MODEL, TERMINAL_COLOUR_COBALT_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = COBALT_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *COBALT_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, TERMINAL_COLOUR_WHITE_MODEL, TERMINAL_COLOUR_WHITE_MODEL_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    *d = WHITE_BACKGROUND_CONTROL_SEQUENCE;
                    *dc = *WHITE_BACKGROUND_CONTROL_SEQUENCE_COUNT;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode terminal background. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode terminal background. The destination count is null.");
    }
}

/* TERMINAL_BACKGROUND_CONVERTER_SOURCE */
#endif
