/*
 * Copyright (C) 1999-2011. Christian Heller.
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
static char CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'C', 'a', 'c', 'h', 'e', '-', 'C', 'o', 'n', 't', 'r', 'o', 'l'};
static char* CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME = CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* CACHE_CONTROL_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The Connection general header http name. */
static char CONNECTION_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'C', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n'};
static char* CONNECTION_GENERAL_HEADER_HTTP_NAME = CONNECTION_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* CONNECTION_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The Date general header http name. */
static char DATE_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'D', 'a', 't', 'e'};
static char* DATE_GENERAL_HEADER_HTTP_NAME = DATE_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* DATE_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The Pragma general header http name. */
static char PRAGMA_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'P', 'r', 'a', 'g', 'm', 'a'};
static char* PRAGMA_GENERAL_HEADER_HTTP_NAME = PRAGMA_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* PRAGMA_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The Trailer general header http name. */
static char TRAILER_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'T', 'r', 'a', 'i', 'l', 'e', 'r'};
static char* TRAILER_GENERAL_HEADER_HTTP_NAME = TRAILER_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* TRAILER_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The Transfer-Encoding general header http name. */
static char TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'T', 'r', 'a', 'n', 's', 'f', 'e', 'r', '-', 'E', 'n', 'c', 'o', 'd', 'i', 'n', 'g'};
static char* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME = TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The Upgrade general header http name. */
static char UPGRADE_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'U', 'p', 'g', 'r', 'a', 'd', 'e'};
static char* UPGRADE_GENERAL_HEADER_HTTP_NAME = UPGRADE_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* UPGRADE_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The Via general header http name. */
static char VIA_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'V', 'i', 'a'};
static char* VIA_GENERAL_HEADER_HTTP_NAME = VIA_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* VIA_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The Warning general header http name. */
static char WARNING_GENERAL_HEADER_HTTP_NAME_ARRAY[] = {'W', 'a', 'r', 'n', 'i', 'n', 'g'};
static char* WARNING_GENERAL_HEADER_HTTP_NAME = WARNING_GENERAL_HEADER_HTTP_NAME_ARRAY;
static int* WARNING_GENERAL_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* GENERAL_HEADER_HTTP_NAME_SOURCE */
#endif
