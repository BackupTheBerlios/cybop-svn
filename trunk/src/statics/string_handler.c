/*
 * $RCSfile: string_handler.c,v $
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
 * @version $Revision: 1.10 $ $Date: 2004-04-02 16:13:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRING_HANDLER_SOURCE
#define STRING_HANDLER_SOURCE

#include "../logger/log_handler.c"

//
// String.
//

/**
 * Initializes the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void initialize_string(void* p0, void* p1, const void* p2, const void* p3) {

    int* ps = (int*) p3;

    if (ps != (void*) 0) {

        char* p = (char*) p2;

        if (p != (void*) 0) {

            int* ts = (int*) p1;

            if (ts != (void*) 0) {

                char* t = (char*) p0;

                if (t != (void*) 0) {

                    log_message((void*) &INFO_LOG_LEVEL, "Initialize string.");

                    *t = *p;
                    *ts = *ps;

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize string. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize string. The transient model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize string. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize string. The persistent model size is null.");
    }
}

/**
 * Finalizes the string.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void finalize_string(const void* p0, const void* p1, void* p2, void* p3) {

    int* ps = (int*) p3;

    if (ps != (void*) 0) {

        char* p = (char*) p2;

        if (p != (void*) 0) {

            int* ts = (int*) p1;

            if (ts != (void*) 0) {

                char* t = (char*) p0;

                if (t != (void*) 0) {

                    log_message((void*) &INFO_LOG_LEVEL, "Finalize string.");

                    *p = *t;
                    *ps = *ts;

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize string. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize string. The transient model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize string. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize string. The persistent model size is null.");
    }
}

/* STRING_HANDLER_SOURCE */
#endif
