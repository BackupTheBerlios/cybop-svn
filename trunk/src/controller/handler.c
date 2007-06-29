/*
 * $RCSfile: handler.c,v $
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
 * @version $Revision: 1.19 $ $Date: 2007-06-29 22:55:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../controller/handler/compound_handler.c"
#include "../controller/handler/operation_handler.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"

/**
 * Handles the signal.
 *
 * This procedure identifies the signal abstraction and then calls either
 * the compound signal handler, or the operation signal handler procedure.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the interrupt request flag
 * @param p8 the signal memory mutex
 * @param p9 the shutdown flag
 * @param p10 the abctraction
 * @param p11 the abstraction count
 * @param p12 the model (signal)
 * @param p13 the model (signal) count
 * @param p14 the details (parameters)
 * @param p15 the details (parameters) count
 * @param p16 the priority
 * @param p17 the signal id
 * @param p18 the direct execution flag
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_message_debug("Information: Handle signal.");

    // The enable name, abstraction, model, details.
    void** en = NULL_POINTER;
    void** enc = NULL_POINTER;
    void** ens = NULL_POINTER;
    void** ea = NULL_POINTER;
    void** eac = NULL_POINTER;
    void** eas = NULL_POINTER;
    // CAUTION! This integer variable is casted below.
    int** em = (int**) NULL_POINTER;
    void** emc = NULL_POINTER;
    void** ems = NULL_POINTER;
    void** ed = NULL_POINTER;
    void** edc = NULL_POINTER;
    void** eds = NULL_POINTER;

    // Get enable.
    get_universal_compound_element_by_name(p14, p15,
        (void*) OPERATION_ENABLE_NAME, (void*) OPERATION_ENABLE_NAME_COUNT,
        (void*) &en, (void*) &enc, (void*) &ens,
        (void*) &ea, (void*) &eac, (void*) &eas,
        (void*) &em, (void*) &emc, (void*) &ems,
        (void*) &ed, (void*) &edc, (void*) &eds,
        p1, p2);

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST a: %s\n", (char*) p10);
    fprintf(stderr, "TEST ac: %i\n", *((int*) p11));
    fprintf(stderr, "TEST m: %s\n", (char*) p12);
    fprintf(stderr, "TEST mc: %i\n", *((int*) p13));
    fprintf(stderr, "TEST ea: %s\n", (char*) *ea);
    fprintf(stderr, "TEST eac: %i\n", **((int**) eac));

    compare_arrays(*ea, *eac, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

    if (r != *NUMBER_0_INTEGER) {

        if (**em != *NUMBER_0_INTEGER) {

            //
            // Handle the signal only if the enable flag is set (not zero).
            //

            // The logic name, abstraction, model, details.
            void** ln = NULL_POINTER;
            void** lnc = NULL_POINTER;
            void** lns = NULL_POINTER;
            void** la = NULL_POINTER;
            void** lac = NULL_POINTER;
            void** las = NULL_POINTER;
            void** lm = NULL_POINTER;
            void** lmc = NULL_POINTER;
            void** lms = NULL_POINTER;
            void** ld = NULL_POINTER;
            void** ldc = NULL_POINTER;
            void** lds = NULL_POINTER;
            // The encapsulated logic name, abstraction, model, details.
            void** eln = NULL_POINTER;
            void** elnc = NULL_POINTER;
            void** elns = NULL_POINTER;
            void** ela = NULL_POINTER;
            void** elac = NULL_POINTER;
            void** elas = NULL_POINTER;
            void** elm = NULL_POINTER;
            void** elmc = NULL_POINTER;
            void** elms = NULL_POINTER;
            void** eld = NULL_POINTER;
            void** eldc = NULL_POINTER;
            void** elds = NULL_POINTER;

            // Reset comparison result.
            r = *NUMBER_0_INTEGER;

            if (r == *NUMBER_0_INTEGER) {

                // CAUTION! Do NOT remove this section with "COMPOUND_ABSTRACTION"!
                // It is needed for at least initial startup logic residing in CYBOL
                // files only, before any logic is created and contained as runtime
                // knowledge models in the knowledge memory.
                compare_arrays(p10, p11, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Handle compound logic.
                    handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p16, p17, p18);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p10, p11, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Get compound logic element as double-encapsulated model.
                    //
                    // CAUTION!
                    // The abstraction of an encapsulated name must always be "character".
                    // The details are uninteresting, since an encapsulated name cannot have
                    // constraints. That is, only the model is of interest. It contains the
                    // hierarchical name of the knowledge part to be retrieved.
                    //
                    // Example of a model pointing to another model containing a logic name:
                    // model="application.record.logic_name"
                    //
                    // The knowledge root does not have a details container with meta
                    // information, which is why a null pointer is handed over here twice.
                    //
                    // Compare also with procedure "get_universal_compound_element_by_name"
                    // in source file "memoriser/accessor/compound_accessor.c"!
                    get_compound_element_by_name(p1, p2, *NULL_POINTER, *NULL_POINTER,
                        p12, p13,
                        (void*) &eln, (void*) &elnc, (void*) &elns,
                        (void*) &ela, (void*) &elac, (void*) &elas,
                        (void*) &elm, (void*) &elmc, (void*) &elms,
                        (void*) &eld, (void*) &eldc, (void*) &elds);

                    // The knowledge root does not have a details container with meta
                    // information, which is why a null pointer is handed over here twice.
                    get_compound_element_by_name(p1, p2, *NULL_POINTER, *NULL_POINTER,
                        *elm, *elmc, &ln, &lnc, &lns, &la, &lac, &las, &lm, &lmc, &lms, &ld, &ldc, &lds);

                    // Handle compound logic.
                    handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *lm, *lmc, p16, p17, p18);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p10, p11, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Get compound logic element as encapsulated model.
                    //
                    // CAUTION!
                    // The abstraction of an encapsulated name must always be "character".
                    // The details are uninteresting, since an encapsulated name cannot have
                    // constraints. That is, only the model is of interest. It contains the
                    // hierarchical name of the knowledge part to be retrieved.
                    //
                    // Example of a model containing a hierarchical logic name:
                    // model="application.record.logic"
                    //
                    // The knowledge root does not have a details container with meta
                    // information, which is why a null pointer is handed over here twice.
                    //
                    // Compare also with procedure "get_universal_compound_element_by_name"
                    // in source file "memoriser/accessor/compound_accessor.c"!
                    get_compound_element_by_name(p1, p2, *NULL_POINTER, *NULL_POINTER,
                        p12, p13, &ln, &lnc, &lns, &la, &lac, &las, &lm, &lmc, &lms, &ld, &ldc, &lds);

                    // Handle compound logic.
                    handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *lm, *lmc, p16, p17, p18);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p10, p11, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Handle simple operation.
                    handle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15, p16, p17);
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                log_message((void*) WARNING_LOG_LEVEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
            }

        } else {

            log_message_debug("Warning: Could not handle signal. The enable parameter model is false.");
        }

    } else {

        log_message_debug("Error: Could not handle signal. The enable parameter abstraction is not boolean.");
    }
}

/* HANDLER_SOURCE */
#endif
