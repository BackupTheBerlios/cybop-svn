/*
 * $RCSfile: Boolean.java,v $
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
 * This class represents a boolean.<br><br>
 *
 * A boolean is a parameter that can only have two values, e.g.:
 *  <ul>
 *      <li>true - false</li>
 *      <li>1 - 0</li>
 *      <li>on - off</li>
 *  </ul>
 *
 * The idea comes from electricity where current can flow or not (digital).
 * Why not using the multiple states between 0 and 1? Because 0 and 1
 * provide the best signal-to-noise ratio possible.<br>
 * Of course, other coding schemes such as the four states of quark particles
 * may be used as well.
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-18 17:25:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Boolean extends Quantity {

    //
    // Static values.
    //
    
    /** The true value. */
    public static final boolean TRUE = true;

    /** The false value. */
    public static final boolean FALSE = false;

    /** The default value. */
    public static final boolean DEFAULT = Boolean.FALSE;

    //
    // Construction.
    //
    
    /**
     * Constructs this boolean.
     */
    public Boolean() {

        super();
    }

    /**
     * Constructs this boolean.<br><br>
     *
     * Normally, constructors are NOT used in the ResMedLib framework,
     * because no counterparts (destructors) exist in the java language.
     * The aim of this prohibition is to ensure a proper startup and shutdown
     * (lifecycle) of every item in the system.<br><br>
     *
     * However, when it comes to lower abstraction (language) levels of our
     * ontology, we need to make some exceptions:<br>
     * Whenever a boolean like "true" or "false" is given,
     * the java language constructs a new boolean object anyway.
     * So, it doesn't matter if also we are creating booleans which do not
     * get properly destroyed by the lifecycle, just by the garbage collector
     * after an indefinable time.
     * Most often, such booleans are needed/created as static variables to define
     * constants, e.g. attribute ids. That's why we need this boolean constructor.
     *
     * @param b the primitive boolean value
     */
    public Boolean(boolean b) {

        super();
        setJavaObject(new java.lang.Boolean(b));
    }

    //
    // Encapsulated java boolean.
    //
    
    /**
     * Creates an encapsulated java boolean.
     *
     * @return the encapsulated java boolean
     */
    public java.lang.Object createJavaObject() {

        return new java.lang.Boolean(createJavaPrimitive());
    }

    //
    // Java primitive.
    //
    
    /**
     * Creates the java primitive.
     *
     * @return the java primitive
     */
    public boolean createJavaPrimitive() {

        return Boolean.DEFAULT;
    }

    /**
     * Destroys the java primitive.
     *
     * @param p the java primitive
     */
    public void destroyJavaPrimitive(boolean p) {
    }

    /**
     * Sets the java primitive.
     *
     * @param p the java primitive
     * @exception Exception if the java object is null
     */
    public void setJavaPrimitive(boolean p) throws Exception {
    }

    /**
     * Returns the java primitive.
     *
     * @return the java primitive
     * @exception Exception if the java object is null
     */
    public boolean getJavaPrimitive() throws Exception {

        boolean p = Boolean.DEFAULT;
        java.lang.Boolean j = (java.lang.Boolean) getJavaObject();
        
        if (j != null) {

            p = j.booleanValue();

        } else {
        
            throw new Exception("Could not get java primitive. The java object is null.");
        }            

        return p;
    }

    //
    // Algebraic methods.
    //

    /**
     * Tests if this boolean is equal to the given boolean.
     *
     * @param b1 the boolean
     * @return true - if this boolean is equal to the given boolean;
     * false - otherwise
     * @exception Exception if the boolean is null
     * @exception Exception if the java boolean is null
     * @exception Exception if this java boolean is null
     */
    public boolean isEqualTo(Boolean b1) throws Exception {

        boolean result = Boolean.FALSE;

        if (b1 != null) {

            java.lang.Boolean j1 = (java.lang.Boolean) b1.getJavaObject();

            if (j1 != null) {

                java.lang.Boolean j2 = (java.lang.Boolean) getJavaObject();
                
                if (j2 != null) {
                    
                    if (j2.booleanValue() == j1.booleanValue()) {
        
                        result = Boolean.TRUE;
                    }
            
                } else {
                    
                    throw new Exception("Could not test boolean. This java boolean is null.");
                }
                
            } else {
                
                throw new Exception("Could not test boolean. The java boolean is null.");
            }
            
        } else {
            
            throw new Exception("Could not test boolean. The boolean is null.");
        }

        return result;        
    }

    /**
     * Tests if this boolean is equal to the given boolean.
     *
     * @param p1 the primitive boolean
     * @return true - if this boolean is equal to the given boolean;
     * false - otherwise
     * @exception Exception if this java boolean is null
     */
    public boolean isEqualTo(boolean p1) throws Exception {

        boolean result = Boolean.FALSE;
        java.lang.Boolean j2 = (java.lang.Boolean) getJavaObject();
        
        if (j2 != null) {
            
            if (j2.booleanValue() == p1) {

                result = Boolean.TRUE;
            }

        } else {
            
            throw new Exception("Could not test boolean. This java boolean is null.");
        }

        return result;        
    }

    /**
     * Tests if this boolean is unequal to the given boolean.
     *
     * @param b the boolean
     * @return true - if this boolean is unequal to the given boolean;
     * false - otherwise
     * @exception Exception if the boolean is null
     * @exception Exception if the java boolean is null
     * @exception Exception if this java boolean is null
     */
    public boolean isUnequalTo(Boolean b) throws Exception {

        return !isEqualTo(b);        
    }

    /**
     * Tests if this boolean is unequal to the given boolean.
     *
     * @param p the primitive boolean
     * @return true - if this boolean is unequal to the given boolean;
     * false - otherwise
     * @exception Exception if this java boolean is null
     */
    public boolean isUnequalTo(boolean p) throws Exception {

        return !isEqualTo(p);        
    }
}

