/*
 * $RCSfile: branch.c,v $
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
 * @version $Revision: 1.14 $ $Date: 2006-04-23 09:56:12 $ $Author: christian $
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BRANCH_SOURCE
#define BRANCH_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/boolean_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13,  void* p14, void* p15, void* p16, void* p17, void* p18);

/**
 * Branches the program flow, depending on a flag.
 *
 * Expected parameters:
 * - criterion: the separation flag
 * - true: the model to be executed if the criterion is true
 * - false: the model to be executed if the criterion is false
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
 * @param p10 the parameters
 * @param p11 the parameters count
 * @param p12 the priority
 * @param p13 the signal id
 */
void branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_debug("\n\n");
    log_message_debug("Branch program flow.");

    // The criterion abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The criterion model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The criterion details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // The true model abstraction.
    void** ta = &NULL_POINTER;
    void** tac = &NULL_POINTER;
    void** tas = &NULL_POINTER;
    // The true model model.
    void** tm = &NULL_POINTER;
    void** tmc = &NULL_POINTER;
    void** tms = &NULL_POINTER;
    // The true model details.
    void** td = &NULL_POINTER;
    void** tdc = &NULL_POINTER;
    void** tds = &NULL_POINTER;

    // The false model abstraction.
    void** fa = &NULL_POINTER;
    void** fac = &NULL_POINTER;
    void** fas = &NULL_POINTER;
    // The false model model.
    void** fm = &NULL_POINTER;
    void** fmc = &NULL_POINTER;
    void** fms = &NULL_POINTER;
    // The false model details.
    void** fd = &NULL_POINTER;
    void** fdc = &NULL_POINTER;
    void** fds = &NULL_POINTER;

    // Get criterion.
    get_universal_compound_element_by_name(p10, p11,
        (void*) CRITERION_NAME, (void*) CRITERION_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p1, p2);

    // Get true model.
    get_universal_compound_element_by_name(p10, p11,
        (void*) FALSE_MODEL_NAME, (void*) FALSE_MODEL_NAME_COUNT,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p1, p2);

    // Get false model.
    get_universal_compound_element_by_name(p10, p11,
        (void*) TRUE_MODEL_NAME, (void*) TRUE_MODEL_NAME_COUNT,
        (void*) &fa, (void*) &fac, (void*) &fas,
        (void*) &fm, (void*) &fmc, (void*) &fms,
        (void*) &fd, (void*) &fdc, (void*) &fds,
        p1, p2);

    if ((*ca != NULL_POINTER)
        && (*cac != NULL_POINTER)
        && (*cas != NULL_POINTER)
        && (*cm != NULL_POINTER)
        && (*cmc != NULL_POINTER)
        && (*cms != NULL_POINTER)
        && (*cd != NULL_POINTER)
        && (*cdc != NULL_POINTER)
        && (*cds != NULL_POINTER)
        // Check true model.
        && (*ta != NULL_POINTER)
        && (*tac != NULL_POINTER)
        && (*tas != NULL_POINTER)
        && (*tm != NULL_POINTER)
        && (*tmc != NULL_POINTER)
        && (*tms != NULL_POINTER)
        && (*td != NULL_POINTER)
        && (*tdc != NULL_POINTER)
        && (*tds != NULL_POINTER)
        // check false model
        && (*fa != NULL_POINTER)
        && (*fac != NULL_POINTER)
        && (*fas != NULL_POINTER)
        && (*fm != NULL_POINTER)
        && (*fmc != NULL_POINTER)
        && (*fms != NULL_POINTER)
        && (*fd != NULL_POINTER)
        && (*fdc != NULL_POINTER)
        && (*fds != NULL_POINTER)) {

        // The comparison result.
        int r = 0;

        // Check if criterion has boolean abstraction.
        compare_arrays(*ca, *cac, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // The criterion.
            void* c = NULL_POINTER;

            // Get criterion.
            get_array_elements(*cm, (void*) PRIMITIVE_VALUE_INDEX, (void*) &c, (void*) INTEGER_ARRAY);

            // Reset comparison result.
            r = 0;

            compare_arrays(c, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) NUMBER_1_INTEGER, &r, (void*) INTEGER_ARRAY);

            // The direct execution flag.
            int x = 0;

            if (r == 1) {

                // The criterion is true.
                handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
                    *ta, *tac, *tm, *tmc, *td, *tdc, p12, p13, (void*) &x);

            } else {

                // The criterion is false.
                handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
                    *fa, *fac, *fm, *fmc, *fd, *fdc, p12, p13, (void*) &x);
            }
        }
    }
}

/* BRANCH_SOURCE */
#endif
