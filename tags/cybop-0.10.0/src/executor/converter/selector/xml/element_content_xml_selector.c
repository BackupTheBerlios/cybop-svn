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

#ifndef ELEMENT_CONTENT_XML_SELECTOR_SOURCE
#define ELEMENT_CONTENT_XML_SELECTOR_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/converter/decoder/xml/declaration_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/definition_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/comment_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/end_tag_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/element_xml_decoder.c"
#include "../../../../executor/converter/detector.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

//
// Forward declarations.
//

/*??
void decode_xml_comment(void* p0, void* p1);
void decode_xml_declaration(void* p0, void* p1, void* p2, void* p3, void* p4);
void decode_xml_definition(void* p0, void* p1, void* p2, void* p3, void* p4);
void decode_xml_element(void* p0, void* p1, void* p2, void* p3, void* p4);
void decode_xml_end_tag(void* p0, void* p1);
*/

/**
 * Selects the xml element content.
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
void select_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p6;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xml element content.");

                //
                // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
                // Before arbitrary elements -- beginning with just "<" and a term -- can be identified,
                // all other possibilities (declaration, definition, comment) have to have
                // been processed, in order to be excluded.
                // Also, the comment begin <!-- has to be searched BEFORE the definition begin <!.
                // The very first comparison, however, is to search for the end tag begin "</".
                // The reason is that all elements begin with a "<" character:
                // - declaration: <?
                // - comment: <!--
                // - definition: <!
                // - element: <
                //
                // CAUTION! The comparison result HAS TO BE ZERO (r == 0),
                // if a detection is to be taking place!
                // Many "detect" functions are called in a sequence, below.
                // If the result of one detection function was positive (r == 1),
                // then that function increments the current position and decrements the remaining count.
                // In this case, further detection functions following afterwards might detect
                // further characters and CHANGE the current position and remaining count, and so forth,
                // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
                // Therefore, the checks for (r == 0) below avoid another detection,
                // if the result already has a value unequal zero.
                //
                // CAUTION! If a detection was successful, then the current position and remaining count
                // were already adapted within the corresponding "detect" function (as called below),
                // so that they now point to the first character following the detected character sequence.
                // Any "decode" function called afterwards can rely on this and start processing right away.
                //

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) END_TAG_BEGIN_XML_NAME, (void*) END_TAG_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        decode_xml_end_tag(p7, p8);

                        // Set break flag, because this xml element's end tag
                        // has been reached and its content fully been decoded.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) DECLARATION_BEGIN_XML_NAME, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML declaration are added to the destination details.
                        decode_xml_declaration(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) COMMENT_BEGIN_XML_NAME, (void*) COMMENT_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML comment are just ignored.
                        decode_xml_comment(p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) DEFINITION_BEGIN_XML_NAME, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML definition are added to the destination details.
                        decode_xml_definition(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) START_TAG_BEGIN_XML_NAME, (void*) START_TAG_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // The data contained in an XML element are added to the destination model.
                        decode_xml_element(p0, p1, p2, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // None of the comparisons above delivered a positive (r != 0) result.
                    // Therefore, increment the current position by one (pointer size).

                    detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element content. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element content. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml element content. The remaining count is null.");
    }
}

/* ELEMENT_CONTENT_XML_SELECTOR_SOURCE */
#endif
