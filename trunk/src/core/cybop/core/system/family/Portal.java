/*
 * $RCSfile: Portal.java,v $
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
 * http://www.resmedicinae.org
 * - Information in Medicine -
 */

package cybop.core.system.family;

import cybop.core.basic.*;
import cybop.core.basic.Integer;
import cybop.core.basic.String;
import cybop.core.model.model.user.*;
import cybop.core.system.*;
import cybop.core.system.System;
import cybop.core.system.block.*;
import cybop.core.system.block.controller.*;
import cybop.core.system.chain.*;

/**
 * This class represents a portal.<br><br>
 *
 * A portal system is capable of hosting multiple child systems which can be
 * internal, i.e. inherited from the ResMedLib framework or external processes.<br><br>
 *
 * The portal basically contains a tree with a hierarchy of all available
 * systems (modules). This tree can be displayed by the corresponding view
 * as menu or tree view. On clicking a system, it gets started. Systems can
 * be run standalone or from within this portal system. It is easily possible
 * to write additional modules and integrate them into this portal system.<br><br>
 *
 * Child systems can be integrated into the portal system's Frame as Frame,
 * InternalFrame or TabPage.
 *
 * @version $Revision: 1.2 $ $Date: 2003-02-19 17:15:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Portal extends Family {

    //
    // Default children.
    //

    /*
     * Returns the default configuration.
     *
     * @return the default configuration
     */
    public String getDefaultConfiguration() {

//??        c.setJavaObject(java.util.prefs.Preferences.systemNodeForPackage(getClass().getPackage().getClass()));
        return new String("cybop.core.system.chain.Configuration");
    }

    /**
     * Returns the default name.
     *
     * @return the default name
     */
    public String getDefaultName() {

        return new String("Res Medicinae Portal");
    }

    /**
     * Returns the default version.
     *
     * @return the default version
     */
    public String getDefaultVersion() {

        return new String("0.0.5.0");
    }

    /**
     * Returns the default date.
     *
     * @return the default date
     */
    public String getDefaultDate() {

        return new String("30.09.2002");
    }

    /**
     * Returns the default authors.
     *
     * @return the default authors
     */
    public String getDefaultAuthors() {

        return new String("Christian Heller\n<christian.heller@tuxtax.de>\n- initiated project\n- maintains ResMedLib framework\n- created Portal module\n");
    }

    /**
     * Returns the default helpers.
     *
     * @return the default helpers
     */
    public String getDefaultHelpers() {

        return new String("Karsten Hilbert\n<karsten.hilbert@gmx.net>\n- maintains the Analysis Document\n- helps out in many things\n\n"
                + "Michael Simon\n<michael.simon@gmx.net>\n- created ANT build.xml files\n- created .bat build/start files\n- prepared IzPack installer\n\n"
                + "Henrik Brandes\n<henrik-b@gmx.de>\n- created ANT build.xml files\n- created .bat build/start files\n- prepared IzPack installer\n\n"
                + "Chris Fraser\n<pangaea@comcen.com.au>\n- provided the 'Littlefish' project resources\n\n"
                + "Andrew Arch\n<archa@anz.com>\n- provided the 'Littlefish' project resources\n\n"
                + "Sebastian Hilbert\n<sebastian.hilbert@gmx.net>\n- designed the Res Medicinae logo\n\n"
                + "Johannes Vieweg\n<jvg@gmx.net>\n- provided a PDF version of the Design Document\n\n");
    }

    /**
     * Returns the default inspirations.
     *
     * @return the default inspirations
     */
    public String getDefaultInspirations() {

        return new String("Scope\nhttp://www.sourceforge.net/projects/scope\n- Hierarchical Model View Controller (HMVC) Design Pattern\n\n"
                + "Apache-Jakarta-Framework\nhttp://jakarta.apache.org\nComponent Lifecycle\n\n"
                + "Linux Kontor\nhttp://www.sourceforge.net/projects/kontor\nEnterprise Resource Planning System\n\n");
    }

    /**
     * Returns the default controller.
     *
     * @return the default controller
     */
    public String getDefaultController() {

        return new String("cybop.core.system.block.controller.PortalController");
    }

    /**
     * Returns the default user.
     *
     * @return the default user
     */
    public String getDefaultUser() {

        return new String("cybop.core.system.system.User");
    }

    //
    // Initialization.
    //

    /**
     * Initializes this portal.
     *
     * @exception NullPointerException if the configuration is null
     * @exception NullPointerException if the user is null
     * @exception NullPointerException if the portal user controller is null
     * @exception NullPointerException if the portal view model is null
     * @exception NullPointerException if the portal contents panel is null
     * @exception NullPointerException if the portal split pane is null
     * @exception NullPointerException if the tree is null
     */
    public void initialize() throws Exception, NullPointerException {

        super.initialize();

        Configuration c = (Configuration) get(Portal.CONFIGURATION);

        if (c != null) {

            //
            // User.
            //

/*??
            User u = (User) get(Portal.USER);

            if (u != null) {
    
                PortalUserController uc = (PortalUserController) u.get(PortalUser.CONTROLLER);
        
                if (uc != null) {

                    PortalUserInterface m = (PortalUserInterface) uc.get(PortalUserController.MODEL);

                    if (m != null) {
                        
                        cybop.model.organizer.PortalContentsPanel cp = (cybop.model.organizer.PortalContentsPanel) m.get(PortalUserInterface.CONTENTS_PANEL);
                        
                        if (cp != null) {
            
                            cybop.model.organizer.PortalSplitPane sp = (cybop.model.organizer.PortalSplitPane) cp.get(cybop.model.organizer.PortalContentsPanel.PORTAL_SPLIT_PANE);
                            
                            if (sp != null) {
                                
                                cybop.model.organizer.Tree t = (cybop.model.organizer.Tree) sp.get(cybop.model.organizer.PortalSplitPane.LEFT_ORGANIZER);
                                
                                if (t != null) {
            
                                    t.set(cybop.model.organizer.Tree.MODEL, get(Portal.AVAILABLE_SYSTEMS));
                                    //?? t.addTreeSelectionListener(this);
    
                                } else {
                
                                    throw new NullPointerException("Could not initialize portal. The tree is null.");
                                }
            
                            } else {
            
                                throw new NullPointerException("Could not initialize portal. The portal split pane is null.");
                            }
            
                        } else {
            
                            throw new NullPointerException("Could not initialize portal. The portal contents panel is null.");
                        }
            
                    } else {
            
                        throw new NullPointerException("Could not initialize portal. The portal view model is null.");
                    }
        
                } else {
        
                    throw new NullPointerException("Could not initialize portal. The portal user controller is null.");
                }
            
            } else {
    
                throw new NullPointerException("Could not initialize portal. The user is null.");
            }
*/

        } else {

            throw new NullPointerException("Could not initialize portal. The configuration is null.");
        }
    }

    /**
     * Finalizes this portal.
     *
     * @exception NullPointerException if the configuration is null
     */
    public void finalizz() throws Exception, NullPointerException {

        Configuration c = (Configuration) get(Portal.CONFIGURATION);

        if (c != null) {

        } else {

            throw new NullPointerException("Could not finalize portal. The configuration is null.");
        }
    }

    //
    // Application tree configuration dialog.
    //

    /**
     * Configures application tree in a dialog.
     *
     * @exception NullPointerException if the application tree configuration dialog is null
     */
    private void configureApplicationTree() throws NullPointerException {

/*??
        log(Level.CONFIG, "Create configuration dialog.");
        ApplicationTreeConfigurationDialog d = new ApplicationTreeConfigurationDialog(GuiController.getGuiController().getActiveFrame(), "Configure Settings", true, (ApplicationTreeNode) this.mainApplication.getAvailableApplications().getRoot());

        if (d != null) {

            d.setSize(new Dimension(700, 600));

            Dimension dialogSize = d.getPreferredSize();
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

            if (dialogSize.height > screenSize.height) {

                dialogSize.height = screenSize.height;
            }

            if (dialogSize.width > screenSize.width) {

                dialogSize.width = screenSize.width;
            }

            d.setLocation((screenSize.width - dialogSize.width) / 2, (screenSize.height - dialogSize.height) / 2);
            d.setVisible(true);

        } else {

            throw new NullPointerException("Could not create about dialog. About dialog is null.");
        }
*/
    }

    //
    // ResMedicinae configuration dialog.
    //

    /**
     * Configures Res Medicinae in a dialog.
     *
     * @exception NullPointerException if the configure Res Medicinae dialog is null
     */
    private void configureResMedicinae() throws NullPointerException {

/*??
        ResMedicinaeConfigurationDialog d = new ResMedicinaeConfigurationDialog(GuiController.getGuiController().getActiveFrame(), "Configure Settings", true, this.mainApplication);

        if (d != null) {

            d.setSize(new Dimension(700, 600));

            Dimension dialogSize = d.getPreferredSize();
            Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

            if (dialogSize.height > screenSize.height) {

                dialogSize.height = screenSize.height;
            }

            if (dialogSize.width > screenSize.width) {

                dialogSize.width = screenSize.width;
            }

            d.setLocation((screenSize.width - dialogSize.width) / 2, (screenSize.height - dialogSize.height) / 2);
            d.setVisible(true);

        } else {

            throw new NullPointerException("Could not create about dialog. About dialog is null.");
        }
*/
    }

    //
    // Change display mode.
    //

    /**
     * Changes the display mode.
     *
     * If the display mode is changed, the following will happen:
     * - the views of all child controllers of this controller are destroyed
     * - the view of this controller is destroyed
     * - the actual display mode value is set
     * - a new view for this controller is created
     * - new views for all child controllers of this controller are created
     *
     * @param mode the display mode
     * @exception NullPointerException if the view is null
     * @exception Exception if the given display mode does not exist
     */
    public void changeDisplayMode(Integer mode) throws Exception, NullPointerException {

/*??
        SwingView v = (SwingView) getView();

        if (v != null) {

            if ((mode == DisplayFactory.FRAME_DISPLAY)
                || (mode == DisplayFactory.INTERNAL_FRAME_DISPLAY)
                || (mode == DisplayFactory.TAB_PAGE_DISPLAY)) {

                if (mode != v.getDisplayMode()) {

                    // Hide view displays of all child controllers of this controller.
                    hideViews();

                    // Set display mode.
                    v.setDisplayMode(mode);
                    v.setChildApplicationComponent(null);

                    // Show view displays for all child controllers of this controller.
                    showViews();
                }

            } else {

                throw new Exception("Could not change display mode. The given display mode does not exist.");
            }

        } else {

            throw new NullPointerException("Could not change display mode. The view is null.");
        }
*/
    }

    /**
     * Show view displays for all application views.
     *
     * @exception NullPointerException if the child controller container is null
     */
    protected void showViews() throws Exception, NullPointerException {

/*??
        // Determine child controllers.
        List l = getChildren();

        if (l != null) {

            Object o = null;

            for (Integer i = 0; i < l.size(); i++) {

                // Determine child controller.
                o = l.get(i);

                if (o instanceof org.resmedicinae.resmedlib.System) {

//??                    ((org.resmedicinae.resmedlib.System) o).show((View) ((org.resmedicinae.resmedlib.System) o).getView());
                }
            }

        } else {

            throw new NullPointerException("Could not show view. The child controller container is null.");
        }
*/
    }

    /**
     * Hide view displays of all application views.
     *
     * @exception NullPointerException if the child controller container is null
     */
    protected void hideViews() throws Exception, NullPointerException {

/*??
        // Determine child controllers.
        List l = getChildren();

        if (l != null) {

            Object o = null;

            for (Integer i = 0; i < l.size(); i++) {

                // Determine child controller.
                o = l.get(i);

                if (o instanceof org.resmedicinae.resmedlib.System) {

//??                    ((org.resmedicinae.resmedlib.System) o).hide((View) ((org.resmedicinae.resmedlib.System) o).getView());
                }
            }

        } else {

            throw new NullPointerException("Could not hide view. The child controller container is null.");
        }
*/
    }
}

