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

            compare_equal_arrays((void*) &r, p7, p8, (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) GET_REQUEST_METHOD_HTTP_MODEL, (void*) GET_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) POST_REQUEST_METHOD_HTTP_MODEL, (void*) POST_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

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

            compare_equal_arrays((void*) &r, p7, p8, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) HEAD_REQUEST_METHOD_HTTP_MODEL, (void*) HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) PUT_REQUEST_METHOD_HTTP_MODEL, (void*) PUT_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) PUT_REQUEST_METHOD_HTTP_MODEL, (void*) PUT_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) DELETE_REQUEST_METHOD_HTTP_MODEL, (void*) DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) TRACE_REQUEST_METHOD_HTTP_MODEL, (void*) TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL, (void*) OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL, (void*) CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Set request method as action parameter within the compound model.
                decode_http_request_set_parameter(p0, p1, p2, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) METHOD_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT,
                    (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL, (void*) UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

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
void decode_http_request_compound_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode uniform resource identifier.");

        // The source index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The separator index.
        int sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        //
        // Scheme.
        //

        // The scheme, initialised with current source index.
        void* sch = i;
        int schc = ic;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Get separator index.
        get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) SCHEME_SEPARATOR_URI_MODEL, (void*) SCHEME_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The scheme separator was found.
            // Further uri parts are expected.

            // Set new count.
            schc = sep;

            // Set new source index.
            i = i + sep + *SCHEME_SEPARATOR_URI_MODEL_COUNT;
            ic = ic - sep - *SCHEME_SEPARATOR_URI_MODEL_COUNT;

        } else {

            // No separator was found.
            // The scheme is assumed not to have been given.
            // The remaining source thus represents the other parts only.

            // Set scheme to null.
            sch = *NULL_POINTER_MEMORY_MODEL;
            schc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        }

    fwprintf(stdout, L"TEST http request uri sch: %ls \n", (wchar_t*) sch);
    fwprintf(stdout, L"TEST http request uri schc: %i \n", schc);

        //
        // Authority.
        //

        // The authority.
        void* a = *NULL_POINTER_MEMORY_MODEL;
        int ac = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Get separator index.
        get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) AUTHORITY_SEPARATOR_URI_MODEL, (void*) AUTHORITY_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The authority separator was found.
            // It demarcates the beginning of the uri part.

            // Set authority.
            a = i + sep + *AUTHORITY_SEPARATOR_URI_MODEL_COUNT;
            ac = ic - sep - *AUTHORITY_SEPARATOR_URI_MODEL_COUNT;

            // Set new source index.
            i = i + sep + *AUTHORITY_SEPARATOR_URI_MODEL_COUNT;
            ic = ic - sep - *AUTHORITY_SEPARATOR_URI_MODEL_COUNT;

            // Get separator index.
            get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) PATH_SEPARATOR_URI_MODEL, (void*) PATH_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
                get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) QUERY_SEPARATOR_URI_MODEL, (void*) QUERY_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
                    get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) FRAGMENT_SEPARATOR_URI_MODEL, (void*) FRAGMENT_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
                        i = *NULL_POINTER_MEMORY_MODEL;
                        ic = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    }
                }
            }
        }

    fwprintf(stdout, L"TEST http request uri a: %ls \n", (wchar_t*) a);
    fwprintf(stdout, L"TEST http request uri ac: %i \n", ac);

        //
        // Path.
        //

        // The path, initialised with current source index.
        void* p = *NULL_POINTER_MEMORY_MODEL;
        int pc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Get separator index.
        get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) PATH_SEPARATOR_URI_MODEL, (void*) PATH_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The path separator was found.
            // It demarcates the beginning of the uri part.

            // Set path.
            p = i + sep + *PATH_SEPARATOR_URI_MODEL_COUNT;
            pc = ic - sep - *PATH_SEPARATOR_URI_MODEL_COUNT;

            // Set new source index.
            i = i + sep + *PATH_SEPARATOR_URI_MODEL_COUNT;
            ic = ic - sep - *PATH_SEPARATOR_URI_MODEL_COUNT;

            // Get separator index.
            get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) QUERY_SEPARATOR_URI_MODEL, (void*) QUERY_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
                get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) FRAGMENT_SEPARATOR_URI_MODEL, (void*) FRAGMENT_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

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
                    i = *NULL_POINTER_MEMORY_MODEL;
                    ic = *NUMBER_0_INTEGER_MEMORY_MODEL;
                }
            }
        }

    fwprintf(stdout, L"TEST http request uri p: %ls \n", (wchar_t*) p);
    fwprintf(stdout, L"TEST http request uri pc: %i \n", pc);

        //
        // Query.
        //

        // The query, initialised with current source index.
        void* q = *NULL_POINTER_MEMORY_MODEL;
        int qc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    fwprintf(stdout, L"TEST http request uri qc 0: %i \n", qc);

        // Get separator index.
        get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) QUERY_SEPARATOR_URI_MODEL, (void*) QUERY_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The query separator was found.
            // It demarcates the beginning of the uri part.

            // Set query.
            q = i + sep + *QUERY_SEPARATOR_URI_MODEL_COUNT;
            qc = ic - sep - *QUERY_SEPARATOR_URI_MODEL_COUNT;

    fwprintf(stdout, L"TEST http request uri qc 1: %i \n", qc);

            // Set new source index.
            i = i + sep + *QUERY_SEPARATOR_URI_MODEL_COUNT;
            ic = ic - sep - *QUERY_SEPARATOR_URI_MODEL_COUNT;

            // Reset separator index.
            sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

            // Get separator index.
            get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) FRAGMENT_SEPARATOR_URI_MODEL, (void*) FRAGMENT_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // The fragment separator was found.
                // It demarcates the end of the uri part.

                // Set new count.
                qc = sep;

    fwprintf(stdout, L"TEST http request uri qc 2: %i \n", qc);

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

    fwprintf(stdout, L"TEST http request uri qc 3: %i \n", qc);

                // Set source index to null.
                i = *NULL_POINTER_MEMORY_MODEL;
                ic = *NUMBER_0_INTEGER_MEMORY_MODEL;
            }
        }

    fwprintf(stdout, L"TEST http request uri q: %ls \n", (wchar_t*) q);
    fwprintf(stdout, L"TEST http request uri qc: %i \n", qc);

        //
        // Fragment.
        //

        // The fragment, initialised with current source index.
        void* f = *NULL_POINTER_MEMORY_MODEL;
        int fc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // Reset separator index.
        sep = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // Get separator index.
        get_array_elements_index((void*) &sep, i, (void*) &ic, (void*) FRAGMENT_SEPARATOR_URI_MODEL, (void*) FRAGMENT_SEPARATOR_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (sep >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The fragment separator was found.
            // It demarcates the beginning of the uri part.

            // Set fragment.
            f = i + sep + *FRAGMENT_SEPARATOR_URI_MODEL_COUNT;
            fc = ic - sep - *FRAGMENT_SEPARATOR_URI_MODEL_COUNT;
        }

    fwprintf(stdout, L"TEST http request uri f: %ls \n", (wchar_t*) f);
    fwprintf(stdout, L"TEST http request uri fc: %i \n", fc);

        // Set the scheme value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) SCHEME_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) SCHEME_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, sch, (void*) &schc, p5, p6);
        // Set the authority value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) AUTHORITY_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) AUTHORITY_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, a, (void*) &ac, p5, p6);
        // Set the path value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) PATH_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) PATH_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p, (void*) &pc, p5, p6);

        // Decode and set query parameters.
        //
        // CAUTION! The query as such does not represent a parameter, it may only contain some.
        decode_http_request_parameters(p0, p1, p2, q, (void*) &qc, p5, p6);

        // Set the fragment value within the compound.
        decode_http_request_set_parameter(p0, p1, p2, (void*) FRAGMENT_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) FRAGMENT_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, f, (void*) &fc, p5, p6);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode uniform resource identifier. The source uniform resource identifier count is null.");
    }
}

/* HTTP_REQUEST_COMPOUND_SELECTOR_SOURCE */
#endif
