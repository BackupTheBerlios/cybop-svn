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
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalContentsPanel extends ContentsPanel {

    //
    // Children.
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
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(PortalContentsPanel.PORTAL_SPLIT_PANE)) {

                setPortalSplitPane((PortalSplitPane) i);
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

            if (n.isEqualTo(PortalContentsPanel.PORTAL_SPLIT_PANE)) {

                removePortalSplitPane((PortalSplitPane) get(n));
            }

        } else {

            throw new NullPointerException("Could not set item. The name is null.");
        }
        
        super.remove(n);
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
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the portal split pane is null
     */
    public void setPortalSplitPane(PortalSplitPane sp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (sp != null) {

                p.add((javax.swing.JSplitPane) sp.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {
    
                throw new NullPointerException("Could not set portal split pane. The portal split pane is null.");
            }

        } else {

            throw new NullPointerException("Could not set portal split pane. The java panel is null.");
        }
    }

    /**
     * Removes the portal split pane.
     *
     * @param sp the portal split pane
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the portal split pane is null
     */
    public void removePortalSplitPane(PortalSplitPane sp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (sp != null) {

                p.remove((javax.swing.JSplitPane) sp.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove portal split pane. The portal split pane is null.");
            }

        } else {

            throw new NullPointerException("Could not remove portal split pane. The java panel is null.");
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

        set(PortalContentsPanel.PORTAL_SPLIT_PANE, createComponent(getDefaultPortalSplitPane()));
    }

    /**
     * Finalizes this portal contents panel.
     */
    public void finalizz() throws Exception {

        PortalSplitPane portalSplitPane = (PortalSplitPane) get(PortalContentsPanel.PORTAL_SPLIT_PANE);
        remove(PortalContentsPanel.PORTAL_SPLIT_PANE);
        destroyComponent(portalSplitPane);

        super.finalizz();
    }
}

