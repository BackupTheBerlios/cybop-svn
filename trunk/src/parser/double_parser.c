/*
 * $RCSfile: double_parser.c,v $
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
 * @version $Revision: 1.9 $ $Date: 2005-01-10 23:54:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_PARSER_SOURCE
#define DOUBLE_PARSER_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "../creator/integer_creator.c"
#include "../creator/double_creator.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

//
// A double is a floating point number.
//

/**
 * Parses the byte stream and creates a double model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_double(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int** sc = (int**) p4;

//??        log_message((void*) &INFO_LOG_LEVEL, (void*) &PARSE_INTEGER_MESSAGE, (void*) &PARSE_INTEGER_MESSAGE_COUNT);

        // The temporary null-terminated string.
        char* tmp = NULL_POINTER;

        // The temporary null-terminated string size.
        int* tmps = INTEGER_NULL_POINTER;
        create_integer((void*) &tmps);
        *tmps = **sc + 1;

        // The index.
        int* i = INTEGER_NULL_POINTER;
        create_integer((void*) &i);
        *i = 0;

        // Create temporary null-terminated string.
        create_array((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &tmps);

        // Copy original string to temporary null-terminated string.
        set_array_elements((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);
        // This is used as index to set the termination character.
        *i = **sc;
        // Add string termination to temporary null-terminated string.
        set_array_elements((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &NULL_CONTROL_CHARACTER, (void*) &ONE_NUMBER);

        // The tail variable is useless here and only needed for the string
        // transformation function. If the whole string array consists of
        // many sub strings, separated by space characters, then each sub
        // string gets interpreted as integer number.
        // The tail variable in this case points to the remaining sub string.
        char* tail = NULL_POINTER;

        // Transform string to double value.
        // The strtod function recognizes four special input strings.
        // The strings "inf" and "infinity" are converted to @math{@infinity{}},
        // or to the largest representable value if the floating-point format
        // doesn't support infinities.
        // One can prepend a "+" or "-" to specify the sign.
        // Case is ignored when scanning these strings.
        // The strings "nan" and "nan(chars...)" are converted to NaN.
        // Again, case is ignored.
        // If chars... are provided, they are used in some unspecified fashion
        // to select a particular representation of NaN (there can be several).
        double* v = DOUBLE_NULL_POINTER;
        create_double((void*) &v);
        *v = strtod(tmp, &tail);

        // Set double value.
        set_array_elements(p0, (void*) &DOUBLE_ARRAY, (void*) &DOUBLE_VALUE_INDEX, (void*) &v, (void*) &ONE_NUMBER);

        // Destroy temporary null-terminated string.
        destroy_array((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &tmps);

        destroy_double((void*) &v);
        destroy_double((void*) &i);
        destroy_double((void*) &tmps);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serializes the double model and creates a byte stream from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_double(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p2 != NULL_POINTER) {

        int** ds = (int**) p2;

        if (p1 != NULL_POINTER) {

            int** dc = (int**) p1;

            if (p0 != NULL_POINTER) {

                char** d = (char**) p0;

//??                log_message((void*) &INFO_LOG_LEVEL, (void*) &SERIALIZE_DOUBLE_MESSAGE, (void*) &SERIALIZE_DOUBLE_MESSAGE_COUNT);

                // The double value.
                double* v = DOUBLE_NULL_POINTER;

                // Get double value.
                get_array_elements(p3, (void*) &DOUBLE_ARRAY, (void*) &DOUBLE_VALUE_INDEX, (void*) &v);

                // Transform source double to destination string.
                **dc = snprintf(*d, **ds, "%d", *v);

                // Set destination string size one greater than the count
                // to have space for the terminating null character.
                **ds = **dc + 1;

                // Resize destination string.
                resize_array(p0, (void*) &CHARACTER_ARRAY, p2);

                // Transform source double to destination string.
                **dc = snprintf(*d, **ds, "%d", *v);

                // CAUTION! Recalculate string count because only in versions
                // of the GNU C library prior to 2.1, the snprintf function
                // returns the number of characters stored, not including the
                // terminating null; unless there was not enough space in the
                // string to store the result in which case -1 is returned.
                // This was CHANGED in order to comply with the ISO C99 standard.
                // As usual, the string count does NOT contain the terminating
                // null character.
                **dc = strlen(*d);

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

/* DOUBLE_PARSER_SOURCE */
#endif
