/*
 * $RCSfile: integer_handler.c,v $
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

#ifndef INTEGER_HANDLER_SOURCE
#define INTEGER_HANDLER_SOURCE

#include "integer.c"

/**
 * This is the integer handler.
 *
 * @version $Revision: 1.2 $ $Date: 2003-12-05 12:10:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default integer value. */
static const int DEFAULT_INTEGER_VALUE = 0;

//
// Integer model.
//

/**
 * Initializes the integer model.
 *
 * @param p0 the integer model
 * @param p1 the model source
 */
static void initialize_integer_model(void* p0, void* p1) {

    struct integer* m = (struct integer*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize integer model.");

        // Read input stream and transform to integer.
//??        sscanf(p1, %d, (void*) &(m->value));

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize integer model. The integer model is null.");
    }
}

/**
 * Finalizes the integer model.
 *
 * @param p0 the integer model
 * @param p1 the model source
 */
static void finalize_integer_model(void* p0, void* p1) {

    struct integer* m = (struct integer*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize integer model.");
        
        // Write output stream and transform from integer.
//??        sprintf(p1, %d, (void*) &(m->value));

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize integer model. The integer model is null.");
    }
}

/* INTEGER_HANDLER_SOURCE */
#endif

