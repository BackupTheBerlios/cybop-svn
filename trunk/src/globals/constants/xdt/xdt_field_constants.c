/*
 * $RCSfile: xdt_field_constants.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2007-09-10 18:37:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_FIELD_CONSTANTS_SOURCE
#define XDT_FIELD_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/**
 * The xdt field size count.
 *
 * All xdt field sizes have the same length: 3 ASCII characters (bytes).
 */
static int* XDT_FIELD_SIZE_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The xdt field identification count.
 *
 * All xdt field identifications have the same length: 4 ASCII characters (bytes).
 */
static int* XDT_FIELD_IDENTIFICATION_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The kbv test number field.
 *
 * German: KBV-Prüfnummer
 * Size: 7
 * Type: integer
 * Rule: 007
 * Example: 9301001
 */
static int* KBV_TEST_NUMBER_XDT_FIELD = NUMBER_101_INTEGER_ARRAY;

/**
 * The responsible entity field.
 *
 * German: Softwareverantwortlicher
 * Size: <= 60 (taken from GDT; is <= 70 in BDT; therefore the smaller is used)
 * Type: character array
 * Rule: -
 * Example: Medical-Soft
 */
static int* RESPONSIBLE_ENTITY_XDT_FIELD = NUMBER_102_INTEGER_ARRAY;

/**
 * The software field.
 *
 * German: Software
 * Size: <= 60 (taken from GDT; is <= 70 in BDT; therefore the smaller is used)
 * Type: character array
 * Rule: -
 * Example: DOCSFUN
 */
static int* SOFTWARE_XDT_FIELD = NUMBER_103_INTEGER_ARRAY;

/**
 * The hardware field.
 *
 * German: Hardware
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: IBM PC/AT
 */
static int* HARDWARE_XDT_FIELD = NUMBER_104_INTEGER_ARRAY;

/**
 * The software release field.
 *
 * German: Release-Stand der Software
 * Size: <= 60 (taken from GDT; is <= 70 in BDT; therefore the smaller is used)
 * Type: character array
 * Rule: -
 * Example: Version 4.30b
 */
static int* SOFTWARE_RELEASE_XDT_FIELD = NUMBER_132_INTEGER_ARRAY;

/**
 * The physician identification field.
 *
 * German: Arztnummer
 * Size: 7-9
 * Type: integer
 * Rule: 329
 * Example: 8353839
 */
static int* PHYSICIAN_IDENTIFICATION_XDT_FIELD = NUMBER_201_INTEGER_ARRAY;

/**
 * The physician practice type field.
 *
 * German: Praxistyp
 * Size: 1
 * Type: integer
 * Rule: 102/330/350
 * Example: 1
 */
static int* PHYSICIAN_PRACTICE_TYPE_XDT_FIELD = NUMBER_202_INTEGER_ARRAY;

/**
 * The physician name field.
 *
 * German: Arztname
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Hans Hohl
 */
static int* PHYSICIAN_NAME_XDT_FIELD = NUMBER_203_INTEGER_ARRAY;

/**
 * The physician category field.
 *
 * German: Arztgruppe verbal
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Radiologe
 */
static int* PHYSICIAN_CATEGORY_XDT_FIELD = NUMBER_204_INTEGER_ARRAY;

/**
 * The physician street field.
 *
 * German: Straße
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Hospizstr. 4
 */
static int* PHYSICIAN_STREET_XDT_FIELD = NUMBER_205_INTEGER_ARRAY;

/**
 * The physician postcode and place field.
 *
 * German: PLZ Ort
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 50859 Köln
 */
static int* PHYSICIAN_POSTCODE_AND_PLACE_XDT_FIELD = NUMBER_206_INTEGER_ARRAY;

/**
 * The physician with service indicator field.
 *
 * German: Arzt mit Leistungskennzeichen
 * Size: <= 70
 * Type: character array
 * Rule: 015
 * Example: Dr. Hohl/1
 */
static int* PHYSICIAN_WITH_SERVICE_INDICATOR_XDT_FIELD = NUMBER_207_INTEGER_ARRAY;

/**
 * The physician phone field.
 *
 * German: Telefonnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/473962
 */
static int* PHYSICIAN_PHONE_XDT_FIELD = NUMBER_208_INTEGER_ARRAY;

/**
 * The physician fax field.
 *
 * German: Telefaxnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/473963
 */
static int* PHYSICIAN_FAX_XDT_FIELD = NUMBER_209_INTEGER_ARRAY;

/**
 * The physician modem field.
 *
 * German: Modemnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/473963
 */
static int* PHYSICIAN_MODEM_XDT_FIELD = NUMBER_210_INTEGER_ARRAY;

/**
 * The physician number within practice field.
 *
 * German: Anzahl Ärzte
 * Size: 2
 * Type: integer
 * Rule: 350
 * Example: 02
 */
static int* PHYSICIAN_NUMBER_WITHIN_PRACTICE_XDT_FIELD = NUMBER_225_INTEGER_ARRAY;

/**
 * The free record 0010 category 1 name field.
 *
 * German: Name der ersten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Funktelefonnummer Praxisinhaber
 */
static int* FREE_RECORD_0010_CATEGORY_1_NAME_XDT_FIELD = NUMBER_250_INTEGER_ARRAY;

/**
 * The free record 0010 category 1 value field.
 *
 * German: Inhalt der ersten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0161/1112223
 */
static int* FREE_RECORD_0010_CATEGORY_1_VALUE_XDT_FIELD = NUMBER_251_INTEGER_ARRAY;

/**
 * The free record 0010 category 2 name field.
 *
 * German: Name der zweiten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schuhgröße Praxisinhaber
 */
static int* FREE_RECORD_0010_CATEGORY_2_NAME_XDT_FIELD = NUMBER_252_INTEGER_ARRAY;

/**
 * The free record 0010 category 2 value field.
 *
 * German: Inhalt der zweiten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 43
 */
static int* FREE_RECORD_0010_CATEGORY_2_VALUE_XDT_FIELD = NUMBER_253_INTEGER_ARRAY;

/**
 * The free record 0010 category 3 name field.
 *
 * German: Name der dritten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_3_NAME_XDT_FIELD = NUMBER_254_INTEGER_ARRAY;

/**
 * The free record 0010 category 3 value field.
 *
 * German: Inhalt der dritten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_3_VALUE_XDT_FIELD = NUMBER_255_INTEGER_ARRAY;

/**
 * The free record 0010 category 4 name field.
 *
 * German: Name der vierten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_4_NAME_XDT_FIELD = NUMBER_256_INTEGER_ARRAY;

/**
 * The free record 0010 category 4 value field.
 *
 * German: Inhalt der vierten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_4_VALUE_XDT_FIELD = NUMBER_257_INTEGER_ARRAY;

/**
 * The free record 0010 category 5 name field.
 *
 * German: Name der fünften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_5_NAME_XDT_FIELD = NUMBER_258_INTEGER_ARRAY;

/**
 * The free record 0010 category 5 value field.
 *
 * German: Inhalt der fünften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_5_VALUE_XDT_FIELD = NUMBER_259_INTEGER_ARRAY;

/**
 * The free record 0010 category 6 name field.
 *
 * German: Name der sechsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_6_NAME_XDT_FIELD = NUMBER_260_INTEGER_ARRAY;

/**
 * The free record 0010 category 6 value field.
 *
 * German: Inhalt der sechsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_6_VALUE_XDT_FIELD = NUMBER_261_INTEGER_ARRAY;

/**
 * The free record 0010 category 7 name field.
 *
 * German: Name der siebenten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_7_NAME_XDT_FIELD = NUMBER_262_INTEGER_ARRAY;

/**
 * The free record 0010 category 7 value field.
 *
 * German: Inhalt der siebenten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_7_VALUE_XDT_FIELD = NUMBER_263_INTEGER_ARRAY;

/**
 * The free record 0010 category 8 name field.
 *
 * German: Name der achten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_8_NAME_XDT_FIELD = NUMBER_264_INTEGER_ARRAY;

/**
 * The free record 0010 category 8 value field.
 *
 * German: Inhalt der achten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_8_VALUE_XDT_FIELD = NUMBER_265_INTEGER_ARRAY;

/**
 * The free record 0010 category 9 name field.
 *
 * German: Name der neunten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_9_NAME_XDT_FIELD = NUMBER_266_INTEGER_ARRAY;

/**
 * The free record 0010 category 9 value field.
 *
 * German: Inhalt der neunten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_9_VALUE_XDT_FIELD = NUMBER_267_INTEGER_ARRAY;

/**
 * The free record 0010 category 10 name field.
 *
 * German: Name der zehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_10_NAME_XDT_FIELD = NUMBER_268_INTEGER_ARRAY;

/**
 * The free record 0010 category 10 value field.
 *
 * German: Inhalt der zehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_10_VALUE_XDT_FIELD = NUMBER_269_INTEGER_ARRAY;

/**
 * The free record 0010 category 11 name field.
 *
 * German: Name der elften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_11_NAME_XDT_FIELD = NUMBER_270_INTEGER_ARRAY;

/**
 * The free record 0010 category 11 value field.
 *
 * German: Inhalt der elften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_11_VALUE_XDT_FIELD = NUMBER_271_INTEGER_ARRAY;

/**
 * The free record 0010 category 12 name field.
 *
 * German: Name der zwölften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_12_NAME_XDT_FIELD = NUMBER_272_INTEGER_ARRAY;

/**
 * The free record 0010 category 12 value field.
 *
 * German: Inhalt der zwölften freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_12_VALUE_XDT_FIELD = NUMBER_273_INTEGER_ARRAY;

/**
 * The free record 0010 category 13 name field.
 *
 * German: Name der dreizehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_13_NAME_XDT_FIELD = NUMBER_274_INTEGER_ARRAY;

/**
 * The free record 0010 category 13 value field.
 *
 * German: Inhalt der dreizehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_13_VALUE_XDT_FIELD = NUMBER_275_INTEGER_ARRAY;

/**
 * The free record 0010 category 14 name field.
 *
 * German: Name der vierzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_14_NAME_XDT_FIELD = NUMBER_276_INTEGER_ARRAY;

/**
 * The free record 0010 category 14 value field.
 *
 * German: Inhalt der vierzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_14_VALUE_XDT_FIELD = NUMBER_277_INTEGER_ARRAY;

/**
 * The free record 0010 category 15 name field.
 *
 * German: Name der fünfzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_15_NAME_XDT_FIELD = NUMBER_278_INTEGER_ARRAY;

/**
 * The free record 0010 category 15 value field.
 *
 * German: Inhalt der fünfzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_15_VALUE_XDT_FIELD = NUMBER_279_INTEGER_ARRAY;

/**
 * The free record 0010 category 16 name field.
 *
 * German: Name der sechzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_16_NAME_XDT_FIELD = NUMBER_280_INTEGER_ARRAY;

/**
 * The free record 0010 category 16 value field.
 *
 * German: Inhalt der sechzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_16_VALUE_XDT_FIELD = NUMBER_281_INTEGER_ARRAY;

/**
 * The free record 0010 category 17 name field.
 *
 * German: Name der siebzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_17_NAME_XDT_FIELD = NUMBER_282_INTEGER_ARRAY;

/**
 * The free record 0010 category 17 value field.
 *
 * German: Inhalt der siebzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_17_VALUE_XDT_FIELD = NUMBER_283_INTEGER_ARRAY;

/**
 * The free record 0010 category 18 name field.
 *
 * German: Name der achzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_18_NAME_XDT_FIELD = NUMBER_284_INTEGER_ARRAY;

/**
 * The free record 0010 category 18 value field.
 *
 * German: Inhalt der achzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_18_VALUE_XDT_FIELD = NUMBER_285_INTEGER_ARRAY;

/**
 * The free record 0010 category 19 name field.
 *
 * German: Name der neunzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_19_NAME_XDT_FIELD = NUMBER_286_INTEGER_ARRAY;

/**
 * The free record 0010 category 19 value field.
 *
 * German: Inhalt der neunzehnten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_19_VALUE_XDT_FIELD = NUMBER_287_INTEGER_ARRAY;

/**
 * The free record 0010 category 20 name field.
 *
 * German: Name der zwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_20_NAME_XDT_FIELD = NUMBER_288_INTEGER_ARRAY;

/**
 * The free record 0010 category 20 value field.
 *
 * German: Inhalt der zwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_20_VALUE_XDT_FIELD = NUMBER_289_INTEGER_ARRAY;

/**
 * The free record 0010 category 21 name field.
 *
 * German: Name der einundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_21_NAME_XDT_FIELD = NUMBER_290_INTEGER_ARRAY;

/**
 * The free record 0010 category 21 value field.
 *
 * German: Inhalt der einundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_21_VALUE_XDT_FIELD = NUMBER_291_INTEGER_ARRAY;

/**
 * The free record 0010 category 22 name field.
 *
 * German: Name der zweiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_22_NAME_XDT_FIELD = NUMBER_292_INTEGER_ARRAY;

/**
 * The free record 0010 category 22 value field.
 *
 * German: Inhalt der zweiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_22_VALUE_XDT_FIELD = NUMBER_293_INTEGER_ARRAY;

/**
 * The free record 0010 category 23 name field.
 *
 * German: Name der dreiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_23_NAME_XDT_FIELD = NUMBER_294_INTEGER_ARRAY;

/**
 * The free record 0010 category 23 value field.
 *
 * German: Inhalt der dreiundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_23_VALUE_XDT_FIELD = NUMBER_295_INTEGER_ARRAY;

/**
 * The free record 0010 category 24 name field.
 *
 * German: Name der vierundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_24_NAME_XDT_FIELD = NUMBER_296_INTEGER_ARRAY;

/**
 * The free record 0010 category 24 value field.
 *
 * German: Inhalt der vierundzwanzigsten freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_0010_CATEGORY_24_VALUE_XDT_FIELD = NUMBER_297_INTEGER_ARRAY;

/**
 * The free record 0010 category 25 name field.
 *
 * German: Name der fünfundzwanzigsten (letzten) freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Gewicht
 */
static int* FREE_RECORD_0010_CATEGORY_25_NAME_XDT_FIELD = NUMBER_298_INTEGER_ARRAY;

/**
 * The free record 0010 category 25 value field.
 *
 * German: Inhalt der fünfundzwanzigsten (letzten) freien Kategorie Satzart "0010"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 75 kg
 */
static int* FREE_RECORD_0010_CATEGORY_25_VALUE_XDT_FIELD = NUMBER_299_INTEGER_ARRAY;

/**
 * The patient identification field.
 *
 * German: Patientennummer/Patientenkennung
 * Size: <= 10
 * Type: character array (taken from new GDT version; was "integer" in old BDT)
 * Rule: -
 * Example: 12345678
 */
static int* PATIENT_IDENTIFICATION_XDT_FIELD = NUMBER_3000_INTEGER_ARRAY;

/**
 * The patient name affix field.
 *
 * German: Namenszusatz/Vorsatzwort des Patienten
 * Size: <= 15
 * Type: character array
 * Rule: -
 * Example: von
 */
static int* PATIENT_NAME_AFFIX_XDT_FIELD = NUMBER_3100_INTEGER_ARRAY;

/**
 * The patient last name field.
 *
 * German: Name des Patienten
 * Size: <= 28
 * Type: character array
 * Rule: -
 * Example: Schmitz
 */
static int* PATIENT_LAST_NAME_XDT_FIELD = NUMBER_3101_INTEGER_ARRAY;

/**
 * The patient first name field.
 *
 * German: Vorname des Patienten
 * Size: <= 28
 * Type: character array
 * Rule: -
 * Example: Erna
 */
static int* PATIENT_FIRST_NAME_XDT_FIELD = NUMBER_3102_INTEGER_ARRAY;

/**
 * The patient birth date field.
 *
 * German: Geburtsdatum des Patienten
 * Size: 8
 * Type: date
 * Rule: 020/304
 * Example: 12041946
 */
static int* PATIENT_BIRTH_DATE_XDT_FIELD = NUMBER_3103_INTEGER_ARRAY;

/**
 * The patient title field.
 *
 * German: Titel des Patienten
 * Size: <= 15
 * Type: character array
 * Rule: -
 * Example: Dr.
 */
static int* PATIENT_TITLE_XDT_FIELD = NUMBER_3104_INTEGER_ARRAY;

/**
 * The patient health insurance number field.
 *
 * German: Versichertennummer des Patienten
 * Size: <= 12 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: - (taken from new GDT version; was 335 in old BDT)
 * Example: 123456M789
 */
static int* PATIENT_HEALTH_INSURANCE_NUMBER_XDT_FIELD = NUMBER_3105_INTEGER_ARRAY;

/**
 * The patient residence field.
 *
 * German: Wohnort des Patienten
 * Size: <= 30
 * Type: character array
 * Rule: -
 * Example: 50859 Koeln
 */
static int* PATIENT_RESIDENCE_XDT_FIELD = NUMBER_3106_INTEGER_ARRAY;

/**
 * The patient street field.
 *
 * German: Straße des Patienten
 * Size: <= 28
 * Type: character array
 * Rule: -
 * Example: Holzweg 106
 */
static int* PATIENT_STREET_XDT_FIELD = NUMBER_3107_INTEGER_ARRAY;

/**
 * The patient health insurance type field.
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
static int* PATIENT_HEALTH_INSURANCE_TYPE_XDT_FIELD = NUMBER_3108_INTEGER_ARRAY;

/**
 * The patient sex field.
 *
 * German: Geschlecht des Patienten
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* PATIENT_SEX_XDT_FIELD = NUMBER_3110_INTEGER_ARRAY;

/**
 * The patient employer field.
 *
 * German: Arbeitgeber
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: KHD Köln
 */
static int* PATIENT_EMPLOYER_XDT_FIELD = NUMBER_3150_INTEGER_ARRAY;

/**
 * The patient accident insurance name field.
 *
 * German: Bezeichnung des Unfallversicherungsträgers
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: DKV
 */
static int* PATIENT_ACCIDENT_INSURANCE_NAME_XDT_FIELD = NUMBER_3152_INTEGER_ARRAY;

/**
 * The insurant last name field.
 *
 * German: Name des Hauptversicherten
 * Size: <= 28
 * Type: character array
 * Rule: 338
 * Example: Schmitz
 */
static int* INSURANT_LAST_NAME_XDT_FIELD = NUMBER_3201_INTEGER_ARRAY;

/**
 * The insurant first name field.
 *
 * German: Vorname des Hauptversicherten
 * Size: <= 28
 * Type: character array
 * Rule: 338
 * Example: Erwin
 */
static int* INSURANT_FIRST_NAME_XDT_FIELD = NUMBER_3202_INTEGER_ARRAY;

/**
 * The insurant birth date field.
 *
 * German: Geburtsdatum des Hauptversicherten
 * Size: 8
 * Type: date
 * Rule: 008/304/338
 * Example: 27091950
 */
static int* INSURANT_BIRTH_DATE_XDT_FIELD = NUMBER_3203_INTEGER_ARRAY;

/**
 * The insurant residence field.
 *
 * German: Wohnort des Hauptversicherten
 * Size: <= 30
 * Type: character array
 * Rule: 338
 * Example: 50859 Köln
 */
static int* INSURANT_RESIDENCE_XDT_FIELD = NUMBER_3204_INTEGER_ARRAY;

/**
 * The insurant street field.
 *
 * German: Straße des Hauptversicherten
 * Size: <= 28
 * Type: character array
 * Rule: 338
 * Example: Holzweg 106
 */
static int* INSURANT_STREET_XDT_FIELD = NUMBER_3205_INTEGER_ARRAY;

/**
 * The injured phone field.
 *
 * German: Telefonnummer des Verletzten
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 02234/76056
 */
static int* INJURED_PHONE_XDT_FIELD = NUMBER_3208_INTEGER_ARRAY;

/**
 * The insurant sex field.
 *
 * German: Geschlecht des Hauptversicherten
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* INSURANT_SEX_XDT_FIELD = NUMBER_3210_INTEGER_ARRAY;

/**
 * The patient x-ray number field.
 *
 * German: Röntgennummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: rö12345g
 */
static int* PATIENT_X_RAY_NUMBER_XDT_FIELD = NUMBER_3601_INTEGER_ARRAY;

/**
 * The patient archive number field.
 *
 * German: Archivnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: a120446
 */
static int* PATIENT_ARCHIVE_NUMBER_XDT_FIELD = NUMBER_3602_INTEGER_ARRAY;

/**
 * The patient employers' liability insurance association number field.
 *
 * German: BG-Nummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 123jdh22
 */
static int* PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_XDT_FIELD = NUMBER_3603_INTEGER_ARRAY;

/**
 * The patient since date field.
 *
 * German: Patient seit
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 03041976
 */
static int* PATIENT_SINCE_DATE_XDT_FIELD = NUMBER_3610_INTEGER_ARRAY;

/**
 * The patient change of insurance inception date field.
 *
 * German: Versicherungsbeginn bei Kassenwechsel
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 12041993
 */
static int* PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_XDT_FIELD = NUMBER_3612_INTEGER_ARRAY;

/**
 * The patient profession field.
 *
 * German: Beruf des Patienten
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Metzger
 */
static int* PATIENT_PROFESSION_XDT_FIELD = NUMBER_3620_INTEGER_ARRAY;

/**
 * The patient body height field.
 *
 * German: Größe des Patienten in cm
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 175.50
 */
static int* PATIENT_BODY_HEIGHT_XDT_FIELD = NUMBER_3622_INTEGER_ARRAY;

/**
 * The patient body weight field.
 *
 * German: Gewicht des Patienten in kg
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 90.50
 */
static int* PATIENT_BODY_WEIGHT_XDT_FIELD = NUMBER_3623_INTEGER_ARRAY;

/**
 * The patient employer field.
 *
 * German: Arbeitgeber des Patienten
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Müller AG
 */
static int* PATIENT_EMPLOYER_XDT_FIELD = NUMBER_3625_INTEGER_ARRAY;

/**
 * The patient phone field.
 *
 * German: Telefonnummer Patient
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 02234/111
 */
static int* PATIENT_PHONE_XDT_FIELD = NUMBER_3626_INTEGER_ARRAY;

/**
 * The patient nationality field.
 *
 * German: Nationalität Patient
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: deutsch
 */
static int* PATIENT_NATIONALITY_XDT_FIELD = NUMBER_3627_INTEGER_ARRAY;

/**
 * The patient mother tongue field.
 *
 * German: Muttersprache
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: türkisch
 */
static int* PATIENT_MOTHER_TONGUE_XDT_FIELD = NUMBER_3628_INTEGER_ARRAY;

/**
 * The patient general practitioner identification field.
 *
 * German: Arztnummer Hausarzt
 * Size: 7-9
 * Type: integer
 * Rule: -
 * Example: 0119950
 */
static int* PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_XDT_FIELD = NUMBER_3630_INTEGER_ARRAY;

/**
 * The patient residence to medical practice distance field.
 *
 * German: Entfernung Wohnort-Praxis
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Z1, 3.5
 */
static int* PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_XDT_FIELD = NUMBER_3631_INTEGER_ARRAY;

/**
 * The patient physician identification in group practice field.
 *
 * German: Interne Zuordnung Arzt bei Gemeinschaftspraxen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Müller
 */
static int* PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_XDT_FIELD = NUMBER_3635_INTEGER_ARRAY;

/**
 * The patient prescription identification field.
 *
 * German: Rezeptkennung
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 1
 */
static int* PATIENT_PRESCRIPTION_IDENTIFICATION_XDT_FIELD = NUMBER_3637_INTEGER_ARRAY;

/**
 * The patient permanent diagnoses begin date field.
 *
 * German: Dauerdiagnosen ab Datum
 * Size: 8
 * Type: date
 * Rule: -
 * Example: 01011990
 */
static int* PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_XDT_FIELD = NUMBER_3649_INTEGER_ARRAY;

/**
 * The patient permanent diagnoses field.
 *
 * German: Dauerdiagnosen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Diabetes mellitus
 */
static int* PATIENT_PERMANENT_DIAGNOSES_XDT_FIELD = NUMBER_3650_INTEGER_ARRAY;

/**
 * The patient permanent drugs begin date field.
 *
 * German: Dauermedikamente ab Datum
 * Size: 8
 * Type: date
 * Rule: -
 * Example: 01011990
 */
static int* PATIENT_PERMANENT_DRUGS_BEGIN_DATE_XDT_FIELD = NUMBER_3651_INTEGER_ARRAY;

/**
 * The patient permanent drugs field.
 *
 * German: Dauermedikamente
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Adalat
 */
static int* PATIENT_PERMANENT_DRUGS_XDT_FIELD = NUMBER_3652_INTEGER_ARRAY;

/**
 * The patient risk factors field.
 *
 * German: Risikofaktoren
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Raucher
 */
static int* PATIENT_RISK_FACTORS_XDT_FIELD = NUMBER_3654_INTEGER_ARRAY;

/**
 * The patient allergies field.
 *
 * German: Allergien
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Neurodermitis
 */
static int* PATIENT_ALLERGIES_XDT_FIELD = NUMBER_3656_INTEGER_ARRAY;

/**
 * The patient accidents field.
 *
 * German: Unfälle
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Motorradunfall
 */
static int* PATIENT_ACCIDENTS_XDT_FIELD = NUMBER_3658_INTEGER_ARRAY;

/**
 * The patient surgeries field.
 *
 * German: Operationen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Blinddarm
 */
static int* PATIENT_SURGERIES_XDT_FIELD = NUMBER_3660_INTEGER_ARRAY;

/**
 * The patient anamnesis field.
 *
 * German: Anamnese
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Frühgeburt
 */
static int* PATIENT_ANAMNESIS_XDT_FIELD = NUMBER_3662_INTEGER_ARRAY;

/**
 * The patient number of births field.
 *
 * German: Anzahl Geburten
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 2
 */
static int* PATIENT_NUMBER_OF_BIRTHS_XDT_FIELD = NUMBER_3664_INTEGER_ARRAY;

/**
 * The patient number of children field.
 *
 * German: Anzahl Kinder
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 3
 */
static int* PATIENT_NUMBER_OF_CHILDREN_XDT_FIELD = NUMBER_3666_INTEGER_ARRAY;

/**
 * The patient number of pregnancies field.
 *
 * German: Anzahl Schwangerschaften
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 4
 */
static int* PATIENT_NUMBER_OF_PREGNANCIES_XDT_FIELD = NUMBER_3668_INTEGER_ARRAY;

/**
 * The patient permanent therapy field.
 *
 * German: Dauertherapie
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Massagen
 */
static int* PATIENT_PERMANENT_THERAPY_XDT_FIELD = NUMBER_3670_INTEGER_ARRAY;

/**
 * The patient recall appointment date field.
 *
 * German: Kontrolltermine
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 01121993
 */
static int* PATIENT_RECALL_APPOINTMENT_DATE_XDT_FIELD = NUMBER_3672_INTEGER_ARRAY;

/**
 * The free record 6100 category 1 name field.
 *
 * German: Name der ersten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Körpergröße
 */
static int* FREE_RECORD_6100_CATEGORY_1_NAME_XDT_FIELD = NUMBER_3700_INTEGER_ARRAY;

/**
 * The free record 6100 category 1 value field.
 *
 * German: Inhalt der ersten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 183 cm
 */
static int* FREE_RECORD_6100_CATEGORY_1_VALUE_XDT_FIELD = NUMBER_3701_INTEGER_ARRAY;

/**
 * The free record 6100 category 2 name field.
 *
 * German: Name der zweiten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Gewicht
 */
static int* FREE_RECORD_6100_CATEGORY_2_NAME_XDT_FIELD = NUMBER_3702_INTEGER_ARRAY;

/**
 * The free record 6100 category 2 value field.
 *
 * German: Inhalt der zweiten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 75 kg
 */
static int* FREE_RECORD_6100_CATEGORY_2_VALUE_XDT_FIELD = NUMBER_3703_INTEGER_ARRAY;

/**
 * The free record 6100 category 3 name field.
 *
 * German: Name der dritten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_3_NAME_XDT_FIELD = NUMBER_3704_INTEGER_ARRAY;

/**
 * The free record 6100 category 3 value field.
 *
 * German: Inhalt der dritten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_3_VALUE_XDT_FIELD = NUMBER_3705_INTEGER_ARRAY;

/**
 * The free record 6100 category 4 name field.
 *
 * German: Name der vierten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_4_NAME_XDT_FIELD = NUMBER_3706_INTEGER_ARRAY;

/**
 * The free record 6100 category 4 value field.
 *
 * German: Inhalt der vierten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_4_VALUE_XDT_FIELD = NUMBER_3707_INTEGER_ARRAY;

/**
 * The free record 6100 category 5 name field.
 *
 * German: Name der fünften freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_5_NAME_XDT_FIELD = NUMBER_3708_INTEGER_ARRAY;

/**
 * The free record 6100 category 5 value field.
 *
 * German: Inhalt der fünften freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_5_VALUE_XDT_FIELD = NUMBER_3709_INTEGER_ARRAY;

/**
 * The free record 6100 category 6 name field.
 *
 * German: Name der sechsten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_6_NAME_XDT_FIELD = NUMBER_3710_INTEGER_ARRAY;

/**
 * The free record 6100 category 6 value field.
 *
 * German: Inhalt der sechsten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_6_VALUE_XDT_FIELD = NUMBER_3711_INTEGER_ARRAY;

/**
 * The free record 6100 category 7 name field.
 *
 * German: Name der siebten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_7_NAME_XDT_FIELD = NUMBER_3712_INTEGER_ARRAY;

/**
 * The free record 6100 category 7 value field.
 *
 * German: Inhalt der siebten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_7_VALUE_XDT_FIELD = NUMBER_3713_INTEGER_ARRAY;

/**
 * The free record 6100 category 8 name field.
 *
 * German: Name der achten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_8_NAME_XDT_FIELD = NUMBER_3714_INTEGER_ARRAY;

/**
 * The free record 6100 category 8 value field.
 *
 * German: Inhalt der achten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_8_VALUE_XDT_FIELD = NUMBER_3715_INTEGER_ARRAY;

/**
 * The free record 6100 category 9 name field.
 *
 * German: Name der neunten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_9_NAME_XDT_FIELD = NUMBER_3716_INTEGER_ARRAY;

/**
 * The free record 6100 category 9 value field.
 *
 * German: Inhalt der neunten freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6100_CATEGORY_9_VALUE_XDT_FIELD = NUMBER_3717_INTEGER_ARRAY;

/**
 * The free record 6100 category 10 name field.
 *
 * German: Name der zehnten (letzten) freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Gewicht
 */
static int* FREE_RECORD_6100_CATEGORY_10_NAME_XDT_FIELD = NUMBER_3718_INTEGER_ARRAY;

/**
 * The free record 6100 category 10 value field.
 *
 * German: Inhalt der zehnten (letzten) freien Kategorie Satzart "6100"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 75 kg
 */
static int* FREE_RECORD_6100_CATEGORY_10_VALUE_XDT_FIELD = NUMBER_3719_INTEGER_ARRAY;

/**
 * The invoice quarter field.
 *
 * German: Quartal der Abrechnung
 * Size: 5
 * Type: integer
 * Rule: 016
 * Example: 31993
 */
static int* INVOICE_QUARTER_XDT_FIELD = NUMBER_4101_INTEGER_ARRAY;

/**
 * The invoice issuance date field.
 *
 * German: Ausstellungsdatum
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 07081993
 */
static int* INVOICE_ISSUANCE_DATE_XDT_FIELD = NUMBER_4102_INTEGER_ARRAY;

/**
 * The invoice validity date field.
 *
 * German: Gültigkeitsdatum
 * Size: 8
 * Type: date
 * Rule: 008/314/338
 * Example: 20091993
 */
static int* INVOICE_VALIDITY_DATE_XDT_FIELD = NUMBER_4103_INTEGER_ARRAY;

/**
 * The invoice insurance number field.
 *
 * German: Kassennummer (VKNR)
 * Size: 5
 * Type: integer
 * Rule: 017/201
 * Example: 27106
 */
static int* INVOICE_INSURANCE_NUMBER_XDT_FIELD = NUMBER_4104_INTEGER_ARRAY;

/**
 * The invoice insurance office field.
 *
 * German: Geschäftsstelle
 * Size: <= 70
 * Type: character array
 * Rule: 338
 * Example: Köln
 */
static int* INVOICE_INSURANCE_OFFICE_XDT_FIELD = NUMBER_4105_INTEGER_ARRAY;

/**
 * The invoice insurance sub category field.
 *
 * German: Kostenträgeruntergruppe
 * Size: 2
 * Type: integer
 * Rule: 126
 * Example: 00
 */
static int* INVOICE_INSURANCE_SUB_CATEGORY_XDT_FIELD = NUMBER_4106_INTEGER_ARRAY;

/**
 * The invoice billing category field.
 *
 * German: Abrechnungsart (Schein)
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 1
 */
static int* INVOICE_BILLING_CATEGORY_XDT_FIELD = NUMBER_4107_INTEGER_ARRAY;

/**
 * The invoice insurance card last read access field.
 *
 * German: Letzter Einlesetag der VK-Karte im Quartal
 * Size: 8
 * Type: date
 * Rule: 008/335
 * Example: 07081993
 */
static int* INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_XDT_FIELD = NUMBER_4109_INTEGER_ARRAY;

/**
 * The invoice insurance card validity date field.
 *
 * German: Bis-Datum der Gültigkeit
 * Size: 4
 * Type: integer
 * Rule: 014/335
 * Example: 1291
 */
static int* INVOICE_INSURANCE_CARD_VALIDITY_DATE_XDT_FIELD = NUMBER_4110_INTEGER_ARRAY;

/**
 * The invoice ik insurance number field.
 *
 * German: Krankenkassennummer (IK)
 * Size: 7
 * Type: integer
 * Rule: 018/335
 * Example: 1568008
 */
static int* INVOICE_IK_INSURANCE_NUMBER_XDT_FIELD = NUMBER_4111_INTEGER_ARRAY;

/**
 * The invoice vk insurance status field.
 *
 * German: Versichertenstatus VK
 * Size: 4
 * Type: integer
 * Rule: 335
 * Example: 1000
 */
static int* INVOICE_VK_INSURANCE_STATUS_XDT_FIELD = NUMBER_4112_INTEGER_ARRAY;

/**
 * The invoice vk east-west status field.
 *
 * German: Ost/West-Status VK
 * Size: 1
 * Type: integer
 * Rule: 117/335
 * Example: 1
 */
static int* INVOICE_VK_EAST_WEST_STATUS_XDT_FIELD = NUMBER_4113_INTEGER_ARRAY;

/**
 * The invoice billing scale field.
 *
 * German: Gebührenordnung
 * Size: 1
 * Type: integer
 * Rule: 106/323/325
 * Example: 1
 */
static int* INVOICE_BILLING_SCALE_XDT_FIELD = NUMBER_4121_INTEGER_ARRAY;

/**
 * The invoice billing area field.
 *
 * German: Abrechnungsgebiet
 * Size: 2
 * Type: integer
 * Rule: 119
 * Example: 00
 */
static int* INVOICE_BILLING_AREA_XDT_FIELD = NUMBER_4122_INTEGER_ARRAY;

/**
 * The referral cause of pain field.
 *
 * German: Ursache des Leidens
 * Size: 1
 * Type: integer
 * Rule: 120
 * Example: 2
 */
static int* REFERRAL_CAUSE_OF_PAIN_XDT_FIELD = NUMBER_4201_INTEGER_ARRAY;

/**
 * The referral supposed accouchement date field.
 *
 * German: Mutmaßlicher Tag der Entbindung
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 22011994
 */
static int* REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_XDT_FIELD = NUMBER_4206_INTEGER_ARRAY;

/**
 * The referral diagnosis field.
 *
 * German: Diagnose/Verdacht
 * Size: <= 70
 * Type: character array
 * Rule: 322
 * Example: Tumorverdacht
 */
static int* REFERRAL_DIAGNOSIS_XDT_FIELD = NUMBER_4207_INTEGER_ARRAY;

/**
 * The referral explanation field.
 *
 * German: Erläuternder Text zur Überweisung
 * Size: <= 70
 * Type: character array
 * Rule: 321
 * Example: Röntgen
 */
static int* REFERRAL_EXPLANATION_XDT_FIELD = NUMBER_4209_INTEGER_ARRAY;

/**
 * The referral check box muvo lsr field.
 *
 * German: Ankreuzfeld Muvo LSR
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_MUVO_LSR_XDT_FIELD = NUMBER_4210_INTEGER_ARRAY;

/**
 * The referral check box muvo hah field.
 *
 * German: Ankreuzfeld Muvo HAH
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_MUVO_HAH_XDT_FIELD = NUMBER_4211_INTEGER_ARRAY;

/**
 * The referral check box ab0 rh field.
 *
 * German: Ankreuzfeld Ab0/Rh
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_AB0_RH_XDT_FIELD = NUMBER_4212_INTEGER_ARRAY;

/**
 * The referral check box ak field.
 *
 * German: Ankreuzfeld AK
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* REFERRAL_CHECK_BOX_AK_XDT_FIELD = NUMBER_4213_INTEGER_ARRAY;

/**
 * The referral from physician number field.
 *
 * German: Überweisung von Arztnummer
 * Size: 7-9
 * Type: integer
 * Rule: -
 * Example: 381953910
 */
static int* REFERRAL_FROM_PHYSICIAN_NUMBER_XDT_FIELD = NUMBER_4218_INTEGER_ARRAY;

/**
 * The referral to physician name field.
 *
 * German: Überweisung an
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Bergmann
 */
static int* REFERRAL_TO_PHYSICIAN_NAME_XDT_FIELD = NUMBER_4220_INTEGER_ARRAY;

/**
 * The inpatient treatment referral by law field.
 *
 * German: Gesetzlicher Abzug zur stationären Behandlung gemäß § 6a GOÄ
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* INPATIENT_TREATMENT_REFERRAL_BY_LAW_XDT_FIELD = NUMBER_4230_INTEGER_ARRAY;

/**
 * The inpatient treatment from to field.
 *
 * German: Stationäre Behandlung von ... bis ...
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 0708199320081993
 */
static int* INPATIENT_TREATMENT_FROM_TO_XDT_FIELD = NUMBER_4233_INTEGER_ARRAY;

/**
 * The inpatient treatment class field.
 *
 * German: Klasse bei stationärer Behandlung
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 2
 */
static int* INPATIENT_TREATMENT_CLASS_XDT_FIELD = NUMBER_4236_INTEGER_ARRAY;

/**
 * The inpatient hospital name field.
 *
 * German: Krankenhaus-Name
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Uniklinik
 */
static int* INPATIENT_HOSPITAL_NAME_XDT_FIELD = NUMBER_4237_INTEGER_ARRAY;

/**
 * The inpatient hospital stay field.
 *
 * German: Krankenhausaufenthalt
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 330
 */
static int* INPATIENT_HOSPITAL_STAY_XDT_FIELD = NUMBER_4238_INTEGER_ARRAY;

/**
 * The invoice sub category field.
 *
 * German: Scheinuntergruppe
 * Size: 2
 * Type: integer
 * Rule: 321/322/331/332/333/334
 * Example: 00
 */
static int* INVOICE_SUB_CATEGORY_XDT_FIELD = NUMBER_4239_INTEGER_ARRAY;

/**
 * The emergency subsequent treatment physician name field.
 *
 * German: Weiterbehandelnder Arzt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Meier
 */
static int* EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_XDT_FIELD = NUMBER_4243_INTEGER_ARRAY;

/**
 * The emergency findings field.
 *
 * German: Befund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Bandruptur
 */
static int* EMERGENCY_FINDINGS_XDT_FIELD = NUMBER_4267_INTEGER_ARRAY;

/**
 * The emergency symptoms field.
 *
 * German: Symptome
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schwellung des li. Sprunggelenkes
 */
static int* EMERGENCY_SYMPTOMS_XDT_FIELD = NUMBER_4268_INTEGER_ARRAY;

/**
 * The accident date field.
 *
 * German: Unfalltag
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_DATE_XDT_FIELD = NUMBER_4500_INTEGER_ARRAY;

/**
 * The accident time field.
 *
 * German: Uhrzeit des Unfalls
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1020
 */
static int* ACCIDENT_TIME_XDT_FIELD = NUMBER_4501_INTEGER_ARRAY;

/**
 * The accident patient admission in practice date field.
 *
 * German: Eingetroffen in Praxis am
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_XDT_FIELD = NUMBER_4502_INTEGER_ARRAY;

/**
 * The accident patient admission in practice time field.
 *
 * German: Uhrzeit des Eintreffens
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1030
 */
static int* ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_XDT_FIELD = NUMBER_4503_INTEGER_ARRAY;

/**
 * The accident patient labour time begin field.
 *
 * German: Beginn Arbeitszeit
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 0715
 */
static int* ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_XDT_FIELD = NUMBER_4504_INTEGER_ARRAY;

/**
 * The accident location field.
 *
 * German: Unfallort
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Baustelle
 */
static int* ACCIDENT_LOCATION_XDT_FIELD = NUMBER_4505_INTEGER_ARRAY;

/**
 * The accident patient employment as field.
 *
 * German: Beschäftigung als
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Tischler
 */
static int* ACCIDENT_PATIENT_EMPLOYMENT_AS_XDT_FIELD = NUMBER_4506_INTEGER_ARRAY;

/**
 * The accident patient employment since field.
 *
 * German: Beschäftigt seit
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 01011980
 */
static int* ACCIDENT_PATIENT_EMPLOYMENT_SINCE_XDT_FIELD = NUMBER_4507_INTEGER_ARRAY;

/**
 * The accident patient nationality field.
 *
 * German: Staatsangehörigkeit
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: deutsch
 */
static int* ACCIDENT_PATIENT_NATIONALITY_XDT_FIELD = NUMBER_4508_INTEGER_ARRAY;

/**
 * The accident company field.
 *
 * German: Unfallbetrieb
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Betriebshof Mitte
 */
static int* ACCIDENT_COMPANY_XDT_FIELD = NUMBER_4509_INTEGER_ARRAY;

/**
 * The accident course of events field.
 *
 * German: Unfallhergang
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Abrutschen von Leiter
 */
static int* ACCIDENT_COURSE_OF_EVENTS_XDT_FIELD = NUMBER_4510_INTEGER_ARRAY;

/**
 * The accident patient behaviour afterwards field.
 *
 * German: Verhalten des Verletzten nach dem Unfall
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Aufsuchen des Krankenhauses
 */
static int* ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_XDT_FIELD = NUMBER_4512_INTEGER_ARRAY;

/**
 * The accident first time treatment date field.
 *
 * German: Erstmalige Behandlung
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_FIRST_TIME_TREATMENT_DATE_XDT_FIELD = NUMBER_4513_INTEGER_ARRAY;

/**
 * The accident treatment by physician name field.
 *
 * German: Behandlung durch
 * Size: 8
 * Type: character array
 * Rule: 008
 * Example: Dr. Sinn
 */
static int* ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_XDT_FIELD = NUMBER_4514_INTEGER_ARRAY;

/**
 * The accident kind of first treatment field.
 *
 * German: Art dieser ersten ärztlichen Behandlung
 * Size: <= 70
 * Type: character array
 * Rule: --
 * Example: Erstversorgung Fraktur
 */
static int* ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD = NUMBER_4515_INTEGER_ARRAY;

/**
 * The accident alcohol influence field.
 *
 * German: Alkoholeinfluß
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_ALCOHOL_INFLUENCE_XDT_FIELD = NUMBER_4520_INTEGER_ARRAY;

/**
 * The accident signs for alcohol influence field.
 *
 * German: Anzeichen des Alkoholeinflusses
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Nein
 */
static int* ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_XDT_FIELD = NUMBER_4521_INTEGER_ARRAY;

/**
 * The accident blood withdrawal field.
 *
 * German: Blutentnahme
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_BLOOD_WITHDRAWAL_XDT_FIELD = NUMBER_4522_INTEGER_ARRAY;

/**
 * The accident findings field.
 *
 * German: Befund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: erhöhter Blutdruck
 */
static int* ACCIDENT_FINDINGS_XDT_FIELD = NUMBER_4530_INTEGER_ARRAY;

/**
 * The accident x-ray result field.
 *
 * German: Röntgenergebnis
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sprunggelenktorsion
 */
static int* ACCIDENT_X_RAY_RESULT_XDT_FIELD = NUMBER_4540_INTEGER_ARRAY;

/**
 * The accident kind of first treatment field.
 *
 * German: Art etwaiger Erstversorgung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schienung Fraktur
 */
static int* ACCIDENT_KIND_OF_FIRST_TREATMENT_XDT_FIELD = NUMBER_4550_INTEGER_ARRAY;

/**
 * The accident abnormal changes independent from accident field.
 *
 * German: Krankhafte Veränderungen unabhängig vom Unfall
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_XDT_FIELD = NUMBER_4551_INTEGER_ARRAY;

/**
 * The accident concerns against statements field.
 *
 * German: Bedenken gegen Angaben
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: -
 */
static int* ACCIDENT_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD = NUMBER_4552_INTEGER_ARRAY;

/**
 * The accident kind of concerns against statements field.
 *
 * German: Art der Bedenken
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_XDT_FIELD = NUMBER_4553_INTEGER_ARRAY;

/**
 * The accident concerns against classification as accident at work field.
 *
 * German: Bedenken gegen Vorliegen eines Arbeitsunfalles
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD = NUMBER_4554_INTEGER_ARRAY;

/**
 * The accident kind of concerns against classification as accident at work field.
 *
 * German: Art der Bedenken
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: keine versicherte Tätigkeit
 */
static int* ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_XDT_FIELD = NUMBER_4555_INTEGER_ARRAY;

/**
 * The accident able to work field.
 *
 * German: arbeitsfähig
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* ACCIDENT_ABLE_TO_WORK_XDT_FIELD = NUMBER_4560_INTEGER_ARRAY;

/**
 * The accident able to work from field.
 *
 * German: wieder arbeitsfähig ab
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 01121993
 */
static int* ACCIDENT_ABLE_TO_WORK_FROM_XDT_FIELD = NUMBER_4561_INTEGER_ARRAY;

/**
 * The accident unable to work certificate issuance date field.
 *
 * German: AU-Bescheinigung ausgestellt
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_DATE_XDT_FIELD = NUMBER_4562_INTEGER_ARRAY;

/**
 * The accident special curative treatment necessary field.
 *
 * German: Besondere Heilbehandlung erforderlich
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_XDT_FIELD = NUMBER_4570_INTEGER_ARRAY;

/**
 * The accident special curative treatment by field.
 *
 * German: Besondere Heilbehandlung durch
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_XDT_FIELD = NUMBER_4571_INTEGER_ARRAY;

/**
 * The accident address of treating physician field.
 *
 * German: Anschrift des behandelnden Arztes
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Herbst
 */
static int* ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_XDT_FIELD = NUMBER_4572_INTEGER_ARRAY;

/**
 * The accident unable to work from field.
 *
 * German: AU ab
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 13121993
 */
static int* ACCIDENT_UNABLE_TO_WORK_FROM_XDT_FIELD = NUMBER_4573_INTEGER_ARRAY;

/**
 * The accident expected duration of inability to work field.
 *
 * German: voraussichtliche Dauer der AU
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 012
 */
static int* ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_XDT_FIELD = NUMBER_4574_INTEGER_ARRAY;

/**
 * The accident kind of bill field.
 *
 * German: Rechnungsart
 * Size: 2
 * Type: integer
 * Rule: -
 * Example: 80
 */
static int* ACCIDENT_KIND_OF_BILL_XDT_FIELD = NUMBER_4580_INTEGER_ARRAY;

/**
 * The accident general curative treatment by field.
 *
 * German: Allgemeine Heilbehandlung durch
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_XDT_FIELD = NUMBER_4581_INTEGER_ARRAY;

/**
 * The accident unable to work for longer than three days field.
 *
 * German: AU über 3 Tage
 * Size: 1
 * Type: integer
 * Rule: 101
 * Example: 1
 */
static int* ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_XDT_FIELD = NUMBER_4582_INTEGER_ARRAY;

/**
 * The accident unability to work certified until field.
 *
 * German: AU bescheinigt bis
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_XDT_FIELD = NUMBER_4583_INTEGER_ARRAY;

/**
 * The accident inspection required on field.
 *
 * German: Nachschau erforderlich am
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11111993
 */
static int* ACCIDENT_INSPECTION_REQUIRED_ON_XDT_FIELD = NUMBER_4584_INTEGER_ARRAY;

/**
 * The billing number field.
 *
 * German: Rechnungsnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 54/66
 */
static int* BILLING_NUMBER_XDT_FIELD = NUMBER_4601_INTEGER_ARRAY;

/**
 * The billing address field.
 *
 * German: Rechnungsanschrift
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Erwin Müller
 *          Ottostraße 123
 *          50859 Köln
 */
static int* BILLING_ADDRESS_XDT_FIELD = NUMBER_4602_INTEGER_ARRAY;

/**
 * The billing referring physician name field.
 *
 * German: Überweisender Arzt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Regenbogen
 */
static int* BILLING_REFERRING_PHYSICIAN_NAME_XDT_FIELD = NUMBER_4603_INTEGER_ARRAY;

/**
 * The billing date field.
 *
 * German: Rechnungsdatum
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 11101993
 */
static int* BILLING_DATE_XDT_FIELD = NUMBER_4604_INTEGER_ARRAY;

/**
 * The billing total sum field.
 *
 * German: Endsumme
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2130 DM
 */
static int* BILLING_TOTAL_SUM_XDT_FIELD = NUMBER_4605_INTEGER_ARRAY;

/**
 * The billing assignment declaration field.
 *
 * German: Abdingungserklärung
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 1
 */
static int* BILLING_ASSIGNMENT_DECLARATION_XDT_FIELD = NUMBER_4608_INTEGER_ARRAY;

/**
 * The billing physician sub account field.
 *
 * German: Unterkonto Arzt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2000
 */
static int* BILLING_PHYSICIAN_SUB_ACCOUNT_XDT_FIELD = NUMBER_4611_INTEGER_ARRAY;

/**
 * The billing attachment field.
 *
 * German: Anlage zur Rechnung
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* BILLING_ATTACHMENT_XDT_FIELD = NUMBER_4613_INTEGER_ARRAY;

/**
 * The billing header field.
 *
 * German: Kopfzeile
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Rechn. v. 01.07.92
 */
static int* BILLING_HEADER_XDT_FIELD = NUMBER_4615_INTEGER_ARRAY;

/**
 * The billing footer field.
 *
 * German: Fußzeile
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Alle Angaben sind streng vertraulich
 */
static int* BILLING_FOOTER_XDT_FIELD = NUMBER_4617_INTEGER_ARRAY;

/**
 * The service treatment date field.
 *
 * German: Leistungstag
 * Size: 8
 * Type: date
 * Rule: 008/304/324
 * Example: 11101993
 */
static int* SERVICE_TREATMENT_DATE_XDT_FIELD = NUMBER_5000_INTEGER_ARRAY;

/**
 * The service gnr identification field.
 *
 * German: GNR/GNR-Ident
 * Size: 1-7
 * Type: character array
 * Rule: -
 * Example: 61
 */
static int* SERVICE_GNR_IDENTIFICATION_XDT_FIELD = NUMBER_5001_INTEGER_ARRAY;

/**
 * The service kind of examination field.
 *
 * German: Art der Untersuchung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Esterasereaktion
 */
static int* SERVICE_KIND_OF_EXAMINATION_XDT_FIELD = NUMBER_5002_INTEGER_ARRAY;

/**
 * The service addressee field.
 *
 * German: Empfänger des Briefes
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Dr. Meier
 */
static int* SERVICE_ADDRESSEE_XDT_FIELD = NUMBER_5003_INTEGER_ARRAY;

/**
 * The service distance in kilometres field.
 *
 * German: Kilometer (nur bei GOÄ)
 * Size: 1-3
 * Type: integer
 * Rule: 325
 * Example: 17
 */
static int* SERVICE_DISTANCE_IN_KILOMETRES_XDT_FIELD = NUMBER_5004_INTEGER_ARRAY;

/**
 * The service multiplier field.
 *
 * German: Multiplikator
 * Size: 2
 * Type: integer
 * Rule: -
 * Example: 3
 */
static int* SERVICE_MULTIPLIER_XDT_FIELD = NUMBER_5005_INTEGER_ARRAY;

/**
 * The service time field.
 *
 * German: Um-Uhrzeit
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1215
 */
static int* SERVICE_TIME_XDT_FIELD = NUMBER_5006_INTEGER_ARRAY;

/**
 * The service order-execution time field.
 *
 * German: Bestellzeit-Ausführungszeit
 * Size: 8
 * Type: integer
 * Rule: 006
 * Example: 12151230
 */
static int* SERVICE_ORDER_EXECUTION_XDT_FIELD = NUMBER_5007_INTEGER_ARRAY;

/**
 * The service dkm field.
 *
 * German: DKM
 * Size: 1-3
 * Type: integer
 * Rule: -
 * Example: 23
 */
static int* SERVICE_DKM_XDT_FIELD = NUMBER_5008_INTEGER_ARRAY;

/**
 * The service free explanatory statement field.
 *
 * German: freier Begründungstext
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2. Untersuchung
 */
static int* SERVICE_FREE_EXPLANATORY_STATEMENT_XDT_FIELD = NUMBER_5009_INTEGER_ARRAY;

/**
 * The service explanatory drug field.
 *
 * German: Medikament als Begründung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Insulin
 */
static int* SERVICE_EXPLANATORY_DRUG_XDT_FIELD = NUMBER_5010_INTEGER_ARRAY;

/**
 * The service material costs description field.
 *
 * German: Sachkosten-Bezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Norm-Silberstift
 */
static int* SERVICE_MATERIAL_COSTS_DESCRIPTION_XDT_FIELD = NUMBER_5011_INTEGER_ARRAY;

/**
 * The service material costs dpf field.
 *
 * German: Sachkosten-/Materialkosten (Dpf)
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: 12345
 */
static int* SERVICE_MATERIAL_COSTS_DPF_XDT_FIELD = NUMBER_5012_INTEGER_ARRAY;

/**
 * The service percent of treatment field.
 *
 * German: Prozent der Leistung
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 50
 */
static int* SERVICE_PERCENT_OF_TREATMENT_XDT_FIELD = NUMBER_5013_INTEGER_ARRAY;

/**
 * The service organ field.
 *
 * German: Organ
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Niere
 */
static int* SERVICE_ORGAN_XDT_FIELD = NUMBER_5015_INTEGER_ARRAY;

/**
 * The service location field.
 *
 * German: Besuchsort bei Hausbesuchen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Neustadt
 */
static int* SERVICE_LOCATION_XDT_FIELD = NUMBER_5017_INTEGER_ARRAY;

/**
 * The service zone field.
 *
 * German: Zone bei Besuchen
 * Size: 2
 * Type: integer
 * Rule: 111
 * Example: Z1
 */
static int* SERVICE_ZONE_XDT_FIELD = NUMBER_5018_INTEGER_ARRAY;

/**
 * The service gnr description field.
 *
 * German: Beschreibung der GNR bei Privatabrechnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Injektion, intravenös
 */
static int* SERVICE_GNR_DESCRIPTION_XDT_FIELD = NUMBER_5060_INTEGER_ARRAY;

/**
 * The service fee field.
 *
 * German: Gebühr bei Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 12.80
 */
static int* SERVICE_FEE_XDT_FIELD = NUMBER_5061_INTEGER_ARRAY;

/**
 * The service factor field.
 *
 * German: Faktor bei Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 2.3
 */
static int* SERVICE_FACTOR_XDT_FIELD = NUMBER_5062_INTEGER_ARRAY;

/**
 * The service sum field.
 *
 * German: Betrag bei Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 25.85
 */
static int* SERVICE_SUM_XDT_FIELD = NUMBER_5063_INTEGER_ARRAY;

/**
 * The service total sum field.
 *
 * German: Endsumme Privatrechnung
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 1324.65
 */
static int* SERVICE_TOTAL_SUM_XDT_FIELD = NUMBER_5064_INTEGER_ARRAY;

/**
 * The service point value field.
 *
 * German: Punktwert
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 18
 */
static int* SERVICE_POINT_VALUE_XDT_FIELD = NUMBER_5065_INTEGER_ARRAY;

/**
 * The service name of fee field.
 *
 * German: Honorarbezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 18
 */
static int* SERVICE_NAME_OF_FEE_XDT_FIELD = NUMBER_5090_INTEGER_ARRAY;

/**
 * The service name of certificate field.
 *
 * German: Gutachten-Bezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 18
 */
static int* SERVICE_NAME_OF_CERTIFICATE_XDT_FIELD = NUMBER_5091_INTEGER_ARRAY;

/**
 * The billing diagnosis field.
 *
 * German: Abrechnungsdiagnose
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Diabetes mellitus
 */
static int* BILLING_DIAGNOSIS_XDT_FIELD = NUMBER_6000_INTEGER_ARRAY;

/**
 * The billing icd key field.
 *
 * German: ICD-Schlüssel
 * Size: 5
 * Type: character array
 * Rule: -
 * Example: 250.0
 */
static int* BILLING_ICD_KEY_XDT_FIELD = NUMBER_6001_INTEGER_ARRAY;

/**
 * The treatment data storage date field.
 *
 * German: Tag der Erhebung von Behandlungsdaten (taken from new GDT version;
 *         was "Tag der Speicherung von Behandlungsdaten" in old BDT)
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 12031993
 */
static int* TREATMENT_DATA_COLLECTION_DATE_XDT_FIELD = NUMBER_6200_INTEGER_ARRAY;

/**
 * The treatment data storage time field.
 *
 * German: Uhrzeit der Erhebung von Behandlungsdaten
 * Size: 6
 * Type: time
 * Rule: 090 HHMMSS
 * Example: 132201
 */
static int* TREATMENT_DATA_COLLECTION_TIME_XDT_FIELD = NUMBER_6201_INTEGER_ARRAY;

/**
 * The treatment current diagnosis field.
 *
 * German: Aktuelle Diagnose
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Diabetes
 */
static int* TREATMENT_CURRENT_DIAGNOSIS_XDT_FIELD = NUMBER_6205_INTEGER_ARRAY;

/**
 * The treatment drug prescribed with prescription field.
 *
 * German: Medikament verordnet auf Rezept
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Adalat
 */
static int* TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_XDT_FIELD = NUMBER_6210_INTEGER_ARRAY;

/**
 * The treatment drug prescribed without prescription field.
 *
 * German: Außerhalb Rezept verordnetes Medikament
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sostril
 */
static int* TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_XDT_FIELD = NUMBER_6211_INTEGER_ARRAY;

/**
 * The treatment physician sample field.
 *
 * German: Ärztemuster
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Nifedepin
 */
static int* TREATMENT_PHYSICIAN_SAMPLE_XDT_FIELD = NUMBER_6215_INTEGER_ARRAY;

/**
 * The treatment findings field.
 *
 * German: Befund
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: erhöhter Blutdruck
 */
static int* TREATMENT_FINDINGS_XDT_FIELD = NUMBER_6220_INTEGER_ARRAY;

/**
 * The treatment external findings field.
 *
 * German: Fremdbefund
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Verdacht auf Obstruktion (taken from new GDT version; was "Bartolin.-cyste, re" in old BDT)
 */
static int* TREATMENT_EXTERNAL_FINDINGS_XDT_FIELD = NUMBER_6221_INTEGER_ARRAY;

/**
 * The treatment laboratory findings field.
 *
 * German: Laborbefund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Eiweiß erhöht
 */
static int* TREATMENT_LABORATORY_FINDINGS_XDT_FIELD = NUMBER_6222_INTEGER_ARRAY;

/**
 * The treatment x-ray findings field.
 *
 * German: Röntgenbefund
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Schatten auf Lunge
 */
static int* TREATMENT_X_RAY_FINDINGS_XDT_FIELD = NUMBER_6225_INTEGER_ARRAY;

/**
 * The treatment subsequent line count field.
 *
 * German: Anzahl Folgezeilen
 * Size: <= 4
 * Type: integer
 * Rule: -
 * Example: 2
 */
static int* TREATMENT_SUBSEQUENT_LINE_COUNT_XDT_FIELD = NUMBER_6226_INTEGER_ARRAY;

/**
 * The treatment comment field.
 *
 * German: Kommentar
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: Belastung abgebrochen
 */
static int* TREATMENT_COMMENT_XDT_FIELD = NUMBER_6227_INTEGER_ARRAY;

/**
 * The treatment formatted result table text field.
 *
 * German: Ergebnistabellentext, formatiert
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: s. Beispiele im Anhang
 */
static int* TREATMENT_FORMATTED_RESULT_TABLE_TEXT_XDT_FIELD = NUMBER_6228_INTEGER_ARRAY;

/**
 * The treatment blood pressure field.
 *
 * German: Blutdruck
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 140/90
 */
static int* TREATMENT_BLOOD_PRESSURE_XDT_FIELD = NUMBER_6230_INTEGER_ARRAY;

/**
 * The treatment symptoms field.
 *
 * German: Symptome
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Haarausfall
 */
static int* TREATMENT_SYMPTOMS_XDT_FIELD = NUMBER_6240_INTEGER_ARRAY;

/**
 * The treatment therapy field.
 *
 * German: Therapie
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Novalgin 3x täglich
 */
static int* TREATMENT_THERAPY_XDT_FIELD = NUMBER_6260_INTEGER_ARRAY;

/**
 * The treatment physical therapy field.
 *
 * German: Physikalische Therapie
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Massagen
 */
static int* TREATMENT_PHYSICAL_THERAPY_XDT_FIELD = NUMBER_6265_INTEGER_ARRAY;

/**
 * The treatment referral content field.
 *
 * German: Überweisung Inhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Röntgen Thorax
 */
static int* TREATMENT_REFERRAL_CONTENT_XDT_FIELD = NUMBER_6280_INTEGER_ARRAY;

/**
 * The treatment work disability duration field.
 *
 * German: AU Dauer
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 1110199311111993
 */
static int* TREATMENT_WORK_DISABILITY_DURATION_XDT_FIELD = NUMBER_6285_INTEGER_ARRAY;

/**
 * The treatment work disability cause field.
 *
 * German: AU wegen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Nasenbeinfraktur
 */
static int* TREATMENT_WORK_DISABILITY_CAUSE_XDT_FIELD = NUMBER_6286_INTEGER_ARRAY;

/**
 * The treatment hospitalisation field.
 *
 * German: Krankenhauseinweisung, Krankenhaus
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Marienhospital
 */
static int* TREATMENT_HOSPITALISATION_XDT_FIELD = NUMBER_6290_INTEGER_ARRAY;

/**
 * The treatment hospitalisation cause field.
 *
 * German: Krankenhauseinweisung wegen
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: stark blutende Wunde
 */
static int* TREATMENT_HOSPITALISATION_CAUSE_XDT_FIELD = NUMBER_6291_INTEGER_ARRAY;

/**
 * The letter certificate kind field.
 *
 * German: Bescheinigung, Art
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Impfbescheinigung
 */
static int* LETTER_CERTIFICATE_KIND_XDT_FIELD = NUMBER_6300_INTEGER_ARRAY;

/**
 * The letter certificate content field.
 *
 * German: Bescheinigung, Inhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Tetanusschutzimpfung
 */
static int* LETTER_CERTIFICATE_CONTENT_XDT_FIELD = NUMBER_6301_INTEGER_ARRAY;

/**
 * The letter file archive number field.
 *
 * German: Datei-Archivierungsnummer
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: 000001
 */
static int* LETTER_FILE_ARCHIVE_NUMBER_XDT_FIELD = NUMBER_6302_INTEGER_ARRAY;

/**
 * The letter file format field.
 *
 * German: Dateiformat
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: PDF
 */
static int* LETTER_FILE_FORMAT_XDT_FIELD = NUMBER_6303_INTEGER_ARRAY;

/**
 * The letter file content field.
 *
 * German: Dateiinhalt
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: Datenanalyse
 */
static int* LETTER_FILE_CONTENT_XDT_FIELD = NUMBER_6304_INTEGER_ARRAY;

/**
 * The letter file url field.
 *
 * German: Verweis auf Datei (URL)
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: \\FS1\DATA\00712.PDF
 */
static int* LETTER_FILE_URL_XDT_FIELD = NUMBER_6305_INTEGER_ARRAY;

/**
 * The letter attestation kind field.
 *
 * German: Attest, Art
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sportbefreiungsattest
 */
static int* LETTER_ATTESTATION_KIND_XDT_FIELD = NUMBER_6306_INTEGER_ARRAY;

/**
 * The letter attestation content field.
 *
 * German: Attest, Inhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Lebensmittelallergie
 */
static int* LETTER_ATTESTATION_CONTENT_XDT_FIELD = NUMBER_6307_INTEGER_ARRAY;

/**
 * The letter addressee field.
 *
 * German: Name des Briefempfängers
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Egon Müller
 */
static int* LETTER_ADDRESSEE_XDT_FIELD = NUMBER_6310_INTEGER_ARRAY;

/**
 * The letter salutation field.
 *
 * German: Anrede
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Herrn Dr.
 */
static int* LETTER_SALUTATION_XDT_FIELD = NUMBER_6311_INTEGER_ARRAY;

/**
 * The letter street field.
 *
 * German: Straße
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Moltkestr. 108
 */
static int* LETTER_STREET_XDT_FIELD = NUMBER_6312_INTEGER_ARRAY;

/**
 * The letter postcode field.
 *
 * German: PLZ
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 50859
 */
static int* LETTER_POSTCODE_XDT_FIELD = NUMBER_6313_INTEGER_ARRAY;

/**
 * The letter residence field.
 *
 * German: Wohnort
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Köln
 */
static int* LETTER_RESIDENCE_XDT_FIELD = NUMBER_6314_INTEGER_ARRAY;

/**
 * The letter complimentary close field.
 *
 * German: Schlußsatz
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Mit kollegialem Gruß
 */
static int* LETTER_COMPLIMENTARY_CLOSE_XDT_FIELD = NUMBER_6315_INTEGER_ARRAY;

/**
 * The letter phone field.
 *
 * German: Telefon-Nummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/123456
 */
static int* LETTER_PHONE_XDT_FIELD = NUMBER_6316_INTEGER_ARRAY;

/**
 * The letter fax field.
 *
 * German: Telefax-Nummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 0221/123675
 */
static int* LETTER_FAX_XDT_FIELD = NUMBER_6317_INTEGER_ARRAY;

/**
 * The letter physician number field.
 *
 * German: Arztnummer/Arztident
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 2780100
 */
static int* LETTER_PHYSICIAN_NUMBER_XDT_FIELD = NUMBER_6319_INTEGER_ARRAY;

/**
 * The letter content field.
 *
 * German: Briefinhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: Sehr geehrter ...
 */
static int* LETTER_CONTENT_XDT_FIELD = NUMBER_6320_INTEGER_ARRAY;

/**
 * The letter image archive number field.
 *
 * German: Bild-Archivierungsnummer
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 3735
 */
static int* LETTER_IMAGE_ARCHIVE_NUMBER_XDT_FIELD = NUMBER_6325_INTEGER_ARRAY;

/**
 * The letter graphic format field.
 *
 * German: Grafikformat
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: PIF
 */
static int* LETTER_GRAPHIC_FORMAT_XDT_FIELD = NUMBER_6326_INTEGER_ARRAY;

/**
 * The letter image content field.
 *
 * German: Bildinhalt
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* LETTER_IMAGE_CONTENT_XDT_FIELD = NUMBER_6327_INTEGER_ARRAY;

/**
 * The free record 6200 category 1 name field.
 *
 * German: Name der ersten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_1_NAME_XDT_FIELD = NUMBER_6330_INTEGER_ARRAY;

/**
 * The free record 6200 category 1 value field.
 *
 * German: Inhalt der ersten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_1_VALUE_XDT_FIELD = NUMBER_6331_INTEGER_ARRAY;

/**
 * The free record 6200 category 2 name field.
 *
 * German: Name der zweiten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_2_NAME_XDT_FIELD = NUMBER_6332_INTEGER_ARRAY;

/**
 * The free record 6200 category 2 value field.
 *
 * German: Inhalt der zweiten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_2_VALUE_XDT_FIELD = NUMBER_6333_INTEGER_ARRAY;

/**
 * The free record 6200 category 3 name field.
 *
 * German: Name der dritten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_3_NAME_XDT_FIELD = NUMBER_6334_INTEGER_ARRAY;

/**
 * The free record 6200 category 3 value field.
 *
 * German: Inhalt der dritten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_3_VALUE_XDT_FIELD = NUMBER_6335_INTEGER_ARRAY;

/**
 * The free record 6200 category 4 name field.
 *
 * German: Name der vierten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_4_NAME_XDT_FIELD = NUMBER_6336_INTEGER_ARRAY;

/**
 * The free record 6200 category 4 value field.
 *
 * German: Inhalt der vierten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_4_VALUE_XDT_FIELD = NUMBER_6337_INTEGER_ARRAY;

/**
 * The free record 6200 category 5 name field.
 *
 * German: Name der fünften freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_5_NAME_XDT_FIELD = NUMBER_6338_INTEGER_ARRAY;

/**
 * The free record 6200 category 5 value field.
 *
 * German: Inhalt der fünften freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_5_VALUE_XDT_FIELD = NUMBER_6339_INTEGER_ARRAY;

/**
 * The free record 6200 category 6 name field.
 *
 * German: Name der sechsten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_6_NAME_XDT_FIELD = NUMBER_6340_INTEGER_ARRAY;

/**
 * The free record 6200 category 6 value field.
 *
 * German: Inhalt der sechsten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_6_VALUE_XDT_FIELD = NUMBER_6341_INTEGER_ARRAY;

/**
 * The free record 6200 category 7 name field.
 *
 * German: Name der siebten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_7_NAME_XDT_FIELD = NUMBER_6342_INTEGER_ARRAY;

/**
 * The free record 6200 category 7 value field.
 *
 * German: Inhalt der siebten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_7_VALUE_XDT_FIELD = NUMBER_6343_INTEGER_ARRAY;

/**
 * The free record 6200 category 8 name field.
 *
 * German: Name der achten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_8_NAME_XDT_FIELD = NUMBER_6344_INTEGER_ARRAY;

/**
 * The free record 6200 category 8 value field.
 *
 * German: Inhalt der achten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_8_VALUE_XDT_FIELD = NUMBER_6345_INTEGER_ARRAY;

/**
 * The free record 6200 category 9 name field.
 *
 * German: Name der neunten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_9_NAME_XDT_FIELD = NUMBER_6346_INTEGER_ARRAY;

/**
 * The free record 6200 category 9 value field.
 *
 * German: Inhalt der neunten freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_9_VALUE_XDT_FIELD = NUMBER_6347_INTEGER_ARRAY;

/**
 * The free record 6200 category 10 name field.
 *
 * German: Name der 10. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_10_NAME_XDT_FIELD = NUMBER_6348_INTEGER_ARRAY;

/**
 * The free record 6200 category 10 value field.
 *
 * German: Inhalt der 10. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_10_VALUE_XDT_FIELD = NUMBER_6349_INTEGER_ARRAY;

/**
 * The free record 6200 category 11 name field.
 *
 * German: Name der 11. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_11_NAME_XDT_FIELD = NUMBER_6350_INTEGER_ARRAY;

/**
 * The free record 6200 category 11 value field.
 *
 * German: Inhalt der 11. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_11_VALUE_XDT_FIELD = NUMBER_6351_INTEGER_ARRAY;

/**
 * The free record 6200 category 12 name field.
 *
 * German: Name der 12. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_12_NAME_XDT_FIELD = NUMBER_6352_INTEGER_ARRAY;

/**
 * The free record 6200 category 12 value field.
 *
 * German: Inhalt der 12. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_12_VALUE_XDT_FIELD = NUMBER_6353_INTEGER_ARRAY;

/**
 * The free record 6200 category 13 name field.
 *
 * German: Name der 13. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_13_NAME_XDT_FIELD = NUMBER_6354_INTEGER_ARRAY;

/**
 * The free record 6200 category 13 value field.
 *
 * German: Inhalt der 13. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_13_VALUE_XDT_FIELD = NUMBER_6355_INTEGER_ARRAY;

/**
 * The free record 6200 category 14 name field.
 *
 * German: Name der 14. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_14_NAME_XDT_FIELD = NUMBER_6356_INTEGER_ARRAY;

/**
 * The free record 6200 category 14 value field.
 *
 * German: Inhalt der 14. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_14_VALUE_XDT_FIELD = NUMBER_6357_INTEGER_ARRAY;

/**
 * The free record 6200 category 15 name field.
 *
 * German: Name der 15. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_15_NAME_XDT_FIELD = NUMBER_6358_INTEGER_ARRAY;

/**
 * The free record 6200 category 15 value field.
 *
 * German: Inhalt der 15. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_15_VALUE_XDT_FIELD = NUMBER_6359_INTEGER_ARRAY;

/**
 * The free record 6200 category 16 name field.
 *
 * German: Name der 16. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_16_NAME_XDT_FIELD = NUMBER_6360_INTEGER_ARRAY;

/**
 * The free record 6200 category 16 value field.
 *
 * German: Inhalt der 16. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_16_VALUE_XDT_FIELD = NUMBER_6361_INTEGER_ARRAY;

/**
 * The free record 6200 category 17 name field.
 *
 * German: Name der 17. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_17_NAME_XDT_FIELD = NUMBER_6362_INTEGER_ARRAY;

/**
 * The free record 6200 category 17 value field.
 *
 * German: Inhalt der 17. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_17_VALUE_XDT_FIELD = NUMBER_6363_INTEGER_ARRAY;

/**
 * The free record 6200 category 18 name field.
 *
 * German: Name der 18. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_18_NAME_XDT_FIELD = NUMBER_6364_INTEGER_ARRAY;

/**
 * The free record 6200 category 18 value field.
 *
 * German: Inhalt der 18. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_18_VALUE_XDT_FIELD = NUMBER_6365_INTEGER_ARRAY;

/**
 * The free record 6200 category 19 name field.
 *
 * German: Name der 19. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_19_NAME_XDT_FIELD = NUMBER_6366_INTEGER_ARRAY;

/**
 * The free record 6200 category 19 value field.
 *
 * German: Inhalt der 19. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_19_VALUE_XDT_FIELD = NUMBER_6367_INTEGER_ARRAY;

/**
 * The free record 6200 category 20 name field.
 *
 * German: Name der 20. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_20_NAME_XDT_FIELD = NUMBER_6368_INTEGER_ARRAY;

/**
 * The free record 6200 category 20 value field.
 *
 * German: Inhalt der 20. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_20_VALUE_XDT_FIELD = NUMBER_6369_INTEGER_ARRAY;

/**
 * The free record 6200 category 21 name field.
 *
 * German: Name der 21. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_21_NAME_XDT_FIELD = NUMBER_6370_INTEGER_ARRAY;

/**
 * The free record 6200 category 21 value field.
 *
 * German: Inhalt der 21. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_21_VALUE_XDT_FIELD = NUMBER_6371_INTEGER_ARRAY;

/**
 * The free record 6200 category 22 name field.
 *
 * German: Name der 22. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_22_NAME_XDT_FIELD = NUMBER_6372_INTEGER_ARRAY;

/**
 * The free record 6200 category 22 value field.
 *
 * German: Inhalt der 22. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_22_VALUE_XDT_FIELD = NUMBER_6373_INTEGER_ARRAY;

/**
 * The free record 6200 category 23 name field.
 *
 * German: Name der 23. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_23_NAME_XDT_FIELD = NUMBER_6374_INTEGER_ARRAY;

/**
 * The free record 6200 category 23 value field.
 *
 * German: Inhalt der 23. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_23_VALUE_XDT_FIELD = NUMBER_6375_INTEGER_ARRAY;

/**
 * The free record 6200 category 24 name field.
 *
 * German: Name der 24. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_24_NAME_XDT_FIELD = NUMBER_6376_INTEGER_ARRAY;

/**
 * The free record 6200 category 24 value field.
 *
 * German: Inhalt der 24. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_24_VALUE_XDT_FIELD = NUMBER_6377_INTEGER_ARRAY;

/**
 * The free record 6200 category 25 name field.
 *
 * German: Name der 25. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_25_NAME_XDT_FIELD = NUMBER_6378_INTEGER_ARRAY;

/**
 * The free record 6200 category 25 value field.
 *
 * German: Inhalt der 25. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_25_VALUE_XDT_FIELD = NUMBER_6379_INTEGER_ARRAY;

/**
 * The free record 6200 category 26 name field.
 *
 * German: Name der 26. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_26_NAME_XDT_FIELD = NUMBER_6380_INTEGER_ARRAY;

/**
 * The free record 6200 category 26 value field.
 *
 * German: Inhalt der 26. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_26_VALUE_XDT_FIELD = NUMBER_6381_INTEGER_ARRAY;

/**
 * The free record 6200 category 27 name field.
 *
 * German: Name der 27. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_27_NAME_XDT_FIELD = NUMBER_6382_INTEGER_ARRAY;

/**
 * The free record 6200 category 27 value field.
 *
 * German: Inhalt der 27. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_27_VALUE_XDT_FIELD = NUMBER_6383_INTEGER_ARRAY;

/**
 * The free record 6200 category 28 name field.
 *
 * German: Name der 28. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_28_NAME_XDT_FIELD = NUMBER_6384_INTEGER_ARRAY;

/**
 * The free record 6200 category 28 value field.
 *
 * German: Inhalt der 28. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_28_VALUE_XDT_FIELD = NUMBER_6385_INTEGER_ARRAY;

/**
 * The free record 6200 category 29 name field.
 *
 * German: Name der 29. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_29_NAME_XDT_FIELD = NUMBER_6386_INTEGER_ARRAY;

/**
 * The free record 6200 category 29 value field.
 *
 * German: Inhalt der 29. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_29_VALUE_XDT_FIELD = NUMBER_6387_INTEGER_ARRAY;

/**
 * The free record 6200 category 30 name field.
 *
 * German: Name der 30. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_30_NAME_XDT_FIELD = NUMBER_6388_INTEGER_ARRAY;

/**
 * The free record 6200 category 30 value field.
 *
 * German: Inhalt der 30. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_30_VALUE_XDT_FIELD = NUMBER_6389_INTEGER_ARRAY;

/**
 * The free record 6200 category 31 name field.
 *
 * German: Name der 31. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_31_NAME_XDT_FIELD = NUMBER_6390_INTEGER_ARRAY;

/**
 * The free record 6200 category 31 value field.
 *
 * German: Inhalt der 31. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_31_VALUE_XDT_FIELD = NUMBER_6391_INTEGER_ARRAY;

/**
 * The free record 6200 category 32 name field.
 *
 * German: Name der 32. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_32_NAME_XDT_FIELD = NUMBER_6392_INTEGER_ARRAY;

/**
 * The free record 6200 category 32 value field.
 *
 * German: Inhalt der 32. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_32_VALUE_XDT_FIELD = NUMBER_6393_INTEGER_ARRAY;

/**
 * The free record 6200 category 33 name field.
 *
 * German: Name der 33. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_33_NAME_XDT_FIELD = NUMBER_6394_INTEGER_ARRAY;

/**
 * The free record 6200 category 33 value field.
 *
 * German: Inhalt der 33. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_33_VALUE_XDT_FIELD = NUMBER_6395_INTEGER_ARRAY;

/**
 * The free record 6200 category 34 name field.
 *
 * German: Name der 34. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_34_NAME_XDT_FIELD = NUMBER_6396_INTEGER_ARRAY;

/**
 * The free record 6200 category 34 value field.
 *
 * German: Inhalt der 34. freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_34_VALUE_XDT_FIELD = NUMBER_6397_INTEGER_ARRAY;

/**
 * The free record 6200 category 35 name field.
 *
 * German: Name der 35. (letzten) freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_35_NAME_XDT_FIELD = NUMBER_6398_INTEGER_ARRAY;

/**
 * The free record 6200 category 35 value field.
 *
 * German: Inhalt der 35. (letzten) freien Kategorie Satzart "6200"
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FREE_RECORD_6200_CATEGORY_35_VALUE_XDT_FIELD = NUMBER_6399_INTEGER_ARRAY;

/**
 * The record identification field.
 *
 * German: Satzidentifikation
 * Size: 4
 * Type: integer
 * Rule: 167
 * Example: 0102
 */
static int* RECORD_IDENTIFICATION_XDT_FIELD = NUMBER_8000_INTEGER_ARRAY;

/**
 * The record size field.
 *
 * German: Satzlänge
 * Size: 5
 * Type: integer
 * Rule: -
 * Example: 00747
 */
static int* RECORD_SIZE_XDT_FIELD = NUMBER_8100_INTEGER_ARRAY;

/**
 * The device receiver gdt id field.
 *
 * German: GDT - ID des Empfängers
 * Size: 8
 * Type: character array
 * Rule: -
 * Example: ROP200U1
 */
static int* DEVICE_RECEIVER_GDT_ID_XDT_FIELD = NUMBER_8315_INTEGER_ARRAY;

/**
 * The device sender gdt id field.
 *
 * German: GDT - ID des Senders
 * Size: 8
 * Type: character array
 * Rule: -
 * Example: PRAX_EDV
 */
static int* DEVICE_SENDER_GDT_ID_XDT_FIELD = NUMBER_8316_INTEGER_ARRAY;

/**
 * The findings kind field.
 *
 * German: Befundart
 * Size: 1
 * Type: character array
 * Rule: -
 * Example: E
 */
static int* FINDINGS_KIND_XDT_FIELD = NUMBER_8401_INTEGER_ARRAY;

/**
 * The findings device specifics field.
 *
 * German: Geräte und verfahrensspezifisches Kennfeld
 * Size: <= 6 (taken from new GDT version; was 2 in old BDT)
 * Type: character array
 * Rule: -
 * Example: EKG01 (taken from new GDT version; was 10 in old BDT), see GDT appendix B
 */
static int* FINDINGS_DEVICE_SPECIFICS_XDT_FIELD = NUMBER_8402_INTEGER_ARRAY;

/**
 * The findings test identification field.
 *
 * German: Test-Ident
 * Size: <= 20 (taken from new GDT version; was 6 in old BDT)
 * Type: character array
 * Rule: -
 * Example: FEV1 (taken from new GDT version; was "Ka" in old BDT)
 */
static int* FINDINGS_TEST_IDENTIFICATION_XDT_FIELD = NUMBER_8410_INTEGER_ARRAY;

/**
 * The findings test name field.
 *
 * German: Testbezeichnung
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Obj. refr. cyl. rechts (taken from new GDT version; was "Kalium" in old BDT)
 */
static int* FINDINGS_TEST_NAME_XDT_FIELD = NUMBER_8411_INTEGER_ARRAY;

/**
 * The findings test status field.
 *
 * German: Teststatus
 * Size: 1
 * Type: character array
 * Rule: -
 * Example: B
 */
static int* FINDINGS_TEST_STATUS_XDT_FIELD = NUMBER_8418_INTEGER_ARRAY;

/**
 * The findings test result value field.
 *
 * German: Ergebnis-Wert
 * Size: variable (taken from new GDT version; was <= 70 in old BDT)
 * Type: float (taken from new GDT version; was "character array" in old BDT)
 * Rule: -
 * Example: -3.7 (taken from new GDT version; was 4,7 in old BDT)
 */
static int* FINDINGS_TEST_RESULT_VALUE_XDT_FIELD = NUMBER_8420_INTEGER_ARRAY;

/**
 * The findings test result unit field.
 *
 * German: Einheit
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: dpt (taken from new GDT version; was "mMol/l" in old BDT)
 */
static int* FINDINGS_TEST_RESULT_UNIT_XDT_FIELD = NUMBER_8421_INTEGER_ARRAY;

/**
 * The findings limit indicator field.
 *
 * German: Grenzwert-Indikator
 * Size: <= 2
 * Type: character array
 * Rule: -
 * Example: ++
 */
static int* FINDINGS_LIMIT_INDICATOR_XDT_FIELD = NUMBER_8422_INTEGER_ARRAY;

/**
 * The findings sample material identification field.
 *
 * German: Probenmaterial-Ident
 * Size: <= 8
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_XDT_FIELD = NUMBER_8428_INTEGER_ARRAY;

/**
 * The findings sample material index field.
 *
 * German: Probenmaterial-Index (taken from new GDT version; was "Probenmaterial-Nummer" in old BDT)
 * Size: 2 (taken from new GDT version; was <= 70 in old BDT)
 * Type: integer (taken from new GDT version; was "character array" in old BDT)
 * Rule: -
 * Example: -
 */
static int* FINDINGS_SAMPLE_MATERIAL_INDEX_XDT_FIELD = NUMBER_8429_INTEGER_ARRAY;

/**
 * The findings sample material name field.
 *
 * German: Probenmaterialbezeichnung
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: - (taken from new GDT version; was "Serum" in old BDT)
 */
static int* FINDINGS_SAMPLE_MATERIAL_NAME_XDT_FIELD = NUMBER_8430_INTEGER_ARRAY;

/**
 * The findings sample material specification field.
 *
 * German: Probenmaterial-Spezifikation
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: - (taken from new GDT version; was "24HV:130 GR" in old BDT)
 */
static int* FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_XDT_FIELD = NUMBER_8431_INTEGER_ARRAY;

/**
 * The findings sample collection date field.
 *
 * German: Abnahme-Datum
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 31011994
 */
static int* FINDINGS_SAMPLE_COLLECTION_DATE_XDT_FIELD = NUMBER_8432_INTEGER_ARRAY;

/**
 * The findings sample collection time (old format) field.
 *
 * Obsolete? Defined by old BDT specification. See new collection time field number 8439!
 *
 * German: Abnahme-Zeit (altes Format, definiert in BDT Version von 1994)
 * Size: 4
 * Type: integer
 * Rule: 005
 * Example: 1045
 */
static int* FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_XDT_FIELD = NUMBER_8433_INTEGER_ARRAY;

/**
 * The findings data stream units field.
 *
 * German: Einheit(en) für Datenstrom
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: min, mmHg, mmHg
 */
static int* FINDINGS_DATA_STREAM_UNITS_XDT_FIELD = NUMBER_8437_INTEGER_ARRAY;

/**
 * The findings data stream field.
 *
 * German: Datenstrom
 * Size: <= 60
 * Type: character array
 * Rule: -
 * Example: 5,120,80... or: (5,120,80),(10,128,92)... and can also contain float values!
 */
static int* FINDINGS_DATA_STREAM_XDT_FIELD = NUMBER_8438_INTEGER_ARRAY;

/**
 * The findings sample collection time field.
 *
 * German: Abnahme-Zeit
 * Size: 6
 * Type: time
 * Rule: 090
 * Example: HHMMSS 125600
 */
static int* FINDINGS_SAMPLE_COLLECTION_TIME_XDT_FIELD = NUMBER_8439_INTEGER_ARRAY;

/**
 * The findings germ identification field.
 *
 * German: Keim-Ident
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_GERM_IDENTIFICATION_XDT_FIELD = NUMBER_8440_INTEGER_ARRAY;

/**
 * The findings germ name field.
 *
 * German: Keim-Bezeichnung
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_GERM_NAME_XDT_FIELD = NUMBER_8441_INTEGER_ARRAY;

/**
 * The findings germ number field.
 *
 * German: Keim-Nummer
 * Size: variable
 * Type: integer
 * Rule: -
 * Example: -
 */
static int* FINDINGS_GERM_NUMBER_XDT_FIELD = NUMBER_8442_INTEGER_ARRAY;

/**
 * The findings resistance method field.
 *
 * German: Resistenz-Methode
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 1
 */
static int* FINDINGS_RESISTANCE_METHOD_XDT_FIELD = NUMBER_8443_INTEGER_ARRAY;

/**
 * The findings active substance field.
 *
 * German: Wirkstoff-Ident
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_ACTIVE_SUBSTANCE_XDT_FIELD = NUMBER_8444_INTEGER_ARRAY;

/**
 * The findings active substance generic name field.
 *
 * German: Wirkstoff-Generic-Name
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_XDT_FIELD = NUMBER_8445_INTEGER_ARRAY;

/**
 * The findings mhk breakpoint value field.
 *
 * German: MHK-Breakpoint-Wert
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: 4.2
 */
static int* FINDINGS_MHK_BREAKPOINT_VALUE_XDT_FIELD = NUMBER_8446_INTEGER_ARRAY;

/**
 * The findings resistance interpretation field.
 *
 * German: Resistenz-Interpretation
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 4
 */
static int* FINDINGS_RESISTANCE_INTERPRETATION_XDT_FIELD = NUMBER_8447_INTEGER_ARRAY;

/**
 * The findings normal value text field.
 *
 * German: Normalwert-Text
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_NORMAL_VALUE_TEXT_XDT_FIELD = NUMBER_8460_INTEGER_ARRAY;

/**
 * The findings normal value lower limit field.
 *
 * German: Normalwert untere Grenze
 * Size: variable
 * Type: float
 * Rule: -
 * Example: -15
 */
static int* FINDINGS_NORMAL_VALUE_LOWER_LIMIT_XDT_FIELD = NUMBER_8461_INTEGER_ARRAY;

/**
 * The findings normal value upper limit field.
 *
 * German: Normalwert obere Grenze
 * Size: variable
 * Type: float
 * Rule: -
 * Example: 12
 */
static int* FINDINGS_NORMAL_VALUE_UPPER_LIMIT_XDT_FIELD = NUMBER_8462_INTEGER_ARRAY;

/**
 * The findings remark field.
 *
 * German: Testbezogene Hinweise (taken from new GDT version; was "Anmerkung" in old BDT)
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_REMARK_XDT_FIELD = NUMBER_8470_INTEGER_ARRAY;

/**
 * The findings result text field.
 *
 * German: Ergebnis-Text
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_RESULT_TEXT_XDT_FIELD = NUMBER_8480_INTEGER_ARRAY;

/**
 * The findings complimentary close field.
 *
 * German: Abschluß-Zeile
 * Size: <= 70
 * Type: character array
 * Rule: -
 * Example: -
 */
static int* FINDINGS_COMPLIMENTARY_CLOSE_XDT_FIELD = NUMBER_8490_INTEGER_ARRAY;

/**
 * The findings signature field.
 *
 * German: Signatur
 * Size: <= 60 (taken from new GDT version; was <= 70 in old BDT)
 * Type: character array
 * Rule: -
 * Example: Dr. Huber (taken from new GDT version; was empty in old BDT)
 */
static int* FINDINGS_SIGNATURE_XDT_FIELD = NUMBER_8990_INTEGER_ARRAY;

/**
 * The data medium sender physician number field.
 *
 * German: Arztnummer des Absenders
 * Size: 7-9
 * Type: integer
 * Rule: 329
 * Example: 8353839
 */
static int* DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_XDT_FIELD = NUMBER_9100_INTEGER_ARRAY;

/**
 * The data medium creation date field.
 *
 * German: Datum der Erstellung
 * Size: 8
 * Type: date
 * Rule: 008
 * Example: 31011994
 */
static int* DATA_MEDIUM_CREATION_DATE_XDT_FIELD = NUMBER_9103_INTEGER_ARRAY;

/**
 * The data medium running number field.
 *
 * German: Ordnungsnummer Datenträger (Header) des Datenpaketes
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 001
 */
static int* DATA_MEDIUM_RUNNING_NUMBER_XDT_FIELD = NUMBER_9105_INTEGER_ARRAY;

/**
 * The data medium character code field.
 *
 * German: Zeichencode
 * Size: 1
 * Type: integer
 * Rule: 112
 * Example: 2
 */
static int* DATA_MEDIUM_CHARACTER_CODE_XDT_FIELD = NUMBER_9106_INTEGER_ARRAY;

/**
 * The data package size field.
 *
 * German: Gesamtlänge des Datenpaketes in Byte
 * Size: 8
 * Type: integer
 * Rule: -
 * Example: 12334878
 */
static int* DATA_PACKAGE_SIZE_XDT_FIELD = NUMBER_9202_INTEGER_ARRAY;

/**
 * The data package mediums count field.
 *
 * German: Anzahl Datenträger des Datenpaketes
 * Size: 3
 * Type: integer
 * Rule: -
 * Example: 004
 */
static int* DATA_PACKAGE_MEDIUMS_COUNT_XDT_FIELD = NUMBER_9203_INTEGER_ARRAY;

/**
 * The data package character set field.
 *
 * German: verwendeter Zeichensatz
 * Size: 1
 * Type: integer
 * Rule: -
 * Example: 2
 */
static int* DATA_PACKAGE_CHARACTER_SET_XDT_FIELD = NUMBER_9206_INTEGER_ARRAY;

/**
 * The data package adt version field.
 *
 * German: Abrechnungs-Datentransfer (ADT) Satzbeschreibung Version
 * Size: 5
 * Type: character array
 * Rule: 118
 * Example: 10/93
 */
static int* DATA_PACKAGE_ADT_VERSION_XDT_FIELD = NUMBER_9210_INTEGER_ARRAY;

/**
 * The data package bdt version field.
 *
 * German: Behandlungs-Datentransfer (BDT) Version
 * Size: 5
 * Type: character array
 * Rule: 172
 * Example: 02/94
 */
static int* DATA_PACKAGE_BDT_VERSION_XDT_FIELD = NUMBER_9213_INTEGER_ARRAY;

/**
 * The data package gdt version field.
 *
 * German: Geräte-Datentransfer (GDT) Version
 * Size: 5
 * Type: character array
 * Rule: -
 * Example: 01.00, 02.00 or 02.10
 */
static int* DATA_PACKAGE_GDT_VERSION_XDT_FIELD = NUMBER_9218_INTEGER_ARRAY;

/**
 * The data package archiving type field.
 *
 * German: Archivierungsart
 * Size: 1
 * Type: integer
 * Rule: 106
 * Example: 1
 */
static int* DATA_PACKAGE_ARCHIVING_TYPE_XDT_FIELD = NUMBER_9600_INTEGER_ARRAY;

/**
 * The data package storage period field.
 *
 * German: Zeitraum der Speicherung
 * Size: 16
 * Type: integer
 * Rule: 019
 * Example: 0110199331121993
 */
static int* DATA_PACKAGE_STORAGE_PERIOD_XDT_FIELD = NUMBER_9601_INTEGER_ARRAY;

/**
 * The data package transfer begin field.
 *
 * German: Beginn der Übertragung
 * Size: 8
 * Type: integer
 * Rule: -
 * Example: 17084600
 */
static int* DATA_PACKAGE_TRANSFER_BEGIN_XDT_FIELD = NUMBER_9602_INTEGER_ARRAY;

/**
 * The system internal parameter field.
 *
 * German: Systeminterner Parameter
 * Size: <= 70
 * Type: character array
 * Rule: 999
 * Example: -
 */
static int* SYSTEM_INTERNAL_PARAMETER_XDT_FIELD = NUMBER_9901_INTEGER_ARRAY;

/* XDT_FIELD_CONSTANTS_SOURCE */
#endif
