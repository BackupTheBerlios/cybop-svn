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
 * @version $Revision: 1.1 $ $Date: 2004-08-15 22:11:29 $ $Author: christian $
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

    // Initialize part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    void* pn = NULL_POINTER;
    void* pnc = NULL_POINTER;
    void* pns = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pcs = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poac = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* pomc = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* poc = NULL_POINTER;
    void* pocc = NULL_POINTER;
    void* pocs = NULL_POINTER;

    // Create part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    create_array((void*) &pn, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pnc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pns, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pm, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pmc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pms, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pa, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pac, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pas, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pc, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pcc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pcs, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pom, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pomc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poms, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poa, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &poac, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poas, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &poc, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pocc, (void*) &INTEGER_ARRAY, p1);
    create_array((void*) &pocs, (void*) &INTEGER_ARRAY, p1);

    //
    // Use ascending order.
    //

    // Set part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);
}

/**
 * Destroys the compound.
 *
 * @param p0 the model
 * @param p1 the model size
 */
void destroy_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_COMPOUND_MESSAGE, (void*) &DESTROY_COMPOUND_MESSAGE_COUNT);

    // Initialize part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    void* pn = NULL_POINTER;
    void* pnc = NULL_POINTER;
    void* pns = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pcs = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poac = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* pomc = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* poc = NULL_POINTER;
    void* pocc = NULL_POINTER;
    void* pocs = NULL_POINTER;

    // Get part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

    //
    // Use descending order.
    //

    // Remove part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_INDEX);

    // Destroy part names, abstractions, models, constraints
    // and position abstractions, models, constraints
    // and their counts and sizes.
    destroy_array((void*) &pn, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pnc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pns, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pas, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pm, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pmc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pcc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pcs, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &poac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poas, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pom, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pomc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pocc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pocs, (void*) &INTEGER_ARRAY, p1);

    // Destroy compound.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);
}

/* COMPOUND_CREATOR_SOURCE */
#endif
