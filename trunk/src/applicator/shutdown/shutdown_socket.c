/*
 * $RCSfile: shutdown_socket.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.20 $ $Date: 2007-10-03 23:40:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTDOWN_SOCKET_SOURCE
#define SHUTDOWN_SOCKET_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

/**
 * Shuts down the socket service.
 *
 * @param p0 the internals memory
 * @param p1 the base internal
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void shutdown_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER) {

        int* base = (int*) p1;

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Shutdown socket.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER;
        // The socket internal of this system.
        int** si = (int**) NULL_POINTER;

        // Get socket internal of this system.
        i = *base + *SOCKET_INTERNAL;
        get_element(p0, (void*) &i, (void*) &si, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        if (*si != *NULL_POINTER) {

            // Interrupt ALL socket service threads of this system.
            interrupt_socket();

            // The socket address (local, ipv4, ipv6) of this system.
            void** a = NULL_POINTER;
            // The communication partner socket address (local, ipv4, ipv6).
            void** pa = NULL_POINTER;
            // The socket address size of this system.
            void** as = NULL_POINTER;
            // The communication partner socket address size.
            void** pas = NULL_POINTER;
            // The socket of this system.
            int** s = (int**) NULL_POINTER;
            // The communication partner socket.
            int** ps = (int**) NULL_POINTER;
/*??
            // The signal ids.
            void** id = NULL_POINTER;
            void** idc = NULL_POINTER;
            void** ids = NULL_POINTER;
*/
            // The character buffer being used in the thread procedure receiving messages via socket.
            void** b = NULL_POINTER;
            void** bc = NULL_POINTER;
            void** bs = NULL_POINTER;

            // Get socket address of this system.
            i = *base + *SOCKET_ADDRESS_INTERNAL;
            get_element(p0, (void*) &i, (void*) &a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get communication partner socket address.
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL;
            get_element(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get socket address size of this system.
            i = *base + *SOCKET_ADDRESS_SIZE_INTERNAL;
            get_element(p0, (void*) &i, (void*) &as, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get communication partner socket address size.
            i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
            get_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get socket of this system.
            i = *base + *SOCKET_INTERNAL;
            get_element(p0, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get communication partner socket.
            i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
            get_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get character buffer.
            i = *base + *SOCKET_CHARACTER_BUFFER_INTERNAL;
            get_element(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL;
            get_element(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL;
            get_element(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
/*??
            // Get signal ids.
            get_element(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get_element(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get_element(p0, (void*) SERVER_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/

            // Close socket of this system.
            close(**s);
            // Close communication partner socket.
//??            close(**ps);

/*??
            // Destroy signal ids.
            deallocate_array((void*) id, (void*) ids, (void*) INTEGER_ARRAY);
            deallocate(idc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate(ids, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
*/
            // Deallocate character buffer.
    fprintf(stderr, "TEST 0 b: %i \n", *b);
    fprintf(stderr, "TEST 0 bc: %i \n", **((int**) bc));
    fprintf(stderr, "TEST 0 bs: %i \n", **((int**) bs));
            deallocate((void*) b, *bs, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) bc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) bs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    fprintf(stderr, "TEST 1: %i \n", **s);
            // Deallocate socket of this system.
            deallocate((void*) s, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    fprintf(stderr, "TEST 2: %i \n", **s);
            // Deallocate communication partner socket.
            deallocate((void*) ps, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    fprintf(stderr, "TEST 3: %i \n", **s);
            // Deallocate socket address of this system.
            free(*a);
    fprintf(stderr, "TEST 4: %i \n", **s);
            // Deallocate communication partner socket address.
            free(*pa);
    fprintf(stderr, "TEST 5: %i \n", **s);
            // Deallocate socket address size of this system.
            deallocate((void*) as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    fprintf(stderr, "TEST 6: %i \n", **s);
            // Deallocate communication partner socket address size.
            deallocate((void*) pas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    fprintf(stderr, "TEST 7: %i \n", **s);

        } else {

            log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not shutdown socket. There is no socket of this system running.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not shutdown socket. The base internal is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SHUTDOWN_SOCKET_SOURCE */
#endif
