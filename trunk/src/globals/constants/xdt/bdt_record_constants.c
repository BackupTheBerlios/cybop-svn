/*
 * $RCSfile: bdt_record_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-02-08 23:52:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BDT_RECORD_CONSTANTS_SOURCE
#define BDT_RECORD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer_constants.c"

/**
 * The bdt record identification count.
 *
 * All bdt record identifications have the same length: 4 ASCII characters (bytes).
 */
static int* BDT_RECORD_IDENTIFICATION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The data medium header record. */
static int* DATA_MEDIUM_HEADER_BDT_RECORD = NUMBER_20_INTEGER_ARRAY;

/** The data medium footer record. */
static int* DATA_MEDIUM_FOOTER_BDT_RECORD = NUMBER_21_INTEGER_ARRAY;

/** The data package header record. */
static int* DATA_PACKAGE_HEADER_BDT_RECORD = NUMBER_22_INTEGER_ARRAY;

/** The data package footer record. */
static int* DATA_PACKAGE_FOOTER_BDT_RECORD = NUMBER_23_INTEGER_ARRAY;

/** The patient master data record. */
static int* PATIENT_MASTER_DATA_BDT_RECORD = NUMBER_6100_INTEGER_ARRAY;

/* BDT_RECORD_CONSTANTS_SOURCE */
#endif
