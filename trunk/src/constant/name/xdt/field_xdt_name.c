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
 * @version $RCSfile: field_xdt_name.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FIELD_XDT_NAME_SOURCE
#define FIELD_XDT_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/**
 * The xdt field size count.
 *
 * All xdt field sizes have the same length: 3 ASCII characters (bytes).
 */
static int* XDT_FIELD_SIZE_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The xdt field identification count.
 *
 * All xdt field identifications have the same length: 4 ASCII characters (bytes).
 */
static int* XDT_FIELD_IDENTIFICATION_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The kbv test number field xdt name.
 *
 * German: KBV-Pr�fnummer
 * Size: 7
 * Type: integer
 * Rule: 007
 * Example: 9301001
 */
static int* KBV_TEST_NUMBER_FIELD_XDT_NAME = NUMBER_101_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The responsible entity field xdt name.
 *
 * German: Softwareverantwortlicher
 * Size: <= 60 (taken from GDT; is <= 70 in BDT; therefore the smaller is used)
 * Type: character array
 * Rule: -
 * Example: Medical-Soft
 */
static int* RESPONSIBLE_ENTITY_FIELD_XDT_NAME = NUMBER_102_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The software field xdt name.
 *
 * German: Software
 * Size: <= 60 (taken from GDT; is <= 70 in BDT; therefore the smaller is used)
 * Type: character array
 * Rule: -
 * Example: DOCSFUN
 */
static int* SOFTWARE_FIELD_XDT_NAME = NUMBER_103_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The hardware field xdt name.
 *
 * German: Hardware
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: IBM PC/AT
 */
static int* HARDWARE_FIELD_XDT_NAME = NUMBER_104_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The software release field xdt name.
 *
 * German: Release-Stand der Software
 * Size: <= 60 (taken from GDT; is <= 70 in BDT; therefore the smaller is used)
 * Type: character array
 * Rule: -
 * Example: Version 4.30b
 */
static int* SOFTWARE_RELEASE_FIELD_XDT_NAME = NUMBER_132_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician identification field xdt name.
 *
 * German: Arztnummer
 * Size: 7-9
 * Type: integer
 * Rule: 329
 * Example: 8353839
 */
static int* PHYSICIAN_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_201_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician practice type field xdt name.
 *
 * German: Praxistyp
 * Size: 1
 * Type: integer
 * Rule: 102/330/350
 * Example: 1
 */
static int* PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_NAME = NUMBER_202_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician name field xdt name.
 *
 * German: Arztname
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Hans Hohl
 */
static int* PHYSICIAN_NAME_FIELD_XDT_NAME = NUMBER_203_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician category field xdt name.
 *
 * German: Arztgruppe verbal
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Radiologe
 */
static int* PHYSICIAN_CATEGORY_FIELD_XDT_NAME = NUMBER_204_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician street field xdt name.
 *
 * German: Stra�e
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Hospizstr. 4
 */
static int* PHYSICIAN_STREET_FIELD_XDT_NAME = NUMBER_205_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician postcode and place field xdt name.
 *
 * German: PLZ Ort
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 50859 K�ln
 */
static int* PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_NAME = NUMBER_206_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician with service indicator field xdt name.
 *
 * German: Arzt mit Leistungskennzeichen
 * Size: <= 70
 * Type: character array
 * Rule: 015
 * Example: Dr. Hohl/1
 */
static int* PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_NAME = NUMBER_207_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician phone field xdt name.
 *
 * German: Telefonnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/473962
 */
static int* PHYSICIAN_PHONE_FIELD_XDT_NAME = NUMBER_208_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician fax field xdt name.
 *
 * German: Telefaxnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/473963
 */
static int* PHYSICIAN_FAX_FIELD_XDT_NAME = NUMBER_209_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician modem field xdt name.
 *
 * German: Modemnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/473963
 */
static int* PHYSICIAN_MODEM_FIELD_XDT_NAME = NUMBER_210_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The physician number within practice field xdt name.
 *
 * German: Anzahl �rzte
 * Size: 2
 * Type: integer
 * Rule: 350
 * Example: 02
 */
static int* PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_NAME = NUMBER_225_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 1 name field xdt name.
 *
 * German: Name der ersten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Funktelefonnummer Praxisinhaber
 */
static int* FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_NAME = NUMBER_250_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 1 value field xdt name.
 *
 * German: Inhalt der ersten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0161/1112223
 */
static int* FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_NAME = NUMBER_251_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 2 name field xdt name.
 *
 * German: Name der zweiten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schuhgr��e Praxisinhaber
 */
static int* FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_NAME = NUMBER_252_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 2 value field xdt name.
 *
 * German: Inhalt der zweiten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 43
 */
static int* FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_NAME = NUMBER_253_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 3 name field xdt name.
 *
 * German: Name der dritten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_NAME = NUMBER_254_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 3 value field xdt name.
 *
 * German: Inhalt der dritten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_NAME = NUMBER_255_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 4 name field xdt name.
 *
 * German: Name der vierten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_NAME = NUMBER_256_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 4 value field xdt name.
 *
 * German: Inhalt der vierten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_NAME = NUMBER_257_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 5 name field xdt name.
 *
 * German: Name der f�nften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_NAME = NUMBER_258_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 5 value field xdt name.
 *
 * German: Inhalt der f�nften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_NAME = NUMBER_259_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 6 name field xdt name.
 *
 * German: Name der sechsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_NAME = NUMBER_260_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 6 value field xdt name.
 *
 * German: Inhalt der sechsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_NAME = NUMBER_261_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 7 name field xdt name.
 *
 * German: Name der siebenten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_NAME = NUMBER_262_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 7 value field xdt name.
 *
 * German: Inhalt der siebenten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_NAME = NUMBER_263_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 8 name field xdt name.
 *
 * German: Name der achten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_NAME = NUMBER_264_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 8 value field xdt name.
 *
 * German: Inhalt der achten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_NAME = NUMBER_265_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 9 name field xdt name.
 *
 * German: Name der neunten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_NAME = NUMBER_266_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 9 value field xdt name.
 *
 * German: Inhalt der neunten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_NAME = NUMBER_267_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 10 name field xdt name.
 *
 * German: Name der zehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_NAME = NUMBER_268_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 10 value field xdt name.
 *
 * German: Inhalt der zehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_NAME = NUMBER_269_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 11 name field xdt name.
 *
 * German: Name der elften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_NAME = NUMBER_270_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 11 value field xdt name.
 *
 * German: Inhalt der elften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_NAME = NUMBER_271_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 12 name field xdt name.
 *
 * German: Name der zw�lften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_NAME = NUMBER_272_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 12 value field xdt name.
 *
 * German: Inhalt der zw�lften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_NAME = NUMBER_273_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 13 name field xdt name.
 *
 * German: Name der dreizehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_NAME = NUMBER_274_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 13 value field xdt name.
 *
 * German: Inhalt der dreizehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_NAME = NUMBER_275_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 14 name field xdt name.
 *
 * German: Name der vierzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_NAME = NUMBER_276_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 14 value field xdt name.
 *
 * German: Inhalt der vierzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_NAME = NUMBER_277_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 15 name field xdt name.
 *
 * German: Name der f�nfzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_NAME = NUMBER_278_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 15 value field xdt name.
 *
 * German: Inhalt der f�nfzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_NAME = NUMBER_279_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 16 name field xdt name.
 *
 * German: Name der sechzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_NAME = NUMBER_280_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 16 value field xdt name.
 *
 * German: Inhalt der sechzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_NAME = NUMBER_281_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 17 name field xdt name.
 *
 * German: Name der siebzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_NAME = NUMBER_282_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 17 value field xdt name.
 *
 * German: Inhalt der siebzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_NAME = NUMBER_283_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 18 name field xdt name.
 *
 * German: Name der achzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_NAME = NUMBER_284_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 18 value field xdt name.
 *
 * German: Inhalt der achzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_NAME = NUMBER_285_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 19 name field xdt name.
 *
 * German: Name der neunzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_NAME = NUMBER_286_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 19 value field xdt name.
 *
 * German: Inhalt der neunzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_NAME = NUMBER_287_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 20 name field xdt name.
 *
 * German: Name der zwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_NAME = NUMBER_288_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 20 value field xdt name.
 *
 * German: Inhalt der zwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_NAME = NUMBER_289_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 21 name field xdt name.
 *
 * German: Name der einundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_NAME = NUMBER_290_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 21 value field xdt name.
 *
 * German: Inhalt der einundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_NAME = NUMBER_291_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 22 name field xdt name.
 *
 * German: Name der zweiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_NAME = NUMBER_292_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 22 value field xdt name.
 *
 * German: Inhalt der zweiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_NAME = NUMBER_293_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 23 name field xdt name.
 *
 * German: Name der dreiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_NAME = NUMBER_294_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 23 value field xdt name.
 *
 * German: Inhalt der dreiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_NAME = NUMBER_295_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 24 name field xdt name.
 *
 * German: Name der vierundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_NAME = NUMBER_296_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 24 value field xdt name.
 *
 * German: Inhalt der vierundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_NAME = NUMBER_297_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 25 name field xdt name.
 *
 * German: Name der f�nfundzwanzigsten (letzten) freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Gewicht
 */
static int* FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_NAME = NUMBER_298_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 0010 category 25 value field xdt name.
 *
 * German: Inhalt der f�nfundzwanzigsten (letzten) freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 75 kg
 */
static int* FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_NAME = NUMBER_299_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient identification field xdt name.
 *
 * German: Patientennummer/Patientenkennung
 * Size: <= 10
 * Type: character array (taken from new GDT version; was "integer" in old BDT)
 * Rule: -
 * Example: 12345678
 */
static int* PATIENT_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_3000_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient name affix field xdt name.
 *
 * German: Namenszusatz/Vorsatzwort des Patienten
 * Size: <= 15
 * Type: character array
 * Rule: -
 * Example: von
 */
static int* PATIENT_NAME_AFFIX_FIELD_XDT_NAME = NUMBER_3100_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient last name field xdt name.
 *
 * German: Name des Patienten
 * Size: <= 28
 * Type: character array
 * Rule: -
 * Example: Schmitz
 */
static int* PATIENT_LAST_NAME_FIELD_XDT_NAME = NUMBER_3101_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient first name field xdt name.
 *
 * German: Vorname des Patienten
 * Size: <= 28
 * Type: character array
 * Rule: -
 * Example: Erna
 */
static int* PATIENT_FIRST_NAME_FIELD_XDT_NAME = NUMBER_3102_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient birth date field xdt name.
 *
 * German: Geburtsdatum des Patienten
 * Size: 8
 * Type: date
 * Rule: 020/304
 * Example: 12041946
 */
static int* PATIENT_BIRTH_DATE_FIELD_XDT_NAME = NUMBER_3103_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient title field xdt name.
 *
 * German: Titel des Patienten
 * Size: <= 15
 * Type: character array
 * Rule: -
 * Example: Dr.
 */
static int* PATIENT_TITLE_FIELD_XDT_NAME = NUMBER_3104_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient health insurance number field xdt name.
 *
 * German: Versichertennummer des Patienten
 * Size: <= 12 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: - (taken from new GDT version; was 335 in old BDT)
 * Example: 123456M789
 */
static int* PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_NAME = NUMBER_3105_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient residence field xdt name.
 *
 * German: Wohnort des Patienten
 * Size: <= 30
 * Type: character array
 * Rule: -
 * Example: 50859 Koeln
 */
static int* PATIENT_RESIDENCE_FIELD_XDT_NAME = NUMBER_3106_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient street field xdt name.
 *
 * German: Stra�e des Patienten
 * Size: <= 28
 * Type: character array
 * Rule: -
 * Example: Holzweg 106
 */
static int* PATIENT_STREET_FIELD_XDT_NAME = NUMBER_3107_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient health insurance type field xdt name.
 *
 * Possible values are:
 * M: Mitglied (member)
 * F: Familie (family)
 * R: Rentner (retired, pensioner)
 *
 * German: Versichertenart MFR
 * Size: 1
 * Type: integer
 * Rule: 116
 * Example: 3
 */
static int* PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_NAME = NUMBER_3108_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient sex field xdt name.
 *
 * German: Geschlecht des Patienten
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* PATIENT_SEX_FIELD_XDT_NAME = NUMBER_3110_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient employer field xdt name.
 *
 * German: Arbeitgeber
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: KHD K�ln
 */
static int* PATIENT_EMPLOYER_FIELD_XDT_NAME = NUMBER_3150_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient accident insurance name field xdt name.
 *
 * German: Bezeichnung des Unfallversicherungstr�gers
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: DKV
 */
static int* PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_NAME = NUMBER_3152_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insurant last name field xdt name.
 *
 * German: Name des Hauptversicherten
 * Size: <= 28
 * Type: character array
 * Rule: 338
 * Example: Schmitz
 */
static int* INSURANT_LAST_NAME_FIELD_XDT_NAME = NUMBER_3201_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insurant first name field xdt name.
 *
 * German: Vorname des Hauptversicherten
 * Size: <= 28
 * Type: character array
 * Rule: 338
 * Example: Erwin
 */
static int* INSURANT_FIRST_NAME_FIELD_XDT_NAME = NUMBER_3202_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insurant birth date field xdt name.
 *
 * German: Geburtsdatum des Hauptversicherten
 * Size: 8
 * Type: date
 * Rule: 008/304/338
 * Example: 27091950
 */
static int* INSURANT_BIRTH_DATE_FIELD_XDT_NAME = NUMBER_3203_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insurant residence field xdt name.
 *
 * German: Wohnort des Hauptversicherten
 * Size: <= 30
 * Type: character array
 * Rule: 338
 * Example: 50859 K�ln
 */
static int* INSURANT_RESIDENCE_FIELD_XDT_NAME = NUMBER_3204_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insurant street field xdt name.
 *
 * German: Stra�e des Hauptversicherten
 * Size: <= 28
 * Type: character array
 * Rule: 338
 * Example: Holzweg 106
 */
static int* INSURANT_STREET_FIELD_XDT_NAME = NUMBER_3205_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The injured phone field xdt name.
 *
 * German: Telefonnummer des Verletzten
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 02234/76056
 */
static int* INJURED_PHONE_FIELD_XDT_NAME = NUMBER_3208_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insurant sex field xdt name.
 *
 * German: Geschlecht des Hauptversicherten
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* INSURANT_SEX_FIELD_XDT_NAME = NUMBER_3210_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient x-ray number field xdt name.
 *
 * German: R�ntgennummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: r�12345g
 */
static int* PATIENT_X_RAY_NUMBER_FIELD_XDT_NAME = NUMBER_3601_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient archive number field xdt name.
 *
 * German: Archivnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: a120446
 */
static int* PATIENT_ARCHIVE_NUMBER_FIELD_XDT_NAME = NUMBER_3602_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient employers' liability insurance association number field xdt name.
 *
 * German: BG-Nummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 123jdh22
 */
static int* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_NAME = NUMBER_3603_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient since date field xdt name.
 *
 * German: Patient seit
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 03041976
 */
static int* PATIENT_SINCE_DATE_FIELD_XDT_NAME = NUMBER_3610_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient change of insurance inception date field xdt name.
 *
 * German: Versicherungsbeginn bei Kassenwechsel
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 12041993
 */
static int* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_NAME = NUMBER_3612_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient profession field xdt name.
 *
 * German: Beruf des Patienten
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Metzger
 */
static int* PATIENT_PROFESSION_FIELD_XDT_NAME = NUMBER_3620_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient body height field xdt name.
 *
 * German: Gr��e des Patienten in cm
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 175.50
 */
static int* PATIENT_BODY_HEIGHT_FIELD_XDT_NAME = NUMBER_3622_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient body weight field xdt name.
 *
 * German: Gewicht des Patienten in kg
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 90.50
 */
static int* PATIENT_BODY_WEIGHT_FIELD_XDT_NAME = NUMBER_3623_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient employer field xdt name.
 *
 * German: Arbeitgeber des Patienten
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: M�ller AG
 */
static int* PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_NAME = NUMBER_3625_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient phone field xdt name.
 *
 * German: Telefonnummer Patient
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 02234/111
 */
static int* PATIENT_PHONE_FIELD_XDT_NAME = NUMBER_3626_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient nationality field xdt name.
 *
 * German: Nationalit�t Patient
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: deutsch
 */
static int* PATIENT_NATIONALITY_FIELD_XDT_NAME = NUMBER_3627_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient mother tongue field xdt name.
 *
 * German: Muttersprache
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: t�rkisch
 */
static int* PATIENT_MOTHER_TONGUE_FIELD_XDT_NAME = NUMBER_3628_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient general practitioner identification field xdt name.
 *
 * German: Arztnummer Hausarzt
 * Size: 7-9
 * Type: integer
 * Rule: -
 * Example: 0119950
 */
static int* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_3630_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient residence to medical practice distance field xdt name.
 *
 * German: Entfernung Wohnort-Praxis
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Z1, 3.5
 */
static int* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_NAME = NUMBER_3631_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient physician identification in group practice field xdt name.
 *
 * German: Interne Zuordnung Arzt bei Gemeinschaftspraxen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. M�ller
 */
static int* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_NAME = NUMBER_3635_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient prescription identification field xdt name.
 *
 * German: Rezeptkennung
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 1
 */
static int* PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_3637_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient permanent diagnoses begin date field xdt name.
 *
 * German: Dauerdiagnosen ab Datum
 * Size: 8
 * Type: date
 * Rule: -
 * Example: 01011990
 */
static int* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_NAME = NUMBER_3649_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient permanent diagnoses field xdt name.
 *
 * German: Dauerdiagnosen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Diabetes mellitus
 */
static int* PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_NAME = NUMBER_3650_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient permanent drugs begin date field xdt name.
 *
 * German: Dauermedikamente ab Datum
 * Size: 8
 * Type: date
 * Rule: -
 * Example: 01011990
 */
static int* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_NAME = NUMBER_3651_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient permanent drugs field xdt name.
 *
 * German: Dauermedikamente
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Adalat
 */
static int* PATIENT_PERMANENT_DRUGS_FIELD_XDT_NAME = NUMBER_3652_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient risk factors field xdt name.
 *
 * German: Risikofaktoren
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Raucher
 */
static int* PATIENT_RISK_FACTORS_FIELD_XDT_NAME = NUMBER_3654_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient allergies field xdt name.
 *
 * German: Allergien
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Neurodermitis
 */
static int* PATIENT_ALLERGIES_FIELD_XDT_NAME = NUMBER_3656_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient accidents field xdt name.
 *
 * German: Unf�lle
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Motorradunfall
 */
static int* PATIENT_ACCIDENTS_FIELD_XDT_NAME = NUMBER_3658_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient surgeries field xdt name.
 *
 * German: Operationen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Blinddarm
 */
static int* PATIENT_SURGERIES_FIELD_XDT_NAME = NUMBER_3660_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient anamnesis field xdt name.
 *
 * German: Anamnese
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Fr�hgeburt
 */
static int* PATIENT_ANAMNESIS_FIELD_XDT_NAME = NUMBER_3662_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient number of births field xdt name.
 *
 * German: Anzahl Geburten
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 2
 */
static int* PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_NAME = NUMBER_3664_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient number of children field xdt name.
 *
 * German: Anzahl Kinder
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 3
 */
static int* PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_NAME = NUMBER_3666_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient number of pregnancies field xdt name.
 *
 * German: Anzahl Schwangerschaften
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 4
 */
static int* PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_NAME = NUMBER_3668_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient permanent therapy field xdt name.
 *
 * German: Dauertherapie
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Massagen
 */
static int* PATIENT_PERMANENT_THERAPY_FIELD_XDT_NAME = NUMBER_3670_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The patient recall appointment date field xdt name.
 *
 * German: Kontrolltermine
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 01121993
 */
static int* PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_NAME = NUMBER_3672_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 1 name field xdt name.
 *
 * German: Name der ersten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: K�rpergr��e
 */
static int* FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_NAME = NUMBER_3700_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 1 value field xdt name.
 *
 * German: Inhalt der ersten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 183 cm
 */
static int* FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_NAME = NUMBER_3701_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 2 name field xdt name.
 *
 * German: Name der zweiten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Gewicht
 */
static int* FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_NAME = NUMBER_3702_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 2 value field xdt name.
 *
 * German: Inhalt der zweiten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 75 kg
 */
static int* FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_NAME = NUMBER_3703_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 3 name field xdt name.
 *
 * German: Name der dritten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_NAME = NUMBER_3704_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 3 value field xdt name.
 *
 * German: Inhalt der dritten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_NAME = NUMBER_3705_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 4 name field xdt name.
 *
 * German: Name der vierten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_NAME = NUMBER_3706_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 4 value field xdt name.
 *
 * German: Inhalt der vierten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_NAME = NUMBER_3707_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 5 name field xdt name.
 *
 * German: Name der f�nften freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_NAME = NUMBER_3708_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 5 value field xdt name.
 *
 * German: Inhalt der f�nften freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_NAME = NUMBER_3709_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 6 name field xdt name.
 *
 * German: Name der sechsten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_NAME = NUMBER_3710_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 6 value field xdt name.
 *
 * German: Inhalt der sechsten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_NAME = NUMBER_3711_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 7 name field xdt name.
 *
 * German: Name der siebten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_NAME = NUMBER_3712_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 7 value field xdt name.
 *
 * German: Inhalt der siebten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_NAME = NUMBER_3713_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 8 name field xdt name.
 *
 * German: Name der achten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_NAME = NUMBER_3714_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 8 value field xdt name.
 *
 * German: Inhalt der achten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_NAME = NUMBER_3715_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 9 name field xdt name.
 *
 * German: Name der neunten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_NAME = NUMBER_3716_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 9 value field xdt name.
 *
 * German: Inhalt der neunten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_NAME = NUMBER_3717_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 10 name field xdt name.
 *
 * German: Name der zehnten (letzten) freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Gewicht
 */
static int* FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_NAME = NUMBER_3718_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6100 category 10 value field xdt name.
 *
 * German: Inhalt der zehnten (letzten) freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 75 kg
 */
static int* FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_NAME = NUMBER_3719_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice quarter field xdt name.
 *
 * German: Quartal der Abrechnung
 * Size: 5
 * Type: integer
 * Rule: 016
 * Example: 31993
 */
static int* INVOICE_QUARTER_FIELD_XDT_NAME = NUMBER_4101_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice issuance date field xdt name.
 *
 * German: Ausstellungsdatum
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 07081993
 */
static int* INVOICE_ISSUANCE_DATE_FIELD_XDT_NAME = NUMBER_4102_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice validity date field xdt name.
 *
 * German: G�ltigkeitsdatum
 * Size: 8
 * Type: date
 * Rule: 008/314/338
 * Example: 20091993
 */
static int* INVOICE_VALIDITY_DATE_FIELD_XDT_NAME = NUMBER_4103_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice insurance number field xdt name.
 *
 * German: Kassennummer (VKNR)
 * Size: 5
 * Type: integer
 * Rule: 017/201
 * Example: 27106
 */
static int* INVOICE_INSURANCE_NUMBER_FIELD_XDT_NAME = NUMBER_4104_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice insurance office field xdt name.
 *
 * German: Gesch�ftsstelle
 * Size: <= 70
 * Type: character array
 * Rule: 338
 * Example: K�ln
 */
static int* INVOICE_INSURANCE_OFFICE_FIELD_XDT_NAME = NUMBER_4105_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice insurance sub category field xdt name.
 *
 * German: Kostentr�geruntergruppe
 * Size: 2
 * Type: integer
 * Rule: 126
 * Example: 00
 */
static int* INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_NAME = NUMBER_4106_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice billing category field xdt name.
 *
 * German: Abrechnungsart (Schein)
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 1
 */
static int* INVOICE_BILLING_CATEGORY_FIELD_XDT_NAME = NUMBER_4107_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice insurance card last read access field xdt name.
 *
 * German: Letzter Einlesetag der VK-Karte im Quartal
 * Size: 8
 * Type: date
 * Rule: 008/335
 * Example: 07081993
 */
static int* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_NAME = NUMBER_4109_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice insurance card validity date field xdt name.
 *
 * German: Bis-Datum der G�ltigkeit
 * Size: 4
 * Type: integer
 * Rule: 014/335
 * Example: 1291
 */
static int* INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_NAME = NUMBER_4110_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice ik insurance number field xdt name.
 *
 * German: Krankenkassennummer (IK)
 * Size: 7
 * Type: integer
 * Rule: 018/335
 * Example: 1568008
 */
static int* INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_NAME = NUMBER_4111_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice vk insurance status field xdt name.
 *
 * German: Versichertenstatus VK
 * Size: 4
 * Type: integer
 * Rule: 335
 * Example: 1000
 */
static int* INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_NAME = NUMBER_4112_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice vk east-west status field xdt name.
 *
 * German: Ost/West-Status VK
 * Size: 1
 * Type: integer
 * Rule: 117/335
 * Example: 1
 */
static int* INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_NAME = NUMBER_4113_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice billing scale field xdt name.
 *
 * German: Geb�hrenordnung
 * Size: 1
 * Type: integer
 * Rule: 106/323/325
 * Example: 1
 */
static int* INVOICE_BILLING_SCALE_FIELD_XDT_NAME = NUMBER_4121_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice billing area field xdt name.
 *
 * German: Abrechnungsgebiet
 * Size: 2
 * Type: integer
 * Rule: 119
 * Example: 00
 */
static int* INVOICE_BILLING_AREA_FIELD_XDT_NAME = NUMBER_4122_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral cause of pain field xdt name.
 *
 * German: Ursache des Leidens
 * Size: 1
 * Type: integer
 * Rule: 120
 * Example: 2
 */
static int* REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_NAME = NUMBER_4201_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral supposed accouchement date field xdt name.
 *
 * German: Mutma�licher Tag der Entbindung
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 22011994
 */
static int* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_NAME = NUMBER_4206_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral diagnosis field xdt name.
 *
 * German: Diagnose/Verdacht
 * Size: <= 70
 * Type: character array
 * Rule: 322
 * Example: Tumorverdacht
 */
static int* REFERRAL_DIAGNOSIS_FIELD_XDT_NAME = NUMBER_4207_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral explanation field xdt name.
 *
 * German: Erl�uternder Text zur �berweisung
 * Size: <= 70
 * Type: character array
 * Rule: 321
 * Example: R�ntgen
 */
static int* REFERRAL_EXPLANATION_FIELD_XDT_NAME = NUMBER_4209_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral check box muvo lsr field xdt name.
 *
 * German: Ankreuzfeld Muvo LSR
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_NAME = NUMBER_4210_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral check box muvo hah field xdt name.
 *
 * German: Ankreuzfeld Muvo HAH
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_NAME = NUMBER_4211_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral check box ab0 rh field xdt name.
 *
 * German: Ankreuzfeld Ab0/Rh
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_NAME = NUMBER_4212_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral check box ak field xdt name.
 *
 * German: Ankreuzfeld AK
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_AK_FIELD_XDT_NAME = NUMBER_4213_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral from physician number field xdt name.
 *
 * German: �berweisung von Arztnummer
 * Size: 7-9
 * Type: integer
 * Rule: -
 * Example: 381953910
 */
static int* REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_NAME = NUMBER_4218_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The referral to physician name field xdt name.
 *
 * German: �berweisung an
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Bergmann
 */
static int* REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_NAME = NUMBER_4220_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The inpatient treatment referral by law field xdt name.
 *
 * German: Gesetzlicher Abzug zur station�ren Behandlung gem�� � 6a GO�
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_NAME = NUMBER_4230_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The inpatient treatment from to field xdt name.
 *
 * German: Station�re Behandlung von ... bis ...
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 0708199320081993
 */
static int* INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_NAME = NUMBER_4233_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The inpatient treatment class field xdt name.
 *
 * German: Klasse bei station�rer Behandlung
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 2
 */
static int* INPATIENT_TREATMENT_CLASS_FIELD_XDT_NAME = NUMBER_4236_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The inpatient hospital name field xdt name.
 *
 * German: Krankenhaus-Name
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Uniklinik
 */
static int* INPATIENT_HOSPITAL_NAME_FIELD_XDT_NAME = NUMBER_4237_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The inpatient hospital stay field xdt name.
 *
 * German: Krankenhausaufenthalt
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 330
 */
static int* INPATIENT_HOSPITAL_STAY_FIELD_XDT_NAME = NUMBER_4238_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The invoice sub category field xdt name.
 *
 * German: Scheinuntergruppe
 * Size: 2
 * Type: integer
 * Rule: 321/322/331/332/333/334
 * Example: 00
 */
static int* INVOICE_SUB_CATEGORY_FIELD_XDT_NAME = NUMBER_4239_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The emergency subsequent treatment physician name field xdt name.
 *
 * German: Weiterbehandelnder Arzt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Meier
 */
static int* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_NAME = NUMBER_4243_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The emergency findings field xdt name.
 *
 * German: Befund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Bandruptur
 */
static int* EMERGENCY_FINDINGS_FIELD_XDT_NAME = NUMBER_4267_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The emergency symptoms field xdt name.
 *
 * German: Symptome
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schwellung des li. Sprunggelenkes
 */
static int* EMERGENCY_SYMPTOMS_FIELD_XDT_NAME = NUMBER_4268_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident date field xdt name.
 *
 * German: Unfalltag
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_DATE_FIELD_XDT_NAME = NUMBER_4500_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident time field xdt name.
 *
 * German: Uhrzeit des Unfalls
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1020
 */
static int* ACCIDENT_TIME_FIELD_XDT_NAME = NUMBER_4501_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient admission in practice date field xdt name.
 *
 * German: Eingetroffen in Praxis am
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_NAME = NUMBER_4502_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient admission in practice time field xdt name.
 *
 * German: Uhrzeit des Eintreffens
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1030
 */
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_NAME = NUMBER_4503_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient labour time begin field xdt name.
 *
 * German: Beginn Arbeitszeit
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 0715
 */
static int* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_NAME = NUMBER_4504_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident location field xdt name.
 *
 * German: Unfallort
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Baustelle
 */
static int* ACCIDENT_LOCATION_FIELD_XDT_NAME = NUMBER_4505_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient employment as field xdt name.
 *
 * German: Besch�ftigung als
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Tischler
 */
static int* ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_NAME = NUMBER_4506_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient employment since field xdt name.
 *
 * German: Besch�ftigt seit
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 01011980
 */
static int* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_NAME = NUMBER_4507_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient nationality field xdt name.
 *
 * German: Staatsangeh�rigkeit
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: deutsch
 */
static int* ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_NAME = NUMBER_4508_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident company field xdt name.
 *
 * German: Unfallbetrieb
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Betriebshof Mitte
 */
static int* ACCIDENT_COMPANY_FIELD_XDT_NAME = NUMBER_4509_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident course of events field xdt name.
 *
 * German: Unfallhergang
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Abrutschen von Leiter
 */
static int* ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_NAME = NUMBER_4510_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident patient behaviour afterwards field xdt name.
 *
 * German: Verhalten des Verletzten nach dem Unfall
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Aufsuchen des Krankenhauses
 */
static int* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_NAME = NUMBER_4512_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident first time treatment date field xdt name.
 *
 * German: Erstmalige Behandlung
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_NAME = NUMBER_4513_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident treatment by physician name field xdt name.
 *
 * German: Behandlung durch
 * Size: 8
 * Type: character array
 * Rule: 008
 * Example: Dr. Sinn
 */
static int* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_NAME = NUMBER_4514_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident kind of treatment field xdt name.
 *
 * German: Art dieser ersten �rztlichen Behandlung
 * Size: <= 70
 * Type: character array
 * Rule: --
 * Example: Erstversorgung Fraktur
 */
static int* ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_NAME = NUMBER_4515_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident alcohol influence field xdt name.
 *
 * German: Alkoholeinflu�
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_NAME = NUMBER_4520_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident signs for alcohol influence field xdt name.
 *
 * German: Anzeichen des Alkoholeinflusses
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Nein
 */
static int* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_NAME = NUMBER_4521_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident blood withdrawal field xdt name.
 *
 * German: Blutentnahme
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_NAME = NUMBER_4522_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident findings field xdt name.
 *
 * German: Befund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: erh�hter Blutdruck
 */
static int* ACCIDENT_FINDINGS_FIELD_XDT_NAME = NUMBER_4530_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident x-ray result field xdt name.
 *
 * German: R�ntgenergebnis
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sprunggelenktorsion
 */
static int* ACCIDENT_X_RAY_RESULT_FIELD_XDT_NAME = NUMBER_4540_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident kind of first treatment field xdt name.
 *
 * German: Art etwaiger Erstversorgung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schienung Fraktur
 */
static int* ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_NAME = NUMBER_4550_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident abnormal changes independent from accident field xdt name.
 *
 * German: Krankhafte Ver�nderungen unabh�ngig vom Unfall
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_NAME = NUMBER_4551_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident concerns against statements field xdt name.
 *
 * German: Bedenken gegen Angaben
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: -
 */
static int* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_NAME = NUMBER_4552_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident kind of concerns against statements field xdt name.
 *
 * German: Art der Bedenken
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_NAME = NUMBER_4553_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident concerns against classification as accident at work field xdt name.
 *
 * German: Bedenken gegen Vorliegen eines Arbeitsunfalles
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_NAME = NUMBER_4554_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident kind of concerns against classification as accident at work field xdt name.
 *
 * German: Art der Bedenken
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: keine versicherte T�tigkeit
 */
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_NAME = NUMBER_4555_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident able to work field xdt name.
 *
 * German: arbeitsf�hig
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* ACCIDENT_ABLE_TO_WORK_FIELD_XDT_NAME = NUMBER_4560_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident able to work from field xdt name.
 *
 * German: wieder arbeitsf�hig ab
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 01121993
 */
static int* ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_NAME = NUMBER_4561_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident unable to work certificate issuance field xdt name.
 *
 * German: AU-Bescheinigung ausgestellt
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_NAME = NUMBER_4562_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident special curative treatment necessary field xdt name.
 *
 * German: Besondere Heilbehandlung erforderlich
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_NAME = NUMBER_4570_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident special curative treatment by field xdt name.
 *
 * German: Besondere Heilbehandlung durch
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_NAME = NUMBER_4571_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident address of treating physician field xdt name.
 *
 * German: Anschrift des behandelnden Arztes
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Herbst
 */
static int* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_NAME = NUMBER_4572_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident unable to work from field xdt name.
 *
 * German: AU ab
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 13121993
 */
static int* ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_NAME = NUMBER_4573_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident expected duration of inability to work field xdt name.
 *
 * German: voraussichtliche Dauer der AU
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 012
 */
static int* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_NAME = NUMBER_4574_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident kind of bill field xdt name.
 *
 * German: Rechnungsart
 * Size: 2
 * Type: integer
 * Rule: -
 * Example: 80
 */
static int* ACCIDENT_KIND_OF_BILL_FIELD_XDT_NAME = NUMBER_4580_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident general curative treatment by field xdt name.
 *
 * German: Allgemeine Heilbehandlung durch
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_NAME = NUMBER_4581_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident unable to work for longer than three days field xdt name.
 *
 * German: AU �ber 3 Tage
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_NAME = NUMBER_4582_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident unability to work certified until field xdt name.
 *
 * German: AU bescheinigt bis
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_NAME = NUMBER_4583_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The accident inspection required on field xdt name.
 *
 * German: Nachschau erforderlich am
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11111993
 */
static int* ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_NAME = NUMBER_4584_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing number field xdt name.
 *
 * German: Rechnungsnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 54/66
 */
static int* BILLING_NUMBER_FIELD_XDT_NAME = NUMBER_4601_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing address field xdt name.
 *
 * German: Rechnungsanschrift
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Erwin M�ller
 *          Ottostra�e 123
 *          50859 K�ln
 */
static int* BILLING_ADDRESS_FIELD_XDT_NAME = NUMBER_4602_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing referring physician name field xdt name.
 *
 * German: �berweisender Arzt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Regenbogen
 */
static int* BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_NAME = NUMBER_4603_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing date field xdt name.
 *
 * German: Rechnungsdatum
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* BILLING_DATE_FIELD_XDT_NAME = NUMBER_4604_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing total sum field xdt name.
 *
 * German: Endsumme
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2130 DM
 */
static int* BILLING_TOTAL_SUM_FIELD_XDT_NAME = NUMBER_4605_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing assignment declaration field xdt name.
 *
 * German: Abdingungserkl�rung
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_NAME = NUMBER_4608_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing physician sub account field xdt name.
 *
 * German: Unterkonto Arzt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2000
 */
static int* BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_NAME = NUMBER_4611_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing attachment field xdt name.
 *
 * German: Anlage zur Rechnung
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* BILLING_ATTACHMENT_FIELD_XDT_NAME = NUMBER_4613_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing header field xdt name.
 *
 * German: Kopfzeile
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Rechn. v. 01.07.92
 */
static int* BILLING_HEADER_FIELD_XDT_NAME = NUMBER_4615_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing footer field xdt name.
 *
 * German: Fu�zeile
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Alle Angaben sind streng vertraulich
 */
static int* BILLING_FOOTER_FIELD_XDT_NAME = NUMBER_4617_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service treatment date field xdt name.
 *
 * German: Leistungstag
 * Size: 8
 * Type: date
 * Rule: 008/304/324
 * Example: 11101993
 */
static int* SERVICE_TREATMENT_DATE_FIELD_XDT_NAME = NUMBER_5000_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service gnr identification field xdt name.
 *
 * German: GNR/GNR-Ident
 * Size: 1-7
 * Type: character array
 * Rule: -
 * Example: 61
 */
static int* SERVICE_GNR_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_5001_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service kind of examination field xdt name.
 *
 * German: Art der Untersuchung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Esterasereaktion
 */
static int* SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_NAME = NUMBER_5002_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service addressee field xdt name.
 *
 * German: Empf�nger des Briefes
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Meier
 */
static int* SERVICE_ADDRESSEE_FIELD_XDT_NAME = NUMBER_5003_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service distance in kilometres field xdt name.
 *
 * German: Kilometer (nur bei GO�)
 * Size: 1-3
 * Type: integer
 * Rule: 325
 * Example: 17
 */
static int* SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_NAME = NUMBER_5004_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service multiplier field xdt name.
 *
 * German: Multiplikator
 * Size: 2
 * Type: integer
 * Rule: -
 * Example: 3
 */
static int* SERVICE_MULTIPLIER_FIELD_XDT_NAME = NUMBER_5005_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service time field xdt name.
 *
 * German: Um-Uhrzeit
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1215
 */
static int* SERVICE_TIME_FIELD_XDT_NAME = NUMBER_5006_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service order-execution time field xdt name.
 *
 * German: Bestellzeit-Ausf�hrungszeit
 * Size: 8
 * Type: integer
 * Rule: 006
 * Example: 12151230
 */
static int* SERVICE_ORDER_EXECUTION_FIELD_XDT_NAME = NUMBER_5007_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service dkm field xdt name.
 *
 * German: DKM
 * Size: 1-3
 * Type: integer
 * Rule: -
 * Example: 23
 */
static int* SERVICE_DKM_FIELD_XDT_NAME = NUMBER_5008_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service free explanatory statement field xdt name.
 *
 * German: freier Begr�ndungstext
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2. Untersuchung
 */
static int* SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_NAME = NUMBER_5009_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service explanatory drug field xdt name.
 *
 * German: Medikament als Begr�ndung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Insulin
 */
static int* SERVICE_EXPLANATORY_DRUG_FIELD_XDT_NAME = NUMBER_5010_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service material costs description field xdt name.
 *
 * German: Sachkosten-Bezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Norm-Silberstift
 */
static int* SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_NAME = NUMBER_5011_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service material costs dpf field xdt name.
 *
 * German: Sachkosten-/Materialkosten (Dpf)
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 12345
 */
static int* SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_NAME = NUMBER_5012_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service percent of treatment field xdt name.
 *
 * German: Prozent der Leistung
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 50
 */
static int* SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_NAME = NUMBER_5013_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service organ field xdt name.
 *
 * German: Organ
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Niere
 */
static int* SERVICE_ORGAN_FIELD_XDT_NAME = NUMBER_5015_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service location field xdt name.
 *
 * German: Besuchsort bei Hausbesuchen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Neustadt
 */
static int* SERVICE_LOCATION_FIELD_XDT_NAME = NUMBER_5017_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service zone field xdt name.
 *
 * German: Zone bei Besuchen
 * Size: 2
 * Type: integer
 * Rule: 111
 * Example: Z1
 */
static int* SERVICE_ZONE_FIELD_XDT_NAME = NUMBER_5018_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service gnr description field xdt name.
 *
 * German: Beschreibung der GNR bei Privatabrechnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Injektion, intraven�s
 */
static int* SERVICE_GNR_DESCRIPTION_FIELD_XDT_NAME = NUMBER_5060_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service fee field xdt name.
 *
 * German: Geb�hr bei Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 12.80
 */
static int* SERVICE_FEE_FIELD_XDT_NAME = NUMBER_5061_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service factor field xdt name.
 *
 * German: Faktor bei Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 2.3
 */
static int* SERVICE_FACTOR_FIELD_XDT_NAME = NUMBER_5062_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service sum field xdt name.
 *
 * German: Betrag bei Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 25.85
 */
static int* SERVICE_SUM_FIELD_XDT_NAME = NUMBER_5063_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service total sum field xdt name.
 *
 * German: Endsumme Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 1324.65
 */
static int* SERVICE_TOTAL_SUM_FIELD_XDT_NAME = NUMBER_5064_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service point value field xdt name.
 *
 * German: Punktwert
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 18
 */
static int* SERVICE_POINT_VALUE_FIELD_XDT_NAME = NUMBER_5065_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service name of fee field xdt name.
 *
 * German: Honorarbezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 18
 */
static int* SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_FEE_FIELD_XDT_NAME = NUMBER_5090_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The service name of certificate field xdt name.
 *
 * German: Gutachten-Bezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 18
 */
static int* SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_NAME = NUMBER_5091_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing diagnosis field xdt name.
 *
 * German: Abrechnungsdiagnose
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Diabetes mellitus
 */
static int* BILLING_DIAGNOSIS_FIELD_XDT_NAME = NUMBER_6000_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The billing icd key field xdt name.
 *
 * German: ICD-Schl�ssel
 * Size: 5
 * Type: character array
 * Rule: -
 * Example: 250.0
 */
static int* BILLING_ICD_KEY_FIELD_XDT_NAME = NUMBER_6001_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment data storage date field xdt name.
 *
 * German: Tag der Erhebung von Behandlungsdaten (taken from new GDT version;
 *         was "Tag der Speicherung von Behandlungsdaten" in old BDT)
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 12031993
 */
static int* TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_NAME = NUMBER_6200_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment data storage time field xdt name.
 *
 * German: Uhrzeit der Erhebung von Behandlungsdaten
 * Size: 6
 * Type: time
 * Rule: 090 HHMMSS
 * Example: 132201
 */
static int* TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_NAME = NUMBER_6201_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment current diagnosis field xdt name.
 *
 * German: Aktuelle Diagnose
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Diabetes
 */
static int* TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_NAME = NUMBER_6205_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment drug prescribed with prescription field xdt name.
 *
 * German: Medikament verordnet auf Rezept
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Adalat
 */
static int* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_NAME = NUMBER_6210_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment drug prescribed without prescription field xdt name.
 *
 * German: Au�erhalb Rezept verordnetes Medikament
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sostril
 */
static int* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_NAME = NUMBER_6211_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment physician sample field xdt name.
 *
 * German: �rztemuster
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Nifedepin
 */
static int* TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_NAME = NUMBER_6215_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment findings field xdt name.
 *
 * German: Befund
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: erh�hter Blutdruck
 */
static int* TREATMENT_FINDINGS_FIELD_XDT_NAME = NUMBER_6220_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment external findings field xdt name.
 *
 * German: Fremdbefund
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Verdacht auf Obstruktion (taken from new GDT version; was "Bartolin.-cyste, re" in old BDT)
 */
static int* TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_NAME = NUMBER_6221_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment laboratory findings field xdt name.
 *
 * German: Laborbefund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Eiwei� erh�ht
 */
static int* TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_NAME = NUMBER_6222_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment x-ray findings field xdt name.
 *
 * German: R�ntgenbefund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schatten auf Lunge
 */
static int* TREATMENT_X_RAY_FINDINGS_FIELD_XDT_NAME = NUMBER_6225_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment subsequent line count field xdt name.
 *
 * German: Anzahl Folgezeilen
 * Size: <= 4
 * Type: integer
 * Rule: -
 * Example: 2
 */
static int* TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_NAME = NUMBER_6226_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment comment field xdt name.
 *
 * German: Kommentar
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: Belastung abgebrochen
 */
static int* TREATMENT_COMMENT_FIELD_XDT_NAME = NUMBER_6227_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment formatted result table text field xdt name.
 *
 * German: Ergebnistabellentext, formatiert
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: s. Beispiele im Anhang
 */
static int* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_NAME = NUMBER_6228_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment blood pressure field xdt name.
 *
 * German: Blutdruck
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 140/90
 */
static int* TREATMENT_BLOOD_PRESSURE_FIELD_XDT_NAME = NUMBER_6230_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment symptoms field xdt name.
 *
 * German: Symptome
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Haarausfall
 */
static int* TREATMENT_SYMPTOMS_FIELD_XDT_NAME = NUMBER_6240_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment therapy field xdt name.
 *
 * German: Therapie
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Novalgin 3x t�glich
 */
static int* TREATMENT_THERAPY_FIELD_XDT_NAME = NUMBER_6260_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment physical therapy field xdt name.
 *
 * German: Physikalische Therapie
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Massagen
 */
static int* TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_NAME = NUMBER_6265_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment referral content field xdt name.
 *
 * German: �berweisung Inhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: R�ntgen Thorax
 */
static int* TREATMENT_REFERRAL_CONTENT_FIELD_XDT_NAME = NUMBER_6280_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment work disability duration field xdt name.
 *
 * German: AU Dauer
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 1110199311111993
 */
static int* TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_NAME = NUMBER_6285_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment work disability cause field xdt name.
 *
 * German: AU wegen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Nasenbeinfraktur
 */
static int* TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_NAME = NUMBER_6286_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment hospitalisation field xdt name.
 *
 * German: Krankenhauseinweisung, Krankenhaus
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Marienhospital
 */
static int* TREATMENT_HOSPITALISATION_FIELD_XDT_NAME = NUMBER_6290_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The treatment hospitalisation cause field xdt name.
 *
 * German: Krankenhauseinweisung wegen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: stark blutende Wunde
 */
static int* TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_NAME = NUMBER_6291_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter certificate kind field xdt name.
 *
 * German: Bescheinigung, Art
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Impfbescheinigung
 */
static int* LETTER_CERTIFICATE_KIND_FIELD_XDT_NAME = NUMBER_6300_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter certificate content field xdt name.
 *
 * German: Bescheinigung, Inhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Tetanusschutzimpfung
 */
static int* LETTER_CERTIFICATE_CONTENT_FIELD_XDT_NAME = NUMBER_6301_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter file archive number field xdt name.
 *
 * German: Datei-Archivierungsnummer
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: 000001
 */
static int* LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_NAME = NUMBER_6302_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter file format field xdt name.
 *
 * German: Dateiformat
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: PDF
 */
static int* LETTER_FILE_FORMAT_FIELD_XDT_NAME = NUMBER_6303_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter file content field xdt name.
 *
 * German: Dateiinhalt
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: Datenanalyse
 */
static int* LETTER_FILE_CONTENT_FIELD_XDT_NAME = NUMBER_6304_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter file url field xdt name.
 *
 * German: Verweis auf Datei (URL)
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: \\FS1\DATA\00712.PDF
 */
static int* LETTER_FILE_URL_FIELD_XDT_NAME = NUMBER_6305_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter attestation kind field xdt name.
 *
 * German: Attest, Art
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sportbefreiungsattest
 */
static int* LETTER_ATTESTATION_KIND_FIELD_XDT_NAME = NUMBER_6306_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter attestation content field xdt name.
 *
 * German: Attest, Inhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Lebensmittelallergie
 */
static int* LETTER_ATTESTATION_CONTENT_FIELD_XDT_NAME = NUMBER_6307_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter addressee field xdt name.
 *
 * German: Name des Briefempf�ngers
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Egon M�ller
 */
static int* LETTER_ADDRESSEE_FIELD_XDT_NAME = NUMBER_6310_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter salutation field xdt name.
 *
 * German: Anrede
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Herrn Dr.
 */
static int* LETTER_SALUTATION_FIELD_XDT_NAME = NUMBER_6311_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter street field xdt name.
 *
 * German: Stra�e
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Moltkestr. 108
 */
static int* LETTER_STREET_FIELD_XDT_NAME = NUMBER_6312_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter postcode field xdt name.
 *
 * German: PLZ
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 50859
 */
static int* LETTER_POSTCODE_FIELD_XDT_NAME = NUMBER_6313_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter residence field xdt name.
 *
 * German: Wohnort
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: K�ln
 */
static int* LETTER_RESIDENCE_FIELD_XDT_NAME = NUMBER_6314_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter complimentary close field xdt name.
 *
 * German: Schlu�satz
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Mit kollegialem Gru�
 */
static int* LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_NAME = NUMBER_6315_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter phone field xdt name.
 *
 * German: Telefon-Nummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/123456
 */
static int* LETTER_PHONE_FIELD_XDT_NAME = NUMBER_6316_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter fax field xdt name.
 *
 * German: Telefax-Nummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/123675
 */
static int* LETTER_FAX_FIELD_XDT_NAME = NUMBER_6317_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter physician number field xdt name.
 *
 * German: Arztnummer/Arztident
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2780100
 */
static int* LETTER_PHYSICIAN_NUMBER_FIELD_XDT_NAME = NUMBER_6319_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter content field xdt name.
 *
 * German: Briefinhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sehr geehrter ...
 */
static int* LETTER_CONTENT_FIELD_XDT_NAME = NUMBER_6320_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter image archive number field xdt name.
 *
 * German: Bild-Archivierungsnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 3735
 */
static int* LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_NAME = NUMBER_6325_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter graphic format field xdt name.
 *
 * German: Grafikformat
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: PIF
 */
static int* LETTER_GRAPHIC_FORMAT_FIELD_XDT_NAME = NUMBER_6326_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The letter image content field xdt name.
 *
 * German: Bildinhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* LETTER_IMAGE_CONTENT_FIELD_XDT_NAME = NUMBER_6327_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 1 name field xdt name.
 *
 * German: Name der ersten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_NAME = NUMBER_6330_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 1 value field xdt name.
 *
 * German: Inhalt der ersten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_NAME = NUMBER_6331_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 2 name field xdt name.
 *
 * German: Name der zweiten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_NAME = NUMBER_6332_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 2 value field xdt name.
 *
 * German: Inhalt der zweiten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_NAME = NUMBER_6333_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 3 name field xdt name.
 *
 * German: Name der dritten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_NAME = NUMBER_6334_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 3 value field xdt name.
 *
 * German: Inhalt der dritten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_NAME = NUMBER_6335_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 4 name field xdt name.
 *
 * German: Name der vierten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_NAME = NUMBER_6336_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 4 value field xdt name.
 *
 * German: Inhalt der vierten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_NAME = NUMBER_6337_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 5 name field xdt name.
 *
 * German: Name der f�nften freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_NAME = NUMBER_6338_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 5 value field xdt name.
 *
 * German: Inhalt der f�nften freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_NAME = NUMBER_6339_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 6 name field xdt name.
 *
 * German: Name der sechsten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_NAME = NUMBER_6340_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 6 value field xdt name.
 *
 * German: Inhalt der sechsten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_NAME = NUMBER_6341_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 7 name field xdt name.
 *
 * German: Name der siebten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_NAME = NUMBER_6342_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 7 value field xdt name.
 *
 * German: Inhalt der siebten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_NAME = NUMBER_6343_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 8 name field xdt name.
 *
 * German: Name der achten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_NAME = NUMBER_6344_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 8 value field xdt name.
 *
 * German: Inhalt der achten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_NAME = NUMBER_6345_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 9 name field xdt name.
 *
 * German: Name der neunten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_NAME = NUMBER_6346_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 9 value field xdt name.
 *
 * German: Inhalt der neunten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_NAME = NUMBER_6347_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 10 name field xdt name.
 *
 * German: Name der 10. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_NAME = NUMBER_6348_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 10 value field xdt name.
 *
 * German: Inhalt der 10. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_NAME = NUMBER_6349_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 11 name field xdt name.
 *
 * German: Name der 11. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_NAME = NUMBER_6350_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 11 value field xdt name.
 *
 * German: Inhalt der 11. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_NAME = NUMBER_6351_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 12 name field xdt name.
 *
 * German: Name der 12. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_NAME = NUMBER_6352_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 12 value field xdt name.
 *
 * German: Inhalt der 12. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_NAME = NUMBER_6353_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 13 name field xdt name.
 *
 * German: Name der 13. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_NAME = NUMBER_6354_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 13 value field xdt name.
 *
 * German: Inhalt der 13. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_NAME = NUMBER_6355_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 14 name field xdt name.
 *
 * German: Name der 14. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_NAME = NUMBER_6356_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 14 value field xdt name.
 *
 * German: Inhalt der 14. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_NAME = NUMBER_6357_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 15 name field xdt name.
 *
 * German: Name der 15. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_NAME = NUMBER_6358_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 15 value field xdt name.
 *
 * German: Inhalt der 15. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_NAME = NUMBER_6359_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 16 name field xdt name.
 *
 * German: Name der 16. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_NAME = NUMBER_6360_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 16 value field xdt name.
 *
 * German: Inhalt der 16. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_NAME = NUMBER_6361_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 17 name field xdt name.
 *
 * German: Name der 17. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_NAME = NUMBER_6362_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 17 value field xdt name.
 *
 * German: Inhalt der 17. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_NAME = NUMBER_6363_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 18 name field xdt name.
 *
 * German: Name der 18. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_NAME = NUMBER_6364_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 18 value field xdt name.
 *
 * German: Inhalt der 18. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_NAME = NUMBER_6365_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 19 name field xdt name.
 *
 * German: Name der 19. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_NAME = NUMBER_6366_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 19 value field xdt name.
 *
 * German: Inhalt der 19. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_NAME = NUMBER_6367_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 20 name field xdt name.
 *
 * German: Name der 20. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_NAME = NUMBER_6368_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 20 value field xdt name.
 *
 * German: Inhalt der 20. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_NAME = NUMBER_6369_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 21 name field xdt name.
 *
 * German: Name der 21. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_NAME = NUMBER_6370_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 21 value field xdt name.
 *
 * German: Inhalt der 21. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_NAME = NUMBER_6371_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 22 name field xdt name.
 *
 * German: Name der 22. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_NAME = NUMBER_6372_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 22 value field xdt name.
 *
 * German: Inhalt der 22. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_NAME = NUMBER_6373_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 23 name field xdt name.
 *
 * German: Name der 23. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_NAME = NUMBER_6374_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 23 value field xdt name.
 *
 * German: Inhalt der 23. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_NAME = NUMBER_6375_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 24 name field xdt name.
 *
 * German: Name der 24. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_NAME = NUMBER_6376_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 24 value field xdt name.
 *
 * German: Inhalt der 24. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_NAME = NUMBER_6377_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 25 name field xdt name.
 *
 * German: Name der 25. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_NAME = NUMBER_6378_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 25 value field xdt name.
 *
 * German: Inhalt der 25. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_NAME = NUMBER_6379_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 26 name field xdt name.
 *
 * German: Name der 26. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_NAME = NUMBER_6380_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 26 value field xdt name.
 *
 * German: Inhalt der 26. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_NAME = NUMBER_6381_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 27 name field xdt name.
 *
 * German: Name der 27. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_NAME = NUMBER_6382_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 27 value field xdt name.
 *
 * German: Inhalt der 27. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_NAME = NUMBER_6383_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 28 name field xdt name.
 *
 * German: Name der 28. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_NAME = NUMBER_6384_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 28 value field xdt name.
 *
 * German: Inhalt der 28. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_NAME = NUMBER_6385_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 29 name field xdt name.
 *
 * German: Name der 29. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_NAME = NUMBER_6386_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 29 value field xdt name.
 *
 * German: Inhalt der 29. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_NAME = NUMBER_6387_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 30 name field xdt name.
 *
 * German: Name der 30. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_NAME = NUMBER_6388_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 30 value field xdt name.
 *
 * German: Inhalt der 30. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_NAME = NUMBER_6389_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 31 name field xdt name.
 *
 * German: Name der 31. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_NAME = NUMBER_6390_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 31 value field xdt name.
 *
 * German: Inhalt der 31. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_NAME = NUMBER_6391_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 32 name field xdt name.
 *
 * German: Name der 32. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_NAME = NUMBER_6392_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 32 value field xdt name.
 *
 * German: Inhalt der 32. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_NAME = NUMBER_6393_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 33 name field xdt name.
 *
 * German: Name der 33. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_NAME = NUMBER_6394_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 33 value field xdt name.
 *
 * German: Inhalt der 33. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_NAME = NUMBER_6395_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 34 name field xdt name.
 *
 * German: Name der 34. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_NAME = NUMBER_6396_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 34 value field xdt name.
 *
 * German: Inhalt der 34. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_NAME = NUMBER_6397_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 35 name field xdt name.
 *
 * German: Name der 35. (letzten) freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_NAME = NUMBER_6398_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The free record 6200 category 35 value field xdt name.
 *
 * German: Inhalt der 35. (letzten) freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_NAME = NUMBER_6399_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The record identification field xdt name.
 *
 * German: Satzidentifikation
 * Size: 4
 * Type: integer
 * Rule: 167
 * Example: 0102
 */
static int* RECORD_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_8000_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The record size field xdt name.
 *
 * German: Satzl�nge
 * Size: 5
 * Type: integer
 * Rule: -
 * Example: 00747
 */
static int* RECORD_SIZE_FIELD_XDT_NAME = NUMBER_8100_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The device receiver gdt id field xdt name.
 *
 * German: GDT - ID des Empf�ngers
 * Size: 8
 * Type: character array
 * Rule: -
 * Example: ROP200U1
 */
static int* DEVICE_RECEIVER_GDT_ID_FIELD_XDT_NAME = NUMBER_8315_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The device sender gdt id field xdt name.
 *
 * German: GDT - ID des Senders
 * Size: 8
 * Type: character array
 * Rule: -
 * Example: PRAX_EDV
 */
static int* DEVICE_SENDER_GDT_ID_FIELD_XDT_NAME = NUMBER_8316_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings kind field xdt name.
 *
 * German: Befundart
 * Size: 1
 * Type: character array
 * Rule: -
 * Example: E
 */
static int* FINDINGS_KIND_FIELD_XDT_NAME = NUMBER_8401_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings device specifics field xdt name.
 *
 * German: Ger�te und verfahrensspezifisches Kennfeld
 * Size: <= 6 (taken from new GDT version; was 2 in old BDT)
 * Type: character array
 * Rule: -
 * Example: EKG01 (taken from new GDT version; was 10 in old BDT), see GDT appendix B
 */
static int* FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_NAME = NUMBER_8402_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings test identification field xdt name.
 *
 * German: Test-Ident
 * Size: <= 20 (taken from new GDT version; was 6 in old BDT)
 * Type: character array
 * Rule: -
 * Example: FEV1 (taken from new GDT version; was "Ka" in old BDT)
 */
static int* FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_8410_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings test name field xdt name.
 *
 * German: Testbezeichnung
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Obj. refr. cyl. rechts (taken from new GDT version; was "Kalium" in old BDT)
 */
static int* FINDINGS_TEST_NAME_FIELD_XDT_NAME = NUMBER_8411_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings test status field xdt name.
 *
 * German: Teststatus
 * Size: 1
 * Type: character array
 * Rule: -
 * Example: B
 */
static int* FINDINGS_TEST_STATUS_FIELD_XDT_NAME = NUMBER_8418_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings test result value field xdt name.
 *
 * German: Ergebnis-Wert
 * Size: variable (taken from new GDT version; was <= 70 in old BDT)
 * Type: float (taken from new GDT version; was "character array" in old BDT)
 * Rule: -
 * Example: -3.7 (taken from new GDT version; was 4,7 in old BDT)
 */
static int* FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_NAME = NUMBER_8420_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings test result unit field xdt name.
 *
 * German: Einheit
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: dpt (taken from new GDT version; was "mMol/l" in old BDT)
 */
static int* FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_NAME = NUMBER_8421_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings limit indicator field xdt name.
 *
 * German: Grenzwert-Indikator
 * Size: <= 2
 * Type: character array
 * Rule: -
 * Example: ++
 */
static int* FINDINGS_LIMIT_INDICATOR_FIELD_XDT_NAME = NUMBER_8422_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample material identification field xdt name.
 *
 * German: Probenmaterial-Ident
 * Size: <= 8
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_8428_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample material index field xdt name.
 *
 * German: Probenmaterial-Index (taken from new GDT version; was "Probenmaterial-Nummer" in old BDT)
 * Size: 2 (taken from new GDT version; was <= 70 in old BDT)
 * Type: integer (taken from new GDT version; was "character array" in old BDT)
 * Rule: -
 * Example: -
 */
static int* FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_NAME = NUMBER_8429_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample material name field xdt name.
 *
 * German: Probenmaterialbezeichnung
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: - (taken from new GDT version; was "Serum" in old BDT)
 */
static int* FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_NAME = NUMBER_8430_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample material specification field xdt name.
 *
 * German: Probenmaterial-Spezifikation
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: - (taken from new GDT version; was "24HV:130 GR" in old BDT)
 */
static int* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_NAME = NUMBER_8431_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample collection date field xdt name.
 *
 * German: Abnahme-Datum
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 31011994
 */
static int* FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_NAME = NUMBER_8432_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample collection time (old format) field xdt name.
 *
 * Obsolete? Defined by old BDT specification. See new collection time field number 8439!
 *
 * German: Abnahme-Zeit (altes Format, definiert in BDT Version von 1994)
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1045
 */
static int* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_NAME = NUMBER_8433_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings data stream units field xdt name.
 *
 * German: Einheit(en) f�r Datenstrom
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: min, mmHg, mmHg
 */
static int* FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_NAME = NUMBER_8437_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings data stream field xdt name.
 *
 * German: Datenstrom
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: 5,120,80... or: (5,120,80),(10,128,92)... and can also contain float values!
 */
static int* FINDINGS_DATA_STREAM_FIELD_XDT_NAME = NUMBER_8438_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings sample collection time field xdt name.
 *
 * German: Abnahme-Zeit
 * Size: 6
 * Type: time
 * Rule: 090
 * Example: HHMMSS 125600
 */
static int* FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_NAME = NUMBER_8439_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings germ identification field xdt name.
 *
 * German: Keim-Ident
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_NAME = NUMBER_8440_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings germ name field xdt name.
 *
 * German: Keim-Bezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_GERM_NAME_FIELD_XDT_NAME = NUMBER_8441_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings germ number field xdt name.
 *
 * German: Keim-Nummer
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: -
 */
static int* FINDINGS_GERM_NUMBER_FIELD_XDT_NAME = NUMBER_8442_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings resistance method field xdt name.
 *
 * German: Resistenz-Methode
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 1
 */
static int* FINDINGS_RESISTANCE_METHOD_FIELD_XDT_NAME = NUMBER_8443_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings active substance field xdt name.
 *
 * German: Wirkstoff-Ident
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_NAME = NUMBER_8444_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings active substance generic name field xdt name.
 *
 * German: Wirkstoff-Generic-Name
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_NAME = NUMBER_8445_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings mhk breakpoint value field xdt name.
 *
 * German: MHK-Breakpoint-Wert
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 4.2
 */
static int* FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_NAME = NUMBER_8446_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings resistance interpretation field xdt name.
 *
 * German: Resistenz-Interpretation
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 4
 */
static int* FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_NAME = NUMBER_8447_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings normal value text field xdt name.
 *
 * German: Normalwert-Text
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_NAME = NUMBER_8460_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings normal value lower limit field xdt name.
 *
 * German: Normalwert untere Grenze
 * Size: variable
 * Type: float
 * Rule: -
 * Example: -15
 */
static int* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_NAME = NUMBER_8461_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings normal value upper limit field xdt name.
 *
 * German: Normalwert obere Grenze
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 12
 */
static int* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_NAME = NUMBER_8462_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings remark field xdt name.
 *
 * German: Testbezogene Hinweise (taken from new GDT version; was "Anmerkung" in old BDT)
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_REMARK_FIELD_XDT_NAME = NUMBER_8470_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings result text field xdt name.
 *
 * German: Ergebnis-Text
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_RESULT_TEXT_FIELD_XDT_NAME = NUMBER_8480_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings complimentary close field xdt name.
 *
 * German: Abschlu�-Zeile
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_NAME = NUMBER_8490_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The findings signature field xdt name.
 *
 * German: Signatur
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Dr. Huber (taken from new GDT version; was empty in old BDT)
 */
static int* FINDINGS_SIGNATURE_FIELD_XDT_NAME = NUMBER_8990_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data medium sender physician number field xdt name.
 *
 * German: Arztnummer des Absenders
 * Size: 7-9
 * Type: integer
 * Rule: 329
 * Example: 8353839
 */
static int* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_NAME = NUMBER_9100_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data medium creation date field xdt name.
 *
 * German: Datum der Erstellung
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 31011994
 */
static int* DATA_MEDIUM_CREATION_DATE_FIELD_XDT_NAME = NUMBER_9103_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data medium running number field xdt name.
 *
 * German: Ordnungsnummer Datentr�ger (Header) des Datenpaketes
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 001
 */
static int* DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_NAME = NUMBER_9105_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data medium character code field xdt name.
 *
 * German: Zeichencode
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_NAME = NUMBER_9106_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package size field xdt name.
 *
 * German: Gesamtl�nge des Datenpaketes in Byte
 * Size: 8
 * Type: integer
 * Rule: -
 * Example: 12334878
 */
static int* DATA_PACKAGE_SIZE_FIELD_XDT_NAME = NUMBER_9202_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package mediums count field xdt name.
 *
 * German: Anzahl Datentr�ger des Datenpaketes
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 004
 */
static int* DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_NAME = NUMBER_9203_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package character set field xdt name.
 *
 * German: verwendeter Zeichensatz
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 2
 */
static int* DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_NAME = NUMBER_9206_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package adt version field xdt name.
 *
 * German: Abrechnungs-Datentransfer (ADT) Satzbeschreibung Version
 * Size: 5
 * Type: character array
 * Rule: 118
 * Example: 10/93
 */
static int* DATA_PACKAGE_ADT_VERSION_FIELD_XDT_NAME = NUMBER_9210_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package bdt version field xdt name.
 *
 * German: Behandlungs-Datentransfer (BDT) Version
 * Size: 5
 * Type: character array
 * Rule: 172
 * Example: 02/94
 */
static int* DATA_PACKAGE_BDT_VERSION_FIELD_XDT_NAME = NUMBER_9213_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package gdt version field xdt name.
 *
 * German: Ger�te-Datentransfer (GDT) Version
 * Size: 5
 * Type: character array
 * Rule: -
 * Example: 01.00, 02.00 or 02.10
 */
static int* DATA_PACKAGE_GDT_VERSION_FIELD_XDT_NAME = NUMBER_9218_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package archiving type field xdt name.
 *
 * German: Archivierungsart
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 1
 */
static int* DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_NAME = NUMBER_9600_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package storage period field xdt name.
 *
 * German: Zeitraum der Speicherung
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 0110199331121993
 */
static int* DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_NAME = NUMBER_9601_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The data package transfer begin field xdt name.
 *
 * German: Beginn der �bertragung
 * Size: 8
 * Type: integer
 * Rule: -
 * Example: 17084600
 */
static int* DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_NAME = NUMBER_9602_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The system internal parameter field xdt name.
 *
 * German: Systeminterner Parameter
 * Size: <= 70
 * Type: character array
 * Rule: 999
 * Example: -
 */
static int* SYSTEM_INTERNAL_PARAMETER_FIELD_XDT_NAME = NUMBER_9901_INTEGER_MEMORY_MODEL_ARRAY;

/* FIELD_XDT_NAME_SOURCE */
#endif
