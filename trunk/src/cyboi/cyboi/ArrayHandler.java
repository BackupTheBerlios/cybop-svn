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
 * @version $Revision: 1.4 $ $Date: 2003-07-20 07:49:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ArrayHandler {

    //
    // Array container management.
    //

    /**
     * Creates an empty array container.
     *
     * @return the array container
     */
    static java.lang.Object[] create_array_container() {

        return new java.lang.Object[0];
    }

    /**
     * Creates an extended array container with double length of the old array container.
     *
     * All elements are copied from the old to the new array container.
     *
     * @param old the old array container
     * @return the extended array container
     */
    static java.lang.Object[] create_array_container(java.lang.Object[] old) {

        java.lang.Object[] a = null;

        if (old != null) {

            int old_length = old.length;
            int new_length = old_length * 2 + 1;
            a = new java.lang.Object[new_length];
            int i = 0;

            while (i < old_length) {

                a[i] = old[i];

                i++;
            }

            ArrayHandler.destroy_array_container(old);

        } else {

            System.out.println("ERROR: Could not create array container. The old array container is null.");
        }

        return a;
    }

    /**
     * Destroys the array container.
     *
     * @param a the array container
     */
    static void destroy_array_container(java.lang.Object[] a) {
    }

    /**
     * Returns the size of the array container.
     *
     * @param a the array container
     * @return the size of the array container
     */
    static int get_array_container_size(java.lang.Object[] a) {

        int s = -1;

        if (a != null) {

            s = a.length;

        } else {

            System.out.println("ERROR: Could not get size of array container. The array container is null.");
        }

        return s;
    }

    /**
     * Compares both array containers.
     *
     * @param a the first array container
     * @param sa the second array container
     * @return true - if the size and contents of both array containers are equal;
     * false - otherwise
     */
    static boolean compare(java.lang.Object[] a, java.lang.Object[] sa) {

        boolean b = true;
        int i = ArrayHandler.get_array_container_size(a);

        // Compares the array container sizes.
        if (i != ArrayHandler.get_array_container_size(sa)) {

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
     * @param c the old array container
     * @param i the index
     * @param e the array element
     */
    static void set_array_element(java.lang.Object[] c, int i, Element e) {

        if (c != null) {

            java.lang.Object[] ac = null;

            // If the array container length is exceeded, a new adjusted array
            // container with extended length is created and delivered back.
            if (i >= c.length) {

                ac = ArrayHandler.create_array_container(c);
                ArrayHandler.destroy_array_container(c);
/*??
                //?? WHAT TO DO HERE??
                ArrayHandler.set_array_container(ac);
*/

            } else {

                ac = c;
            }

            //?? Temporary: Remove old and add new java tree node.
/*??
            ArrayHandler.remove_tree_node(ac[i]);
            ArrayHandler.add_tree_node(e);
*/

            // Set element.
            ac[i] = e;

        } else {

            System.out.println("ERROR: Could not set array element. The old array container is null.");
        }
    }

    /**
     * Removes the array element.
     *
     * @param a the array container
     * @param i the index
     */
    static void remove_array_element(java.lang.Object[] a, int i) {

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
    static Element get_array_element(java.lang.Object[] a, int i) {

        Element e = null;

        if (a != null) {

//??            if (i > -1) {

                e = (Element) a[i];
//??            }

        } else {

            System.out.println("ERROR: Could not get array element. The array is null.");
        }

        return e;
    }
}

