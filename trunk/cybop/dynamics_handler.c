/*
 * $RCSfile: dynamics_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License; or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful;
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not; write to the Free Software
 * Foundation; Inc.; 59 Temple Place - Suite 330; Boston; MA  02111-1307; USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 */

#ifndef DYNAMICS_HANDLER_SOURCE
#define DYNAMICS_HANDLER_SOURCE

#include "dynamics.c"
#include "log_handler.c"

/**
 * This is the dynamics handler.
 *
 * It implements dynamic operations.
 *
 * @version $Revision: 1.6 $ $Date: 2003-10-09 10:54:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Boolean operations.
//

/**
 * Logical AND.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static void and(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = *i0 && *i1;
    p2 = (void*) &result;
}

/**
 * Logical OR.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static void or(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = *i0 || *i1;
    p2 = (void*) &result;
}

//
// Comparison.
//

/**
 * Compares if the first parameter is equal to the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static void equal(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 == *i1);
    p2 = (void*) &result;
}

/**
 * Compares if the first parameter is smaller than the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static int smaller(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 < *i1);
    p2 = (void*) &result;
}

/**
 * Compares if the first parameter is greater than the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static int greater(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 > *i1);
    p2 = (void*) &result;
}

/**
 * Compares if the first parameter is smaller than or equal to the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static int smaller_or_equal(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 <= *i1);
    p2 = (void*) &result;
}

/**
 * Compares if the first parameter is greater than or equal to the second parameter.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the boolean result
 */
static int greater_or_equal(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 >= *i1);
    p2 = (void*) &result;
}

//
// Algebra.
//

/**
 * Adds the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the sum
 */
static int add(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 + *i1);
    p2 = (void*) &result;
}

/**
 * Subtracts the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the difference
 */
static int subtract(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 - *i1);
    p2 = (void*) &result;
}

/**
 * Multiplies the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the product
 */
static int multiply(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 * *i1);
    p2 = (void*) &result;
}

/**
 * Divides the parameters.
 *
 * @param p0 the first parameter
 * @param p1 the second parameter
 * @param p2 the integer quotient (without rest)
 */
static int divide(void* p0, void* p1, void* p2) {

    int* i0 = (int*) p0;
    int* i1 = (int*) p1;
    int result = (*i0 / *i1);
    // Rest of integer division is determined with:
    // rest = i0 % i1;
    p2 = (void*) &result;
}

//
// Signal handling.
//

/**
 * Handles the mouse clicked action.
 *
 * @param p0 the screen item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the action
 */
static void mouse_clicked_action(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != 0) {

/*??
        // Determine the action of the clicked child screen item.
        int count = 0;
        int size = get_map_size(p0->items);
        void* child = 0;
        struct vector* position = 0;
        struct vector* expansion = 0;
        int x = -1;
        int y = -1;
        int z = -1;
        int width = -1;
        int height = -1;
        int depth = -1;
        int contains = 0;
        void* action = 0;
        
        while (count < size) {

            // Determine child, its position and expansion within the given screen item.
            child = get_map_element(p0->items, count);
            position = (vector*) get_map_element(p0->positions, count);
            
            if (child instanceof item) {
                    
                expansion = (vector) get_item_element(child, "expansion");
                
                if (position != 0) {
                        
                    // Translate the given coordinates according to the child's position.
                    x = p1 - position->x;
                    y = p2 - position->y;
                    z = p3 - position->z;

                    if (expansion != 0) {

                        // Determine child's expansion.
                        width = expansion->x;
                        height = expansion->y;
                        depth = expansion->z;
        
                        // Check if the given coordinates are in the child's screen area.
                        // The "if" conditions had to be inserted because in classical
                        // graphical user interfaces, the depth is normally 0 and
                        // such the boolean comparison would deliver "false".
                        // Using the conditions, the coordinates that are set to "0"
                        // are not considered for comparison.
                        contains = (x >= 0);
                        contains = contains && (x < width);
                        contains = contains && (y >= 0);
                        contains = contains && (y < height);
                        contains = contains && (z >= 0);
                        contains = contains && (z < depth);
        
                        if (contains == 1) {
        
                            // The given coordinates are in the child's screen area.
                            // Therefore, use the child's action.
                            action = mouse_clicked_action(child, x, y, z, p4);
                
                            break;
                        }

                    } else {
                        
                        log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. An expansion is null.");
                    }

                } else {
                    
                    log((void*) &ERROR_LOG_LEVEL, "Could not handle mouse clicked action. A position is null.");
                }

            } else {
                
                log((void*) &INFO_LOG_LEVEL, "Could not handle mouse clicked action. A child is not of type Item.");
            }
            
            count++;
        }
        
        // Only use child screen item's action if it exists.
        // Otherwise, use the parent screen item's action.
        if (action != 0) {
            
            p4 = action;

        } else {
            
            // Determine the action of the given screen item.
            get_map_element(i->items, "mouse_clicked_action", p4);
        }
*/

    } else {
        
        puts("ERROR: Could not handle mouse clicked action. The item is null.");
    }
}

/* DYNAMICS_HANDLER_SOURCE */
#endif

