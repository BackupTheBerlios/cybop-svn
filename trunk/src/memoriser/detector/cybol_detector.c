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
 * @version $RCSfile: cybol_detector.c,v $ $Revision: 1.1 $ $Date: 2008-12-23 22:37:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_DETECTOR_SOURCE
#define CYBOL_DETECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"

/**
 * Detects the xml attribute value end.
 *
 * @param p0 the comparison result
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void detect_xml_attribute_value_end(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* r = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect xml attribute value end.");

                if (*rem >= *ATTRIBUTE_VALUE_END_XML_NAME_COUNT) {

                    compare_arrays(*pos, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, (void*) ATTRIBUTE_VALUE_END_XML_NAME, (void*) ATTRIBUTE_VALUE_END_XML_NAME_COUNT, p0, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Increment current position.
                        *pos = *pos + (*ATTRIBUTE_VALUE_END_XML_NAME_COUNT * *POINTER_PRIMITIVE_SIZE);

                        // Decrement remaining count.
                        *rem = *rem - *ATTRIBUTE_VALUE_END_XML_NAME_COUNT;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The remaining count is too small.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The comparison result is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not detect xml attribute value end. The remaining count is null.");
    }
}

/* CYBOL_DETECTOR_SOURCE */
#endif
