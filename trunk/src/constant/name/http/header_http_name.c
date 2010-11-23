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

#ifndef HEADER_HTTP_NAME_SOURCE
#define HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// The following does not seem to be part of the HTTP 1.1 RFC 2616 specification.
//

/** The Set-Cookie header http name. */
static wchar_t SET_COOKIE_HEADER_HTTP_NAME_ARRAY[] = {L'S', L'e', L't', L'-', L'C', L'o', L'o', L'k', L'i', L'e'};
static wchar_t* SET_COOKIE_HEADER_HTTP_NAME = SET_COOKIE_HEADER_HTTP_NAME_ARRAY;
static int* SET_COOKIE_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/* HEADER_HTTP_NAME_SOURCE */
#endif
