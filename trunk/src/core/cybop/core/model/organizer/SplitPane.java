/*
 * $RCSfile: SplitPane.java,v $
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
 * This class represents a split pane.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SplitPane extends Organizer {

    //
    // Children.
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
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(SplitPane.LEFT_ORGANIZER)) {

                setLeftOrganizer((Organizer) i);

            } else if (n.isEqualTo(SplitPane.RIGHT_ORGANIZER)) {

                setRightOrganizer((Organizer) i);
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

            if (n.isEqualTo(SplitPane.LEFT_ORGANIZER)) {

                removeLeftOrganizer((Organizer) get(n));
            
            } else if (n.isEqualTo(SplitPane.RIGHT_ORGANIZER)) {

                removeRightOrganizer((Organizer) get(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
        }

        super.remove(n);
    }

    //
    // Encapsulated java swing split pane.
    //
    
    /**
     * Creates an encapsulated java swing split pane.
     *
     * @return the encapsulated java swing split pane
     * @exception NullPointerException if the encapsulated java swing split pane is null
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        javax.swing.JSplitPane sp = new javax.swing.JSplitPane();

        if (sp != null) {

            sp.setOrientation(javax.swing.JSplitPane.HORIZONTAL_SPLIT);
            sp.setOneTouchExpandable(true);
            sp.setContinuousLayout(true);
            sp.setDividerLocation(200);
            sp.setPreferredSize(new java.awt.Dimension(800, 600));

        } else {

            throw new NullPointerException("Could not create encapsulated java swing split pane. The encapsulated java swing split pane is null.");
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
    public String getDefaultLeftOrganizer() {

        return new String("cybop.model.organizer.Panel");
    }

    /**
     * Returns the right organizer.
     *
     * @return the right organizer
     */
    public String getDefaultRightOrganizer() {

        return new String("cybop.model.organizer.Panel");
    }

    //
    // Left organizer.
    //

    /**
     * Sets the left organizer.
     *
     * @param c the left organizer
     * @exception NullPointerException if the java split pane is null
     * @exception NullPointerException if the left organizer is null
     */
    public void setLeftOrganizer(Organizer c) throws NullPointerException {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setLeftComponent((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set left organizer. The left organizer is null.");
            }

        } else {

            throw new NullPointerException("Could not set left organizer. The java split pane is null.");
        }
    }

    /**
     * Removes the left organizer.
     *
     * @param c the left organizer
     * @exception NullPointerException if the java split pane is null
     * @exception NullPointerException if the left organizer is null
     */
    public void removeLeftOrganizer(Organizer c) throws NullPointerException {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.remove((java.awt.Component) c.getJavaObject());

            } else {

                throw new NullPointerException("Could not remove left organizer. The left organizer is null.");
            }

        } else {

            throw new NullPointerException("Could not remove left organizer. The java split pane is null.");
        }
    }

    //
    // Right organizer.
    //

    /**
     * Sets the right organizer.
     *
     * @param c the right organizer
     * @exception NullPointerException if the java split pane is null
     * @exception NullPointerException if the right organizer is null
     */
    public void setRightOrganizer(Organizer c) throws NullPointerException {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.setRightComponent((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set right organizer. The right organizer is null.");
            }

        } else {

            throw new NullPointerException("Could not set right organizer. The java split pane is null.");
        }
    }

    /**
     * Removes the right organizer.
     *
     * @param c the right organizer
     * @exception NullPointerException if the java split pane is null
     * @exception NullPointerException if the right organizer is null
     */
    public void removeRightOrganizer(Organizer c) throws NullPointerException {

        javax.swing.JSplitPane sp = (javax.swing.JSplitPane) getJavaObject();

        if (sp != null) {

            if (c != null) {

                sp.remove((java.awt.Component) c.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove right organizer. The right organizer is null.");
            }

        } else {

            throw new NullPointerException("Could not remove right organizer. The java split pane is null.");
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

        set(SplitPane.LEFT_ORGANIZER, createItem(getDefaultLeftOrganizer()));
        set(SplitPane.RIGHT_ORGANIZER, createItem(getDefaultRightOrganizer()));
    }

    /**
     * Finalizes this split pane.
     */
    public void finalizz() throws Exception {

        Organizer rightOrganizer = (Organizer) get(SplitPane.RIGHT_ORGANIZER);
        remove(SplitPane.RIGHT_ORGANIZER);
        destroyItem(rightOrganizer);

        Organizer leftOrganizer = (Organizer) get(SplitPane.LEFT_ORGANIZER);
        remove(SplitPane.LEFT_ORGANIZER);
        destroyItem(leftOrganizer);

        super.finalizz();
    }
}

