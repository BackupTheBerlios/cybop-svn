/*
 * $RCSfile: operation_parser.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2004-08-26 23:44:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_PARSER_SOURCE
#define OPERATION_PARSER_SOURCE

#include "../global/abstraction_constants.c"
#include "../global/constant.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

//
// This file handles an operation, also known as system.
//
// The persistent model string contains, separated by a separator:
// - operation
// - operand 0
// - operand 1
// - operand 2
// - operand ...
//
// Example:
// operation,operand0,operand1,operand2,...
//
// The transient model contains the operation, its operands and their sizes
// as separate array elements.
//
// An operation transports an input state through logics to an output state.
// The logics is kept as function pointer.
// Many inputs and outputs are possible.
// Statics models are kept as hierarchical paths.
//
// Operations can be stored as signals in a signal memory.
//

/**
 * Parses the byte stream and creates an operation model from it.
 *
 * Finds persistent model parts which are separated by a separator.
 * Adds these parts and their corresponding counts as separate elements
 * to the operation array.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void parse_operation(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p2 != NULL_POINTER) {

                int* ds = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* dc = (int*) p1;

                        log_message((void*) &INFO_LOG_LEVEL, (void*) &INITIALIZE_OPERATION_MESSAGE, (void*) &INITIALIZE_OPERATION_MESSAGE_COUNT);

                        // The parameter count initially set to the persistent model count.
                        int count = *sc;

    fprintf(stderr, "initop p3: %s\n", *((char**) p3));
    fprintf(stderr, "initop p4: %i\n", *((int*) p4));
    fprintf(stderr, "initop count: %i\n", count);

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
                            void* pas = NULL_POINTER;

                            // Get elements.
                            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &pa);
                            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pac);
                            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &pas);

                            // The index for adding the parameter and its count.
                            int i = *dc;

    fprintf(stderr, "initop i: %i\n", i);

                            if (i >= 0) {

                                if (i == *ds) {

                                    // Increase size.
                                    *ds = *ds * OPERATION_RESIZE_FACTOR + 1;

                                    // Resize elements.
                                    resize_array((void*) &pa, (void*) &POINTER_ARRAY, p2);
                                    resize_array((void*) &pac, (void*) &INTEGER_ARRAY, p2);
                                    resize_array((void*) &pas, (void*) &INTEGER_ARRAY, p2);
                                }

                                if (i < *ds) {

                                    // Initialize transient parameter
                                    // and its count and size.
                                    void* tp = NULL_POINTER;
                                    int tpc = 0;
                                    int tps = 0;

                                    // Create transient parameter
                                    // and its count and size.
                                    create((void*) &tp, (void*) &tps,
                                        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

    fprintf(stderr, "initop tp before: %s\n", tp);
    fprintf(stderr, "initop tpc before: %i\n", tpc);
    fprintf(stderr, "initop tps before: %i\n", tps);

                                    // Initialize transient parameter
                                    // and its count and size.
/*??
                                    initialize_model((void*) &tp, (void*) &tpc, (void*) &tps,
                                        p3, (void*) &count,
                                        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
*/

    fprintf(stderr, "initop tp after: %s\n", tp);
    fprintf(stderr, "initop tpc after: %i\n", tpc);
    fprintf(stderr, "initop tps after: %i\n", tps);

                                    // Set transient parameter
                                    // and its count and size.
                                    set_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &i, (void*) &tp);
                                    set_array_element((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &tpc);
                                    set_array_element((void*) &pas, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &tps);

                                    // Increment count.
                                    (*dc)++;

                                    // If separator was found, then process
                                    // the remaining parameters.
                                    if (si != -1) {

                                        // The size of the remaining parameters.
                                        // Example: "operation,parameter"
                                        // *sc = 19
                                        // si = 9
                                        // rc = *sc - (si + 1) = 9
                                        int rc = *sc - (si + 1);

                                        if (rc > 0) {

                                            // The remaining parameters.
                                            void* r = *s + si + 1;

                                            // Call procedure recursively if more parameters
                                            // are following after the separator.
                                            // Set index of remaining string to one after the separator.
                                            parse_operation(p0, p1, p2, (void*) &r, (void*) &rc);

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

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model count is null.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialize operation. The transient model size is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_PARSE_INTEGER_THE_SOURCE_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Serializes the operation model and creates a byte stream from it.
 *
 * Finds parts and their corresponding counts from operation arrays.
 * Writes them as parts separated by a separator into the persistent model string.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialize_operation(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

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

/* OPERATION_PARSER_SOURCE */
#endif
