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
 * @version $RCSfile: border_cybol_model.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BORDER_CYBOL_MODEL_SOURCE
#define BORDER_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The ascii line border cybol model. */
static wchar_t ASCII_LINE_BORDER_CYBOL_MODEL_ARRAY[] = {L'a', L's', L'c', L'i', L'i'};
static wchar_t* ASCII_LINE_BORDER_CYBOL_MODEL = ASCII_LINE_BORDER_CYBOL_MODEL_ARRAY;
static int* ASCII_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The double line border cybol model. */
static wchar_t DOUBLE_LINE_BORDER_CYBOL_MODEL_ARRAY[] = {L'd', L'o', L'u', L'b', L'l', L'e'};
static wchar_t* DOUBLE_LINE_BORDER_CYBOL_MODEL = DOUBLE_LINE_BORDER_CYBOL_MODEL_ARRAY;
static int* DOUBLE_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The round line border cybol model. */
static wchar_t ROUND_LINE_BORDER_CYBOL_MODEL_ARRAY[] = {L'r', L'o', L'u', L'n', L'd'};
static wchar_t* ROUND_LINE_BORDER_CYBOL_MODEL = ROUND_LINE_BORDER_CYBOL_MODEL_ARRAY;
static int* ROUND_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The simple line border cybol model. */
static wchar_t SIMPLE_LINE_BORDER_CYBOL_MODEL_ARRAY[] = {L's', L'i', L'm', L'p', L'l', L'e'};
static wchar_t* SIMPLE_LINE_BORDER_CYBOL_MODEL = SIMPLE_LINE_BORDER_CYBOL_MODEL_ARRAY;
static int* SIMPLE_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* BORDER_CYBOL_MODEL_SOURCE */
#endif
