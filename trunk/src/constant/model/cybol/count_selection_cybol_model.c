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
 * @version $RCSfile: count_selection_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COUNT_SELECTION_CYBOL_MODEL_SOURCE
#define COUNT_SELECTION_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The all count selection cybol model. */
static wchar_t ALL_COUNT_SELECTION_CYBOL_MODEL_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* ALL_COUNT_SELECTION_CYBOL_MODEL = ALL_COUNT_SELECTION_CYBOL_MODEL_ARRAY;
static int* ALL_COUNT_SELECTION_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The prefix count selection cybol model. */
static wchar_t PREFIX_COUNT_SELECTION_CYBOL_MODEL_ARRAY[] = {L'p', L'r', L'e', L'f', L'i', L'x'};
static wchar_t* PREFIX_COUNT_SELECTION_CYBOL_MODEL = PREFIX_COUNT_SELECTION_CYBOL_MODEL_ARRAY;
static int* PREFIX_COUNT_SELECTION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The suffix count selection cybol model. */
static wchar_t SUFFIX_COUNT_SELECTION_CYBOL_MODEL_ARRAY[] = {L's', L'u', L'f', L'f', L'i', L'x'};
static wchar_t* SUFFIX_COUNT_SELECTION_CYBOL_MODEL = SUFFIX_COUNT_SELECTION_CYBOL_MODEL_ARRAY;
static int* SUFFIX_COUNT_SELECTION_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* COUNT_SELECTION_CYBOL_MODEL_SOURCE */
#endif
