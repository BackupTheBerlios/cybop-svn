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

#ifndef BODY_HTTP_REQUEST_DECODER_SOURCE
#define BODY_HTTP_REQUEST_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the http request body.
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
void decode_http_request_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        void** pos = (void**) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http request body.");

        //
        // CAUTION! There is NO NEED to detect the body end with a
        // function like "select_http_request_body".
        // All of the remaining characters are seen as body.
        //

        //
        // The body represents the actual http message content.
        // Its data are thus added to the destination MODEL (p0, p1, p2),
        // whilst the destination DETAILS contain meta data, i.e. the http headers.
        //
        // CAUTION! The body data may be encoded.
        // Therefore, use the CHARACTER_MEMORY_ABSTRACTION abstraction here
        // (and DO NOT convert to WIDE_CHARACTER_MEMORY_ABSTRACTION by chance).
        //
        // One of the http request header argument/value pairs defines the encoding,
        // so that the cybol application will have to decode the data,
        // because here, the corresponding http encoding header is not available.
        //
        replace_array_elements(p0, p1, p2, *pos, p7, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request body. The current position is null.");
    }
}

/* BODY_HTTP_REQUEST_DECODER_SOURCE */
#endif
