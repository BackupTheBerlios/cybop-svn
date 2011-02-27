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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HEADER_HTTP_RESPONSE_ENCODER_SOURCE
#define HEADER_HTTP_RESPONSE_ENCODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/encoder/http_response/header_entry_http_response_encoder.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../executor/modifier/appender.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the http response header content length.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the source message model count (content length)
 */
void encode_http_response_header_content_length(void* p0, void* p1, void* p2, void* p3) {

    // The wide character array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;

    // Allocate character array.
    allocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Encode wide character array into multibyte character array.
    encode_integer((void*) &a, ac, as, p3, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

    append(p0, p1, p2, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
    append(p0, p1, p2, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // CAUTION! Use the message count (content length) integer value
    // that was handed over as parameter!
    select_http_response_header_entry_append(p0, p1, p2, a, ac);
    append(p0, p1, p2, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Deallocate character array.
    deallocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Encodes the http response header.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the source metadata abstraction
 * @param p4 the source metadata abstraction count
 * @param p5 the source metadata model
 * @param p6 the source metadata model count
 * @param p7 the source metadata details
 * @param p8 the source metadata details count
 * @param p9 the source message model count
 */
void encode_http_response_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode http response header.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            encode_http_response_header_entry(p0, p1, p2, p5, p6, (void*) &j, p9);

            // Increment loop variable.
            j++;
        }

        // The content length is currently always added
        // (but this solution may change later).
        encode_http_response_header_content_length(p0, p1, p2, p9);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode http response header. The metadata model count is null.");
    }
}

/* HEADER_HTTP_RESPONSE_ENCODER_SOURCE */
#endif
