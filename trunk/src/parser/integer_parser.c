/*
 * $RCSfile: integer_parser.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2004-08-25 07:17:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_PARSER_SOURCE
#define INTEGER_PARSER_SOURCE

#include <stdlib.h>
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Parses the byte stream and creates an integer model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_integer(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            int* d = (int*) p0;

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

            // Transform string to integer.
            // The third parameter is the number base:
            // 0 - tries to automatically identify the correct number base
            // 8 - octal
            // 10 - decimal
            // 16 - hexadecimal
            *d = strtol(tmp, &tail, 10);

//??            double example:
//??            test = strtod(tmp, &tail);

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
 * Serializes the integer model and creates a byte stream from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_integer(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p3 != NULL_POINTER) {

        int* s = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

//??                    log_message((void*) &INFO_LOG_LEVEL, (void*) &SERIALIZE_INTEGER_MESSAGE, (void*) &SERIALIZE_INTEGER_MESSAGE_COUNT);

                    // Transform integer to string.
                    // A temporary null-terminated string gets created inside.
//??                    *d = (void*) itoa(*s);
//?? USE sprintf here!
//??    fprintf(p1, %i, &(m->value));

                    // Determine temporary null-terminated string size and count.
                    *ds = sizeof((char*) *d);
                    *dc = strlen((char*) *d);

                    // Reduce temporary null-terminated string count by one so that
                    // the string termination is not considered.
                    (*dc)--;

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_IS_NULL_MESSAGE_COUNT);
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
    }
}

/* INTEGER_PARSER_SOURCE */
#endif
