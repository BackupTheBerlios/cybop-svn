/*
 * $RCSfile: model_handler.c,v $
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

#ifndef MODEL_HANDLER_SOURCE
#define MODEL_HANDLER_SOURCE

#include <string.h>
#include "log_handler.c"
#include "map.c"
#include "map_handler.c"

/**
 * This is the model handler.
 *
 * It contains functions which are used by both, the statics and the
 * dynamics model handler.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Helper functions.
//

/**
 * Returns the part name.
 *
 * It is the most left name before the first dot/point "." in the given string
 * or, if there is no dot, then it is the given name itself.
 *
 * @param p0 the hierarchical model name
 * @return the part name
 */
static void* get_part_name(void* p0) {
    
    void* name = 0;
    char* n = (char*) p0;
    
    if (n != 0) {
        
/*??
        int i = n->indexOf(".");
        
        if (i != -1) {
            
            p1 = n->substring(0, i);
        
        } else {
        
            p1 = n;
        }
*/
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not get part name. The hierarchical model name is null.");
    }
    
    return name;
}

/**
 * Returns the remaining name.
 *
 * It is the whole string after the first dot/point ".".
 *
 * @param p0 the hierarchical model name
 * @return the remaining name
 */
static void* get_remaining_name(void* p0) {

    void* name = 0;    
    char* n = (char*) p0;
    
    if (n != 0) {
        
/*??
        int i = n->indexOf(".");
        
        if (i != -1) {

            p1 = n->substring(i + 1);
        }
*/
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not get remaining name. The hierarchical model name is null.");
    }
    
    return name;
}

/* MODEL_HANDLER_SOURCE */
#endif

