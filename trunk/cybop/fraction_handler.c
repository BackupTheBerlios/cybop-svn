/*
 * $RCSfile: fraction_handler.c,v $
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

#include "fraction.c"

/**
 * This is the fraction handler.
 *
 * @version $Revision: 1.2 $ $Date: 2003-10-22 00:45:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default fraction value. */
static const int DEFAULT_FRACTION_VALUE = 0.0;

//
// Fraction model.
//

/**
 * Creates a fraction model.
 *
 * @param p0 the model source
 * @return the fraction model
 */
static void* create_fraction_model(void* p0) {

    void* i = 0;
    
    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Create fraction model.");

        if (strcmp(p0, "") != 0) {
            
            i = malloc(sizeof(struct fraction));

            initialize_fraction_model(i, p0);
        }
    }
    
    return i;
}

/**
 * Destroys the fraction model.
 *
 * @param p0 the fraction model
 * @param p1 the model source
 */
static void destroy_fraction_model(void* p0, void* p1) {

    if (p0 != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Destroy fraction model.");

        if (strcmp(p1, "") != 0) {
            
            finalize_fraction_model(p0, p1);
        }

        free(p0);
    }
}

/**
 * Initializes the fraction model.
 *
 * @param p0 the fraction model
 * @param p1 the model source
 */
static void initialize_fraction_model(void* p0, void* p1) {

    struct fraction* f = (struct fraction*) p0;
    
    if (f != 0) {
        
        log((void*) &INFO_LOG_LEVEL, "Initialize fraction model.");

        // Read input stream and transform to fraction.
        fscanf(p1, %f, &(f->value));

    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not initialize fraction model. The fraction model is null.");
    }
}

/**
 * Finalizes the fraction model.
 *
 * @param p0 the fraction model
 */
static void finalize_fraction_model(void* p0, void* p1) {

    struct fraction* f = (struct fraction*) p0;
    
    if (f != 0) {

        log((void*) &INFO_LOG_LEVEL, "Finalize fraction model.");

        // Write output stream and transform from fraction.
        fprintf(p1, %f, &(f->value));

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize fraction model. The fraction model is null.");
    }
}

