/*
 * $RCSfile: complex_handler.c,v $
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

#ifndef COMPLEX_HANDLER_SOURCE
#define COMPLEX_HANDLER_SOURCE

#include <string.h>
#include "complex.c"

/**
 * This is the complex handler.
 *
 * @version $Revision: 1.3 $ $Date: 2003-12-09 15:49:45 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default complex value. */
static const char* DEFAULT_COMPLEX_VALUE = "0.0,0.0";

//
// Complex model.
//

/**
 * Initializes the complex model.
 *
 * @param p0 the complex model
 * @param p1 the model source
 */
static void initialize_complex_model(void* p0, void* p1) {

    struct complex* m = (struct complex*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize complex model.");

        // Read input stream and transform to complex.
//??        fscanf(p1, %d, (void*) &(m->real));
//??        fscanf(p1, %d, (void*) &(m->imaginary));

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize complex model. The complex model is null.");
    }
}

/**
 * Finalizes the complex model.
 *
 * @param p0 the complex model
 * @param p1 the model source
 */
static void finalize_complex_model(void* p0, void* p1) {

    struct complex* m = (struct complex*) p0;
    
    if (m != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Finalize complex model.");
        
        // Write output stream and transform from complex.
//??        fprintf(p1, %d, (void*) &(m->real));
//??        fprintf(p1, %d, (void*) &(m->imaginary));

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize complex model. The complex model is null.");
    }
}

/* COMPLEX_HANDLER_SOURCE */
#endif

