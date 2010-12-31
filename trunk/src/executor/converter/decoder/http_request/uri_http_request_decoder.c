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

#ifndef URI_HTTP_REQUEST_DECODER_SOURCE
#define URI_HTTP_REQUEST_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/decoder/percent_encoding_character_decoder.c"
#include "../../../../executor/converter/selector/http_request/uri_http_request_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the http request uri content.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source uri
 * @param p4 the source uri count
 */
void decode_http_request_uri_content(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** dd = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http request uri content.");

        // The percent-decoded character array.
        void* p = *NULL_POINTER_MEMORY_MODEL;
        void* pc = *NULL_POINTER_MEMORY_MODEL;
        void* ps = *NULL_POINTER_MEMORY_MODEL;

        // Allocate percent-decoded character array.
        allocate_model((void*) &p, (void*) &pc, (void*) &ps, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST p3: %s \n", (char*) p3);
    fwprintf(stdout, L"TEST p4: %i \n", *((int*) p4));

        //
        // CAUTION! Percent-encoding may be used for all URI, including URL and URN.
        //

        // Decode encoding character array into serialised wide character array.
        decode_percent_encoding_character_vector((void*) &p, pc, ps, p3, p4);

    fwprintf(stdout, L"TEST p: %s \n", (char*) p);
    fwprintf(stdout, L"TEST pc: %i \n", *((int*) pc));
    fwprintf(stdout, L"TEST ps: %i \n", *((int*) ps));

        // The serialised wide character array.
        void* s = *NULL_POINTER_MEMORY_MODEL;
        void* sc = *NULL_POINTER_MEMORY_MODEL;
        void* ss = *NULL_POINTER_MEMORY_MODEL;

        // Allocate serialised wide character array.
        allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Decode encoded character array into serialised wide character array.
        decode_utf_8_unicode_character_vector((void*) &s, sc, ss, p, pc);

    fwprintf(stdout, L"TEST s: %ls \n", (wchar_t*) s);
    fwprintf(stdout, L"TEST sc: %i \n", *((int*) sc));
    fwprintf(stdout, L"TEST ss: %i \n", *((int*) ss));

        // Deallocate percent-decoded character array.
        deallocate_model((void*) &p, (void*) &pc, (void*) &ps, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

        //
        // CAUTION! The uri is added twice to the destination details:
        //
        // 1 as full text representation
        // 2 as compound hierarchy consisting of parts
        //

        // Add uri as full text string.
        append_part(p0, p1, p2,
            (void*) CYBOI_URI_TEXT_HTTP_NAME, (void*) CYBOI_URI_TEXT_HTTP_NAME_COUNT,
            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
            s, sc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

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
            (void*) CYBOI_URI_HTTP_NAME, (void*) CYBOI_URI_HTTP_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        // Decode uri part abstraction.
        decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        // Decode uri part model and details.
        decode((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds,
            s, sc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) URI_TEXT_CYBOL_ABSTRACTION, (void*) URI_TEXT_CYBOL_ABSTRACTION_COUNT);

        // Deallocate serialised wide character array.
        deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Add uri as compound hierarchy consisting of parts.
        // CAUTION! Hand over the name as reference!
        append_compound_element_by_name(*dd, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request uri content. The destination details is null.");
    }
}

/**
 * Decodes the http request uri.
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
void decode_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http request uri.");

            // The element.
            void* e = *pos;
            int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_uri(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_http_request_uri_content(p3, p4, p5, e, (void*) &ec);

                    break;

                } else {

                    // Increment uri count.
                    ec++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request uri. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request uri. The remaining count is null.");
    }
}

/* URI_HTTP_REQUEST_DECODER_SOURCE */
#endif
