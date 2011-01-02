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
 * @version $RCSfile: http_request_compound_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSOLUTE_URI_SELECTOR_SOURCE
#define ABSOLUTE_URI_SELECTOR_SOURCE

#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/model/uri/scheme_uri_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/converter/decoder/uri/http_uri_decoder.c"
#include "../../../../logger/logger.c"

/**
 * Selects absolute uri.
 *
 * Examples:
 *
 * ftp://ftp.is.co.za/rfc/rfc1808.txt
 * http://www.ietf.org/rfc/rfc2396.txt
 * ldap://[2001:db8::7]/c=GB?objectClass?one
 * mailto:John.Doe@example.com
 * news:comp.infosystems.www.servers.unix
 * tel:+1-816-555-1212
 * telnet://192.0.2.16:80/
 * urn:oasis:names:specification:docbook:dtd:xml:4.1.2
 *
 * CAUTION! Each URI begins with a scheme name that refers to a
 * specification for assigning identifiers within that scheme.
 * As such, the URI syntax is a federated and extensible
 * naming system wherein each scheme's specification may
 * further restrict the syntax and semantics of identifiers
 * using that scheme.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the current position (Hand over as reference!)
 * @param p7 the remaining count
 * @param p8 the scheme
 * @param p9 the scheme count
 */
void select_absolute_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select absolute uri.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) FTP_SCHEME_URI_MODEL, (void*) FTP_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) HTTP_SCHEME_URI_MODEL, (void*) HTTP_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_http_uri(p0, p1, p2, p3, p4, p5, *((void**) p6), p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) LDAP_SCHEME_URI_MODEL, (void*) LDAP_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) MAILTO_SCHEME_URI_MODEL, (void*) MAILTO_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) NEWS_SCHEME_URI_MODEL, (void*) NEWS_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) TEL_SCHEME_URI_MODEL, (void*) TEL_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) TELNET_SCHEME_URI_MODEL, (void*) TELNET_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p8, p9, (void*) URN_SCHEME_URI_MODEL, (void*) URN_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not select absolute uri. The uri scheme is unknown.");
    }
}

/* ABSOLUTE_URI_SELECTOR_SOURCE */
#endif
