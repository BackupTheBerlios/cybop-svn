/*
 * $RCSfile: ftp_communicator.c,v $
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
 * This file contains the functionality to:
 * - receive an ftp stream into a byte array
 * - send an ftp stream from a byte array
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-14 22:20:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FTP_COMMUNICATOR_SOURCE
#define FTP_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Receives an ftp stream and writes it into a byte array.
 *
 * @param p0 the destination (byte array)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (ftp url)
 * @param p4 the source count
 * ?? login
 * ?? password
 */
void receive_ftp(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Sends an ftp stream that was read from a byte array.
 *
 * @param p0 the destination (ftp url)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 * ?? login
 * ?? password
 */
void send_ftp(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* FTP_COMMUNICATOR_SOURCE */
#endif
