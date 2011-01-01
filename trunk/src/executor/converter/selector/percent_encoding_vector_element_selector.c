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
 * @version $RCSfile: http_request_selector.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PERCENT_ENCODING_VECTOR_ELEMENT_SELECTOR_SOURCE
#define PERCENT_ENCODING_VECTOR_ELEMENT_SELECTOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/percent_encoding/separator_percent_encoding_name.c"
#include "../../../executor/converter/detector.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

//
// CAUTION! This comment is valid for all "select" functions below.
//
// The comparison result HAS TO BE ZERO (r == 0),
// if a detection is to be taking place!
//
// Many "detect" functions are called in a sequence, below.
// If the result of one detection function was positive (r == 1), then that
// function increments the current position and decrements the remaining count.
// In this case, further detection functions following afterwards might detect
// further characters and CHANGE the current position and remaining count,
// and so forth, which would have the effect of "JUMPING" over some characters
// and produce WRONG RESULTS!
//
// Therefore, the checks for (r == 0) below avoid another detection,
// if the result already has a value unequal zero.
//
// CAUTION! If a detection was successful, then the current position and remaining count
// were already adapted within the corresponding "detect" function (as called below),
// so that they now point to the first character following the detected character sequence.
// Any "decode" function called afterwards can rely on this and start processing right away.
//

/**
 * Selects the percent-encoding vector element.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the break flag
 * @param p4 the current position (Hand over as reference!)
 * @param p5 the remaining count
 */
void select_percent_encoding_vector_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select percent-encoding vector element.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p4, p5, (void*) SEPARATOR_PERCENT_ENCODING_NAME, (void*) SEPARATOR_PERCENT_ENCODING_NAME_COUNT, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p4, p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select percent-encoding vector element. The break flag is null.");
    }
}

/* PERCENT_ENCODING_VECTOR_ELEMENT_SELECTOR_SOURCE */
#endif
