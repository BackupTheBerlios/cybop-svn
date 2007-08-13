/*
 * $RCSfile: ftp_communicator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.8 $ $Date: 2007-08-13 16:37:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FTP_COMMUNICATOR_SOURCE
#define FTP_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Reads an ftp stream and writes it into a byte array.
 *
 * @param p0 the destination (byte array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (ftp url)
 * @param p4 the source count
 * ?? login
 * ?? password
 */
void read_ftp(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Writes an ftp stream that was read from a byte array.
 *
 * @param p0 the destination (ftp url) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 * ?? login
 * ?? password
 */
void write_ftp(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* FTP_COMMUNICATOR_SOURCE */
#endif
