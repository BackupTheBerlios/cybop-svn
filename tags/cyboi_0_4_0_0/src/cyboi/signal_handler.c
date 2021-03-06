/*
 * $RCSfile: signal_handler.c,v $
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
 * @version $Revision: 1.20 $ $Date: 2005-01-28 23:30:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef SIGNAL_HANDLER_SOURCE
#define SIGNAL_HANDLER_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/integer_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"
#include "../logic/add.c"
#include "../logic/create.c"
#include "../logic/destroy.c"
#include "../logic/receive.c"
#include "../logic/send.c"
#include "../test/test.c"
#include "../x_windows/x_windows_handler.c"

/**
 * Handles the compound signal.
 *
 * @param p0 the signal
 * @param p1 the signal count
 * @param p2 the signal priority
 * @param p3 the signal id
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 */
void handle_compound_signal(const void* p0, const void* p1, const void* p2,
    const void* p3, void* p4, void* p5, void* p6) {

    if (p1 != NULL_POINTER) {

        int* sc = (int*) p1;

        int index = 0;
//??        test_compound(p0, (int*) p1, &index);

        log_message((void*) INFO_LOG_LEVEL, (void*) HANDLE_COMPOUND_SIGNAL_MESSAGE, (void*) HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT);

        // The abstractions, models, details.
        void** pa = POINTER_NULL_POINTER;
        void** pac = POINTER_NULL_POINTER;
        void** pm = POINTER_NULL_POINTER;
        void** pmc = POINTER_NULL_POINTER;
        void** pd = POINTER_NULL_POINTER;
        void** pdc = POINTER_NULL_POINTER;

        // Get abstractions, models, details.
        get_array_elements(p0, (void*) ABSTRACTIONS_INDEX, (void*) &pa, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &pac, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) MODELS_INDEX, (void*) &pm, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &pmc, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) DETAILS_INDEX, (void*) &pd, (void*) POINTER_ARRAY);
        get_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) &pdc, (void*) POINTER_ARRAY);

        if (pa != POINTER_NULL_POINTER) {

            if (pac != POINTER_NULL_POINTER) {

                if (pm != POINTER_NULL_POINTER) {

                    if (pmc != POINTER_NULL_POINTER) {

                        if (pd != POINTER_NULL_POINTER) {

                            if (pdc != POINTER_NULL_POINTER) {

                                // The abstraction, model, details.
                                void** a = POINTER_NULL_POINTER;
                                void** ac = POINTER_NULL_POINTER;
                                void** m = POINTER_NULL_POINTER;
                                void** mc = POINTER_NULL_POINTER;
                                void** d = POINTER_NULL_POINTER;
                                void** dc = POINTER_NULL_POINTER;

                                // The loop variable.
                                int j = 0;

                                while (1) {

                                    if (j >= *sc) {

                                        break;
                                    }

                                    // Get abstraction, model, details.
                                    get_array_elements(*pa, (void*) &j, (void*) &a, (void*) POINTER_ARRAY);
                                    get_array_elements(*pac, (void*) &j, (void*) &ac, (void*) INTEGER_ARRAY);
                                    get_array_elements(*pm, (void*) &j, (void*) &m, (void*) POINTER_ARRAY);
                                    get_array_elements(*pmc, (void*) &j, (void*) &mc, (void*) INTEGER_ARRAY);
                                    get_array_elements(*pd, (void*) &j, (void*) &d, (void*) POINTER_ARRAY);
                                    get_array_elements(*pdc, (void*) &j, (void*) &dc, (void*) INTEGER_ARRAY);

                                    if (a != POINTER_NULL_POINTER) {

                                        if (ac != POINTER_NULL_POINTER) {

                                            if (m != POINTER_NULL_POINTER) {

                                                if (mc != POINTER_NULL_POINTER) {

                                                    if (d != POINTER_NULL_POINTER) {

                                                        if (dc != POINTER_NULL_POINTER) {

                                                            // Add part model (signal) to memory, using the whole signal's priority.
                                                            // (Each signal has a priority. A signal may consist of part
                                                            // signals. The part signals cannot have higher / lower priority
                                                            // than their original whole signal.)
                                                            set_signal(p4, p5, p6, *a, *ac, *m, *mc, *d, *dc, p2, p3);

                                                        } else {

                                                            log_message_debug("Could not handle compound signal. The details count is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not handle compound signal. The details is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not handle compound signal. The model count is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not handle compound signal. The model is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not handle compound signal. The abstraction count is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not handle compound signal. The abstraction is null.");
                                    }

                                    // Reset abstraction, model, details.
                                    a = POINTER_NULL_POINTER;
                                    ac = POINTER_NULL_POINTER;
                                    m = POINTER_NULL_POINTER;
                                    mc = POINTER_NULL_POINTER;
                                    d = POINTER_NULL_POINTER;
                                    dc = POINTER_NULL_POINTER;

                                    j++;
                                }

                            } else {

                                log_message_debug("Could not handle compound signal. The part details counts is null.");
                            }

                        } else {

                            log_message_debug("Could not handle compound signal. The part details is null.");
                        }

                    } else {

                        log_message_debug("Could not handle compound signal. The part models counts is null.");
                    }

                } else {

                    log_message_debug("Could not handle compound signal. The part models is null.");
                }

            } else {

                log_message_debug("Could not handle compound signal. The part abstractions counts is null.");
            }

        } else {

            log_message_debug("Could not handle compound signal. The part abstractions is null.");
        }

    } else {

        log_message_debug("Could not handle compound signal. The signal count is null.");
    }
}

/**
 * Handles the operation signal.
 *
 * @param p0 the signal (operation)
 * @param p1 the signal count
 * @param p2 the parameters (details)
 * @param p3 the parameters count
 * @param p4 the knowledge
 * @param p5 the knowledge count
 * @param p6 the knowledge size
 * @param p7 the signal id
 * @param p8 the internals
 * @param p9 the shutdown flag
 */
void handle_operation_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message((void*) INFO_LOG_LEVEL, (void*) HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

    // The comparison result.
    int r = 0;

    fprintf(stderr, "TEST operation: %s\n", (char*) p0);
    fprintf(stderr, "TEST operation count: %i\n", *((int*) p1));

    if (r != 1) {

        compare_arrays(p0, p1, (void*) ADD_ABSTRACTION, (void*) ADD_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            add(p2, p3, p4, p5, p6);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) CREATE_PART_ABSTRACTION, (void*) CREATE_PART_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            create_part(p2, p3, p4, p5, p6);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) DESTROY_PART_ABSTRACTION, (void*) DESTROY_PART_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            destroy_part(p2, p3, p4, p5, p6);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SEND_ABSTRACTION, (void*) SEND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_message(p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) RECEIVE_ABSTRACTION, (void*) RECEIVE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_message(p2, p3, p4, p5, p6, p8);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) EXIT_ABSTRACTION, (void*) EXIT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            log_message((void*) INFO_LOG_LEVEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE, (void*) SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

            int* f = (int*) p9;
            *f = 1;
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

//??        mouse_clicked_action(main_frame, (void*) pointer_position->x, (void*) pointer_position->y, (void*) pointer_position->z, s->predicate);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not handle mouse clicked action. The pointer position is null.");
        }
    }
*/
}

/* SIGNAL_HANDLER_SOURCE */
#endif
