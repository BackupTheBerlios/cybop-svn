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

package cybop.core.basic;

import cybop.core.basic.Integer;
import cybop.core.basic.String;
//?? temporary!
import cybop.core.model.principle.*;

/**
 * This class represents a general abstract item.<br><br>
 *
 * It is the super-super class of all level classes in the framework's ontology:<br>
 *  <ul>
 *      <li>Family</li>
 *      <li>System</li>
 *      <li>Block</li>
 *      <li>Region</li>
 *      <li>Component</li>
 *      <li>Part</li>
 *      <li>Chain</li>
 *  </ul>
 *
 * An item consists of a number of child items. It can also be a child itself,
 * belonging to a parent item.<br><br>
 *
 * Since humans don't know where this hierarchy stops in the real world
 * - to microcosm as well as towards macrocosm -, a black box has to be assumed
 * at some point towards microcosm. In the case of programming, this is mostly
 * the basic items of programming language, namely Boolean and Numbers.
 * They are coded in binaries within the machine and that is the final abstraction.
 * Towards macrocosm, it depends on the modeller how far he/she wants to go.
 * At the time of writing this, the CYBOP framework's highest class in its
 * ontology is Network, consisting of Families which consist of Systems.<br><br>
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
 *      <li>initialize(): creates items (attributes) that are specific to this item; allocates necessary memory</li>
 *      <li>finalize(): destroys items (attributes) that are specific to this item; deallocates memory</li>
 *      <li>destructor(): called without any parameters; not available for Java where a garbage collector destroys objects incidentally!</li>
 *  </ul>
 *
 * Children of an item can have a position, relative to each other. That means
 * that this item also is a special constellation of children which can be
 * enforced by constraints.
 *
 * @version $Revision: 1.9 $ $Date: 2003-03-18 00:18:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Item extends State {

    //
    // Children names.
    //

    /**
     * The children.
     *
     * ?? This map is temporary and can be removed later, when this Item class
     * contains the array handling - necessary to provide map behaviour - itself.
     */
    private java.util.Map children;

    /** The positioning */
    private String positioning;

    /**
     * The java tree node.
     *
     * ?? Temporary until CYBOP framework doesn't rely on java classes anymore.
     */
    private javax.swing.tree.DefaultMutableTreeNode javaTreeNode;

    /**
     * The encapsulated java object.
     *
     * ?? Temporary until CYBOP framework doesn't rely on java classes anymore.
     */
    private java.lang.Object javaObject;

    /** The action. */
    public static final String ACTION = new String("action");

    //
    // Children positioning.
    //

    /** The index positioning. */
    public static final String INDEX_POSITIONING = new String("index_positioning");

    /** The compass positioning. */
    public static final String COMPASS_POSITIONING = new String("compass_positioning");

    /** The box positioning. */
    public static final String BOX_POSITIONING = new String("box_positioning");

    /** The card positioning. */
    public static final String CARD_POSITIONING = new String("card_positioning");

    /** The grid bag positioning. */
    public static final String GRID_BAG_POSITIONING = new String("grid_bag_positioning");

    //
    // Constructor.
    //

    /**
     * Constructs this item.
     *
     * Actually, constructors should NOT be used in the CYBOP framework
     * or any derived systems. The offered lifecycle methods are sufficient.
     * However, since the children container is not really a child item itself
     * but rather a helper attribute to store children, it is created in this constructor.
     * In some way, it can be seen as meta property of (every) item as it
     * makes items hierarchical, just like in the universe, the real world.
     *
     * The items created here are destroyed in the finalize method
     * as Java does not provide destructors for its objects.
     */
    public Item() {

        setChildren(createChildren());
        setPositioning(createPositioning());

        // This java tree node is equivalent to the above children container
        // in that it can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system (dependency) tree using java tree nodes
        // so that such trees can easily be displayed in javax.swing.JTree objects.
        setJavaTreeNode(createJavaTreeNode());

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        //
        // This method is not called in the initialize lifecycle method
        // since then one would especially need to call initialize
        // even for every primitive item (like String), being created.
        setJavaObject(createJavaObject());
    }

    //
    // Default children.
    //

    /**
     * Returns the default action.
     *
     * @return the default action
     */
    public String getDefaultAction() {

        return null;
    }

    //
    // Children container.
    //

    /**
     * Creates the children.
     *
     * @return the children
     */
    public java.util.Map createChildren() {

        return new java.util.HashMap();
    }

    /**
     * Destroys the children.
     *
     * @param c the children
     */
    public void destroyChildren(java.util.Map c) {
    }

    /**
     * Sets the children.
     *
     * @param c the children
     */
    public void setChildren(java.util.Map c) {

        this.children = c;
    }

    /**
     * Returns the children.
     *
     * @return the children
     */
    public java.util.Map getChildren() {

        return this.children;
    }

    //
    // Positioning.
    //

    /**
     * Creates a positioning.
     *
     * @return the positioning
     */
    public String createPositioning() {

        return null;
    }

    /**
     * Destroys the positioning.
     *
     * @param p the positioning
     */
    public void destroyPositioning(String p) {
    }

    /**
     * Sets the positioning.
     *
     * @param p the positioning
     */
    public void setPositioning(String p) {

        this.positioning = p;
    }

    /**
     * Returns the positioning.
     *
     * @return the positioning
     */
    public String getPositioning() {

        return this.positioning;
    }

    //
    // Java tree node.
    //

    /**
     * Creates a java tree node.
     *
     * @return the java tree node
     * @exception NullPointerException if the java tree node is null
     */
    public javax.swing.tree.DefaultMutableTreeNode createJavaTreeNode() throws NullPointerException {

        javax.swing.tree.DefaultMutableTreeNode tn = new javax.swing.tree.DefaultMutableTreeNode();

        if (tn != null) {

            tn.setUserObject("Item");

        } else {

            throw new NullPointerException("Could not create java tree node. The java tree node is null.");
        }

        return tn;
    }

    /**
     * Destroys the java tree node.
     *
     * @param tn the java tree node
     */
    public void destroyJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {
    }

    /**
     * Sets the java tree node.
     *
     * @param tn the java tree node
     */
    public void setJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {

        this.javaTreeNode = tn;
    }

    /**
     * Returns the java tree node.
     *
     * @return the java tree node
     */
    public javax.swing.tree.DefaultMutableTreeNode getJavaTreeNode() {

        return this.javaTreeNode;
    }

    //
    // Encapsulated java object.
    //
    
    /**
     * Creates an encapsulated java object.
     *
     * @return the encapsulated java object
     * @exception NullPointerException if the encapsulated java object is null
     */
    public java.lang.Object createJavaObject() {

        return null;
    }

    /**
     * Destroys the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
    public void destroyJavaObject(java.lang.Object o) {
    }

    /**
     * Sets the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
    public void setJavaObject(java.lang.Object o) {

        this.javaObject = o;
    }

    /**
     * Returns the encapsulated java object.
     *
     * @return the encapsulated java object
     */
    public java.lang.Object getJavaObject() {

        return this.javaObject;
    }

    //
    // Child management.
    //

    /**
     * Creates an item.
     *
     * @param n the item class name
     * @return the item
     * @exception NullPointerException if the item class is null
     * @exception NullPointerException if the item is null
     */
    public Item createItem(String n) throws Exception {

        Item i = null;

        // If an item class name is set to null, then don't try to create the item.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create item from given class.
                i = (Item) cl.newInstance();

                if (i != null) {

                    java.lang.System.out.println("INFO: Initialize item.");
                    i.initialize();

                } else {
        
                    throw new NullPointerException("Could not create item. The item is null.");
                }

            } else {

                throw new NullPointerException("Could not create item. The item class is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not create item. The item class name is null.");
        }

        return i;
    }

    /**
     * Destroys the item.
     *
     * @param i the item
     * @exception NullPointerException if the item is null
     */
    public void destroyItem(Item i) throws Exception {

        if (i != null) {

            java.lang.System.out.println("INFO: Finalize item.");
            i.finalizz();

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy item. The item is null.");
        }
    }

    /**
     * Adds the item to become a child of this item.
     *
     * @param n the name
     * @param i the item
     */
    public void set(String n, Item i) {

        set(n, i, null);
    }

    /**
     * Adds the item to become a child of this item.
     *
     * The positioning/ constellation/ constraints for children of this item
     * are taken into consideration.
     *
     * @param n the name
     * @param i the item
     * @param p the position
     * @exception NullPointerException if the children structure is null
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i, Position p) throws NullPointerException {

        java.util.Map s = getChildren();

        if (s != null) {

            if (n != null) {

                // This test is necessary because java maps do not allow null values.
                // Otherwise, this test would be superfluous because the item i variable
                // is not accessed directly but only handed over to another method.
                if (i != null) {

                    java.lang.System.out.println("DEBUG: Set child: " + i + " with name: " + n.getJavaObject() + " in item: " + this);
                    addTreeNode(i);
                    s.put(n.getJavaObject(), i);
//??                    position(p, i);

                } else {

                    java.lang.System.out.println("DEBUG: Could not set item. The item is null.");
                }

            } else {

                throw new NullPointerException("Could not set item. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not set item. The children structure is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception NullPointerException if the children structure is null
     * @exception NullPointerException if the name is null
     */
    public void remove(String n) throws NullPointerException {

        java.util.Map s = getChildren();

        if (s != null) {

            if (n != null) {

                // The order of these method calls is important for removal of the tree node!
                // ?? Reason unclear.
                java.lang.System.out.println("DEBUG: Remove child: " + get(n) + " with name: " + n.getJavaObject() + " in item: " + this);
                s.remove(n.getJavaObject());
                removeTreeNode(get(n));

            } else {

                throw new NullPointerException("Could not remove item. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not remove item. The children structure is null.");
        }
    }

    /**
     * Returns the child with the given name.
     *
     * @param n the name
     * @exception NullPointerException if the children structure is null
     * @exception NullPointerException if the name is null
     */
    public Item get(String n) throws NullPointerException {

        Item i = null;
        java.util.Map s = getChildren();

        if (s != null) {

            if (n != null) {

                i = (Item) s.get(n.getJavaObject());

            } else {

                throw new NullPointerException("Could not get item. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not get item. The children structure is null.");
        }

        return i;
    }

    /**
     * Returns the number of children.
     *
     * @return the number of children
     * @exception NullPointerException if the children structure is null
     */
    public Integer getChildrenNumber() throws NullPointerException {

        Integer c = null;
        java.util.Map s = getChildren();

        if (s != null) {

            c = new Integer(s.size());

        } else {

            throw new NullPointerException("Could not get children number. The children structure is null.");
        }

        return c;
    }

    //
    // Positioning.
    //

    /**
     * Positions the item.
     *
     * The item will be positioned according to the given position which
     * is considered in relation to other items and the whole constellation
     * of items of this item.
     *
     * @param i the item
     * @param p the position
     * @exception NullPointerException if the constellation is null
     */
/*??
    public void position(Item i, Position p) throws NullPointerException {

        if (p != null) {

            Constellation c = getConstellation();
            
            if (c != null) {

                c.position(i, p);

            } else {

                throw new NullPointerException("Could not position item. The constellation is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not position item. The position is null.");
        }
    }

    /**
     * Unpositions the item.
     *
     * @param i the item
     * @param p the position
     * @exception NullPointerException if the constellation is null
     */
/*??
    public void unposition(Item i, Position p) throws NullPointerException {

        if (p != null) {

            Constellation c = getConstellation();
            
            if (c != null) {

                c.unposition(i, p);
                
            } else {
    
                throw new NullPointerException("Could not unposition item. The constellation is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not unposition item. The position is null.");
        }
    }

    //
    // Java tree node management.
    //

    /**
     * Adds the java tree node of the item.
     *
     * @param i the item
     * @exception NullPointerException if the java tree node is null
     * @exception NullPointerException if the item is null
     */
    public void addTreeNode(Item i) throws NullPointerException {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (i != null) {

                tn.add(i.getJavaTreeNode());

            } else {
    
                java.lang.System.out.println("DEBUG: Could not add java tree node. The item is null.");
            }
    
        } else {
    
            throw new NullPointerException("Could not add java tree node. The java tree node is null.");
        }
    }

    /**
     * Removes the java tree node of the item.
     *
     * @param i the item
     * @exception NullPointerException if the java tree node is null
     * @exception NullPointerException if the item is null
     */
    public void removeTreeNode(Item i) throws NullPointerException {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (i != null) {

                tn.remove(i.getJavaTreeNode());

            } else {
    
                java.lang.System.out.println("DEBUG: Could not remove java tree node. The item is null.");
            }

        } else {

            throw new NullPointerException("Could not remove java tree node. The java tree node is null.");
        }
    }

    //
    // Initializable.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {
        
        super.initialize();

        set(Item.ACTION, getDefaultAction());
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        String action = (String) get(Item.ACTION);
        remove(Item.ACTION);
        destroyItem(action);

        // The following objects MUST NOT be destroyed here!
        // They actually belong into a destructor method (if it existed in java).
        //
        // On shutdown, items call the finalize BEFORE the deglobalize method.
        // If the children container or java tree node were destroyed here,
        // an exception would occure since the deglobalize method still tries
        // to remove e.g. log record and configuration and such accesses the children
        // container and java tree node of this item AFTER finalize has been called.
        //
        // However, the code to destroy these objects would look like this:

        // java.lang.Object javaObject = getJavaObject();
        // setJavaObject(null);
        // destroyJavaObject(javaObject);
        
        // javax.swing.tree.DefaultMutableTreeNode javaTreeNode = getJavaTreeNode();
        // setJavaTreeNode(null);
        // destroyJavaTreeNode(javaTreeNode);

        // java.util.Map children = getChildren();
        // setChildren(null);
        // destroyChildren(children);

        super.finalizz();
    }

    //
    // Functionality.
    //

    /**
     * Returns the child item at the given position.
     *
     * @param p the position relative to this container item
     * @return the child item
     * @exception NullPointerException if the item is null
     */
    public Item get(Space p) throws Exception, NullPointerException {

        Item child = null;
/*??
        Children[] c = getChildren();
        int loops = c.length;
//??        int loops = getChildrenNumber();
        Item item = null;
        Space rp = null;
        Integer n = null;

        for (int i = 0; i < loops; i++) {

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
                            child = item.get(rp);
                        }
                    }
                }

            } else {
    
                throw new NullPointerException("Could not get child item. An item is null.");
            }
        }
*/

        return child;
    }

    /**
     * Checks whether or not this item contains the given position.
     *
     * @param p the position relative to this item
     * @return true if this item contains the given position;
     * false otherwise
     * @exception NullPointerException if the space is null
     */
    public boolean contains(Space p) throws Exception, NullPointerException {

        boolean b = false;
        Space s = null; //?? get(Item.SPACE);

        if (s != null) {

            b = s.contains(p);

        } else {

            throw new NullPointerException("Could not check position. The space is null.");
        }

        return b;
    }
}

