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
 * This file destroys a transient model into a persistent model.
 *
 * @version $Revision: 1.6 $ $Date: 2004-04-01 17:35:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_MODEL_SOURCE
#define DESTROY_MODEL_SOURCE

#include "../cybol/cybol_model_handler.c"
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
 * Destroys a memory model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 * @param p2 the location
 * @param p3 the abstraction
 */
void destroy_model(void* p0, void* p1, void* p2, void* p3) {

    void** m = (void**) p3;

    if (m != (void*) 0) {

        int r = 0;

        // Do not consider empty cybol models further.
        compare_arrays(p0, (void*) &EMPTY_STRING, (void*) &r);

        if (r == 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Destroy model.");

            // Compound model.
            compare_arrays(p2, (void*) &COMPOUND_MODEL, (void*) &r);

            if (r == 1) {

                finalize_model(p0, p1);
                destroy_model_containers(p0);
                free(p0);

            } else {

                // Dynamics model.
                compare_arrays(p2, (void*) &OPERATION_MODEL, (void*) &r);

                if (r == 1) {

                    finalize_operation_model(p0, p1);
                    destroy_operation_container(p0);
                    free(p0);

                } else {

                    // Statics models.
                    compare_arrays(p2, (void*) &TIME_MODEL, (void*) &r);

                    if (r == 1) {

                        finalize_time_model(p0, p1);
                        free(p0);

                    } else {

                        compare_arrays(p2, (void*) &STRING_MODEL, (void*) &r);

                        if (r == 1) {

                            finalize_string_model(p0, p1);
                            free(p0);

                        } else {

                            compare_arrays(p2, (void*) &VECTOR_MODEL, (void*) &r);

                            if (r == 1) {

                                finalize_vector_model(p0, p1);
                                free(p0);

                            } else {

                                compare_arrays(p2, (void*) &COMPLEX_MODEL, (void*) &r);

                                if (r == 1) {

                                    finalize_complex_model(p0, p1);
                                    free(p0);

                                } else {

                                    compare_arrays(p2, (void*) &FRACTION_MODEL, (void*) &r);

                                    if (r == 1) {

                                        finalize_fraction_model(p0, p1);
                                        free(p0);

                                    } else {

                                        compare_arrays(p2, (void*) &INTEGER_MODEL, (void*) &r);

                                        if (r == 1) {

                                            finalize_integer_model(p0, p1);
                                            free(p0);

                                        } else {

                                            compare_arrays(p2, (void*) &BOOLEAN_MODEL, (void*) &r);

                                            if (r == 1) {

                                                finalize_boolean_model(p0, p1);
                                                free(p0);
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

/* DESTROY_MODEL_SOURCE */
#endif
