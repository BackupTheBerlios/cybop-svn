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
 * @version $Revision: 1.1 $ $Date: 2004-08-13 07:22:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STRUCTURE_CONSTANTS_SOURCE
#define STRUCTURE_CONSTANTS_SOURCE

//
// Arrays.
//

/** The pointer array constant. */
static const int POINTER_ARRAY = 0;

/** The integer array constant. */
static const int INTEGER_ARRAY = 1;

/** The character array constant. */
static const int CHARACTER_ARRAY = 2;

/** The double array constant. */
static const int DOUBLE_ARRAY = 3;

//
// String.
//

/** The string resize factor. */
static const int STRING_RESIZE_FACTOR = 2;

//
// Fraction.
//

/** The fraction count. */
static const int FRACTION_COUNT = 2;

/** The numerator index. */
static const int NUMERATOR_INDEX = 0;

/** The denominator index. */
static const int DENOMINATOR_INDEX = 1;

//
// Vector.
//

/** The vector count. */
static const int VECTOR_COUNT = 3;

/** The x index. */
static const int X_INDEX = 0;

/** The y index. */
static const int Y_INDEX = 1;

/** The z index. */
static const int Z_INDEX = 2;

//
// Time.
//

/** The time count. */
static const int TIME_COUNT = 6;

/** The year index. */
static const int YEAR_INDEX = 0;

/** The month index. */
static const int MONTH_INDEX = 1;

/** The day index. */
static const int DAY_INDEX = 2;

/** The hour index. */
static const int HOUR_INDEX = 3;

/** The minute index. */
static const int MINUTE_INDEX = 4;

/** The second index. */
static const int SECOND_INDEX = 5;

//
// Complex.
//

/** The complex count. */
static const int COMPLEX_COUNT = 2;

/** The real index. */
static const int REAL_INDEX = 0;

/** The imaginary index. */
static const int IMAGINARY_INDEX = 1;

//
// Operation.
//

/** The operation resize factor. */
static const int OPERATION_RESIZE_FACTOR = 2;

/** The operation count. */
static const int OPERATION_COUNT = 3;

/** The parameters index. */
static const int PARAMETERS_INDEX = 0;

/** The parameters counts index. */
static const int PARAMETERS_COUNTS_INDEX = 1;

/** The parameters sizes index. */
static const int PARAMETERS_SIZES_INDEX = 2;

//
// Compound.
//

/** The compound resize factor. */
static const int COMPOUND_RESIZE_FACTOR = 2;

/** The compound count. */
static const int COMPOUND_COUNT = 21;

/** The part names index. */
static const int PART_NAMES_INDEX = 0;

/** The part names counts index. */
static const int PART_NAMES_COUNTS_INDEX = 1;

/** The part names sizes index. */
static const int PART_NAMES_SIZES_INDEX = 2;

/** The part models index. */
static const int PART_MODELS_INDEX = 3;

/** The part models counts index. */
static const int PART_MODELS_COUNTS_INDEX = 4;

/** The part models sizes index. */
static const int PART_MODELS_SIZES_INDEX = 5;

/** The part abstractions index. */
static const int PART_ABSTRACTIONS_INDEX = 6;

/** The part abstractions counts index. */
static const int PART_ABSTRACTIONS_COUNTS_INDEX = 7;

/** The part abstractions sizes index. */
static const int PART_ABSTRACTIONS_SIZES_INDEX = 8;

/** The part constraints index. */
static const int PART_CONSTRAINTS_INDEX = 9;

/** The part constraints counts index. */
static const int PART_CONSTRAINTS_COUNTS_INDEX = 10;

/** The part constraints sizes index. */
static const int PART_CONSTRAINTS_SIZES_INDEX = 11;

/** The position models index. */
static const int POSITION_MODELS_INDEX = 12;

/** The position models counts index. */
static const int POSITION_MODELS_COUNTS_INDEX = 13;

/** The position models sizes index. */
static const int POSITION_MODELS_SIZES_INDEX = 14;

/** The position abstractions index. */
static const int POSITION_ABSTRACTIONS_INDEX = 15;

/** The position abstractions counts index. */
static const int POSITION_ABSTRACTIONS_COUNTS_INDEX = 16;

/** The position abstractions sizes index. */
static const int POSITION_ABSTRACTIONS_SIZES_INDEX = 17;

/** The position constraints index. */
static const int POSITION_CONSTRAINTS_INDEX = 18;

/** The position constraints counts index. */
static const int POSITION_CONSTRAINTS_COUNTS_INDEX = 19;

/** The position constraints sizes index. */
static const int POSITION_CONSTRAINTS_SIZES_INDEX = 20;

//
// Signal memory.
//

/** The signal memory resize factor. */
static const int SIGNAL_MEMORY_RESIZE_FACTOR = 2;

/** The signal memory count. */
static const int SIGNAL_MEMORY_COUNT = 5;

/** The signals models index. */
static const int SIGNALS_MODELS_INDEX = 0;

/** The signals models counts index. */
static const int SIGNALS_MODELS_COUNTS_INDEX = 1;

/** The signals priorities index. */
static const int SIGNALS_PRIORITIES_INDEX = 2;

/** The signals abstractions index. */
static const int SIGNALS_ABSTRACTIONS_INDEX = 3;

/** The signals abstractions counts index. */
static const int SIGNALS_ABSTRACTIONS_COUNTS_INDEX = 4;

//
// Xml tag.
//

/** The xml tag count. */
static const int XML_TAG_COUNT = 2;

/** The xml tag name, attribute, value index. */
static const int XML_TAG_NAME_ATTRIBUTE_VALUE_INDEX = 0;

/** The xml tag counts index. */
static const int XML_TAG_COUNTS_INDEX = 1;

//
// Xml attribute.
//

/** The xml attribute count. */
static const int XML_ATTRIBUTE_COUNT = 2;

/** The xml attribute name, value index. */
static const int XML_ATTRIBUTE_NAME_VALUE_INDEX = 0;

/** The xml attribute counts index. */
static const int XML_ATTRIBUTE_COUNTS_INDEX = 1;

/* STRUCTURE_CONSTANTS_SOURCE */
#endif
