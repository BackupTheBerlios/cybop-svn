/*
 * $RCSfile: MapHandler.java,v $
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
 * This is a map handler.
 *
 * Map elements are accessed over their index or name.
 *
 * @version $Revision: 1.12 $ $Date: 2003-07-29 22:38:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class MapHandler {

    //
    // Map.
    //

    /**
     * Initializes the map.
     *
     * @param p0 the map
     */
    static void initialize_map(java.lang.Object p0) {

        Map m = (Map) p0;

        if (m != null) {

            m.names = new java.lang.Object[0];
            m.references = new java.lang.Object[0];

        } else {

            java.lang.System.out.println("ERROR: Could not initialize map. The map is null.");
        }
    }

    /**
     * Finalizes the map.
     *
     * @param p0 the map
     */
    static void finalize_map(java.lang.Object p0) {

        Map m = (Map) p0;
        
        if (m != null) {

            m.references = null;
            m.names = null;

        } else {

            java.lang.System.out.println("ERROR: Could not finalize map. The map is null.");
        }
    }

    //
    // Map element.
    //

    /**
     * Adds the element.
     *
     * @param c the map
     * @param n the name
     * @param e the element
     */
    static void add_map_element(java.lang.Object c, java.lang.Object n, java.lang.Object e) {

        java.lang.Object en = MapHandler.get_new_map_element_name(c, n);

        MapHandler.set_map_element(c, en, e);
    }

    /**
     * Sets the element.
     *
     * @param c the map
     * @param n the name
     * @param e the element
     */
    static void set_map_element(java.lang.Object c, java.lang.Object n, java.lang.Object e) {

        Map mc = (Map) c;
        
        if (mc != null) {
            
            int i = MapHandler.get_next_map_element_index(mc, n);

            mc.names = ArrayHandler.set_array_element(mc.names, i, n);
            mc.references = ArrayHandler.set_array_element(mc.references, i, e);

        } else {

            java.lang.System.out.println("ERROR: Could not set element. The map is null.");
        }
    }

    /**
     * Removes the element with the index.
     *
     * @param c the map
     * @param i the index
     */
    static void remove_map_element(java.lang.Object c, int i) {

        Map mc = (Map) c;
        
        if (mc != null) {

            if (i > -1) {

                ArrayHandler.remove_array_element(mc.names, i);
                ArrayHandler.remove_array_element(mc.references, i);
            }

        } else {

            java.lang.System.out.println("ERROR: Could not remove element. The map is null.");
        }
    }

    /**
     * Removes the element with the name.
     *
     * @param c the map
     * @param n the name
     */
    static void remove_map_element(java.lang.Object c, java.lang.Object n) {
    
        int i = MapHandler.get_map_element_index(c, n);

        MapHandler.remove_map_element(c, i);
    }

    /**
     * Returns the element with the index.
     *
     * @param c the map
     * @param i the index
     * @return the element
     */
    static java.lang.Object get_map_element(java.lang.Object c, int i) {

        java.lang.Object e = null;
        Map mc = (Map) c;

        if (mc != null) {
    
            e = ArrayHandler.get_array_element(mc.references, i);

        } else {

            java.lang.System.out.println("ERROR: Could not get element. The map is null.");
        }

        return e;
    }

    /**
     * Returns the element with the name.
     *
     * @param c the map
     * @param n the name
     * @return the element
     */
    static java.lang.Object get_map_element(java.lang.Object c, java.lang.Object n) {

        int i = MapHandler.get_map_element_index(c, n);

        return MapHandler.get_map_element(c, i);
    }

    /**
     * Returns the element index of the name.
     *
     * @param c the map
     * @param n the name
     * @return the index
     */
    static int get_map_element_index(java.lang.Object c, java.lang.Object n) {

        int index = -1;
        Map mc = (Map) c;

        if (mc != null) {
            
            java.lang.Object[] a = mc.names;
            int i = index + 1;
            int size = ArrayHandler.get_array_size(a);
            java.lang.Object name = null;

            while (i < size) {

                name = ArrayHandler.get_array_element(a, i);

                // If a null name is reached, then the name was not found.
                // In this case, reset index to -1.
                if (name == null) {

                    index = -1;
                    break;
                
                } else {

                    // If a name equal to the searched one is found,
                    // then its index is the one to be returned.
                    if (name.equals((java.lang.String) n)) {

                        index = i;
                        break;
                    }
                }

                i++;
            }

        } else {

            java.lang.System.out.println("ERROR: Could not get element index. The map is null.");
        }

        return index;
    }

    /**
     * Returns the next index that can be used to set an element.
     *
     * If an element with the given name is found, then its index will be returned
     * so that the element can be replaced.
     * If a null element is reached, then the corresponding index marks the next
     * available place and will be returned.
     * If neither an element matches nor a null element is reached, then the
     * map is full and its size will be returned as next available index.
     *
     * @param c the map
     * @param n the name
     * @return the next index
     */
    static int get_next_map_element_index(java.lang.Object c, java.lang.Object n) {

        int index = -1;
        Map mc = (Map) c;

        if (mc != null) {

            java.lang.Object[] a = mc.names;
            int i = index + 1;
            int size = ArrayHandler.get_array_size(a);
            java.lang.Object name = null;

            while (i < size) {

                name = ArrayHandler.get_array_element(a, i);

                // If a null name is reached, then the name was not found.
                // In this case, the current value of i is the next free index.
                if (name == null) {

                    index = i;
                    break;

                } else {

                    // If a name equal to the searched one is found,
                    // then its index is the one to be returned since
                    // this element will have to be replaced.
                    if (name.equals((java.lang.String) n)) {

                        index = i;
                        break;
                    }
                }

                i++;
            }

            // Neither element matched, nor was a null element found.
            // The map is full and such its size will be the next index to be used.
            if (index == -1) {

                index = size;
            }

        } else {

            java.lang.System.out.println("ERROR: Could not get next element index. The map is null.");
        }

        return index;
    }

    /**
     * Returns an extended version of the given name.
     *
     * The given name is used as a word base for the new name.
     * Additionally, the new name will receive a number suffix.
     * It is determined by the current number of names containing the given word base
     * (which is the same as increasing the currently highest index by one).
     *
     * @param c the map
     * @param n the word base name
     * @return the new name
     */
    static java.lang.Object get_new_map_element_name(java.lang.Object c, java.lang.Object n) {

        java.lang.Object nn = null;
        java.lang.String index = java.lang.String.valueOf(MapHandler.get_map_element_count(c, n));

        if (n != null) {

            if (index != null) {

                nn = ((java.lang.String) n) + "_" + index;

            } else {

                java.lang.System.out.println("ERROR: Could not get new element name. The index string is null.");
            }

        } else {

            java.lang.System.out.println("ERROR: Could not get new element name. The word base of the name is null.");
        }

        return nn;
    }

    /**
     * Returns the number of names that start with the given name as word base.
     *
     * @param c the map
     * @param n the name
     * @return the number of names that start with the given name as word base
     */
    static int get_map_element_count(java.lang.Object c, java.lang.Object n) {

        int count = 0;
        Map mc = (Map) c;

        if (mc != null) {

            java.lang.Object[] a = mc.names;
            int i = 0;
            int size = ArrayHandler.get_array_size(a);
            java.lang.Object name = null;

            while (i < size) {

                name = ArrayHandler.get_array_element(a, i);

                if (name != null) {

                    if (((java.lang.String) name).startsWith((java.lang.String) n)) {

/*??
                        int begin = 0;
                        java.lang.String sub = null;
                        int number = 0;
            
                        begin = ((java.lang.String) name).indexOf("_");
                        sub = ((java.lang.String) name).substring(begin + 1);
                        number = Integer.parseInt(sub);

                        if (number > count) {

                            count = number;
                        }
*/

                        count++;
                    }

                } else {

                    // Reached last valid name. Only null entries left.
                    break;
                }

                i++;
            }

        } else {

            java.lang.System.out.println("ERROR: Could not get element count. The map is null.");
        }

        return count;
    }
}

