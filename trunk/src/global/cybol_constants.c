/*
 * $RCSfile: cybol_constants.c,v $
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
 * This file defines global cybol constants.
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-13 07:22:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CONSTANTS_SOURCE
#define CYBOL_CONSTANTS_SOURCE

//
// Cybol attributes.
//

/** The name attribute array, pointer, count. */
static const char NAME_ATTRIBUTE_ARRAY[] = {'n', 'a', 'm', 'e'};
static const char* NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;
static const int NAME_ATTRIBUTE_COUNT = 4;

/** The abstraction attribute array, pointer, count. */
static const char ABSTRACTION_ATTRIBUTE_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* ABSTRACTION_ATTRIBUTE = ABSTRACTION_ATTRIBUTE_ARRAY;
static const int ABSTRACTION_ATTRIBUTE_COUNT = 11;

/** The location attribute array, pointer, count. */
static const char LOCATION_ATTRIBUTE_ARRAY[] = {'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};
static const char* LOCATION_ATTRIBUTE = LOCATION_ATTRIBUTE_ARRAY;
static const int LOCATION_ATTRIBUTE_COUNT = 8;

/** The model attribute array, pointer, count. */
static const char MODEL_ATTRIBUTE_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* MODEL_ATTRIBUTE = MODEL_ATTRIBUTE_ARRAY;
static const int MODEL_ATTRIBUTE_COUNT = 5;

/** The constraint attribute array, pointer, count. */
static const char CONSTRAINT_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't'};
static const char* CONSTRAINT_ATTRIBUTE = CONSTRAINT_ATTRIBUTE_ARRAY;
static const int CONSTRAINT_ATTRIBUTE_COUNT = 10;

/** The position location attribute array, pointer, count. */
static const char POSITION_LOCATION_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};
static const char* POSITION_LOCATION_ATTRIBUTE = POSITION_LOCATION_ATTRIBUTE_ARRAY;
static const int POSITION_LOCATION_ATTRIBUTE_COUNT = 17;

/** The position abstraction attribute array, pointer, count. */
static const char POSITION_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* POSITION_ABSTRACTION_ATTRIBUTE = POSITION_ABSTRACTION_ATTRIBUTE_ARRAY;
static const int POSITION_ABSTRACTION_ATTRIBUTE_COUNT = 20;

/** The position model attribute array, pointer, count. */
static const char POSITION_MODEL_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'm', 'o', 'd', 'e', 'l'};
static const char* POSITION_MODEL_ATTRIBUTE = POSITION_MODEL_ATTRIBUTE_ARRAY;
static const int POSITION_MODEL_ATTRIBUTE_COUNT = 14;

/** The position constraint attribute array, pointer, count. */
static const char POSITION_CONSTRAINT_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't'};
static const char* POSITION_CONSTRAINT_ATTRIBUTE = POSITION_CONSTRAINT_ATTRIBUTE_ARRAY;
static const int POSITION_CONSTRAINT_ATTRIBUTE_COUNT = 19;

/* CYBOL_CONSTANTS_SOURCE */
#endif
