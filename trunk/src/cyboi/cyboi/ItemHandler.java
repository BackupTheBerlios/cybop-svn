/*
 * $RCSfile: ItemHandler.java,v $
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
 * This is an item handler.<br><br>
 *
 * An item has well-defined methods useable by outside entities. An outside
 * entity which contains items is called their container. Containers have a contract
 * with the items they contain, in that methods are called in a specific order,
 * called a lifecycle.<br><br>
 *
 * By calling the lifecycle methods, a container ensures the proper startup and
 * shutdown of each item, to work correctly. One or more methods can be called
 * by the container, but the order must be the same.<br>
 *
 * An item has the following lifecycle:
 *  <ul>
 *      <li>constructor(): called without any parameters on keyword <code>new</code></li>
 *      <li>abstract()</li>
 *      <li>name()</li>
 *      <li>inherit()</li>
 *      <li>categorize()</li>
 *      <li>position()</li>
 *      <li>constrain()</li>
 *      <li>behave()</li>
 *      <li>globalize()</li>
 *      <li>initialize()</li>
 *      <li>finalize(): destroys items (attributes) that are specific to this item; deallocates memory</li>
 *      <li>deglobalize()</li>
 *      <li>unbehave()</li>
 *      <li>unconstrain()</li>
 *      <li>unposition()</li>
 *      <li>decategorize()</li>
 *      <li>uninherit()</li>
 *      <li>unname()</li>
 *      <li>deabstract()</li>
 *      <li>destructor(): called without any parameters; not available for Java where a garbage collector destroys objects incidentally!</li>
 *  </ul>
 *
 * Only globalize and initialize relate to the dynamic instance creation.
 * All other methods are for specifying the static category.
 *
 * @version $Revision: 1.3 $ $Date: 2003-07-17 09:03:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class ItemHandler {

    //
    // Creation and destruction.
    //

    /**
     * Creates an item.
     *
     * @return the item
     */
    static Item createItem() {

        Item i = new Item();

        if (i != null) {

            i.abstractions = MapHandler.createMap();
            i.categories = MapHandler.createMap();
            i.positions = MapHandler.createMap();
            i.items = MapHandler.createMap();

        } else {

            System.out.println("ERROR: Could not create item. The item is null.");
        }

        return i;
    }

    /**
     * Destroys the item.
     *
     * @param i the item
     */
    static void destroyItem(Item i) {

        if (i != null) {

            Map items = i.items;
            i.items = null;
            MapHandler.destroyMap(items);

            Map positions = i.positions;
            i.positions = null;
            MapHandler.destroyMap(positions);

            Map categories = i.categories;
            i.categories = null;
            MapHandler.destroyMap(categories);

            Map abstractions = i.abstractions;
            i.abstractions = null;
            MapHandler.destroyMap(abstractions);

        } else {

            System.out.println("ERROR: Could not destroy item. The item is null.");
        }
    }

    //
    // Item element management.
    //

    /**
     * Sets the item.
     *
     * @param n the name
     * @param c the item
     */
/*??
    static void setItem(Object n, Item c) {

        Map m = getItemren();

        if (m != null) {

            m.set(n, c);

        } else {

            System.out.println("Could not set item. The itemren is null.");
        }
    }

    /**
     * Adds the item.
     *
     * @param n the base name
     * @param c the item
     * @return the item name
     */
/*??
    static Object addItem(Object n, Item c) {

        Object cn = null;
        Map m = getItemren();

        if (m != null) {

            cn = m.add(n, c);

        } else {

            System.out.println("Could not add item. The itemren is null.");
        }
        
        return cn;
    }

    /**
     * Removes the item.
     *
     * @param i the index
     */
/*??
    static void removeItem(int i) {

        Map m = getItemren();

        if (m != null) {

            m.remove(i);

        } else {

            System.out.println("Could not remove item. The itemren is null.");
        }
    }

    /**
     * Removes the item.
     *
     * @param n the name
     */
/*??
    static void removeItem(Object n) {

        Map m = getItemren();

        if (m != null) {

            m.remove(n);

        } else {

            System.out.println("Could not remove item. The itemren is null.");
        }
    }

    /**
     * Returns the item with the index.
     *
     * @param i the index
     * @return the item
     */
/*??
    static Item getItem(int i) {

        Item c = null;
        Map m = getItemren();

        if (m != null) {

            c = (Item) m.get(i);

        } else {

            System.out.println("Could not get item. The itemren is null.");
        }

        return c;
    }

    /**
     * Returns the item.
     *
     * @param n the name
     * @return the item
     */
/*??
    static Item getItem(Object n) {

        Item c = null;
        Map m = getItemren();

        if (m != null) {

            c = (Item) m.get(n);

        } else {

            System.out.println("Could not get item. The itemren is null.");
        }

        return c;
    }

    /**
     * Returns the item.
     *
     * @param n the name
     * @param d the default item
     * @return the item
     */
/*??
    static Item getItem(Object n, Item d) {

        Item c = getItem(n);

        if (c == null) {

            c = d;
        }

        return c;
    }

    /**
     * Returns the number of itemren whose name starts with the given name as word base.
     *
     * @param n the name
     */
/*??
    static int getCount(Object n) {

        int c = -1;
        Map m = getItemren();

        if (m != null) {

            c = m.getCount(n);

        } else {

            System.out.println("Could not get itemren count. The itemren is null.");
        }
        
        return c;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
/*??
    static void initialize() {
    }

    /**
     * Finalizes this item.
     *
     * This method's name is <code>finalizz</code> and not <code>finalize</code>
     * because the java computer language already uses <code>finalize</code> in
     * its <code>java.lang.Object</code> class.
     *
     * This method will be renamed to <code>finalize</code> as soon as the new
     * and simplified CYBOL computer language is used.
     */
/*??
    static void finalizz() {
    }

    //
    // Functionality.
    //

    /**
     * Returns the item at the given position.
     *
     * @param p the position relative to this container item
     * @return the item
     */
/*??
    static Item getChild(Space p) {

        Item child = null;
        Item[] c = getChildren();

        if (c != null) {

            int no = getChildrenNumber();
            Item item = null;
            Space rp = null;
            Integer n = null;
            int i = 0;

            while (i < no) {

                item = c[i];

                // Transform position into a position relative to (within) the child item.
                rp = new Space(); //?? p.subtract(originPositionDesChildItems);

                if (item != null) {

                    if (item.contains(rp)) {

                        // Set resulting child item to the current item by default.
                        // If the current item does not have children or none of the
                        // child items contains the position, then the child item is
                        // returned itself.
                        // For example, a mouse may be clicked on a panel, in the gap between
                        // two buttons. Then, none of the buttons contains the given position
                        // but the panel as parent container of the buttons does.
                        child = item;
                        n = item.getChildrenNumber();
    
                        if (n != null) {
                            
                            if (n.isGreaterThan(0)) {
    
                                // The child item has children, so call this method
                                // recursively on child item, to get the child item's
                                // child item which is located at the given position.
                                child = item.getChild(rp);
                            }
                        }
                    }
    
                } else {
        
                    System.out.println("Could not get child item. An item is null.");
                }
                
                i++;
            }

        } else {

            System.out.println("Could not get child item. The children array is null.");
        }

        return child;
    }

    /**
     * Checks whether or not this item contains the given position.
     *
     * @param p the position relative to this item
     * @return true if this item contains the given position;
     * false otherwise
     */
/*??
    static boolean contains(Structure p) {

        boolean b = false;
        Structure s = null; //?? getChild(Item.SPACE);

        if (s != null) {

            b = s.contains(p);

        } else {

            System.out.println("Could not check position. The space is null.");
        }

        return b;
    }
*/
}

