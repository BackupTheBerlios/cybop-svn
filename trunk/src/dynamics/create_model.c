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
 *
 * This file creates a transient model from a persistent model.
 *
 * @version $Revision: 1.11 $ $Date: 2004-04-21 11:02:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

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

//
// Constants.
//

/** The compound abstraction. */
static const char COMPOUND_ABSTRACTION[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};

/** The compound abstraction size. */
static const int COMPOUND_ABSTRACTION_SIZE = 8;

/** The operation abstraction. */
static const char OPERATION_ABSTRACTION[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

/** The operation abstraction size. */
static const int OPERATION_ABSTRACTION_SIZE = 9;

/** The string abstraction. */
static const char STRING_ABSTRACTION[] = {'s', 't', 'r', 'i', 'n', 'g'};

/** The string abstraction size. */
static const int STRING_ABSTRACTION_SIZE = 6;

/** The boolean abstraction. */
static const char BOOLEAN_ABSTRACTION[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};

/** The boolean abstraction size. */
static const int BOOLEAN_ABSTRACTION_SIZE = 7;

/** The integer abstraction. */
static const char INTEGER_ABSTRACTION[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};

/** The integer abstraction size. */
static const int INTEGER_ABSTRACTION_SIZE = 7;

/** The vector abstraction. */
static const char VECTOR_ABSTRACTION[] = {'v', 'e', 'c', 't', 'o', 'r'};

/** The vector abstraction size. */
static const int VECTOR_ABSTRACTION_SIZE = 6;

/** The float abstraction. */
static const char FLOAT_ABSTRACTION[] = {'f', 'l', 'o', 'a', 't'};

/** The float abstraction size. */
static const int FLOAT_ABSTRACTION_SIZE = 5;

/** The fraction abstraction. */
static const char FRACTION_ABSTRACTION[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The fraction abstraction size. */
static const int FRACTION_ABSTRACTION_SIZE = 8;

/** The complex abstraction. */
static const char COMPLEX_ABSTRACTION[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};

/** The complex abstraction size. */
static const int COMPLEX_ABSTRACTION_SIZE = 7;

/** The time abstraction. */
static const char TIME_ABSTRACTION[] = {'t', 'i', 'm', 'e'};

/** The time abstraction size. */
static const int TIME_ABSTRACTION_SIZE = 4;

/**
 * Creates a transient model from a persistent model.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 * @param p4 the abstraction
 * @param p5 the abstraction size
 */
void create_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5) {

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

            create_compound(p0);
            initialize_compound(p0, p2, p3);

        } else {

        //
        // Logic and Dynamics.
        //

        compare_arrays(p4, p5, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            create_operation(p0, p1);
            initialize_operation(p0, p1, p2, p3);

        } else {

        //
        // Statics.
        //

        compare_arrays(p4, p5, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            initialize_string(p0, p1, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &BOOLEAN_ABSTRACTION, (void*) &BOOLEAN_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            // No creation because primitive type.
            initialize_boolean(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            // No creation because primitive type.
            initialize_integer(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &VECTOR_ABSTRACTION, (void*) &VECTOR_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            create_vector(p0);
            initialize_vector(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &FLOAT_ABSTRACTION, (void*) &FLOAT_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            // No creation because primitive type.
            initialize_float(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &FRACTION_ABSTRACTION, (void*) &FRACTION_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            create_fraction(p0);
            initialize_fraction(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &COMPLEX_ABSTRACTION, (void*) &COMPLEX_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            create_complex(p0);
            initialize_complex(p0, p2, p3);

        } else {

        compare_arrays(p4, p5, (void*) &TIME_ABSTRACTION, (void*) &TIME_ABSTRACTION_SIZE, (void*) &CHARACTER_ARRAY, (void*) &r);

        if (r == 1) {

            create_time(p0);
            initialize_time(p0, p2, p3);

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

/* CREATE_MODEL_SOURCE */
#endif
