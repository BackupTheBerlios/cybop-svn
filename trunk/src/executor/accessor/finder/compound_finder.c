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
 * @version $RCSfile: accessor.c,v $ $Revision: 1.24 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_FINDER_SOURCE
#define COMPOUND_FINDER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/accessor/getter/array_getter.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/comparator/count_array_comparator.c"

/**
 * Finds the compound element.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the element name
 * @param p3 the element name count
 * @param p4 the index (Hand over as reference!)
 */
void find_compound(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p4;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* cc = (int*) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Find compound element.");

            // The element names.
            void** n = NULL_POINTER_MEMORY_MODEL;
            void** nc = NULL_POINTER_MEMORY_MODEL;

            // Get element names.
            get_array_elements((void*) &n, p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &nc, p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (*n != *NULL_POINTER_MEMORY_MODEL) {

                if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The name.
                    void** n1 = NULL_POINTER_MEMORY_MODEL;
                    void** nc1 = NULL_POINTER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *cc) {

                            break;
                        }

                        // Get element name.
                        get_array_elements((void*) &n1, *n, (void*) &j, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                        get_array_elements((void*) &nc1, *nc, (void*) &j, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                        if (*n1 != *NULL_POINTER_MEMORY_MODEL) {

                            if (*nc1 != *NULL_POINTER_MEMORY_MODEL) {

                                compare_array_count((void*) &r, p2, p3, *n1, *nc1);

                                if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                    *i = j;

                                    break;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not find compound element. The name count is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not find compound element. The name is null.");
                        }

                        // Reset name and name count.
                        n1 = NULL_POINTER_MEMORY_MODEL;
                        nc1 = NULL_POINTER_MEMORY_MODEL;

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not find compound element. The part names counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not find compound element. The part names is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not find compound element. The compound count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not find compound element. The index is null.");
    }
*/
}

/* COMPOUND_FINDER_SOURCE */
#endif
