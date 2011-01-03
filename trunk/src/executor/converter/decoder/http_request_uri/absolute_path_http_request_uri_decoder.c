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

#ifndef ABSOLUTE_PATH_HTTP_REQUEST_URI_DECODER_SOURCE
#define ABSOLUTE_PATH_HTTP_REQUEST_URI_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/converter/selector/http_request_uri/absolute_path_http_request_uri_selector.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the absolute path http request uri.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the comparison result
 * @param p7 the current position (Hand over as reference!)
 * @param p8 the remaining count
 */
void decode_absolute_path_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p8;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            int* r = (int*) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode absolute path http request uri.");

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_absolute_path_http_request_uri(p0, p1, p2, p3, p4, p5, p6, p7, p8);

                if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode absolute path http request uri. The comparison result is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode absolute path http request uri. The remaining count is null.");
    }
}

/* ABSOLUTE_PATH_HTTP_REQUEST_URI_DECODER_SOURCE */
#endif
