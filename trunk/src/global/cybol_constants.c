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
 * @version $Revision: 1.3 $ $Date: 2004-12-16 16:34:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CONSTANTS_SOURCE
#define CYBOL_CONSTANTS_SOURCE

//
// Cybol tag (node) attributes (properties).
//

/** The name attribute array, pointer, count. */
static const char NAME_ATTRIBUTE_ARRAY[] = {'n', 'a', 'm', 'e'};
static const char* NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;
static const int NAME_ATTRIBUTE_COUNT_ARRAY[] = {4};
static const int* NAME_ATTRIBUTE_COUNT = NAME_ATTRIBUTE_COUNT_ARRAY;

/** The channel attribute array, pointer, count. */
static const char CHANNEL_ATTRIBUTE_ARRAY[] = {'c', 'h', 'a', 'n', 'n', 'e', 'l'};
static const char* CHANNEL_ATTRIBUTE = CHANNEL_ATTRIBUTE_ARRAY;
static const int CHANNEL_ATTRIBUTE_COUNT_ARRAY[] = {7};
static const int* CHANNEL_ATTRIBUTE_COUNT = CHANNEL_ATTRIBUTE_COUNT_ARRAY;

/** The abstraction attribute array, pointer, count. */
static const char ABSTRACTION_ATTRIBUTE_ARRAY[] = {'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* ABSTRACTION_ATTRIBUTE = ABSTRACTION_ATTRIBUTE_ARRAY;
static const int ABSTRACTION_ATTRIBUTE_COUNT_ARRAY[] = {11};
static const int* ABSTRACTION_ATTRIBUTE_COUNT = ABSTRACTION_ATTRIBUTE_COUNT_ARRAY;

/** The model attribute array, pointer, count. */
static const char MODEL_ATTRIBUTE_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};
static const char* MODEL_ATTRIBUTE = MODEL_ATTRIBUTE_ARRAY;
static const int MODEL_ATTRIBUTE_COUNT_ARRAY[] = {5};
static const int* MODEL_ATTRIBUTE_COUNT = MODEL_ATTRIBUTE_COUNT_ARRAY;

/* CYBOL_CONSTANTS_SOURCE */
#endif
