/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: escape_code_uri_model.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ESCAPE_CODE_URI_MODEL_SOURCE
#define ESCAPE_CODE_URI_MODEL_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The space   url escape code uri model. */
static wchar_t SPACE_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'2', L'0'};
static wchar_t* SPACE_ESCAPE_CODE_URI_MODEL = SPACE_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* SPACE_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The number sign # url escape code uri model. */
static wchar_t NUMBER_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'2', L'3'};
static wchar_t* NUMBER_SIGN_ESCAPE_CODE_URI_MODEL = NUMBER_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* NUMBER_SIGN_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The dollar sign $ url escape code uri model. */
static wchar_t DOLLAR_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'2', L'4'};
static wchar_t* DOLLAR_SIGN_ESCAPE_CODE_URI_MODEL = DOLLAR_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* DOLLAR_SIGN_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The percent sign % url escape code uri model. */
static wchar_t PERCENT_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'2', L'5'};
static wchar_t* PERCENT_SIGN_ESCAPE_CODE_URI_MODEL = PERCENT_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* PERCENT_SIGN_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The ampersand & url escape code uri model. */
static wchar_t AMPERSAND_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'2', L'6'};
static wchar_t* AMPERSAND_ESCAPE_CODE_URI_MODEL = AMPERSAND_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* AMPERSAND_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The solidus (slash) / url escape code uri model. */
static wchar_t SOLIDUS_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'2', L'F'};
static wchar_t* SOLIDUS_ESCAPE_CODE_URI_MODEL = SOLIDUS_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* SOLIDUS_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The colon : url escape code uri model. */
static wchar_t COLON_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'3', L'A'};
static wchar_t* COLON_ESCAPE_CODE_URI_MODEL = COLON_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* COLON_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The semicolon ; url escape code uri model. */
static wchar_t SEMICOLON_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'3', L'B'};
static wchar_t* SEMICOLON_ESCAPE_CODE_URI_MODEL = SEMICOLON_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* SEMICOLON_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The less than sign < url escape code uri model. */
static wchar_t LESS_THAN_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'3', L'C'};
static wchar_t* LESS_THAN_SIGN_ESCAPE_CODE_URI_MODEL = LESS_THAN_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* LESS_THAN_SIGN_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The equals sign = url escape code uri model. */
static wchar_t EQUALS_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'3', L'D'};
static wchar_t* EQUALS_SIGN_ESCAPE_CODE_URI_MODEL = EQUALS_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* EQUALS_SIGN_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater than sign > url escape code uri model. */
static wchar_t GREATER_THAN_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'3', L'E'};
static wchar_t* GREATER_THAN_SIGN_ESCAPE_CODE_URI_MODEL = GREATER_THAN_SIGN_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* GREATER_THAN_SIGN_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The question mark ? url escape code uri model. */
static wchar_t QUESTION_MARK_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'3', L'F'};
static wchar_t* QUESTION_MARK_ESCAPE_CODE_URI_MODEL = QUESTION_MARK_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* QUESTION_MARK_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The commercial at @ url escape code uri model. */
static wchar_t COMMERCIAL_AT_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'4', L'0'};
static wchar_t* COMMERCIAL_AT_ESCAPE_CODE_URI_MODEL = COMMERCIAL_AT_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* COMMERCIAL_AT_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The left square bracket [ url escape code uri model. */
static wchar_t LEFT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'5', L'B'};
static wchar_t* LEFT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL = LEFT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* LEFT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The reverse solidus (backslash) \ url escape code uri model. */
static wchar_t REVERSE_SOLIDUS_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'5', L'C'};
static wchar_t* REVERSE_SOLIDUS_ESCAPE_CODE_URI_MODEL = REVERSE_SOLIDUS_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* REVERSE_SOLIDUS_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The right square bracket ] url escape code uri model. */
static wchar_t RIGHT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'5', L'D'};
static wchar_t* RIGHT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL = RIGHT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* RIGHT_SQUARE_BRACKET_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The caret ^ (circumflex accent) url escape code uri model. */
static wchar_t CARET_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'5', L'E'};
static wchar_t* CARET_ESCAPE_CODE_URI_MODEL = CARET_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* CARET_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The grave accent ` url escape code uri model. */
static wchar_t GRAVE_ACCENT_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'6', L'0'};
static wchar_t* GRAVE_ACCENT_ESCAPE_CODE_URI_MODEL = GRAVE_ACCENT_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* GRAVE_ACCENT_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The left curly brace { url escape code uri model. */
static wchar_t LEFT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'7', L'B'};
static wchar_t* LEFT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL = LEFT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* LEFT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The vertical bar | url escape code uri model. */
static wchar_t VERTICAL_BAR_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'7', L'C'};
static wchar_t* VERTICAL_BAR_ESCAPE_CODE_URI_MODEL = VERTICAL_BAR_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* VERTICAL_BAR_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The right curly brace } url escape code uri model. */
static wchar_t RIGHT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'7', L'D'};
static wchar_t* RIGHT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL = RIGHT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* RIGHT_CURLY_BRACE_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The tilde ~ url escape code uri model. */
static wchar_t TILDE_ESCAPE_CODE_URI_MODEL_ARRAY[] = {L'%', L'7', L'E'};
static wchar_t* TILDE_ESCAPE_CODE_URI_MODEL = TILDE_ESCAPE_CODE_URI_MODEL_ARRAY;
static int* TILDE_ESCAPE_CODE_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* ESCAPE_CODE_URI_MODEL_SOURCE */
#endif
