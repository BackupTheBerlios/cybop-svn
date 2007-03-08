/*
 * $RCSfile: bdt_field_constants.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2007-03-08 23:56:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BDT_FIELD_CONSTANTS_SOURCE
#define BDT_FIELD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer_constants.c"

/**
 * The bdt field size count.
 *
 * All bdt field sizes have the same length: 3 ASCII characters (bytes).
 */
static int* BDT_FIELD_SIZE_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The bdt field identification count.
 *
 * All bdt field identifications have the same length: 4 ASCII characters (bytes).
 */
static int* BDT_FIELD_IDENTIFICATION_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The kbv pruefnummer field.
 *
 * Size: 7
 * Type: integer
 * Rule: 007
 * Example: 9301001
 */
/*??
static char KBV_PRUEFNUMMER_BDT_FIELD_ARRAY[] = {'0', '1', '0', '1'};
static char* KBV_PRUEFNUMMER_BDT_FIELD = KBV_PRUEFNUMMER_BDT_FIELD_ARRAY;
*/
static int* KBV_PRUEFNUMMER_BDT_FIELD = NUMBER_101_INTEGER_ARRAY;

/**
 * The patient identification field.
 *
 * Size: <= 10
 * Type: integer
 * Rule: -
 * Example: 12345678
 */
/*??
static char PATIENT_IDENTIFICATION_BDT_FIELD_ARRAY[] = {'3', '0', '0', '0'};
static char* PATIENT_IDENTIFICATION_BDT_FIELD = PATIENT_IDENTIFICATION_BDT_FIELD_ARRAY;
*/
static int* PATIENT_IDENTIFICATION_BDT_FIELD = NUMBER_3000_INTEGER_ARRAY;

/**
 * The name affix field.
 *
 * Size: <= 15
 * Type: string
 * Rule: -
 * Example: von
 */
/*??
static char NAME_AFFIX_BDT_FIELD_ARRAY[] = {'3', '1', '0', '0'};
static char* NAME_AFFIX_BDT_FIELD = NAME_AFFIX_BDT_FIELD_ARRAY;
*/
static int* NAME_AFFIX_BDT_FIELD = NUMBER_3100_INTEGER_ARRAY;

/**
 * The patient last name field.
 *
 * Size: <= 28
 * Type: string
 * Rule: -
 * Example: Schmitz
 */
/*??
static char PATIENT_LAST_NAME_BDT_FIELD_ARRAY[] = {'3', '1', '0', '1'};
static char* PATIENT_LAST_NAME_BDT_FIELD = PATIENT_LAST_NAME_BDT_FIELD_ARRAY;
*/
static int* PATIENT_LAST_NAME_BDT_FIELD = NUMBER_3101_INTEGER_ARRAY;

/**
 * The patient first name field.
 *
 * Size: <= 28
 * Type: string
 * Rule: -
 * Example: Erna
 */
/*??
static char PATIENT_FIRST_NAME_BDT_FIELD_ARRAY[] = {'3', '1', '0', '2'};
static char* PATIENT_FIRST_NAME_BDT_FIELD = PATIENT_FIRST_NAME_BDT_FIELD_ARRAY;
*/
static int* PATIENT_FIRST_NAME_BDT_FIELD = NUMBER_3102_INTEGER_ARRAY;

/**
 * The patient birth date field.
 *
 * Size: 8
 * Type: date
 * Rule: 020
 * Example: 12041946
 */
/*??
static char PATIENT_BIRTH_DATE_BDT_FIELD_ARRAY[] = {'3', '1', '0', '3'};
static char* PATIENT_BIRTH_DATE_BDT_FIELD = PATIENT_BIRTH_DATE_BDT_FIELD_ARRAY;
*/
static int* PATIENT_BIRTH_DATE_BDT_FIELD = NUMBER_3103_INTEGER_ARRAY;

/**
 * The patient title field.
 *
 * Size: <= 15
 * Type: string
 * Rule: -
 * Example: Dr.
 */
/*??
static char PATIENT_TITLE_BDT_FIELD_ARRAY[] = {'3', '1', '0', '4'};
static char* PATIENT_TITLE_BDT_FIELD = PATIENT_TITLE_BDT_FIELD_ARRAY;
*/
static int* PATIENT_TITLE_BDT_FIELD = NUMBER_3104_INTEGER_ARRAY;

/**
 * The patient health insurance number field.
 *
 * Size: <= 70
 * Type: string
 * Rule: 335
 * Example: 1234567890
 */
/*??
static char PATIENT_HEALTH_INSURANCE_NUMBER_BDT_FIELD_ARRAY[] = {'3', '1', '0', '5'};
static char* PATIENT_HEALTH_INSURANCE_NUMBER_BDT_FIELD = PATIENT_HEALTH_INSURANCE_NUMBER_BDT_FIELD_ARRAY;
*/
static int* PATIENT_HEALTH_INSURANCE_NUMBER_BDT_FIELD = NUMBER_3105_INTEGER_ARRAY;

/**
 * The patient residence field.
 *
 * Size: <= 30
 * Type: string
 * Rule: -
 * Example: 50859 Koeln
 */
/*??
static char PATIENT_RESIDENCE_BDT_FIELD_ARRAY[] = {'3', '1', '0', '6'};
static char* PATIENT_RESIDENCE_BDT_FIELD = PATIENT_RESIDENCE_BDT_FIELD_ARRAY;
*/
static int* PATIENT_RESIDENCE_BDT_FIELD = NUMBER_3106_INTEGER_ARRAY;

/**
 * The patient street field.
 *
 * Size: <= 28
 * Type: string
 * Rule: -
 * Example: Holzweg 106
 */
/*??
static char PATIENT_STREET_BDT_FIELD_ARRAY[] = {'3', '1', '0', '7'};
static char* PATIENT_STREET_BDT_FIELD = PATIENT_STREET_BDT_FIELD_ARRAY;
*/
static int* PATIENT_STREET_BDT_FIELD = NUMBER_3107_INTEGER_ARRAY;

/**
 * The health insurance type field.
 *
 * Possible types are:
 * M: Mitglied (member)
 * F: Familie (family)
 * R: Rentner (retired, pensioner)
 *
 * Size: 1
 * Type: integer
 * Rule: 116
 * Example: 3
 */
/*??
static char HEALTH_INSURANCE_TYPE_BDT_FIELD_ARRAY[] = {'3', '1', '0', '8'};
static char* HEALTH_INSURANCE_TYPE_BDT_FIELD = HEALTH_INSURANCE_TYPE_BDT_FIELD_ARRAY;
*/
static int* HEALTH_INSURANCE_TYPE_BDT_FIELD = NUMBER_3108_INTEGER_ARRAY;

/**
 * The patient sex field.
 *
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
/*??
static char PATIENT_SEX_BDT_FIELD_ARRAY[] = {'3', '1', '1', '0'};
static char* PATIENT_SEX_BDT_FIELD = PATIENT_SEX_BDT_FIELD_ARRAY;
*/
static int* PATIENT_SEX_BDT_FIELD = NUMBER_3110_INTEGER_ARRAY;

/**
 * The record identification field.
 *
 * Size: 4
 * Type: integer
 * Rule: 167
 * Example: 0102
 */
/*??
static char RECORD_IDENTIFICATION_BDT_FIELD_ARRAY[] = {'8', '0', '0', '0'};
static char* RECORD_IDENTIFICATION_BDT_FIELD = RECORD_IDENTIFICATION_BDT_FIELD_ARRAY;
*/
static int* RECORD_IDENTIFICATION_BDT_FIELD = NUMBER_8000_INTEGER_ARRAY;

/**
 * The record size field.
 *
 * Size: 5
 * Type: integer
 * Rule: -
 * Example: 00747
 */
/*??
static char RECORD_SIZE_BDT_FIELD_ARRAY[] = {'8', '1', '0', '0'};
static char* RECORD_SIZE_BDT_FIELD = RECORD_SIZE_BDT_FIELD_ARRAY;
*/
static int* RECORD_SIZE_BDT_FIELD = NUMBER_8100_INTEGER_ARRAY;

/**
 * The sender medical doctor number field.
 *
 * Size: 7-9
 * Type: integer
 * Rule: 329
 * Example: 8353839
 */
/*??
static char SENDER_MEDICAL_DOCTOR_NUMBER_BDT_FIELD_ARRAY[] = {'9', '1', '0', '0'};
static char* SENDER_MEDICAL_DOCTOR_NUMBER_BDT_FIELD = SENDER_MEDICAL_DOCTOR_NUMBER_BDT_FIELD_ARRAY;
*/
static int* SENDER_MEDICAL_DOCTOR_NUMBER_BDT_FIELD = NUMBER_9100_INTEGER_ARRAY;

/**
 * The creation date field.
 *
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 31011994
 */
/*??
static char CREATION_DATE_BDT_FIELD_ARRAY[] = {'9', '1', '0', '3'};
static char* CREATION_DATE_BDT_FIELD = CREATION_DATE_BDT_FIELD_ARRAY;
*/
static int* CREATION_DATE_BDT_FIELD = NUMBER_9103_INTEGER_ARRAY;

/**
 * The data medium running numeration field.
 *
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 001
 */
/*??
static char DATA_MEDIUM_RUNNING_NUMERATION_BDT_FIELD_ARRAY[] = {'9', '1', '0', '5'};
static char* DATA_MEDIUM_RUNNING_NUMERATION_BDT_FIELD = DATA_MEDIUM_RUNNING_NUMERATION_BDT_FIELD_ARRAY;
*/
static int* DATA_MEDIUM_RUNNING_NUMERATION_BDT_FIELD = NUMBER_9105_INTEGER_ARRAY;

/**
 * The character code field.
 *
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
/*??
static char CHARACTER_CODE_BDT_FIELD_ARRAY[] = {'9', '1', '0', '6'};
static char* CHARACTER_CODE_BDT_FIELD = CHARACTER_CODE_BDT_FIELD_ARRAY;
*/
static int* CHARACTER_CODE_BDT_FIELD = NUMBER_9106_INTEGER_ARRAY;

/**
 * The data package size field.
 *
 * Size: 8
 * Type: integer
 * Rule: -
 * Example: 12345678
 */
/*??
static char DATA_PACKAGE_SIZE_BDT_FIELD_ARRAY[] = {'9', '2', '0', '2'};
static char* DATA_PACKAGE_SIZE_BDT_FIELD = DATA_PACKAGE_SIZE_BDT_FIELD_ARRAY;
*/
static int* DATA_PACKAGE_SIZE_BDT_FIELD = NUMBER_9202_INTEGER_ARRAY;

/**
 * The data medium count field.
 *
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 004
 */
/*??
static char DATA_MEDIUM_COUNT_BDT_FIELD_ARRAY[] = {'9', '2', '0', '3'};
static char* DATA_MEDIUM_COUNT_BDT_FIELD = DATA_MEDIUM_COUNT_BDT_FIELD_ARRAY;
*/
static int* DATA_MEDIUM_COUNT_BDT_FIELD = NUMBER_9203_INTEGER_ARRAY;

/**
 * The abrechnungs-datentransfer (adt) record specification version field.
 *
 * Size: 5
 * Type: string
 * Rule: 118
 * Example: 10/93
 */
/*??
static char ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD_ARRAY[] = {'9', '2', '1', '0'};
static char* ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD = ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD_ARRAY;
*/
static int* ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD = NUMBER_9210_INTEGER_ARRAY;

/**
 * The behandlungs-datentransfer (bdt) version field.
 *
 * Size: 5
 * Type: string
 * Rule: 172
 * Example: 02/94
 */
/*??
static char BDT_VERSION_BDT_FIELD_ARRAY[] = {'9', '2', '1', '3'};
static char* BDT_VERSION_BDT_FIELD = BDT_VERSION_BDT_FIELD_ARRAY;
*/
static int* BDT_VERSION_BDT_FIELD = NUMBER_9213_INTEGER_ARRAY;

/**
 * The archiving type field.
 *
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 1
 */
/*??
static char ARCHIVING_TYPE_BDT_FIELD_ARRAY[] = {'9', '6', '0', '0'};
static char* ARCHIVING_TYPE_BDT_FIELD = ARCHIVING_TYPE_BDT_FIELD_ARRAY;
*/
static int* ARCHIVING_TYPE_BDT_FIELD = NUMBER_9600_INTEGER_ARRAY;

/**
 * The data storage period field.
 *
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 0110199331121993
 */
/*??
static char DATA_STORAGE_PERIOD_BDT_FIELD_ARRAY[] = {'9', '6', '0', '1'};
static char* DATA_STORAGE_PERIOD_BDT_FIELD = DATA_STORAGE_PERIOD_BDT_FIELD_ARRAY;
*/
static int* DATA_STORAGE_PERIOD_BDT_FIELD = NUMBER_9601_INTEGER_ARRAY;

/**
 * The transfer begin field.
 *
 * Size: 8
 * Type: integer
 * Rule: -
 * Example: 17084600
 */
/*??
static char TRANSFER_BEGIN_BDT_FIELD_ARRAY[] = {'9', '6', '0', '2'};
static char* TRANSFER_BEGIN_BDT_FIELD = TRANSFER_BEGIN_BDT_FIELD_ARRAY;
*/
static int* TRANSFER_BEGIN_BDT_FIELD = NUMBER_9602_INTEGER_ARRAY;

/**
 * The system internal parameter field.
 *
 * Size: <= 70
 * Type: string
 * Rule: 999
 * Example: -
 */
/*??
static char SYSTEM_INTERNAL_PARAMETER_BDT_FIELD_ARRAY[] = {'9', '9', '0', '1'};
static char* SYSTEM_INTERNAL_PARAMETER_BDT_FIELD = SYSTEM_INTERNAL_PARAMETER_BDT_FIELD_ARRAY;
*/
static int* SYSTEM_INTERNAL_PARAMETER_BDT_FIELD = NUMBER_9901_INTEGER_ARRAY;

/* BDT_FIELD_CONSTANTS_SOURCE */
#endif
