/*
 * $RCSfile: Fraction.java,v $
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
 * This class represents a fraction.
 *
 * A fraction consists of a numerator and a denominator.
 * In computing, it is also known as floating point- or double number,
 * having a part "before and after the point/comma".
 *
 * @version $Revision: 1.2 $ $Date: 2003-06-12 21:16:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Fraction extends Quantity {

    //
    // Constants.
    //

    /** The minimum value. */
    public static final double MINIMUM = java.lang.Double.MIN_VALUE;

    /** The maximum value. */
    public static final double MAXIMUM = java.lang.Double.MAX_VALUE;

    /** The default value. */
    public static final double DEFAULT = 0.0;

    //
    // Attribute ids.
    //

    /** The numerator. */
    public static final String NUMERATOR = new String("numerator");

    /** The denominator. */
    public static final String DENOMINATOR = new String("denominator");

    //
    // Construction.
    //
    
    /**
     * Constructs this fraction.
     */
    public Fraction() {

        super();
    }

    /**
     * Constructs this fraction.<br><br>
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
     *
     * @param d the primitive double value
     */
    public Fraction(double d) {

        super();
        setJavaObject(new java.lang.Double(d));
    }
    
    //
    // Encapsulated java double.
    //
    
    /**
     * Creates an encapsulated java double.
     *
     * @return the encapsulated java double
     */
    public java.lang.Object createJavaObject() {

        return new java.lang.Double(createJavaPrimitive());
    }

    //
    // Java primitive.
    //
    
    /**
     * Creates the java primitive.
     *
     * @return the java primitive
     */
    public double createJavaPrimitive() {

        return Fraction.DEFAULT;
    }

    /**
     * Destroys the java primitive.
     *
     * @param p the java primitive
     */
    public void destroyJavaPrimitive(double p) {
    }

    /**
     * Sets the java primitive.
     *
     * @param p the java primitive
     * @exception Exception if the java object is null
     */
    public void setJavaPrimitive(double p) throws Exception {
    }

    /**
     * Returns the java primitive.
     *
     * @return the java primitive
     * @exception Exception if the java object is null
     */
    public double getJavaPrimitive() throws Exception {

        double p = Fraction.DEFAULT;
        java.lang.Double j = (java.lang.Double) getJavaObject();
        
        if (j != null) {

            p = j.doubleValue();

        } else {
        
            throw new Exception("Could not get java primitive. The java object is null.");
        }            

        return p;
    }

    //
    // Algebra.
    //

    /**
     * Adds the fraction.
     *
     * @param f the fraction
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     * @exception Exception if the denominator 1 is null
     */
    public void add(Fraction f) throws Exception {

/*??
        if (f != null) {

            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);

            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);

                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));

                    if (extnum1 != null) {

                        Integer den1 = (Integer) getChild(Fraction.DENOMINATOR);
            
                        if (den1 != null) {
                            
                            setChild(Fraction.NUMERATOR, extnum1.add(extnum2));
                            setChild(Fraction.DENOMINATOR, den1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR)));
                            reduct();
    
                        } else {
            
                            throw new Exception("Could not add fraction. The denominator 1 is null.");
                        }

                    } else {
        
                        throw new Exception("Could not add fraction. The extended numerator 1 is null.");
                    }            
                    
                } else {
    
                    throw new Exception("Could not add fraction. The numerator 1 is null.");
                }
    
            } else {

                throw new Exception("Could not add fraction. The numerator 2 is null.");
            }

        } else {
        
            throw new Exception("Could not add fraction. The fraction is null.");
        }
*/
    }

    /**
     * Subtracts the fraction.
     *
     * @param f the fraction
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     * @exception Exception if the denominator 1 is null
     */
    public void subtract(Fraction f) throws Exception {

/*??
        if (f != null) {

            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);

            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
                
                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));

                    if (extnum1 != null) {

                        Integer den1 = (Integer) getChild(Fraction.DENOMINATOR);
            
                        if (den1 != null) {
                            
                            setChild(Fraction.NUMERATOR, extnum1.subtract(extnum2));
                            setChild(Fraction.DENOMINATOR, den1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR)));
                            reduct();
                
                        } else {
            
                            throw new Exception("Could not subtract fraction. The denominator 1 is null.");
                        }

                    } else {
        
                        throw new Exception("Could not subtract fraction. The extended numerator 1 is null.");
                    }            
                    
                } else {
    
                    throw new Exception("Could not subtract fraction. The numerator 1 is null.");
                }
    
            } else {

                throw new Exception("Could not subtract fraction. The numerator 2 is null.");
            }

        } else {
        
            throw new Exception("Could not subtract fraction. The fraction is null.");
        }
*/
    }

    /**
     * Multiplies this fraction with the fraction.
     *
     * @param f the fraction
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the denominator 1 is null
     */
    public void multiplyWith(Fraction f) throws Exception {

/*??
        if (f != null) {

            Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
            
            if (num1 != null) {

                Integer den1 = (Integer) getChild(Fraction.DENOMINATOR);

                if (den1 != null) {

                    setChild(Fraction.NUMERATOR, num1.multiplyWith((Integer) f.getChild(Fraction.NUMERATOR)));
                    setChild(Fraction.DENOMINATOR, den1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR)));
                    reduct();

                } else {
    
                    throw new Exception("Could not multiply fraction. The denominator 1 is null.");
                }

            } else {

                throw new Exception("Could not multiply fraction. The numerator 1 is null.");
            }

        } else {
        
            throw new Exception("Could not multiply fraction. The fraction is null.");
        }
*/
    }

    /**
     * Divides this fraction by the fraction.
     *
     * @param f the fraction
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the denominator 1 is null
     */
    public void divideBy(Fraction f) throws Exception {

/*??
        if (f != null) {

            Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
            
            if (num1 != null) {

                Integer den1 = (Integer) getChild(Fraction.DENOMINATOR);

                if (den1 != null) {

                    setChild(Fraction.NUMERATOR, num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR)));
                    setChild(Fraction.DENOMINATOR, den1.multiplyWith((Integer) f.getChild(Fraction.NUMERATOR)));
                    reduct();

                } else {
    
                    throw new Exception("Could not divide fraction. The denominator 1 is null.");
                }

            } else {

                throw new Exception("Could not divide fraction. The numerator 1 is null.");
            }

        } else {
        
            throw new Exception("Could not divide fraction. The fraction is null.");
        }
*/
    }

    //
    // Comparison.
    //
    
    /**
     * Compares if this fraction is equal to the given fraction.
     *
     * @param f the fraction
     * @return true - if this fraction is equal to the given fraction;
     * false - otherwise
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     */
    public boolean isEqualTo(Fraction f) throws Exception {

        boolean result = Boolean.FALSE;

        if (f != null) {

/*??
            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);
            
            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));            
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
                
                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));
                    
                    if (extnum1 != null) {
                        
                        result = extnum1.isEqualTo(extnum2);

                    } else {
                        
                        throw new Exception("Could not compare fraction. The extended numerator 1 is null.");
                    }

                } else {
                    
                    throw new Exception("Could not compare fraction. The numerator 1 is null.");
                }

            } else {
                
                throw new Exception("Could not compare fraction. The numerator 2 is null.");
            }
*/
                
        } else {
            
            throw new Exception("Could not compare fraction. The fraction is null.");
        }

        return result;        
    }

    /**
     * Compares if this fraction is smaller than the given fraction.
     *
     * @param f the fraction
     * @return true - if this fraction is smaller than the given fraction;
     * false - otherwise
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     */
    public boolean isSmallerThan(Fraction f) throws Exception {

        boolean result = Boolean.FALSE;

        if (f != null) {

/*??
            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);
            
            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));            
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
                
                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));
                    
                    if (extnum1 != null) {
                        
                        result = extnum1.isSmallerThan(extnum2);

                    } else {
                        
                        throw new Exception("Could not compare fraction. The extended numerator 1 is null.");
                    }

                } else {
                    
                    throw new Exception("Could not compare fraction. The numerator 1 is null.");
                }

            } else {
                
                throw new Exception("Could not compare fraction. The numerator 2 is null.");
            }
*/
                
        } else {
            
            throw new Exception("Could not compare fraction. The fraction is null.");
        }

        return result;        
    }

    /**
     * Compares if this fraction is greater than the given fraction.
     *
     * @param f the fraction
     * @return true - if this fraction is greater than the given fraction;
     * false - otherwise
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     */
    public boolean isGreaterThan(Fraction f) throws Exception {

        boolean result = Boolean.FALSE;

        if (f != null) {

/*??
            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);
            
            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));            
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
                
                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));
                    
                    if (extnum1 != null) {
                        
                        result = extnum1.isGreaterThan(extnum2);

                    } else {
                        
                        throw new Exception("Could not compare fraction. The extended numerator 1 is null.");
                    }

                } else {
                    
                    throw new Exception("Could not compare fraction. The numerator 1 is null.");
                }

            } else {
                
                throw new Exception("Could not compare fraction. The numerator 2 is null.");
            }
*/
                
        } else {
            
            throw new Exception("Could not compare fraction. The fraction is null.");
        }

        return result;        
    }

    /**
     * Compares if this fraction is smaller than or equal to the given fraction.
     *
     * @param f the fraction
     * @return true - if this fraction is smaller than or equal to the given fraction;
     * false - otherwise
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     */
    public boolean isSmallerThanOrEqualTo(Fraction f) throws Exception {

        boolean result = Boolean.FALSE;

        if (f != null) {

/*??
            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);
            
            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));            
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
                
                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));
                    
                    if (extnum1 != null) {
                        
                        result = extnum1.isSmallerThanOrEqualTo(extnum2);

                    } else {
                        
                        throw new Exception("Could not compare fraction. The extended numerator 1 is null.");
                    }

                } else {
                    
                    throw new Exception("Could not compare fraction. The numerator 1 is null.");
                }

            } else {
                
                throw new Exception("Could not compare fraction. The numerator 2 is null.");
            }
*/
                
        } else {
            
            throw new Exception("Could not compare fraction. The fraction is null.");
        }

        return result;        
    }

    /**
     * Compares if this fraction is greater than or equal to the given fraction.
     *
     * @param f the fraction
     * @return true - if this fraction is greater than or equal to the given fraction;
     * false - otherwise
     * @exception Exception if the fraction is null
     * @exception Exception if the numerator 2 is null
     * @exception Exception if the numerator 1 is null
     * @exception Exception if the extended numerator 1 is null
     */
    public boolean isGreaterThanOrEqualTo(Fraction f) throws Exception {

        boolean result = Boolean.FALSE;

        if (f != null) {

/*??
            Integer num2 = (Integer) f.getChild(Fraction.NUMERATOR);
            
            if (num2 != null) {
                
                Integer extnum2 = num2.multiplyWith((Integer) getChild(Fraction.DENOMINATOR));            
                Integer num1 = (Integer) getChild(Fraction.NUMERATOR);
                
                if (num1 != null) {
                    
                    Integer extnum1 = num1.multiplyWith((Integer) f.getChild(Fraction.DENOMINATOR));
                    
                    if (extnum1 != null) {
                        
                        result = extnum1.isGreaterThanOrEqualTo(extnum2);

                    } else {
                        
                        throw new Exception("Could not compare fraction. The extended numerator 1 is null.");
                    }

                } else {
                    
                    throw new Exception("Could not compare fraction. The numerator 1 is null.");
                }

            } else {
                
                throw new Exception("Could not compare fraction. The numerator 2 is null.");
            }
*/
                
        } else {
            
            throw new Exception("Could not compare fraction. The fraction is null.");
        }

        return result;        
    }

    /**
     * Reducts this fraction.
     */
    public void reduct() throws Exception {

        Integer den = (Integer) getChild(Fraction.DENOMINATOR);
        
        if (den != null) {
            
            Integer num = (Integer) getChild(Fraction.NUMERATOR);
            
            if (num != null) {
    
                Integer absnum = num.absolute();
                
                if (absnum != null) {
    
                    // Find the biggest divider that both, numerator and denominator contain.                
                    Integer max;
    
                    if (absnum.isSmallerThanOrEqualTo((Integer) getChild(Fraction.DENOMINATOR))) {
    
                        max = absnum;
                        
                    } else {
                        
                        max = (Integer) getChild(Fraction.DENOMINATOR);
                    }
    
                    Integer rednum;
                    
                    if (max != null) {

                        // Find the first divider with integer result (without rest).
                        // Begin with the biggest divider that both, numerator and denominator contain.
                        int i = max.getJavaPrimitive();

                        while (i > 1) {

                            if (absnum.isDividableWithoutRest(i) && den.isDividableWithoutRest(i)) {
                                
/*??
                                rednum = absnum.divideBy(i);
    
                                if (num.isSmallerThan(0)) {
                                    
                                    setChild(Fraction.NUMERATOR, rednum.multiplyWith(-1));
                                    
                                } else {
                                    
                                    setChild(Fraction.NUMERATOR, rednum);
                                }
    
                                setChild(Fraction.DENOMINATOR, den.divideBy(i));
                                break;
*/
                            }

                            i--;
                        }
                
                    } else {
                        
                        throw new Exception("Could not reduct fraction. The maximum divider is null.");
                    }
                }
            }
        }
    }
}

