/*
 * $RCSfile: dos_character_set_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2008-07-08 17:55:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOS_CHARACTER_SET_CONSTANTS_SOURCE
#define DOS_CHARACTER_SET_CONSTANTS_SOURCE

#include "../../../../globals/constants/integer/integer_constants.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains dos character set constants.
//

/*
 * The dos-850 character set.
 *
 * Disk Operating System (DOS) Code page 850.
 */
static wchar_t DOS_850_CHARACTER_SET_ARRAY[] = {L'd', L'o', L's', L'-', L'8', L'5', L'0'};
static wchar_t* DOS_850_CHARACTER_SET = DOS_850_CHARACTER_SET_ARRAY;
static int* DOS_850_CHARACTER_SET_COUNT = NUMBER_7_INTEGER_ARRAY;

/* DOS_CHARACTER_SET_CONSTANTS_SOURCE */
#endif
