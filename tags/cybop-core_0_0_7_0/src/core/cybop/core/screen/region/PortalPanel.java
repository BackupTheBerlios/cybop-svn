/*
 * $RCSfile: PortalPanel.java,v $
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
import cybop.core.screen.region.splitpane.*;

/**
 * This class represents a portal panel.
 *
 * @version $Revision: 1.9 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalPanel extends Panel {

    //
    // Children names.
    //

    /** The portal split pane. */
    public static final String PORTAL_SPLIT_PANE = new String("portal_split_pane");

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

            if (n.isEqualTo(PortalPanel.PORTAL_SPLIT_PANE)) {

                setPortalSplitPane((PortalSplitPane) i);
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

            if (n.isEqualTo(PortalPanel.PORTAL_SPLIT_PANE)) {

                removePortalSplitPane((PortalSplitPane) getChild(n));
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
        
        super.removeChild(n);
    }

    //
    // Default categories.
    //

    /**
     * Returns the default portal split pane category.
     *
     * @return the default portal split pane category
     */
    public Item getDefaultPortalSplitPaneCategory() {

        return new String("cybop.core.screen.region.splitpane.PortalSplitPane");
    }

    //
    // Portal split pane.
    //

    /**
     * Sets the portal split pane.
     *
     * @param sp the portal split pane
     * @exception Exception if the java panel is null
     * @exception Exception if the portal split pane is null
     */
    public void setPortalSplitPane(PortalSplitPane sp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (sp != null) {

                p.add((javax.swing.JSplitPane) sp.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {
    
                throw new Exception("Could not set portal split pane. The portal split pane is null.");
            }

        } else {

            throw new Exception("Could not set portal split pane. The java panel is null.");
        }
    }

    /**
     * Removes the portal split pane.
     *
     * @param sp the portal split pane
     * @exception Exception if the java panel is null
     * @exception Exception if the portal split pane is null
     */
    public void removePortalSplitPane(PortalSplitPane sp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (sp != null) {

                p.remove((javax.swing.JSplitPane) sp.getJavaObject());

            } else {
    
                throw new Exception("Could not remove portal split pane. The portal split pane is null.");
            }

        } else {

            throw new Exception("Could not remove portal split pane. The java panel is null.");
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

        setCategory(PortalPanel.PORTAL_SPLIT_PANE, getDefaultPortalSplitPaneCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(PortalPanel.PORTAL_SPLIT_PANE);

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

        setChild(PortalPanel.PORTAL_SPLIT_PANE, createChild(getCategory(PortalPanel.PORTAL_SPLIT_PANE)));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item portalSplitPane = getChild(PortalPanel.PORTAL_SPLIT_PANE);
        removeChild(PortalPanel.PORTAL_SPLIT_PANE);
        destroyChild(portalSplitPane);

        super.finalizz();
    }
}

