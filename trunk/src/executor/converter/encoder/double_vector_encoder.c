/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: double_vector_converter.c,v $ $Revision: 1.24 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_VECTOR_ENCODER_SOURCE
#define DOUBLE_VECTOR_ENCODER_SOURCE

#include <string.h>
#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Encodes the double model and creates a wide character byte stream from it.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source double number
 * @param p4 the source count
 */
void encode_double(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        size_t* ds = (size_t*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                wchar_t** d = (wchar_t**) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode double into wide character.");

                // The double value.
                double* v = (double*) *NULL_POINTER_MEMORY_MODEL;

                // Get double value.
                get_array_elements(p3, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &v, (void*) DOUBLE_ARRAY_MEMORY_ABSTRACTION);

                // Initialise destination count to -1.
                // CAUTION! It must be negative for the loop to run.
                *dc = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*dc >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        break;
                    }

                    // Initialise destination string count to zero.
                    // CAUTION! This is essential because otherwise,
                    // the array reallocation calculates wrong values.
                    *dc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Set destination string size one greater than the count
                    // to have space for the terminating null character and
                    // to avoid a zero value in case destination string size is zero.
                    *ds = (*dc * *WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;

                    // Reallocate destination string.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Transform source double to destination string.
                    // A null wide character is written to mark the end of the string.
                    // The return value is the number of characters generated
                    // for the given input, excluding the trailing null.
                    // If not all output fits into the provided buffer,
                    // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
                    *dc = wsprintfW(*d, L"%d", *v);
/* CYGWIN_ENVIRONMENT */
#else
                    *dc = swprintf(*d, *ds, L"%d", *v);
/* CYGWIN_ENVIRONMENT */
#endif
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode double into wide character. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode double into wide character. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode double into wide character. The destination size is null.");
    }
}

/**
 * Encodes the double vector model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source vector model
 * @param p4 the source count
 */
void encode_double_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
//??    log_message((void*) &INFORMATION_LEVEL_LOG_MODEL, (void*) &"Finalise double vector.");

    // Write output stream and transform from double vector.

    // Initialise elements.
    int z = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int y = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int x = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get elements.
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
    get_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);

    // Remove elements.
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &Z_INDEX);
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &Y_INDEX);
    remove_array_elements(p0, (void*) INTEGER_ARRAY, (void*) &INTEGER_VECTOR_COUNT, (void*) &X_INDEX);

//??    fwprintf(p1, %d, &(m->x));
//??    fwprintf(p1, %d, &(m->y));
//??    fwprintf(p1, %d, &(m->z));
*/
}

/* DOUBLE_VECTOR_ENCODER_SOURCE */
#endif
