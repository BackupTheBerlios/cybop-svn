/*
 * $RCSfile: JavaObjectHandler.java,v $
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

package cyboi;

/**
 * This is a java object handler.
 *
 * It is necessary only as long as the Cybernetics Oriented Interpreter (CYBOI)
 * is implemented in the Java programming language.
 *
 * @version $Revision: 1.12 $ $Date: 2003-09-08 06:48:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class JavaObjectHandler {

    //
    // Constants.
    //
    
    /** The name. */
    static java.lang.String NAME = "name";

    /** The key binding. */
    static java.lang.String KEY_BINDING = "key_binding";

    /** The width. */
    static java.lang.String WIDTH = "width";

    /** The height. */
    static java.lang.String HEIGHT = "height";

    /** The left border. */
    static java.lang.String LEFT_BORDER = "left_border";

    /** The right border. */
    static java.lang.String RIGHT_BORDER = "right_border";

    /** The top border. */
    static java.lang.String TOP_BORDER = "top_border";

    /** The bottom border. */
    static java.lang.String BOTTOM_BORDER = "bottom_border";

    /** The positioning. */
    static java.lang.String POSITIONING = "positioning";

    /** The horizontal alignment. */
    static java.lang.String HORIZONTAL_ALIGNMENT = "horizontal_alignment";

    /** The vertical alignment. */
    static java.lang.String VERTICAL_ALIGNMENT = "vertical_alignment";

    /** The font. */
    static java.lang.String FONT = "font";

    //
    // Java object.
    //

    /**
     * Creates a java object.
     *
     * @param p0 the category
     * @return the java object
     */
    static java.lang.Object create_java_object(java.lang.Object p0) throws java.lang.Exception {

        java.lang.Object o = null;
        
        if (p0 != null) {

            // If a swing jpanel with border layout is to be created, the layout
            // has to be handed over in the constructor! Later assignment via:
            //     panel.setLayout(new BorderLayout);
            // will NOT work! Therefore, jpanel needs some extra code here.
            if (p0.equals("javax.swing.JPanel")) {
                
                o = new javax.swing.JPanel(new java.awt.BorderLayout());
            
            } else {

                // Find class by name.
                java.lang.Class cl = java.lang.Class.forName((java.lang.String) p0);
    
                if (cl != null) {
    
                    LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Create java object.");
                
                    o = cl.newInstance();
                    
                } else {
    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not create java object. The class is null.");
                }
            }

        } else {

            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not create java object. The category is null.");
        }
        
        return o;
    }

    /**
     * Destroys the java object.
     *
     * This procedure is actually superfluous as the Java Garbage Collector cleans
     * up (destroys) all unused java objects automatically, at an arbitrary time.
     *
     * @param p0 the java object
     * @param p1 the category
     */
    static void destroy_java_object(java.lang.Object p0, java.lang.Object p1) {
    }

    //
    // Initialization and finalization.
    //
    
    /**
     * Initializes the java object attributes.
     *
     * @param p0 the java object
     * @param p1 the attributes
     */
    static void initialize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize java object attributes.");
        
        if (p0 instanceof javax.swing.JFrame) {

            JavaObjectHandler.initialize_jframe((javax.swing.JFrame) p0, p1);                    

        } else if (p0 instanceof javax.swing.JDialog) {

            JavaObjectHandler.initialize_jdialog((javax.swing.JDialog) p0, p1);                    

        } else if (p0 instanceof javax.swing.JMenuBar) {
            
            JavaObjectHandler.initialize_jmenubar((javax.swing.JMenuBar) p0, p1);

        } else if (p0 instanceof javax.swing.JMenu) {
            
            JavaObjectHandler.initialize_jmenu((javax.swing.JMenu) p0, p1);

        } else if (p0 instanceof javax.swing.JMenuItem) {
            
            JavaObjectHandler.initialize_jmenuitem((javax.swing.JMenuItem) p0, p1);

        } else if (p0 instanceof javax.swing.JPanel) {
            
            JavaObjectHandler.initialize_jpanel((javax.swing.JPanel) p0, p1);

        } else if (p0 instanceof javax.swing.JTabbedPane) {
            
            JavaObjectHandler.initialize_jtabbedpane((javax.swing.JTabbedPane) p0, p1);

        } else if (p0 instanceof javax.swing.JButton) {
            
            JavaObjectHandler.initialize_jbutton((javax.swing.JButton) p0, p1);

        } else if (p0 instanceof javax.swing.JLabel) {
            
            JavaObjectHandler.initialize_jlabel((javax.swing.JLabel) p0, p1);
        }
    }

    /**
     * Finalizes the java object attributes.
     *
     * @param p0 the java object
     * @param p1 the attributes
     */
    static void finalize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) {
    }

    //
    // Addition and removal.
    //

    /**
     * Adds to the java object.
     *
     * @param p0 the java object
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_java_object(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        if (p0 != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to java object.");
            
            if (p0 instanceof javax.swing.JFrame) {
                    
                JavaObjectHandler.add_to_jframe((javax.swing.JFrame) p0, p1, p2);

            } else if (p0 instanceof javax.swing.JDialog) {
                    
                JavaObjectHandler.add_to_jdialog((javax.swing.JDialog) p0, p1, p2);

            } else if (p0 instanceof javax.swing.JMenuBar) {
                
                JavaObjectHandler.add_to_jmenubar((javax.swing.JMenuBar) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JMenu) {
                
                JavaObjectHandler.add_to_jmenu((javax.swing.JMenu) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JPanel) {
                
                JavaObjectHandler.add_to_jpanel((javax.swing.JPanel) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JTabbedPane) {
                
                JavaObjectHandler.add_to_jtabbedpane((javax.swing.JTabbedPane) p0, p1, p2);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to java object. The java object is null.");
        }
    }

    /**
     * Remove from the java object.
     *
     * @param p0 the java object
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_java_object(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        if (p0 != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from java object.");
            
            if (p0 instanceof javax.swing.JFrame) {
                    
                JavaObjectHandler.remove_from_jframe((javax.swing.JFrame) p0, p1, p2);

            } else if (p0 instanceof javax.swing.JDialog) {
                    
                JavaObjectHandler.remove_from_jdialog((javax.swing.JDialog) p0, p1, p2);

            } else if (p0 instanceof javax.swing.JMenuBar) {
                
                JavaObjectHandler.remove_from_jmenubar((javax.swing.JMenuBar) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JMenu) {
                
                JavaObjectHandler.remove_from_jmenu((javax.swing.JMenu) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JPanel) {
                
                JavaObjectHandler.remove_from_jpanel((javax.swing.JPanel) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JTabbedPane) {
                
                JavaObjectHandler.remove_from_jtabbedpane((javax.swing.JTabbedPane) p0, p1, p2);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from java object. The java object is null.");
        }
    }

    //
    // JFrame.
    //

    /**
     * Initializes the jframe.
     *
     * @param p0 the jframe
     * @param p1 the attributes
     */
    static void initialize_jframe(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JFrame f = (javax.swing.JFrame) p0;
        
        if (f != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jframe.");
            
            java.lang.String width = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.WIDTH);
            java.lang.String height = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.HEIGHT);
            f.setSize(java.lang.Integer.parseInt(width), java.lang.Integer.parseInt(height));
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jframe. The jframe is null.");
        }
    }
    
    /**
     * Finalizes the jframe.
     *
     * @param p0 the jframe
     * @param p1 the attributes
     */
    static void finalize_jframe(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Adds to the jframe.
     *
     * @param p0 the jframe
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jframe(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JFrame f = (javax.swing.JFrame) p0;
        
        if (f != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to jframe.");
            
            if (p1 instanceof javax.swing.JMenuBar) {
                    
                f.setJMenuBar((javax.swing.JMenuBar) p1);
                
            } else if (p1 instanceof java.awt.Component) {
                    
                java.awt.Container c = (java.awt.Container) f.getContentPane();
                
                if (c != null) {
                    
                    c.add((java.awt.Component) p1, p2);
        
                } else {
                    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jframe. The content pane is null.");
                }
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jframe. The jframe is null.");
        }
    }
    
    /**
     * Removes from the jframe.
     *
     * @param p0 the jframe
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jframe(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JFrame f = (javax.swing.JFrame) p0;
        
        if (f != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from jframe.");
            
            if (p1 instanceof javax.swing.JMenuBar) {
                    
                f.setJMenuBar(null);
                
            } else if (p1 instanceof java.awt.Component) {
                    
                java.awt.Container c = (java.awt.Container) f.getContentPane();
                
                if (c != null) {
                    
                    c.remove((java.awt.Component) p1);
        
                } else {
                    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jframe. The content pane is null.");
                }
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jframe. The jframe is null.");
        }
    }

    //
    // JDialog.
    //

    /**
     * Initializes the jdialog.
     *
     * @param p0 the jdialog
     * @param p1 the attributes
     */
    static void initialize_jdialog(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JDialog d = (javax.swing.JDialog) p0;
        
        if (d != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jdialog.");
            
            java.lang.String width = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.WIDTH);
            java.lang.String height = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.HEIGHT);
            d.setSize(java.lang.Integer.parseInt(width), java.lang.Integer.parseInt(height));

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jdialog. The jdialog is null.");
        }
    }
    
    /**
     * Finalizes the jdialog.
     *
     * @param p0 the jdialog
     * @param p1 the attributes
     */
    static void finalize_jdialog(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Adds to the jdialog.
     *
     * @param p0 the jdialog
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jdialog(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JDialog d = (javax.swing.JDialog) p0;
        
        if (d != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to jdialog.");
                
            if (p1 instanceof java.awt.Component) {
                    
                java.awt.Container c = (java.awt.Container) d.getContentPane();
                
                if (c != null) {
                    
                    c.add((java.awt.Component) p1, p2);
        
                } else {
                    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jdialog. The content pane is null.");
                }
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jdialog. The jdialog is null.");
        }
    }
    
    /**
     * Removes from the jdialog.
     *
     * @param p0 the jdialog
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jdialog(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JDialog d = (javax.swing.JDialog) p0;
        
        if (d != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from jdialog.");
            
            if (p1 instanceof java.awt.Component) {
                    
                java.awt.Container c = (java.awt.Container) d.getContentPane();
                
                if (c != null) {
                    
                    c.remove((java.awt.Component) p1);
        
                } else {
                    
                    LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jdialog. The content pane is null.");
                }
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jdialog. The jdialog is null.");
        }
    }

    //
    // JMenuBar.
    //

    /**
     * Initializes the jmenubar.
     *
     * @param p0 the jmenubar
     * @param p1 the attributes
     */
    static void initialize_jmenubar(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Finalizes the jmenubar.
     *
     * @param p0 the jmenubar
     * @param p1 the attributes
     */
    static void finalize_jmenubar(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Adds to the jmenubar.
     *
     * @param p0 the jmenubar
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jmenubar(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JMenuBar mb = (javax.swing.JMenuBar) p0;
        
        if (mb != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to jmenubar.");
            
            if (p1 instanceof javax.swing.JMenu) {
                    
                mb.add((javax.swing.JMenu) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jmenubar. The jmenubar is null.");
        }
    }
    
    /**
     * Removes from the jmenubar.
     *
     * @param p0 the jframe
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jmenubar(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JMenuBar mb = (javax.swing.JMenuBar) p0;
        
        if (mb != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from jmenubar.");
            
            if (p1 instanceof javax.swing.JMenu) {
                    
                mb.remove((javax.swing.JMenu) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jmenubar. The jmenubar is null.");
        }
    }

    //
    // JMenu.
    //

    /**
     * Initializes the jmenu.
     *
     * @param p0 the jmenu
     * @param p1 the attributes
     */
    static void initialize_jmenu(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JMenu m = (javax.swing.JMenu) p0;
        
        if (m != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jmenu.");
            
            java.lang.String name = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.NAME);
            m.setText(name);
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jmenu. The jmenu is null.");
        }
    }
    
    /**
     * Finalizes the jmenu.
     *
     * @param p0 the jmenu
     * @param p1 the attributes
     */
    static void finalize_jmenu(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Adds to the jmenu.
     *
     * @param p0 the jmenu
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jmenu(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JMenu m = (javax.swing.JMenu) p0;
        
        if (m != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to jmenu.");
            
            if (p1 instanceof javax.swing.JMenuItem) {
                    
                m.add((javax.swing.JMenuItem) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jmenu. The jmenu is null.");
        }
    }
    
    /**
     * Removes from the jmenu.
     *
     * @param p0 the jmenu
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jmenu(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JMenu m = (javax.swing.JMenu) p0;
        
        if (m != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from jmenu.");
            
            if (p1 instanceof javax.swing.JMenuItem) {
                    
                m.remove((javax.swing.JMenuItem) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jmenu. The jmenu is null.");
        }
    }

    //
    // JMenuItem.
    //

    /**
     * Initializes the jmenuitem.
     *
     * @param p0 the jmenuitem
     * @param p1 the attributes
     */
    static void initialize_jmenuitem(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JMenuItem mi = (javax.swing.JMenuItem) p0;
        
        if (mi != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jmenuitem.");
            
            java.lang.String name = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.NAME);
            java.lang.String key_binding = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.KEY_BINDING);

            mi.setText(name);
            
            if (key_binding != null) {
                
                mi.setMnemonic(java.lang.Integer.parseInt(key_binding));
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jmenuitem. The jmenuitem is null.");
        }
    }
    
    /**
     * Finalizes the jmenuitem.
     *
     * @param p0 the jmenuitem
     * @param p1 the attributes
     */
    static void finalize_jmenuitem(java.lang.Object p0, java.lang.Object p1) {
    }
    
    //
    // JPanel.
    //

    /**
     * Initializes the jpanel.
     *
     * @param p0 the jpanel
     * @param p1 the attributes
     */
    static void initialize_jpanel(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JPanel p = (javax.swing.JPanel) p0;
        
        if (p != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jpanel.");
            
            java.lang.String left_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.LEFT_BORDER);
            java.lang.String right_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.RIGHT_BORDER);
            java.lang.String top_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.TOP_BORDER);
            java.lang.String bottom_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.BOTTOM_BORDER);
            java.lang.String positioning = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.POSITIONING);
/*??
            p.setBorder(javax.swing.BorderFactory.createEmptyBorder(
                java.lang.Integer.parseInt(left_border),
                java.lang.Integer.parseInt(right_border),
                java.lang.Integer.parseInt(top_border),
                java.lang.Integer.parseInt(bottom_border)));
*/
            
            // Border layout can not be assigned here! It has to be handed over
            // in the jpanel constructor! See: JavaObjectHandler.create_java_object
            // However, other layouts can be assigned here using panel.setLayout(...);
            if (positioning != null) {
                
                if (positioning.equals("box")) {
                
//??                    p.setLayout(new javax.swing.BoxLayout());
                }
            }
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jpanel. The jpanel is null.");
        }
    }
    
    /**
     * Finalizes the jpanel.
     *
     * @param p0 the jpanel
     * @param p1 the attributes
     */
    static void finalize_jpanel(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Adds to the jpanel.
     *
     * @param p0 the jpanel
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jpanel(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JPanel p = (javax.swing.JPanel) p0;
        
        if (p != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to jpanel.");
            
            if (p1 instanceof java.awt.Component) {
                    
                p.add((java.awt.Component) p1, p2);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jpanel. The jpanel is null.");
        }
    }
    
    /**
     * Removes from the jpanel.
     *
     * @param p0 the jpanel
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jpanel(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JPanel p = (javax.swing.JPanel) p0;
        
        if (p != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from jpanel.");
            
            if (p1 instanceof java.awt.Component) {
                    
                p.remove((java.awt.Component) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jpanel. The jpanel is null.");
        }
    }

    //
    // JTabbedPane.
    //

    /**
     * Initializes the jtabbedpane.
     *
     * @param p0 the jtabbedpane
     * @param p1 the attributes
     */
    static void initialize_jtabbedpane(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) p0;
        
        if (tp != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jtabbedpane.");
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jtabbedpane. The jtabbedpane is null.");
        }
    }
    
    /**
     * Finalizes the jtabbedpane.
     *
     * @param p0 the jtabbedpane
     * @param p1 the attributes
     */
    static void finalize_jtabbedpane(java.lang.Object p0, java.lang.Object p1) {
    }
    
    /**
     * Adds to the jtabbedpane.
     *
     * @param p0 the jtabbedpane
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jtabbedpane(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) p0;
        
        if (tp != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Add to jtabbedpane.");
            
            if (p1 instanceof javax.swing.JMenuItem) {
                    
                tp.add("Panel", (java.awt.Component) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not add to jtabbedpane. The jtabbedpane is null.");
        }
    }
    
    /**
     * Removes from the jtabbedpane.
     *
     * @param p0 the jtabbedpane
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jtabbedpane(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {

        javax.swing.JTabbedPane tp = (javax.swing.JTabbedPane) p0;
        
        if (tp != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Remove from jtabbedpane.");
            
            if (p1 instanceof javax.swing.JMenuItem) {
                    
                tp.remove((java.awt.Component) p1);
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not remove from jtabbedpane. The jtabbedpane is null.");
        }
    }

    //
    // JButton.
    //

    /**
     * Initializes the jbutton.
     *
     * @param p0 the jbutton
     * @param p1 the attributes
     */
    static void initialize_jbutton(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JButton b = (javax.swing.JButton) p0;
        
        if (b != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jbutton.");
            
            java.lang.String name = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.NAME);
            java.lang.String key_binding = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.KEY_BINDING);

            b.setText(name);
            
            if (key_binding != null) {
                
                b.setMnemonic(java.lang.Integer.parseInt(key_binding));
            }

        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jbutton. The jbutton is null.");
        }
    }
    
    /**
     * Finalizes the jbutton.
     *
     * @param p0 the jbutton
     * @param p1 the attributes
     */
    static void finalize_jbutton(java.lang.Object p0, java.lang.Object p1) {
    }

    //
    // JLabel.
    //

    /**
     * Initializes the jlabel.
     *
     * @param p0 the jlabel
     * @param p1 the attributes
     */
    static void initialize_jlabel(java.lang.Object p0, java.lang.Object p1) {

        javax.swing.JLabel l = (javax.swing.JLabel) p0;
        
        if (l != null) {

            LogHandler.log(LogHandler.INFO_LOG_LEVEL, "Initialize jlabel.");
            
            java.lang.String left_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.LEFT_BORDER);
            java.lang.String right_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.RIGHT_BORDER);
            java.lang.String top_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.TOP_BORDER);
            java.lang.String bottom_border = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.BOTTOM_BORDER);
            java.lang.String name = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.NAME);
            java.lang.String horizontal_alignment = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.HORIZONTAL_ALIGNMENT);
            java.lang.String vertical_alignment = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.VERTICAL_ALIGNMENT);
            java.lang.String font = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.FONT);
/*??
            l.setBorder(javax.swing.BorderFactory.createEmptyBorder(
                java.lang.Integer.parseInt(left_border),
                java.lang.Integer.parseInt(right_border),
                java.lang.Integer.parseInt(top_border),
                java.lang.Integer.parseInt(bottom_border)));
*/
            l.setText(name);
//??            l.setHorizontalAlignment(horizontal_alignment);
//??            l.setVerticalAlignment(vertical_alignment);
//??            l.setFont(new Font(null, Font.BOLD, 18));
            
        } else {
            
            LogHandler.log(LogHandler.ERROR_LOG_LEVEL, "Could not initialize jlabel. The jlabel is null.");
        }
    }
    
    /**
     * Finalizes the jlabel.
     *
     * @param p0 the jlabel
     * @param p1 the attributes
     */
    static void finalize_jlabel(java.lang.Object p0, java.lang.Object p1) {
    }
}

