/*
 * $RCSfile: xdt_record_name_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-09-10 18:37:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_RECORD_NAME_CONSTANTS_SOURCE
#define XDT_RECORD_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

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
static char REFERRAL_CASE_XDT_RECORD_NAME_ARRAY[] = {'r', 'e', 'f', 'e', 'r', 'r', 'a', 'l', '_', 'c', 'a', 's', 'e'};
static char* REFERRAL_CASE_XDT_RECORD_NAME = REFERRAL_CASE_XDT_RECORD_NAME_ARRAY;
static int* REFERRAL_CASE_XDT_RECORD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The medical treatment with cottage hospital affiliation record name. */
static char MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'w', 'i', 't', 'h', '_', 'c', 'o', 't', 't', 'a', 'g', 'e', '_', 'h', 'o', 's', 'p', 'i', 't', 'a', 'l', '_', 'a', 'f', 'f', 'i', 'l', 'i', 'a', 't', 'i', 'o', 'n'};
static char* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME = MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The medical emergency service record name. */
static char MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 'e', 'm', 'e', 'r', 'g', 'e', 'n', 'c', 'y', '_', 's', 'e', 'r', 'v', 'i', 'c', 'e'};
static char* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME = MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The private billing record name. */
static char PRIVATE_BILLING_XDT_RECORD_NAME_ARRAY[] = {'p', 'r', 'i', 'v', 'a', 't', 'e', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g'};
static char* PRIVATE_BILLING_XDT_RECORD_NAME = PRIVATE_BILLING_XDT_RECORD_NAME_ARRAY;
static int* PRIVATE_BILLING_XDT_RECORD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The employers' liability insurance association billing record name. */
static char EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_ARRAY[] = {'e', 'm', 'p', 'l', 'o', 'y', 'e', 'r', 's', '_', 'l', 'i', 'a', 'b', 'i', 'l', 'i', 't', 'y', '_', 'i', 'n', 's', 'u', 'r', 'a', 'n', 'c', 'e', '_', 'a', 's', 's', 'o', 'c', 'i', 'a', 't', 'i', 'o', 'n', '_', 'b', 'i', 'l', 'l', 'i', 'n', 'g'};
static char* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME = EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_ARRAY;
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_COUNT = NUMBER_49_INTEGER_ARRAY;

/** The unstructured cases record name. */
static char UNSTRUCTURED_CASES_XDT_RECORD_NAME_ARRAY[] = {'u', 'n', 's', 't', 'r', 'u', 'c', 't', 'u', 'r', 'e', 'd', '_', 'c', 'a', 's', 'e', 's'};
static char* UNSTRUCTURED_CASES_XDT_RECORD_NAME = UNSTRUCTURED_CASES_XDT_RECORD_NAME_ARRAY;
static int* UNSTRUCTURED_CASES_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient master data record name. */
static char PATIENT_MASTER_DATA_XDT_RECORD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'm', 'a', 's', 't', 'e', 'r', '_', 'd', 'a', 't', 'a'};
static char* PATIENT_MASTER_DATA_XDT_RECORD_NAME = PATIENT_MASTER_DATA_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_XDT_RECORD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The medical treatment data record name. */
static char MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_ARRAY[] = {'m', 'e', 'd', 'i', 'c', 'a', 'l', '_', 't', 'r', 'e', 'a', 't', 'm', 'e', 'n', 't', '_', 'd', 'a', 't', 'a'};
static char* MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME = MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The patient master data request record name. */
static char PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'm', 'a', 's', 't', 'e', 'r', '_', 'd', 'a', 't', 'a', '_', 'r', 'e', 'q', 'u', 'e', 's', 't'};
static char* PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME = PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The patient master data transfer record name. */
static char PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY[] = {'p', 'a', 't', 'i', 'e', 'n', 't', '_', 'm', 'a', 's', 't', 'e', 'r', '_', 'd', 'a', 't', 'a', '_', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'};
static char* PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME = PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The examination request record name. */
static char EXAMINATION_REQUEST_XDT_RECORD_NAME_ARRAY[] = {'e', 'x', 'a', 'm', 'i', 'n', 'a', 't', 'i', 'o', 'n', '_', 'r', 'e', 'q', 'u', 'e', 's', 't'};
static char* EXAMINATION_REQUEST_XDT_RECORD_NAME = EXAMINATION_REQUEST_XDT_RECORD_NAME_ARRAY;
static int* EXAMINATION_REQUEST_XDT_RECORD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The examination data transfer record name. */
static char EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY[] = {'e', 'x', 'a', 'm', 'i', 'n', 'a', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'a', '_', 't', 'r', 'a', 'n', 's', 'f', 'e', 'r'};
static char* EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME = EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY;
static int* EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The examination data display record name. */
static char EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME_ARRAY[] = {'e', 'x', 'a', 'm', 'i', 'n', 'a', 't', 'i', 'o', 'n', '_', 'd', 'a', 't', 'a', '_', 'd', 'i', 's', 'p', 'l', 'a', 'y'};
static char* EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME = EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME_ARRAY;
static int* EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/* XDT_RECORD_NAME_CONSTANTS_SOURCE */
#endif
