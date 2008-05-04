/*
 * $RCSfile: fraction_converter.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2008-05-04 00:18:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRACTION_CONVERTER_SOURCE
#define FRACTION_CONVERTER_SOURCE

#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"

//
// A fraction consists of two integers, a numerator and a denominator.
//
// For higher performance, it is mostly better to use floating point numbers
// (float) which can be calculated by the Arithmetic Logic Unit (ALU).
//

/**
 * Decodes the byte stream and creates a fraction model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_fraction(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

/*??
            //??    log_message((void*) &INFORMATION_LOG_LEVEL, (void*) &"Initialise fraction.");

            //??    sscanf(p1, %l, (void*) &(m->value));

                // Initialise elements.
                int d = *NUMBER_0_INTEGER;
                int n = *NUMBER_0_INTEGER;

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
 * Encodes the fraction model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_fraction(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    //?? log_message((void*) &INFORMATION_LOG_LEVEL, (void*) &"Finalise fraction.");

    // Initialise elements.
    int d = *NUMBER_0_INTEGER;
    int n = *NUMBER_0_INTEGER;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DENOMINATOR_INDEX, (void*) &d);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &NUMERATOR_INDEX, (void*) &n);

    // Remove elements.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT, (void*) &DENOMINATOR_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT, (void*) &NUMERATOR_INDEX);

//??    sprintf(p1, %l, (void*) &(m->value));
*/
}

/* FRACTION_CONVERTER_SOURCE */
#endif
