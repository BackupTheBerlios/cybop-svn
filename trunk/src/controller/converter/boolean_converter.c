/*
 * $RCSfile: boolean_converter.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2005-06-05 11:12:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_CONVERTER_SOURCE
#define BOOLEAN_CONVERTER_SOURCE

#include "../../globals/constants/constant.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memory/array/array.c"
#include "../../memory/creator/integer_creator.c"

//
// A boolean can have just one of the two values: TRUE or FALSE
// Synonyms are:
// - one and zero
// - 1 and 0
// - on and off
//

/**
 * Parses the byte stream and creates a boolean model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_boolean(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            int** d = (int**) p0;

            log_message_debug("Parse boolean.");

            // The comparison result.
            int r = 0;

            if (*sc == *TRUE_BOOLEAN_COUNT) {

                compare_array_elements(p3, (void*) TRUE_BOOLEAN, (void*) TRUE_BOOLEAN_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    // Set boolean value to 'true'.
                    set_array_elements(*d, (void*) INTEGER_VALUE_INDEX, (void*) ONE_NUMBER, (void*) ONE_NUMBER, (void*) INTEGER_ARRAY);
                }
            }

            if (*sc == *FALSE_BOOLEAN_COUNT) {

                compare_array_elements(p3, (void*) FALSE_BOOLEAN, (void*) FALSE_BOOLEAN_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    // Set boolean value to 'true'.
                    set_array_elements(*d, (void*) INTEGER_VALUE_INDEX, (void*) ZERO_NUMBER, (void*) ONE_NUMBER, (void*) INTEGER_ARRAY);
                }
            }


        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serializes the boolean model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_boolean(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p3 != NULL_POINTER) {

        int* s = (int*) p3;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            log_message_debug("Serialize boolean.");

            if (*s == 1) {

/*??
                set_array_elements(TRUE_BOOLEAN ...);
                set_size
                set_count
*/

            } else {

/*??
                set_array_elements(FALSE_BOOLEAN ...);
                set_size
                set_count
*/
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/* BOOLEAN_CONVERTER_SOURCE */
#endif