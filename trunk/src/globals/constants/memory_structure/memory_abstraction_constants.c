/*
 * $RCSfile: memory_abstraction_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.5 $ $Date: 2008-06-07 11:09:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_ABSTRACTION_CONSTANTS_SOURCE
#define MEMORY_ABSTRACTION_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Internal memory abstraction.
//

/** The internal memory abstraction. */
static wchar_t INTERNAL_MEMORY_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'n', L'a', L'l', L'_', L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* INTERNAL_MEMORY_ABSTRACTION = INTERNAL_MEMORY_ABSTRACTION_ARRAY;
static int* INTERNAL_MEMORY_ABSTRACTION_COUNT = NUMBER_16_INTEGER_ARRAY;

//
// Compound abstraction.
//
// Compound models consist of other compound or primitive models.
//
// CAUTION! This is also used as knowledge memory abstraction!
//

/** The compound abstraction. */
static wchar_t COMPOUND_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd'};
static wchar_t* COMPOUND_ABSTRACTION = COMPOUND_ABSTRACTION_ARRAY;
static int* COMPOUND_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// CAUTION! This redundant constant is necessary, because the module "initialiser.c"
// needs to hand over a multibyte character string as argument, which later gets decoded
// into a wide character string.
// An extra "COMPOUND_ABSTRACTION_ASCII_COUNT" constant is NOT introduced here,
// but the "COMPOUND_ABSTRACTION_COUNT" from above used instead.
//

/** The compound abstraction as ascii character string. */
static char COMPOUND_ABSTRACTION_ASCII_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};
static char* COMPOUND_ABSTRACTION_ASCII = COMPOUND_ABSTRACTION_ASCII_ARRAY;

//
// Signal memory abstraction.
//

/** The signal memory abstraction. */
static wchar_t SIGNAL_MEMORY_ABSTRACTION_ARRAY[] = {L's', L'i', L'g', L'n', L'a', L'l', L'_', L'm', L'e', L'm', L'o', L'r', L'y'};
static wchar_t* SIGNAL_MEMORY_ABSTRACTION = SIGNAL_MEMORY_ABSTRACTION_ARRAY;
static int* SIGNAL_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/* MEMORY_ABSTRACTION_CONSTANTS_SOURCE */
#endif
