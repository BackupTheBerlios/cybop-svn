/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: primitive_type_size.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REAL_TYPE_SIZE_SOURCE
#define REAL_TYPE_SIZE_SOURCE

//
// CAUTION! Do NOT try to assign any values here!
// Otherwise, the compiler shows the following error:
// "error: initializer element is not constant"
// Therefore, the variables are only initialised in module "globaliser.c".
//

//
// The standard header file "float.h" defines the minimum and maximum values
// of the floating-point types float, double, and long double.
// It also defines other limits that are relevant to the processing
// of floating-point numbers.
//

//
// A double variable can be marked as being a "long double",
// which the compiler may use to select a larger floating point
// representation than a plain double. However, the standard is
// unspecific on the relative sizes of the floating point values,
// and only requires a float not to be larger than a double,
// which should not be larger than a long double.
//

//
// Each of the three types of real values may represent values
// in a different form, often one of the IEEE floating point formats:
// http://en.wikipedia.org/wiki/IEEE_floating-point
//
// Floating-point constants may be written in decimal notation, e.g. 1.23.
//
// Scientific notation may be used by adding e or E followed by a
// decimal exponent, e.g. 1.23e2 (which has the value 123).
// Either a decimal point or an exponent is required
// (otherwise, the number is an integer constant).
//
// Hexadecimal floating-point constants follow similar rules except that
// they must be prefixed by 0x and use p to specify a binary exponent,
// e.g. 0xAp-2 (which has the value 2.5, since 10 * 2^-2 = 10 / 4).
//
// Both decimal and hexadecimal floating-point constants may be suffixed by:
// - f or F to indicate a constant of type float,
// - by l or L to indicate type long double
// - or left unsuffixed for a double constant.
//

/**
 * The float real type size.
 *
 * single-precision
 *
 * Minimum allowed range: 1×10^−37..1×10^37
 * Typical allowed range: 1×10^−37..1×10^37
 * Typical size [Byte]: 4
 * Typical size [Bit]: 32
 */
static signed char* FLOAT_REAL_TYPE_SIZE;

/**
 * The double real type size.
 *
 * double-precision
 *
 * Minimum allowed range: 1×10^−37..1×10^37
 * Typical allowed range: 1×10^−308..1×10^308
 * Typical size [Byte]: 8
 * Typical size [Bit]: 64
 */
static signed char* DOUBLE_REAL_TYPE_SIZE;

/**
 * The long double real type size.
 *
 * double-extended-precision
 *
 * Minimum allowed range: 1×10^−37..1×10^37
 * Typical allowed range: 1×10^−308..1×10^308 or 1×10^−4932..1×10^4932 (x87 FPU systems)
 * Typical size [Byte]: 8 or 12
 * Typical size [Bit]: 64 or 96
 */
static signed char* LONG_DOUBLE_REAL_TYPE_SIZE;

/* REAL_TYPE_SIZE_SOURCE */
#endif
