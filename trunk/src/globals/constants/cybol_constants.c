/*
 * $RCSfile: cybol_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2005-07-25 21:01:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CONSTANTS_SOURCE
#define CYBOL_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Cybol tag (node) attributes (properties).
//

/** The name attribute. */
static char NAME_ATTRIBUTE_ARRAY[] = {'n', 'a', 'm', 'e'};
static char* NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;
static int* NAME_ATTRIBUTE_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The channel attribute. */
static char CHANNEL_ATTRIBUTE_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static char* CHANNEL_ATTRIBUTE = CHANNEL_ATTRIBUTE_ARRAY;
static int* CHANNEL_ATTRIBUTE_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The abstraction attribute. */
static char ABSTRACTION_ATTRIBUTE_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* ABSTRACTION_ATTRIBUTE = ABSTRACTION_ATTRIBUTE_ARRAY;
static int* ABSTRACTION_ATTRIBUTE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The model attribute. */
static char MODEL_ATTRIBUTE_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static char* MODEL_ATTRIBUTE = MODEL_ATTRIBUTE_ARRAY;
static int* MODEL_ATTRIBUTE_COUNT = NUMBER_5_INTEGER_ARRAY;

/* CYBOL_CONSTANTS_SOURCE */
#endif
