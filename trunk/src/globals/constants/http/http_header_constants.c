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
 * @version $Revision: 1.2 $ $Date: 2008-05-04 00:18:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_HEADER_CONSTANTS_SOURCE
#define HTTP_HEADER_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The content type http header. */
static char CONTENT_TYPE_HTTP_HEADER_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '-', 't', 'y', 'p', 'e'};
static char* CONTENT_TYPE_HTTP_HEADER = CONTENT_TYPE_HTTP_HEADER_ARRAY;
static int* CONTENT_TYPE_HTTP_HEADER_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The content language http header. */
static char CONTENT_LANGUAGE_HTTP_HEADER_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '-', 'l', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
static char* CONTENT_LANGUAGE_HTTP_HEADER = CONTENT_LANGUAGE_HTTP_HEADER_ARRAY;
static int* CONTENT_LANGUAGE_HTTP_HEADER_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The content encoding http header. */
static char CONTENT_ENCODING_HTTP_HEADER_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '-', 'e', 'n', 'c', 'o', 'd', 'i', 'n', 'g'};
static char* CONTENT_ENCODING_HTTP_HEADER = CONTENT_ENCODING_HTTP_HEADER_ARRAY;
static int* CONTENT_ENCODING_HTTP_HEADER_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The content length http header. */
static char CONTENT_LENGTH_HTTP_HEADER_ARRAY[] = {'c', 'o', 'n', 't', 'e', 'n', 't', '-', 'l', 'e', 'n', 'g', 't', 'h'};
static char* CONTENT_LENGTH_HTTP_HEADER = CONTENT_LENGTH_HTTP_HEADER_ARRAY;
static int* CONTENT_LENGTH_HTTP_HEADER_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The date http header. */
static char DATE_HTTP_HEADER_ARRAY[] = {'d', 'a', 't', 'e'};
static char* DATE_HTTP_HEADER = DATE_HTTP_HEADER_ARRAY;
static int* DATE_HTTP_HEADER_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The last modified http header. */
static char LAST_MODIFIED_HTTP_HEADER_ARRAY[] = {'l', 'a', 's', 't', '-', 'm', 'o', 'd', 'i', 'f', 'i', 'e', 'd'};
static char* LAST_MODIFIED_HTTP_HEADER = LAST_MODIFIED_HTTP_HEADER_ARRAY;
static int* LAST_MODIFIED_HTTP_HEADER_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The set cookie http header. */
static char SET_COOKIE_HTTP_HEADER_ARRAY[] = {'s', 'e', 't', '-', 'c', 'o', 'o', 'k', 'i', 'e'};
static char* SET_COOKIE_HTTP_HEADER = SET_COOKIE_HTTP_HEADER_ARRAY;
static int* SET_COOKIE_HTTP_HEADER_COUNT = NUMBER_10_INTEGER_ARRAY;

/* HTTP_HEADER_CONSTANTS_SOURCE */
#endif
