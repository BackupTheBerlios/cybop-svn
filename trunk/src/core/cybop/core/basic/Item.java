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
 * @version $Revision: 1.20 $ $Date: 2003-04-24 15:58:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Item extends State {

    //
    // Meta attributes.
    //

    /** The name. */
    private String name;

    /** The position */
    private Integer position;

    /** The following item. */
    private Item follower;

    /** The children container. */
    private Item[] children;

    /** The children number. */
    private int childrenNumber;

    /**
     * The children limit factor.
     *
     * It is a percentual limit for the children array length. For example:
     *
     * Factor           Percentage
     * 0.25             25%
     * 0.5              50%
     * 0.75             75%
     *
     * If the array is filled by the given percentage, it will be extended.
     */
    private double childrenLimitFactor;

    /** The children categories container. */
    private Item[] childrenCategories;

    /** The children categories number. */
    private int childrenCategoriesNumber;

    /**
     * The children categories limit factor.
     *
     * It is a percentual limit for the children array length. For example:
     *
     * Factor           Percentage
     * 0.25             25%
     * 0.5              50%
     * 0.75             75%
     *
     * If the array is filled by the given percentage, it will be extended.
     */
    private double childrenCategoriesLimitFactor;

    /** The children positions container. */
    private Item[] childrenPositions;

    /** The children Positions number. */
    private int childrenPositionsNumber;

    /**
     * The children positions limit factor.
     *
     * It is a percentual limit for the children array length. For example:
     *
     * Factor           Percentage
     * 0.25             25%
     * 0.5              50%
     * 0.75             75%
     *
     * If the array is filled by the given percentage, it will be extended.
     */
    private double childrenPositionsLimitFactor;

    //
    // Temporary until CYBOP framework doesn't rely on java classes anymore.
    //

    /** The java tree node. */
    private javax.swing.tree.DefaultMutableTreeNode javaTreeNode;

    /** The encapsulated java object. */
    private java.lang.Object javaObject;

    //
    // Children names.
    //

    /** The action. */
    public static final String ACTION = new String("action");

    //
    // Children positions.
    //

    /** The index positioning. */
    public static final String INDEX_POSITIONING = new String("index_positioning");

    /** The list positioning. */
    public static final String LIST_POSITIONING = new String("list_positioning");

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

        setName(createName());
        setPosition(createPosition());
        setFollower(createFollower());
        setChildren(createChildren());
        setChildrenNumber(createChildrenNumber());
        setChildrenLimitFactor(createChildrenLimitFactor());
        setChildrenCategories(createChildrenCategories());
        setChildrenCategoriesNumber(createChildrenCategoriesNumber());
        setChildrenCategoriesLimitFactor(createChildrenCategoriesLimitFactor());
        setChildrenPositions(createChildrenPositions());
        setChildrenPositionsNumber(createChildrenPositionsNumber());
        setChildrenPositionsLimitFactor(createChildrenPositionsLimitFactor());

        // This java tree node is equivalent to the children container above
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
    // Name.
    //

    /**
     * Creates a name.
     *
     * @return the name
     */
    public String createName() {

        return null;
    }

    /**
     * Destroys the name.
     *
     * @param n the name
     */
    public void destroyName(String n) {
    }

    /**
     * Sets the name.
     *
     * @param n the name
     */
    public void setName(String n) {

        this.name = n;
    }

    /**
     * Returns the name.
     *
     * @return the name
     */
    public String getName() {

        return this.name;
    }

    //
    // Position.
    //

    /**
     * Creates the position.
     *
     * @return the position
     */
    public Integer createPosition() {

        return null;
    }

    /**
     * Destroys the position.
     *
     * @param p the position
     */
    public void destroyPosition(Integer p) {
    }

    /**
     * Sets the position.
     *
     * @param p the position
     */
    public void setPosition(Integer p) {

        this.position = p;
    }

    /**
     * Returns the position.
     *
     * @return the position
     */
    public Integer getPosition() {

        return this.position;
    }

    //
    // Following item.
    //
    
    /**
     * Creates the following item.
     *
     * @return the following item
     */
    public Item createFollower() {

        return null;
    }

    /**
     * Destroys the following item.
     *
     * @param f the following item
     */
    public void destroyFollower(Item f) {
    }

    /**
     * Sets the following item.
     *
     * @param f the following item
     */
    public void setFollower(Item f) {

        this.follower = f;
    }

    /**
     * Returns the following item.
     *
     * @return the following item
     */
    public Item getFollower() {

        return this.follower;
    }

    //
    // Children container.
    //

    /**
     * Creates the children container.
     *
     * @return the children container
     */
    public Item[] createChildren() {

        return new Item[0];
    }

    /**
     * Destroys the children container.
     *
     * @param c the children container
     */
    public void destroyChildren(Item[] c) {
    }

    /**
     * Sets the children container.
     *
     * @param c the children container
     */
    public void setChildren(Item[] c) {

        this.children = c;
    }

    /**
     * Returns the children container.
     *
     * @return the children container
     */
    public Item[] getChildren() {

        return this.children;
    }

    //
    // Children number.
    //

    /**
     * Creates the children number.
     *
     * @return the children number
     */
    public int createChildrenNumber() {

        return 0;
    }

    /**
     * Destroys the children number.
     *
     * @param n the children number
     */
    public void destroyChildrenNumber(int n) {
    }

    /**
     * Sets the children number.
     *
     * @param n the children number
     */
    public void setChildrenNumber(int n) {

        this.childrenNumber = n;
    }

    /**
     * Returns the children number.
     *
     * @return the children number
     */
    public int getChildrenNumber() {

        return this.childrenNumber;
    }

    //
    // Children limit factor.
    //

    /**
     * Creates the children limit factor.
     *
     * @return the children limit factor
     */
    public double createChildrenLimitFactor() {

        return 0.75;
    }

    /**
     * Destroys the children limit factor.
     *
     * @param f the children limit factor
     */
    public void destroyChildrenLimitFactor(double f) {
    }

    /**
     * Sets the children limit factor.
     *
     * @param f the children limit factor
     */
    public void setChildrenLimitFactor(double f) {

        this.childrenLimitFactor = f;
    }

    /**
     * Returns the children limit factor.
     *
     * @return the children limit factor
     */
    public double getChildrenLimitFactor() {

        return this.childrenLimitFactor;
    }

    //
    // Children categories container.
    //

    /**
     * Creates the children categories container.
     *
     * @return the children categories container
     */
    public Item[] createChildrenCategories() {

        return new Item[0];
    }

    /**
     * Destroys the children categories container.
     *
     * @param c the children categories container
     */
    public void destroyChildrenCategories(Item[] c) {
    }

    /**
     * Sets the children categories container.
     *
     * @param c the children categories container
     */
    public void setChildrenCategories(Item[] c) {

        this.childrenCategories = c;
    }

    /**
     * Returns the children categories container.
     *
     * @return the children categories container
     */
    public Item[] getChildrenCategories() {

        return this.childrenCategories;
    }

    //
    // Children categories number.
    //

    /**
     * Creates the children categories number.
     *
     * @return the children categories number
     */
    public int createChildrenCategoriesNumber() {

        return 0;
    }

    /**
     * Destroys the children categories number.
     *
     * @param n the children categories number
     */
    public void destroyChildrenCategoriesNumber(int n) {
    }

    /**
     * Sets the children categories number.
     *
     * @param n the children categories number
     */
    public void setChildrenCategoriesNumber(int n) {

        this.childrenCategoriesNumber = n;
    }

    /**
     * Returns the children categories number.
     *
     * @return the children categories number
     */
    public int getChildrenCategoriesNumber() {

        return this.childrenCategoriesNumber;
    }

    //
    // Children categories limit factor.
    //

    /**
     * Creates the children categories limit factor.
     *
     * @return the children categories limit factor
     */
    public double createChildrenCategoriesLimitFactor() {

        return 0.75;
    }

    /**
     * Destroys the children categories limit factor.
     *
     * @param f the children categories limit factor
     */
    public void destroyChildrenCategoriesLimitFactor(double f) {
    }

    /**
     * Sets the children categories limit factor.
     *
     * @param f the children categories limit factor
     */
    public void setChildrenCategoriesLimitFactor(double f) {

        this.childrenCategoriesLimitFactor = f;
    }

    /**
     * Returns the children categories limit factor.
     *
     * @return the children categories limit factor
     */
    public double getChildrenCategoriesLimitFactor() {

        return this.childrenCategoriesLimitFactor;
    }

    //
    // Children positions container.
    //

    /**
     * Creates the children positions container.
     *
     * @return the children positions container
     */
    public Item[] createChildrenPositions() {

        return new Item[0];
    }

    /**
     * Destroys the children positions container.
     *
     * @param c the children positions container
     */
    public void destroyChildrenPositions(Item[] c) {
    }

    /**
     * Sets the children positions container.
     *
     * @param c the children positions container
     */
    public void setChildrenPositions(Item[] c) {

        this.childrenPositions = c;
    }

    /**
     * Returns the children positions container.
     *
     * @return the children positions container
     */
    public Item[] getChildrenPositions() {

        return this.childrenPositions;
    }

    //
    // Children positions number.
    //

    /**
     * Creates the children positions number.
     *
     * @return the children positions number
     */
    public int createChildrenPositionsNumber() {

        return 0;
    }

    /**
     * Destroys the children positions number.
     *
     * @param n the children positions number
     */
    public void destroyChildrenPositionsNumber(int n) {
    }

    /**
     * Sets the children positions number.
     *
     * @param n the children positions number
     */
    public void setChildrenPositionsNumber(int n) {

        this.childrenPositionsNumber = n;
    }

    /**
     * Returns the children positions number.
     *
     * @return the children positions number
     */
    public int getChildrenPositionsNumber() {

        return this.childrenPositionsNumber;
    }

    //
    // Children positions limit factor.
    //

    /**
     * Creates the children positions limit factor.
     *
     * @return the children positions limit factor
     */
    public double createChildrenPositionsLimitFactor() {

        return 0.75;
    }

    /**
     * Destroys the children positions limit factor.
     *
     * @param f the children positions limit factor
     */
    public void destroyChildrenPositionsLimitFactor(double f) {
    }

    /**
     * Sets the children positions limit factor.
     *
     * @param f the children positions limit factor
     */
    public void setChildrenPositionsLimitFactor(double f) {

        this.childrenPositionsLimitFactor = f;
    }

    /**
     * Returns the children positions limit factor.
     *
     * @return the children positions limit factor
     */
    public double getChildrenPositionsLimitFactor() {

        return this.childrenPositionsLimitFactor;
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
    // Child.
    //

    /**
     * Creates a child item.
     *
     * @param n the child item category (class) name
     * @return the child item
     * @exception NullPointerException if the child item class is null
     * @exception NullPointerException if the child item is null
     */
    public Item createChildItem(String n) throws Exception, NullPointerException {

        Item i = null;

        // If a child item class name is set to null, then don't try to create the item.
        if (n != null) {

            // Find class by name.
            Class cl = Class.forName((java.lang.String) n.getJavaObject());

            if (cl != null) {

                // Create item from given class.
                i = (Item) cl.newInstance();

                if (i != null) {

                    java.lang.System.out.println("INFO: Initialize child item.");
                    i.initialize();

                } else {
        
                    throw new NullPointerException("Could not create child item. The child item is null.");
                }

            } else {

                throw new NullPointerException("Could not create child item. The child item class is null.");
            }

        } else {

            java.lang.System.out.println("DEBUG: Could not create child item. The child item class name is null.");
        }

        return i;
    }

    /**
     * Destroys the child item.
     *
     * @param i the child item
     * @exception NullPointerException if the child item is null
     */
    public void destroyChildItem(Item i) throws Exception {

        if (i != null) {

            java.lang.System.out.println("INFO: Finalize child item.");
            i.finalizz();

        } else {

            java.lang.System.out.println("DEBUG: Could not destroy child item. The child item is null.");
        }
    }

    /**
     * Sets the child item.
     *
     * @param n the child item name
     * @param c the child item
     */
    public void setChildItem(String n, Item c) {

        if (c != null) {

            // Set meta attributes for child.
            // DO NOT use the normal method setChildItem(name, item);
            // This would lead to an endless loop since for example
            // setChildItem(Item.NAME, n); would cause to be called repeatedly!
            c.setName(n);

            Item[] a = getChildren();
            int no = getChildrenNumber();

            if (replace(a, no, n, c) == false) {

                // If the child was not found and such not replaced,
                // then it does not exist in the array yet.
                // Therefore, it is added to the array here.

                // If the array length is exceeded, a new adjusted array with
                // extended length is created and delivered back.
                // Otherwise, the previous array is returned again.
                Item[] aa = adjust(a, no, getChildrenLimitFactor());

                add(aa, no, c);
                setChildren(aa);
                setChildrenNumber(no + 1);
            }

        } else {

            java.lang.System.out.println("WARNING: Could not set child item. The child item is null.");
        }
    }

    /**
     * Removes the child item.
     *
     * @param n the child item name
     */
    public void removeChildItem(String n) {

        int no = getChildrenNumber();

        remove(getChildren(), no, n);
        setChildrenNumber(no - 1);
    }

    /**
     * Returns the child item.
     *
     * @param n the child item name
     * @return the child item
     */
    public Item getChildItem(String n) {

        return getChildItem(n, null);
    }

    /**
     * Returns the child item.
     *
     * @param n the child item name
     * @param d the default item
     * @return the child item
     */
    public Item getChildItem(String n, Item d) {

        Item i = get(getChildren(), getChildrenNumber(), n);

        if (i == null) {

            i = d;
        }

        return i;
    }

    //
    // Child category.
    //

    /**
     * Creates a child category.
     *
     * @return the child category
     */
    public Item createChildCategory() throws Exception {

        return null;
    }

    /**
     * Destroys the child category.
     *
     * @param c the child category
     */
    public void destroyChildCategory(Item c) throws Exception {
    }

    /**
     * Sets the child category.
     *
     * @param n the child category name
     * @param c the child category
     */
    public void setChildCategory(String n, Item c) {

        if (c != null) {

            // Set meta attributes for child.
            // DO NOT use the normal method setChildItem(name, item);
            // This would lead to an endless loop since for example
            // setChildItem(Item.NAME, n); would cause to be called repeatedly!
            c.setName(n);

            Item[] a = getChildrenCategories();
            int no = getChildrenCategoriesNumber();

            if (replace(a, no, n, c) == false) {

                // If the child was not found and such not replaced,
                // then it does not exist in the array yet.
                // Therefore, it is added to the array here.

                // If the array length is exceeded, a new adjusted array with
                // extended length is created and delivered back.
                // Otherwise, the previous array is returned again.
                Item[] aa = adjust(a, no, getChildrenCategoriesLimitFactor());

                add(aa, no, c);
                setChildrenCategories(aa);
                setChildrenCategoriesNumber(no + 1);
            }

        } else {

            java.lang.System.out.println("WARNING: Could not set child category. The child category is null.");
        }
    }

    /**
     * Removes the child category.
     *
     * @param n the child category name
     */
    public void removeChildCategory(String n) {

        int no = getChildrenCategoriesNumber();

        remove(getChildrenCategories(), no, n);
        setChildrenCategoriesNumber(no - 1);
    }

    /**
     * Returns the child category.
     *
     * @param n the child category name
     * @return the child category
     */
    public Item getChildCategory(String n) {

        return getChildCategory(n, null);
    }

    /**
     * Returns the child category.
     *
     * @param n the child category name
     * @param d the default child category
     * @return the child category
     */
    public Item getChildCategory(String n, Item d) {

        Item i = get(getChildrenCategories(), getChildrenCategoriesNumber(), n);

        if (i == null) {

            i = d;
        }

        return i;
    }

    //
    // Child position.
    //

    /**
     * Creates a child position.
     *
     * @return the child position
     */
    public Item createChildPosition() {

        return null;
    }

    /**
     * Destroys the child position.
     *
     * @param p the child position
     */
    public void destroyChildPosition(Item p) {
    }

    /**
     * Sets the child position.
     *
     * @param n the child position name
     * @param c the child position
     */
    public void setChildPosition(String n, Item c) {

        if (c != null) {

            // Set meta attributes for child.
            // DO NOT use the normal method setChildItem(name, item);
            // This would lead to an endless loop since for example
            // setChildItem(Item.NAME, n); would cause to be called repeatedly!
            c.setName(n);

            Item[] a = getChildrenPositions();
            int no = getChildrenPositionsNumber();

            if (replace(a, no, n, c) == false) {

                // If the child was not found and such not replaced,
                // then it does not exist in the array yet.
                // Therefore, it is added to the array here.

                // If the array length is exceeded, a new adjusted array with
                // extended length is created and delivered back.
                // Otherwise, the previous array is returned again.
                Item[] aa = adjust(a, no, getChildrenPositionsLimitFactor());

                add(aa, no, c);
                setChildrenPositions(aa);
                setChildrenPositionsNumber(no + 1);
            }

        } else {

            java.lang.System.out.println("WARNING: Could not set child position. The child position is null.");
        }
    }

    /**
     * Removes the child position.
     *
     * @param n the child position name
     */
    public void removeChildPosition(String n) {

        int no = getChildrenPositionsNumber();

        remove(getChildrenPositions(), no, n);
        setChildrenPositionsNumber(no - 1);
    }

    /**
     * Returns the child position.
     *
     * @param n the child position name
     * @return the child position
     */
    public Item getChildPosition(String n) {

        return getChildPosition(n, null);
    }

    /**
     * Returns the child position.
     *
     * @param n the child position name
     * @param d the default child position
     * @return the child position
     */
    public Item getChildPosition(String n, Item d) {

        Item i = get(getChildrenPositions(), getChildrenPositionsNumber(), n);

        if (i == null) {

            i = d;
        }

        return i;
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

                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
                if (tn.isNodeChild(i.getJavaTreeNode())) {

                    tn.remove(i.getJavaTreeNode());
                }

            } else {
    
                java.lang.System.out.println("DEBUG: Could not remove java tree node. The item is null.");
            }

        } else {

            throw new NullPointerException("Could not remove java tree node. The java tree node is null.");
        }
    }

    //
    // Array container management.
    //

    /**
     * Adjusts the array.
     *
     * If the length limit of the given array is reached, a new array with
     * extended length is created and returned.
     *
     * @param a the array
     * @param n the array items number
     * @param f the array limit factor
     * @return the adjusted array;
     * by default, the same array like given as parameter will be returned;
     * only if the length limit was reached, a new array with extended length
     * is created and returned
     *
     * @exception NullPointerException if the array is null
     */
    protected Item[] adjust(Item[] a, int n, double f) throws NullPointerException {

        Item[] i = a;

        if (a != null) {

            int limit = (int) (a.length * f);

            if (n >= limit) {

                // If the children number reaches/ exceeds the limit,
                // the children array will be extended (rehashed).
                i = recreate(a);
            }

        } else {

            throw new NullPointerException("Could not adjust array. The array is null.");
        }

        return i;
    }

    /**
     * Recreates the given array with double length.
     *
     * Extends the length of the children array and internally reorganizes it, 
     * in order to accommodate and access its entries more efficiently.
     *
     * @param old the old children array
     * @return the recreated children array
     * @exception NullPointerException if the children array is null
     * @exception NullPointerException if an old item is null
     */
    protected Item[] recreate(Item[] old) throws NullPointerException {

        Item[] c = null;

        if (old != null) {

            int oldLength = old.length;
            int newLength = oldLength * 2 + 1;
            c = new Item[newLength];
            int i = 0;

            while (i < oldLength) {

                c[i] = old[i];

                i++;
            }

        } else {

            throw new NullPointerException("Could not extend children array. The children array is null.");
        }

        return c;
    }

    //
    // Array item management.
    //

    /**
     * Adds the item with the name to the array.
     *
     * @param a the array
     * @param no the item number
     * @param i the item
     * @exception NullPointerException if the array is null
     */
    public void add(Item[] a, int no, Item i) throws NullPointerException {

        if (a != null) {

            java.lang.System.out.println("DEBUG: Add item: " + i + " in item: " + this);
            addTreeNode(i);
            a[no] = i;

        } else {

            throw new NullPointerException("Could not add item. The array is null.");
        }
    }

    /**
     * Replaces the item with the name in the array.
     *
     * @param a the array
     * @param no the item number
     * @param n the name
     * @param i the item
     * @return true if the item was replaced; false otherwise
     * @exception NullPointerException if the array is null
     * @exception NullPointerException if the name is null
     * @exception NullPointerException if a child is null
     */
    public boolean replace(Item[] a, int no, String n, Item i) throws NullPointerException {

        boolean b = false;

        if (a != null) {

            if (n != null) {

                int index = 0;
                Item child = null;

                while (index < no) {

                    child = a[index];

                    if (child != null) {

                        if (n.isEqualTo(child.getName())) {

                            java.lang.System.out.println("DEBUG: Replace item: " + i + " with name: " + n.getJavaObject() + " in item: " + this);

                            removeTreeNode(child);
                            addTreeNode(i);
                            a[index] = i;
                            b = true;

                            break;
                        }
                        
                    } else {

                        throw new NullPointerException("Could not replace item. A child is null.");
                    }

                    index++;
                }

            } else {

                throw new NullPointerException("Could not replace item. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not replace item. The array is null.");
        }
        
        return b;
    }

    /**
     * Removes the item from this item.
     *
     * @param a the array
     * @param no the item number
     * @param n the name
     * @exception NullPointerException if the array is null
     * @exception NullPointerException if the name is null
     * @exception NullPointerException if a child is null
     */
    public void remove(Item[] a, int no, String n) throws NullPointerException {

        if (a != null) {

            if (n != null) {

                int index = 0;
                Item i = null;

                while (index < no) {

                    i = a[index];

                    if (i != null) {

                        if (n.isEqualTo(i.getName())) {

                            // Move all remaining items one place towards the
                            // beginning of the array.
                            java.lang.System.out.println("DEBUG: Remove item: " + i + " with name: " + n.getJavaObject() + " in item: " + this);

                            while ((index + 1) < no) {

                                a[index] = a[index + 1];

                                index++;
                            }

                            // The order of these method calls is important for
                            // removal of the tree node!

                            // Set former last item to null.
                            a[index] = null;
                            removeTreeNode(i);

                            break;
                        }

                    } else {

                        throw new NullPointerException("Could not remove item. A child is null.");
                    }

                    index++;
                }

            } else {

                throw new NullPointerException("Could not remove item. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not remove item. The array is null.");
        }
    }

    /**
     * Returns the item with the name.
     *
     * @param a the array
     * @param no the item number
     * @param n the name
     * @return the item
     * @exception NullPointerException if the name is null
     * @exception NullPointerException if the array is null
     * @exception NullPointerException if a child is null
     */
    public Item get(Item[] a, int no, String n) throws NullPointerException {

        Item i = null;

        if (a != null) {

            if (n != null) {

                int index = 0;
                Item child = null;

                while (index < no) {
                    
                    child = a[index];
    
                    if (child != null) {
    
                        if (n.isEqualTo(child.getName())) {

                            i = child;

                            break;
                        }

                    } else {

                        throw new NullPointerException("Could not get item. A child is null.");
                    }

                    index++;
                }

            } else {

                throw new NullPointerException("Could not get item. The name is null.");
            }

        } else {

            throw new NullPointerException("Could not get item. The array is null.");
        }

        return i;
    }

    //
    // Name management.
    //

    /**
     * Builds a name.
     *
     * @param base the word base of the name
     * @return the name
     * @exception NullPointerException if the highest name number is null
     * @exception NullPointerException if the word base of the name is null
     * @exception NullPointerException if the number string is null
     */
    public String buildName(String base) throws NullPointerException {

        String n = null;
        Integer i = getHighestNameNumber(base);
        
        if (i != null) {

            String no = new String(java.lang.String.valueOf(i.getJavaPrimitive() + 1));

            if (base != null) {

                if (no != null) {

                    n = new String(base.getJavaObject() + "_" + no.getJavaObject());

                } else {
        
                    throw new NullPointerException("Could not build name. The number string is null.");
                }

            } else {
    
                throw new NullPointerException("Could not build name. The word base of the name is null.");
            }

        } else {

            throw new NullPointerException("Could not build name. The highest name number is null.");
        }

        return n;        
    }

    /**
     * Returns the highest name number.
     *
     * @param base the word base of the name
     * @return the highest name number
     * @exception NullPointerException if the children array is null
     * @exception NullPointerException if a child is null
     * @exception NullPointerException if the name is null
     * @exception NullPointerException if the number is null
     */
    public Integer getHighestNameNumber(String base) throws NullPointerException {

        Integer i = new Integer(-1);
        Item[] c = getChildren();

        if (c != null) {

            int index = 0;
            int no = getChildrenNumber();
            Item child = null;
            String n = null;
            int begin = 0;
            String sub = null;
            Integer number = null;

            while (index < no) {

                child = (Item) c[index];

                if (child != null) {

                    n = child.getName();

                    if (n != null) {

                        if (n.startsWith(base)) {

                            begin = n.indexOf(new String("_"));
                            sub = n.subString(begin + 1);
                            number = Integer.toInteger(sub);

                            if (number != null) {

                                if (number.isGreaterThan(i)) {

                                    i = number;
                                }

                            } else {
                
                                throw new NullPointerException("Could not get highest name number. The number is null.");
                            }
                        }

                    } else {
        
                        throw new NullPointerException("Could not get highest name number. The name is null.");
                    }
    
                } else {

                    throw new NullPointerException("Could not get highest name number. A child is null.");
                }

                index++;
            }

        } else {

            throw new NullPointerException("Could not get highest name number. The children array is null.");
        }

        return i;
    }

    //
    // Initializable.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {
        
        super.initialize();

        setChildItem(Item.ACTION, getDefaultAction());
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        String action = (String) getChildItem(Item.ACTION);
        removeChildItem(Item.ACTION);
        destroyChildItem(action);

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
     * @exception NullPointerException if the children array is null
     * @exception NullPointerException if the child item is null
     */
    public Item getChildItem(Space p) throws Exception, NullPointerException {

        Item child = null;
/*??
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
                                child = item.getChildItem(rp);
                            }
                        }
                    }
    
                } else {
        
                    throw new NullPointerException("Could not get child item. An item is null.");
                }
                
                i++;
            }

        } else {

            throw new NullPointerException("Could not get child item. The children array is null.");
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
        Space s = null; //?? getChildItem(Item.SPACE);

        if (s != null) {

            b = s.contains(p);

        } else {

            throw new NullPointerException("Could not check position. The space is null.");
        }

        return b;
    }
}

