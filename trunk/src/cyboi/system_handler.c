/*
 * $RCSfile: system_handler.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.17 $ $Date: 2005-04-15 09:01:01 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SYSTEM_HANDLER_SOURCE
#define SYSTEM_HANDLER_SOURCE

#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../cyboi/knowledge_memory_handler.c"
#include "../cyboi/signal_memory_handler.c"
#include "../cyboi/input_output_handler.c"
#include "../cyboi/signal_waiter.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/constant.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"
#include "../logic/create.c"
#include "../logic/destroy.c"

/**
 * Handles the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup knowledge memory (statics = state knowledge + logic knowledge)
 * - startup signal memory
 * - startup input output
 * - create startup signal and add to signal memory
 * - run signal waiting loop (dynamics)
 * - destroy startup signal
 * - shutdown input output
 * - shutdown signal memory
 * - shutdown knowledge memory (statics = state knowledge + logic knowledge)
 *
 * @param p0 the internals memory
 */
void handle_system(void* p0, void* start_file, void* start_file_count) {

    log_message_debug("Handle system.");

    if ( p0 != NULL_POINTER ) {

        startup_knowledge_memory(p0);
        startup_signal_memory(p0);
        startup_input_output(p0);

        if ( (start_file != NULL_POINTER) && (start_file_count != NULL_POINTER) ) {

            log_message_debug("Create startup model.");

            // The startup model abstraction, model, details.
            void* ma = NULL_POINTER;
            int* mac = INTEGER_NULL_POINTER;
            int* mas = INTEGER_NULL_POINTER;
            void* mm = NULL_POINTER;
            int* mmc = INTEGER_NULL_POINTER;
            int* mms = INTEGER_NULL_POINTER;
            void* md = NULL_POINTER;
            int* mdc = INTEGER_NULL_POINTER;
            int* mds = INTEGER_NULL_POINTER;

            // Create startup model abstraction, model, details.
            create_integer((void*) &mac);
            create_integer((void*) &mas);
            create_integer((void*) &mmc);
            create_integer((void*) &mms);
            // CAUTION! Do not create startup model details!
            // It is not needed for the startup signal.

            // Initialize startup model abstraction, model, details.
            *mac = 0;
            *mas = 0;
            *mmc = 0;
            *mms = 0;
            // CAUTION! Do not create startup model details!
            // It is not needed for the startup signal.

            // Create startup model abstraction, model, details.
            create_model((void*) &ma, (void*) mac, (void*) mas, 
                (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT,
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            create_model((void*) &mm, (void*) mmc, (void*) mms,
                start_file, start_file_count, 
                CYBOL_ABSTRACTION, CYBOL_ABSTRACTION_COUNT, 
                FILE_CHANNEL, FILE_CHANNEL_COUNT );
            // CAUTION! Do not create startup model details!
            // It is not needed for the startup signal.

            log_message_debug("Add startup model as signal to signal memory.");

            // The signal memory.
            void** s = POINTER_NULL_POINTER;
            void** sc = POINTER_NULL_POINTER;
            void** ss = POINTER_NULL_POINTER;

            // Get signal memory.
            get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_ARRAY);

            if (s != POINTER_NULL_POINTER) {

                if (sc != POINTER_NULL_POINTER) {

                    if (ss != POINTER_NULL_POINTER) {

                        // The signal id.
                        int* id = INTEGER_NULL_POINTER;
                        create_integer((void*) &id);
                        *id = 0;
                        get_new_signal_id(*s, *sc, (void*) id);

                        fprintf(stderr, "p: %i\n", *NORMAL_PRIORITY);
                        fprintf(stderr, "id: %i\n", *id);

                        fprintf(stderr, "s: %i\n", *s);
                        fprintf(stderr, "sc: %i\n", *((int*) *sc));
                        fprintf(stderr, "ss: %i\n", *((int*) *ss));

                        // Add startup signal to signal memory.
                        set_signal(*s, *sc, *ss,
                            ma, (void*) mac,
                            mm, (void*) mmc,
                            md, (void*) mdc,
                            (void*) NORMAL_PRIORITY, (void*) id);
    
                        // The system is now started up and complete so that a loop
                        // can be entered, waiting for signals (events/ interrupts)
                        // which are stored/ found in the signal memory.
                        // The loop is left as soon as its shutdown flag is set.
                        wait(p0);

                    } else {

                        log_message_debug("Could not handle system. The signal memory size is null.");
                    }

                } else {

                    log_message_debug("Could not handle system. The signal memory count is null.");
                }

            } else {

                log_message_debug("Could not handle system. The signal memory is null.");
            }
        }
        else {
            
            log_message_debug("Could not handle system. The start file or start file count is null.");
        }
        
        shutdown_input_output(p0);
        shutdown_signal_memory(p0);
        shutdown_knowledge_memory(p0);
        
    }
    else {
        
        log_message_debug("Could not handle system. The internal memory is null.");
    }

}

//    // The startup parameters channel, abstraction, model.
//    // CAUTION! These were created while reading from the configuration file,
//    // and such do not have to be created here!
//    void** pc = POINTER_NULL_POINTER;
//    void** pcc = POINTER_NULL_POINTER;
//    void** pa = POINTER_NULL_POINTER;
//    void** pac = POINTER_NULL_POINTER;
//    void** pm = POINTER_NULL_POINTER;
//    void** pmc = POINTER_NULL_POINTER;
//
//    // Get startup parameters channel, abstraction, model.
//    get_array_elements(p0, (void*) STARTUP_CHANNEL_INTERNAL, (void*) &pc, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) STARTUP_CHANNEL_COUNT_INTERNAL, (void*) &pcc, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) STARTUP_ABSTRACTION_INTERNAL, (void*) &pa, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) STARTUP_ABSTRACTION_COUNT_INTERNAL, (void*) &pac, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) STARTUP_MODEL_INTERNAL, (void*) &pm, (void*) POINTER_ARRAY);
//    get_array_elements(p0, (void*) STARTUP_MODEL_COUNT_INTERNAL, (void*) &pmc, (void*) POINTER_ARRAY);
//
//    if (pc != POINTER_NULL_POINTER) {
//
//        if (pcc != POINTER_NULL_POINTER) {
//
//            if (pa != POINTER_NULL_POINTER) {
//
//                if (pac != POINTER_NULL_POINTER) {
//
//                    if (pm != POINTER_NULL_POINTER) {
//
//                        if (pmc != POINTER_NULL_POINTER) {
//
//                            log_message_debug("Create startup model.");
//
//                            // The startup model abstraction, model, details.
//                            void* ma = NULL_POINTER;
//                            int* mac = INTEGER_NULL_POINTER;
//                            int* mas = INTEGER_NULL_POINTER;
//                            void* mm = NULL_POINTER;
//                            int* mmc = INTEGER_NULL_POINTER;
//                            int* mms = INTEGER_NULL_POINTER;
//                            void* md = NULL_POINTER;
//                            int* mdc = INTEGER_NULL_POINTER;
//                            int* mds = INTEGER_NULL_POINTER;
//
//                            // Create startup model abstraction, model, details.
//                            create_integer((void*) &mac);
//                            create_integer((void*) &mas);
//                            create_integer((void*) &mmc);
//                            create_integer((void*) &mms);
//                            // CAUTION! Do not create startup model details!
//                            // It is not needed for the startup signal.
//
//                            // Initialize startup model abstraction, model, details.
//                            *mac = 0;
//                            *mas = 0;
//                            *mmc = 0;
//                            *mms = 0;
//                            // CAUTION! Do not create startup model details!
//                            // It is not needed for the startup signal.
//
//                            // Create startup model abstraction, model, details.
//                            create_model((void*) &ma, (void*) mac, (void*) mas, *pa, *pac,
//                                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
//                                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
//
//                            fprintf(stderr, "ma: %s\n", (char*) ma);
//                            fprintf(stderr, "mac: %i\n", *mac);
//
//                            create_model((void*) &mm, (void*) mmc, (void*) mms,
//                                *pm, *pmc, *pa, *pac, *pc, *pcc);
//                            // CAUTION! Do not create startup model details!
//                            // It is not needed for the startup signal.
//
//                            fprintf(stderr, "mm: %i\n", mm);
//                            fprintf(stderr, "mmc: %i\n", *mmc);
//                            //?? DO NOT try to print details and its count. They are NULL.
//
//                            log_message_debug("Add startup model as signal to signal memory.");
//
//                            // The signal memory.
//                            void** s = POINTER_NULL_POINTER;
//                            void** sc = POINTER_NULL_POINTER;
//                            void** ss = POINTER_NULL_POINTER;
//
//                            // Get signal memory.
//                            get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);
//                            get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_ARRAY);
//                            get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_ARRAY);
//
//                            if (s != POINTER_NULL_POINTER) {
//
//                                if (sc != POINTER_NULL_POINTER) {
//
//                                    if (ss != POINTER_NULL_POINTER) {
//
//                                        // The signal id.
//                                        int* id = INTEGER_NULL_POINTER;
//                                        create_integer((void*) &id);
//                                        *id = 0;
//                                        get_new_signal_id(*s, *sc, (void*) id);
//
//                                        fprintf(stderr, "p: %i\n", *NORMAL_PRIORITY);
//                                        fprintf(stderr, "id: %i\n", *id);
//
//                                        fprintf(stderr, "s: %i\n", *s);
//                                        fprintf(stderr, "sc: %i\n", *((int*) *sc));
//                                        fprintf(stderr, "ss: %i\n", *((int*) *ss));
//
//                                        // Add startup signal to signal memory.
//                                        set_signal(*s, *sc, *ss,
//                                            ma, (void*) mac,
//                                            mm, (void*) mmc,
//                                            md, (void*) mdc,
//                                            (void*) NORMAL_PRIORITY, (void*) id);
//
//                                        // The system is now started up and complete so that a loop
//                                        // can be entered, waiting for signals (events/ interrupts)
//                                        // which are stored/ found in the signal memory.
//                                        // The loop is left as soon as its shutdown flag is set.
//                                        wait(p0);
//
//                                    } else {
//
//                                        log_message_debug("Could not handle system. The signal memory size is null.");
//                                    }
//
//                                } else {
//
//                                    log_message_debug("Could not handle system. The signal memory count is null.");
//                                }
//
//                            } else {
//
//                                log_message_debug("Could not handle system. The signal memory is null.");
//                            }
//
//                            // Destroy startup signal.
//                            // CAUTION! All signals are destroyed in the signal waiting loop,
//                            // after having been read from the signal memory.
//                            // Since this also counts for the startup signal,
//                            // it (in other words: the signal id) MUST NOT be destroyed here!
//                            // However, the startup signal's model NEEDS to be destroyed -- see below!
//
//                            log_message_debug("Destroy startup model.");
//
//                            // CAUTION! Do not destroy startup model details!
//                            // It was not needed for the startup signal.
//                            destroy_model((void*) &mm, (void*) mmc, (void*) mms,
//                                *pm, *pmc, *pa, *pac, *pc, *pcc);
//                            destroy_model((void*) &ma, (void*) mac, (void*) mas, *pa, *pac,
//                                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
//                                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);
//
//                            // CAUTION! Do not destroy startup model details!
//                            // It was not needed for the startup signal.
//                            destroy_integer((void*) &mms);
//                            destroy_integer((void*) &mmc);
//                            destroy_integer((void*) &mas);
//                            destroy_integer((void*) &mac);
//
//                        } else {
//
//                            log_message_debug("Could not handle system. The startup parameter model count is null.");
//                        }
//
//                    } else {
//
//                        log_message_debug("Could not handle system. The startup parameter model is null.");
//                    }
//
//                } else {
//
//                    log_message_debug("Could not handle system. The startup parameter abstraction count is null.");
//                }
//
//            } else {
//
//                log_message_debug("Could not handle system. The startup parameter abstraction is null.");
//            }
//
//        } else {
//
//            log_message_debug("Could not handle system. The startup parameter channel count is null.");
//        }
//
//    } else {
//
//        log_message_debug("Could not handle system. The startup parameter channel is null.");
//    }
//
//    shutdown_input_output(p0);
//    shutdown_signal_memory(p0);
//    shutdown_knowledge_memory(p0);
//}

/* SYSTEM_HANDLER_SOURCE */
#endif
