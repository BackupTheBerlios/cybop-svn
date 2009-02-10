/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: http_request_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-10 01:01:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_SELECTOR_SOURCE
#define HTTP_REQUEST_SELECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/xml_cybol_name.c"
#include "../../constant/name/xml_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/detector.c"

//
// Forward declarations.
//

// void process_xml_declaration(void* p0, void* p1, void* p2, void* p3, void* p4);

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

/*??
    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p6;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request method.");

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
                // Any "process" function called afterwards can rely on this and start processing right away.
                //

//??    fwprintf(stdout, L"TEST select element content rem: %i\n", *rem);

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST select element content end tag begin: %i\n", *rem);

                        process_xml_end_tag(p7, p8);

                        // Set break flag, because this xml element's end tag
                        // has been reached and its content fully been processed.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) DECLARATION_BEGIN_XML_NAME, (void*) DECLARATION_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST select element content declaration begin: %i\n", *rem);

                        // The data contained in an XML declaration are added to the destination details.
                        process_xml_declaration(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) COMMENT_BEGIN_XML_NAME, (void*) COMMENT_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST select element content comment begin: %i\n", *rem);

                        // The data contained in an XML comment are just ignored.
                        process_xml_comment(p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) DEFINITION_BEGIN_XML_NAME, (void*) DEFINITION_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST select element content definition begin: %i\n", *rem);

                        // The data contained in an XML definition are added to the destination details.
                        process_xml_definition(p3, p4, p5, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p7, p8, (void*) START_TAG_BEGIN_XML_NAME, (void*) START_TAG_BEGIN_XML_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST select element content start tag begin: %i\n", *rem);

                        // The data contained in an XML element are added to the destination model.
                        process_xml_element(p0, p1, p2, p7, p8);
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST select element content nothing detected: %i\n", *rem);

                    // None of the comparisons above delivered a positive (r != 0) result.
                    // Therefore, increment the current position by one (pointer size).

                    detect_move_position(p7, p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
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
*/
}

/**
 * Selects the http request method.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_method(void* p0, void* p1, void* p2) {

/*??
    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request method.");

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) REQUEST_METHOD_SEPARATOR_HTTP_NAME, (void*) REQUEST_METHOD_SEPARATOR_HTTP_NAME_COUNT, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // CAUTION! The current position and remaining count were already
                        // changed in the called function, to be processed further.

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xml attribute value. The remaining count is null.");
    }
*/
}

/* HTTP_REQUEST_SELECTOR_SOURCE */
#endif
