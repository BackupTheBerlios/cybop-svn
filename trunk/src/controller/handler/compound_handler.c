/*
 * Copyright (C) 1999-2009. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: compound_handler.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:31:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_HANDLER_SOURCE
#define COMPOUND_HANDLER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/compound_memory_name.c"
#include "../../logger/logger.c"
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
 * @param p10 the signal model
 * @param p11 the signal model count
 * @param p12 the signal priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 * @param p14 the direct execution flag
 * @param p15 the part index
 */
void handle_compound_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    // The direct execution flag.
    int* x = (int*) *NULL_POINTER_MEMORY_MODEL;

    if (p14 != *NULL_POINTER_MEMORY_MODEL) {

        x = (int*) p14;
    };

    // The abstractions, models, details.
    void** pa = NULL_POINTER_MEMORY_MODEL;
    void** pac = NULL_POINTER_MEMORY_MODEL;
    void** pm = NULL_POINTER_MEMORY_MODEL;
    void** pmc = NULL_POINTER_MEMORY_MODEL;
    void** pd = NULL_POINTER_MEMORY_MODEL;
    void** pdc = NULL_POINTER_MEMORY_MODEL;

    // Get abstractions, models, details.
    get_array_elements(p10, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &pa, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p10, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &pac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p10, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &pm, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p10, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &pmc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p10, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &pd, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p10, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &pdc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

    if (*pa != *NULL_POINTER_MEMORY_MODEL) {

        if (*pac != *NULL_POINTER_MEMORY_MODEL) {

            if (*pm != *NULL_POINTER_MEMORY_MODEL) {

                if (*pmc != *NULL_POINTER_MEMORY_MODEL) {

                    if (*pd != *NULL_POINTER_MEMORY_MODEL) {

                        if (*pdc != *NULL_POINTER_MEMORY_MODEL) {

                            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle compound part.");

                            // The abstraction, model, details.
                            void** a = NULL_POINTER_MEMORY_MODEL;
                            void** ac = NULL_POINTER_MEMORY_MODEL;
                            void** m = NULL_POINTER_MEMORY_MODEL;
                            void** mc = NULL_POINTER_MEMORY_MODEL;
                            void** d = NULL_POINTER_MEMORY_MODEL;
                            void** dc = NULL_POINTER_MEMORY_MODEL;

                            // Get abstraction, model, details.
                            get_array_elements(*pa, p15, (void*) &a, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                            get_array_elements(*pac, p15, (void*) &ac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                            get_array_elements(*pm, p15, (void*) &m, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                            get_array_elements(*pmc, p15, (void*) &mc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                            get_array_elements(*pd, p15, (void*) &d, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                            get_array_elements(*pdc, p15, (void*) &dc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                            // Add part model (signal) to memory, using the whole signal's priority.
                            // (Each signal has a priority. A signal may consist of part
                            // signals. The part signals cannot have higher / lower priority
                            // than their original whole signal.)
/*??
                            if (*x != *NUMBER_0_INTEGER_MEMORY_MODEL) {
*/

/*??
    fwprintf(stdout, L"TEST handle compound part a: %ls\n", *((wchar_t**) a));
    fwprintf(stdout, L"TEST handle compound part ac: %i\n", **((int**) ac));
*/

                                handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p12, p13, p14);

/*??
                            } else {

                                // Lock signal memory mutex.
                                pthread_mutex_lock(*mt);

                                set_signal(p4, p5, p6, a, ac, m, mc, d, dc, p12, p13);

                                // Set interrupt request flag, in order to notify the signal checker
                                // that a new signal has been placed in the signal memory.
                                **irq = *NUMBER_1_INTEGER_MEMORY_MODEL;

                                // Unlock signal memory mutex.
                                pthread_mutex_unlock(*mt);
                            }
*/

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound part. The part details counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound part. The part details is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound part. The part models counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound part. The part models is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound part. The part abstractions counts is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound part. The part abstractions is null.");
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
 * @param p10 the signal model
 * @param p11 the signal model count
 * @param p12 the signal priority (Hand over as reference!)
 * @param p13 the signal identification (Hand over as reference!)
 * @param p14 the direct execution flag
 */
void handle_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p11 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p11;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
        log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) HANDLE_COMPOUND_MESSAGE_LOG_MODEL, (void*) HANDLE_COMPOUND_MESSAGE_LOG_MODEL_COUNT);

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
    fwprintf(stdout, L"TEST handle compound sc: %i\n", *sc);
*/

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

/*??
    fwprintf(stdout, L"TEST handle compound j: %i\n", j);
*/

            handle_compound_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, (void*) &j);

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle compound. The signal count is null.");
    }
}

/* COMPOUND_HANDLER_SOURCE */
#endif
