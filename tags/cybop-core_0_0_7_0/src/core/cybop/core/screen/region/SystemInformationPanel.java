/*
 * $RCSfile: SystemInformationPanel.java,v $
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

/**
 * This class represents a system information contents panel.
 *
 * @version $Revision: 1.9 $ $Date: 2003-06-20 11:32:32 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformationPanel extends Panel {

    //
    // Children names.
    //

    /** The system version panel. */
    public static final String SYSTEM_VERSION_PANEL = new String("system_version_panel");

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

            if (n.isEqualTo(SystemInformationPanel.SYSTEM_VERSION_PANEL)) {

                setSystemVersionPanel((SystemVersionPanel) i);

            } else if (n.isEqualTo(SystemInformationPanel.TABBED_PANE)) {

                setTabbedPane((TabbedPane) i);
            
            } else if (n.isEqualTo(SystemInformationPanel.BUTTON_PANEL)) {

                setButtonPanel((ButtonPanel) i);
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

            if (n.isEqualTo(SystemInformationPanel.SYSTEM_VERSION_PANEL)) {

                removeSystemVersionPanel((SystemVersionPanel) getChild(n));

            } else if (n.isEqualTo(SystemInformationPanel.TABBED_PANE)) {

                removeTabbedPane((TabbedPane) getChild(n));
            
            } else if (n.isEqualTo(SystemInformationPanel.BUTTON_PANEL)) {

                removeButtonPanel((ButtonPanel) getChild(n));
            }

        } else {

            throw new Exception("Could not set item. The name is null.");
        }
        
        super.removeChild(n);
    }

    //
    // Default children.
    //

    /**
     * Returns the default system version panel.
     *
     * @return the default system version panel
     */
    public String getDefaultSystemVersionPanel() {

        return new String("cybop.core.screen.region.SystemVersionPanel");
    }

    /**
     * Returns the default tabbed pane.
     *
     * @return the default tabbed pane
     */
    public String getDefaultTabbedPane() {

        return new String("cybop.core.screen.region.TabbedPane");
    }

    /**
     * Returns the default button panel.
     *
     * @return the default button panel
     */
    public String getDefaultButtonPanel() {

        return new String("cybop.core.screen.region.CloseButtonPanel");
    }

    //
    // System version panel.
    //

    /**
     * Sets the system version panel.
     *
     * @param vp the system version panel
     * @exception Exception if the java panel is null
     * @exception Exception if the system version panel is null
     */
    public void setSystemVersionPanel(SystemVersionPanel vp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (vp != null) {

                p.add((javax.swing.JPanel) vp.getJavaObject(), java.awt.BorderLayout.NORTH);

            } else {
    
                throw new Exception("Could not set system version panel. The system version panel is null.");
            }

        } else {

            throw new Exception("Could not set system version panel. The java panel is null.");
        }
    }

    /**
     * Removes the system version panel.
     *
     * @param vp the system version panel
     * @exception Exception if the java panel is null
     * @exception Exception if the system version panel is null
     */
    public void removeSystemVersionPanel(SystemVersionPanel vp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (vp != null) {

                p.remove((javax.swing.JPanel) vp.getJavaObject());

            } else {

                throw new Exception("Could not remove system version panel. The system version panel is null.");
            }

        } else {

            throw new Exception("Could not remove system version panel. The java panel is null.");
        }
    }

    //
    // Tabbed pane.
    //

    /**
     * Sets the tabbed pane.
     *
     * @param tp the tabbed pane
     * @exception Exception if the java panel is null
     * @exception Exception if the tabbed pane is null
     */
    public void setTabbedPane(TabbedPane tp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (tp != null) {

                p.add((javax.swing.JTabbedPane) tp.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {
    
                throw new Exception("Could not set tabbed pane. The tabbed pane is null.");
            }

        } else {

            throw new Exception("Could not set tabbed pane. The java panel is null.");
        }
    }

    /**
     * Removes the tabbed pane.
     *
     * @param tp the tabbed pane
     * @exception Exception if the java panel is null
     * @exception Exception if the tabbed pane is null
     */
    public void removeTabbedPane(TabbedPane tp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (tp != null) {

                p.remove((javax.swing.JTabbedPane) tp.getJavaObject());

            } else {
    
                throw new Exception("Could not remove tabbed pane. The tabbed pane is null.");
            }

        } else {

            throw new Exception("Could not remove tabbed pane. The java panel is null.");
        }
    }

    //
    // Button panel.
    //

    /**
     * Sets the button panel.
     *
     * @param bp the button panel
     * @exception Exception if the java panel is null
     * @exception Exception if the button panel is null
     */
    public void setButtonPanel(ButtonPanel bp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (bp != null) {

                p.add((javax.swing.JPanel) bp.getJavaObject(), java.awt.BorderLayout.SOUTH);

            } else {
    
                throw new Exception("Could not set button panel. The button panel is null.");
            }

        } else {

            throw new Exception("Could not set button panel. The java panel is null.");
        }
    }

    /**
     * Removes the button panel.
     *
     * @param bp the button panel
     * @exception Exception if the java panel is null
     * @exception Exception if the button panel is null
     */
    public void removeButtonPanel(ButtonPanel bp) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (bp != null) {

                p.remove((javax.swing.JPanel) bp.getJavaObject());

            } else {
    
                throw new Exception("Could not remove button panel. The button panel is null.");
            }

        } else {

            throw new Exception("Could not remove button panel. The java panel is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this item.
     */
    public void initialize() throws Exception {

        super.initialize();

        setChild(SystemInformationPanel.SYSTEM_VERSION_PANEL, createChild(getDefaultSystemVersionPanel()));
        setChild(SystemInformationPanel.TABBED_PANE, createChild(getDefaultTabbedPane()));
        setChild(SystemInformationPanel.BUTTON_PANEL, createChild(getDefaultButtonPanel()));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item buttonPanel = getChild(SystemInformationPanel.BUTTON_PANEL);
        removeChild(SystemInformationPanel.BUTTON_PANEL);
        destroyChild(buttonPanel);

        Item tabbedPane = getChild(SystemInformationPanel.TABBED_PANE);
        removeChild(SystemInformationPanel.TABBED_PANE);
        destroyChild(tabbedPane);

        Item systemVersionPanel = getChild(SystemInformationPanel.SYSTEM_VERSION_PANEL);
        removeChild(SystemInformationPanel.SYSTEM_VERSION_PANEL);
        destroyChild(systemVersionPanel);

        super.finalizz();
    }
}

