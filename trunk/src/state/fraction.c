/*
 * $RCSfile: fraction.c,v $
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
 * This file handles a fraction.
 *
 * A fraction consists of two integers, a numerator and a denominator.
 *
 * For higher performance, it is mostly better to use floating point numbers
 * (float) which can be calculated by the Arithmetic Logic Unit (ALU).
 *
 * @version $Revision: 1.4 $ $Date: 2004-06-18 22:55:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FRACTION_SOURCE
#define FRACTION_SOURCE

#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Creates the fraction.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_fraction(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Create fraction.");

    // The fraction.
    create_array(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT);
}

/**
 * Destroys the fraction.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_fraction(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy fraction.");

    // The fraction.
    destroy_array(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT);
}

/**
 * Initializes the fraction.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_fraction(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize fraction.");

//??    sscanf(p1, %l, (void*) &(m->value));

    // Initialize elements.
    int d = 0;
    int n = 0;

    // Set elements.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &NUMERATOR_INDEX, (void*) &n);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DENOMINATOR_INDEX, (void*) &d);
}

/**
 * Finalizes the fraction.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_fraction(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize fraction.");

    // Initialize elements.
    int d = 0;
    int n = 0;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &DENOMINATOR_INDEX, (void*) &d);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &NUMERATOR_INDEX, (void*) &n);

    // Remove elements.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT, (void*) &DENOMINATOR_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &FRACTION_COUNT, (void*) &NUMERATOR_INDEX);

//??    sprintf(p1, %l, (void*) &(m->value));
}

/* FRACTION_SOURCE */
#endif
