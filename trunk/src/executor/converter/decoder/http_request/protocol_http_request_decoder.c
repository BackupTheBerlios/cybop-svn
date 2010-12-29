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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROTOCOL_HTTP_REQUEST_DECODER_SOURCE
#define PROTOCOL_HTTP_REQUEST_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/http_request/protocol_http_request_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Converts the given characters to wide characters and
 * appends them to the destination.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 */
void decode_http_request_protocol_append_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Decode encoded character array into serialised wide character array.
    decode_utf_8_unicode_character_vector((void*) &s, sc, ss, p7, p8);

    append_part(p0, p1, p2, p3, p4, p5, p6, s, sc, p9, p10);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Decodes the http request protocol.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the current position (Hand over as reference!)
 * @param p7 the remaining count
 */
void decode_http_request_protocol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http request protocol.");

            // The element.
            void* e = *pos;
            int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_protocol(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_http_request_protocol_append_part(p3, p4, p5,
                        (void*) CYBOI_PROTOCOL_HTTP_NAME, (void*) CYBOI_PROTOCOL_HTTP_NAME_COUNT,
                        (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                        e, (void*) &ec, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                    break;

                } else {

                    // Increment protocol count.
                    ec++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request protocol. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request protocol. The remaining count is null.");
    }
}

/* PROTOCOL_HTTP_REQUEST_DECODER_SOURCE */
#endif
