/*
 * $RCSfile: communicator.c,v $
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
 * - receive data into a byte array
 * - send data from a byte array
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-14 22:20:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATOR_SOURCE
#define COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/channel_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Receives a stream according to the given communication channel type
 * and creates a byte array from it.
 *
 * @param p0 the destination (byte array)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void receive(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {

    if (p6 != NULL_POINTER) {

        int* tc = (int*) p6;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*tc == INLINE_CHANNEL_COUNT) {

                compare_array_elements(p5, (void*) &INLINE_CHANNEL, (void*) &CHARACTER_ARRAY, (void*) &INLINE_CHANNEL_COUNT, (void*) &r);

                if (r == 1) {

                    receive_inline(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*tc == FILE_CHANNEL_COUNT) {

                compare_array_elements(p5, (void*) &FILE_CHANNEL, (void*) &CHARACTER_ARRAY, (void*) &FILE_CHANNEL_COUNT, (void*) &r);

                if (r == 1) {

                    receive_file(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*tc == FTP_CHANNEL_COUNT) {

                compare_array_elements(p5, (void*) &FTP_CHANNEL, (void*) &CHARACTER_ARRAY, (void*) &FTP_CHANNEL_COUNT, (void*) &r);

                if (r == 1) {

                    receive_ftp(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*tc == HTTP_CHANNEL_COUNT) {

                compare_array_elements(p5, (void*) &HTTP_CHANNEL, (void*) &CHARACTER_ARRAY, (void*) &HTTP_CHANNEL_COUNT, (void*) &r);

                if (r == 1) {

                    receive_http(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_MESSAGE, (void*) &COULD_NOT_PARSE_MESSAGE_COUNT);
    }
}

/**
 * Sends a stream according to the given communication channel type
 * and reads its data from a byte array.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void send(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6) {
}

/* COMMUNICATOR_SOURCE */
#endif
