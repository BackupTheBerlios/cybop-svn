/*
 * $RCSfile: dynamics_model_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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

#ifndef DYNAMICS_MODEL_HANDLER_SOURCE
#define DYNAMICS_MODEL_HANDLER_SOURCE

#include "log_handler.c"
#include "map.c"
#include "map_handler.c"
#include "model_handler.c"

/**
 * This is the dynamics model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.3 $ $Date: 2003-12-05 12:10:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Dynamics model part.
//

/**
 * Sets the dynamics model part.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @param p2 the part
 * @param p3 the input 0
 * @param p4 the input 1
 * @param p5 the output 0
 * @param p6 the output 1
 * @param p7 the position
 */
static void set_dynamics_model_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Set dynamics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {

            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            set_dynamics_model_part(part, r, p2, p3, p4, p5, p6, p7);
            
        } else {

            // The given model is the compound of the part.
            set_map_element_with_name(m->parts, n, p2);
            set_map_element_with_name(m->inputs_0, n, p3);
            set_map_element_with_name(m->inputs_1, n, p4);
            set_map_element_with_name(m->outputs_0, n, p5);
            set_map_element_with_name(m->outputs_1, n, p6);
            set_map_element_with_name(m->positions, n, p7);
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not set dynamics model part. The dynamics model is null.");
    }
}

/**
 * Removes the dynamics model part.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 */
static void remove_dynamics_model_part(void* p0, void* p1) {

    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Remove dynamics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            remove_dynamics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            remove_map_element_with_name(m->parts, n);
            remove_map_element_with_name(m->inputs_0, n);
            remove_map_element_with_name(m->inputs_1, n);
            remove_map_element_with_name(m->outputs_0, n);
            remove_map_element_with_name(m->outputs_1, n);
            remove_map_element_with_name(m->positions, n);
        }
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove dynamics model part. The dynamics model is null.");
    }
}

/**
 * Returns the dynamics model part.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part
 */
static void* get_dynamics_model_part(void* p0, void* p1) {

    void* p = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_dynamics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->parts, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part. The dynamics model is null.");
    }
    
    return p;
}

/**
 * Returns the dynamics model part input 0.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part input 0
 */
static void* get_dynamics_model_part_input_0(void* p0, void* p1) {

    void* i = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part input 0: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            i = get_dynamics_model_part_input_0(part, r);
            
        } else {

            // The given model is the compound of the part.
            i = get_map_element_with_name(m->inputs_0, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part input 0. The dynamics model is null.");
    }
    
    return i;
}

/**
 * Returns the dynamics model part input 1.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part input 1
 */
static void* get_dynamics_model_part_input_1(void* p0, void* p1) {

    void* i = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part input 1: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            i = get_dynamics_model_part_input_1(part, r);
            
        } else {

            // The given model is the compound of the part.
            i = get_map_element_with_name(m->inputs_1, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part input 1. The dynamics model is null.");
    }
    
    return i;
}

/**
 * Returns the dynamics model part output 0.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part output 0
 */
static void* get_dynamics_model_part_output_0(void* p0, void* p1) {

    void* o = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part output 0: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            o = get_dynamics_model_part_output_0(part, r);
            
        } else {

            // The given model is the compound of the part.
            o = get_map_element_with_name(m->outputs_0, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part output 0. The dynamics model is null.");
    }
    
    return o;
}

/**
 * Returns the dynamics model part output 1.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part output 1
 */
static void* get_dynamics_model_part_output_1(void* p0, void* p1) {

    void* o = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part output 1: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            o = get_dynamics_model_part_output_1(part, r);
            
        } else {

            // The given model is the compound of the part.
            o = get_map_element_with_name(m->outputs_1, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part output 1. The dynamics model is null.");
    }
    
    return o;
}

/**
 * Returns the dynamics model part position.
 *
 * @param p0 the dynamics model
 * @param p1 the hierarchical dynamics model name
 * @return the part position
 */
static void* get_dynamics_model_part_position(void* p0, void* p1) {

    void* p = 0;
    struct dynamics_model* m = (struct dynamics_model*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Get dynamics model part position: ");
        log((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1);
        void* r = get_remaining_name(p1);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_dynamics_model_part_position(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->positions, n);
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get dynamics model part position. The dynamics model is null.");
    }
    
    return p;
}

/* DYNAMICS_MODEL_HANDLER_SOURCE */
#endif

