/*
 * Copyright (C) 1999-2009. Christian Heller.
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

#ifndef SIGNAL_MEMORY_GETTER_SOURCE
#define SIGNAL_MEMORY_GETTER_SOURCE

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
 * Gets the signal memory element (signal).
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the index
 * @param p3 the signal abstraction (Hand over as reference!)
 * @param p4 the signal abstraction count (Hand over as reference!)
 * @param p5 the signal model (Hand over as reference!)
 * @param p6 the signal model count (Hand over as reference!)
 * @param p7 the signal details (Hand over as reference!)
 * @param p8 the signal details count (Hand over as reference!)
 * @param p9 the signal priority (Hand over as reference!)
 * @param p10 the main signal identification (Hand over as reference!)
 */
void get_signal(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, int* p10) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* smc = (int*) p1;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get signal.");

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
            get_array_elements(p0, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &a, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &ac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &m, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &mc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &d, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &dc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) &p, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &id, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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

                                                    // Get abstraction, model, details, priority, identification.
                                                    get_array_elements(*a, p2, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*ac, p2, p4, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*m, p2, p5, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*mc, p2, p6, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*d, p2, p7, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*dc, p2, p8, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*p, p2, p9, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                    get_array_elements(*id, p2, p10, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The index exceeds the count.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The index is negativ.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The identifications is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The priorities is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The details counts is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The details is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The models counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The models is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The abstractions counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The abstractions is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get signal. The index is null.");
    }
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the index
 */
void get_highest_priority_signal_index(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* smc = (int*) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get highest priority signal index.");

            // The signal priorities.
            void** sp = NULL_POINTER_MEMORY_MODEL;

            // Get signal priorities.
            get_array_elements(p0, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) &sp, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

            if (*sp != *NULL_POINTER_MEMORY_MODEL) {

                // The loop variable.
                int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The priority.
                int** prio = (int**) NULL_POINTER_MEMORY_MODEL;
                // The highest priority.
                // CAUTION! Do not initialise it with zero, because then the
                // priority will not be set, due to the comparison: if (prio > h).
                // The smallest possible priority is zero and greater than minus one.
                int h = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (j >= *smc) {

                        break;
                    }

                    // Get signal priority.
                    get_array_elements(*sp, (void*) &j, (void*) &prio, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                    if (**prio > h) {

                        h = **prio;

                        // If a signal with higher priority is found,
                        // then its index is the one to be returned.
                        *i = j;
                    }

                    // Reset priority.
                    prio = (int**) NULL_POINTER_MEMORY_MODEL;

                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get highest priority signal index. The signal priorities is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get highest priority signal index. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get highest priority signal index. The index is null.");
    }
}

/**
 * Sets the new signal identification.
 *
 * @param p0 the signal identification (Hand over as reference!)
 * @param p1 the signal identification value
 */
void set_new_signal_identification(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* v = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** id = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set new signal identification.");

            //
            // CAUTION! These comparisons can be extended to infinity!
            // Unfortunately, no other solution has been found.
            //
            // The reason why these comparisons are necessary is that allocations
            // are not allowed here and integer constants have to be used.
            // This is because "receive" threads (linux console, x window system,
            // tcp sockets with http requests etc.) will access this function
            // when placing signals into the signal memory (queue).
            // If this function (and thereby the threads) allocated a "signal identification"
            // value, this would result in an error of the following kind:
            //
            // *** glibc detected *** malloc(): memory corruption (fast): 0x080e0470 ***
            // Aborted
            //
            // CAUTION! The following advices on pointer assignment are IMPORTANT.
            // If not followed, the whole CYBOI system might get mixed up,
            // with NULL_POINTER_MEMORY_MODEL having the same address as some NUMBER_X_INTEGER
            // constants etc., resulting in unpredictable, strange errors!
            // Here are the advices:
            // - Do NOT assign the pointers directly, for example:
            //   *id = NUMBER_0_INTEGER_MEMORY_MODEL;
            // - Assigning the value is effectively the same and also NOT correct:
            //   *id = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;
            // - Instead, DO assign a pointer's reference, for example:
            //   *id = &NUMBER_0_INTEGER_MEMORY_MODEL;
            //

            if (*v == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_0_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_1_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_2_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_2_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_3_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_3_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_4_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_4_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_5_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_5_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_6_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_6_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_7_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_7_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_8_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_8_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_9_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_9_INTEGER_MEMORY_MODEL;

            } else if (*v == *NUMBER_10_INTEGER_MEMORY_MODEL) {

                *id = &NUMBER_10_INTEGER_MEMORY_MODEL;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set new signal identification. The signal identification is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set new signal identification. The signal identification value is null.");
    }
}

/**
 * Gets a new signal identification.
 *
 * The new identification is calculated as:
 * maximum signal identification + 1
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal identification (Hand over as reference!)
 */
void get_new_signal_identification(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* smc = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get new signal identification.");

        // The signal identifications.
        void** ids = NULL_POINTER_MEMORY_MODEL;

        // Get signal identifications.
        get_array_elements(p0, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &ids, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

        if (*ids != *NULL_POINTER_MEMORY_MODEL) {

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The maximum signal identification value.
            //
            // CAUTION! Do not initialise it with zero, because then the
            // maximum will not be set, due to the comparison: if (id > max).
            // The smallest possible priority is zero and greater than minus one.
            int max = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // The identification.
            int** id = (int**) NULL_POINTER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *smc) {

                    break;
                }

                // Get signal identification.
                get_array_elements(*ids, (void*) &j, (void*) &id, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                if (**id > max) {

                    max = **id;
                }

                // Reset identification.
                id = (int**) NULL_POINTER_MEMORY_MODEL;

                // Increment loop variable.
                j++;
            }

            // Increment maximum signal identification value, so that the
            // next signal will receive a differing identification value.
            //
            // If no signal was found, then minus one will be incremented,
            // so that the first signal always receives the identification zero.
            max++;

            // Set new signal identification using the maximum value.
            set_new_signal_identification(p2, (void*) &max);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get new signal identification. The signal identifications is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get new signal identification. The signal memory count is null.");
    }
}

/* SIGNAL_MEMORY_GETTER_SOURCE */
#endif
