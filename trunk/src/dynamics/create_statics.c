/*
 * $RCSfile: create_statics.c,v $
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

#ifndef CREATE_STATICS_SOURCE
#define CREATE_STATICS_SOURCE

/**
 * This is the create statics operation.
 *
 * It creates a statics memory model from a given statics cybol model.
 *
 * @param p0 the statics cybol model path
 * @param p1 the abstraction
 * @return the statics model
 * @version $Revision: 1.1 $ $Date: 2003-12-03 15:10:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
void* create_statics(void* p0, void* p1) {

    void* m = 0;
    char* p = (char*) p0;
    char* a = (char*) p1;
    
    if (p != 0) {
        
        if (strcmp(p, "") != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Create statics: ");
            log((void*) &INFO_LOG_LEVEL, p0);

            if (strcmp(a, STATICS_COMPOUND) == 0) {
        
                m = malloc(sizeof(struct statics_model));
                create_statics_model_containers(m);
                initialize_statics_model(m, p0);
        
            } else if (strcmp(a, TIME_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct time));
                initialize_time_model(m, p0);
                
            } else if (strcmp(a, STRING_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct string));
                initialize_string_model(m, p0);
        
            } else if (strcmp(a, VECTOR_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct vector));
                initialize_vector_model(m, p0);
        
            } else if (strcmp(a, COMPLEX_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct complex));
                initialize_complex_model(m, p0);
        
            } else if (strcmp(a, FRACTION_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct fraction));
                initialize_fraction_model(m, p0);
        
            } else if (strcmp(a, INTEGER_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct integer));
                initialize_integer_model(m, p0);
        
            } else if (strcmp(a, BOOLEAN_PRIMITIVE) == 0) {
        
                m = malloc(sizeof(struct boolean));
                initialize_boolean_model(m, p0);
            }
        }
    }
        
    return m;
}

/* CREATE_STATICS_SOURCE */
#endif

