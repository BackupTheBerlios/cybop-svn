/*
 * $RCSfile: destroy_model.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file destroys a transient model to a persistent model.
 *
 * @version $Revision: 1.17 $ $Date: 2004-04-29 15:18:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_MODEL_SOURCE
#define DESTROY_MODEL_SOURCE

#include "../logger/log_handler.c"
#include "../model/model_handler.c"
#include "../statics/boolean_handler.c"
#include "../statics/complex_handler.c"
#include "../statics/double_handler.c"
#include "../statics/fraction_handler.c"
#include "../statics/integer_handler.c"
#include "../statics/operation_handler.c"
#include "../statics/string_handler.c"
#include "../statics/time_handler.c"
#include "../statics/vector_handler.c"

/**
 * Destroys a transient model to a persistent model.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 * @param p4 the abstraction
 * @param p5 the abstraction size
 */
void destroy_model(void* p0, void* p1, void* p2, void* p3, const void* p4, const void* p5) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p5 != NULL_POINTER) {

        int* s = (int*) p5;

        if (p3 != NULL_POINTER) {

            int* ps = (int*) p3;

            // Only proceed, if persistent model is not empty.
            if (*ps > 0) {

                //
                // Three comparisons are done:
                // 1 done flag (no further processing if an abstraction already matched)
                // 2 abstraction size
                // 3 abstraction characters
                //
                // The order is important!
                // The size needs to be checked before the arrays are handed over to the
                // comparison procedure. Otherwise, array boundaries might get crossed.
                //

                //
                // Compound.
                //

                if (d == 0) {

                    if (*s == COMPOUND_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_compound(p0, p2, p3);
                            destroy_compound(p0);

                            d = 1;
                        }
                    }
                }

                //
                // Logic and Dynamics.
                //

                if (d == 0) {

                    if (*s == OPERATION_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_operation(p0, p1, p2, p3);
                            destroy_operation(p0, p1);

                            d = 1;
                        }
                    }
                }

                //
                // Statics.
                //

                if (d == 0) {

                    if (*s == STRING_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_string(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == BOOLEAN_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_boolean(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == INTEGER_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_integer(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == VECTOR_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_vector(p0, p2, p3);
                            destroy_vector(p0);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == DOUBLE_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_double(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == FRACTION_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_fraction(p0, p2, p3);
                            destroy_fraction(p0);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == COMPLEX_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_complex(p0, p2, p3);
                            destroy_complex(p0);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == TIME_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            finalize_time(p0, p2, p3);
                            destroy_time(p0);

                            d = 1;
                        }
                    }
                }
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not destroy model. The persistent model size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not destroy model. The abstraction size is null.");
    }
}

/* DESTROY_MODEL_SOURCE */
#endif
