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
 * This file handles a model which represents statics or dynamics.
 *
 * A persistent compound model part consists of a location and a path:
 * model="location:path"
 *
 * CYBOL Examples:
 * <part name="x" part_abstraction="compound" part_model="ftp://test_compound.cybol"/>
 * <part name="y" part_abstraction="string" part_model="file:/test_string.txt"/>
 * <part name="z" part_abstraction="string" part_model="inline:/This is a test string."/>
 *
 * A transient compound model keeps the following meta information about its parts:
 * - part abstraction
 * - part location
 * - part model
 * - position abstraction
 * - position location
 * - position model
 * - constraint abstraction
 * - constraint location
 * - constraint model
 *
 * A model is like a table, the first column (array) containing the part names
 * and the following columns (arrays) containing the meta information about the parts.
 * Model parts can such be accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * A model represents an abstract description of some real world item
 * in one of the physical measurements (dimensions):
 * - space
 * - time
 * - mass
 *
 * A model can be created by cloning an existing model so that
 * some place gets allocated in the computer's memory.
 * Basically, every model can become a template itself,
 * if copies (other instances) of this model are created.
 *
 * @version $Revision: 1.5 $ $Date: 2004-05-27 13:52:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_SOURCE
#define COMPOUND_SOURCE

#include "../array/array.c"
#include "../constants/constants.c"
#include "../cybol/cybol.c"
#include "../logger/logger.c"

//
// Model.
//

/**
 * Creates the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 */
void create_compound(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Create compound.");

    // Create model.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT);

    // Initialize elements.
    int s = 0;
    int c = 0;
    void* n = NULL_POINTER;
    void* ns = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pl = NULL_POINTER;
    void* pls = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* pol = NULL_POINTER;
    void* pols = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* ca = NULL_POINTER;
    void* cas = NULL_POINTER;
    void* cl = NULL_POINTER;
    void* cls = NULL_POINTER;
    void* cm = NULL_POINTER;
    void* cms = NULL_POINTER;

    // Create elements.
    create_array((void*) &n, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &ns, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &pa, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &pl, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &pls, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &pm, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &pms, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &poa, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &poas, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &pol, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &pols, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &pom, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &poms, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &ca, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &cas, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &cl, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &cls, (void*) &INTEGER_ARRAY, (void*) &c);
    create_array((void*) &cm, (void*) &POINTER_ARRAY, (void*) &c);
    create_array((void*) &cms, (void*) &INTEGER_ARRAY, (void*) &c);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_SIZE_INDEX, (void*) &s);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &ns);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_INDEX, (void*) &pl);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_COUNTS_INDEX, (void*) &pls);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_INDEX, (void*) &pol);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_COUNTS_INDEX, (void*) &pols);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &poms);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_INDEX, (void*) &ca);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX, (void*) &cas);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_INDEX, (void*) &cl);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_COUNTS_INDEX, (void*) &cls);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_INDEX, (void*) &cm);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_COUNTS_INDEX, (void*) &cms);
}

/**
 * Destroys the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 */
void destroy_compound(void* p0, void* p1) {

//??    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy compound.");

    // Initialize elements.
    int s = 0;
    int c = 0;
    void* n = NULL_POINTER;
    void* ns = NULL_POINTER;
    void* pa = NULL_POINTER;
    void* pas = NULL_POINTER;
    void* pl = NULL_POINTER;
    void* pls = NULL_POINTER;
    void* pm = NULL_POINTER;
    void* pms = NULL_POINTER;
    void* poa = NULL_POINTER;
    void* poas = NULL_POINTER;
    void* pol = NULL_POINTER;
    void* pols = NULL_POINTER;
    void* pom = NULL_POINTER;
    void* poms = NULL_POINTER;
    void* ca = NULL_POINTER;
    void* cas = NULL_POINTER;
    void* cl = NULL_POINTER;
    void* cls = NULL_POINTER;
    void* cm = NULL_POINTER;
    void* cms = NULL_POINTER;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &ns);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_INDEX, (void*) &pl);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_COUNTS_INDEX, (void*) &pls);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_INDEX, (void*) &pol);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_COUNTS_INDEX, (void*) &pols);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &poms);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_INDEX, (void*) &ca);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX, (void*) &cas);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_INDEX, (void*) &cl);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_COUNTS_INDEX, (void*) &cls);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_INDEX, (void*) &cm);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_COUNTS_INDEX, (void*) &cms);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &CONSTRAINT_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &CONSTRAINT_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &CONSTRAINT_LOCATIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &CONSTRAINT_LOCATIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &CONSTRAINT_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &POSITION_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &POSITION_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &POSITION_LOCATIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &POSITION_LOCATIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &POSITION_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &PART_MODELS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &PART_MODELS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &PART_LOCATIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &PART_LOCATIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &PART_ABSTRACTIONS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &NAMES_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT, (void*) &NAMES_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &MODEL_COUNT, (void*) &PARTS_COUNT_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &MODEL_COUNT, (void*) &PARTS_SIZE_INDEX);

    // Destroy elements.
    destroy_array((void*) &n, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &ns, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &pa, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &pl, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &pls, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &pm, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &pms, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &poa, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &poas, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &pol, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &pols, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &pom, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &poms, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &ca, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &cas, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &cl, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &cls, (void*) &INTEGER_ARRAY, (void*) &c);
    destroy_array((void*) &cm, (void*) &POINTER_ARRAY, (void*) &c);
    destroy_array((void*) &cms, (void*) &INTEGER_ARRAY, (void*) &c);

    // Destroy model.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &MODEL_COUNT);
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
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 * @param p4 the abstraction
 * @param p5 the abstraction size
 * @param p6 the location
 * @param p7 the location size
 */
void create_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6, const void* p7);

/**
 * Destroys a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 * @param p4 the abstraction
 * @param p5 the abstraction size
 * @param p6 the location
 * @param p7 the location size
 */
void destroy_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6, const void* p7);

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
 * @param p2 the persistent model
 * @param p3 the persistent model count
 */
void initialize_compound(void* p0, void* p1, const void* p2, const void* p3) {
}

/**
 * Finalizes the compound.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 */
void finalize_compound(const void* p0, const void* p1, void* p2, void* p3) {
}

//
// Model part.
//

/**
 * Gets the model part index.
 *
 * @param p0 the model
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the index
 */
void get_model_part_index(const void* p0, const void* p1, const void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Get model part index.");

            // Initialize elements.
            int c = 0;
            void* n = NULL_POINTER;
            void* ns = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &ns);

            // The comparison loop.
            int j = 0;
            // The name.
            void* name = NULL_POINTER;
            // The name length.
            int count = 0;
            // The comparison result.
            int r = 0;

            while (1) {

                if (j >= c) {

                    break;
                }

                // Get element.
                get_array_element((void*) &n, (void*) &POINTER_ARRAY, (void*) &j, (void*) &name);
                get_array_element((void*) &ns, (void*) &POINTER_ARRAY, (void*) &j, (void*) &count);

                if (*s == count) {

                    compare_array_elements(p1, (void*) &name, (void*) &CHARACTER_ARRAY, (void*) &count, (void*) &r);

                    if (r == 1) {

                        *i = j;
                        break;
                    }
                }

                // Reset name length.
                count = 0;
                j++;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part index. The name size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part index. The index is null.");
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

        name = get_array_element(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX);

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

        name = get_array_element(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX);

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
 * Sets the model part by index.
 *
 * @param p0 the model
 * @param p1 the index
 * @param p2 the name
 * @param p3 the name size
 * @param p4 the part abstraction
 * @param p5 the part abstraction size
 * @param p6 the part location
 * @param p7 the part location size
 * @param p8 the part model
 * @param p9 the part model size
 * @param p10 the position abstraction
 * @param p11 the position abstraction size
 * @param p12 the position location
 * @param p13 the position location size
 * @param p14 the position model
 * @param p15 the position model size
 * @param p16 the constraint abstraction
 * @param p17 the constraint abstraction size
 * @param p18 the constraint location
 * @param p19 the constraint location size
 * @param p20 the constraint model
 * @param p21 the constraint model size
 */
void set_model_part_by_index(void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6, const void* p7, const void* p8, const void* p9,
    const void* p10, const void* p11, const void* p12, const void* p13, const void* p14, const void* p15,
    const void* p16, const void* p17, const void* p18, const void* p19, const void* p20, const void* p21) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Set model part by index.");

            // Initialize elements.
            int s = 0;
            int c = 0;
            void* n = NULL_POINTER;
            void* ns = NULL_POINTER;
            void* pa = NULL_POINTER;
            void* pas = NULL_POINTER;
            void* pl = NULL_POINTER;
            void* pls = NULL_POINTER;
            void* pm = NULL_POINTER;
            void* pms = NULL_POINTER;
            void* poa = NULL_POINTER;
            void* poas = NULL_POINTER;
            void* pol = NULL_POINTER;
            void* pols = NULL_POINTER;
            void* pom = NULL_POINTER;
            void* poms = NULL_POINTER;
            void* ca = NULL_POINTER;
            void* cas = NULL_POINTER;
            void* cl = NULL_POINTER;
            void* cls = NULL_POINTER;
            void* cm = NULL_POINTER;
            void* cms = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &ns);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_INDEX, (void*) &pl);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_COUNTS_INDEX, (void*) &pls);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pms);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_INDEX, (void*) &pol);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_COUNTS_INDEX, (void*) &pols);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &poms);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_INDEX, (void*) &ca);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX, (void*) &cas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_INDEX, (void*) &cl);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_COUNTS_INDEX, (void*) &cls);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_INDEX, (void*) &cm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_COUNTS_INDEX, (void*) &cms);

            if (*i == s) {

                // Increase size.
                s = s * 2 + 1;

                // Resize elements.
                resize_array((void*) &n, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &ns, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &pa, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &pl, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &pls, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &pm, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &pms, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &poa, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &poas, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &pol, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &pols, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &pom, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &poms, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &ca, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &cas, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &cl, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &cls, (void*) &INTEGER_ARRAY, (void*) &s);
                resize_array((void*) &cm, (void*) &POINTER_ARRAY, (void*) &s);
                resize_array((void*) &cms, (void*) &INTEGER_ARRAY, (void*) &s);

                // Set array size.
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_SIZE_INDEX, (void*) &s);
            }

            if (*i < s) {

                // Set part.
                set_array_element((void*) &n, (void*) &POINTER_ARRAY, p1, p2);
                set_array_element((void*) &ns, (void*) &POINTER_ARRAY, p1, p3);
                set_array_element((void*) &pa, (void*) &POINTER_ARRAY, p1, p4);
                set_array_element((void*) &pas, (void*) &POINTER_ARRAY, p1, p5);
                set_array_element((void*) &pl, (void*) &POINTER_ARRAY, p1, p6);
                set_array_element((void*) &pls, (void*) &POINTER_ARRAY, p1, p7);
                set_array_element((void*) &pm, (void*) &POINTER_ARRAY, p1, p8);
                set_array_element((void*) &pms, (void*) &POINTER_ARRAY, p1, p9);
                set_array_element((void*) &poa, (void*) &POINTER_ARRAY, p1, p10);
                set_array_element((void*) &poas, (void*) &POINTER_ARRAY, p1, p11);
                set_array_element((void*) &pol, (void*) &POINTER_ARRAY, p1, p12);
                set_array_element((void*) &pols, (void*) &POINTER_ARRAY, p1, p13);
                set_array_element((void*) &pom, (void*) &POINTER_ARRAY, p1, p14);
                set_array_element((void*) &poms, (void*) &POINTER_ARRAY, p1, p15);
                set_array_element((void*) &ca, (void*) &POINTER_ARRAY, p1, p16);
                set_array_element((void*) &cas, (void*) &POINTER_ARRAY, p1, p17);
                set_array_element((void*) &cl, (void*) &POINTER_ARRAY, p1, p18);
                set_array_element((void*) &cls, (void*) &POINTER_ARRAY, p1, p19);
                set_array_element((void*) &cm, (void*) &POINTER_ARRAY, p1, p20);
                set_array_element((void*) &cms, (void*) &POINTER_ARRAY, p1, p21);

                // Increment count.
                c++;

                // Set array count.
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by index. The index exceeds the size.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by index. The index is negativ.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by index. The index is null.");
    }
}

/**
 * Sets the model part by name.
 *
 * @param p0 the model
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the part abstraction
 * @param p4 the part abstraction size
 * @param p5 the part location
 * @param p6 the part location size
 * @param p7 the part model
 * @param p8 the part model size
 * @param p9 the position abstraction
 * @param p10 the position abstraction size
 * @param p11 the position location
 * @param p12 the position location size
 * @param p13 the position model
 * @param p14 the position model size
 * @param p15 the constraint abstraction
 * @param p16 the constraint abstraction size
 * @param p17 the constraint location
 * @param p18 the constraint location size
 * @param p19 the constraint model
 * @param p20 the constraint model size
 */
void set_model_part_by_name(void* p0, const void* p1, const void* p2,
    const void* p3, const void* p4, const void* p5, const void* p6, const void* p7, const void* p8,
    const void* p9, const void* p10, const void* p11, const void* p12, const void* p13, const void* p14,
    const void* p15, const void* p16, const void* p17, const void* p18, const void* p19, const void* p20) {

    // The separator index.
    int i = -1;

    get_array_element_index(p1, (void*) &CHARACTER_ARRAY, p2, (void*) &MODEL_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given model contains parts which are compound models.

        if (p2 != NULL_POINTER) {

            // The name size.
            int* ns = (int*) p2;

            if (p1 != NULL_POINTER) {

                // The name.
                char** n = (char**) p1;

                if (i >= 0) {

                    if (i < *ns) {

                        if (i != 0) {

                            if (i != (*ns - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                char* r = (char*) (*n + i + 1);

                                // The remaining name size is the full name size decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name size is 10.
                                // The separator index is 5.
                                // The size of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rs = *ns - (i + 1);

                                // Get part models.
                                void* pm = NULL_POINTER;
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);

                                // Get index of part name.
                                // The index i is used as part name size.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The size of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_model_part_index(p0, p1, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Get part.
                                    void* part = NULL_POINTER;
                                    get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &index, (void*) &part);

                                    // Recursively continue to process along the hierarchical name.
                                    set_model_part_by_name((void*) &part, (void*) &r, (void*) &rs,
                                        p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                        p15, p16, p17, p18, p19, p20);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not set model part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set model part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given model contains parts which are primitive models.

        // The index of the given name.
        int index = -1;
        get_model_part_index(p0, p1, p2, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Set model part by name.");

            set_model_part_by_index(p0, (void*) &index, p1, p2,
                p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20);

        } else {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Add model part by name.");

            // Get parts count.
            int c = 0;
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);

            set_model_part_by_index(p0, (void*) &c, p1, p2,
                p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20);
        }
    }
}

/**
 * Adds the model part.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the reference
 * @param p4 the reference size
 */
void add_model_part(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

/*??
    // This element name will get destroyed (free) in remove_map_element.
    void* n = malloc(0);

    // Extend name with next free index.
    build_next_map_element_name(m->names, p1, n);
    set_map_element_with_name(p0, n, p3);

    int i = -1;

    get_map_size(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX);

    if (i != -1) {

        set_map_element_at_index(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX, p1, p3);
    }
*/
}

/**
 * Removes the model part by index.
 *
 * @param p0 the model
 * @param p1 the index
 */
void remove_model_part_by_index(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Remove model part by index.");

            // Initialize elements.
            int s = 0;
            int c = 0;
            void* n = NULL_POINTER;
            void* ns = NULL_POINTER;
            void* pa = NULL_POINTER;
            void* pas = NULL_POINTER;
            void* pl = NULL_POINTER;
            void* pls = NULL_POINTER;
            void* pm = NULL_POINTER;
            void* pms = NULL_POINTER;
            void* poa = NULL_POINTER;
            void* poas = NULL_POINTER;
            void* pol = NULL_POINTER;
            void* pols = NULL_POINTER;
            void* pom = NULL_POINTER;
            void* poms = NULL_POINTER;
            void* ca = NULL_POINTER;
            void* cas = NULL_POINTER;
            void* cl = NULL_POINTER;
            void* cls = NULL_POINTER;
            void* cm = NULL_POINTER;
            void* cms = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_INDEX, (void*) &n);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &NAMES_COUNTS_INDEX, (void*) &ns);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_INDEX, (void*) &pl);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_COUNTS_INDEX, (void*) &pls);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pms);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_INDEX, (void*) &pol);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_COUNTS_INDEX, (void*) &pols);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &poms);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_INDEX, (void*) &ca);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX, (void*) &cas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_INDEX, (void*) &cl);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_COUNTS_INDEX, (void*) &cls);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_INDEX, (void*) &cm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_COUNTS_INDEX, (void*) &cms);

            if (*i < c) {

                // Remove part.
                remove_array_element((void*) &n, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &ns, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pas, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pl, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pls, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pms, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &poa, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &poas, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pol, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pols, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &pom, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &poms, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &ca, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &cas, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &cl, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &cls, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &cm, (void*) &POINTER_ARRAY, (void*) &c, p1);
                remove_array_element((void*) &cms, (void*) &POINTER_ARRAY, (void*) &c, p1);

                // Decrement count.
                c--;

                // Set array count.
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by index. The index exceeds the size.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by index. The index is negativ.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by index. The index is null.");
    }
}

/**
 * Removes the model part by name.
 *
 * @param p0 the model
 * @param p1 the name
 * @param p2 the name size
 */
void remove_model_part_by_name(void* p0, const void* p1, const void* p2) {

    // The separator index.
    int i = -1;

    get_array_element_index(p1, (void*) &CHARACTER_ARRAY, p2, (void*) &MODEL_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given model contains parts which are compound models.

        if (p2 != NULL_POINTER) {

            // The name size.
            int* ns = (int*) p2;

            if (p1 != NULL_POINTER) {

                // The name.
                void** n = (void**) p1;

                if (i >= 0) {

                    if (i < *ns) {

                        if (i != 0) {

                            if (i != (*ns - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name size is the full name size decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name size is 10.
                                // The separator index is 5.
                                // The size of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rs = *ns - (i + 1);

                                // Get part models.
                                void* pm = NULL_POINTER;
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);

                                // Get index of part name.
                                // The index i is used as part name size.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The size of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_model_part_index(p0, p1, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Get part.
                                    void* part = NULL_POINTER;
                                    get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &index, (void*) &part);

                                    // Recursively continue to process along the hierarchical name.
                                    remove_model_part_by_name((void*) &part, (void*) &r, (void*) &rs);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not remove model part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove model part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given model contains parts which are primitive models.

        // The index of the given name.
        int index = -1;
        get_model_part_index(p0, p1, p2, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Remove model part by name.");

            remove_model_part_by_index(p0, (void*) &index);

        } else {

//??            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not remove model part by name. A part with that name does not exist.");
        }
    }
}

/**
 * Gets the model part by index.
 *
 * @param p0 the model
 * @param p1 the index
 * @param p2 the part abstraction
 * @param p3 the part abstraction size
 * @param p4 the part location
 * @param p5 the part location size
 * @param p6 the part model
 * @param p7 the part model size
 * @param p8 the position abstraction
 * @param p9 the position abstraction size
 * @param p10 the position location
 * @param p11 the position location size
 * @param p12 the position model
 * @param p13 the position model size
 * @param p14 the constraint abstraction
 * @param p15 the constraint abstraction size
 * @param p16 the constraint location
 * @param p17 the constraint location size
 * @param p18 the constraint model
 * @param p19 the constraint model size
 */
void get_model_part_by_index(const void* p0, const void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13,
    void* p14, void* p15, void* p16, void* p17, void* p18, void* p19) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Get model part by index.");

            // Initialize elements.
            int s = 0;
            int c = 0;
            void* pa = NULL_POINTER;
            void* pas = NULL_POINTER;
            void* pl = NULL_POINTER;
            void* pls = NULL_POINTER;
            void* pm = NULL_POINTER;
            void* pms = NULL_POINTER;
            void* poa = NULL_POINTER;
            void* poas = NULL_POINTER;
            void* pol = NULL_POINTER;
            void* pols = NULL_POINTER;
            void* pom = NULL_POINTER;
            void* poms = NULL_POINTER;
            void* ca = NULL_POINTER;
            void* cas = NULL_POINTER;
            void* cl = NULL_POINTER;
            void* cls = NULL_POINTER;
            void* cm = NULL_POINTER;
            void* cms = NULL_POINTER;

            // Get elements.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARTS_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_INDEX, (void*) &pl);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_LOCATIONS_COUNTS_INDEX, (void*) &pls);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pms);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_INDEX, (void*) &poa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_ABSTRACTIONS_COUNTS_INDEX, (void*) &poas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_INDEX, (void*) &pol);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_LOCATIONS_COUNTS_INDEX, (void*) &pols);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_INDEX, (void*) &pom);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &POSITION_MODELS_COUNTS_INDEX, (void*) &poms);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_INDEX, (void*) &ca);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX, (void*) &cas);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_INDEX, (void*) &cl);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_LOCATIONS_COUNTS_INDEX, (void*) &cls);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_INDEX, (void*) &cm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &CONSTRAINT_MODELS_COUNTS_INDEX, (void*) &cms);

            if (*i < c) {

                // Get part.
                get_array_element((void*) &pa, (void*) &POINTER_ARRAY, p1, p2);
                get_array_element((void*) &pas, (void*) &POINTER_ARRAY, p1, p3);
                get_array_element((void*) &pl, (void*) &POINTER_ARRAY, p1, p4);
                get_array_element((void*) &pls, (void*) &POINTER_ARRAY, p1, p5);
                get_array_element((void*) &pm, (void*) &POINTER_ARRAY, p1, p6);
                get_array_element((void*) &pms, (void*) &POINTER_ARRAY, p1, p7);
                get_array_element((void*) &poa, (void*) &POINTER_ARRAY, p1, p8);
                get_array_element((void*) &poas, (void*) &POINTER_ARRAY, p1, p9);
                get_array_element((void*) &pol, (void*) &POINTER_ARRAY, p1, p10);
                get_array_element((void*) &pols, (void*) &POINTER_ARRAY, p1, p11);
                get_array_element((void*) &pom, (void*) &POINTER_ARRAY, p1, p12);
                get_array_element((void*) &poms, (void*) &POINTER_ARRAY, p1, p13);
                get_array_element((void*) &ca, (void*) &POINTER_ARRAY, p1, p14);
                get_array_element((void*) &cas, (void*) &POINTER_ARRAY, p1, p15);
                get_array_element((void*) &cl, (void*) &POINTER_ARRAY, p1, p16);
                get_array_element((void*) &cls, (void*) &POINTER_ARRAY, p1, p17);
                get_array_element((void*) &cm, (void*) &POINTER_ARRAY, p1, p18);
                get_array_element((void*) &cms, (void*) &POINTER_ARRAY, p1, p19);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by index. The index exceeds the size.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by index. The index is negativ.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by index. The index is null.");
    }
}

/**
 * Gets the model part by name.
 *
 * @param p0 the model
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the part abstraction
 * @param p4 the part abstraction size
 * @param p5 the part location
 * @param p6 the part location size
 * @param p7 the part model
 * @param p8 the part model size
 * @param p9 the position abstraction
 * @param p10 the position abstraction size
 * @param p11 the position location
 * @param p12 the position location size
 * @param p13 the position model
 * @param p14 the position model size
 * @param p15 the constraint abstraction
 * @param p16 the constraint abstraction size
 * @param p17 the constraint location
 * @param p18 the constraint location size
 * @param p19 the constraint model
 * @param p20 the constraint model size
 */
void get_model_part_by_name(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14,
    void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    // The separator index.
    int i = -1;

    get_array_element_index(p1, (void*) &CHARACTER_ARRAY, p2, (void*) &MODEL_PART_SEPARATOR, (void*) &i);

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given model contains parts which are compound models.

        if (p2 != NULL_POINTER) {

            // The name size.
            int* ns = (int*) p2;

            if (p1 != NULL_POINTER) {

                // The name.
                void** n = (void**) p1;

                if (i >= 0) {

                    if (i < *ns) {

                        if (i != 0) {

                            if (i != (*ns - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (*n + i + 1);

                                // The remaining name size is the full name size decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name size is 10.
                                // The separator index is 5.
                                // The size of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rs = *ns - (i + 1);

                                // Get part models.
                                void* pm = NULL_POINTER;
                                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);

                                // Get index of part name.
                                // The index i is used as part name size.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The size of the part name "hello" before the separator is likewise 5.
                                int index = -1;
                                get_model_part_index(p0, p1, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // Get part.
                                    void* part = NULL_POINTER;
                                    get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &index, (void*) &part);

                                    // Recursively continue to process along the hierarchical name.
                                    get_model_part_by_name((void*) &part, (void*) &r, (void*) &rs,
                                        p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
                                        p15, p16, p17, p18, p19, p20);

                                } else {

//??                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not get model part by name. A part with that name does not exist.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by name. The full name ends with a separator.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by name. The full name starts with a separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by name. The separator index exceeds the full name size.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by name. The separator index is negative.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by name. The name is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get model part by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the part name.
        // The given model contains parts which are primitive models.

        // The index of the given name.
        int index = -1;
        get_model_part_index(p0, p1, p2, (void*) &index);

        if (index != -1) {

//??            log_message((void*) &INFO_LOG_LEVEL, (void*) &"Get model part by name.");

            get_model_part_by_index(p0, (void*) &index,
                p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
                p15, p16, p17, p18, p19, p20);

        } else {

//??            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not get model part by name. A part with that name does not exist.");
        }
    }
}

/* COMPOUND_SOURCE */
#endif
