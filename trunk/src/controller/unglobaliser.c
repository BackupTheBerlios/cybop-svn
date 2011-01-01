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
 * @version $RCSfile: globaliser.c,v $ $Revision: 1.13 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNGLOBALISER_SOURCE
#define UNGLOBALISER_SOURCE

#include "../controller/unglobaliser/conversion_unglobaliser.c"
#include "../controller/unglobaliser/integral_unglobaliser.c"
#include "../controller/unglobaliser/log_unglobaliser.c"
#include "../controller/unglobaliser/pointer_unglobaliser.c"
#include "../controller/unglobaliser/process_unglobaliser.c"
#include "../controller/unglobaliser/real_unglobaliser.c"
#include "../controller/unglobaliser/reallocation_factor_unglobaliser.c"
#include "../controller/unglobaliser/service_exit_unglobaliser.c"
#include "../controller/unglobaliser/signal_unglobaliser.c"
#include "../controller/unglobaliser/socket_unglobaliser.c"
#include "../controller/unglobaliser/terminal_unglobaliser.c"
#include "../controller/unglobaliser/thread_unglobaliser.c"
#include "../controller/unglobaliser/thread_identification_unglobaliser.c"
#include "../controller/unglobaliser/x_window_system_unglobaliser.c"

/**
 * Deallocates global variables.
 */
void unglobalise() {

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    // Instead, use malloc, free and similar functions directly!
    //

    //
    // There seems to be no need to use descending order,
    // as compared to allocation.
    // The variables do not depend on each other and
    // may be freed in the same order as they were allocated.
    //

    unglobalise_integral();
    unglobalise_real();
    unglobalise_pointer();
    unglobalise_conversion();
    unglobalise_process();
    unglobalise_signal();
    unglobalise_socket();
    unglobalise_terminal();
    unglobalise_thread();
    unglobalise_x_window_system();
    unglobalise_log();
    unglobalise_thread_identification();
    unglobalise_service_exit();
    unglobalise_reallocation_factor();
}

/* UNGLOBALISER_SOURCE */
#endif
