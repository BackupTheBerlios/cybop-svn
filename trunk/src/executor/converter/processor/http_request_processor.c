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

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/http/compound_http_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/part_accessor.c"
#include "../../memoriser/selector/http_request_selector.c"

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
// known fact that HTML forms have been violating that rule for years. Similar
// comment for HTML4's 17.13.1.
//

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

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

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
                            (void*) METHOD_COMPOUND_HTTP_NAME, (void*) METHOD_COMPOUND_HTTP_NAME_COUNT,
                            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION,
                            rm, (void*) &rmc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                        break;

                    } else {

                        // Increment request method count.
                        rmc++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request method. The destination details is null.");
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

                        append_part(p3, p4, p5,
                            (void*) URI_COMPOUND_HTTP_NAME, (void*) URI_COMPOUND_HTTP_NAME_COUNT,
                            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION,
                            u, (void*) &uc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

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

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

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
                            (void*) PROTOCOL_COMPOUND_HTTP_NAME, (void*) PROTOCOL_COMPOUND_HTTP_NAME_COUNT,
                            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION,
                            p, (void*) &pc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                        break;

                    } else {

                        // Increment protocol count.
                        pc++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request protocol. The destination details is null.");
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

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

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

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header argument. The destination details is null.");
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

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

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

                        select_http_request_header(p3, p4, p5, p8, p9, hv, (void*) &hvc);

                        break;

                    } else {

                        // Increment header value count.
                        hvc++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request header value. The destination details is null.");
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

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process http request body.");

                // The body.
                void* bo = *pos;
                int boc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // The break flag.
                int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        break;
                    }

                    select_http_request_body(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                    if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

/*??
                        append_part(p3, p4, p5,
                            (void*) PROTOCOL_COMPOUND_HTTP_NAME, (void*) PROTOCOL_COMPOUND_HTTP_NAME_COUNT,
                            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION,
                            p, (void*) &pc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
*/

                        break;

                    } else {

                        // Increment body count.
                        boc++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request body. The destination details is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request body. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process http request body. The remaining count is null.");
    }
}

/* HTTP_REQUEST_PROCESSOR_SOURCE */
#endif
