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
 * @version $Revision: 1.7 $ $Date: 2003-06-19 22:25:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SplitPane extends DisplayRegion {

    //
    // Children names.
    //

    /** The left organizer. */
    public static final String LEFT_ORGANIZER = new String("left_organizer");

    /** The right organizer. */
    public static final String RIGHT_ORGANIZER = new String("right_organizer");

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

            if (n.isEqualTo(SplitPane.LEFT_ORGANIZER)) {

                setLeftDisplayItem((DisplayItem) i);

            } else if (n.isEqualTo(SplitPane.RIGHT_ORGANIZER)) {

                setRightDisplayItem((DisplayItem) i);
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

            if (n.isEqualTo(SplitPane.LEFT_ORGANIZER)) {

                removeLeftDisplayItem((DisplayItem) getChild(n));
            
            } else if (n.isEqualTo(SplitPane.RIGHT_ORGANIZER)) {

                removeRightDisplayItem((DisplayItem) getChild(n));
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
    // Default children.
    //

    /**
     * Returns the left organizer.
     *
     * @return the left organizer
     */
    public String getDefaultLeftDisplayItem() {

        return new String("cybop.core.screen.region.Panel");
    }

    /**
     * Returns the right organizer.
     *
     * @return the right organizer
     */
    public String getDefaultRightDisplayItem() {

        return new String("cybop.core.screen.region.Panel");
    }

    //
    // Left organizer.
    //

    /**
     * Sets the left organizer.
     *
     * @param c the left organizer
     * @exception Exception if the java split pane is null
     * @exception Exception if the left organizer is null
     */
    public void setLeftDisplayItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setLeftComponent((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set left organizer. The left organizer is null.");
            }

        } else {

            throw new Exception("Could not set left organizer. The java split pane is null.");
        }
    }

    /**
     * Removes the left organizer.
     *
     * @param c the left organizer
     * @exception Exception if the java split pane is null
     * @exception Exception if the left organizer is null
     */
    public void removeLeftDisplayItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.remove((java.awt.Component) c.getJavaObject());

            } else {

                throw new Exception("Could not remove left organizer. The left organizer is null.");
            }

        } else {

            throw new Exception("Could not remove left organizer. The java split pane is null.");
        }
    }

    //
    // Right organizer.
    //

    /**
     * Sets the right organizer.
     *
     * @param c the right organizer
     * @exception Exception if the java split pane is null
     * @exception Exception if the right organizer is null
     */
    public void setRightDisplayItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setRightComponent((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not set right organizer. The right organizer is null.");
            }

        } else {

            throw new Exception("Could not set right organizer. The java split pane is null.");
        }
    }

    /**
     * Removes the right organizer.
     *
     * @param c the right organizer
     * @exception Exception if the java split pane is null
     * @exception Exception if the right organizer is null
     */
    public void removeRightDisplayItem(DisplayItem c) throws Exception {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.remove((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new Exception("Could not remove right organizer. The right organizer is null.");
            }

        } else {

            throw new Exception("Could not remove right organizer. The java split pane is null.");
        }
    }

    //
    // Initializable.
    //

    /**
     * Initializes this split pane.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(SplitPane.LEFT_ORGANIZER, createChild(getDefaultLeftDisplayItem()));
        setChild(SplitPane.RIGHT_ORGANIZER, createChild(getDefaultRightDisplayItem()));
    }

    /**
     * Finalizes this split pane.
     */
    public void finalizz() throws Exception {

        DisplayItem rightDisplayItem = (DisplayItem) getChild(SplitPane.RIGHT_ORGANIZER);
        removeChild(SplitPane.RIGHT_ORGANIZER);
        destroyChild(rightDisplayItem);

        DisplayItem leftDisplayItem = (DisplayItem) getChild(SplitPane.LEFT_ORGANIZER);
        removeChild(SplitPane.LEFT_ORGANIZER);
        destroyChild(leftDisplayItem);

        super.finalizz();
    }
}

