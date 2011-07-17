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
 * @version $RCSfile: signal_memory_accessor.c,v $ $Revision: 1.29 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_REPLACER_SOURCE
#define SIGNAL_MEMORY_REPLACER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/signal_memory_memory_name.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/memoriser/reallocator/signal_memory_reallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Replaces the signal memory element.
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
void replace_signal_memory(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sms = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* smc = (int*) p1;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace signal memory element.");

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
            get_array_elements((void*) &a, p0, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &ac, p0, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &m, p0, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &mc, p0, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &d, p0, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &dc, p0, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &p, p0, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            get_array_elements((void*) &id, p0, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

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
                                                    *sms = (*sms * *ARRAY_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;

                                                    reallocate_signal_memory((void*) &p0, p1, p2);
                                                }

                                                if (i < *sms) {

                                                    // Set abstraction, model, details, priority, identification.
                                                    replace_array(*a, (void*) p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*ac, (void*) p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*m, (void*) p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*mc, (void*) p6, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*d, (void*) p7, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*dc, (void*) p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*p, (void*) p9, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                    replace_array(*id, (void*) p10, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                                    // Increment count.
                                                    (*smc)++;

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The index exceeds the size.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The index is negativ.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The identifications is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The priorities is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The details counts is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The details is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The models counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The models is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The abstractions counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The abstractions is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace signal memory element. The signal memory size is null.");
    }
}

/* SIGNAL_MEMORY_REPLACER_SOURCE */
#endif
