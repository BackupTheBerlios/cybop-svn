/*
 * $RCSfile: array_handler.c,v $
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

/**
 * This is the array handler.
 *
 * An array represents an allocated area in the computer's memory
 * that can contain a number of abstract elements.
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * Array elements are accessed over their index.
 *
 * @version $Revision: 1.7 $ $Date: 2003-09-27 19:50:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Array.
//

/**
 * Extends the array by doubling its length.
 *
 * All elements are copied from the old to the new array.
 *
 * @param p0 the array
 * @param p1 the extended array
 */
void extend_array(void* p0, void* p1) {

    if (p0 != 0) {

        int old_length = sizeof(p0);
        int new_length = old_length * 2 + 1;
        p1 = malloc(sizeof(new_length));

        if (p1 != 0) {
                
            int i = 0;

            while (i < old_length) {

//??                a[i] = p0[i];

                i++;
            }

            free(p0);

        } else {

            log(ERROR_LOG_LEVEL, "Could not extend array. The new array is null.");
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not extend array. The array is null.");
    }
}

//
// Array element.
//

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the element
 * @param p3 the same or an extended array
 */
void set_array_element(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != 0) {

        // If the array length is exceeded, a new array with extended length
        // is created and delivered back.
        if (p1 >= sizeof(p0)) {

            extend_array(p0, p3);
        
        } else {
        
            p3 = p0;
        }

        // Set element.
        p3[p1] = p2;

    } else {

        log(ERROR_LOG_LEVEL, "Could not set array element. The array is null.");
    }
}

/**
 * Removes the array element.
 *
 * @param p0 the array
 * @param p1 the index
 */
void remove_array_element(void* p0, void* p1) {

    if (p0 != 0) {

        if (*p1 != -1) {
            
            // Move all remaining elements one place towards the
            // beginning of the elements.
            int size = sizeof(p0);

            while ((*p1 + 1) < size) {

//??                p0[p1] = p0[p1 + 1];

                (*p1)++;
            }

            // Set former last element to 0.
            p0[*p1] = 0;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not remove array element. The array is null.");
    }
}

/**
 * Returns the element.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the element
 */
void get_array_element(void* p0, void* p1, void* p2) {

    if (p0 != 0) {

        if (*p1 != -1) {
            
//??            p2 = p0[*p1];
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get array element. The array is null.");
    }
}

