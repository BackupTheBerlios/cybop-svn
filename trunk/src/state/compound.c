/*
 * $RCSfile: compound.c,v $
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
 * This file handles a compound model which represents state or logic knowledge.
 *
 * A persistent compound model consists of:
 * - part name
 * - part abstraction
 * - part location
 * - part model (either inline or path to model at location)
 * - part constraint
 * - position abstraction
 * - position location
 * - position model (either inline or path to model at location)
 * - position constraint
 *
 * CYBOL Examples:
 * <part name="example_0" abstraction="compound" location="ftp" model="address,login,password,/test_compound.cybol"/>
 * <part name="example_1" abstraction="string" location="file" model="/test_string.txt"/>
 * <part name="example_2" abstraction="string" location="inline" model="This is a test string."/>
 * <part name="example_3" abstraction="integer" location="inline" model="5" constraint="minimum=1,maximum=10,area=1..10"/>
 *
 * A transient compound model keeps the following meta information about its parts:
 * - part model
 * - part abstraction
 * - part constraint
 * - position model
 * - position abstraction
 * - position constraint
 * The part/ position location is not stored as it is not needed at runtime.
 *
 * A compound is like a table, the first column (array) containing the part names
 * and the following columns (arrays) containing the meta information about the parts.
 * Model parts can such be accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * A compound model represents an abstract description of some real world item
 * in one of the physical measurements (dimensions):
 * - space
 * - time
 * - mass
 *
 * A compound model can be created by cloning an existing model template so that
 * some space gets allocated in the computer's memory.
 *
 * @version $Revision: 1.3 $ $Date: 2004-06-13 23:13:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_SOURCE
#define COMPOUND_SOURCE

#include "../array/array.c"
#include "../cybol/cybol.c"
#include "../global/constant.c"
#include "../logger/logger.c"

//
// Compound.
//

/**
 * Creates the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_COMPOUND_MESSAGE, (void*) &CREATE_COMPOUND_MESSAGE_COUNT);

    // Create compound.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);

    // Initialize part names, models, abstractions, constraints
    // and position models, abstractions, constraints
    // and their counts and sizes.
    void* pn = NULL_POINTER;
    void* pnc = NULL_POINTER;
    void* pns = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pcs = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* pomc = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poac = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* poc = NULL_POINTER;
    void* pocc = NULL_POINTER;
    void* pocs = NULL_POINTER;

    // Create part names, models, abstractions, constraints
    // and position models, abstractions, constraints
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

    // Set part names, models, abstractions, constraints
    // and position models, abstractions, constraints
    // and their counts and sizes.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);
}

/**
 * Destroys the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_compound(void* p0, const void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_COMPOUND_MESSAGE, (void*) &DESTROY_COMPOUND_MESSAGE_COUNT);

    // Initialize part names, models, abstractions, constraints
    // and position models, abstractions, constraints
    // and their counts and sizes.
    void* pn = NULL_POINTER;
    void* pnc = NULL_POINTER;
    void* pns = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pmc = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pac = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pc = NULL_POINTER;
    void* pcc = NULL_POINTER;
    void* pcs = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* pomc = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poac = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* poc = NULL_POINTER;
    void* pocc = NULL_POINTER;
    void* pocs = NULL_POINTER;

    // Get part names, models, abstractions, constraints
    // and position models, abstractions, constraints
    // and their counts and sizes.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

    //
    // Use descending order.
    //

    // Remove part names, models, abstractions, constraints
    // and position models, abstractions, constraints
    // and their counts and sizes.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_CONSTRAINTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &POSITION_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_CONSTRAINTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT, (void*) &PART_NAMES_INDEX);

    // Destroy part names, models, abstractions, constraints
    // and position models, abstractions, constraints
    // and their counts and sizes.
    destroy_array((void*) &pn, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pnc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pns, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pm, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pmc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pas, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pcc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pcs, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pom, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pomc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poms, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poa, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &poac, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poas, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &poc, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pocc, (void*) &INTEGER_ARRAY, p1);
    destroy_array((void*) &pocs, (void*) &INTEGER_ARRAY, p1);

    // Destroy compound.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &COMPOUND_COUNT);
}

//
// Forward declarations.
//
// These functions are the only forward declarations. They are needed because
// compounds can recursively create/ destroy other models.
//

/**
 * Creates a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the transient position model
 * @param p4 the transient position model count
 * @param p5 the transient position model size
 * @param p6 the persistent part abstraction
 * @param p7 the persistent part abstraction count
 * @param p8 the persistent part location
 * @param p9 the persistent part location count
 * @param p10 the persistent part model
 * @param p11 the persistent part model count
 * @param p12 the persistent position abstraction
 * @param p13 the persistent position abstraction count
 * @param p14 the persistent position location
 * @param p15 the persistent position location count
 * @param p16 the persistent position model
 * @param p17 the persistent position model count
 */
void create_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    const void* p6, const void* p7, const void* p8, const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14, const void* p15, const void* p16, const void* p17);

/**
 * Destroys a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the transient position model
 * @param p4 the transient position model count
 * @param p5 the transient position model size
 * @param p6 the persistent part abstraction
 * @param p7 the persistent part abstraction count
 * @param p8 the persistent part location
 * @param p9 the persistent part location count
 * @param p10 the persistent part model
 * @param p11 the persistent part model count
 * @param p12 the persistent position abstraction
 * @param p13 the persistent position abstraction count
 * @param p14 the persistent position location
 * @param p15 the persistent position location count
 * @param p16 the persistent position model
 * @param p17 the persistent position model count
 */
void destroy_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    const void* p6, const void* p7, const void* p8, const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14, const void* p15, const void* p16, const void* p17);

//
// Part.
//

/**
 * Initializes the part.
 *
 * @param p0 the memory model
 * @param p1 the cybol part attributes
 */
void initialize_part(void* p0, const void* p1) {

/*??
        void* name = (void*) get_map_element_with_name(p1, (void*) NAME);
        void* abstraction = NULL_POINTER;
        void* location = NULL_POINTER;
        // The model read as string from a cybol file.
        void* model = NULL_POINTER;
        // The model as stored in computer memory (RAM).
        void* part = NULL_POINTER;

        // Part.
        abstraction = (void*) get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        location = (void*) get_map_element_with_name(p1, (void*) PART_LOCATION);
        model = (void*) get_map_element_with_name(p1, (void*) PART_MODEL);
        part = (void*) create_model(model, location, abstraction);
        set_map_element_with_name(m->part_abstractions, name, abstraction);
        set_map_element_with_name(m->part_locations, name, location);
        set_map_element_with_name(m->part_models, name, part);

        // Position.
        abstraction = (void*) get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        location = (void*) get_map_element_with_name(p1, (void*) POSITION_LOCATION);
        model = (void*) get_map_element_with_name(p1, (void*) POSITION_MODEL);
        part = (void*) create_model(model, location, abstraction);
        set_map_element_with_name(m->position_abstractions, name, abstraction);
        set_map_element_with_name(m->position_locations, name, location);
        set_map_element_with_name(m->position_models, name, part);

        // Constraint.
        abstraction = (void*) get_map_element_with_name(p1, (void*) CONSTRAINT_ABSTRACTION);
        location = (void*) get_map_element_with_name(p1, (void*) CONSTRAINT_LOCATION);
        model = (void*) get_map_element_with_name(p1, (void*) CONSTRAINT_MODEL);
        part = (void*) create_model(model, location, abstraction);
        set_map_element_with_name(m->constraint_abstractions, name, abstraction);
        set_map_element_with_name(m->constraint_locations, name, location);
        set_map_element_with_name(m->constraint_models, name, part);
*/
}

/**
 * Finalizes the part.
 *
 * @param p0 the memory model
 * @param p1 the cybol part attributes
 */
void finalize_part(void* p0, const void* p1) {

/*??
        void* name = (void*) get_map_element_with_name(p1, (void*) NAME);
        void* abstraction = NULL_POINTER;
        void* location = NULL_POINTER;
        // The model read as string from a cybol file.
        void* model = NULL_POINTER;
        // The model as stored in computer memory (RAM).
        void* part = NULL_POINTER;

/*??
        // Position.
        memory_model = (void*) get_map_element_with_name(m->positions, name);
        model = (void*) get_map_element_with_name(p1, (void*) POSITION_MODEL);
        abstraction = (void*) get_map_element_with_name(p1, (void*) POSITION_ABSTRACTION);
        destroy_statics(memory_model, model, abstraction);

        // Part.
        abstraction = (void*) get_map_element_with_name(p1, (void*) PART_ABSTRACTION);
        location = (void*) get_map_element_with_name(p1, (void*) PART_LOCATION);
        model = (void*) get_map_element_with_name(p1, (void*) PART_MODEL);
        part = (void*) get_map_element_with_name(m->part_models, name);
        destroy_model(part, model, location, abstraction);
*/
}

//
// Parts.
//

/**
 * Initializes the parts.
 *
 * @param p0 the memory model
 * @param p1 the cybol parts
 */
void initialize_parts(void* p0, const void* p1) {

/*??
    struct map* m = (struct map*) p1;
    int count = 0;
    int size = 0;
    get_map_size(m, (void*) &size);
    struct model* e = NULL_POINTER;

    while (count < size) {

        e = (struct model*) get_map_element_at_index(m, (void*) &count);

        if (e != NULL_POINTER) {

            initialize_part(p0, e->part_models);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize parts. A cybol part is null.");
        }

        count++;
    }
*/
}

/**
 * Finalizes the parts.
 *
 * @param p0 the memory model
 * @param p1 the cybol parts
 */
void finalize_parts(void* p0, const void* p1) {

/*??
    struct map* m = (struct map*) p1;
    int count = 0;
    int size = 0;
    get_map_size(m, (void*) &size);
    struct model* e = NULL_POINTER;

    while (count < size) {

        e = (struct model*) get_map_element_at_index(m, (void*) &count);

        if (e != NULL_POINTER) {

            finalize_part(p0, e->part_models);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize parts. A cybol part is null.");
        }

        count++;
    }
*/
}

//
// Model.
//

/**
 * Initializes the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_compound(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Finalizes the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_compound(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {
}

//
// Compound part.
//

/**
 * Gets the compound part index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the part name
 * @param p3 the part name count
 * @param p4 the index
 */
void get_compound_part_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* nc0 = (int*) p3;

            if (p1 != NULL_POINTER) {

                int* cc = (int*) p1;

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &GET_COMPOUND_PART_INDEX_MESSAGE, (void*) &GET_COMPOUND_PART_INDEX_MESSAGE_COUNT);

                // Initialize part names and their counts.
                void* n = NULL_POINTER;
                void* nc = NULL_POINTER;

                // Get part names and their counts.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &n);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &nc);

                // The loop variable.
                int j = 0;
                // The name.
                void* n1 = NULL_POINTER;
                // The name count.
                int nc1 = 0;
                // The comparison result.
                int r = 0;

                while (1) {

                    if (j >= *cc) {

                        break;
                    }

                    // Get part name and its count.
                    get_array_element((void*) &n, (void*) &POINTER_ARRAY, (void*) &j, (void*) &n1);
                    get_array_element((void*) &nc, (void*) &POINTER_ARRAY, (void*) &j, (void*) &nc1);

                    if (*nc0 == nc1) {

                        compare_array_elements(p2, (void*) &n1, (void*) &CHARACTER_ARRAY, (void*) &nc1, (void*) &r);

                        if (r == 1) {

                            *i = j;

                            break;
                        }
                    }

                    // Reset name length.
                    nc1 = 0;

                    j++;
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_COMPOUND_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_COMPOUND_COUNT_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_INDEX_THE_NAME_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Returns the next index that can be used to set a map element.
 *
 * If an element with the given name is found, then its index will be returned
 * so that the element can be replaced.
 * If a 0 element is reached, then the corresponding index marks the next
 * available place and will be returned.
 * If neither an element matches nor a 0 element is reached, then the
 * map is full and its size will be returned as next available index.
 *
 * @param p0 the names array
 * @param p1 the name
 * @return the next index
 */
/*??
int get_next_map_element_index(const void* p0, const void* p1) {

    int index = INVALID_INDEX;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = NULL_POINTER;

    while (i < count) {

        name = get_array_element(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX);

        // If a name equal to the searched one is found,
        // then its index is the one to be returned
        // since this element will have to be replaced.
        if (strcmp((char*) name, (char*) p1) == 0) {

            index = i;

            break;
        }

        i++;
    }

    // Neither element matched. The next index will be the current element count.
    if (index == INVALID_INDEX) {

        index = count;
    }

    return index;
}

/**
 * Returns the number of map elements whose name starts with the given base name.
 *
 * @param p0 the names array
 * @param p1 the base name
 * @return the number of map elements whose name starts with the given base name
 */
/*??
int get_map_element_count(const void* p0, const void* p1) {

    int name_count = 0;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = NULL_POINTER;

    while (i < count) {

        name = get_array_element(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX);

        if (name != NULL_POINTER) {

            // Compares the current element's name with the searched base name.
            if (strncmp((char*) name, (char*) p1, strlen((char*) p1)) == 0) {

                char* suffix = strchr((char*) name, SEPARATION);
                char* check = strchr(suffix + 1, SEPARATION);

                // If no second separation is found, the name really matches.
                if (check == NULL_POINTER) {

                    int number = atoi(suffix + 1);

                    if (number > name_count) {

                        name_count = number;
                    }
                }
            }

        } else {

            // Reached last valid name. Only null entries left.
            break;
        }

        i++;
    }

    return name_count;
}

/** The separation. The ASCII code for "_" is 95. */
//??static const int SEPARATION = 95;

/**
 * Builds the next map element name.
 *
 * The given name is used as a word base for the new extended name.
 * Additionally, the new name will receive a number suffix.
 * It is determined by the current number of names containing the given
 * word base and finally increasing the highest index by one.
 *
 * @param p0 the names array
 * @param p1 the base name
 * @param p2 the extended name
 */
/*??
void build_next_map_element_name(const void* p0, const void* p1, void* p2) {

    int count = get_map_element_count(p0, p1);

    //?? It is unclear how to convert the integer into a string!
    //?? A simple cast does not work as it is only for ASCII code
    //?? but here a normal integer number is to be converted into a string.
    char suffix = (char) count;
    p2 = (void*) strcat((char*) p2, (char*) p1);
//??    char separation = (char) SEPARATION;
//?? Use SEPARATION instead of "_"!
    p2 = (void*) strcat((char*) p2, "_");
//??    p2 = (void*) strcat((char*) p2, &suffix);
    //?? Temporary solution adds "0" instead of real suffix.
    p2 = (void*) strcat((char*) p2, "0");
}

/**
 * Sets the compound part by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 * @param p4 the part name
 * @param p5 the part name count
 * @param p6 the part name size
 * @param p7 the part model
 * @param p8 the part model count
 * @param p9 the part model size
 * @param p10 the part abstraction
 * @param p11 the part abstraction count
 * @param p12 the part abstraction size
 * @param p13 the part constraint
 * @param p14 the part constraint count
 * @param p15 the part constraint size
 * @param p16 the position model
 * @param p17 the position model count
 * @param p18 the position model size
 * @param p19 the position abstraction
 * @param p20 the position abstraction count
 * @param p21 the position abstraction size
 * @param p22 the position constraint
 * @param p23 the position constraint count
 * @param p24 the position constraint size
 */
void set_compound_part_by_index(void* p0, void* p1, void* p2,
    const void* p3,
    const void* p4, const void* p5, const void* p6,
    const void* p7, const void* p8, const void* p9,
    const void* p10, const void* p11, const void* p12,
    const void* p13, const void* p14, const void* p15,
    const void* p16, const void* p17, const void* p18,
    const void* p19, const void* p20, const void* p21,
    const void* p22, const void* p23, const void* p24) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                if (*i >= 0) {

//??                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Set compound part by index.");

                    // Initialize part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    void* pn = NULL_POINTER;
                    void* pnc = NULL_POINTER;
                    void* pns = NULL_POINTER;
                    void* pm = NULL_POINTER;
                    void* pmc = NULL_POINTER;
                    void* pms = NULL_POINTER;
                    void* pa = NULL_POINTER;
                    void* pac = NULL_POINTER;
                    void* pas = NULL_POINTER;
                    void* pc = NULL_POINTER;
                    void* pcc = NULL_POINTER;
                    void* pcs = NULL_POINTER;
                    void* pom = NULL_POINTER;
                    void* pomc = NULL_POINTER;
                    void* poms = NULL_POINTER;
                    void* poa = NULL_POINTER;
                    void* poac = NULL_POINTER;
                    void* poas = NULL_POINTER;
                    void* poc = NULL_POINTER;
                    void* pocc = NULL_POINTER;
                    void* pocs = NULL_POINTER;

                    // Get part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

                    if (*i == *s) {

                        // Increase size.
                        *s = (*s * COMPOUND_RESIZE_FACTOR) + 1;

                        // Resize part names, models, abstractions, constraints
                        // and position models, abstractions, constraints
                        // and their counts and sizes.
                        resize_array((void*) &pn, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pnc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pns, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pm, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pmc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pms, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pa, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pac, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pas, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pc, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pcc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pcs, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pom, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pomc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poms, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poa, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &poac, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poas, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &poc, (void*) &POINTER_ARRAY, p2);
                        resize_array((void*) &pocc, (void*) &INTEGER_ARRAY, p2);
                        resize_array((void*) &pocs, (void*) &INTEGER_ARRAY, p2);
                    }

                    if (*i < *s) {

                        // Set part name, model, abstraction, constraint
                        // and position model, abstraction, constraint
                        // and their count and size.
                        // CAUTION! Only those parameters are set, which are not null.

                        if (p4 != NULL_POINTER) {

                            set_array_element((void*) &pn, (void*) &POINTER_ARRAY, p3, p4);
                        }

                        if (p5 != NULL_POINTER) {

                            set_array_element((void*) &pnc, (void*) &INTEGER_ARRAY, p3, p5);
                        }

                        if (p6 != NULL_POINTER) {

                            set_array_element((void*) &pns, (void*) &INTEGER_ARRAY, p3, p6);
                        }

                        if (p7 != NULL_POINTER) {

                            set_array_element((void*) &pm, (void*) &POINTER_ARRAY, p3, p7);
                        }

                        if (p8 != NULL_POINTER) {

                            set_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, p3, p8);
                        }

                        if (p9 != NULL_POINTER) {

                            set_array_element((void*) &pms, (void*) &INTEGER_ARRAY, p3, p9);
                        }

                        if (p10 != NULL_POINTER) {

                            set_array_element((void*) &pa, (void*) &POINTER_ARRAY, p3, p10);
                        }

                        if (p11 != NULL_POINTER) {

                            set_array_element((void*) &pac, (void*) &INTEGER_ARRAY, p3, p11);
                        }

                        if (p12 != NULL_POINTER) {

                            set_array_element((void*) &pas, (void*) &INTEGER_ARRAY, p3, p12);
                        }

                        if (p13 != NULL_POINTER) {

                            set_array_element((void*) &pc, (void*) &POINTER_ARRAY, p3, p13);
                        }

                        if (p14 != NULL_POINTER) {

                            set_array_element((void*) &pcc, (void*) &INTEGER_ARRAY, p3, p14);
                        }

                        if (p15 != NULL_POINTER) {

                            set_array_element((void*) &pcs, (void*) &INTEGER_ARRAY, p3, p15);
                        }

                        if (p16 != NULL_POINTER) {

                            set_array_element((void*) &pom, (void*) &POINTER_ARRAY, p3, p16);
                        }

                        if (p17 != NULL_POINTER) {

                            set_array_element((void*) &pomc, (void*) &INTEGER_ARRAY, p3, p17);
                        }

                        if (p18 != NULL_POINTER) {

                            set_array_element((void*) &poms, (void*) &INTEGER_ARRAY, p3, p18);
                        }

                        if (p19 != NULL_POINTER) {

                            set_array_element((void*) &poa, (void*) &POINTER_ARRAY, p3, p19);
                        }

                        if (p20 != NULL_POINTER) {

                            set_array_element((void*) &poac, (void*) &INTEGER_ARRAY, p3, p20);
                        }

                        if (p21 != NULL_POINTER) {

                            set_array_element((void*) &poas, (void*) &INTEGER_ARRAY, p3, p21);
                        }

                        if (p22 != NULL_POINTER) {

                            set_array_element((void*) &poc, (void*) &POINTER_ARRAY, p3, p22);
                        }

                        if (p23 != NULL_POINTER) {

                            set_array_element((void*) &pocc, (void*) &INTEGER_ARRAY, p3, p23);
                        }

                        if (p24 != NULL_POINTER) {

                            set_array_element((void*) &pocs, (void*) &INTEGER_ARRAY, p3, p24);
                        }

                        // Increment count.
                        (*c)++;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index exceeds the size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by index. The index is null.");
    }
}

/**
 * Sets the compound part by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the part name
 * @param p4 the part name count
 * @param p5 the part name size
 * @param p6 the part model
 * @param p7 the part model count
 * @param p8 the part model size
 * @param p9 the part abstraction
 * @param p10 the part abstraction count
 * @param p11 the part abstraction size
 * @param p12 the part constraint
 * @param p13 the part constraint count
 * @param p14 the part constraint size
 * @param p15 the position model
 * @param p16 the position model count
 * @param p17 the position model size
 * @param p18 the position abstraction
 * @param p19 the position abstraction count
 * @param p20 the position abstraction size
 * @param p21 the position constraint
 * @param p22 the position constraint count
 * @param p23 the position constraint size
 */
void set_compound_part_by_name(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5,
    const void* p6, const void* p7, const void* p8,
    const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14,
    const void* p15, const void* p16, const void* p17,
    const void* p18, const void* p19, const void* p20,
    const void* p21, const void* p22, const void* p23) {

    // The separator index.
    int i = -1;

    get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &COMPOUND_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains parts which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** n = (void**) p3;

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Initialize part models and their counts and sizes.
                                void* m = NULL_POINTER;
                                int mc = 0;
                                int ms = 0;

                                // Get part models and their counts and sizes.
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &m);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &mc);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &ms);

                                // Get index of part name.
                                // The separator index i is used as part name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_compound_part_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Initialize part model and its count and size.
                                    void* pm = NULL_POINTER;
                                    int pmc = 0;
                                    int pms = 0;

                                    // Get part model and its count and size.
                                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &index, (void*) &pm);
                                    get_array_element((void*) &mc, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pmc);
                                    get_array_element((void*) &ms, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pms);

                                    //?? TODO:
                                    //?? For now, the remaining name count is also used as
                                    //?? remaining name size and such handed over twice.
                                    //?? Later implementations may use UNICODE names so that
                                    //?? the name count and size differ.

                                    // Recursively continue to process along the hierarchical name.
                                    set_compound_part_by_name((void*) &pm, (void*) &pmc, (void*) &pms,
                                        (void*) &r, (void*) &rc, (void*) &rc,
                                        p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                        p15, p16, p17, p18, p19, p20, p21, p22, p23);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not set compound part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The separator index exceeds the full name count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set compound part by name. The name count is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given compound contains parts which are primitive models.

        // The index of the part name.
        int index = -1;
        get_compound_part_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &SET_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &SET_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            //?? TODO:
            //?? - Do NOT just replace existing parts, otherwise the reference to
            //??   them is lost and they can not be destroyed properly.
            //?? - Allow replacement for primitive types (integer, double) that
            //??   do not have to be destroyed!
            //?? - Check the abstraction of the model to be set:
            //??   If it is compound, then do NOT replace; otherwise DO replace!

/*??
            // Use index of the found element.
            set_compound_part_by_index(p0, p1, p2,
                (void*) &index,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20, p21, p22, p23);
*/

        } else {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &ADD_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &ADD_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            // Use compound count as index.
            set_compound_part_by_index(p0, p1, p2,
                p1,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20, p21, p22, p23);
        }
    }
}

/**
 * Adds the compound part.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the reference
 * @param p4 the reference size
 */
void add_compound_part(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

/*??
    // This element name will get destroyed (free) in remove_map_element.
    void* n = malloc(0);

    // Extend name with next free index.
    build_next_map_element_name(m->names, p1, n);
    set_map_element_with_name(p0, n, p3);

    int i = -1;

    get_map_size(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX);

    if (i != -1) {

        set_map_element_at_index(p0, (void*) &PART_NAMES_COUNTS_ARRAY_INDEX, p1, p3);
    }
*/
}

/**
 * Removes the compound part by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 */
void remove_compound_part_by_index(void* p0, void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                if (*i >= 0) {

//??                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Remove compound part by index.");

                    // Initialize part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    void* pn = NULL_POINTER;
                    void* pnc = NULL_POINTER;
                    void* pns = NULL_POINTER;
                    void* pm = NULL_POINTER;
                    void* pmc = NULL_POINTER;
                    void* pms = NULL_POINTER;
                    void* pa = NULL_POINTER;
                    void* pac = NULL_POINTER;
                    void* pas = NULL_POINTER;
                    void* pc = NULL_POINTER;
                    void* pcc = NULL_POINTER;
                    void* pcs = NULL_POINTER;
                    void* pom = NULL_POINTER;
                    void* pomc = NULL_POINTER;
                    void* poms = NULL_POINTER;
                    void* poa = NULL_POINTER;
                    void* poac = NULL_POINTER;
                    void* poas = NULL_POINTER;
                    void* poc = NULL_POINTER;
                    void* pocc = NULL_POINTER;
                    void* pocs = NULL_POINTER;

                    // Get part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

                    if (*i < *c) {

                        // Remove part name, model, abstraction, constraint
                        // and position model, abstraction, constraint
                        // and their count and size.
                        remove_array_element((void*) &pn, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pnc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pns, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pm, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pms, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pa, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pac, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pas, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pc, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pcc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pcs, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pom, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pomc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poms, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poa, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &poac, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poas, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &poc, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &pocc, (void*) &INTEGER_ARRAY, p1, p3);
                        remove_array_element((void*) &pocs, (void*) &INTEGER_ARRAY, p1, p3);

                        // Decrement count.
                        (*c)--;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The index exceeds the count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by index. The index is null.");
    }
}

/**
 * Removes the compound part by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the part name
 * @param p4 the part name count
 * @param p5 the part name size
 */
void remove_compound_part_by_name(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5) {

    // The separator index.
    int i = -1;

    get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &COMPOUND_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains parts which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** n = (void**) p3;

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Initialize part models and their counts and sizes.
                                void* m = NULL_POINTER;
                                int mc = 0;
                                int ms = 0;

                                // Get part models and their counts and sizes.
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &m);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &mc);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &ms);

                                // Get index of part name.
                                // The separator index i is used as part name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_compound_part_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Initialize part model and its count and size.
                                    void* pm = NULL_POINTER;
                                    int pmc = 0;
                                    int pms = 0;

                                    // Get part model and its count and size.
                                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &index, (void*) &pm);
                                    get_array_element((void*) &mc, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pmc);
                                    get_array_element((void*) &ms, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pms);

                                    //?? TODO:
                                    //?? For now, the remaining name count is also used as
                                    //?? remaining name size and such handed over twice.
                                    //?? Later implementations may use UNICODE names so that
                                    //?? the name count and size differ.

                                    // Recursively continue to process along the hierarchical name.
                                    remove_compound_part_by_name((void*) &pm, (void*) &pmc, (void*) &pms,
                                        (void*) &r, (void*) &rc, (void*) &rc);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not remove compound part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove compound part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given compound contains parts which are primitive models.

        // The index of the part name.
        int index = -1;
        get_compound_part_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &REMOVE_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &REMOVE_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            remove_compound_part_by_index(p0, p1, p2, (void*) &index);

        } else {

//??            log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_REMOVE_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE, (void*) &COULD_NOT_REMOVE_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE_COUNT);
        }
    }
}

/**
 * Gets the compound part by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 * @param p4 the part name
 * @param p5 the part name count
 * @param p6 the part name size
 * @param p7 the part model
 * @param p8 the part model count
 * @param p9 the part model size
 * @param p10 the part abstraction
 * @param p11 the part abstraction count
 * @param p12 the part abstraction size
 * @param p13 the part constraint
 * @param p14 the part constraint count
 * @param p15 the part constraint size
 * @param p16 the position model
 * @param p17 the position model count
 * @param p18 the position model size
 * @param p19 the position abstraction
 * @param p20 the position abstraction count
 * @param p21 the position abstraction size
 * @param p22 the position constraint
 * @param p23 the position constraint count
 * @param p24 the position constraint size
 */
void get_compound_part_by_index(const void* p0, const void* p1, const void* p2,
    const void* p3,
    void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12,
    void* p13, void* p14, void* p15,
    void* p16, void* p17, void* p18,
    void* p19, void* p20, void* p21,
    void* p22, void* p23, void* p24) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                if (*i >= 0) {

//??                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Get compound part by index.");

                    // Initialize part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    void* pn = NULL_POINTER;
                    void* pnc = NULL_POINTER;
                    void* pns = NULL_POINTER;
                    void* pm = NULL_POINTER;
                    void* pmc = NULL_POINTER;
                    void* pms = NULL_POINTER;
                    void* pa = NULL_POINTER;
                    void* pac = NULL_POINTER;
                    void* pas = NULL_POINTER;
                    void* pc = NULL_POINTER;
                    void* pcc = NULL_POINTER;
                    void* pcs = NULL_POINTER;
                    void* pom = NULL_POINTER;
                    void* pomc = NULL_POINTER;
                    void* poms = NULL_POINTER;
                    void* poa = NULL_POINTER;
                    void* poac = NULL_POINTER;
                    void* poas = NULL_POINTER;
                    void* poc = NULL_POINTER;
                    void* pocc = NULL_POINTER;
                    void* pocs = NULL_POINTER;

                    // Get part names, models, abstractions, constraints
                    // and position models, abstractions, constraints
                    // and their counts and sizes.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_INDEX, (void*) &pn);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_COUNTS_INDEX, (void*) &pnc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_NAMES_SIZES_INDEX, (void*) &pns);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &pms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_SIZES_INDEX, (void*) &pas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_INDEX, (void*) &pc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_COUNTS_INDEX, (void*) &pcc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_CONSTRAINTS_SIZES_INDEX, (void*) &pcs);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &pomc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_SIZES_INDEX, (void*) &poms);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_SIZES_INDEX, (void*) &poas);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_INDEX, (void*) &poc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_COUNTS_INDEX, (void*) &pocc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_CONSTRAINTS_SIZES_INDEX, (void*) &pocs);

                    if (*i < *c) {

                        // Get part name, model, abstraction, constraint
                        // and position model, abstraction, constraint
                        // and their count and size.
                        // CAUTION! Only those parameters are got, which are not null.

                        if (p4 != NULL_POINTER) {

                            get_array_element((void*) &pn, (void*) &POINTER_ARRAY, p3, p4);
                        }

                        if (p5 != NULL_POINTER) {

                            get_array_element((void*) &pnc, (void*) &INTEGER_ARRAY, p3, p5);
                        }

                        if (p6 != NULL_POINTER) {

                            get_array_element((void*) &pns, (void*) &INTEGER_ARRAY, p3, p6);
                        }

                        if (p7 != NULL_POINTER) {

                            get_array_element((void*) &pm, (void*) &POINTER_ARRAY, p3, p7);
                        }

                        if (p8 != NULL_POINTER) {

                            get_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, p3, p8);
                        }

                        if (p9 != NULL_POINTER) {

                            get_array_element((void*) &pms, (void*) &INTEGER_ARRAY, p3, p9);
                        }

                        if (p10 != NULL_POINTER) {

                            get_array_element((void*) &pa, (void*) &POINTER_ARRAY, p3, p10);
                        }

                        if (p11 != NULL_POINTER) {

                            get_array_element((void*) &pac, (void*) &INTEGER_ARRAY, p3, p11);
                        }

                        if (p12 != NULL_POINTER) {

                            get_array_element((void*) &pas, (void*) &INTEGER_ARRAY, p3, p12);
                        }

                        if (p13 != NULL_POINTER) {

                            get_array_element((void*) &pc, (void*) &POINTER_ARRAY, p3, p13);
                        }

                        if (p14 != NULL_POINTER) {

                            get_array_element((void*) &pcc, (void*) &INTEGER_ARRAY, p3, p14);
                        }

                        if (p15 != NULL_POINTER) {

                            get_array_element((void*) &pcs, (void*) &INTEGER_ARRAY, p3, p15);
                        }

                        if (p16 != NULL_POINTER) {

                            get_array_element((void*) &pom, (void*) &POINTER_ARRAY, p3, p16);
                        }

                        if (p17 != NULL_POINTER) {

                            get_array_element((void*) &pomc, (void*) &INTEGER_ARRAY, p3, p17);
                        }

                        if (p18 != NULL_POINTER) {

                            get_array_element((void*) &poms, (void*) &INTEGER_ARRAY, p3, p18);
                        }

                        if (p19 != NULL_POINTER) {

                            get_array_element((void*) &poa, (void*) &POINTER_ARRAY, p3, p19);
                        }

                        if (p20 != NULL_POINTER) {

                            get_array_element((void*) &poac, (void*) &INTEGER_ARRAY, p3, p20);
                        }

                        if (p21 != NULL_POINTER) {

                            get_array_element((void*) &poas, (void*) &INTEGER_ARRAY, p3, p21);
                        }

                        if (p22 != NULL_POINTER) {

                            get_array_element((void*) &poc, (void*) &POINTER_ARRAY, p3, p22);
                        }

                        if (p23 != NULL_POINTER) {

                            get_array_element((void*) &pocc, (void*) &INTEGER_ARRAY, p3, p23);
                        }

                        if (p24 != NULL_POINTER) {

                            get_array_element((void*) &pocs, (void*) &INTEGER_ARRAY, p3, p24);
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The index exceeds the count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by index. The index is null.");
    }
}

/**
 * Gets the compound part by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the part name
 * @param p4 the part name count
 * @param p5 the part name size
 * @param p6 the part model
 * @param p7 the part model count
 * @param p8 the part model size
 * @param p9 the part abstraction
 * @param p10 the part abstraction count
 * @param p11 the part abstraction size
 * @param p12 the part constraint
 * @param p13 the part constraint count
 * @param p14 the part constraint size
 * @param p15 the position model
 * @param p16 the position model count
 * @param p17 the position model size
 * @param p18 the position abstraction
 * @param p19 the position abstraction count
 * @param p20 the position abstraction size
 * @param p21 the position constraint
 * @param p22 the position constraint count
 * @param p23 the position constraint size
 */
void get_compound_part_by_name(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14,
    void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20,
    void* p21, void* p22, void* p23) {

    // The separator index.
    int i = -1;

    get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &COMPOUND_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains parts which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** n = (void**) p3;

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Initialize part models and their counts and sizes.
                                void* m = NULL_POINTER;
                                int mc = 0;
                                int ms = 0;

                                // Get part models and their counts and sizes.
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &m);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &mc);
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_SIZES_INDEX, (void*) &ms);

                                // Get index of part name.
                                // The separator index i is used as part name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_compound_part_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Initialize part model and its count and size.
                                    void* pm = NULL_POINTER;
                                    int pmc = 0;
                                    int pms = 0;

                                    // Get part model and its count and size.
                                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &index, (void*) &pm);
                                    get_array_element((void*) &mc, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pmc);
                                    get_array_element((void*) &ms, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &pms);

                                    //?? TODO:
                                    //?? For now, the remaining name count is also used as
                                    //?? remaining name size and such handed over twice.
                                    //?? Later implementations may use UNICODE names so that
                                    //?? the name count and size differ.

                                    // Recursively continue to process along the hierarchical name.
                                    get_compound_part_by_name((void*) &pm, (void*) &pmc, (void*) &pms,
                                        (void*) &r, (void*) &rc, (void*) &rc,
                                        p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                        p15, p16, p17, p18, p19, p20, p21, p22, p23);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not get compound part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get compound part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given compound contains parts which are primitive models.

        // The index of the part name.
        int index = -1;
        get_compound_part_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &GET_COMPOUND_PART_BY_NAME_MESSAGE, (void*) &GET_COMPOUND_PART_BY_NAME_MESSAGE_COUNT);

            get_compound_part_by_index(p0, p1, p2,
                (void*) &index,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20, p21, p22, p23);

        } else {

//??            log_message((void*) &WARNING_LOG_LEVEL, (void*) &COULD_NOT_GET_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE, (void*) &COULD_NOT_GET_COMPOUND_PART_BY_NAME_A_PART_WITH_THAT_NAME_DOES_NOT_EXIST_MESSAGE_COUNT);
        }
    }
}

/* COMPOUND_SOURCE */
#endif
