/*
 * $RCSfile: cyboi_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2007-04-16 16:23:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_CONSTANTS_SOURCE
#define CYBOI_CONSTANTS_SOURCE

#include "../../globals/constants/integer/integer_constants.c"

//
// Cybol file.
//

/** The file reallocate factor. */
static int* FILE_REALLOCATE_FACTOR = NUMBER_2_INTEGER_ARRAY;

//
// Signal priorities.
//

/** The normal priority. */
static int* NORMAL_PRIORITY = NUMBER_0_INTEGER_ARRAY;

//
// Xml parse modes.
//

/** The zero parse mode. */
static int* ZERO_PARSE_MODE = NUMBER_0_INTEGER_ARRAY;

/** The comment tag parse mode. */
static int* COMMENT_TAG_PARSE_MODE = NUMBER_1_INTEGER_ARRAY;

/** The begin tag parse mode. */
static int* BEGIN_TAG_PARSE_MODE = NUMBER_2_INTEGER_ARRAY;

/** The end tag parse mode. */
static int* END_TAG_PARSE_MODE = NUMBER_3_INTEGER_ARRAY;

/** The tag value parse mode. */
static int* TAG_VALUE_PARSE_MODE = NUMBER_4_INTEGER_ARRAY;

/** The attribute name parse mode. */
static int* ATTRIBUTE_NAME_PARSE_MODE = NUMBER_5_INTEGER_ARRAY;

/** The attribute value parse mode. */
static int* ATTRIBUTE_VALUE_PARSE_MODE = NUMBER_6_INTEGER_ARRAY;

/* CYBOI_CONSTANTS_SOURCE */
#endif
