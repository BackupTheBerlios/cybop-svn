/*
 * $RCSfile: PortalContentsPanel.java,v $
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

/**
 * This class represents a portal contents panel.
 *
 * @version $Revision: 1.7 $ $Date: 2003-05-17 22:30:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalContentsPanel extends ContentsPanel {

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
    public void setChildItem(String n, Item i) throws Exception {

        super.setChildItem(n, i);

        if (n != null) {

            if (n.isEqualTo(PortalContentsPanel.PORTAL_SPLIT_PANE)) {

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
    public void removeChildItem(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(PortalContentsPanel.PORTAL_SPLIT_PANE)) {

                removePortalSplitPane((PortalSplitPane) getChildItem(n));
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
        
        super.removeChildItem(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default portal split pane.
     *
     * @return the default portal split pane
     */
    public String getDefaultPortalSplitPane() {

        return new String("cybop.core.model.organizer.PortalSplitPane");
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
    // Initializable.
    //

    /**
     * Initializes this portal contents panel.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChildItem(PortalContentsPanel.PORTAL_SPLIT_PANE, createChildItem(getDefaultPortalSplitPane()));
    }

    /**
     * Finalizes this portal contents panel.
     */
    public void finalizz() throws Exception {

        PortalSplitPane portalSplitPane = (PortalSplitPane) getChildItem(PortalContentsPanel.PORTAL_SPLIT_PANE);
        removeChildItem(PortalContentsPanel.PORTAL_SPLIT_PANE);
        destroyChildItem(portalSplitPane);

        super.finalizz();
    }
}

