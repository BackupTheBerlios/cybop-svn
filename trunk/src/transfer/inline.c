/*
 * $RCSfile: inline.c,v $
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

#ifndef INLINE_SOURCE
#define INLINE_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Reads inline stream into array.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the inline byte stream
 * @param p4 the inline byte stream count
 */
void read_inline(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* ic = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* as = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* ac = (int*) p1;

                // Set new array size.
                *as = *ic;

                // Resize array.
                resize_array(p0, (void*) &CHARACTER_ARRAY, p2);

                // The array index to start writing at.
                int i = 0;

                set_array_elements(p0, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);

                // Set new array count.
                *ac = *ic;

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
 * Writes inline stream from array.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the inline byte stream
 * @param p4 the inline byte stream count
 */
void write_inline(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {
}

/* INLINE_SOURCE */
#endif
