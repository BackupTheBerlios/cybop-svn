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
#include "../logger/log_handler.c"
#include "../model/map.c"
#include "../model/map_handler.c"

/**
 * This is the model handler.
 *
 * It contains functions which are used by both, the statics and the
 * dynamics model handler.
 *
 * @version $Revision: 1.5 $ $Date: 2004-01-05 16:38:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The empty string. */
static const char* EMPTY_STRING = "";

/** The slash separator. */
static const char* SLASH_SEPARATOR = "/";

/** The dot separator. */
static const char* DOT_SEPARATOR = ".";

/** The comma separator. */
static const char* COMMA_SEPARATOR = ",";

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
 * @param p1 the separation
 * @return the part name
 */
void* get_part_name(void* p0, void* p1) {
    
    void* p = 0;
    char* n = (char*) p0;
    
    if (n != 0) {
        
/*??
        int i = n->indexOf(p1);
        
        if (i != -1) {
            
            p = n->substring(0, i);
        
        } else {
        
            p = n;
        }
*/
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not get part name. The hierarchical model name is null.");
    }
    
    return p;
}

/**
 * Returns the remaining name.
 *
 * It is the whole string after the first dot/point ".".
 *
 * @param p0 the hierarchical model name
 * @param p1 the separation
 * @return the remaining name
 */
void* get_remaining_name(void* p0, void* p1) {

    void* r = 0;    
    char* n = (char*) p0;
    
    if (n != 0) {
        
/*??
        int i = n->indexOf(p1);
        
        if (i != -1) {

            r = n->substring(i + 1);
        }
*/
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not get remaining name. The hierarchical model name is null.");
    }
    
    return r;
}

/* MODEL_HANDLER_SOURCE */
#endif

