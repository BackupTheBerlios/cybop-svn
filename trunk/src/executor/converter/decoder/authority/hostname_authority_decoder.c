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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HOSTNAME_AUTHORITY_DECODER_SOURCE
#define HOSTNAME_AUTHORITY_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/authority/hostname_authority_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the authority hostname.
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
void decode_authority_hostname(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode authority hostname.");

            // The element.
            void* e = *pos;
            int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*TRUE_BOOLEAN_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_authority_hostname(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;

                } else {

                    // Increment element count.
                    ec++;
                }
            }

            //
            // If the hostname-port separator : was NOT found,
            // then no port was given.
            // In this case, the source represents a hostname only.
            //
            // If the hostname-port separator : WAS found,
            // then a port was given.
            // In this case, the port was already decoded
            // inside the "select_authority_hostname" function.
            //
            append_part(p0, p1, p2,
                (void*) CYBOI_HOSTNAME_AUTHORITY_NAME, (void*) CYBOI_HOSTNAME_AUTHORITY_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                e, (void*) &ec, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode authority hostname. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode authority hostname. The remaining count is null.");
    }
}

/* HOSTNAME_AUTHORITY_DECODER_SOURCE */
#endif
