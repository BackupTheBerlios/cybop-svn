/*
 * $RCSfile: interrupt_socket.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2006-12-28 16:04:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef INTERRUPT_SOCKET_SOURCE
#define INTERRUPT_SOCKET_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Interrupts the socket service.
 */
void interrupt_socket() {

    log_message_debug("Interrupt socket service.");

    if (*WWW_SERVICE_THREAD != *INVALID_VALUE) {

        // Set thread interrupt flag for signal handler.
        *WWW_SERVICE_THREAD_INTERRUPT = *NUMBER_1_INTEGER;

        // Send signal to thread.
        //
        // CAUTION! Sending a SIGKILL signal to a thread using pthread_kill()
        // ends the ENTIRE PROCESS, not simply the target thread.
        // SIGKILL is defined to end the entire process, regardless
        // of the thread it is delivered to, or how it is sent.
        //
        // Therefore, the user signal SIGUSR1 is used here instead.
        // It is processed in the interrupt_service_system_signal_handler
        // procedure, situated in the following module:
        // controller/manager/system_signal_handler_manager.c
        pthread_kill(*WWW_SERVICE_THREAD, SIGUSR1);

        // Wait for thread to finish.
        pthread_join(*WWW_SERVICE_THREAD, NULL_POINTER);

        // Reset thread.
        *WWW_SERVICE_THREAD = *INVALID_VALUE;

        // Reset thread interrupt flag for signal handler.
        *WWW_SERVICE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;

    } else {

        log_message_debug("Warning: Could not interrupt socket. The server socket thread is invalid.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* INTERRUPT_SOCKET_SOURCE */
#endif
