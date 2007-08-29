/*
 * $RCSfile: uri_separator_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-29 23:11:23 $ $Author: christian $
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
static char* URI_SCHEME_SEPARATOR = COLON_CHARACTER_ARRAY;
static int* URI_SCHEME_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri authority separator (twice "solidus"). */
static char URI_AUTHORITY_SEPARATOR_ARRAY[] = {0x2F, 0x2F};
static char* URI_AUTHORITY_SEPARATOR = URI_AUTHORITY_SEPARATOR_ARRAY;
static int* URI_AUTHORITY_SEPARATOR_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The uri path separator ("solidus"). */
static char* URI_PATH_SEPARATOR = SOLIDUS_CHARACTER_ARRAY;
static int* URI_PATH_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri query separator ("question mark"). */
static char* URI_QUERY_SEPARATOR = QUESTION_MARK_CHARACTER_ARRAY;
static int* URI_QUERY_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri fragment separator ("number sign"). */
static char* URI_FRAGMENT_SEPARATOR = NUMBER_SIGN_CHARACTER_ARRAY;
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
static char* URI_PARAMETER_SEPARATOR = AMPERSAND_CHARACTER_ARRAY;
static int* URI_PARAMETER_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The uri parameter alternative separator ("semicolon").
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static char* URI_PARAMETER_ALTERNATIVE_SEPARATOR = SEMICOLON_CHARACTER_ARRAY;
static int* URI_PARAMETER_ALTERNATIVE_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/**
 * The uri value separator ("equals").
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static char* URI_VALUE_SEPARATOR = EQUALS_SIGN_CHARACTER_ARRAY;
static int* URI_VALUE_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

//
// Authority parts.
//

/** The uri host separator ("commercial at"). */
static char* URI_HOST_SEPARATOR = COMMERCIAL_AT_CHARACTER_ARRAY;
static int* URI_HOST_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/** The uri port separator ("colon"). */
static char* URI_PORT_SEPARATOR = COLON_CHARACTER_ARRAY;
static int* URI_PORT_SEPARATOR_COUNT = NUMBER_1_INTEGER_ARRAY;

/* URI_SEPARATOR_CONSTANTS_SOURCE */
#endif
