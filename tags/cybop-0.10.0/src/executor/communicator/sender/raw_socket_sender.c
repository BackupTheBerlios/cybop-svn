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
 * @version $RCSfile: raw_socket_communicator.c,v $ $Revision: 1.8 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RAW_SOCKET_SENDER_SOURCE
#define RAW_SOCKET_SENDER_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/comparator/array_equality_comparator.c"

/**
 * Sends a byte array stream to the raw socket.
 *
 * @param p0 the destination socket of this system
 * @param p1 the source byte array
 * @param p2 the source byte array count
 * @param p3 the socket address of the communication partner (Hand over as reference!)
 * @param p4 the socket address of the communication partner size
 * @param p5 the communication mode
 * @param p6 the communication mode count
 * @param p7 the communication style
 */
void send_raw_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // Not implemented.
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send to raw socket.");
    log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"The raw socket functionality is NOT implemented yet!");
}

/* RAW_SOCKET_SENDER_SOURCE */
#endif
