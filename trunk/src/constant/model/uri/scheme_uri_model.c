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
 * @version $RCSfile: escape_code_uri_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SCHEME_URI_MODEL_SOURCE
#define SCHEME_URI_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The ftp scheme uri model. */
static wchar_t FTP_SCHEME_URI_MODEL_ARRAY[] = {L'f', L't', L'p'};
static wchar_t* FTP_SCHEME_URI_MODEL = FTP_SCHEME_URI_MODEL_ARRAY;
static int* FTP_SCHEME_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The http scheme uri model. */
static wchar_t HTTP_SCHEME_URI_MODEL_ARRAY[] = {L'h', L't', L't', L'p'};
static wchar_t* HTTP_SCHEME_URI_MODEL = HTTP_SCHEME_URI_MODEL_ARRAY;
static int* HTTP_SCHEME_URI_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The ldap scheme uri model. */
static wchar_t LDAP_SCHEME_URI_MODEL_ARRAY[] = {L'l', L'd', L'a', L'p'};
static wchar_t* LDAP_SCHEME_URI_MODEL = LDAP_SCHEME_URI_MODEL_ARRAY;
static int* LDAP_SCHEME_URI_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The mailto scheme uri model. */
static wchar_t MAILTO_SCHEME_URI_MODEL_ARRAY[] = {L'm', L'a', L'i', L'l', L't', L'o'};
static wchar_t* MAILTO_SCHEME_URI_MODEL = MAILTO_SCHEME_URI_MODEL_ARRAY;
static int* MAILTO_SCHEME_URI_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The news scheme uri model. */
static wchar_t NEWS_SCHEME_URI_MODEL_ARRAY[] = {L'n', L'e', L'w', L's'};
static wchar_t* NEWS_SCHEME_URI_MODEL = NEWS_SCHEME_URI_MODEL_ARRAY;
static int* NEWS_SCHEME_URI_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The tel scheme uri model. */
static wchar_t TEL_SCHEME_URI_MODEL_ARRAY[] = {L't', L'e', L'l'};
static wchar_t* TEL_SCHEME_URI_MODEL = TEL_SCHEME_URI_MODEL_ARRAY;
static int* TEL_SCHEME_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The telnet scheme uri model. */
static wchar_t TELNET_SCHEME_URI_MODEL_ARRAY[] = {L't', L'e', L'l', L'n', L'e', L't'};
static wchar_t* TELNET_SCHEME_URI_MODEL = TELNET_SCHEME_URI_MODEL_ARRAY;
static int* TELNET_SCHEME_URI_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The urn scheme uri model. */
static wchar_t URN_SCHEME_URI_MODEL_ARRAY[] = {L'u', L'r', L'n'};
static wchar_t* URN_SCHEME_URI_MODEL = URN_SCHEME_URI_MODEL_ARRAY;
static int* URN_SCHEME_URI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* SCHEME_URI_MODEL_SOURCE */
#endif
