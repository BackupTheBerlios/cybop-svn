/*
 * $RCSfile: destroy_model.c,v $
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

#ifndef DESTROY_MODEL_SOURCE
#define DESTROY_MODEL_SOURCE

#include "../cybol/cybol_model_handler.c"
#include "../model/dynamics_models.c"
#include "../logger/log_handler.c"
#include "../model/map.c"
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
 * This is the destroy model operation.
 *
 * It destroys a statics or dynamics memory model to a cybol model.
 *
 * @version $Revision: 1.2 $ $Date: 2004-02-29 18:33:29 $ $Author: christian $
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
 * Destroys a memory model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 * @param p2 the location
 * @param p3 the abstraction
 */
void destroy_model(void* p0, void* p1, void* p2, void* p3);

//
// Model containers.
//

/**
 * Destroys the model containers.
 *
 * @param p0 the memory model
 */
void destroy_model_containers(void* p0) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Destroy model containers.");

        finalize_map(m->constraint_models);
        free(m->constraint_models);

        finalize_map(m->constraint_locations);
        free(m->constraint_locations);

        finalize_map(m->constraint_abstractions);
        free(m->constraint_abstractions);

        finalize_map(m->position_models);
        free(m->position_models);

        finalize_map(m->position_locations);
        free(m->position_locations);

        finalize_map(m->position_abstractions);
        free(m->position_abstractions);

        finalize_map(m->part_models);
        free(m->part_models);

        finalize_map(m->part_locations);
        free(m->part_locations);

        finalize_map(m->part_abstractions);
        free(m->part_abstractions);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not destroy model containers. The memory model is null.");
    }
}

//
// Part.
//

/**
 * Finalizes the part.
 *
 * @param p0 the memory model
 * @param p1 the cybol part attributes
 */
void finalize_part(void* p0, void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        void* name = (void*) get_map_element_with_name(p1, (void*) NAME);
        void* abstraction = (void*) 0;
        void* location = (void*) 0;
        // The model read as string from a cybol file.
        void* model = (void*) 0;
        // The model as stored in computer memory (RAM).
        void* part = (void*) 0;

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

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize part. The memory model is null.");
    }
}

//
// Parts.
//

/**
 * Finalizes the parts.
 *
 * @param p0 the memory model
 * @param p1 the cybol parts
 */
void finalize_parts(void* p0, void* p1) {

    struct map* m = (struct map*) p1;
    int count = 0;
    int size = 0;
    get_map_size(m, (void*) &size);
    struct model* e = (void*) 0;

    while (count < size) {

        e = (struct model*) get_map_element_at_index(m, (void*) &count);

        if (e != (void*) 0) {

            finalize_part(p0, e->part_models);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize parts. A cybol part is null.");
        }

        count++;
    }
}

//
// Model.
//

/**
 * Finalizes the model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 */
void finalize_statics_model(void* p0, void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize model.");

/*??
        //?? USE ARRAYS in ARRAY (instead of model with maps) here!!

        // Create temporary statics cybol model.
        struct statics_model* cybol = (struct statics_model*) malloc(sizeof(struct statics_model));
        create_statics_model_containers((void*) cybol);

        // Finalize statics model parts with statics cybol model.
        if (cybol != (void*) 0) {

            finalize_statics_parts(p0, cybol->parts);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize statics model. The statics cybol model is null.");
        }

        // Write statics cybol model to file path.
        write_statics_cybol_model((void*) cybol, p1);

        // Destroy temporary statics cybol model.
        destroy_statics_model_containers((void*) cybol);
        free((void*) cybol);
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize model. The memory model is null.");
    }
}

/**
 * Destroys a memory model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 * @param p2 the location
 * @param p3 the abstraction
 */
void destroy_model(void* p0, void* p1, void* p2, void* p3) {

    char* p = (char*) p1;
    char* a = (char*) p3;

    if (p0 != (void*) 0) {

//??        if (p != (void*) 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Destroy model: ");
            log_message((void*) &INFO_LOG_LEVEL, p1);

            // Compound model.
            if (strcmp(a, STATICS_COMPOUND) == 0) {

                finalize_statics_model(p0, p1);
                destroy_statics_model_containers(p0);
                free(p0);

            // Dynamics model.
            } else if (strcmp(a, OPERATION) == 0) {

                finalize_operation_model(p0, p1);
                free(p0);

            // Statics models.
            } else if (strcmp(a, TIME_PRIMITIVE) == 0) {

                finalize_time_model(p0, p1);
                free(p0);

            } else if (strcmp(a, STRING_PRIMITIVE) == 0) {

                finalize_string_model(p0, p1);
                free(p0);

            } else if (strcmp(a, VECTOR_PRIMITIVE) == 0) {

                finalize_vector_model(p0, p1);
                free(p0);

            } else if (strcmp(a, COMPLEX_PRIMITIVE) == 0) {

                finalize_complex_model(p0, p1);
                free(p0);

            } else if (strcmp(a, FRACTION_PRIMITIVE) == 0) {

                finalize_fraction_model(p0, p1);
                free(p0);

            } else if (strcmp(a, INTEGER_PRIMITIVE) == 0) {

                finalize_integer_model(p0, p1);
                free(p0);

            } else if (strcmp(a, BOOLEAN_PRIMITIVE) == 0) {

                finalize_boolean_model(p0, p1);
                free(p0);
            }
//??        }
    }
}

/* DESTROY_MODEL_SOURCE */
#endif
