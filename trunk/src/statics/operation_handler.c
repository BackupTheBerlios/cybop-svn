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
 * @version $Revision: 1.18 $ $Date: 2004-04-06 13:50:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../constants.c"
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

    // Set array size which is equal for all arrays.
    int s = 0;
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

    // The parameters array.
    void* p = NULL;
    create_array((void*) &p, (void*) &s);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &p);

    // The parameters sizes array.
    void* ps = NULL;
    create_array((void*) &ps, (void*) &s);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &ps);
}

/**
 * Destroys the operation.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 */
void destroy_operation(void* p0, const void* p1) {

    log_message((void*) &INFO_LOG_LEVEL, "Destroy operation.");

    // Get array size which is equal for all arrays.
    int s = 0;
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

    // The parameters sizes array.
    void* ps = NULL;
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &ps);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_SIZE, (void*) &PARAMETERS_SIZES_ARRAY_INDEX);
    destroy_array((void*) &ps, (void*) &s);

    // The parameters array.
    void* p = NULL;
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &p);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &OPERATION_SIZE, (void*) &PARAMETERS_ARRAY_INDEX);
    destroy_array((void*) &p, (void*) &s);

    // Remove array size which is equal for all arrays.
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &OPERATION_SIZE, (void*) &ARRAY_SIZE_INDEX);

    // The operation.
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

    if (p3 != NULL) {

        int* ps = (int*) p3;

        if (p2 != NULL) {

            void** p = (int*) p2;

            if (p1 != NULL) {

                int* ts = (int*) p1;

                if (p0 != NULL) {

                    void** t = (int*) p0;

                    log_message((void*) &INFO_LOG_LEVEL, "Initialize operation.");

                    // The parameter size initially set to the persistent model size.
                    int size = *ps;

                    // The separator index.
                    int i = -1;
                    get_array_element_index(p2, (void*) &CHARACTER_ARRAY, p3, (void*) &OPERATION_PARAMETER_SEPARATOR, (void*) &i);

                    if (i != -1) {

                        // Reset parameter size if a separator is found and more parameters exist.
                        // Example: "operation,parameter"
                        // i = 9
                        // size = 9
                        size = i;
                    }

                    if (size > 0) {

                        // Get array size which is equal for all arrays.
                        int s = 0;
                        get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

                        // Get parameter array.
                        void* pa = NULL;
                        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &pa);

                        // Get parameter size array.
                        void* pas = NULL;
                        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &pas);

                        // The index for adding the parameter and its size.
                        int index = s;

                        // Increment array size.
                        s++;

                        // Resize arrays.
                        resize_array(pa, (void*) &s);
                        resize_array(pas, (void*) &s);

                        // Set array size which is equal for all arrays.
                        set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

                        if (index < s) {

                            // Set array elements.
                            set_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &index, p0);
                            set_array_element((void*) &pas, (void*) &POINTER_ARRAY, (void*) &index, (void*) &size);

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

                                    log_message((void*) &WARNING_LOG_LEVEL, "Could not initialize operation. There are no remaining parameters after the separator.");
                                }
                            }

                        } else {

                            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize operation. The index exceeds the size.");
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
 * Finds parts and their corresponding sizes from operation arrays.
 * Writes them as parts separated by a separator into the persistent model string.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 */
void finalize_operation(const void* p0, const void* p1, void* p2, void* p3) {

    if (p3 != NULL) {

        int* ps = (int*) p3;

        if (p2 != NULL) {

            void** p = (int*) p2;

            if (p1 != NULL) {

                int* ts = (int*) p1;

                if (p0 != NULL) {

                    void** t = (int*) p0;

                    log_message((void*) &INFO_LOG_LEVEL, "Finalize operation.");

                    // Get array size which is equal for all arrays.
                    int s = 0;
                    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);

                    // Get parameter array.
                    void* pa = NULL;
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_ARRAY_INDEX, (void*) &pa);

                    // Get parameter size array.
                    void* pas = NULL;
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_ARRAY_INDEX, (void*) &pas);

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

                                log_message((void*) &WARNING_LOG_LEVEL, "Could not finalize operation. There are no remaining parameters after the separator.");
                            }
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation. The index exceeds the size.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation. The transient model is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation. The transient model size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation. The persistent model is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize operation. The persistent model size is null.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
