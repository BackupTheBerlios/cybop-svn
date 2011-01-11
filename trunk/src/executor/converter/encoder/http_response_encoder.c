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
 * @version $RCSfile: http_response_converter.c,v $ $Revision: 1.21 $ $Date: 2009-02-22 19:09:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_RESPONSE_ENCODER_SOURCE
#define HTTP_RESPONSE_ENCODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/converter/encoder/http_response/body_http_response_encoder.c"
#include "../../../executor/converter/encoder/http_response/header_http_response_encoder.c"
#include "../../../executor/converter/encoder/http_response/protocol_http_response_encoder.c"
#include "../../../executor/converter/encoder/http_response/status_code_http_response_encoder.c"
#include "../../../logger/logger.c"

/**
 * Encodes the compound into an http response.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the source message abstraction
 * @param p4 the source message abstraction count
 * @param p5 the source message model
 * @param p6 the source message model count
 * @param p7 the source message details
 * @param p8 the source message details count
 * @param p9 the source metadata abstraction
 * @param p10 the source metadata abstraction count
 * @param p11 the source metadata model
 * @param p12 the source metadata model count
 * @param p13 the source metadata details
 * @param p14 the source metadata details count
 */
void encode_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode http response.");

    //
    // CAUTION! The body is encoded to UTF-8 first, so that its count
    // can be determined, as it has to be given as header value in http.
    //

    // The body character array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;

    // Allocate body character array.
    allocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Encode body wide character array into body multibyte character array.
    encode_utf_8_unicode_character_vector((void*) &a, ac, as, p5, p6);

    encode_http_response_protocol(p0, p1, p2, p9, p10, p11, p12, p13, p14);
    append_array_elements(p0, p1, p2, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

/*??
    encode_http_response_protocol((void*) &a, ac, as, p9, p10, p11, p12, p13, p14);

    fwprintf(stdout, L"TEST encode http response p5: %ls\n", (wchar_t*) p5);
    fwprintf(stdout, L"TEST encode http response p6: %i\n", *((int*) p6));
    fwprintf(stdout, L"TEST encode http response a: %s\n", (char*) a);
    fwprintf(stdout, L"TEST encode http response ac: %i\n", *((int*) ac));
    fwprintf(stdout, L"TEST encode http response p0: %s\n", *((char**) p0));
    fwprintf(stdout, L"TEST encode http response p1: %i\n", *((int*) p1));
*/

    encode_http_response_status_code(p0, p1, p2, p9, p10, p11, p12, p13, p14);
    append_array_elements(p0, p1, p2, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

/*??
    encode_http_response_header(p0, p1, p2, p9, p10, p11, p12, p13, p14, ac);

    //
    // CAUTION! Do NOT add the BODY_BEGIN_SEPARATOR_HTTP_NAME
    // (twice carriage return and line feed).
    // One CR + LF was already added by HEADER_SEPARATOR_HTTP_NAME
    // inside the "encode_http_response_header" function.
    // If there are no header entries (which shouldn't happen normally),
    // then one CR + LF was already added by
    // REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME above.
    // Therefore, ONLY ONE MORE CR + LF is to be added here.
    //
    append_array_elements(p0, p1, p2, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //?? This function is commented out, since it is not needed for now.
    //?? Its content was moved directly into here (see above),
    //?? since the body count (length) needs to be determined.
    //?? encode_http_response_body(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    // CAUTION! Append body ONLY here and NOT before,
    // since it has to stand at the end of the http message.
    append_array_elements(p0, p1, p2, a, ac, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
*/

    // Deallocate body character array.
    deallocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* HTTP_RESPONSE_ENCODER_SOURCE */
#endif
