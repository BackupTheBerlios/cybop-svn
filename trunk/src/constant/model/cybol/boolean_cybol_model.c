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
 * @version $RCSfile: boolean_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_CYBOL_MODEL_SOURCE
#define BOOLEAN_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The false boolean cybol model. */
static wchar_t FALSE_BOOLEAN_CYBOL_MODEL_ARRAY[] = {L'f', L'a', L'l', L's', L'e'};
static wchar_t* FALSE_BOOLEAN_CYBOL_MODEL = FALSE_BOOLEAN_CYBOL_MODEL_ARRAY;
static int* FALSE_BOOLEAN_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The true boolean cybol model. */
static wchar_t TRUE_BOOLEAN_CYBOL_MODEL_ARRAY[] = {L't', L'r', L'u', L'e'};
static wchar_t* TRUE_BOOLEAN_CYBOL_MODEL = TRUE_BOOLEAN_CYBOL_MODEL_ARRAY;
static int* TRUE_BOOLEAN_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* BOOLEAN_CYBOL_MODEL_SOURCE */
#endif
