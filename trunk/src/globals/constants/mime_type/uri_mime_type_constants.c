/*
 * $RCSfile: uri_mime_type_constants.c,v $
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

#ifndef URI_MIME_TYPE_CONSTANTS_SOURCE
#define URI_MIME_TYPE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The mms uri mime type. */
static wchar_t MMS_URI_MIME_TYPE_ARRAY[] = {L'u', L'r', L'i', L'/', L'm', L'm', L's'};
static wchar_t* MMS_URI_MIME_TYPE = MMS_URI_MIME_TYPE_ARRAY;
static int* MMS_URI_MIME_TYPE_COUNT = NUMBER_7_INTEGER_ARRAY;

/* URI_MIME_TYPE_CONSTANTS_SOURCE */
#endif
