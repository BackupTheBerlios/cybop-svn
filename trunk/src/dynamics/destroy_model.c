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
 * @version $Revision: 1.9 $ $Date: 2004-04-21 11:02:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_MODEL_SOURCE
#define DESTROY_MODEL_SOURCE

#include "../logger/log_handler.c"
#include "../model/model_handler.c"
#include "../model/models.c"
#include "../model/statics_models.c"
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

    // The comparison result.
    int r = 0;

    // Do not consider an empty persistent model further.
    int* s = (int*) p3;

    if (*s != 0) {

        //
        // Compound.
        //

        compare_arrays(p4, p5, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_compound(p0, p2, p3);
            destroy_compound(p0);

        } else {

        //
        // Logic and Dynamics.
        //

        compare_arrays(p4, p5, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_operation(p0, p1, p2, p3);
            destroy_operation(p0, p1);

        } else {

        //
        // Statics.
        //

        compare_arrays(p4, p5, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_string(p0, p1, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &BOOLEAN_ABSTRACTION, (void*) &BOOLEAN_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            // No destruction because primitive type.
            finalize_boolean(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            // No destruction because primitive type.
            finalize_integer(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &VECTOR_ABSTRACTION, (void*) &VECTOR_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_vector(p0, p2, p3);
            destroy_vector(p0);

        } else {

        compare_arrays(p4, p5, (void*) &FLOAT_ABSTRACTION, (void*) &FLOAT_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            // No destruction because primitive type.
            finalize_float(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &FRACTION_ABSTRACTION, (void*) &FRACTION_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_fraction(p0, p2, p3);
            destroy_fraction(p0);

        } else {

        compare_arrays(p4, p5, (void*) &COMPLEX_ABSTRACTION, (void*) &COMPLEX_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_complex(p0, p2, p3);
            destroy_complex(p0);

        } else {

        compare_arrays(p4, p5, (void*) &TIME_ABSTRACTION, (void*) &TIME_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            finalize_time(p0, p2, p3);
            destroy_time(p0);

        } // Time.
        } // Complex.
        } // Fraction.
        } // Float.
        } // Vector.
        } // Integer.
        } // Boolean.
        } // String.
        } // Operation.
        } // Compound.
    }
}

/* DESTROY_MODEL_SOURCE */
#endif
