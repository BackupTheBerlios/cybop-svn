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
 * @version $Revision: 1.5 $ $Date: 2004-12-14 12:27:04 $ $Author: christian $
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
 * @param p3 the signal abstraction
 * @param p4 the signal abstraction count
 * @param p5 the signal model
 * @param p6 the signal model count
 * @param p7 the signal details
 * @param p8 the signal details count
 * @param p9 the signal priority
 * @param main_sig_id the main signal id
 */
void set_signal(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5,
    const void* p6, const void* p7, const void* p8,
    const void* p9, const int* main_sig_id) {

    if (p2 != NULL_POINTER) {

        int** s = (int**) p2;

        if (p1 != NULL_POINTER) {

            int** c = (int**) p1;

            // The abstractions.
            void* a = NULL_POINTER;
            void* ac = NULL_POINTER;
            // The models.
            void* m = NULL_POINTER;
            void* mc = NULL_POINTER;
            // The details.
            void* d = NULL_POINTER;
            void* dc = NULL_POINTER;
            // The priorities.
            void* p = NULL_POINTER;
            // main signal id s.
            void* ids = NULL_POINTER;

            // Get abstractions, models, details, priorities.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &m);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_INDEX, (void*) &d);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX, (void*) &ids);

            // The index.
            int* i = INTEGER_NULL_POINTER;
            create_integer((void*) &i);
            *i = **c;

            if (*i >= 0) {

                if (*i == **s) {

                    // Increase size.
                    **s = **s * SIGNAL_MEMORY_RESIZE_FACTOR + 1;

                    // Resize abstractions, models, details, priorities.
                    resize_array((void*) &a, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &ac, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &m, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &mc, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &d, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &dc, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &p, (void*) &POINTER_ARRAY, p2);
                    resize_array((void*) &ids, (void*) &POINTER_ARRAY, p2);

                    // Set new array reference.
                    // CAUTION! If an array gets resized, a new array is
                    // created and the contents of the old array gets copied.
                    // Therefore, the new array reference needs to be set.
                    // The old array gets destroyed automatically by resize.
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &m);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_INDEX, (void*) &d);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
                    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX, (void*) &ids);
                }

                if (*i < **s) {

                    // Set abstraction, model, details, priority.
                    set_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) &i, p3);
                    set_array_element((void*) &ac, (void*) &POINTER_ARRAY, (void*) &i, p4);
                    set_array_element((void*) &m, (void*) &POINTER_ARRAY, (void*) &i, p5);
                    set_array_element((void*) &mc, (void*) &POINTER_ARRAY, (void*) &i, p6);
                    set_array_element((void*) &d, (void*) &POINTER_ARRAY, (void*) &i, p7);
                    set_array_element((void*) &dc, (void*) &POINTER_ARRAY, (void*) &i, p8);
                    set_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &i, p9);
                    set_array_element((void*) &ids, (void*) &POINTER_ARRAY, (void*) &i, main_sig_id);

                    // Increment count.
                    (**c)++;

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index exceeds the size.");
                }

            } else {

//??              log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set signal. The index is negativ.");
            }

            destroy_integer((void*) &i);

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

        int** i = (int**) p3;

        if (p2 != NULL_POINTER) {

            int** s = (int**) p2;

            if (p1 != NULL_POINTER) {

                int** c = (int**) p1;

                if (**i >= 0) {

                    // The abstractions.
                    void* a = NULL_POINTER;
                    void* ac = NULL_POINTER;
                    // The models.
                    void* m = NULL_POINTER;
                    void* mc = NULL_POINTER;
                    // The details.
                    void* d = NULL_POINTER;
                    void* dc = NULL_POINTER;
                    // The priorities.
                    void* p = NULL_POINTER;
                    // The main signal ids.
                    void* ids = NULL_POINTER;

                    // Get abstractions, models, details, priorities.
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &m);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_INDEX, (void*) &d);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
                    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &ids);

                    if (**i < **c) {

                        // Remove abstraction, model, details, priority.
                        remove_array_element((void*) &a, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &ac, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &m, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &mc, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &d, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &dc, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &p, (void*) &POINTER_ARRAY, p1, p3);
                        remove_array_element((void*) &ids, (void*) &POINTER_ARRAY, p1, p3);

                        // Decrement count.
                        (**c)--;

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
 * @param p3 the signal abstraction
 * @param p4 the signal abstraction count
 * @param p5 the signal model
 * @param p6 the signal model count
 * @param p7 the signal details
 * @param p8 the signal details count
 * @param p9 the signal priority
 * @param main_sig_id the main signal id
 */
void get_signal(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9,
    int* main_signal_id) {

    if (p2 != NULL_POINTER) {

        int** i = (int**) p2;

        if (p1 != NULL_POINTER) {

            int** c = (int**) p1;

            if (**i >= 0) {

                // The abstractions.
                void* a = NULL_POINTER;
                void* ac = NULL_POINTER;
                // The models.
                void* m = NULL_POINTER;
                void* mc = NULL_POINTER;
                // The details.
                void* d = NULL_POINTER;
                void* dc = NULL_POINTER;
                // The priorities.
                void* p = NULL_POINTER;
                // The main signal id.
                void* ids = NULL_POINTER;

                // Get abstractions, models, details, priorities.
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_INDEX, (void*) &a);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ABSTRACTIONS_COUNTS_INDEX, (void*) &ac);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_INDEX, (void*) &m);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MODELS_COUNTS_INDEX, (void*) &mc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_INDEX, (void*) &d);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_DETAILS_COUNTS_INDEX, (void*) &dc);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &p);
                get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX, (void*) &ids);

                if (**i < **c) {

                    // Get abstraction, model, details, priority.
                    get_array_element((void*) &a, (void*) &POINTER_ARRAY, p2, p3);
                    get_array_element((void*) &ac, (void*) &POINTER_ARRAY, p2, p4);
                    get_array_element((void*) &m, (void*) &POINTER_ARRAY, p2, p5);
                    get_array_element((void*) &mc, (void*) &POINTER_ARRAY, p2, p6);
                    get_array_element((void*) &d, (void*) &POINTER_ARRAY, p2, p7);
                    get_array_element((void*) &dc, (void*) &POINTER_ARRAY, p2, p8);
                    get_array_element((void*) &p, (void*) &POINTER_ARRAY, p2, p9);
                    get_array_element((void*) &ids, (void*) &POINTER_ARRAY, p2, main_signal_id);

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

        int** i = (int**) p2;

        if (p1 != NULL_POINTER) {

            int** c = (int**) p1;

            // The signal priorities.
            void* sp = NULL_POINTER;

            // Get signal priorities.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_PRIORITIES_INDEX, (void*) &sp);

            // The loop variable.
            int* j = INTEGER_NULL_POINTER;
            create_integer((void*) &j);
            *j = 0;
            // The priority.
            int* prio = INTEGER_NULL_POINTER;
            create_integer((void*) &prio);
            *prio = -1;
            // The highest priority.
            // CAUTION! Do not set it to zero, because then the priority
            // will not be set, due to the comparison: if (prio > h)
            // The smallest possible priority is zero and greater than minus one.
            int* h = INTEGER_NULL_POINTER;
            create_integer((void*) &h);
            *h = -1;

            while (1) {

                if (*j >= **c) {

                    break;
                }

                // Get signal priority.
                get_array_element((void*) &sp, (void*) &POINTER_ARRAY, (void*) &j, (void*) &prio);

                if (*prio > *h) {

                    *h = *prio;

                    // If a signal with higher priority is found,
                    // then its index is the one to be returned.
                    **i = *j;
                }

                (*j)++;
            }

            destroy_integer((void*) &h);
            destroy_integer((void*) &prio);
            destroy_integer((void*) &j);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The index is null.");
    }
}

/**
 * Gets the new main signal id.
 * This is the max signal id + 1
 *
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal id
 */
void* get_new_main_signal_id(void** sig_memory,
                             int* sig_memory_count,
                             int* new_main_signal_id) {

    if ( sig_memory == NULL_POINTER ) {

        log_message_debug( "sig_memory is a NULL POINTER" );

    } else if ( sig_memory_count == NULL_POINTER ) {

        log_message_debug( "sig_memory_count is a NULL POINTER" );

    } else if ( new_main_signal_id == NULL_POINTER ) {

        log_message_debug( "new_main_signal_id is a NULL POINTER" );

    } else {

        int i = 0;
        int max_main_signal_id = 0;
        int id = 0;
        void* ids = NULL_POINTER;

        //get the signal memories main signal id
        get_array_element(sig_memory, (void*) &POINTER_ARRAY,
                          (void*) &SIGNALS_MAIN_SIGNAL_ID_INDEX,
                          (void*) &ids);

        while (1) {

            if (i >= *sig_memory_count) {

                break;
            }

            get_array_element((void*) &ids, (void*) &POINTER_ARRAY,
                              (void*) &i, (void*) &id);

            if (id > max_main_signal_id) {

                max_main_signal_id = id;
            }

            i = i + 1;
        }

        *new_main_signal_id = max_main_signal_id + 1;
    }
}

/* SIGNAL_MEMORY_ACCESSOR_SOURCE */
#endif
