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
 * @version $RCSfile: general_header_http_name.c,v $ $Revision: 1.1 $ $Date: 2009-07-21 15:39:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GENERAL_HEADER_HTTP_NAME_SOURCE
#define GENERAL_HEADER_HTTP_NAME_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

//
// The following constants are taken from the HTTP 1.1 RFC 2616 specification:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14
// They are sorted alphabetically here.
//

/** The Cache-Control general header http name. */
static wchar_t CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'a', L'c', L'h', L'e', L'-', L'C', L'o', L'n', L't', L'r', L'o', L'l'};
static wchar_t* CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME = CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The Connection general header http name. */
static wchar_t CONNECTION_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'C', L'o', L'n', L'n', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* CONNECTION_GENERAL_HEADER_HTTP_NAME = CONNECTION_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The Date general header http name. */
static wchar_t DATE_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'D', L'a', L't', L'e'};
static wchar_t* DATE_GENERAL_HEADER_HTTP_NAME = DATE_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* DATE_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The Pragma general header http name. */
static wchar_t PRAGMA_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'P', L'r', L'a', L'g', L'm', L'a'};
static wchar_t* PRAGMA_GENERAL_HEADER_HTTP_NAME = PRAGMA_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The Trailer general header http name. */
static wchar_t TRAILER_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'T', L'r', L'a', L'i', L'l', L'e', L'r'};
static wchar_t* TRAILER_GENERAL_HEADER_HTTP_NAME = TRAILER_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The Transfer-Encoding general header http name. */
static wchar_t TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'T', L'r', L'a', L'n', L's', L'f', L'e', L'r', L'-', L'E', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME = TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The Upgrade general header http name. */
static wchar_t UPGRADE_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'U', L'p', L'g', L'r', L'a', L'd', L'e'};
static wchar_t* UPGRADE_GENERAL_HEADER_HTTP_NAME = UPGRADE_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The Via general header http name. */
static wchar_t VIA_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'V', L'i', L'a'};
static wchar_t* VIA_GENERAL_HEADER_HTTP_NAME = VIA_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* VIA_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The Warning general header http name. */
static wchar_t WARNING_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {L'W', L'a', L'r', L'n', L'i', L'n', L'g'};
static wchar_t* WARNING_GENERAL_HEADER_HTTP_NAME = WARNING_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* WARNING_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* GENERAL_HEADER_HTTP_NAME_SOURCE */
#endif
