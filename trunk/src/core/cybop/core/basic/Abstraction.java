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

package cybop.core.basic;

/**
 * This class represents an abstraction.
 *
 * An abstraction is something which represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * Actually, the abstraction can be seen as byte array itself.
 *
 * @version $Revision: 1.1 $ $Date: 2003-04-30 14:37:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Abstraction extends java.lang.Object {
    
    //?? See for example:
    //?? java.io.ObjectOutputStream::writeArray
    //?? for how to transfer a java.lang.Object into a byte[]

    //
    // Meta attributes.
    //

    /** The byte code. */
    private byte[] byteCode;

    //
    // Byte code.
    //

    /**
     * Creates a byte code.
     *
     * @return the byte code
     */
    public byte[] createByteCode() {

        return null;
    }

    /**
     * Destroys the byte code.
     *
     * @param c the byte code
     */
    public void destroyByteCode(byte[] c) {
    }

    /**
     * Sets the byte code.
     *
     * @param c the byte code
     */
    public void setByteCode(byte[] c) {

        this.byteCode = c;
    }

    /**
     * Returns the byte code.
     *
     * @return the byte code
     */
    public byte[] getByteCode() {

        return this.byteCode;
    }

    //
    // Initialization.
    //

    /**
     * Initializes this abstraction.
     */
    public void initialize() throws Exception {

        setByteCode(createByteCode());
    }

    /**
     * Finalizes this abstraction.
     */
    public void finalizz() throws Exception {

        byte[] byteCode = getByteCode();
        setByteCode(null);
        destroyByteCode(byteCode);
    }
}

