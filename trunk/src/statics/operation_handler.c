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
 * The persistent model string contains, separated by a separator:
 * - operation
 * - operand 0
 * - operand 1
 * - operand 2
 * - operand ...
 *
 * Example:
 * operation,operand0,operand1,operand2,...
 *
 * The transient model contains the operation, its operands and their sizes
 * as separate array elements.
 *
 * An operation transports an input state through logics to an output state.
 * The logics is kept as function pointer.
 * Many inputs and outputs are possible.
 * Statics models are kept as hierarchical paths.
 *
 * Operations can be stored as signals in a signal memory.
 *
 * @version $Revision: 1.26 $ $Date: 2004-04-28 14:35:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"
#include "../model/array_handler.c"

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

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Create operation.");

    // Create operation.
    create_array(p0, (void*) &OPERATION_SIZE);

    // Initialize elements.
    int s = 0;
    void* p = NULL_POINTER;
    void* ps = NULL_POINTER;

    // Create elements.
    create_array((void*) &p, (void*) &s);
    create_array((void*) &ps, (void*) &s);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_SIZE_INDEX, (void*) &s);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);
}

/**
 * Destroys the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Destroy operation.");

    // Initialize elements.
    int s = 0;
    void* p = NULL_POINTER;
    void* ps = NULL_POINTER;

    // Get elements.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_SIZE, (void*) &PARAMETERS_SIZES_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_SIZE, (void*) &PARAMETERS_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &OPERATION_SIZE, (void*) &PARAMETERS_SIZE_INDEX);

    // Destroy elements.
    destroy_array((void*) &p, (void*) &s);
    destroy_array((void*) &ps, (void*) &s);

    // Destroy operation.
    destroy_array(p0, (void*) &OPERATION_SIZE);
}

/**
 * Initializes the operation.
 *
 * Finds persistent model parts which are separated by a separator.
 * Adds these parts and their corresponding sizes as separate elements
 * to the operation array.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void initialize_operation(void* p0, void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* ps = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** p = (void**) p2;

            if (p1 != NULL_POINTER) {

                int* ts = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** t = (void**) p0;

                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Initialize operation.");

                    // The parameter size initially set to the persistent model size.
                    int size = *ps;

                    // The separator index.
                    int i = -1;
                    get_array_element_index(p2, (void*) &CHARACTER_ARRAY, p3, (void*) &OPERATION_PARAMETER_SEPARATOR, (void*) &i);

                    if (i >= 0) {

                        // Reset parameter size if a separator is found and more parameters exist.
                        // Example: "operation,parameter"
                        // i = 9
                        // size = 9
                        size = i;
                    }

                    if (size > 0) {

                        // Initialize elements.
                        int s = 0;
                        void* pa = NULL_POINTER;
                        void* pas = NULL_POINTER;

                        // Get elements.
    fprintf(stderr, "s1: %d\n", s);
                        get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_SIZE_INDEX, (void*) &s);
    //?? size is wrong! negative!
    fprintf(stderr, "s2: %d\n", s);
                        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &pa);
                        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &pas);

                        // The index for adding the parameter and its size.
                        int index = s;

                        // Increment size.
                        s++;

                        // Resize elements.
                        resize_array(pa, (void*) &s);
    fputs("TEST B\n", stderr);
                        resize_array(pas, (void*) &s);

                        // Set size.
    fputs("TEST C\n", stderr);
                        set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_SIZE_INDEX, (void*) &s);
    fputs("TEST D\n", stderr);

                        if (index < s) {

                            // Set parameter.
                            set_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &index, p0);
    fputs("TEST E\n", stderr);
                            set_array_element((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &index, (void*) &size);

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
                                    // Set index of remaining string to one after the separator.
                                    initialize_operation(p0, p1, (void*) &r, (void*) &rs);

                                } else {

                                    log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize operation. There are no remaining parameters after the separator.");
                                }
                            }

                        } else {

                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The index exceeds the size.");
                        }

                    } else {

                        log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize operation. There is no parameter before the separator.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The persistent model size is null.");
    }
}

/**
 * Finalizes the operation.
 *
 * Finds parts and their corresponding sizes from operation arrays.
 * Writes them as parts separated by a separator into the persistent model string.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void finalize_operation(const void* p0, const void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* ps = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** p = (void**) p2;

            if (p1 != NULL_POINTER) {

                int* ts = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** t = (void**) p0;

                    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Finalize operation.");

                    // Initialize elements.
                    int s = 0;
                    void* p = NULL_POINTER;
                    void* ps = NULL_POINTER;

                    // Get elements.
                    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_SIZE_INDEX, (void*) &s);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);

/*??
                    Finalization of operation is possibly not necessary!
                    Operations get defined in CYBOL models (files).
                    To manipulate them may become the task of a special modelling/ design tool,
                    but not every application needs to allow modification of operations.
                    Therefore, this block is commented/ disabled, for now.

                    // The index for removing the parameter and its size.
                    int index = 0;

                    if (index < s) {

                        // Remove array elements.
                        remove_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &s, (void*) &index);
                        remove_array_element((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &s, (void*) &index);

                        // Decrement array size.
                        s--;

                        // Resize arrays.
                        resize_array(pa, (void*) &s);
                        resize_array(pas, (void*) &s);

                        // Set array size which is equal for all arrays.
                        set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

                        if (s > 0) {

                            index = 0;

                            get_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &idx, (void*) &elem);

                            //?? Add to persistent pointer which was handed over.
                            //?? Add separator and then make recursive call to add further parameters.
                            //?? Use transient size to set (increase) starting point of persistent pointer.

                            p + OPERATION_PARAMETER_SEPARATOR

                            // The size of the remaining parameters.
                            // Example: "operation,parameter"
                            // *ps = 19
                            // i = 9
                            // rs = *ps - (i + 1) = 9
                            int rs = *ps - (i + 1);

                            if (rs > 0) {

                                // The remaining parameters.
                                void* r = *p + ts + 1;

                                // Call procedure recursively if operation array contains more parameters.
                                // Add separator between the parameters.
                                finalize_operation(p0, p1, (void*) &r, (void*) &rs);

                            } else {

                                log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not finalize operation. There are no remaining parameters after the separator.");
                            }
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The index exceeds the size.");
                    }
*/

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The transient model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The persistent model size is null.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
