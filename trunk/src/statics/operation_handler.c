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
 *
 * This file handles an operation, also known as system.
 *
 * An operation transports an input state through logics to an output state.
 * The logics is kept as function pointer.
 * Many inputs and outputs are possible.
 * Statics models are kept as hierarchical paths.
 *
 * Operations can be stored as signals in a signal memory.
 *
 * Operation, input and output are stored in the following form:
 * operation, operand1, operand2, operand3, ...
 *
 * @version $Revision: 1.15 $ $Date: 2004-04-02 16:13:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../logger/log_handler.c"

//
// Operation.
//

/**
 * Creates the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void create_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, "Create operation.");

    // The operation.
    create_array(p0, p1);
}

/**
 * Destroys the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy operation.");

    // The operation.
    destroy_array(p0, p1);
}

/**
 * Initializes the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void initialize_operation(void* p0, void* p1, const void* p2, const void* p3) {

    int* ps = (int*) p3;

    if (ps != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize operation.");

        // Find pointers to the single string parts which are separated by a comma.
        // Identify sizes of the single string parts.
        // Add these pointers and the corresponding sizes as separate string elements
        // to the operation array. Transform to operation with operands.

        int i = -1;
        get_array_element_index(p2, p3, (void*) &CHARACTER_ARRAY, (void*) &COMMA_CHARACTER, i);

        if (i != -1) {

            //?? Store pointer and size in arrays!

            // Add element.
            get_array_element(p0, p1, (void*) &POINTER_ARRAY, index-0, (void*) &pointers);
            get_array_element(p0, p1, (void*) &POINTER_ARRAY, index-1, (void*) &sizes);

            set_array_element(p0-pointers, p0-size, (void*) &POINTER_ARRAY, p1, (void*) &element-part-name-begin-pointer);
            set_array_element(p0-sizes, p0-size, (void*) &INTEGER_ARRAY, p1, (void*) &element-part-name-size);


--
        get_character_index(p1, (void*) &COMMA_CHARACTER, (void*) &length, (void*) &end);
        add_array_element(p0, s);

        char* r = (char*) p1 + end;

        // Only call procedure recursively if the remaining string is not empty.
        if (*r != '\0') {

            // Set index of remaining string to one after the comma character.
            initialize_operation_model(p0, r + 1);
        }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation. The transient model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation. The persistent model size is null.");
    }
}

/**
 * Finalizes the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void finalize_operation(const void* p0, const void* p1, void* p2, void* p3) {

    log_message((void*) &INFO_LOG_LEVEL, "Finalize operation.");

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
}

/* OPERATION_HANDLER_SOURCE */
#endif
