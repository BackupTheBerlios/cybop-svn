/*
 * $RCSfile: create_model.c,v $
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
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

#include "../logger/log_handler.c"
#include "../model/models.c"
#include "../model/statics_models.c"
#include "../statics/boolean_handler.c"
#include "../statics/complex_handler.c"
#include "../statics/fraction_handler.c"
#include "../statics/integer_handler.c"
#include "../statics/operation_handler.c"
#include "../statics/string_handler.c"
#include "../statics/time_handler.c"
#include "../statics/vector_handler.c"

/**
 * This is the create model operation.
 *
 * It creates a statics or dynamics memory model from a cybol model.
 *
 * @version $Revision: 1.7 $ $Date: 2004-04-01 15:15:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the transient model
 * @param p1 the abstraction
 * @param p2 the abstraction size
 * @param p3 the persistent model
 * @param p4 the persistent model size
 */
void create_model(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    //?? part name="x" part_abstraction="compound" part_model="ftp://test_compound.cybol"
    //?? part name="y" part_abstraction="string" part_model="file://test_string.txt"
    //?? part name="z" part_abstraction="string" part_model="inline://This is a test string."

    // The comparison result.
    int r = 0;

    // Do not consider an empty persistent model further.
    int* s = (int*) p4;

    if (*s != 0) {

        // Compound.
        compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND, (void*) &COMPOUND_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            create_compound(p0);
            initialize_compound(p0, p3, p4);

        } else {

            // Operation.
            compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &OPERATION, (void*) &OPERATION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

            if (r == 1) {

                create_operation(p0);
                initialize_operation(p0, p3, p4);

            } else {

                compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &STRING, (void*) &STRING_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                if (r == 1) {

                    create_string(p0);
                    initialize_string(p0, p3, p4);

                } else {

                    compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_MODEL, (void*) &COMPOUND_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                    if (r == 1) {

                        initialize_boolean(p0, p3, p4);

                    } else {

                        compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_MODEL, (void*) &COMPOUND_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                        if (r == 1) {

                            initialize_integer(p0, p3, p4);

                        } else {

                            compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &VECTOR, (void*) &VECTOR_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                            if (r == 1) {

                                create_vector(p0);
                                initialize_vector(p0, p3, p4);

                            } else {

                                compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &FLOAT_MODEL, (void*) &COMPOUND_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                                if (r == 1) {

                                    create_fraction(p0);
                                    initialize_fraction(p0, p3, p4);

                                } else {

                                    compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_MODEL, (void*) &COMPOUND_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                                    if (r == 1) {

                                        create_fraction(p0);
                                        initialize_fraction(p0, p3, p4);

                                    } else {

                                        compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_MODEL, (void*) &COMPOUND_MODEL_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                                        if (r == 1) {

                                            create_complex(p0);
                                            initialize_complex(p0, p3, p4);

                                        } else {

                                            // Statics models.
                                            compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, (void*) &TIME, (void*) &TIME_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

                                            if (r == 1) {

                                                create_time(p0);
                                                initialize_time(p0, p3, p4);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/* CREATE_MODEL_SOURCE */
#endif
