/*
 * $RCSfile: cybol_abstraction_constants.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2008-05-06 22:36:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_ABSTRACTION_CONSTANTS_SOURCE
#define CYBOL_ABSTRACTION_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Knowledge abstraction.
//
// Parts in a compound knowledge tree are accessed at runtime.
//

/** The knowledge abstraction. */
static wchar_t KNOWLEDGE_ABSTRACTION_ARRAY[] = {L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e'};
static wchar_t* KNOWLEDGE_ABSTRACTION = KNOWLEDGE_ABSTRACTION_ARRAY;
static int* KNOWLEDGE_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The encapsulated knowledge abstraction. */
static wchar_t ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY[] = {L'e', L'n', L'c', L'a', L'p', L's', L'u', L'l', L'a', L't', L'e', L'd'};
static wchar_t* ENCAPSULATED_KNOWLEDGE_ABSTRACTION = ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY;
static int* ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT = NUMBER_12_INTEGER_ARRAY;

//
// Operation abstraction.
//

/** The operation abstraction. */
static wchar_t OPERATION_ABSTRACTION_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n'};
static wchar_t* OPERATION_ABSTRACTION = OPERATION_ABSTRACTION_ARRAY;
static int* OPERATION_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

//
// Primitive abstractions.
//

/** The boolean abstraction. */
static wchar_t BOOLEAN_ABSTRACTION_ARRAY[] = {L'b', L'o', L'o', L'l', L'e', L'a', L'n'};
static wchar_t* BOOLEAN_ABSTRACTION = BOOLEAN_ABSTRACTION_ARRAY;
static int* BOOLEAN_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The character vector abstraction. */
static wchar_t CHARACTER_VECTOR_ABSTRACTION_ARRAY[] = {L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r'};
static wchar_t* CHARACTER_VECTOR_ABSTRACTION = CHARACTER_VECTOR_ABSTRACTION_ARRAY;
static int* CHARACTER_VECTOR_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The complex abstraction. */
static wchar_t COMPLEX_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'l', L'e', L'x'};
static wchar_t* COMPLEX_ABSTRACTION = COMPLEX_ABSTRACTION_ARRAY;
static int* COMPLEX_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The double vector abstraction. */
static wchar_t DOUBLE_VECTOR_ABSTRACTION_ARRAY[] = {L'd', L'o', L'u', L'b', L'l', L'e'};
static wchar_t* DOUBLE_VECTOR_ABSTRACTION = DOUBLE_VECTOR_ABSTRACTION_ARRAY;
static int* DOUBLE_VECTOR_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The fraction abstraction. */
static wchar_t FRACTION_ABSTRACTION_ARRAY[] = {L'f', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* FRACTION_ABSTRACTION = FRACTION_ABSTRACTION_ARRAY;
static int* FRACTION_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The integer vector abstraction. */
static wchar_t INTEGER_VECTOR_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'g', L'e', L'r'};
static wchar_t* INTEGER_VECTOR_ABSTRACTION = INTEGER_VECTOR_ABSTRACTION_ARRAY;
static int* INTEGER_VECTOR_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The pointer vector abstraction. */
static wchar_t POINTER_VECTOR_ABSTRACTION_ARRAY[] = {L'p', L'o', L'i', L'n', L't', L'e', L'r', L'_', L'v', L'e', L'c', L't', L'o', L'r'};
static wchar_t* POINTER_VECTOR_ABSTRACTION = POINTER_VECTOR_ABSTRACTION_ARRAY;
static int* POINTER_VECTOR_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The terminal background colour abstraction. */
static wchar_t TERMINAL_BACKGROUND_ABSTRACTION_ARRAY[] = {L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l', L'_', L'b', L'a', L'c', L'k', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* TERMINAL_BACKGROUND_ABSTRACTION = TERMINAL_BACKGROUND_ABSTRACTION_ARRAY;
static int* TERMINAL_BACKGROUND_ABSTRACTION_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The terminal foreground colour abstraction. */
static wchar_t TERMINAL_FOREGROUND_ABSTRACTION_ARRAY[] = {L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l', L'_', L'f', L'o', L'r', L'e', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* TERMINAL_FOREGROUND_ABSTRACTION = TERMINAL_FOREGROUND_ABSTRACTION_ARRAY;
static int* TERMINAL_FOREGROUND_ABSTRACTION_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The iso 8601 date abstraction. */
static wchar_t ISO_8601_DATE_ABSTRACTION_ARRAY[] = {L'i', L's', L'o', L'_', L'8', L'6', L'0', L'1', L'_', L'd', L'a', L't', L'e'};
static wchar_t* ISO_8601_DATE_ABSTRACTION = ISO_8601_DATE_ABSTRACTION_ARRAY;
static int* ISO_8601_DATE_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The date time abstraction. */
static wchar_t DATE_TIME_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L'_', L't', L'i', L'm', L'e'};
static wchar_t* DATE_TIME_ABSTRACTION = DATE_TIME_ABSTRACTION_ARRAY;
static int* DATE_TIME_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The ddmmyyyy date time abstraction. */
static wchar_t DDMMYYYY_DATE_TIME_ABSTRACTION_ARRAY[] = {L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'_', L'd', L'a', L't', L'e', L'_', L't', L'i', L'm', L'e'};
static wchar_t* DDMMYYYY_DATE_TIME_ABSTRACTION = DDMMYYYY_DATE_TIME_ABSTRACTION_ARRAY;
static int* DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The xdt hhmm date abstraction. */
static wchar_t XDT_HHMM_DATE_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'h', L'h', L'm', L'm', L'_', L'd', L'a', L't', L'e'};
static wchar_t* XDT_HHMM_DATE_ABSTRACTION = XDT_HHMM_DATE_ABSTRACTION_ARRAY;
static int* XDT_HHMM_DATE_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The xdt hhmmhhmm date abstraction. */
static wchar_t XDT_HHMMHHMM_DATE_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'h', L'h', L'm', L'm', L'h', L'h', L'm', L'm', L'_', L'd', L'a', L't', L'e'};
static wchar_t* XDT_HHMMHHMM_DATE_ABSTRACTION = XDT_HHMMHHMM_DATE_ABSTRACTION_ARRAY;
static int* XDT_HHMMHHMM_DATE_ABSTRACTION_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The xdt yymmnnn date abstraction. */
static wchar_t XDT_YYMMNNN_DATE_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'y', L'y', L'm', L'm', L'n', L'n', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* XDT_YYMMNNN_DATE_ABSTRACTION = XDT_YYMMNNN_DATE_ABSTRACTION_ARRAY;
static int* XDT_YYMMNNN_DATE_ABSTRACTION_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The xdt ddmmyyyy date abstraction. */
static wchar_t XDT_DDMMYYYY_DATE_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'_', L'd', L'a', L't', L'e'};
static wchar_t* XDT_DDMMYYYY_DATE_ABSTRACTION = XDT_DDMMYYYY_DATE_ABSTRACTION_ARRAY;
static int* XDT_DDMMYYYY_DATE_ABSTRACTION_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The xdt mmyy date abstraction. */
static wchar_t XDT_MMYY_DATE_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'm', L'm', L'y', L'y', L'_', L'd', L'a', L't', L'e'};
static wchar_t* XDT_MMYY_DATE_ABSTRACTION = XDT_MMYY_DATE_ABSTRACTION_ARRAY;
static int* XDT_MMYY_DATE_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The xdt ddmmyyyyddmmyyyy date abstraction. */
static wchar_t XDT_DDMMYYYYDDMMYYYY_DATE_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'_', L'd', L'a', L't', L'e'};
static wchar_t* XDT_DDMMYYYYDDMMYYYY_DATE_ABSTRACTION = XDT_DDMMYYYYDDMMYYYY_DATE_ABSTRACTION_ARRAY;
static int* XDT_DDMMYYYYDDMMYYYY_DATE_ABSTRACTION_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The xdt hhmmss time abstraction. */
static wchar_t XDT_HHMMSS_TIME_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'h', L'h', L'm', L'm', L's', L's', L'_', L't', L'i', L'm', L'e'};
static wchar_t* XDT_HHMMSS_TIME_ABSTRACTION = XDT_HHMMSS_TIME_ABSTRACTION_ARRAY;
static int* XDT_HHMMSS_TIME_ABSTRACTION_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The xdt hhmm time abstraction. */
static wchar_t XDT_HHMM_TIME_ABSTRACTION_ARRAY[] = {L'x', L'd', L't', L'_', L'h', L'h', L'm', L'm', L'_', L't', L'i', L'm', L'e'};
static wchar_t* XDT_HHMM_TIME_ABSTRACTION = XDT_HHMM_TIME_ABSTRACTION_ARRAY;
static int* XDT_HHMM_TIME_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The unsigned long vector abstraction. */
static wchar_t UNSIGNED_LONG_VECTOR_ABSTRACTION_ARRAY[] = {L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L'_', L'l', L'o', L'n', L'g'};
static wchar_t* UNSIGNED_LONG_VECTOR_ABSTRACTION = UNSIGNED_LONG_VECTOR_ABSTRACTION_ARRAY;
static int* UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The wide character vector abstraction. */
static wchar_t WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY[] = {L'w', L'i', L'd', L'e', L'_', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r'};
static wchar_t* WIDE_CHARACTER_VECTOR_ABSTRACTION = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
static int* WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

//
// Unicode character encoding abstractions.
//

/** The utf-8 character encoding abstraction. */
static wchar_t UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION_ARRAY[] = {L'u', L't', L'f', L'-', L'8'};
static wchar_t* UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION = UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION_ARRAY;
static int* UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The utf-16 character encoding abstraction. */
static wchar_t UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION_ARRAY[] = {L'u', L't', L'f', L'-', L'1', L'6'};
static wchar_t* UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION = UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION_ARRAY;
static int* UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

//
// Audio abstractions.
//

/** The mp3 abstraction. */
static wchar_t MP3_MODEL_ARRAY[] = {L'm', L'p', L'3'};
static wchar_t* MP3_MODEL = MP3_MODEL_ARRAY;
static int* MP3_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Image abstractions.
//

/** The jpeg abstraction. */
static wchar_t JPEG_ABSTRACTION_ARRAY[] = {L'j', L'p', L'e', L'g'};
static wchar_t* JPEG_ABSTRACTION = JPEG_ABSTRACTION_ARRAY;
static int* JPEG_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The gif abstraction. */
static wchar_t GIF_ABSTRACTION_ARRAY[] = {L'g', L'i', L'f'};
static wchar_t* GIF_ABSTRACTION = GIF_ABSTRACTION_ARRAY;
static int* GIF_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The bmp abstraction. */
static wchar_t BMP_ABSTRACTION_ARRAY[] = {L'b', L'm', L'p'};
static wchar_t* BMP_ABSTRACTION = BMP_ABSTRACTION_ARRAY;
static int* BMP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Text abstractions.
//

/** The cybol abstraction. */
/*??
static wchar_t CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'y', L'b', L'o', L'l'};
static wchar_t* CYBOL_ABSTRACTION = CYBOL_ABSTRACTION_ARRAY;
static int* CYBOL_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;
*/

/** The model diagram abstraction. */
static wchar_t MODEL_DIAGRAM_ABSTRACTION_ARRAY[] = {L'm', L'o', L'd', L'e', L'l', L'_', L'd', L'i', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* MODEL_DIAGRAM_ABSTRACTION = MODEL_DIAGRAM_ABSTRACTION_ARRAY;
static int* MODEL_DIAGRAM_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The (german) behandlungsdaten-transfer abstraction. */
static wchar_t XDT_ABSTRACTION_ARRAY[] = {L'x', L'd', L't'};
static wchar_t* XDT_ABSTRACTION = XDT_ABSTRACTION_ARRAY;
static int* XDT_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The healthcare exchange protocol abstraction. */
static wchar_t HXP_ABSTRACTION_ARRAY[] = {L'h', L'x', L'p'};
static wchar_t* HXP_ABSTRACTION = HXP_ABSTRACTION_ARRAY;
static int* HXP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The latex abstraction. */
static wchar_t LATEX_ABSTRACTION_ARRAY[] = {L'l', L'a', L't', L'e', L'x'};
static wchar_t* LATEX_ABSTRACTION = LATEX_ABSTRACTION_ARRAY;
static int* LATEX_ABSTRACTION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The rtf abstraction. */
static wchar_t RTF_ABSTRACTION_ARRAY[] = {L'r', L't', L'f'};
static wchar_t* RTF_ABSTRACTION = RTF_ABSTRACTION_ARRAY;
static int* RTF_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The sgml abstraction. */
static wchar_t SGML_ABSTRACTION_ARRAY[] = {L's', L'g', L'm', L'l'};
static wchar_t* SGML_ABSTRACTION = SGML_ABSTRACTION_ARRAY;
static int* SGML_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The tex abstraction. */
static wchar_t TEX_ABSTRACTION_ARRAY[] = {L't', L'e', L'x'};
static wchar_t* TEX_ABSTRACTION = TEX_ABSTRACTION_ARRAY;
static int* TEX_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The xhtml abstraction. */
static wchar_t XHTML_ABSTRACTION_ARRAY[] = {L'x', L'h', L't', L'm', L'l'};
static wchar_t* XHTML_ABSTRACTION = XHTML_ABSTRACTION_ARRAY;
static int* XHTML_ABSTRACTION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The http request abstraction. */
static wchar_t HTTP_REQUEST_ABSTRACTION_ARRAY[] = {L'h', L't', L't', L'p', L'_', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* HTTP_REQUEST_ABSTRACTION = HTTP_REQUEST_ABSTRACTION_ARRAY;
static int* HTTP_REQUEST_ABSTRACTION_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The http response abstraction. */
static wchar_t HTTP_RESPONSE_ABSTRACTION_ARRAY[] = {L'h', L't', L't', L'p', L'_', L'r', L'e', L's', L'p', L'o', L'n', L's', L'e'};
static wchar_t* HTTP_RESPONSE_ABSTRACTION = HTTP_RESPONSE_ABSTRACTION_ARRAY;
static int* HTTP_RESPONSE_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The xml abstraction. */
static wchar_t XML_ABSTRACTION_ARRAY[] = {L'x', L'm', L'l'};
static wchar_t* XML_ABSTRACTION = XML_ABSTRACTION_ARRAY;
static int* XML_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Video abstractions.
//

/** The mpeg abstraction. */
static wchar_t MPEG_ABSTRACTION_ARRAY[] = {L'm', L'p', L'e', L'g'};
static wchar_t* MPEG_ABSTRACTION = MPEG_ABSTRACTION_ARRAY;
static int* MPEG_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The quicktime abstraction. */
static wchar_t QT_ABSTRACTION_ARRAY[] = {L'q', L't'};
static wchar_t* QT_ABSTRACTION = QT_ABSTRACTION_ARRAY;
static int* QT_ABSTRACTION_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Packed abstractions.
//

/** The tar abstraction. */
static wchar_t TAR_ABSTRACTION_ARRAY[] = {L't', L'a', L'r'};
static wchar_t* TAR_ABSTRACTION = TAR_ABSTRACTION_ARRAY;
static int* TAR_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The zip abstraction. */
static wchar_t ZIP_ABSTRACTION_ARRAY[] = {L'z', L'i', L'p'};
static wchar_t* ZIP_ABSTRACTION = ZIP_ABSTRACTION_ARRAY;
static int* ZIP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Application abstractions.
//

/** The koffice kword abstraction. */
static wchar_t KWD_ABSTRACTION_ARRAY[] = {L'k', L'w', L'd'};
static wchar_t* KWD_ABSTRACTION = KWD_ABSTRACTION_ARRAY;
static int* KWD_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The open office writer abstraction. */
static wchar_t SXW_ABSTRACTION_ARRAY[] = {L's', L'x', L'w'};
static wchar_t* SXW_ABSTRACTION = SXW_ABSTRACTION_ARRAY;
static int* SXW_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/* CYBOL_ABSTRACTION_CONSTANTS_SOURCE */
#endif
