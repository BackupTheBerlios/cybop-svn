/*
 * $RCSfile: Button.java,v $
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
 * but WITHOUT ANY WARRANTY; without even the ied warranty of
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

package cybop.core.screen.component;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.screen.*;

/**
 * This class represents a button.
 *
 * @version $Revision: 1.5 $ $Date: 2003-06-17 08:21:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Button extends DisplayComponent {

    //
    // Children names.
    //

    /** The label. */
    public static final String LABEL = new String("label");

    /** The mnemonic. */
    public static final String MNEMONIC = new String("mnemonic");

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

            if (n.isEqualTo(Button.LABEL)) {

                setLabel((String) i);

            } else if (n.isEqualTo(Button.MNEMONIC)) {

                setMnemonic((Integer) i);
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

            if (n.isEqualTo(Button.LABEL)) {

                removeLabel((String) getChild(n));

            } else if (n.isEqualTo(Button.MNEMONIC)) {

                removeMnemonic((Integer) getChild(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }

        super.removeChild(n);
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

        return null;
    }

    /**
     * Returns the default mnemonic.
     *
     * @return the default mnemonic
     */
    public Integer getDefaultMnemonic() {

        return null;
    }

    //
    // Label.
    //

    /**
     * Sets the label.
     *
     * @param l the label
     * @exception Exception if the java menu item is null
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

            throw new Exception("Could not set label. The java menu item is null.");
        }
    }

    /**
     * Removes the label.
     *
     * @param l the label
     * @exception Exception if the java menu item is null
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

            throw new Exception("Could not remove label. The java menu item is null.");
        }
    }

    //
    // Mnemonic.
    //

    /**
     * Sets the mnemonic.
     *
     * @param m the mnemonic
     * @exception Exception if the java menu item is null
     * @exception Exception if the mnemonic is null
     * @exception Exception if the mnemonic java object is null
     */
    public void setMnemonic(Integer m) throws Exception {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (m != null) {

                java.lang.Integer i = (java.lang.Integer) m.getJavaObject();

                if (i != null) {
                    
                    b.setMnemonic(i.intValue());

                } else {
        
                    throw new Exception("Could not set mnemonic. The mnemonic java object is null.");
                }

            } else {
    
                throw new Exception("Could not set mnemonic. The mnemonic is null.");
            }

        } else {

            throw new Exception("Could not set mnemonic. The java menu item is null.");
        }
    }

    /**
     * Removes the mnemonic.
     *
     * @param m the mnemonic
     * @exception Exception if the java menu item is null
     * @exception Exception if the mnemonic is null
     * @exception Exception if the mnemonic java object is null
     */
    public void removeMnemonic(Integer m) throws Exception {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (m != null) {

                java.lang.Integer i = (java.lang.Integer) m.getJavaObject();

                if (i != null) {
                    
                    b.setMnemonic(0);

                } else {
        
                    throw new Exception("Could not set mnemonic. The mnemonic java object is null.");
                }

            } else {
    
                throw new Exception("Could not remove mnemonic. The mnemonic is null.");
            }

        } else {

            throw new Exception("Could not remove mnemonic. The java menu item is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this button.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(Button.LABEL, getDefaultLabel());
        setChild(Button.MNEMONIC, getDefaultMnemonic());
    }

    /**
     * Finalizes this button.
     */
    public void finalizz() throws Exception {

        Integer mnemonic = (Integer) getChild(Button.MNEMONIC);
        removeChild(Button.MNEMONIC);
        destroyChild(mnemonic);

        String label = (String) getChild(Button.LABEL);
        removeChild(Button.LABEL);
        destroyChild(label);

        super.finalizz();
    }
}

