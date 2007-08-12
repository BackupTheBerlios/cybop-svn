/*
 * $RCSfile: character_set_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2007-08-12 23:31:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_SET_CONSTANTS_SOURCE
#define CHARACTER_SET_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The iso-8859-1 character set. */
static char ISO_8859_1_CHARACTER_SET_ARRAY[] = {'i', 's', 'o', '-', '8', '8', '5', '9', '-', '1'};
static char* ISO_8859_1_CHARACTER_SET = ISO_8859_1_CHARACTER_SET_ARRAY;
static int* ISO_8859_1_CHARACTER_SET_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The utf-8 character set. */
static char UTF_8_CHARACTER_SET_ARRAY[] = {'u', 't', 'f', '-', '8'};
static char* UTF_8_CHARACTER_SET = UTF_8_CHARACTER_SET_ARRAY;
static int* UTF_8_CHARACTER_SET_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The html coded character set. */
static char HTML_CODED_CHARACTER_SET_ARRAY[] = {'h', 't', 'm', 'l', ' ', 'c', 'o', 'd', 'e', 'd'};
static char* HTML_CODED_CHARACTER_SET = HTML_CODED_CHARACTER_SET_ARRAY;
static int* HTML_CODED_CHARACTER_SET_COUNT = NUMBER_10_INTEGER_ARRAY;

/* CHARACTER_SET_CONSTANTS_SOURCE */
#endif
