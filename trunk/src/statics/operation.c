/*
 * $RCSfile: operation.c,v $
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
 * @version $Revision: 1.12 $ $Date: 2004-05-31 17:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_SOURCE
#define OPERATION_SOURCE

#include "../array/array.c"
#include "../constants/constants.c"
#include "../logger/logger.c"

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

    log_message((void*) &INFO_LOG_LEVEL, (void*) &CREATE_OPERATION_MESSAGE, (void*) &CREATE_OPERATION_MESSAGE_COUNT);

    // Create operation.
    create_array(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT);

    // Initialize elements.
    void* p = NULL_POINTER;
    void* pc = NULL_POINTER;

    // Create elements.
    create_array((void*) &p, (void*) &POINTER_ARRAY, p1);
    create_array((void*) &pc, (void*) &INTEGER_ARRAY, p1);

    // Set elements in ascending order.
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);
}

/**
 * Destroys the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &DESTROY_OPERATION_MESSAGE, (void*) &DESTROY_OPERATION_MESSAGE_COUNT);

    // Initialize elements.
    void* p = NULL_POINTER;
    void* pc = NULL_POINTER;

    // Get elements.
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);

    // Remove elements in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT, (void*) &PARAMETERS_COUNTS_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT, (void*) &PARAMETERS_INDEX);

    // Destroy elements.
    destroy_array((void*) &p, (void*) &POINTER_ARRAY, p1);
    destroy_array((void*) &pc, (void*) &INTEGER_ARRAY, p1);

    // Destroy operation.
    destroy_array(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_COUNT);
}

/**
 * Initializes the operation.
 *
 * Finds persistent model parts which are separated by a separator.
 * Adds these parts and their corresponding counts as separate elements
 * to the operation array.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void initialize_operation(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* pc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** p = (void**) p3;

            if (p2 != NULL_POINTER) {

                int* ts = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* tc = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** t = (void**) p0;

                        log_message((void*) &INFO_LOG_LEVEL, (void*) &INITIALIZE_OPERATION_MESSAGE, (void*) &INITIALIZE_OPERATION_MESSAGE_COUNT);

                        // The parameter count initially set to the persistent model count.
                        int count = *pc;

                        // The separator index.
                        int si = -1;
                        get_array_element_index(p3, (void*) &CHARACTER_ARRAY, p4, (void*) &OPERATION_PARAMETER_SEPARATOR, (void*) &si);

                        if (si >= 0) {

                            // Change parameter count if a separator is found
                            // and more parameters exist.
                            // Example: "operation,parameter"
                            // i = 9
                            // count = 9
                            count = si;
                        }

                        if (count > 0) {

                            // Initialize elements.
                            void* pa = NULL_POINTER;
                            void* pac = NULL_POINTER;

                            // Get elements.
                            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &pa);
                            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pac);

                            // The index for adding the parameter and its count.
                            int i = *tc;

                            if (i >= 0) {

                                if (i == *ts) {

                                    // Increase size.
                                    *ts = *ts * OPERATION_RESIZE_FACTOR + 1;

                                    // Resize elements.
                                    resize_array((void*) &pa, (void*) &POINTER_ARRAY, p2);
                                    resize_array((void*) &pac, (void*) &INTEGER_ARRAY, p2);
                                }

                                if (i < *ts) {

                                    // Set parameter.
                                    set_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &i, p3);
                                    set_array_element((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &count);

                                    // Increment count.
                                    (*tc)++;

                                    // If separator was found, then process
                                    // the remaining parameters.
                                    if (si != -1) {

                                        // The size of the remaining parameters.
                                        // Example: "operation,parameter"
                                        // *pc = 19
                                        // si = 9
                                        // rc = *pc - (si + 1) = 9
                                        int rc = *pc - (si + 1);

                                        if (rc > 0) {

                                            // The remaining parameters.
                                            void* r = *p + si + 1;

                                            // Call procedure recursively if more parameters
                                            // are following after the separator.
                                            // Set index of remaining string to one after the separator.
                                            initialize_operation(p0, p1, (void*) &r, (void*) &rc);

                                        } else {

//??                                            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize operation. There are no remaining parameters after the separator.");
                                        }
                                    }

                                } else {

//??                                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The index exceeds the size.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The index is negativ.");
                            }

                        } else {

//??                            log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not initialize operation. There is no parameter before the separator.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model is null.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model count is null.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model size is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The persistent model is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The persistent model count is null.");
    }
}

/**
 * Finalizes the operation.
 *
 * Finds parts and their corresponding counts from operation arrays.
 * Writes them as parts separated by a separator into the persistent model string.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 */
void finalize_operation(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {

/*??
    if (p3 != NULL_POINTER) {

        int* pc = (int*) p3;

        if (p2 != NULL_POINTER) {

            void** p = (void**) p2;

            if (p1 != NULL_POINTER) {

                int* tc = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** t = (void**) p0;

                    log_message((void*) &INFO_LOG_LEVEL, (void*) &FINALIZE_OPERATION_MESSAGE, (void*) &FINALIZE_OPERATION_MESSAGE_COUNT);

                    // Initialize elements.
                    int c = 0;
                    void* p = NULL_POINTER;
                    void* pc = NULL_POINTER;

                    // Get elements.
                    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &PARAMETERS_COUNT_INDEX, (void*) &c);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);

                    Finalization of operation is possibly not necessary!
                    Operations get defined in CYBOL models (files).
                    To manipulate them may become the task of a special modelling/ design tool,
                    but not every application needs to allow modification of operations.
                    Therefore, this block is commented/ disabled, for now.

                    // The index for removing the parameter and its count.
                    int index = 0;

                    if (index < c) {

                        // Remove array elements.
                        remove_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &c, (void*) &index);
                        remove_array_element((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &c, (void*) &index);

                        // Decrement array count.
                        c--;

                        // Resize arrays.
                        resize_array(pa, (void*) &POINTER_ARRAY, (void*) &c);
                        resize_array(pac, (void*) &INTEGER_ARRAY, (void*) &c);

                        // Set array count which is equal for all arrays.
                        set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);

                        if (c > 0) {

                            index = 0;

                            get_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &idx, (void*) &elem);

                            //?? Add to persistent pointer which was handed over.
                            //?? Add separator and then make recursive call to add further parameters.
                            //?? Use transient count to set (increase) starting point of persistent pointer.

                            p + OPERATION_PARAMETER_SEPARATOR

                            // The count of the remaining parameters.
                            // Example: "operation,parameter"
                            // *pc = 19
                            // i = 9
                            // rc = *pc - (i + 1) = 9
                            int rc = *pc - (i + 1);

                            if (rc > 0) {

                                // The remaining parameters.
                                void* r = *p + tc + 1;

                                // Call procedure recursively if operation array
                                // contains more parameters.
                                // Add separator between the parameters.
                                finalize_operation(p0, p1, (void*) &r, (void*) &rc);

                            } else {

//??                                log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not finalize operation. There are no remaining parameters after the separator.");
                            }
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The index exceeds the count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The transient model is null.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The transient model count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The persistent model is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not finalize operation. The persistent model count is null.");
    }
*/
}

/* OPERATION_SOURCE */
#endif
