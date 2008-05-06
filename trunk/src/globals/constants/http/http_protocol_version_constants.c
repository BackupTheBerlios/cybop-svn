/*
 * $RCSfile: http_protocol_version_constants.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_PROTOCOL_VERSION_CONSTANTS_SOURCE
#define HTTP_PROTOCOL_VERSION_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The http 1.0 protocol version. */
static wchar_t HTTP_1_0_PROTOCOL_VERSION_ARRAY[] = {L'H', L'T', L'T', L'P', L'/', L'1', L'.', L'0'};
static wchar_t* HTTP_1_0_PROTOCOL_VERSION = HTTP_1_0_PROTOCOL_VERSION_ARRAY;
static int* HTTP_1_0_PROTOCOL_VERSION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The http 1.1 protocol version. */
static wchar_t HTTP_1_1_PROTOCOL_VERSION_ARRAY[] = {L'H', L'T', L'T', L'P', L'/', L'1', L'.', L'1'};
static wchar_t* HTTP_1_1_PROTOCOL_VERSION = HTTP_1_1_PROTOCOL_VERSION_ARRAY;
static int* HTTP_1_1_PROTOCOL_VERSION_COUNT = NUMBER_8_INTEGER_ARRAY;

/* HTTP_PROTOCOL_VERSION_CONSTANTS_SOURCE */
#endif
