/*
 * $RCSfile: String.java,v $
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
 * This class represents a string.
 *
 * A string is an addition of characters.
 *
 * @version $Revision: 1.6 $ $Date: 2003-04-25 14:02:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class String extends Quality {

    //
    // Static values.
    //
    
    /** The default value. */
    public static final java.lang.String DEFAULT = "";

    //
    // Construction.
    //

    /**
     * Constructs this string.
     */
    public String() {

        super();
    }

    /**
     * Constructs this string.<br><br>
     *
     * Normally, constructors are NOT used in the ResMedLib framework,
     * because no counterparts (destructors) exist in the java language.
     * The aim of this prohibition is to ensure a proper startup and shutdown
     * (lifecycle) of every item in the system.<br><br>
     *
     * However, when it comes to lower abstraction (language) levels of our
     * ontology, we need to make some exceptions:<br>
     * Whenever a string such as "string" is given in quotation marks,
     * the java language constructs a new string object anyway.
     * So, it doesn't matter if also we are creating strings which do not
     * get properly destroyed by the lifecycle, but only by the garbage collector
     * after an indefinable time.
     *
     * Most often, such strings are needed/created as static variables to define
     * constants, e.g. attribute ids. That's why we need this string constructor.
     *
     * @param s the java string
     */
    public String(java.lang.String s) {

        super();
        setJavaObject(s);
    }

    //
    // Encapsulated java string.
    //
    
    /**
     * Creates an encapsulated java string.
     *
     * @return the encapsulated java string
     */
    public java.lang.Object createJavaObject() {

        return new java.lang.String();
    }

    //
    // Java primitive.
    //
    
    /**
     * Sets the java primitive.
     *
     * @param p the java primitive
     * @exception NullPointerException if the java object is null
     */
    public void setJavaPrimitive(java.lang.String p) throws NullPointerException {
    }

    /**
     * Returns the java primitive.
     *
     * @return the java primitive
     * @exception NullPointerException if the java object is null
     */
    public java.lang.String getJavaPrimitive() throws NullPointerException {

        return (java.lang.String) getJavaObject();
    }

    //
    // Algebraic methods.
    //

    /**
     * Compares if this string is equal to the given string.
     *
     * @param s the string
     * @return true - if this string is equal to the given string;
     * false - otherwise
     * @exception NullPointerException if the string is null
     * @exception NullPointerException if the java object is null
     */
    public boolean isEqualTo(String s) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (s != null) {

            java.lang.String o = (java.lang.String) getJavaObject();

            if (o != null) {

                if (o.equals(s.getJavaObject())) {

                    result = Boolean.TRUE;
                }

            } else {

                throw new NullPointerException("Could not compare string. The java object is null.");
            }

        } else {

            throw new NullPointerException("Could not compare string. The string is null.");
        }

        return result;
    }
    
    /**
     * Compares if this string is unequal to the given string.
     *
     * @param s the string
     * @return true - if this string is equal to the given string;
     * false - otherwise
     * @exception NullPointerException if the string is null
     * @exception NullPointerException if the java object is null
     */
    public boolean isUnequalTo(String s) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (s != null) {

            java.lang.String o = (java.lang.String) getJavaObject();

            if (o != null) {

                if (!o.equals(s.getJavaObject())) {

                    result = Boolean.TRUE;
                }

            } else {

                throw new NullPointerException("Could not compare string. The java object is null.");
            }

        } else {

            throw new NullPointerException("Could not compare string. The string is null.");
        }

        return result;
    }
    
    /**
     * Returns the length.
     *
     * @return the length
     * @exception NullPointerException if the java object is null
     */
    public int getLength() throws NullPointerException {

        int l = 0;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            l = o.length();

        } else {

            throw new NullPointerException("Could not return length. The java object is null.");
        }

        return l;
    }

    /**
     * Returns the index of where the given sub string starts.
     *
     * @param s the sub string
     * @return the index of where the given sub string starts
     * @exception NullPointerException if the java object is null
     * @exception NullPointerException if the sub string is null
     */
    public int indexOf(String s) throws NullPointerException {

        int i = 0;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            if (s != null) {

                i = o.indexOf((java.lang.String) s.getJavaObject());

            } else {

                throw new NullPointerException("Could not return index. The sub string is null.");
            }

        } else {

            throw new NullPointerException("Could not return index. The java object is null.");
        }
        
        return i;
    }

    /**
     * Returns the character at the given position.
     *
     * @param i the character position
     * @return the character
     * @exception NullPointerException if the java object is null
     */
    public char getChar(int i) throws NullPointerException {

        char c;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            c = o.charAt(i);

        } else {

            throw new NullPointerException("Could not return character. The java object is null.");
        }

        return c;
    }

    /**
     * Returns the sub string of this string, starting at begin and ending at end.
     *
     * @param begin the begin of the substring
     * @param end the end of the substring
     * @return the sub string of this string
     * @exception NullPointerException if the java object is null
     */
    public String subString(int begin, int end) throws NullPointerException {
        
        String s = null;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            s = new String(o.substring(begin, end));

        } else {

            throw new NullPointerException("Could not return sub string. The java object is null.");
        }

        return s;
    }

    /**
     * Returns the sub string of this string, starting at begin and ending at
     * this string's length.
     *
     * @param begin the begin of the substring
     * @return the sub string of this string
     * @exception NullPointerException if the java object is null
     */
    public String subString(int begin) throws NullPointerException {
        
        String s = null;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            s = new String(o.substring(begin, o.length()));

        } else {

            throw new NullPointerException("Could not return sub string. The java object is null.");
        }

        return s;
    }

    /**
     * Checks if this string starts with the given prefix.
     *
     * @param p the prefix
     * @return true - if this string starts with the given prefix;
     * false - otherwise
     * @exception NullPointerException if the java object is null
     * @exception NullPointerException if the prefix is null
     */
    public boolean startsWith(String p) throws NullPointerException {

        boolean b = false;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            if (p != null) {

                b = o.startsWith((java.lang.String) p.getJavaObject());

            } else {

                throw new NullPointerException("Could not check for prefix. The prefix is null.");
            }

        } else {

            throw new NullPointerException("Could not check for prefix. The java object is null.");
        }

        return b;        
    }

    //
    // Transformation.
    //

    /**
     * Returns the string representation of the given integer.
     *
     * @param i the integer
     * @return the string representation of the given integer
     * @exception NullPointerException if the java object is null
     */
    public String toString(int i) throws NullPointerException {

        String s = null;
        java.lang.String o = (java.lang.String) getJavaObject();

        if (o != null) {

            s = new String(o.valueOf(i));

        } else {

            throw new NullPointerException("Could not return string representation. The java object is null.");
        }

        return s;
    }
}

