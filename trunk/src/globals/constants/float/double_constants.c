/*
 * $RCSfile: double_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
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
 *
 * @version $Revision: 1.1 $ $Date: 2007-04-09 16:34:25 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_CONSTANTS_SOURCE
#define DOUBLE_CONSTANTS_SOURCE

#include <math.h>

//
// Mathematical.
//
// The header math.h defines several useful mathematical constants.
// All values are defined as preprocessor macros starting with M_.
//
// These constants come from the Unix98 standard and were also available in 4.4BSD;
// therefore they are only defined if _BSD_SOURCE or _XOPEN_SOURCE=500, or a more general
// feature select macro, is defined. The default set of features includes these constants.
//
// All values are of type double.
// As an extension, the GNU C library also defines these constants with type long double.
// The long double macros have a lowercase l appended to their names: M_El, M_PIl, and so forth.
// These are only available if _GNU_SOURCE is defined.
//

/** The base of natural logarithms double. */
static double E_DOUBLE_ARRAY[] = {M_E};
static double* E_DOUBLE = E_DOUBLE_ARRAY;

/** The logarithm to base 2 of M_E double. */
static double LOG_2_E_DOUBLE_ARRAY[] = {M_LOG2E};
static double* LOG_2_E_DOUBLE = LOG_2_E_DOUBLE_ARRAY;

/** The logarithm to base 10 of M_E double. */
static double LOG_10_E_DOUBLE_ARRAY[] = {M_LOG10E};
static double* LOG_10_E_DOUBLE = LOG_10_E_DOUBLE_ARRAY;

/** The natural logarithm of 2 double. */
static double LN_2_DOUBLE_ARRAY[] = {M_LN2};
static double* LN_2_DOUBLE = LN_2_DOUBLE_ARRAY;

/** The natural logarithm of 10 double. */
static double LN_10_DOUBLE_ARRAY[] = {M_LN10};
static double* LN_10_DOUBLE = LN_10_DOUBLE_ARRAY;

/** The ratio of a circle's circumference to its diameter, called "pi" double. */
static double PI_DOUBLE_ARRAY[] = {M_PI};
static double* PI_DOUBLE = PI_DOUBLE_ARRAY;

/** The pi divided by 2 double. */
static double PI_DIVIDED_BY_2_DOUBLE_ARRAY[] = {M_PI_2};
static double* PI_DIVIDED_BY_2_DOUBLE = PI_DIVIDED_BY_2_DOUBLE_ARRAY;

/** The pi divided by 4 double. */
static double PI_DIVIDED_BY_4_DOUBLE_ARRAY[] = {M_PI_4};
static double* PI_DIVIDED_BY_4_DOUBLE = PI_DIVIDED_BY_4_DOUBLE_ARRAY;

/** The reciprocal of pi (1/pi) double. */
static double RECIPROCAL_OF_PI_DOUBLE_ARRAY[] = {M_1_PI};
static double* RECIPROCAL_OF_PI_DOUBLE = RECIPROCAL_OF_PI_DOUBLE_ARRAY;

/** The two times the reciprocal of pi double. */
static double TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_ARRAY[] = {M_2_PI};
static double* TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE = TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_ARRAY;

/** The two times the reciprocal of the square root of pi double. */
static double TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_ARRAY[] = {M_2_SQRTPI};
static double* TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE = TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_ARRAY;

/** The square root of 2 double. */
static double SQUARE_ROOT_OF_2_DOUBLE_ARRAY[] = {M_SQRT2};
static double* SQUARE_ROOT_OF_2_DOUBLE = SQUARE_ROOT_OF_2_DOUBLE_ARRAY;

/** The reciprocal of the square root of 2 (also the square root of 1/2) double. */
static double RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_ARRAY[] = {M_SQRT1_2};
static double* RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE = RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_ARRAY;

/* DOUBLE_CONSTANTS_SOURCE */
#endif
