/*
 * $RCSfile: vector_handler.c,v $
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
 * This file handles a vector.
 *
 * A vector contains the three coordinates: x, y, z.
 *
 * @version $Revision: 1.11 $ $Date: 2004-04-06 13:50:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VECTOR_HANDLER_SOURCE
#define VECTOR_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"

//
// Constants.
//

/** The vector size. */
static const int VECTOR_SIZE = 3;

/** The x index. */
static const int X_INDEX = 0;

/** The y index. */
static const int Y_INDEX = 1;

/** The z index. */
static const int Z_INDEX = 2;

//
// Vector.
//

/**
 * Creates the vector.
 *
 * @param p0 the transient model
 */
void create_vector(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Create vector.");

    // The vector.
    create_array(p0, (void*) &VECTOR_SIZE);
}

/**
 * Destroys the vector.
 *
 * @param p0 the transient model
 */
void destroy_vector(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy vector.");

    // The vector.
    destroy_array(p0, (void*) &VECTOR_SIZE);
}

/**
 * Initializes the vector.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void initialize_vector(void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Initialize vector.");

    // Read input stream and transform to vector.
//??    fscanf(p1, %d, &(m->x));
//??    fscanf(p1, %d, &(m->y));
//??    fscanf(p1, %d, &(m->z));

    // The x.
    int x = 0;
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);

    // The y.
    int y = 0;
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);

    // The z.
    int z = 0;
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);

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

            log_message((void*) &ERROR_LOG_LEVEL, "Could not create vector. The vector does not contain a z coordinate.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not create vector. The vector does not contain an y coordinate.");
    }
*/
}

/**
 * Finalizes the vector.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_vector(const void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Finalize vector.");

    // Write output stream and transform from vector.

    // The z.
    int z = 0;
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Z_INDEX, (void*) &z);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &VECTOR_SIZE, (void*) &Z_INDEX);

    // The y.
    int y = 0;
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &Y_INDEX, (void*) &y);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &VECTOR_SIZE, (void*) &Y_INDEX);

    // The x.
    int x = 0;
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &X_INDEX, (void*) &x);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &VECTOR_SIZE, (void*) &X_INDEX);

//??    fprintf(p1, %d, &(m->x));
//??    fprintf(p1, %d, &(m->y));
//??    fprintf(p1, %d, &(m->z));
}

/* VECTOR_HANDLER_SOURCE */
#endif
