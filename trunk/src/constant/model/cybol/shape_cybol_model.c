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
 * @version $RCSfile: shape_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHAPE_CYBOL_MODEL_SOURCE
#define SHAPE_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The rectangle shape cybol model. */
static wchar_t RECTANGLE_SHAPE_CYBOL_MODEL_ARRAY[] = {L'r', L'e', L'c', L't', L'a', L'n', L'g', L'l', L'e'};
static wchar_t* RECTANGLE_SHAPE_CYBOL_MODEL = RECTANGLE_SHAPE_CYBOL_MODEL_ARRAY;
static int* RECTANGLE_SHAPE_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The circle shape cybol model. */
static wchar_t CIRCLE_SHAPE_CYBOL_MODEL_ARRAY[] = {L'c', L'i', L'r', L'c', L'l', L'e'};
static wchar_t* CIRCLE_SHAPE_CYBOL_MODEL = CIRCLE_SHAPE_CYBOL_MODEL_ARRAY;
static int* CIRCLE_SHAPE_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The polygon shape cybol model. */
static wchar_t POLYGON_SHAPE_CYBOL_MODEL_ARRAY[] = {L'p', L'o', L'l', L'y', L'g', L'o', L'n'};
static wchar_t* POLYGON_SHAPE_CYBOL_MODEL = POLYGON_SHAPE_CYBOL_MODEL_ARRAY;
static int* POLYGON_SHAPE_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* SHAPE_CYBOL_MODEL_SOURCE */
#endif
