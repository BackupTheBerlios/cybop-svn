/*
 * $RCSfile: tcp_socket_constants.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2006-04-20 22:36:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TCP_SOCKET_CONSTANTS_SOURCE
#define TCP_SOCKET_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Request method.
//

/** The get request method. */
static char GET_REQUEST_METHOD_ARRAY[] = {'G', 'E', 'T'};
static char* GET_REQUEST_METHOD = GET_REQUEST_METHOD_ARRAY;
static int* GET_REQUEST_METHOD_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The post request method. */
static char POST_REQUEST_METHOD_ARRAY[] = {'P', 'O', 'S', 'T'};
static char* POST_REQUEST_METHOD = POST_REQUEST_METHOD_ARRAY;
static int* POST_REQUEST_METHOD_COUNT = NUMBER_4_INTEGER_ARRAY;

/* TCP_SOCKET_CONSTANTS_SOURCE */
#endif
