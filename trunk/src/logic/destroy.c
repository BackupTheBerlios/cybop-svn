/*
 * $RCSfile: destroy.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2004-08-23 07:52:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_SOURCE
#define DESTROY_SOURCE

#include "../logger/logger.c"

/**
 * Serializes a transient model to a persistent model.
 *
 * Finalizes and destroys the transient model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void serialize_model(void* p0, void* p1, void* p2, void* p3, const void* p4, const void* p5) {

/*??
    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p5 != NULL_POINTER) {

        int* ac = (int*) p5;

        if (p3 != NULL_POINTER) {

            int* pc = (int*) p3;

            // Only proceed, if persistent model is not empty.
            if (*pc > 0) {

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

                    if (*ac == COMPOUND_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_compound(p0, p1, p2, p3);
                            destroy_compound(p0, p1);

                            d = 1;
                        }
                    }
                }

                //
                // Logic and Dynamics.
                //

                if (d == 0) {

                    if (*ac == OPERATION_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

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

                    if (*ac == STRING_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_string(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_boolean(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == INTEGER_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_integer(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == VECTOR_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_vector(p0, p1, p2, p3);
                            destroy_vector(p0, p1);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_double(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == FRACTION_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_fraction(p0, p1, p2, p3);
                            destroy_fraction(p0, p1);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_complex(p0, p1, p2, p3);
                            destroy_complex(p0, p1);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == TIME_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_time(p0, p1, p2, p3);
                            destroy_time(p0, p1);

                            d = 1;
                        }
                    }
                }
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not serialize model. The persistent model count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not serialize model. The abstraction count is null.");
    }
*/
}

/**
 * Destroys a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the transient position model
 * @param p4 the transient position model count
 * @param p5 the transient position model size
 * @param p6 the persistent part abstraction
 * @param p7 the persistent part abstraction count
 * @param p8 the persistent part location
 * @param p9 the persistent part location count
 * @param p10 the persistent part model
 * @param p11 the persistent part model count
 * @param p12 the persistent position abstraction
 * @param p13 the persistent position abstraction count
 * @param p14 the persistent position location
 * @param p15 the persistent position location count
 * @param p16 the persistent position model
 * @param p17 the persistent position model count
 */
void handle_destroy(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    const void* p6, const void* p7, const void* p8, const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14, const void* p15, const void* p16, const void* p17) {

/*??
    if (p5 != NULL_POINTER) {

        int* pos = (int*) p5;

        if (p4 != NULL_POINTER) {

            int* poc = (int*) p4;

            if (p3 != NULL_POINTER) {

                void** po = (void**) p3;

                if (p2 != NULL_POINTER) {

                    int* ps = (int*) p2;

                    if (p1 != NULL_POINTER) {

                        int* pc = (int*) p1;

                        if (p0 != NULL_POINTER) {

                            void** p = (void**) p0;

                            //
                            // Buffer.
                            //

                            // The buffer array.
                            void* b = NULL_POINTER;
                            // The buffer array count.
                            int bc = 0;
                            // The buffer array size.
                            int bs = 0;

                            //
                            // Part.
                            //

                            // Create buffer array of type character to read single bytes.
                            create_array((void*) &b, (void*) &CHARACTER_ARRAY, (void*) &bs);
                            // Read persistent model from location into buffer array.
                            read_model((void*) &b, (void*) &bc, (void*) &bs, p8, p9, p10, p11);
                            // Create and initialize transient model from buffer array.
                            interpret_model((void*) &p, (void*) &pc, (void*) &ps, (void*) &b, (void*) &bc, p6, p7);
                            // Destroy buffer array.
                            destroy_array((void*) &b, (void*) &CHARACTER_ARRAY, (void*) &bs);

                            //
                            // Position.
                            //

                            // Create buffer array of type character to read single bytes.
                            create_array((void*) &b, (void*) &CHARACTER_ARRAY, (void*) &bs);
                            // Read persistent model from location into buffer array.
                            read_model((void*) &b, (void*) &bc, (void*) &bs, p14, p15, p16, p17);
                            // Create and initialize transient model from buffer array.
                            interpret_model((void*) &po, (void*) &poc, (void*) &pos, (void*) &b, (void*) &bc, p12, p13);
                            // Destroy buffer array.
                            destroy_array((void*) &b, (void*) &CHARACTER_ARRAY, (void*) &bs);

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_IS_NULL_MESSAGE_COUNT);
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_COUNT_IS_NULL_MESSAGE_COUNT);
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_SIZE_IS_NULL_MESSAGE_COUNT);
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_POSITION_MODEL_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_POSITION_MODEL_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_POSITION_MODEL_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_POSITION_MODEL_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_POSITION_MODEL_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_POSITION_MODEL_SIZE_IS_NULL_MESSAGE_COUNT);
    }
*/
}

/* DESTROY_SOURCE */
#endif
