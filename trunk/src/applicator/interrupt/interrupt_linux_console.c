/*
 * $RCSfile: interrupt_linux_console.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2006-05-14 19:35:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_LINUX_CONSOLE_SOURCE
#define INTERRUPT_LINUX_CONSOLE_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <sys/signal.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"

/**
 * Interrupts the linux console service.
 */
void interrupt_linux_console() {

    log_message_debug("Interrupt linux console service.");

    // Set thread interrupt flag.
    *LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_1_INTEGER;

    if (*LINUX_CONSOLE_THREAD != -1) {

        // Send signal to thread.
        // CAUTION! Sending a SIGKILL signal to a thread using pthread_kill()
        // ends the ENTIRE PROCESS, not simply the target thread.
        // SIGKILL is defined to end the entire process, regardless
        // of the thread it is delivered to, or how it is sent.
        // The user signal SIGUSR1 is used here instead.
        pthread_kill(*LINUX_CONSOLE_THREAD, SIGUSR1);

        // Wait for thread to finish.
        pthread_join(*LINUX_CONSOLE_THREAD, NULL_POINTER);

        // Reset thread.
        *LINUX_CONSOLE_THREAD = -1;

    } else {

        log_message_debug("Warning: Could not interrupt x window system. The x window system thread is invalid.");
    }

    // Reset thread interrupt flag.
    *LINUX_CONSOLE_THREAD_INTERRUPT = *NUMBER_0_INTEGER;
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* INTERRUPT_LINUX_CONSOLE_SOURCE */
#endif
