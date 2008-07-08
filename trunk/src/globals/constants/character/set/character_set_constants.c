/*
 * $RCSfile: character_set_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2008-07-08 06:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_SET_CONSTANTS_SOURCE
#define CHARACTER_SET_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains character set constants.
//

/**
 * The ascii character set.
 *
 * American Standard Code for Information Interchange (ASCII).
 */
static wchar_t ASCII_CHARACTER_SET_ARRAY[] = {L'a', L's', L'c', L'i', L'i'};
static wchar_t* ASCII_CHARACTER_SET = ASCII_CHARACTER_SET_ARRAY;
static int* ASCII_CHARACTER_SET_COUNT = NUMBER_5_INTEGER_ARRAY;

/*
 * The ebcdic character set.
 *
 * Extended Binary Coded Decimal Interchange Code (EBCDIC).
 */
static wchar_t EBCDIC_CHARACTER_SET_ARRAY[] = {L'e', L'b', L'c', L'd', L'i', L'c'};
static wchar_t* EBCDIC_CHARACTER_SET = EBCDIC_CHARACTER_SET_ARRAY;
static int* EBCDIC_CHARACTER_SET_COUNT = NUMBER_6_INTEGER_ARRAY;

/*
 * The gb character set.
 *
 * Guobiao code (GB): Simplified Chinese (Mainland China, South East).
 */
static wchar_t GB_CHARACTER_SET_ARRAY[] = {L'g', L'b'};
static wchar_t* GB_CHARACTER_SET = GB_CHARACTER_SET_ARRAY;
static int* GB_CHARACTER_SET_COUNT = NUMBER_2_INTEGER_ARRAY;

/*
 * The big-5 character set.
 *
 * Big-5 or Big5: Traditional Chinese (Taiwan, Hong Kong, Macau).
 */
static wchar_t BIG_5_CHARACTER_SET_ARRAY[] = {L'b', L'i', L'g', L'-', L'5'};
static wchar_t* BIG_5_CHARACTER_SET = BIG_5_CHARACTER_SET_ARRAY;
static int* BIG_5_CHARACTER_SET_COUNT = NUMBER_5_INTEGER_ARRAY;

/*
 * The shift-jis character set.
 *
 * Shift JIS for Japanese (Microsoft Code page 932).
 */
static wchar_t SHIFT_JIS_CHARACTER_SET_ARRAY[] = {L's', L'h', L'i', L'f', L't', L'-', L'j', L'i', L's'};
static wchar_t* SHIFT_JIS_CHARACTER_SET = SHIFT_JIS_CHARACTER_SET_ARRAY;
static int* SHIFT_JIS_CHARACTER_SET_COUNT = NUMBER_9_INTEGER_ARRAY;

/*
 * The unicode universal character set.
 *
 * Universal Character Set (UCS).
 *
 * Plane 0 (0000–FFFF): Basic Multilingual Plane (BMP)
 * Plane 1 (10000–1FFFF): Supplementary Multilingual Plane (SMP)
 * Plane 2 (20000–2FFFF): Supplementary Ideographic Plane (SIP)
 * Planes 3 to 13 (30000–DFFFF) not assigned
 * Plane 14 (E0000–EFFFF): Supplementary Special-purpose Plane (SSP)
 * Plane 15 (F0000–FFFFF) and Plane 16 (100000–10FFFF): Private Use Area (PUA)
 */
static wchar_t UNIVERSAL_CHARACTER_SET_ARRAY[] = {L'u', L'n', L'i', L'v', L'e', L'r', L's', L'a', L'l'};
static wchar_t* UNIVERSAL_CHARACTER_SET = UNIVERSAL_CHARACTER_SET_ARRAY;
static int* UNIVERSAL_CHARACTER_SET_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The html coded character set. */
/*??
static wchar_t HTML_CODED_CHARACTER_SET_ARRAY[] = {L'h', L't', L'm', L'l', L' ', L'c', L'o', L'd', L'e', L'd'};
static wchar_t* HTML_CODED_CHARACTER_SET = HTML_CODED_CHARACTER_SET_ARRAY;
static int* HTML_CODED_CHARACTER_SET_COUNT = NUMBER_10_INTEGER_ARRAY;
*/

/* CHARACTER_SET_CONSTANTS_SOURCE */
#endif
