/*
 * $RCSfile: string.c,v $
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
 * This file handles a string.
 *
 * A string is a chain of characters.
 *
 * @version $Revision: 1.6 $ $Date: 2004-08-13 07:22:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRING_SOURCE
#define STRING_SOURCE

#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Creates the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_string(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_STRING_MESSAGE, (void*) &CREATE_STRING_MESSAGE_COUNT);

    create_array(p0, (void*) &CHARACTER_ARRAY, p1);
}

/**
 * Destroys the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_string(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_STRING_MESSAGE, (void*) &DESTROY_STRING_MESSAGE_COUNT);

    destroy_array(p0, (void*) &CHARACTER_ARRAY, p1);
}

/**
 * Initializes the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_string(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* pc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ts = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* tc = (int*) p1;

                // The destination array index.
                int i = 0;

                // The new transient array size.
                // (Not exactly the size, but the transient array index
                // increased by the persistent array count.)
                int nts = i + *pc;

                if (i >= 0) {

//??                log_message((void*) &INFO_LOG_LEVEL, (void*) &INITIALIZE_STRING_MESSAGE, (void*) &INITIALIZE_STRING_MESSAGE_COUNT);

                    if (nts >= *ts) {

                        while (nts >= *ts) {

                            // Increase size.
                            *ts = (*ts * STRING_RESIZE_FACTOR) + 1;
                        }

                        // Resize string.
                        resize_array(p0, (void*) &CHARACTER_ARRAY, p2);
                    }

                    if (i < (*ts - *pc)) {

                        // Set string.
                        // CAUTION! Parameter is only set, when not null.

                        if (p3 != NULL_POINTER) {

                            set_array_elements(p0, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);
                        }

                        // Increment count.
                        // Example:
                        // t = "helloworld"
                        // i = 5
                        // p = "universe"
                        // pc = 8
                        // t (after set) = "hellouniverse"
                        // tc = i + pc = 13
                        *tc = i + *pc;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index exceeds the size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The transient count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The transient size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The persistent count is null.");
    }
}

/**
 * Finalizes the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_string(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* STRING_SOURCE */
#endif
