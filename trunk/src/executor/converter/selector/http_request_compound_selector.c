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
 * @version $RCSfile: http_request_compound_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_COMPOUND_SELECTOR_SOURCE
#define HTTP_REQUEST_COMPOUND_SELECTOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../constant/name/xml_name.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/detector.c"

/**
 * Decodes http request method.
 *
 * Examples:
 *
 * GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
 * POST /wiki/Spezial:Search HTTP/1.1
 *
 * CAUTION! The methods GET and HEAD MUST be supported by all general-purpose servers!
 * All other methods are OPTIONAL.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source body
 * @param p4 the source body count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 * @param p7 the source request method
 * @param p8 the source request method count
 */
void decode_http_request_compound_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** d = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http request method.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2,
                    (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) POST_REQUEST_METHOD_HTTP_MODEL, (void*) POST_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) POST_REQUEST_METHOD_HTTP_MODEL, (void*) POST_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);

                // Decode body parameters containing model data.
                //
                // CAUTION! The POST method http request may contain a body with parameters,
                // which are listed in the same key-value pair format as those in the uri.
                decode_http_request_parameters(p0, p1, p2, p3, p4, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) HEAD_REQUEST_METHOD_HTTP_MODEL, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) PUT_REQUEST_METHOD_HTTP_MODEL, (void*) PUT_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) PUT_REQUEST_METHOD_HTTP_MODEL, (void*) PUT_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) DELETE_REQUEST_METHOD_HTTP_MODEL, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) TRACE_REQUEST_METHOD_HTTP_MODEL, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode http request method. The source request method is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request method. The destination model is null.");
    }
}

/* HTTP_REQUEST_COMPOUND_SELECTOR_SOURCE */
#endif
