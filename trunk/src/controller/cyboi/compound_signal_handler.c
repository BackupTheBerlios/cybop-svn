/*
 * $RCSfile: compound_signal_handler.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-07-08 16:24:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef COMPOUND_SIGNAL_HANDLER_SOURCE
#define COMPOUND_SIGNAL_HANDLER_SOURCE

#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array/array.c"

//
// Forward declarations.
//

void handle_signal(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5, const  void* p6, const void* p7, void* p8, void* p9, void* p10);

/*??
void loop(const void* param, const int* param_count,
          const void* priority, const void* signal_id, void* shutdownflag,
          void* internal);

void branch(const void* param, const int* param_count,
           const void* priority, const void* signal_id, void* shutdownflag,
           void* internal);
*/

/**
 * Handles the compound signal.
 *
 * @param p0 the signal
 * @param p1 the signal count
 * @param p2 the signal priority
 * @param p3 the signal id
 * @param p4 the shutdown flag
 * @param p5 the internals memory
 * @param p6 the direct execution flag
 */
void handle_compound_signal(const void* p0, const void* p1,
    const void* p2, const void* p3, void* p4, void* p5, void* p6) {

    if (p1 != NULL_POINTER) {

        int* sc = (int*) p1;

        // The direct execution flag.
        int x = 0;

        if (p6 != NULL_POINTER) {

            x = *((int*) p6);
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
/*??
                                                            if (x == 0) {

                                                                set_signal(*sm, *smc, *sms, *a, *ac, *m, *mc, *d, *dc, p2, p3);

                                                            } else {
*/
                                                                handle_signal(*a, *ac, *m, *mc, *d, *dc, p2, p3, p4, p5, p6);
/*??
                                                            }
*/

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

/* COMPOUND_SIGNAL_HANDLER_SOURCE */
#endif
