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
 * @version $RCSfile: integer_vector_converter.c,v $ $Revision: 1.48 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_ENCODER_SOURCE
#define INTEGER_VECTOR_ENCODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/converter/integer_converter.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../variable/primitive_type_size.c"
#include "../../variable/reallocation_factor.c"

/**
 * Encodes the integer vector elements and creates a wide character array from it.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source integer vector
 * @param p4 the source integer vector count
 * @param p5 the iteration count
 */
void encode_integer_vector_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* it = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* sc = (int*) p4;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ds = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* dc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        void** d = (void**) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode integer vector elements.");

                        // The integer.
                        void* i = *NULL_POINTER_MEMORY_MODEL;
                        // The integer wide character.
                        void* c = *NULL_POINTER_MEMORY_MODEL;
                        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        int cs = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Allocate integer wide character.
                        allocate_array((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*sc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Get first integer from vector.
                            get_element(p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, &i, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION);

/*??
    fwprintf(stdout, L"TEST encode integer vector elements 0 i: %i\n", *((int*) i));
    fwprintf(stdout, L"TEST encode integer vector elements 0 cs: %i\n", cs);
    fwprintf(stdout, L"TEST encode integer vector elements 0 cc: %i\n", cc);
    fwprintf(stdout, L"TEST encode integer vector elements 0 c: %ls\n", (wchar_t*) c);
*/

                            // Encode first integer.
                            encode_integer((void*) &c, (void*) &cc, (void*) &cs, i, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

/*??
    fwprintf(stdout, L"TEST encode integer vector elements 1 i: %i\n", *((int*) i));
    fwprintf(stdout, L"TEST encode integer vector elements 1 cs: %i\n", cs);
    fwprintf(stdout, L"TEST encode integer vector elements 1 cc: %i\n", cc);
    fwprintf(stdout, L"TEST encode integer vector elements 1 c: %ls\n", (wchar_t*) c);
*/

                            if (*it > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // If this is NOT the first iteration cycle through the source array,
                                // then add a comma character before adding a new integer element,
                                // in order to separate from already existing elements.

                                // Append comma character.
                                append_wide_character_vector(p0, p1, p2, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
                            }

                            // Append integer characters.
                            append_wide_character_vector(p0, p1, p2, c, (void*) &cc);

                            // Determine remaining vector elements.
                            //
                            // CAUTION! The source count has to be greater than zero!
                            // However, this does not have to be checked here,
                            // as it is already checked further above.
                            //
                            // CAUTION! Do ONLY multiply the summand for the element pointer with the type size,
                            // but NOT the subtrahend for the element count!
                            void* e = p3 + (*PRIMITIVE_MEMORY_MODEL_COUNT * *INTEGER_PRIMITIVE_SIZE);
                            int ec = *sc - *PRIMITIVE_MEMORY_MODEL_COUNT;

                            // Increment iteration count.
                            (*it)++;

                            // Recursively call this procedure for further integer numbers.
                            encode_integer_vector_elements(p0, p1, p2, e, (void*) &ec, p5);

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The source count is zero or smaller.");
                        }

                        // Deallocate integer wide character.
                        // CAUTION! It may be deallocated here, since its content
                        // was copied in the "set_array_elements" function, further above!
                        deallocate_array((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The destination is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The destination count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The destination size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The source count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The iteration count is null.");
    }
}

/**
 * Encodes the integer vector model and creates a wide character array from it.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source integer vector
 * @param p4 the source integer vector count
 */
void encode_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode integer vector.");

    // The iteration count.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Encode integer vector elements.
    // Hand over zero iteration value, since this is the initial call.
    encode_integer_vector_elements(p0, p1, p2, p3, p4, (void*) &i);
}

/* INTEGER_VECTOR_ENCODER_SOURCE */
#endif
