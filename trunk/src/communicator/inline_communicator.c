/*
 * $RCSfile: inline_communicator.c,v $
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
 * - receive an inline stream into a byte array
 * - send an inline stream from a byte array
 *
 * @version $Revision: 1.2 $ $Date: 2004-12-20 00:19:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INLINE_COMMUNICATOR_SOURCE
#define INLINE_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Receives an inline stream and writes it into a byte array.
 *
 * @param p0 the destination (byte array)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (inline data)
 * @param p4 the source count
 */
void receive_inline(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int** sc = (int**) p4;

        if (p2 != NULL_POINTER) {

            int** ds = (int**) p2;

            if (p1 != NULL_POINTER) {

                int** dc = (int**) p1;

                // Set new array size.
                **ds = **sc;

                // Resize array.
                resize_array(p0, (void*) &CHARACTER_ARRAY, p2);

                // The destination array index to start writing at.
                int* i = INTEGER_NULL_POINTER;
                create_integer((void*) &i);
                *i = 0;

                set_array_elements(p0, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);

                destroy_integer((void*) &i);

                // Set new array count.
                **dc = **sc;

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read inline. The array count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read inline. The array size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read inline. The inline byte stream count is null.");
    }
}

/**
 * Sends an inline stream that was read from a byte array.
 *
 * @param p0 the destination (inline data)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 */
void send_inline(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* INLINE_COMMUNICATOR_SOURCE */
#endif
