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
 * @version $Revision: 1.6 $ $Date: 2003-07-24 08:16:43 $ $Author: christian $
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
     * @param c the array container
     * @return the extended array container
     */
    static java.lang.Object[] create_array_container(java.lang.Object[] c) {

        java.lang.Object[] ac = null;

        if (c != null) {

            int old_length = c.length;
            int new_length = old_length * 2 + 1;
            ac = new java.lang.Object[new_length];
            int i = 0;

            while (i < old_length) {

                ac[i] = c[i];

                i++;
            }

            ArrayHandler.destroy_array_container(c);

        } else {

            System.out.println("ERROR: Could not create array container. The old array container is null.");
        }

        return ac;
    }

    /**
     * Destroys the array container.
     *
     * @param c the array container
     */
    static void destroy_array_container(java.lang.Object[] c) {
    }

    /**
     * Returns the size of the array container.
     *
     * @param c the array container
     * @return the size of the array container
     */
    static int get_array_container_size(java.lang.Object[] c) {

        int s = -1;

        if (c != null) {

            s = c.length;

        } else {

            System.out.println("ERROR: Could not get size of array container. The array container is null.");
        }

        return s;
    }

    /**
     * Compares both array containers.
     *
     * @param c1 the first array container
     * @param c2 the second array container
     * @return true - if the size and contents of both array containers are equal;
     * false - otherwise
     */
    static boolean compare(java.lang.Object[] c1, java.lang.Object[] c2) {

        boolean b = true;
        int i = ArrayHandler.get_array_container_size(c1);

        // Compares the array container sizes.
        if (i != ArrayHandler.get_array_container_size(c2)) {

            b = false;
            
        } else {

            // Compares the array elements.
            while (i-- != 0) {

                if (ArrayHandler.get_array_element(c1, i) != ArrayHandler.get_array_element(c2, i)) {

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
     * @param c the array container
     * @param i the index
     * @param e the array element
     * @return the new array container
     */
    static java.lang.Object[] set_array_element(java.lang.Object[] c, int i, java.lang.Object e) {

        java.lang.Object[] ac = null;

        if (c != null) {

            // If the array container length is exceeded, a new adjusted array
            // container with extended length is created and delivered back.
            if (i >= c.length) {

                ac = ArrayHandler.create_array_container(c);
                ArrayHandler.destroy_array_container(c);

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

            System.out.println("ERROR: Could not set array element. The array container is null.");
        }
        
        return ac;
    }

    /**
     * Removes the array element.
     *
     * @param c the array container
     * @param i the index
     */
    static void remove_array_element(java.lang.Object[] c, int i) {

        if (c != null) {

            //?? Temporary: Remove java tree node.
//??            ArrayHandler.remove_tree_node(c[i]);

            // Move all remaining elements one place towards the
            // beginning of the elements.
            int index = i;
            int size = c.length;

            while ((index + 1) < size) {

                c[index] = c[index + 1];

                index++;
            }

            // Set former last element to null.
            c[index] = null;

        } else {

            System.out.println("ERROR: Could not remove array element. The array container is null.");
        }
    }

    /**
     * Returns the array element.
     *
     * @param c the array container
     * @return the array element
     */
    static java.lang.Object get_array_element(java.lang.Object[] c, int i) {

        java.lang.Object e = null;

        if (c != null) {

//??            if (i > -1) {

                e = c[i];
//??            }

        } else {

            System.out.println("ERROR: Could not get array element. The array container is null.");
        }

        return e;
    }
}

