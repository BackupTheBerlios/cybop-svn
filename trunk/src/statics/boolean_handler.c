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

#ifndef BOOLEAN_HANDLER_SOURCE
#define BOOLEAN_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../statics/boolean.c"

/**
 * This is the boolean handler.
 *
 * @version $Revision: 1.6 $ $Date: 2004-01-05 20:24:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The true boolean value. */
static const char* TRUE_VALUE = "true";

/** The false boolean value. */
static const char* FALSE_VALUE = "false";

/** The default boolean value. */
static const char* DEFAULT_BOOLEAN_VALUE = "false";

//
// Boolean model.
//

/**
 * Initializes the boolean model.
 *
 * @param p0 the boolean model
 * @param p1 the model source
 */
void initialize_boolean_model(void* p0, void* p1) {

    struct boolean* m = (struct boolean*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize boolean model.");

        if (strcmp((char*) p1, TRUE_VALUE) == 0) {
            
            m->value = 1;
            
        } else {

            // The default value is "false".
            m->value = 0;
        }

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize boolean model. The boolean model is null.");
    }
}

/**
 * Finalizes the boolean model.
 *
 * @param p0 the boolean model
 * @param p1 the model source
 */
void finalize_boolean_model(void* p0, void* p1) {

    struct boolean* m = (struct boolean*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Finalize boolean model.");

        if (m->value == 1) {
            
            strcat(p1, TRUE_VALUE);
            
        } else {
    
            strcat(p1, FALSE_VALUE);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize boolean model. The boolean model is null.");
    }
}

/* BOOLEAN_HANDLER_SOURCE */
#endif

