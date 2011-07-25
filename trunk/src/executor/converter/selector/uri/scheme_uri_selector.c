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

#ifndef SCHEME_URI_SELECTOR_SOURCE
#define SCHEME_URI_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../constant/name/uri/separator_uri_name.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the uri scheme.
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
void select_uri_scheme(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* b = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select uri scheme.");

        //
        // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
        //

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // This detection of (colon, solidus, solidus) is necessary,
        // in order to move the position pointer to the beginning of
        // the authority starting AFTER the two slashes.
        // All functions processing the authority afterwards do
        // expect it WITHOUT double slash at the beginning.

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_array((void*) &r, p7, p8, (void*) SCHEME_WITH_AUTHORITY_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SCHEME_WITH_AUTHORITY_SEPARATOR_URI_NAME_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        // Only if the sequence (colon, solidus, solidus) could not be found,
        // try detecting the scheme end separator (colon) alone.
        // The scheme "file", for example, may be given without authority,
        // but with path.

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            detect_array((void*) &r, p7, p8, (void*) SCHEME_END_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) SCHEME_END_SEPARATOR_URI_NAME_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set break flag.
                *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select uri scheme. The break flag is null.");
    }
}

/* SCHEME_URI_SELECTOR_SOURCE */
#endif
