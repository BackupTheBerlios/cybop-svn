/*
 * $RCSfile: boolean.c,v $
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
 * This file handles a boolean.
 *
 * A boolean can have just one of the two values: TRUE or FALSE
 * Synonyms are:
 * - one and zero
 * - 1 and 0
 * - on and off
 *
 * @version $Revision: 1.2 $ $Date: 2004-06-11 19:34:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_SOURCE
#define BOOLEAN_SOURCE

#include "../array/array.c"
#include "../constant/constant.c"
#include "../logger/logger.c"

//
// Boolean.
//

/**
 * Initializes the boolean.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_boolean(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p3 != NULL_POINTER) {

        int* pc = (int*) p3;

        if (p0 != NULL_POINTER) {

            int* t = (int*) p0;

            // The default.
            *t = 0;

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize boolean.");

            // The comparison result.
            int r = 0;

            if (*pc == TRUE_BOOLEAN_COUNT) {

                compare_array_elements(p1, (void*) &TRUE_BOOLEAN, (void*) &CHARACTER_ARRAY, (void*) &TRUE_BOOLEAN_COUNT, (void*) &r);

                if (r == 1) {

                    *t = 1;
                }
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize boolean. The transient model is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize boolean. The persistent model count is null.");
    }
}

/**
 * Finalizes the boolean.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_boolean(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p3 != NULL_POINTER) {

        int* pc = (int*) p3;

        if (p1 != NULL_POINTER) {

            char* p = (char*) p2;

            if (p0 != NULL_POINTER) {

                int* t = (int*) p0;

//??                log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize boolean.");

                if (*t == 1) {

//??                    *p = TRUE_BOOLEAN;
                    *pc = TRUE_BOOLEAN_COUNT;

                } else {

                    // The default.
//??                    *p = FALSE_BOOLEAN;
                    *pc = FALSE_BOOLEAN_COUNT;
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize boolean. The transient model is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize boolean. The persistent model is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize boolean. The persistent model count is null.");
    }
}

/* BOOLEAN_SOURCE */
#endif
