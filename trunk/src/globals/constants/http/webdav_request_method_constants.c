/*
 * $RCSfile: webdav_request_method_constants.c,v $
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

#ifndef WEBDAV_REQUEST_METHOD_CONSTANTS_SOURCE
#define WEBDAV_REQUEST_METHOD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The propfind request method. Reads properties as resources from an xml file. Retrieves the directory structure of a remote system. */
static char WEBDAV_PROPFIND_REQUEST_METHOD_ARRAY[] = {'P', 'R', 'O', 'P', 'F', 'I', 'N', 'D'};
static char* WEBDAV_PROPFIND_REQUEST_METHOD = WEBDAV_PROPFIND_REQUEST_METHOD_ARRAY;
static int* WEBDAV_PROPFIND_REQUEST_METHOD_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The proppatch request method. Changes and deletes various properties of a resource in one single atomic act. */
static char WEBDAV_PROPPATCH_REQUEST_METHOD_ARRAY[] = {'P', 'R', 'O', 'P', 'P', 'A', 'T', 'C', 'H'};
static char* WEBDAV_PROPPATCH_REQUEST_METHOD = WEBDAV_PROPPATCH_REQUEST_METHOD_ARRAY;
static int* WEBDAV_PROPPATCH_REQUEST_METHOD_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The mkcol request method. Creates a collection (also called directory). */
static char WEBDAV_MKCOL_REQUEST_METHOD_ARRAY[] = {'M', 'K', 'C', 'O', 'L'};
static char* WEBDAV_MKCOL_REQUEST_METHOD = WEBDAV_MKCOL_REQUEST_METHOD_ARRAY;
static int* WEBDAV_MKCOL_REQUEST_METHOD_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The copy request method. Copies a resource from one uri to another. */
static char WEBDAV_COPY_REQUEST_METHOD_ARRAY[] = {'C', 'O', 'P', 'Y'};
static char* WEBDAV_COPY_REQUEST_METHOD = WEBDAV_COPY_REQUEST_METHOD_ARRAY;
static int* WEBDAV_COPY_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The move request method. Moves a resource from one uri to another. */
static char WEBDAV_MOVE_REQUEST_METHOD_ARRAY[] = {'M', 'O', 'V', 'E'};
static char* WEBDAV_MOVE_REQUEST_METHOD = WEBDAV_MOVE_REQUEST_METHOD_ARRAY;
static int* WEBDAV_MOVE_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The lock request method. Locks a resource. */
static char WEBDAV_LOCK_REQUEST_METHOD_ARRAY[] = {'L', 'O', 'C', 'K'};
static char* WEBDAV_LOCK_REQUEST_METHOD = WEBDAV_LOCK_REQUEST_METHOD_ARRAY;
static int* WEBDAV_LOCK_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The unlock request method. Unlocks a resource. */
static char WEBDAV_UNLOCK_REQUEST_METHOD_ARRAY[] = {'U', 'N', 'L', 'O', 'C', 'K'};
static char* WEBDAV_UNLOCK_REQUEST_METHOD = WEBDAV_UNLOCK_REQUEST_METHOD_ARRAY;
static int* WEBDAV_UNLOCK_REQUEST_METHOD_COUNT = NUMBER_6_INTEGER_ARRAY;

/* WEBDAV_REQUEST_METHOD_CONSTANTS_SOURCE */
#endif
