/*
 * $RCSfile: add_integer_vector.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2006-06-23 00:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_INTEGER_VECTOR_SOURCE
#define ADD_INTEGER_VECTOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Adds two integer vectors.
 *
 * @param p0 the sum (Hand over as reference!)
 * @param p1 the sum count
 * @param p2 the sum size
 * @param p3 the summand 1
 * @param p4 the summand 1 count
 * @param p5 the summand 2
 * @param p6 the summand 2 count
 */
void add_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != NULL_POINTER) {

        int* s2c = (int*) p6;

        if (p4 != NULL_POINTER) {

            int* s1c = (int*) p4;

            if (p2 != NULL_POINTER) {

                int* ss = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* sc = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** s = (void**) p0;

                        log_message_debug("Add integer vectors.");

                        // CAUTION! In order to achieve correct results,
                        // the sum array needs to be resized to the exact size
                        // of the summand with the SMALLER count!
                        // Otherwise, the array borders of the summand with the
                        // smaller count would be crossed.

                        if (*s1c < *s2c) {

                            *ss = *s1c;

                        } else {

                            *ss = *s2c;
                        }

                        // The sum count serves as loop count below.
                        *sc = *NUMBER_0_INTEGER;

                        reallocate_array(p0, p1, p2, (void*) INTEGER_ARRAY);

                        // The temporary values.
                        int summand1 = 0;
                        int summand2 = 0;
                        int sum = 0;

                        while (1) {

                            if (*sc >= *ss) {

                                break;
                            }

                            get_array_elements(*s, (void*) sc, (void*) &sum, (void*) INTEGER_ARRAY);
                            get_array_elements(p3, (void*) sc, (void*) &summand1, (void*) INTEGER_ARRAY);
                            get_array_elements(p5, (void*) sc, (void*) &summand2, (void*) INTEGER_ARRAY);

                            sum = summand1 + summand2;

                            set_array_elements(*s, (void*) sc, (void*) &sum, (void*) PRIMITIVE_COUNT, (void*) INTEGER_ARRAY);

                            (*sc)++;
                        }

                    } else {

                        log_message_debug("Could not add integer vectors. The sum is null.");
                    }

                } else {

                    log_message_debug("Could not add integer vectors. The sum count is null.");
                }

            } else {

                log_message_debug("Could not add integer vectors. The sum size is null.");
            }

        } else {

            log_message_debug("Could not add integer vectors. The summand 1 count is null.");
        }

    } else {

        log_message_debug("Could not add integer vectors. The summand 2 count is null.");
    }
}

/* ADD_INTEGER_VECTOR_SOURCE */
#endif
