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
 * Map elements are accessed over their name or index.
 *
 * @version $Revision: 1.13 $ $Date: 2003-07-31 00:52:20 $ $Author: christian $
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

    /**
     * Returns the map size.
     *
     * @param p0 the map
     * @return the map size
     */
    static int get_map_size(java.lang.Object p0) {

        int s = -1;
        Map m = (Map) p0;

        if (m != null) {

            s = ArrayHandler.get_array_size(m.names);

        } else {

            System.out.println("ERROR: Could not get map size. The map is null.");
        }

        return s;
    }

    //
    // Map element.
    //

    /**
     * Adds the map element.
     *
     * @param p0 the map
     * @param p1 the element
     * @param p2 the name
     */
    static void add_map_element(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        MapHandler.determine_map_element_name(p0, p2);
        MapHandler.set_map_element(p0, p1, p2);
    }

    /**
     * Sets the map element.
     *
     * @param p0 the map
     * @param p1 the element
     * @param p2 the name
     */
    static void set_map_element(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        Map m = (Map) p0;
        
        if (m != null) {
            
            int i = MapHandler.determine_next_map_element_index(m, p2);

            ArrayHandler.set_array_element(m.names, p2, i);
            ArrayHandler.set_array_element(m.references, p1, i);

        } else {

            java.lang.System.out.println("ERROR: Could not set map element. The map is null.");
        }
    }

    /**
     * Removes the map element with the index.
     *
     * @param p0 the map
     * @param p1 the index
     */
    static void remove_map_element(java.lang.Object p0, int p1) {

        Map m = (Map) p0;
        
        if (m != null) {

            ArrayHandler.remove_array_element(m.names, p1);
            ArrayHandler.remove_array_element(m.references, p1);

        } else {

            java.lang.System.out.println("ERROR: Could not remove map element. The map is null.");
        }
    }

    /**
     * Removes the map element with the name.
     *
     * @param p0 the map
     * @param p1 the name
     */
    static void remove_map_element(java.lang.Object p0, java.lang.Object p1) {
    
        int i = MapHandler.get_map_element_index(p0, p1);

        MapHandler.remove_map_element(p0, i);
    }

    /**
     * Returns the map element with the index.
     *
     * @param p0 the map
     * @param p1 the element
     * @param p2 the index
     */
    static void get_map_element(java.lang.Object p0, java.lang.Object p1, int p2) {

        Map m = (Map) p0;

        if (m != null) {
    
            ArrayHandler.get_array_element(m.references, p1, p2);

        } else {

            java.lang.System.out.println("ERROR: Could not get map element. The map is null.");
        }
    }

    /**
     * Returns the map element with the name.
     *
     * @param p0 the map
     * @param p1 the element
     * @param p2 the name
     */
    static void get_map_element(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        int i = MapHandler.get_map_element_index(p0, p2);

        MapHandler.get_map_element(p0, p1, i);
    }

    /**
     * Returns the map element index.
     *
     * @param p0 the map
     * @param p1 the name
     * @return the index
     */
    static int get_map_element_index(java.lang.Object p0, java.lang.Object p1) {

        int index = -1;
        Map m = (Map) p0;

        if (m != null) {
            
            java.lang.Object[] a = m.names;
            int i = index + 1;
            int size = ArrayHandler.get_array_size(a);
            java.lang.Object name = null;

            while (i < size) {

                ArrayHandler.get_array_element(a, name, i);

                // If a null name is reached, then the name was not found.
                // In this case, reset index to -1.
                if (name == null) {

                    index = -1;
                    break;
                
                } else {

                    // If a name equal to the searched one is found,
                    // then its index is the one to be returned.
                    if (name.equals((java.lang.String) p1)) {

                        index = i;
                        break;
                    }
                }

                i++;
            }

        } else {

            java.lang.System.out.println("ERROR: Could not get map element index. The map is null.");
        }

        return index;
    }

    /**
     * Returns the next index that can be used to set a map element.
     *
     * If an element with the given name is found, then its index will be returned
     * so that the element can be replaced.
     * If a null element is reached, then the corresponding index marks the next
     * available place and will be returned.
     * If neither an element matches nor a null element is reached, then the
     * map is full and its size will be returned as next available index.
     *
     * @param p0 the map
     * @param p1 the name
     * @return the next index
     */
    static int determine_next_map_element_index(java.lang.Object p0, java.lang.Object p1) {

        int index = -1;
        Map m = (Map) p0;

        if (m != null) {

            java.lang.Object[] a = m.names;
            int i = index + 1;
            int size = ArrayHandler.get_array_size(a);
            java.lang.Object name = null;

            while (i < size) {

                ArrayHandler.get_array_element(a, name, i);

                // If a null name is reached, then the name was not found.
                // In this case, the current value of i is the next free index.
                if (name == null) {

                    index = i;
                    break;

                } else {

                    // If a name equal to the searched one is found,
                    // then its index is the one to be returned since
                    // this element will have to be replaced.
                    if (name.equals((java.lang.String) p1)) {

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

            java.lang.System.out.println("ERROR: Could not get next map element index. The map is null.");
        }

        return index;
    }

    /**
     * Determines the map element name.
     *
     * The given name is used as a word base for the new extended name.
     * Additionally, the new name will receive a number suffix.
     * It is determined by the current number of names containing the given word base
     * (which is the same as increasing the currently highest index by one).
     *
     * @param p0 the map
     * @param p1 the name
     */
    static void determine_map_element_name(java.lang.Object p0, java.lang.Object p1) {

        java.lang.String index = java.lang.String.valueOf(MapHandler.get_map_element_count(p0, p1));

        if (p1 != null) {

            if (index != null) {

                p1 = p1 + "_" + index;

            } else {

                java.lang.System.out.println("ERROR: Could not determine map element name. The index string is null.");
            }

        } else {

            java.lang.System.out.println("ERROR: Could not determine map element name. The name is null.");
        }
    }

    /**
     * Returns the number of map elements whose name starts with the given name.
     *
     * @param p0 the map
     * @param p1 the name
     * @return the number of map elements whose name starts with the given name
     */
    static int get_map_element_count(java.lang.Object p0, java.lang.Object p1) {

        int count = 0;
        Map m = (Map) p0;

        if (m != null) {

            java.lang.Object[] a = m.names;
            int i = 0;
            int size = ArrayHandler.get_array_size(a);
            java.lang.Object name = null;

            while (i < size) {

                ArrayHandler.get_array_element(a, name, i);

                if (name != null) {

                    if (((java.lang.String) name).startsWith((java.lang.String) p1)) {

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

