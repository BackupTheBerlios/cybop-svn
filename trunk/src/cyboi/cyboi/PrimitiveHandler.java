/*
 * $RCSfile: PrimitiveHandler.java,v $
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
 * This is a primitive handler.
 *
 * It contains procedures to create items of primitive type.
 *
 * @version $Revision: 1.9 $ $Date: 2003-07-24 20:36:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
class PrimitiveHandler {

    //
    // Integer primitive.
    //

    /**
     * Creates an integer primitive.
     *
     * @param s the integer primitive as string
     * @return the integer primitive
     */
    static java.lang.Object create_integer_primitive(java.lang.Object s) {

        java.lang.System.out.println("INFO: Create integer primitive.");
        return java.lang.Integer.valueOf((java.lang.String) s);
    }

    /**
     * Destroys the integer primitive.
     *
     * @param p the integer primitive
     */
    static void destroy_integer_primitive(java.lang.Object p) {

        java.lang.System.out.println("INFO: Destroy integer primitive.");
    }

    //
    // Float primitive.
    //

    /**
     * Creates a float primitive.
     *
     * @param s the float primitive as string
     * @return the float primitive
     */
    static java.lang.Object create_float_primitive(java.lang.Object s) {

        java.lang.System.out.println("INFO: Create float primitive.");
        return java.lang.Double.valueOf((java.lang.String) s);
    }

    /**
     * Destroys the float primitive.
     *
     * @param p the float primitive
     */
    static void destroy_float_primitive(java.lang.Object p) {

        java.lang.System.out.println("INFO: Destroy float primitive.");
    }

    //
    // Character primitive.
    //

    /**
     * Creates a character primitive.
     *
     * @param s the character primitive as string
     * @return the character primitive
     */
    static java.lang.Object create_character_primitive(java.lang.Object s) {

        java.lang.System.out.println("INFO: Create character primitive.");
        return s; //?? java.lang.Double.valueOf((java.lang.String) s);
    }

    /**
     * Destroys the character primitive.
     *
     * @param p the character primitive
     */
    static void destroy_character_primitive(java.lang.Object p) {

        java.lang.System.out.println("INFO: Destroy character primitive.");
    }

    //
    // String primitive.
    //

    /**
     * Creates a string primitive.
     *
     * @param s the string primitive as string
     * @return the string primitive
     */
    static java.lang.Object create_string_primitive(java.lang.Object s) {

        java.lang.System.out.println("INFO: Create string primitive.");
        return s;
    }

    /**
     * Destroys the string primitive.
     *
     * @param p the string primitive
     */
    static void destroy_string_primitive(java.lang.Object p) {

        java.lang.System.out.println("INFO: Destroy string primitive.");
    }

/*??
    static void abstracc() {

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        setJavaObject(createJavaObject());

        // This java tree node can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system tree using java tree nodes so that such trees can
        // easily be displayed in javax.swing.JTree objects.
        setJavaTreeNode(createJavaTreeNode());
    }

    static void deabstract() {

        // This java tree node can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system tree using java tree nodes so that such trees can
        // easily be displayed in javax.swing.JTree objects.
        javax.swing.tree.DefaultMutableTreeNode javaTreeNode = getJavaTreeNode();
        setJavaTreeNode(null);
        destroyJavaTreeNode(javaTreeNode);

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        java.lang.Object javaObject = getJavaObject();
        setJavaObject(null);
        destroyJavaObject(javaObject);
    }
*/
    //
    // Encapsulated java object.
    //

    /**
     * Creates an encapsulated java object.
     *
     * @return the encapsulated java object
     */
/*??
    static java.lang.Object createJavaObject() {

        return null;
    }

    /**
     * Destroys the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
/*??
    static void destroyJavaObject(java.lang.Object o) {
    }

    /**
     * Sets the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
/*??
    static void setJavaObject(java.lang.Object o) {

        this.javaObject = o;
    }

    /**
     * Returns the encapsulated java object.
     *
     * @return the encapsulated java object
     */
/*??
    static java.lang.Object getJavaObject() {

        return this.javaObject;
    }

    //
    // Java tree node.
    //

    /**
     * Creates a java tree node.
     *
     * @return the java tree node
     */
/*??
    static javax.swing.tree.DefaultMutableTreeNode createJavaTreeNode() {

        javax.swing.tree.DefaultMutableTreeNode tn = new javax.swing.tree.DefaultMutableTreeNode();

        if (tn != null) {

            tn.setUserObject("Item");

        } else {

            System.out.println("Could not create java tree node. The java tree node is null.");
        }

        return tn;
    }

    /**
     * Destroys the java tree node.
     *
     * @param tn the java tree node
     */
/*??
    static void destroyJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {
    }

    /**
     * Sets the java tree node.
     *
     * @param tn the java tree node
     */
/*??
    static void setJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {

        this.javaTreeNode = tn;
    }

    /**
     * Returns the java tree node.
     *
     * @return the java tree node
     */
/*??
    static javax.swing.tree.DefaultMutableTreeNode getJavaTreeNode() {

        return this.javaTreeNode;
    }

    //
    // Java tree node management.
    //

    /**
     * Adds the java tree node of the array.
     *
     * @param a the array
     */
/*??
    static void addTreeNode(Array a) {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (a != null) {

                //
                // It is bad coding style to use instanceof.
                // However, since this method is a temporary solution anyway,
                // it seems the simplest way to work with instanceof here.
                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
                // Also, array should not know about Signal because this
                // breaks the dependency between the framework's layers.
                //
                if ((a.getJavaTreeNode() != null) && (a.getJavaTreeNode().isNodeAncestor(tn))) {

                    tn.add(a.getJavaTreeNode());
                }

            } else {

//??                System.out.println("DEBUG: Could not add java tree node. The array is null.");
            }

        } else {

            System.out.println("Could not add java tree node. The java tree node is null.");
        }
    }

    /**
     * Removes the java tree node of the array.
     *
     * @param a the array
     */
/*??
    static void removeTreeNode(Array a) {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (a != null) {

                //
                // It is bad coding style to use instanceof.
                // However, since this method is a temporary solution anyway,
                // it seems the simplest way to work with instanceof here.
                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
                // Also, array should not know about Signal because this
                // breaks the dependency between the framework's layers.
                // Alternative:
                // if (tn.isNodeChild(a.getJavaTreeNode())) {
                //
                if ((a.getJavaTreeNode() != null) && (a.getJavaTreeNode().isNodeAncestor(tn))) {

                    tn.remove(a.getJavaTreeNode());
                }

            } else {

//??                System.out.println("DEBUG: Could not remove java tree node. The array is null.");
            }

        } else {

            System.out.println("Could not remove java tree node. The java tree node is null.");
        }
    }
*/
}

