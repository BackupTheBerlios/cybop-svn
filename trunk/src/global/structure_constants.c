/*
 * $RCSfile: structure_constants.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 *
 * This file defines global model structure constants.
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * @version $Revision: 1.7 $ $Date: 2004-12-19 00:53:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRUCTURE_CONSTANTS_SOURCE
#define STRUCTURE_CONSTANTS_SOURCE

//
// Arrays.
//

/** The pointer array constant. */
static const int POINTER_ARRAY_ARRAY[] = {0};
static const int* POINTER_ARRAY = POINTER_ARRAY_ARRAY;

/** The integer array constant. */
static const int INTEGER_ARRAY_ARRAY[] = {1};
static const int* INTEGER_ARRAY = INTEGER_ARRAY_ARRAY;

/** The character array constant. */
static const int CHARACTER_ARRAY_ARRAY[] = {2};
static const int* CHARACTER_ARRAY = CHARACTER_ARRAY_ARRAY;

/** The double array constant. */
static const int DOUBLE_ARRAY_ARRAY[] = {3};
static const int* DOUBLE_ARRAY = DOUBLE_ARRAY_ARRAY;

//
// Array element counts.
//

/** The one element count. */
static const int ONE_ELEMENT_COUNT_ARRAY[] = {1};
static const int* ONE_ELEMENT_COUNT = ONE_ELEMENT_COUNT_ARRAY;

//
// String.
//

/** The string resize factor. */
static const int STRING_RESIZE_FACTOR_ARRAY[] = {2};
static const int* STRING_RESIZE_FACTOR = STRING_RESIZE_FACTOR_ARRAY;

//
// Integer.
//

/** The integer count. */
static const int INTEGER_COUNT_ARRAY[] = {1};
static const int* INTEGER_COUNT = INTEGER_COUNT_ARRAY;

/** The integer value index. */
static const int INTEGER_VALUE_INDEX_ARRAY[] = {0};
static const int* INTEGER_VALUE_INDEX = INTEGER_VALUE_INDEX_ARRAY;

//
// Double.
//

/** The double count. */
static const int DOUBLE_COUNT_ARRAY[] = {1};
static const int* DOUBLE_COUNT = DOUBLE_COUNT_ARRAY;

/** The double value index. */
static const int DOUBLE_VALUE_INDEX_ARRAY[] = {0};
static const int* DOUBLE_VALUE_INDEX = DOUBLE_VALUE_INDEX_ARRAY;

//
// Fraction.
//

/** The fraction count. */
static const int FRACTION_COUNT_ARRAY[] = {2};
static const int* FRACTION_COUNT = FRACTION_COUNT_ARRAY;

/** The numerator index. */
static const int NUMERATOR_INDEX_ARRAY[] = {0};
static const int* NUMERATOR_INDEX = NUMERATOR_INDEX_ARRAY;

/** The denominator index. */
static const int DENOMINATOR_INDEX_ARRAY[] = {1};
static const int* DENOMINATOR_INDEX = DENOMINATOR_INDEX_ARRAY;

//
// Vector.
//

/** The vector count. */
static const int VECTOR_COUNT_ARRAY[] = {3};
static const int* VECTOR_COUNT = VECTOR_COUNT_ARRAY;

/** The x index. */
static const int X_INDEX_ARRAY[] = {0};
static const int* X_INDEX = X_INDEX_ARRAY;

/** The y index. */
static const int Y_INDEX_ARRAY[] = {1};
static const int* Y_INDEX = Y_INDEX_ARRAY;

/** The z index. */
static const int Z_INDEX_ARRAY[] = {2};
static const int* Z_INDEX = Z_INDEX_ARRAY;

//
// Time.
//

/** The time count. */
static const int TIME_COUNT_ARRAY[] = {6};
static const int* TIME_COUNT = TIME_COUNT_ARRAY;

/** The year index. */
static const int YEAR_INDEX_ARRAY[] = {0};
static const int* YEAR_INDEX = YEAR_INDEX_ARRAY;

/** The month index. */
static const int MONTH_INDEX_ARRAY[] = {1};
static const int* MONTH_INDEX = MONTH_INDEX_ARRAY;

/** The day index. */
static const int DAY_INDEX_ARRAY[] = {2};
static const int* DAY_INDEX = DAY_INDEX_ARRAY;

/** The hour index. */
static const int HOUR_INDEX_ARRAY[] = {3};
static const int* HOUR_INDEX = HOUR_INDEX_ARRAY;

/** The minute index. */
static const int MINUTE_INDEX_ARRAY[] = {4};
static const int* MINUTE_INDEX = MINUTE_INDEX_ARRAY;

/** The second index. */
static const int SECOND_INDEX_ARRAY[] = {5};
static const int* SECOND_INDEX = SECOND_INDEX_ARRAY;

//
// Complex.
//

/** The complex count. */
static const int COMPLEX_COUNT_ARRAY[] = {2};
static const int* COMPLEX_COUNT = COMPLEX_COUNT_ARRAY;

/** The real index. */
static const int REAL_INDEX_ARRAY[] = {0};
static const int* REAL_INDEX = REAL_INDEX_ARRAY;

/** The imaginary index. */
static const int IMAGINARY_INDEX_ARRAY[] = {1};
static const int* IMAGINARY_INDEX = IMAGINARY_INDEX_ARRAY;

//
// Compound.
//

/** The compound resize factor. */
static const int COMPOUND_RESIZE_FACTOR_ARRAY[] = {2};
static const int* COMPOUND_RESIZE_FACTOR = COMPOUND_RESIZE_FACTOR_ARRAY;

/** The compound count. */
static const int COMPOUND_COUNT_ARRAY[] = {12};
static const int* COMPOUND_COUNT = COMPOUND_COUNT_ARRAY;

/** The names index. */
static const int NAMES_INDEX_ARRAY[] = {0};
static const int* NAMES_INDEX = NAMES_INDEX_ARRAY;

/** The names counts index. */
static const int NAMES_COUNTS_INDEX_ARRAY[] = {1};
static const int* NAMES_COUNTS_INDEX = NAMES_COUNTS_INDEX_ARRAY;

/** The names sizes index. */
static const int NAMES_SIZES_INDEX_ARRAY[] = {2};
static const int* NAMES_SIZES_INDEX = NAMES_SIZES_INDEX_ARRAY;

/** The abstractions index. */
static const int ABSTRACTIONS_INDEX_ARRAY[] = {3};
static const int* ABSTRACTIONS_INDEX = ABSTRACTIONS_INDEX_ARRAY;

/** The abstractions counts index. */
static const int ABSTRACTIONS_COUNTS_INDEX_ARRAY[] = {4};
static const int* ABSTRACTIONS_COUNTS_INDEX = ABSTRACTIONS_COUNTS_INDEX_ARRAY;

/** The abstractions sizes index. */
static const int ABSTRACTIONS_SIZES_INDEX_ARRAY[] = {5};
static const int* ABSTRACTIONS_SIZES_INDEX = ABSTRACTIONS_SIZES_INDEX_ARRAY;

/** The models index. */
static const int MODELS_INDEX_ARRAY[] = {6};
static const int* MODELS_INDEX = MODELS_INDEX_ARRAY;

/** The models counts index. */
static const int MODELS_COUNTS_INDEX_ARRAY[] = {7};
static const int* MODELS_COUNTS_INDEX = MODELS_COUNTS_INDEX_ARRAY;

/** The models sizes index. */
static const int MODELS_SIZES_INDEX_ARRAY[] = {8};
static const int* MODELS_SIZES_INDEX = MODELS_SIZES_INDEX_ARRAY;

/** The details index. */
static const int DETAILS_INDEX_ARRAY[] = {9};
static const int* DETAILS_INDEX = DETAILS_INDEX_ARRAY;

/** The details counts index. */
static const int DETAILS_COUNTS_INDEX_ARRAY[] = {10};
static const int* DETAILS_COUNTS_INDEX = DETAILS_COUNTS_INDEX_ARRAY;

/** The details sizes index. */
static const int DETAILS_SIZES_INDEX_ARRAY[] = {11};
static const int* DETAILS_SIZES_INDEX = DETAILS_SIZES_INDEX_ARRAY;

//
// Signal memory.
//

/** The signal memory resize factor. */
static const int SIGNAL_MEMORY_RESIZE_FACTOR_ARRAY[] = {2};
static const int* SIGNAL_MEMORY_RESIZE_FACTOR = SIGNAL_MEMORY_RESIZE_FACTOR_ARRAY;

/** The signal memory count. */
static const int SIGNAL_MEMORY_COUNT_ARRAY[] = {8};
static const int* SIGNAL_MEMORY_COUNT = SIGNAL_MEMORY_COUNT_ARRAY;

/** The signals abstractions index. */
static const int SIGNALS_ABSTRACTIONS_INDEX_ARRAY[] = {0};
static const int* SIGNALS_ABSTRACTIONS_INDEX = SIGNALS_ABSTRACTIONS_INDEX_ARRAY;

/** The signals abstractions counts index. */
static const int SIGNALS_ABSTRACTIONS_COUNTS_INDEX_ARRAY[] = {1};
static const int* SIGNALS_ABSTRACTIONS_COUNTS_INDEX = SIGNALS_ABSTRACTIONS_COUNTS_INDEX_ARRAY;

/** The signals models index. */
static const int SIGNALS_MODELS_INDEX_ARRAY[] = {2};
static const int* SIGNALS_MODELS_INDEX = SIGNALS_MODELS_INDEX_ARRAY;

/** The signals models counts index. */
static const int SIGNALS_MODELS_COUNTS_INDEX_ARRAY[] = {3};
static const int* SIGNALS_MODELS_COUNTS_INDEX = SIGNALS_MODELS_COUNTS_INDEX_ARRAY;

/** The signals details index. */
static const int SIGNALS_DETAILS_INDEX_ARRAY[] = {4};
static const int* SIGNALS_DETAILS_INDEX = SIGNALS_DETAILS_INDEX_ARRAY;

/** The signals details counts index. */
static const int SIGNALS_DETAILS_COUNTS_INDEX_ARRAY[] = {5};
static const int* SIGNALS_DETAILS_COUNTS_INDEX = SIGNALS_DETAILS_COUNTS_INDEX_ARRAY;

/** The signals priorities index. */
static const int SIGNALS_PRIORITIES_INDEX_ARRAY[] = {6};
static const int* SIGNALS_PRIORITIES_INDEX = SIGNALS_PRIORITIES_INDEX_ARRAY;

/** The main signal ids index. */
static const int SIGNALS_MAIN_SIGNAL_ID_INDEX_ARRAY[] = {7};
static const int* SIGNALS_MAIN_SIGNAL_ID_INDEX = SIGNALS_MAIN_SIGNAL_ID_INDEX_ARRAY;

//
// Xml tag.
//

/** The xml tag count. */
static const int XML_TAG_COUNT_ARRAY[] = {2};
static const int* XML_TAG_COUNT = XML_TAG_COUNT_ARRAY;

/** The xml tag name, attribute, value index. */
static const int XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX_ARRAY[] = {0};
static const int* XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX = XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX_ARRAY;

/** The xml tag counts index. */
static const int XML_TAG_COUNTS_INDEX_ARRAY[] = {1};
static const int* XML_TAG_COUNTS_INDEX = XML_TAG_COUNTS_INDEX_ARRAY;

//
// Xml attribute.
//

/** The xml attribute count. */
static const int XML_ATTRIBUTE_COUNT_ARRAY[] = {2};
static const int* XML_ATTRIBUTE_COUNT = XML_ATTRIBUTE_COUNT_ARRAY;

/** The xml attribute name, value index. */
static const int XML_ATTRIBUTE_NAME_VALUE_INDEX_ARRAY[] = {0};
static const int* XML_ATTRIBUTE_NAME_VALUE_INDEX = XML_ATTRIBUTE_NAME_VALUE_INDEX_ARRAY;

/** The xml attribute counts index. */
static const int XML_ATTRIBUTE_COUNTS_INDEX_ARRAY[] = {1};
static const int* XML_ATTRIBUTE_COUNTS_INDEX = XML_ATTRIBUTE_COUNTS_INDEX_ARRAY;

/* STRUCTURE_CONSTANTS_SOURCE */
#endif
