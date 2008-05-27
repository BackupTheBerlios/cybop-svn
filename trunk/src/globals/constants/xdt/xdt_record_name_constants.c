/*
 * $RCSfile: xdt_record_name_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.5 $ $Date: 2008-05-27 22:52:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_RECORD_NAME_CONSTANTS_SOURCE
#define XDT_RECORD_NAME_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The medical practice data record name. */
static wchar_t MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e', L'_', L'd', L'a', L't', L'a'};
static wchar_t* MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME = MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The data medium header record name. */
/*?? This constant is (probably) not needed.
static wchar_t DATA_MEDIUM_HEADER_XDT_RECORD_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'h', L'e', L'a', L'd', L'e', L'r'};
static wchar_t* DATA_MEDIUM_HEADER_XDT_RECORD_NAME = DATA_MEDIUM_HEADER_XDT_RECORD_NAME_ARRAY;
static int* DATA_MEDIUM_HEADER_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;
*/

/** The data medium footer record name. */
/*?? This constant is not needed.
static wchar_t DATA_MEDIUM_FOOTER_XDT_RECORD_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'f', L'o', L'o', L't', L'e', L'r'};
static wchar_t* DATA_MEDIUM_FOOTER_XDT_RECORD_NAME = DATA_MEDIUM_FOOTER_XDT_RECORD_NAME_ARRAY;
static int* DATA_MEDIUM_FOOTER_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;
*/

/** The package header name. */
static wchar_t PACKAGE_HEADER_XDT_RECORD_NAME_ARRAY[] = {L'h', L'e', L'a', L'd', L'e', L'r'};
static wchar_t* PACKAGE_HEADER_XDT_RECORD_NAME = PACKAGE_HEADER_XDT_RECORD_NAME_ARRAY;
static int* PACKAGE_HEADER_XDT_RECORD_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The package footer name. */
static wchar_t PACKAGE_FOOTER_XDT_RECORD_NAME_ARRAY[] = {L'f', L'o', L'o', L't', L'e', L'r'};
static wchar_t* PACKAGE_FOOTER_XDT_RECORD_NAME = PACKAGE_FOOTER_XDT_RECORD_NAME_ARRAY;
static int* PACKAGE_FOOTER_XDT_RECORD_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The medical treatment record name. */
static wchar_t MEDICAL_TREATMENT_XDT_RECORD_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't'};
static wchar_t* MEDICAL_TREATMENT_XDT_RECORD_NAME = MEDICAL_TREATMENT_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_XDT_RECORD_NAME_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The referral case record name. */
static wchar_t REFERRAL_CASE_XDT_RECORD_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'a', L's', L'e'};
static wchar_t* REFERRAL_CASE_XDT_RECORD_NAME = REFERRAL_CASE_XDT_RECORD_NAME_ARRAY;
static int* REFERRAL_CASE_XDT_RECORD_NAME_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The medical treatment with cottage hospital affiliation record name. */
static wchar_t MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'w', L'i', L't', L'h', L'_', L'c', L'o', L't', L't', L'a', L'g', L'e', L'_', L'h', L'o', L's', L'p', L'i', L't', L'a', L'l', L'_', L'a', L'f', L'f', L'i', L'l', L'i', L'a', L't', L'i', L'o', L'n'};
static wchar_t* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME = MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD_NAME_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The medical emergency service record name. */
static wchar_t MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L'e', L'm', L'e', L'r', L'g', L'e', L'n', L'c', L'y', L'_', L's', L'e', L'r', L'v', L'i', L'c', L'e'};
static wchar_t* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME = MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The private billing record name. */
static wchar_t PRIVATE_BILLING_XDT_RECORD_NAME_ARRAY[] = {L'p', L'r', L'i', L'v', L'a', L't', L'e', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g'};
static wchar_t* PRIVATE_BILLING_XDT_RECORD_NAME = PRIVATE_BILLING_XDT_RECORD_NAME_ARRAY;
static int* PRIVATE_BILLING_XDT_RECORD_NAME_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The employers' liability insurance association billing record name. */
static wchar_t EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_ARRAY[] = {L'e', L'm', L'p', L'l', L'o', L'y', L'e', L'r', L's', L'_', L'l', L'i', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'a', L's', L's', L'o', L'c', L'i', L'a', L't', L'i', L'o', L'n', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g'};
static wchar_t* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME = EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_ARRAY;
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD_NAME_COUNT = NUMBER_49_INTEGER_ARRAY;

/** The unstructured cases record name. */
static wchar_t UNSTRUCTURED_CASES_XDT_RECORD_NAME_ARRAY[] = {L'u', L'n', L's', L't', L'r', L'u', L'c', L't', L'u', L'r', L'e', L'd', L'_', L'c', L'a', L's', L'e', L's'};
static wchar_t* UNSTRUCTURED_CASES_XDT_RECORD_NAME = UNSTRUCTURED_CASES_XDT_RECORD_NAME_ARRAY;
static int* UNSTRUCTURED_CASES_XDT_RECORD_NAME_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The patient master data record name. */
static wchar_t PATIENT_MASTER_DATA_XDT_RECORD_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'a', L's', L't', L'e', L'r', L'_', L'd', L'a', L't', L'a'};
static wchar_t* PATIENT_MASTER_DATA_XDT_RECORD_NAME = PATIENT_MASTER_DATA_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_XDT_RECORD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The medical treatment data record name. */
static wchar_t MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'a'};
static wchar_t* MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME = MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_ARRAY;
static int* MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The patient master data request record name. */
static wchar_t PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'a', L's', L't', L'e', L'r', L'_', L'd', L'a', L't', L'a', L'_', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME = PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_REQUEST_XDT_RECORD_NAME_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The patient master data transfer record name. */
static wchar_t PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'a', L's', L't', L'e', L'r', L'_', L'd', L'a', L't', L'a', L'_', L't', L'r', L'a', L'n', L's', L'f', L'e', L'r'};
static wchar_t* PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME = PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD_NAME_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The examination request record name. */
static wchar_t EXAMINATION_REQUEST_XDT_RECORD_NAME_ARRAY[] = {L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n', L'_', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* EXAMINATION_REQUEST_XDT_RECORD_NAME = EXAMINATION_REQUEST_XDT_RECORD_NAME_ARRAY;
static int* EXAMINATION_REQUEST_XDT_RECORD_NAME_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The examination data transfer record name. */
static wchar_t EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY[] = {L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'a', L'_', L't', L'r', L'a', L'n', L's', L'f', L'e', L'r'};
static wchar_t* EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME = EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME_ARRAY;
static int* EXAMINATION_DATA_TRANSFER_XDT_RECORD_NAME_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The examination data display record name. */
static wchar_t EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME_ARRAY[] = {L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'a', L'_', L'd', L'i', L's', L'p', L'l', L'a', L'y'};
static wchar_t* EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME = EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME_ARRAY;
static int* EXAMINATION_DATA_DISPLAY_XDT_RECORD_NAME_COUNT = NUMBER_24_INTEGER_ARRAY;

/* XDT_RECORD_NAME_CONSTANTS_SOURCE */
#endif
