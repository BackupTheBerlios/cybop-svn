/*
 * $RCSfile: destroy_statics.c,v $
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

#ifndef DESTROY_STATICS_SOURCE
#define DESTROY_STATICS_SOURCE

/**
 * This is the destroy statics operation.
 *
 * It destroys a statics memory model to a given statics cybol model.
 *
 * @param p0 the statics memory model
 * @param p1 the statics cybol model path
 * @param p2 the abstraction
 * @param p3 unused
 * @version $Revision: 1.1 $ $Date: 2003-12-03 15:10:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
void destroy_statics(void* p0, void* p1, void* p2, void* p3) {

    char* p = (char*) p1;
    char* a = (char*) p2;

    if (p0 != 0) {
        
        if (p != 0) {
            
            log((void*) &INFO_LOG_LEVEL, "Destroy statics: ");
            log((void*) &INFO_LOG_LEVEL, p1);
        
            if (strcmp(a, STATICS_COMPOUND) == 0) {
        
                finalize_statics_model(p0, p1);
                destroy_statics_model_containers(p0);
                free(p0);

            } else if (strcmp(a, TIME_PRIMITIVE) == 0) {
        
                finalize_time_model(p0, p1);
                free(p0);
                
            } else if (strcmp(a, STRING_PRIMITIVE) == 0) {
        
                finalize_string_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, VECTOR_PRIMITIVE) == 0) {
        
                finalize_vector_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, COMPLEX_PRIMITIVE) == 0) {
        
                finalize_complex_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, FRACTION_PRIMITIVE) == 0) {
        
                finalize_fraction_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, INTEGER_PRIMITIVE) == 0) {
        
                finalize_integer_model(p0, p1);
                free(p0);
        
            } else if (strcmp(a, BOOLEAN_PRIMITIVE) == 0) {
        
                finalize_boolean_model(p0, p1);
                free(p0);
            }
        }
    }
}

/* DESTROY_STATICS_SOURCE */
#endif

