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
 * @version $RCSfile: print_cybol_abstraction.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PRINT_MIME_TYPE_CONSTANTS_SOURCE
#define PRINT_MIME_TYPE_CONSTANTS_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// This MIME type was taken from/ inspired by the KDE desktop.
// It is not sure yet, whether it will be useful in the context of CYBOI.
//

/**
 * The print/jobs cybol abstraction.
 */
static wchar_t JOBS_PRINT_CYBOL_ABSTRACTION_ARRAY[] = {L'p', L'r', L'i', L'n', L't', L'/', L'j', L'o', L'b', L's'};
static wchar_t* JOBS_PRINT_CYBOL_ABSTRACTION = JOBS_PRINT_CYBOL_ABSTRACTION_ARRAY;
static int* JOBS_PRINT_CYBOL_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/* PRINT_MIME_TYPE_CONSTANTS_SOURCE */
#endif
