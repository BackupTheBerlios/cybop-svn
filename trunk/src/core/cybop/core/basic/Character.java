/*
 * $RCSfile: Character.java,v $
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
 * This class represents a character.
 *
 * A character is an abstract representation of something in the real world.
 * In informatics, special tables were created which map every known sign
 * to a certain encoding number. The most popular tables are ASCII, ANSI and UNICODE.
 *
 * @version $Revision: 1.3 $ $Date: 2003-02-20 15:35:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Character extends Item {

    //
    // Construction.
    //
    
    /**
     * Constructs this character.
     */
    public Character() {

        super();
    }

    //
    // Children.
    //
    
    /** The encapsulated java object. */
/*??
    private char javaObject;

    //
    // The encapsulated java object.
    //
    
    /**
     * Creates the encapsulated java object.
     *
     * @return the encapsulated java object
     */
/*??
    public char createJavaObject() {

        return null;
    }

    /**
     * Destroys the encapsulated java object.
     *
     * @param o the encapsulated java object
     */
/*??
    public void destroyJavaObject(char o) {
    }

    /**
     * Sets encapsulated java object.
     * 
     * @param o the encapsulated java object
     */
/*??
    public void setJavaObject(char o) {
        
        this.javaObject = o;
    }

    /**
     * Returns the encapsulated java object.
     *
     * @return the encapsulated java object
     */
/*??
    public char getJavaObject() {
        
        return this.javaObject;
    }
*/
}

