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

#ifndef REALLOCATION_FACTOR_UNGLOBALISER_SOURCE
#define REALLOCATION_FACTOR_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates reallocation factor global variables.
 */
void unglobalise_reallocation_factor() {

    // Free array reallocation factor.
    free((void*) ARRAY_REALLOCATION_FACTOR);

    // Free compound reallocation factor.
    free((void*) COMPOUND_REALLOCATION_FACTOR);

    // Free cybol file reallocation factor.
    free((void*) CYBOL_FILE_REALLOCATION_FACTOR);
}

/* REALLOCATION_FACTOR_UNGLOBALISER_SOURCE */
#endif