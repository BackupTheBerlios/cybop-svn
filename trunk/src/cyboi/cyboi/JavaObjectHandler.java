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
 * @version $Revision: 1.6 $ $Date: 2003-08-09 15:34:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class JavaObjectHandler {

    //
    // Constants.
    //
    
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
        
        if (p0 != null) {

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

        javax.swing.JFrame f = (javax.swing.JFrame) p0;
        
        if (p0 != null) {

            java.lang.System.out.println("INFO: Finalize jframe.");
            
/*??
            java.lang.String width = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.WIDTH);
            java.lang.String height = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.HEIGHT);
            f.setSize(java.lang.Integer.parseInt(width), java.lang.Integer.parseInt(height));
            
            java.awt.Container c = (java.awt.Container) f.getContentPane();
            
            if (c != null) {
                
                c.setLayout(new java.awt.BorderLayout());

            } else {
                
                java.lang.System.out.println("ERROR: Could not initialize jframe. The content pane is null.");
            }
*/

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize jframe. The jframe is null.");
        }
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
                    
                javax.swing.JMenuBar test = new javax.swing.JMenuBar();
                test.add(new javax.swing.JMenu("test"));
//??                f.setJMenuBar((javax.swing.JMenuBar) p1);
                f.setJMenuBar(test);
                
                //?? Temporary until SHOW communication signal is sent!
                f.setVisible(true);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not add to jframe. The jframe is null.");
        }
    }
    
    /**
     * Remove from the jframe.
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
            
            java.lang.System.out.println("ERROR: Could not add to jframe. The jframe is null.");
        }
    }
}

