/*
 * $RCSfile: ftp.c,v $
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

#ifndef FTP_SOURCE
#define FTP_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Reads ftp stream into array.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the ftp url
 * @param p4 the ftp url count
 * ?? login
 * ?? password
 */
void read_ftp(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Writes ftp stream from array.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the ftp url
 * @param p4 the ftp url count
 * ?? login
 * ?? password
 */
void write_ftp(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {
}

/* FTP_SOURCE */
#endif
