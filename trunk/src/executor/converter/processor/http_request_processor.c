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

#ifndef HTTP_REQUEST_PROCESSOR_SOURCE
#define HTTP_REQUEST_PROCESSOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/http/cyboi_http_name.c"
#include "../../../executor/accessor/appender/part_appender.c"
#include "../../../executor/converter/selector/http_request_selector.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"

//
// Taken from:
// https://bugzilla.mozilla.org/show_bug.cgi?id=18643
//
// We cannot add a charset parameter to the Content-Type header for HTTP GET,
// because there is no Content-Type header in the case of GET (since there is no
// body following the headers). A *lot* of forms use GET.
//
// Since the charset of GET requests is always straight 7bit ASCII encoding
// standard ISO-Latin-1 text, I would have thought that that was pretty irrelevant.
//
// According to RFC1630:
// #     Where the local naming scheme uses ASCII characters which are not
// #     allowed in the URI, these may be represented in the URL by a
// #     percent sign "%" immediately followed by two hexadecimal digits
// #     (0-9, A-F) giving the ISO Latin 1 code for that character.
//                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Does this not mean that URIs can only contain a single character encoding?
//
// Similarly in HTML4, section 17.13.1:
// #   Note. The "get" method restricts form data set values to ASCII
// #   characters. Only the "post" method (with
// #   enctype="multipart/form-data") is specified to cover the entire
// #   [ISO10646] character set.
//
// RFC1630 does attempt to restrict URIs to iso-8859-1, but it is a well
// known fact that HTML forms have been violating that rule for years.
// Similar comment for HTML4's 17.13.1.
//

/**
 * Processes the http request message header.
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
void process_http_request_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request header.");

            // The request header.
            void* rh = *pos;
            int rhc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_header(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;

                } else {

                    // Increment request header count.
                    rhc++;
                }
            }

            //
            // The header has to be processed in any case,
            // no matter whether its end was detected as:
            // - body begin (b != 0)
            // - end of the whole message (*rem <= 0)
            //
            // Therefore, it is placed outside the loop.
            //

            // The serialised wide character array.
            void* s = *NULL_POINTER_MEMORY_MODEL;
            void* sc = *NULL_POINTER_MEMORY_MODEL;
            void* ss = *NULL_POINTER_MEMORY_MODEL;

            // Allocate serialised wide character array.
            allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

            // Decode encoded character array into serialised wide character array.
            decode_utf_8_unicode_character_vector((void*) &s, sc, ss, rh, (void*) &rhc);

            // The serialised wide character array copy.
            void* c = s;
            int cc = *((int*) sc);

            // CAUTION! Hand over a COPY of the wide character array!
            // This is necessary, because the processing functions
            // increment the array pointer inside, so that deallocation
            // would fail below, as the pointer does not point to the
            // begin of the array anymore.
            process_http_request_method(p0, p1, p2, p3, p4, p5, (void*) &c, (void*) &cc);

            // Deallocate serialised wide character array.
            deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header. The remaining count is null.");
    }
}

/**
 * Processes the http request method.
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
void process_http_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request method.");

            // The request method.
            void* rm = *pos;
            int rmc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_method(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    append_part(p3, p4, p5,
                        (void*) CYBOI_METHOD_HTTP_NAME, (void*) CYBOI_METHOD_HTTP_NAME_COUNT,
                        (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                        rm, (void*) &rmc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                    break;

                } else {

                    // Increment request method count.
                    rmc++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request method. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request method. The remaining count is null.");
    }
}

/**
 * Processes the http request uri.
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
void process_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request uri.");

                // The uri.
                void* u = *pos;
                int uc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // The break flag.
                int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        break;
                    }

                    select_http_request_uri(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                    if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        //
                        // CAUTION! The uri is added twice to the destination details:
                        //
                        // 1 as full text representation
                        // 2 as compound hierarchy consisting of parts
                        //

                        // Add uri as full text string.
                        append_part(p3, p4, p5,
                            (void*) CYBOI_URI_HTTP_NAME, (void*) CYBOI_URI_HTTP_NAME_COUNT,
                            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                            u, (void*) &uc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                        // The uri part name, abstraction, model, details.
                        void* n = *NULL_POINTER_MEMORY_MODEL;
                        void* nc = *NULL_POINTER_MEMORY_MODEL;
                        void* ns = *NULL_POINTER_MEMORY_MODEL;
                        void* a = *NULL_POINTER_MEMORY_MODEL;
                        void* ac = *NULL_POINTER_MEMORY_MODEL;
                        void* as = *NULL_POINTER_MEMORY_MODEL;
                        void* m = *NULL_POINTER_MEMORY_MODEL;
                        void* mc = *NULL_POINTER_MEMORY_MODEL;
                        void* ms = *NULL_POINTER_MEMORY_MODEL;
                        void* d = *NULL_POINTER_MEMORY_MODEL;
                        void* dc = *NULL_POINTER_MEMORY_MODEL;
                        void* ds = *NULL_POINTER_MEMORY_MODEL;

                        // Allocate uri part.
                        allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                            (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

                        // Decode uri part name.
                        decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                            (void*) CYBOI_PARTS_URI_HTTP_NAME, (void*) CYBOI_PARTS_URI_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

                        // Decode uri part abstraction.
                        decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                            (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

                        // Decode uri part model and details.
                        decode((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds,
                            u, (void*) &uc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                            (void*) URI_TEXT_CYBOL_ABSTRACTION, (void*) URI_TEXT_CYBOL_ABSTRACTION_COUNT);

                        // Add uri as compound hierarchy consisting of parts.
                        // CAUTION! Hand over the name as reference!
                        append_compound_element_by_name(*dd, p4, p5, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

                        break;

                    } else {

                        // Increment uri count.
                        uc++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request uri. The destination details is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request uri. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request uri. The remaining count is null.");
    }
}

/**
 * Processes the http request protocol.
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
void process_http_request_protocol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request protocol.");

            // The protocol.
            void* p = *pos;
            int pc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_protocol(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    append_part(p3, p4, p5,
                        (void*) CYBOI_PROTOCOL_HTTP_NAME, (void*) CYBOI_PROTOCOL_HTTP_NAME_COUNT,
                        (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                        p, (void*) &pc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                    break;

                } else {

                    // Increment protocol count.
                    pc++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request protocol. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request protocol. The remaining count is null.");
    }
}

/**
 * Processes the http request header argument.
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
void process_http_request_header_argument(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request header argument.");

            // The header argument.
            void* ha = *pos;
            int hac = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_header_argument(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7, ha, (void*) &hac);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;

                } else {

                    // Increment header argument count.
                    hac++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header argument. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header argument. The remaining count is null.");
    }
}

/**
 * Processes the http request header value.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the current position (Hand over as reference!)
 * @param p7 the remaining count
 * @param p8 the header argument
 * @param p9 the header argument count
 */
void process_http_request_header_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request header value.");

            // The header value.
            void* hv = *pos;
            int hvc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_header_value(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    select_http_request_header_field(p3, p4, p5, p8, p9, hv, (void*) &hvc);

                    break;

                } else {

                    // Increment header value count.
                    hvc++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header value. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header value. The remaining count is null.");
    }
}

/**
 * Processes the http request body.
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
void process_http_request_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        void** pos = (void**) p6;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request body.");

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

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request body. The current position is null.");
    }
}

/* HTTP_REQUEST_PROCESSOR_SOURCE */
#endif
