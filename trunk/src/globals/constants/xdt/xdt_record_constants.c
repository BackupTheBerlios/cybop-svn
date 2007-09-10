/*
 * $RCSfile: xdt_record_constants.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2007-09-10 18:37:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_RECORD_CONSTANTS_SOURCE
#define XDT_RECORD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/**
 * The xdt record identification count.
 *
 * All xdt record identifications have the same length: 4 ASCII characters (bytes).
 */
static int* XDT_RECORD_IDENTIFICATION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The medical practice data record. */
static int* MEDICAL_PRACTICE_DATA_XDT_RECORD = NUMBER_10_INTEGER_ARRAY;

/** The data medium header record. */
static int* DATA_MEDIUM_HEADER_XDT_RECORD = NUMBER_20_INTEGER_ARRAY;

/** The data medium footer record. */
static int* DATA_MEDIUM_FOOTER_XDT_RECORD = NUMBER_21_INTEGER_ARRAY;

/** The data package header record. */
static int* DATA_PACKAGE_HEADER_XDT_RECORD = NUMBER_22_INTEGER_ARRAY;

/** The data package footer record. */
static int* DATA_PACKAGE_FOOTER_XDT_RECORD = NUMBER_23_INTEGER_ARRAY;

/** The medical treatment record. */
static int* MEDICAL_TREATMENT_XDT_RECORD = NUMBER_101_INTEGER_ARRAY;

/** The referral case record. */
static int* REFERRAL_CASE_XDT_RECORD = NUMBER_102_INTEGER_ARRAY;

/** The medical treatment with cottage hospital affiliation record. */
static int* MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_XDT_RECORD = NUMBER_103_INTEGER_ARRAY;

/** The medical emergency service record. */
static int* MEDICAL_EMERGENCY_SERVICE_XDT_RECORD = NUMBER_104_INTEGER_ARRAY;

/** The private billing record. */
static int* PRIVATE_BILLING_XDT_RECORD = NUMBER_190_INTEGER_ARRAY;

/** The employers' liability insurance association billing record. */
static int* EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_XDT_RECORD = NUMBER_191_INTEGER_ARRAY;

/** The unstructured cases record. */
static int* UNSTRUCTURED_CASES_XDT_RECORD = NUMBER_199_INTEGER_ARRAY;

/** The patient master data record. */
static int* PATIENT_MASTER_DATA_XDT_RECORD = NUMBER_6100_INTEGER_ARRAY;

/** The medical treatment data record. */
static int* MEDICAL_TREATMENT_DATA_XDT_RECORD = NUMBER_6200_INTEGER_ARRAY;

/** The patient master data request record. */
static int* PATIENT_MASTER_DATA_REQUEST_XDT_RECORD = NUMBER_6300_INTEGER_ARRAY;

/** The patient master data transfer record. */
static int* PATIENT_MASTER_DATA_TRANSFER_XDT_RECORD = NUMBER_6301_INTEGER_ARRAY;

/** The examination request record. */
static int* EXAMINATION_REQUEST_XDT_RECORD = NUMBER_6302_INTEGER_ARRAY;

/** The examination data transfer record. */
static int* EXAMINATION_DATA_TRANSFER_XDT_RECORD = NUMBER_6310_INTEGER_ARRAY;

/** The examination data display record. */
static int* EXAMINATION_DATA_DISPLAY_XDT_RECORD = NUMBER_6311_INTEGER_ARRAY;

/* XDT_RECORD_CONSTANTS_SOURCE */
#endif
