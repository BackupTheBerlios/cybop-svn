/*
 * $RCSfile: FrameDisplay.java,v $
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

package cybop.core.screen.model;

import cybop.core.category.*;
import cybop.core.model.*;
import cybop.core.model.Boolean;
import cybop.core.model.Integer;
import cybop.core.model.String;
import cybop.core.screen.*;
import cybop.core.screen.region.*;

/**
 * This class represents a frame model.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-17 08:21:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class FrameModel extends Display {

    //
    // Children names.
    //

    /** The user interface mode. */
    public static final String USER_INTERFACE_MODE = new String("user_interface_mode");

    /** The title. */
    public static final String TITLE = new String("title");

    /** The icon. */
    public static final String ICON = new String("icon");

    /** The menu bar. */
    public static final String MENU_BAR = new String("menu_bar");

    /** The tool bar. */
    public static final String TOOL_BAR = new String("tool_bar");

    /** The contents panel. */
    public static final String CONTENTS_PANEL = new String("contents_panel");

    /** The status bar. */
    public static final String STATUS_BAR = new String("status_bar");

    /** The bounds. */
    public static final String BOUNDS = new String("bounds");

    /** The bounds of the user interface. */
    private java.awt.Rectangle bounds;

    /** The resizable flag. */
    public static final String RESIZABLE_FLAG = new String("resizable");

    /** The look and feel. */
    public static final String LOOK_AND_FEEL = new String("look_and_feel");

    //
    // User interface modes.
    //

    /** The applet user interface mode. */
    public static final Integer APPLET_MODE = new Integer(0);

    /** The window user interface mode. */
    public static final Integer WINDOW_MODE = new Integer(1);

    /** The modal dialog user interface mode. */
    public static final Integer MODAL_DIALOG_MODE = new Integer(2);

    /** The modeless dialog user interface mode. */
    public static final Integer MODELESS_DIALOG_MODE = new Integer(3);

    /** The frame user interface mode. */
    public static final Integer FRAME_MODE = new Integer(4);

    /** The internal frame user interface mode. */
    public static final Integer INTERNAL_FRAME_MODE = new Integer(5);

    /** The tab page user interface mode. */
    public static final Integer TAB_PAGE_MODE = new Integer(6);

    //
    // Encapsulated java swing window/dialog/frame/internal frame/tab page.
    //

    /**
     * Creates an encapsulated java swing window/dialog/frame/internal frame/tab page.
     *
     * @return the encapsulated java swing window/dialog/frame/internal frame/tab page
     */
    public java.lang.Object createJavaObject() {

        java.awt.Container c = null;
/*??
        Integer i = (Integer) getChild(UserInterface.USER_INTERFACE_MODE);

        if (i != null) {

            if (i.isEqualTo(UserInterface.APPLET_MODE)) {
    
                c = new javax.swing.JApplet();
    
            } else if (i.isEqualTo(UserInterface.WINDOW_MODE)) {
    
                c = new javax.swing.JWindow();
    
            } else if (i.isEqualTo(UserInterface.MODAL_DIALOG_MODE)) {
    
                c = new javax.swing.JDialog();
    
            } else if (i.isEqualTo(UserInterface.MODELESS_DIALOG_MODE)) {
    
                c = new javax.swing.JDialog();
    
            } else if (i.isEqualTo(UserInterface.FRAME_MODE)) {
*/
    
                c = new javax.swing.JFrame();

                if (c != null) {
        
                    c.setSize(600, 400); 

                } else {
        
                    throw new Exception("Could not create encapsulated java swing frame. The encapsulated java swing frame is null.");
                }

/*??
            } else if (i.isEqualTo(UserInterface.INTERNAL_FRAME_MODE)) {
    
                c = new javax.swing.JInternalFrame();
    
            } else if (i.isEqualTo(UserInterface.TAB_PAGE_MODE)) {
    
                c = new javax.swing.JPanel();
            }

        } else {

            throw new Exception("Could not create frame. The user interface mode is null.");
        }
*/

        return c;
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

            if (n.isEqualTo(UserInterface.TITLE)) {

                setTitle((String) i);

            } else if (n.isEqualTo(UserInterface.ICON)) {

                setIcon((String) i);

            } else if (n.isEqualTo(UserInterface.MENU_BAR)) {

                setMenuBar((MenuBar) i);

            } else if (n.isEqualTo(UserInterface.TOOL_BAR)) {

                setToolBar((ToolBar) i);

            } else if (n.isEqualTo(UserInterface.CONTENTS_PANEL)) {

                setContentsPanel((DisplayRegion) i);

            } else if (n.isEqualTo(UserInterface.STATUS_BAR)) {     

                setStatusBar((StatusBar) i);

            } else if (n.isEqualTo(UserInterface.BOUNDS)) {

//??                setBounds((java.awt.Rectangle) i);
                java.lang.System.out.println("WARNING: Bounds not set. Replace java.awt.Rectangle");

            } else if (n.isEqualTo(UserInterface.RESIZABLE_FLAG)) {

                setResizable((Boolean) i);
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

            if (n.isEqualTo(UserInterface.TITLE)) {

                removeTitle((String) getChild(n));

            } else if (n.isEqualTo(UserInterface.ICON)) {

                removeIcon((String) getChild(n));

            } else if (n.isEqualTo(UserInterface.MENU_BAR)) {

                removeMenuBar((MenuBar) getChild(n));

            } else if (n.isEqualTo(UserInterface.TOOL_BAR)) {

                removeToolBar((ToolBar) getChild(n));

            } else if (n.isEqualTo(UserInterface.CONTENTS_PANEL)) {

                removeContentsPanel((DisplayRegion) getChild(n));

            } else if (n.isEqualTo(UserInterface.STATUS_BAR)) {

                removeStatusBar((StatusBar) getChild(n));

            } else if (n.isEqualTo(UserInterface.BOUNDS)) {

//??                    removeBounds((java.awt.Rectangle) getChild(n));
                java.lang.System.out.println("WARNING: Bounds not set. Replace java.awt.Rectangle");

            } else if (n.isEqualTo(UserInterface.RESIZABLE_FLAG)) {
                
                removeResizable((Boolean) getChild(n));
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
     * Returns the default user interface mode.
     *
     * The default is: System.INTERNAL_FRAME_MODE
     *
     * @return the default user interface mode
     */
    public Integer getDefaultUserInterfaceMode() {

        return UserInterface.FRAME_MODE;
    }

    /**
     * Returns the default title.
     *
     * @return the default title
     */
    public String getDefaultTitle() {

        return new String("Res Medicinae");
    }

    /**
     * Returns the default icon.
     *
     * @return the default icon
     */
    public String getDefaultIcon() {

        return new String("icon");
    }

    /**
     * Returns the default menu bar.
     *
     * @return the default menu bar
     */
    public String getDefaultMenuBar() {

        return new String("cybop.core.model.organizer.MenuBar");
    }

    /**
     * Returns the default tool bar.
     *
     * @return the default tool bar
     */
    public String getDefaultToolBar() {

        return new String("cybop.core.model.organizer.ToolBar");
    }

    /**
     * Returns the default contents panel.
     *
     * @return the default contents panel
     */
    public String getDefaultContentsPanel() {

        return new String("cybop.core.model.organizer.DisplayRegion");
    }

    /**
     * Returns the default status bar.
     *
     * @return the default status bar
     */
    public String getDefaultStatusBar() {

        return new String("cybop.core.model.organizer.StatusBar");
    }

    /**
     * Returns the default rectangle storing the bounds.
     *
     * @return the default rectangle storing the bounds
     */
    public java.awt.Rectangle getDefaultBounds() {

        // Determine width.
        int w = (int) Math.floor(java.awt.Toolkit.getDefaultToolkit().getScreenSize().getWidth());

        // Use centered x position by default.
        int x = 0;

        // Determine height.
        int h = (int) Math.floor(java.awt.Toolkit.getDefaultToolkit().getScreenSize().getHeight());

        // Use centered y position by default.
        int y = 0;

        return new java.awt.Rectangle(x, y, w, h);
    }

    /**
     * Returns the default resizable flag.
     *
     * @return the default resizable flag
     */
    public Boolean getDefaultResizableFlag() {

        return new Boolean(Boolean.TRUE);
    }

    /**
     * Returns the default look and feel.
     *
     * @return the default look and feel
     */
    public javax.swing.LookAndFeel getDefaultLookAndFeel() {

        return new javax.swing.plaf.metal.MetalLookAndFeel();
    }

    //
    // Title.
    //

    /**
     * Sets the title.
     *
     * @param t the title
     * @exception Exception if the java frame is null
     * @exception Exception if the title is null
     */
    public void setTitle(String t) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();

        if (f != null) {

            if (t != null) {
                
                f.setTitle((java.lang.String) t.getJavaObject());

            } else {
    
                throw new Exception("Could not set title. The title is null.");
            }

        } else {

            throw new Exception("Could not set title. The java frame is null.");
        }
    }

    /**
     * Removes the title.
     *
     * @param t the title
     * @exception Exception if the java frame is null
     * @exception Exception if the title is null
     */
    public void removeTitle(String t) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();

        if (f != null) {

            if (t != null) {
                
                f.setTitle(null);

            } else {
    
                throw new Exception("Could not set title. The title is null.");
            }

        } else {

            throw new Exception("Could not set title. The java frame is null.");
        }
    }

    //
    // Icon.
    //

    /**
     * Sets the icon.
     *
     * @param i the icon
     * @exception Exception if the java frame is null
     * @exception Exception if the icon is null
     */
    public void setIcon(String i) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (i != null) {
                
//??                f.setIconImage(i.getJavaObject());

            } else {
    
                throw new Exception("Could not set icon. The icon is null.");
            }

        } else {

            throw new Exception("Could not set icon. The java frame is null.");
        }
    }

    /**
     * Removes the icon.
     *
     * @param i the icon
     * @exception Exception if the java frame is null
     * @exception Exception if the icon is null
     */
    public void removeIcon(String i) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (i != null) {
                
//??                f.setIconImage(null);

            } else {
    
                throw new Exception("Could not set icon. The icon is null.");
            }

        } else {

            throw new Exception("Could not set icon. The java frame is null.");
        }
    }

    //
    // Menu bar.
    //

    /**
     * Sets the menu bar.
     *
     * @param m the menu bar
     * @exception Exception if the java frame is null
     * @exception Exception if the menu bar is null
     */
    public void setMenuBar(MenuBar m) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (m != null) {
                
                f.setJMenuBar((javax.swing.JMenuBar) m.getJavaObject());

            } else {
    
                throw new Exception("Could not set menu bar. The menu bar is null.");
            }

        } else {

            throw new Exception("Could not set menu bar. The java frame is null.");
        }
    }

    /**
     * Removes the menu bar.
     *
     * @param m the menu bar
     * @exception Exception if the java frame is null
     * @exception Exception if the menu bar is null
     */
    public void removeMenuBar(MenuBar m) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (m != null) {
                
                f.setJMenuBar(null);

            } else {
    
                throw new Exception("Could not set menu bar. The menu bar is null.");
            }

        } else {

            throw new Exception("Could not set menu bar. The java frame is null.");
        }
    }

    //
    // Tool bar.
    //

    /**
     * Sets the tool bar.
     *
     * @param t the tool bar
     * @exception Exception if the java frame is null
     * @exception Exception if the tool bar is null
     * @exception Exception if the content pane is null
     */
    public void setToolBar(ToolBar t) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (t != null) {

                java.awt.Container cp = f.getContentPane();
                
                if (cp != null) {
                    
                    cp.add((javax.swing.JToolBar) t.getJavaObject(), java.awt.BorderLayout.NORTH);

                } else {
        
                    throw new Exception("Could not set tool bar. The content pane is null.");
                }

            } else {
    
                throw new Exception("Could not set tool bar. The tool bar is null.");
            }

        } else {

            throw new Exception("Could not set tool bar. The java frame is null.");
        }
    }

    /**
     * Removes the tool bar.
     *
     * @param t the tool bar
     * @exception Exception if the java frame is null
     * @exception Exception if the tool bar is null
     * @exception Exception if the content pane is null
     */
    public void removeToolBar(ToolBar t) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (t != null) {

                java.awt.Container cp = f.getContentPane();
                
                if (cp != null) {
                    
                    cp.remove((javax.swing.JToolBar) t.getJavaObject());

                } else {
        
                    throw new Exception("Could not set tool bar. The content pane is null.");
                }

            } else {
    
                throw new Exception("Could not set tool bar. The tool bar is null.");
            }

        } else {

            throw new Exception("Could not set tool bar. The java frame is null.");
        }
    }

    //
    // Contents panel.
    //

    /**
     * Sets the contents panel.
     *
     * @param c the contents panel
     * @exception Exception if the java frame is null
     * @exception Exception if the contents panel is null
     * @exception Exception if the content pane is null
     */
    public void setContentsPanel(DisplayRegion c) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();

        if (f != null) {

            if (c != null) {
                
                java.awt.Container cp = f.getContentPane();
                
                if (cp != null) {
                    
                    cp.add((javax.swing.JPanel) c.getJavaObject(), java.awt.BorderLayout.CENTER);

                } else {
        
                    throw new Exception("Could not set contents panel. The content pane is null.");
                }

            } else {
    
                throw new Exception("Could not set contents panel. The contents panel is null.");
            }

        } else {

            throw new Exception("Could not set contents panel. The java frame is null.");
        }
    }

    /**
     * Removes the contents panel.
     *
     * @param c the contents panel
     * @exception Exception if the java frame is null
     * @exception Exception if the contents panel is null
     * @exception Exception if the content pane is null
     */
    public void removeContentsPanel(DisplayRegion c) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();

        if (f != null) {

            if (c != null) {
                
                java.awt.Container cp = f.getContentPane();
                
                if (cp != null) {
                    
                    cp.remove((javax.swing.JPanel) c.getJavaObject());

                } else {
        
                    throw new Exception("Could not set contents panel. The content pane is null.");
                }

            } else {
    
                throw new Exception("Could not set contents panel. The contents panel is null.");
            }

        } else {

            throw new Exception("Could not set contents panel. The java frame is null.");
        }
    }

    //
    // Status bar.
    //

    /**
     * Sets the status bar.
     *
     * @param s the status bar
     * @exception Exception if the java frame is null
     * @exception Exception if the status bar is null
     * @exception Exception if the content pane is null
     */
    public void setStatusBar(StatusBar s) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (s != null) {
                
                java.awt.Container cp = f.getContentPane();
                
                if (cp != null) {

                    cp.add((javax.swing.JLabel) s.getJavaObject(), java.awt.BorderLayout.SOUTH);

                } else {
        
                    throw new Exception("Could not set status bar. The content pane is null.");
                }

            } else {
    
                throw new Exception("Could not set status bar. The status bar is null.");
            }

        } else {

            throw new Exception("Could not set status bar. The java frame is null.");
        }
    }

    /**
     * Removes the status bar.
     *
     * @param s the status bar
     * @exception Exception if the java frame is null
     * @exception Exception if the status bar is null
     * @exception Exception if the content pane is null
     */
    public void removeStatusBar(StatusBar s) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (s != null) {
                
                java.awt.Container cp = f.getContentPane();
                
                if (cp != null) {
                    
                    cp.remove((javax.swing.JLabel) s.getJavaObject());

                } else {
        
                    throw new Exception("Could not set status bar. The content pane is null.");
                }

            } else {
    
                throw new Exception("Could not set status bar. The status bar is null.");
            }

        } else {

            throw new Exception("Could not set status bar. The java frame is null.");
        }
    }

    //
    // Bounds.
    //

    /**
     * Sets the bounds.
     *
     * @param b the bounds
     * @exception Exception if the java frame is null
     * @exception Exception if the bounds is null
     */
    public void setBounds(java.awt.Rectangle b) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (b != null) {
                
//??                f.setBounds(b.getJavaObject());

            } else {
    
                throw new Exception("Could not set bounds. The bounds is null.");
            }

        } else {

            throw new Exception("Could not set bounds. The java frame is null.");
        }
    }

    /**
     * Removes the bounds.
     *
     * @param b the bounds
     * @exception Exception if the java frame is null
     * @exception Exception if the bounds is null
     */
    public void removeBounds(java.awt.Rectangle b) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (b != null) {

//??                f.removeBounds(b.getJavaObject());

            } else {
    
                throw new Exception("Could not set bounds. The bounds is null.");
            }

        } else {

            throw new Exception("Could not set bounds. The java frame is null.");
        }
    }

    /**
     * Configures the bounds.
     *
     * @param def the default bounds
     * @return the bounds
     * @exception Exception if the configuration is null
     * @exception Exception if the default bounds is null
     */
    public java.awt.Rectangle configureBounds(java.awt.Rectangle def) throws Exception {

/*??
        java.awt.Rectangle r = def;
        Configuration c = (Configuration) getChild(UserInterface.CONFIGURATION);

        if (c != null) {

            if (def != null) {
    
                int x = c.getWindowX((int) Math.floor(def.getX()));
                int y = c.getWindowY((int) Math.floor(def.getY()));
                int w = c.getWindowWidth((int) Math.floor(def.getWidth()));
                int h = c.getWindowHeight((int) Math.floor(def.getHeight()));

                if ((x != def.getX()) || (y != def.getY()) || (w != def.getWidth()) || (h != def.getHeight())) {
                
                    r = new java.awt.Rectangle(x, y, w, h);
                }

            } else {
    
                throw new Exception("Could not configure bounds. The default bounds is null.");
            }

        } else {

            throw new Exception("Could not configure bounds. The configuration is null.");
        }
    
        return r;
*/

        return null;
    }

    /**
     * Deconfigures the bounds.
     *
     * @param r the bounds
     * @exception Exception if the configuration is null
     * @exception Exception if the bounds is null
     */
    public void deconfigureBounds(java.awt.Rectangle r) throws Exception {

/*??
        Configuration c = (Configuration) getChild(UserInterface.CONFIGURATION);

        if (c != null) {

            if (r != null) {
    
                c.setWindowX((int) Math.floor(r.getX()));
                c.setWindowY((int) Math.floor(r.getY()));
                c.setWindowWidth((int) Math.floor(r.getWidth()));
                c.setWindowHeight((int) Math.floor(r.getHeight()));

            } else {
    
                throw new Exception("Could not deconfigure window bounds. The window bounds is null.");
            }

        } else {

            throw new Exception("Could not deconfigure window bounds. The configuration is null.");
        }
*/
    }

    //
    // Resizable.
    //

    /**
     * Sets the resizable flag.
     *
     * @param r the resizable flag
     * @exception Exception if the java frame is null
     * @exception Exception if the resizable flag is null
     */
    public void setResizable(Boolean r) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (r != null) {
                
                f.setResizable(r.getJavaPrimitive());

            } else {
    
                throw new Exception("Could not set resizable flag. The resizable flag is null.");
            }

        } else {

            throw new Exception("Could not set resizable flag. The java frame is null.");
        }
    }

    /**
     * Removes the resizable flag.
     *
     * @param r the resizable flag
     * @exception Exception if the java frame is null
     * @exception Exception if the resizable flag is null
     */
    public void removeResizable(Boolean r) throws Exception {

        javax.swing.JFrame f = (javax.swing.JFrame) getJavaObject();
    
        if (f != null) {

            if (r != null) {
                
                f.setResizable(Boolean.FALSE);

            } else {
    
                throw new Exception("Could not set resizable flag. The resizable flag is null.");
            }

        } else {

            throw new Exception("Could not set resizable flag. The java frame is null.");
        }
    }

    //
    // Look and feel.
    //

    /**
     * Configures the look and feel.
     *
     * @param def the default look and feel
     * @exception Exception if the configuration is null
     * @exception Exception if the default look and feel is null
     * @exception Exception if the look and feel id string is null
     * @exception Exception if the look and feel is invalid
     */
/*??
    public javax.swing.LookAndFeel configureLookAndFeel(javax.swing.LookAndFeel def) throws Exception {

        javax.swing.LookAndFeel laf = def;
        Configuration c = (Configuration) getChild(UserInterface.CONFIGURATION);
        
        if (c != null) {
            
            if (def != null) {
                
                String s = c.getLookAndFeel(def.getID());
    
                if (s != null) {

                    if (s.equals(def.getID()) == false) {
                            
                        if (s.equals("Metal")) {
        
                            laf = new javax.swing.plaf.metal.MetalLookAndFeel();
        
                        } else if (s.equals("Motif")) {
        
                            laf = new com.sun.java.swing.plaf.motif.MotifLookAndFeel();
        
/*??
                        } else if (s.equals("Mac")) {
        
                            laf = new com.sun.java.swing.plaf.mac.MacLookAndFeel();
*/
/*??
        
                        } else if (s.equals("Windows")) {
        
                            laf = new com.sun.java.swing.plaf.windows.WindowsLookAndFeel();
        
                        } else {
        
                            throw new Exception("Could not configure look and feel. The look and feel is invalid.");
                        }
                    }
        
                } else {
    
                    throw new Exception("Could not configure look and feel. The look and feel id string is null.");
                }
    
            } else {

                throw new Exception("Could not configure look and feel. The default look and feel is null.");
            }

        } else {

            throw new Exception("Could not configure look and feel. The configuration is null.");
        }
        
        return laf;
    }
    
    /**
     * Deconfigures the look and feel.
     *
     * @exception Exception if the configuration is null
     * @exception Exception if the look and feel is null
     */
/*??
    public void deconfigureLookAndFeel(javax.swing.LookAndFeel laf) throws Exception {

        Configuration c = (Configuration) getChild(UserInterface.CONFIGURATION);
        
        if (c != null) {

            if (laf != null) {
                
                c.setLookAndFeel(laf.getID());

            } else {
    
                throw new Exception("Could not deconfigure look and feel. The look and feel is null.");
            }

        } else {

            throw new Exception("Could not deconfigure look and feel. The configuration is null.");
        }
    }

    //
    // Initialization.
    //

    /**
     * Initializes this swing view.
     *
     * @exception Exception if the configuration is null
     */
    public void initialize() throws Exception {

        super.initialize();

        javax.swing.UIManager.setLookAndFeel(getDefaultLookAndFeel());
        setChild(UserInterface.USER_INTERFACE_MODE, getDefaultUserInterfaceMode());
/*??
        setChild(UserInterface.WINDOW_BOUNDS, configureWindowBounds(getDefaultWindowBounds()));
        setChild(UserInterface.DIALOG_BOUNDS, configureDialogBounds(getDefaultDialogBounds()));
        setChild(UserInterface.FRAME_BOUNDS, configureFrameBounds(getDefaultFrameBounds()));
        setChild(UserInterface.INTERNAL_FRAME_BOUNDS, configureInternalFrameBounds(getDefaultInternalFrameBounds()));
*/
        setChild(UserInterface.TITLE, getDefaultTitle());
        setChild(UserInterface.ICON, getDefaultIcon());
        setChild(UserInterface.MENU_BAR, createChild(getDefaultMenuBar()));
        setChild(UserInterface.TOOL_BAR, createChild(getDefaultToolBar()));
        setChild(UserInterface.CONTENTS_PANEL, createChild(getDefaultContentsPanel()));
        setChild(UserInterface.STATUS_BAR, createChild(getDefaultStatusBar()));
        setChild(UserInterface.RESIZABLE_FLAG, getDefaultResizableFlag());
    }

    /**
     * Finalizes this swing view.
     *
     * @exception Exception if the configuration is null
     */
    public void finalizz() throws Exception {

        Boolean resizable = (Boolean) getChild(UserInterface.RESIZABLE_FLAG);
        removeChild(UserInterface.RESIZABLE_FLAG);

        StatusBar statusBar = (StatusBar) getChild(UserInterface.STATUS_BAR);
        removeChild(UserInterface.STATUS_BAR);
        destroyChild(statusBar);

        ContentsPanel contentsPanel = (ContentsPanel) getChild(UserInterface.CONTENTS_PANEL);
        removeChild(UserInterface.CONTENTS_PANEL);
        destroyChild(contentsPanel);

        ToolBar toolBar = (ToolBar) getChild(UserInterface.TOOL_BAR);
        removeChild(UserInterface.TOOL_BAR);
        destroyChild(toolBar);

        MenuBar menuBar = (MenuBar) getChild(UserInterface.MENU_BAR);
        removeChild(UserInterface.MENU_BAR);
        destroyChild(menuBar);

        String icon = (String) getChild(UserInterface.ICON);
        removeChild(UserInterface.ICON);

        String title = (String) getChild(UserInterface.TITLE);
        removeChild(UserInterface.TITLE);

/*??
        deconfigureInternalFrameBounds((java.awt.Rectangle) getChild(UserInterface.INTERNAL_FRAME_BOUNDS));
        removeChild(UserInterface.INTERNAL_FRAME_BOUNDS);
        destroyChild((java.awt.Rectangle) getChild(UserInterface.INTERNAL_FRAME_BOUNDS));

        deconfigureFrameBounds((java.awt.Rectangle) getChild(UserInterface.FRAME_BOUNDS));
        removeChild(UserInterface.FRAME_BOUNDS);
        destroyChild((java.awt.Rectangle) getChild(UserInterface.FRAME_BOUNDS));

        deconfigureDialogBounds((java.awt.Rectangle) getChild(UserInterface.DIALOG_BOUNDS));
        removeChild(UserInterface.DIALOG_BOUNDS);
        destroyChild((java.awt.Rectangle) getChild(UserInterface.DIALOG_BOUNDS));

        deconfigureWindowBounds((java.awt.Rectangle) getChild(UserInterface.WINDOW_BOUNDS));
        removeChild(UserInterface.WINDOW_BOUNDS);
        destroyChild((java.awt.Rectangle) getChild(UserInterface.WINDOW_BOUNDS));
*/

        Integer viewModelMode = (Integer) getChild(UserInterface.USER_INTERFACE_MODE);
        removeChild(UserInterface.USER_INTERFACE_MODE);

        super.finalizz();
    }
}

