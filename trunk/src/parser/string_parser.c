/*
 * $RCSfile: string_parser.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2004-08-23 07:18:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRING_PARSER_SOURCE
#define STRING_PARSER_SOURCE

#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

//
// A string is a chain of characters.
//

/**
 * Parses the byte stream and creates a string model from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_string(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                // The destination array index.
                int i = 0;

                // The new destination array size.
                // (Not exactly the size, but the destination array index
                // increased by the source array count.)
                int nds = i + *sc;

                if (i >= 0) {

//??                log_message((void*) &INFO_LOG_LEVEL, (void*) &INITIALIZE_STRING_MESSAGE, (void*) &INITIALIZE_STRING_MESSAGE_COUNT);

                    if (nds >= *ds) {

                        while (nds >= *ds) {

                            // Increase size.
                            *ds = (*ds * STRING_RESIZE_FACTOR) + 1;
                        }

                        // Resize string.
                        resize_array(p0, (void*) &CHARACTER_ARRAY, p2);
                    }

                    if (i < (*ds - *sc)) {

                        // Set string.
                        // CAUTION! Parameter is only set, when not null.

                        if (p3 != NULL_POINTER) {

                            set_array_elements(p0, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);
                        }

                        // Increment count.
                        // Example:
                        // d = "helloworld"
                        // i = 5
                        // s = "universe"
                        // sc = 8
                        // d (after set) = "hellouniverse"
                        // dc = i + sc = 13
                        *dc = i + *sc;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index exceeds the size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_COUNT_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_DESTINATION_SIZE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serializes the string model and creates a byte stream from it.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_string(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* STRING_PARSER_SOURCE */
#endif
