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

package cybop.core.screen.region.tabbedpane;

import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.screen.region.*;

/**
 * This class represents a system information tabbed pane.
 *
 * @version $Revision: 1.3 $ $Date: 2003-05-23 11:57:29 $ $Author: christian $
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
     * @exception Exception if the name is null
     */
    public void setChildItem(String n, Item i) throws Exception {

        super.setChildItem(n, i);

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

            throw new Exception("Could not set item. The name is null.");
        }
    }

    /**
     * Removes the child item from this item.
     *
     * @param n the name
     * @exception Exception if the name is null
     */
    public void removeChildItem(String n) throws Exception {

        if (n != null) {

            if (n.isEqualTo(SystemInformationTabbedPane.IMAGE_PANEL)) {

                removeImagePanel((ImagePanel) getChildItem(n));

            } else if (n.isEqualTo(SystemInformationTabbedPane.COPYRIGHT_PANEL)) {

                removeCopyrightPanel((TextPanel) getChildItem(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.AUTHORS_PANEL)) {

                removeAuthorsPanel((TextPanel) getChildItem(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.HELPERS_PANEL)) {

                removeHelpersPanel((TextPanel) getChildItem(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.INSPIRATIONS_PANEL)) {

                removeInspirationsPanel((TextPanel) getChildItem(n));
            
            } else if (n.isEqualTo(SystemInformationTabbedPane.LICENSE_PANEL)) {

                removeLicensePanel((TextPanel) getChildItem(n));
            }

        } else {

            throw new Exception("Could not remove item. The name is null.");
        }

        super.removeChildItem(n);
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
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the image panel is null
     * @exception Exception if the image panel child name is null
     */
    public void setImagePanel(ImagePanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.IMAGE_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new Exception("Could not set image panel. The image panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set image panel. The image panel is null.");
            }

        } else {

            throw new Exception("Could not set image panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the image panel.
     *
     * @param p the image panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the image panel is null
     */
    public void removeImagePanel(ImagePanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove image panel. The image panel is null.");
            }

        } else {

            throw new Exception("Could not remove image panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Copyright panel.
    //

    /**
     * Sets the copyright panel.
     *
     * @param p the copyright panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the copyright panel is null
     * @exception Exception if the copyright panel child name is null
     */
    public void setCopyrightPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.COPYRIGHT_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new Exception("Could not set copyright panel. The panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set copyright panel. The copyright panel is null.");
            }

        } else {

            throw new Exception("Could not set copyright panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the copyright panel.
     *
     * @param p the copyright panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the copyright panel is null
     */
    public void removeCopyrightPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove copyright panel. The copyright panel is null.");
            }

        } else {

            throw new Exception("Could not remove copyright panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Authors panel.
    //

    /**
     * Sets the authors panel.
     *
     * @param p the authors panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the authors panel is null
     * @exception Exception if the authors panel child name is null
     */
    public void setAuthorsPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.AUTHORS_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new Exception("Could not set authors panel. The authors panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set authors panel. The authors panel is null.");
            }

        } else {

            throw new Exception("Could not set authors panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the authors panel.
     *
     * @param p the authors panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the authors panel is null
     */
    public void removeAuthorsPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove authors panel. The authors panel is null.");
            }

        } else {

            throw new Exception("Could not remove authors panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Helpers panel.
    //

    /**
     * Sets the helpers panel.
     *
     * @param p the helpers panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the helpers panel is null
     * @exception Exception if the helpers panel child name is null
     */
    public void setHelpersPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.HELPERS_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new Exception("Could not set helpers panel. The helpers panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set helpers panel. The helpers panel is null.");
            }

        } else {

            throw new Exception("Could not set helpers panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the helpers panel.
     *
     * @param p the helpers panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the helpers panel is null
     */
    public void removeHelpersPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove helpers panel. The helpers panel is null.");
            }

        } else {

            throw new Exception("Could not remove helpers panel. The java swing tabbed pane is null.");
        }
    }

    //
    // Inspirations panel.
    //

    /**
     * Sets the inspirations panel.
     *
     * @param p the inspirations panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the inspirations panel is null
     * @exception Exception if the inspirations panel child name is null
     */
    public void setInspirationsPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.INSPIRATIONS_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new Exception("Could not set inspirations panel. The inspirations panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set inspirations panel. The inspirations panel is null.");
            }

        } else {

            throw new Exception("Could not set inspirations panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the inspirations panel.
     *
     * @param p the inspirations panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the inspirations panel is null
     */
    public void removeInspirationsPanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove inspirations panel. The inspirations panel is null.");
            }

        } else {

            throw new Exception("Could not remove inspirations panel. The java swing tabbed pane is null.");
        }
    }

    //
    // License panel.
    //

    /**
     * Sets the license panel.
     *
     * @param p the license panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the license panel is null
     * @exception Exception if the license panel child name is null
     */
    public void setLicensePanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                String s = SystemInformationTabbedPane.LICENSE_PANEL;
                
                if (s != null) {

                    tp.add((java.lang.String) s.getJavaObject(), (javax.swing.JPanel) p.getJavaObject());

                } else {

                    throw new Exception("Could not set license panel. The license panel child name is null.");
                }

            } else {

                java.lang.System.out.println("DEBUG: Could not set license panel. The license panel is null.");
            }

        } else {

            throw new Exception("Could not set license panel. The java swing tabbed pane is null.");
        }
    }

    /**
     * Removes the license panel.
     *
     * @param p the license panel
     * @exception Exception if the java swing tabbed pane is null
     * @exception Exception if the license panel is null
     */
    public void removeLicensePanel(TextPanel p) throws Exception {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) getJavaObject();

        if (tp != null) {

            if (p != null) {

                tp.remove((javax.swing.JPanel) p.getJavaObject());

            } else {

                java.lang.System.out.println("DEBUG: Could not remove license panel. The license panel is null.");
            }

        } else {

            throw new Exception("Could not remove license panel. The java swing tabbed pane is null.");
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

        setChildItem(SystemInformationTabbedPane.IMAGE_PANEL, createChildItem(getDefaultImagePanel()));
        setChildItem(SystemInformationTabbedPane.COPYRIGHT_PANEL, createChildItem(getDefaultCopyrightPanel()));
        setChildItem(SystemInformationTabbedPane.AUTHORS_PANEL, createChildItem(getDefaultAuthorsPanel()));
        setChildItem(SystemInformationTabbedPane.HELPERS_PANEL, createChildItem(getDefaultHelpersPanel()));
        setChildItem(SystemInformationTabbedPane.INSPIRATIONS_PANEL, createChildItem(getDefaultInspirationsPanel()));
        setChildItem(SystemInformationTabbedPane.LICENSE_PANEL, createChildItem(getDefaultLicensePanel()));
    }

    /**
     * Finalizes this system information tabbed pane.
     */
    public void finalizz() throws Exception {

        TextPanel licensePanel = (TextPanel) getChildItem(SystemInformationTabbedPane.LICENSE_PANEL);
        removeChildItem(SystemInformationTabbedPane.LICENSE_PANEL);
        destroyChildItem(licensePanel);

        TextPanel inspirationsPanel = (TextPanel) getChildItem(SystemInformationTabbedPane.INSPIRATIONS_PANEL);
        removeChildItem(SystemInformationTabbedPane.INSPIRATIONS_PANEL);
        destroyChildItem(inspirationsPanel);

        TextPanel helpersPanel = (TextPanel) getChildItem(SystemInformationTabbedPane.HELPERS_PANEL);
        removeChildItem(SystemInformationTabbedPane.HELPERS_PANEL);
        destroyChildItem(helpersPanel);

        TextPanel authorsPanel = (TextPanel) getChildItem(SystemInformationTabbedPane.AUTHORS_PANEL);
        removeChildItem(SystemInformationTabbedPane.AUTHORS_PANEL);
        destroyChildItem(authorsPanel);

        TextPanel copyrightPanel = (TextPanel) getChildItem(SystemInformationTabbedPane.COPYRIGHT_PANEL);
        removeChildItem(SystemInformationTabbedPane.COPYRIGHT_PANEL);
        destroyChildItem(copyrightPanel);

        ImagePanel imagePanel = (ImagePanel) getChildItem(SystemInformationTabbedPane.IMAGE_PANEL);
        removeChildItem(SystemInformationTabbedPane.IMAGE_PANEL);
        destroyChildItem(imagePanel);

        super.finalizz();
    }
}

