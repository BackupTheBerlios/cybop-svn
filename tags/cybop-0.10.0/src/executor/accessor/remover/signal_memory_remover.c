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

#ifndef SIGNAL_MEMORY_REMOVER_SOURCE
#define SIGNAL_MEMORY_REMOVER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/signal_memory_memory_name.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Removes the signal memory element (signal).
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the index
 */
void remove_signal(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* sms = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* smc = (int*) p1;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove signal.");

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

                                                if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                                    if (*i < *smc) {

                                                        // Remove abstraction, model, details, priority, identification.
                                                        remove_array_elements(*a, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*ac, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*m, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*mc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*d, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*dc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*p, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
                                                        remove_array_elements(*id, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

                                                        // Decrement count.
                                                        (*smc)--;

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The index exceeds the count.");
                                                    }

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The index is negativ.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The identifications is null.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The priorities is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The details counts is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The details is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The models counts is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The models is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The abstractions counts is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The abstractions is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The signal memory count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The signal memory size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove signal. The index is null.");
    }
}

/* SIGNAL_MEMORY_REMOVER_SOURCE */
#endif
