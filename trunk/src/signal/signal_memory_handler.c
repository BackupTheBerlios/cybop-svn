/*
 * $RCSfile: signal_memory_handler.c,v $
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
 * This file handles a signal memory.
 *
 * A signal memory is capable of storing signals.
 * For each signal, the following meta information is stored:
 * - signal
 * - priority
 * - language
 *
 * Signal processing procedures should be called in the following order:
 * - receive
 * - handle
 * - send
 * - reset
 *
 * @version $Revision: 1.29 $ $Date: 2004-04-21 10:59:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_HANDLER_SOURCE
#define SIGNAL_MEMORY_HANDLER_SOURCE

#include "../constants.c"
#include "../dynamics/add.c"
#include "../dynamics/create_model.c"
#include "../dynamics/destroy_model.c"
#include "../logger/log_handler.c"
#include "../model/array_handler.c"
#include "../model/dynamics_models.c"
#include "../model/map_handler.c"
#include "../model/model_handler.c"
#include "../signal/languages.c"
#include "../signal/priorities.c"
#include "../x_windows/x_windows_handler.c"

//
// Integer constants.
//

/** The zero number. */
static const int ZERO_NUMBER = 0;

/** The one number. */
static const int ONE_NUMBER = 1;

/** The two number. */
static const int TWO_NUMBER = 2;

/** The three number. */
static const int THREE_NUMBER = 3;

/** The four number. */
static const int FOUR_NUMBER = 4;

/** The five number. */
static const int FIVE_NUMBER = 5;

/** The six number. */
static const int SIX_NUMBER = 6;

/** The seven number. */
static const int SEVEN_NUMBER = 7;

/** The eight number. */
static const int EIGHT_NUMBER = 8;

/** The nine number. */
static const int NINE_NUMBER = 9;

//
// Part constants.
//

/** The signal memory size. */
static const int SIGNAL_MEMORY_SIZE = 6;

/** The array size index. */
static const int ARRAY_SIZE_INDEX = 0;

/** The array count index. */
static const int ARRAY_COUNT_INDEX = 1;

/** The signals array index. */
static const int SIGNALS_ARRAY_INDEX = 2;

/** The priorities array index. */
static const int PRIORITIES_ARRAY_INDEX = 3;

/** The abstractions array index. */
static const int ABSTRACTIONS_ARRAY_INDEX = 4;

/** The abstractions sizes array index. */
static const int ABSTRACTIONS_SIZES_ARRAY_INDEX = 5;

//
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 */
void create_signal_memory(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Create signal memory.");

    // Create signal memory.
    create_array(p0, (void*) &SIGNAL_MEMORY_SIZE);

    // Initialize parts.
    int s = 0;
    int c = 0;
    void* sig = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* as = NULL_POINTER;

    // Create parts.
    create_array((void*) &sig, (void*) &s);
    create_array((void*) &p, (void*) &s);
    create_array((void*) &a, (void*) &s);
    create_array((void*) &as, (void*) &s);

    // Set parts in ascending order.
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);
    set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ARRAY_INDEX, (void*) &sig);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_ARRAY_INDEX, (void*) &p);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_ARRAY_INDEX, (void*) &a);
    set_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_ARRAY_INDEX, (void*) &as);
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 */
void destroy_signal_memory(void* p0) {

    // Initialize parts.
    int s = 0;
    int c = 0;
    void* sig = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* as = NULL_POINTER;

/*??
    log_message((void*) &INFO_LOG_LEVEL, "Destroy all signals left in signal memory.");

    int i = 0;
    get_array_count(m->signals, (void*) &i);
    i--;
    void* s = NULL_POINTER;
    void* a = NULL_POINTER;

    while (i >= 0) {

        s = (void*) get_signal(p0, (void*) &i);
        a = (void*) get_abstraction(p0, (void*) &i);
        // Priority is not needed to destroy the signal.

        // Abstraction and priority are removed internally,
        // together with the signal.
        remove_signal(p0, (void*) &i);

        // Destroy signal. Do not destroy the signal's abstraction and
        // priority here; they are static within CYBOI.
        destroy_model(s, NULL, NULL, (void*) a);

        i--;
    }
*/

    log_message((void*) &INFO_LOG_LEVEL, "Destroy signal memory.");

    // Get parts.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ARRAY_INDEX, (void*) &sig);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_ARRAY_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_ARRAY_INDEX, (void*) &a);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_ARRAY_INDEX, (void*) &as);

    // Remove parts in descending order.
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &ABSTRACTIONS_SIZES_ARRAY_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &ABSTRACTIONS_ARRAY_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &PRIORITIES_ARRAY_INDEX);
    remove_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &SIGNALS_ARRAY_INDEX);
    remove_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE, (void*) &ARRAY_SIZE_INDEX);

    // Destroy parts.
    destroy_array((void*) &sig, (void*) &s);
    destroy_array((void*) &p, (void*) &s);
    destroy_array((void*) &a, (void*) &s);
    destroy_array((void*) &as, (void*) &s);

    // Destroy signal memory.
    destroy_array(p0, (void*) &SIGNAL_MEMORY_SIZE);
}

//
// Signal memory element (signal).
//

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 * @param p2 the priority
 * @param p3 the abstraction
 * @param p4 the abstraction size
 */
void set_signal(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    // Initialize parts.
    int s = 0;
    int c = 0;
    void* sig = NULL_POINTER;
    void* p = NULL_POINTER;
    void* a = NULL_POINTER;
    void* as = NULL_POINTER;

    // Get parts.
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);
    get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ARRAY_INDEX, (void*) &sig);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_ARRAY_INDEX, (void*) &p);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_ARRAY_INDEX, (void*) &a);
    get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_ARRAY_INDEX, (void*) &as);

    // The index.
    int i = c;

    if (i >= 0) {

        if (i >= s) {

            // Double array size.
            s = s * 2 + 1;

            // Resize parts.
            resize_array(sig, (void*) &s);
            resize_array(p, (void*) &s);
            resize_array(a, (void*) &s);
            resize_array(as, (void*) &s);

            // Set array size which is equal for all arrays.
            set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);
        }

        if (i < s) {

            // Set element (signal).
            set_array_element((void*) &sig, (void*) &POINTER_ARRAY, (void*) &i, p1);
            set_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &i, p2);
            set_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) &i, p3);
            set_array_element((void*) &as, (void*) &POINTER_ARRAY, (void*) &i, p4);

            // Increment element count.
            c++;

            // Set array count which is equal for all arrays.
            set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not set signal. The index exceeds the size.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set signal. The index is negativ.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
void remove_signal(void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

            // Initialize parts.
            int s = 0;
            int c = 0;
            void* sig = NULL_POINTER;
            void* p = NULL_POINTER;
            void* a = NULL_POINTER;
            void* as = NULL_POINTER;

            // Get parts.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ARRAY_INDEX, (void*) &sig);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_ARRAY_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_ARRAY_INDEX, (void*) &a);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_ARRAY_INDEX, (void*) &as);

            if (*i < s) {

                // Remove element (signal).
                remove_array_element((void*) &sig, (void*) &POINTER_ARRAY, (void*) &s, p1);
                remove_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &s, p1);
                remove_array_element((void*) &a, (void*) &POINTER_ARRAY, (void*) &s, p1);
                remove_array_element((void*) &as, (void*) &POINTER_ARRAY, (void*) &s, p1);

                // Decrement element count.
                c--;

                // Set array count which is equal for all arrays.
                set_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The index exceeds the size.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The index is negativ.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The index is null.");
    }
}

/**
 * Gets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @param p2 the signal
 * @param p3 the priority
 * @param p4 the abstraction
 * @param p5 the abstraction size
 */
void get_signal(const void* p0, const void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        if (*i >= 0) {

            // Initialize parts.
            int s = 0;
            int c = 0;
            void* sig = NULL_POINTER;
            void* p = NULL_POINTER;
            void* a = NULL_POINTER;
            void* as = NULL_POINTER;

            // Get parts.
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_SIZE_INDEX, (void*) &s);
            get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &SIGNALS_ARRAY_INDEX, (void*) &sig);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_ARRAY_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_ARRAY_INDEX, (void*) &a);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &ABSTRACTIONS_SIZES_ARRAY_INDEX, (void*) &as);

            if (*i < s) {

                // Get element (signal).
                get_array_element((void*) &sig, (void*) &POINTER_ARRAY, p1, p2);
                get_array_element((void*) &p, (void*) &INTEGER_ARRAY, p1, p3);
                get_array_element((void*) &a, (void*) &POINTER_ARRAY, p1, p4);
                get_array_element((void*) &as, (void*) &POINTER_ARRAY, p1, p5);

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get signal. The index exceeds the size.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get signal. The index is negativ.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get signal. The index is null.");
    }
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
void get_highest_priority_index(const void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* i = (int*) p1;

        // Initialize parts.
        int c = 0;
        void* p = NULL_POINTER;

        // Get parts.
        get_array_element(p0, (void*) &INTEGER_ARRAY, (void*) &ARRAY_COUNT_INDEX, (void*) &c);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PRIORITIES_ARRAY_INDEX, (void*) &p);

        // The loop variable.
        int j = 0;
        // The priority.
        int prio = 0;
        // The highest priority.
        int h = prio;

        while (1) {

            if (j >= c) {

                break;
            }

            // Get element (signal) priority.
            get_array_element((void*) &p, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &prio);

            if (prio > h) {

                h = prio;

                // If a signal with higher priority is found,
                // then its index is the one to be returned.
                *i = j;
            }

            j++;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get highest priority index. The index is null.");
    }
}

//
// Signal handling.
//

/**
 * Handles the compound signal.
 *
 * @param p0 the signal memory
 * @param p1 the compound signal
 * @param p2 the priority
 */
void handle_compound_signal(const void* p0, const void* p1, const void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Handle compound signal.");

    // Initialize parts.
    void* pa = NULL_POINTER;
    int pas = 0;
    void* pl = NULL_POINTER;
    int pls = 0;
    void* pm = NULL_POINTER;
    int pms = 0;
    void* poa = NULL_POINTER;
    int poas = 0;
    void* pol = NULL_POINTER;
    int pols = 0;
    void* pom = NULL_POINTER;
    int poms = 0;
    void* ca = NULL_POINTER;
    int cas = 0;
    void* cl = NULL_POINTER;
    int cls = 0;
    void* cm = NULL_POINTER;
    int cms = 0;

    get_model_part(p1, n, ns,
        (void*) &pa, (void*) &pas, (void*) &pl, (void*) &pls, (void*) &pm, (void*) &pms,
        (void*) &poa, (void*) &poas, (void*) &pol, (void*) &pols, (void*) &pom, (void*) &poms,
        (void*) &ca, (void*) &cas, (void*) &cl, (void*) &cls, (void*) &cm, (void*) &cms);

    int count = 0;
    get_array_count(m->part_models, (void*) &count);
    int p = 0;
    int i = 0;
    int* position = NULL_POINTER;
    void* abstraction = NULL_POINTER;
    void* location = NULL_POINTER;
    void* part = NULL_POINTER;

    // All positions.
    while (p < count) {

        // All parts.
        while (i < count) {

            // Determine position.
            position = (int*) get_map_element_at_index(m->position_models, (void*) &i);

            // All parts at the current position.
            if (*position == p) {

                // Determine abstraction.
                get_model_part_at_index(m->part_abstractions, (void*) &i, abstraction, abstraction_size);

                // Determine part signal as dynamics model.
                part = get_map_element_at_index(m->part_models, (void*) &i);

                // Add "part" signal to memory, using the "whole" signal's priority.
                // (Each signal has a priority. A signal may consist of "part"
                // signals. The "part" signals cannot have higher/lower priority
                // than their original "whole" signal.)
                set_signal(p0, signal, p2, abstraction, abstraction_size);

                break;
            }

            i++;
        }

        p++;
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the operation signal
 * @param p1 the statics
 * @param p2 the dynamics
 * @param p3 the internals
 * @param p4 the shutdown flag
 */
void handle_operation_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message((void*) &INFO_LOG_LEVEL, "Handle operation signal.");

    struct operation* o = (struct operation*) p0;

    if (o != NULL_POINTER) {

        void* v = o->value;

        if (v != NULL_POINTER) {

            log_message((void*) &INFO_LOG_LEVEL, "TEST 0");

            char* a = (char*) get_array_element(v, (void*) &ZERO_NUMBER);

            log_message((void*) &INFO_LOG_LEVEL, "TEST 1");

            if (strcmp(a, ADD_MODEL) == 0) {

                add(get_array_element(v, (void*) &ONE_NUMBER), get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER));

            } else if (strcmp(a, CREATE_STATICS_MODEL) == 0) {

                struct model* s = (struct model*) p1;

                if (s != NULL_POINTER) {

                    //?? Work this out! Hand over 9 or just 3 parameters,
                    //?? for only part or also position and constraint?
                    void* m = create_model(get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));
                    set_map_element_with_name(s->part_models, get_array_element(v, (void*) &ONE_NUMBER), m);

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle create statics model. The statics is null.");
                }

            } else if (strcmp(a, DESTROY_STATICS_MODEL) == 0) {

                struct model* s = (struct model*) p1;

                if (s != NULL_POINTER) {

                    //?? Work this out! Hand over 9 or just 3 parameters,
                    //?? for only part or also position and constraint?
                    void* m = get_map_element_with_name(s->part_models, get_map_element_with_name(v, (void*) &ONE_NUMBER));
                    destroy_model(m, get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle destroy statics model. The statics is null.");
                }

            } else if (strcmp(a, CREATE_DYNAMICS_MODEL) == 0) {

                struct model* d = (struct model*) p2;

                if (d != NULL_POINTER) {

                    //?? Work this out! Hand over 9 or just 3 parameters,
                    //?? for only part or also position and constraint?
                    void* m = create_model(get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));
                    set_map_element_with_name(d->part_models, get_array_element(v, (void*) &ONE_NUMBER), m);

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle create dynamics model. The dynamics is null.");
                }

            } else if (strcmp(a, DESTROY_DYNAMICS_MODEL) == 0) {

                struct model* d = (struct model*) p2;

                if (d != NULL_POINTER) {

                    //?? Work this out! Hand over 9 or just 3 parameters,
                    //?? for only part or also position and constraint?
                    void* m = get_map_element_with_name(d->part_models, get_map_element_with_name(v, (void*) &ONE_NUMBER));
                    destroy_model(m, get_array_element(v, (void*) &TWO_NUMBER), get_array_element(v, (void*) &THREE_NUMBER), get_array_element(v, (void*) &FOUR_NUMBER));

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle destroy dynamics model. The dynamics is null.");
                }

            } else if (strcmp(a, SEND_MODEL) == 0) {

                void* l = get_map_element_with_name(v, "language");

                if (strcmp(l, X_WINDOWS_LANGUAGE) == 0) {

                    send_x_windows_output(get_array_element(v, (void*) &ONE_NUMBER), get_array_element(v, (void*) &TWO_NUMBER), p3);

                } else if (strcmp(l, TUI_LANGUAGE) == 0) {

                }

            } else if (strcmp(a, RECEIVE_MODEL) == 0) {

            } else if (strcmp(a, EXIT_MODEL) == 0) {

                log_message((void*) &INFO_LOG_LEVEL, "Set shutdown flag.");

                int* f = (int*) p4;
                *f = 1;
            }

/*??
            //?? Only for later, when mouse interrupt is handled directly here, and not in JavaEventHandler.
            if (strcmp(l, "mouse_moved") == 0) {

                Model statics = statics;

                set_model_element(statics, "mouse.pointer_position.x_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getX()));
                set_model_element(statics, "mouse.pointer_position.x_distance.unit", "pixel");
                set_model_element(statics, "mouse.pointer_position.y_distance.quantity", new java.lang.Integer(((java.awt.event.MouseEvent) evt).getY()));
                set_model_element(statics, "mouse.pointer_position.y_distance.unit", "pixel");

            } else if (strcmp(l, "mouse_clicked") == 0) {

                void* main_frame = get_statics_model_part(statics, (void*) "main_frame");
                struct vector* pointer_position = get_statics_model_part(statics, (void*) "mouse.pointer_position");

                reset_signal(s);

                if (pointer_position != NULL_POINTER) {

    //??            mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. The pointer position is null.");
                }
            }
*/
        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not handle operation signal. The operation value is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not handle operation signal. The signal model is null.");
    }
}

/* SIGNAL_MEMORY_HANDLER_SOURCE */
#endif
