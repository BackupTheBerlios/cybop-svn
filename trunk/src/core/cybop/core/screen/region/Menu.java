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

package cybop.core.screen.region;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.String;
import cybop.core.screen.*;

/**
 * This class represents a menu.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-20 13:44:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Menu extends DisplayRegion {

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
    public void setChild(String n, Item i) throws Exception {

        super.setChild(n, i);

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
    public void removeChild(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(Menu.LABEL)) {

                removeLabel((String) getChild(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }
        
        super.removeChild(n);
    }

    //
    // Default categories.
    //

    /**
     * Returns the default label category.
     *
     * @return the default label category
     */
    public Item getDefaultLabelCategory() {

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
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(Menu.LABEL, getDefaultLabelCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(Menu.LABEL);

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

        setChild(Menu.LABEL, (String) getCategory(Menu.LABEL));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item label = getChild(Menu.LABEL);
        removeChild(Menu.LABEL);
        destroyChild(label);

        super.finalizz();
    }
}

