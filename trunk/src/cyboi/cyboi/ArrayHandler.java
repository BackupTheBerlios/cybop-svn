/*
 * $RCSfile: ArrayHandler.java,v $
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

package cyboi;

/**
 * This is an array handler.
 *
 * Array elements are accessed over their index.
 *
 * @version $Revision: 1.13 $ $Date: 2003-08-11 19:30:40 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ArrayHandler {

    //
    // Array.
    //

    /**
     * Extends the array by doubling its length.
     *
     * All elements are copied from the old to the new array.
     *
     * @param p0 the array
     * @return the extended array
     */
    static java.lang.Object[] extend_array(java.lang.Object[] p0) {

        java.lang.Object[] a = null;
        
        if (p0 != null) {

            int old_length = p0.length;
            int new_length = old_length * 2 + 1;
            a = new java.lang.Object[new_length];
            
            if (a != null) {
                    
                int i = 0;
    
                while (i < old_length) {
    
                    a[i] = p0[i];
    
                    i++;
                }
    
                p0 = null;

            } else {
    
                System.out.println("ERROR: Could not extend array. The new array is null.");
            }

        } else {

            System.out.println("ERROR: Could not extend array. The array is null.");
        }
        
        return a;
    }

    /**
     * Returns the array size.
     *
     * @param p0 the array
     * @return the array size
     */
    static int get_array_size(java.lang.Object[] p0) {

        int s = -1;

        if (p0 != null) {

            s = p0.length;

        } else {

            System.out.println("ERROR: Could not get array size. The array is null.");
        }

        return s;
    }

    /**
     * Compares both arrays.
     *
     * @param p0 the first array
     * @param p1 the second array
     * @return 1 if the size and contents of both arrays are equal; 0 otherwise
     */
    static int compare(java.lang.Object[] p0, java.lang.Object[] p1) {

        int r = 1;
/*??
        int i = ArrayHandler.get_array_size(p0);

        // Compares the array sizes.
        if (i != ArrayHandler.get_array_size(p1)) {

            r = 0;
            
        } else {

            // Compares the elements.
            while (i-- != 0) {

                if (ArrayHandler.get_array_element(p0, i) != ArrayHandler.get_array_element(p1, i)) {

                    r = 0;

                    break;
                }
            }
        }
*/

        return r;
    }

    //
    // Array element.
    //

    /**
     * Sets the array element.
     *
     * @param p0 the array
     * @param p1 the element
     * @param p2 the index
     * @return the extended array
     */
    static java.lang.Object[] set_array_element(java.lang.Object[] p0, java.lang.Object p1, int p2) {

        java.lang.Object[] a = null;
        
        if (p0 != null) {

            // If the array length is exceeded, a new array with extended length
            // is created and delivered back.
            if (p2 >= p0.length) {

                a = ArrayHandler.extend_array(p0);
            
            } else {
            
                a = p0;
            }

            //?? Temporary: Remove old and add new java tree node.
/*??
            ArrayHandler.remove_tree_node(p0[i]);
            ArrayHandler.add_tree_node(p1);
*/

            // Set element.
            a[p2] = p1;

        } else {

            System.out.println("ERROR: Could not set array element. The array is null.");
        }
        
        return a;
    }

    /**
     * Removes the array element.
     *
     * @param p0 the array
     * @param p1 the index
     */
    static void remove_array_element(java.lang.Object[] p0, int p1) {

        if (p0 != null) {

            if (p1 != -1) {
                
                //?? Temporary: Remove java tree node.
//??                ArrayHandler.remove_tree_node(p0[p1]);

                // Move all remaining elements one place towards the
                // beginning of the elements.
                int size = p0.length;
    
                while ((p1 + 1) < size) {
    
                    p0[p1] = p0[p1 + 1];
    
                    p1++;
                }
    
                // Set former last element to null.
                p0[p1] = null;
            }

        } else {

            System.out.println("ERROR: Could not remove array element. The array is null.");
        }
    }

    /**
     * Returns the element.
     *
     * @param p0 the array
     * @param p1 the index
     * @return the element
     */
    static java.lang.Object get_array_element(java.lang.Object[] p0, int p1) {

        java.lang.Object e = null;
        
        if (p0 != null) {

            if (p1 != -1) {
                
                e = p0[p1];
            }

        } else {

            System.out.println("ERROR: Could not get array element. The array is null.");
        }
        
        return e;
    }
}

