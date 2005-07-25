/*
 * $RCSfile: abstraction_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.6 $ $Date: 2005-07-25 21:01:02 $ $Author: christian $
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

/** The integer array constant. */
static int* INTEGER_ARRAY = NUMBER_1_INTEGER_ARRAY;

/** The pointer array constant. */
static int* POINTER_ARRAY = NUMBER_2_INTEGER_ARRAY;

/** The double array constant. */
static int* DOUBLE_ARRAY = NUMBER_3_INTEGER_ARRAY;

/** The unsigned long array constant. */
static int* UNSIGNED_LONG_ARRAY = NUMBER_4_INTEGER_ARRAY;

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
static char ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY[] = {'e', 'n', 'c', 'a', 'p', 's', 'u', 'l', 'a', 't', 'e', 'd', '_', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e'};
static char* ENCAPSULATED_KNOWLEDGE_ABSTRACTION = ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY;
static int* ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT = NUMBER_22_INTEGER_ARRAY;

//
// Internal abstractions.
//

/** The textual user interface (tui) abstraction. */
static char TUI_ABSTRACTION_ARRAY[] = {'t', 'u', 'i'};
static char* TUI_ABSTRACTION = TUI_ABSTRACTION_ARRAY;
static int* TUI_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

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

/** The pointer abstraction. */
static char POINTER_ABSTRACTION_ARRAY[] = {'p', 'o', 'i', 'n', 't', 'e', 'r'};
static char* POINTER_ABSTRACTION = POINTER_ABSTRACTION_ARRAY;
static int* POINTER_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The boolean abstraction. */
static char BOOLEAN_ABSTRACTION_ARRAY[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};
static char* BOOLEAN_ABSTRACTION = BOOLEAN_ABSTRACTION_ARRAY;
static int* BOOLEAN_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The integer abstraction. */
static char INTEGER_ABSTRACTION_ARRAY[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};
static char* INTEGER_ABSTRACTION = INTEGER_ABSTRACTION_ARRAY;
static int* INTEGER_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The double abstraction. */
static char DOUBLE_ABSTRACTION_ARRAY[] = {'d', 'o', 'u', 'b', 'l', 'e'};
static char* DOUBLE_ABSTRACTION = DOUBLE_ABSTRACTION_ARRAY;
static int* DOUBLE_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The fraction abstraction. */
static char FRACTION_ABSTRACTION_ARRAY[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static char* FRACTION_ABSTRACTION = FRACTION_ABSTRACTION_ARRAY;
static int* FRACTION_ABSTRACTION_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The complex abstraction. */
static char COMPLEX_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};
static char* COMPLEX_ABSTRACTION = COMPLEX_ABSTRACTION_ARRAY;
static int* COMPLEX_ABSTRACTION_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The vector abstraction. */
static char VECTOR_ABSTRACTION_ARRAY[] = {'v', 'e', 'c', 't', 'o', 'r'};
static char* VECTOR_ABSTRACTION = VECTOR_ABSTRACTION_ARRAY;
static int* VECTOR_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The string abstraction. */
static char STRING_ABSTRACTION_ARRAY[] = {'s', 't', 'r', 'i', 'n', 'g'};
static char* STRING_ABSTRACTION = STRING_ABSTRACTION_ARRAY;
static int* STRING_ABSTRACTION_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The time abstraction. */
static char TIME_ABSTRACTION_ARRAY[] = {'t', 'i', 'm', 'e'};
static char* TIME_ABSTRACTION = TIME_ABSTRACTION_ARRAY;
static int* TIME_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

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

/** The cybol abstraction. */
static char CYBOL_ABSTRACTION_ARRAY[] = {'c', 'y', 'b', 'o', 'l'};
static char* CYBOL_ABSTRACTION = CYBOL_ABSTRACTION_ARRAY;
static int* CYBOL_ABSTRACTION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The sgml abstraction. */
static char SGML_ABSTRACTION_ARRAY[] = {'s', 'g', 'm', 'l'};
static char* SGML_ABSTRACTION = SGML_ABSTRACTION_ARRAY;
static int* SGML_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The xml abstraction. */
static char XML_ABSTRACTION_ARRAY[] = {'x', 'm', 'l'};
static char* XML_ABSTRACTION = XML_ABSTRACTION_ARRAY;
static int* XML_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The html abstraction. */
static char HTML_ABSTRACTION_ARRAY[] = {'h', 't', 'm', 'l'};
static char* HTML_ABSTRACTION = HTML_ABSTRACTION_ARRAY;
static int* HTML_ABSTRACTION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The rtf abstraction. */
static char RTF_ABSTRACTION_ARRAY[] = {'r', 't', 'f'};
static char* RTF_ABSTRACTION = RTF_ABSTRACTION_ARRAY;
static int* RTF_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The tex abstraction. */
static char TEX_ABSTRACTION_ARRAY[] = {'t', 'e', 'x'};
static char* TEX_ABSTRACTION = TEX_ABSTRACTION_ARRAY;
static int* TEX_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The healthcare exchange protocol abstraction. */
static char HXP_ABSTRACTION_ARRAY[] = {'h', 'x', 'p'};
static char* HXP_ABSTRACTION = HXP_ABSTRACTION_ARRAY;
static int* HXP_ABSTRACTION_COUNT = NUMBER_3_INTEGER_ARRAY;

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
