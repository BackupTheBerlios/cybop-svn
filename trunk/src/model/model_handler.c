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
#include "../logger/log_handler.c"
#include "../model/map.c"
#include "../model/map_handler.c"
#include "../model/model.c"
#include "../string_helper.c"

/**
 * This is the model handler.
 *
 * It handles models which represent statics or dynamics.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.11 $ $Date: 2004-02-29 18:33:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Model part.
//

/**
 * Sets the model part.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
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
void set_model_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Set model part: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);

        void* n = get_sub_string(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_string(p1, (void*) DOT_SEPARATOR);

        if (r != (void*) 0) {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            set_model_part(part, r, p2, p3, p4, p5, p6, p7, p8, p9, p10);

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
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set model part. The model is null.");
    }
}

/**
 * Removes the model part.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 */
void remove_model_part(void* p0, void* p1) {

    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Remove model part: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);

        void* n = get_sub_string(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_string(p1, (void*) DOT_SEPARATOR);

        if (r != (void*) 0) {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            remove_model_part(part, r);

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
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove model part. The model is null.");
    }
}

/**
 * Returns the model part.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 * @return the part
 */
void* get_model_part(void* p0, void* p1) {

    void* p = (void*) 0;
    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Get model part: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);

        void* n = get_sub_string(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_string(p1, (void*) DOT_SEPARATOR);

        if (r != (void*) 0) {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            p = get_model_part(part, r);

        } else {

            // The given model contains primitive models.
            p = get_map_element_with_name(m->part_models, n);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get model part. The model is null.");
    }

    return p;
}

/**
 * Returns the model part position.
 *
 * @param p0 the model
 * @param p1 the hierarchical model name
 * @return the part position
 */
void* get_model_part_position(void* p0, void* p1) {

    void* p = (void*) 0;
    struct model* m = (struct model*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Get model part position: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);

        void* n = get_sub_string(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_string(p1, (void*) DOT_SEPARATOR);

        if (r != (void*) 0) {

            // The given model contains compound models.
            void* part = get_map_element_with_name(m->part_models, n);

            // Continue to process along the hierarchical name.
            p = get_model_part(part, r);

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
