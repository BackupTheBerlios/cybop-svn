/*
 * $RCSfile: Tree.java,v $
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

package cybop.core.model.organizer;

import cybop.core.basic.*;
import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a tree.
 *
 * @version $Revision: 1.6 $ $Date: 2003-05-17 22:30:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Tree extends Organizer {

    //
    // Children names.
    //

    /** The model. */
    public static final String MODEL = new String("model");

    /** The selection model. */
    public static final String SELECTION_MODEL = new String("selection_model");

    /** The cell renderer. */
    public static final String CELL_RENDERER = new String("cell_renderer");

    /** The row height. */
    public static final String ROW_HEIGHT = new String("row_height");

    /** The root visible. */
    public static final String ROOT_VISIBLE = new String("root_visible");

    /** The editable. */
    public static final String EDITABLE = new String("editable");

    /** The toggle click count. */
    public static final String TOGGLE_CLICK_COUNT = new String("toggle_click_count");

    //
    // Encapsulated java swing tree.
    //

    /**
     * Creates an encapsulated java swing tree.
     *
     * @return the encapsulated java swing tree
     * @exception Exception if the encapsulated java swing tree is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JTree t = new javax.swing.JTree();
//??        javax.swing.JTree t = new javax.swing.JTree(new javax.swing.tree.DefaultTreeModel(new javax.swing.tree.DefaultMutableTreeNode("test")));

        if (t != null) {

            t.setToggleClickCount(1);
//??            t.setRootVisible(false);
            t.getSelectionModel().setSelectionMode(javax.swing.tree.TreeSelectionModel.SINGLE_TREE_SELECTION);
            t.setMinimumSize(new java.awt.Dimension(300, 400));

        } else {

            throw new Exception("Could not create encapsulated java swing tree. The encapsulated java swing tree is null.");
        }

        return t;
    }

    //
    // Child management.
    //

    /**
     * Adds the item to become a child of this item.
     *
     * @param n the name
     * @param i the item
     * @exception Exception if the name is null
     */
    public void setChildItem(String n, Item i) throws Exception {

        super.setChildItem(n, i);

        if (n != null) {

            if (n.isEqualTo(Tree.MODEL)) {

                setModel((Model) i);
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
    public void removeChildItem(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(Tree.MODEL)) {

                removeModel((Model) getChildItem(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }

        super.removeChildItem(n);
    }

    //
    // Model.
    //

    /**
     * Sets the model.
     *
     * @param m the model
     * @exception Exception if the java tree node is null
     * @exception Exception if the model is null
     */
    public void setModel(Model m) throws Exception {

        javax.swing.JTree t = (javax.swing.JTree) getJavaObject();

        if (t != null) {

            if (m != null) {

                t.setModel(new javax.swing.tree.DefaultTreeModel((javax.swing.tree.DefaultMutableTreeNode) m.getJavaTreeNode()));

            } else {

                throw new Exception("Could not set model. The model is null.");
            }

        } else {

            throw new Exception("Could not set model. The java tree node is null.");
        }
    }

    /**
     * Removes the model.
     *
     * @param m the model
     * @exception Exception if the java tree node is null
     */
    public void removeModel(Model m) throws Exception {

        javax.swing.JTree t = (javax.swing.JTree) getJavaObject();

        if (t != null) {

            t.setModel(null);

        } else {

            throw new Exception("Could not remove model. The java tree node is null.");
        }
    }

    //
    // Initializable.
    //

    /**
     * Initializes this tree.
     */
    public void initialize() throws Exception {

        super.initialize();
    }

    /**
     * Finalizes this tree.
     */
    public void finalizz() throws Exception {

        super.finalizz();
    }
}

