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
 * @version $Revision: 1.5 $ $Date: 2003-07-20 07:49:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class MapHandler {

    //
    // Creation and destruction.
    //

    /**
     * Creates a map.
     *
     * @return the map
     */
    static java.lang.Object create_map() {

        Map m = new Map();

        if (m != null) {

            m.names = ArrayHandler.create_array();
            m.references = ArrayHandler.create_array();

        } else {

            System.out.println("ERROR: Could not create map. The map is null.");
        }
        
        return m;
    }

    /**
     * Destroys the map.
     *
     * @param o the map
     */
    static void destroy_map(java.lang.Object o) {

        Map m = (Map) o;
        
        if (m != null) {

            java.lang.Object[] references = m.references;
            m.references = null;
            ArrayHandler.destroy_array(references);

            java.lang.Object[] names = m.names;
            m.names = null;
            ArrayHandler.destroy_array(names);

        } else {

            System.out.println("ERROR: Could not destroy map. The map is null.");
        }
    }

    /**
     * Returns the map size.
     *
     * @param o the map
     * @return the map size
     */
    static int get_map_size(java.lang.Object o) {

        int s = -1;
        Map m = (Map) o;

        if (m != null) {

            ArrayHandler.get_array_size(m.names);

        } else {

            System.out.println("ERROR: Could not get map size. The map is null.");
        }

        return s;
    }

    //
    // Element management.
    //

    /**
     * Sets the map element.
     *
     * @param c the map container
     * @param e the map element
     */
    static void set_map_element(java.lang.Object c, Element e) {

        Map mc = (Map) c;
        
        if (mc != null) {
            
            MapElement me = (MapElement) e;
            
            if (me != null) {
    
                int i = MapHandler.get_next_map_element_index(mc, me.name);
    
                ArrayHandler.set_array_element(mc.names, i, me.name);
                ArrayHandler.set_array_element(mc.references, i, me.reference);

            } else {
    
                System.out.println("ERROR: Could not set map element. The map element is null.");
            }

        } else {

            System.out.println("ERROR: Could not set map element. The map is null.");
        }
    }

    /**
     * Adds the map element.
     *
     * @param o1 the map
     * @param o2 the map element
     * @return the map element name
     */
    static java.lang.Object add_map_element(java.lang.Object o1, java.lang.Object o2) {

        java.lang.Object o2.name = MapHandler.get_new_map_element_name(o1, o2);

        MapHandler.set_map_element(o1, o2);

        return name;
    }

    /**
     * Removes the map element with the index.
     *
     * @param o1 the map
     * @param i the index
     * @exception Exception if the references is null
     * @exception Exception if the names is null
     */
    static void remove_map_element(java.lang.Object o1, int i) {

        Map m = (Map) o1;
        
        if (m != null) {

            if (i > -1) {

                ArrayHandler.remove_array_element(m.names, i);
                ArrayHandler.remove_array_element(m.references, i);
            }

        } else {

            System.out.println("ERROR: Could not remove map element. The map is null.");
        }
    }

    /**
     * Removes the map element with the name.
     *
     * @param o1 the map
     * @param o2 the map element
     */
    static void remove_map_element(java.lang.Object o1, java.lang.Object o2) {
    
        int i = MapHandler.get_map_element_index(o1, o2);

        MapHandler.remove_map_element(o1, i);
    }

    /**
     * Returns the map element with the index.
     *
     * @param o1 the map
     * @param i the index
     * @return the map element
     */
    static java.lang.Object get_map_element(java.lang.Object o1, int i) {

        java.lang.Object e = null;
        Map m = (Map) o1;

        if (m != null) {
    
            e = ArrayHandler.get_array_element(m.references, i);

        } else {

            System.out.println("ERROR: Could not get map element. The map is null.");
        }

        return e;
    }

    /**
     * Returns the map element with the name.
     *
     * @param o1 the map
     * @param o2 the map element
     * @return the map element
     */
    static java.lang.Object get_map_element(java.lang.Object o1, java.lang.Object o2) {

        int i = MapHandler.get_map_element_index(o1, o2);

        return MapHandler.get_map_element(o1, i);
    }

    /**
     * Returns the map element index of the name.
     *
     * @param o1 the map
     * @param o2 the map element
     * @return the index
     */
    static int get_map_element_index(Map o1, java.lang.Object o2) {

        int index = -1;
        Map m = (Map) o1;

        if (m != null) {
            
            if (o2 != null) {
    
                int i = index + 1;
                int size = MapHandler.get_map_size(o1);
                java.lang.Object name = null;
    
                while (i < size) {
    
                    name = ArrayHandler.get_array_element(m.names, i);
    
                    // If a null name is reached, then the name was not found.
                    // In this case, reset index to -1.
                    if (name == null) {
    
                        break;
                    
                    } else {
    
                        // If a name equal to the searched one is found,
                        // then its index is the one to be returned.
                        if (name.equals((java.lang.String) o2.name)) {
    
                            index = i;
                            break;
                        }
                    }
    
                    i++;
                }

            } else {
    
                System.out.println("ERROR: Could not get map element index. The map element is null.");
            }

        } else {

            System.out.println("ERROR: Could not get map element index. The map is null.");
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
     * @param o1 the map
     * @param o2 the map element
     * @return the next index
     */
    static int get_next_map_element_index(java.lang.Object o1, java.lang.Object o2) {

        int index = -1;
        Map m = (Map) o1;

        if (m != null) {

            if (o2 != null) {
                    
                int i = index + 1;
                int size = MapHandler.get_map_size(m);
                java.lang.Object name = null;
    
                while (i < size) {
    
                    name = ArrayHandler.get_array_element(m.names, i);
    
                    // If a null name is reached, then the name was not found.
                    // In this case, the current value of i is the next free index.
                    if (name == null) {
    
                        index = i;
                        break;
    
                    } else {
    
                        // If a name equal to the searched one is found,
                        // then its index is the one to be returned since
                        // this element will have to be replaced.
                        if (name.equals((java.lang.String) o2.name)) {
    
                            index = i;
                            break;
                        }
                    }
    
                    i++;
                }
    
                // Neither element matched, nor was a null element found.
                // The map is full and such its size will be the next index to be used.
                if (index == -1) {
    
                    index = MapHandler.get_map_size(m);
                }

            } else {
    
                System.out.println("ERROR: Could not get next map element index. The map element is null.");
            }

        } else {

            System.out.println("ERROR: Could not get next map element index. The map is null.");
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
     * @param o1 the map
     * @param o2 the map element
     * @return the new name
     */
    static java.lang.Object get_new_map_element_name(java.lang.Object o1, java.lang.Object o2) {

        java.lang.Object nn = null;
        java.lang.String index = java.lang.String.valueOf(MapHandler.get_map_element_count(o1, o2));

        if (n != null) {

            if (index != null) {

                nn = ((java.lang.String) n) + "_" + index;

            } else {

                System.out.println("ERROR: Could not get new map element name. The index string is null.");
            }

        } else {

            System.out.println("ERROR: Could not get new map element name. The word base of the name is null.");
        }

        return nn;
    }

    /**
     * Returns the number of names that start with the given name as word base.
     *
     * @param o1 the map
     * @param o2 the map element
     * @return the number of names that start with the given name as word base
     */
    static int get_map_element_count(java.lang.Object o1, java.lang.Object o2) {

        int count = 0;
        Map m = (Map) o1;

        if (m != null) {

            int i = 0;
            int size = MapHandler.get_map_size(m);
            java.lang.Object name = null;

            while (i < size) {

                name = ArrayHandler.get_array_element(m.names, i);

                if (name != null) {

                    if (((java.lang.String) name).startsWith((java.lang.String) o2.name)) {

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

            System.out.println("ERROR: Could not get map element count. The map is null.");
        }

        return count;
    }
}

