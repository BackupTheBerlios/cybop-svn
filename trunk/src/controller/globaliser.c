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

#ifndef GLOBALISER_SOURCE
#define GLOBALISER_SOURCE

#include "../controller/globaliser/conversion_globaliser.c"
#include "../controller/globaliser/integral_globaliser.c"
#include "../controller/globaliser/log_globaliser.c"
#include "../controller/globaliser/pointer_globaliser.c"
#include "../controller/globaliser/process_globaliser.c"
#include "../controller/globaliser/real_globaliser.c"
#include "../controller/globaliser/reallocation_factor_globaliser.c"
#include "../controller/globaliser/service_exit_globaliser.c"
#include "../controller/globaliser/signal_globaliser.c"
#include "../controller/globaliser/socket_globaliser.c"
#include "../controller/globaliser/terminal_globaliser.c"
#include "../controller/globaliser/thread_globaliser.c"
#include "../controller/globaliser/thread_identification_globaliser.c"
#include "../controller/globaliser/x_window_system_globaliser.c"

/**
 * Allocates and initialises global variables.
 */
void globalise() {

    //
    // CAUTION! These global variables MUST NOT be initialised in the files
    // "variable/*.c" because then, constant values are expected!
    //

    //
    // CAUTION! DO NOT use array functionality here!
    // The array functions use the logger which in turn depends on global
    // log variables set here. So this would cause circular references.
    // Instead, use malloc, free and similar functions directly!
    //

    //
    // CAUTION! The glibc manual states that the data type of the result
    // of the "sizeof" function may vary between compilers.
    // It therefore recommends to use type "size_t" (instead of "int")
    // as the preferred way to declare any arguments or variables
    // that hold the size of an object.
    //
    // See:
    // http://www.gnu.org/software/libtool/manual/libc/Important-Data-Types.html#Important-Data-Types
    //
    // However, cyboi assigns the sizes of all primitive types to special
    // global integer variables at system startup, in module "globaliser.c".
    // As long as these global integer variables are used, there is
    // no need to work with type "sizt_t" in cyboi source code.
    //

    //
    // CAUTION! The SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE variable needs to be
    // initialised FIRST, BEFORE all other initialisations,
    // because all other assignments below make use of it.
    //
    // Therefore, the "globalise_integral" function HAS TO BE CALLED FIRST!
    //

    globalise_integral();
    globalise_real();
    globalise_pointer();
    globalise_conversion();
    globalise_process();
    globalise_signal();
    globalise_socket();
    globalise_terminal();
    globalise_thread();
    globalise_x_window_system();
    globalise_log();
    globalise_thread_identification();
    globalise_service_exit();
    globalise_reallocation_factor();
}

/* GLOBALISER_SOURCE */
#endif
