/*
 * $RCSfile: communicator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * - receive data into a byte array
 * - send data from a byte array
 *
 * @version $Revision: 1.1 $ $Date: 2005-03-01 13:10:58 $ $Author: reichenbach $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATOR_SOURCE
#define COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../communicator/file_communicator.c"
#include "../communicator/ftp_communicator.c"
#include "../communicator/http_communicator.c"
#include "../communicator/inline_communicator.c"
#include "../global/channel_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Receives a stream according to the given communication channel type
 * and creates a byte array from it.
 *
 * CAUTION! This procedure cannot be called "receive"
 * as that name is already used by the socket mechanism.
 *
 * @param p0 the destination (byte array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void receive_general(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p5, p6, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_file(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) FTP_CHANNEL, (void*) FTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_ftp(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) HTTP_CHANNEL, (void*) HTTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_http(p0, p1, p2, p3, p4);
        }
    }
}

/**
 * Sends a stream according to the given communication channel type
 * and reads its data from a byte array.
 *
 * CAUTION! This procedure cannot be called "send"
 * as that name is already used by the socket mechanism.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void send_general(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p5, p6, (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_inline(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_file(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) FTP_CHANNEL, (void*) FTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_ftp(p0, p1, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays(p5, p6, (void*) HTTP_CHANNEL, (void*) HTTP_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_http(p0, p1, p2, p3, p4);
        }
    }
}

/* COMMUNICATOR_SOURCE */
#endif
