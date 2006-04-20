/*
 * $RCSfile: receive_unix_socket.c,v $
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
 * @description
 */

#ifndef RECEIVE_UNIX_SOCKET_SOURCE
#define RECEIVE_UNIX_SOCKET_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"

/*??
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "../../applicator/create.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/constant.c"
#include "../../globals/constants/escape_code_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/internal_memory_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"
*/

/**
 * Receives via unix socket.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 */
void receive_unix_socket(void* p0, void* p1, void* p2) {

    log_message_debug("Receive via unix socket.");
}

/* RECEIVE_UNIX_SOCKET_SOURCE */
#endif
