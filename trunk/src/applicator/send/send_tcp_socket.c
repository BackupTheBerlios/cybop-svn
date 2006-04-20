/*
 * $RCSfile: send_tcp_socket.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_TCP_SOCKET_SOURCE
#define SEND_TCP_SOCKET_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
/*??
#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/converter.c"
#include "../../memoriser/translator.c"
*/

/**
 * Sends a message via tcp socket.
 *
 * @param p0 the internal memory
 * @param p1 the source tui compound model
 * @param p2 the source count
 */
void send_tcp_socket(void* p0, void* p1, void* p2) {

    log_message_debug("Send tcp socket.");
}

/* SEND_TCP_SOCKET_SOURCE */
#endif
