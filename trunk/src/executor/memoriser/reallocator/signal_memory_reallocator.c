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

#ifndef SIGNAL_MEMORY_REALLOCATOR_SOURCE
#define SIGNAL_MEMORY_REALLOCATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Reallocates the signal memory.
 *
 * @param p0 the signal memory (Hand over as reference!)
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 */
void reallocate_signal_memory(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** sm = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reallocate signal memory.");

        // The abstractions, models, details, priorities, identifications.
        void** a = NULL_POINTER_MEMORY_MODEL;
        void** ac = NULL_POINTER_MEMORY_MODEL;
        void** m = NULL_POINTER_MEMORY_MODEL;
        void** mc = NULL_POINTER_MEMORY_MODEL;
        void** d = NULL_POINTER_MEMORY_MODEL;
        void** dc = NULL_POINTER_MEMORY_MODEL;
        void** p = NULL_POINTER_MEMORY_MODEL;
        void** id = NULL_POINTER_MEMORY_MODEL;

        // Get abstractions, models, details, priorities, identifications.
        get_array_elements((void*) &a, *sm, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &ac, *sm, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &m, *sm, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &mc, *sm, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &d, *sm, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &dc, *sm, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &p, *sm, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &id, *sm, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (*a != *NULL_POINTER_MEMORY_MODEL) {

            if (*ac != *NULL_POINTER_MEMORY_MODEL) {

                if (*m != *NULL_POINTER_MEMORY_MODEL) {

                    if (*mc != *NULL_POINTER_MEMORY_MODEL) {

                        if (*d != *NULL_POINTER_MEMORY_MODEL) {

                            if (*dc != *NULL_POINTER_MEMORY_MODEL) {

                                if (*p != *NULL_POINTER_MEMORY_MODEL) {

                                    if (*id != *NULL_POINTER_MEMORY_MODEL) {

                                        // Reallocate abstractions, models, details, priorities, identifications.
                                        reallocate_array(a, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(ac, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(m, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(mc, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(d, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(dc, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(p, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        reallocate_array(id, p1, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                        // Set new array reference.
                                        // CAUTION! If an array gets reallocated, a new array is
                                        // created and the contents of the old array gets copied.
                                        // Therefore, the new array reference needs to be set.
                                        // The old array gets destroyed automatically by reallocate.
                                        replace_array(*sm, (void*) a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) ac, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) mc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) dc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) p, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                        replace_array(*sm, (void*) id, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The identifications is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The priorities is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The details counts is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The details is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The models counts is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The models is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The abstractions counts is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The abstractions is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not reallocate signal memory. The signal memory is null.");
    }
}

/* SIGNAL_MEMORY_REALLOCATOR_SOURCE */
#endif
