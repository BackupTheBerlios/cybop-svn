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
#include "../model/map_handler.c"
#include "../model/model_handler.c"
#include "../statics/operation.c"

/**
 * This is the operation handler.
 *
 * @version $Revision: 1.12 $ $Date: 2004-03-31 15:52:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Operation container.
//

/**
 * Creates the operation container.
 *
 * @param p0 the operation memory model
 */
void create_operation_container(void* p0) {

    struct operation* m = (struct operation*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Create operation container.");

/*??
        m->value = (void*) malloc(sizeof(struct array));
        initialize_array(m->value, (void*) &CHARACTER_ARRAY);
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not create operation container. The operation memory model is null.");
    }
}

/**
 * Destroys the operation container.
 *
 * @param p0 the operation memory model
 */
void destroy_operation_container(void* p0) {

    struct operation* m = (struct operation*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Destroy operation container.");

/*??
        finalize_array(m->value);
        free(m->value);
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not destroy operation container. The operation memory model is null.");
    }
}

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

/*??
        // Read input stream and transform to operation with operands.
        int length = 0;
        get_string_length(p1, (void*) &length);
        int start = 0;
        int end = 0;
        get_character_index(p1, (void*) &COMMA_CHARACTER, (void*) &length, (void*) &end);
        void* s = malloc(0);

        copy_sub_string(p1, (void*) &start, (void*) &end, s);
        add_array_element(m->value, s);

        char* r = (char*) p1 + end;

        // Only call procedure recursively if the remaining string is not empty.
        if (*r != '\0') {

            // Set index of remaining string to one after the comma character.
            initialize_operation_model(p0, r + 1);
        }
*/

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

/*??
        if (p1 != (void*) 0) {

            // Write output stream by transforming from operation with operands.
            int c = 0;
            get_array_count(m->value, (void*) &c);

            if (c > 0) {

                int i = c - 1;
                void* s = get_array_element(m->value, (void*) &i);
                remove_array_element(m->value, (void*) &i);

                strcat((char*) p1, &COMMA_CHARACTER);
                strcat((char*) p1, (char*) s);

                free(s);

                finalize_operation_model(p0, p1);
            }

        } else {

            log_message((void*) &INFO_LOG_LEVEL, "Did not finalize operation model. The cybol model is null.");
        }
*/

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation model. The operation model is null.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
