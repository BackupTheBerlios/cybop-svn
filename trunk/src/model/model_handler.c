/*
 * $RCSfile: model_handler.c,v $
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

#ifndef MODEL_HANDLER_SOURCE
#define MODEL_HANDLER_SOURCE

#include <string.h>
#include "../cybol/cybol_model_handler.c"
#include "../logger/log_handler.c"
#include "../model/map.c"
#include "../model/map_handler.c"
#include "../model/model.c"

/**
 * This is the model handler.
 *
 * It handles models which represent statics or dynamics.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.16 $ $Date: 2004-03-11 22:44:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Model.
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
// Forward declarations.
//
// These functions are the only forward declarations. They are needed because
// models can recursively create/ destroy compound models using functions which
// are defined in model_handler.c.
//

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the cybol model
 * @param p1 the location
 * @param p2 the abstraction
 * @return the memory model
 */
void* create_model(const void* p0, const void* p1, const void* p2);

/**
 * Destroys a memory model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 * @param p2 the location
 * @param p3 the abstraction
 */
void destroy_model(void* p0, const void* p1, const void* p2, const void* p3);

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

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

/*??
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
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize part. The memory model is null.");
    }
}

/**
 * Finalizes the part.
 *
 * @param p0 the memory model
 * @param p1 the cybol part attributes
 */
void finalize_part(void* p0, const void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

/*??
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
*/
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
void initialize_model(void* p0, const void* p1) {

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
 * Finalizes the model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 */
void finalize_model(void* p0, const void* p1) {

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

//
// Model part.
//

/**
 * Sets the model part.
 *
 * @param p0 the model
 * @param p1 the name
 * @param p2 the part abstraction
 * @param p3 the part location
 * @param p4 the part model
 * @param p5 the position abstraction
 * @param p6 the position location
 * @param p7 the position model
 * @param p8 the constraint abstraction
 * @param p9 the constraint location
 * @param p10 the constraint model
 */
void set_model_part(void* p0, const void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6, const void* p7, const void* p8, const void* p9, const void* p10) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Set model part: ");

        set_map_element_with_name(m->part_abstractions, p1, p2);
        set_map_element_with_name(m->part_locations, p1, p3);
        set_map_element_with_name(m->part_models, p1, p4);
        set_map_element_with_name(m->position_abstractions, p1, p5);
        set_map_element_with_name(m->position_locations, p1, p6);
        set_map_element_with_name(m->position_models, p1, p7);
        set_map_element_with_name(m->constraint_abstractions, p1, p8);
        set_map_element_with_name(m->constraint_locations, p1, p9);
        set_map_element_with_name(m->constraint_models, p1, p10);

/*??
        int length = 0;
        get_string_length(p1, (void*) &length);
        int start = 0;
        int end = 0;
        get_character_index(p1, (void*) &DOT_CHARACTER, (void*) &length, (void*) &end);
        void* n = malloc(0);

        copy_sub_string(p1, (void*) &start, (void*) &end, n);

        char* r = (char*) p1 + end;

        // Only call procedure recursively if the remaining string is not empty.
        if (*r != '\0') {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            set_model_part(part, r + 1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

            // The name served only as a temporary model identificator.
            free(n);

        } else {

            // The given model contains primitive models.
            set_map_element_with_name(m->part_abstractions, n, p2);
            set_map_element_with_name(m->part_locations, n, p3);
            set_map_element_with_name(m->part_models, n, p4);
            set_map_element_with_name(m->position_abstractions, n, p5);
            set_map_element_with_name(m->position_locations, n, p6);
            set_map_element_with_name(m->position_models, n, p7);
            set_map_element_with_name(m->constraint_abstractions, n, p8);
            set_map_element_with_name(m->constraint_locations, n, p9);
            set_map_element_with_name(m->constraint_models, n, p10);

            // Do not free(n) here! The name is referenced by the model maps.
            // It will get freed when removing a model part.
        }
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set model part. The model is null.");
    }
}

/**
 * Removes the model part.
 *
 * @param p0 the model
 * @param p1 the name
 */
void remove_model_part(void* p0, const void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Remove model part: ");

        remove_map_element_with_name(m->part_abstractions, p1);
        remove_map_element_with_name(m->part_locations, p1);
        remove_map_element_with_name(m->part_models, p1);
        remove_map_element_with_name(m->position_abstractions, p1);
        remove_map_element_with_name(m->position_locations, p1);
        remove_map_element_with_name(m->position_models, p1);
        remove_map_element_with_name(m->constraint_abstractions, p1);
        remove_map_element_with_name(m->constraint_locations, p1);
        remove_map_element_with_name(m->constraint_models, p1);

/*??
        int length = 0;
        get_string_length(p1, (void*) &length);
        int start = 0;
        int end = 0;
        get_character_index(p1, (void*) &DOT_CHARACTER, (void*) &length, (void*) &end);
        void* n = malloc(0);

        copy_sub_string(p1, (void*) &start, (void*) &end, n);

        char* r = (char*) p1 + end;

        // Only call procedure recursively if the remaining string is not empty.
        if (*r != '\0') {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            remove_model_part(part, r + 1);

            // The name served only as a temporary model identificator.
            free(n);

        } else {

            // The given model contains primitive models.
            remove_map_element_with_name(m->part_abstractions, n);
            remove_map_element_with_name(m->part_locations, n);
            remove_map_element_with_name(m->part_models, n);
            remove_map_element_with_name(m->position_abstractions, n);
            remove_map_element_with_name(m->position_locations, n);
            remove_map_element_with_name(m->position_models, n);
            remove_map_element_with_name(m->constraint_abstractions, n);
            remove_map_element_with_name(m->constraint_locations, n);
            remove_map_element_with_name(m->constraint_models, n);

            // Do not free(n) here! The name is referenced by the model maps.
            // It will get freed when removing a model part.
        }
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove model part. The model is null.");
    }
}

/**
 * Gets the model part.
 *
 * @param p0 the model
 * @param p1 the name
 * @param p2 the part
 */
void get_model_part(const void* p0, const void* p1, void* p2) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Get model part: ");

        get_map_element_with_name(m->part_models, p1, p2);

/*??
        int s = p1->size;
        int i = INVALID_INDEX;
        get_array_element_index(p1, (void*) &DOT_CHARACTER, (void*) &i);

        void* n = (p1 + i - 1);

        // Only call procedure recursively if the remaining string is not empty.
        if (i != INVALID_INDEX) {

            char* r = (char*) (p1 + i + 1);

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            p = get_model_part(part, r + 1);

        } else {

            // The given model contains primitive models.
            p = get_map_element_with_name(m->part_models, n);
        }
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get model part. The model is null.");
    }
}

/**
 * Gets the model part position.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 * @return the part position
 */
/*??
void* get_model_part_position(const void* p0, const void* p1) {

    void* p = (void*) 0;
    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Get model part position: ");

        int length = 0;
        get_string_length(p1, (void*) &length);
        int start = 0;
        int end = 0;
        get_character_index(p1, (void*) &DOT_CHARACTER, (void*) &length, (void*) &end);
        void* n = malloc(0);

        copy_sub_string(p1, (void*) &start, (void*) &end, n);

        char* r = (char*) p1 + end;

        // Only call procedure recursively if the remaining string is not empty.
        if (*r != '\0') {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            p = get_model_part(part, r + 1);

        } else {

            // The given model contains primitive models.
            p = get_map_element_with_name(m->position_models, n);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get model part position. The model is null.");
    }

    return p;
}

/* MODEL_HANDLER_SOURCE */
#endif
