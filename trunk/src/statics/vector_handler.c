/*
 * $RCSfile: vector_handler.c,v $
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
#include "vector.c"

/**
 * This is the vector handler.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default vector value. */
static const char* DEFAULT_VECTOR_VALUE = "0.0,0.0,0.0";

//
// Vector model.
//

/**
 * Initializes the vector model.
 *
 * @param p0 the vector model
 * @param p1 the model source
 */
static void initialize_vector_model(void* p0, void* p1) {

    struct vector* m = (struct vector*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize vector model.");

        // Read input stream and transform to vector.
//??        fscanf(p1, %d, &(m->x));
//??        fscanf(p1, %d, &(m->y));
//??        fscanf(p1, %d, &(m->z));

/*??
        int i1 = s.indexOf(",");
        
        if (i1 != -1) {
            
            char[] x = s.substring(0, i1);
            char[] yz = s.substring(i1 + 1);
            int i2 = yz.indexOf(",");

            if (i2 != -1) {
            
                char[] y = yz.substring(0, i2);
                char[] z = yz.substring(i2 + 1);

                p.x = java.lang.Integer.parseInt(x);
                p.y = java.lang.Integer.parseInt(y);
                p.z = java.lang.Integer.parseInt(z);

            } else {
            
                log((void*) &ERROR_LOG_LEVEL, "Could not create vector model. The vector does not contain a z coordinate.");
            }
            
        } else {
        
            log((void*) &ERROR_LOG_LEVEL, "Could not create vector model. The vector does not contain an y coordinate.");
        }
*/

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize vector model. The vector model is null.");
    }
}

/**
 * Finalizes the vector model.
 *
 * @param p0 the vector model
 * @param p1 the model source
 */
static void finalize_vector_model(void* p0, void* p1) {

    struct vector* m = (struct vector*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize vector model.");
        
        // Write output stream and transform from vector.
//??        fprintf(p1, %d, &(m->x));
//??        fprintf(p1, %d, &(m->y));
//??        fprintf(p1, %d, &(m->z));

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize vector model. The vector model is null.");
    }
}

