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

#ifndef CONVERSION_GLOBALISER_SOURCE
#define CONVERSION_GLOBALISER_SOURCE

#include <wchar.h>
#include "../../variable/type_size/conversion_type_size.c"
#include "../../variable/type_size/integral_type_size.c"

/**
 * Allocates and initialises conversion global variables.
 */
void globalise_conversion() {

    // Allocate and initialise struct mbstate_t conversion type size.
    MULTIBYTE_CHARACTER_STATE_CONVERSION_TYPE_SIZE = (signed char*) malloc(*SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    // CAUTION! Do NOT use "struct mbstate_t" but ONLY "mbstate_t".
    // Otherwise, the compiler brings the error:
    // "invalid application of 'sizeof' to incomplete type 'struct mbstate_t'"
    *MULTIBYTE_CHARACTER_STATE_CONVERSION_TYPE_SIZE = sizeof(mbstate_t);
}

/* CONVERSION_GLOBALISER_SOURCE */
#endif
