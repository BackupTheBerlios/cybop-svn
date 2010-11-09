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
 * @version $RCSfile: detector.c,v $ $Revision: 1.3 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DETECTOR_SOURCE
#define DETECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/converter/encoder/model_diagram_encoder.c"
#include "../../logger/logger.c"

/**
 * Moves the detector's current parsing position.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 * @param p2 the element count
 * @param p3 the primitive type size
 */
void detect_move_position(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ac = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ec = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* rem = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pos = (void**) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Move detector position.");

                    // Increment current position.
                    *pos = *pos + (*ec * *ac);

                    // Decrement remaining count.
                    *rem = *rem - *ec;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not move detector position. The current position is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not move detector position. The remaining count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not move detector position. The element count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not move detector position. The element type size is null.");
    }
}

/**
 * Detects the given element.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 * @param p3 the element
 * @param p4 the element count
 * @param p5 the abstraction
 * @param p6 the primitive type size
 */
void detect_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* ec = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* rem = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                void** pos = (void**) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    int* r = (int*) p0;

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect element.");

                    if (*rem >= *ec) {

                        compare_equal_arrays(p0, *pos, p4, p3, p4, p5);

                        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_move_position(p1, p2, p4, p6);
                        }

                    } else {

                        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not detect element. The remaining count is too small.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect element. The comparison result is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect element. The current position is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect element. The remaining count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect element. The element count is null.");
    }
}

/**
 * Detects the given element.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 * @param p3 the element
 * @param p4 the element count
 * @param p5 the element abstraction
 * @param p6 the element abstraction count
 */
void detect(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Detect.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_element(p0, p1, p2, p3, p4, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CHARACTER_PRIMITIVE_SIZE);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p5, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_element(p0, p1, p2, p3, p4, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }
    }

    // Further comparisons may follow here, if needed. For example, for:
    // DOUBLE_MEMORY_ABSTRACTION
    // INTEGER_MEMORY_ABSTRACTION
    // etc.
}

/* DETECTOR_SOURCE */
#endif
