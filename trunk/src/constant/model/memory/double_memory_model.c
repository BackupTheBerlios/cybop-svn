/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: double_memory_model.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_MEMORY_MODEL_SOURCE
#define DOUBLE_MEMORY_MODEL_SOURCE

#include <math.h>

//
// Numbers 0.0 - 0.9.
//

/** The number 0.0 double memory model. */
static double NUMBER_0_0_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.0};
static double* NUMBER_0_0_DOUBLE_MEMORY_MODEL = NUMBER_0_0_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.1 double memory model. */
static double NUMBER_0_1_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.1};
static double* NUMBER_0_1_DOUBLE_MEMORY_MODEL = NUMBER_0_1_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.2 double memory model. */
static double NUMBER_0_2_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.2};
static double* NUMBER_0_2_DOUBLE_MEMORY_MODEL = NUMBER_0_2_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.3 double memory model. */
static double NUMBER_0_3_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.3};
static double* NUMBER_0_3_DOUBLE_MEMORY_MODEL = NUMBER_0_3_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.4 double memory model. */
static double NUMBER_0_4_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.4};
static double* NUMBER_0_4_DOUBLE_MEMORY_MODEL = NUMBER_0_4_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.5 double memory model. */
static double NUMBER_0_5_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.5};
static double* NUMBER_0_5_DOUBLE_MEMORY_MODEL = NUMBER_0_5_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.6 double memory model. */
static double NUMBER_0_6_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.6};
static double* NUMBER_0_6_DOUBLE_MEMORY_MODEL = NUMBER_0_6_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.7 double memory model. */
static double NUMBER_0_7_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.7};
static double* NUMBER_0_7_DOUBLE_MEMORY_MODEL = NUMBER_0_7_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.8 double memory model. */
static double NUMBER_0_8_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.8};
static double* NUMBER_0_8_DOUBLE_MEMORY_MODEL = NUMBER_0_8_DOUBLE_MEMORY_MODEL_ARRAY;

/** The number 0.9 double memory model. */
static double NUMBER_0_9_DOUBLE_MEMORY_MODEL_ARRAY[] = {0.9};
static double* NUMBER_0_9_DOUBLE_MEMORY_MODEL = NUMBER_0_9_DOUBLE_MEMORY_MODEL_ARRAY;

//
// Numbers 1.0 - 1.9.
//

/** The number 1.0 double memory model. */
static double NUMBER_1_0_DOUBLE_MEMORY_MODEL_ARRAY[] = {1.0};
static double* NUMBER_1_0_DOUBLE_MEMORY_MODEL = NUMBER_1_0_DOUBLE_MEMORY_MODEL_ARRAY;

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

/** The base of natural logarithms double memory model. */
static double E_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_E};
static double* E_DOUBLE_MEMORY_MODEL = E_DOUBLE_MEMORY_MODEL_ARRAY;

/** The logarithm to base 2 of M_E double memory model. */
static double LOG_2_E_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_LOG2E};
static double* LOG_2_E_DOUBLE_MEMORY_MODEL = LOG_2_E_DOUBLE_MEMORY_MODEL_ARRAY;

/** The logarithm to base 10 of M_E double memory model. */
static double LOG_10_E_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_LOG10E};
static double* LOG_10_E_DOUBLE_MEMORY_MODEL = LOG_10_E_DOUBLE_MEMORY_MODEL_ARRAY;

/** The natural logarithm of 2 double memory model. */
static double LN_2_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_LN2};
static double* LN_2_DOUBLE_MEMORY_MODEL = LN_2_DOUBLE_MEMORY_MODEL_ARRAY;

/** The natural logarithm of 10 double memory model. */
static double LN_10_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_LN10};
static double* LN_10_DOUBLE_MEMORY_MODEL = LN_10_DOUBLE_MEMORY_MODEL_ARRAY;

/** The ratio of a circle's circumference to its diameter, called "pi" double memory model. */
static double PI_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_PI};
static double* PI_DOUBLE_MEMORY_MODEL = PI_DOUBLE_MEMORY_MODEL_ARRAY;

/** The pi divided by 2 double memory model. */
static double PI_DIVIDED_BY_2_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_PI_2};
static double* PI_DIVIDED_BY_2_DOUBLE_MEMORY_MODEL = PI_DIVIDED_BY_2_DOUBLE_MEMORY_MODEL_ARRAY;

/** The pi divided by 4 double memory model. */
static double PI_DIVIDED_BY_4_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_PI_4};
static double* PI_DIVIDED_BY_4_DOUBLE_MEMORY_MODEL = PI_DIVIDED_BY_4_DOUBLE_MEMORY_MODEL_ARRAY;

/** The reciprocal of pi (1/pi) double memory model. */
static double RECIPROCAL_OF_PI_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_1_PI};
static double* RECIPROCAL_OF_PI_DOUBLE_MEMORY_MODEL = RECIPROCAL_OF_PI_DOUBLE_MEMORY_MODEL_ARRAY;

/** The two times the reciprocal of pi double memory model. */
static double TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_2_PI};
static double* TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_MEMORY_MODEL = TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_MEMORY_MODEL_ARRAY;

/** The two times the reciprocal of the square root of pi double memory model. */
static double TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_2_SQRTPI};
static double* TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_MEMORY_MODEL = TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_MEMORY_MODEL_ARRAY;

/** The square root of 2 double memory model. */
static double SQUARE_ROOT_OF_2_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_SQRT2};
static double* SQUARE_ROOT_OF_2_DOUBLE_MEMORY_MODEL = SQUARE_ROOT_OF_2_DOUBLE_MEMORY_MODEL_ARRAY;

/** The reciprocal of the square root of 2 (also the square root of 1/2) double memory model. */
static double RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_MEMORY_MODEL_ARRAY[] = {M_SQRT1_2};
static double* RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_MEMORY_MODEL = RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_MEMORY_MODEL_ARRAY;

/* DOUBLE_MEMORY_MODEL_SOURCE */
#endif
