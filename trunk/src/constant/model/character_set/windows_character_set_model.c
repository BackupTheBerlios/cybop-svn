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
 * @version $RCSfile: windows_character_set_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOWS_CHARACTER_SET_MODEL_SOURCE
#define WINDOWS_CHARACTER_SET_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains windows character set constants.
//

/*
 * The windows-1250 character set model.
 *
 * Windows-1250 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1250_CHARACTER_SET_MODEL_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'0'};
static wchar_t* WINDOWS_1250_CHARACTER_SET_MODEL = WINDOWS_1250_CHARACTER_SET_MODEL_ARRAY;
static int* WINDOWS_1250_CHARACTER_SET_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/* WINDOWS_CHARACTER_SET_MODEL_SOURCE */
#endif
