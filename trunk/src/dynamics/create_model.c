/*
 * $RCSfile: create_model.c,v $
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
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

#include "../cybol/cybol_model_handler.c"
#include "../logger/log_handler.c"
#include "../model/map.c"
#include "../model/models.c"
#include "../model/statics_models.c"
#include "../statics/boolean_handler.c"
#include "../statics/complex_handler.c"
#include "../statics/fraction_handler.c"
#include "../statics/integer_handler.c"
#include "../statics/operation_handler.c"
#include "../statics/string_handler.c"
#include "../statics/time_handler.c"
#include "../statics/vector_handler.c"

/**
 * This is the create model operation.
 *
 * It creates a statics or dynamics memory model from a cybol model.
 *
 * @version $Revision: 1.3 $ $Date: 2004-02-29 19:55:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Forward declaration.
//
// This function is the only forward declaration. It is needed because models
// can recursively create/ destroy compound models using functions which are
// defined in model_handler.c.
//

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the cybol model
 * @param p1 the location
 * @param p2 the abstraction
 * @return the memory model
 */
void* create_model(void* p0, void* p1, void* p2);

//
// Model containers.
//

/**
 * Creates the model containers.
 *
 * @param p0 the memory model
 */
void create_model_containers(void* p0) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Create model containers.");

        m->part_abstractions = (void*) malloc(sizeof(struct map));
        initialize_map(m->part_abstractions);

        m->part_locations = (void*) malloc(sizeof(struct map));
        initialize_map(m->part_locations);

        m->part_models = (void*) malloc(sizeof(struct map));
        initialize_map(m->part_models);

        m->position_abstractions = (void*) malloc(sizeof(struct map));
        initialize_map(m->position_abstractions);

        m->position_locations = (void*) malloc(sizeof(struct map));
        initialize_map(m->position_locations);

        m->position_models = (void*) malloc(sizeof(struct map));
        initialize_map(m->position_models);

        m->constraint_abstractions = (void*) malloc(sizeof(struct map));
        initialize_map(m->constraint_abstractions);

        m->constraint_locations = (void*) malloc(sizeof(struct map));
        initialize_map(m->constraint_locations);

        m->constraint_models = (void*) malloc(sizeof(struct map));
        initialize_map(m->constraint_models);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not create model containers. The memory model is null.");
    }
}

//
// Part.
//

/**
 * Initializes the part.
 *
 * @param p0 the memory model
 * @param p1 the cybol part attributes
 */
void initialize_part(void* p0, void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        void* name = (void*) get_map_element_with_name(p1, (void*) NAME);
        void* abstraction = (void*) 0;
        void* location = (void*) 0;
        // The model read as string from a cybol file.
        void* model = (void*) 0;
        // The model as stored in computer memory (RAM).
        void* part = (void*) 0;

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

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize part. The memory model is null.");
    }
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
void initialize_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int size = 0;
    get_map_size(m, (void*) &size);
    struct model* e = (void*) 0;

    while (count < size) {

        e = (struct model*) get_map_element_at_index(m, (void*) &count);

        if (e != (void*) 0) {

            initialize_part(p0, e->part_models);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize parts. A cybol part is null.");
        }

        count++;
    }
}

//
// Model.
//

/**
 * Initializes the model from a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 */
void initialize_model(void* p0, void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize model.");

/*??
        //?? USE ARRAYS in ARRAY (instead of model with maps) here!!

        // Create temporary cybol model.
        struct statics_model* cybol = (struct statics_model*) malloc(sizeof(struct statics_model));
        create_statics_model_containers((void*) cybol);

        // Read statics cybol model from file path.
        read_statics_cybol_model((void*) cybol, p1);

        // Initialize statics model parts with statics cybol model.
        if (cybol != (void*) 0) {

            initialize_statics_parts(p0, cybol->parts);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize statics model. The statics cybol model is null.");
        }

        // Destroy temporary statics cybol model.
        destroy_statics_model_containers((void*) cybol);
        free((void*) cybol);
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize model. The memory model is null.");
    }
}

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the cybol model
 * @param p1 the location
 * @param p2 the abstraction
 * @return the memory model
 */
void* create_model(void* p0, void* p1, void* p2) {

    void* m = (void*) 0;
    char* p = (char*) p0;
    char* a = (char*) p2;

    if (p != (void*) 0) {

        if (strcmp(p, "") != 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Create model: ");
            log_message((void*) &INFO_LOG_LEVEL, p0);

            // Compound model.
            if (strcmp(a, COMPOUND_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct model));
                create_model_containers(m);
                initialize_model(m, p0);

            // Dynamics model.
            } else if (strcmp(a, OPERATION_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct operation));
                initialize_operation_model(m, p0);

            // Statics models.
            } else if (strcmp(a, TIME_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct time));
                initialize_time_model(m, p0);

            } else if (strcmp(a, STRING_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct string));
                initialize_string_model(m, p0);

            } else if (strcmp(a, VECTOR_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct vector));
                initialize_vector_model(m, p0);

            } else if (strcmp(a, COMPLEX_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct complex));
                initialize_complex_model(m, p0);

            } else if (strcmp(a, FRACTION_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct fraction));
                initialize_fraction_model(m, p0);

            } else if (strcmp(a, INTEGER_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct integer));
                initialize_integer_model(m, p0);

            } else if (strcmp(a, BOOLEAN_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct boolean));
                initialize_boolean_model(m, p0);
            }
        }
    }

    return m;
}

/* CREATE_MODEL_SOURCE */
#endif
