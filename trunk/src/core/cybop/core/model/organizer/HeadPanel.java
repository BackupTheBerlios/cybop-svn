/*
 * $RCSfile: HeadPanel.java,v $
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
 * This class represents a head panel.
 *
 * @version $Revision: 1.1 $ $Date: 2003-02-19 07:49:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class HeadPanel extends Panel {

    //
    // Children.
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

            if (n.isEqualTo(HeadPanel.NAME_LABEL)) {

                setNameLabel((Label) i);

            } else if (n.isEqualTo(HeadPanel.VERSION_LABEL)) {

                setVersionLabel((Label) i);
            
            } else if (n.isEqualTo(HeadPanel.DATE_LABEL)) {

                setDateLabel((Label) i);
            
            } else if (n.isEqualTo(HeadPanel.SLOGAN_LABEL)) {

                setSloganLabel((Label) i);
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

            if (n.isEqualTo(HeadPanel.NAME_LABEL)) {

                removeNameLabel((Label) get(n));

            } else if (n.isEqualTo(HeadPanel.VERSION_LABEL)) {

                removeVersionLabel((Label) get(n));
            
            } else if (n.isEqualTo(HeadPanel.DATE_LABEL)) {

                removeDateLabel((Label) get(n));
            
            } else if (n.isEqualTo(HeadPanel.SLOGAN_LABEL)) {

                removeSloganLabel((Label) get(n));
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
     * Returns the default name label.
     *
     * @return the default name label
     */
    public String getDefaultNameLabel() {

        return new String("cybop.model.organizer.Label");
    }

    /**
     * Returns the default version label.
     *
     * @return the default version label
     */
    public String getDefaultVersionLabel() {

        return new String("cybop.model.organizer.Label");
    }

    /**
     * Returns the default date label.
     *
     * @return the default date label
     */
    public String getDefaultDateLabel() {

        return new String("cybop.model.organizer.Label");
    }

    /**
     * Returns the default slogan label.
     *
     * @return the default slogan label
     */
    public String getDefaultSloganLabel() {

        return new String("cybop.model.organizer.Label");
    }

    //
    // Name label.
    //

    /**
     * Sets the name label.
     *
     * @param l the name label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the name label is null
     */
    public void setNameLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.WEST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set name label. The name label is null.");
            }

        } else {

            throw new NullPointerException("Could not set name label. The java panel is null.");
        }
    }

    /**
     * Removes the name label.
     *
     * @param l the name label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the name label is null
     */
    public void removeNameLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove name label. The name label is null.");
            }

        } else {

            throw new NullPointerException("Could not remove name label. The java panel is null.");
        }
    }

    //
    // Version label.
    //

    /**
     * Sets the version label.
     *
     * @param l the version label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the version label is null
     */
    public void setVersionLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.CENTER);

            } else {

                java.lang.System.out.println("DEBUG: Could not set version label. The version label is null.");
            }

        } else {

            throw new NullPointerException("Could not set version label. The java panel is null.");
        }
    }

    /**
     * Removes the version label.
     *
     * @param l the version label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the version label is null
     */
    public void removeVersionLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove version label. The version label is null.");
            }

        } else {

            throw new NullPointerException("Could not remove version label. The java panel is null.");
        }
    }

    //
    // Date label.
    //

    /**
     * Sets the date label.
     *
     * @param l the date label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the date label is null
     */
    public void setDateLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.EAST);

            } else {

                java.lang.System.out.println("DEBUG: Could not set date label. The date label is null.");
            }

        } else {

            throw new NullPointerException("Could not set date label. The java panel is null.");
        }
    }

    /**
     * Removes the date label.
     *
     * @param l the date label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the date label is null
     */
    public void removeDateLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove date label. The date label is null.");
            }

        } else {

            throw new NullPointerException("Could not remove date label. The java panel is null.");
        }
    }

    //
    // Slogan label.
    //

    /**
     * Sets the slogan label.
     *
     * @param l the slogan label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the slogan label is null
     */
    public void setSloganLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.add((javax.swing.JLabel) l.getJavaObject(), java.awt.BorderLayout.SOUTH);

            } else {

                java.lang.System.out.println("DEBUG: Could not set slogan label. The slogan label is null.");
            }

        } else {

            throw new NullPointerException("Could not set slogan label. The java panel is null.");
        }
    }

    /**
     * Removes the slogan label.
     *
     * @param l the slogan label
     * @exception NullPointerException if the java panel is null
     * @exception NullPointerException if the slogan label is null
     */
    public void removeSloganLabel(Label l) throws NullPointerException {

        javax.swing.JPanel p = (javax.swing.JPanel) getJavaObject();

        if (p != null) {

            if (l != null) {

                p.remove((javax.swing.JLabel) l.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove slogan label. The slogan label is null.");
            }

        } else {

            throw new NullPointerException("Could not remove slogan label. The java panel is null.");
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

    //
    // Initializable.
    //

    /**
     * Initializes this head panel.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(HeadPanel.NAME_LABEL, createComponent(getDefaultNameLabel()));
        set(HeadPanel.VERSION_LABEL, createComponent(getDefaultVersionLabel()));
        set(HeadPanel.DATE_LABEL, createComponent(getDefaultDateLabel()));
        set(HeadPanel.SLOGAN_LABEL, createComponent(getDefaultSloganLabel()));
    }

    /**
     * Finalizes this head panel.
     */
    public void finalizz() throws Exception {

        Label sloganLabel = (Label) get(HeadPanel.SLOGAN_LABEL);
        remove(HeadPanel.SLOGAN_LABEL);
        destroyComponent(sloganLabel);

        Label dateLabel = (Label) get(HeadPanel.DATE_LABEL);
        remove(HeadPanel.DATE_LABEL);
        destroyComponent(dateLabel);

        Label versionLabel = (Label) get(HeadPanel.VERSION_LABEL);
        remove(HeadPanel.VERSION_LABEL);
        destroyComponent(versionLabel);

        Label nameLabel = (Label) get(HeadPanel.NAME_LABEL);
        remove(HeadPanel.NAME_LABEL);
        destroyComponent(nameLabel);

        super.finalizz();
    }
}

