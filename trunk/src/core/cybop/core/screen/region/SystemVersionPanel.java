/*
 * $RCSfile: SystemVersionPanel.java,v $
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
import cybop.core.screen.component.*;

/**
 * This class represents a system version panel.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-18 09:57:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemVersionPanel extends DisplayRegion {

    //
    // Children names.
    //

    /** The name label. */
    public static final String NAME_LABEL = new String("name_label");

    /** The version label. */
    public static final String VERSION_LABEL = new String("version_label");

    /** The date label. */
    public static final String DATE_LABEL = new String("date_label");

    /** The slogan label. */
    public static final String SLOGAN_LABEL = new String("slogan_label");

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
    public void destroyJavaObject(java.lang.Object o) {

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

            if (n.isEqualTo(SystemVersionPanel.NAME_LABEL)) {

                setNameLabel((Label) i);

            } else if (n.isEqualTo(SystemVersionPanel.VERSION_LABEL)) {

                setVersionLabel((Label) i);
            
            } else if (n.isEqualTo(SystemVersionPanel.DATE_LABEL)) {

                setDateLabel((Label) i);
            
            } else if (n.isEqualTo(SystemVersionPanel.SLOGAN_LABEL)) {

                setSloganLabel((Label) i);
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

            if (n.isEqualTo(SystemVersionPanel.NAME_LABEL)) {

                removeNameLabel((Label) getChild(n));

            } else if (n.isEqualTo(SystemVersionPanel.VERSION_LABEL)) {

                removeVersionLabel((Label) getChild(n));
            
            } else if (n.isEqualTo(SystemVersionPanel.DATE_LABEL)) {

                removeDateLabel((Label) getChild(n));
            
            } else if (n.isEqualTo(SystemVersionPanel.SLOGAN_LABEL)) {

                removeSloganLabel((Label) getChild(n));
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
     * Returns the default name label category.
     *
     * @return the default name label category
     */
    public String getDefaultNameLabelCategory() {

        return new String("cybop.core.screen.component.Label");
    }

    /**
     * Returns the default version label category.
     *
     * @return the default version label category
     */
    public String getDefaultVersionLabelCategory() {

        return new String("cybop.core.screen.component.Label");
    }

    /**
     * Returns the default date label category.
     *
     * @return the default date label category
     */
    public String getDefaultDateLabelCategory() {

        return new String("cybop.core.screen.component.Label");
    }

    /**
     * Returns the default slogan label category.
     *
     * @return the default slogan label category
     */
    public String getDefaultSloganLabelCategory() {

        return new String("cybop.core.screen.component.Label");
    }

    //
    // Name label.
    //

    /**
     * Sets the name label.
     *
     * @param l the name label
     * @exception Exception if the java panel is null
     * @exception Exception if the name label is null
     */
    public void setNameLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.WEST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set name label. The name label is null.");
            }

        } else {

            throw new Exception("Could not set name label. The java panel is null.");
        }
    }

    /**
     * Removes the name label.
     *
     * @param l the name label
     * @exception Exception if the java panel is null
     * @exception Exception if the name label is null
     */
    public void removeNameLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove name label. The name label is null.");
            }

        } else {

            throw new Exception("Could not remove name label. The java panel is null.");
        }
    }

    //
    // Version label.
    //

    /**
     * Sets the version label.
     *
     * @param l the version label
     * @exception Exception if the java panel is null
     * @exception Exception if the version label is null
     */
    public void setVersionLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not set version label. The version label is null.");
            }

        } else {

            throw new Exception("Could not set version label. The java panel is null.");
        }
    }

    /**
     * Removes the version label.
     *
     * @param l the version label
     * @exception Exception if the java panel is null
     * @exception Exception if the version label is null
     */
    public void removeVersionLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove version label. The version label is null.");
            }

        } else {

            throw new Exception("Could not remove version label. The java panel is null.");
        }
    }

    //
    // Date label.
    //

    /**
     * Sets the date label.
     *
     * @param l the date label
     * @exception Exception if the java panel is null
     * @exception Exception if the date label is null
     */
    public void setDateLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set date label. The date label is null.");
            }

        } else {

            throw new Exception("Could not set date label. The java panel is null.");
        }
    }

    /**
     * Removes the date label.
     *
     * @param l the date label
     * @exception Exception if the java panel is null
     * @exception Exception if the date label is null
     */
    public void removeDateLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove date label. The date label is null.");
            }

        } else {

            throw new Exception("Could not remove date label. The java panel is null.");
        }
    }

    //
    // Slogan label.
    //

    /**
     * Sets the slogan label.
     *
     * @param l the slogan label
     * @exception Exception if the java panel is null
     * @exception Exception if the slogan label is null
     */
    public void setSloganLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.SOUTH);

            } else {

                java.lang.System.out.println("DEBUG: Could not set slogan label. The slogan label is null.");
            }

        } else {

            throw new Exception("Could not set slogan label. The java panel is null.");
        }
    }

    /**
     * Removes the slogan label.
     *
     * @param l the slogan label
     * @exception Exception if the java panel is null
     * @exception Exception if the slogan label is null
     */
    public void removeSloganLabel(Label l) throws Exception {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove slogan label. The slogan label is null.");
            }

        } else {

            throw new Exception("Could not remove slogan label. The java panel is null.");
        }
    }

//?? ==================================================

    /**
     * Creates the version label.
     *
            l.setFont(new Font(null, Font.BOLD, 18));
            l.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 10, 0, 0));

    /**
     * Creates the date label.
     *
            l.setHorizontalAlignment(ResLabel.RIGHT);
//?? ===================================================

    //
    // Categorization.
    //

    /**
     * Categorizes this hierarchy.
     */
    public void categorize() throws Exception {

        super.categorize();

        setCategory(SystemVersionPanel.NAME_LABEL, getDefaultNameLabelCategory());
        setCategory(SystemVersionPanel.VERSION_LABEL, getDefaultVersionLabelCategory());
        setCategory(SystemVersionPanel.DATE_LABEL, getDefaultDateLabelCategory());
        setCategory(SystemVersionPanel.SLOGAN_LABEL, getDefaultSloganLabelCategory());
    }

    /**
     * Decategorizes this hierarchy.
     */
    public void decategorize() throws Exception {

        removeCategory(SystemVersionPanel.SLOGAN_LABEL);
        removeCategory(SystemVersionPanel.DATE_LABEL);
        removeCategory(SystemVersionPanel.VERSION_LABEL);
        removeCategory(SystemVersionPanel.NAME_LABEL);

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

        setChild(SystemVersionPanel.NAME_LABEL, createChild(SystemVersionPanel.NAME_LABEL));
        setChild(SystemVersionPanel.VERSION_LABEL, createChild(SystemVersionPanel.VERSION_LABEL));
        setChild(SystemVersionPanel.DATE_LABEL, createChild(SystemVersionPanel.DATE_LABEL));
        setChild(SystemVersionPanel.SLOGAN_LABEL, createChild(SystemVersionPanel.SLOGAN_LABEL));
    }

    /**
     * Finalizes this item.
     */
    public void finalizz() throws Exception {

        Item sloganLabel = getChild(SystemVersionPanel.SLOGAN_LABEL);
        removeChild(SystemVersionPanel.SLOGAN_LABEL);
        destroyChild(sloganLabel);

        Item dateLabel = getChild(SystemVersionPanel.DATE_LABEL);
        removeChild(SystemVersionPanel.DATE_LABEL);
        destroyChild(dateLabel);

        Item versionLabel = getChild(SystemVersionPanel.VERSION_LABEL);
        removeChild(SystemVersionPanel.VERSION_LABEL);
        destroyChild(versionLabel);

        Item nameLabel = getChild(SystemVersionPanel.NAME_LABEL);
        removeChild(SystemVersionPanel.NAME_LABEL);
        destroyChild(nameLabel);

        super.finalizz();
    }
}

