/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: signal_memory_accessor.c,v $ $Revision: 1.29 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_SETTER_SOURCE
#define SIGNAL_MEMORY_SETTER_SOURCE

#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/signal_memory_memory_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../variable/reallocation_factor.c"

/**
 * Sets the signal memory element (signal).
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the signal abstraction (Hand over as reference!)
 * @param p4 the signal abstraction count (Hand over as reference!)
 * @param p5 the signal model (Hand over as reference!)
 * @param p6 the signal model count (Hand over as reference!)
 * @param p7 the signal details (Hand over as reference!)
 * @param p8 the signal details count (Hand over as reference!)
 * @param p9 the signal priority (Hand over as reference!)
 * @param p10 the signal identification (Hand over as reference!)
 */
void set_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sms = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* smc = (int*) p1;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set signal.");

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
            get_array_elements(p0, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &a, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &ac, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &m, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &mc, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &d, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &dc, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) &p, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &id, (void*) POINTER_MEMORY_ABSTRACTION);

            if (*a != *NULL_POINTER_MEMORY_MODEL) {

                if (*ac != *NULL_POINTER_MEMORY_MODEL) {

                    if (*m != *NULL_POINTER_MEMORY_MODEL) {

                        if (*mc != *NULL_POINTER_MEMORY_MODEL) {

                            if (*d != *NULL_POINTER_MEMORY_MODEL) {

                                if (*dc != *NULL_POINTER_MEMORY_MODEL) {

                                    if (*p != *NULL_POINTER_MEMORY_MODEL) {

                                        if (*id != *NULL_POINTER_MEMORY_MODEL) {

                                            // The index.
                                            int i = *smc;

                                            if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                                if (i == *sms) {

                                                    // Increase size.
                                                    *sms = (*sms * *SIGNAL_MEMORY_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;

                                                    // Reallocate abstractions, models, details, priorities, identifications.
                                                    reallocate_array(a, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(ac, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(m, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(mc, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(d, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(dc, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(p, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    reallocate_array(id, p1, p2, (void*) POINTER_MEMORY_ABSTRACTION);

                                                    // Set new array reference.
                                                    // CAUTION! If an array gets reallocated, a new array is
                                                    // created and the contents of the old array gets copied.
                                                    // Therefore, the new array reference needs to be set.
                                                    // The old array gets destroyed automatically by reallocate.
                                                    set_array_elements(p0, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) ac, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) mc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) dc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) p, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(p0, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) id, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                }

                                                if (i < *sms) {

                                                    // Set abstraction, model, details, priority, identification.
                                                    set_array_elements(*a, (void*) &i, (void*) p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*ac, (void*) &i, (void*) p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*m, (void*) &i, (void*) p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*mc, (void*) &i, (void*) p6, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*d, (void*) &i, (void*) p7, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*dc, (void*) &i, (void*) p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*p, (void*) &i, (void*) p9, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                    set_array_elements(*id, (void*) &i, (void*) p10, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);

                                                    // Increment count.
                                                    (*smc)++;

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The index exceeds the size.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The index is negativ.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The identifications is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The priorities is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The details counts is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The details is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The models counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The models is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The abstractions counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The abstractions is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set signal. The signal memory size is null.");
    }
}

/* SIGNAL_MEMORY_SETTER_SOURCE */
#endif
