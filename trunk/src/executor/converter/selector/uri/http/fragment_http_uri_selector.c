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
 * @version $RCSfile: http_request_compound_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRAGMENT_HTTP_URI_SELECTOR_SOURCE
#define FRAGMENT_HTTP_URI_SELECTOR_SOURCE

#include "../../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../../constant/model/log/message_log_model.c"
#include "../../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../../constant/name/uri/separator_uri_name.c"
#include "../../../../../executor/converter/detector.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the http uri fragment.
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
void select_http_uri_fragment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http uri fragment.");

        //
        // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http uri fragment. The break flag is null.");
    }
}

/* FRAGMENT_HTTP_URI_SELECTOR_SOURCE */
#endif
