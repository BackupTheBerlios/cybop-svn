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

#ifndef NAME_KNOWLEDGE_SELECTOR_SOURCE
#define NAME_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

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
// so that they now point to the first character FOLLOWING the detected character sequence.
// Any "decode" function called afterwards can rely on this and start processing right away.
//

/**
 * Selects the knowledge name.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_knowledge_name(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select knowledge name.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // The "." or "#" indicate that a new sub part or meta property begins.
    // They thus get detected as delimiter of the current part name.

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! Do NOT move the position (last parametre) here,
        // since the "." has to be DETECTED AGAIN later for
        // determining the correct knowledge branch (model).
        detect_array((void*) &r, p1, p2, (void*) PART_SEPARATOR_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_SEPARATOR_CYBOL_NAME_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set break flag.
            copy_integer(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! Do NOT move the position (last parametre) here,
        // since the "#" has to be DETECTED AGAIN later for
        // determining the correct knowledge branch (details).
        detect_array((void*) &r, p1, p2, (void*) META_SEPARATOR_CYBOL_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) META_SEPARATOR_CYBOL_NAME_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set break flag.
            copy_integer(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Move position by one if nothing was found.
        move_position(p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    }
}

/* NAME_KNOWLEDGE_SELECTOR_SOURCE */
#endif
