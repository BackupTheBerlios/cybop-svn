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
 * @version $Revision: 1.16 $ $Date: 2004-04-22 13:25:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

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
    if (p3 != NULL_POINTER) {

        int* s = (int*) p3;

        if (*s != 0) {

            //
            // Compound.
            //

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                create_compound(p0);
                initialize_compound(p0, p2, p3);

            } else {

            //
            // Logic and Dynamics.
            //

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                create_operation(p0, p1);
                initialize_operation(p0, p1, p2, p3);

            } else {

            //
            // Statics.
            //

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                initialize_string(p0, p1, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                // No creation because primitive type.
                initialize_boolean(p0, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                // No creation because primitive type.
                initialize_integer(p0, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                create_vector(p0);
                initialize_vector(p0, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                // No creation because primitive type.
                initialize_double(p0, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                create_fraction(p0);
                initialize_fraction(p0, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_SIZE, (void*) &r);

            if (r == 1) {

                create_complex(p0);
                initialize_complex(p0, p2, p3);

            } else {

            //?? CAUTION! Still compare sizes here!
            compare_array_elements(p4, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_SIZE, (void*) &r);

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

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create model. The persistent model size is null.");
    }
}

/* CREATE_MODEL_SOURCE */
#endif
