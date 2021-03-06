/*
 * $RCSfile: ButtonPanel.java,v $
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
import cybop.core.screen.component.button.*;

/**
 * This class represents a button panel.
 *
 * @version $Revision: 1.7 $ $Date: 2003-06-20 11:32:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class ButtonPanel extends Panel {

    //
    // Children names.
    //

    /** The ok button. */
    public static final String OK_BUTTON = new String("ok_button");

    /** The cancel button. */
    public static final String CANCEL_BUTTON = new String("cancel_button");

    /** The yes button. */
    public static final String YES_BUTTON = new String("yes_button");

    /** The no button. */
    public static final String NO_BUTTON = new String("no_button");

    /** The apply button. */
    public static final String APPLY_BUTTON = new String("apply_button");

    /** The reset button. */
    public static final String RESET_BUTTON = new String("reset_button");

    /** The help button. */
    public static final String HELP_BUTTON = new String("help_button");

    /** The close button. */
    public static final String CLOSE_BUTTON = new String("close_button");

    //
    // Encapsulated java swing panel.
    //

    /**
     * Creates the encapsulated java swing panel.
     *
     * @return the encapsulated java swing panel
     * @exception Exception if the java swing panel is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        javax.swing.JPanel p = new javax.swing.JPanel();

        if (p != null) {
            
            p.setBorder(javax.swing.BorderFactory.createEmptyBorder(10, 10, 10, 10));

        } else {

            throw new Exception("Could not create java swing panel. The java swing panel is null.");
        }

        return p; 
    }

    /**
     * Destroys the encapsulated java swing panel.
     *
     * @param o the encapsulated java swing panel
     */
    public void destroyJavaObject(java.lang.Object o) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) o;

        if (p != null) {
            
            p.setBorder(null);

        } else {

            throw new Exception("Could not destroy java swing panel. The java swing panel is null.");
        }
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

            if (n.isEqualTo(ButtonPanel.OK_BUTTON)) {

                setOkButton((OkButton) i);

            } else if (n.isEqualTo(ButtonPanel.CANCEL_BUTTON)) {

                setCancelButton((CancelButton) i);
            
            } else if (n.isEqualTo(ButtonPanel.YES_BUTTON)) {

                setYesButton((YesButton) i);
            
            } else if (n.isEqualTo(ButtonPanel.NO_BUTTON)) {

                setNoButton((NoButton) i);
            
            } else if (n.isEqualTo(ButtonPanel.APPLY_BUTTON)) {

                setApplyButton((ApplyButton) i);
            
            } else if (n.isEqualTo(ButtonPanel.RESET_BUTTON)) {

                setResetButton((ResetButton) i);
            
            } else if (n.isEqualTo(ButtonPanel.HELP_BUTTON)) {

                setHelpButton((HelpButton) i);
            
            } else if (n.isEqualTo(ButtonPanel.CLOSE_BUTTON)) {

                setCloseButton((CloseButton) i);
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

            if (n.isEqualTo(ButtonPanel.OK_BUTTON)) {

                removeOkButton((OkButton) getChild(n));

            } else if (n.isEqualTo(ButtonPanel.CANCEL_BUTTON)) {

                removeCancelButton((CancelButton) getChild(n));
            
            } else if (n.isEqualTo(ButtonPanel.YES_BUTTON)) {

                removeYesButton((YesButton) getChild(n));
            
            } else if (n.isEqualTo(ButtonPanel.NO_BUTTON)) {

                removeNoButton((NoButton) getChild(n));
            
            } else if (n.isEqualTo(ButtonPanel.APPLY_BUTTON)) {

                removeApplyButton((ApplyButton) getChild(n));
            
            } else if (n.isEqualTo(ButtonPanel.RESET_BUTTON)) {

                removeResetButton((ResetButton) getChild(n));
            
            } else if (n.isEqualTo(ButtonPanel.HELP_BUTTON)) {

                removeHelpButton((HelpButton) getChild(n));

            } else if (n.isEqualTo(ButtonPanel.CLOSE_BUTTON)) {

                removeCloseButton((CloseButton) getChild(n));
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
     * Returns the default ok button.
     *
     * @return the default ok button
     */
    public String getDefaultOkButton() {

        return null;
    }

    /**
     * Returns the default cancel button.
     *
     * @return the default cancel button
     */
    public String getDefaultCancelButton() {

        return null;
    }

    /**
     * Returns the default yes button.
     *
     * @return the default yes button
     */
    public String getDefaultYesButton() {

        return null;
    }

    /**
     * Returns the default no button.
     *
     * @return the default no button
     */
    public String getDefaultNoButton() {

        return null;
    }

    /**
     * Returns the default apply button.
     *
     * @return the default apply button
     */
    public String getDefaultApplyButton() {

        return null;
    }

    /**
     * Returns the default reset button.
     *
     * @return the default reset button
     */
    public String getDefaultResetButton() {

        return null;
    }

    /**
     * Returns the default help button.
     *
     * @return the default help button
     */
    public String getDefaultHelpButton() {

        return null;
    }

    /**
     * Returns the default close button.
     *
     * @return the default close button
     */
    public String getDefaultCloseButton() {

        return null;
    }

    //
    // Ok button.
    //

    /**
     * Sets the ok button.
     *
     * @param b the ok button
     * @exception Exception if the java panel is null
     * @exception Exception if the ok button is null
     */
    public void setOkButton(OkButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set ok button. The ok button is null.");
            }

        } else {

            throw new Exception("Could not set ok button. The java panel is null.");
        }
    }

    /**
     * Removes the ok button.
     *
     * @param b the ok button
     * @exception Exception if the java panel is null
     * @exception Exception if the ok button is null
     */
    public void removeOkButton(OkButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove ok button. The ok button is null.");
            }

        } else {

            throw new Exception("Could not remove ok button. The java panel is null.");
        }
    }

    //
    // Cancel button.
    //

    /**
     * Sets the cancel button.
     *
     * @param b the cancel button
     * @exception Exception if the java panel is null
     * @exception Exception if the cancel button is null
     */
    public void setCancelButton(CancelButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {
    
                java.lang.System.out.println("DEBUG: Could not set cancel button. The cancel button is null.");
            }

        } else {

            throw new Exception("Could not set cancel button. The java panel is null.");
        }
    }

    /**
     * Removes the cancel button.
     *
     * @param b the cancel button
     * @exception Exception if the java panel is null
     * @exception Exception if the cancel button is null
     */
    public void removeCancelButton(CancelButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {
    
                java.lang.System.out.println("DEBUG: Could not remove cancel button. The cancel button is null.");
            }

        } else {

            throw new Exception("Could not remove cancel button. The java panel is null.");
        }
    }

    //
    // Yes button.
    //

    /**
     * Sets the yes button.
     *
     * @param b the yes button
     * @exception Exception if the java panel is null
     * @exception Exception if the yes button is null
     */
    public void setYesButton(YesButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {
    
                java.lang.System.out.println("DEBUG: Could not set yes button. The yes button is null.");
            }

        } else {

            throw new Exception("Could not set yes button. The java panel is null.");
        }
    }

    /**
     * Removes the yes button.
     *
     * @param b the yes button
     * @exception Exception if the java panel is null
     * @exception Exception if the yes button is null
     */
    public void removeYesButton(YesButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove yes button. The yes button is null.");
            }

        } else {

            throw new Exception("Could not remove yes button. The java panel is null.");
        }
    }

    //
    // No button.
    //

    /**
     * Sets the no button.
     *
     * @param b the no button
     * @exception Exception if the java panel is null
     * @exception Exception if the no button is null
     */
    public void setNoButton(NoButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set no button. The no button is null.");
            }

        } else {

            throw new Exception("Could not set no button. The java panel is null.");
        }
    }

    /**
     * Removes the no button.
     *
     * @param b the no button
     * @exception Exception if the java panel is null
     * @exception Exception if the no button is null
     */
    public void removeNoButton(NoButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove no button. The no button is null.");
            }

        } else {

            throw new Exception("Could not remove no button. The java panel is null.");
        }
    }

    //
    // Apply button.
    //

    /**
     * Sets the apply button.
     *
     * @param b the apply button
     * @exception Exception if the java panel is null
     * @exception Exception if the apply button is null
     */
    public void setApplyButton(ApplyButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set apply button. The apply button is null.");
            }

        } else {

            throw new Exception("Could not set apply button. The java panel is null.");
        }
    }

    /**
     * Removes the apply button.
     *
     * @param b the apply button
     * @exception Exception if the java panel is null
     * @exception Exception if the apply button is null
     */
    public void removeApplyButton(ApplyButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {
    
                java.lang.System.out.println("DEBUG: Could not remove apply button. The apply button is null.");
            }

        } else {

            throw new Exception("Could not remove apply button. The java panel is null.");
        }
    }

    //
    // Reset button.
    //

    /**
     * Sets the reset button.
     *
     * @param b the reset button
     * @exception Exception if the java panel is null
     * @exception Exception if the reset button is null
     */
    public void setResetButton(ResetButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set reset button. The reset button is null.");
            }

        } else {

            throw new Exception("Could not set reset button. The java panel is null.");
        }
    }

    /**
     * Removes the reset button.
     *
     * @param b the reset button
     * @exception Exception if the java panel is null
     * @exception Exception if the reset button is null
     */
    public void removeResetButton(ResetButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {
    
                java.lang.System.out.println("DEBUG: Could not remove reset button. The reset button is null.");
            }

        } else {

            throw new Exception("Could not remove reset button. The java panel is null.");
        }
    }

    //
    // Help button.
    //

    /**
     * Sets the help button.
     *
     * @param b the help button
     * @exception Exception if the java panel is null
     * @exception Exception if the help button is null
     */
    public void setHelpButton(HelpButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {
    
                java.lang.System.out.println("DEBUG: Could not set help button. The help button is null.");
            }

        } else {

            throw new Exception("Could not set help button. The java panel is null.");
        }
    }

    /**
     * Removes the help button.
     *
     * @param b the help button
     * @exception Exception if the java panel is null
     * @exception Exception if the help button is null
     */
    public void removeHelpButton(HelpButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove help button. The help button is null.");
            }

        } else {

            throw new Exception("Could not remove help button. The java panel is null.");
        }
    }

    //
    // Close button.
    //

    /**
     * Sets the close button.
     *
     * @param b the close button
     * @exception Exception if the java panel is null
     * @exception Exception if the close button is null
     */
    public void setCloseButton(CloseButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.add((javax.swing.JButton) b.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set close button. The close button is null.");
            }

        } else {

            throw new Exception("Could not set close button. The java panel is null.");
        }
    }

    /**
     * Removes the close button.
     *
     * @param b the close button
     * @exception Exception if the java panel is null
     * @exception Exception if the close button is null
     */
    public void removeCloseButton(CloseButton b) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (b != null) {

                p.remove((javax.swing.JButton) b.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove close button. The close button is null.");
            }

        } else {

            throw new Exception("Could not remove close button. The java panel is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this button panel.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(ButtonPanel.OK_BUTTON, createChild(getDefaultOkButton()));
        setChild(ButtonPanel.CANCEL_BUTTON, createChild(getDefaultCancelButton()));
        setChild(ButtonPanel.YES_BUTTON, createChild(getDefaultYesButton()));
        setChild(ButtonPanel.NO_BUTTON, createChild(getDefaultNoButton()));
        setChild(ButtonPanel.APPLY_BUTTON, createChild(getDefaultApplyButton()));
        setChild(ButtonPanel.RESET_BUTTON, createChild(getDefaultResetButton()));
        setChild(ButtonPanel.HELP_BUTTON, createChild(getDefaultHelpButton()));
        setChild(ButtonPanel.CLOSE_BUTTON, createChild(getDefaultCloseButton()));
    }

    /**
     * Finalizes this button panel.
     */
    public void finalizz() throws Exception {

        CloseButton closeButton = (CloseButton) getChild(ButtonPanel.CLOSE_BUTTON);
        removeChild(ButtonPanel.CLOSE_BUTTON);
        destroyChild(closeButton);

        HelpButton helpButton = (HelpButton) getChild(ButtonPanel.HELP_BUTTON);
        removeChild(ButtonPanel.HELP_BUTTON);
        destroyChild(helpButton);

        ResetButton resetButton = (ResetButton) getChild(ButtonPanel.RESET_BUTTON);
        removeChild(ButtonPanel.RESET_BUTTON);
        destroyChild(resetButton);

        ApplyButton applyButton = (ApplyButton) getChild(ButtonPanel.APPLY_BUTTON);
        removeChild(ButtonPanel.APPLY_BUTTON);
        destroyChild(applyButton);

        NoButton noButton = (NoButton) getChild(ButtonPanel.NO_BUTTON);
        removeChild(ButtonPanel.NO_BUTTON);
        destroyChild(noButton);

        YesButton yesButton = (YesButton) getChild(ButtonPanel.YES_BUTTON);
        removeChild(ButtonPanel.YES_BUTTON);
        destroyChild(yesButton);

        CancelButton cancelButton = (CancelButton) getChild(ButtonPanel.CANCEL_BUTTON);
        removeChild(ButtonPanel.CANCEL_BUTTON);
        destroyChild(cancelButton);

        OkButton okButton = (OkButton) getChild(ButtonPanel.OK_BUTTON);
        removeChild(ButtonPanel.OK_BUTTON);
        destroyChild(okButton);

        super.finalizz();
    }
}

