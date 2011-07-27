/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef INTEGER_VECTOR_DECODER_SOURCE
#define INTEGER_VECTOR_DECODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/converter/decoder/integer_decoder.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Decodes the wide character array and creates an integer vector model from it.
 *
 * CAUTION! Do not mix up "integer" and "integer_vector"!
 * The latter is an array storing one or many integer numbers at different indexes.
 *
 * @param p0 the destination integer vector (Hand over as reference!)
 * @param p1 the destination integer vector count
 * @param p2 the destination integer vector size
 * @param p3 the source wide character array
 * @param p4 the source wide character array count
 */
void decode_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode integer vector.");

                    // CAUTION! This check is necessary since otherwise,
                    // the array border gets crossed and a comma might be found
                    // that actually does not belong to the array.
                    if (*sc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The comma index.
                        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
                        // The first element count.
                        int fec = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The integer value.
                        int v = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Find comma character index.
                        get_array_elements_index((void*) &i, p3, p4, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                        if (i > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Set first element count to comma index only if a comma
                            // was found at a position greater than the zero index.
                            fec = i;

                        } else {

                            // Set first element count to source count,
                            // if no comma was found (i == -1)
                            // or if the string started with a comma (i == 0).
                            fec = *sc;
                        }

                        // The variable fec is in any case greater than zero.
                        // Either, it is equal to the source count, which was checked
                        // to be greater than zero above, or it is the comma index,
                        // in which case it is also greater than zero.

                        // Decode integer.
                        //
                        // Example:
                        // Vector elements: "200,300,400"
                        // The number 200 character array length is 3.
                        // Index of first comma: 3
                        // Handed over as first element source count fec: index i
                        // (which is 3, as needed for the length)
                        decode_integer((void*) &v, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p3, (void*) &fec);

                        overwrite_array(p0, (void*) &v, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);

                        if (i > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // If a comma (at a later than the first position) was found,
                            // then process the remaining integer vector elements.

                            // The next vector element.
                            //
                            // Example:
                            // Character vector elements: "200,300,400"
                            // The number 200 character array length is 3.
                            // Index of first comma: 3
                            // Next vector element starts at index: 4
                            // (which is the comma index plus 1)
                            //
                            // CAUTION! Do ONLY multiply the summand for the element pointer with the type size,
                            // but NOT the subtrahend for the element count!
                            void* e = p3 + ((i + *NUMBER_1_INTEGER_MEMORY_MODEL) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                            int ec = *sc - (i + *NUMBER_1_INTEGER_MEMORY_MODEL);

                            // Recursively call this function.
                            decode_integer_vector(p0, p1, p2, e, (void*) &ec);
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer vector. The source count is zero (or smaller).");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer vector. The source count is null.");
    }
}

/* INTEGER_VECTOR_DECODER_SOURCE */
#endif
