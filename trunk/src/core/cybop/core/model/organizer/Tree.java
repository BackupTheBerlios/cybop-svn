/*
 * $RCSfile: Tree.java,v $
 *
 * Copyright (c) 1999-2002. The Res Medicinae developers. All rights reserved.
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.model.organizer;

import cybop.basic.*;
import cybop.basic.String;
import cybop.model.*;

/**
 * This class represents a tree.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Tree extends Organizer {

    //
    // Children.
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
     * @exception NullPointerException if the encapsulated java swing tree is null
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        javax.swing.JTree t = new javax.swing.JTree();
//??        javax.swing.JTree t = new javax.swing.JTree(new javax.swing.tree.DefaultTreeModel(new javax.swing.tree.DefaultMutableTreeNode("test")));

        if (t != null) {

            t.setToggleClickCount(1);
//??            t.setRootVisible(false);
            t.getSelectionModel().setSelectionMode(javax.swing.tree.TreeSelectionModel.SINGLE_TREE_SELECTION);
            t.setMinimumSize(new java.awt.Dimension(300, 400));

        } else {

            throw new NullPointerException("Could not create encapsulated java swing tree. The encapsulated java swing tree is null.");
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
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(Tree.MODEL)) {

                setModel((Model) i);
            }

        } else {

            throw new NullPointerException("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception NullPointerException if the name is null
     */
    public void remove(String n) throws NullPointerException {

        if (n != null) {

            if (n.isEqualTo(Tree.MODEL)) {

                removeModel((Model) get(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
        }

        super.remove(n);
    }

    //
    // Model.
    //

    /**
     * Sets the model.
     *
     * @param m the model
     * @exception NullPointerException if the java tree node is null
     * @exception NullPointerException if the model is null
     */
    public void setModel(Model m) throws NullPointerException {

        javax.swing.JTree t = (javax.swing.JTree) getJavaObject();

        if (t != null) {

            if (m != null) {

                t.setModel(new javax.swing.tree.DefaultTreeModel((javax.swing.tree.DefaultMutableTreeNode) m.getJavaTreeNode()));

            } else {

                throw new NullPointerException("Could not set model. The model is null.");
            }

        } else {

            throw new NullPointerException("Could not set model. The java tree node is null.");
        }
    }

    /**
     * Removes the model.
     *
     * @param m the model
     * @exception NullPointerException if the java tree node is null
     */
    public void removeModel(Model m) throws NullPointerException {

        javax.swing.JTree t = (javax.swing.JTree) getJavaObject();

        if (t != null) {

            t.setModel(null);

        } else {

            throw new NullPointerException("Could not remove model. The java tree node is null.");
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

