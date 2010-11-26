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
 * @version $RCSfile: http_request_selector.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef METHOD_HTTP_REQUEST_SELECTOR_SOURCE
#define METHOD_HTTP_REQUEST_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/separator_http_name.c"
#include "../../../../executor/converter/detector.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

//
// Forward declarations.
//

void process_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

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
// Any "process" function called afterwards can rely on this and start processing right away.
//

/**
 * Selects the http request method.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the break flag
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void select_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request method.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect((void*) &r, p7, p8, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                process_http_request_uri(p0, p1, p2, p3, p4, p5, p7, p8);

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request method. The break flag is null.");
    }
}

/* METHOD_HTTP_REQUEST_SELECTOR_SOURCE */
#endif
