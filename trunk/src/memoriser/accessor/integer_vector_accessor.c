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
 * @version $RCSfile: integer_vector_accessor.c,v $ $Revision: 1.13 $ $Date: 2009-01-17 15:56:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_ACCESSOR_SOURCE
#define INTEGER_VECTOR_ACCESSOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Appends the source- to the destination integer vector.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void append_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append integer vector.");

                    // Set destination size.
                    *ds = *dc + *sc;

                    // Reallocate destination vector.
                    reallocate_array(p0, p1, p2, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

                    // Append source- to destination vector.
                    //
                    // CAUTION! Do NOT set the destination count above
                    // (together with the destination size),
                    // because it is used here as index!
                    set_array_elements(*d, p1, p3, p4, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

                    // Set destination count to the same value as the -size.
                    *dc = *ds;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append integer vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append integer vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append integer vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append integer vector. The source count is null.");
    }
}

/**
 * Sets the integer vector element.
 *
 * @param p0 the integer vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void set_integer_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set integer vector element.");

    set_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Removes the integer vector element.
 *
 * @param p0 the integer vector
 * @param p1 the size
 * @param p2 the index
 */
void remove_integer_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove integer vector element.");

    remove_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Gets the integer vector element.
 *
 * @param p0 the integer vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void get_integer_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get integer vector element.");

    get_array_elements(p0, p1, p2, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);
}

/* INTEGER_VECTOR_ACCESSOR_SOURCE */
#endif
