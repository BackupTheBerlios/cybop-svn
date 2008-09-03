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
 * @version $RCSfile: ascii_character_vector_converter.c,v $ $Revision: 1.2 $ $Date: 2008-09-03 22:04:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ASCII_CHARACTER_VECTOR_CONVERTER_SOURCE
#define ASCII_CHARACTER_VECTOR_CONVERTER_SOURCE

#include "../../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../../globals/constants/integer/integer_constants.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../globals/variables/reallocation_factor_variables.c"
#include "../../../memoriser/array.c"

/**
 * Decodes the ascii character byte stream and creates a character vector model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_ascii_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    if (*dc >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode ascii character vector.");

                        // The new destination character vector size.
                        // (Not exactly the size, but the destination character vector index
                        // increased by the source array count.)
                        *ds = *dc + *sc;

                        // Reallocate destination character vector.
                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                        if (*dc <= (*ds - *sc)) {

                            // Set source into destination character vector.
                            set_array_elements(*d, p1, p3, p4, (void*) CHARACTER_ARRAY);

                            // Increment count.
                            // Example:
                            // d = "helloworld"
                            // dc (as index) = 5
                            // s = "universe"
                            // sc = 8
                            // d (after set) = "hellouniverse"
                            // dc = dc + sc = 13
                            *dc = *dc + *sc;

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ascii character vector. The destination count exceeds the size.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ascii character vector. The destination count is negative.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ascii character vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ascii character vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ascii character vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ascii character vector. The source count is null.");
    }
}

/**
 * Encodes the character vector model and creates an ascii character byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_ascii_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode ascii character vector.");

                    if ((*dc + *sc) >= *ds) {

                        // The new destination character vector size.
                        // CAUTION! Add constant in case *dc is zero!
                        *ds = (*dc * *CHARACTER_VECTOR_REALLOCATION_FACTOR) + *sc;

                        // Reallocate destination character vector.
                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                    }

                    // Set source into destination character vector.
                    set_array_elements(*d, p1, p3, p4, (void*) CHARACTER_ARRAY);

                    // Increment destination count.
                    *dc = *dc + *sc;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode ascii character vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode ascii character vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode ascii character vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode ascii character vector. The source count is null.");
    }
}

/* ASCII_CHARACTER_VECTOR_CONVERTER_SOURCE */
#endif
