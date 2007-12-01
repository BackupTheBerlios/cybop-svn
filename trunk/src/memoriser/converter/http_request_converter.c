/*
 * $RCSfile: http_request_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.12 $ $Date: 2007-12-01 23:57:42 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_CONVERTER_SOURCE
#define HTTP_REQUEST_CONVERTER_SOURCE

#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/http/http_request_method_constants.c"
#include "../../globals/constants/http/http_separator_constants.c"
#include "../../globals/constants/http/uri_separator_constants.c"
#include "../../globals/constants/http/webdav_request_method_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/logger/logger.c"

//
// An http server request delivers message data in text format (like MIME 1.0),
// and consists of the following three parts:
// 1 request line containing request method, file path and protocol version
// 2 headers containing meta data, of which some have the form of variables
// 3 body containing optional user data (such as an encoded/serialised xhtml page)
//
// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).
// The end of the headers is demarcated by an empty line (CRLF without any space).
//
// HTTP request and response messages use a generic message format for transferring
// entities (the payload of the message). Both types of message consist of a:
// - start-line
// - zero or more header fields (also known as "headers")
// - an empty line (i.e., a line with nothing preceding the CRLF)
//   indicating the end of the header fields
// - possibly a message-body
//

//
// Forward declarations.
//

/**
 * Decodes the source into the destination, according to the given language.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source
 * @param p7 the source count
 * @param p8 the knowledge memory
 * @param p9 the knowledge memory count
 * @param p10 the language
 * @param p11 the language count
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Sets the value of the parameter with the given key, within the compound.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source parameter key
 * @param p4 the source parameter key count
 * @param p5 the source parameter value
 * @param p6 the source parameter value count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 */
void decode_http_request_set_parameter(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER) {

        // CAUTION! Do NOT use "d" as name, as it is used for "details" below.
        void** dest = (void**) p0;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request set parameter.");

        //
        // Setting of parameter.
        //

    fprintf(stderr, "TEST http request parameter dest: %i \n", *dest);
    fprintf(stderr, "TEST http request parameter destc: %i \n", *((int*) p1));

        // The parameter name, abstraction, model, details.
        void** n = NULL_POINTER;
        void** nc = NULL_POINTER;
        void** ns = NULL_POINTER;
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        void** as = NULL_POINTER;
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;

    fprintf(stderr, "TEST http request parameter pn: %s \n", (char*) p3);
    fprintf(stderr, "TEST http request parameter pnc: %i \n", *((int*) p4));

        // Get parameter from model, using its key as name.
        get_universal_compound_element_by_name(*dest, p1,
            p3, p4,
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            p7, p8);

/*??
    fprintf(stderr, "TEST http request parameter nc: %i \n", **((int**) nc));
    fprintf(stderr, "TEST http request parameter n: %s \n", (char*) *n);
    fprintf(stderr, "TEST http request parameter ac: %i \n", **((int**) ac));
    fprintf(stderr, "TEST http request parameter a: %s \n", (char*) *a);
    fprintf(stderr, "TEST http request parameter mc: %i \n", **((int**) mc));
    fprintf(stderr, "TEST http request parameter m: %s \n", (char*) *m);
*/

        // Decode and set parameter value according to given abstraction.
        decode((void*) m, *mc, *ms, (void*) d, *dc, *ds, p5, p6, p7, p8, *a, *ac);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request set parameter. The destination model is null.");
    }
}

/**
 * Decodes an http request parameter (from uri query or http request body).
 *
 * Examples:
 *
 * search=Katzen
 * go=Artikel
 * action=close
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source parameter
 * @param p4 the source parameter count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 */
void decode_http_request_parameter(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request parameter.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Key.
        //

        // The key, initialised with current source index.
        void* k = i;
        int kc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) URI_VALUE_SEPARATOR, (void*) URI_VALUE_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set key count.
            kc = sep;

            // Set new source index.
            i = i + sep + *URI_VALUE_SEPARATOR_COUNT;
            ic = ic - sep - *URI_VALUE_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.

            // Set source index to null.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request parameter k: %s \n", (char*) k);
    fprintf(stderr, "TEST http request parameter kc: %i \n", kc);

        //
        // Value.
        //

        // The value.
        void* v = i;
        int vc = ic;

        // No further separators have to be found.

    fprintf(stderr, "TEST http request parameter v: %s \n", (char*) v);
    fprintf(stderr, "TEST http request parameter vc: %i \n", vc);

        // Sets the value of the parameter with the given key, within the compound.
        decode_http_request_set_parameter(p0, p1, p2, k, (void*) &kc, v, (void*) &vc, p5, p6);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request parameter. The source parameter count is null.");
    }
}

/**
 * Decodes http request uri query parameters.
 *
 * Example:
 *
 * search=Katzen&go=Artikel
 * action=close
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source parameters
 * @param p4 the source parameters count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 */
void decode_http_request_parameters(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request parameters.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;
        // The parameter, initialised with current source index.
        void* p = i;
        int pc = ic;

        while (*NUMBER_1_INTEGER) {

            // Set parameter.
            p = i;
            pc = ic;

            // Reset separator index.
            sep = *NUMBER_MINUS_1_INTEGER;

            // Get separator index.
            get_array_elements_index(i, (void*) &ic, (void*) URI_PARAMETER_SEPARATOR, (void*) URI_PARAMETER_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

            if (sep >= *NUMBER_0_INTEGER) {

                // A parameter separator was found. More parameters exist.

                // Set new count.
                pc = sep;

                // Decode the identified header.
                decode_http_request_parameter(p0, p1, p2, p, (void*) &pc, p5, p6);

                // Set new source index.
                i = i + sep + *URI_PARAMETER_SEPARATOR_COUNT;
                ic = ic - sep - *URI_PARAMETER_SEPARATOR_COUNT;

            } else {

                // No parameter separator was found. This is the last parameter.

                // Decode the identified header.
                decode_http_request_parameter(p0, p1, p2, p, (void*) &pc, p5, p6);

                // Break loop since no further parameters are to be expected.
                break;
            }

    fprintf(stderr, "TEST http request parameters p: %s \n", (char*) p);
    fprintf(stderr, "TEST http request parameters pc: %i \n", pc);
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request parameters. The source parameters count is null.");
    }
}

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
void decode_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER) {

        void** d = (void**) p0;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request method.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_GET_REQUEST_METHOD, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_GET_REQUEST_METHOD_MODEL, (void*) HTTP_GET_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_POST_REQUEST_METHOD, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_POST_REQUEST_METHOD_MODEL, (void*) HTTP_POST_REQUEST_METHOD_MODEL_COUNT, p5, p6);

                // Decode body parameters containing model data.
                //
                // CAUTION! The POST method http request may contain a body with parameters,
                // which are listed in the same key-value pair format as those in the uri.
                decode_http_request_parameters(p0, p1, p2, p3, p4, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_HEAD_REQUEST_METHOD, (void*) HTTP_HEAD_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_HEAD_REQUEST_METHOD_MODEL, (void*) HTTP_HEAD_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_PUT_REQUEST_METHOD, (void*) HTTP_PUT_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_PUT_REQUEST_METHOD_MODEL, (void*) HTTP_PUT_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_DELETE_REQUEST_METHOD, (void*) HTTP_DELETE_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_DELETE_REQUEST_METHOD_MODEL, (void*) HTTP_DELETE_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_TRACE_REQUEST_METHOD, (void*) HTTP_TRACE_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_TRACE_REQUEST_METHOD_MODEL, (void*) HTTP_TRACE_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_OPTIONS_REQUEST_METHOD, (void*) HTTP_OPTIONS_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_OPTIONS_REQUEST_METHOD_MODEL, (void*) HTTP_OPTIONS_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) HTTP_CONNECT_REQUEST_METHOD, (void*) HTTP_CONNECT_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) HTTP_CONNECT_REQUEST_METHOD_MODEL, (void*) HTTP_CONNECT_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_PROPFIND_REQUEST_METHOD, (void*) WEBDAV_PROPFIND_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_PROPFIND_REQUEST_METHOD_MODEL, (void*) WEBDAV_PROPFIND_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_PROPPATCH_REQUEST_METHOD, (void*) WEBDAV_PROPPATCH_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_PROPPATCH_REQUEST_METHOD_MODEL, (void*) WEBDAV_PROPPATCH_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_MKCOL_REQUEST_METHOD, (void*) WEBDAV_MKCOL_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_MKCOL_REQUEST_METHOD_MODEL, (void*) WEBDAV_MKCOL_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_COPY_REQUEST_METHOD, (void*) WEBDAV_COPY_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_COPY_REQUEST_METHOD_MODEL, (void*) WEBDAV_COPY_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_MOVE_REQUEST_METHOD, (void*) WEBDAV_MOVE_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_MOVE_REQUEST_METHOD_MODEL, (void*) WEBDAV_MOVE_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_LOCK_REQUEST_METHOD, (void*) WEBDAV_LOCK_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_LOCK_REQUEST_METHOD_MODEL, (void*) WEBDAV_LOCK_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p7, p8, (void*) WEBDAV_UNLOCK_REQUEST_METHOD, (void*) WEBDAV_UNLOCK_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_METHOD_NAME, (void*) SENSE_MODEL_METHOD_NAME_COUNT,
                    (void*) WEBDAV_UNLOCK_REQUEST_METHOD_MODEL, (void*) WEBDAV_UNLOCK_REQUEST_METHOD_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not decode http request method. The source request method is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request method. The destination model is null.");
    }
}

/**
 * Decodes an http request header into the details compound.
 *
 * Example:
 *
 * content-type: text/html; charset=iso-8859-1
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the source header
 * @param p4 the source header count
 */
void decode_http_request_header(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request header.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Argument.
        //

        // The argument, initialised with current source index.
        void* a = i;
        int ac = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADER_ARGUMENT_SEPARATOR, (void*) HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set new count.
            ac = sep;

            // Set new source index.
            i = i + sep + *HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.

            // Set source index to null.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request header a: %s \n", (char*) a);
    fprintf(stderr, "TEST http request header ac: %i \n", ac);

        //
        // Value.
        //

        // The value, initialised with current source index.
        void* v = i;
        int vc = ic;
        // No further separators have to be found.

    fprintf(stderr, "TEST http request header v: %s \n", (char*) v);
    fprintf(stderr, "TEST http request header vc: %i \n", vc);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request header. The source http request count is null.");
    }
}

/**
 * Decodes http request headers.
 *
 * Example:
 *
 * host: de.wikipedia.org
 * content-type: application/x-www-form-urlencoded
 * content-length: 24
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the source headers
 * @param p4 the source headers count
 */
void decode_http_request_headers(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request headers.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;
        // The header, initialised with current source index.
        void* h = i;
        int hc = ic;

        while (*NUMBER_1_INTEGER) {

            // Set header.
            h = i;
            hc = ic;

            // Reset separator index.
            sep = *NUMBER_MINUS_1_INTEGER;

            // Get separator index.
            get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADER_SEPARATOR, (void*) HTTP_HEADER_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

            if (sep >= *NUMBER_0_INTEGER) {

                // A header separator was found. More headers exist.

                // Set new count.
                hc = sep;

                // Decode the identified header.
                decode_http_request_header(p0, p1, p2, h, (void*) &hc);

                // Set new source index.
                i = i + sep + *HTTP_HEADER_SEPARATOR_COUNT;
                ic = ic - sep - *HTTP_HEADER_SEPARATOR_COUNT;

            } else {

                // No header separator was found. This is the last header.

                // Decode the identified header.
                decode_http_request_header(p0, p1, p2, h, (void*) &hc);

                // Break loop since no further headers are to be expected.
                break;
            }

    fprintf(stderr, "TEST http request headers h: %s \n", (char*) h);
    fprintf(stderr, "TEST http request headers hc: %i \n", hc);

        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request headers. The source http request count is null.");
    }
}

/**
 * Decodes uniform resource identifier (uri).
 *
 * The generic URI syntax consists of a hierarchical sequence of
 * components referred to as the scheme, authority, path, query, and
 * fragment.
 *
 * URI         = scheme ":" hier-part [ "?" query ] [ "#" fragment ]
 *
 * hier-part   = "//" authority path-abempty
 *             / path-absolute
 *             / path-rootless
 *             / path-empty
 *
 * The scheme and path components are required, though the path may be
 * empty (no characters).  When authority is present, the path must
 * either be empty or begin with a slash ("/") character.  When
 * authority is not present, the path cannot begin with two slash
 * characters ("//").  These restrictions result in five different ABNF
 * rules for a path (Section 3.3), only one of which will match any
 * given URI reference.
 *
 * The following are two example URIs and their component parts:
 *
 *   foo://example.com:8042/over/there?name=ferret#nose
 *   \_/   \______________/\_________/ \_________/ \__/
 *    |           |            |            |        |
 * scheme     authority       path        query   fragment
 *    |   _____________________|__
 *   / \ /                        \
 *   urn:example:animal:ferret:nose
 *
 * Exception:
 *
 * Although not defined by IETF's uri specification rfc3986, it has become
 * usual to use the characters ";" and "&" as parameter separators in a uri.
 * These are commonly found in both, the "path" and "query" component part.
 * For cyboi, however, it is defined that parameters may only be given in the
 * "query" component part, and that parameters are separated by ampersand "&".
 *
 * Examples:
 *
 * http://localhost:1971/?exit
 * http://127.0.0.1:1971?name=close&channel=inline&abstraction=knowledge&model=.residenz.logic.exit_program
 * http://de.wikipedia.org/w/index.php?title=Uniform_Resource_Locator&action=edit
 *
 * There are a number of reserved characters, to which belong:
 * ! # $ % & ' ( ) * + , / : ; = ? @ [ ]
 * The following url contains the reserved # character:
 * http://www.example.net/index.html?session=A54C6FE2#info
 * which should be encoded as %23 like:
 * http://www.example.net/index.html?session=A54C6FE2%23info
 *
 * The url path specified by the client is relative to the
 * server's root directory. Consider the following url as it
 * would be requested by a client:
 * http://www.example.com/path/file.html
 * The client's web browser will translate it into a connection
 * to www.example.com with the following http 1.1 request:
 * GET /path/file.html HTTP/1.1
 * host: www.example.com
 * The Web server on www.example.com will append the given path
 * to the path of its root directory. On Unix machines, this is
 * commonly /var/www/htdocs.
 * The result is the local file system resource:
 * /var/www/htdocs/path/file.html
 * The Web server will then read the file, if it exists, and
 * send a response to the client's web browser. The response
 * will describe the content of the file and contain the file itself.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source uniform resource identifier
 * @param p4 the source uniform resource identifier count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 */
void decode_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode uniform resource identifier.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Scheme.
        //

        // The scheme, initialised with current source index.
        void* sch = i;
        int schc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) URI_SCHEME_SEPARATOR, (void*) URI_SCHEME_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // The scheme separator was found.
            // Further uri parts are expected.

            // Set new count.
            schc = sep;

            // Set new source index.
            i = i + sep + *URI_SCHEME_SEPARATOR_COUNT;
            ic = ic - sep - *URI_SCHEME_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The scheme is assumed not to have been given.
            // The remaining source thus represents the other parts only.

            // Set scheme to null.
            sch = *NULL_POINTER;
            schc = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request uri sch: %s \n", (char*) sch);
    fprintf(stderr, "TEST http request uri schc: %i \n", schc);

        //
        // Authority.
        //

        // The authority.
        void* a = *NULL_POINTER;
        int ac = *NUMBER_0_INTEGER;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) URI_AUTHORITY_SEPARATOR, (void*) URI_AUTHORITY_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // The authority separator was found.
            // It demarcates the beginning of the uri part.

            // Set authority.
            a = i + sep + *URI_AUTHORITY_SEPARATOR_COUNT;
            ac = ic - sep - *URI_AUTHORITY_SEPARATOR_COUNT;

            // Set new source index.
            i = i + sep + *URI_AUTHORITY_SEPARATOR_COUNT;
            ic = ic - sep - *URI_AUTHORITY_SEPARATOR_COUNT;

            // Get separator index.
            get_array_elements_index(i, (void*) &ic, (void*) URI_PATH_SEPARATOR, (void*) URI_PATH_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

            if (sep >= *NUMBER_0_INTEGER) {

                // The path separator was found.
                // It demarcates the end of the uri part.

                // Set new count.
                ac = sep;

                // Set new source index.
                //
                // CAUTION! Do only add the separator index, but NOT its count,
                // because the separator demarcates the beginning of the next
                // part and has to be found again below!
                i = i + sep;
                ic = ic - sep;

            } else {

                // Get separator index.
                get_array_elements_index(i, (void*) &ic, (void*) URI_QUERY_SEPARATOR, (void*) URI_QUERY_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

                if (sep >= *NUMBER_0_INTEGER) {

                    // The query separator was found.
                    // It demarcates the end of the uri part.

                    // Set new count.
                    ac = sep;

                    // Set new source index.
                    //
                    // CAUTION! Do only add the separator index, but NOT its count,
                    // because the separator demarcates the beginning of the next
                    // part and has to be found again below!
                    i = i + sep;
                    ic = ic - sep;

                } else {

                    // Get separator index.
                    get_array_elements_index(i, (void*) &ic, (void*) URI_FRAGMENT_SEPARATOR, (void*) URI_FRAGMENT_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

                    if (sep >= *NUMBER_0_INTEGER) {

                        // The fragment separator was found.
                        // It demarcates the end of the uri part.

                        // Set new count.
                        ac = sep;

                        // Set new source index.
                        //
                        // CAUTION! Do only add the separator index, but NOT its count,
                        // because the separator demarcates the beginning of the next
                        // part and has to be found again below!
                        i = i + sep;
                        ic = ic - sep;

                    } else {

                        // No separator was found.
                        // The remaining source is assumed to contain no further parts.

                        // Set source index to null.
                        i = *NULL_POINTER;
                        ic = *NUMBER_0_INTEGER;
                    }
                }
            }
        }

    fprintf(stderr, "TEST http request uri a: %s \n", (char*) a);
    fprintf(stderr, "TEST http request uri ac: %i \n", ac);

        //
        // Path.
        //

        // The path, initialised with current source index.
        void* p = *NULL_POINTER;
        int pc = *NUMBER_0_INTEGER;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) URI_PATH_SEPARATOR, (void*) URI_PATH_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // The path separator was found.
            // It demarcates the beginning of the uri part.

            // Set path.
            p = i + sep + *URI_PATH_SEPARATOR_COUNT;
            pc = ic - sep - *URI_PATH_SEPARATOR_COUNT;

            // Set new source index.
            i = i + sep + *URI_PATH_SEPARATOR_COUNT;
            ic = ic - sep - *URI_PATH_SEPARATOR_COUNT;

            // Get separator index.
            get_array_elements_index(i, (void*) &ic, (void*) URI_QUERY_SEPARATOR, (void*) URI_QUERY_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

            if (sep >= *NUMBER_0_INTEGER) {

                // The query separator was found.
                // It demarcates the end of the uri part.

                // Set new count.
                pc = sep;

                // Set new source index.
                //
                // CAUTION! Do only add the separator index, but NOT its count,
                // because the separator demarcates the beginning of the next
                // part and has to be found again below!
                i = i + sep;
                ic = ic - sep;

            } else {

                // Get separator index.
                get_array_elements_index(i, (void*) &ic, (void*) URI_FRAGMENT_SEPARATOR, (void*) URI_FRAGMENT_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

                if (sep >= *NUMBER_0_INTEGER) {

                    // The fragment separator was found.
                    // It demarcates the end of the uri part.

                    // Set new count.
                    pc = sep;

                    // Set new source index.
                    //
                    // CAUTION! Do only add the separator index, but NOT its count,
                    // because the separator demarcates the beginning of the next
                    // part and has to be found again below!
                    i = i + sep;
                    ic = ic - sep;

                } else {

                    // No separator was found.
                    // The remaining source is assumed to contain no further parts.

                    // Set source index to null.
                    i = *NULL_POINTER;
                    ic = *NUMBER_0_INTEGER;
                }
            }
        }

    fprintf(stderr, "TEST http request uri p: %s \n", (char*) p);
    fprintf(stderr, "TEST http request uri pc: %i \n", pc);

        //
        // Query.
        //

        // The query, initialised with current source index.
        void* q = *NULL_POINTER;
        int qc = *NUMBER_0_INTEGER;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

    fprintf(stderr, "TEST http request uri qc 0: %i \n", qc);

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) URI_QUERY_SEPARATOR, (void*) URI_QUERY_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // The query separator was found.
            // It demarcates the beginning of the uri part.

            // Set query.
            q = i + sep + *URI_QUERY_SEPARATOR_COUNT;
            qc = ic - sep - *URI_QUERY_SEPARATOR_COUNT;

    fprintf(stderr, "TEST http request uri qc 1: %i \n", qc);

            // Set new source index.
            i = i + sep + *URI_QUERY_SEPARATOR_COUNT;
            ic = ic - sep - *URI_QUERY_SEPARATOR_COUNT;

            // Reset separator index.
            sep = *NUMBER_MINUS_1_INTEGER;

            // Get separator index.
            get_array_elements_index(i, (void*) &ic, (void*) URI_FRAGMENT_SEPARATOR, (void*) URI_FRAGMENT_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

            if (sep >= *NUMBER_0_INTEGER) {

                // The fragment separator was found.
                // It demarcates the end of the uri part.

                // Set new count.
                qc = sep;

    fprintf(stderr, "TEST http request uri qc 2: %i \n", qc);

                // Set new source index.
                //
                // CAUTION! Do only add the separator index, but NOT its count,
                // because the separator demarcates the beginning of the next
                // part and has to be found again below!
                i = i + sep;
                ic = ic - sep;

            } else {

                // No separator was found.
                // The remaining source is assumed to contain no further parts.

    fprintf(stderr, "TEST http request uri qc 3: %i \n", qc);

                // Set source index to null.
                i = *NULL_POINTER;
                ic = *NUMBER_0_INTEGER;
            }
        }

    fprintf(stderr, "TEST http request uri q: %s \n", (char*) q);
    fprintf(stderr, "TEST http request uri qc: %i \n", qc);

        //
        // Fragment.
        //

        // The fragment, initialised with current source index.
        void* f = *NULL_POINTER;
        int fc = *NUMBER_0_INTEGER;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) URI_FRAGMENT_SEPARATOR, (void*) URI_FRAGMENT_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // The fragment separator was found.
            // It demarcates the beginning of the uri part.

            // Set fragment.
            f = i + sep + *URI_FRAGMENT_SEPARATOR_COUNT;
            fc = ic - sep - *URI_FRAGMENT_SEPARATOR_COUNT;
        }

    fprintf(stderr, "TEST http request uri f: %s \n", (char*) f);
    fprintf(stderr, "TEST http request uri fc: %i \n", fc);

        // Set the scheme value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_SCHEME_NAME, (void*) SENSE_MODEL_SCHEME_NAME_COUNT, sch, (void*) &schc, p5, p6);
        // Set the authority value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_AUTHORITY_NAME, (void*) SENSE_MODEL_AUTHORITY_NAME_COUNT, a, (void*) &ac, p5, p6);
        // Set the path value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_PATH_NAME, (void*) SENSE_MODEL_PATH_NAME_COUNT, p, (void*) &pc, p5, p6);

        // Decode and set query parameters.
        //
        // CAUTION! The query as such does not represent a parameter, it may only contain some.
        decode_http_request_parameters(p0, p1, p2, q, (void*) &qc, p5, p6);

        // Set the fragment value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) SENSE_MODEL_FRAGMENT_NAME, (void*) SENSE_MODEL_FRAGMENT_NAME_COUNT, f, (void*) &fc, p5, p6);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode uniform resource identifier. The source uniform resource identifier count is null.");
    }
}

/**
 * Decodes an http request request line into the details compound.
 *
 * Example:
 *
 * POST /wiki/Spezial:Search HTTP/1.1
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source body
 * @param p7 the source body count
 * @param p8 the source headers
 * @param p9 the source headers count
 * @param p10 the source request line
 * @param p11 the source request line count
 * @param p12 the knowledge memory
 * @param p13 the knowledge memory count
 */
void decode_http_request_line(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    if (p11 != *NULL_POINTER) {

        int* sc = (int*) p11;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Decode http request request line.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p10;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Request method.
        //

        // The request method, initialised with current source index.
        void* rm = i;
        int rmc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_REQUEST_METHOD_SEPARATOR, (void*) HTTP_REQUEST_METHOD_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set new count.
            rmc = sep;

            // Set new source index.
            i = i + sep + *HTTP_REQUEST_METHOD_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_METHOD_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.

            // Set source index to null.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request line rm: %s \n", (char*) rm);
    fprintf(stderr, "TEST http request line rmc: %i \n", rmc);

        //
        // Uniform resource identifier.
        //

        // The uniform resource identifier, initialised with current source index.
        void* uri = i;
        int uric = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR, (void*) HTTP_UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set new count.
            uric = sep;

            // Set new source index.
            i = i + sep + *HTTP_UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_UNIFORM_RESOURCE_IDENTIFIER_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.

            // Set source index to null.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request line uri: %s \n", (char*) uri);
    fprintf(stderr, "TEST http request line uric: %i \n", uric);

        //
        // Protocol version.
        //

        // The protocol version, initialised with current source index.
        void* pv = i;
        int pvc = ic;
        // No further separators have to be found.

    fprintf(stderr, "TEST http request line pv: %s \n", (char*) pv);
    fprintf(stderr, "TEST http request line pvc: %i \n", pvc);

        // CAUTION! Do NOT move the function calls below to any other function!
        // The reason is that the http protocol version was decoded here so that
        // it is available and may be used for example in the "decode_http_request_headers"
        // function to decode differing http headers, depending on the protocol version.

        // Decode request method.
        //
        // Each request method causes a special action and gives special
        // parameters as meta information accompanying that action.
        //
        // CAUTION! This function has to be called BEFORE "decode_http_request_uri"!
        // The reason is that the standard action of the request method
        // may have to be overwritten with a parameter given in the uri.
        // GET and POST, for example, do mostly not represent the desired action
        // themselves, but are accompanied by an "action" parameter in the uri.
        decode_http_request_method(p0, p1, p2, p6, p7, p12, p13, rm, (void*) &rmc);

        // Decode headers containing meta data.
        decode_http_request_headers(p3, p4, p5, p8, p9);

        // Decode uniform resource identifier containing model data.
        // The uri's parts are set as parameters in the destination compound model.
        decode_http_request_uri(p0, p1, p2, uri, (void*) &uric, p12, p13);

    fprintf(stderr, "TEST http request line END i: %s \n", (char*) uri);
    fprintf(stderr, "TEST http request line END ic: %i \n", uric);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request request line. The source http request count is null.");
    }
}

/**
 * Decodes an http request into a compound.
 *
 * Example with GET method 1:
 *
 * GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
 * host: de.wikipedia.org
 *
 * The value pairs (parameters) of the example are:
 *
 * -------------------------------------
 * Argument         Value
 * -------------------------------------
 * search           Katzen
 * go               Artikel
 * -------------------------------------
 *
 * Example with GET method 2:
 *
 * GET /residenz/test.html HTTP/1.1
 * user-agent: Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Debian)
 * accept: text/html, image/jpeg, image/png, text/*, image/*, * /*
 * accept-encoding: x-gzip, x-deflate, gzip, deflate
 * accept-charset: utf-8, utf-8;q=0.5, *;q=0.5
 * accept-language: en, de, pl
 * host: 127.0.0.1:1971
 * connection: Keep-Alive
 *
 * Example with POST method:
 *
 * POST /wiki/Spezial:Search HTTP/1.1
 * host: de.wikipedia.org
 * content-type: application/x-www-form-urlencoded
 * content-length: 24
 *
 * search=Katzen&go=Artikel
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source http request
 * @param p7 the source http request count
 * @param p8 the knowledge memory
 * @param p9 the knowledge memory count
 */
void decode_http_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p7 != *NULL_POINTER) {

        int* sc = (int*) p7;

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Decode http request.");

    fprintf(stderr, "TEST http request mc p1: %i \n", *((int*) p1));
    fprintf(stderr, "TEST http request dc p4: %i \n", *((int*) p4));
    fprintf(stderr, "TEST http request sc p7: %i \n", *((int*) p7));
    fprintf(stderr, "TEST http request kmc p9: %i \n", *((int*) p9));

    fprintf(stderr, "TEST http request s p6: %s \n", (char*) p6);

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p6;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Request line.
        //

        // The request line, initialised with current source index.
        void* rl = i;
        int rlc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_REQUEST_LINE_SEPARATOR, (void*) HTTP_REQUEST_LINE_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set new count.
            rlc = sep;

            // Set new source index.
            i = i + sep + *HTTP_REQUEST_LINE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_LINE_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.

            // Set source index to null.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request rl: %s \n", (char*) rl);
    fprintf(stderr, "TEST http request rlc: %i \n", rlc);

        //
        // Headers.
        //

        // The headers, initialised with current source index.
        void* h = i;
        int hc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADERS_SEPARATOR, (void*) HTTP_HEADERS_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set new count.
            hc = sep;

            // Set new source index.
            i = i + sep + *HTTP_REQUEST_LINE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_LINE_SEPARATOR_COUNT;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.

            // Set source index to null.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    fprintf(stderr, "TEST http request h: %s \n", (char*) h);
    fprintf(stderr, "TEST http request hc: %i \n", hc);

        //
        // Body.
        //

        // The body, initialised with current source index.
        void* b = i;
        int bc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_BODY_SEPARATOR, (void*) HTTP_BODY_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set new count.
            bc = sep;

        } else {

            // No separator was found.
            // The remaining source is assumed to contain no further parts.
        }

    fprintf(stderr, "TEST http request b: %s \n", (char*) b);
    fprintf(stderr, "TEST http request bc: %i \n", bc);

        // Decode request line containing request method, uniform resource identifier and protocol version.
        decode_http_request_line(p0, p1, p2, p3, p4, p5, b, (void*) &bc, h, (void*) &hc, rl, (void*) &rlc, p8, p9);

    fprintf(stderr, "TEST http request END i: %s \n", (char*) i);
    fprintf(stderr, "TEST http request END ic: %i \n", ic);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode http request. The source http request count is null.");
    }
}

/**
 * Encodes a compound into an http request.
 *
 * @param p0 the destination http request (Hand over as reference!)
 * @param p1 the destination http request count
 * @param p2 the destination http request size
 * @param p3 the source compound abstraction
 * @param p4 the source compound abstraction count
 * @param p5 the source compound model
 * @param p6 the source compound model count
 * @param p7 the source compound details
 * @param p8 the source compound details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 */
void encode_http_request(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Encode http request.");
}

/* HTTP_REQUEST_CONVERTER_SOURCE */
#endif
