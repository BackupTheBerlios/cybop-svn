/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef X_WINDOW_SYSTEM_GLOBALISER_SOURCE
#define X_WINDOW_SYSTEM_GLOBALISER_SOURCE

#include <X11/Xlib.h>
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/x_window_system_type_size.c"

/**
 * Allocates and initialises x window system global variables.
 */
void globalise_x_window_system() {

    // Allocate and initialise struct XGCValues x window system type size.
    XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE = (signed int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    // CAUTION! Do NOT use "struct XGCValues" but ONLY "XGCValues".
    // Otherwise, the compiler brings the error:
    // "invalid application of 'sizeof' to incomplete type 'struct XGCValues'"
    *XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE = sizeof(XGCValues);
}

/* X_WINDOW_SYSTEM_GLOBALISER_SOURCE */
#endif
