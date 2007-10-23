/*
 * $RCSfile: interrupt_socket.c,v $
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
 * @version $Revision: 1.12 $ $Date: 2007-10-23 17:37:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef INTERRUPT_SOCKET_SOURCE
#define INTERRUPT_SOCKET_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Interrupts the socket service.
 *
 * The service may be for example:
 * - www
 * - cyboi
 * - etc.
 *
 * @param p0 the socket service thread
 * @param p1 the socket service thread interrupt
 */
void interrupt_socket(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* i = (int*) p1;

        if (p0 != *NULL_POINTER) {

            pthread_t* t = (pthread_t*) p0;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Interrupt socket service.");

            if (*t != *NUMBER_MINUS_1_INTEGER) {

                // Set thread interrupt flag for signal handler.
                *i = *NUMBER_1_INTEGER;

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
                pthread_kill(*t, SIGUSR1);

                // Wait for thread to finish.
                pthread_join(*t, *NULL_POINTER);

                // Reset thread.
                *t = *NUMBER_MINUS_1_INTEGER;

                // Reset thread interrupt flag for signal handler.
                *i = *NUMBER_0_INTEGER;

            } else {

                log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not interrupt socket service. The socket service thread is invalid.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not interrupt socket service. The socket service thread is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not interrupt socket service. The socket service thread interrupt is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* INTERRUPT_SOCKET_SOURCE */
#endif
