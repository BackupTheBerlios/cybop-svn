/*
 * $RCSfile: time_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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
 */

#include <string.h>
#include "time.c"

/**
 * This is the time handler.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default time value. */
static const char* DEFAULT_TIME_VALUE = "01.01.0000 00:00:00";

//
// Time model.
//

/**
 * Initializes the time model.
 *
 * @param p0 the time model
 * @param p1 the model source
 */
static void initialize_time_model(void* p0, void* p1) {

    struct time* m = (struct time*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize time model.");

        // Read input stream and transform to time.
//??        fscanf(p1, %d, &(m->value));

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize time model. The time model is null.");
    }
}

/**
 * Finalizes the time model.
 *
 * @param p0 the time model
 * @param p1 the model source
 */
static void finalize_time_model(void* p0, void* p1) {

    struct time* m = (struct time*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize time model.");
        
        // Write output stream and transform from time.
//??        fprintf(p1, %d, &(m->value));

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize time model. The time model is null.");
    }
}

