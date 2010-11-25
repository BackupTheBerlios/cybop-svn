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
 * Converts the given characters to wide characters and
 * appends them to the destination.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 */
void process_http_request_append_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

/*??
    fwprintf(stdout, L"TEST process_http_request_append sm: %s \n", (char*) p7);
    fwprintf(stdout, L"TEST process_http_request_append smc: %i \n", *((int*) p8));
*/

    // Decode encoded character array into serialised wide character array.
    decode_utf_8_unicode_character_vector((void*) &s, sc, ss, p7, p8);

/*??
    fwprintf(stdout, L"TEST process_http_request_append s: %ls \n", (wchar_t*) s);
    fwprintf(stdout, L"TEST process_http_request_append sc: %i \n", *((int*) sc));
    fwprintf(stdout, L"TEST process_http_request_append socket ss: %i \n", *((int*) ss));
*/

    append_part(p0, p1, p2, p3, p4, p5, p6, s, sc, p9, p10);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/* HTTP_REQUEST_PROCESSOR_SOURCE */
#endif
