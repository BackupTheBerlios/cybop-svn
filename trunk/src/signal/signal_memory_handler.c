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
 * @version $Revision: 1.27 $ $Date: 2004-04-07 10:36:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_HANDLER_SOURCE
#define SIGNAL_MEMORY_HANDLER_SOURCE

#include <string.h>
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
#include "../signal/signal_memory.c"
#include "../statics/vector.c"
#include "../x_windows/x_windows_handler.c"

//
// Constants.
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

...
/** The signals. */
void* signals;

/** The abstractions. */
void* abstractions;

/** The priorities. */
void* priorities;
...

//
// Signal.
//

/**
 * Sets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @param p2 the signal
 * @param p3 the abstraction
 * @param p4 the priority
 */
void set_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != NULL_POINTER) {

        set_array_element(m->signals, p1, p2);
        set_array_element(m->abstractions, p1, p3);
        set_array_element(m->priorities, p1, p4);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set signal. The signal memory is null.");
    }
}

/**
 * Adds the signal.
 *
 * @param p0 the signal memory
 * @param p1 the signal
 * @param p2 the abstraction
 * @param p3 the priority
 */
void add_signal(void* p0, void* p1, void* p2, void* p3) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != NULL_POINTER) {

        int i = 0;
        get_array_count(m->signals, (void*) &i);
        set_signal(p0, (void*) &i, p1, p2, p3);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not add signal. The signal memory is null.");
    }
}

/**
 * Removes the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 */
void remove_signal(void* p0, void* p1) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != NULL_POINTER) {

        remove_array_element(m->signals, p1);
        remove_array_element(m->abstractions, p1);
        remove_array_element(m->priorities, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove signal. The signal memory is null.");
    }
}

/**
 * Gets the signal.
 *
 * @param p0 the signal memory
 * @param p1 the index
 * @return the signal
 */
void* get_signal(void* p0, void* p1) {

    void* s = NULL_POINTER;
    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != NULL_POINTER) {

        s = get_array_element(m->signals, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get signal. The signal memory is null.");
    }

    return s;
}

/**
 * Gets the index of the signal with highest priority.
 *
 * @param p0 the signal memory
 * @param p1 the signal index
 */
void get_highest_priority_index(void* p0, void* p1) {

    struct signal_memory* m = (struct signal_memory*) p0;
    int* index = (int*) p1;

    if (m != NULL_POINTER) {

        int i = 0;
        int count = 0;
        get_array_count(m->priorities, (void*) &count);
        int* p = NULL_POINTER;
        int h = *index;

        while (i < count) {

            p = (int*) get_array_element(m->priorities, (void*) &i);

            // If a signal with higher priority is found,
            // then its index is the one to be returned.
            if (*p > h) {

                *index = i;
                h = *p;
            }

            i++;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get index of the signal with highest priority. The signal memory is null.");
    }
}

//
// Signal memory.
//

/**
 * Creates the signal memory.
 *
 * @param p0 the signal memory
 */
void create_signal_memory(void* p0) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != NULL_POINTER) {

        log_message((void*) &INFO_LOG_LEVEL, "Create signal memory.");

        m->signals = malloc(sizeof(struct array));
        initialize_array(m->signals);

        m->abstractions = malloc(sizeof(struct array));
        initialize_array(m->abstractions);

        m->priorities = malloc(sizeof(struct array));
        initialize_array(m->priorities);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not create signal memory. The signal memory is null.");
    }
}

/**
 * Destroys the signal memory.
 *
 * @param p0 the signal memory
 */
void destroy_signal_memory(void* p0) {

    struct signal_memory* m = (struct signal_memory*) p0;

    if (m != NULL_POINTER) {

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

        log_message((void*) &INFO_LOG_LEVEL, "Destroy signal memory.");

        finalize_array(m->priorities);
        free(m->priorities);

        finalize_array(m->abstractions);
        free(m->abstractions);

        finalize_array(m->signals);
        free(m->signals);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not destroy signal memory. The signal memory is null.");
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
void handle_compound_signal(void* p0, void* p1, void* p2) {

    log_message((void*) &INFO_LOG_LEVEL, "Handle compound signal.");

    struct model* m = (struct model*) p1;

    if (m != NULL_POINTER) {

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
                    abstraction = get_map_element_at_index(m->part_abstractions, (void*) &i);

                    // Determine abstraction.
                    location = get_map_element_at_index(m->part_locations, (void*) &i);

                    // Determine part signal as dynamics model.
                    part = get_map_element_at_index(m->part_models, (void*) &i);

                    // Add "part" signal to signal memory,
                    // using the "whole" signal's priority.
                    // (Each signal has a priority. A signal may consist of "part"
                    // signals. The "part" signals cannot have higher/lower priority
                    // than their original "whole" signal.)
                    add_signal(p0, part, abstraction, p2);

                    break;
                }

                i++;
            }

            p++;
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not handle compound signal. The signal model is null.");
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
