/*
 * $RCSfile: copy_character_vector.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2007-04-16 15:56:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COPY_CHARACTER_VECTOR_SOURCE
#define COPY_CHARACTER_VECTOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Copies a character vector.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void copy_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** d = (void**) p0;

                    log_message_debug("Copy character vector.");

                    // CAUTION! The destination array needs to be resized not only
                    // if the source array is greater, but also if it is smaller!
                    // If this is not done, false results may occur.
                    // Example: A colour gets copied from source to destination.
                    // The source colour is "red" with a count of 3.
                    // The destination colour is "green" with a count of 5.
                    // If the source colour gets copied to the destination,
                    // the resulting destination array is "reden" with a count of 5.
                    // This colour value does not exist and will cause errors!
                    // Therefore, the destination array count and size ALWAYS
                    // have to be adapted to the source array count and size.
                    // If this had been done in the example, the resulting
                    // destination array would have been "red" with a count of 3,
                    // which is correct.

                    // CAUTION! Do NOT use < or > here, for the reasons explained above!
                    if (*sc != *dc) {

                        *dc = *sc;
                        *ds = *dc;

                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                    }

                    set_array_elements(*d, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);

                } else {

                    log_message_debug("Could not copy character vector. The destination is null.");
                }

            } else {

                log_message_debug("Could not copy character vector. The destination count is null.");
            }

        } else {

            log_message_debug("Could not copy character vector. The destination size is null.");
        }

    } else {

        log_message_debug("Could not copy character vector. The source count is null.");
    }
}

/* COPY_CHARACTER_VECTOR_SOURCE */
#endif
