/*
 * $RCSfile: receive.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.1 $ $Date: 2005-03-01 13:10:58 $ $Author: reichenbach $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOURCE
#define RECEIVE_SOURCE

#include "../global/channel_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"
#include "../socket/unix_socket.c"

/**
 * Receives a message in a special language.
 *
 * CAUTION! Do NOT rename this procedure to "receive",
 * as that name is already used by socket functionality.
 *
 * Expected parameters:
 * - language (channel): internal, tui, gui, socket, http
 * - sender (who): ip address, socket port
 * - receiver (whom): ip address, socket port
 * - message (what): knowledge model to be sent in serialized form
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the internals
 */
void receive_message(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, void* p5) {
}

/* RECEIVE_SOURCE */
#endif
