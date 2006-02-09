/*
 * $RCSfile: wide_character_vector_converter.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2006-02-09 02:22:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIDE_CHARACTER_VECTOR_CONVERTER_SOURCE
#define WIDE_CHARACTER_VECTOR_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Parses the byte stream and creates a wide character vector model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_wide_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

                    if (*dc >= 0) {

                        log_message_debug("Parse wide character vector.");

                        // The new destination wide character vector size.
                        // (Not exactly the size, but the destination character vector index
                        // increased by the source array count.)
                        *ds = *dc + *sc;

                        // Reallocate destination wide character vector.
                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);

                        if (*dc <= (*ds - *sc)) {

                            // Set source into destination wide character vector.
                            set_array_elements(*d, p1, p3, p4, (void*) WIDE_CHARACTER_ARRAY);

                            // Increment count.
                            // Example:
                            // d = "helloworld"
                            // dc (as index) = 5
                            // s = "universe"
                            // sc = 8
                            // d (after set) = "hellouniverse"
                            // dc = dc + sc = 13
                            // CAUTION! This example presumes normal one-byte
                            // characters as source. Wide characters occupy
                            // more bytes in a file/memory, but the principle
                            // of conversion and counting is the same.
                            *dc = *dc + *sc;

                        } else {

                            log_message_debug("Could not parse wide character vector. The destination count exceeds the size.");
                        }

                    } else {

                        log_message_debug("Could not parse wide character vector. The destination count is negative.");
                    }

                } else {

                    log_message_debug("Could not parse wide character vector. The destination is null.");
                }

            } else {

                log_message_debug("Could not parse wide character vector. The destination count is null.");
            }

        } else {

            log_message_debug("Could not parse wide character vector. The destination size is null.");
        }

    } else {

        log_message_debug("Could not parse wide character vector. The source count is null.");
    }
}

/**
 * Serialises the wide character vector model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialise_wide_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* WIDE_CHARACTER_VECTOR_CONVERTER_SOURCE */
#endif
