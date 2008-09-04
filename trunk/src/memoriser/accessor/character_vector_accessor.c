/*
 * Copyright (C) 1999-2008. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: character_vector_accessor.c,v $ $Revision: 1.12 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_VECTOR_ACCESSOR_SOURCE
#define CHARACTER_VECTOR_ACCESSOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Sets the source into the destination character.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void set_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set character.");

                    // CAUTION! The destination array needs to be resized not only
                    // if the source array is greater, but also if it is smaller!
                    // If this is not done, false results may occur.
                    //
                    // Example: A colour gets copied from source to destination.
                    // The source colour is "red" with a count of 3.
                    // The destination colour is "green" with a count of 5.
                    // If the source colour gets copied to the destination,
                    // the resulting destination array is "reden" with a count of 5.
                    // This colour value does not exist and will cause errors!
                    //
                    // Therefore, the destination array count and size ALWAYS
                    // have to be adapted to the source array count and size.
                    // If this had been done in the example, the resulting
                    // destination array would have been "red" with a count of 3,
                    // which is correct.

                    // CAUTION! Do NOT use < or > here, for the reasons explained above!
                    if (*sc != *dc) {

                        *dc = *sc;
                        *ds = *dc;

                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                    }

                    set_array_elements(*d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set character elements. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set character elements. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set character elements. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set character elements. The source count is null.");
    }
}

/**
 * Sets the character vector element.
 *
 * @param p0 the character vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void set_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set character vector element.");

    set_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Removes the character vector element.
 *
 * @param p0 the character vector
 * @param p1 the size
 * @param p2 the index
 */
void remove_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove character vector element.");

    remove_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Gets the character vector element.
 *
 * @param p0 the character vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void get_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get character vector element.");

    get_array_elements(p0, p1, p2, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/* CHARACTER_VECTOR_ACCESSOR_SOURCE */
#endif
