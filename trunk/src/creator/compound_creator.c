/*
 * $RCSfile: compound_creator.c,v $
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
 * This file contains the functionality to:
 * - create a compound model in memory
 *
 * @version $Revision: 1.2 $ $Date: 2004-09-08 19:44:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_CREATOR_SOURCE
#define COMPOUND_CREATOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the compound.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void create_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_COMPOUND_MESSAGE, (void*) &CREATE_COMPOUND_MESSAGE_COUNT);

    // Create compound.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);

    // The names, abstractions, models, details.
    void* n = NULL_POINTER;
    void* nc = NULL_POINTER;
    void* ns = NULL_POINTER;
    void* a = NULL_POINTER;
    void* ac = NULL_POINTER;
    void* as = NULL_POINTER;
    void* m = NULL_POINTER;
    void* mc = NULL_POINTER;
    void* ms = NULL_POINTER;
    void* d = NULL_POINTER;
    void* dc = NULL_POINTER;
    void* ds = NULL_POINTER;

    // Create names, abstractions, models, details.
    create_array((void*) &n, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &nc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &ns, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &a, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &ac, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &as, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &m, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &mc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &ms, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &d, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &dc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &ds, (void*) &INTEGER_ARRAY, p1);

    //
    // Use ascending order.
    //

    // Set names, abstractions, models, details.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &nc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_SIZES_INDEX, (void*) &ns);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_INDEX, (void*) &m);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_COUNTS_INDEX, (void*) &mc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_SIZES_INDEX, (void*) &ms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_INDEX, (void*) &d);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_COUNTS_INDEX, (void*) &dc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_SIZES_INDEX, (void*) &ds);
}

/**
 * Destroys the compound.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void destroy_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_COMPOUND_MESSAGE, (void*) &DESTROY_COMPOUND_MESSAGE_COUNT);

    // The names, abstractions, models, details.
    void* n = NULL_POINTER;
    void* nc = NULL_POINTER;
    void* ns = NULL_POINTER;
    void* a = NULL_POINTER;
    void* ac = NULL_POINTER;
    void* as = NULL_POINTER;
    void* m = NULL_POINTER;
    void* mc = NULL_POINTER;
    void* ms = NULL_POINTER;
    void* d = NULL_POINTER;
    void* dc = NULL_POINTER;
    void* ds = NULL_POINTER;

    // Get names, abstractions, models, details.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &nc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_SIZES_INDEX, (void*) &ns);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_INDEX, (void*) &a);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_INDEX, (void*) &as);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_INDEX, (void*) &m);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_COUNTS_INDEX, (void*) &mc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODELS_SIZES_INDEX, (void*) &ms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_INDEX, (void*) &d);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_COUNTS_INDEX, (void*) &dc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &DETAILS_SIZES_INDEX, (void*) &ds);

    //
    // Use descending order.
    //

    // Remove names, abstractions, models, details.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &DETAILS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &DETAILS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &DETAILS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &NAMES_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &NAMES_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &NAMES_INDEX);

    // Destroy names, abstractions, models, details.
    destroy_array((void*) &n, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &nc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &ns, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &a, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &ac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &as, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &m, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &mc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &ms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &d, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &dc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &ds, (void*) &INTEGER_ARRAY, p1);

    // Destroy compound.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);
}

/* COMPOUND_CREATOR_SOURCE */
#endif
