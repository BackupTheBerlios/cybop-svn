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
#include "../model/map.c"
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
 * @version $Revision: 1.5 $ $Date: 2004-03-11 22:44:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the cybol model
 * @param p1 the location
 * @param p2 the abstraction
 * @param p3 the memory model
 */
void create_model(const void* p0, const void* p1, const void* p2, void* p3) {

    void** m = (void**) p3;

    if (m != (void*) 0) {

        int r = 0;

        // Do not consider empty cybol models further.
        compare_arrays(p0, (void*) &EMPTY_STRING, (void*) &r);

        if (r == 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Create model.");

            // Compound model.
            compare_arrays(p2, (void*) &COMPOUND_MODEL, (void*) &r);

            if (r == 1) {

                *m = (void*) malloc(sizeof(struct model));
                create_model_containers((void*) m);
                initialize_model((void*) m, p0);

            } else {

                // Dynamics model.
                compare_arrays(p2, (void*) &OPERATION_MODEL, (void*) &r);

                if (r == 1) {

                    *m = (void*) malloc(sizeof(struct operation));
                    create_operation_container((void*) m);
                    initialize_operation_model((void*) m, p0);

                } else {

                    // Statics models.
                    compare_arrays(p2, (void*) &TIME_MODEL, (void*) &r);

                    if (r == 1) {

                        *m = (void*) malloc(sizeof(struct time));
                        initialize_time_model((void*) m, p0);

                    } else {

                        compare_arrays(p2, (void*) &STRING_MODEL, (void*) &r);

                        if (r == 1) {

                            *m = (void*) malloc(sizeof(struct string));
                            initialize_string_model((void*) m, p0);

                        } else {

                            compare_arrays(p2, (void*) &VECTOR_MODEL, (void*) &r);

                            if (r == 1) {

                                *m = (void*) malloc(sizeof(struct vector));
                                initialize_vector_model((void*) m, p0);

                            } else {

                                compare_arrays(p2, (void*) &COMPLEX_MODEL, (void*) &r);

                                if (r == 1) {

                                    *m = (void*) malloc(sizeof(struct complex));
                                    initialize_complex_model((void*) m, p0);

                                } else {

                                    compare_arrays(p2, (void*) &FRACTION_MODEL, (void*) &r);

                                    if (r == 1) {

                                        *m = (void*) malloc(sizeof(struct fraction));
                                        initialize_fraction_model((void*) m, p0);

                                    } else {

                                        compare_arrays(p2, (void*) &INTEGER_MODEL, (void*) &r);

                                        if (r == 1) {

                                            *m = (void*) malloc(sizeof(struct integer));
                                            initialize_integer_model((void*) m, p0);

                                        } else {

                                            compare_arrays(p2, (void*) &BOOLEAN_MODEL, (void*) &r);

                                            if (r == 1) {

                                                *m = (void*) malloc(sizeof(struct boolean));
                                                initialize_boolean_model((void*) m, p0);
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

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not create model. The model is null.");
    }
}

/* CREATE_MODEL_SOURCE */
#endif
