/*
 * $RCSfile: handler.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.11 $ $Date: 2006-08-19 02:04:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../controller/handler/compound_handler.c"
#include "../controller/handler/operation_handler.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
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
 * @param p7 the signal memory blocked flag
 * @param p8 the interrupt request flag
 * @param p9 the shutdown flag
 * @param p10 the abctraction
 * @param p11 the abstraction count
 * @param p12 the signal (model)
 * @param p13 the signal count
 * @param p14 the parameters (details)
 * @param p15 the parameters count
 * @param p16 the priority
 * @param p17 the signal id
 * @param p18 the direct execution flag
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18) {

    // The logic abstraction.
    void** a = &NULL_POINTER;
    void** ac = &NULL_POINTER;
    void** as = &NULL_POINTER;
    // The logic model.
    void** m = &NULL_POINTER;
    void** mc = &NULL_POINTER;
    void** ms = &NULL_POINTER;
    // The logic details.
    void** d = &NULL_POINTER;
    void** dc = &NULL_POINTER;
    void** ds = &NULL_POINTER;

    // The encapsulated logic abstraction.
    void** ea = &NULL_POINTER;
    void** eac = &NULL_POINTER;
    void** eas = &NULL_POINTER;
    // The encapsulated logic model.
    void** em = &NULL_POINTER;
    void** emc = &NULL_POINTER;
    void** ems = &NULL_POINTER;
    // The encapsulated logic details.
    void** ed = &NULL_POINTER;
    void** edc = &NULL_POINTER;
    void** eds = &NULL_POINTER;

    // The comparison result.
    int r = 0;

    if (r == 0) {

        // CAUTION! Do NOT remove this section with "COMPOUND_ABSTRACTION"!
        // It is needed for at least initial startup logic residing in CYBOL
        // files only, before any logic is created and contained as runtime
        // knowledge models in the knowledge memory.
        compare_arrays(p10, p11, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Handle compound logic.
            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p16, p17, p18);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

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
            get_compound_element_by_name(p1, p2, NULL_POINTER, NULL_POINTER,
                p12, p13,
                (void*) &ea, (void*) &eac, (void*) &eas,
                (void*) &em, (void*) &emc, (void*) &ems,
                (void*) &ed, (void*) &edc, (void*) &eds);

            // The knowledge root does not have a details container with meta
            // information, which is why a null pointer is handed over here twice.
            get_compound_element_by_name(p1, p2, NULL_POINTER, NULL_POINTER,
                *em, *emc, &a, &ac, &as, &m, &mc, &ms, &d, &dc, &ds);

            // Handle compound logic.
            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *m, *mc, p16, p17, p18);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

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
            get_compound_element_by_name(p1, p2, NULL_POINTER, NULL_POINTER,
                p12, p13, &a, &ac, &as, &m, &mc, &ms, &d, &dc, &ds);

            // Handle compound logic.
            handle_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *m, *mc, p16, p17, p18);
        }
    }

    if (r == 0) {

        compare_arrays(p10, p11, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Handle simple operation.
            handle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15, p16, p17);
        }
    }

    if (r == 0) {

        log_message((void*) WARNING_LOG_LEVEL, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE, (void*) COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT);
    }
}

/* HANDLER_SOURCE */
#endif
