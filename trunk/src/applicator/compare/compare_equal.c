/*
 * $RCSfile: compare_equal.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2005-08-09 13:04:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_EQUAL_SOURCE
#define COMPARE_EQUAL_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Compares if the left parameter is equal to the right parameter.
 *
 * The result parameter's abstraction must be BOOLEAN.
 * The left side- and right side parameters' abstractions have to be equal.
 * They can be one of:
 * - CHARACTER
 * - INTEGER
 * - DOUBLE
 *
 * @param p0 the left side parameter abstraction
 * @param p1 the left side parameter abstraction count
 * @param p2 the left side parameter abstraction size
 * @param p3 the left side parameter model
 * @param p4 the left side parameter model count
 * @param p5 the left side parameter model size
 * @param p6 the left side parameter details
 * @param p7 the left side parameter details count
 * @param p8 the left side parameter details size
 * @param p9 the right side parameter abstraction
 * @param p10 the right side parameter abstraction count
 * @param p11 the right side parameter abstraction size
 * @param p12 the right side parameter model
 * @param p13 the right side parameter model count
 * @param p14 the right side parameter model size
 * @param p15 the right side parameter details
 * @param p16 the right side parameter details count
 * @param p17 the right side parameter details size
 * @param p18 the result parameter abstraction
 * @param p19 the result parameter abstraction count
 * @param p20 the result parameter abstraction size
 * @param p21 the result parameter model
 * @param p22 the result parameter model count
 * @param p23 the result parameter model size
 * @param p24 the result parameter details
 * @param p25 the result parameter details count
 * @param p26 the result parameter details size
 */
void compare_equal(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14,
    void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20,
    void* p21, void* p22, void* p23,
    void* p24, void* p25, void* p26) {

    if (p21 != NULL_POINTER) {

        int* rm = (int*) p21;

        if (p12 != NULL_POINTER) {

            if (p3 != NULL_POINTER) {

                log_message_debug("Compare if parameters are equal.");

                // The result parameter comparison result.
                int r = 0;

                // Compare result parameter abstraction. It must be a boolean.
                compare_arrays(p18, p19, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    // The left side parameter comparison result.
                    int lr;
                    // The right side parameter comparison result.
                    int rr;

                    //
                    // Character parameters.
                    //

                    // Reset parameter comparison results.
                    lr = 0;
                    rr = 0;

                    // Compare parameter abstractions.
                    compare_arrays(p0, p1, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &lr, (void*) CHARACTER_ARRAY);
                    compare_arrays(p9, p10, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &rr, (void*) CHARACTER_ARRAY);

                    if ((lr == 1) && (rr == 1)) {

                        log_message_debug("Use character parameters.");

                        if (*((char*) p3) == *((char*) p12)) {

                            *rm = *TRUE_BOOLEAN;

                        } else {

                            *rm = *FALSE_BOOLEAN;
                        }
                    }

                    //
                    // Integer parameters.
                    //

                    // Reset parameter comparison results.
                    lr = 0;
                    rr = 0;

                    // Compare parameter abstractions.
                    compare_arrays(p0, p1, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &lr, (void*) CHARACTER_ARRAY);
                    compare_arrays(p9, p10, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &rr, (void*) CHARACTER_ARRAY);

                    if ((lr == 1) && (rr == 1)) {

                        log_message_debug("Use integer parameters.");

                        if (*((int*) p3) == *((int*) p12)) {

                            *rm = *TRUE_BOOLEAN;

                        } else {

                            *rm = *FALSE_BOOLEAN;
                        }
                    }

                    //
                    // Double parameters.
                    //

                    // Reset parameter comparison results.
                    lr = 0;
                    rr = 0;

                    // Compare parameter abstractions.
                    compare_arrays(p0, p1, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &lr, (void*) CHARACTER_ARRAY);
                    compare_arrays(p9, p10, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &rr, (void*) CHARACTER_ARRAY);

                    if ((lr == 1) && (rr == 1)) {

                        log_message_debug("Use double parameters.");

                        if (*((double*) p3) == *((double*) p12)) {

                            *rm = *TRUE_BOOLEAN;

                        } else {

                            *rm = *FALSE_BOOLEAN;
                        }
                    }

                } else {

                    log_message_debug("Could not compare if parameters are equal. The result parameter is not a boolean.");
                }

            } else {

                log_message_debug("Could not compare if parameters are equal. The left side parameter is null.");
            }

        } else {

            log_message_debug("Could not compare if parameters are equal. The right side parameter is null.");
        }

    } else {

        log_message_debug("Could not compare if parameters are equal. The result parameter is null.");
    }
}

/* COMPARE_EQUAL_SOURCE */
#endif
