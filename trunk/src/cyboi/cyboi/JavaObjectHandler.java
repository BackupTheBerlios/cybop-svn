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
 * @version $Revision: 1.4 $ $Date: 2003-07-31 11:09:45 $ $Author: christian $
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

                // Create java object from class.
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
    // Java object attributes.
    //
    
    /**
     * Initializes the java object attributes.
     *
     * @param p0 the java object
     * @param p1 the attributes
     */
    static void initialize_java_object_attributes(java.lang.Object p0, java.lang.Object p1) throws java.lang.Exception {

        if (p0 != null) {

            java.lang.System.out.println("INFO: Initialize java object.");
            
            if (p0 instanceof javax.swing.JFrame) {
                    
                java.lang.String width = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.WIDTH);
                java.lang.String height = (java.lang.String) MapHandler.get_map_element(p1, JavaObjectHandler.HEIGHT);
                ((javax.swing.JFrame) p0).setSize(java.lang.Integer.parseInt(width), java.lang.Integer.parseInt(height));
                ((javax.swing.JFrame) p0).setVisible(true);
            }

        } else {
            
            java.lang.System.out.println("ERROR: Could not initialize java object attributes. The java object is null.");
        }
    }
}

