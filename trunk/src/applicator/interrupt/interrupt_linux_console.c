/*
 * $RCSfile: interrupt_linux_console.c,v $
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
 * @version $Revision: 1.9 $ $Date: 2007-04-16 15:56:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_LINUX_CONSOLE_SOURCE
#define INTERRUPT_LINUX_CONSOLE_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <sys/signal.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log_message/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Interrupts the linux console service.
 */
void interrupt_linux_console() {

    log_message_debug("Interrupt linux console service.");

    if (*LINUX_CONSOLE_THREAD != *INVALID_VALUE) {

        // Set thread interrupt flag for signal handler.
        *LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_1_INTEGER;

        // Send signal to thread.
        //
        // CAUTION! Sending a SIGKILL signal to a thread using pthread_kill()
        // would end the ENTIRE PROCESS, not simply the target thread.
        // SIGKILL is defined to end the entire process, regardless
        // of the thread it is delivered to, or how it is sent.
        //
        // Therefore, the user signal SIGUSR1 is used here instead.
        // It is processed in the interrupt_service_system_signal_handler
        // procedure, situated in the following module:
        // controller/manager/system_signal_handler_manager.c
        pthread_kill(*LINUX_CONSOLE_THREAD, SIGUSR1);

        // Wait for thread to finish.
        pthread_join(*LINUX_CONSOLE_THREAD, NULL_POINTER);

        // Reset thread.
        *LINUX_CONSOLE_THREAD = *INVALID_VALUE;

        // Reset thread interrupt flag for signal handler.
        *LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;

    } else {

        log_message_debug("Warning: Could not interrupt linux console. The linux console thread is invalid.");
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* INTERRUPT_LINUX_CONSOLE_SOURCE */
#endif
