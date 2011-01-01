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

#ifndef INTEGRAL_UNGLOBALISER_SOURCE
#define INTEGRAL_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates integral global variables.
 */
void unglobalise_integral() {

    // Free signed char integral type size.
    free((void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

    // Free unsigned char integral type size.
    free((void*) UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

    // Free signed short int integral type size.
    free((void*) SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned short int integral type size.
    free((void*) UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free signed int integral type size.
    free((void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned int integral type size.
    free((void*) UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free signed long int integral type size.
    free((void*) SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned long int integral type size.
    free((void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free signed long long int integral type size.
    free((void*) SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free unsigned long long int integral type size.
    free((void*) UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

    // Free wchar_t integral type size.
    free((void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
}

/* INTEGRAL_UNGLOBALISER_SOURCE */
#endif
