/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: layout_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LAYOUT_CYBOL_MODEL_SOURCE
#define LAYOUT_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The root layout cybol model. */
static wchar_t ROOT_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'r', L'o', L'o', L't'};
static wchar_t* ROOT_LAYOUT_CYBOL_MODEL = ROOT_LAYOUT_CYBOL_MODEL_ARRAY;
static int* ROOT_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The coordinates layout cybol model. */
static wchar_t COORDINATES_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'o', L'r', L'd', L'i', L'n', L'a', L't', L'e', L's'};
static wchar_t* COORDINATES_LAYOUT_CYBOL_MODEL = COORDINATES_LAYOUT_CYBOL_MODEL_ARRAY;
static int* COORDINATES_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The compass layout cybol model. */
static wchar_t COMPASS_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L's', L's'};
static wchar_t* COMPASS_LAYOUT_CYBOL_MODEL = COMPASS_LAYOUT_CYBOL_MODEL_ARRAY;
static int* COMPASS_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* LAYOUT_CYBOL_MODEL_SOURCE */
#endif
