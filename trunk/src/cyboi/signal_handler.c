/*
 * $RCSfile: signal_handler.c,v $
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

#ifndef SIGNAL_HANDLER_SOURCE
#define SIGNAL_HANDLER_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../logic/add.c"
#include "../logic/create.c"
#include "../logic/destroy.c"
#include "../logic/receive.c"
#include "../logic/send.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Handles the compound signal.
 *
 * @param p0 the signal
 * @param p1 the signal count
 * @param p2 the signal priority
 * @param p3 the signal memory
 * @param p4 the signal memory count
 * @param p5 the signal memory size
 */
void handle_compound_signal(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5) {

    if (p2 != NULL_POINTER) {

        int* sc = (int*) p2;

        log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE, (void*) &HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT);

        // Initialize part models, abstractions and their counts.
        void* pm = NULL_POINTER;
        void* pmc = NULL_POINTER;
        void* pa = NULL_POINTER;
        void* pac = NULL_POINTER;

        // Get part models, abstractions and their counts.
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_INDEX, (void*) &pm);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_MODELS_COUNTS_INDEX, (void*) &pmc);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_INDEX, (void*) &pa);
        get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PART_ABSTRACTIONS_COUNTS_INDEX, (void*) &pac);

        // Initialize part model, abstraction and their count.
        void* m = NULL_POINTER;
        int mc = 0;
        void* a = NULL_POINTER;
        int ac = 0;

        // The loop variable.
        int j = 0;

        while (1) {

            if (j >= *sc) {

                break;
            }

            // Get part model, abstraction
            // and their count.
            get_array_element((void*) &pm, (void*) &POINTER_ARRAY, (void*) &j, (void*) &m);
            get_array_element((void*) &pmc, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &mc);
            get_array_element((void*) &pa, (void*) &POINTER_ARRAY, (void*) &j, (void*) &a);
            get_array_element((void*) &pac, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ac);

            // Add part model (signal) to memory, using the whole signal's priority.
            // (Each signal has a priority. A signal may consist of part
            // signals. The part signals cannot have higher/lower priority
            // than their original whole signal.)
            set_signal(p3, p4, p5, (void*) &m, (void*) &mc, p2, (void*) &a, (void*) &ac);

            j++;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle compound signal. The signal memory count is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the signal
 * @param p1 the signal parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the character internals
 * @param p6 the integer internals
 * @param p7 the pointer internals
 * @param p8 the double internals
 * @param p9 the shutdown flag
 */
void handle_operation_signal(const void* p0, const void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p1 != NULL_POINTER) {

        int* sc = (int*) p1;

        // The signal parameters count must be greater than zero.
        if (*sc >= 1) {

            log_message((void*) &INFO_LOG_LEVEL, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) &HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

            // Initialize parameters
            // and their counts and sizes.
            void* p = NULL_POINTER;
            int pc = 0;
            int ps = 0;

            // Get parameters
            // and their counts and sizes.
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_INDEX, (void*) &p);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_COUNTS_INDEX, (void*) &pc);
            get_array_element(p0, (void*) &POINTER_ARRAY, (void*) &PARAMETERS_SIZES_INDEX, (void*) &ps);

            // Initialize logic (operation) name
            // and its count.
            // The first parameter param0 is the operation name.
            // Following parameters param1 .. are input and output names.
            void* l = NULL_POINTER;
            int lc = 0;

            // The logic (operation) name parameter index.
            int i = 0;

            // Get logic (operation) name
            // and its count.
            get_array_element((void*) &p, (void*) &POINTER_ARRAY, (void*) &i, (void*) &l);
            get_array_element((void*) &pc, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &lc);

            // The done flag.
            int d = 0;
            // The comparison result.
            int r = 0;

            fprintf(stderr, "TEST logic: %s\n", (char*) l);
            fprintf(stderr, "TEST logic_count: %i\n", lc);

            if (d == 0) {

                if (lc == ADD_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &ADD_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &ADD_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        add(p1, (void*) &p, (void*) &pc, (void*) &ps, p2, p3, p4);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == CREATE_MODEL_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &CREATE_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CREATE_MODEL_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        handle_create(p1, (void*) &p, (void*) &pc, (void*) &ps, p2, p3, p4);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == DESTROY_MODEL_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &DESTROY_MODEL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DESTROY_MODEL_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

/*??
                        handle_destroy(p1, (void*) &p, (void*) &pc, (void*) &ps, p2, p3, p4);
*/

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == SEND_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &SEND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SEND_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        send_message(p1, (void*) &p, (void*) &pc, (void*) &ps,
                            p2, p3, p4, p5, p6, p7, p8);

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == RECEIVE_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &RECEIVE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &RECEIVE_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

/*??
                        receive_message(p1, (void*) &p, (void*) &pc, (void*) &ps,
                            p2, p3, p4, p5, p6, p7, p8);
*/

                        d = 1;
                    }
                }
            }

            if (d == 0) {

                if (lc == EXIT_ABSTRACTION_COUNT) {

                    compare_array_elements((void*) &l, (void*) &EXIT_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &EXIT_ABSTRACTION_COUNT, (void*) &r);

                    if (r == 1) {

                        log_message((void*) &INFO_LOG_LEVEL, (void*) &SET_SHUTDOWN_FLAG_MESSAGE, (void*) &SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

                        int* f = (int*) p9;
                        *f = 1;

                        d = 1;
                    }
                }
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

//??                    mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. The pointer position is null.");
                    }
                }
*/

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle operation signal. The signal parameters count is zero.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle operation signal. The signal parameters count is null.");
    }
}

/* SIGNAL_HANDLER_SOURCE */
#endif
