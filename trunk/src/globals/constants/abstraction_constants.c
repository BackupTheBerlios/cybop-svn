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
 * @version $Revision: 1.2 $ $Date: 2005-06-26 22:33:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_CONSTANTS_SOURCE
#define ABSTRACTION_CONSTANTS_SOURCE

//
// Internals memory abstraction.
//

/** The internals memory abstraction. */
static const char INTERNALS_MEMORY_ABSTRACTION_ARRAY[] = {'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', 's', '_', 'm', 'e', 'm', 'o', 'r', 'y'};
static const char* INTERNALS_MEMORY_ABSTRACTION = INTERNALS_MEMORY_ABSTRACTION_ARRAY;
static const int INTERNALS_MEMORY_ABSTRACTION_COUNT_ARRAY[] = {16};
static const int* INTERNALS_MEMORY_ABSTRACTION_COUNT = INTERNALS_MEMORY_ABSTRACTION_COUNT_ARRAY;

//
// Signal memory abstraction.
//

/** The signal memory abstraction. */
static const char SIGNAL_MEMORY_ABSTRACTION_ARRAY[] = {'s', 'i', 'g', 'n', 'a', 'l', '_', 'm', 'e', 'm', 'o', 'r', 'y'};
static const char* SIGNAL_MEMORY_ABSTRACTION = SIGNAL_MEMORY_ABSTRACTION_ARRAY;
static const int SIGNAL_MEMORY_ABSTRACTION_COUNT_ARRAY[] = {13};
static const int* SIGNAL_MEMORY_ABSTRACTION_COUNT = SIGNAL_MEMORY_ABSTRACTION_COUNT_ARRAY;

//
// Knowledge memory abstraction.
//

/** The knowledge memory abstraction. */
static const char KNOWLEDGE_MEMORY_ABSTRACTION_ARRAY[] = {'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', '_', 'm', 'e', 'm', 'o', 'r', 'y'};
static const char* KNOWLEDGE_MEMORY_ABSTRACTION = KNOWLEDGE_MEMORY_ABSTRACTION_ARRAY;
static const int KNOWLEDGE_MEMORY_ABSTRACTION_COUNT_ARRAY[] = {16};
static const int* KNOWLEDGE_MEMORY_ABSTRACTION_COUNT = KNOWLEDGE_MEMORY_ABSTRACTION_COUNT_ARRAY;

//
// Knowledge abstraction.
//
// Parts in a compound knowledge tree are accessed at runtime.
//

/** The knowledge abstraction. */
static const char KNOWLEDGE_ABSTRACTION_ARRAY[] = {'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e'};
static const char* KNOWLEDGE_ABSTRACTION = KNOWLEDGE_ABSTRACTION_ARRAY;
static const int KNOWLEDGE_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* KNOWLEDGE_ABSTRACTION_COUNT = KNOWLEDGE_ABSTRACTION_COUNT_ARRAY;

/** The encapsulated knowledge abstraction. */
static const char ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY[] = {'e', 'n', 'c', 'a', 'p', 's', 'u', 'l', 'a', 't', 'e', 'd', '_', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e'};
static const char* ENCAPSULATED_KNOWLEDGE_ABSTRACTION = ENCAPSULATED_KNOWLEDGE_ABSTRACTION_ARRAY;
static const int ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT_ARRAY[] = {22};
static const int* ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT = ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT_ARRAY;

//
// Compound abstraction.
//
// Compound models consist of other compound or primitive models.
//

/** The compound abstraction. */
static const char COMPOUND_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};
static const char* COMPOUND_ABSTRACTION = COMPOUND_ABSTRACTION_ARRAY;
static const int COMPOUND_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* COMPOUND_ABSTRACTION_COUNT = COMPOUND_ABSTRACTION_COUNT_ARRAY;

//
// Operation abstraction.
//

/** The operation abstraction. */
static const char OPERATION_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};
static const char* OPERATION_ABSTRACTION = OPERATION_ABSTRACTION_ARRAY;
static const int OPERATION_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* OPERATION_ABSTRACTION_COUNT = OPERATION_ABSTRACTION_COUNT_ARRAY;

//
// Primitive abstractions.
//

/** The pointer abstraction. */
static const char POINTER_ABSTRACTION_ARRAY[] = {'p', 'o', 'i', 'n', 't', 'e', 'r'};
static const char* POINTER_ABSTRACTION = POINTER_ABSTRACTION_ARRAY;
static const int POINTER_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* POINTER_ABSTRACTION_COUNT = POINTER_ABSTRACTION_COUNT_ARRAY;

/** The boolean abstraction. */
static const char BOOLEAN_ABSTRACTION_ARRAY[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};
static const char* BOOLEAN_ABSTRACTION = BOOLEAN_ABSTRACTION_ARRAY;
static const int BOOLEAN_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* BOOLEAN_ABSTRACTION_COUNT = BOOLEAN_ABSTRACTION_COUNT_ARRAY;

/** The integer abstraction. */
static const char INTEGER_ABSTRACTION_ARRAY[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};
static const char* INTEGER_ABSTRACTION = INTEGER_ABSTRACTION_ARRAY;
static const int INTEGER_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* INTEGER_ABSTRACTION_COUNT = INTEGER_ABSTRACTION_COUNT_ARRAY;

/** The double abstraction. */
static const char DOUBLE_ABSTRACTION_ARRAY[] = {'d', 'o', 'u', 'b', 'l', 'e'};
static const char* DOUBLE_ABSTRACTION = DOUBLE_ABSTRACTION_ARRAY;
static const int DOUBLE_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* DOUBLE_ABSTRACTION_COUNT = DOUBLE_ABSTRACTION_COUNT_ARRAY;

/** The fraction abstraction. */
static const char FRACTION_ABSTRACTION_ARRAY[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};
static const char* FRACTION_ABSTRACTION = FRACTION_ABSTRACTION_ARRAY;
static const int FRACTION_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* FRACTION_ABSTRACTION_COUNT = FRACTION_ABSTRACTION_COUNT_ARRAY;

/** The complex abstraction. */
static const char COMPLEX_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};
static const char* COMPLEX_ABSTRACTION = COMPLEX_ABSTRACTION_ARRAY;
static const int COMPLEX_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* COMPLEX_ABSTRACTION_COUNT = COMPLEX_ABSTRACTION_COUNT_ARRAY;

/** The vector abstraction. */
static const char VECTOR_ABSTRACTION_ARRAY[] = {'v', 'e', 'c', 't', 'o', 'r'};
static const char* VECTOR_ABSTRACTION = VECTOR_ABSTRACTION_ARRAY;
static const int VECTOR_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* VECTOR_ABSTRACTION_COUNT = VECTOR_ABSTRACTION_COUNT_ARRAY;

/** The string abstraction. */
static const char STRING_ABSTRACTION_ARRAY[] = {'s', 't', 'r', 'i', 'n', 'g'};
static const char* STRING_ABSTRACTION = STRING_ABSTRACTION_ARRAY;
static const int STRING_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* STRING_ABSTRACTION_COUNT = STRING_ABSTRACTION_COUNT_ARRAY;

/** The time abstraction. */
static const char TIME_ABSTRACTION_ARRAY[] = {'t', 'i', 'm', 'e'};
static const char* TIME_ABSTRACTION = TIME_ABSTRACTION_ARRAY;
static const int TIME_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* TIME_ABSTRACTION_COUNT = TIME_ABSTRACTION_COUNT_ARRAY;

//
// Audio abstractions.
//

/** The mp3 abstraction. */
static const char MP3_MODEL_ARRAY[] = {'m', 'p', '3'};
static const char* MP3_MODEL = MP3_MODEL_ARRAY;
static const int MP3_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* MP3_ABSTRACTION_COUNT = MP3_ABSTRACTION_COUNT_ARRAY;

//
// Image abstractions.
//

/** The jpeg abstraction. */
static const char JPEG_ABSTRACTION_ARRAY[] = {'j', 'p', 'e', 'g'};
static const char* JPEG_ABSTRACTION = JPEG_ABSTRACTION_ARRAY;
static const int JPEG_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* JPEG_ABSTRACTION_COUNT = JPEG_ABSTRACTION_COUNT_ARRAY;

/** The gif abstraction. */
static const char GIF_ABSTRACTION_ARRAY[] = {'g', 'i', 'f'};
static const char* GIF_ABSTRACTION = GIF_ABSTRACTION_ARRAY;
static const int GIF_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* GIF_ABSTRACTION_COUNT = GIF_ABSTRACTION_COUNT_ARRAY;

/** The bmp abstraction. */
static const char BMP_ABSTRACTION_ARRAY[] = {'b', 'm', 'p'};
static const char* BMP_ABSTRACTION = BMP_ABSTRACTION_ARRAY;
static const int BMP_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* BMP_ABSTRACTION_COUNT = BMP_ABSTRACTION_COUNT_ARRAY;

//
// Text abstractions.
//

/** The cybol abstraction. */
static const char CYBOL_ABSTRACTION_ARRAY[] = {'c', 'y', 'b', 'o', 'l'};
static const char* CYBOL_ABSTRACTION = CYBOL_ABSTRACTION_ARRAY;
static const int CYBOL_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* CYBOL_ABSTRACTION_COUNT = CYBOL_ABSTRACTION_COUNT_ARRAY;

/** The sgml abstraction. */
static const char SGML_ABSTRACTION_ARRAY[] = {'s', 'g', 'm', 'l'};
static const char* SGML_ABSTRACTION = SGML_ABSTRACTION_ARRAY;
static const int SGML_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* SGML_ABSTRACTION_COUNT = SGML_ABSTRACTION_COUNT_ARRAY;

/** The xml abstraction. */
static const char XML_ABSTRACTION_ARRAY[] = {'x', 'm', 'l'};
static const char* XML_ABSTRACTION = XML_ABSTRACTION_ARRAY;
static const int XML_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* XML_ABSTRACTION_COUNT = XML_ABSTRACTION_COUNT_ARRAY;

/** The html abstraction. */
static const char HTML_ABSTRACTION_ARRAY[] = {'h', 't', 'm', 'l'};
static const char* HTML_ABSTRACTION = HTML_ABSTRACTION_ARRAY;
static const int HTML_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* HTML_ABSTRACTION_COUNT = HTML_ABSTRACTION_COUNT_ARRAY;

/** The rtf abstraction. */
static const char RTF_ABSTRACTION_ARRAY[] = {'r', 't', 'f'};
static const char* RTF_ABSTRACTION = RTF_ABSTRACTION_ARRAY;
static const int RTF_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* RTF_ABSTRACTION_COUNT = RTF_ABSTRACTION_COUNT_ARRAY;

/** The tex abstraction. */
static const char TEX_ABSTRACTION_ARRAY[] = {'t', 'e', 'x'};
static const char* TEX_ABSTRACTION = TEX_ABSTRACTION_ARRAY;
static const int TEX_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* TEX_ABSTRACTION_COUNT = TEX_ABSTRACTION_COUNT_ARRAY;

/** The healthcare exchange protocol abstraction. */
static const char HXP_ABSTRACTION_ARRAY[] = {'h', 'x', 'p'};
static const char* HXP_ABSTRACTION = HXP_ABSTRACTION_ARRAY;
static const int HXP_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* HXP_ABSTRACTION_COUNT = HXP_ABSTRACTION_COUNT_ARRAY;

//
// Video abstractions.
//

/** The mpeg abstraction. */
static const char MPEG_ABSTRACTION_ARRAY[] = {'m', 'p', 'e', 'g'};
static const char* MPEG_ABSTRACTION = MPEG_ABSTRACTION_ARRAY;
static const int MPEG_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* MPEG_ABSTRACTION_COUNT = MPEG_ABSTRACTION_COUNT_ARRAY;

/** The quicktime abstraction. */
static const char QT_ABSTRACTION_ARRAY[] = {'q', 't'};
static const char* QT_ABSTRACTION = QT_ABSTRACTION_ARRAY;
static const int QT_ABSTRACTION_COUNT_ARRAY[] = {2};
static const int* QT_ABSTRACTION_COUNT = QT_ABSTRACTION_COUNT_ARRAY;

//
// Packed abstractions.
//

/** The tar abstraction. */
static const char TAR_ABSTRACTION_ARRAY[] = {'t', 'a', 'r'};
static const char* TAR_ABSTRACTION = TAR_ABSTRACTION_ARRAY;
static const int TAR_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* TAR_ABSTRACTION_COUNT = TAR_ABSTRACTION_COUNT_ARRAY;

/** The zip abstraction. */
static const char ZIP_ABSTRACTION_ARRAY[] = {'z', 'i', 'p'};
static const char* ZIP_ABSTRACTION = ZIP_ABSTRACTION_ARRAY;
static const int ZIP_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* ZIP_ABSTRACTION_COUNT = ZIP_ABSTRACTION_COUNT_ARRAY;

//
// Application abstractions.
//

/** The koffice kword abstraction. */
static const char KWD_ABSTRACTION_ARRAY[] = {'k', 'w', 'd'};
static const char* KWD_ABSTRACTION = KWD_ABSTRACTION_ARRAY;
static const int KWD_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* KWD_ABSTRACTION_COUNT = KWD_ABSTRACTION_COUNT_ARRAY;

/** The open office writer abstraction. */
static const char SXW_ABSTRACTION_ARRAY[] = {'s', 'x', 'w'};
static const char* SXW_ABSTRACTION = SXW_ABSTRACTION_ARRAY;
static const int SXW_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* SXW_ABSTRACTION_COUNT = SXW_ABSTRACTION_COUNT_ARRAY;

/* ABSTRACTION_CONSTANTS_SOURCE */
#endif
