/*
 * $RCSfile: statics_model_handler.c,v $
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

#ifndef STATICS_MODEL_HANDLER_SOURCE
#define STATICS_MODEL_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../model/map.c"
#include "../model/map_handler.c"
#include "../model/model_handler.c"

/**
 * This is the statics model handler.
 *
 * Model elements are accessed over their index or name.
 * They can also be accessed hierarchically, using a dot-separated name like:
 * "system.frame.menu_bar.exit_menu_item.action"
 *
 * @version $Revision: 1.6 $ $Date: 2004-01-05 16:38:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Statics model part.
//

/**
 * Sets the statics model part.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 * @param p2 the part
 * @param p3 the position
 */
void set_statics_model_part(void* p0, void* p1, void* p2, void* p3) {

    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Set statics model part: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_name(p1, (void*) DOT_SEPARATOR);
        
        if (r != 0) {

            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            set_statics_model_part(part, r, p2, p3);
            
        } else {

            // The given model is the compound of the part.
            set_map_element_with_name(m->parts, n, p2);
            set_map_element_with_name(m->positions, n, p3);
        }
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not set statics model part. The statics model is null.");
    }
}

/**
 * Removes the statics model part.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 */
void remove_statics_model_part(void* p0, void* p1) {

    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Remove statics model part: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_name(p1, (void*) DOT_SEPARATOR);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            remove_statics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            remove_map_element_with_name(m->parts, n);
            remove_map_element_with_name(m->positions, n);
        }
        
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove statics model part. The statics model is null.");
    }
}

/**
 * Returns the statics model part.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 * @return the part
 */
void* get_statics_model_part(void* p0, void* p1) {

    void* p = 0;
    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Get statics model part: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_name(p1, (void*) DOT_SEPARATOR);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_statics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->parts, n);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get statics model part. The statics model is null.");
    }
    
    return p;
}

/**
 * Returns the statics model part position.
 *
 * @param p0 the statics model
 * @param p1 the hierarchical statics model name
 * @return the part position
 */
void* get_statics_model_part_position(void* p0, void* p1) {

    void* p = 0;
    struct statics_model* m = (struct statics_model*) p0;

    if (m != 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Get statics model part position: ");
        log_message((void*) &INFO_LOG_LEVEL, p1);
        
        void* n = get_part_name(p1, (void*) DOT_SEPARATOR);
        void* r = get_remaining_name(p1, (void*) DOT_SEPARATOR);
        
        if (r != 0) {
            
            // The given model is a compound of other compounds.
            void* part = get_map_element_with_name(m->parts, n);
            
            // Continue to process along the hierarchical name.
            p = get_statics_model_part(part, r);
            
        } else {

            // The given model is the compound of the part.
            p = get_map_element_with_name(m->positions, n);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get statics model part position. The statics model is null.");
    }
    
    return p;
}

/* STATICS_MODEL_HANDLER_SOURCE */
#endif

