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
 * @version $Revision: 1.6 $ $Date: 2004-03-29 21:54:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the transient model
 * @param p1 the abstraction
 * @param p2 the abstraction size
 * @param p3 the location
 * @param p4 the location size
 * @param p5 the persistent model
 * @param p6 the persistent model size
 */
void create_model(void* p0, const void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6) {

    int r = 0;

    // Do not consider an empty persistent model further.
    char* e = {};
    int es = 0;
    compare_arrays(p5, p6, (void*) &CHARACTER_ARRAY, (void*) &e, (void*) &es, (void*) &CHARACTER_ARRAY, (void*) &r);

    if (r == 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Create model.");

        // Compound model.
        compare_arrays(p2, (void*) &COMPOUND_MODEL, (void*) &r);

        if (r == 1) {

            create_compound_model(p3);
            initialize_compound_model(p3, p0);

        } else {

            // Operation model.
            compare_arrays(p2, (void*) &OPERATION_MODEL, (void*) &r);

            if (r == 1) {

                create_operation_model(p3);
                initialize_operation_model(p3, p0);

            } else {

                // Statics models.
                compare_arrays(p2, (void*) &TIME_MODEL, (void*) &r);

                if (r == 1) {

                    create_time_model(p3);
                    initialize_time_model(p3, p0);

                } else {

                    compare_arrays(p2, (void*) &STRING_MODEL, (void*) &r);

                    if (r == 1) {

                        create_string_model(p3);
                        initialize_string_model(p3, p0);

                    } else {

                        compare_arrays(p2, (void*) &VECTOR_MODEL, (void*) &r);

                        if (r == 1) {

                            create_vector_model(p3);
                            initialize_vector_model(p3, p0);

                        } else {

                            compare_arrays(p2, (void*) &COMPLEX_MODEL, (void*) &r);

                            if (r == 1) {

                                create_complex_model(p3);
                                initialize_complex_model(p3, p0);

                            } else {

                                compare_arrays(p2, (void*) &FRACTION_MODEL, (void*) &r);

                                if (r == 1) {

                                    create_fraction_model(p3);
                                    initialize_fraction_model(p3, p0);

                                } else {

                                    compare_arrays(p2, (void*) &INTEGER_MODEL, (void*) &r);

                                    if (r == 1) {

                                        create_integer_model(p3);
                                        initialize_integer_model(p3, p0);

                                    } else {

                                        compare_arrays(p2, (void*) &BOOLEAN_MODEL, (void*) &r);

                                        if (r == 1) {

                                            create_boolean_model(p3);
                                            initialize_boolean_model(p3, p0);
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
