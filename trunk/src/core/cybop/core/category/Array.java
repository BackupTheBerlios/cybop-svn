/*
 * $RCSfile: Array.java,v $
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

package cybop.core.category;

/**
 * This class represents an array.
 *
 * An array is an area in the computer memory that can contain a number of
 * abstract elements.
 *
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * @version $Revision: 1.6 $ $Date: 2003-06-17 15:39:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Array {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a java.lang.Object into a byte[]

    //
    // Meta attributes.
    //

    /** The elements. */
    private Array[] elements;

    //
    // Temporary until CYBOP framework doesn't rely on java classes anymore.
    //

    /** The encapsulated java object. */
    private java.lang.Object javaObject;

    /** The java tree node. */
    private javax.swing.tree.DefaultMutableTreeNode javaTreeNode;

    //
    // Elements.
    //

    /**
     * Creates the elements.
     *
     * @return the elements
     */
    public Array[] createElements() {

        return new Array[0];
    }

    /**
     * Creates the elements.
     *
     * At first, a new array with double length of the old is created.
     * Then, all elements are copied from the old to the new array.
     *
     * @param old the old elements array
     * @return the elements array
     * @exception Exception if the elements array is null
     * @exception Exception if an old item is null
     */
    public Array[] createElements(Array[] old) throws Exception {

        Array[] a = null;

        if (old != null) {

            int oldLength = old.length;
            int newLength = oldLength * 2 + 1;
            a = new Array[newLength];
            int i = 0;

            while (i < oldLength) {

                a[i] = old[i];

                i++;
            }

        } else {

            throw new Exception("Could not create elements array. The old elements array is null.");
        }

        return a;
    }

    /**
     * Destroys the elements.
     *
     * @param e the elements
     */
    public void destroyElements(Array[] e) {
    }

    /**
     * Sets the elements.
     *
     * @param e the elements
     */
    public void setElements(Array[] e) {

        this.elements = e;
    }

    /**
     * Returns the elements.
     *
     * @return the elements
     */
    public Array[] getElements() {

        return this.elements;
    }

    /**
     * Returns the size.
     *
     * @return the size
     */
    public int getSize() throws Exception {

        int size = 0;
        Array[] a = getElements();

        if (a != null) {

            size = a.length;

        } else {

            throw new Exception("Could not get size. The elements is null.");
        }

        return size;
    }

    //
    // Element management.
    //

    /**
     * Sets the element.
     *
     * @param i the index
     * @param e the element
     * @exception Exception if the elements is null
     */
    public void set(int i, Array e) throws Exception {

        Array[] a = getElements();

        if (a != null) {

            // If the array length is exceeded, a new adjusted array with
            // extended length is created and delivered back.
            while (i >= a.length) {

                java.lang.System.out.println("DEBUG: Create new array in: " + this);
                Array[] old = getElements();
                a = createElements(old);
//??                destroyElements(old);

                setElements(a);
            }

            java.lang.System.out.println("DEBUG: Set element: " + e + " in: " + this);

            //?? Temporary: Remove old and add new java tree node.
            removeTreeNode(a[i]);
            addTreeNode(e);

            // Set element.
            a[i] = e;

        } else {

            throw new Exception("Could not set element. The elements is null.");
        }
    }

    /**
     * Removes the element.
     *
     * @param i the index
     * @exception Exception if the elements is null
     */
    public void remove(int i) throws Exception {

        Array[] a = getElements();

        if (a != null) {

            java.lang.System.out.println("DEBUG: Remove element: " + i + " in: " + this);

            //?? Temporary: Remove java tree node.
            removeTreeNode(a[i]);

            // Move all remaining elements one place towards the
            // beginning of the elements.
            int index = i;

            while ((index + 1) < a.length) {

                a[index] = a[index + 1];

                index++;
            }

            // Set former last element to null.
            a[index] = null;

        } else {

            throw new Exception("Could not remove element. The elements is null.");
        }
    }

    /**
     * Returns the element.
     *
     * @return the element
     * @exception Exception if the elements is null
     */
    public Array get(int i) throws Exception {

        Array e = null;
        Array[] a = getElements();

        if (a != null) {

            e = a[i];

        } else {

            throw new Exception("Could not get element. The elements is null.");
        }

        return e;
    }

    /**
     * Checks if this array is equal to the given array.
     *
     * @param a the array
     * @return true - if the size and contents of both arrays are equal;
     * false - otherwise
     * @exception Exception if the array is null
     */
    public boolean isEqualTo(Array a) throws Exception {

        boolean b = true;

        if (a != null) {

            int i = a.getSize();

            // Compares the array sizes.
            if (i != getSize()) {

                b = false;
                
            } else {

                // Compares the array elements.
                while (i-- != 0) {

                    if (a.get(i) != get(i)) {

                        b = false;

                        break;
                    }
                }
            }

        } else {

            throw new Exception("Could not compare arrays. The array is null.");
        }

        return b;
    }

    //
    // Encapsulated java object.
    //

    /**
     * Creates an encapsulated java object.
     *
     * @return the encapsulated java object
     * @exception Exception if the encapsulated java object is null
     */
    public java.lang.Object createJavaObject() throws Exception {

        return null;
    }

    /**
     * Destroys the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
    public void destroyJavaObject(java.lang.Object o) throws Exception {
    }

    /**
     * Sets the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
    public void setJavaObject(java.lang.Object o) {

        this.javaObject = o;
    }

    /**
     * Returns the encapsulated java object.
     *
     * @return the encapsulated java object
     */
    public java.lang.Object getJavaObject() {

        return this.javaObject;
    }

    //
    // Java tree node.
    //

    /**
     * Creates a java tree node.
     *
     * @return the java tree node
     * @exception Exception if the java tree node is null
     */
    public javax.swing.tree.DefaultMutableTreeNode createJavaTreeNode() throws Exception {

        javax.swing.tree.DefaultMutableTreeNode tn = new javax.swing.tree.DefaultMutableTreeNode();

        if (tn != null) {

            tn.setUserObject("Item");

        } else {

            throw new Exception("Could not create java tree node. The java tree node is null.");
        }

        return tn;
    }

    /**
     * Destroys the java tree node.
     *
     * @param tn the java tree node
     */
    public void destroyJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) throws Exception {
    }

    /**
     * Sets the java tree node.
     *
     * @param tn the java tree node
     */
    public void setJavaTreeNode(javax.swing.tree.DefaultMutableTreeNode tn) {

        this.javaTreeNode = tn;
    }

    /**
     * Returns the java tree node.
     *
     * @return the java tree node
     */
    public javax.swing.tree.DefaultMutableTreeNode getJavaTreeNode() {

        return this.javaTreeNode;
    }

    //
    // Java tree node management.
    //

    /**
     * Adds the java tree node of the array.
     *
     * @param a the array
     * @exception Exception if the java tree node is null
     * @exception Exception if the array is null
     */
    public void addTreeNode(Array a) throws Exception {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (a != null) {

                // It is bad coding style to use instanceof.
                // However, since this method is a temporary solution anyway,
                // it seems the simplest way to work with instanceof here.
                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
//??                if ((a instanceof Signal) == false) {

                    tn.add(a.getJavaTreeNode());
//??                }

            } else {
    
                java.lang.System.out.println("DEBUG: Could not add java tree node. The array is null.");
            }

        } else {

            throw new Exception("Could not add java tree node. The java tree node is null.");
        }
    }

    /**
     * Removes the java tree node of the array.
     *
     * @param a the array
     * @exception Exception if the java tree node is null
     * @exception Exception if the array is null
     */
    public void removeTreeNode(Array a) throws Exception {

        javax.swing.tree.DefaultMutableTreeNode tn = getJavaTreeNode();

        if (tn != null) {
    
            if (a != null) {

                // It is bad coding style to use instanceof.
                // However, since this method is a temporary solution anyway,
                // it seems the simplest way to work with instanceof here.
                // This check had to be inserted because signal items have
                // children that are not child tree nodes of that signal.
                // Alternative:
                // if (tn.isNodeChild(i.getJavaTreeNode())) {
//??                if ((a instanceof Signal) == false) {

                    tn.remove(a.getJavaTreeNode());
//??                }

            } else {
    
                java.lang.System.out.println("DEBUG: Could not remove java tree node. The array is null.");
            }

        } else {

            throw new Exception("Could not remove java tree node. The java tree node is null.");
        }
    }

    //
    // Abstraction.
    //

    /**
     * Abstracts this array.
     *
     * This is something like a meta method which sets up this category
     * (class/type) with all its properties.
     *
     * This method's name is <code>abstracc</code> and not <code>abstract</code>
     * because the java computer language already uses <code>abstract</code> as
     * key word.
     *
     * This method will be renamed to <code>abstract</code> as soon as the new
     * and simplified CYBOL computer language is used.
     */
    public void abstracc() throws Exception {

        setElements(createElements());

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        setJavaObject(createJavaObject());

        // This java tree node can contain children.
        // It is only used as long as Java objects are used in the CYBOP framework,
        // to build up a system tree using java tree nodes so that such trees can
        // easily be displayed in javax.swing.JTree objects.
        setJavaTreeNode(createJavaTreeNode());
    }

    /**
     * Deabstracts this array.
     */
    public void deabstract() throws Exception {

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

        Array[] elements = getElements();
        setElements(null);
        destroyElements(elements);
    }
}

