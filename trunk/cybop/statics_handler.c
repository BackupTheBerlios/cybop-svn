/*
 * $RCSfile: statics_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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

#ifndef STATICS_HANDLER_SOURCE
#define STATICS_HANDLER_SOURCE

#include <string.h>
#include "boolean_handler.c"
#include "complex_handler.c"
#include "fraction_handler.c"
#include "integer_handler.c"
#include "log_handler.c"
#include "model_handler.c"
#include "statics.c"
#include "string_handler.c"
#include "time_handler.c"
#include "vector_handler.c"

/**
 * This is the statics handler.
 *
 * It implements static operators, called "Model".
 * Models are allocated and initialized from a model source.
 *
 * @version $Revision: 1.15 $ $Date: 2003-10-23 14:27:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Statics model.
//

/**
 * Creates a statics model.
 *
 * @param p0 the model source
 * @param p1 the abstraction
 * @return the statics model
 */
static void* create_statics_model(void* p0, void* p1) {

    void* m = 0;
    
    if (p0 != 0) {
        
        if (strcmp((char*) p0, "") != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Create statics model: ");
            log((void*) &INFO_LOG_LEVEL, p0);
    
            if (strcmp(p1, COMPLEX_STATICS_MODEL) == 0) {
        
                m = malloc(sizeof(struct model));
                create_statics_model_containers(m);
                initialize_statics_model(m, p0);
        
            } else if (strcmp(p1, TIME_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct time));
                initialize_time_model(m, p0);
                
            } else if (strcmp(p1, STRING_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct string));
                initialize_string_model(m, p0);
        
            } else if (strcmp(p1, VECTOR_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct vector));
                initialize_vector_model(m, p0);
        
            } else if (strcmp(p1, COMPLEX_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct complex));
                initialize_complex_model(m, p0);
        
            } else if (strcmp(p1, FRACTION_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct fraction));
                initialize_fraction_model(m, p0);
        
            } else if (strcmp(p1, INTEGER_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct integer));
                initialize_integer_model(m, p0);
        
            } else if (strcmp(p1, BOOLEAN_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct boolean));
                initialize_boolean_model(m, p0);
            }
        }
    }
        
    return m;
}

/**
 * Destroys the statics model.
 *
 * @param p0 the statics model
 * @param p1 the model source
 * @param p2 the abstraction
 */
static void destroy_statics_model(void* p0, void* p1, void* p2) {

    if (p0 != 0) {
        
        if (p1 != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Destroy statics model: ");
            log((void*) &INFO_LOG_LEVEL, p1);
        
            if (strcmp(p2, COMPLEX_STATICS_MODEL) == 0) {
        
                finalize_statics_model(p0, p1);
                destroy_statics_model_containers(p0);
                free(p0);

            } else if (strcmp(p2, TIME_PRIMITIVE) == 0) {
        
                finalize_time_model(p0, p1);
                free(p0);
                
            } else if (strcmp(p2, STRING_PRIMITIVE) == 0) {
        
                finalize_string_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, VECTOR_PRIMITIVE) == 0) {
        
                finalize_vector_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, COMPLEX_PRIMITIVE) == 0) {
        
                finalize_complex_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, FRACTION_PRIMITIVE) == 0) {
        
                finalize_fraction_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, INTEGER_PRIMITIVE) == 0) {
        
                finalize_integer_model(p0, p1);
                free(p0);
        
            } else if (strcmp(p2, BOOLEAN_PRIMITIVE) == 0) {
        
                finalize_boolean_model(p0, p1);
                free(p0);
            }
        }
    }
}

/* STATICS_HANDLER_SOURCE */
#endif

