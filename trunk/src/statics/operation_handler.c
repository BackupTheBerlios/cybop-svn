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
 * @version $Revision: 1.17 $ $Date: 2004-04-05 16:10:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../model/array_handler.c"

//
// Constants.
//

/** The operation size. */
static const int OPERATION_SIZE = 3;

/** The array size index. */
static const int ARRAY_SIZE_INDEX = 0;

/** The parameters array index. */
static const int PARAMETERS_ARRAY_INDEX = 1;

/** The parameters sizes array index. */
static const int PARAMETERS_SIZES_ARRAY_INDEX = 2;

/** The operation parameter separator. */
static const char OPERATION_PARAMETER_SEPARATOR = ',';

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
    create_array(p0, (void*) &OPERATION_SIZE);

    // The array size which is always equal for both arrays.
    int s = 0;
    set_array_element(p0, (void*) &OPERATION_SIZE, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

    // The parameters array.
    void* p = NULL;
    create_array((void*) &p, (void*) &s);
    set_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &p);

    // The parameters sizes array.
    void* ps = NULL;
    create_array((void*) &ps, (void*) &s);
    set_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &ps);
}

/**
 * Destroys the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy operation.");

    // The array size which is always equal for both arrays.
    int s = 0;
    get_array_element(p0, (void*) &OPERATION_SIZE, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

    // The parameters sizes array.
    void* ps = NULL;
    get_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &ps);
    remove_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX);
    destroy_array((void*) &ps, (void*) &s);

    // The parameters array.
    void* p = NULL;
    get_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &p);
    remove_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX);
    destroy_array((void*) &p, (void*) &s);

    // The array size which is always equal for both arrays.
    remove_array_element(p0, (void*) &OPERATION_SIZE, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX);

    // The operation.
    destroy_array(p0, (void*) &OPERATION_SIZE);
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

    if (ps != NULL) {

        void** p = (int*) p2;

        if (p != NULL) {

            int* ts = (int*) p1;

            if (ts != NULL) {

                void** t = (int*) p0;

                if (t != NULL) {

                    log_message((void*) &INFO_LOG_LEVEL, "Initialize operation.");

                    // Find pointers to the single string parts which are separated by a comma.
                    // Identify sizes of the single string parts.
                    // Add these pointers and the corresponding sizes as separate string elements
                    // to the operation array. Transform to operation with operands.

                    // The parameter size initially set to the whole persistent model size.
                    int size = *ps;

                    // The separator index.
                    int i = -1;
                    get_array_element_index(p2, p3, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_PARAMETER_SEPARATOR, (void*) &i);

                    if (i != -1) {

                        // Reset parameter size if a separator is found and more parameters exist.
                        // Example: "operation,parameter"
                        // i = 9
                        // size = 9
                        size = i;
                    }

                    if (size > 0) {

                        // The array size.
                        int s = 0;
                        get_array_element(p0, (void*) &OPERATION_SIZE, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

                        //?? Handle size in new (simplified) way! Consider changes in array_handler!

                        // Add parameter to array.
                        void* pa = NULL;
                        get_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &pa);
                        set_array_element((void*) &pa, (void*) &s, (void*) &POINTER_ARRAY, (void*) &s, p0);

                        // Add parameter size to array.
                        void* pas = NULL;
                        get_array_element(p0, (void*) &OPERATION_SIZE, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &pas);
                        set_array_element((void*) &pas, (void*) &s, (void*) &POINTER_ARRAY, (void*) &s, (void*) &size);

                        if (i != -1) {

                            // The size of the remaining parameters.
                            // Example: "operation,parameter"
                            // *ps = 19
                            // i = 9
                            // rs = *ps - (i + 1) = 9
                            int rs = *ps - (i + 1);

                            if (rs > 0) {

                                // The remaining parameters.
                                void* r = *p + i + 1;

                                // Call procedure recursively if more parameters are following after the separator.
                                // Set index of remaining string to one after the comma character.
                                initialize_operation(p0, p1, (void*) &r, (void*) &rs);

                            } else {

                                log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize operation. There are no remaining parameters after the separator.");
                            }
                        }

                    } else {

                        log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize operation. There is no parameter before the separator.");
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
    if (p1 != NULL) {

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
