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
 * @version $RCSfile: xml_selector.c,v $ $Revision: 1.13 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMENT_XML_SELECTOR_SOURCE
#define COMMENT_XML_SELECTOR_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/converter/detector.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the xml comment.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_xml_comment(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml comment.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) COMMENT_END_XML_NAME, (void*) COMMENT_END_XML_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // None of the comparisons above delivered a positive (r != 0) result.
                    // Therefore, increment the current position by one (pointer size).

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml comment. The remaining count is null.");
    }
}

/* COMMENT_XML_SELECTOR_SOURCE */
#endif
