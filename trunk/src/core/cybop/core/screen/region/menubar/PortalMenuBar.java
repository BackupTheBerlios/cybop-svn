/*
 * $RCSfile: PortalMenuBar.java,v $
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

import cybop.core.model.*;
import cybop.core.model.String;
import cybop.core.model.*;
import cybop.core.model.organizer.menu.*;

/**
 * This class represents a portal menu bar.
 *
 * @version $Revision: 1.2 $ $Date: 2003-05-20 06:21:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class PortalMenuBar extends MenuBar {

    //
    // Children names.
    //

    /** The systems menu. */
    public static final String SYSTEMS_MENU = new String("systems_menu");

    /** The editor menu. */
    public static final String EDITOR_MENU = new String("editor_menu");

    /** The view menu. */
    public static final String VIEW_MENU = new String("view_menu");

    /** The context menu. */
    public static final String CONTEXT_MENU = new String("context_menu");

    /** The settings menu. */
    public static final String SETTINGS_MENU = new String("settings_menu");

    /** The window menu. */
    public static final String WINDOW_MENU = new String("window_menu");

    /** The help menu. */
    public static final String HELP_MENU = new String("help_menu");

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

            if (n.isEqualTo(PortalMenuBar.SYSTEMS_MENU)) {

                setSystemsMenu((SystemsMenu) i);

/*??
            } else if (n.isEqualTo(PortalMenuBar.EDITOR_MENU)) {

                setEditorMenu((EditorMenu) i);

            } else if (n.isEqualTo(PortalMenuBar.VIEW_MENU)) {

                setViewMenu((ViewMenu) i);

            } else if (n.isEqualTo(PortalMenuBar.CONTEXT_MENU)) {

                setContextMenu((ContextMenu) i);

            } else if (n.isEqualTo(PortalMenuBar.SETTINGS_MENU)) {

                setSettingsMenu((SettingsMenu) i);

            } else if (n.isEqualTo(PortalMenuBar.WINDOW_MENU)) {

                setWindowMenu((WindowMenu) i);
*/

            } else if (n.isEqualTo(PortalMenuBar.HELP_MENU)) {

                setHelpMenu((HelpMenu) i);
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

            if (n.isEqualTo(PortalMenuBar.SYSTEMS_MENU)) {

                removeSystemsMenu((SystemsMenu) getChildItem(n));

/*??
            } else if (n.isEqualTo(PortalMenuBar.EDITOR_MENU)) {

                removeEditorMenu((EditorMenu) getChildItem(n));

            } else if (n.isEqualTo(PortalMenuBar.VIEW_MENU)) {

                removeViewMenu((ViewMenu) getChildItem(n));

            } else if (n.isEqualTo(PortalMenuBar.CONTEXT_MENU)) {

                removeContextMenu((ContextMenu) getChildItem(n));

            } else if (n.isEqualTo(PortalMenuBar.SETTINGS_MENU)) {

                removeSettingsMenu((SettingsMenu) getChildItem(n));

            } else if (n.isEqualTo(PortalMenuBar.WINDOW_MENU)) {

                removeWindowMenu((WindowMenu) getChildItem(n));
*/

            } else if (n.isEqualTo(PortalMenuBar.HELP_MENU)) {

                removeHelpMenu((HelpMenu) getChildItem(n));
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
     * Returns the default systems menu.
     *
     * It is based on the available system tree of the view's controller.
     * The system will be displayed as a menu hierarchy using the SystemMenu class.
     *
     * @return the default systems menu
     */
    public String getDefaultSystemsMenu() {

        return new String("cybop.core.model.organizer.menu.SystemsMenu");
/*??
        SystemsMenu m = new SystemsMenu();

        if (m != null) {

            m.initialize();
/*??
            SystemTreeNode n = null;

            m.setSystems(n);
            m.setControlId(Portal.CREATE_SYSTEM_SIGNAL_ID);
            m.setText("Healthcare");
            m.setMnemonic(KeyEvent.VK_E);
            m.setControlId(Portal.DESTROY_SYSTEM_SIGNAL_ID);
            //?? Clear this line up. Don't use getController() on view!
            m.setControlParameter((Object) v.getController());
            m.setEnabled(true);
            m.setText("Systems");
            m.setMnemonic(KeyEvent.VK_A);
*/
    }

    /**
     * Returns the default editor menu.
     *
     * @return the default editor menu
     */
    public String getDefaultEditorMenu() {

        return new String("cybop.core.model.organizer.menu.EditorMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        MenuItem cutMenuItem = new MenuItem();
        MenuItem copyMenuItem = new MenuItem();
        MenuItem pasteMenuItem = new MenuItem();

        // Initialize menu items.
        if (cutMenuItem != null) {

            cutMenuItem.setText("Cut");
            cutMenuItem.setMnemonic(KeyEvent.VK_U);
            cutMenuItem.setControlId(Portal.CUT_SIGNAL_ID);
            cutMenuItem.setOwner(getOwner());
            cutMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create editor menu. The cut menu item is null.");
        }

        if (copyMenuItem != null) {

            copyMenuItem.setText("Copy");
            copyMenuItem.setMnemonic(KeyEvent.VK_C);
            copyMenuItem.setControlId(Portal.COPY_SIGNAL_ID);
            copyMenuItem.setOwner(getOwner());
            copyMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create editor menu. The copy menu item is null.");
        }

        if (pasteMenuItem != null) {

            pasteMenuItem.setText("Paste");
            pasteMenuItem.setMnemonic(KeyEvent.VK_P);
            pasteMenuItem.setControlId(Portal.PASTE_SIGNAL_ID);
            pasteMenuItem.setOwner(getOwner());
            pasteMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create editor menu. The paste menu item is null.");
        }

        if (m != null) {

            // Initialize menu and add menu items.
            m.setText("Editor");
            m.setMnemonic(KeyEvent.VK_E);
            m.add(cutMenuItem);
            m.add(copyMenuItem);
            m.add(pasteMenuItem);

        } else {

            throw new Exception("Could not create editor menu. The editor menu is null.");
        }
*/
    }

    /**
     * Returns the default view menu.
     *
     * @return the default view menu
     */
    public String getDefaultViewMenu() {

        return new String("cybop.core.model.organizer.menu.ViewMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        CheckBoxMenuItem showToolBarMenuItem = new CheckBoxMenuItem();
        CheckBoxMenuItem showStatusBarMenuItem = new CheckBoxMenuItem();
        CheckBoxMenuItem showSystemTreeMenuItem = new CheckBoxMenuItem();

        // Initialize menu items.
        if (showToolBarMenuItem != null) {

            showToolBarMenuItem.setText("Show Tool Bar");
            showToolBarMenuItem.setMnemonic(KeyEvent.VK_T);
            showToolBarMenuItem.setControlId(Portal.SHOW_TOOL_BAR_SIGNAL_ID);
            showToolBarMenuItem.setOwner(getOwner());
            showToolBarMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create view menu. The show tool bar menu item is null.");
        }

        if (showStatusBarMenuItem != null) {

            showStatusBarMenuItem.setText("Show Status Bar");
            showStatusBarMenuItem.setMnemonic(KeyEvent.VK_S);
            showStatusBarMenuItem.setControlId(Portal.SHOW_STATUS_BAR_SIGNAL_ID);
            showStatusBarMenuItem.setOwner(getOwner());
            showStatusBarMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create view menu. The show status bar menu item is null.");
        }

        if (showSystemTreeMenuItem != null) {

            showSystemTreeMenuItem.setText("Show System Tree");
            showSystemTreeMenuItem.setMnemonic(KeyEvent.VK_M);
            showSystemTreeMenuItem.setControlId(Portal.SHOW_SYSTEM_TREE_SIGNAL_ID);
            showSystemTreeMenuItem.setOwner(getOwner());
            showSystemTreeMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create view menu. The show system tree menu item is null.");
        }

        if (m != null) {

            // Initialize menu and add menu items.
            m.setText("View");
            m.setMnemonic(KeyEvent.VK_V);
            m.add(showToolBarMenuItem);
            m.add(showStatusBarMenuItem);
            m.add(showSystemTreeMenuItem);

        } else {

            throw new Exception("Could not create view menu. The view menu is null.");
        }
*/
    }

    /**
     * Returns the default context menu.
     *
     * @return the default context menu
     */
    public String getDefaultContextMenu() {

        return new String("cybop.core.model.organizer.menu.ContextMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();

        if (m != null)
        {

/*??
            // Initialize menu and add menu items.
            m.setText("Context");
            m.setMnemonic(KeyEvent.VK_C);
            m.addSeparator();
*/
    }

    /**
     * Returns the default settings menu.
     *
     * @return the default settings menu
     */
    public String getDefaultSettingsMenu() {

        return new String("cybop.core.model.organizer.menu.SettingsMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        MenuItem configureMenuBarMenuItem = new MenuItem();
        MenuItem configureToolBarMenuItem = new MenuItem();
        MenuItem configureStatusBarMenuItem = new MenuItem();
        MenuItem configureKeyBindingsMenuItem = new MenuItem();
        MenuItem configureSystemTreeMenuItem = new MenuItem();
        MenuItem configureResMedicinaeMenuItem = new MenuItem();

        // Initialize menu items.
        if (configureMenuBarMenuItem != null) {

            configureMenuBarMenuItem.setText("Configure Menu Bar...");
            configureMenuBarMenuItem.setMnemonic(KeyEvent.VK_E);
            configureMenuBarMenuItem.setControlId(Portal.CONFIGURE_MENU_BAR_SIGNAL_ID);
            configureMenuBarMenuItem.setOwner(getOwner());
            configureMenuBarMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create settings menu. The configure menu bar menu item is null.");
        }

        if (configureToolBarMenuItem != null) {

            configureToolBarMenuItem.setText("Configure Tool Bars...");
            configureToolBarMenuItem.setMnemonic(KeyEvent.VK_T);
            configureToolBarMenuItem.setControlId(Portal.CONFIGURE_TOOL_BAR_SIGNAL_ID);
            configureToolBarMenuItem.setOwner(getOwner());
            configureToolBarMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create settings menu. The configure tool bar menu item is null.");
        }

        if (configureStatusBarMenuItem != null) {

            configureStatusBarMenuItem.setText("Configure Status Bar...");
            configureStatusBarMenuItem.setMnemonic(KeyEvent.VK_U);
            configureStatusBarMenuItem.setControlId(Portal.CONFIGURE_STATUS_BAR_SIGNAL_ID);
            configureStatusBarMenuItem.setOwner(getOwner());
            configureStatusBarMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create settings menu. The configure status bar menu item is null.");
        }

        if (configureKeyBindingsMenuItem != null) {

            configureKeyBindingsMenuItem.setText("Configure Key Bindings...");
            configureKeyBindingsMenuItem.setMnemonic(KeyEvent.VK_K);
            configureKeyBindingsMenuItem.setControlId(Portal.CONFIGURE_KEY_BINDINGS_SIGNAL_ID);
            configureKeyBindingsMenuItem.setOwner(getOwner());
            configureKeyBindingsMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create settings menu. The configure key bindings menu item is null.");
        }

        if (configureSystemTreeMenuItem != null) {

            configureSystemTreeMenuItem.setText("Configure System Tree...");
            configureSystemTreeMenuItem.setMnemonic(KeyEvent.VK_C);
            configureSystemTreeMenuItem.setControlId(Portal.CONFIGURE_SYSTEM_TREE_SIGNAL_ID);
            configureSystemTreeMenuItem.setOwner(getOwner());
            configureSystemTreeMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create settings menu. The configure system tree menu item is null.");
        }

        if (configureResMedicinaeMenuItem != null) {

            configureResMedicinaeMenuItem.setText("Configure Res Medicinae...");
            configureResMedicinaeMenuItem.setMnemonic(KeyEvent.VK_S);
            configureResMedicinaeMenuItem.setControlId(Portal.CONFIGURE_RES_MEDICINAE_SIGNAL_ID);
            configureResMedicinaeMenuItem.setOwner(getOwner());
            configureResMedicinaeMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create settings menu. The configure res medicinae menu item is null.");
        }

        if (m != null) {

            // Initialize settings menu and add menu items.
            m.setText("Settings");
            m.setMnemonic(KeyEvent.VK_S);
            m.add(configureMenuBarMenuItem);
            m.add(configureToolBarMenuItem);
            m.add(configureStatusBarMenuItem);
            m.add(configureKeyBindingsMenuItem);
            m.addSeparator();
            m.add(configureSystemTreeMenuItem);
            m.add(configureResMedicinaeMenuItem);

        } else {

            throw new Exception("Could not create settings menu. The settings menu is null.");
        }
*/
    }

    /**
     * Returns the default window menu.
     *
     * @return the default window menu
     */
    public String getDefaultWindowMenu() {

        return new String("cybop.core.model.organizer.menu.WindowMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        MenuItem iconifyAllMenuItem = new MenuItem();
        MenuItem closeMenuItem = new MenuItem();
        MenuItem closeAllMenuItem = new MenuItem();

        // Initialize menu items.
        if (iconifyAllMenuItem != null) {

            iconifyAllMenuItem.setText("Iconify all");
            iconifyAllMenuItem.setMnemonic(KeyEvent.VK_I);
            iconifyAllMenuItem.setControlId(Portal.ICONIFY_ALL_SIGNAL_ID);
            iconifyAllMenuItem.setOwner(getOwner());
            iconifyAllMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create window menu. The iconify all menu item is null.");
        }

        if (closeMenuItem != null) {

            closeMenuItem.setText("Close");
            closeMenuItem.setMnemonic(KeyEvent.VK_C);
            closeMenuItem.setControlId(Portal.CLOSE_SIGNAL_ID);
            closeMenuItem.setOwner(getOwner());
            closeMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create window menu. The close menu item is null.");
        }

        if (closeAllMenuItem != null) {

            closeAllMenuItem.setText("Close all");
            closeAllMenuItem.setMnemonic(KeyEvent.VK_A);
            closeAllMenuItem.setControlId(Portal.CLOSE_ALL_SIGNAL_ID);
            closeAllMenuItem.setOwner(getOwner());
            closeAllMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create window menu. The close all menu item is null.");
        }

        if (m != null) {

            // Initialize window menu and add menu items.
            m.setText("Window");
            m.setMnemonic(KeyEvent.VK_W);
            m.add(iconifyAllMenuItem);
            m.add(closeMenuItem);
            m.add(closeAllMenuItem);
            m.addSeparator();
            m.add(createPlacingMenu());
            m.addSeparator();
            m.add(createModeMenu());

        } else {

            throw new Exception("Could not create window menu. The window menu is null.");
        }
*/
    }

    /**
     * Returns the default help menu.
     *
     * @return the default help menu
     */
    public String getDefaultHelpMenu() {

        return new String("cybop.core.model.organizer.menu.HelpMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        MenuItem showContentsMenuItem = new MenuItem();
        MenuItem reportBugMenuItem = new MenuItem();
        MenuItem informAboutResMedicinaeMenuItem = new MenuItem();

        // Initialize menu items.
        if (showContentsMenuItem != null) {

            showContentsMenuItem.setText("Show Contents...");
            showContentsMenuItem.setMnemonic(KeyEvent.VK_C);
            showContentsMenuItem.setControlId(Portal.SHOW_HELP_CONTENTS_SIGNAL_ID);
            showContentsMenuItem.setOwner(getOwner());
            showContentsMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create help menu. The show contents menu item is null.");
        }

        if (reportBugMenuItem != null) {

            reportBugMenuItem.setText("Report Bug...");
            reportBugMenuItem.setMnemonic(KeyEvent.VK_R);
            reportBugMenuItem.setControlId(Portal.REPORT_BUG_SIGNAL_ID);
            reportBugMenuItem.setOwner(getOwner());
            reportBugMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create help menu. The report bug menu item is null.");
        }

        if (informAboutResMedicinaeMenuItem != null) {

            informAboutResMedicinaeMenuItem.setText("Inform About ResMedicinae...");
            informAboutResMedicinaeMenuItem.setMnemonic(KeyEvent.VK_A);
            informAboutResMedicinaeMenuItem.setControlId(AboutDialog.CREATE_ABOUT_DIALOG_SIGNAL_ID);
            informAboutResMedicinaeMenuItem.setOwner(getOwner());
            informAboutResMedicinaeMenuItem.setEnabled(true);
            //?? Temporary!
            informAboutResMedicinaeMenuItem.addActionListener((Portal) getController());
            informAboutResMedicinaeMenuItem.setActionCommand(AboutDialog.CREATE_ABOUT_DIALOG_SIGNAL_ID);

        } else {

            throw new Exception("Could not create help menu. The inform about res medicinae menu item is null.");
        }

        if (m != null) {

            // Initialize help menu and add menu items.
            m.setText("Help");
            m.setMnemonic(KeyEvent.VK_H);
            m.add(showContentsMenuItem);
            m.addSeparator();
            m.add(reportBugMenuItem);
            m.addSeparator();
            m.add(informAboutResMedicinaeMenuItem);

        } else {

            throw new Exception("Could not create help menu. The help menu is null.");
        }
*/
    }

    //
    // Systems menu.
    //

    /**
     * Sets the systems menu.
     *
     * @param m the systems menu
     * @exception Exception if the java menu bar is null
     * @exception Exception if the systems menu is null
     */
    public void setSystemsMenu(SystemsMenu m) throws Exception {

        javax.swing.JMenuBar mb = (javax.swing.JMenuBar) getJavaObject();

        if (mb != null) {

            if (m != null) {

                mb.add((javax.swing.JMenu) m.getJavaObject());

            } else {
    
                throw new Exception("Could not set systems menu. The systems menu is null.");
            }

        } else {

            throw new Exception("Could not set systems menu. The java menu bar is null.");
        }
    }

    /**
     * Removes the systems menu.
     *
     * @param m the systems menu
     * @exception Exception if the java menu bar is null
     * @exception Exception if the systems menu is null
     */
    public void removeSystemsMenu(SystemsMenu m) throws Exception {

        javax.swing.JMenuBar mb = (javax.swing.JMenuBar) getJavaObject();

        if (mb != null) {

            if (m != null) {

                mb.remove((javax.swing.JMenu) m.getJavaObject());

            } else {
    
                throw new Exception("Could not remove systems menu. The systems menu is null.");
            }

        } else {

            throw new Exception("Could not remove systems menu. The java menu bar is null.");
        }
    }

    //
    // Help menu.
    //

    /**
     * Sets the help menu.
     *
     * @param m the help menu
     * @exception Exception if the java menu bar is null
     * @exception Exception if the help menu is null
     */
    public void setHelpMenu(HelpMenu m) throws Exception {

        javax.swing.JMenuBar mb = (javax.swing.JMenuBar) getJavaObject();

        if (mb != null) {

            if (m != null) {

                mb.add((javax.swing.JMenu) m.getJavaObject());

            } else {
    
                throw new Exception("Could not set help menu. The help menu is null.");
            }

        } else {

            throw new Exception("Could not set help menu. The java menu bar is null.");
        }
    }

    /**
     * Removes the help menu.
     *
     * @param m the help menu
     * @exception Exception if the java menu bar is null
     * @exception Exception if the help menu is null
     */
    public void removeHelpMenu(HelpMenu m) throws Exception {

        javax.swing.JMenuBar mb = (javax.swing.JMenuBar) getJavaObject();

        if (mb != null) {

            if (m != null) {

                mb.remove((javax.swing.JMenu) m.getJavaObject());

            } else {
    
                throw new Exception("Could not remove help menu. The help menu is null.");
            }

        } else {

            throw new Exception("Could not remove help menu. The java menu bar is null.");
        }
    }

//?? =========================================

    /**
     * Returns the default placing menu.
     *
     * @return the default placing menu
     */
    public String getDefaultPlacingMenu() {

        return new String("cybop.core.model.organizer.menu.PlacingMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        MenuItem cascadeMenuItem = new MenuItem();
        MenuItem tileVerticallyMenuItem = new MenuItem();
        MenuItem tileHorizontallyMenuItem = new MenuItem();

        // Initialize menu items.
        if (cascadeMenuItem != null) {

            cascadeMenuItem.setText("Cascade");
            cascadeMenuItem.setMnemonic(KeyEvent.VK_C);
            cascadeMenuItem.setControlId(Portal.CASCADE_SIGNAL_ID);
            cascadeMenuItem.setOwner(getOwner());
            cascadeMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create placing menu. The cascade menu item is null.");
        }

        if (tileVerticallyMenuItem != null) {

            tileVerticallyMenuItem.setText("Tile vertically");
            tileVerticallyMenuItem.setMnemonic(KeyEvent.VK_V);
            tileVerticallyMenuItem.setControlId(Portal.TILE_VERTICALLY_SIGNAL_ID);
            tileVerticallyMenuItem.setOwner(getOwner());
            tileVerticallyMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create placing menu. The tile vertically menu item is null.");
        }

        if (tileHorizontallyMenuItem != null) {

            tileHorizontallyMenuItem.setText("Tile horizontally");
            tileHorizontallyMenuItem.setMnemonic(KeyEvent.VK_H);
            tileHorizontallyMenuItem.setControlId(Portal.TILE_HORIZONTALLY_SIGNAL_ID);
            tileHorizontallyMenuItem.setOwner(getOwner());
            tileHorizontallyMenuItem.setEnabled(false);

        } else {

            throw new Exception("Could not create placing menu. The tile horizontally menu item is null.");
        }

        if (m != null) {

            // Initialize placing menu and add menu items.
            m.setText("Placing");
            m.setMnemonic(KeyEvent.VK_P);
            m.add(cascadeMenuItem);
            m.add(tileVerticallyMenuItem);
            m.add(tileHorizontallyMenuItem);

        } else {

            throw new Exception("Could not create placing menu. The placing menu is null.");
        }
*/
    }

    /**
     * Returns the default mode menu.
     *
     * @return the default mode menu
     */
    public String getDefaultModeMenu() {

        return new String("cybop.core.model.organizer.menu.ModeMenu");

/*??
        // Create menu and its menu items.
        Menu m = new Menu();
/*??
        RadioButtonMenuItem setFrameDisplayMenuItem = new RadioButtonMenuItem();
        RadioButtonMenuItem setInternalFrameDisplayMenuItem = new RadioButtonMenuItem();
        RadioButtonMenuItem setTabPageDisplayMenuItem = new RadioButtonMenuItem();
*/
/*??
        MenuItem setFrameDisplayMenuItem = new MenuItem();
        MenuItem setInternalFrameDisplayMenuItem = new MenuItem();
        MenuItem setTabPageDisplayMenuItem = new MenuItem();

        // Initialize menu items.
        if (setFrameDisplayMenuItem != null) {

            setFrameDisplayMenuItem.setText("Set Frame Display");
            setFrameDisplayMenuItem.setMnemonic(KeyEvent.VK_F);
            setFrameDisplayMenuItem.setControlId(Portal.SET_FRAME_DISPLAY_SIGNAL_ID);
            setFrameDisplayMenuItem.setOwner(getOwner());
            setFrameDisplayMenuItem.setEnabled(true);
            //?? Temporary!
            setFrameDisplayMenuItem.addActionListener((Portal) getController());
            setFrameDisplayMenuItem.setActionCommand(Portal.SET_FRAME_DISPLAY_SIGNAL_ID);

        } else {

            throw new Exception("Could not create mode menu. The set frame display menu item is null.");
        }

        if (setInternalFrameDisplayMenuItem != null) {

            setInternalFrameDisplayMenuItem.setText("Set Internal Frame Display");
            setInternalFrameDisplayMenuItem.setMnemonic(KeyEvent.VK_I);
            setInternalFrameDisplayMenuItem.setControlId(Portal.SET_INTERNAL_FRAME_DISPLAY_SIGNAL_ID);
            setInternalFrameDisplayMenuItem.setOwner(getOwner());
            setInternalFrameDisplayMenuItem.setEnabled(true);
            //?? Temporary!
            setFrameDisplayMenuItem.addActionListener((Portal) getController());
            setFrameDisplayMenuItem.setActionCommand(Portal.SET_INTERNAL_FRAME_DISPLAY_SIGNAL_ID);

        } else {

            throw new Exception("Could not create mode menu. The set internal frame display menu item is null.");
        }

        if (setTabPageDisplayMenuItem != null) {

            setTabPageDisplayMenuItem.setText("Set Tab Page Display");
            setTabPageDisplayMenuItem.setMnemonic(KeyEvent.VK_T);
            setTabPageDisplayMenuItem.setControlId(Portal.SET_TAB_PAGE_DISPLAY_SIGNAL_ID);
            setTabPageDisplayMenuItem.setOwner(getOwner());
            setTabPageDisplayMenuItem.setEnabled(true);
            //?? Temporary!
            setFrameDisplayMenuItem.addActionListener((Portal) getController());
            setFrameDisplayMenuItem.setActionCommand(Portal.SET_TAB_PAGE_DISPLAY_SIGNAL_ID);

        } else {

            throw new Exception("Could not create mode menu. The set tab page display menu item is null.");
        }

        if (m != null) {

            // Initialize mode menu and add menu items.
            m.setText("Mode");
            m.setMnemonic(KeyEvent.VK_M);
            m.add(setFrameDisplayMenuItem);
            m.add(setInternalFrameDisplayMenuItem);
            m.add(setTabPageDisplayMenuItem);

        } else {

            throw new Exception("Could not create mode menu. The mode menu is null.");
        }
*/
    }

    //
    // Initializable.
    //

    /**
     * Initializes this portal menu bar.
     */
    public void initialize() throws Exception {

/*??
        // Determine system tree model.
        TreeModel m = main.getAvailableSystems();

        if (m != null) {

            // Register this menu bar as tree model listener.
            m.addTreeModelListener(this);
        }

        // Set system tree model.
        setSystemTreeModel(m);
*/

/*??
        m.add(createSystemsMenu());
        m.addSeparator();
        m.add(createExitMenuItem());
*/

        setChildItem(PortalMenuBar.SYSTEMS_MENU, createChildItem(getDefaultSystemsMenu()));
/*??
        setChildItem(PortalMenuBar.EDITOR_MENU, createChildItem(getDefaultEditorMenu()));
        setChildItem(PortalMenuBar.VIEW_MENU, createChildItem(getDefaultViewMenu()));
        setChildItem(PortalMenuBar.CONTEXT_MENU, createChildItem(getDefaultContextMenu()));
        setChildItem(PortalMenuBar.SETTINGS_MENU, createChildItem(getDefaultSettingsMenu()));
        setChildItem(PortalMenuBar.WINDOW_MENU, createChildItem(getDefaultWindowMenu()));
*/
        setChildItem(PortalMenuBar.HELP_MENU, createChildItem(getDefaultHelpMenu()));
    }

    /**
     * Finalizes this portal menu bar.
     */
    public void finalizz() throws Exception {

        HelpMenu helpMenu = (HelpMenu) getChildItem(PortalMenuBar.HELP_MENU);
        removeChildItem(PortalMenuBar.HELP_MENU);
        destroyChildItem(helpMenu);

/*??
        removeChildItem(PortalMenuBar.WINDOW_MENU);
        destroyChildItem((WindowMenu) getChildItem(PortalMenuBar.WINDOW_MENU));

        removeChildItem(PortalMenuBar.SETTINGS_MENU);
        destroyChildItem((SettingsMenu) getChildItem(PortalMenuBar.SETTINGS_MENU));

        removeChildItem(PortalMenuBar.CONTEXT_MENU);
        destroyChildItem((ContextMenu) getChildItem(PortalMenuBar.CONTEXT_MENU));

        removeChildItem(PortalMenuBar.VIEW_MENU);
        destroyChildItem((ViewMenu) getChildItem(PortalMenuBar.VIEW_MENU));

        removeChildItem(PortalMenuBar.EDITOR_MENU);
        destroyChildItem((EditorMenu) getChildItem(PortalMenuBar.EDITOR_MENU));
*/

        SystemsMenu systemsMenu = (SystemsMenu) getChildItem(PortalMenuBar.SYSTEMS_MENU);
        removeChildItem(PortalMenuBar.SYSTEMS_MENU);
        destroyChildItem(systemsMenu);
    }
}

