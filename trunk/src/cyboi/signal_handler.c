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
 * @version $Revision: 1.25 $ $Date: 2005-03-20 01:43:33 $ $Author: christian $
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
#include "../logic/build.c"
#include "../logic/compare.c"
#include "../logic/count.c"
#include "../logic/create.c"
#include "../logic/destroy.c"
#include "../logic/loop.c"
#include "../logic/receive.c"
#include "../logic/selection.c"
#include "../logic/send.c"
#include "../logic/set.c"
#include "../logic/shutdown.c"
#include "../logic/startup.c"
#include "../test/test.c"
#include "../x_windows/x_windows_handler.c"


void loop( const void* param, const int* param_count,
           const void* priority, const void* signal_id, void* shutdownflag,
           void* internal );
void selection( const void* param, const int* param_count,
           const void* priority, const void* signal_id, void* shutdownflag,
           void* internal );
void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5,const  void* p6, const void* p7, void* p8, void* p9, void* p10);

/**
 * Handles the compound signal.
 *
 * @param p0 the signal
 * @param p1 the signal count
 * @param p2 the signal priority
 * @param p3 the signal id
 * @param p4 the shutdown flag
 * @param p5 the internal
 * @param p6 the direct execution flag
 */
void handle_compound_signal(const void* p0, const void* p1, const void* p2,
    const void* p3, void* p4, void* p5, void* p6) {

    if (p1 != NULL_POINTER) {

        int* sc = (int*) p1;

        int direct_execution_flag = 0;
        //direct execution flag
        if (p6 != NULL_POINTER) {

            direct_execution_flag = *((int*)p6);
        };

        // The signal memory.
        void** sm = POINTER_NULL_POINTER;
        void** smc = POINTER_NULL_POINTER;
        void** sms = POINTER_NULL_POINTER;

        // Get signal memory.
        get_array_elements(p5, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &sm, (void*) POINTER_ARRAY);
        get_array_elements(p5, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &smc, (void*) POINTER_ARRAY);
        get_array_elements(p5, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &sms, (void*) POINTER_ARRAY);

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
                                                            if ( direct_execution_flag == 0 ) {
                                                                set_signal(*sm, *smc, *sms, *a, *ac, *m, *mc, *d, *dc, p2, p3);
                                                            }
                                                            else {
                                                                handle_signal( *a, *ac, *m, *mc, *d, *dc, p2, p3, p4, p5, p6 );
                                                            }
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
 * @param p4 the signal priority
 * @param p5 the signal id
 * @param p6 the shutdown flag
 * @param p7 the internals
 */
void handle_operation_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, void* p6, void* p7) {

    log_message((void*) INFO_LOG_LEVEL, (void*) HANDLE_OPERATION_SIGNAL_MESSAGE, (void*) HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT);

    // The comparison result.
    int r = 0;

    fprintf(stderr, "TEST operation: %s\n", (char*) p0);
    fprintf(stderr, "TEST operation count: %i\n", *((int*) p1));

    // The knowledge memory.
    void** km = POINTER_NULL_POINTER;
    void** kmc = POINTER_NULL_POINTER;
    void** kms = POINTER_NULL_POINTER;

    // Get knowledge memory.
    get_array_elements(p7, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_ARRAY);
    get_array_elements(p7, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_ARRAY);
    get_array_elements(p7, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_ARRAY);

    if (r != 1) {

        compare_arrays(p0, p1, (void*) ADD_ABSTRACTION, (void*) ADD_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            add(p2, p3, *km, *kmc, *kms);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) CREATE_PART_ABSTRACTION, (void*) CREATE_PART_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            create_part(p2, p3, *km, *kmc, *kms);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) DESTROY_PART_ABSTRACTION, (void*) DESTROY_PART_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            destroy_part(p2, p3, *km, *kmc, *kms);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) COMPARE_ABSTRACTION, (void*) COMPARE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            compare(p2, p3, p4, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) COUNT_PART_ABSTRACTION, (void*) COUNT_PART_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            count_part(p2, p3, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) BUILD_LISTNAME_ABSTRACTION, (void*) BUILD_LISTNAME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            build_listname(p2, p3, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) LOOP_ABSTRACTION, (void*) LOOP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            loop(p2, p3, p4, p5, p6, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SELECTION_ABSTRACTION, (void*) SELECTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            selection(p2, p3, p4, p5, p6, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SET_ABSTRACTION, (void*) SET_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            set(p2, p3, p4, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SET_PROPERTY_ABSTRACTION, (void*) SET_PROPERTY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            set_property(p2, p3, p4, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SEND_ABSTRACTION, (void*) SEND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            send_message(p2, p3, *km, *kmc, *kms, p5, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) RECEIVE_ABSTRACTION, (void*) RECEIVE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            receive_message(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) STARTUP_ABSTRACTION, (void*) STARTUP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            startup_service(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) SHUTDOWN_ABSTRACTION, (void*) SHUTDOWN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            shutdown_service(p2, p3, *km, *kmc, *kms, p7);
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) EXIT_ABSTRACTION, (void*) EXIT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            log_message((void*) INFO_LOG_LEVEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE, (void*) SET_SHUTDOWN_FLAG_MESSAGE_COUNT);

            int* f = (int*) p6;
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

/**
 * Handles the signal.
 *
 * @param p0 the abctraction
 * @param p1 the abstraction count
 * @param p2 the signal
 * @param p3 the signal count
 * @param p4 the parameters (details)
 * @param p5 the parameters count
 * @param p6 the priority
 * @param p7 the signal id
 * @param p8 the shutdown flag
 * @param p9 the internals
 * @param p10 the direct execution flag
 */
void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const  void* p6, const void* p7, void* p8, void* p9, void* p10) {

//    // The knowledge memory.
//    void** k = POINTER_NULL_POINTER;
//    void** kc = POINTER_NULL_POINTER;
//    void** ks = POINTER_NULL_POINTER;
//    // The signal memory.
//    void** s = POINTER_NULL_POINTER;
//    void** sc = POINTER_NULL_POINTER;
//    void** ss = POINTER_NULL_POINTER;
//
//    // Get knowledge memory.
//    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_ARRAY);
//    // Get signal memory.
//    get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_ARRAY);

    int r = 0;

    if (r != 1) {

        compare_arrays(p0, p1, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            handle_compound_signal(p2, p3, p6, p7, p8, p9, p10 );
        }
    }

    if (r != 1) {

        compare_arrays(p0, p1, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            handle_operation_signal( p2, p3, p4, p5, p6, p7, p8, p9 );
        }
    }

    if (r != 1) {

        log_message((void*) WARNING_LOG_LEVEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
    }
}

/* SIGNAL_HANDLER_SOURCE */
#endif
