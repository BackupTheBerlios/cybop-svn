/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: header_http_name.c,v $ $Revision: 1.5 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_AUTHORITY_NAME_SOURCE
#define CYBOI_AUTHORITY_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// The constants defined here are copies of the standard constants
// that may be found in files of this same directory.
//
// The difference is that these constants are of type "wchar_t"
// and are prefixed with "CYBOI_".
//
// This duplication of constants is necessary, because names or models
// of standard formats like HTTP or xDT are not always intuitive,
// so that CYBOI uses its own speaking names internally.
//
// Examples:
// - HTTP header names start with a capital letter, but CYBOI uses lower-case names only
// - URI parts do not have a name at all, so that CYBOI has to invent some
// - xDT fields are represented by numbers, but CYBOI uses speaking names (text) only
//

/** The cyboi username authority name. */
static wchar_t CYBOI_USERNAME_AUTHORITY_NAME_ARRAY[] = {L'u', L's', L'e', L'r', L'n', L'a', L'm', L'e'};
static wchar_t* CYBOI_USERNAME_AUTHORITY_NAME = CYBOI_USERNAME_AUTHORITY_NAME_ARRAY;
static int* CYBOI_USERNAME_AUTHORITY_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi password authority name. */
static wchar_t CYBOI_PASSWORD_AUTHORITY_NAME_ARRAY[] = {L'p', L'a', L's', L's', L'w', L'o', L'r', L'd'};
static wchar_t* CYBOI_PASSWORD_AUTHORITY_NAME = CYBOI_PASSWORD_AUTHORITY_NAME_ARRAY;
static int* CYBOI_PASSWORD_AUTHORITY_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi hostname authority name. */
static wchar_t CYBOI_HOSTNAME_AUTHORITY_NAME_ARRAY[] = {L'h', L'o', L's', L't', L'n', L'a', L'm', L'e'};
static wchar_t* CYBOI_HOSTNAME_AUTHORITY_NAME = CYBOI_HOSTNAME_AUTHORITY_NAME_ARRAY;
static int* CYBOI_HOSTNAME_AUTHORITY_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The cyboi port authority name. */
static wchar_t CYBOI_PORT_AUTHORITY_NAME_ARRAY[] = {L'p', L'o', L'r', L't'};
static wchar_t* CYBOI_PORT_AUTHORITY_NAME = CYBOI_PORT_AUTHORITY_NAME_ARRAY;
static int* CYBOI_PORT_AUTHORITY_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_AUTHORITY_NAME_SOURCE */
#endif
