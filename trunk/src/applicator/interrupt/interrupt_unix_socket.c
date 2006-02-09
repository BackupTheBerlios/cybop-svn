/*
 * $RCSfile: interrupt_unix_socket.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2006-02-09 02:22:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_UNIX_SOCKET_SOURCE
#define INTERRUPT_UNIX_SOCKET_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"

/*??
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"
*/

/**
 * Interrupts the unix socket service.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 */
void interrupt_unix_socket(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("Interrupt unix socket service.");

    // The interrupt flag.
    int** f = NULL_POINTER;

    get(p0, (void*) UNIX_SOCKET_INTERRUPT_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if ((f != NULL_POINTER) && (*f != NULL_POINTER)) {

        **f = 1;

    } else {

        log_message_debug("Could not interrupt unix socket service. The unix socket interrupt flag is null.");
    }
}

/* INTERRUPT_UNIX_SOCKET_SOURCE */
#endif
