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

#ifndef URI_SCHEME_EVALUATOR_SOURCE
#define URI_SCHEME_EVALUATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/uri/scheme_uri_model.c"
#include "../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../constant/name/xml_name.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/detector.c"

/**
 * Evaluates uri scheme.
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
 * @param p3 the source body
 * @param p4 the source body count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 * @param p7 the source request method
 * @param p8 the source request method count
 */
void evaluate_uri_scheme(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** d = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Evaluate uri scheme.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) FTP_SCHEME_URI_MODEL, (void*) FTP_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) HTTP_SCHEME_URI_MODEL, (void*) HTTP_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) LDAP_SCHEME_URI_MODEL, (void*) LDAP_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) MAILTO_SCHEME_URI_MODEL, (void*) MAILTO_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) NEWS_SCHEME_URI_MODEL, (void*) NEWS_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) TEL_SCHEME_URI_MODEL, (void*) TEL_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) TELNET_SCHEME_URI_MODEL, (void*) TELNET_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal_arrays((void*) &r, p7, p8, (void*) URN_SCHEME_URI_MODEL, (void*) URN_SCHEME_URI_MODEL_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                //?? TODO
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode http request method. The source request method is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http request method. The destination model is null.");
    }
}

/* URI_SCHEME_EVALUATOR_SOURCE */
#endif
