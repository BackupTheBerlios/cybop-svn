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
 * @version $Revision: 1.7 $ $Date: 2003-08-14 12:13:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class JavaObjectHandler {

    //
    // Constants.
    //
    
    /** The name. */
    static java.lang.String NAME = "name";

    /** The mnemonic. */
    static java.lang.String KEY_BINDING = "key_binding";

    /** The width. */
    static java.lang.String WIDTH = "width";

    /** The height. */
    static java.lang.String HEIGHT = "height";

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

            // Find class by name.
            java.lang.Class cl = java.lang.Class.forName((java.lang.String) p0);

            if (cl != null) {

                java.lang.System.out.println("INFO: Create java object.");
            
                o = cl.newInstance();

            } else {

                java.lang.System.out.println("ERROR: Could not create java object. The class is null.");
            }

        } else {

            java.lang.System.out.println("ERROR: Could not create java object. The category is null.");
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

        java.lang.System.out.println("INFO: Initialize java object attributes.");
        
        if (p0 instanceof javax.swing.JFrame) {

            JavaObjectHandler.initialize_jframe((javax.swing.JFrame) p0, p1);                    

        } else if (p0 instanceof javax.swing.JMenuBar) {
            
            JavaObjectHandler.initialize_jmenubar((javax.swing.JMenuBar) p0, p1);

        } else if (p0 instanceof javax.swing.JMenu) {
            
            JavaObjectHandler.initialize_jmenu((javax.swing.JMenu) p0, p1);

        } else if (p0 instanceof javax.swing.JMenuItem) {
            
            JavaObjectHandler.initialize_jmenuitem((javax.swing.JMenuItem) p0, p1);
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

            java.lang.System.out.println("INFO: Add to java object.");
            
            if (p0 instanceof javax.swing.JFrame) {
                    
                JavaObjectHandler.add_to_jframe((javax.swing.JFrame) p0, p1, p2);

            } else if (p0 instanceof javax.swing.JMenuBar) {
                
                JavaObjectHandler.add_to_jmenubar((javax.swing.JMenuBar) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JMenu) {
                
                JavaObjectHandler.add_to_jmenu((javax.swing.JMenu) p0, p1, p2);
    
            } else if (p0 instanceof javax.swing.JMenuItem) {
                
                JavaObjectHandler.add_to_jmenuitem((javax.swing.JMenuItem) p0, p1, p2);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not add to java object. The java object is null.");
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

            java.lang.System.out.println("INFO: Add to java object.");
            
            if (p0 instanceof javax.swing.JFrame) {
                    
                JavaObjectHandler.remove_from_jframe((javax.swing.JFrame) p0, p1, p2);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not add to java object. The java object is null.");
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

            java.lang.System.out.println("INFO: Initialize jframe.");
            
            java.lang.String width = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.WIDTH);
            java.lang.String height = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.HEIGHT);
            f.setSize(java.lang.Integer.parseInt(width), java.lang.Integer.parseInt(height));
            
            java.awt.Container c = (java.awt.Container) f.getContentPane();
            
            if (c != null) {
                
                c.setLayout(new java.awt.BorderLayout());

            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize jframe. The content pane is null.");
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize jframe. The jframe is null.");
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

            java.lang.System.out.println("INFO: Add to jframe.");
            
            if (p1 instanceof javax.swing.JMenuBar) {
                    
                f.setJMenuBar((javax.swing.JMenuBar) p1);
                
                //?? Temporary until SHOW communication signal is sent!
                f.setVisible(true);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not add to jframe. The jframe is null.");
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

            java.lang.System.out.println("INFO: Remove from jframe.");
            
            if (p1 instanceof javax.swing.JMenuBar) {
                    
                f.setJMenuBar(null);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not remove from jframe. The jframe is null.");
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

            java.lang.System.out.println("INFO: Add to jmenubar.");
            
            if (p1 instanceof javax.swing.JMenu) {
                    
                mb.add((javax.swing.JMenu) p1);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not add to jmenubar. The jmenubar is null.");
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

            java.lang.System.out.println("INFO: Remove from jmenubar.");
            
            if (p1 instanceof javax.swing.JMenu) {
                    
                mb.remove((javax.swing.JMenu) p1);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not remove from jmenubar. The jmenubar is null.");
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

            java.lang.System.out.println("INFO: Initialize jmenu.");
            
            java.lang.String name = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.NAME);
            m.setText(name);
            
        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize jmenu. The jmenu is null.");
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

            java.lang.System.out.println("INFO: Add to jmenu.");
            
            if (p1 instanceof javax.swing.JMenuItem) {
                    
                m.add((javax.swing.JMenuItem) p1);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not add to jmenu. The jmenu is null.");
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

            java.lang.System.out.println("INFO: Remove from jmenu.");
            
            if (p1 instanceof javax.swing.JMenuItem) {
                    
                m.remove((javax.swing.JMenuItem) p1);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not remove from jmenu. The jmenu is null.");
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

            java.lang.System.out.println("INFO: Initialize jmenuitem.");
            
            java.lang.String name = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.NAME);
            java.lang.String key_binding = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.KEY_BINDING);
            mi.setText(name);
            
            if (key_binding != null) {
                
                mi.setMnemonic(java.lang.Integer.parseInt(key_binding));
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize jmenuitem. The jmenuitem is null.");
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
    
    /**
     * Adds to the jmenuitem.
     *
     * @param p0 the jmenuitem
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void add_to_jmenuitem(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {
    }
    
    /**
     * Removes from the jmenuitem.
     *
     * @param p0 the jmenuitem
     * @param p1 the child java object
     * @param p2 the child position
     */
    static void remove_from_jmenuitem(java.lang.Object p0, java.lang.Object p1, java.lang.Object p2) {
    }
}

