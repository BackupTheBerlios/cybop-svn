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
 * @version $Revision: 1.4 $ $Date: 2003-03-12 18:12:20 $ $Author: christian $
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

    /** The action. */
    public static final String ACTION = new String("action");

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

            if (n.isEqualTo(Button.LABEL)) {

                setLabel((String) i);

            } else if (n.isEqualTo(Button.MNEMONIC)) {

                setMnemonic((Integer) i);

            } else if (n.isEqualTo(Button.ACTION)) {

                setAction((String) i);
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

            if (n.isEqualTo(Button.LABEL)) {

                removeLabel((String) get(n));

            } else if (n.isEqualTo(Button.MNEMONIC)) {

                removeMnemonic((Integer) get(n));

            } else if (n.isEqualTo(Button.ACTION)) {

                removeAction((String) get(n));
            }

        } else {

            throw new NullPointerException("Could not remove item. The name is null.");
        }

        super.remove(n);
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

    /**
     * Returns the default action.
     *
     * @return the default action
     */
    public String getDefaultAction() {

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
    // Action.
    //
    
    /**
     * Sets the action.
     *
     * @param a the action
     * @exception NullPointerException if the java menu item is null
     * @exception NullPointerException if the action is null
     */
    public void setAction(String a) throws NullPointerException {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            if (a != null) {

                b.setActionCommand((java.lang.String) a.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not set action. The action is null.");
            }

        } else {

            throw new NullPointerException("Could not set action. The java menu item is null.");
        }
    }

    /**
     * Removes the action.
     *
     * @param a the action
     * @exception NullPointerException if the java menu item is null
     */
    public void removeAction(String a) throws NullPointerException {

        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            b.setActionCommand(null);

        } else {

            throw new NullPointerException("Could not remove action. The java menu item is null.");
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

        set(Button.LABEL, getDefaultLabel());
        set(Button.MNEMONIC, getDefaultMnemonic());
        set(Button.ACTION, getDefaultAction());

        //?? Add java awt/swing action listener.
        //?? Has to be done here (and not in createJavaObject) because the signal handler
        //?? (action listener) has to be forwarded in the globalize method first.
        //?? Remove this part as soon as CYBOP supports mouse/keyboard input handling.
        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            b.addActionListener((cybop.core.system.family.Launcher) getSignalHandler());

        } else {

            throw new NullPointerException("Could not create encapsulated java swing abstract button. The encapsulated java swing abstract button is null.");
        }
    }

    /**
     * Finalizes this button.
     */
    public void finalizz() throws Exception {

        //?? Remove java awt/swing action listener.
        //?? Has to be done here (and not in createJavaObject) because the signal handler
        //?? (action listener) has to be forwarded in the globalize method first.
        //?? Remove this part as soon as CYBOP supports mouse/keyboard input handling.
        javax.swing.AbstractButton b = (javax.swing.AbstractButton) getJavaObject();

        if (b != null) {

            b.removeActionListener((cybop.core.system.family.Launcher) getSignalHandler());

        } else {

            throw new NullPointerException("Could not destroy encapsulated java swing abstract button. The encapsulated java swing abstract button is null.");
        }

        String action = (String) get(Button.ACTION);
        remove(Button.ACTION);
        destroyItem(action);

        Integer mnemonic = (Integer) get(Button.MNEMONIC);
        remove(Button.MNEMONIC);
        destroyItem(mnemonic);

        String label = (String) get(Button.LABEL);
        remove(Button.LABEL);
        destroyItem(label);

        super.finalizz();
    }
}

