/*
 * $RCSfile: http_header_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_HEADER_CONSTANTS_SOURCE
#define HTTP_HEADER_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The content type http header. */
static wchar_t CONTENT_TYPE_HTTP_HEADER_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L't', L'y', L'p', L'e'};
static wchar_t* CONTENT_TYPE_HTTP_HEADER = CONTENT_TYPE_HTTP_HEADER_ARRAY;
static int* CONTENT_TYPE_HTTP_HEADER_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The content language http header. */
static wchar_t CONTENT_LANGUAGE_HTTP_HEADER_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CONTENT_LANGUAGE_HTTP_HEADER = CONTENT_LANGUAGE_HTTP_HEADER_ARRAY;
static int* CONTENT_LANGUAGE_HTTP_HEADER_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The content encoding http header. */
static wchar_t CONTENT_ENCODING_HTTP_HEADER_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* CONTENT_ENCODING_HTTP_HEADER = CONTENT_ENCODING_HTTP_HEADER_ARRAY;
static int* CONTENT_ENCODING_HTTP_HEADER_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The content length http header. */
static wchar_t CONTENT_LENGTH_HTTP_HEADER_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CONTENT_LENGTH_HTTP_HEADER = CONTENT_LENGTH_HTTP_HEADER_ARRAY;
static int* CONTENT_LENGTH_HTTP_HEADER_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The date http header. */
static wchar_t DATE_HTTP_HEADER_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_HTTP_HEADER = DATE_HTTP_HEADER_ARRAY;
static int* DATE_HTTP_HEADER_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The last modified http header. */
static wchar_t LAST_MODIFIED_HTTP_HEADER_ARRAY[] = {L'l', L'a', L's', L't', L'-', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* LAST_MODIFIED_HTTP_HEADER = LAST_MODIFIED_HTTP_HEADER_ARRAY;
static int* LAST_MODIFIED_HTTP_HEADER_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The set cookie http header. */
static wchar_t SET_COOKIE_HTTP_HEADER_ARRAY[] = {L's', L'e', L't', L'-', L'c', L'o', L'o', L'k', L'i', L'e'};
static wchar_t* SET_COOKIE_HTTP_HEADER = SET_COOKIE_HTTP_HEADER_ARRAY;
static int* SET_COOKIE_HTTP_HEADER_COUNT = NUMBER_10_INTEGER_ARRAY;

/* HTTP_HEADER_CONSTANTS_SOURCE */
#endif
