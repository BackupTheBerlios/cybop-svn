/*
 * $RCSfile: Integer.java,v $
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
 * This class represents an integer.<br><br>
 *
 * An integer is an unbroken number with only a whole part.<br><br>
 *
 * A number stands for some countable thing of the real world.
 * Possible compositions of Integer are Fraction (Float/Double) and Complex.
 *
 * @version $Revision: 1.5 $ $Date: 2003-04-25 14:02:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Integer extends Quantity {

    //
    // Static values.
    //

    /** The minimum value. */
    public static final int MINIMUM = java.lang.Integer.MIN_VALUE;

    /** The maximum value. */
    public static final int MAXIMUM = java.lang.Integer.MAX_VALUE;

    /** The default value. */
    public static final int DEFAULT = 0;

    //
    // Construction.
    //
    
    /**
     * Constructs this integer.
     */
    public Integer() {

        super();
    }

    /**
     * Constructs this integer.<br><br>
     *
     * Normally, constructors are NOT used in the ResMedLib framework,
     * because no counterparts (destructors) exist in the java language.
     * The aim of this prohibition is to ensure a proper startup and shutdown
     * (lifecycle) of every item in the system.<br><br>
     *
     * However, when it comes to lower abstraction (language) levels of our
     * ontology, we need to make some exceptions:<br>
     * Whenever an integer like "0", "1", "2" is given,
     * the java language constructs a new integer object anyway.
     * So, it doesn't matter if also we are creating integers which do not
     * get properly destroyed by the lifecycle, just by the garbage collector
     * after an indefinable time.
     * Most often, such integers are needed/created as static variables to define
     * constants, e.g. attribute ids. That's why we need this integer constructor.
     *
     * @param i the primitive integer value
     */
    public Integer(int i) {

        super();
        setJavaObject(new java.lang.Integer(i));
    }

    /**
     * Constructs this integer.<br><br>
     *
     * Normally, constructors are NOT used in the ResMedLib framework,
     * because no counterparts (destructors) exist in the java language.
     * The aim of this prohibition is to ensure a proper startup and shutdown
     * (lifecycle) of every item in the system.<br><br>
     *
     * However, when it comes to lower abstraction (language) levels of our
     * ontology, we need to make some exceptions:<br>
     * Whenever an integer like "0", "1", "2" is given,
     * the java language constructs a new integer object anyway.
     * So, it doesn't matter if also we are creating integers which do not
     * get properly destroyed by the lifecycle, just by the garbage collector
     * after an indefinable time.
     * Most often, such integers are needed/created as static variables to define
     * constants, e.g. attribute ids. That's why we need this integer constructor.
     *
     * @param i the java integer
     */
    public Integer(java.lang.Integer i) {

        super();
        setJavaObject(i);
    }

    //
    // Encapsulated java integer.
    //
    
    /**
     * Creates an encapsulated java integer.
     *
     * @return the encapsulated java integer
     */
    public java.lang.Object createJavaObject() {

        return new java.lang.Integer(createJavaPrimitive());
    }

    //
    // Java primitive.
    //
    
    /**
     * Creates the java primitive.
     *
     * @return the java primitive
     */
    public int createJavaPrimitive() {

        return Integer.DEFAULT;
    }

    /**
     * Destroys the java primitive.
     *
     * @param p the java primitive
     */
    public void destroyJavaPrimitive(int p) {
    }

    /**
     * Sets the java primitive.
     *
     * @param p the java primitive
     * @exception NullPointerException if the java object is null
     */
    public void setJavaPrimitive(int p) throws NullPointerException {
    }

    /**
     * Returns the java primitive.
     *
     * @return the java primitive
     * @exception NullPointerException if the java object is null
     */
    public int getJavaPrimitive() throws NullPointerException {

        int p = Integer.DEFAULT;
        java.lang.Integer j = (java.lang.Integer) getJavaObject();
        
        if (j != null) {

            p = j.intValue();

        } else {
        
            throw new NullPointerException("Could not get java primitive. The java object is null.");
        }            

        return p;
    }

    //
    // Algebra.
    //

    /**
     * Adds the integer.
     *
     * @param i the integer
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public void add(Integer i) throws NullPointerException {

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    setJavaObject(new java.lang.Integer(j1.intValue() + j2.intValue()));
                
                } else {
                    
                    throw new NullPointerException("Could not add integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not add integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not add integer. The integer is null.");
        }
    }

    /**
     * Subtracts the integer.
     *
     * @param i the integer
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public void subtract(Integer i) throws NullPointerException {

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    setJavaObject(new java.lang.Integer(j1.intValue() - j2.intValue()));
                
                } else {
                    
                    throw new NullPointerException("Could not subtract integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not subtract integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not subtract integer. The integer is null.");
        }
    }

    /**
     * Multiplies this integer with the integer.
     *
     * @param i the integer
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public void multiplyWith(Integer i) throws NullPointerException {

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    setJavaObject(new java.lang.Integer(j1.intValue() * j2.intValue()));
                
                } else {
                    
                    throw new NullPointerException("Could not multiply integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not multiply integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not multiply integer. The integer is null.");
        }
    }

    /**
     * Divides this integer by the integer.
     *
     * @param i the integer
     * @return the rest
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public Integer divideBy(Integer i) throws NullPointerException {

        Integer rest = null;
        
        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    rest = new Integer(j1.intValue() % j2.intValue());
                    setJavaObject(new java.lang.Integer(j1.intValue() / j2.intValue()));

                } else {
                    
                    throw new NullPointerException("Could not divide integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not divide integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not divide integer. The integer is null.");
        }
        
        return rest;
    }

    /**
     * Compares if this integer is dividable by the integer without rest.
     *
     * @param i the integer
     * @return true - if this integer is dividable by the integer without rest;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public boolean isDividableWithoutRest(Integer i) throws NullPointerException {

        boolean result = Boolean.FALSE;
        
        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    int rest = j1.intValue() % j2.intValue();

                    if (rest == 0) {
                        
                        result = Boolean.TRUE;
                    }

                } else {
                    
                    throw new NullPointerException("Could not divide integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not divide integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not divide integer. The integer is null.");
        }
        
        return result;
    }

    /**
     * Compares if this integer is dividable by the integer without rest.
     *
     * @param i the integer
     * @return true - if this integer is dividable by the integer without rest;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public boolean isDividableWithoutRest(int i) throws NullPointerException {

        boolean result = Boolean.FALSE;
        java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

        if (j1 != null) {

            int rest = j1.intValue() % i;

            if (rest == 0) {
                
                result = Boolean.TRUE;
            }

        } else {
            
            throw new NullPointerException("Could not divide integer. This java integer 1 is null.");
        }
        
        return result;
    }

    /**
     * Returns the absolute value (without sign) of this integer.
     *
     * @return the absolute value (without sign) of this integer
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if the java integer 1 is null
     */
    public Integer absolute() throws NullPointerException {

        Integer abs = null;
        
/*??
        java.lang.Integer j = (java.lang.Integer) getJavaObject();

        if (j != null) {
            
            int i = abs(j.intValue());
            abs = new java.lang.Integer(i);

        } else {
            
            throw new NullPointerException("Could not determine absolute value. The java integer is null.");
        }
*/

        return abs;
    }

    //
    // Comparison.
    //
    
    /**
     * Compares if this integer is equal to the given integer.
     *
     * @param i the integer
     * @return true - if this integer is equal to the given integer;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if this java integer 1 is null
     */
    public boolean isEqualTo(Integer i) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    if (j1.intValue() == j2.intValue()) {

                        result = Boolean.TRUE;
                    }
                
                } else {
                    
                    throw new NullPointerException("Could not compare integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not compare integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not compare integer. The integer is null.");
        }

        return result;        
    }

    /**
     * Compares if this integer is equal to the given integer.
     *
     * @param p the primitive integer
     * @return true - if this integer is equal to the given integer;
     * false - otherwise
     * @exception NullPointerException if the java integer is null
     */
    public boolean isEqualTo(int p) throws NullPointerException {

        boolean result = Boolean.FALSE;
        java.lang.Integer j = (java.lang.Integer) getJavaObject();
        
        if (j != null) {
            
            if (j.intValue() == p) {

                result = Boolean.TRUE;
            }
        
        } else {
            
            throw new NullPointerException("Could not compare integer. This java integer is null.");
        }
            
        return result;        
    }

    /**
     * Compares if this integer is smaller than the given integer.
     *
     * @param i the integer
     * @return true - if this integer is smaller than the given integer;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if this java integer 1 is null
     */
    public boolean isSmallerThan(Integer i) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    if (j1.intValue() < j2.intValue()) {

                        result = Boolean.TRUE;
                    }
                
                } else {
                    
                    throw new NullPointerException("Could not compare integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not compare integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not compare integer. The integer is null.");
        }

        return result;        
    }

    /**
     * Compares if this integer is smaller than the given integer.
     *
     * @param p the primitive integer
     * @return true - if this integer is smaller than the given integer;
     * false - otherwise
     * @exception NullPointerException if the java integer is null
     */
    public boolean isSmallerThan(int p) throws NullPointerException {

        boolean result = Boolean.FALSE;
        java.lang.Integer j = (java.lang.Integer) getJavaObject();
        
        if (j != null) {
            
            if (j.intValue() < p) {

                result = Boolean.TRUE;
            }
        
        } else {
            
            throw new NullPointerException("Could not compare integer. This java integer is null.");
        }
            
        return result;        
    }

    /**
     * Compares if this integer is greater than the given integer.
     *
     * @param i the integer
     * @return true - if this integer is greater than the given integer;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if this java integer 1 is null
     */
    public boolean isGreaterThan(Integer i) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    if (j1.intValue() > j2.intValue()) {

                        result = Boolean.TRUE;
                    }
                
                } else {
                    
                    throw new NullPointerException("Could not compare integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not compare integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not compare integer. The integer is null.");
        }

        return result;        
    }

    /**
     * Compares if this integer is greater than the given integer.
     *
     * @param p the primitive integer
     * @return true - if this integer is greater than the given integer;
     * false - otherwise
     * @exception NullPointerException if the java integer is null
     */
    public boolean isGreaterThan(int p) throws NullPointerException {

        boolean result = Boolean.FALSE;
        java.lang.Integer j = (java.lang.Integer) getJavaObject();
        
        if (j != null) {
            
            if (j.intValue() > p) {

                result = Boolean.TRUE;
            }
        
        } else {
            
            throw new NullPointerException("Could not compare integer. This java integer is null.");
        }
            
        return result;        
    }

    /**
     * Compares if this integer is smaller than or equal to the given integer.
     *
     * @param i the integer
     * @return true - if this integer is smaller than or equal to the given integer;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if this java integer 1 is null
     */
    public boolean isSmallerThanOrEqualTo(Integer i) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    if (j1.intValue() <= j2.intValue()) {

                        result = Boolean.TRUE;
                    }
                
                } else {
                    
                    throw new NullPointerException("Could not compare integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not compare integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not compare integer. The integer is null.");
        }

        return result;        
    }

    /**
     * Compares if this integer is smaller than or equal to the given integer.
     *
     * @param p the primitive integer
     * @return true - if this integer is smaller than or equal to the given integer;
     * false - otherwise
     * @exception NullPointerException if the java integer is null
     */
    public boolean isSmallerThanOrEqualTo(int p) throws NullPointerException {

        boolean result = Boolean.FALSE;
        java.lang.Integer j = (java.lang.Integer) getJavaObject();
        
        if (j != null) {
            
            if (j.intValue() <= p) {

                result = Boolean.TRUE;
            }

        } else {

            throw new NullPointerException("Could not compare integer. This java integer is null.");
        }

        return result;        
    }

    /**
     * Compares if this integer is greater than or equal to the given integer.
     *
     * @param i the integer
     * @return true - if this integer is greater than or equal to the given integer;
     * false - otherwise
     * @exception NullPointerException if the integer is null
     * @exception NullPointerException if the java integer 2 is null
     * @exception NullPointerException if this java integer 1 is null
     */
    public boolean isGreaterThanOrEqualTo(Integer i) throws NullPointerException {

        boolean result = Boolean.FALSE;

        if (i != null) {

            java.lang.Integer j2 = (java.lang.Integer) i.getJavaObject();

            if (j2 != null) {

                java.lang.Integer j1 = (java.lang.Integer) getJavaObject();

                if (j1 != null) {

                    if (j1.intValue() >= j2.intValue()) {

                        result = Boolean.TRUE;
                    }
                
                } else {
                    
                    throw new NullPointerException("Could not compare integer. This java integer 1 is null.");
                }

            } else {
                
                throw new NullPointerException("Could not compare integer. The java integer 2 is null.");
            }
                
        } else {
            
            throw new NullPointerException("Could not compare integer. The integer is null.");
        }

        return result;        
    }

    /**
     * Compares if this integer is greater than or equal to the given integer.
     *
     * @param p the primitive integer
     * @return true - if this integer is greater than or equal to the given integer;
     * false - otherwise
     * @exception NullPointerException if the java integer is null
     */
    public boolean isGreaterThanOrEqualTo(int p) throws NullPointerException {

        boolean result = Boolean.FALSE;
        java.lang.Integer j = (java.lang.Integer) getJavaObject();
        
        if (j != null) {
            
            if (j.intValue() >= p) {

                result = Boolean.TRUE;
            }
        
        } else {
            
            throw new NullPointerException("Could not compare integer. This java integer is null.");
        }
            
        return result;        
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
    public static Integer toInteger(String s) throws NullPointerException {

        Integer i = null;

        if (s != null) {

            i = new Integer(java.lang.Integer.valueOf((java.lang.String) s.getJavaObject()));
        
        } else {
            
            throw new NullPointerException("Could not transform string to integer. The string is null.");
        }

        return i;
    }
}

