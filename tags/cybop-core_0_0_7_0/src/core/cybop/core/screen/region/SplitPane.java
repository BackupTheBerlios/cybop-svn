/*
 * $RCSfile: SplitPane.java,v $
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

package cybop.core.screen.region;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.screen.*;

/**
 * This class represents a split pane.
 *
 * @version $Revision: 1.8 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SplitPane extends DisplayRegion {

    //
    // Children names.
    //

    /** The left item. */
    public static final String LEFT_ITEM = new String("left_item");

    /** The right item. */
    public static final String RIGHT_ITEM = new String("right_item");

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
    public void setChild(String n, Item i) throws Exception {

        super.setChild(n, i);

        if (n != null) {

            if (n.isEqualTo(SplitPane.LEFT_ITEM)) {

                setLeftItem((DisplayItem) i);

            } else if (n.isEqualTo(SplitPane.RIGHT_ITEM)) {

                setRightItem((DisplayItem) i);
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
    public void removeChild(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(SplitPane.LEFT_ITEM)) {

                removeLeftItem((DisplayItem) getChild(n));
            
            } else if (n.isEqualTo(SplitPane.RIGHT_ITEM)) {

                removeRightItem((DisplayItem) getChild(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }

        super.removeChild(n);
    }

    //
    // Encapsulated java swing split pane.
    //
    
    /**
     * Creates an encapsulated java swing split pane.
     *
     * @return the encapsulated java swing split pane
     * @exception Exception if the encapsulated java swing split pane is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JSplitPane sp = new javax.swing.JSplitPane();

        if (sp != null) {

            sp.setOrientation(javax.swing.JSplitPane.HORIZONTAL_SPLIT);
            sp.setOneTouchExpandable(true);
            sp.setContinuousLayout(true);
            sp.setDividerLocation(200);
            sp.setPreferredSize(new java.awt.Dimension(800, 600));

        } else {

            throw new Exception("Could not create encapsulated java swing split pane. The encapsulated java swing split pane is null.");
        }

        return sp;
    }

    //
    // Default categories.
    //

    /**
     * Returns the left item category.
     *
     * @return the left item category
     */
    public Item getDefaultLeftItemCategory() {

        return new String("cybop.core.screen.region.Panel");
    }

    /**
     * Returns the right item category.
     *
     * @return the right item category
     */
    public Item getDefaultRightItemCategory() {

        return new String("cybop.core.screen.region.Panel");
    }

    //
    // Left item.
    //

    /**
     * Sets the left item.
     *
     * @param c the left item
     * @exception Exception if the java split pane is null
     * @exception Exception if the left item is null
     */
    public void setLeftItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setLeftComponent((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set left item. The left item is null.");
            }

        } else {

            throw new Exception("Could not set left item. The java split pane is null.");
        }
    }

    /**
     * Removes the left item.
     *
     * @param c the left item
     * @exception Exception if the java split pane is null
     * @exception Exception if the left item is null
     */
    public void removeLeftItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.remove((java.awt.Component) c.getJavaObject());

            } else {

                throw new Exception("Could not remove left item. The left item is null.");
            }

        } else {

            throw new Exception("Could not remove left item. The java split pane is null.");
        }
    }

    //
    // Right item.
    //

    /**
     * Sets the right item.
     *
     * @param c the right item
     * @exception Exception if the java split pane is null
     * @exception Exception if the right item is null
     */
    public void setRightItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setRightComponent((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set right item. The right item is null.");
            }

        } else {

            throw new Exception("Could not set right item. The java split pane is null.");
        }
    }

    /**
     * Removes the right item.
     *
     * @param c the right item
     * @exception Exception if the java split pane is null
     * @exception Exception if the right item is null
     */
    public void removeRightItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.remove((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not remove right item. The right item is null.");
            }

        } else {

            throw new Exception("Could not remove right item. The java split pane is null.");
        }
    }

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(SplitPane.LEFT_ITEM, getDefaultLeftItemCategory());
        setCategory(SplitPane.RIGHT_ITEM, getDefaultRightItemCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(SplitPane.RIGHT_ITEM);
        removeCategory(SplitPane.LEFT_ITEM);

        super.decategorize();
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(SplitPane.LEFT_ITEM, createChild(getCategory(SplitPane.LEFT_ITEM)));
        setChild(SplitPane.RIGHT_ITEM, createChild(getCategory(SplitPane.RIGHT_ITEM)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item rightDisplayItem = getChild(SplitPane.RIGHT_ITEM);
        removeChild(SplitPane.RIGHT_ITEM);
        destroyChild(rightDisplayItem);

        Item leftDisplayItem = getChild(SplitPane.LEFT_ITEM);
        removeChild(SplitPane.LEFT_ITEM);
        destroyChild(leftDisplayItem);

        super.finalizz();
    }
}

