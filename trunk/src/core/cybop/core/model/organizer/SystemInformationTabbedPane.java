/*
 * $RCSfile: SystemInformationTabbedPane.java,v $
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
import cybop.core.basic.String;

/**
 * This class represents a system information tabbed pane.
 *
 * @version $Revision: 1.4 $ $Date: 2003-03-12 18:12:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class SystemInformationTabbedPane extends TabbedPane {

    //
    // Children names.
    //

    /** The image panel. */
    public static final String IMAGE_PANEL = new String("image_panel");

    /** The copyright panel. */
    public static final String COPYRIGHT_PANEL = new String("copyright");

    /** The authors panel. */
    public static final String AUTHORS_PANEL = new String("authors");

    /** The helpers panel. */
    public static final String HELPERS_PANEL = new String("helpers");

    /** The inspirations panel. */
    public static final String INSPIRATIONS_PANEL = new String("inspirations");

    /** The license panel. */
    public static final String LICENSE_PANEL = new String("license");

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

            if (n.isEqualTo(SystemInformationTabbedPane.IMAGE_PANEL)) {

                setImagePanel((ImagePanel) i);

            } else if (n.isEqualTo(SystemInformationTabbedPane.COPYRIGHT_PANEL)) {

                setCopyrightPanel((TextPanel) i);
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.AUTHORS_PANEL)) {

                setAuthorsPanel((TextPanel) i);
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.HELPERS_PANEL)) {

                setHelpersPanel((TextPanel) i);
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.INSPIRATIONS_PANEL)) {

                setInspirationsPanel((TextPanel) i);
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.LICENSE_PANEL)) {

                setLicensePanel((TextPanel) i);
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

            if (n.isEqualTo(SystemInformationTabbedPane.IMAGE_PANEL)) {

                removeImagePanel((ImagePanel) get(n));

            } else if (n.isEqualTo(SystemInformationTabbedPane.COPYRIGHT_PANEL)) {

                removeCopyrightPanel((TextPanel) get(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.AUTHORS_PANEL)) {

                removeAuthorsPanel((TextPanel) get(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.HELPERS_PANEL)) {

                removeHelpersPanel((TextPanel) get(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.INSPIRATIONS_PANEL)) {

                removeInspirationsPanel((TextPanel) get(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.LICENSE_PANEL)) {

                removeLicensePanel((TextPanel) get(n));
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
     * Returns the default image panel.
     *
     * @return the default image panel
     */
    public String getDefaultImagePanel() {

        return null;
    }

    /**
     * Returns the default copyright panel.
     *
     * @return the default copyright panel
     */
    public String getDefaultCopyrightPanel() {

        return null;
    }

    /**
     * Returns the default authors panel.
     *
     * @return the default authors panel
     */
    public String getDefaultAuthorsPanel() {

        return null;
    }

    /**
     * Returns the default helpers panel.
     *
     * @return the default helpers panel
     */
    public String getDefaultHelpersPanel() {

        return null;
    }

    /**
     * Returns the default inspirations panel.
     *
     * @return the default inspirations panel
     */
    public String getDefaultInspirationsPanel() {

        return null;
    }

    /**
     * Returns the default license panel.
     *
     * @return the default license panel
     */
    public String getDefaultLicensePanel() {

        return null;
    }

    //
    // Image panel.
    //

    /**
     * Sets the image panel.
     *
     * @param p the image panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the image panel is null
     * @exception NullPointerException if the image panel child name is null
     */
    public void setImagePanel(ImagePanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.IMAGE_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new NullPointerException("Could not set image panel. The image panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set image panel. The image panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set image panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the image panel.
     *
     * @param p the image panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the image panel is null
     */
    public void removeImagePanel(ImagePanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove image panel. The image panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove image panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Copyright panel.
    //

    /**
     * Sets the copyright panel.
     *
     * @param p the copyright panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the copyright panel is null
     * @exception NullPointerException if the copyright panel child name is null
     */
    public void setCopyrightPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.COPYRIGHT_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new NullPointerException("Could not set copyright panel. The panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set copyright panel. The copyright panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set copyright panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the copyright panel.
     *
     * @param p the copyright panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the copyright panel is null
     */
    public void removeCopyrightPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove copyright panel. The copyright panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove copyright panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Authors panel.
    //

    /**
     * Sets the authors panel.
     *
     * @param p the authors panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the authors panel is null
     * @exception NullPointerException if the authors panel child name is null
     */
    public void setAuthorsPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.AUTHORS_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new NullPointerException("Could not set authors panel. The authors panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set authors panel. The authors panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set authors panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the authors panel.
     *
     * @param p the authors panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the authors panel is null
     */
    public void removeAuthorsPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove authors panel. The authors panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove authors panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Helpers panel.
    //

    /**
     * Sets the helpers panel.
     *
     * @param p the helpers panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the helpers panel is null
     * @exception NullPointerException if the helpers panel child name is null
     */
    public void setHelpersPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.HELPERS_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new NullPointerException("Could not set helpers panel. The helpers panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set helpers panel. The helpers panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set helpers panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the helpers panel.
     *
     * @param p the helpers panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the helpers panel is null
     */
    public void removeHelpersPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove helpers panel. The helpers panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove helpers panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Inspirations panel.
    //

    /**
     * Sets the inspirations panel.
     *
     * @param p the inspirations panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the inspirations panel is null
     * @exception NullPointerException if the inspirations panel child name is null
     */
    public void setInspirationsPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.INSPIRATIONS_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new NullPointerException("Could not set inspirations panel. The inspirations panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set inspirations panel. The inspirations panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set inspirations panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the inspirations panel.
     *
     * @param p the inspirations panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the inspirations panel is null
     */
    public void removeInspirationsPanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove inspirations panel. The inspirations panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove inspirations panel. The java swing tabbed pane is null.");
        }
    }

    //
    // License panel.
    //

    /**
     * Sets the license panel.
     *
     * @param p the license panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the license panel is null
     * @exception NullPointerException if the license panel child name is null
     */
    public void setLicensePanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.LICENSE_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new NullPointerException("Could not set license panel. The license panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set license panel. The license panel is null.");
            }

        } else {

            throw new NullPointerException("Could not set license panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the license panel.
     *
     * @param p the license panel
     * @exception NullPointerException if the java swing tabbed pane is null
     * @exception NullPointerException if the license panel is null
     */
    public void removeLicensePanel(TextPanel p) throws NullPointerException {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove license panel. The license panel is null.");
            }

        } else {

            throw new NullPointerException("Could not remove license panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this system information tabbed pane.
     */
    public void initialize() throws Exception {

        super.initialize();

        set(SystemInformationTabbedPane.IMAGE_PANEL, createComponent(getDefaultImagePanel()));
        set(SystemInformationTabbedPane.COPYRIGHT_PANEL, createComponent(getDefaultCopyrightPanel()));
        set(SystemInformationTabbedPane.AUTHORS_PANEL, createComponent(getDefaultAuthorsPanel()));
        set(SystemInformationTabbedPane.HELPERS_PANEL, createComponent(getDefaultHelpersPanel()));
        set(SystemInformationTabbedPane.INSPIRATIONS_PANEL, createComponent(getDefaultInspirationsPanel()));
        set(SystemInformationTabbedPane.LICENSE_PANEL, createComponent(getDefaultLicensePanel()));
    }

    /**
     * Finalizes this system information tabbed pane.
     */
    public void finalizz() throws Exception {

        TextPanel licensePanel = (TextPanel) get(SystemInformationTabbedPane.LICENSE_PANEL);
        remove(SystemInformationTabbedPane.LICENSE_PANEL);
        destroyComponent(licensePanel);

        TextPanel inspirationsPanel = (TextPanel) get(SystemInformationTabbedPane.INSPIRATIONS_PANEL);
        remove(SystemInformationTabbedPane.INSPIRATIONS_PANEL);
        destroyComponent(inspirationsPanel);

        TextPanel helpersPanel = (TextPanel) get(SystemInformationTabbedPane.HELPERS_PANEL);
        remove(SystemInformationTabbedPane.HELPERS_PANEL);
        destroyComponent(helpersPanel);

        TextPanel authorsPanel = (TextPanel) get(SystemInformationTabbedPane.AUTHORS_PANEL);
        remove(SystemInformationTabbedPane.AUTHORS_PANEL);
        destroyComponent(authorsPanel);

        TextPanel copyrightPanel = (TextPanel) get(SystemInformationTabbedPane.COPYRIGHT_PANEL);
        remove(SystemInformationTabbedPane.COPYRIGHT_PANEL);
        destroyComponent(copyrightPanel);

        ImagePanel imagePanel = (ImagePanel) get(SystemInformationTabbedPane.IMAGE_PANEL);
        remove(SystemInformationTabbedPane.IMAGE_PANEL);
        destroyComponent(imagePanel);

        super.finalizz();
    }
}

