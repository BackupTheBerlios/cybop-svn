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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_REALLOCATOR_SOURCE
#define COMPOUND_REALLOCATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/compound_memory_name.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../logger/logger.c"

/**
 * Reallocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the compound count
 * @param p2 the compound size
 */
void reallocate_compound(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** c = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reallocate compound.");

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
        get_array_elements((void*) &n, *c, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &nc, *c, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &ns, *c, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &a, *c, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &ac, *c, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &as, *c, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &m, *c, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &mc, *c, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &ms, *c, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &d, *c, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &dc, *c, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &ds, *c, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

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

                                                        // Reallocate names, abstractions, models, details.
                                                        reallocate_array(n, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(nc, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(ns, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(a, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(ac, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(as, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(m, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(mc, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(ms, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(d, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(dc, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        reallocate_array(ds, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

/*?? TODO!
                                                        // Set new array reference.
                                                        // CAUTION! If an array gets reallocated, a new array is
                                                        // created and the contents of the old array gets copied.
                                                        // Therefore, the new array reference needs to be set.
                                                        // The old array gets destroyed automatically by reallocate.
                                                        overwrite_array(*c, (void*) n, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) nc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) ns, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) ac, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) as, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) mc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) ms, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) dc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        overwrite_array(*c, (void*) ds, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
*/

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

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate compound. The compound is null.");
    }
}

/* COMPOUND_REALLOCATOR_SOURCE */
#endif
