/*
 * $RCSfile: add.c,v $
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
 * @version $Revision: 1.11 $ $Date: 2004-04-05 16:10:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADD_SOURCE
#define ADD_SOURCE

#include "../logger/log_handler.c"
#include "../statics/integer.c"

/**
 * Adds two summands resulting in the sum.
 *
 * @param p0 the summand 0
 * @param p1 the summand 1
 * @param p2 the sum
 */
void add(void* p0, void* p1, void* p2) {

    struct integer* summand_0 = (struct integer*) p0;
    struct integer* summand_1 = (struct integer*) p1;
    struct integer* sum = (struct integer*) p2;

    if (summand_0 != NULL) {

        if (summand_1 != NULL) {

            if (sum != NULL) {

                sum->value = summand_0->value + summand_1->value;

            } else {
                
                log_message((void*) &ERROR_LOG_LEVEL, "Could not execute add. The sum is null.");
            }
            
        } else {
            
            log_message((void*) &ERROR_LOG_LEVEL, "Could not execute add. The summand 1 is null.");
        }
        
    } else {
        
        log_message((void*) &ERROR_LOG_LEVEL, "Could not execute add. The summand 0 is null.");
    }
};

/* ADD_SOURCE */
#endif
