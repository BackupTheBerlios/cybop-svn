/*
 * $RCSfile: signal_memory_accessor.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.17 $ $Date: 2005-01-24 22:47:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_ACCESSOR_SOURCE
#define SIGNAL_MEMORY_ACCESSOR_SOURCE

#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the signal abstraction
 * @param p4 the signal abstraction count
 * @param p5 the signal model
 * @param p6 the signal model count
 * @param p7 the signal details
 * @param p8 the signal details count
 * @param p9 the signal priority
 * @param p10 the signal id
 */
void set_signal(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5,
    const void* p6, const void* p7, const void* p8,
    const void* p9, const void* p10) {

    if (p2 != NULL_POINTER) {

        int* s = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            log_message_debug("Set signal.");

            // The abstractions, models, details, priorities, identifications.
            void** a = POINTER_NULL_POINTER;
            void** ac = POINTER_NULL_POINTER;
            void** m = POINTER_NULL_POINTER;
            void** mc = POINTER_NULL_POINTER;
            void** d = POINTER_NULL_POINTER;
            void** dc = POINTER_NULL_POINTER;
            void** p = POINTER_NULL_POINTER;
            void** id = POINTER_NULL_POINTER;

            // Get abstractions, models, details, priorities, identifications.
            get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

            // The index.
            int i = *c;

            if (i >= 0) {

                if (i == *s) {

                    // Increase size.
                    *s = (*s * *SIGNAL_MEMORY_RESIZE_FACTOR) + 1;

                    // Resize abstractions, models, details, priorities, identifications.
                    resize_array(a, p2, (void*) POINTER_ARRAY);
                    resize_array(ac, p2, (void*) POINTER_ARRAY);
                    resize_array(m, p2, (void*) POINTER_ARRAY);
                    resize_array(mc, p2, (void*) POINTER_ARRAY);
                    resize_array(d, p2, (void*) POINTER_ARRAY);
                    resize_array(dc, p2, (void*) POINTER_ARRAY);
                    resize_array(p, p2, (void*) POINTER_ARRAY);
                    resize_array(id, p2, (void*) POINTER_ARRAY);

                    // Set new array reference.
                    // CAUTION! If an array gets resized, a new array is
                    // created and the contents of the old array gets copied.
                    // Therefore, the new array reference needs to be set.
                    // The old array gets destroyed automatically by resize.
                    set_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) a, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) ac, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) m, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) mc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) d, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) dc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) p, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) id, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                }

                if (i < *s) {

                    // Set abstraction, model, details, priority, identification.
                    set_array_elements(*a, (void*) &i, (void*) &p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*ac, (void*) &i, (void*) &p4, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*m, (void*) &i, (void*) &p5, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*mc, (void*) &i, (void*) &p6, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*d, (void*) &i, (void*) &p7, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*dc, (void*) &i, (void*) &p8, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*p, (void*) &i, (void*) &p9, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                    set_array_elements(*id, (void*) &i, (void*) &p10, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

                    // Increment count.
                    (*c)++;

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index exceeds the size.");
                }

            } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index is negativ.");
            }

        } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The signal count is null.");
        }

    } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The signal size is null.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the index
 */
void remove_signal(void* p0, void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* s = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* c = (int*) p1;

                log_message_debug("Remove signal.");

                if (*i >= 0) {

                    // The abstractions, models, details, priorities, identifications.
                    void** a = POINTER_NULL_POINTER;
                    void** ac = POINTER_NULL_POINTER;
                    void** m = POINTER_NULL_POINTER;
                    void** mc = POINTER_NULL_POINTER;
                    void** d = POINTER_NULL_POINTER;
                    void** dc = POINTER_NULL_POINTER;
                    void** p = POINTER_NULL_POINTER;
                    void** id = POINTER_NULL_POINTER;

                    // Get abstractions, models, details, priorities, identifications.
                    get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

                    if (*i < *c) {

                        // Remove abstraction, model, details, priority, identification.
                        remove_array_elements(*a, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*ac, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*m, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*mc, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*d, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*dc, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*p, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                        remove_array_elements(*id, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

                        // Decrement count.
                        (*c)--;

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index exceeds the count.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index is negativ.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The signal memory count is null.");
            }

        } else {

//??           log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The signal memory size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove signal. The index is null.");
    }
}

/**
 * Gets the signal.
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
 * @param p10 the main signal id (Hand over as reference!)
 */
void get_signal(const void* p0, const void* p1, const void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, int* p10) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            log_message_debug("Get signal.");

            if (*i >= 0) {

                // The abstractions, models, details, priorities, identifications.
                void** a = POINTER_NULL_POINTER;
                void** ac = POINTER_NULL_POINTER;
                void** m = POINTER_NULL_POINTER;
                void** mc = POINTER_NULL_POINTER;
                void** d = POINTER_NULL_POINTER;
                void** dc = POINTER_NULL_POINTER;
                void** p = POINTER_NULL_POINTER;
                void** id = POINTER_NULL_POINTER;

                // Get abstractions, models, details, priorities, identifications.
                get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &p, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNALS_IDENTIFICATIONS_INDEX, (void*) &id, (void*) POINTER_ARRAY);

                if (*i < *c) {

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

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index exceeds the count.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index is negativ.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The signal memory count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get signal. The index is null.");
    }
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the index (Hand over as reference!)
 */
void get_highest_priority_index(const void* p0, const void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            // The signal priorities.
            void** sp = POINTER_NULL_POINTER;

            // Get signal priorities.
            get_array_elements(p0, (void*) SIGNALS_PRIORITIES_INDEX, (void*) &sp, (void*) POINTER_ARRAY);

            // The loop variable.
            int j = 0;
            // The priority.
            int* prio = INTEGER_NULL_POINTER;
            // The highest priority.
            // CAUTION! Do not set it to zero, because then the priority
            // will not be set, due to the comparison: if (prio > h)
            // The smallest possible priority is zero and greater than minus one.
            int h = -1;

            while (1) {

                if (j >= *c) {

                    break;
                }

                // Get signal priority.
                get_array_elements(*sp, (void*) &j, (void*) &prio, (void*) POINTER_ARRAY);

                if (*prio > h) {

                    h = *prio;

                    // If a signal with higher priority is found,
                    // then its index is the one to be returned.
                    *i = j;
                }

                j++;
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The index is null.");
    }
}

/**
 * Gets the new signal id.
 *
 * The new id is: maximum signal id + 1
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal id (Hand over as reference!)
 */
void get_new_signal_id(const void* p0, const void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* mc = (int*) p1;

            // The signal identifications.
            void** ids = POINTER_NULL_POINTER;

            // Get signal identifications.
            get_array_elements(p0, (void*) &SIGNALS_IDENTIFICATIONS_INDEX, (void*) &ids, (void*) POINTER_ARRAY);

            // The loop variable.
            int j = 0;
            // The maximum signal identification.
            int max = -1;
            // The identification.
            int* id = INTEGER_NULL_POINTER;

            while (1) {

                if (j >= *mc) {

                    break;
                }

                // Get signal identification.
                get_array_elements(*ids, (void*) &j, (void*) &id, (void*) POINTER_ARRAY);

                if (*id > max) {

                    max = *id;
                }

                j++;
            }

            *i = max + 1;

        } else {

            log_message_debug("The signal memory count is null.");
        }

    } else {

        log_message_debug("The new signal id is null.");
    }
}

/* SIGNAL_MEMORY_ACCESSOR_SOURCE */
#endif
