/*
 * $RCSfile: SystemInformationContentsPanel.java,v $
 *
 * Copyright (c) 1999-2003. The Res Medicinae developers. All rights reserved.
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

/**
 * This class represents a system information contents panel.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformationContentsPanel extends ContentsPanel {

    //
    // Children.
    //

    /** The head panel. */
    public static final String HEAD_PANEL = new String("head_panel");

    /** The tabbed pane. */
    public static final String TABBED_PANE = new String("tabbed_pane");

    /** The button panel. */
    public static final String BUTTON_PANEL = new String("button_panel");

    //
    // Encapsulated java swing panel.
    //
    
    /**
     * Creates the encapsulated java swing panel.
     *
     * @return the encapsulated java swing panel
     * @exception NullPointerException if the java swing panel is null
     */
    public java.lang.Object createJavaObject() throws NullPointerException {

        javax.swing.JPanel p = new javax.swing.JPanel();

        if (p != null) {
            
            p.setBorder(javax.swing.BorderFactory.createEmptyBorder(10, 10, 10, 10));

        } else {

            throw new NullPointerException("Could not create java swing panel. The java swing panel is null.");
        }

        return p; 
    }

    /**
     * Destroys the encapsulated java swing panel.
     *
     * @param o the encapsulated java swing panel
     */
    public void destroyJavaObject(java.lang.Object o) {

        javax.swing.JPanel p = (javax.swing.JPanel) o;

        if (p != null) {
            
            p.setBorder(null);

        } else {

            throw new NullPointerException("Could not destroy java swing panel. The java swing panel is null.");
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
     * @exception NullPointerException if the name is null
     */
    public void set(String n, Item i) throws NullPointerException {

        super.set(n, i);

        if (n != null) {

            if (n.isEqualTo(SystemInformationContentsPanel.HEAD_PANEL)) {

                setHeadPanel((HeadPanel) i);

            } else if (n.isEqualTo(SystemInformationContentsPanel.TABBED_PANE)) {

                setTabbedPane((TabbedPane) i);
            
            } else if (n.isEqualTo(SystemInformationContentsPanel.BUTTON_PANEL)) {

                setButtonPanel((ButtonPanel) i);
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

            if (n.isEqualTo(SystemInformationContentsPanel.HEAD_PANEL)) {

                removeHeadPanel((HeadPanel) get(n));

            } else if (n.isEqualTo(SystemInformationContentsPanel.TABBED_PANE)) {

                removeTabbedPane((TabbedPane) get(n));
            
            } else if (n.isEqualTo(SystemInformationContentsPanel.BUTTON_PANEL)) {

                removeButtonPanel((ButtonPanel) get(n));
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
     * Returns the default head panel.
     *
     * @return the default head panel
     */
    public String getDefaultHeadPanel() {

        return new String("cybop.model.organizer.HeadPanel");
    }

    /**
     * Returns the default tabbed pane.
     *
     * @return the default tabbed pane
     */
    public String getDefaultTabbedPane() {

        return new String("cybop.model.organizer.TabbedPane");
    }

    /**
     * Returns the default button panel.
     *
     * @return the default button panel
     */
    public String getDefaultButtonPanel() {

        return new String("cybop.model.organizer.CloseButtonPanel");
    }

    //
    // Head panel.
    //

    /**
     * Sets the head panel.
     *
     * @param hp the head panel
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the head panel is null
     */
    public void setHeadPanel(HeadPanel hp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (hp != null) {

                p.add((javax.swing.JPanel) hp.getJavaObject(), java.awt.BorderLayout.NORTH);

            } else {
    
                throw new NullPointerException("Could not set head panel. The head panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set head panel. The java panel is null.");
        }
    }

    /**
     * Removes the head panel.
     *
     * @param hp the head panel
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the head panel is null
     */
    public void removeHeadPanel(HeadPanel hp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (hp != null) {

                p.remove((javax.swing.JPanel) hp.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove head panel. The head panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove head panel. The java panel is null.");
        }
    }

    //
    // Tabbed pane.
    //

    /**
     * Sets the tabbed pane.
     *
     * @param tp the tabbed pane
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the tabbed pane is null
     */
    public void setTabbedPane(TabbedPane tp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (tp != null) {

                p.add((javax.swing.JTabbedPane) tp.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {
    
                throw new NullPointerException("Could not set tabbed pane. The tabbed pane is null.");
            }

        } else {

            throw new NullPointerException("Could not set tabbed pane. The java panel is null.");
        }
    }

    /**
     * Removes the tabbed pane.
     *
     * @param tp the tabbed pane
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the tabbed pane is null
     */
    public void removeTabbedPane(TabbedPane tp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (tp != null) {

                p.remove((javax.swing.JTabbedPane) tp.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove tabbed pane. The tabbed pane is null.");
            }

        } else {

            throw new NullPointerException("Could not remove tabbed pane. The java panel is null.");
        }
    }

    //
    // Button panel.
    //

    /**
     * Sets the button panel.
     *
     * @param bp the button panel
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the button panel is null
     */
    public void setButtonPanel(ButtonPanel bp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (bp != null) {

                p.add((javax.swing.JPanel) bp.getJavaObject(), java.awt.BorderLayout.SOUTH);

            } else {
    
                throw new NullPointerException("Could not set button panel. The button panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set button panel. The java panel is null.");
        }
    }

    /**
     * Removes the button panel.
     *
     * @param bp the button panel
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the button panel is null
     */
    public void removeButtonPanel(ButtonPanel bp) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (bp != null) {

                p.remove((javax.swing.JPanel) bp.getJavaObject());

            } else {
    
                throw new NullPointerException("Could not remove button panel. The button panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove button panel. The java panel is null.");
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

        set(SystemInformationContentsPanel.HEAD_PANEL, createComponent(getDefaultHeadPanel()));
        set(SystemInformationContentsPanel.TABBED_PANE, createComponent(getDefaultTabbedPane()));
        set(SystemInformationContentsPanel.BUTTON_PANEL, createComponent(getDefaultButtonPanel()));
    }

    /**
     * Finalizes this portal contents panel.
     */
    public void finalizz() throws Exception {

        ButtonPanel buttonPanel = (ButtonPanel) get(SystemInformationContentsPanel.BUTTON_PANEL);
        remove(SystemInformationContentsPanel.BUTTON_PANEL);
        destroyComponent(buttonPanel);

        TabbedPane tabbedPane = (TabbedPane) get(SystemInformationContentsPanel.TABBED_PANE);
        remove(SystemInformationContentsPanel.TABBED_PANE);
        destroyComponent(tabbedPane);

        HeadPanel headPanel = (HeadPanel) get(SystemInformationContentsPanel.HEAD_PANEL);
        remove(SystemInformationContentsPanel.HEAD_PANEL);
        destroyComponent(headPanel);

        super.finalizz();
    }
}

