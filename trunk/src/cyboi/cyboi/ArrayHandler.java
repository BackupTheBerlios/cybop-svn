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
 * An array is an area in the computer memory that can contain a number of
 * abstract elements.
 *
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * @version $Revision: 1.3 $ $Date: 2003-07-18 11:24:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ArrayHandler {

    //
    // Creation and destruction.
    //

    /**
     * Creates an empty array.
     *
     * @return the array
     */
    static Object[] create_array() {

        return new Object[0];
    }

    /**
     * Creates an extended array with double length of the old array.
     *
     * All elements are copied from the old to the new array.
     *
     * @param old the old array
     * @return the extended array
     */
    static Object[] create_array(Object[] old) {

        Object[] a = null;

        if (old != null) {

            int old_length = old.length;
            int new_length = old_length * 2 + 1;
            a = new Object[new_length];
            int i = 0;

            while (i < old_length) {

                a[i] = old[i];

                i++;
            }

            ArrayHandler.destroy_array(old);

        } else {

            System.out.println("ERROR: Could not create empty array. The old array is null.");
        }

        return a;
    }

    /**
     * Destroys the array.
     *
     * @param a the array
     */
    static void destroy_array(Object[] a) {
    }

    /**
     * Returns the size of the array.
     *
     * @param a the array
     * @return the size of the array
     */
    static int get_array_size(Object[] a) {

        int s = -1;

        if (a != null) {

            s = a.length;

        } else {

            System.out.println("ERROR: Could not get size of array. The array is null.");
        }

        return s;
    }

    /**
     * Compares both arrays.
     *
     * @param a the array
     * @param sa the second array
     * @return true - if the size and contents of both arrays are equal;
     * false - otherwise
     */
    static boolean compare(Object[] a, Object[] sa) {

        boolean b = true;
        int i = ArrayHandler.get_array_size(a);

        // Compares the array sizes.
        if (i != ArrayHandler.get_array_size(sa)) {

            b = false;
            
        } else {

            // Compares the array elements.
            while (i-- != 0) {

                if (ArrayHandler.get_array_element(a, i) != ArrayHandler.get_array_element(sa, i)) {

                    b = false;

                    break;
                }
            }
        }

        return b;
    }

    //
    // Array element management.
    //

    /**
     * Sets the array element.
     *
     * @param old the old array
     * @param i the index
     * @param e the array element
     */
    static void set_array_element(Object[] old, int i, Object e) {

        if (old != null) {

            Object[] a = null;

            // If the array length is exceeded, a new adjusted array with
            // extended length is created and delivered back.
            if (i >= old.length) {

                a = ArrayHandler.create_array(old);
                ArrayHandler.destroy_array(old);
/*??
                //?? WHAT TO DO HERE??
                ArrayHandler.set_elements(a);
*/

            } else {

                a = old;
            }

            //?? Temporary: Remove old and add new java tree node.
/*??
            ArrayHandler.remove_tree_node(a[i]);
            ArrayHandler.add_tree_node(e);
*/

            // Set element.
            a[i] = e;

        } else {

            System.out.println("ERROR: Could not set array element. The old array is null.");
        }
    }

    /**
     * Removes the array element.
     *
     * @param a the array
     * @param i the index
     */
    static void remove_array_element(Object[] a, int i) {

        if (a != null) {

            //?? Temporary: Remove java tree node.
//??            ArrayHandler.remove_tree_node(a[i]);

            // Move all remaining elements one place towards the
            // beginning of the elements.
            int index = i;

            while ((index + 1) < a.length) {

                a[index] = a[index + 1];

                index++;
            }

            // Set former last element to null.
            a[index] = null;

        } else {

            System.out.println("ERROR: Could not remove array element. The array is null.");
        }
    }

    /**
     * Returns the array element.
     *
     * @param a the array
     * @return the array element
     */
    static Object get_array_element(Object[] a, int i) {

        Object e = null;

        if (a != null) {

//??            if (i > -1) {

                e = a[i];
//??            }

        } else {

            System.out.println("ERROR: Could not get array element. The array is null.");
        }

        return e;
    }
}

