/*
 * $RCSfile: abstraction_constants.c,v $
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
 * @version $Revision: 1.21 $ $Date: 2007-03-06 00:11:38 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_CONSTANTS_SOURCE
#define ABSTRACTION_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

//
// Array abstractions.
//

/** The character array constant. */
static int* CHARACTER_ARRAY = NUMBER_0_INTEGER_ARRAY;

/** The wide character array constant. */
static int* WIDE_CHARACTER_ARRAY = NUMBER_1_INTEGER_ARRAY;

/** The integer array constant. */
static int* INTEGER_ARRAY = NUMBER_2_INTEGER_ARRAY;

/** The pointer array constant. */
static int* POINTER_ARRAY = NUMBER_3_INTEGER_ARRAY;

/** The double array constant. */
static int* DOUBLE_ARRAY = NUMBER_4_INTEGER_ARRAY;

/** The unsigned long array constant. */
static int* UNSIGNED_LONG_ARRAY = NUMBER_5_INTEGER_ARRAY;

//
// Internal memory abstraction.
//

/** The internal memory abstraction. */
static char INTERNAL_MEMORY_ABSTRACTION_ARRAY[] = {'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', '_', 'm', 'e', 'm', 'o', 'r', 'y'};
static char* INTERNAL_MEMORY_ABSTRACTION = INTERNAL_MEMORY_ABSTRACTION_ARRAY;
static int* INTERNAL_MEMORY_ABSTRACTION_COUNT = NUMBER_16_INTEGER_ARRAY;

//
// Compound abstraction.
//
// Compound models consist of other compound or primitive models.
//
// CAUTION! This is also used as knowledge memory abstraction!
//

/** The compound abstraction. */
static char COMPOUND_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};
static char* COMPOUND_ABSTRACTION = COMPOUND_ABSTRACTION_ARRAY;
static int* COMPOUND_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Signal memory abstraction.
//

/** The signal memory abstraction. */
static char SIGNAL_MEMORY_ABSTRACTION_ARRAY[] = {'s', 'i', 'g', 'n', 'a', 'l', '_', 'm', 'e', 'm', 'o', 'r', 'y'};
static char* SIGNAL_MEMORY_ABSTRACTION = SIGNAL_MEMORY_ABSTRACTION_ARRAY;
static int* SIGNAL_MEMORY_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

//
// Knowledge abstraction.
//
// Parts in a compound knowledge tree are accessed at runtime.
//

/** The knowledge abstraction. */
static char KNOWLEDGE_ABSTRACTION_ARRAY[] = {'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e'};
static char* KNOWLEDGE_ABSTRACTION = KNOWLEDGE_ABSTRACTION_ARRAY;
static int* KNOWLEDGE_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The encapsulated knowledge abstraction. */
static char ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY[] = {'e', 'n', 'c', 'a', 'p', 's', 'u', 'l', 'a', 't', 'e', 'd'};
static char* ENCAPSULATED_KNOWLEDGE_ABSTRACTION = ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY;
static int* ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT = NUMBER_12_INTEGER_ARRAY;

//
// Operation abstraction.
//

/** The operation abstraction. */
static char OPERATION_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};
static char* OPERATION_ABSTRACTION = OPERATION_ABSTRACTION_ARRAY;
static int* OPERATION_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

//
// Primitive abstractions.
//

/** The boolean abstraction. */
static char BOOLEAN_ABSTRACTION_ARRAY[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};
static char* BOOLEAN_ABSTRACTION = BOOLEAN_ABSTRACTION_ARRAY;
static int* BOOLEAN_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The character vector abstraction. */
static char CHARACTER_VECTOR_ABSTRACTION_ARRAY[] = {'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r'};
static char* CHARACTER_VECTOR_ABSTRACTION = CHARACTER_VECTOR_ABSTRACTION_ARRAY;
static int* CHARACTER_VECTOR_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The complex abstraction. */
static char COMPLEX_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};
static char* COMPLEX_ABSTRACTION = COMPLEX_ABSTRACTION_ARRAY;
static int* COMPLEX_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The double vector abstraction. */
static char DOUBLE_VECTOR_ABSTRACTION_ARRAY[] = {'d', 'o', 'u', 'b', 'l', 'e'};
static char* DOUBLE_VECTOR_ABSTRACTION = DOUBLE_VECTOR_ABSTRACTION_ARRAY;
static int* DOUBLE_VECTOR_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The fraction abstraction. */
static char FRACTION_ABSTRACTION_ARRAY[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* FRACTION_ABSTRACTION = FRACTION_ABSTRACTION_ARRAY;
static int* FRACTION_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The integer vector abstraction. */
static char INTEGER_VECTOR_ABSTRACTION_ARRAY[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};
static char* INTEGER_VECTOR_ABSTRACTION = INTEGER_VECTOR_ABSTRACTION_ARRAY;
static int* INTEGER_VECTOR_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The pointer vector abstraction. */
static char POINTER_VECTOR_ABSTRACTION_ARRAY[] = {'p', 'o', 'i', 'n', 't', 'e', 'r', '_', 'v', 'e', 'c', 't', 'o', 'r'};
static char* POINTER_VECTOR_ABSTRACTION = POINTER_VECTOR_ABSTRACTION_ARRAY;
static int* POINTER_VECTOR_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The terminal background colour abstraction. */
static char TERMINAL_BACKGROUND_ABSTRACTION_ARRAY[] = {'t', 'e', 'r', 'm', 'i', 'n', 'a', 'l', '_', 'b', 'a', 'c', 'k', 'g', 'r', 'o', 'u', 'n', 'd'};
static char* TERMINAL_BACKGROUND_ABSTRACTION = TERMINAL_BACKGROUND_ABSTRACTION_ARRAY;
static int* TERMINAL_BACKGROUND_ABSTRACTION_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The terminal foreground colour abstraction. */
static char TERMINAL_FOREGROUND_ABSTRACTION_ARRAY[] = {'t', 'e', 'r', 'm', 'i', 'n', 'a', 'l', '_', 'f', 'o', 'r', 'e', 'g', 'r', 'o', 'u', 'n', 'd'};
static char* TERMINAL_FOREGROUND_ABSTRACTION = TERMINAL_FOREGROUND_ABSTRACTION_ARRAY;
static int* TERMINAL_FOREGROUND_ABSTRACTION_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The date time abstraction. */
static char DATE_TIME_ABSTRACTION_ARRAY[] = {'d', 'a', 't', 'e', '_', 't', 'i', 'm', 'e'};
static char* DATE_TIME_ABSTRACTION = DATE_TIME_ABSTRACTION_ARRAY;
static int* DATE_TIME_ABSTRACTION_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The ddmmyyyy date time abstraction. */
static char DDMMYYYY_DATE_TIME_ABSTRACTION_ARRAY[] = {'d', 'd', 'm', 'm', 'y', 'y', 'y', 'y', '_', 'd', 'a', 't', 'e', '_', 't', 'i', 'm', 'e'};
static char* DDMMYYYY_DATE_TIME_ABSTRACTION = DDMMYYYY_DATE_TIME_ABSTRACTION_ARRAY;
static int* DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The unsigned long vector abstraction. */
static char UNSIGNED_LONG_VECTOR_ABSTRACTION_ARRAY[] = {'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', '_', 'l', 'o', 'n', 'g'};
static char* UNSIGNED_LONG_VECTOR_ABSTRACTION = UNSIGNED_LONG_VECTOR_ABSTRACTION_ARRAY;
static int* UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The wide character vector abstraction. */
static char WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY[] = {'w', 'i', 'd', 'e', '_', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r'};
static char* WIDE_CHARACTER_VECTOR_ABSTRACTION = WIDE_CHARACTER_VECTOR_ABSTRACTION_ARRAY;
static int* WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT = NUMBER_14_INTEGER_ARRAY;

//
// Audio abstractions.
//

/** The mp3 abstraction. */
static char MP3_MODEL_ARRAY[] = {'m', 'p', '3'};
static char* MP3_MODEL = MP3_MODEL_ARRAY;
static int* MP3_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Image abstractions.
//

/** The jpeg abstraction. */
static char JPEG_ABSTRACTION_ARRAY[] = {'j', 'p', 'e', 'g'};
static char* JPEG_ABSTRACTION = JPEG_ABSTRACTION_ARRAY;
static int* JPEG_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The gif abstraction. */
static char GIF_ABSTRACTION_ARRAY[] = {'g', 'i', 'f'};
static char* GIF_ABSTRACTION = GIF_ABSTRACTION_ARRAY;
static int* GIF_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The bmp abstraction. */
static char BMP_ABSTRACTION_ARRAY[] = {'b', 'm', 'p'};
static char* BMP_ABSTRACTION = BMP_ABSTRACTION_ARRAY;
static int* BMP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Text abstractions.
//

/** The (german) behandlungsdaten-transfer abstraction. */
static char BDT_ABSTRACTION_ARRAY[] = {'b', 'd', 't'};
static char* BDT_ABSTRACTION = BDT_ABSTRACTION_ARRAY;
static int* BDT_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The healthcare exchange protocol abstraction. */
static char HXP_ABSTRACTION_ARRAY[] = {'h', 'x', 'p'};
static char* HXP_ABSTRACTION = HXP_ABSTRACTION_ARRAY;
static int* HXP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The latex abstraction. */
static char LATEX_ABSTRACTION_ARRAY[] = {'l', 'a', 't', 'e', 'x'};
static char* LATEX_ABSTRACTION = LATEX_ABSTRACTION_ARRAY;
static int* LATEX_ABSTRACTION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The rtf abstraction. */
static char RTF_ABSTRACTION_ARRAY[] = {'r', 't', 'f'};
static char* RTF_ABSTRACTION = RTF_ABSTRACTION_ARRAY;
static int* RTF_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The sgml abstraction. */
static char SGML_ABSTRACTION_ARRAY[] = {'s', 'g', 'm', 'l'};
static char* SGML_ABSTRACTION = SGML_ABSTRACTION_ARRAY;
static int* SGML_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The tex abstraction. */
static char TEX_ABSTRACTION_ARRAY[] = {'t', 'e', 'x'};
static char* TEX_ABSTRACTION = TEX_ABSTRACTION_ARRAY;
static int* TEX_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The xhtml abstraction. */
static char XHTML_ABSTRACTION_ARRAY[] = {'x', 'h', 't', 'm', 'l'};
static char* XHTML_ABSTRACTION = XHTML_ABSTRACTION_ARRAY;
static int* XHTML_ABSTRACTION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The xml abstraction. */
static char XML_ABSTRACTION_ARRAY[] = {'x', 'm', 'l'};
static char* XML_ABSTRACTION = XML_ABSTRACTION_ARRAY;
static int* XML_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Video abstractions.
//

/** The mpeg abstraction. */
static char MPEG_ABSTRACTION_ARRAY[] = {'m', 'p', 'e', 'g'};
static char* MPEG_ABSTRACTION = MPEG_ABSTRACTION_ARRAY;
static int* MPEG_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The quicktime abstraction. */
static char QT_ABSTRACTION_ARRAY[] = {'q', 't'};
static char* QT_ABSTRACTION = QT_ABSTRACTION_ARRAY;
static int* QT_ABSTRACTION_COUNT = NUMBER_2_INTEGER_ARRAY;

//
// Packed abstractions.
//

/** The tar abstraction. */
static char TAR_ABSTRACTION_ARRAY[] = {'t', 'a', 'r'};
static char* TAR_ABSTRACTION = TAR_ABSTRACTION_ARRAY;
static int* TAR_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The zip abstraction. */
static char ZIP_ABSTRACTION_ARRAY[] = {'z', 'i', 'p'};
static char* ZIP_ABSTRACTION = ZIP_ABSTRACTION_ARRAY;
static int* ZIP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

//
// Application abstractions.
//

/** The koffice kword abstraction. */
static char KWD_ABSTRACTION_ARRAY[] = {'k', 'w', 'd'};
static char* KWD_ABSTRACTION = KWD_ABSTRACTION_ARRAY;
static int* KWD_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The open office writer abstraction. */
static char SXW_ABSTRACTION_ARRAY[] = {'s', 'x', 'w'};
static char* SXW_ABSTRACTION = SXW_ABSTRACTION_ARRAY;
static int* SXW_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/* ABSTRACTION_CONSTANTS_SOURCE */
#endif
