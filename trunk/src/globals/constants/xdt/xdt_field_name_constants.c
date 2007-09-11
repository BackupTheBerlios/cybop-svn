/*
 * $RCSfile: xdt_field_name_constants.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2007-09-11 07:47:24 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_FIELD_NAME_CONSTANTS_SOURCE
#define XDT_FIELD_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The kbv test number field name. */
static char KBV_TEST_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'k', 'b', 'v', '_', 't', 'e', 's', 't', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* KBV_TEST_NUMBER_XDT_FIELD_NAME = KBV_TEST_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* KBV_TEST_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The responsible entity field name. */
static char RESPONSIBLE_ENTITY_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 's', 'p', 'o', 'n', 's', 'i', 'b', 'l', 'e', '_', 'e', 'n', 't', 'i', 't', 'y'};
static char* RESPONSIBLE_ENTITY_XDT_FIELD_NAME = RESPONSIBLE_ENTITY_XDT_FIELD_NAME_ARRAY;
static int* RESPONSIBLE_ENTITY_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The software field name. */
static char SOFTWARE_XDT_FIELD_NAME_ARRAY[] = {'s', 'o', 'f', 't', 'w', 'a', 'r', 'e'};
static char* SOFTWARE_XDT_FIELD_NAME = SOFTWARE_XDT_FIELD_NAME_ARRAY;
static int* SOFTWARE_XDT_FIELD_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The hardware field name. */
static char HARDWARE_XDT_FIELD_NAME_ARRAY[] = {'h', 'a', 'r', 'd', 'w', 'a', 'r', 'e'};
static char* HARDWARE_XDT_FIELD_NAME = HARDWARE_XDT_FIELD_NAME_ARRAY;
static int* HARDWARE_XDT_FIELD_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The software release field name. */
static char SOFTWARE_RELEASE_XDT_FIELD_NAME_ARRAY[] = {'s', 'o', 'f', 't', 'w', 'a', 'r', 'e', '_', 'r', 'e', 'l', 'e', 'a', 's', 'e'};
static char* SOFTWARE_RELEASE_XDT_FIELD_NAME = SOFTWARE_RELEASE_XDT_FIELD_NAME_ARRAY;
static int* SOFTWARE_RELEASE_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The physician identification field name. */
static char PHYSICIAN_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* PHYSICIAN_IDENTIFICATION_XDT_FIELD_NAME = PHYSICIAN_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The physician practice type field name. */
static char PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '_', 't', 'y', 'p', 'e'};
static char* PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_NAME = PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The physician name field name. */
static char PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'a', 'm', 'e'};
static char* PHYSICIAN_NAME_XDT_FIELD_NAME = PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_NAME_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The physician category field name. */
static char PHYSICIAN_CATEGORY_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y'};
static char* PHYSICIAN_CATEGORY_XDT_FIELD_NAME = PHYSICIAN_CATEGORY_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_CATEGORY_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The physician street field name. */
static char PHYSICIAN_STREET_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 's', 't', 'r', 'e', 'e', 't'};
static char* PHYSICIAN_STREET_XDT_FIELD_NAME = PHYSICIAN_STREET_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_STREET_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The physician postcode and place field name. */
static char PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'p', 'o', 's', 't', 'c', 'o', 'd', 'e', '_', 'a', 'n', 'd', '_', 'p', 'l', 'a', 'c', 'e'};
static char* PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_NAME = PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The physician with service indicator field name. */
static char PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'w', 'i', 't', 'h', '_', 's', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'i', 'n', 'd', 'i', 'c', 'a', 't', 'o', 'r'};
static char* PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_NAME = PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The physician phone field name. */
static char PHYSICIAN_PHONE_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'p', 'h', 'o', 'n', 'e'};
static char* PHYSICIAN_PHONE_XDT_FIELD_NAME = PHYSICIAN_PHONE_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_PHONE_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The physician fax field name. */
static char PHYSICIAN_FAX_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'f', 'a', 'x'};
static char* PHYSICIAN_FAX_XDT_FIELD_NAME = PHYSICIAN_FAX_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_FAX_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The physician modem field name. */
static char PHYSICIAN_MODEM_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'm', 'o', 'd', 'e', 'm'};
static char* PHYSICIAN_MODEM_XDT_FIELD_NAME = PHYSICIAN_MODEM_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_MODEM_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The physician number within practice field name. */
static char PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_NAME_ARRAY[] = {'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'u', 'm', 'b', 'e', 'r', '_', 'w', 'i', 't', 'h', 'i', 'n', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};
static char* PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_NAME = PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_NAME_ARRAY;
static int* PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 1 name field name. */
static char FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 1 value field name. */
static char FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 2 name field name. */
static char FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 2 value field name. */
static char FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 3 name field name. */
static char FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 3 value field name. */
static char FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 4 name field name. */
static char FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 4 value field name. */
static char FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 5 name field name. */
static char FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 5 value field name. */
static char FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 6 name field name. */
static char FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '6', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 6 value field name. */
static char FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '6', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 7 name field name. */
static char FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '7', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 7 value field name. */
static char FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '7', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 8 name field name. */
static char FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '8', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 8 value field name. */
static char FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '8', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 9 name field name. */
static char FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '9', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 0010 category 9 value field name. */
static char FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '9', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 10 name field name. */
static char FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '0', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 10 value field name. */
static char FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '0', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 11 name field name. */
static char FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 11 value field name. */
static char FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 12 name field name. */
static char FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 12 value field name. */
static char FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 13 name field name. */
static char FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 13 value field name. */
static char FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 14 name field name. */
static char FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 14 value field name. */
static char FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 15 name field name. */
static char FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 15 value field name. */
static char FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 16 name field name. */
static char FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '6', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 16 value field name. */
static char FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '6', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 17 name field name. */
static char FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '7', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 17 value field name. */
static char FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '7', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 18 name field name. */
static char FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '8', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 18 value field name. */
static char FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '8', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 19 name field name. */
static char FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '9', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 19 value field name. */
static char FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '9', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 20 name field name. */
static char FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '0', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 20 value field name. */
static char FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '0', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 21 name field name. */
static char FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 21 value field name. */
static char FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 22 name field name. */
static char FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 22 value field name. */
static char FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 23 name field name. */
static char FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 23 value field name. */
static char FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 24 name field name. */
static char FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 24 value field name. */
static char FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 0010 category 25 name field name. */
static char FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 0010 category 25 value field name. */
static char FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '0', '0', '1', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_NAME = FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The patient identification field name. */
static char PATIENT_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* PATIENT_IDENTIFICATION_XDT_FIELD_NAME = PATIENT_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The patient name affix field name. */
static char PATIENT_NAME_AFFIX_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'n', 'a', 'm', 'e', '_', 'a', 'f', 'f', 'i', 'x'};
static char* PATIENT_NAME_AFFIX_XDT_FIELD_NAME = PATIENT_NAME_AFFIX_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_NAME_AFFIX_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient last name field name. */
static char PATIENT_LAST_NAME_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'l', 'a', 's', 't', '_', 'n', 'a', 'm', 'e'};
static char* PATIENT_LAST_NAME_XDT_FIELD_NAME = PATIENT_LAST_NAME_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_LAST_NAME_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The patient first name field name. */
static char PATIENT_FIRST_NAME_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'f', 'i', 'r', 's', 't', '_', 'n', 'a', 'm', 'e'};
static char* PATIENT_FIRST_NAME_XDT_FIELD_NAME = PATIENT_FIRST_NAME_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_FIRST_NAME_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient birth date field name. */
static char PATIENT_BIRTH_DATE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'b', 'i', 'r', 't', 'h', '_', 'd', 'a', 't', 'e'};
static char* PATIENT_BIRTH_DATE_XDT_FIELD_NAME = PATIENT_BIRTH_DATE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_BIRTH_DATE_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient title field name. */
static char PATIENT_TITLE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 't', 'i', 't', 'l', 'e'};
static char* PATIENT_TITLE_XDT_FIELD_NAME = PATIENT_TITLE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_TITLE_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The patient health insurance number field name. */
static char PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'h', 'e', 'a', 'l', 't', 'h', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_NAME = PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The patient residence field name. */
static char PATIENT_RESIDENCE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'r', 'e', 's', 'i', 'd', 'e', 'n', 'c', 'e'};
static char* PATIENT_RESIDENCE_XDT_FIELD_NAME = PATIENT_RESIDENCE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_RESIDENCE_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The patient street field name. */
static char PATIENT_STREET_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 's', 't', 'r', 'e', 'e', 't'};
static char* PATIENT_STREET_XDT_FIELD_NAME = PATIENT_STREET_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_STREET_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The patient health insurance type field name. */
static char PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'h', 'e', 'a', 'l', 't', 'h', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 't', 'y', 'p', 'e'};
static char* PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME = PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME_COUNT = NUMBER_29_INTEGER_ARRAY;

/** The patient sex field name. */
static char PATIENT_SEX_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 's', 'e', 'x'};
static char* PATIENT_SEX_XDT_FIELD_NAME = PATIENT_SEX_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_SEX_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The patient employer field name. */
static char PATIENT_EMPLOYER_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'e', 'm', 'p', 'l', 'o', 'y', 'e', 'r'};
static char* PATIENT_EMPLOYER_XDT_FIELD_NAME = PATIENT_EMPLOYER_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_EMPLOYER_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The patient accident insurance name field name. */
static char PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'n', 'a', 'm', 'e'};
static char* PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_NAME = PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The insurant last name field name. */
static char INSURANT_LAST_NAME_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 's', 'u', 'r', 'a', 'n', 't', '_', 'l', 'a', 's', 't', '_', 'n', 'a', 'm', 'e'};
static char* INSURANT_LAST_NAME_XDT_FIELD_NAME = INSURANT_LAST_NAME_XDT_FIELD_NAME_ARRAY;
static int* INSURANT_LAST_NAME_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The insurant first name field name. */
static char INSURANT_FIRST_NAME_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 's', 'u', 'r', 'a', 'n', 't', '_', 'f', 'i', 'r', 's', 't', '_', 'n', 'a', 'm', 'e'};
static char* INSURANT_FIRST_NAME_XDT_FIELD_NAME = INSURANT_FIRST_NAME_XDT_FIELD_NAME_ARRAY;
static int* INSURANT_FIRST_NAME_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The insurant birth date field name. */
static char INSURANT_BIRTH_DATE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 's', 'u', 'r', 'a', 'n', 't', '_', 'b', 'i', 'r', 't', 'h', '_', 'd', 'a', 't', 'e'};
static char* INSURANT_BIRTH_DATE_XDT_FIELD_NAME = INSURANT_BIRTH_DATE_XDT_FIELD_NAME_ARRAY;
static int* INSURANT_BIRTH_DATE_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The insurant residence field name. */
static char INSURANT_RESIDENCE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 's', 'u', 'r', 'a', 'n', 't', '_', 'r', 'e', 's', 'i', 'd', 'e', 'n', 'c', 'e'};
static char* INSURANT_RESIDENCE_XDT_FIELD_NAME = INSURANT_RESIDENCE_XDT_FIELD_NAME_ARRAY;
static int* INSURANT_RESIDENCE_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The insurant street field name. */
static char INSURANT_STREET_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 's', 'u', 'r', 'a', 'n', 't', '_', 's', 't', 'r', 'e', 'e', 't'};
static char* INSURANT_STREET_XDT_FIELD_NAME = INSURANT_STREET_XDT_FIELD_NAME_ARRAY;
static int* INSURANT_STREET_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The injured phone field name. */
static char INJURED_PHONE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'j', 'u', 'r', 'e', 'd', '_', 'p', 'h', 'o', 'n', 'e'};
static char* INJURED_PHONE_XDT_FIELD_NAME = INJURED_PHONE_XDT_FIELD_NAME_ARRAY;
static int* INJURED_PHONE_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The insurant sex field name. */
static char INSURANT_SEX_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 's', 'u', 'r', 'a', 'n', 't', '_', 's', 'e', 'x'};
static char* INSURANT_SEX_XDT_FIELD_NAME = INSURANT_SEX_XDT_FIELD_NAME_ARRAY;
static int* INSURANT_SEX_XDT_FIELD_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The patient x-ray number field name. */
static char PATIENT_X_RAY_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'x', '-', 'r', 'a', 'y', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* PATIENT_X_RAY_NUMBER_XDT_FIELD_NAME = PATIENT_X_RAY_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_X_RAY_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The patient archive number field name. */
static char PATIENT_ARCHIVE_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'r', 'c', 'h', 'i', 'v', 'e', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* PATIENT_ARCHIVE_NUMBER_XDT_FIELD_NAME = PATIENT_ARCHIVE_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_ARCHIVE_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The patient employers' liability insurance association number field name. */
static char PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'e', 'm', 'p', 'l', 'o', 'y', 'e', 'r', 's', '_', 'l', 'i', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'a', 's', 's', 'o', 'c', 'i', 'a', 't', 'i', 'o', 'n', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_NAME = PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The patient since date field name. */
static char PATIENT_SINCE_DATE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 's', 'i', 'n', 'c', 'e', '_', 'd', 'a', 't', 'e'};
static char* PATIENT_SINCE_DATE_XDT_FIELD_NAME = PATIENT_SINCE_DATE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_SINCE_DATE_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient change of insurance inception date field name. */
static char PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'c', 'h', 'a', 'n', 'g', 'e', '_', 'o', 'f', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'i', 'n', 'c', 'e', 'p', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'e'};
static char* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_NAME = PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_NAME_COUNT = NUMBER_42_INTEGER_ARRAY;

/** The patient profession field name. */
static char PATIENT_PROFESSION_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'r', 'o', 'f', 'e', 's', 's', 'i', 'o', 'n'};
static char* PATIENT_PROFESSION_XDT_FIELD_NAME = PATIENT_PROFESSION_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PROFESSION_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient body height field name. */
static char PATIENT_BODY_HEIGHT_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'b', 'o', 'd', 'y', '_', 'h', 'e', 'i', 'g', 'h', 't'};
static char* PATIENT_BODY_HEIGHT_XDT_FIELD_NAME = PATIENT_BODY_HEIGHT_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_BODY_HEIGHT_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The patient body weight field name. */
static char PATIENT_BODY_WEIGHT_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'b', 'o', 'd', 'y', '_', 'w', 'e', 'i', 'g', 'h', 't'};
static char* PATIENT_BODY_WEIGHT_XDT_FIELD_NAME = PATIENT_BODY_WEIGHT_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_BODY_WEIGHT_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The patient employer (redundant) field name. */
static char PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'e', 'm', 'p', 'l', 'o', 'y', 'e', 'r', '_', 'r', 'e', 'd', 'u', 'n', 'd', 'a', 'n', 't'};
static char* PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_NAME = PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The patient phone field name. */
static char PATIENT_PHONE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'h', 'o', 'n', 'e'};
static char* PATIENT_PHONE_XDT_FIELD_NAME = PATIENT_PHONE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PHONE_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The patient nationality field name. */
static char PATIENT_NATIONALITY_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l', 'i', 't', 'y'};
static char* PATIENT_NATIONALITY_XDT_FIELD_NAME = PATIENT_NATIONALITY_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_NATIONALITY_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The patient mother tongue field name. */
static char PATIENT_MOTHER_TONGUE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'm', 'o', 't', 'h', 'e', 'r', '_', 't', 'o', 'n', 'g', 'u', 'e'};
static char* PATIENT_MOTHER_TONGUE_XDT_FIELD_NAME = PATIENT_MOTHER_TONGUE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_MOTHER_TONGUE_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The patient general practitioner identification field name. */
static char PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'g', 'e', 'n', 'e', 'r', 'a', 'l', '_', 'p', 'r', 'a', 'c', 't', 'i', 't', 'i', 'o', 'n', 'e', 'r', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_NAME = PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_43_INTEGER_ARRAY;

/** The patient residence to medical practice distance field name. */
static char PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'r', 'e', 's', 'i', 'd', 'e', 'n', 'c', 'e', '_', 't', 'o', '_', 'm', 'e', 'd', 'i', 'c', 'a', 'l', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '_', 'd', 'i', 's', 't', 'a', 'n', 'c', 'e'};
static char* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_NAME = PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_NAME_COUNT = NUMBER_46_INTEGER_ARRAY;

/** The patient physician identification in group practice field name. */
static char PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n', '_', 'i', 'n', '_', 'g', 'r', 'o', 'u', 'p', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};
static char* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_NAME = PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_NAME_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The patient prescription identification field name. */
static char PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'r', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_NAME = PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_35_INTEGER_ARRAY;

/** The patient permanent diagnoses begin date field name. */
static char PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', '_', 'd', 'i', 'a', 'g', 'n', 'o', 's', 'e', 's', '_', 'b', 'e', 'g', 'i', 'n', '_', 'd', 'a', 't', 'e'};
static char* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_NAME = PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_NAME_COUNT = NUMBER_38_INTEGER_ARRAY;

/** The patient permanent diagnoses field name. */
static char PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', '_', 'd', 'i', 'a', 'g', 'n', 'o', 's', 'e', 's'};
static char* PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_NAME = PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The patient permanent drugs begin date field name. */
static char PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', '_', 'd', 'r', 'u', 'g', 's', '_', 'b', 'e', 'g', 'i', 'n', '_', 'd', 'a', 't', 'e'};
static char* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_NAME = PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The patient permanent drugs field name. */
static char PATIENT_PERMANENT_DRUGS_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', '_', 'd', 'r', 'u', 'g', 's'};
static char* PATIENT_PERMANENT_DRUGS_XDT_FIELD_NAME = PATIENT_PERMANENT_DRUGS_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PERMANENT_DRUGS_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The patient risk factors field name. */
static char PATIENT_RISK_FACTORS_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'r', 'i', 's', 'k', '_', 'f', 'a', 'c', 't', 'o', 'r', 's'};
static char* PATIENT_RISK_FACTORS_XDT_FIELD_NAME = PATIENT_RISK_FACTORS_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_RISK_FACTORS_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The patient allergies field name. */
static char PATIENT_ALLERGIES_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'l', 'l', 'e', 'r', 'g', 'i', 'e', 's'};
static char* PATIENT_ALLERGIES_XDT_FIELD_NAME = PATIENT_ALLERGIES_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_ALLERGIES_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The patient accidents field name. */
static char PATIENT_ACCIDENTS_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', 's'};
static char* PATIENT_ACCIDENTS_XDT_FIELD_NAME = PATIENT_ACCIDENTS_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_ACCIDENTS_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The patient surgeries field name. */
static char PATIENT_SURGERIES_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 's', 'u', 'r', 'g', 'e', 'r', 'i', 'e', 's'};
static char* PATIENT_SURGERIES_XDT_FIELD_NAME = PATIENT_SURGERIES_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_SURGERIES_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The patient anamnesis field name. */
static char PATIENT_ANAMNESIS_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'n', 'a', 'm', 'n', 'e', 's', 'i', 's'};
static char* PATIENT_ANAMNESIS_XDT_FIELD_NAME = PATIENT_ANAMNESIS_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_ANAMNESIS_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The patient number of births field name. */
static char PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'n', 'u', 'm', 'b', 'e', 'r', '_', 'o', 'f', '_', 'b', 'i', 'r', 't', 'h', 's'};
static char* PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_NAME = PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The patient number of children field name. */
static char PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'n', 'u', 'm', 'b', 'e', 'r', '_', 'o', 'f', '_', 'c', 'h', 'i', 'l', 'd', 'r', 'e', 'n'};
static char* PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_NAME = PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The patient number of pregnancies field name. */
static char PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'n', 'u', 'm', 'b', 'e', 'r', '_', 'o', 'f', '_', 'p', 'r', 'e', 'g', 'n', 'a', 'n', 'c', 'i', 'e', 's'};
static char* PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_NAME = PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_NAME_COUNT = NUMBER_29_INTEGER_ARRAY;

/** The patient permanent therapy field name. */
static char PATIENT_PERMANENT_THERAPY_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'p', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', '_', 't', 'h', 'e', 'r', 'a', 'p', 'y'};
static char* PATIENT_PERMANENT_THERAPY_XDT_FIELD_NAME = PATIENT_PERMANENT_THERAPY_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_PERMANENT_THERAPY_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The patient recall appointment date field name. */
static char PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'r', 'e', 'c', 'a', 'l', 'l', '_', 'a', 'p', 'p', 'o', 'i', 'n', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'e'};
static char* PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_NAME = PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The free record 6100 category 1 name field name. */
static char FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 1 value field name. */
static char FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 2 name field name. */
static char FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 2 value field name. */
static char FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 3 name field name. */
static char FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 3 value field name. */
static char FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 4 name field name. */
static char FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 4 value field name. */
static char FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 5 name field name. */
static char FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 5 value field name. */
static char FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 6 name field name. */
static char FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '6', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 6 value field name. */
static char FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '6', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 7 name field name. */
static char FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '7', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 7 value field name. */
static char FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '7', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 8 name field name. */
static char FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '8', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 8 value field name. */
static char FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '8', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 9 name field name. */
static char FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '9', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6100 category 9 value field name. */
static char FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '9', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 10 name field name. */
static char FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '0', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6100 category 10 value field name. */
static char FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '1', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '0', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_NAME = FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The invoice quarter field name. */
static char INVOICE_QUARTER_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'q', 'u', 'a', 'r', 't', 'e', 'r'};
static char* INVOICE_QUARTER_XDT_FIELD_NAME = INVOICE_QUARTER_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_QUARTER_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The invoice issuance date field name. */
static char INVOICE_ISSUANCE_DATE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 's', 's', 'u', 'a', 'n', 'c', 'e', '_', 'd', 'a', 't', 'e'};
static char* INVOICE_ISSUANCE_DATE_XDT_FIELD_NAME = INVOICE_ISSUANCE_DATE_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_ISSUANCE_DATE_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The invoice validity date field name. */
static char INVOICE_VALIDITY_DATE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'v', 'a', 'l', 'i', 'd', 'i', 't', 'y', '_', 'd', 'a', 't', 'e'};
static char* INVOICE_VALIDITY_DATE_XDT_FIELD_NAME = INVOICE_VALIDITY_DATE_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_VALIDITY_DATE_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The invoice insurance number field name. */
static char INVOICE_INSURANCE_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* INVOICE_INSURANCE_NUMBER_XDT_FIELD_NAME = INVOICE_INSURANCE_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_INSURANCE_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The invoice insurance office field name. */
static char INVOICE_INSURANCE_OFFICE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'o', 'f', 'f', 'i', 'c', 'e'};
static char* INVOICE_INSURANCE_OFFICE_XDT_FIELD_NAME = INVOICE_INSURANCE_OFFICE_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_INSURANCE_OFFICE_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The invoice insurance sub category field name. */
static char INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 's', 'u', 'b', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y'};
static char* INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_NAME = INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The invoice billing category field name. */
static char INVOICE_BILLING_CATEGORY_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y'};
static char* INVOICE_BILLING_CATEGORY_XDT_FIELD_NAME = INVOICE_BILLING_CATEGORY_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_BILLING_CATEGORY_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The invoice insurance card last read access field name. */
static char INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'c', 'a', 'r', 'd', '_', 'l', 'a', 's', 't', '_', 'r', 'e', 'a', 'd', '_', 'a', 'c', 'c', 'e', 's', 's'};
static char* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_NAME = INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_NAME_COUNT = NUMBER_39_INTEGER_ARRAY;

/** The invoice insurance card validity date field name. */
static char INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'c', 'a', 'r', 'd', '_', 'v', 'a', 'l', 'i', 'd', 'i', 't', 'y', '_', 'd', 'a', 't', 'e'};
static char* INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_NAME = INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_NAME_COUNT = NUMBER_36_INTEGER_ARRAY;

/** The invoice ik insurance number field name. */
static char INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'i', 'k', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_NAME = INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The invoice vk insurance status field name. */
static char INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'v', 'k', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 's', 't', 'a', 't', 'u', 's'};
static char* INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_NAME = INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The invoice vk east-west status field name. */
static char INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'v', 'k', '_', 'e', 'a', 's', 't', '-', 'w', 'e', 's', 't', '_', 's', 't', 'a', 't', 'u', 's'};
static char* INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_NAME = INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The invoice billing scale field name. */
static char INVOICE_BILLING_SCALE_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 's', 'c', 'a', 'l', 'e'};
static char* INVOICE_BILLING_SCALE_XDT_FIELD_NAME = INVOICE_BILLING_SCALE_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_BILLING_SCALE_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The invoice billing area field name. */
static char INVOICE_BILLING_AREA_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'a', 'r', 'e', 'a'};
static char* INVOICE_BILLING_AREA_XDT_FIELD_NAME = INVOICE_BILLING_AREA_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_BILLING_AREA_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The referral cause of pain field name. */
static char REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'a', 'u', 's', 'e', '_', 'o', 'f', '_', 'p', 'a', 'i', 'n'};
static char* REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_NAME = REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The referral supposed accouchement date field name. */
static char REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 's', 'u', 'p', 'p', 'o', 's', 'e', 'd', '_', 'a', 'c', 'c', 'o', 'u', 'c', 'h', 'e', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'e'};
static char* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_NAME = REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_NAME_COUNT = NUMBER_35_INTEGER_ARRAY;

/** The referral diagnosis field name. */
static char REFERRAL_DIAGNOSIS_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'd', 'i', 'a', 'g', 'n', 'o', 's', 'i', 's'};
static char* REFERRAL_DIAGNOSIS_XDT_FIELD_NAME = REFERRAL_DIAGNOSIS_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_DIAGNOSIS_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The referral explanation field name. */
static char REFERRAL_EXPLANATION_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'e', 'x', 'p', 'l', 'a', 'n', 'a', 't', 'i', 'o', 'n'};
static char* REFERRAL_EXPLANATION_XDT_FIELD_NAME = REFERRAL_EXPLANATION_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_EXPLANATION_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The referral check box muvo lsr field name. */
static char REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'h', 'e', 'c', 'k', '_', 'b', 'o', 'x', '_', 'm', 'u', 'v', 'o', '_', 'l', 's', 'r'};
static char* REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_NAME = REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The referral check box muvo hah field name. */
static char REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'h', 'e', 'c', 'k', '_', 'b', 'o', 'x', '_', 'm', 'u', 'v', 'o', '_', 'h', 'a', 'h'};
static char* REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_NAME = REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The referral check box ab0 rh field name. */
static char REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'h', 'e', 'c', 'k', '_', 'b', 'o', 'x', '_', 'a', 'b', '0', '_', 'r', 'h'};
static char* REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_NAME = REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The referral check box ak field name. */
static char REFERRAL_CHECK_BOX_AK_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'h', 'e', 'c', 'k', '_', 'b', 'o', 'x', '_', 'a', 'k'};
static char* REFERRAL_CHECK_BOX_AK_XDT_FIELD_NAME = REFERRAL_CHECK_BOX_AK_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_AK_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The referral from physician number field name. */
static char REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'f', 'r', 'o', 'm', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_NAME = REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The referral to physician name field name. */
static char REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 't', 'o', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'a', 'm', 'e'};
static char* REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_NAME = REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY;
static int* REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The inpatient treatment referral by law field name. */
static char INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'b', 'y', '_', 'l', 'a', 'w'};
static char* INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_NAME = INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_NAME_ARRAY;
static int* INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_NAME_COUNT = NUMBER_35_INTEGER_ARRAY;

/** The inpatient treatment from to field name. */
static char INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'f', 'r', 'o', 'm', '_', 't', 'o'};
static char* INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_NAME = INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_NAME_ARRAY;
static int* INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The inpatient treatment class field name. */
static char INPATIENT_TREATMENT_CLASS_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'c', 'l', 'a', 's', 's'};
static char* INPATIENT_TREATMENT_CLASS_XDT_FIELD_NAME = INPATIENT_TREATMENT_CLASS_XDT_FIELD_NAME_ARRAY;
static int* INPATIENT_TREATMENT_CLASS_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The inpatient hospital name field name. */
static char INPATIENT_HOSPITAL_NAME_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'h', 'o', 's', 'p', 'i', 't', 'a', 'l', '_', 'n', 'a', 'm', 'e'};
static char* INPATIENT_HOSPITAL_NAME_XDT_FIELD_NAME = INPATIENT_HOSPITAL_NAME_XDT_FIELD_NAME_ARRAY;
static int* INPATIENT_HOSPITAL_NAME_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The inpatient hospital stay field name. */
static char INPATIENT_HOSPITAL_STAY_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'h', 'o', 's', 'p', 'i', 't', 'a', 'l', '_', 's', 't', 'a', 'y'};
static char* INPATIENT_HOSPITAL_STAY_XDT_FIELD_NAME = INPATIENT_HOSPITAL_STAY_XDT_FIELD_NAME_ARRAY;
static int* INPATIENT_HOSPITAL_STAY_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The invoice sub category field name. */
static char INVOICE_SUB_CATEGORY_XDT_FIELD_NAME_ARRAY[] = {'i', 'n', 'v', 'o', 'i', 'c', 'e', '_', 's', 'u', 'b', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y'};
static char* INVOICE_SUB_CATEGORY_XDT_FIELD_NAME = INVOICE_SUB_CATEGORY_XDT_FIELD_NAME_ARRAY;
static int* INVOICE_SUB_CATEGORY_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The emergency subsequent treatment physician name field name. */
static char EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY[] = {'e', 'm', 'e', 'r', 'g', 'e', 'n', 'c', 'y', '_', 's', 'u', 'b', 's', 'e', 'q', 'u', 'e', 'n', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'a', 'm', 'e'};
static char* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_NAME = EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY;
static int* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_NAME_COUNT = NUMBER_45_INTEGER_ARRAY;

/** The emergency findings field name. */
static char EMERGENCY_FINDINGS_XDT_FIELD_NAME_ARRAY[] = {'e', 'm', 'e', 'r', 'g', 'e', 'n', 'c', 'y', '_', 'f', 'i', 'n', 'd', 'i', 'n', 'g', 's'};
static char* EMERGENCY_FINDINGS_XDT_FIELD_NAME = EMERGENCY_FINDINGS_XDT_FIELD_NAME_ARRAY;
static int* EMERGENCY_FINDINGS_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The emergency symptoms field name. */
static char EMERGENCY_SYMPTOMS_XDT_FIELD_NAME_ARRAY[] = {'e', 'm', 'e', 'r', 'g', 'e', 'n', 'c', 'y', '_', 's', 'y', 'm', 'p', 't', 'o', 'm', 's'};
static char* EMERGENCY_SYMPTOMS_XDT_FIELD_NAME = EMERGENCY_SYMPTOMS_XDT_FIELD_NAME_ARRAY;
static int* EMERGENCY_SYMPTOMS_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The accident date field name. */
static char ACCIDENT_DATE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'd', 'a', 't', 'e'};
static char* ACCIDENT_DATE_XDT_FIELD_NAME = ACCIDENT_DATE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_DATE_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The accident time field name. */
static char ACCIDENT_TIME_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 't', 'i', 'm', 'e'};
static char* ACCIDENT_TIME_XDT_FIELD_NAME = ACCIDENT_TIME_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_TIME_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The accident patient admission in practice date field name. */
static char ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'd', 'm', 'i', 's', 's', 'i', 'o', 'n', '_', 'i', 'n', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '_', 'd', 'a', 't', 'e'};
static char* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_NAME = ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_NAME_COUNT = NUMBER_43_INTEGER_ARRAY;

/** The accident patient admission in practice time field name. */
static char ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'a', 'd', 'm', 'i', 's', 's', 'i', 'o', 'n', '_', 'i', 'n', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '_', 't', 'i', 'm', 'e'};
static char* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_NAME = ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_NAME_COUNT = NUMBER_43_INTEGER_ARRAY;

/** The accident patient labour time begin field name. */
static char ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'l', 'a', 'b', 'o', 'u', 'r', '_', 't', 'i', 'm', 'e', '_', 'b', 'e', 'g', 'i', 'n'};
static char* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_NAME = ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The accident location field name. */
static char ACCIDENT_LOCATION_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};
static char* ACCIDENT_LOCATION_XDT_FIELD_NAME = ACCIDENT_LOCATION_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_LOCATION_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The accident patient employment as field name. */
static char ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'e', 'm', 'p', 'l', 'o', 'y', 'm', 'e', 'n', 't', '_', 'a', 's'};
static char* ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_NAME = ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The accident patient employment since field name. */
static char ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'e', 'm', 'p', 'l', 'o', 'y', 'm', 'e', 'n', 't', '_', 's', 'i', 'n', 'c', 'e'};
static char* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_NAME = ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The accident patient nationality field name. */
static char ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'n', 'a', 't', 'i', 'o', 'n', 'a', 'l', 'i', 't', 'y'};
static char* ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_NAME = ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The accident company field name. */
static char ACCIDENT_COMPANY_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'c', 'o', 'm', 'p', 'a', 'n', 'y'};
static char* ACCIDENT_COMPANY_XDT_FIELD_NAME = ACCIDENT_COMPANY_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_COMPANY_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The accident course of events field name. */
static char ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'c', 'o', 'u', 'r', 's', 'e', '_', 'o', 'f', '_', 'e', 'v', 'e', 'n', 't', 's'};
static char* ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_NAME = ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The accident patient behaviour afterwards field name. */
static char ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'b', 'e', 'h', 'a', 'v', 'i', 'o', 'u', 'r', '_', 'a', 'f', 't', 'e', 'r', 'w', 'a', 'r', 'd', 's'};
static char* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_NAME = ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_NAME_COUNT = NUMBER_37_INTEGER_ARRAY;

/** The accident first time treatment date field name. */
static char ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'f', 'i', 'r', 's', 't', '_', 't', 'i', 'm', 'e', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'e'};
static char* ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_NAME = ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The accident treatment by physician name field name. */
static char ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'b', 'y', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'a', 'm', 'e'};
static char* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_NAME = ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_NAME_COUNT = NUMBER_36_INTEGER_ARRAY;

/** The accident kind of treatment field name. */
static char ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'k', 'i', 'n', 'd', '_', 'o', 'f', '_', 'f', 'i', 'r', 's', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't'};
static char* ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_NAME = ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The accident alcohol influence field name. */
static char ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 'l', 'c', 'o', 'h', 'o', 'l', '_', 'i', 'n', 'f', 'l', 'u', 'e', 'n', 'c', 'e'};
static char* ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_NAME = ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The accident signs for alcohol influence field name. */
static char ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 's', 'i', 'g', 'n', 's', '_', 'f', 'o', 'r', '_', 'a', 'l', 'c', 'o', 'h', 'o', 'l', '_', 'i', 'n', 'f', 'l', 'u', 'e', 'n', 'c', 'e'};
static char* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_NAME = ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_NAME_COUNT = NUMBER_36_INTEGER_ARRAY;

/** The accident blood withdrawal field name. */
static char ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'b', 'l', 'o', 'o', 'd', '_', 'w', 'i', 't', 'h', 'd', 'r', 'a', 'w', 'a', 'l'};
static char* ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_NAME = ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The accident findings field name. */
static char ACCIDENT_FINDINGS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'f', 'i', 'n', 'd', 'i', 'n', 'g', 's'};
static char* ACCIDENT_FINDINGS_XDT_FIELD_NAME = ACCIDENT_FINDINGS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_FINDINGS_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The accident x-ray result field name. */
static char ACCIDENT_X_RAY_RESULT_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'x', '-', 'r', 'a', 'y', '_', 'r', 'e', 's', 'u', 'l', 't'};
static char* ACCIDENT_X_RAY_RESULT_XDT_FIELD_NAME = ACCIDENT_X_RAY_RESULT_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_X_RAY_RESULT_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The accident kind of first treatment field name. */
static char ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'k', 'i', 'n', 'd', '_', 'o', 'f', '_', 'f', 'i', 'r', 's', 't', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't'};
static char* ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_NAME = ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The accident abnormal changes independent from accident field name. */
static char ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 'b', 'n', 'o', 'r', 'm', 'a', 'l', '_', 'c', 'h', 'a', 'n', 'g', 'e', 's', '_', 'i', 'n', 'd', 'e', 'p', 'e', 'n', 'd', 'e', 'n', 't', '_', 'f', 'r', 'o', 'm', '_', 'a', 'c', 'c', 'i', 'd', 'e', 'n', 't'};
static char* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_NAME = ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_NAME_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The accident concerns against statements field name. */
static char ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'c', 'o', 'n', 'c', 'e', 'r', 'n', 's', '_', 'a', 'g', 'a', 'i', 'n', 's', 't', '_', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't', 's'};
static char* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME = ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME_COUNT = NUMBER_36_INTEGER_ARRAY;

/** The accident kind of concerns against statements field name. */
static char ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'k', 'i', 'n', 'd', '_', 'o', 'f', '_', 'c', 'o', 'n', 'c', 'e', 'r', 'n', 's', '_', 'a', 'g', 'a', 'i', 'n', 's', 't', '_', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't', 's'};
static char* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME = ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_NAME_COUNT = NUMBER_44_INTEGER_ARRAY;

/** The accident concerns against classification as accident at work field name. */
static char ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'c', 'o', 'n', 'c', 'e', 'r', 'n', 's', '_', 'a', 'g', 'a', 'i', 'n', 's', 't', '_', 'c', 'l', 'a', 's', 's', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n', '_', 'a', 's', '_', 'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 't', '_', 'w', 'o', 'r', 'k'};
static char* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME = ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The accident kind of concerns against classification as accident at work field name. */
static char ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'k', 'i', 'n', 'd', '_', 'o', 'f', '_', 'c', 'o', 'n', 'c', 'e', 'r', 'n', 's', '_', 'a', 'g', 'a', 'i', 'n', 's', 't', '_', 'c', 'l', 'a', 's', 's', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n', '_', 'a', 's', '_', 'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 't', '_', 'w', 'o', 'r', 'k'};
static char* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME = ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_NAME_COUNT = NUMBER_68_INTEGER_ARRAY;

/** The accident able to work field name. */
static char ACCIDENT_ABLE_TO_WORK_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 'b', 'l', 'e', '_', 't', 'o', '_', 'w', 'o', 'r', 'k'};
static char* ACCIDENT_ABLE_TO_WORK_XDT_FIELD_NAME = ACCIDENT_ABLE_TO_WORK_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_ABLE_TO_WORK_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The accident able to work from field name. */
static char ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 'b', 'l', 'e', '_', 't', 'o', '_', 'w', 'o', 'r', 'k', '_', 'f', 'r', 'o', 'm'};
static char* ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_NAME = ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The accident unable to work certificate issuance date field name. */
static char ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_DATE_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'u', 'n', 'a', 'b', 'l', 'e', '_', 't', 'o', '_', 'w', 'o', 'r', 'k', '_', 'c', 'e', 'r', 't', 'i', 'f', 'i', 'c', 'a', 't', 'e', '_', 'i', 's', 's', 'u', 'a', 'n', 'c', 'e', '_', 'd', 'a', 't', 'e'};
static char* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_DATE_XDT_FIELD_NAME = ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_DATE_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_DATE_XDT_FIELD_NAME_COUNT = NUMBER_49_INTEGER_ARRAY;

/** The accident special curative treatment necessary field name. */
static char ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', '_', 'c', 'u', 'r', 'a', 't', 'i', 'v', 'e', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'n', 'e', 'c', 'e', 's', 's', 'a', 'r', 'y'};
static char* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_NAME = ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_NAME_COUNT = NUMBER_45_INTEGER_ARRAY;

/** The accident special curative treatment by field name. */
static char ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', '_', 'c', 'u', 'r', 'a', 't', 'i', 'v', 'e', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'b', 'y'};
static char* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME = ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME_COUNT = NUMBER_38_INTEGER_ARRAY;

/** The accident address of treating physician field name. */
static char ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'a', 'd', 'd', 'r', 'e', 's', 's', '_', 'o', 'f', '_', 't', 'r', 'e', 'a', 't', 'i', 'n', 'g', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n'};
static char* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_NAME = ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_NAME_COUNT = NUMBER_38_INTEGER_ARRAY;

/** The accident unable to work from field name. */
static char ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'u', 'n', 'a', 'b', 'l', 'e', '_', 't', 'o', '_', 'w', 'o', 'r', 'k', '_', 'f', 'r', 'o', 'm'};
static char* ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_NAME = ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The accident expected duration of inability to work field name. */
static char ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', '_', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', '_', 'o', 'f', '_', 'i', 'n', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 't', 'o', '_', 'w', 'o', 'r', 'k'};
static char* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_NAME = ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_NAME_COUNT = NUMBER_47_INTEGER_ARRAY;

/** The accident kind of bill field name. */
static char ACCIDENT_KIND_OF_BILL_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'k', 'i', 'n', 'd', '_', 'o', 'f', '_', 'b', 'i', 'l', 'l'};
static char* ACCIDENT_KIND_OF_BILL_XDT_FIELD_NAME = ACCIDENT_KIND_OF_BILL_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_BILL_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The accident general curative treatment by field name. */
static char ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'g', 'e', 'n', 'e', 'r', 'a', 'l', '_', 'c', 'u', 'r', 'a', 't', 'i', 'v', 'e', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'b', 'y'};
static char* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME = ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_NAME_COUNT = NUMBER_38_INTEGER_ARRAY;

/** The accident unable to work for longer than three days field name. */
static char ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'u', 'n', 'a', 'b', 'l', 'e', '_', 't', 'o', '_', 'w', 'o', 'r', 'k', '_', 'f', 'o', 'r', '_', 'l', 'o', 'n', 'g', 'e', 'r', '_', 't', 'h', 'a', 'n', '_', 't', 'h', 'r', 'e', 'e', '_', 'd', 'a', 'y', 's'};
static char* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_NAME = ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_NAME_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The accident unability to work certified until field name. */
static char ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'u', 'n', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 't', 'o', '_', 'w', 'o', 'r', 'k', '_', 'c', 'e', 'r', 't', 'i', 'f', 'i', 'e', 'd', '_', 'u', 'n', 't', 'i', 'l'};
static char* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_NAME = ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_NAME_COUNT = NUMBER_42_INTEGER_ARRAY;

/** The accident inspection required on field name. */
static char ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_NAME_ARRAY[] = {'a', 'c', 'c', 'i', 'd', 'e', 'n', 't', '_', 'i', 'n', 's', 'p', 'e', 'c', 't', 'i', 'o', 'n', '_', 'r', 'e', 'q', 'u', 'i', 'r', 'e', 'd', '_', 'o', 'n'};
static char* ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_NAME = ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_NAME_ARRAY;
static int* ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The billing number field name. */
static char BILLING_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* BILLING_NUMBER_XDT_FIELD_NAME = BILLING_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* BILLING_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The billing address field name. */
static char BILLING_ADDRESS_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'a', 'd', 'd', 'r', 'e', 's', 's'};
static char* BILLING_ADDRESS_XDT_FIELD_NAME = BILLING_ADDRESS_XDT_FIELD_NAME_ARRAY;
static int* BILLING_ADDRESS_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The billing referring physician name field name. */
static char BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'r', 'e', 'f', 'e', 'r', 'r', 'i', 'n', 'g', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'a', 'm', 'e'};
static char* BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_NAME = BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_NAME_ARRAY;
static int* BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The billing date field name. */
static char BILLING_DATE_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'd', 'a', 't', 'e'};
static char* BILLING_DATE_XDT_FIELD_NAME = BILLING_DATE_XDT_FIELD_NAME_ARRAY;
static int* BILLING_DATE_XDT_FIELD_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The billing total sum field name. */
static char BILLING_TOTAL_SUM_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 't', 'o', 't', 'a', 'l', '_', 's', 'u', 'm'};
static char* BILLING_TOTAL_SUM_XDT_FIELD_NAME = BILLING_TOTAL_SUM_XDT_FIELD_NAME_ARRAY;
static int* BILLING_TOTAL_SUM_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The billing assignment declaration field name. */
static char BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'a', 's', 's', 'i', 'g', 'n', 'm', 'e', 'n', 't', '_', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 't', 'i', 'o', 'n'};
static char* BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_NAME = BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_NAME_ARRAY;
static int* BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The billing physician sub account field name. */
static char BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 's', 'u', 'b', '_', 'a', 'c', 'c', 'o', 'u', 'n', 't'};
static char* BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_NAME = BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_NAME_ARRAY;
static int* BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_NAME_COUNT = NUMBER_29_INTEGER_ARRAY;

/** The billing attachment field name. */
static char BILLING_ATTACHMENT_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'a', 't', 't', 'a', 'c', 'h', 'm', 'e', 'n', 't'};
static char* BILLING_ATTACHMENT_XDT_FIELD_NAME = BILLING_ATTACHMENT_XDT_FIELD_NAME_ARRAY;
static int* BILLING_ATTACHMENT_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The billing header field name. */
static char BILLING_HEADER_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'h', 'e', 'a', 'd', 'e', 'r'};
static char* BILLING_HEADER_XDT_FIELD_NAME = BILLING_HEADER_XDT_FIELD_NAME_ARRAY;
static int* BILLING_HEADER_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The billing footer field name. */
static char BILLING_FOOTER_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'f', 'o', 'o', 't', 'e', 'r'};
static char* BILLING_FOOTER_XDT_FIELD_NAME = BILLING_FOOTER_XDT_FIELD_NAME_ARRAY;
static int* BILLING_FOOTER_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The service treatment date field name. */
static char SERVICE_TREATMENT_DATE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'e'};
static char* SERVICE_TREATMENT_DATE_XDT_FIELD_NAME = SERVICE_TREATMENT_DATE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_TREATMENT_DATE_XDT_FIELD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The service gnr identification field name. */
static char SERVICE_GNR_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'g', 'n', 'r', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* SERVICE_GNR_IDENTIFICATION_XDT_FIELD_NAME = SERVICE_GNR_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_GNR_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The service kind of examination field name. */
static char SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'k', 'i', 'n', 'd', '_', 'o', 'f', '_', 'e', 'x', 'a', 'm', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
static char* SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_NAME = SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The service addressee field name. */
static char SERVICE_ADDRESSEE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'a', 'd', 'd', 'r', 'e', 's', 's', 'e', 'e'};
static char* SERVICE_ADDRESSEE_XDT_FIELD_NAME = SERVICE_ADDRESSEE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_ADDRESSEE_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The service distance in kilometres field name. */
static char SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'd', 'i', 's', 't', 'a', 'n', 'c', 'e', '_', 'i', 'n', '_', 'k', 'i', 'l', 'o', 'm', 'e', 't', 'r', 'e', 's'};
static char* SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_NAME = SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The service multiplier field name. */
static char SERVICE_MULTIPLIER_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'i', 'e', 'r'};
static char* SERVICE_MULTIPLIER_XDT_FIELD_NAME = SERVICE_MULTIPLIER_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_MULTIPLIER_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The service time field name. */
static char SERVICE_TIME_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 't', 'i', 'm', 'e'};
static char* SERVICE_TIME_XDT_FIELD_NAME = SERVICE_TIME_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_TIME_XDT_FIELD_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The service order-execution time field name. */
static char SERVICE_ORDER_EXECUTION_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'o', 'r', 'd', 'e', 'r', '-', 'e', 'x', 'e', 'c', 'u', 't', 'i', 'o', 'n', '_', 't', 'i', 'm', 'e'};
static char* SERVICE_ORDER_EXECUTION_XDT_FIELD_NAME = SERVICE_ORDER_EXECUTION_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_ORDER_EXECUTION_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The service dkm field name. */
static char SERVICE_DKM_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'd', 'k', 'm'};
static char* SERVICE_DKM_XDT_FIELD_NAME = SERVICE_DKM_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_DKM_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The service free explanatory statement field name. */
static char SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'f', 'r', 'e', 'e', '_', 'e', 'x', 'p', 'l', 'a', 'n', 'a', 't', 'o', 'r', 'y', '_', 's', 't', 'a', 't', 'e', 'm', 'e', 'n', 't'};
static char* SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_NAME = SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The service explanatory drug field name. */
static char SERVICE_EXPLANATORY_DRUG_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'e', 'x', 'p', 'l', 'a', 'n', 'a', 't', 'o', 'r', 'y', '_', 'd', 'r', 'u', 'g'};
static char* SERVICE_EXPLANATORY_DRUG_XDT_FIELD_NAME = SERVICE_EXPLANATORY_DRUG_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_EXPLANATORY_DRUG_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The service material costs description field name. */
static char SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'm', 'a', 't', 'e', 'r', 'i', 'a', 'l', '_', 'c', 'o', 's', 't', 's', '_', 'd', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n'};
static char* SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_NAME = SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The service material costs dpf field name. */
static char SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'm', 'a', 't', 'e', 'r', 'i', 'a', 'l', '_', 'c', 'o', 's', 't', 's', '_', 'd', 'p', 'f'};
static char* SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_NAME = SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The service percent of treatment field name. */
static char SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'p', 'e', 'r', 'c', 'e', 'n', 't', '_', 'o', 'f', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't'};
static char* SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_NAME = SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The service organ field name. */
static char SERVICE_ORGAN_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'o', 'r', 'g', 'a', 'n'};
static char* SERVICE_ORGAN_XDT_FIELD_NAME = SERVICE_ORGAN_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_ORGAN_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The service location field name. */
static char SERVICE_LOCATION_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};
static char* SERVICE_LOCATION_XDT_FIELD_NAME = SERVICE_LOCATION_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_LOCATION_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The service zone field name. */
static char SERVICE_ZONE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'z', 'o', 'n', 'e'};
static char* SERVICE_ZONE_XDT_FIELD_NAME = SERVICE_ZONE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_ZONE_XDT_FIELD_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The service gnr description field name. */
static char SERVICE_GNR_DESCRIPTION_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'g', 'n', 'r', '_', 'd', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n'};
static char* SERVICE_GNR_DESCRIPTION_XDT_FIELD_NAME = SERVICE_GNR_DESCRIPTION_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_GNR_DESCRIPTION_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The service fee field name. */
static char SERVICE_FEE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'f', 'e', 'e'};
static char* SERVICE_FEE_XDT_FIELD_NAME = SERVICE_FEE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_FEE_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The service factor field name. */
static char SERVICE_FACTOR_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'f', 'a', 'c', 't', 'o', 'r'};
static char* SERVICE_FACTOR_XDT_FIELD_NAME = SERVICE_FACTOR_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_FACTOR_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The service sum field name. */
static char SERVICE_SUM_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 's', 'u', 'm'};
static char* SERVICE_SUM_XDT_FIELD_NAME = SERVICE_SUM_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_SUM_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The service total sum field name. */
static char SERVICE_TOTAL_SUM_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 't', 'o', 't', 'a', 'l', '_', 's', 'u', 'm'};
static char* SERVICE_TOTAL_SUM_XDT_FIELD_NAME = SERVICE_TOTAL_SUM_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_TOTAL_SUM_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The service point value field name. */
static char SERVICE_POINT_VALUE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'p', 'o', 'i', 'n', 't', '_', 'v', 'a', 'l', 'u', 'e'};
static char* SERVICE_POINT_VALUE_XDT_FIELD_NAME = SERVICE_POINT_VALUE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_POINT_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The service name of fee field name. */
static char SERVICE_NAME_OF_FEE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'n', 'a', 'm', 'e', '_', 'o', 'f', '_', 'f', 'e', 'e'};
static char* SERVICE_NAME_OF_FEE_XDT_FIELD_NAME = SERVICE_NAME_OF_FEE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_NAME_OF_FEE_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The service name of certificate field name. */
static char SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'r', 'v', 'i', 'c', 'e', '_', 'n', 'a', 'm', 'e', '_', 'o', 'f', '_', 'c', 'e', 'r', 't', 'i', 'f', 'i', 'c', 'a', 't', 'e'};
static char* SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_NAME = SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_NAME_ARRAY;
static int* SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The billing diagnosis field name. */
static char BILLING_DIAGNOSIS_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'd', 'i', 'a', 'g', 'n', 'o', 's', 'i', 's'};
static char* BILLING_DIAGNOSIS_XDT_FIELD_NAME = BILLING_DIAGNOSIS_XDT_FIELD_NAME_ARRAY;
static int* BILLING_DIAGNOSIS_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The billing icd key field name. */
static char BILLING_ICD_KEY_XDT_FIELD_NAME_ARRAY[] = {'b', 'i', 'l', 'l', 'i', 'n', 'g', '_', 'i', 'c', 'd', '_', 'k', 'e', 'y'};
static char* BILLING_ICD_KEY_XDT_FIELD_NAME = BILLING_ICD_KEY_XDT_FIELD_NAME_ARRAY;
static int* BILLING_ICD_KEY_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The treatment data collection date field name. */
static char TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'a', '_', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'e'};
static char* TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_NAME = TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The treatment data collection time field name. */
static char TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'a', '_', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', '_', 't', 'i', 'm', 'e'};
static char* TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_NAME = TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The treatment current diagnosis field name. */
static char TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'c', 'u', 'r', 'r', 'e', 'n', 't', '_', 'd', 'i', 'a', 'g', 'n', 'o', 's', 'i', 's'};
static char* TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_NAME = TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The treatment drug prescribed with prescription field name. */
static char TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'r', 'u', 'g', '_', 'p', 'r', 'e', 's', 'c', 'r', 'i', 'b', 'e', 'd', '_', 'w', 'i', 't', 'h', '_', 'p', 'r', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n'};
static char* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_NAME = TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_NAME_COUNT = NUMBER_43_INTEGER_ARRAY;

/** The treatment drug prescribed without prescription field name. */
static char TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'r', 'u', 'g', '_', 'p', 'r', 'e', 's', 'c', 'r', 'i', 'b', 'e', 'd', '_', 'w', 'i', 't', 'h', 'o', 'u', 't', '_', 'p', 'r', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n'};
static char* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_NAME = TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_NAME_COUNT = NUMBER_46_INTEGER_ARRAY;

/** The treatment physician sample field name. */
static char TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 's', 'a', 'm', 'p', 'l', 'e'};
static char* TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_NAME = TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The treatment findings field name. */
static char TREATMENT_FINDINGS_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'f', 'i', 'n', 'd', 'i', 'n', 'g', 's'};
static char* TREATMENT_FINDINGS_XDT_FIELD_NAME = TREATMENT_FINDINGS_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_FINDINGS_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The treatment external findings field name. */
static char TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'e', 'x', 't', 'e', 'r', 'n', 'a', 'l', '_', 'f', 'i', 'n', 'd', 'i', 'n', 'g', 's'};
static char* TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_NAME = TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The treatment laboratory findings field name. */
static char TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'l', 'a', 'b', 'o', 'r', 'a', 't', 'o', 'r', 'y', '_', 'f', 'i', 'n', 'd', 'i', 'n', 'g', 's'};
static char* TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_NAME = TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_NAME_COUNT = NUMBER_29_INTEGER_ARRAY;

/** The treatment x-ray findings field name. */
static char TREATMENT_X_RAY_FINDINGS_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'x', '-', 'r', 'a', 'y', '_', 'f', 'i', 'n', 'd', 'i', 'n', 'g', 's'};
static char* TREATMENT_X_RAY_FINDINGS_XDT_FIELD_NAME = TREATMENT_X_RAY_FINDINGS_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_X_RAY_FINDINGS_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The treatment subsequent line count field name. */
static char TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 's', 'u', 'b', 's', 'e', 'q', 'u', 'e', 'n', 't', '_', 'l', 'i', 'n', 'e', '_', 'c', 'o', 'u', 'n', 't'};
static char* TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_NAME = TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The treatment comment field name. */
static char TREATMENT_COMMENT_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'c', 'o', 'm', 'm', 'e', 'n', 't'};
static char* TREATMENT_COMMENT_XDT_FIELD_NAME = TREATMENT_COMMENT_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_COMMENT_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The treatment formatted result table text field name. */
static char TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'f', 'o', 'r', 'm', 'a', 't', 't', 'e', 'd', '_', 'r', 'e', 's', 'u', 'l', 't', '_', 't', 'a', 'b', 'l', 'e', '_', 't', 'e', 'x', 't'};
static char* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_NAME = TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_NAME_COUNT = NUMBER_37_INTEGER_ARRAY;

/** The treatment blood pressure field name. */
static char TREATMENT_BLOOD_PRESSURE_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'b', 'l', 'o', 'o', 'd', '_', 'p', 'r', 'e', 's', 's', 'u', 'r', 'e'};
static char* TREATMENT_BLOOD_PRESSURE_XDT_FIELD_NAME = TREATMENT_BLOOD_PRESSURE_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_BLOOD_PRESSURE_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The treatment symptoms field name. */
static char TREATMENT_SYMPTOMS_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 's', 'y', 'm', 'p', 't', 'o', 'm', 's'};
static char* TREATMENT_SYMPTOMS_XDT_FIELD_NAME = TREATMENT_SYMPTOMS_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_SYMPTOMS_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The treatment therapy field name. */
static char TREATMENT_THERAPY_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 't', 'h', 'e', 'r', 'a', 'p', 'y'};
static char* TREATMENT_THERAPY_XDT_FIELD_NAME = TREATMENT_THERAPY_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_THERAPY_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The treatment physical therapy field name. */
static char TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'p', 'h', 'y', 's', 'i', 'c', 'a', 'l', '_', 't', 'h', 'e', 'r', 'a', 'p', 'y'};
static char* TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_NAME = TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The treatment referral content field name. */
static char TREATMENT_REFERRAL_CONTENT_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'o', 'n', 't', 'e', 'n', 't'};
static char* TREATMENT_REFERRAL_CONTENT_XDT_FIELD_NAME = TREATMENT_REFERRAL_CONTENT_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_REFERRAL_CONTENT_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The treatment work disability duration field name. */
static char TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'w', 'o', 'r', 'k', '_', 'd', 'i', 's', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n'};
static char* TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_NAME = TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The treatment work disability cause field name. */
static char TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'w', 'o', 'r', 'k', '_', 'd', 'i', 's', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 'c', 'a', 'u', 's', 'e'};
static char* TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_NAME = TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The treatment hospitalisation field name. */
static char TREATMENT_HOSPITALISATION_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'h', 'o', 's', 'p', 'i', 't', 'a', 'l', 'i', 's', 'a', 't', 'i', 'o', 'n'};
static char* TREATMENT_HOSPITALISATION_XDT_FIELD_NAME = TREATMENT_HOSPITALISATION_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_HOSPITALISATION_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The treatment hospitalisation cause field name. */
static char TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'h', 'o', 's', 'p', 'i', 't', 'a', 'l', 'i', 's', 'a', 't', 'i', 'o', 'n', '_', 'c', 'a', 'u', 's', 'e'};
static char* TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_NAME = TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_NAME_ARRAY;
static int* TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The letter certificate kind field name. */
static char LETTER_CERTIFICATE_KIND_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'c', 'e', 'r', 't', 'i', 'f', 'i', 'c', 'a', 't', 'e', '_', 'k', 'i', 'n', 'd'};
static char* LETTER_CERTIFICATE_KIND_XDT_FIELD_NAME = LETTER_CERTIFICATE_KIND_XDT_FIELD_NAME_ARRAY;
static int* LETTER_CERTIFICATE_KIND_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The letter certificate content field name. */
static char LETTER_CERTIFICATE_CONTENT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'c', 'e', 'r', 't', 'i', 'f', 'i', 'c', 'a', 't', 'e', '_', 'c', 'o', 'n', 't', 'e', 'n', 't'};
static char* LETTER_CERTIFICATE_CONTENT_XDT_FIELD_NAME = LETTER_CERTIFICATE_CONTENT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_CERTIFICATE_CONTENT_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The letter file archive number field name. */
static char LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'f', 'i', 'l', 'e', '_', 'a', 'r', 'c', 'h', 'i', 'v', 'e', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_NAME = LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The letter file format field name. */
static char LETTER_FILE_FORMAT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'f', 'i', 'l', 'e', '_', 'f', 'o', 'r', 'm', 'a', 't'};
static char* LETTER_FILE_FORMAT_XDT_FIELD_NAME = LETTER_FILE_FORMAT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_FILE_FORMAT_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The letter file content field name. */
static char LETTER_FILE_CONTENT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'f', 'i', 'l', 'e', '_', 'c', 'o', 'n', 't', 'e', 'n', 't'};
static char* LETTER_FILE_CONTENT_XDT_FIELD_NAME = LETTER_FILE_CONTENT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_FILE_CONTENT_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The letter file url field name. */
static char LETTER_FILE_URL_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'f', 'i', 'l', 'e', '_', 'u', 'r', 'l'};
static char* LETTER_FILE_URL_XDT_FIELD_NAME = LETTER_FILE_URL_XDT_FIELD_NAME_ARRAY;
static int* LETTER_FILE_URL_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The letter attestation kind field name. */
static char LETTER_ATTESTATION_KIND_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'a', 't', 't', 'e', 's', 't', 'a', 't', 'i', 'o', 'n', '_', 'k', 'i', 'n', 'd'};
static char* LETTER_ATTESTATION_KIND_XDT_FIELD_NAME = LETTER_ATTESTATION_KIND_XDT_FIELD_NAME_ARRAY;
static int* LETTER_ATTESTATION_KIND_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The letter attestation content field name. */
static char LETTER_ATTESTATION_CONTENT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'a', 't', 't', 'e', 's', 't', 'a', 't', 'i', 'o', 'n', '_', 'c', 'o', 'n', 't', 'e', 'n', 't'};
static char* LETTER_ATTESTATION_CONTENT_XDT_FIELD_NAME = LETTER_ATTESTATION_CONTENT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_ATTESTATION_CONTENT_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The letter addressee field name. */
static char LETTER_ADDRESSEE_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'a', 'd', 'd', 'r', 'e', 's', 's', 'e', 'e'};
static char* LETTER_ADDRESSEE_XDT_FIELD_NAME = LETTER_ADDRESSEE_XDT_FIELD_NAME_ARRAY;
static int* LETTER_ADDRESSEE_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The letter salutation field name. */
static char LETTER_SALUTATION_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 's', 'a', 'l', 'u', 't', 'a', 't', 'i', 'o', 'n'};
static char* LETTER_SALUTATION_XDT_FIELD_NAME = LETTER_SALUTATION_XDT_FIELD_NAME_ARRAY;
static int* LETTER_SALUTATION_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The letter street field name. */
static char LETTER_STREET_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 's', 't', 'r', 'e', 'e', 't'};
static char* LETTER_STREET_XDT_FIELD_NAME = LETTER_STREET_XDT_FIELD_NAME_ARRAY;
static int* LETTER_STREET_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The letter postcode field name. */
static char LETTER_POSTCODE_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'p', 'o', 's', 't', 'c', 'o', 'd', 'e'};
static char* LETTER_POSTCODE_XDT_FIELD_NAME = LETTER_POSTCODE_XDT_FIELD_NAME_ARRAY;
static int* LETTER_POSTCODE_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The letter residence field name. */
static char LETTER_RESIDENCE_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'r', 'e', 's', 'i', 'd', 'e', 'n', 'c', 'e'};
static char* LETTER_RESIDENCE_XDT_FIELD_NAME = LETTER_RESIDENCE_XDT_FIELD_NAME_ARRAY;
static int* LETTER_RESIDENCE_XDT_FIELD_NAME_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The letter complimentary close field name. */
static char LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'c', 'o', 'm', 'p', 'l', 'i', 'm', 'e', 'n', 't', 'a', 'r', 'y', '_', 'c', 'l', 'o', 's', 'e'};
static char* LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME = LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME_ARRAY;
static int* LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The letter phone field name. */
static char LETTER_PHONE_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'p', 'h', 'o', 'n', 'e'};
static char* LETTER_PHONE_XDT_FIELD_NAME = LETTER_PHONE_XDT_FIELD_NAME_ARRAY;
static int* LETTER_PHONE_XDT_FIELD_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The letter fax field name. */
static char LETTER_FAX_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'f', 'a', 'x'};
static char* LETTER_FAX_XDT_FIELD_NAME = LETTER_FAX_XDT_FIELD_NAME_ARRAY;
static int* LETTER_FAX_XDT_FIELD_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The letter physician number field name. */
static char LETTER_PHYSICIAN_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* LETTER_PHYSICIAN_NUMBER_XDT_FIELD_NAME = LETTER_PHYSICIAN_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* LETTER_PHYSICIAN_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The letter content field name. */
static char LETTER_CONTENT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'c', 'o', 'n', 't', 'e', 'n', 't'};
static char* LETTER_CONTENT_XDT_FIELD_NAME = LETTER_CONTENT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_CONTENT_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The letter image archive number field name. */
static char LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'i', 'm', 'a', 'g', 'e', '_', 'a', 'r', 'c', 'h', 'i', 'v', 'e', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_NAME = LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The letter graphic format field name. */
static char LETTER_GRAPHIC_FORMAT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'g', 'r', 'a', 'p', 'h', 'i', 'c', '_', 'f', 'o', 'r', 'm', 'a', 't'};
static char* LETTER_GRAPHIC_FORMAT_XDT_FIELD_NAME = LETTER_GRAPHIC_FORMAT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_GRAPHIC_FORMAT_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The letter image content field name. */
static char LETTER_IMAGE_CONTENT_XDT_FIELD_NAME_ARRAY[] = {'l', 'e', 't', 't', 'e', 'r', '_', 'i', 'm', 'a', 'g', 'e', '_', 'c', 'o', 'n', 't', 'e', 'n', 't'};
static char* LETTER_IMAGE_CONTENT_XDT_FIELD_NAME = LETTER_IMAGE_CONTENT_XDT_FIELD_NAME_ARRAY;
static int* LETTER_IMAGE_CONTENT_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The free record 6200 category 1 name field name. */
static char FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 1 value field name. */
static char FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 2 name field name. */
static char FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 2 value field name. */
static char FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 3 name field name. */
static char FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 3 value field name. */
static char FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 4 name field name. */
static char FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 4 value field name. */
static char FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 5 name field name. */
static char FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 5 value field name. */
static char FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 6 name field name. */
static char FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '6', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 6 value field name. */
static char FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '6', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 7 name field name. */
static char FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '7', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 7 value field name. */
static char FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '7', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 8 name field name. */
static char FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '8', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 8 value field name. */
static char FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '8', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 9 name field name. */
static char FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '9', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The free record 6200 category 9 value field name. */
static char FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '9', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 10 name field name. */
static char FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '0', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 10 value field name. */
static char FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '0', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 11 name field name. */
static char FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 11 value field name. */
static char FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 12 name field name. */
static char FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 12 value field name. */
static char FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 13 name field name. */
static char FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 13 value field name. */
static char FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 14 name field name. */
static char FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 14 value field name. */
static char FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 15 name field name. */
static char FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 15 value field name. */
static char FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 16 name field name. */
static char FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '6', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 16 value field name. */
static char FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '6', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 17 name field name. */
static char FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '7', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 17 value field name. */
static char FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '7', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 18 name field name. */
static char FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '8', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 18 value field name. */
static char FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '8', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 19 name field name. */
static char FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '9', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 19 value field name. */
static char FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '1', '9', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 20 name field name. */
static char FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '0', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 20 value field name. */
static char FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '0', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 21 name field name. */
static char FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 21 value field name. */
static char FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 22 name field name. */
static char FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 22 value field name. */
static char FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 23 name field name. */
static char FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 23 value field name. */
static char FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 24 name field name. */
static char FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 24 value field name. */
static char FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 25 name field name. */
static char FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 25 value field name. */
static char FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 26 name field name. */
static char FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '6', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 26 value field name. */
static char FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '6', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 27 name field name. */
static char FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '7', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 27 value field name. */
static char FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '7', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 28 name field name. */
static char FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '8', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 28 value field name. */
static char FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '8', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 29 name field name. */
static char FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '9', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 29 value field name. */
static char FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '2', '9', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 30 name field name. */
static char FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '0', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 30 value field name. */
static char FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '0', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 31 name field name. */
static char FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '1', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 31 value field name. */
static char FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '1', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 32 name field name. */
static char FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '2', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 32 value field name. */
static char FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '2', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 33 name field name. */
static char FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '3', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 33 value field name. */
static char FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '3', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 34 name field name. */
static char FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '4', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 34 value field name. */
static char FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '4', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The free record 6200 category 35 name field name. */
static char FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '5', '_', 'n', 'a', 'm', 'e'};
static char* FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The free record 6200 category 35 value field name. */
static char FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'r', 'e', 'e', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', '6', '2', '0', '0', '_', 'c', 'a', 't', 'e', 'g', 'o', 'r', 'y', '_', '3', '5', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_NAME = FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The record identification field name. */
static char RECORD_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'c', 'o', 'r', 'd', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* RECORD_IDENTIFICATION_XDT_FIELD_NAME = RECORD_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* RECORD_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The record size field name. */
static char RECORD_SIZE_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'c', 'o', 'r', 'd', '_', 's', 'i', 'z', 'e'};
static char* RECORD_SIZE_XDT_FIELD_NAME = RECORD_SIZE_XDT_FIELD_NAME_ARRAY;
static int* RECORD_SIZE_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The device receiver gdt id field name. */
static char DEVICE_RECEIVER_GDT_ID_XDT_FIELD_NAME_ARRAY[] = {'d', 'e', 'v', 'i', 'c', 'e', '_', 'r', 'e', 'c', 'e', 'i', 'v', 'e', 'r', '_', 'g', 'd', 't', '_', 'i', 'd'};
static char* DEVICE_RECEIVER_GDT_ID_XDT_FIELD_NAME = DEVICE_RECEIVER_GDT_ID_XDT_FIELD_NAME_ARRAY;
static int* DEVICE_RECEIVER_GDT_ID_XDT_FIELD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The device sender gdt id field name. */
static char DEVICE_SENDER_GDT_ID_XDT_FIELD_NAME_ARRAY[] = {'d', 'e', 'v', 'i', 'c', 'e', '_', 's', 'e', 'n', 'd', 'e', 'r', '_', 'g', 'd', 't', '_', 'i', 'd'};
static char* DEVICE_SENDER_GDT_ID_XDT_FIELD_NAME = DEVICE_SENDER_GDT_ID_XDT_FIELD_NAME_ARRAY;
static int* DEVICE_SENDER_GDT_ID_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The findings kind field name. */
static char FINDINGS_KIND_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'k', 'i', 'n', 'd'};
static char* FINDINGS_KIND_XDT_FIELD_NAME = FINDINGS_KIND_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_KIND_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The findings device specifics field name. */
static char FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'd', 'e', 'v', 'i', 'c', 'e', '_', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'c', 's'};
static char* FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_NAME = FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The findings test identification field name. */
static char FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 't', 'e', 's', 't', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_NAME = FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The findings test name field name. */
static char FINDINGS_TEST_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 't', 'e', 's', 't', '_', 'n', 'a', 'm', 'e'};
static char* FINDINGS_TEST_NAME_XDT_FIELD_NAME = FINDINGS_TEST_NAME_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_TEST_NAME_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The findings test status field name. */
static char FINDINGS_TEST_STATUS_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 't', 'e', 's', 't', '_', 's', 't', 'a', 't', 'u', 's'};
static char* FINDINGS_TEST_STATUS_XDT_FIELD_NAME = FINDINGS_TEST_STATUS_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_TEST_STATUS_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The findings test result value field name. */
static char FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 't', 'e', 's', 't', '_', 'r', 'e', 's', 'u', 'l', 't', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_NAME = FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The findings test result unit field name. */
static char FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 't', 'e', 's', 't', '_', 'r', 'e', 's', 'u', 'l', 't', '_', 'u', 'n', 'i', 't'};
static char* FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_NAME = FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The findings limit indicator field name. */
static char FINDINGS_LIMIT_INDICATOR_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'l', 'i', 'm', 'i', 't', '_', 'i', 'n', 'd', 'i', 'c', 'a', 't', 'o', 'r'};
static char* FINDINGS_LIMIT_INDICATOR_XDT_FIELD_NAME = FINDINGS_LIMIT_INDICATOR_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_LIMIT_INDICATOR_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The findings sample material identification field name. */
static char FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'm', 'a', 't', 'e', 'r', 'i', 'a', 'l', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_NAME = FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_39_INTEGER_ARRAY;

/** The findings sample material index field name. */
static char FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'm', 'a', 't', 'e', 'r', 'i', 'a', 'l', '_', 'i', 'n', 'd', 'e', 'x'};
static char* FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_NAME = FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The findings sample material name field name. */
static char FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'm', 'a', 't', 'e', 'r', 'i', 'a', 'l', '_', 'n', 'a', 'm', 'e'};
static char* FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_NAME = FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_NAME_COUNT = NUMBER_29_INTEGER_ARRAY;

/** The findings sample material specification field name. */
static char FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'm', 'a', 't', 'e', 'r', 'i', 'a', 'l', '_', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_NAME = FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_38_INTEGER_ARRAY;

/** The findings sample collection date field name. */
static char FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'e'};
static char* FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_NAME = FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The findings sample collection time (old format) field name. */
static char FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', '_', 't', 'i', 'm', 'e', '_', 'o', 'l', 'd', '_', 'f', 'o', 'r', 'm', 'a', 't'};
static char* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_NAME = FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_NAME_COUNT = NUMBER_42_INTEGER_ARRAY;

/** The findings data stream units field name. */
static char FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'd', 'a', 't', 'a', '_', 's', 't', 'r', 'e', 'a', 'm', '_', 'u', 'n', 'i', 't', 's'};
static char* FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_NAME = FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The findings data stream field name. */
static char FINDINGS_DATA_STREAM_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'd', 'a', 't', 'a', '_', 's', 't', 'r', 'e', 'a', 'm'};
static char* FINDINGS_DATA_STREAM_XDT_FIELD_NAME = FINDINGS_DATA_STREAM_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_DATA_STREAM_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The findings sample collection time field name. */
static char FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'a', 'm', 'p', 'l', 'e', '_', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', '_', 't', 'i', 'm', 'e'};
static char* FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_NAME = FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_NAME_COUNT = NUMBER_31_INTEGER_ARRAY;

/** The findings germ identification field name. */
static char FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'g', 'e', 'r', 'm', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_NAME = FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The findings germ name field name. */
static char FINDINGS_GERM_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'g', 'e', 'r', 'm', '_', 'n', 'a', 'm', 'e'};
static char* FINDINGS_GERM_NAME_XDT_FIELD_NAME = FINDINGS_GERM_NAME_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_GERM_NAME_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The findings germ number field name. */
static char FINDINGS_GERM_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'g', 'e', 'r', 'm', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* FINDINGS_GERM_NUMBER_XDT_FIELD_NAME = FINDINGS_GERM_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_GERM_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The findings resistance method field name. */
static char FINDINGS_RESISTANCE_METHOD_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'r', 'e', 's', 'i', 's', 't', 'a', 'n', 'c', 'e', '_', 'm', 'e', 't', 'h', 'o', 'd'};
static char* FINDINGS_RESISTANCE_METHOD_XDT_FIELD_NAME = FINDINGS_RESISTANCE_METHOD_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_RESISTANCE_METHOD_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The findings active substance field name. */
static char FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'a', 'c', 't', 'i', 'v', 'e', '_', 's', 'u', 'b', 's', 't', 'a', 'n', 'c', 'e'};
static char* FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_NAME = FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The findings active substance generic name field name. */
static char FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'a', 'c', 't', 'i', 'v', 'e', '_', 's', 'u', 'b', 's', 't', 'a', 'n', 'c', 'e', '_', 'g', 'e', 'n', 'e', 'r', 'i', 'c', '_', 'n', 'a', 'm', 'e'};
static char* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_NAME = FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_NAME_COUNT = NUMBER_38_INTEGER_ARRAY;

/** The findings mhk breakpoint value field name. */
static char FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'm', 'h', 'k', '_', 'b', 'r', 'e', 'a', 'k', 'p', 'o', 'i', 'n', 't', '_', 'v', 'a', 'l', 'u', 'e'};
static char* FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_NAME = FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_NAME_COUNT = NUMBER_29_INTEGER_ARRAY;

/** The findings resistance interpretation field name. */
static char FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'r', 'e', 's', 'i', 's', 't', 'a', 'n', 'c', 'e', '_', 'i', 'n', 't', 'e', 'r', 'p', 'r', 'e', 't', 'a', 't', 'i', 'o', 'n'};
static char* FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_NAME = FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_NAME_COUNT = NUMBER_34_INTEGER_ARRAY;

/** The findings normal value text field name. */
static char FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'n', 'o', 'r', 'm', 'a', 'l', '_', 'v', 'a', 'l', 'u', 'e', '_', 't', 'e', 'x', 't'};
static char* FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_NAME = FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The findings normal value lower limit field name. */
static char FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'n', 'o', 'r', 'm', 'a', 'l', '_', 'v', 'a', 'l', 'u', 'e', '_', 'l', 'o', 'w', 'e', 'r', '_', 'l', 'i', 'm', 'i', 't'};
static char* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_NAME = FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The findings normal value upper limit field name. */
static char FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'n', 'o', 'r', 'm', 'a', 'l', '_', 'v', 'a', 'l', 'u', 'e', '_', 'u', 'p', 'p', 'e', 'r', '_', 'l', 'i', 'm', 'i', 't'};
static char* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_NAME = FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_NAME_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The findings remark field name. */
static char FINDINGS_REMARK_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'r', 'e', 'm', 'a', 'r', 'k'};
static char* FINDINGS_REMARK_XDT_FIELD_NAME = FINDINGS_REMARK_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_REMARK_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The findings result text field name. */
static char FINDINGS_RESULT_TEXT_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'r', 'e', 's', 'u', 'l', 't', '_', 't', 'e', 'x', 't'};
static char* FINDINGS_RESULT_TEXT_XDT_FIELD_NAME = FINDINGS_RESULT_TEXT_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_RESULT_TEXT_XDT_FIELD_NAME_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The findings complimentary close field name. */
static char FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 'c', 'o', 'm', 'p', 'l', 'i', 'm', 'e', 'n', 't', 'a', 'r', 'y', '_', 'c', 'l', 'o', 's', 'e'};
static char* FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME = FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The findings signature field name. */
static char FINDINGS_SIGNATURE_XDT_FIELD_NAME_ARRAY[] = {'f', 'i', 'n', 'd', 'i', 'n', 'g', 's', '_', 's', 'i', 'g', 'n', 'a', 't', 'u', 'r', 'e'};
static char* FINDINGS_SIGNATURE_XDT_FIELD_NAME = FINDINGS_SIGNATURE_XDT_FIELD_NAME_ARRAY;
static int* FINDINGS_SIGNATURE_XDT_FIELD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The data medium sender physician number field name. */
static char DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 's', 'e', 'n', 'd', 'e', 'r', '_', 'p', 'h', 'y', 's', 'i', 'c', 'i', 'a', 'n', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_NAME = DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_35_INTEGER_ARRAY;

/** The data medium creation date field name. */
static char DATA_MEDIUM_CREATION_DATE_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'c', 'r', 'e', 'a', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'e'};
static char* DATA_MEDIUM_CREATION_DATE_XDT_FIELD_NAME = DATA_MEDIUM_CREATION_DATE_XDT_FIELD_NAME_ARRAY;
static int* DATA_MEDIUM_CREATION_DATE_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The data medium running number field name. */
static char DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'r', 'u', 'n', 'n', 'i', 'n', 'g', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_NAME = DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The data medium character code field name. */
static char DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', '_', 'c', 'o', 'd', 'e'};
static char* DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_NAME = DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_NAME_ARRAY;
static int* DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The data package size field name. */
static char DATA_PACKAGE_SIZE_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 's', 'i', 'z', 'e'};
static char* DATA_PACKAGE_SIZE_XDT_FIELD_NAME = DATA_PACKAGE_SIZE_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_SIZE_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The data package mediums count field name. */
static char DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 'm', 'e', 'd', 'i', 'u', 'm', 's', '_', 'c', 'o', 'u', 'n', 't'};
static char* DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_NAME = DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The data package character set field name. */
static char DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', '_', 's', 'e', 't'};
static char* DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_NAME = DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_NAME_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The data package adt version field name. */
static char DATA_PACKAGE_ADT_VERSION_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 'a', 'd', 't', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n'};
static char* DATA_PACKAGE_ADT_VERSION_XDT_FIELD_NAME = DATA_PACKAGE_ADT_VERSION_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_ADT_VERSION_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The data package bdt version field name. */
static char DATA_PACKAGE_BDT_VERSION_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 'b', 'd', 't', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n'};
static char* DATA_PACKAGE_BDT_VERSION_XDT_FIELD_NAME = DATA_PACKAGE_BDT_VERSION_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_BDT_VERSION_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The data package gdt version field name. */
static char DATA_PACKAGE_GDT_VERSION_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 'g', 'd', 't', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n'};
static char* DATA_PACKAGE_GDT_VERSION_XDT_FIELD_NAME = DATA_PACKAGE_GDT_VERSION_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_GDT_VERSION_XDT_FIELD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The data package archiving type field name. */
static char DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 'a', 'r', 'c', 'h', 'i', 'v', 'i', 'n', 'g', '_', 't', 'y', 'p', 'e'};
static char* DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_NAME = DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The data package storage period field name. */
static char DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 's', 't', 'o', 'r', 'a', 'g', 'e', '_', 'p', 'e', 'r', 'i', 'o', 'd'};
static char* DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_NAME = DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The data package transfer begin field name. */
static char DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r', '_', 'b', 'e', 'g', 'i', 'n'};
static char* DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_NAME = DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The system internal parameter field name. */
static char SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME_ARRAY[] = {'s', 'y', 's', 't', 'e', 'm', '_', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '_', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r'};
static char* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME = SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME_ARRAY;
static int* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/* XDT_FIELD_NAME_CONSTANTS_SOURCE */
#endif
