/*
 * $RCSfile: xml_character_entity_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-27 07:07:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_CHARACTER_ENTITY_CONSTANTS_SOURCE
#define XML_CHARACTER_ENTITY_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The quotation mark xml character entity. */
static char QUOTATION_MARK_XML_CHARACTER_ENTITY_ARRAY[] = {'q', 'u', 'o', 't'};
static char* QUOTATION_MARK_XML_CHARACTER_ENTITY = QUOTATION_MARK_XML_CHARACTER_ENTITY_ARRAY;
static int* QUOTATION_MARK_XML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The ampersand xml character entity. */
static char AMPERSAND_XML_CHARACTER_ENTITY_ARRAY[] = {'a', 'm', 'p'};
static char* AMPERSAND_XML_CHARACTER_ENTITY = AMPERSAND_XML_CHARACTER_ENTITY_ARRAY;
static int* AMPERSAND_XML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The apostrophe xml character entity. CAUTION! It is only used in XHTML. */
static char APOSTROPHE_XML_CHARACTER_ENTITY_ARRAY[] = {'a', 'p', 'o', 's'};
static char* APOSTROPHE_XML_CHARACTER_ENTITY = APOSTROPHE_XML_CHARACTER_ENTITY_ARRAY;
static int* APOSTROPHE_XML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The less than sign xml character entity. */
static char LESS_THAN_SIGN_XML_CHARACTER_ENTITY_ARRAY[] = {'l', 't'};
static char* LESS_THAN_SIGN_XML_CHARACTER_ENTITY = LESS_THAN_SIGN_XML_CHARACTER_ENTITY_ARRAY;
static int* LESS_THAN_SIGN_XML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The greater than sign xml character entity. */
static char GREATER_THAN_SIGN_XML_CHARACTER_ENTITY_ARRAY[] = {'g', 't'};
static char* GREATER_THAN_SIGN_XML_CHARACTER_ENTITY = GREATER_THAN_SIGN_XML_CHARACTER_ENTITY_ARRAY;
static int* GREATER_THAN_SIGN_XML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/* XML_CHARACTER_ENTITY_CONSTANTS_SOURCE */
#endif
