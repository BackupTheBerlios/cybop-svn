/*
 * $RCSfile: operation_handler.c,v $
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

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../model/map.c"
#include "../model/map_handler.c"
#include "../model/model_handler.c"
#include "../statics/operation.c"

/**
 * This is the operation handler.
 *
 * @version $Revision: 1.6 $ $Date: 2004-02-29 16:26:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Operation model.
//

/**
 * Initializes the operation model.
 *
 * @param p0 the operation model
 * @param p1 the model source
 */
void initialize_operation_model(void* p0, void* p1) {

    struct operation* m = (struct operation*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize operation model.");

        // Read input stream and transform to inputs and outputs.
        void* io = get_sub_string(p1, (void*) COMMA_SEPARATOR);
        void* r = get_remaining_string(p1, (void*) COMMA_SEPARATOR);

        add_array_element(m->inputs_outputs, io);

        if (r != (void*) 0) {

            initialize_operation_model(p0, r);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation model. The operation model is null.");
    }
}

/**
 * Finalizes the operation model.
 *
 * @param p0 the operation model
 * @param p1 the model source
 */
void finalize_operation_model(void* p0, void* p1) {

    struct operation* m = (struct operation*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize operation model.");

        // Write output stream and transform from inputs and outputs.
        int c = 0;
        get_array_count(m->inputs_outputs, (void*) &c);

        if (c > 0) {

            void* io = get_array_element(m->inputs_outputs, c - 1);
            remove_array_element(m->inputs_outputs, c - 1);

            strcat((char*) p1, COMMA_SEPARATOR);
            strcat((char*) p1, (char*) io);

            finalize_operation_model(p0, p1);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation model. The operation model is null.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
