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
 * @version $Revision: 1.4 $ $Date: 2004-03-01 17:08:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Creates a memory model from a cybol model.
 *
 * @param p0 the cybol model
 * @param p1 the location
 * @param p2 the abstraction
 * @return the memory model
 */
void* create_model(void* p0, void* p1, void* p2) {

    void* m = (void*) 0;
    char* p = (char*) p0;
    char* a = (char*) p2;

    if (p != (void*) 0) {

        if (strcmp(p, "") != 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Create model.");
            log_message((void*) &INFO_LOG_LEVEL, p0);

            // Compound model.
            if (strcmp(a, COMPOUND_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct model));
                create_model_containers(m);
                initialize_model(m, p0);

            // Dynamics model.
            } else if (strcmp(a, OPERATION_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct operation));
                create_operation_container(m);
                initialize_operation_model(m, p0);

            // Statics models.
            } else if (strcmp(a, TIME_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct time));
                initialize_time_model(m, p0);

            } else if (strcmp(a, STRING_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct string));
                initialize_string_model(m, p0);

            } else if (strcmp(a, VECTOR_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct vector));
                initialize_vector_model(m, p0);

            } else if (strcmp(a, COMPLEX_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct complex));
                initialize_complex_model(m, p0);

            } else if (strcmp(a, FRACTION_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct fraction));
                initialize_fraction_model(m, p0);

            } else if (strcmp(a, INTEGER_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct integer));
                initialize_integer_model(m, p0);

            } else if (strcmp(a, BOOLEAN_MODEL) == 0) {

                m = (void*) malloc(sizeof(struct boolean));
                initialize_boolean_model(m, p0);
            }
        }
    }

    return m;
}

/* CREATE_MODEL_SOURCE */
#endif
