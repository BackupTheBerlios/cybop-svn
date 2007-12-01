/*
 * $RCSfile: compound_handler.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.22 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_HANDLER_SOURCE
#define COMPOUND_HANDLER_SOURCE

#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18);

/**
 * Handles a compound signal's part.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the signal
 * @param p11 the signal count
 * @param p12 the signal priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 * @param p14 the direct execution flag
 * @param p15 the part index
 */
void handle_compound_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    // The direct execution flag.
    int* x = (int*) *NULL_POINTER;

    if (p14 != *NULL_POINTER) {

        x = (int*) p14;
    };

    // The abstractions, models, details.
    void** pa = NULL_POINTER;
    void** pac = NULL_POINTER;
    void** pm = NULL_POINTER;
    void** pmc = NULL_POINTER;
    void** pd = NULL_POINTER;
    void** pdc = NULL_POINTER;

    // Get abstractions, models, details.
    get_array_elements(p10, (void*) ABSTRACTIONS_INDEX, (void*) &pa, (void*) POINTER_ARRAY);
    get_array_elements(p10, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &pac, (void*) POINTER_ARRAY);
    get_array_elements(p10, (void*) MODELS_INDEX, (void*) &pm, (void*) POINTER_ARRAY);
    get_array_elements(p10, (void*) MODELS_COUNTS_INDEX, (void*) &pmc, (void*) POINTER_ARRAY);
    get_array_elements(p10, (void*) DETAILS_INDEX, (void*) &pd, (void*) POINTER_ARRAY);
    get_array_elements(p10, (void*) DETAILS_COUNTS_INDEX, (void*) &pdc, (void*) POINTER_ARRAY);

    if (*pa != *NULL_POINTER) {

        if (*pac != *NULL_POINTER) {

            if (*pm != *NULL_POINTER) {

                if (*pmc != *NULL_POINTER) {

                    if (*pd != *NULL_POINTER) {

                        if (*pdc != *NULL_POINTER) {

                            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Handle compound part.");

                            // The abstraction, model, details.
                            void** a = NULL_POINTER;
                            void** ac = NULL_POINTER;
                            void** m = NULL_POINTER;
                            void** mc = NULL_POINTER;
                            void** d = NULL_POINTER;
                            void** dc = NULL_POINTER;

                            // Get abstraction, model, details.
                            get_array_elements(*pa, p15, (void*) &a, (void*) POINTER_ARRAY);
                            get_array_elements(*pac, p15, (void*) &ac, (void*) INTEGER_ARRAY);
                            get_array_elements(*pm, p15, (void*) &m, (void*) POINTER_ARRAY);
                            get_array_elements(*pmc, p15, (void*) &mc, (void*) INTEGER_ARRAY);
                            get_array_elements(*pd, p15, (void*) &d, (void*) POINTER_ARRAY);
                            get_array_elements(*pdc, p15, (void*) &dc, (void*) INTEGER_ARRAY);

                            // Add part model (signal) to memory, using the whole signal's priority.
                            // (Each signal has a priority. A signal may consist of part
                            // signals. The part signals cannot have higher / lower priority
                            // than their original whole signal.)
/*??
                            if (*x != *NUMBER_0_INTEGER) {
*/
                                handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p12, p13, p14);

/*??
                            } else {

                                // Lock signal memory mutex.
                                pthread_mutex_lock(*mt);

                                set_signal(p4, p5, p6, a, ac, m, mc, d, dc, p12, p13);

                                // Set interrupt request flag, in order to notify the signal checker
                                // that a new signal has been placed in the signal memory.
                                **irq = *NUMBER_1_INTEGER;

                                // Unlock signal memory mutex.
                                pthread_mutex_unlock(*mt);
                            }
*/

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound part. The part details counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound part. The part details is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound part. The part models counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound part. The part models is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound part. The part abstractions counts is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound part. The part abstractions is null.");
    }
}

/**
 * Handles the compound signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the signal
 * @param p11 the signal count
 * @param p12 the signal priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 * @param p14 the direct execution flag
 */
void handle_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p11 != *NULL_POINTER) {

        int* sc = (int*) p11;

        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "\n\n");
        log_message((void*) INFORMATION_LOG_LEVEL, (void*) HANDLE_COMPOUND_MESSAGE, (void*) HANDLE_COMPOUND_MESSAGE_COUNT);

        // The loop variable.
        int j = *NUMBER_0_INTEGER;

        while (*NUMBER_1_INTEGER) {

            if (j >= *sc) {

                break;
            }

            handle_compound_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, (void*) &j);

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not handle compound. The signal count is null.");
    }
}

/* COMPOUND_HANDLER_SOURCE */
#endif
