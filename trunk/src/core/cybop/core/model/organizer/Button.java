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

package cybop.core.model.organizer;

import cybop.core.basic.*;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a button.
 *
 * @version $Revision: 1.7 $ $Date: 2003-04-24 15:58:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Button extends Organizer {

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
     * @exception NullPointerException if the name is null
     */
    public void setChildItem(String n, Item i) throws NullPointerException {

        super.setChildItem(n, i);

        if (n != null) {

            if (n.isEqualTo(Button.LABEL)) {

                setLabel((String) i);

            } else if (n.isEqualTo(Button.MNEMONIC)) {

                setMnemonic((Integer) i);
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
    public void removeChildItem(String n) throws NullPointerException {

        if (n != null) {

            if (n.isEqualTo(Button.LABEL)) {

                removeLabel((String) getChildItem(n));

            } else if (n.isEqualTo(Button.MNEMONIC)) {

                removeMnemonic((Integer) getChildItem(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
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
     * @exception NullPointerException if the java menu item is null
     * @exception NullPointerException if the label is null
     */
    public void setLabel(String l) throws NullPointerException {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (l != null) {

                b.setText((java.lang.String) l.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set label. The label is null.");
            }

        } else {

            throw new NullPointerException("Could not set label. The java menu item is null.");
        }
    }

    /**
     * Removes the label.
     *
     * @param l the label
     * @exception NullPointerException if the java menu item is null
     * @exception NullPointerException if the label is null
     */
    public void removeLabel(String l) throws NullPointerException {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (l != null) {

                b.setText(null);

            } else {
    
                throw new NullPointerException("Could not remove label. The label is null.");
            }

        } else {

            throw new NullPointerException("Could not remove label. The java menu item is null.");
        }
    }

    //
    // Mnemonic.
    //

    /**
     * Sets the mnemonic.
     *
     * @param m the mnemonic
     * @exception NullPointerException if the java menu item is null
     * @exception NullPointerException if the mnemonic is null
     * @exception NullPointerException if the mnemonic java object is null
     */
    public void setMnemonic(Integer m) throws NullPointerException {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (m != null) {

                java.lang.Integer i = (java.lang.Integer) m.getJavaObject();

                if (i != null) {
                    
                    b.setMnemonic(i.intValue());

                } else {
        
                    throw new NullPointerException("Could not set mnemonic. The mnemonic java object is null.");
                }

            } else {
    
                throw new NullPointerException("Could not set mnemonic. The mnemonic is null.");
            }

        } else {

            throw new NullPointerException("Could not set mnemonic. The java menu item is null.");
        }
    }

    /**
     * Removes the mnemonic.
     *
     * @param m the mnemonic
     * @exception NullPointerException if the java menu item is null
     * @exception NullPointerException if the mnemonic is null
     * @exception NullPointerException if the mnemonic java object is null
     */
    public void removeMnemonic(Integer m) throws NullPointerException {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (m != null) {

                java.lang.Integer i = (java.lang.Integer) m.getJavaObject();

                if (i != null) {
                    
                    b.setMnemonic(0);

                } else {
        
                    throw new NullPointerException("Could not set mnemonic. The mnemonic java object is null.");
                }

            } else {
    
                throw new NullPointerException("Could not remove mnemonic. The mnemonic is null.");
            }

        } else {

            throw new NullPointerException("Could not remove mnemonic. The java menu item is null.");
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

        setChildItem(Button.LABEL, getDefaultLabel());
        setChildItem(Button.MNEMONIC, getDefaultMnemonic());
    }

    /**
     * Finalizes this button.
     */
    public void finalizz() throws Exception {

        Integer mnemonic = (Integer) getChildItem(Button.MNEMONIC);
        removeChildItem(Button.MNEMONIC);
        destroyChildItem(mnemonic);

        String label = (String) getChildItem(Button.LABEL);
        removeChildItem(Button.LABEL);
        destroyChildItem(label);

        super.finalizz();
    }
}

