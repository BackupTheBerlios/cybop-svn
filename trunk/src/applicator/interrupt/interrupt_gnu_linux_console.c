/*
 * $RCSfile: interrupt_gnu_linux_console.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2007-10-03 23:40:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_GNU_LINUX_CONSOLE_SOURCE
#define INTERRUPT_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <sys/signal.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/service_interrupt_variables.c"
#include "../../globals/variables/thread_identification_variables.c"
#include "../../memoriser/accessor.c"

/**
 * Interrupts the gnu/linux console service.
 */
void interrupt_gnu_linux_console() {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Interrupt gnu/linux console service.");

    if (*GNU_LINUX_CONSOLE_THREAD != *NUMBER_MINUS_1_INTEGER) {

        // Set thread interrupt flag for signal handler.
        *GNU_LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_1_INTEGER;

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
        pthread_kill(*GNU_LINUX_CONSOLE_THREAD, SIGUSR1);

        // Wait for thread to finish.
        pthread_join(*GNU_LINUX_CONSOLE_THREAD, *NULL_POINTER);

        // Reset thread.
        *GNU_LINUX_CONSOLE_THREAD = *NUMBER_MINUS_1_INTEGER;

        // Reset thread interrupt flag for signal handler.
        *GNU_LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;

    } else {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not interrupt gnu/linux console. The gnu/linux console thread is invalid.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* INTERRUPT_GNU_LINUX_CONSOLE_SOURCE */
#endif
