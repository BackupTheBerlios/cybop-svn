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
 * @version $RCSfile: compass_layout_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPASS_LAYOUT_CYBOL_MODEL_SOURCE
#define COMPASS_LAYOUT_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

/** The north compass layout cybol model. */
static wchar_t NORTH_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'n', L'o', L'r', L't', L'h'};
static wchar_t* NORTH_COMPASS_LAYOUT_CYBOL_MODEL = NORTH_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY;
static int* NORTH_COMPASS_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The south compass layout cybol model. */
static wchar_t SOUTH_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY[] = {L's', L'o', L'u', L't', L'h'};
static wchar_t* SOUTH_COMPASS_LAYOUT_CYBOL_MODEL = SOUTH_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY;
static int* SOUTH_COMPASS_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The west compass layout cybol model. */
static wchar_t WEST_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'w', L'e', L's', L't'};
static wchar_t* WEST_COMPASS_LAYOUT_CYBOL_MODEL = WEST_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY;
static int* WEST_COMPASS_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The east compass layout cybol model. */
static wchar_t EAST_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'e', L'a', L's', L't'};
static wchar_t* EAST_COMPASS_LAYOUT_CYBOL_MODEL = EAST_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY;
static int* EAST_COMPASS_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The centre compass layout cybol model. */
static wchar_t CENTRE_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY[] = {L'c', L'e', L'n', L't', L'r', L'e'};
static wchar_t* CENTRE_COMPASS_LAYOUT_CYBOL_MODEL = CENTRE_COMPASS_LAYOUT_CYBOL_MODEL_ARRAY;
static int* CENTRE_COMPASS_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPASS_LAYOUT_CYBOL_MODEL_SOURCE */
#endif
