/*
 * $RCSfile: boolean_handler.c,v $
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
 * @version $Revision: 1.14 $ $Date: 2004-04-21 11:02:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BOOLEAN_HANDLER_SOURCE
#define BOOLEAN_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"
#include "../model/array_handler.c"

//
// Constants.
//

/** The true boolean. */
static const char TRUE_BOOLEAN[] = {'t', 'r', 'u', 'e'};

/** The true boolean size. */
static const int TRUE_BOOLEAN_SIZE = 4;

/** The false boolean. */
static const char FALSE_BOOLEAN[] = {'f', 'a', 'l', 's', 'e'};

/** The false boolean size. */
static const int FALSE_BOOLEAN_SIZE = 5;

//
// Boolean.
//

/**
 * Initializes the boolean.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void initialize_boolean(void* p0, const void* p1, const void* p2) {

    if (p0 != NULL_POINTER) {

        int* t = (int*) p0;

        log_message((void*) &INFO_LOG_LEVEL, "Initialize boolean.");

        int r = 0;
        compare_arrays(p1, p2, (void*) &TRUE_BOOLEAN, (void*) &TRUE_BOOLEAN_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            *t = 1;

        } else {

            // The default.
            *t = 0;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize boolean. The transient model is null.");
    }
}

/**
 * Finalizes the boolean.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_boolean(const void* p0, void* p1, void* p2) {

    if (p0 != NULL_POINTER) {

        int* t = (int*) p0;

        if (p1 != NULL_POINTER) {

            char* p = (char*) p1;

            if (p2 != NULL_POINTER) {

                int* ps = (int*) p2;

                log_message((void*) &INFO_LOG_LEVEL, "Finalize boolean.");

                if (*t == 1) {

//??                    *p = TRUE_BOOLEAN;
                    *ps = TRUE_BOOLEAN_SIZE;

                } else {

                    // The default.
//??                    *p = FALSE_BOOLEAN;
                    *ps = FALSE_BOOLEAN_SIZE;
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize boolean. The persistent model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize boolean. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize boolean. The transient model is null.");
    }
}

/* BOOLEAN_HANDLER_SOURCE */
#endif
