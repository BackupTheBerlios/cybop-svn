/*
 * $RCSfile: Menu.java,v $
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
import cybop.core.basic.Boolean;
import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a menu.
 *
 * @version $Revision: 1.6 $ $Date: 2003-05-17 22:30:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Menu extends Organizer {

    //
    // Children names.
    //

    /** The label. */
    public static final String LABEL = new String("label");

    //
    // Encapsulated java swing menu.
    //

    /**
     * Creates an encapsulated java swing menu.
     *
     * @return the encapsulated java swing menu
     * @exception Exception if the encapsulated java swing menu is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JMenu m = new javax.swing.JMenu();

        if (m != null) {

            m.setEnabled(Boolean.TRUE);

        } else {

            throw new Exception("Could not create encapsulated java swing menu. The encapsulated java swing menu is null.");
        }

        return m;
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

            if (n.isEqualTo(Menu.LABEL)) {

                setLabel((String) i);
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

            if (n.isEqualTo(Menu.LABEL)) {

                removeLabel((String) getChildItem(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }
        
        super.removeChildItem(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default label.
     *
     * @return the default label
     */
    public String getDefaultLabel() {

        return new String("Menu");
    }

    //
    // Label.
    //

    /**
     * Sets the label.
     *
     * @param l the label
     * @exception Exception if the java abstract button is null
     * @exception Exception if the label is null
     */
    public void setLabel(String l) throws Exception {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (l != null) {

                b.setText((java.lang.String) l.getJavaObject());

            } else {
    
                throw new Exception("Could not set label. The label is null.");
            }

        } else {

            throw new Exception("Could not set label. The java abstract button is null.");
        }
    }

    /**
     * Removes the label.
     *
     * @param l the label
     * @exception Exception if the java abstract button is null
     * @exception Exception if the label is null
     */
    public void removeLabel(String l) throws Exception {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (l != null) {

                b.setText(null);

            } else {
    
                throw new Exception("Could not remove label. The label is null.");
            }

        } else {

            throw new Exception("Could not remove label. The java abstract button is null.");
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

        setChildItem(Menu.LABEL, getDefaultLabel());
    }

    /**
     * Finalizes this split pane.
     */
    public void finalizz() throws Exception {

        String label = (String) getChildItem(Menu.LABEL);
        removeChildItem(Menu.LABEL);
//??            destroyLabel(label);

        super.finalizz();
    }
}

