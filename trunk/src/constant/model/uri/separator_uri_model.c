/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: separator_uri_model.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEPARATOR_URI_MODEL_SOURCE
#define SEPARATOR_URI_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"

//
// The following constants were defined in accordance with:
//
// Uniform Resource Identifier (URI): Generic Syntax
// http://tools.ietf.org/html/rfc3986
//

//
// Main parts.
//

/** The scheme separator ("colon") uri model. */
static wchar_t* SCHEME_SEPARATOR_URI_MODEL = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SCHEME_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The authority separator (twice "solidus") uri model. */
static wchar_t AUTHORITY_SEPARATOR_URI_MODEL_ARRAY[] = {0x002F, 0x002F};
static wchar_t* AUTHORITY_SEPARATOR_URI_MODEL = AUTHORITY_SEPARATOR_URI_MODEL_ARRAY;
static int* AUTHORITY_SEPARATOR_URI_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The path separator ("solidus") uri model. */
static wchar_t* PATH_SEPARATOR_URI_MODEL = SOLIDUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PATH_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The query separator ("question mark") uri model. */
static wchar_t* QUERY_SEPARATOR_URI_MODEL = QUESTION_MARK_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* QUERY_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The fragment separator ("number sign") uri model. */
static wchar_t* FRAGMENT_SEPARATOR_URI_MODEL = NUMBER_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* FRAGMENT_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Path parts.
//

/**
 * The parameter separator ("ampersand") uri model.
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static wchar_t* PARAMETER_SEPARATOR_URI_MODEL = AMPERSAND_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PARAMETER_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The parameter alternative separator ("semicolon") uri model.
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static wchar_t* PARAMETER_ALTERNATIVE_SEPARATOR_URI_MODEL = SEMICOLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PARAMETER_ALTERNATIVE_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The value separator ("equals") uri model.
 *
 * CAUTION! This separator is NOT defined by IETF's uri specification rfc3986,
 * but commonly used in the internet.
 */
static wchar_t* VALUE_SEPARATOR_URI_MODEL = EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* VALUE_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

//
// Authority parts.
//

/** The host separator ("commercial at") uri model. */
static wchar_t* HOST_SEPARATOR_URI_MODEL = COMMERCIAL_AT_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* HOST_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The port separator ("colon") uri model. */
static wchar_t* PORT_SEPARATOR_URI_MODEL = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PORT_SEPARATOR_URI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/* SEPARATOR_URI_MODEL_SOURCE */
#endif
