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
 * @version $Revision: 1.5 $ $Date: 2004-05-25 22:58:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRING_SOURCE
#define STRING_SOURCE

#include "../constants/constants.c"
#include "../logger/logger.c"

//
// String.
//

/**
 * Initializes the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 */
void initialize_string(void* p0, void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* pc = (int*) p3;

        if (p2 != NULL_POINTER) {

            char* p = (char*) p2;

            if (p1 != NULL_POINTER) {

                int* tc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    char* t = (char*) p0;

                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize string.");

                    *t = *p;
                    *tc = *pc;

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize string. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize string. The transient model count is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize string. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize string. The persistent model count is null.");
    }
}

/**
 * Finalizes the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 */
void finalize_string(const void* p0, const void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* pc = (int*) p3;

        if (p2 != NULL_POINTER) {

            char* p = (char*) p2;

            if (p1 != NULL_POINTER) {

                int* tc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    char* t = (char*) p0;

                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize string.");

                    *p = *t;
                    *pc = *tc;

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize string. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize string. The transient model count is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize string. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize string. The persistent model count is null.");
    }
}

/* STRING_SOURCE */
#endif
