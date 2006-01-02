/*
 * $RCSfile: startup_unix_socket.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2006-01-02 11:56:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef STARTUP_UNIX_SOCKET_SOURCE
#define STARTUP_UNIX_SOCKET_SOURCE

#include "../../globals/constants/log_constants.c"
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
#include "../../memoriser/allocator.c"
*/

/**
 * Starts up the unix socket.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 * @param p4 the socke port abstraction
 * @param p5 the socke port abstraction count
 * @param p6 the socke port model
 * @param p7 the socke port model count
 */
void startup_unix_socket(void* internals, void* know, void* know_count, void* know_size,
    void* socket_port_abstr, void* socket_port_abstr_count, void* socket_port_model, void* socket_port_model_count) {

    log_message_debug("Startup unix socket.");
}

/* STARTUP_UNIX_SOCKET_SOURCE */
#endif
