/*
 * $RCSfile: uri_separator_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2008-05-27 22:52:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URI_SEPARATOR_CONSTANTS_SOURCE
#define URI_SEPARATOR_CONSTANTS_SOURCE

#include "../../../globals/constants/character/character_constants.c"
#include "../../../globals/constants/integer/integer_constants.c"

//
// The following constants were defined in accordance with:
//
// Uniform Resource Identifier (URI): Generic Syntax
// http://tools.ietf.org/html/rfc3986
//

//
// Main parts.
//

/** The uri scheme separator ("colon"). */
static wchar_t* URI_SCHEME_SEPARATOR = COLON_WIDE_CHARACTER_ARRAY;
static int* URI_SCHEME_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri authority separator (twice "solidus"). */
static wchar_t URI_AUTHORITY_SEPARATOR_ARRAY[] = {0x002F, 0x002F};
static wchar_t* URI_AUTHORITY_SEPARATOR = URI_AUTHORITY_SEPARATOR_ARRAY;
static int* URI_AUTHORITY_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The uri path separator ("solidus"). */
static wchar_t* URI_PATH_SEPARATOR = SOLIDUS_WIDE_CHARACTER_ARRAY;
static int* URI_PATH_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri query separator ("question mark"). */
static wchar_t* URI_QUERY_SEPARATOR = QUESTION_MARK_WIDE_CHARACTER_ARRAY;
static int* URI_QUERY_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri fragment separator ("number sign"). */
static wchar_t* URI_FRAGMENT_SEPARATOR = NUMBER_SIGN_WIDE_CHARACTER_ARRAY;
static int* URI_FRAGMENT_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Path parts.
//

/**
 * The uri parameter separator ("ampersand").
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static wchar_t* URI_PARAMETER_SEPARATOR = AMPERSAND_WIDE_CHARACTER_ARRAY;
static int* URI_PARAMETER_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The uri parameter alternative separator ("semicolon").
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static wchar_t* URI_PARAMETER_ALTERNATIVE_SEPARATOR = SEMICOLON_WIDE_CHARACTER_ARRAY;
static int* URI_PARAMETER_ALTERNATIVE_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The uri value separator ("equals").
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static wchar_t* URI_VALUE_SEPARATOR = EQUALS_SIGN_WIDE_CHARACTER_ARRAY;
static int* URI_VALUE_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Authority parts.
//

/** The uri host separator ("commercial at"). */
static wchar_t* URI_HOST_SEPARATOR = COMMERCIAL_AT_WIDE_CHARACTER_ARRAY;
static int* URI_HOST_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri port separator ("colon"). */
static wchar_t* URI_PORT_SEPARATOR = COLON_WIDE_CHARACTER_ARRAY;
static int* URI_PORT_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/* URI_SEPARATOR_CONSTANTS_SOURCE */
#endif
