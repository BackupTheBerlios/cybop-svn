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
 * @version $RCSfile: http_request_selector.c,v $ $Revision: 1.2 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
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
// Example with GET method 1:
//
// GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
// host: de.wikipedia.org
//
// The value pairs (parameters) of the example are:
//
// -------------------------------------
// Argument         Value
// -------------------------------------
// search           Katzen
// go               Artikel
// -------------------------------------
//
// Example with GET method 2:
//
// GET /residenz/test.html HTTP/1.1
// user-agent: Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Debian)
// accept: text/html, image/jpeg, image/png, text/*, image/*,// /*
// accept-encoding: x-gzip, x-deflate, gzip, deflate
// accept-charset: utf-8, utf-8;q=0.5, *;q=0.5
// accept-language: en, de, pl
// host: 127.0.0.1:1971
// connection: Keep-Alive
//
// Example with POST method:
//
// POST /wiki/Spezial:Search HTTP/1.1
// host: de.wikipedia.org
// content-type: application/x-www-form-urlencoded
// content-length: 24
//
// search=Katzen&go=Artikel
//

//
// Forward declarations.
//

void process_http_request_uri(void* p0, void* p1, void* p2);
void process_http_request_protocol(void* p0, void* p1, void* p2);
void process_http_request_header_argument(void* p0, void* p1, void* p2);
void process_http_request_header_value(void* p0, void* p1, void* p2);
void process_http_request_body(void* p0, void* p1, void* p2);

/**
 * Selects the http request method.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_method(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_uri(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request method. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request method. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request method. The remaining count is null.");
    }
}

/**
 * Selects the http request uri.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_uri(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request uri.");

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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_protocol(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request uri. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request uri. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request uri. The remaining count is null.");
    }
}

/**
 * Selects the http request protocol.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_protocol(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request protocol.");

                //
                // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
                // Before the request response line final element http name (ending with "carriage return"
                // and "line feed") can be identified, the possibility of a body begin http name
                // (twice "carriage return" and "line feed") indicating the message body
                // has to be considered:
                // - twice "carriage return" and "line feed"
                // - "carriage return" and "line feed"
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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) BODY_BEGIN_HTTP_NAME, (void*) BODY_BEGIN_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_body(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_header_argument(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request protocol. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request protocol. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request protocol. The remaining count is null.");
    }
}

/**
 * Selects the http request header argument.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_header_argument(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request header argument.");

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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) HEADER_ARGUMENT_HTTP_NAME, (void*) HEADER_ARGUMENT_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_header_value(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header argument. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header argument. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header argument. The remaining count is null.");
    }
}

/**
 * Selects the http request header value.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_header_value(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request header value.");

                //
                // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
                // Before the header value http name or header http name (ending with "carriage return"
                // and "line feed") can be identified, the possibility of a body begin
                // (twice "carriage return" and "line feed") indicating the message body
                // has to be considered:
                // - twice "carriage return" and "line feed"
                // - "carriage return" and "line feed"
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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) BODY_BEGIN_HTTP_NAME, (void*) BODY_BEGIN_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_body(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) HEADER_HTTP_NAME, (void*) HEADER_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        process_http_request_header_argument(p1, p2);

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header value. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header value. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request header value. The remaining count is null.");
    }
}

/**
 * Selects the http request body.
 *
 * @param p0 the break flag
 * @param p1 the current position (Hand over as reference!)
 * @param p2 the remaining count
 */
void select_http_request_body(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* b = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http request body.");

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

                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect((void*) &r, p1, p2, (void*) BODY_END_HTTP_NAME, (void*) BODY_END_HTTP_NAME_COUNT, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        // Set break flag.
                        *b = *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    detect_move_position(p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request body. The break flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request body. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select http request body. The remaining count is null.");
    }
}

/* HTTP_REQUEST_SELECTOR_SOURCE */
#endif
