/*
 * $RCSfile: Hierarchy.java,v $
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

/**
 * This class represents a hierarchy.
 *
 * A hierarchy consists of a number of children. It can also be a child itself,
 * belonging to a parent item.<br><br>
 *
 * Since humans don't know where this hierarchy stops in the real world,
 * to microcosm as well as towards macrocosm, a black box has to be assumed
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
 * @version $Revision: 1.1 $ $Date: 2003-04-30 14:37:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Hierarchy extends Category {

    //
    // Meta attributes.
    //

    /** The children container. */
    private Hierarchy[] children;

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

    //
    // Temporary until CYBOP framework doesn't rely on java classes anymore.
    //

    /** The java tree node. */
    private javax.swing.tree.DefaultMutableTreeNode javaTreeNode;

    //
    // Initialization.
    //

    /**
     * Initializes this category.
     */
    public void initialize() throws Exception {

        setChildren(createChildren());
        setChildrenNumber(createChildrenNumber());
        setChildrenLimitFactor(createChildrenLimitFactor());

        // This java tree node is equivalent to the children container above
        // in that it can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system (dependency) tree using java tree nodes
        // so that such trees can easily be displayed in javax.swing.JTree objects.
        setJavaTreeNode(createJavaTreeNode());
    }

    /**
     * Finalizes this category.
     */
    public void finalizz() throws Exception {

        // This java tree node is equivalent to the children container above
        // in that it can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system (dependency) tree using java tree nodes
        // so that such trees can easily be displayed in javax.swing.JTree objects.
        javax.swing.tree.DefaultMutableTreeNode javaTreeNode = getJavaTreeNode();
        setJavaTreeNode(null);
        destroyJavaTreeNode(javaTreeNode);

        Hierarchy[] children = getChildren();
        setChildren(null);
        destroyChildren(children);

        double childrenNumber = getChildrenNumber();
        //?? setChildrenNumber(null);
        //?? destroyChildrenNumber(childrenNumber);

        int childrenLimitFactor = getChildrenLimitFactor();
        //?? setChildrenLimitFactor(null);
        //?? destroyChildrenLimitFactor(childrenLimitFactor);
    }
}

