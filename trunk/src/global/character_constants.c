/*
 * $RCSfile: character_constants.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file defines global character constants.
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * @version $Revision: 1.3 $ $Date: 2004-12-16 09:52:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_CONSTANTS_SOURCE
#define CHARACTER_CONSTANTS_SOURCE

//
// ASCII characters (0 - 127).
//

//?? See KDE menu: | Applications | Debian | Text | Unicode character map
//?? Add below also the following constants:
//?? - UTF-8
//?? - Octal escaped UTF-8
//?? - Decimal entity reference

/** The colon character. ASCII: ?? */
static const char COLON_CHARACTER_ARRAY[] = {':'};
static const char* COLON_CHARACTER = COLON_CHARACTER_ARRAY;
static const int COLON_CHARACTER_COUNT_ARRAY[] = {1};
static const int* COLON_CHARACTER_COUNT = COLON_CHARACTER_COUNT_ARRAY;

/** The space character. ASCII: ?? */
static const char SPACE_CHARACTER_ARRAY[] = {' '};
static const char* SPACE_CHARACTER = SPACE_CHARACTER_ARRAY;
static const int SPACE_CHARACTER_COUNT_ARRAY[] = {1};
static const int* SPACE_CHARACTER_COUNT = SPACE_CHARACTER_COUNT_ARRAY;

/** The new line character. ASCII: ?? */
static const char NEW_LINE_CHARACTER_ARRAY[] = {'\n'};
static const char* NEW_LINE_CHARACTER = NEW_LINE_CHARACTER_ARRAY;
static const int NEW_LINE_CHARACTER_COUNT_ARRAY[] = {1};
static const int* NEW_LINE_CHARACTER_COUNT = NEW_LINE_CHARACTER_COUNT_ARRAY;

/** The low line character. ASCII: 95 */
static const char LOW_LINE_CHARACTER_ARRAY[] = {'_'};
static const char* LOW_LINE_CHARACTER = LOW_LINE_CHARACTER_ARRAY;
static const int LOW_LINE_CHARACTER_COUNT_ARRAY[] = {1};
static const int* LOW_LINE_CHARACTER_COUNT = LOW_LINE_CHARACTER_COUNT_ARRAY;

//
// ANSI characters (128 - 255).
//

//
// UNICODE characters (256 - ??).
//

//
// Special characters.
//

/** The null character, used as string termination in the c programming language. */
static const char NULL_CHARACTER_ARRAY[] = {'\0'};
static const char* NULL_CHARACTER = NULL_CHARACTER_ARRAY;
static const int NULL_CHARACTER_COUNT_ARRAY[] = {1};
static const int* NULL_CHARACTER_COUNT = NULL_CHARACTER_COUNT_ARRAY;

/* CHARACTER_CONSTANTS_SOURCE */
#endif
