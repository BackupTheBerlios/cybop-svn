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

#ifndef FRACTION_HANDLER_SOURCE
#define FRACTION_HANDLER_SOURCE

#include "../logger/log_handler.c"
#include "../statics/fraction.c"

/**
 * This is the fraction handler.
 *
 * @version $Revision: 1.6 $ $Date: 2004-01-05 20:24:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The default fraction value. */
static const double DEFAULT_FRACTION_VALUE = 0.0;

//
// Fraction model.
//

/**
 * Initializes the fraction model.
 *
 * @param p0 the fraction model
 * @param p1 the model source
 */
void initialize_fraction_model(void* p0, void* p1) {

    struct fraction* m = (struct fraction*) p0;
    
    if (m != 0) {
        
        log_message((void*) &INFO_LOG_LEVEL, "Initialize fraction model.");

        // Read input stream and transform to fraction.
//??        sscanf(p1, %l, (void*) &(m->value));

    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize fraction model. The fraction model is null.");
    }
}

/**
 * Finalizes the fraction model.
 *
 * @param p0 the fraction model
 */
void finalize_fraction_model(void* p0, void* p1) {

    struct fraction* m = (struct fraction*) p0;
    
    if (m != 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize fraction model.");

        // Write output stream and transform from fraction.
//??        sprintf(p1, %l, (void*) &(m->value));

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize fraction model. The fraction model is null.");
    }
}

/* FRACTION_HANDLER_SOURCE */
#endif

