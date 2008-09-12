/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: socket_shutting_maintainer.c,v $ $Revision: 1.5 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SHUTTER_SOURCE
#define SOCKET_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/accessor.c"
#include "../../../memoriser/allocator.c"
#include "../../../memoriser/array.c"

/**
 * Shuts down the socket service.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internals memory
 * @param p1 the base internal
 * @param p2 the socket service thread
 * @param p3 the socket service thread interrupt
 */
void shutdown_socket(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* base = (int*) p1;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Shutdown socket.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
        // The socket internal of this system.
        int** si = (int**) NULL_POINTER_MEMORY_MODEL;

        // Get socket internal of this system.
        i = *base + *SOCKET_INTERNAL;
        get_element(p0, (void*) &i, (void*) &si, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

        if (*si != *NULL_POINTER_MEMORY_MODEL) {

            // Interrupt ALL socket service threads of this system.
            interrupt_thread(p2, p3);

            // The socket address (local, ipv4, ipv6) of this system.
            void** a = NULL_POINTER_MEMORY_MODEL;
            // The communication partner socket address (local, ipv4, ipv6).
            void** pa = NULL_POINTER_MEMORY_MODEL;
            // The socket address size of this system.
            void** as = NULL_POINTER_MEMORY_MODEL;
            // The communication partner socket address size.
            void** pas = NULL_POINTER_MEMORY_MODEL;
            // The socket of this system.
            int** s = (int**) NULL_POINTER_MEMORY_MODEL;
            // The communication partner socket.
            int** ps = (int**) NULL_POINTER_MEMORY_MODEL;
/*??
            // The signal ids.
            void** id = NULL_POINTER_MEMORY_MODEL;
            void** idc = NULL_POINTER_MEMORY_MODEL;
            void** ids = NULL_POINTER_MEMORY_MODEL;
*/
            // The character buffer being used in the thread procedure receiving messages via socket.
            void** b = NULL_POINTER_MEMORY_MODEL;
            void** bc = NULL_POINTER_MEMORY_MODEL;
            void** bs = NULL_POINTER_MEMORY_MODEL;

            // Get socket address of this system.
            i = *base + *SOCKET_ADDRESS_INTERNAL;
            get_element(p0, (void*) &i, (void*) &a, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Get communication partner socket address.
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL;
            get_element(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Get socket address size of this system.
            i = *base + *SOCKET_ADDRESS_SIZE_INTERNAL;
            get_element(p0, (void*) &i, (void*) &as, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Get communication partner socket address size.
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
            get_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Get socket of this system.
            i = *base + *SOCKET_INTERNAL;
            get_element(p0, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Get communication partner socket.
            i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
            get_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            // Get character buffer.
            i = *base + *SOCKET_CHARACTER_BUFFER_INTERNAL;
            get_element(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            i = *base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL;
            get_element(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            i = *base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL;
            get_element(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
/*??
            // Get signal ids.
            get_element(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            get_element(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            get_element(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
*/

            // Close socket of this system.
            close(**s);
            // Close communication partner socket.
//??            close(**ps);

/*??
            // Destroy signal ids.
            deallocate_array((void*) id, (void*) ids, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);
            deallocate(idc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate(ids, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
*/
            // Deallocate character buffer.
            deallocate((void*) b, *bs, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            deallocate((void*) bc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) bs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            // Deallocate socket of this system.
            deallocate((void*) s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            // Deallocate communication partner socket.
            deallocate((void*) ps, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            // Deallocate socket address of this system.
            free(*a);
            // Deallocate communication partner socket address.
            free(*pa);
            // Deallocate socket address size of this system.
            deallocate((void*) as, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            // Deallocate communication partner socket address size.
            deallocate((void*) pas, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not shutdown socket. There is no socket of this system running.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not shutdown socket. The base internal is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SOCKET_SHUTTER_SOURCE */
#endif