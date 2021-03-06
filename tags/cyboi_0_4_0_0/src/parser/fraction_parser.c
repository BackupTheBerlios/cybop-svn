/*
 * $RCSfile: fraction_parser.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2005-01-19 12:54:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRACTION_PARSER_SOURCE
#define FRACTION_PARSER_SOURCE

#include "../global/log_constants.c"
#include "../logger/logger.c"

//
// A fraction consists of two integers, a numerator and a denominator.
//
// For higher performance, it is mostly better to use floating point numbers
// (float) which can be calculated by the Arithmetic Logic Unit (ALU).
//

/**
 * Parses the byte stream and creates a fraction model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_fraction(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

/*??
            //??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize fraction.");

            //??    sscanf(p1, %l, (void*) &(m->value));

                // Initialize elements.
                int d = 0;
                int n = 0;

                // Set elements.
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &NUMERATOR_INDEX, (void*) &n);
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DENOMINATOR_INDEX, (void*) &d);
*/

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serializes the fraction model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_fraction(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

/*??
            //??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize fraction.");

                // Initialize elements.
                int d = 0;
                int n = 0;

                // Get elements.
                get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DENOMINATOR_INDEX, (void*) &d);
                get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &NUMERATOR_INDEX, (void*) &n);

                // Remove elements.
                remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT, (void*) &DENOMINATOR_INDEX);
                remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT, (void*) &NUMERATOR_INDEX);

            //??    sprintf(p1, %l, (void*) &(m->value));
*/
}

/* FRACTION_PARSER_SOURCE */
#endif
