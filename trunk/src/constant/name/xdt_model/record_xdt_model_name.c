/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: record_xdt_model_name.c,v $ $Revision: 1.2 $ $Date: 2009-02-10 01:13:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECORD_XDT_MODEL_NAME_SOURCE
#define RECORD_XDT_MODEL_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The medical practice data record xdt model name. */
static wchar_t MEDICAL_PRACTICE_DATA_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L'p', L'r', L'a', L'c', L't', L'i', L'c', L'e', L'_', L'd', L'a', L't', L'a'};
static wchar_t* MEDICAL_PRACTICE_DATA_RECORD_XDT_MODEL_NAME = MEDICAL_PRACTICE_DATA_RECORD_XDT_MODEL_NAME_ARRAY;
static int* MEDICAL_PRACTICE_DATA_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The data medium header record xdt model name. */
/*?? This constant is (probably) not needed.
static wchar_t DATA_MEDIUM_HEADER_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'h', L'e', L'a', L'd', L'e', L'r'};
static wchar_t* DATA_MEDIUM_HEADER_RECORD_XDT_MODEL_NAME = DATA_MEDIUM_HEADER_RECORD_XDT_MODEL_NAME_ARRAY;
static int* DATA_MEDIUM_HEADER_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;
*/

/** The data medium footer record xdt model name. */
/*?? This constant is not needed.
static wchar_t DATA_MEDIUM_FOOTER_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'd', L'a', L't', L'a', L'_', L'm', L'e', L'd', L'i', L'u', L'm', L'_', L'f', L'o', L'o', L't', L'e', L'r'};
static wchar_t* DATA_MEDIUM_FOOTER_RECORD_XDT_MODEL_NAME = DATA_MEDIUM_FOOTER_RECORD_XDT_MODEL_NAME_ARRAY;
static int* DATA_MEDIUM_FOOTER_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;
*/

/** The package header name. */
static wchar_t PACKAGE_HEADER_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'h', L'e', L'a', L'd', L'e', L'r'};
static wchar_t* PACKAGE_HEADER_RECORD_XDT_MODEL_NAME = PACKAGE_HEADER_RECORD_XDT_MODEL_NAME_ARRAY;
static int* PACKAGE_HEADER_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The package footer name. */
static wchar_t PACKAGE_FOOTER_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'f', L'o', L'o', L't', L'e', L'r'};
static wchar_t* PACKAGE_FOOTER_RECORD_XDT_MODEL_NAME = PACKAGE_FOOTER_RECORD_XDT_MODEL_NAME_ARRAY;
static int* PACKAGE_FOOTER_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The medical treatment record xdt model name. */
static wchar_t MEDICAL_TREATMENT_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't'};
static wchar_t* MEDICAL_TREATMENT_RECORD_XDT_MODEL_NAME = MEDICAL_TREATMENT_RECORD_XDT_MODEL_NAME_ARRAY;
static int* MEDICAL_TREATMENT_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The referral case record xdt model name. */
static wchar_t REFERRAL_CASE_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'r', L'e', L'f', L'e', L'r', L'r', L'a', L'l', L'_', L'c', L'a', L's', L'e'};
static wchar_t* REFERRAL_CASE_RECORD_XDT_MODEL_NAME = REFERRAL_CASE_RECORD_XDT_MODEL_NAME_ARRAY;
static int* REFERRAL_CASE_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The medical treatment with cottage hospital affiliation record xdt model name. */
static wchar_t MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'w', L'i', L't', L'h', L'_', L'c', L'o', L't', L't', L'a', L'g', L'e', L'_', L'h', L'o', L's', L'p', L'i', L't', L'a', L'l', L'_', L'a', L'f', L'f', L'i', L'l', L'i', L'a', L't', L'i', L'o', L'n'};
static wchar_t* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_MODEL_NAME = MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_MODEL_NAME_ARRAY;
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The medical emergency service record xdt model name. */
static wchar_t MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L'e', L'm', L'e', L'r', L'g', L'e', L'n', L'c', L'y', L'_', L's', L'e', L'r', L'v', L'i', L'c', L'e'};
static wchar_t* MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_MODEL_NAME = MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_MODEL_NAME_ARRAY;
static int* MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The private billing record xdt model name. */
static wchar_t PRIVATE_BILLING_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'p', L'r', L'i', L'v', L'a', L't', L'e', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g'};
static wchar_t* PRIVATE_BILLING_RECORD_XDT_MODEL_NAME = PRIVATE_BILLING_RECORD_XDT_MODEL_NAME_ARRAY;
static int* PRIVATE_BILLING_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The employers' liability insurance association billing record xdt model name. */
static wchar_t EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'e', L'm', L'p', L'l', L'o', L'y', L'e', L'r', L's', L'_', L'l', L'i', L'a', L'b', L'i', L'l', L'i', L't', L'y', L'_', L'i', L'n', L's', L'u', L'r', L'a', L'n', L'c', L'e', L'_', L'a', L's', L's', L'o', L'c', L'i', L'a', L't', L'i', L'o', L'n', L'_', L'b', L'i', L'l', L'l', L'i', L'n', L'g'};
static wchar_t* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_MODEL_NAME = EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_MODEL_NAME_ARRAY;
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_49_INTEGER_MEMORY_MODEL_ARRAY;

/** The unstructured cases record xdt model name. */
static wchar_t UNSTRUCTURED_CASES_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'u', L'n', L's', L't', L'r', L'u', L'c', L't', L'u', L'r', L'e', L'd', L'_', L'c', L'a', L's', L'e', L's'};
static wchar_t* UNSTRUCTURED_CASES_RECORD_XDT_MODEL_NAME = UNSTRUCTURED_CASES_RECORD_XDT_MODEL_NAME_ARRAY;
static int* UNSTRUCTURED_CASES_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient master data record xdt model name. */
static wchar_t PATIENT_MASTER_DATA_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'a', L's', L't', L'e', L'r', L'_', L'd', L'a', L't', L'a'};
static wchar_t* PATIENT_MASTER_DATA_RECORD_XDT_MODEL_NAME = PATIENT_MASTER_DATA_RECORD_XDT_MODEL_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The medical treatment data record xdt model name. */
static wchar_t MEDICAL_TREATMENT_DATA_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'm', L'e', L'd', L'i', L'c', L'a', L'l', L'_', L't', L'r', L'e', L'a', L't', L'm', L'e', L'n', L't', L'_', L'd', L'a', L't', L'a'};
static wchar_t* MEDICAL_TREATMENT_DATA_RECORD_XDT_MODEL_NAME = MEDICAL_TREATMENT_DATA_RECORD_XDT_MODEL_NAME_ARRAY;
static int* MEDICAL_TREATMENT_DATA_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient master data request record xdt model name. */
static wchar_t PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'a', L's', L't', L'e', L'r', L'_', L'd', L'a', L't', L'a', L'_', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_MODEL_NAME = PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_MODEL_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The patient master data transfer record xdt model name. */
static wchar_t PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'p', L'a', L't', L'i', L'e', L'n', L't', L'_', L'm', L'a', L's', L't', L'e', L'r', L'_', L'd', L'a', L't', L'a', L'_', L't', L'r', L'a', L'n', L's', L'f', L'e', L'r'};
static wchar_t* PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_MODEL_NAME = PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_ARRAY;
static int* PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The examination request record xdt model name. */
static wchar_t EXAMINATION_REQUEST_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n', L'_', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* EXAMINATION_REQUEST_RECORD_XDT_MODEL_NAME = EXAMINATION_REQUEST_RECORD_XDT_MODEL_NAME_ARRAY;
static int* EXAMINATION_REQUEST_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The examination data transfer record xdt model name. */
static wchar_t EXAMINATION_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'a', L'_', L't', L'r', L'a', L'n', L's', L'f', L'e', L'r'};
static wchar_t* EXAMINATION_DATA_TRANSFER_RECORD_XDT_MODEL_NAME = EXAMINATION_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_ARRAY;
static int* EXAMINATION_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The examination data display record xdt model name. */
static wchar_t EXAMINATION_DATA_DISPLAY_RECORD_XDT_MODEL_NAME_ARRAY[] = {L'e', L'x', L'a', L'm', L'i', L'n', L'a', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'a', L'_', L'd', L'i', L's', L'p', L'l', L'a', L'y'};
static wchar_t* EXAMINATION_DATA_DISPLAY_RECORD_XDT_MODEL_NAME = EXAMINATION_DATA_DISPLAY_RECORD_XDT_MODEL_NAME_ARRAY;
static int* EXAMINATION_DATA_DISPLAY_RECORD_XDT_MODEL_NAME_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/* RECORD_XDT_MODEL_NAME_SOURCE */
#endif
