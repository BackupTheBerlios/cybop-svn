/*
 * $RCSfile: Abstraction.java,v $
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

package cybop.core.model;

/**
 * This class represents an abstraction.
 *
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Abstraction extends Array {

    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a java.lang.Object into a byte[]

    //
    // Temporary until CYBOP framework doesn't rely on java classes anymore.
    //

    /** The encapsulated java object. */
    private java.lang.Object javaObject;

    //
    // Encapsulated java object.
    //

    /**
     * Creates an encapsulated java object.
     *
     * @return the encapsulated java object
     * @exception Exception if the encapsulated java object is null
     */
    public java.lang.Object createJavaObject() {

        return null;
    }

    /**
     * Destroys the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
    public void destroyJavaObject(java.lang.Object o) {
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
    // Abstraction.
    //

    /**
     * Abstracts this abstraction.
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

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        setJavaObject(createJavaObject());
    }

    /**
     * Deabstracts this abstraction.
     */
    public void deabstract() throws Exception {

        // As long as the CYBOP framework is built on Java, every
        // item needs to be capable of encapsulating a pure Java object.
        java.lang.Object javaObject = getJavaObject();
        setJavaObject(null);
        destroyJavaObject(javaObject);
    }
}

