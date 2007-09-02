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
 * @version $Revision: 1.5 $ $Date: 2007-09-02 22:35:17 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_FIELD_NAME_CONSTANTS_SOURCE
#define XDT_FIELD_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Xdt package names.
//

/** The standard package name. */
static char STANDARD_XDT_PACKAGE_NAME_ARRAY[] = {'s', 't', 'a', 'n', 'd', 'a', 'r', 'd'};
static char* STANDARD_XDT_PACKAGE_NAME = STANDARD_XDT_PACKAGE_NAME_ARRAY;
static int* STANDARD_XDT_PACKAGE_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Xdt record names.
//

/** The medical practice data record name. */
static char MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '_', 'd', 'a', 't', 'a'};
static char* MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME = MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The data medium header record name. */
/*?? This constant is (probably) not needed.
static char DATA_MEDIUM_HEADER_XDT_RECORD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'h', 'e', 'a', 'd', 'e', 'r'};
static char* DATA_MEDIUM_HEADER_XDT_RECORD_NAME = DATA_MEDIUM_HEADER_XDT_RECORD_NAME_ARRAY;
static int* DATA_MEDIUM_HEADER_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;
*/

/** The data medium footer record name. */
/*?? This constant is not needed.
static char DATA_MEDIUM_FOOTER_XDT_RECORD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'f', 'o', 'o', 't', 'e', 'r'};
static char* DATA_MEDIUM_FOOTER_XDT_RECORD_NAME = DATA_MEDIUM_FOOTER_XDT_RECORD_NAME_ARRAY;
static int* DATA_MEDIUM_FOOTER_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;
*/

/** The package header name. */
static char PACKAGE_HEADER_XDT_RECORD_NAME_ARRAY[] = {'h', 'e', 'a', 'd', 'e', 'r'};
static char* PACKAGE_HEADER_XDT_RECORD_NAME = PACKAGE_HEADER_XDT_RECORD_NAME_ARRAY;
static int* PACKAGE_HEADER_XDT_RECORD_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The package footer name. */
static char PACKAGE_FOOTER_XDT_RECORD_NAME_ARRAY[] = {'f', 'o', 'o', 't', 'e', 'r'};
static char* PACKAGE_FOOTER_XDT_RECORD_NAME = PACKAGE_FOOTER_XDT_RECORD_NAME_ARRAY;
static int* PACKAGE_FOOTER_XDT_RECORD_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The medical treatment record name. */
static char MEDICAL_TREATMENT_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't'};
static char* MEDICAL_TREATMENT_XDT_RECORD_NAME = MEDICAL_TREATMENT_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_XDT_RECORD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The referral case record name. */
/*?? This constant is (probably) not needed.
static char REFERRAL_CASE_XDT_RECORD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'a', 's', 'e'};
static char* REFERRAL_CASE_XDT_RECORD_NAME = REFERRAL_CASE_XDT_RECORD_NAME_ARRAY;
static int* REFERRAL_CASE_XDT_RECORD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;
*/

/** The medical treatment with cottage hospital affiliation record name. */
/*?? This constant is (probably) not needed.
static char MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'w', 'i', 't', 'h', '_', 'c', 'o', 't', 't', 'a', 'g', 'e', '_', 'h', 'o', 's', 'p', 'i', 't', 'a', 'l', '_', 'a', 'f', 'f', 'i', 'l', 'i', 'a', 't', 'i', 'o', 'n'};
static char* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME = MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_COUNT = NUMBER_51_INTEGER_ARRAY;
*/

/** The medical emergency service record name. */
/*?? This constant is (probably) not needed.
static char MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 'e', 'm', 'e', 'r', 'g', 'e', 'n', 'c', 'y', '_', 's', 'e', 'r', 'v', 'i', 'c', 'e'};
static char* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME = MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;
*/

/** The private billing record name. */
/*?? This constant is (probably) not needed.
static char PRIVATE_BILLING_XDT_RECORD_NAME_ARRAY[] = {'p', 'r', 'i', 'v', 'a', 't', 'e', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g'};
static char* PRIVATE_BILLING_XDT_RECORD_NAME = PRIVATE_BILLING_XDT_RECORD_NAME_ARRAY;
static int* PRIVATE_BILLING_XDT_RECORD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;
*/

/** The employers' liability insurance association billing record name. */
/*?? This constant is (probably) not needed.
static char EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_ARRAY[] = {'e', 'm', 'p', 'l', 'o', 'y', 'e', 'r', 's', '_', 'l', 'i', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'a', 's', 's', 'o', 'c', 'i', 'a', 't', 'i', 'o', 'n', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g'};
static char* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME = EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_ARRAY;
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_COUNT = NUMBER_49_INTEGER_ARRAY;
*/

/** The unstructured cases record name. */
/*?? This constant is (probably) not needed.
static char UNSTRUCTURED_CASES_XDT_RECORD_NAME_ARRAY[] = {'u', 'n', 's', 't', 'r', 'u', 'c', 't', 'u', 'r', 'e', 'd', '_', 'c', 'a', 's', 'e', 's'};
static char* UNSTRUCTURED_CASES_XDT_RECORD_NAME = UNSTRUCTURED_CASES_XDT_RECORD_NAME_ARRAY;
static int* UNSTRUCTURED_CASES_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;
*/

/** The patient master data record name. */
static char PATIENT_MASTER_DATA_XDT_RECORD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'm', 'a', 's', 't', 'e', 'r', '_', 'd', 'a', 't', 'a'};
static char* PATIENT_MASTER_DATA_XDT_RECORD_NAME = PATIENT_MASTER_DATA_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_XDT_RECORD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The medical treatment data record name. */
static char MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'a'};
static char* MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME = MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

//
// Xdt field names.
//

/** The kbv pruefnummer field name. */
static char KBV_PRUEFNUMMER_XDT_FIELD_NAME_ARRAY[] = {'k', 'b', 'v', '_', 'p', 'r', 'u', 'e', 'f', 'n', 'u', 'm', 'm', 'e', 'r'};
static char* KBV_PRUEFNUMMER_XDT_FIELD_NAME = KBV_PRUEFNUMMER_XDT_FIELD_NAME_ARRAY;
static int* KBV_PRUEFNUMMER_XDT_FIELD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The patient identification field name. */
static char PATIENT_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* PATIENT_IDENTIFICATION_XDT_FIELD_NAME = PATIENT_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The name affix field name. */
static char NAME_AFFIX_XDT_FIELD_NAME_ARRAY[] = {'n', 'a', 'm', 'e', '_', 'a', 'f', 'f', 'i', 'x'};
static char* NAME_AFFIX_XDT_FIELD_NAME = NAME_AFFIX_XDT_FIELD_NAME_ARRAY;
static int* NAME_AFFIX_XDT_FIELD_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

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

/** The health insurance type field name. */
static char HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME_ARRAY[] = {'h', 'e', 'a', 'l', 't', 'h', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 't', 'y', 'p', 'e'};
static char* HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME = HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME_ARRAY;
static int* HEALTH_INSURANCE_TYPE_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The patient sex field name. */
static char PATIENT_SEX_XDT_FIELD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 's', 'e', 'x'};
static char* PATIENT_SEX_XDT_FIELD_NAME = PATIENT_SEX_XDT_FIELD_NAME_ARRAY;
static int* PATIENT_SEX_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The record identification field name. */
/*??
static char RECORD_IDENTIFICATION_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'c', 'o', 'r', 'd', '_', 'i', 'd', 'e', 'n', 't', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n'};
static char* RECORD_IDENTIFICATION_XDT_FIELD_NAME = RECORD_IDENTIFICATION_XDT_FIELD_NAME_ARRAY;
static int* RECORD_IDENTIFICATION_XDT_FIELD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The record size field name. */
static char RECORD_SIZE_XDT_FIELD_NAME_ARRAY[] = {'r', 'e', 'c', 'o', 'r', 'd', '_', 's', 'i', 'z', 'e'};
static char* RECORD_SIZE_XDT_FIELD_NAME = RECORD_SIZE_XDT_FIELD_NAME_ARRAY;
static int* RECORD_SIZE_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The sender medical doctor number field name. */
static char SENDER_MEDICAL_DOCTOR_NUMBER_XDT_FIELD_NAME_ARRAY[] = {'s', 'e', 'n', 'd', 'e', 'r', '_', 'm', 'e', 'd', 'i', 'c', 'a', 'l', '_', 'd', 'o', 'c', 't', 'o', 'r', '_', 'n', 'u', 'm', 'b', 'e', 'r'};
static char* SENDER_MEDICAL_DOCTOR_NUMBER_XDT_FIELD_NAME = SENDER_MEDICAL_DOCTOR_NUMBER_XDT_FIELD_NAME_ARRAY;
static int* SENDER_MEDICAL_DOCTOR_NUMBER_XDT_FIELD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The creation date field name. */
static char CREATION_DATE_XDT_FIELD_NAME_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'e'};
static char* CREATION_DATE_XDT_FIELD_NAME = CREATION_DATE_XDT_FIELD_NAME_ARRAY;
static int* CREATION_DATE_XDT_FIELD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The data medium running numeration field name. */
/*??
static char DATA_MEDIUM_RUNNING_NUMERATION_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'r', 'u', 'n', 'n', 'i', 'n', 'g', '_', 'n', 'u', 'm', 'e', 'r', 'a', 't', 'i', 'o', 'n'};
static char* DATA_MEDIUM_RUNNING_NUMERATION_XDT_FIELD_NAME = DATA_MEDIUM_RUNNING_NUMERATION_XDT_FIELD_NAME_ARRAY;
static int* DATA_MEDIUM_RUNNING_NUMERATION_XDT_FIELD_NAME_COUNT = NUMBER_30_INTEGER_ARRAY;

/** The character code field name. */
/*??
static char CHARACTER_CODE_XDT_FIELD_NAME_ARRAY[] = {'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', '_', 'c', 'o', 'd', 'e'};
static char* CHARACTER_CODE_XDT_FIELD_NAME = CHARACTER_CODE_XDT_FIELD_NAME_ARRAY;
static int* CHARACTER_CODE_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The data package size field name. */
/*??
static char DATA_PACKAGE_SIZE_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'p', 'a', 'c', 'k', 'a', 'g', 'e', '_', 's', 'i', 'z', 'e'};
static char* DATA_PACKAGE_SIZE_XDT_FIELD_NAME = DATA_PACKAGE_SIZE_XDT_FIELD_NAME_ARRAY;
static int* DATA_PACKAGE_SIZE_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The data medium count field name. */
/*??
static char DATA_MEDIUM_COUNT_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 'm', 'e', 'd', 'i', 'u', 'm', '_', 'c', 'o', 'u', 'n', 't'};
static char* DATA_MEDIUM_COUNT_XDT_FIELD_NAME = DATA_MEDIUM_COUNT_XDT_FIELD_NAME_ARRAY;
static int* DATA_MEDIUM_COUNT_XDT_FIELD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The abrechnungs-datentransfer (adt) record specification version field name. */
static char ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_ARRAY[] = {'a', 'd', 't', '_', 'r', 'e', 'c', 'o', 'r', 'd', '_', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n'};
static char* ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME = ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_ARRAY;
static int* ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_COUNT = NUMBER_32_INTEGER_ARRAY;

/** The behandlungs-datentransfer (bdt) version field name. */
/*??
static char BDT_VERSION_XDT_FIELD_NAME_ARRAY[] = {'b', 'd', 't', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n'};
static char* BDT_VERSION_XDT_FIELD_NAME = BDT_VERSION_XDT_FIELD_NAME_ARRAY;
static int* BDT_VERSION_XDT_FIELD_NAME_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The archiving type field name. */
/*??
static char ARCHIVING_TYPE_XDT_FIELD_NAME_ARRAY[] = {'a', 'r', 'c', 'h', 'i', 'v', 'i', 'n', 'g', '_', 't', 'y', 'p', 'e'};
static char* ARCHIVING_TYPE_XDT_FIELD_NAME = ARCHIVING_TYPE_XDT_FIELD_NAME_ARRAY;
static int* ARCHIVING_TYPE_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The data storage period field name. */
/*??
static char DATA_STORAGE_PERIOD_XDT_FIELD_NAME_ARRAY[] = {'d', 'a', 't', 'a', '_', 's', 't', 'o', 'r', 'a', 'g', 'e', '_', 'p', 'e', 'r', 'i', 'o', 'd'};
static char* DATA_STORAGE_PERIOD_XDT_FIELD_NAME = DATA_STORAGE_PERIOD_XDT_FIELD_NAME_ARRAY;
static int* DATA_STORAGE_PERIOD_XDT_FIELD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The transfer begin field name. */
/*??
static char TRANSFER_BEGIN_XDT_FIELD_NAME_ARRAY[] = {'t', 'r', 'a', 'n', 's', 'f', 'e', 'r', '_', 'b', 'e', 'g', 'i', 'n'};
static char* TRANSFER_BEGIN_XDT_FIELD_NAME = TRANSFER_BEGIN_XDT_FIELD_NAME_ARRAY;
static int* TRANSFER_BEGIN_XDT_FIELD_NAME_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The system internal parameter field name. */
/*??
static char SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME_ARRAY[] = {'s', 'y', 's', 't', 'e', 'm', '_', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '_', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r'};
static char* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME = SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME_ARRAY;
static int* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/* XDT_FIELD_NAME_CONSTANTS_SOURCE */
#endif
