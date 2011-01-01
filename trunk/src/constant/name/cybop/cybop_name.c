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
 * @version $RCSfile: cybop_name.c,v $ $Revision: 1.5 $ $Date: 2009-02-10 01:01:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOP_NAME_SOURCE
#define CYBOP_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The name cybop name. */
static wchar_t NAME_CYBOP_NAME_ARRAY[] = {L'n', L'a', L'm', L'e'};
static wchar_t* NAME_CYBOP_NAME = NAME_CYBOP_NAME_ARRAY;
static int* NAME_CYBOP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The channel cybop name. */
static wchar_t CHANNEL_CYBOP_NAME_ARRAY[] = {L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_CYBOP_NAME = CHANNEL_CYBOP_NAME_ARRAY;
static int* CHANNEL_CYBOP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The abstraction cybop name. */
static wchar_t ABSTRACTION_CYBOP_NAME_ARRAY[] = {L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* ABSTRACTION_CYBOP_NAME = ABSTRACTION_CYBOP_NAME_ARRAY;
static int* ABSTRACTION_CYBOP_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The model cybop name. */
static wchar_t MODEL_CYBOP_NAME_ARRAY[] = {L'm', L'o', L'd', L'e', L'l'};
static wchar_t* MODEL_CYBOP_NAME = MODEL_CYBOP_NAME_ARRAY;
static int* MODEL_CYBOP_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOP_NAME_SOURCE */
#endif
