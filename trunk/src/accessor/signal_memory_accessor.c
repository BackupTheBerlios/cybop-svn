/*
 * $RCSfile: signal_memory_accessor.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.1 $ $Date: 2004-08-23 07:18:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_ACCESSOR_SOURCE
#define SIGNAL_MEMORY_ACCESSOR_SOURCE

#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the signal model
 * @param p4 the signal model count
 * @param p5 the signal priority
 * @param p6 the signal abstraction
 * @param p7 the signal abstraction count
 */
void set_signal(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5, const void* p6, const void* p7) {

    if (p2 != NULL_POINTER) {

        int* s = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            // Initialize signal models, priorities, abstractions
            // and their counts.
            void* sm = NULL_POINTER;
            void* smc = NULL_POINTER;
            void* sp = NULL_POINTER;
            void* sa = NULL_POINTER;
            void* sac = NULL_POINTER;

            // Get signal models, priorities, abstractions
            // and their counts.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

            // The index.
            int i = *c;

            if (i >= 0) {

                if (i == *s) {

                    // Increase size.
                    *s = *s * SIGNAL_MEMORY_RESIZE_FACTOR + 1;

                    // Resize signal models, priorities, abstractions
                    // and their counts.
                    resize_array((void*) &sm, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &smc, (void*) &INTEGER_ARRAY, p2);
                    resize_array((void*) &sp, (void*) &INTEGER_ARRAY, p2);
                    resize_array((void*) &sa, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &sac, (void*) &INTEGER_ARRAY, p2);
                }

                if (i < *s) {

                    // Set signal model, priority, abstraction
                    // and their count.
                    set_array_element((void*) &sm, (void*) &POINTER_ARRAY, (void*) &i, p3);
                    set_array_element((void*) &smc, (void*) &INTEGER_ARRAY, (void*) &i, p4);
                    set_array_element((void*) &sp, (void*) &INTEGER_ARRAY, (void*) &i, p5);
                    set_array_element((void*) &sa, (void*) &POINTER_ARRAY, (void*) &i, p6);
                    set_array_element((void*) &sac, (void*) &INTEGER_ARRAY, (void*) &i, p7);

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

                if (*i >= 0) {

                    // Initialize signal models, priorities, abstractions
                    // and their counts.
                    void* sm = NULL_POINTER;
                    void* smc = NULL_POINTER;
                    void* sp = NULL_POINTER;
                    void* sa = NULL_POINTER;
                    void* sac = NULL_POINTER;

                    // Get signal models, priorities, abstractions
                    // and their counts.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

                    if (*i < *c) {

                        // Remove signal model, priority, abstraction
                        // and their count.
                        remove_array_element((void*) &sm, (void*) &POINTER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &smc, (void*) &INTEGER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sp, (void*) &INTEGER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sa, (void*) &POINTER_ARRAY, (void*) c, p3);
                        remove_array_element((void*) &sac, (void*) &INTEGER_ARRAY, (void*) c, p3);

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
 * @param p3 the signal model
 * @param p4 the signal model count
 * @param p5 the signal priority
 * @param p6 the signal abstraction
 * @param p7 the signal abstraction count
 */
void get_signal(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            if (*i >= 0) {

                // Initialize signal models, priorities, abstractions
                // and their counts.
                void* sm = NULL_POINTER;
                void* smc = NULL_POINTER;
                void* sp = NULL_POINTER;
                void* sa = NULL_POINTER;
                void* sac = NULL_POINTER;

                // Get signal models, priorities, abstractions
                // and their counts.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &sm);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &smc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &sa);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &sac);

                if (*i < *c) {

                    // Get signal model, priority, abstraction
                    // and their count.
                    get_array_element((void*) &sm, (void*) &POINTER_ARRAY, p2, p3);
                    get_array_element((void*) &smc, (void*) &INTEGER_ARRAY, p2, p4);
                    get_array_element((void*) &sp, (void*) &INTEGER_ARRAY, p2, p5);
                    get_array_element((void*) &sa, (void*) &POINTER_ARRAY, p2, p6);
                    get_array_element((void*) &sac, (void*) &INTEGER_ARRAY, p2, p7);

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
 * @param p2 the index
 */
void get_highest_priority_index(const void* p0, const void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* c = (int*) p1;

            // Initialize signal priorities.
            void* sp = NULL_POINTER;

            // Get signal priorities.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);

            // The loop variable.
            int j = 0;
            // The priority.
            int prio = -1;
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
                get_array_element((void*) &sp, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &prio);

                if (prio > h) {

                    h = prio;

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

/* SIGNAL_MEMORY_ACCESSOR_SOURCE */
#endif
