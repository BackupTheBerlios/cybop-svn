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
 */

#ifndef DESTROY_MODEL_SOURCE
#define DESTROY_MODEL_SOURCE

#include "../cybol/cybol_model_handler.c"
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
 * This is the destroy model operation.
 *
 * It destroys a statics or dynamics memory model to a cybol model.
 *
 * @version $Revision: 1.4 $ $Date: 2004-03-01 17:08:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

/**
 * Destroys a memory model to a cybol model.
 *
 * @param p0 the memory model
 * @param p1 the cybol model
 * @param p2 the location
 * @param p3 the abstraction
 */
void destroy_model(void* p0, void* p1, void* p2, void* p3) {

    char* p = (char*) p1;
    char* a = (char*) p3;

    if (p0 != (void*) 0) {

//??        if (p != (void*) 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Destroy model.");
            log_message((void*) &INFO_LOG_LEVEL, p1);

            // Compound model.
            if (strcmp(a, COMPOUND_MODEL) == 0) {

                finalize_model(p0, p1);
                destroy_model_containers(p0);
                free(p0);

            // Dynamics model.
            } else if (strcmp(a, OPERATION_MODEL) == 0) {

                finalize_operation_model(p0, p1);
                destroy_operation_container(p0);
                free(p0);

            // Statics models.
            } else if (strcmp(a, TIME_MODEL) == 0) {

                finalize_time_model(p0, p1);
                free(p0);

            } else if (strcmp(a, STRING_MODEL) == 0) {

                finalize_string_model(p0, p1);
                free(p0);

            } else if (strcmp(a, VECTOR_MODEL) == 0) {

                finalize_vector_model(p0, p1);
                free(p0);

            } else if (strcmp(a, COMPLEX_MODEL) == 0) {

                finalize_complex_model(p0, p1);
                free(p0);

            } else if (strcmp(a, FRACTION_MODEL) == 0) {

                finalize_fraction_model(p0, p1);
                free(p0);

            } else if (strcmp(a, INTEGER_MODEL) == 0) {

                finalize_integer_model(p0, p1);
                free(p0);

            } else if (strcmp(a, BOOLEAN_MODEL) == 0) {

                finalize_boolean_model(p0, p1);
                free(p0);
            }
//??        }
    }
}

/* DESTROY_MODEL_SOURCE */
#endif
