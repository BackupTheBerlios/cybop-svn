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
 * This is an add operation.
 *
 * It calculates the sum of two summands.
 *
 * @param p0 the operand (model)
 * @version $Revision: 1.1 $ $Date: 2003-10-23 15:23:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
void add(void* p0) {

    struct model* m = (struct model*) p0;
    
    if (m != 0) {
        
        void* summand_1 = get_map_element_with_name(m->children, "summand_1");
        void* summand_2 = get_map_element_with_name(m->children, "summand_2");

        if (summand_1 != null) {
            
            int* summand_1_value = (int*) summand_1->value;
            
            if (summand_2 != null) {
        
                int* summand_2_value = (int*) summand_2->value;

                int sum = *summand_1_value + *summand_2_value;

                //?? Caution! Does not work with sum as locally defined variable!
                set_map_element_with_name(m->children, "sum", (void*) &sum);
            }
        }
        
    } else {
        
        log((void*) &ERROR_LOG_LEVEL, "Could not execute add operation. The operand is null.");
    }
};

/* ADD_SOURCE */
#endif

