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
 * @version $Revision: 1.1 $ $Date: 2004-12-06 14:34:54 $ $Author: reichenbach $
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
static const char COLON_CHARACTER = ':';

/** The space character. ASCII: ?? */
static const char SPACE_CHARACTER = ' ';

/** The new line character. ASCII: ?? */
static const char NEW_LINE_CHARACTER = '\n';

/** The low line character. ASCII: 95 */
static const char LOW_LINE_CHARACTER = '_';

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
static const char NULL_CHARACTER = '\0';

/* CHARACTER_CONSTANTS_SOURCE */
#endif
