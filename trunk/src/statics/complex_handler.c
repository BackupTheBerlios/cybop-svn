/*
 * $RCSfile: complex_handler.c,v $
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
 * This file handles a complex.
 *
 * A complex consists of two floats, a real and an imaginary.
 *
 * @version $Revision: 1.12 $ $Date: 2004-04-21 11:02:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPLEX_HANDLER_SOURCE
#define COMPLEX_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"
#include "../model/array_handler.c"

//
// Constants.
//

/** The complex size. */
static const int COMPLEX_SIZE = 2;

/** The real index. */
static const int REAL_INDEX = 0;

/** The imaginary index. */
static const int IMAGINARY_INDEX = 1;

//
// Complex.
//

/**
 * Creates the complex.
 *
 * @param p0 the transient model
 */
void create_complex(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Create complex.");

    // The complex.
    create_array(p0, (void*) &COMPLEX_SIZE);
}

/**
 * Destroys the complex.
 *
 * @param p0 the transient model
 */
void destroy_complex(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy complex.");

    // The complex.
    destroy_array(p0, (void*) &COMPLEX_SIZE);
}

/**
 * Initializes the complex.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void initialize_complex(void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Initialize complex.");

//??    fscanf(p1, %d, (void*) &(t->real));
//??    fscanf(p1, %d, (void*) &(t->imaginary));

    // Initialize elements.
    int i = 0;
    int r = 0;

    // Set elements.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &REAL_INDEX, (void*) &r);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
}

/**
 * Finalizes the complex model.
 *
 * @param p0 the transient model
 * @param p1 the persistent model
 * @param p2 the persistent model size
 */
void finalize_complex(void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Finalize complex.");

    // Initialize elements.
    int i = 0;
    int r = 0;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &REAL_INDEX, (void*) &r);

    // Remove elements.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &COMPLEX_SIZE, (void*) &IMAGINARY_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &COMPLEX_SIZE, (void*) &REAL_INDEX);

//??    fprintf(p1, %d, (void*) &(t->real));
//??    fprintf(p1, %d, (void*) &(t->imaginary));
}

/* COMPLEX_HANDLER_SOURCE */
#endif
