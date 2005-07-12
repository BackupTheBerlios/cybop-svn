/*
 * $RCSfile: branch.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-07-12 15:23:38 $ $Author: christian $
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

void handle(const void* p0, const void* p1, const void* p2, const void* p3,
    const void* p4, const void* p5,const  void* p6, const void* p7, void* p8, void* p9, void* p10);

/**
 * Branches the program flow, depending on a flag.
 *
 * Expected parameters:
 * - criterion: the separation flag
 * - true: the model to be executed if the criterion is true
 * - false: the model to be executed if the criterion is false
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the priority
 * @param p6 the signal id
 * @param p7 the shutdown flag
 * @param p8 the internals memory
 */
void branch(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, void* p7, void* p8) {

    log_message_debug("Branch program flow.");

    // The criterion abstraction.
    void** ca = POINTER_NULL_POINTER;
    void** cac = POINTER_NULL_POINTER;
    void** cas = POINTER_NULL_POINTER;
    // The criterion model.
    void** cm = POINTER_NULL_POINTER;
    void** cmc = POINTER_NULL_POINTER;
    void** cms = POINTER_NULL_POINTER;
    // The criterion details.
    void** cd = POINTER_NULL_POINTER;
    void** cdc = POINTER_NULL_POINTER;
    void** cds = POINTER_NULL_POINTER;

    // The true model abstraction.
    void** ta = POINTER_NULL_POINTER;
    void** tac = POINTER_NULL_POINTER;
    void** tas = POINTER_NULL_POINTER;
    // The true model model.
    void** tm = POINTER_NULL_POINTER;
    void** tmc = POINTER_NULL_POINTER;
    void** tms = POINTER_NULL_POINTER;
    // The true model details.
    void** td = POINTER_NULL_POINTER;
    void** tdc = POINTER_NULL_POINTER;
    void** tds = POINTER_NULL_POINTER;

    // The false model abstraction.
    void** fa = POINTER_NULL_POINTER;
    void** fac = POINTER_NULL_POINTER;
    void** fas = POINTER_NULL_POINTER;
    // The false model model.
    void** fm = POINTER_NULL_POINTER;
    void** fmc = POINTER_NULL_POINTER;
    void** fms = POINTER_NULL_POINTER;
    // The false model details.
    void** fd = POINTER_NULL_POINTER;
    void** fdc = POINTER_NULL_POINTER;
    void** fds = POINTER_NULL_POINTER;

    // Get criterion.
    get_real_compound_element_by_name(p0, p1,
        (void*) CRITERION_NAME, (void*) CRITERION_NAME_COUNT,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        p2, p3);

    // Get true model.
    get_real_compound_element_by_name(p0, p1,
        (void*) FALSE_MODEL_NAME, (void*) FALSE_MODEL_NAME_COUNT,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p2, p3);

    // Get false model.
    get_real_compound_element_by_name(p0, p1,
        (void*) TRUE_MODEL_NAME, (void*) TRUE_MODEL_NAME_COUNT,
        (void*) &fa, (void*) &fac, (void*) &fas,
        (void*) &fm, (void*) &fmc, (void*) &fms,
        (void*) &fd, (void*) &fdc, (void*) &fds,
        p2, p3);

    if ((ca != POINTER_NULL_POINTER)
        && (cac != POINTER_NULL_POINTER)

        && (cas != POINTER_NULL_POINTER)
        && (cm != POINTER_NULL_POINTER)

        && (cmc != POINTER_NULL_POINTER)
        && (cms != POINTER_NULL_POINTER)
        && (cd != POINTER_NULL_POINTER)
        && (cdc != POINTER_NULL_POINTER)
        && (cds != POINTER_NULL_POINTER)
        // Check true model.
        && (ta != POINTER_NULL_POINTER)
        && (tac != POINTER_NULL_POINTER)
        && (tas != POINTER_NULL_POINTER)
        && (tm != POINTER_NULL_POINTER)
        && (tmc != POINTER_NULL_POINTER)
        && (tms != POINTER_NULL_POINTER)
        && (td != POINTER_NULL_POINTER)
        && (tdc != POINTER_NULL_POINTER)
        && (tds != POINTER_NULL_POINTER)
        // check false model
        && (fa != POINTER_NULL_POINTER)
        && (fac != POINTER_NULL_POINTER)
        && (fas != POINTER_NULL_POINTER)
        && (fm != POINTER_NULL_POINTER)
        && (fmc != POINTER_NULL_POINTER)
        && (fms != POINTER_NULL_POINTER)
        && (fd != POINTER_NULL_POINTER)
        && (fdc != POINTER_NULL_POINTER)
        && (fds != POINTER_NULL_POINTER)) {

        // The comparison result.
        int r = 0;

        // Check if criterion has boolean abstraction.
        compare_arrays(*ca, *cac, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            // The criterion.
            void* c = NULL_POINTER;

            // Get criterion.
            get_array_elements(*cm, (void*) INTEGER_VALUE_INDEX, (void*) &c, (void*) INTEGER_ARRAY);

            // Reset comparison result.
            r = 0;

            compare_arrays(c, (void*) INTEGER_COUNT, (void*) TRUE_BOOLEAN, (void*) ONE_INTEGER, &r, (void*) INTEGER_ARRAY);

            // The direct execution flag.
            int x = 0;

            if (r == 1) {

                // The criterion is true.
                handle(*ta, *tac, *tm, *tmc, *td, *tdc,
                    p5, p6, p7, p8, (void*) &x);

            } else {

                // The criterion is false.
                handle(*fa, *fac, *fm, *fmc, *fd, *fdc,
                    p5, p6, p7, p8, (void*) &x);
            }
        }
    }
}

/* BRANCH_SOURCE */
#endif
