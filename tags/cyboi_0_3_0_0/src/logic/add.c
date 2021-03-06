/*
 * $RCSfile: add.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2004-09-12 23:04:40 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

#include "../accessor/compound_accessor.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Adds two integer summands resulting in the integer sum.
 *
 * @param p0 the sum
 * @param p1 the summand 1
 * @param p2 the summand 2
 */
void add_integers(void* p0, const void* p1, const void* p2) {

    if (p2 != NULL_POINTER) {

        int* summand2 = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* summand1 = (int*) p1;

            if (p0 != NULL_POINTER) {

                int* sum = (int*) p0;

                *sum = *summand1 + *summand2;

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Adds two primitive summands resulting in the primitive sum.
 *
 * @param p0 the sum
 * @param p1 the summand 1
 * @param p2 the summand 2
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void add_primitives(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* ac = (int*) p4;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*ac == INTEGER_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    add_integers(p0, p1, p2);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Adds two summands resulting in the sum.
 *
 * CYBOL Examples:
 *
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,summand 1,summand 2,sum /-->
 *
 * <part name="add_two_numbers" part_abstraction="operation" part_location="inline"
 *      part_model="add,application.summand1,application.summand2,application.sum"/>
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 */
void add(const void* p0, const void* p1, void* p2, void* p3, void* p4) {

/*??
    if (p0 != NULL_POINTER) {

        int* sc = (int*) p0;

        if (*sc == 4) {

            // Initialize persistent summand 1-, summand 2- and sum model
            // and their counts and sizes.
            void* ps1m = NULL_POINTER;
            int ps1mc = 0;
            int ps1ms = 0;
            void* ps2m = NULL_POINTER;
            int ps2mc = 0;
            int ps2ms = 0;
            void* psumm = NULL_POINTER;
            int psummc = 0;
            int psumms = 0;

            // CAUTION! The parameter at index 0 is the logic/ operation name.
            // Input and output parameters start with index 1.

            // The loop variable.
            int j = 1;

            while (1) {

                if (j >= *sc) {

                    break;
                }

                // CAUTION! The parameter at index 0 is the logic/ operation name.
                // Input and output parameters start with index 1.

                if (j == 1) {

                    // Get persistent summand 1 model and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ps1m);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ps1mc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ps1ms);

                } else if (j == 2) {

                    // Get persistent summand 2 model and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ps2m);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ps2mc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ps2ms);

                } else if (j == 3) {

                    // Get persistent sum model and its count and size.
                    get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &psumm);
                    get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &psummc);
                    get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &psumms);
                }

                j++;
            }

            // Initialize transient summand 1-, summand 2- and sum model, abstraction
            // and their counts and sizes.
            void* ts1m = NULL_POINTER;
            int ts1mc = 0;
            int ts1ms = 0;
            void* ts1a = NULL_POINTER;
            int ts1ac = 0;
            int ts1as = 0;
            void* ts2m = NULL_POINTER;
            int ts2mc = 0;
            int ts2ms = 0;
            void* ts2a = NULL_POINTER;
            int ts2ac = 0;
            int ts2as = 0;
            void* tsumm = NULL_POINTER;
            int tsummc = 0;
            int tsumms = 0;
            void* tsuma = NULL_POINTER;
            int tsumac = 0;
            int tsumas = 0;

/*??
            // Get transient summand 1-, summand 2- and sum model
            // and their counts and sizes.
            get_compound_part_by_name(p4, p5, p6,
                (void*) &ps1m, (void*) &ps1mc, (void*) &ps1ms,
                (void*) &ts1m, (void*) &ts1mc, (void*) &ts1ms,
                (void*) &ts1a, (void*) &ts1ac, (void*) &ts1as,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
            get_compound_part_by_name(p4, p5, p6,
                (void*) &ps2m, (void*) &ps2mc, (void*) &ps2ms,
                (void*) &ts2m, (void*) &ts2mc, (void*) &ts2ms,
                (void*) &ts2a, (void*) &ts2ac, (void*) &ts2as,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
            get_compound_part_by_name(p4, p5, p6,
                (void*) &psumm, (void*) &psummc, (void*) &psumms,
                (void*) &tsumm, (void*) &tsummc, (void*) &tsumms,
                (void*) &tsuma, (void*) &tsumac, (void*) &tsumas,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
*/

/*??
            //
            // CAUTION! Only addition of primitives with equal type is allowed!
            //

            // The comparison result.
            int r = 0;

            // Compare summand 1- and sum abstraction.
            if (tsumac == ts1ac) {

                compare_array_elements((void*) &tsuma, (void*) &ts1a, (void*) &CHARACTER_ARRAY, (void*) &tsumac, (void*) &r);

                if (r == 1) {

                    r = 0;

                    // Compare summand 2- and sum abstraction.
                    if (tsumac == ts2ac) {

                        compare_array_elements((void*) &tsuma, (void*) &ts2a, (void*) &CHARACTER_ARRAY, (void*) &tsumac, (void*) &r);

                        if (r == 1) {

                            // Add summand 1 and summand 2 resulting in the sum.
                            add_primitives((void*) &ts1m, (void*) &ts2m, (void*) &tsumm, (void*) &tsuma, (void*) &tsumac);
                        }
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
    }
*/
}

/* ADD_SOURCE */
#endif
