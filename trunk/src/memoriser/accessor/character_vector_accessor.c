/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: character_vector_accessor.c,v $ $Revision: 1.15 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
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
 * Replace the destination- with the source character vector.
 *
 * The destination count AND size BOTH take the value of the source
 * character vector COUNT, even if the source size differs from the source count.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void replace_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace character vector.");

                    // Set destination size.
                    *ds = *sc;

                    // Reallocate destination character vector.
                    reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Replace destination- with source character vector.
                    // Use an index with value zero, so that all characters get replaced.
                    set_array_elements(*d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Set destination count to the same value as the -size.
                    *dc = *ds;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace character elements. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace character elements. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace character elements. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace character elements. The source count is null.");
    }
}

/**
 * Appends the source- to the destination character vector.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void append_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append character vector.");

                    // Set destination size.
                    *ds = *dc + *sc;

                    // Reallocate destination character vector.
                    reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Append source- to destination character vector.
                    //
                    // CAUTION! Do NOT set the destination count above
                    // (together with the destination size),
                    // because it is used here as index!
                    set_array_elements(*d, p1, p3, p4, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Set destination count to the same value as the -size.
                    *dc = *ds;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append character vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append character vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append character vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append character vector. The source count is null.");
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
