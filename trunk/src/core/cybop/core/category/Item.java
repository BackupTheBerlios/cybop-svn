/*
 * $RCSfile: Item.java,v $
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

package cybop.core.category;

import cybop.core.model.Integer;
import cybop.core.model.String;

/**
 * This class represents an item.<br><br>
 *
 * An item can be created by instantiating (cloning) an existing category.
 * Basically, every item can become a category if copies of this item are created.
 * The meta-level classes that form a category follow this order:<br><br>
 *
 *  <ul>
 *      <li>Array</li>
 *      <li>Map</li>
 *      <li>Category</li>
 *      <li>Inheritance</li>
 *      <li>Hierarchy</li>
 *      <li>Structure</li>
 *      <li>Definition</li>
 *      <li>Behaviour</li>
 *  </ul>
 *
 * Item is the super class of all other classes in the framework.<br><br>
 *
 * An item has well-defined public methods useable by outside entities. An outside
 * entity which contains items is called their container. Containers have a contract
 * with the items they contain, in that public methods are called in a specific order,
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
 * @version $Revision: 1.15 $ $Date: 2003-06-20 15:06:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Item extends Behaviour {

    //
    // Attributes.
    //

    /** The children. */
    private Map children;

    //
    // Children.
    //

    /**
     * Creates the children.
     *
     * @return the children
     */
    public Map createChildren() throws Exception {

        Map m = new Map();
        
        if (m != null) {

            m.abstracc();

        } else {

            throw new Exception("Could not create children. The children is null.");
        }

        return m;
    }

    /**
     * Destroys the children.
     *
     * @param c the children
     */
    public void destroyChildren(Map c) throws Exception {
    }

    /**
     * Sets the children.
     *
     * @param c the children
     */
    public void setChildren(Map c) {

        this.children = c;
    }

    /**
     * Returns the children.
     *
     * @return the children
     */
    public Map getChildren() {

        return this.children;
    }

    /**
     * Returns the size.
     *
     * @return the size
     */
    public int getChildrenSize() throws Exception {

        int s = 0;
        Map c = getChildren();

        if (c != null) {

            s = c.getSize();

        } else {

            throw new Exception("Could not get size. The children is null.");
        }

        return s;
    }

    //
    // Child management.
    //

    /**
     * Creates a child.
     *
     * @param n the category name
     * @return the child
     * @exception Exception if the category is null
     * @exception Exception if the child is null
     */
    public Item createChild(Array n) throws Exception {

        Item i = null;

        // If a category name is set to null, then don't try to create the child.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create item from given class.
                i = (Item) cl.newInstance();

                if (i != null) {

                    java.lang.System.out.println("INFO: Abstract child to get an abstraction.");
                    i.abstracc();

                    java.lang.System.out.println("INFO: Name child to get a category.");
                    i.name(null);

                    java.lang.System.out.println("INFO: Inherit child to get an inheritance.");
                    i.inherit();

                    java.lang.System.out.println("INFO: Categorize child to get a hierarchy.");
                    i.categorize();

                    java.lang.System.out.println("INFO: Position child to get a structure.");
                    i.position();

                    java.lang.System.out.println("INFO: Constrain child to get a definition.");
                    i.constrain();

                    java.lang.System.out.println("INFO: Behave child to get a behaviour.");
                    i.behave();

                    java.lang.System.out.println("INFO: Initialize child to get an item.");
                    i.initialize();

                } else {

                    throw new Exception("Could not create child. The child is null.");
                }

            } else {

                throw new Exception("Could not create child. The category is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not create child. The category name is null.");
        }

        return i;
    }

    /**
     * Destroys the child.
     *
     * @param i the child
     * @exception Exception if the child is null
     */
    public void destroyChild(Item i) throws Exception {

        if (i != null) {

            java.lang.System.out.println("INFO: Finalize child.");
            i.finalizz();

            java.lang.System.out.println("INFO: Unbehave child.");
            i.unbehave();

            java.lang.System.out.println("INFO: Unconstrain child.");
            i.unconstrain();

            java.lang.System.out.println("INFO: Deposition child.");
            i.deposition();

            java.lang.System.out.println("INFO: Decategorize child.");
            i.decategorize();

            java.lang.System.out.println("INFO: Uninherit child.");
            i.uninherit();

            java.lang.System.out.println("INFO: Unname child.");
            i.unname();

            java.lang.System.out.println("INFO: Deabstract child.");
            i.deabstract();

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy child. The child is null.");
        }
    }

    /**
     * Sets the child.
     *
     * @param n the name
     * @param c the child
     * @exception Exception if the children is null
     */
    public void setChild(Array n, Item c) throws Exception {

        Map m = getChildren();

        if (m != null) {

            // The child must sometimes know its own name, just like people in real life.
            // Signals for example can only be deleted from the signal memory
            // if they carry their own name.
            if (c != null) {

                c.setName(n);
            }

            m.set(n, c);

        } else {

            throw new Exception("Could not set child. The children is null.");
        }
    }

    /**
     * Removes the child.
     *
     * @param i the index
     * @exception Exception if the children is null
     */
    public void removeChild(int i) throws Exception {

        Map m = getChildren();

        if (m != null) {

            m.remove(i);

/*??
            // The child must sometimes know its own name, just like people in real life.
            // Signals for example can only be deleted from the signal memory
            // if they carry their own name.
            //?? WHERE to best remove the name from child? In Array?
            if (c != null) {

                c.removeName(n);
            }
*/

        } else {

            throw new Exception("Could not remove child. The children is null.");
        }
    }

    /**
     * Removes the child.
     *
     * @param n the name
     * @exception Exception if the children is null
     */
    public void removeChild(Array n) throws Exception {

        Map m = getChildren();

        if (m != null) {

            m.remove(n);

        } else {

            throw new Exception("Could not remove child. The children is null.");
        }
    }

    /**
     * Returns the child with the index.
     *
     * @param i the index
     * @return the child
     * @exception Exception if the children is null
     */
    public Item getChild(int i) throws Exception {

        Item c = null;
        Map m = getChildren();

        if (m != null) {

            c = (Item) m.get(i);

        } else {

            throw new Exception("Could not get child. The children is null.");
        }

        return c;
    }

    /**
     * Returns the child.
     *
     * @param n the name
     * @return the child
     * @exception Exception if the children is null
     */
    public Item getChild(Array n) throws Exception {

        Item c = null;
        Map m = getChildren();

        if (m != null) {

            c = (Item) m.get(n);

        } else {

            throw new Exception("Could not get child. The children is null.");
        }

        return c;
    }

    /**
     * Returns the child.
     *
     * @param n the name
     * @param d the default child
     * @return the child
     * @exception Exception if the children is null
     */
    public Item getChild(Array n, Item d) throws Exception {

        Item c = getChild(n);

        if (c == null) {

            c = d;
        }

        return c;
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this abstraction.
     */
    public void abstracc() throws Exception {

        super.abstracc();

        setChildren(createChildren());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        Map children = getChildren();
        setChildren(null);
        destroyChildren(children);

        super.deabstract();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {
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
    public void finalizz() throws Exception {
    }

    //
    // Functionality.
    //

    /**
     * Returns the child item at the given position.
     *
     * @param p the position relative to this container item
     * @return the child item
     * @exception Exception if the children array is null
     * @exception Exception if the child item is null
     */
/*??
    public Item getChild(Space p) throws Exception {

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
        
                    throw new Exception("Could not get child item. An item is null.");
                }
                
                i++;
            }

        } else {

            throw new Exception("Could not get child item. The children array is null.");
        }

        return child;
    }

    /**
     * Checks whether or not this item contains the given position.
     *
     * @param p the position relative to this item
     * @return true if this item contains the given position;
     * false otherwise
     * @exception Exception if the space is null
     */
/*??
    public boolean contains(Structure p) throws Exception {

        boolean b = false;
        Structure s = null; //?? getChild(Item.SPACE);

        if (s != null) {

            b = s.contains(p);

        } else {

            throw new Exception("Could not check position. The space is null.");
        }

        return b;
    }
*/
}

