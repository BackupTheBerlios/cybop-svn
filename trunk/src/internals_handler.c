/*
 * $RCSfile: internals_handler.c,v $
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
 * This file handles internals.
 *
 * @version $Revision: 1.5 $ $Date: 2004-04-01 17:35:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNALS_HANDLER_SOURCE
#define INTERNALS_HANDLER_SOURCE

#include "internals.c"
#include "logger/log_handler.c"
#include "x_windows/x_windows.c"

//
// Internals.
//

/**
 * Initializes the internals.
 *
 * @param p0 the internals
 */
void initialize_internals(void* p0) {

    struct internals* i = (struct internals*) p0;

    if (i != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize internals.");

        i->x_windows_flag = 1;
        i->x_windows = (void*) malloc(sizeof(struct x_windows));
        initialize_x_windows(i->x_windows);

/*??
        i->macintosh_flag = 0;
        i->macintosh = malloc(sizeof(struct macintosh));
        initialize_macintosh(i->macintosh);

        i->ms_windows_flag = 0;
        i->ms_windows = malloc(sizeof(struct ms_windows));
        initialize_ms_windows(i->ms_windows);
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize internals. The internals is null.");
    }
}

/**
 * Finalizes the internals.
 *
 * @param p0 the internals
 */
void finalize_internals(void* p0) {

    struct internals* i = (struct internals*) p0;

    if (i != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize internals.");

/*??
        finalize_ms_windows(i->ms_windows);
        free(i->ms_windows);
        i->ms_windows_flag = -1;

        finalize_macintosh(i->macintosh);
        free(i->macintosh);
        i->macintosh_flag = -1;
*/

        finalize_x_windows(i->x_windows);
        free(i->x_windows);
        i->x_windows_flag = -1;

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize internals. The internals is null.");
    }
}

/* INTERNALS_HANDLER_SOURCE */
#endif
