/*
 * $RCSfile: add.c,v $
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

#ifndef ADD_SOURCE
#define ADD_SOURCE

/**
 * This is the add operation.
 *
 * It calculates the sum of two summands.
 *
 * @param p0 the summand 0
 * @param p1 the summand 1
 * @param p2 the sum
 * @version $Revision: 1.2 $ $Date: 2003-12-03 15:10:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
void add(void* p0, void* p1, void* p2) {
    
    int* summand_0 = (int*) p0;
    int* summand_1 = (int*) p1;
    int* sum = (int*) p2;
    
    if (summand_0 != 0) {
        
        if (summand_1 != 0) {
            
            if (sum != 0) {
        
                sum->value = summand_0->value + summand_1->value;
        
            } else {
                
                log((void*) &ERROR_LOG_LEVEL, "Could not execute add. The sum is null.");
            }
            
        } else {
            
            log((void*) &ERROR_LOG_LEVEL, "Could not execute add. The summand 1 is null.");
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not execute add. The summand 0 is null.");
    }
};

/* ADD_SOURCE */
#endif

