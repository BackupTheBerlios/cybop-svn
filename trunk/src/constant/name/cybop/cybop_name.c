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
 * @version $RCSfile: cybop_name.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
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

//
// Cybol tag attributes as char.
//
// They are needed by the "compound_converter.c" module and
// may (possibly) be deleted later, if a self-written XML parser is used.
//
// The count of the standard (wchar_t) tag attributes (see above) is used here.
//

/** The name cybop name as char. */
static char NAME_CYBOP_NAME_AS_CHAR_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* NAME_CYBOP_NAME_AS_CHAR = NAME_CYBOP_NAME_AS_CHAR_ARRAY;

/** The channel cybop name as char. */
static char CHANNEL_CYBOP_NAME_AS_CHAR_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* CHANNEL_CYBOP_NAME_AS_CHAR = CHANNEL_CYBOP_NAME_AS_CHAR_ARRAY;

/** The abstraction cybop name as char. */
static char ABSTRACTION_CYBOP_NAME_AS_CHAR_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* ABSTRACTION_CYBOP_NAME_AS_CHAR = ABSTRACTION_CYBOP_NAME_AS_CHAR_ARRAY;

/** The model cybop name as char. */
static char MODEL_CYBOP_NAME_AS_CHAR_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* MODEL_CYBOP_NAME_AS_CHAR = MODEL_CYBOP_NAME_AS_CHAR_ARRAY;

/* CYBOP_NAME_SOURCE */
#endif
