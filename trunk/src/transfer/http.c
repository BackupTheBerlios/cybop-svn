/*
 * $RCSfile: http.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file handles a file.
 *
 * @version $Revision: 1.1 $ $Date: 2004-07-28 22:46:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_SOURCE
#define HTTP_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Reads http stream into array.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the http url
 * @param p4 the http url count
 */
void read_http(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Writes http stream from array.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the http url
 * @param p4 the http url count
 */
void write_http(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {
}

/* HTTP_SOURCE */
#endif
