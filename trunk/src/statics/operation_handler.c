/*
 * $RCSfile: operation_handler.c,v $
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

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../model/map.c"
#include "../model/map_handler.c"
#include "../model/model_handler.c"
#include "../statics/operation.c"

/**
 * This is the operation handler.
 *
 * @version $Revision: 1.2 $ $Date: 2004-01-05 16:38:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Operation input and output.
//

/**
 * Initializes the operation input and output.
 *
 * @param p0 the dynamics operation model
 * @param p1 the input output names
 * @param p2 the input output values
 */
void initialize_operation_input_and_output(void* p0, void* p1, void* p2) {

    struct operation* m = (struct operation*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize operation input and output.");
        log_message((void*) &INFO_LOG_LEVEL, p1);

        void* io_name = get_part_name(p1, (void*) COMMA_SEPARATOR);
        void* rem_name = get_remaining_name(p1, (void*) COMMA_SEPARATOR);
        void* io_value = get_part_name(p2, (void*) COMMA_SEPARATOR);
        void* rem_value = get_remaining_name(p2, (void*) COMMA_SEPARATOR);

        set_map_element_with_name(m->inputs_outputs, io_name, io_value);

        if (rem_name != 0) {

            initialize_operation_input_and_output(p0, rem_name, rem_value);
        }

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation input and output. The operation is null.");
    }
}

/**
 * Finalizes the operation input and output.
 *
 * @param p0 the dynamics operation model
 * @param p1 the input output names
 * @param p2 the input output values
 */
void finalize_operation_input_and_output(void* p0, void* p1, void* p2) {

    struct operation* m = (struct operation*) p0;
    
    if (m != 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize operation input and output.");
        log_message((void*) &INFO_LOG_LEVEL, p1);

        // Write output stream and transform from fraction.
//??        sprintf(p1, %l, (void*) &(m->value));

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation input and output. The operation is null.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif

