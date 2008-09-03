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
 * @version $RCSfile: integer_vector_converter.c,v $ $Revision: 1.34 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_CONVERTER_SOURCE
#define INTEGER_VECTOR_CONVERTER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../globals/variables/primitive_type_size_variables.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/converter/integer_converter.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

/**
 * Decodes the byte stream and creates an integer vector model from it.
 *
 * CAUTION! Do not mix up "integer" and "integer_vector"!
 * The latter is an array storing one or many integer numbers at different indexes.
 *
 * @param p0 the destination integer vector (Hand over as reference!)
 * @param p1 the destination integer vector count
 * @param p2 the destination integer vector size
 * @param p3 the source byte stream
 * @param p4 the source byte stream count
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
                        int i = *NUMBER_MINUS_1_INTEGER;
                        // The first element count.
                        int fec = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The integer value.
                        int v = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The remaining vector elements.
                        void* e = *NULL_POINTER_MEMORY_MODEL;
                        int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Find comma character index.
                        get_array_elements_index(p3, p4, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) &i, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                        if (i > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Set first element count to comma index only if a comma
                            // was found at a position greater than the zero index.
                            fec = i;

                        } else {

                            // Set first element count to source count, if no comma
                            // was found, or if the string started with a comma.
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
                        decode_integer((void*) &v, *NULL_POINTER, *NULL_POINTER, p3, (void*) &fec);

                        // Check vector size.
                        if (*dc >= *ds) {

                            // Calculate new vector size.
                            //
                            // CAUTION! Add number one as summand at the end to
                            // avoid a zero result, since the initial size is zero!
                            *ds = (*dc * *INTEGER_VECTOR_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER;

                            // Reallocate vector.
                            reallocate(p0, p1, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        }

                        // Set integer value.
                        set_element(*d, (void*) dc, (void*) &v, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                        // Increment integer vector count, because of new element.
                        (*dc)++;

                        if (i > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // If a comma was found, then process the remaining integer vector elements.

                            // The next vector element.
                            //
                            // Example:
                            // Character vector elements: "200,300,400"
                            // The number 200 character array length is 3.
                            // Index of first comma: 3
                            // Next vector element starts at index: 4
                            // (which is the comma index plus 1)
                            e = p3 + (i * *WIDE_CHARACTER_PRIMITIVE_SIZE) + *NUMBER_1_INTEGER;
                            ec = *sc - (i * *WIDE_CHARACTER_PRIMITIVE_SIZE) + *NUMBER_1_INTEGER;

                            // Recursively call this function.
                            decode_integer_vector(p0, p1, p2, e, (void*) &ec);
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer vector. The source count is zero.");
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

/**
 * Encodes the integer vector elements and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source integer vector model
 * @param p4 the source integer vector model count
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
                        // The integer character.
                        void* c = *NULL_POINTER_MEMORY_MODEL;
                        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        int cs = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        if (*sc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Get first integer from vector.
                            get_element(p3, (void*) NUMBER_0_INTEGER, &i, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                            // Encode first integer.
                            encode_integer((void*) &c, (void*) &cc, (void*) &cs, i, (void*) PRIMITIVE_COUNT);

                            // CAUTION! Add one for the comma character added further below!
                            if ((*dc + *NUMBER_1_INTEGER + cc) >= *ds) {

                                // The new destination integer vector size.
                                // CAUTION! Add one for the comma character added further below!
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = (*dc * *INTEGER_VECTOR_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER + cc;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                            }

                            if (*it > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // If this is NOT the first iteration cycle through the source array,
                                // then add a comma character before adding a new integer element,
                                // in order to separate from already existing elements.

                                // Set comma character.
                                set_array_elements(*d, p1, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                *dc = *dc + *PRIMITIVE_MEMORY_MODEL_COUNT;
                            }

                            // Set integer characters.
                            set_array_elements(*d, p1, c, (void*) &cc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                            *dc = *dc + cc;

                            // Determine remaining vector elements.
                            //
                            // CAUTION! The source count has to be greater than zero!
                            // However, this does not have to be checked here,
                            // as it is already checked further above.
                            void* e = p3 + (*NUMBER_1_INTEGER * *INTEGER_PRIMITIVE_SIZE);
                            int ec = *sc - *NUMBER_1_INTEGER;

                            // Increment iteration count.
                            (*it)++;

                            // Recursively call this procedure for further integer numbers.
                            encode_integer_vector_elements(p0, p1, p2, e, (void*) &ec, p5);

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode integer vector elements. The source count is zero.");
                        }

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
 * Encodes the integer vector model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source vector model
 * @param p4 the source count
 */
void encode_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode integer vector.");

    // The iteration count.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Encode integer vector elements.
    // Hand over zero iteration value, since this is the initial call.
    encode_integer_vector_elements(p0, p1, p2, p3, p4, (void*) &i);
}

/* INTEGER_VECTOR_CONVERTER_SOURCE */
#endif
