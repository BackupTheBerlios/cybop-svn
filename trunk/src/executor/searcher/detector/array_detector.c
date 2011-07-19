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
 * @version $RCSfile: detector.c,v $ $Revision: 1.3 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_DETECTOR_SOURCE
#define ARRAY_DETECTOR_SOURCE

#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/converter/encoder/model_diagram_encoder.c"
#include "../../logger/logger.c"
#include "../../variable/type_size/integral_type_size.c"

/**
 * Detects the given array.
 *
 * This code was moved into its own function, because:
 * - the current position pointer needs to be dereferenced
 * - the element count and remaining count need to be compared
 *   in order to avoid crossing array boundaries
 * - the current position and remaining count are moved automatically
 *
 * Example calls of this function for ascii characters:
 * detect_element(p0, p1, p2, p3, p4, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE, p7);
 *
 * Example calls of this function for wide characters:
 * detect((void*) &r, p7, p8, (void*) QUERY_PARAMETER_BEGIN_SEPARATOR_URI_NAME, (void*) QUERY_PARAMETER_BEGIN_SEPARATOR_URI_NAME_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 * @param p3 the array
 * @param p4 the abstraction
 * @param p5 the count
 * @param p6 the move flag
 */
void detect_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* m = (int*) p6;

        if (p5 != *NULL_POINTER_MEMORY_MODEL) {

            int* c = (int*) p5;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* rem = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pos = (void**) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* r = (int*) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect array.");

                        // CAUTION! This comparison ensures that array boundaries
                        // of p4 / element count / *ec are not crossed, since p4 is
                        // handed over as count for the source p3 AND destination *pos.
                        if (*rem >= *c) {

                            // CAUTION! The remaining count may NOT be handed over as position count,
                            // since it might be greater than the array count and would thus differ.
                            compare_all_array(p0, *pos, p3, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, p4, p5, p5);

                            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                if (*m != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    move_position(p1, p2, p4, p5);
                                }
                            }

                        } else {

                            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not detect array. The remaining count is smaller than the array count.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect array. The comparison result is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect array. The current position is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect array. The remaining count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect array. The element count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect array. The move flag is null.");
    }
}

/* ARRAY_DETECTOR_SOURCE */
#endif
