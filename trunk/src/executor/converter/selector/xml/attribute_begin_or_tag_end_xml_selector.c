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

#ifndef ATTRIBUTE_BEGIN_OR_TAG_END_XML_SELECTOR_SOURCE
#define ATTRIBUTE_BEGIN_OR_TAG_END_XML_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the attribute begin or tag end.
 *
 * @param p0 the has attribute flag
 * @param p1 the has content flag
 * @param p2 the is empty flag
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void select_xml_attribute_begin_or_tag_end(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ie = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* hc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* ha = (int*) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml attribute begin or tag end.");

                        //
                        // CAUTION! The ORDER of the following function calls is IMPORTANT!
                        // The empty tag end "/>" has to be searched BEFORE
                        // the simple tag end ">", because of the slash "/" character.
                        //
                        // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
                        // Many "detect" functions are called in a sequence, below.
                        // If the result of one detection function was positive (r == 1),
                        // then that function increments the current position and decrements the remaining count.
                        // In this case, further detection functions following afterwards might detect
                        // further characters and CHANGE the current position and remaining count, and so forth,
                        // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                        // Therefore, the checks for (r == 0) below avoid another detection,
                        // if the result already has a value unequal zero.
                        //

                        // The comparison result.
                        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_array((void*) &r, p3, p4, (void*) EMPTY_TAG_END_XML_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) EMPTY_TAG_END_XML_NAME_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // The empty tag end was found.
                                // Set is empty flag.
                                *ie = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_array((void*) &r, p3, p4, (void*) TAG_END_XML_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) TAG_END_XML_NAME_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // The tag end, indicating subsequent element content, was found.
                                // Set has content flag.
                                *hc = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            detect_array((void*) &r, p3, p4, (void*) ATTRIBUTE_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) ATTRIBUTE_BEGIN_XML_NAME_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // The tag name end, indicating subsequent attributes, was found.
                                // Set has attribute flag.
                                *ha = *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            move_position(p3, p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The has attribute flag is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The has content flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The is empty flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute begin or tag end. The remaining count is null.");
    }
}

/* ATTRIBUTE_BEGIN_OR_TAG_END_XML_SELECTOR_SOURCE */
#endif
