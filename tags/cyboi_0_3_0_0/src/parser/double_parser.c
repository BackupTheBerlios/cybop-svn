/*
 * $RCSfile: double_parser.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.3 $ $Date: 2004-09-11 22:19:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_PARSER_SOURCE
#define DOUBLE_PARSER_SOURCE

#include <stdio.h>
#include <stdlib.h>
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

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            double* d = (double*) p0;

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &PARSE_INTEGER_MESSAGE, (void*) &PARSE_INTEGER_MESSAGE_COUNT);

            // The temporary null-terminated string.
            char* tmp = NULL_POINTER;
            int tmps = *sc + 1;
            // The index.
            int i = 0;

            // Create temporary null-terminated string.
            create_array((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &tmps);

            // Copy original string to temporary null-terminated string.
            set_array_elements((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);
            // This is used as index to set the termination character.
            i = *sc;
            // Add string termination to temporary null-terminated string.
            set_array_element((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &NULL_CHARACTER);

            // The tail variable is useless here and only needed for the string
            // transformation function. If the whole string array consists of
            // many sub strings, separated by space characters, then each sub
            // string gets interpreted as integer number.
            // The tail variable in this case points to the remaining sub string.
            char* tail = NULL_POINTER;

            // Transform string to double.
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
            *d = strtod(tmp, &tail);

            // Destroy temporary null-terminated string.
            destroy_array((void*) &tmp, (void*) &CHARACTER_ARRAY, (void*) &tmps);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
        }

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
}

/* DOUBLE_PARSER_SOURCE */
#endif
