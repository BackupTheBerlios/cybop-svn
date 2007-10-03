/*
 * $RCSfile: signal_memory_accessor.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.23 $ $Date: 2007-10-03 23:40:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_ACCESSOR_SOURCE
#define SIGNAL_MEMORY_ACCESSOR_SOURCE

#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

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

    if (p2 != *NULL_POINTER) {

        int* sms = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* smc = (int*) p1;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Set signal.");

            // The abstractions, models, details, priorities, identifications.
            void** a = NULL_POINTER;
            void** ac = NULL_POINTER;
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** d = NULL_POINTER;
            void** dc = NULL_POINTER;
            void** p = NULL_POINTER;
            void** id = NULL_POINTER;

            // Get abstractions, models, details, priorities, identifications.
            get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

            if (*a != *NULL_POINTER) {

                if (*ac != *NULL_POINTER) {

                    if (*m != *NULL_POINTER) {

                        if (*mc != *NULL_POINTER) {

                            if (*d != *NULL_POINTER) {

                                if (*dc != *NULL_POINTER) {

                                    if (*p != *NULL_POINTER) {

                                        if (*id != *NULL_POINTER) {

                                            // The index.
                                            int i = *smc;

                                            if (i >= *NUMBER_0_INTEGER) {

                                                if (i == *sms) {

                                                    // Increase size.
                                                    *sms = (*sms * *SIGNAL_MEMORY_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER;

                                                    // Reallocate abstractions, models, details, priorities, identifications.
                                                    reallocate_array(a, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(ac, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(m, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(mc, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(d, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(dc, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(p, p1, p2, (void*) POINTER_ARRAY);
                                                    reallocate_array(id, p1, p2, (void*) POINTER_ARRAY);

                                                    // Set new array reference.
                                                    // CAUTION! If an array gets reallocated, a new array is
                                                    // created and the contents of the old array gets copied.
                                                    // Therefore, the new array reference needs to be set.
                                                    // The old array gets destroyed automatically by reallocate.
                                                    set_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) a, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) ac, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) m, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) mc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) d, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) dc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) p, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) id, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                }

                                                if (i < *sms) {

                                                    // Set abstraction, model, details, priority, identification.
                                                    set_array_elements(*a, (void*) &i, (void*) p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*ac, (void*) &i, (void*) p4, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*m, (void*) &i, (void*) p5, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*mc, (void*) &i, (void*) p6, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*d, (void*) &i, (void*) p7, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*dc, (void*) &i, (void*) p8, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*p, (void*) &i, (void*) p9, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                    set_array_elements(*id, (void*) &i, (void*) p10, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

                                                    // Increment count.
                                                    (*smc)++;

                                                } else {

                                                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The index exceeds the size.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The index is negativ.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The identifications is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The priorities is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The details counts is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The details is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The models counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The models is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The abstractions counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The abstractions is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set signal. The signal memory size is null.");
    }
}

/**
 * Removes the signal memory element (signal).
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the index
 */
void remove_signal(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != *NULL_POINTER) {

            int* sms = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* smc = (int*) p1;

                log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Remove signal.");

                // The abstractions, models, details, priorities, identifications.
                void** a = NULL_POINTER;
                void** ac = NULL_POINTER;
                void** m = NULL_POINTER;
                void** mc = NULL_POINTER;
                void** d = NULL_POINTER;
                void** dc = NULL_POINTER;
                void** p = NULL_POINTER;
                void** id = NULL_POINTER;

                // Get abstractions, models, details, priorities, identifications.
                get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

                if (*a != *NULL_POINTER) {

                    if (*ac != *NULL_POINTER) {

                        if (*m != *NULL_POINTER) {

                            if (*mc != *NULL_POINTER) {

                                if (*d != *NULL_POINTER) {

                                    if (*dc != *NULL_POINTER) {

                                        if (*p != *NULL_POINTER) {

                                            if (*id != *NULL_POINTER) {

                                                if (*i >= *NUMBER_0_INTEGER) {

                                                    if (*i < *smc) {

                                                        // Remove abstraction, model, details, priority, identification.
                                                        remove_array_elements(*a, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*ac, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*m, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*mc, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*d, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*dc, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*p, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                        remove_array_elements(*id, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

                                                        // Decrement count.
                                                        (*smc)--;

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The index exceeds the count.");
                                                    }

                                                } else {

                                                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The index is negativ.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The identifications is null.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The priorities is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The details counts is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The details is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The models counts is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The models is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The abstractions counts is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The abstractions is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The signal memory count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The signal memory size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not remove signal. The index is null.");
    }
}

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

    if (p2 != *NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* smc = (int*) p1;

            log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Get signal.");

            // The abstractions, models, details, priorities, identifications.
            void** a = NULL_POINTER;
            void** ac = NULL_POINTER;
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** d = NULL_POINTER;
            void** dc = NULL_POINTER;
            void** p = NULL_POINTER;
            void** id = NULL_POINTER;

            // Get abstractions, models, details, priorities, identifications.
            get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

            if (*a != *NULL_POINTER) {

                if (*ac != *NULL_POINTER) {

                    if (*m != *NULL_POINTER) {

                        if (*mc != *NULL_POINTER) {

                            if (*d != *NULL_POINTER) {

                                if (*dc != *NULL_POINTER) {

                                    if (*p != *NULL_POINTER) {

                                        if (*id != *NULL_POINTER) {

                                            if (*i >= *NUMBER_0_INTEGER) {

                                                if (*i < *smc) {

                                                    // Get abstraction, model, details, priority, identification.
                                                    get_array_elements(*a, p2, p3, (void*) POINTER_ARRAY);
                                                    get_array_elements(*ac, p2, p4, (void*) POINTER_ARRAY);
                                                    get_array_elements(*m, p2, p5, (void*) POINTER_ARRAY);
                                                    get_array_elements(*mc, p2, p6, (void*) POINTER_ARRAY);
                                                    get_array_elements(*d, p2, p7, (void*) POINTER_ARRAY);
                                                    get_array_elements(*dc, p2, p8, (void*) POINTER_ARRAY);
                                                    get_array_elements(*p, p2, p9, (void*) POINTER_ARRAY);
                                                    get_array_elements(*id, p2, p10, (void*) POINTER_ARRAY);

                                                } else {

                                                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The index exceeds the count.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The index is negativ.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The identifications is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The priorities is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The details counts is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The details is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The models counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The models is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The abstractions counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The abstractions is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get signal. The index is null.");
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

    if (p2 != *NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* smc = (int*) p1;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Get highest priority signal index.");

            // The signal priorities.
            void** sp = NULL_POINTER;

            // Get signal priorities.
            get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &sp, (void*) POINTER_ARRAY);

            if (*sp != *NULL_POINTER) {

                // The loop variable.
                int j = *NUMBER_0_INTEGER;
                // The priority.
                int** prio = (int**) NULL_POINTER;
                // The highest priority.
                // CAUTION! Do not initialise it with zero, because then the
                // priority will not be set, due to the comparison: if (prio > h).
                // The smallest possible priority is zero and greater than minus one.
                int h = *NUMBER_MINUS_1_INTEGER;

                while (*NUMBER_1_INTEGER) {

                    if (j >= *smc) {

                        break;
                    }

                    // Get signal priority.
                    get_array_elements(*sp, (void*) &j, (void*) &prio, (void*) POINTER_ARRAY);

                    if (**prio > h) {

                        h = **prio;

                        // If a signal with higher priority is found,
                        // then its index is the one to be returned.
                        *i = j;
                    }

                    // Reset priority.
                    prio = (int**) NULL_POINTER;

                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get highest priority signal index. The signal priorities is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get highest priority signal index. The signal memory count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get highest priority signal index. The index is null.");
    }
}

/**
 * Sets the new signal identification.
 *
 * @param p0 the signal identification (Hand over as reference!)
 * @param p1 the signal identification value
 */
void set_new_signal_identification(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* v = (int*) p1;

        if (p0 != *NULL_POINTER) {

            void** id = (void**) p0;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Set new signal identification.");

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
            // CAUTION! The following advice on pointer assignment is IMPORTANT.
            // If not followed, the whole CYBOI system might get mixed up,
            // with NULL_POINTER having the same address as some NUMBER_X_INTEGER
            // constants etc., resulting in unpredictable, strange errors!
            // Here are the advices:
            // - Do NOT assign the pointers directly, for example:
            //   *id = NUMBER_0_INTEGER;
            // - Assigning the value is effectively the same and also NOT correct:
            //   *id = NUMBER_0_INTEGER_ARRAY;
            // - Instead, DO assign a pointer's reference, for example:
            //   *id = &NUMBER_0_INTEGER;
            //

            if (*v == *NUMBER_0_INTEGER) {

                *id = &NUMBER_0_INTEGER;

            } else if (*v == *NUMBER_1_INTEGER) {

                *id = &NUMBER_1_INTEGER;

            } else if (*v == *NUMBER_2_INTEGER) {

                *id = &NUMBER_2_INTEGER;

            } else if (*v == *NUMBER_3_INTEGER) {

                *id = &NUMBER_3_INTEGER;

            } else if (*v == *NUMBER_4_INTEGER) {

                *id = &NUMBER_4_INTEGER;

            } else if (*v == *NUMBER_5_INTEGER) {

                *id = &NUMBER_5_INTEGER;

            } else if (*v == *NUMBER_6_INTEGER) {

                *id = &NUMBER_6_INTEGER;

            } else if (*v == *NUMBER_7_INTEGER) {

                *id = &NUMBER_7_INTEGER;

            } else if (*v == *NUMBER_8_INTEGER) {

                *id = &NUMBER_8_INTEGER;

            } else if (*v == *NUMBER_9_INTEGER) {

                *id = &NUMBER_9_INTEGER;

            } else if (*v == *NUMBER_10_INTEGER) {

                *id = &NUMBER_10_INTEGER;
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set new signal identification. The signal identification is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not set new signal identification. The signal identification value is null.");
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

    if (p1 != *NULL_POINTER) {

        int* smc = (int*) p1;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Get new signal identification.");

        // The signal identifications.
        void** ids = NULL_POINTER;

        // Get signal identifications.
        get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &ids, (void*) POINTER_ARRAY);

        if (*ids != *NULL_POINTER) {

            // The loop variable.
            int j = *NUMBER_0_INTEGER;
            // The maximum signal identification value.
            //
            // CAUTION! Do not initialise it with zero, because then the
            // maximum will not be set, due to the comparison: if (id > max).
            // The smallest possible priority is zero and greater than minus one.
            int max = *NUMBER_MINUS_1_INTEGER;
            // The identification.
            int** id = (int**) NULL_POINTER;

            while (*NUMBER_1_INTEGER) {

                if (j >= *smc) {

                    break;
                }

                // Get signal identification.
                get_array_elements(*ids, (void*) &j, (void*) &id, (void*) POINTER_ARRAY);

                if (**id > max) {

                    max = **id;
                }

                // Reset identification.
                id = (int**) NULL_POINTER;

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

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get new signal identification. The signal identifications is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get new signal identification. The signal memory count is null.");
    }
}

/* SIGNAL_MEMORY_ACCESSOR_SOURCE */
#endif
