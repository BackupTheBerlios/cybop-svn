/*
 * $RCSfile: integer_converter.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2005-07-25 21:01:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_CONVERTER_SOURCE
#define INTEGER_CONVERTER_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/allocator/integer_allocator.c"

/**
 * Parses the byte stream and creates an integer model from it.
 *
 * @param p0 the destination integer number (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source character array
 * @param p4 the source count
 */
void parse_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER ) {

            void** d = (void**) p0;

            log_message_debug("Parse integer.");

            // The temporary null-terminated string.
            char* tmp = NULL_POINTER;
            int tmps = *sc + 1;

            // Create temporary null-terminated string.
            allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

            // The index.
            int i = 0;

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) &i, p3, p4, (void*) CHARACTER_ARRAY);

            // This is used as index to set the termination character.
            i = *sc;

            // Add string termination to temporary null-terminated string.
            set_array_elements((void*) tmp, (void*) &i, (void*) NULL_CONTROL_CHARACTER, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            char* tail = NULL_POINTER;

            // Transform string to integer value.
            // The third parameter is the number base:
            // 0 - tries to automatically identify the correct number base
            // 8 - octal
            // 10 - decimal
            // 16 - hexadecimal
            int v = strtol(tmp, &tail, 10);

            //?? p0 (Hand over as reference!)
            //?? Doesn't p0 need to be resized from size 0 to size 1,
            //?? to be able to take the double value?

            // Set integer value.
            set_array_elements(*d, (void*) INTEGER_VALUE_INDEX, (void*) &v, (void*) NUMBER_1_INTEGER, (void*) INTEGER_ARRAY);

            // Destroy temporary null-terminated string.
            deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

        } else {

            log_message_debug("Could not parse integer. The destination is null.");
        }

    } else {

        log_message_debug("Could not parse integer. The source count is null.");
    }
}

/**
 * Serialises the integer model and creates a byte stream from it.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source integer number
 * @param p4 the source count
 */
void serialise_integer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != NULL_POINTER) {

                char** d = (char**) p0;

                log_message_debug("Serialise integer.");

                // The integer value.
                int* v = INTEGER_NULL_POINTER;

                // Get integer value.
                get_array_elements(p3, (void*) INTEGER_VALUE_INDEX, (void*) &v, (void*) INTEGER_ARRAY);

                //?? TODO: set_array_elements is missing!
                //?? The get_array_elements procedure does NOT copy values;
                //?? it returns just a reference to the corresponding value!

                // Transform source integer to destination string.
                *dc = snprintf(*d, *ds, "%i", *v);

                // Set destination string size one greater than the count
                // to have space for the terminating null character.
                *ds = *dc + 1;

                // Resize destination string.
                resize_array(p0, p2, (void*) CHARACTER_ARRAY);

                // Transform source integer to destination string.
                *dc = snprintf(*d, *ds, "%i", *v);

                // CAUTION! Recalculate string count because only in versions
                // of the GNU C library prior to 2.1, the snprintf function
                // returns the number of characters stored, not including the
                // terminating null; unless there was not enough space in the
                // string to store the result in which case -1 is returned.
                // This was CHANGED in order to comply with the ISO C99 standard.
                // As usual, the string count does NOT contain the terminating
                // null character.
                *dc = strlen(*d);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/* INTEGER_CONVERTER_SOURCE */
#endif
