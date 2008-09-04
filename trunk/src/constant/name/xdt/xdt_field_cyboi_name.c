/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: xdt_field_cyboi_name.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_FIELD_CYBOI_NAME_SOURCE
#define XDT_FIELD_CYBOI_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The kbv test number xdt field cyboi name. */
static wchar_t KBV_TEST_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'k', L'b', L'v', L'_', L't', L'e', L's', L't', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* KBV_TEST_NUMBER_XDT_FIELD_CYBOI_NAME = KBV_TEST_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* KBV_TEST_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The responsible entity xdt field cyboi name. */
static wchar_t RESPONSIBLE_ENTITY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L's', L'p', L'o', L'n', L's', L'i', L'b', L'l', L'e', L'_', L'e', L'n', L't', L'i', L't', L'y'};
static wchar_t* RESPONSIBLE_ENTITY_XDT_FIELD_CYBOI_NAME = RESPONSIBLE_ENTITY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* RESPONSIBLE_ENTITY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The software xdt field cyboi name. */
static wchar_t SOFTWARE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'o', L'f', L't', L'w', L'a', L'r', L'e'};
static wchar_t* SOFTWARE_XDT_FIELD_CYBOI_NAME = SOFTWARE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SOFTWARE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The hardware xdt field cyboi name. */
static wchar_t HARDWARE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'h', L'a', L'r', L'd', L'w', L'a', L'r', L'e'};
static wchar_t* HARDWARE_XDT_FIELD_CYBOI_NAME = HARDWARE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* HARDWARE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The software release xdt field cyboi name. */
static wchar_t SOFTWARE_RELEASE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'o', L'f', L't', L'w', L'a', L'r', L'e', L'_', L'r', L'e', L'l', L'e', L'a', L's', L'e'};
static wchar_t* SOFTWARE_RELEASE_XDT_FIELD_CYBOI_NAME = SOFTWARE_RELEASE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SOFTWARE_RELEASE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician identification xdt field cyboi name. */
static wchar_t PHYSICIAN_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* PHYSICIAN_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = PHYSICIAN_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician practice type xdt field cyboi name. */
static wchar_t PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e', L'_', L't', L'y', L'p', L'e'};
static wchar_t* PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_CYBOI_NAME = PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_PRACTICE_TYPE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician name xdt field cyboi name. */
static wchar_t PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME = PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician category xdt field cyboi name. */
static wchar_t PHYSICIAN_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y'};
static wchar_t* PHYSICIAN_CATEGORY_XDT_FIELD_CYBOI_NAME = PHYSICIAN_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_CATEGORY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician street xdt field cyboi name. */
static wchar_t PHYSICIAN_STREET_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L's', L't', L'r', L'e', L'e', L't'};
static wchar_t* PHYSICIAN_STREET_XDT_FIELD_CYBOI_NAME = PHYSICIAN_STREET_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_STREET_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician postcode and place xdt field cyboi name. */
static wchar_t PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'p', L'o', L's', L't', L'c', L'o', L'd', L'e', L'_', L'a', L'n', L'd', L'_', L'p', L'l', L'a', L'c', L'e'};
static wchar_t* PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_CYBOI_NAME = PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician with service indicator xdt field cyboi name. */
static wchar_t PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'w', L'i', L't', L'h', L'_', L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'i', L'n', L'd', L'i', L'c', L'a', L't', L'o', L'r'};
static wchar_t* PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_CYBOI_NAME = PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician phone xdt field cyboi name. */
static wchar_t PHYSICIAN_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'p', L'h', L'o', L'n', L'e'};
static wchar_t* PHYSICIAN_PHONE_XDT_FIELD_CYBOI_NAME = PHYSICIAN_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_PHONE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician fax xdt field cyboi name. */
static wchar_t PHYSICIAN_FAX_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'f', L'a', L'x'};
static wchar_t* PHYSICIAN_FAX_XDT_FIELD_CYBOI_NAME = PHYSICIAN_FAX_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_FAX_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician modem xdt field cyboi name. */
static wchar_t PHYSICIAN_MODEM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'm', L'o', L'd', L'e', L'm'};
static wchar_t* PHYSICIAN_MODEM_XDT_FIELD_CYBOI_NAME = PHYSICIAN_MODEM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_MODEM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The physician number within practice xdt field cyboi name. */
static wchar_t PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'u', L'm', L'b', L'e', L'r', L'_', L'w', L'i', L't', L'h', L'i', L'n', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e'};
static wchar_t* PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_CYBOI_NAME = PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 1 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 1 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 2 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 2 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 3 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 3 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 4 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 4 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 5 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 5 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 6 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'6', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 6 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'6', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 7 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'7', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 7 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'7', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 8 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'8', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 8 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'8', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 9 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'9', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 9 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'9', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 10 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'0', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 10 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'0', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 11 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 11 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 12 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 12 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 13 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 13 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 14 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 14 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 15 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 15 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 16 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'6', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 16 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'6', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 17 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'7', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 17 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'7', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 18 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'8', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 18 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'8', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 19 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'9', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 19 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'9', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 20 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'0', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 20 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'0', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 21 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 21 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 22 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 22 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 23 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 23 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 24 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 24 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 25 name xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 0010 category 25 value xdt field cyboi name. */
static wchar_t FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'0', L'0', L'1', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient identification xdt field cyboi name. */
static wchar_t PATIENT_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* PATIENT_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = PATIENT_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient name affix xdt field cyboi name. */
static wchar_t PATIENT_NAME_AFFIX_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'n', L'a', L'm', L'e', L'_', L'a', L'f', L'f', L'i', L'x'};
static wchar_t* PATIENT_NAME_AFFIX_XDT_FIELD_CYBOI_NAME = PATIENT_NAME_AFFIX_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_NAME_AFFIX_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient last name xdt field cyboi name. */
static wchar_t PATIENT_LAST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'l', L'a', L's', L't', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* PATIENT_LAST_NAME_XDT_FIELD_CYBOI_NAME = PATIENT_LAST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_LAST_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient first name xdt field cyboi name. */
static wchar_t PATIENT_FIRST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'f', L'i', L'r', L's', L't', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* PATIENT_FIRST_NAME_XDT_FIELD_CYBOI_NAME = PATIENT_FIRST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_FIRST_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient birth date xdt field cyboi name. */
static wchar_t PATIENT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'b', L'i', L'r', L't', L'h', L'_', L'd', L'a', L't', L'e'};
static wchar_t* PATIENT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME = PATIENT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient title xdt field cyboi name. */
static wchar_t PATIENT_TITLE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L't', L'i', L't', L'l', L'e'};
static wchar_t* PATIENT_TITLE_XDT_FIELD_CYBOI_NAME = PATIENT_TITLE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_TITLE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient health insurance number xdt field cyboi name. */
static wchar_t PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'h', L'e', L'a', L'l', L't', L'h', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME = PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient residence xdt field cyboi name. */
static wchar_t PATIENT_RESIDENCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'r', L'e', L's', L'i', L'd', L'e', L'n', L'c', L'e'};
static wchar_t* PATIENT_RESIDENCE_XDT_FIELD_CYBOI_NAME = PATIENT_RESIDENCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_RESIDENCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient street xdt field cyboi name. */
static wchar_t PATIENT_STREET_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L's', L't', L'r', L'e', L'e', L't'};
static wchar_t* PATIENT_STREET_XDT_FIELD_CYBOI_NAME = PATIENT_STREET_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_STREET_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient health insurance type xdt field cyboi name. */
static wchar_t PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'h', L'e', L'a', L'l', L't', L'h', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L't', L'y', L'p', L'e'};
static wchar_t* PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_CYBOI_NAME = PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient sex xdt field cyboi name. */
static wchar_t PATIENT_SEX_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L's', L'e', L'x'};
static wchar_t* PATIENT_SEX_XDT_FIELD_CYBOI_NAME = PATIENT_SEX_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_SEX_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient employer xdt field cyboi name. */
static wchar_t PATIENT_EMPLOYER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'e', L'm', L'p', L'l', L'o', L'y', L'e', L'r'};
static wchar_t* PATIENT_EMPLOYER_XDT_FIELD_CYBOI_NAME = PATIENT_EMPLOYER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_EMPLOYER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient accident insurance name xdt field cyboi name. */
static wchar_t PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_CYBOI_NAME = PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The insurant last name xdt field cyboi name. */
static wchar_t INSURANT_LAST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L's', L'u', L'r', L'a', L'n', L't', L'_', L'l', L'a', L's', L't', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* INSURANT_LAST_NAME_XDT_FIELD_CYBOI_NAME = INSURANT_LAST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INSURANT_LAST_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The insurant first name xdt field cyboi name. */
static wchar_t INSURANT_FIRST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L's', L'u', L'r', L'a', L'n', L't', L'_', L'f', L'i', L'r', L's', L't', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* INSURANT_FIRST_NAME_XDT_FIELD_CYBOI_NAME = INSURANT_FIRST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INSURANT_FIRST_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The insurant birth date xdt field cyboi name. */
static wchar_t INSURANT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L's', L'u', L'r', L'a', L'n', L't', L'_', L'b', L'i', L'r', L't', L'h', L'_', L'd', L'a', L't', L'e'};
static wchar_t* INSURANT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME = INSURANT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INSURANT_BIRTH_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The insurant residence xdt field cyboi name. */
static wchar_t INSURANT_RESIDENCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L's', L'u', L'r', L'a', L'n', L't', L'_', L'r', L'e', L's', L'i', L'd', L'e', L'n', L'c', L'e'};
static wchar_t* INSURANT_RESIDENCE_XDT_FIELD_CYBOI_NAME = INSURANT_RESIDENCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INSURANT_RESIDENCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The insurant street xdt field cyboi name. */
static wchar_t INSURANT_STREET_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L's', L'u', L'r', L'a', L'n', L't', L'_', L's', L't', L'r', L'e', L'e', L't'};
static wchar_t* INSURANT_STREET_XDT_FIELD_CYBOI_NAME = INSURANT_STREET_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INSURANT_STREET_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The injured phone xdt field cyboi name. */
static wchar_t INJURED_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'j', L'u', L'r', L'e', L'd', L'_', L'p', L'h', L'o', L'n', L'e'};
static wchar_t* INJURED_PHONE_XDT_FIELD_CYBOI_NAME = INJURED_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INJURED_PHONE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The insurant sex xdt field cyboi name. */
static wchar_t INSURANT_SEX_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L's', L'u', L'r', L'a', L'n', L't', L'_', L's', L'e', L'x'};
static wchar_t* INSURANT_SEX_XDT_FIELD_CYBOI_NAME = INSURANT_SEX_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INSURANT_SEX_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient x-ray number xdt field cyboi name. */
static wchar_t PATIENT_X_RAY_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'x', L'-', L'r', L'a', L'y', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* PATIENT_X_RAY_NUMBER_XDT_FIELD_CYBOI_NAME = PATIENT_X_RAY_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_X_RAY_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient archive number xdt field cyboi name. */
static wchar_t PATIENT_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'r', L'c', L'h', L'i', L'v', L'e', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* PATIENT_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME = PATIENT_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient employers' liability insurance association number xdt field cyboi name. */
static wchar_t PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'e', L'm', L'p', L'l', L'o', L'y', L'e', L'r', L's', L'_', L'l', L'i', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'a', L's', L's', L'o', L'c', L'i', L'a', L't', L'i', L'o', L'n', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_CYBOI_NAME = PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient since date xdt field cyboi name. */
static wchar_t PATIENT_SINCE_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L's', L'i', L'n', L'c', L'e', L'_', L'd', L'a', L't', L'e'};
static wchar_t* PATIENT_SINCE_DATE_XDT_FIELD_CYBOI_NAME = PATIENT_SINCE_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_SINCE_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient change of insurance inception date xdt field cyboi name. */
static wchar_t PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'c', L'h', L'a', L'n', L'g', L'e', L'_', L'o', L'f', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'i', L'n', L'c', L'e', L'p', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_CYBOI_NAME = PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient profession xdt field cyboi name. */
static wchar_t PATIENT_PROFESSION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'r', L'o', L'f', L'e', L's', L's', L'i', L'o', L'n'};
static wchar_t* PATIENT_PROFESSION_XDT_FIELD_CYBOI_NAME = PATIENT_PROFESSION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PROFESSION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient body height xdt field cyboi name. */
static wchar_t PATIENT_BODY_HEIGHT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'b', L'o', L'd', L'y', L'_', L'h', L'e', L'i', L'g', L'h', L't'};
static wchar_t* PATIENT_BODY_HEIGHT_XDT_FIELD_CYBOI_NAME = PATIENT_BODY_HEIGHT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_BODY_HEIGHT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient body weight xdt field cyboi name. */
static wchar_t PATIENT_BODY_WEIGHT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'b', L'o', L'd', L'y', L'_', L'w', L'e', L'i', L'g', L'h', L't'};
static wchar_t* PATIENT_BODY_WEIGHT_XDT_FIELD_CYBOI_NAME = PATIENT_BODY_WEIGHT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_BODY_WEIGHT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient employer (redundant) xdt field cyboi name. */
static wchar_t PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'e', L'm', L'p', L'l', L'o', L'y', L'e', L'r', L'_', L'r', L'e', L'd', L'u', L'n', L'd', L'a', L'n', L't'};
static wchar_t* PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_CYBOI_NAME = PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_EMPLOYER_REDUNDANT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient phone xdt field cyboi name. */
static wchar_t PATIENT_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'h', L'o', L'n', L'e'};
static wchar_t* PATIENT_PHONE_XDT_FIELD_CYBOI_NAME = PATIENT_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PHONE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient nationality xdt field cyboi name. */
static wchar_t PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'n', L'a', L't', L'i', L'o', L'n', L'a', L'l', L'i', L't', L'y'};
static wchar_t* PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME = PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient mother tongue xdt field cyboi name. */
static wchar_t PATIENT_MOTHER_TONGUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'o', L't', L'h', L'e', L'r', L'_', L't', L'o', L'n', L'g', L'u', L'e'};
static wchar_t* PATIENT_MOTHER_TONGUE_XDT_FIELD_CYBOI_NAME = PATIENT_MOTHER_TONGUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_MOTHER_TONGUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient general practitioner identification xdt field cyboi name. */
static wchar_t PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'g', L'e', L'n', L'e', L'r', L'a', L'l', L'_', L'p', L'r', L'a', L'c', L't', L'i', L't', L'i', L'o', L'n', L'e', L'r', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient residence to medical practice distance xdt field cyboi name. */
static wchar_t PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'r', L'e', L's', L'i', L'd', L'e', L'n', L'c', L'e', L'_', L't', L'o', L'_', L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e', L'_', L'd', L'i', L's', L't', L'a', L'n', L'c', L'e'};
static wchar_t* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_CYBOI_NAME = PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_46_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient physician identification in group practice xdt field cyboi name. */
static wchar_t PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'_', L'i', L'n', L'_', L'g', L'r', L'o', L'u', L'p', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e'};
static wchar_t* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_CYBOI_NAME = PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient prescription identification xdt field cyboi name. */
static wchar_t PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'r', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient permanent diagnoses begin date xdt field cyboi name. */
static wchar_t PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'_', L'd', L'i', L'a', L'g', L'n', L'o', L's', L'e', L's', L'_', L'b', L'e', L'g', L'i', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_CYBOI_NAME = PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient permanent diagnoses xdt field cyboi name. */
static wchar_t PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'_', L'd', L'i', L'a', L'g', L'n', L'o', L's', L'e', L's'};
static wchar_t* PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_CYBOI_NAME = PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient permanent drugs begin date xdt field cyboi name. */
static wchar_t PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'_', L'd', L'r', L'u', L'g', L's', L'_', L'b', L'e', L'g', L'i', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_CYBOI_NAME = PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient permanent drugs xdt field cyboi name. */
static wchar_t PATIENT_PERMANENT_DRUGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'_', L'd', L'r', L'u', L'g', L's'};
static wchar_t* PATIENT_PERMANENT_DRUGS_XDT_FIELD_CYBOI_NAME = PATIENT_PERMANENT_DRUGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PERMANENT_DRUGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient risk factors xdt field cyboi name. */
static wchar_t PATIENT_RISK_FACTORS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'r', L'i', L's', L'k', L'_', L'f', L'a', L'c', L't', L'o', L'r', L's'};
static wchar_t* PATIENT_RISK_FACTORS_XDT_FIELD_CYBOI_NAME = PATIENT_RISK_FACTORS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_RISK_FACTORS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient allergies xdt field cyboi name. */
static wchar_t PATIENT_ALLERGIES_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'l', L'l', L'e', L'r', L'g', L'i', L'e', L's'};
static wchar_t* PATIENT_ALLERGIES_XDT_FIELD_CYBOI_NAME = PATIENT_ALLERGIES_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_ALLERGIES_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient accidents xdt field cyboi name. */
static wchar_t PATIENT_ACCIDENTS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L's'};
static wchar_t* PATIENT_ACCIDENTS_XDT_FIELD_CYBOI_NAME = PATIENT_ACCIDENTS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_ACCIDENTS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient surgeries xdt field cyboi name. */
static wchar_t PATIENT_SURGERIES_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L's', L'u', L'r', L'g', L'e', L'r', L'i', L'e', L's'};
static wchar_t* PATIENT_SURGERIES_XDT_FIELD_CYBOI_NAME = PATIENT_SURGERIES_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_SURGERIES_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient anamnesis xdt field cyboi name. */
static wchar_t PATIENT_ANAMNESIS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'n', L'a', L'm', L'n', L'e', L's', L'i', L's'};
static wchar_t* PATIENT_ANAMNESIS_XDT_FIELD_CYBOI_NAME = PATIENT_ANAMNESIS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_ANAMNESIS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient number of births xdt field cyboi name. */
static wchar_t PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'n', L'u', L'm', L'b', L'e', L'r', L'_', L'o', L'f', L'_', L'b', L'i', L'r', L't', L'h', L's'};
static wchar_t* PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_CYBOI_NAME = PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient number of children xdt field cyboi name. */
static wchar_t PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'n', L'u', L'm', L'b', L'e', L'r', L'_', L'o', L'f', L'_', L'c', L'h', L'i', L'l', L'd', L'r', L'e', L'n'};
static wchar_t* PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_CYBOI_NAME = PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient number of pregnancies xdt field cyboi name. */
static wchar_t PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'n', L'u', L'm', L'b', L'e', L'r', L'_', L'o', L'f', L'_', L'p', L'r', L'e', L'g', L'n', L'a', L'n', L'c', L'i', L'e', L's'};
static wchar_t* PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_CYBOI_NAME = PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient permanent therapy xdt field cyboi name. */
static wchar_t PATIENT_PERMANENT_THERAPY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'p', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'_', L't', L'h', L'e', L'r', L'a', L'p', L'y'};
static wchar_t* PATIENT_PERMANENT_THERAPY_XDT_FIELD_CYBOI_NAME = PATIENT_PERMANENT_THERAPY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_PERMANENT_THERAPY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient recall appointment date xdt field cyboi name. */
static wchar_t PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'r', L'e', L'c', L'a', L'l', L'l', L'_', L'a', L'p', L'p', L'o', L'i', L'n', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'e'};
static wchar_t* PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_CYBOI_NAME = PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 1 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 1 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 2 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 2 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 3 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 3 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 4 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 4 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 5 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 5 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 6 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'6', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 6 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'6', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 7 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'7', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 7 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'7', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 8 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'8', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 8 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'8', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 9 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'9', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 9 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'9', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 10 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'0', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6100 category 10 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'1', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'0', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice quarter xdt field cyboi name. */
static wchar_t INVOICE_QUARTER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'q', L'u', L'a', L'r', L't', L'e', L'r'};
static wchar_t* INVOICE_QUARTER_XDT_FIELD_CYBOI_NAME = INVOICE_QUARTER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_QUARTER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice issuance date xdt field cyboi name. */
static wchar_t INVOICE_ISSUANCE_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L's', L's', L'u', L'a', L'n', L'c', L'e', L'_', L'd', L'a', L't', L'e'};
static wchar_t* INVOICE_ISSUANCE_DATE_XDT_FIELD_CYBOI_NAME = INVOICE_ISSUANCE_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_ISSUANCE_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice validity date xdt field cyboi name. */
static wchar_t INVOICE_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'v', L'a', L'l', L'i', L'd', L'i', L't', L'y', L'_', L'd', L'a', L't', L'e'};
static wchar_t* INVOICE_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME = INVOICE_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice insurance number xdt field cyboi name. */
static wchar_t INVOICE_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* INVOICE_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME = INVOICE_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice insurance office xdt field cyboi name. */
static wchar_t INVOICE_INSURANCE_OFFICE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'o', L'f', L'f', L'i', L'c', L'e'};
static wchar_t* INVOICE_INSURANCE_OFFICE_XDT_FIELD_CYBOI_NAME = INVOICE_INSURANCE_OFFICE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_INSURANCE_OFFICE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice insurance sub category xdt field cyboi name. */
static wchar_t INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L's', L'u', L'b', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y'};
static wchar_t* INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME = INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice billing category xdt field cyboi name. */
static wchar_t INVOICE_BILLING_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y'};
static wchar_t* INVOICE_BILLING_CATEGORY_XDT_FIELD_CYBOI_NAME = INVOICE_BILLING_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_BILLING_CATEGORY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice insurance card last read access xdt field cyboi name. */
static wchar_t INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'c', L'a', L'r', L'd', L'_', L'l', L'a', L's', L't', L'_', L'r', L'e', L'a', L'd', L'_', L'a', L'c', L'c', L'e', L's', L's'};
static wchar_t* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_CYBOI_NAME = INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_39_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice insurance card validity date xdt field cyboi name. */
static wchar_t INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'c', L'a', L'r', L'd', L'_', L'v', L'a', L'l', L'i', L'd', L'i', L't', L'y', L'_', L'd', L'a', L't', L'e'};
static wchar_t* INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME = INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice ik insurance number xdt field cyboi name. */
static wchar_t INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'i', L'k', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME = INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice vk insurance status xdt field cyboi name. */
static wchar_t INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'v', L'k', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L's', L't', L'a', L't', L'u', L's'};
static wchar_t* INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_CYBOI_NAME = INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_VK_INSURANCE_STATUS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice vk east-west status xdt field cyboi name. */
static wchar_t INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'v', L'k', L'_', L'e', L'a', L's', L't', L'-', L'w', L'e', L's', L't', L'_', L's', L't', L'a', L't', L'u', L's'};
static wchar_t* INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_CYBOI_NAME = INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice billing scale xdt field cyboi name. */
static wchar_t INVOICE_BILLING_SCALE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L's', L'c', L'a', L'l', L'e'};
static wchar_t* INVOICE_BILLING_SCALE_XDT_FIELD_CYBOI_NAME = INVOICE_BILLING_SCALE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_BILLING_SCALE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice billing area xdt field cyboi name. */
static wchar_t INVOICE_BILLING_AREA_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'a', L'r', L'e', L'a'};
static wchar_t* INVOICE_BILLING_AREA_XDT_FIELD_CYBOI_NAME = INVOICE_BILLING_AREA_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_BILLING_AREA_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral cause of pain xdt field cyboi name. */
static wchar_t REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'a', L'u', L's', L'e', L'_', L'o', L'f', L'_', L'p', L'a', L'i', L'n'};
static wchar_t* REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_CYBOI_NAME = REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_CAUSE_OF_PAIN_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral supposed accouchement date xdt field cyboi name. */
static wchar_t REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L's', L'u', L'p', L'p', L'o', L's', L'e', L'd', L'_', L'a', L'c', L'c', L'o', L'u', L'c', L'h', L'e', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'e'};
static wchar_t* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_CYBOI_NAME = REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral diagnosis xdt field cyboi name. */
static wchar_t REFERRAL_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'd', L'i', L'a', L'g', L'n', L'o', L's', L'i', L's'};
static wchar_t* REFERRAL_DIAGNOSIS_XDT_FIELD_CYBOI_NAME = REFERRAL_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral explanation xdt field cyboi name. */
static wchar_t REFERRAL_EXPLANATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'e', L'x', L'p', L'l', L'a', L'n', L'a', L't', L'i', L'o', L'n'};
static wchar_t* REFERRAL_EXPLANATION_XDT_FIELD_CYBOI_NAME = REFERRAL_EXPLANATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_EXPLANATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral check box muvo lsr xdt field cyboi name. */
static wchar_t REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'h', L'e', L'c', L'k', L'_', L'b', L'o', L'x', L'_', L'm', L'u', L'v', L'o', L'_', L'l', L's', L'r'};
static wchar_t* REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_CYBOI_NAME = REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral check box muvo hah xdt field cyboi name. */
static wchar_t REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'h', L'e', L'c', L'k', L'_', L'b', L'o', L'x', L'_', L'm', L'u', L'v', L'o', L'_', L'h', L'a', L'h'};
static wchar_t* REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_CYBOI_NAME = REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral check box ab0 rh xdt field cyboi name. */
static wchar_t REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'h', L'e', L'c', L'k', L'_', L'b', L'o', L'x', L'_', L'a', L'b', L'0', L'_', L'r', L'h'};
static wchar_t* REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_CYBOI_NAME = REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral check box ak xdt field cyboi name. */
static wchar_t REFERRAL_CHECK_BOX_AK_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'h', L'e', L'c', L'k', L'_', L'b', L'o', L'x', L'_', L'a', L'k'};
static wchar_t* REFERRAL_CHECK_BOX_AK_XDT_FIELD_CYBOI_NAME = REFERRAL_CHECK_BOX_AK_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_CHECK_BOX_AK_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral from physician number xdt field cyboi name. */
static wchar_t REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'f', L'r', L'o', L'm', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME = REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral to physician name xdt field cyboi name. */
static wchar_t REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L't', L'o', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME = REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The inpatient treatment referral by law xdt field cyboi name. */
static wchar_t INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'b', L'y', L'_', L'l', L'a', L'w'};
static wchar_t* INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_CYBOI_NAME = INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The inpatient treatment from to xdt field cyboi name. */
static wchar_t INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'f', L'r', L'o', L'm', L'_', L't', L'o'};
static wchar_t* INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_CYBOI_NAME = INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INPATIENT_TREATMENT_FROM_TO_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The inpatient treatment class xdt field cyboi name. */
static wchar_t INPATIENT_TREATMENT_CLASS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'c', L'l', L'a', L's', L's'};
static wchar_t* INPATIENT_TREATMENT_CLASS_XDT_FIELD_CYBOI_NAME = INPATIENT_TREATMENT_CLASS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INPATIENT_TREATMENT_CLASS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The inpatient hospital name xdt field cyboi name. */
static wchar_t INPATIENT_HOSPITAL_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'h', L'o', L's', L'p', L'i', L't', L'a', L'l', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* INPATIENT_HOSPITAL_NAME_XDT_FIELD_CYBOI_NAME = INPATIENT_HOSPITAL_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INPATIENT_HOSPITAL_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The inpatient hospital stay xdt field cyboi name. */
static wchar_t INPATIENT_HOSPITAL_STAY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'h', L'o', L's', L'p', L'i', L't', L'a', L'l', L'_', L's', L't', L'a', L'y'};
static wchar_t* INPATIENT_HOSPITAL_STAY_XDT_FIELD_CYBOI_NAME = INPATIENT_HOSPITAL_STAY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INPATIENT_HOSPITAL_STAY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The invoice sub category xdt field cyboi name. */
static wchar_t INVOICE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'i', L'n', L'v', L'o', L'i', L'c', L'e', L'_', L's', L'u', L'b', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y'};
static wchar_t* INVOICE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME = INVOICE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* INVOICE_SUB_CATEGORY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The emergency subsequent treatment physician name xdt field cyboi name. */
static wchar_t EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'e', L'm', L'e', L'r', L'g', L'e', L'n', L'c', L'y', L'_', L's', L'u', L'b', L's', L'e', L'q', L'u', L'e', L'n', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME = EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_45_INTEGER_MEMORY_MODEL_ARRAY;

/** The emergency findings xdt field cyboi name. */
static wchar_t EMERGENCY_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'e', L'm', L'e', L'r', L'g', L'e', L'n', L'c', L'y', L'_', L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's'};
static wchar_t* EMERGENCY_FINDINGS_XDT_FIELD_CYBOI_NAME = EMERGENCY_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* EMERGENCY_FINDINGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The emergency symptoms xdt field cyboi name. */
static wchar_t EMERGENCY_SYMPTOMS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'e', L'm', L'e', L'r', L'g', L'e', L'n', L'c', L'y', L'_', L's', L'y', L'm', L'p', L't', L'o', L'm', L's'};
static wchar_t* EMERGENCY_SYMPTOMS_XDT_FIELD_CYBOI_NAME = EMERGENCY_SYMPTOMS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* EMERGENCY_SYMPTOMS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident date xdt field cyboi name. */
static wchar_t ACCIDENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'd', L'a', L't', L'e'};
static wchar_t* ACCIDENT_DATE_XDT_FIELD_CYBOI_NAME = ACCIDENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident time xdt field cyboi name. */
static wchar_t ACCIDENT_TIME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L't', L'i', L'm', L'e'};
static wchar_t* ACCIDENT_TIME_XDT_FIELD_CYBOI_NAME = ACCIDENT_TIME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_TIME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient admission in practice date xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'd', L'm', L'i', L's', L's', L'i', L'o', L'n', L'_', L'i', L'n', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e', L'_', L'd', L'a', L't', L'e'};
static wchar_t* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient admission in practice time xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'a', L'd', L'm', L'i', L's', L's', L'i', L'o', L'n', L'_', L'i', L'n', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e', L'_', L't', L'i', L'm', L'e'};
static wchar_t* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient labour time begin xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'l', L'a', L'b', L'o', L'u', L'r', L'_', L't', L'i', L'm', L'e', L'_', L'b', L'e', L'g', L'i', L'n'};
static wchar_t* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident location xdt field cyboi name. */
static wchar_t ACCIDENT_LOCATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* ACCIDENT_LOCATION_XDT_FIELD_CYBOI_NAME = ACCIDENT_LOCATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_LOCATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient employment as xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'e', L'm', L'p', L'l', L'o', L'y', L'm', L'e', L'n', L't', L'_', L'a', L's'};
static wchar_t* ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient employment since xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'e', L'm', L'p', L'l', L'o', L'y', L'm', L'e', L'n', L't', L'_', L's', L'i', L'n', L'c', L'e'};
static wchar_t* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient nationality xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'n', L'a', L't', L'i', L'o', L'n', L'a', L'l', L'i', L't', L'y'};
static wchar_t* ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident company xdt field cyboi name. */
static wchar_t ACCIDENT_COMPANY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'c', L'o', L'm', L'p', L'a', L'n', L'y'};
static wchar_t* ACCIDENT_COMPANY_XDT_FIELD_CYBOI_NAME = ACCIDENT_COMPANY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_COMPANY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident course of events xdt field cyboi name. */
static wchar_t ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'c', L'o', L'u', L'r', L's', L'e', L'_', L'o', L'f', L'_', L'e', L'v', L'e', L'n', L't', L's'};
static wchar_t* ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_CYBOI_NAME = ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident patient behaviour afterwards xdt field cyboi name. */
static wchar_t ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'b', L'e', L'h', L'a', L'v', L'i', L'o', L'u', L'r', L'_', L'a', L'f', L't', L'e', L'r', L'w', L'a', L'r', L'd', L's'};
static wchar_t* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_CYBOI_NAME = ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_37_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident first time treatment date xdt field cyboi name. */
static wchar_t ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'f', L'i', L'r', L's', L't', L'_', L't', L'i', L'm', L'e', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'e'};
static wchar_t* ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME = ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident treatment by physician name xdt field cyboi name. */
static wchar_t ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'b', L'y', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME = ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident kind of treatment xdt field cyboi name. */
static wchar_t ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'k', L'i', L'n', L'd', L'_', L'o', L'f', L'_', L'f', L'i', L'r', L's', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't'};
static wchar_t* ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_CYBOI_NAME = ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_TREATMENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident alcohol influence xdt field cyboi name. */
static wchar_t ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L'l', L'c', L'o', L'h', L'o', L'l', L'_', L'i', L'n', L'f', L'l', L'u', L'e', L'n', L'c', L'e'};
static wchar_t* ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME = ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident signs for alcohol influence xdt field cyboi name. */
static wchar_t ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L's', L'i', L'g', L'n', L's', L'_', L'f', L'o', L'r', L'_', L'a', L'l', L'c', L'o', L'h', L'o', L'l', L'_', L'i', L'n', L'f', L'l', L'u', L'e', L'n', L'c', L'e'};
static wchar_t* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME = ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident blood withdrawal xdt field cyboi name. */
static wchar_t ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'b', L'l', L'o', L'o', L'd', L'_', L'w', L'i', L't', L'h', L'd', L'r', L'a', L'w', L'a', L'l'};
static wchar_t* ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_CYBOI_NAME = ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident findings xdt field cyboi name. */
static wchar_t ACCIDENT_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's'};
static wchar_t* ACCIDENT_FINDINGS_XDT_FIELD_CYBOI_NAME = ACCIDENT_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_FINDINGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident x-ray result xdt field cyboi name. */
static wchar_t ACCIDENT_X_RAY_RESULT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'x', L'-', L'r', L'a', L'y', L'_', L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* ACCIDENT_X_RAY_RESULT_XDT_FIELD_CYBOI_NAME = ACCIDENT_X_RAY_RESULT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_X_RAY_RESULT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident kind of first treatment xdt field cyboi name. */
static wchar_t ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'k', L'i', L'n', L'd', L'_', L'o', L'f', L'_', L'f', L'i', L'r', L's', L't', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't'};
static wchar_t* ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_CYBOI_NAME = ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident abnormal changes independent from accident xdt field cyboi name. */
static wchar_t ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L'b', L'n', L'o', L'r', L'm', L'a', L'l', L'_', L'c', L'h', L'a', L'n', L'g', L'e', L's', L'_', L'i', L'n', L'd', L'e', L'p', L'e', L'n', L'd', L'e', L'n', L't', L'_', L'f', L'r', L'o', L'm', L'_', L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't'};
static wchar_t* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_CYBOI_NAME = ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident concerns against statements xdt field cyboi name. */
static wchar_t ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'c', L'o', L'n', L'c', L'e', L'r', L'n', L's', L'_', L'a', L'g', L'a', L'i', L'n', L's', L't', L'_', L's', L't', L'a', L't', L'e', L'm', L'e', L'n', L't', L's'};
static wchar_t* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME = ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_36_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident kind of concerns against statements xdt field cyboi name. */
static wchar_t ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'k', L'i', L'n', L'd', L'_', L'o', L'f', L'_', L'c', L'o', L'n', L'c', L'e', L'r', L'n', L's', L'_', L'a', L'g', L'a', L'i', L'n', L's', L't', L'_', L's', L't', L'a', L't', L'e', L'm', L'e', L'n', L't', L's'};
static wchar_t* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME = ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_44_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident concerns against classification as accident at work xdt field cyboi name. */
static wchar_t ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'c', L'o', L'n', L'c', L'e', L'r', L'n', L's', L'_', L'a', L'g', L'a', L'i', L'n', L's', L't', L'_', L'c', L'l', L'a', L's', L's', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'_', L'a', L's', L'_', L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L't', L'_', L'w', L'o', L'r', L'k'};
static wchar_t* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME = ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident kind of concerns against classification as accident at work xdt field cyboi name. */
static wchar_t ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'k', L'i', L'n', L'd', L'_', L'o', L'f', L'_', L'c', L'o', L'n', L'c', L'e', L'r', L'n', L's', L'_', L'a', L'g', L'a', L'i', L'n', L's', L't', L'_', L'c', L'l', L'a', L's', L's', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'_', L'a', L's', L'_', L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L't', L'_', L'w', L'o', L'r', L'k'};
static wchar_t* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME = ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident able to work xdt field cyboi name. */
static wchar_t ACCIDENT_ABLE_TO_WORK_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L'b', L'l', L'e', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k'};
static wchar_t* ACCIDENT_ABLE_TO_WORK_XDT_FIELD_CYBOI_NAME = ACCIDENT_ABLE_TO_WORK_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_ABLE_TO_WORK_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident able to work from xdt field cyboi name. */
static wchar_t ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L'b', L'l', L'e', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k', L'_', L'f', L'r', L'o', L'm'};
static wchar_t* ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME = ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident unable to work certificate issuance xdt field cyboi name. */
static wchar_t ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'u', L'n', L'a', L'b', L'l', L'e', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k', L'_', L'c', L'e', L'r', L't', L'i', L'f', L'i', L'c', L'a', L't', L'e', L'_', L'i', L's', L's', L'u', L'a', L'n', L'c', L'e'};
static wchar_t* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_XDT_FIELD_CYBOI_NAME = ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_44_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident special curative treatment necessary xdt field cyboi name. */
static wchar_t ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L's', L'p', L'e', L'c', L'i', L'a', L'l', L'_', L'c', L'u', L'r', L'a', L't', L'i', L'v', L'e', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'n', L'e', L'c', L'e', L's', L's', L'a', L'r', L'y'};
static wchar_t* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_CYBOI_NAME = ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_45_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident special curative treatment by xdt field cyboi name. */
static wchar_t ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L's', L'p', L'e', L'c', L'i', L'a', L'l', L'_', L'c', L'u', L'r', L'a', L't', L'i', L'v', L'e', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'b', L'y'};
static wchar_t* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME = ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident address of treating physician xdt field cyboi name. */
static wchar_t ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'a', L'd', L'd', L'r', L'e', L's', L's', L'_', L'o', L'f', L'_', L't', L'r', L'e', L'a', L't', L'i', L'n', L'g', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n'};
static wchar_t* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_CYBOI_NAME = ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident unable to work from xdt field cyboi name. */
static wchar_t ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'u', L'n', L'a', L'b', L'l', L'e', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k', L'_', L'f', L'r', L'o', L'm'};
static wchar_t* ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME = ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident expected duration of inability to work xdt field cyboi name. */
static wchar_t ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'e', L'x', L'p', L'e', L'c', L't', L'e', L'd', L'_', L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'_', L'o', L'f', L'_', L'i', L'n', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k'};
static wchar_t* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_CYBOI_NAME = ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_47_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident kind of bill xdt field cyboi name. */
static wchar_t ACCIDENT_KIND_OF_BILL_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'k', L'i', L'n', L'd', L'_', L'o', L'f', L'_', L'b', L'i', L'l', L'l'};
static wchar_t* ACCIDENT_KIND_OF_BILL_XDT_FIELD_CYBOI_NAME = ACCIDENT_KIND_OF_BILL_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_KIND_OF_BILL_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident general curative treatment by xdt field cyboi name. */
static wchar_t ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'g', L'e', L'n', L'e', L'r', L'a', L'l', L'_', L'c', L'u', L'r', L'a', L't', L'i', L'v', L'e', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'b', L'y'};
static wchar_t* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME = ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident unable to work for longer than three days xdt field cyboi name. */
static wchar_t ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'u', L'n', L'a', L'b', L'l', L'e', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k', L'_', L'f', L'o', L'r', L'_', L'l', L'o', L'n', L'g', L'e', L'r', L'_', L't', L'h', L'a', L'n', L'_', L't', L'h', L'r', L'e', L'e', L'_', L'd', L'a', L'y', L's'};
static wchar_t* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_CYBOI_NAME = ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident unability to work certified until xdt field cyboi name. */
static wchar_t ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'u', L'n', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L't', L'o', L'_', L'w', L'o', L'r', L'k', L'_', L'c', L'e', L'r', L't', L'i', L'f', L'i', L'e', L'd', L'_', L'u', L'n', L't', L'i', L'l'};
static wchar_t* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_CYBOI_NAME = ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

/** The accident inspection required on xdt field cyboi name. */
static wchar_t ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'a', L'c', L'c', L'i', L'd', L'e', L'n', L't', L'_', L'i', L'n', L's', L'p', L'e', L'c', L't', L'i', L'o', L'n', L'_', L'r', L'e', L'q', L'u', L'i', L'r', L'e', L'd', L'_', L'o', L'n'};
static wchar_t* ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_CYBOI_NAME = ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing number xdt field cyboi name. */
static wchar_t BILLING_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* BILLING_NUMBER_XDT_FIELD_CYBOI_NAME = BILLING_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing address xdt field cyboi name. */
static wchar_t BILLING_ADDRESS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'a', L'd', L'd', L'r', L'e', L's', L's'};
static wchar_t* BILLING_ADDRESS_XDT_FIELD_CYBOI_NAME = BILLING_ADDRESS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_ADDRESS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing referring physician name xdt field cyboi name. */
static wchar_t BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'r', L'e', L'f', L'e', L'r', L'r', L'i', L'n', L'g', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME = BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing date xdt field cyboi name. */
static wchar_t BILLING_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'd', L'a', L't', L'e'};
static wchar_t* BILLING_DATE_XDT_FIELD_CYBOI_NAME = BILLING_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing total sum xdt field cyboi name. */
static wchar_t BILLING_TOTAL_SUM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L't', L'o', L't', L'a', L'l', L'_', L's', L'u', L'm'};
static wchar_t* BILLING_TOTAL_SUM_XDT_FIELD_CYBOI_NAME = BILLING_TOTAL_SUM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_TOTAL_SUM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing assignment declaration xdt field cyboi name. */
static wchar_t BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'a', L's', L's', L'i', L'g', L'n', L'm', L'e', L'n', L't', L'_', L'd', L'e', L'c', L'l', L'a', L'r', L'a', L't', L'i', L'o', L'n'};
static wchar_t* BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_CYBOI_NAME = BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing physician sub account xdt field cyboi name. */
static wchar_t BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L's', L'u', L'b', L'_', L'a', L'c', L'c', L'o', L'u', L'n', L't'};
static wchar_t* BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_CYBOI_NAME = BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing attachment xdt field cyboi name. */
static wchar_t BILLING_ATTACHMENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'a', L't', L't', L'a', L'c', L'h', L'm', L'e', L'n', L't'};
static wchar_t* BILLING_ATTACHMENT_XDT_FIELD_CYBOI_NAME = BILLING_ATTACHMENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_ATTACHMENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing header xdt field cyboi name. */
static wchar_t BILLING_HEADER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'h', L'e', L'a', L'd', L'e', L'r'};
static wchar_t* BILLING_HEADER_XDT_FIELD_CYBOI_NAME = BILLING_HEADER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_HEADER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing footer xdt field cyboi name. */
static wchar_t BILLING_FOOTER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'f', L'o', L'o', L't', L'e', L'r'};
static wchar_t* BILLING_FOOTER_XDT_FIELD_CYBOI_NAME = BILLING_FOOTER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_FOOTER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The service treatment date xdt field cyboi name. */
static wchar_t SERVICE_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'e'};
static wchar_t* SERVICE_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME = SERVICE_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_TREATMENT_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The service gnr identification xdt field cyboi name. */
static wchar_t SERVICE_GNR_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'g', L'n', L'r', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* SERVICE_GNR_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = SERVICE_GNR_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_GNR_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The service kind of examination xdt field cyboi name. */
static wchar_t SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'k', L'i', L'n', L'd', L'_', L'o', L'f', L'_', L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n'};
static wchar_t* SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_CYBOI_NAME = SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_KIND_OF_EXAMINATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The service addressee xdt field cyboi name. */
static wchar_t SERVICE_ADDRESSEE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'a', L'd', L'd', L'r', L'e', L's', L's', L'e', L'e'};
static wchar_t* SERVICE_ADDRESSEE_XDT_FIELD_CYBOI_NAME = SERVICE_ADDRESSEE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_ADDRESSEE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The service distance in kilometres xdt field cyboi name. */
static wchar_t SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'd', L'i', L's', L't', L'a', L'n', L'c', L'e', L'_', L'i', L'n', L'_', L'k', L'i', L'l', L'o', L'm', L'e', L't', L'r', L'e', L's'};
static wchar_t* SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_CYBOI_NAME = SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The service multiplier xdt field cyboi name. */
static wchar_t SERVICE_MULTIPLIER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'm', L'u', L'l', L't', L'i', L'p', L'l', L'i', L'e', L'r'};
static wchar_t* SERVICE_MULTIPLIER_XDT_FIELD_CYBOI_NAME = SERVICE_MULTIPLIER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_MULTIPLIER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The service time xdt field cyboi name. */
static wchar_t SERVICE_TIME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L't', L'i', L'm', L'e'};
static wchar_t* SERVICE_TIME_XDT_FIELD_CYBOI_NAME = SERVICE_TIME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_TIME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The service order-execution time xdt field cyboi name. */
static wchar_t SERVICE_ORDER_EXECUTION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'o', L'r', L'd', L'e', L'r', L'-', L'e', L'x', L'e', L'c', L'u', L't', L'i', L'o', L'n', L'_', L't', L'i', L'm', L'e'};
static wchar_t* SERVICE_ORDER_EXECUTION_XDT_FIELD_CYBOI_NAME = SERVICE_ORDER_EXECUTION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_ORDER_EXECUTION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The service dkm xdt field cyboi name. */
static wchar_t SERVICE_DKM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'd', L'k', L'm'};
static wchar_t* SERVICE_DKM_XDT_FIELD_CYBOI_NAME = SERVICE_DKM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_DKM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The service free explanatory statement xdt field cyboi name. */
static wchar_t SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'f', L'r', L'e', L'e', L'_', L'e', L'x', L'p', L'l', L'a', L'n', L'a', L't', L'o', L'r', L'y', L'_', L's', L't', L'a', L't', L'e', L'm', L'e', L'n', L't'};
static wchar_t* SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_CYBOI_NAME = SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The service explanatory drug xdt field cyboi name. */
static wchar_t SERVICE_EXPLANATORY_DRUG_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'e', L'x', L'p', L'l', L'a', L'n', L'a', L't', L'o', L'r', L'y', L'_', L'd', L'r', L'u', L'g'};
static wchar_t* SERVICE_EXPLANATORY_DRUG_XDT_FIELD_CYBOI_NAME = SERVICE_EXPLANATORY_DRUG_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_EXPLANATORY_DRUG_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The service material costs description xdt field cyboi name. */
static wchar_t SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'm', L'a', L't', L'e', L'r', L'i', L'a', L'l', L'_', L'c', L'o', L's', L't', L's', L'_', L'd', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_CYBOI_NAME = SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The service material costs dpf xdt field cyboi name. */
static wchar_t SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'm', L'a', L't', L'e', L'r', L'i', L'a', L'l', L'_', L'c', L'o', L's', L't', L's', L'_', L'd', L'p', L'f'};
static wchar_t* SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_CYBOI_NAME = SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The service percent of treatment xdt field cyboi name. */
static wchar_t SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'p', L'e', L'r', L'c', L'e', L'n', L't', L'_', L'o', L'f', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't'};
static wchar_t* SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_CYBOI_NAME = SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The service organ xdt field cyboi name. */
static wchar_t SERVICE_ORGAN_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'o', L'r', L'g', L'a', L'n'};
static wchar_t* SERVICE_ORGAN_XDT_FIELD_CYBOI_NAME = SERVICE_ORGAN_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_ORGAN_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The service location xdt field cyboi name. */
static wchar_t SERVICE_LOCATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* SERVICE_LOCATION_XDT_FIELD_CYBOI_NAME = SERVICE_LOCATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_LOCATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The service zone xdt field cyboi name. */
static wchar_t SERVICE_ZONE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'z', L'o', L'n', L'e'};
static wchar_t* SERVICE_ZONE_XDT_FIELD_CYBOI_NAME = SERVICE_ZONE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_ZONE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The service gnr description xdt field cyboi name. */
static wchar_t SERVICE_GNR_DESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'g', L'n', L'r', L'_', L'd', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* SERVICE_GNR_DESCRIPTION_XDT_FIELD_CYBOI_NAME = SERVICE_GNR_DESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_GNR_DESCRIPTION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The service fee xdt field cyboi name. */
static wchar_t SERVICE_FEE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'f', L'e', L'e'};
static wchar_t* SERVICE_FEE_XDT_FIELD_CYBOI_NAME = SERVICE_FEE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_FEE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The service factor xdt field cyboi name. */
static wchar_t SERVICE_FACTOR_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'f', L'a', L'c', L't', L'o', L'r'};
static wchar_t* SERVICE_FACTOR_XDT_FIELD_CYBOI_NAME = SERVICE_FACTOR_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_FACTOR_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The service sum xdt field cyboi name. */
static wchar_t SERVICE_SUM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L's', L'u', L'm'};
static wchar_t* SERVICE_SUM_XDT_FIELD_CYBOI_NAME = SERVICE_SUM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_SUM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The service total sum xdt field cyboi name. */
static wchar_t SERVICE_TOTAL_SUM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L't', L'o', L't', L'a', L'l', L'_', L's', L'u', L'm'};
static wchar_t* SERVICE_TOTAL_SUM_XDT_FIELD_CYBOI_NAME = SERVICE_TOTAL_SUM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_TOTAL_SUM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The service point value xdt field cyboi name. */
static wchar_t SERVICE_POINT_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'p', L'o', L'i', L'n', L't', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* SERVICE_POINT_VALUE_XDT_FIELD_CYBOI_NAME = SERVICE_POINT_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_POINT_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The service name of fee xdt field cyboi name. */
static wchar_t SERVICE_NAME_OF_FEE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'n', L'a', L'm', L'e', L'_', L'o', L'f', L'_', L'f', L'e', L'e'};
static wchar_t* SERVICE_NAME_OF_FEE_XDT_FIELD_CYBOI_NAME = SERVICE_NAME_OF_FEE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_NAME_OF_FEE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The service name of certificate xdt field cyboi name. */
static wchar_t SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'i', L'c', L'e', L'_', L'n', L'a', L'm', L'e', L'_', L'o', L'f', L'_', L'c', L'e', L'r', L't', L'i', L'f', L'i', L'c', L'a', L't', L'e'};
static wchar_t* SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_CYBOI_NAME = SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing diagnosis xdt field cyboi name. */
static wchar_t BILLING_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'd', L'i', L'a', L'g', L'n', L'o', L's', L'i', L's'};
static wchar_t* BILLING_DIAGNOSIS_XDT_FIELD_CYBOI_NAME = BILLING_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The billing icd key xdt field cyboi name. */
static wchar_t BILLING_ICD_KEY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'b', L'i', L'l', L'l', L'i', L'n', L'g', L'_', L'i', L'c', L'd', L'_', L'k', L'e', L'y'};
static wchar_t* BILLING_ICD_KEY_XDT_FIELD_CYBOI_NAME = BILLING_ICD_KEY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* BILLING_ICD_KEY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment data collection date xdt field cyboi name. */
static wchar_t TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'a', L'_', L'c', L'o', L'l', L'l', L'e', L'c', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME = TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment data collection time xdt field cyboi name. */
static wchar_t TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'a', L'_', L'c', L'o', L'l', L'l', L'e', L'c', L't', L'i', L'o', L'n', L'_', L't', L'i', L'm', L'e'};
static wchar_t* TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME = TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment current diagnosis xdt field cyboi name. */
static wchar_t TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'c', L'u', L'r', L'r', L'e', L'n', L't', L'_', L'd', L'i', L'a', L'g', L'n', L'o', L's', L'i', L's'};
static wchar_t* TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_CYBOI_NAME = TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment drug prescribed with prescription xdt field cyboi name. */
static wchar_t TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'r', L'u', L'g', L'_', L'p', L'r', L'e', L's', L'c', L'r', L'i', L'b', L'e', L'd', L'_', L'w', L'i', L't', L'h', L'_', L'p', L'r', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_CYBOI_NAME = TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment drug prescribed without prescription xdt field cyboi name. */
static wchar_t TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'r', L'u', L'g', L'_', L'p', L'r', L'e', L's', L'c', L'r', L'i', L'b', L'e', L'd', L'_', L'w', L'i', L't', L'h', L'o', L'u', L't', L'_', L'p', L'r', L'e', L's', L'c', L'r', L'i', L'p', L't', L'i', L'o', L'n'};
static wchar_t* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_CYBOI_NAME = TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_46_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment physician sample xdt field cyboi name. */
static wchar_t TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L's', L'a', L'm', L'p', L'l', L'e'};
static wchar_t* TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_CYBOI_NAME = TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment findings xdt field cyboi name. */
static wchar_t TREATMENT_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's'};
static wchar_t* TREATMENT_FINDINGS_XDT_FIELD_CYBOI_NAME = TREATMENT_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_FINDINGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment external findings xdt field cyboi name. */
static wchar_t TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'e', L'x', L't', L'e', L'r', L'n', L'a', L'l', L'_', L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's'};
static wchar_t* TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_CYBOI_NAME = TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment laboratory findings xdt field cyboi name. */
static wchar_t TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'l', L'a', L'b', L'o', L'r', L'a', L't', L'o', L'r', L'y', L'_', L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's'};
static wchar_t* TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_CYBOI_NAME = TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_LABORATORY_FINDINGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment x-ray findings xdt field cyboi name. */
static wchar_t TREATMENT_X_RAY_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'x', L'-', L'r', L'a', L'y', L'_', L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's'};
static wchar_t* TREATMENT_X_RAY_FINDINGS_XDT_FIELD_CYBOI_NAME = TREATMENT_X_RAY_FINDINGS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_X_RAY_FINDINGS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment subsequent line count xdt field cyboi name. */
static wchar_t TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L's', L'u', L'b', L's', L'e', L'q', L'u', L'e', L'n', L't', L'_', L'l', L'i', L'n', L'e', L'_', L'c', L'o', L'u', L'n', L't'};
static wchar_t* TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_CYBOI_NAME = TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment comment xdt field cyboi name. */
static wchar_t TREATMENT_COMMENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'c', L'o', L'm', L'm', L'e', L'n', L't'};
static wchar_t* TREATMENT_COMMENT_XDT_FIELD_CYBOI_NAME = TREATMENT_COMMENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_COMMENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment formatted result table text xdt field cyboi name. */
static wchar_t TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'f', L'o', L'r', L'm', L'a', L't', L't', L'e', L'd', L'_', L'r', L'e', L's', L'u', L'l', L't', L'_', L't', L'a', L'b', L'l', L'e', L'_', L't', L'e', L'x', L't'};
static wchar_t* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_CYBOI_NAME = TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_37_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment blood pressure xdt field cyboi name. */
static wchar_t TREATMENT_BLOOD_PRESSURE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'b', L'l', L'o', L'o', L'd', L'_', L'p', L'r', L'e', L's', L's', L'u', L'r', L'e'};
static wchar_t* TREATMENT_BLOOD_PRESSURE_XDT_FIELD_CYBOI_NAME = TREATMENT_BLOOD_PRESSURE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_BLOOD_PRESSURE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment symptoms xdt field cyboi name. */
static wchar_t TREATMENT_SYMPTOMS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L's', L'y', L'm', L'p', L't', L'o', L'm', L's'};
static wchar_t* TREATMENT_SYMPTOMS_XDT_FIELD_CYBOI_NAME = TREATMENT_SYMPTOMS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_SYMPTOMS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment therapy xdt field cyboi name. */
static wchar_t TREATMENT_THERAPY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L't', L'h', L'e', L'r', L'a', L'p', L'y'};
static wchar_t* TREATMENT_THERAPY_XDT_FIELD_CYBOI_NAME = TREATMENT_THERAPY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_THERAPY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment physical therapy xdt field cyboi name. */
static wchar_t TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'a', L'l', L'_', L't', L'h', L'e', L'r', L'a', L'p', L'y'};
static wchar_t* TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_CYBOI_NAME = TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_PHYSICAL_THERAPY_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment referral content xdt field cyboi name. */
static wchar_t TREATMENT_REFERRAL_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* TREATMENT_REFERRAL_CONTENT_XDT_FIELD_CYBOI_NAME = TREATMENT_REFERRAL_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_REFERRAL_CONTENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment work disability duration xdt field cyboi name. */
static wchar_t TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'w', L'o', L'r', L'k', L'_', L'd', L'i', L's', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n'};
static wchar_t* TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_CYBOI_NAME = TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment work disability cause xdt field cyboi name. */
static wchar_t TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'w', L'o', L'r', L'k', L'_', L'd', L'i', L's', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L'c', L'a', L'u', L's', L'e'};
static wchar_t* TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_CYBOI_NAME = TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment hospitalisation xdt field cyboi name. */
static wchar_t TREATMENT_HOSPITALISATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'h', L'o', L's', L'p', L'i', L't', L'a', L'l', L'i', L's', L'a', L't', L'i', L'o', L'n'};
static wchar_t* TREATMENT_HOSPITALISATION_XDT_FIELD_CYBOI_NAME = TREATMENT_HOSPITALISATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_HOSPITALISATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The treatment hospitalisation cause xdt field cyboi name. */
static wchar_t TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'h', L'o', L's', L'p', L'i', L't', L'a', L'l', L'i', L's', L'a', L't', L'i', L'o', L'n', L'_', L'c', L'a', L'u', L's', L'e'};
static wchar_t* TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_CYBOI_NAME = TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter certificate kind xdt field cyboi name. */
static wchar_t LETTER_CERTIFICATE_KIND_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'c', L'e', L'r', L't', L'i', L'f', L'i', L'c', L'a', L't', L'e', L'_', L'k', L'i', L'n', L'd'};
static wchar_t* LETTER_CERTIFICATE_KIND_XDT_FIELD_CYBOI_NAME = LETTER_CERTIFICATE_KIND_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_CERTIFICATE_KIND_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter certificate content xdt field cyboi name. */
static wchar_t LETTER_CERTIFICATE_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'c', L'e', L'r', L't', L'i', L'f', L'i', L'c', L'a', L't', L'e', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* LETTER_CERTIFICATE_CONTENT_XDT_FIELD_CYBOI_NAME = LETTER_CERTIFICATE_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_CERTIFICATE_CONTENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter file archive number xdt field cyboi name. */
static wchar_t LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'f', L'i', L'l', L'e', L'_', L'a', L'r', L'c', L'h', L'i', L'v', L'e', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME = LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter file format xdt field cyboi name. */
static wchar_t LETTER_FILE_FORMAT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'f', L'i', L'l', L'e', L'_', L'f', L'o', L'r', L'm', L'a', L't'};
static wchar_t* LETTER_FILE_FORMAT_XDT_FIELD_CYBOI_NAME = LETTER_FILE_FORMAT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_FILE_FORMAT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter file content xdt field cyboi name. */
static wchar_t LETTER_FILE_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'f', L'i', L'l', L'e', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* LETTER_FILE_CONTENT_XDT_FIELD_CYBOI_NAME = LETTER_FILE_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_FILE_CONTENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter file url xdt field cyboi name. */
static wchar_t LETTER_FILE_URL_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'f', L'i', L'l', L'e', L'_', L'u', L'r', L'l'};
static wchar_t* LETTER_FILE_URL_XDT_FIELD_CYBOI_NAME = LETTER_FILE_URL_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_FILE_URL_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter attestation kind xdt field cyboi name. */
static wchar_t LETTER_ATTESTATION_KIND_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'a', L't', L't', L'e', L's', L't', L'a', L't', L'i', L'o', L'n', L'_', L'k', L'i', L'n', L'd'};
static wchar_t* LETTER_ATTESTATION_KIND_XDT_FIELD_CYBOI_NAME = LETTER_ATTESTATION_KIND_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_ATTESTATION_KIND_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter attestation content xdt field cyboi name. */
static wchar_t LETTER_ATTESTATION_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'a', L't', L't', L'e', L's', L't', L'a', L't', L'i', L'o', L'n', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* LETTER_ATTESTATION_CONTENT_XDT_FIELD_CYBOI_NAME = LETTER_ATTESTATION_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_ATTESTATION_CONTENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter addressee xdt field cyboi name. */
static wchar_t LETTER_ADDRESSEE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'a', L'd', L'd', L'r', L'e', L's', L's', L'e', L'e'};
static wchar_t* LETTER_ADDRESSEE_XDT_FIELD_CYBOI_NAME = LETTER_ADDRESSEE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_ADDRESSEE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter salutation xdt field cyboi name. */
static wchar_t LETTER_SALUTATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L's', L'a', L'l', L'u', L't', L'a', L't', L'i', L'o', L'n'};
static wchar_t* LETTER_SALUTATION_XDT_FIELD_CYBOI_NAME = LETTER_SALUTATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_SALUTATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter street xdt field cyboi name. */
static wchar_t LETTER_STREET_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L's', L't', L'r', L'e', L'e', L't'};
static wchar_t* LETTER_STREET_XDT_FIELD_CYBOI_NAME = LETTER_STREET_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_STREET_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter postcode xdt field cyboi name. */
static wchar_t LETTER_POSTCODE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'p', L'o', L's', L't', L'c', L'o', L'd', L'e'};
static wchar_t* LETTER_POSTCODE_XDT_FIELD_CYBOI_NAME = LETTER_POSTCODE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_POSTCODE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter residence xdt field cyboi name. */
static wchar_t LETTER_RESIDENCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'r', L'e', L's', L'i', L'd', L'e', L'n', L'c', L'e'};
static wchar_t* LETTER_RESIDENCE_XDT_FIELD_CYBOI_NAME = LETTER_RESIDENCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_RESIDENCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter complimentary close xdt field cyboi name. */
static wchar_t LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'c', L'o', L'm', L'p', L'l', L'i', L'm', L'e', L'n', L't', L'a', L'r', L'y', L'_', L'c', L'l', L'o', L's', L'e'};
static wchar_t* LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME = LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter phone xdt field cyboi name. */
static wchar_t LETTER_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'p', L'h', L'o', L'n', L'e'};
static wchar_t* LETTER_PHONE_XDT_FIELD_CYBOI_NAME = LETTER_PHONE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_PHONE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter fax xdt field cyboi name. */
static wchar_t LETTER_FAX_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'f', L'a', L'x'};
static wchar_t* LETTER_FAX_XDT_FIELD_CYBOI_NAME = LETTER_FAX_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_FAX_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter physician number xdt field cyboi name. */
static wchar_t LETTER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* LETTER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME = LETTER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter content xdt field cyboi name. */
static wchar_t LETTER_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* LETTER_CONTENT_XDT_FIELD_CYBOI_NAME = LETTER_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_CONTENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter image archive number xdt field cyboi name. */
static wchar_t LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'i', L'm', L'a', L'g', L'e', L'_', L'a', L'r', L'c', L'h', L'i', L'v', L'e', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME = LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter graphic format xdt field cyboi name. */
static wchar_t LETTER_GRAPHIC_FORMAT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'g', L'r', L'a', L'p', L'h', L'i', L'c', L'_', L'f', L'o', L'r', L'm', L'a', L't'};
static wchar_t* LETTER_GRAPHIC_FORMAT_XDT_FIELD_CYBOI_NAME = LETTER_GRAPHIC_FORMAT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_GRAPHIC_FORMAT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The letter image content xdt field cyboi name. */
static wchar_t LETTER_IMAGE_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'l', L'e', L't', L't', L'e', L'r', L'_', L'i', L'm', L'a', L'g', L'e', L'_', L'c', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* LETTER_IMAGE_CONTENT_XDT_FIELD_CYBOI_NAME = LETTER_IMAGE_CONTENT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* LETTER_IMAGE_CONTENT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 1 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 1 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 2 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 2 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 3 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 3 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 4 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 4 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 5 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 5 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 6 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'6', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 6 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'6', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 7 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'7', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 7 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'7', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 8 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'8', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 8 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'8', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 9 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'9', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 9 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'9', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 10 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'0', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 10 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'0', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 11 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 11 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 12 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 12 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 13 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 13 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 14 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 14 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 15 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 15 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 16 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'6', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 16 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'6', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 17 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'7', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 17 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'7', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 18 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'8', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 18 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'8', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 19 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'9', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 19 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'1', L'9', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 20 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'0', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 20 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'0', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 21 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 21 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 22 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 22 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 23 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 23 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 24 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 24 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 25 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 25 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 26 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'6', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 26 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'6', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 27 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'7', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 27 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'7', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 28 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'8', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 28 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'8', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 29 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'9', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 29 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'2', L'9', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 30 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'0', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 30 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'0', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 31 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'1', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 31 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'1', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 32 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'2', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 32 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'2', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 33 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'3', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 33 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'3', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 34 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'4', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 34 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'4', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 35 name xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'5', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The free record 6200 category 35 value xdt field cyboi name. */
static wchar_t FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'r', L'e', L'e', L'_', L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'6', L'2', L'0', L'0', L'_', L'c', L'a', L't', L'e', L'g', L'o', L'r', L'y', L'_', L'3', L'5', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_CYBOI_NAME = FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The record identification xdt field cyboi name. */
static wchar_t RECORD_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'c', L'o', L'r', L'd', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* RECORD_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = RECORD_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* RECORD_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The record size xdt field cyboi name. */
static wchar_t RECORD_SIZE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'r', L'e', L'c', L'o', L'r', L'd', L'_', L's', L'i', L'z', L'e'};
static wchar_t* RECORD_SIZE_XDT_FIELD_CYBOI_NAME = RECORD_SIZE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* RECORD_SIZE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The device receiver gdt id xdt field cyboi name. */
static wchar_t DEVICE_RECEIVER_GDT_ID_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'e', L'v', L'i', L'c', L'e', L'_', L'r', L'e', L'c', L'e', L'i', L'v', L'e', L'r', L'_', L'g', L'd', L't', L'_', L'i', L'd'};
static wchar_t* DEVICE_RECEIVER_GDT_ID_XDT_FIELD_CYBOI_NAME = DEVICE_RECEIVER_GDT_ID_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DEVICE_RECEIVER_GDT_ID_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The device sender gdt id xdt field cyboi name. */
static wchar_t DEVICE_SENDER_GDT_ID_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'e', L'v', L'i', L'c', L'e', L'_', L's', L'e', L'n', L'd', L'e', L'r', L'_', L'g', L'd', L't', L'_', L'i', L'd'};
static wchar_t* DEVICE_SENDER_GDT_ID_XDT_FIELD_CYBOI_NAME = DEVICE_SENDER_GDT_ID_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DEVICE_SENDER_GDT_ID_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings kind xdt field cyboi name. */
static wchar_t FINDINGS_KIND_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'k', L'i', L'n', L'd'};
static wchar_t* FINDINGS_KIND_XDT_FIELD_CYBOI_NAME = FINDINGS_KIND_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_KIND_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings device specifics xdt field cyboi name. */
static wchar_t FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'd', L'e', L'v', L'i', L'c', L'e', L'_', L's', L'p', L'e', L'c', L'i', L'f', L'i', L'c', L's'};
static wchar_t* FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_CYBOI_NAME = FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_DEVICE_SPECIFICS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings test identification xdt field cyboi name. */
static wchar_t FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L't', L'e', L's', L't', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_TEST_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings test name xdt field cyboi name. */
static wchar_t FINDINGS_TEST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L't', L'e', L's', L't', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FINDINGS_TEST_NAME_XDT_FIELD_CYBOI_NAME = FINDINGS_TEST_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_TEST_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings test status xdt field cyboi name. */
static wchar_t FINDINGS_TEST_STATUS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L't', L'e', L's', L't', L'_', L's', L't', L'a', L't', L'u', L's'};
static wchar_t* FINDINGS_TEST_STATUS_XDT_FIELD_CYBOI_NAME = FINDINGS_TEST_STATUS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_TEST_STATUS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings test result value xdt field cyboi name. */
static wchar_t FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L't', L'e', L's', L't', L'_', L'r', L'e', L's', L'u', L'l', L't', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_CYBOI_NAME = FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_TEST_RESULT_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings test result unit xdt field cyboi name. */
static wchar_t FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L't', L'e', L's', L't', L'_', L'r', L'e', L's', L'u', L'l', L't', L'_', L'u', L'n', L'i', L't'};
static wchar_t* FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_CYBOI_NAME = FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_TEST_RESULT_UNIT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings limit indicator xdt field cyboi name. */
static wchar_t FINDINGS_LIMIT_INDICATOR_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'l', L'i', L'm', L'i', L't', L'_', L'i', L'n', L'd', L'i', L'c', L'a', L't', L'o', L'r'};
static wchar_t* FINDINGS_LIMIT_INDICATOR_XDT_FIELD_CYBOI_NAME = FINDINGS_LIMIT_INDICATOR_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_LIMIT_INDICATOR_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample material identification xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'm', L'a', L't', L'e', L'r', L'i', L'a', L'l', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_39_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample material index xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'm', L'a', L't', L'e', L'r', L'i', L'a', L'l', L'_', L'i', L'n', L'd', L'e', L'x'};
static wchar_t* FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample material name xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'm', L'a', L't', L'e', L'r', L'i', L'a', L'l', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample material specification xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'm', L'a', L't', L'e', L'r', L'i', L'a', L'l', L'_', L's', L'p', L'e', L'c', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample collection date xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'c', L'o', L'l', L'l', L'e', L'c', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample collection time (old format) xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'c', L'o', L'l', L'l', L'e', L'c', L't', L'i', L'o', L'n', L'_', L't', L'i', L'm', L'e', L'_', L'o', L'l', L'd', L'_', L'f', L'o', L'r', L'm', L'a', L't'};
static wchar_t* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings data stream units xdt field cyboi name. */
static wchar_t FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'd', L'a', L't', L'a', L'_', L's', L't', L'r', L'e', L'a', L'm', L'_', L'u', L'n', L'i', L't', L's'};
static wchar_t* FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_CYBOI_NAME = FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_DATA_STREAM_UNITS_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings data stream xdt field cyboi name. */
static wchar_t FINDINGS_DATA_STREAM_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'd', L'a', L't', L'a', L'_', L's', L't', L'r', L'e', L'a', L'm'};
static wchar_t* FINDINGS_DATA_STREAM_XDT_FIELD_CYBOI_NAME = FINDINGS_DATA_STREAM_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_DATA_STREAM_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings sample collection time xdt field cyboi name. */
static wchar_t FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'a', L'm', L'p', L'l', L'e', L'_', L'c', L'o', L'l', L'l', L'e', L'c', L't', L'i', L'o', L'n', L'_', L't', L'i', L'm', L'e'};
static wchar_t* FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME = FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings germ identification xdt field cyboi name. */
static wchar_t FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'g', L'e', L'r', L'm', L'_', L'i', L'd', L'e', L'n', L't', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_CYBOI_NAME = FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_GERM_IDENTIFICATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings germ name xdt field cyboi name. */
static wchar_t FINDINGS_GERM_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'g', L'e', L'r', L'm', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FINDINGS_GERM_NAME_XDT_FIELD_CYBOI_NAME = FINDINGS_GERM_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_GERM_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings germ number xdt field cyboi name. */
static wchar_t FINDINGS_GERM_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'g', L'e', L'r', L'm', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* FINDINGS_GERM_NUMBER_XDT_FIELD_CYBOI_NAME = FINDINGS_GERM_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_GERM_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings resistance method xdt field cyboi name. */
static wchar_t FINDINGS_RESISTANCE_METHOD_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'r', L'e', L's', L'i', L's', L't', L'a', L'n', L'c', L'e', L'_', L'm', L'e', L't', L'h', L'o', L'd'};
static wchar_t* FINDINGS_RESISTANCE_METHOD_XDT_FIELD_CYBOI_NAME = FINDINGS_RESISTANCE_METHOD_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_RESISTANCE_METHOD_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings active substance xdt field cyboi name. */
static wchar_t FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'a', L'c', L't', L'i', L'v', L'e', L'_', L's', L'u', L'b', L's', L't', L'a', L'n', L'c', L'e'};
static wchar_t* FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_CYBOI_NAME = FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings active substance generic name xdt field cyboi name. */
static wchar_t FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'a', L'c', L't', L'i', L'v', L'e', L'_', L's', L'u', L'b', L's', L't', L'a', L'n', L'c', L'e', L'_', L'g', L'e', L'n', L'e', L'r', L'i', L'c', L'_', L'n', L'a', L'm', L'e'};
static wchar_t* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_CYBOI_NAME = FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_38_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings mhk breakpoint value xdt field cyboi name. */
static wchar_t FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'm', L'h', L'k', L'_', L'b', L'r', L'e', L'a', L'k', L'p', L'o', L'i', L'n', L't', L'_', L'v', L'a', L'l', L'u', L'e'};
static wchar_t* FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_CYBOI_NAME = FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_29_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings resistance interpretation xdt field cyboi name. */
static wchar_t FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'r', L'e', L's', L'i', L's', L't', L'a', L'n', L'c', L'e', L'_', L'i', L'n', L't', L'e', L'r', L'p', L'r', L'e', L't', L'a', L't', L'i', L'o', L'n'};
static wchar_t* FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_CYBOI_NAME = FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings normal value text xdt field cyboi name. */
static wchar_t FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'n', L'o', L'r', L'm', L'a', L'l', L'_', L'v', L'a', L'l', L'u', L'e', L'_', L't', L'e', L'x', L't'};
static wchar_t* FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_CYBOI_NAME = FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings normal value lower limit xdt field cyboi name. */
static wchar_t FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'n', L'o', L'r', L'm', L'a', L'l', L'_', L'v', L'a', L'l', L'u', L'e', L'_', L'l', L'o', L'w', L'e', L'r', L'_', L'l', L'i', L'm', L'i', L't'};
static wchar_t* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_CYBOI_NAME = FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings normal value upper limit xdt field cyboi name. */
static wchar_t FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'n', L'o', L'r', L'm', L'a', L'l', L'_', L'v', L'a', L'l', L'u', L'e', L'_', L'u', L'p', L'p', L'e', L'r', L'_', L'l', L'i', L'm', L'i', L't'};
static wchar_t* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_CYBOI_NAME = FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings remark xdt field cyboi name. */
static wchar_t FINDINGS_REMARK_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'r', L'e', L'm', L'a', L'r', L'k'};
static wchar_t* FINDINGS_REMARK_XDT_FIELD_CYBOI_NAME = FINDINGS_REMARK_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_REMARK_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings result text xdt field cyboi name. */
static wchar_t FINDINGS_RESULT_TEXT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'r', L'e', L's', L'u', L'l', L't', L'_', L't', L'e', L'x', L't'};
static wchar_t* FINDINGS_RESULT_TEXT_XDT_FIELD_CYBOI_NAME = FINDINGS_RESULT_TEXT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_RESULT_TEXT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings complimentary close xdt field cyboi name. */
static wchar_t FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L'c', L'o', L'm', L'p', L'l', L'i', L'm', L'e', L'n', L't', L'a', L'r', L'y', L'_', L'c', L'l', L'o', L's', L'e'};
static wchar_t* FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME = FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The findings signature xdt field cyboi name. */
static wchar_t FINDINGS_SIGNATURE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'f', L'i', L'n', L'd', L'i', L'n', L'g', L's', L'_', L's', L'i', L'g', L'n', L'a', L't', L'u', L'r', L'e'};
static wchar_t* FINDINGS_SIGNATURE_XDT_FIELD_CYBOI_NAME = FINDINGS_SIGNATURE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* FINDINGS_SIGNATURE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The data medium sender physician number xdt field cyboi name. */
static wchar_t DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L's', L'e', L'n', L'd', L'e', L'r', L'_', L'p', L'h', L'y', L's', L'i', L'c', L'i', L'a', L'n', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME = DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The data medium creation date xdt field cyboi name. */
static wchar_t DATA_MEDIUM_CREATION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'c', L'r', L'e', L'a', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* DATA_MEDIUM_CREATION_DATE_XDT_FIELD_CYBOI_NAME = DATA_MEDIUM_CREATION_DATE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_MEDIUM_CREATION_DATE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The data medium running number xdt field cyboi name. */
static wchar_t DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'r', L'u', L'n', L'n', L'i', L'n', L'g', L'_', L'n', L'u', L'm', L'b', L'e', L'r'};
static wchar_t* DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_CYBOI_NAME = DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The data medium character code xdt field cyboi name. */
static wchar_t DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L'_', L'c', L'o', L'd', L'e'};
static wchar_t* DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_CYBOI_NAME = DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package size xdt field cyboi name. */
static wchar_t DATA_PACKAGE_SIZE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L's', L'i', L'z', L'e'};
static wchar_t* DATA_PACKAGE_SIZE_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_SIZE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_SIZE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package mediums count xdt field cyboi name. */
static wchar_t DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L's', L'_', L'c', L'o', L'u', L'n', L't'};
static wchar_t* DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package character set xdt field cyboi name. */
static wchar_t DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L'_', L's', L'e', L't'};
static wchar_t* DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_CHARACTER_SET_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package adt version xdt field cyboi name. */
static wchar_t DATA_PACKAGE_ADT_VERSION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L'a', L'd', L't', L'_', L'v', L'e', L'r', L's', L'i', L'o', L'n'};
static wchar_t* DATA_PACKAGE_ADT_VERSION_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_ADT_VERSION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_ADT_VERSION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package bdt version xdt field cyboi name. */
static wchar_t DATA_PACKAGE_BDT_VERSION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L'b', L'd', L't', L'_', L'v', L'e', L'r', L's', L'i', L'o', L'n'};
static wchar_t* DATA_PACKAGE_BDT_VERSION_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_BDT_VERSION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_BDT_VERSION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package gdt version xdt field cyboi name. */
static wchar_t DATA_PACKAGE_GDT_VERSION_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L'g', L'd', L't', L'_', L'v', L'e', L'r', L's', L'i', L'o', L'n'};
static wchar_t* DATA_PACKAGE_GDT_VERSION_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_GDT_VERSION_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_GDT_VERSION_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package archiving type xdt field cyboi name. */
static wchar_t DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L'a', L'r', L'c', L'h', L'i', L'v', L'i', L'n', L'g', L'_', L't', L'y', L'p', L'e'};
static wchar_t* DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package storage period xdt field cyboi name. */
static wchar_t DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L's', L't', L'o', L'r', L'a', L'g', L'e', L'_', L'p', L'e', L'r', L'i', L'o', L'd'};
static wchar_t* DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The data package transfer begin xdt field cyboi name. */
static wchar_t DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'p', L'a', L'c', L'k', L'a', L'g', L'e', L'_', L't', L'r', L'a', L'n', L's', L'f', L'e', L'r', L'_', L'b', L'e', L'g', L'i', L'n'};
static wchar_t* DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_CYBOI_NAME = DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The system internal parameter xdt field cyboi name. */
static wchar_t SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_CYBOI_NAME_ARRAY[] = {L's', L'y', L's', L't', L'e', L'm', L'_', L'i', L'n', L't', L'e', L'r', L'n', L'a', L'l', L'_', L'p', L'a', L'r', L'a', L'm', L'e', L't', L'e', L'r'};
static wchar_t* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_CYBOI_NAME = SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_CYBOI_NAME_ARRAY;
static int* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_CYBOI_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/* XDT_FIELD_CYBOI_NAME_SOURCE */
#endif
