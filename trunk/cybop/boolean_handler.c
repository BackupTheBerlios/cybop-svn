/*
 * $RCSfile: boolean_handler.c,v $
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

#include "boolean.c"

/**
 * This is the boolean handler.
 *
 * @version $Revision: 1.2 $ $Date: 2003-10-22 00:45:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The true boolean value. */
static const int TRUE_VALUE = 1;

/** The false boolean value. */
static const int FALSE_VALUE = 0;

//
// Boolean model.
//

/**
 * Creates a boolean model.
 *
 * @param p0 the model source
 * @return the boolean model
 */
static void* create_boolean_model(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create boolean model.");

        if (strcmp(p0, "") != 0) {
            
            i = malloc(sizeof(struct boolean));

            initialize_boolean_model(i, p0);
        }
    }
    
    return i;
}

/**
 * Destroys the boolean model.
 *
 * @param p0 the boolean model
 * @param p1 the model source
 */
static void destroy_boolean_model(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy boolean model.");

        if (strcmp(p1, "") != 0) {
            
            finalize_boolean_model(p0, p1);
        }

        free(p0);
    }
}

/**
 * Initializes the boolean model.
 *
 * @param p0 the boolean model
 * @param p1 the model source
 */
static void initialize_boolean_model(void* p0, void* p1) {

    struct boolean* b = (struct boolean*) p0;
    
    if (b != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize boolean model.");

        if (strcmp((char*) p1, TRUE_VALUE)) {
            
            b->value = 1;
            
        } else {

            // The default value is "false".
            b->value = 0;
        }

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize boolean model. The boolean model is null.");
    }
}

/**
 * Finalizes the boolean model.
 *
 * @param p0 the boolean model
 * @param p1 the model source
 */
static void finalize_boolean_model(void* p0, void* p1) {

    struct boolean* b = (struct boolean*) p0;
    
    if (b != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize boolean model.");

        if (b->value == 1) {
            
            strcat(p1, TRUE_VALUE);
            
        } else {
    
            strcat(p1, FALSE_VALUE);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize boolean model. The boolean model is null.");
    }
}

