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

#include "integer.c"

/**
 * This is the integer handler.
 *
 * @version $Revision: 1.2 $ $Date: 2003-10-22 00:45:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default integer value. */
static const int DEFAULT_INTEGER_VALUE = 0;

/** The invalid index value. */
static const int INVALID_VALUE = -1;

//
// Integer model.
//

/**
 * Creates an integer model.
 *
 * @param p0 the model source
 * @return the integer model
 */
static void* create_integer_model(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create integer model.");
        
        if (strcmp(p0, "") != 0) {
            
            i = malloc(sizeof(struct integer));

            initialize_integer_model(i, p0);
        }
    }
    
    return i;
}

/**
 * Destroys the integer model.
 *
 * @param p0 the integer model
 * @param p1 the model source
 */
static void destroy_integer_model(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy integer model.");

        if (strcmp(p1, "") != 0) {
            
            finalize_integer_model(p0, p1);
        }

        free(p0);
    }
}

/**
 * Initializes the integer model.
 *
 * @param p0 the integer model
 * @param p1 the model source
 */
static void initialize_integer_model(void* p0, void* p1) {

    struct integer* i = (struct integer*) p0;
    
    if (i != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize integer model.");

        // Read input stream and transform to integer.
        fscanf(p1, %d, &(i->value));

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

    struct integer* i = (struct integer*) p0;
    
    if (i != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize integer model.");
        
        // Write output stream and transform from integer.
        fprintf(p1, %d, &(i->value));

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize integer model. The integer model is null.");
    }
}

