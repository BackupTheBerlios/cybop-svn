/*
 * $RCSfile: Complex.java,v $
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

package cybop.core.model.principle;

import cybop.core.basic.String;
import cybop.core.model.*;

/**
 * This class represents a complex number.
 *
 * A complex number has two parts, one called "real" and a second
 * one called "imaginary".
 *
 * @version $Revision: 1.1 $ $Date: 2003-05-18 17:25:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
public class Complex extends Principle {

    //
    // Attribute ids.
    //

    /** The real part. */
    public static final String REAL = new String("real");

    /** The imaginary part. */
    public static final String IMAGINARY = new String("imaginary");

    /** The absolute value. */
    public static final String ABSOLUTE = new String("absolute");

    /** The argument value. */
    public static final String ARGUMENT = new String("argument");

    //
    // Algebra.
    //

    /**
     * Adds the complex number.
     *
     * @paramcthe complex number
     */
/*??
    public void add(Complex c) {
        
        setReal(getReal() + c.getReal());
        setImag(getImag() + c.getImag());
    }
    
    /**
     * Adds the integer.
     *
     * @param i the integer
     */
/*??
    public void add(int i) {
        
        Complex tmp(c);
    
        add( tmp );
    }
    
    /**
     * Adds the double
     *
     * @param d the double
     */
/*??
    void add(double d) {
        
        Complex tmp(c);
    
        add( tmp );
    }
    
    /**
     * Adds the fraction.
     *
     * @param f the fraction
     */
/*??
    void add(Fraction f) {
        
        Complex tmp(c);
    
        add( tmp );
    }
    
    /**
     * Subtracts the complex number.
     *
     * @param c the complex numer
     */
/*??
    void sub(Complex c) {
        
        setReal( getReal() - c.getReal() );
        setImag( getImag() - c.getImag() );
    }
    
    /**
     * Subtracts the integer. 
     *
     * @param i the integer
     */
/*??
    void sub(int i) {
        
        Complex tmp(c);
    
        sub( tmp );
    }
    
    /**
     * Subtracts the double. 
     *
     * @param d the double
     */
/*??
    void sub(double d) {
        
        Complex tmp(c);
    
        sub( tmp );
    }

    /**
     * Subtracts the fraction. 
     *
     * @param f the fraction
     */
/*??
    void sub(Fraction f) {
        
        Complex tmp(c);
    
        sub( tmp );
    }
    
    /**
     * Multiplicates the complex number.
     *
     * @param c the complex number
     */
/*??
    void multiplicate(Complex c) {
        
        setAbs( getAbs() * c.getAbs() );
        setArg( getArg() + c.getArg() );
    }
    
    /**
     * Multiplicates the integer. 
     *
     * @param i the integer
     */
/*??
    void mul(int i) {
        
        Complex tmp(c);
    
        mul( tmp );
    }
    
    /**
     * Multiplicate the double. 
     *
     * @param d the double
     */
/*??
    void mul(double c) {
        
        Complex tmp(c);
    
        mul( tmp );
    }
    
    /**
     * Multiplicate this complex with the fraction. 
     *
     * @param f the fraction
     */
/*??
    void mul(Fraction c) {
        
        Complex tmp(c);
    
        mul( tmp );
    }
    
    /**
     * Divide this complex by the complex number.
     *
     * @param c the complex number
     */
/*??
    void div(Complex c) {
        
        setAbs( getAbs() / c.getAbs() );
        setArg( getArg() - c.getArg() );
    }
    
    /**
     * Divide this complex by the integer.
     *
     * @param i the integer
     */
/*??
    void div(int i) {

        Complex tmp(c);
    
        div( tmp );
    }
    
    /**
     * Divide this complex by the double.
     *
     * @param d the double
     */
/*??
    void div(double d) {
        
        Complex tmp(c);
    
        div( tmp );
    }
    
    /**
     * Divide this complex by the fraction.
     *
     * @param f the fraction
     */
/*??
    void div(Fraction f) {
        
        Complex tmp(c);
    
        div( tmp );
    }

    //
    // Transfer parts of the complex number into each other.
    //
    
    /**
     * Determine real part from absolute value and argument.
     */
/*??
    void real() {
        
        m_real = m_abs * cos( m_arg );
    }
    
    /**
     * Determine imaginary part from absolute value and argument (angle).
     */
/*??
    void imag() {
        
        m_imag = m_abs * sin( m_arg );
    }
    
    /**
     * Determine absolute from real part and imaginary part.
     */
/*??
    void abs() {
        
        m_abs = sqrt( pow( m_real, 2 ) + pow( m_imag, 2 ) );
    }
    
    /**
     * Determine argument (angle) from real part and imaginary part.
     */
/*??
    void arg() {
        
        double tmpSummand = 0;
    
        if( m_real <= 0 )
        {
            if (( m_real < 0 ) && ( m_imag >= 0 ) )
            {
                tmpSummand = PI;
            }
            else if (( m_real < 0 ) && ( m_imag < 0 ) )
            {
                tmpSummand = -PI;
                    }
            }
    
        m_arg = atan2( m_imag, m_real ) + tmpSummand;
    }
*/
}

