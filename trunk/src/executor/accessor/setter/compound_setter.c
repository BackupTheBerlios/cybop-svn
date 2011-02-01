/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_SETTER_SOURCE
#define COMPOUND_SETTER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/compound_memory_name.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sets the compound element by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 * @param p4 the name
 * @param p5 the name count
 * @param p6 the name size
 * @param p7 the abstraction
 * @param p8 the abstraction count
 * @param p9 the abstraction size
 * @param p10 the model
 * @param p11 the model count
 * @param p12 the model size
 * @param p13 the details
 * @param p14 the details count
 * @param p15 the details size
 */
void set_compound_element_by_index(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* cs = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* cc = (int*) p1;

                if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set compound element by index.");

                    // The names, abstractions, models, details.
                    void** n = NULL_POINTER_MEMORY_MODEL;
                    void** nc = NULL_POINTER_MEMORY_MODEL;
                    void** ns = NULL_POINTER_MEMORY_MODEL;
                    void** a = NULL_POINTER_MEMORY_MODEL;
                    void** ac = NULL_POINTER_MEMORY_MODEL;
                    void** as = NULL_POINTER_MEMORY_MODEL;
                    void** m = NULL_POINTER_MEMORY_MODEL;
                    void** mc = NULL_POINTER_MEMORY_MODEL;
                    void** ms = NULL_POINTER_MEMORY_MODEL;
                    void** d = NULL_POINTER_MEMORY_MODEL;
                    void** dc = NULL_POINTER_MEMORY_MODEL;
                    void** ds = NULL_POINTER_MEMORY_MODEL;

                    // Get names, abstractions, models, details.
                    get_array_elements((void*) &n, p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &nc, p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &ns, p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &a, p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &ac, p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &as, p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &m, p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &mc, p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &ms, p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &d, p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &dc, p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                    get_array_elements((void*) &ds, p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

//??    fwprintf(stdout, L"TEST Set compound element by index ns: %i\n", *ns);
//??    fwprintf(stdout, L"TEST Set compound element by index nc: %i\n", *nc);
//??    fwprintf(stdout, L"TEST Set compound element by index n: %i\n", *n);

/*??
                    // CAUTION! If a compound model was properly allocated, then all arrays should exist!
                    // Therefore, check all arrays for null pointers here.

                    if (*n != *NULL_POINTER_MEMORY_MODEL) {

                        if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                            if (*ns != *NULL_POINTER_MEMORY_MODEL) {

                                if (*a != *NULL_POINTER_MEMORY_MODEL) {

                                    if (*ac != *NULL_POINTER_MEMORY_MODEL) {

                                        if (*as != *NULL_POINTER_MEMORY_MODEL) {

                                            if (*m != *NULL_POINTER_MEMORY_MODEL) {

                                                if (*mc != *NULL_POINTER_MEMORY_MODEL) {

                                                    if (*ms != *NULL_POINTER_MEMORY_MODEL) {

                                                        if (*d != *NULL_POINTER_MEMORY_MODEL) {

                                                            if (*dc != *NULL_POINTER_MEMORY_MODEL) {

                                                                if (*ds != *NULL_POINTER_MEMORY_MODEL) {
*/

                                                                    if (*i >= *cs) {

//??    fwprintf(stdout, L"TEST set compound element by index 00 i: %i\n", *i);
//??    fwprintf(stdout, L"TEST set compound element by index 00 cs: %i\n", *cs);
//??    fwprintf(stdout, L"TEST set compound element by index 00 cc: %i\n", *cc);
                                                                        // Increase size.
                                                                        *cs = (*cs * *COMPOUND_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;
//??    fwprintf(stdout, L"TEST set compound element by index 00 new cs: %i\n", *cs);

                                                                        //?? CAUTION! Does this reference &p0 cause an error? Check!
                                                                        reallocate_compound((void*) &p0, p1, p2);
                                                                    }

                                                                    if (*i < *cs) {

                                                                        // Set name, abstraction, model, details.
                                                                        set_array_elements(*n, (void*) &p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*nc, (void*) &p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ns, (void*) &p6, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*a, (void*) &p7, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ac, (void*) &p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*as, (void*) &p9, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*m, (void*) &p10, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*mc, (void*) &p11, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ms, (void*) &p12, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*d, (void*) &p13, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*dc, (void*) &p14, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ds, (void*) &p15, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                                                        // Increment count.
                                                                        (*cc)++;

                                                                    } else {

                                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The index exceeds the size.");
                                                                    }

/*??
                                                                } else {

                                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The models counts is null.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The models is null.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The abstractions is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The names sizes is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The names counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The names is null.");
                    }
*/

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The index is negative.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The compound count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The compound sizes is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The index is null.");
    }
}

/**
 * Sets the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void set_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set compound element by name.");

    // The element name index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Get compound element index.
    //
    // CAUTION! The name is given WITHOUT prefix here!
    // Correct example: "patient"
    // Incorrect examples: ".patient", "#patient"
    get_compound_element_index(p0, p1, p3, p4, (void*) &i);

//??    fwprintf(stdout, L"TEST element index %i\n", i);

    if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by name. A compound element with that name does already exist.");

    } else {

        // Could not get compound element index.
        // An element with that name does not exist.
        // Therefore, add compound element by name here.

        // CAUTION! Use compound count as index for adding new elements.
        set_compound_element_by_index(p0, p1, p2, p1, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    }
}

/* COMPOUND_SETTER_SOURCE */
#endif
