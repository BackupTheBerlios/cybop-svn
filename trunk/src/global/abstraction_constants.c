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
 * @version $Revision: 1.23 $ $Date: 2005-04-13 11:26:43 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_CONSTANTS_SOURCE
#define ABSTRACTION_CONSTANTS_SOURCE

//
// Configuration abstraction.
//

/** The configuration abstraction. */
static const char CONFIGURATION_ABSTRACTION_ARRAY[] = {'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o', 'n'};
static const char* CONFIGURATION_ABSTRACTION = CONFIGURATION_ABSTRACTION_ARRAY;
static const int CONFIGURATION_ABSTRACTION_COUNT_ARRAY[] = {13};
static const int* CONFIGURATION_ABSTRACTION_COUNT = CONFIGURATION_ABSTRACTION_COUNT_ARRAY;

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
// State abstractions.
//
// There are compound and primitive state models.
// The compound abstraction constant is defined above.
// Primitive models as defined below are the final abstraction in software.
//

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

//
// User interface abstractions.
//

/** The character/ textual user interface (tui) abstraction. */
static const char TUI_ABSTRACTION_ARRAY[] = {'t', 'u', 'i'};
static const char* TUI_ABSTRACTION = TUI_ABSTRACTION_ARRAY;
static const int TUI_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* TUI_ABSTRACTION_COUNT = TUI_ABSTRACTION_COUNT_ARRAY;

/** The graphical user interface (gui) abstraction. */
static const char GUI_ABSTRACTION_ARRAY[] = {'g', 'u', 'i'};
static const char* GUI_ABSTRACTION = GUI_ABSTRACTION_ARRAY;
static const int GUI_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* GUI_ABSTRACTION_COUNT = GUI_ABSTRACTION_COUNT_ARRAY;

/** The x window system abstraction. */
static const char X_WINDOW_SYSTEM_ABSTRACTION_ARRAY[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', '_', 's', 'y', 's', 't', 'e', 'm'};
static const char* X_WINDOW_SYSTEM_ABSTRACTION = X_WINDOW_SYSTEM_ABSTRACTION_ARRAY;
static const int X_WINDOW_SYSTEM_ABSTRACTION_COUNT_ARRAY[] = {15};
static const int* X_WINDOW_SYSTEM_ABSTRACTION_COUNT = X_WINDOW_SYSTEM_ABSTRACTION_COUNT_ARRAY;

/** The tcp socket abstraction. */
static const char TCP_SOCKET_ABSTRACTION_ARRAY[] = {'t', 'c', 'p', '_', 's', 'o', 'c', 'k', 'e', 't'};
static const char* TCP_SOCKET_ABSTRACTION = TCP_SOCKET_ABSTRACTION_ARRAY;
static const int TCP_SOCKET_ABSTRACTION_COUNT_ARRAY[] = {10};
static const int* TCP_SOCKET_ABSTRACTION_COUNT = TCP_SOCKET_ABSTRACTION_COUNT_ARRAY;

/** The mouse abstraction. */
static const char MOUSE_ABSTRACTION_ARRAY[] = {'m', 'o', 'u', 's', 'e'};
static const char* MOUSE_ABSTRACTION = MOUSE_ABSTRACTION_ARRAY;
static const int MOUSE_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* MOUSE_ABSTRACTION_COUNT = MOUSE_ABSTRACTION_COUNT_ARRAY;

//??
//?? Special, additional abstractions (former signal languages).
//?? Sort them into better categories later! See above!
//??

/** The structured query language (sql). */
static const char SQL_LANGUAGE_ARRAY[] = {'s', 'q', 'l'};
static const char* SQL_LANGUAGE = SQL_LANGUAGE_ARRAY;
static const int SQL_LANGUAGE_COUNT_ARRAY[] = {3};
static const int* SQL_LANGUAGE_COUNT = SQL_LANGUAGE_COUNT_ARRAY;

/** The tar language. */
static const char TAR_LANGUAGE_ARRAY[] = {'t', 'a', 'r'};
static const char* TAR_LANGUAGE = TAR_LANGUAGE_ARRAY;
static const int TAR_LANGUAGE_COUNT_ARRAY[] = {3};
static const int* TAR_LANGUAGE_COUNT = TAR_LANGUAGE_COUNT_ARRAY;

/** The zip language. */
static const char ZIP_LANGUAGE_ARRAY[] = {'z', 'i', 'p'};
static const char* ZIP_LANGUAGE = ZIP_LANGUAGE_ARRAY;
static const int ZIP_LANGUAGE_COUNT_ARRAY[] = {3};
static const int* ZIP_LANGUAGE_COUNT = ZIP_LANGUAGE_COUNT_ARRAY;

//
// Logic abstractions.
//
// There are compound and primitive logic models.
// The compound abstraction constant is defined above.
// Primitive models as defined below are the final abstraction in software.
//

//
// Program flow abstractions.
//

/** The set/ assign/ copy abstraction. */
static const char SET_ABSTRACTION_ARRAY[] = {'s', 'e', 't'};
static const char* SET_ABSTRACTION = SET_ABSTRACTION_ARRAY;
static const int SET_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* SET_ABSTRACTION_COUNT = SET_ABSTRACTION_COUNT_ARRAY;

/** The set property/ assign/ copy abstraction. */
static const char SET_PROPERTY_ABSTRACTION_ARRAY[] = {'s', 'e', 't', '_', 'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
static const char* SET_PROPERTY_ABSTRACTION = SET_PROPERTY_ABSTRACTION_ARRAY;
static const int SET_PROPERTY_ABSTRACTION_COUNT_ARRAY[] = {12};
static const int* SET_PROPERTY_ABSTRACTION_COUNT = SET_PROPERTY_ABSTRACTION_COUNT_ARRAY;

/** The compare abstraction. */
static const char COMPARE_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'a', 'r', 'e'};
static const char* COMPARE_ABSTRACTION = COMPARE_ABSTRACTION_ARRAY;
static const int COMPARE_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* COMPARE_ABSTRACTION_COUNT = COMPARE_ABSTRACTION_COUNT_ARRAY;

/** The loop abstraction. */
static const char LOOP_ABSTRACTION_ARRAY[] = {'l', 'o', 'o', 'p'};
static const char* LOOP_ABSTRACTION = LOOP_ABSTRACTION_ARRAY;
static const int LOOP_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* LOOP_ABSTRACTION_COUNT = LOOP_ABSTRACTION_COUNT_ARRAY;

/** The count part abstraction. */
static const char COUNT_PART_ABSTRACTION_ARRAY[] = {'c', 'o', 'u', 'n', 't', '_', 'p', 'a', 'r', 't' };
static const char* COUNT_PART_ABSTRACTION = COUNT_PART_ABSTRACTION_ARRAY;
static const int COUNT_PART_ABSTRACTION_COUNT_ARRAY[] = {10};
static const int* COUNT_PART_ABSTRACTION_COUNT = COUNT_PART_ABSTRACTION_COUNT_ARRAY;

/** The build listname abstraction. */
static const char BUILD_LISTNAME_ABSTRACTION_ARRAY[] = {'b', 'u', 'i', 'l', 'd', '_', 'l', 'i', 's', 't', 'n', 'a', 'm', 'e' };
static const char* BUILD_LISTNAME_ABSTRACTION = BUILD_LISTNAME_ABSTRACTION_ARRAY;
static const int BUILD_LISTNAME_ABSTRACTION_COUNT_ARRAY[] = {14};
static const int* BUILD_LISTNAME_ABSTRACTION_COUNT = BUILD_LISTNAME_ABSTRACTION_COUNT_ARRAY;

/** The selection abstraction. */
static const char SELECTION_ABSTRACTION_ARRAY[] = {'s', 'e', 'l', 'e', 'c', 't', 'i', 'o', 'n' };
static const char* SELECTION_ABSTRACTION = SELECTION_ABSTRACTION_ARRAY;
static const int SELECTION_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* SELECTION_ABSTRACTION_COUNT = SELECTION_ABSTRACTION_COUNT_ARRAY;

//
// Boolean logic abstractions.
//

/** The and abstraction. */
static const char AND_ABSTRACTION_ARRAY[] = {'a', 'n', 'd'};
static const char* AND_ABSTRACTION = AND_ABSTRACTION_ARRAY;
static const int AND_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* AND_ABSTRACTION_COUNT = AND_ABSTRACTION_COUNT_ARRAY;

/** The or abstraction. */
static const char OR_ABSTRACTION_ARRAY[] = {'o', 'r'};
static const char* OR_ABSTRACTION = OR_ABSTRACTION_ARRAY;
static const int OR_ABSTRACTION_COUNT_ARRAY[] = {2};
static const int* OR_ABSTRACTION_COUNT = OR_ABSTRACTION_COUNT_ARRAY;

//
// Comparison abstractions.
//

/** The equal abstraction. */
static const char EQUAL_ABSTRACTION_ARRAY[] = {'e', 'q', 'u', 'a', 'l'};
static const char* EQUAL_ABSTRACTION = EQUAL_ABSTRACTION_ARRAY;
static const int EQUAL_ABSTRACTION_COUNT_ARRAY[] = {5};
static const int* EQUAL_ABSTRACTION_COUNT = EQUAL_ABSTRACTION_COUNT_ARRAY;

/** The smaller abstraction. */
static const char SMALLER_ABSTRACTION_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r'};
static const char* SMALLER_ABSTRACTION = SMALLER_ABSTRACTION_ARRAY;
static const int SMALLER_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* SMALLER_ABSTRACTION_COUNT = SMALLER_ABSTRACTION_COUNT_ARRAY;

/** The greater abstraction. */
static const char GREATER_ABSTRACTION_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r'};
static const char* GREATER_ABSTRACTION = GREATER_ABSTRACTION_ARRAY;
static const int GREATER_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* GREATER_ABSTRACTION_COUNT = GREATER_ABSTRACTION_COUNT_ARRAY;

/** The smaller or equal abstraction. */
static const char SMALLER_OR_EQUAL_ABSTRACTION_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static const char* SMALLER_OR_EQUAL_ABSTRACTION = SMALLER_OR_EQUAL_ABSTRACTION_ARRAY;
static const int SMALLER_OR_EQUAL_ABSTRACTION_COUNT_ARRAY[] = {16};
static const int* SMALLER_OR_EQUAL_ABSTRACTION_COUNT = SMALLER_OR_EQUAL_ABSTRACTION_COUNT_ARRAY;

/** The greater or equal abstraction. */
static const char GREATER_OR_EQUAL_ABSTRACTION_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};
static const char* GREATER_OR_EQUAL_ABSTRACTION = GREATER_OR_EQUAL_ABSTRACTION_ARRAY;
static const int GREATER_OR_EQUAL_ABSTRACTION_COUNT_ARRAY[] = {16};
static const int* GREATER_OR_EQUAL_ABSTRACTION_COUNT = GREATER_OR_EQUAL_ABSTRACTION_COUNT_ARRAY;

//
// Arithmetic abstractions.
//

/** The add abstraction. */
static const char ADD_ABSTRACTION_ARRAY[] = {'a', 'd', 'd'};
static const char* ADD_ABSTRACTION = ADD_ABSTRACTION_ARRAY;
static const int ADD_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* ADD_ABSTRACTION_COUNT = ADD_ABSTRACTION_COUNT_ARRAY;

/** The add summand 1 abstraction. */
static const char ADD_SUMMAND_1_ABSTRACTION_ARRAY[] = {'s', 'u', 'm', 'm', 'a', 'n', 'd', '_', '1'};
static const char* ADD_SUMMAND_1_ABSTRACTION = ADD_SUMMAND_1_ABSTRACTION_ARRAY;
static const int ADD_SUMMAND_1_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* ADD_SUMMAND_1_ABSTRACTION_COUNT = ADD_SUMMAND_1_ABSTRACTION_COUNT_ARRAY;

/** The add summand 2 abstraction. */
static const char ADD_SUMMAND_2_ABSTRACTION_ARRAY[] = {'s', 'u', 'm', 'm', 'a', 'n', 'd', '_', '2'};
static const char* ADD_SUMMAND_2_ABSTRACTION = ADD_SUMMAND_2_ABSTRACTION_ARRAY;
static const int ADD_SUMMAND_2_ABSTRACTION_COUNT_ARRAY[] = {9};
static const int* ADD_SUMMAND_2_ABSTRACTION_COUNT = ADD_SUMMAND_2_ABSTRACTION_COUNT_ARRAY;

/** The add sum abstraction. */
static const char ADD_SUM_ABSTRACTION_ARRAY[] = {'s', 'u', 'm'};
static const char* ADD_SUM_ABSTRACTION = ADD_SUM_ABSTRACTION_ARRAY;
static const int ADD_SUM_ABSTRACTION_COUNT_ARRAY[] = {3};
static const int* ADD_SUM_ABSTRACTION_COUNT = ADD_SUM_ABSTRACTION_COUNT_ARRAY;

/** The subtract abstraction. */
static const char SUBTRACT_ABSTRACTION_ARRAY[] = {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'};
static const char* SUBTRACT_ABSTRACTION = SUBTRACT_ABSTRACTION_ARRAY;
static const int SUBTRACT_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* SUBTRACT_ABSTRACTION_COUNT = SUBTRACT_ABSTRACTION_COUNT_ARRAY;

/** The multiply abstraction. */
static const char MULTIPLY_ABSTRACTION_ARRAY[] = {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'};
static const char* MULTIPLY_ABSTRACTION = MULTIPLY_ABSTRACTION_ARRAY;
static const int MULTIPLY_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* MULTIPLY_ABSTRACTION_COUNT = MULTIPLY_ABSTRACTION_COUNT_ARRAY;

/** The divide abstraction. */
static const char DIVIDE_ABSTRACTION_ARRAY[] = {'d', 'i', 'v', 'i', 'd', 'e'};
static const char* DIVIDE_ABSTRACTION = DIVIDE_ABSTRACTION_ARRAY;
static const int DIVIDE_ABSTRACTION_COUNT_ARRAY[] = {6};
static const int* DIVIDE_ABSTRACTION_COUNT = DIVIDE_ABSTRACTION_COUNT_ARRAY;

//
// Memory management abstractions.
//

/** The create part abstraction. */
static const char CREATE_PART_ABSTRACTION_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 'p', 'a', 'r', 't'};
static const char* CREATE_PART_ABSTRACTION = CREATE_PART_ABSTRACTION_ARRAY;
static const int CREATE_PART_ABSTRACTION_COUNT_ARRAY[] = {11};
static const int* CREATE_PART_ABSTRACTION_COUNT = CREATE_PART_ABSTRACTION_COUNT_ARRAY;

/** The destroy part abstraction. */
static const char DESTROY_PART_ABSTRACTION_ARRAY[] = {'d', 'e', 's', 't', 'r', 'o', 'y', '_', 'p', 'a', 'r', 't'};
static const char* DESTROY_PART_ABSTRACTION = DESTROY_PART_ABSTRACTION_ARRAY;
static const int DESTROY_PART_ABSTRACTION_COUNT_ARRAY[] = {12};
static const int* DESTROY_PART_ABSTRACTION_COUNT = DESTROY_PART_ABSTRACTION_COUNT_ARRAY;

/** The create signal abstraction. */
static const char CREATE_SIGNAL_ABSTRACTION_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 's', 'i', 'g', 'n', 'a', 'l' };
static const char* CREATE_SIGNAL_ABSTRACTION = CREATE_SIGNAL_ABSTRACTION_ARRAY;
static const int CREATE_SIGNAL_ABSTRACTION_COUNT_ARRAY[] = {13};
static const int* CREATE_SIGNAL_ABSTRACTION_COUNT = CREATE_SIGNAL_ABSTRACTION_COUNT_ARRAY;


//
// Communication abstractions.
//

/** The send abstraction. */
static const char SEND_ABSTRACTION_ARRAY[] = {'s', 'e', 'n', 'd'};
static const char* SEND_ABSTRACTION = SEND_ABSTRACTION_ARRAY;
static const int SEND_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* SEND_ABSTRACTION_COUNT = SEND_ABSTRACTION_COUNT_ARRAY;

/** The receive abstraction. */
static const char RECEIVE_ABSTRACTION_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e'};
static const char* RECEIVE_ABSTRACTION = RECEIVE_ABSTRACTION_ARRAY;
static const int RECEIVE_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* RECEIVE_ABSTRACTION_COUNT = RECEIVE_ABSTRACTION_COUNT_ARRAY;

/** The url refresh abstraction. */
static const char URL_REFRESH_ABSTRACTION_ARRAY[] = {'u', 'r', 'l', '_', 'r', 'e', 'f', 'r', 'e', 's', 'h' };
static const char* URL_REFRESH_ABSTRACTION = URL_REFRESH_ABSTRACTION_ARRAY;
static const int URL_REFRESH_ABSTRACTION_COUNT_ARRAY[] = {11};
static const int* URL_REFRESH_ABSTRACTION_COUNT = URL_REFRESH_ABSTRACTION_COUNT_ARRAY;

//
// Lifecycle abstractions.
//

/** The startup abstraction. */
static const char STARTUP_ABSTRACTION_ARRAY[] = {'s', 't', 'a', 'r', 't', 'u', 'p'};
static const char* STARTUP_ABSTRACTION = STARTUP_ABSTRACTION_ARRAY;
static const int STARTUP_ABSTRACTION_COUNT_ARRAY[] = {7};
static const int* STARTUP_ABSTRACTION_COUNT = STARTUP_ABSTRACTION_COUNT_ARRAY;

/** The shutdown abstraction. */
static const char SHUTDOWN_ABSTRACTION_ARRAY[] = {'s', 'h', 'u', 't', 'd', 'o', 'w', 'n'};
static const char* SHUTDOWN_ABSTRACTION = SHUTDOWN_ABSTRACTION_ARRAY;
static const int SHUTDOWN_ABSTRACTION_COUNT_ARRAY[] = {8};
static const int* SHUTDOWN_ABSTRACTION_COUNT = SHUTDOWN_ABSTRACTION_COUNT_ARRAY;

/** The exit abstraction. */
static const char EXIT_ABSTRACTION_ARRAY[] = {'e', 'x', 'i', 't'};
static const char* EXIT_ABSTRACTION = EXIT_ABSTRACTION_ARRAY;
static const int EXIT_ABSTRACTION_COUNT_ARRAY[] = {4};
static const int* EXIT_ABSTRACTION_COUNT = EXIT_ABSTRACTION_COUNT_ARRAY;



//
//
// Opcodes.
//

/** The nop abstraction array. */
//??static const char NOP_ABSTRACTION_ARRAY[] = {'n', 'o', 'p'};

/** The nop abstraction. */
//??static const char* NOP_ABSTRACTION = NOP_ABSTRACTION_ARRAY;

/** The nop abstraction count. */
//??static const int NOP_ABSTRACTION_COUNT = 3;

/*??
//
// Pushing constants.
//

static const char _ABSTRACTION[] = {'aconst_null'};
static const char _ABSTRACTION[] = {'iconst_m1'};
static const char _ABSTRACTION[] = {'iconst_0'};
static const char _ABSTRACTION[] = {'iconst_1'};
static const char _ABSTRACTION[] = {'iconst_2'};
static const char _ABSTRACTION[] = {'iconst_3'};
static const char _ABSTRACTION[] = {'iconst_4'};
static const char _ABSTRACTION[] = {'iconst_5'};
static const char _ABSTRACTION[] = {'lconst_0'};
static const char _ABSTRACTION[] = {'lconst_1'}; // 10
static const char _ABSTRACTION[] = {'fconst_0'};
static const char _ABSTRACTION[] = {'fconst_1'};
static const char _ABSTRACTION[] = {'fconst_2'};
static const char _ABSTRACTION[] = {'dconst_0'};
static const char _ABSTRACTION[] = {'dconst_1'};
static const char _ABSTRACTION[] = {'bipush'};
static const char _ABSTRACTION[] = {'sipush'};
static const char _ABSTRACTION[] = {'ldc'}; //or ldc
static const char _ABSTRACTION[] = {'ldc_w'}; //or ldc_w was ldc2
static const char _ABSTRACTION[] = {'ldc2_w'};//or ldc2_w was ldc2w // 20

//
// Loading local variables.
//

static const char _ABSTRACTION[] = {'iload'};
static const char _ABSTRACTION[] = {'lload'};
static const char _ABSTRACTION[] = {'fload'};
static const char _ABSTRACTION[] = {'dload'};
static const char _ABSTRACTION[] = {'aload'};
static const char _ABSTRACTION[] = {'iload_0'};
static const char _ABSTRACTION[] = {'iload_1'};
static const char _ABSTRACTION[] = {'iload_2'};
static const char _ABSTRACTION[] = {'iload_3'};
static const char _ABSTRACTION[] = {'lload_0'}; // 30
static const char _ABSTRACTION[] = {'lload_1'};
static const char _ABSTRACTION[] = {'lload_2'};
static const char _ABSTRACTION[] = {'lload_3'};
static const char _ABSTRACTION[] = {'fload_0'};
static const char _ABSTRACTION[] = {'fload_1'};
static const char _ABSTRACTION[] = {'fload_2'};
static const char _ABSTRACTION[] = {'fload_3'};
static const char _ABSTRACTION[] = {'dload_0'};
static const char _ABSTRACTION[] = {'dload_1'};
static const char _ABSTRACTION[] = {'dload_2'}; // 40
static const char _ABSTRACTION[] = {'dload_3'};
static const char _ABSTRACTION[] = {'aload_0'};
static const char _ABSTRACTION[] = {'aload_1'};
static const char _ABSTRACTION[] = {'aload_2'};
static const char _ABSTRACTION[] = {'aload_3'};

//
// Loading array elements.
//

static const char _ABSTRACTION[] = {'iaload'};
static const char _ABSTRACTION[] = {'laload'};
static const char _ABSTRACTION[] = {'faload'};
static const char _ABSTRACTION[] = {'daload'};
static const char _ABSTRACTION[] = {'aaload'}; // 50
static const char _ABSTRACTION[] = {'baload'};
static const char _ABSTRACTION[] = {'caload'};
static const char _ABSTRACTION[] = {'saload'};

//
// Storing to local variables.
//

static const char _ABSTRACTION[] = {'istore'};
static const char _ABSTRACTION[] = {'lstore'};
static const char _ABSTRACTION[] = {'fstore'};
static const char _ABSTRACTION[] = {'dstore'};
static const char _ABSTRACTION[] = {'astore'};
static const char _ABSTRACTION[] = {'istore_0'};
static const char _ABSTRACTION[] = {'istore_1'}; // 60
static const char _ABSTRACTION[] = {'istore_2'};
static const char _ABSTRACTION[] = {'istore_3'};
static const char _ABSTRACTION[] = {'lstore_0'};
static const char _ABSTRACTION[] = {'lstore_1'};
static const char _ABSTRACTION[] = {'lstore_2'};
static const char _ABSTRACTION[] = {'lstore_3'};
static const char _ABSTRACTION[] = {'fstore_0'};
static const char _ABSTRACTION[] = {'fstore_1'};
static const char _ABSTRACTION[] = {'fstore_2'};
static const char _ABSTRACTION[] = {'fstore_3'}; // 70
static const char _ABSTRACTION[] = {'dstore_0'};
static const char _ABSTRACTION[] = {'dstore_1'};
static const char _ABSTRACTION[] = {'dstore_2'};
static const char _ABSTRACTION[] = {'dstore_3'};
static const char _ABSTRACTION[] = {'astore_0'};
static const char _ABSTRACTION[] = {'astore_1'};
static const char _ABSTRACTION[] = {'astore_2'};
static const char _ABSTRACTION[] = {'astore_3'};

//
// Storing to array elements.
//

static const char _ABSTRACTION[] = {'iastore'};
static const char _ABSTRACTION[] = {'lastore'}; // 80
static const char _ABSTRACTION[] = {'fastore'};
static const char _ABSTRACTION[] = {'dastore'};
static const char _ABSTRACTION[] = {'aastore'};
static const char _ABSTRACTION[] = {'bastore'};
static const char _ABSTRACTION[] = {'castore'};
static const char _ABSTRACTION[] = {'sastore'};

//
// Stack instructions.
//

static const char _ABSTRACTION[] = {'pop'};
static const char _ABSTRACTION[] = {'pop2'};
static const char _ABSTRACTION[] = {'dup_'};
static const char _ABSTRACTION[] = {'dup_x1'}; // 90
static const char _ABSTRACTION[] = {'dup_x2'};
static const char _ABSTRACTION[] = {'dup2_'};
static const char _ABSTRACTION[] = {'dup2_x1'};
static const char _ABSTRACTION[] = {'dup2_x2'};
static const char _ABSTRACTION[] = {'swap'};

//
// Arithmetic instructions.
//

static const char _ABSTRACTION[] = {'iadd'};
static const char _ABSTRACTION[] = {'ladd'};
static const char _ABSTRACTION[] = {'fadd'};
static const char _ABSTRACTION[] = {'dadd'};
static const char _ABSTRACTION[] = {'isub'}; // 100
static const char _ABSTRACTION[] = {'lsub'};
static const char _ABSTRACTION[] = {'fsub'};
static const char _ABSTRACTION[] = {'dsub'};
static const char _ABSTRACTION[] = {'imul'};
static const char _ABSTRACTION[] = {'lmul'};
static const char _ABSTRACTION[] = {'fmul'};
static const char _ABSTRACTION[] = {'dmul'};
static const char _ABSTRACTION[] = {'idiv'};
static const char _ABSTRACTION[] = {'ldiv_'};
static const char _ABSTRACTION[] = {'fdiv'}; // 110
static const char _ABSTRACTION[] = {'ddiv'};
static const char _ABSTRACTION[] = {'imod'};
static const char _ABSTRACTION[] = {'lmod'};
static const char _ABSTRACTION[] = {'fmod_'};
static const char _ABSTRACTION[] = {'dmod'};
static const char _ABSTRACTION[] = {'ineg'};
static const char _ABSTRACTION[] = {'lneg'};
static const char _ABSTRACTION[] = {'fneg'};
static const char _ABSTRACTION[] = {'dneg'};

//
// Logical instructions.
//

static const char _ABSTRACTION[] = {'ishl'}; // 120
static const char _ABSTRACTION[] = {'lshl'};
static const char _ABSTRACTION[] = {'ishr'};
static const char _ABSTRACTION[] = {'lshr'};
static const char _ABSTRACTION[] = {'iushr'};
static const char _ABSTRACTION[] = {'lushr'};
static const char _ABSTRACTION[] = {'iand'};
static const char _ABSTRACTION[] = {'land'};
static const char _ABSTRACTION[] = {'ior'};
static const char _ABSTRACTION[] = {'lor'};
static const char _ABSTRACTION[] = {'ixor'}; // 130
static const char _ABSTRACTION[] = {'lxor'};

//
// Increment.
//

static const char _ABSTRACTION[] = {'iinc'};

//
// Conversion operations.
//

static const char _ABSTRACTION[] = {'i2l'}; // 133 here ... was 132 in spec
static const char _ABSTRACTION[] = {'i2f'}; // 134 here... was 133 in spec
static const char _ABSTRACTION[] = {'i2d'}; // 135 here... was 134 in spec
static const char _ABSTRACTION[] = {'l2i'};
static const char _ABSTRACTION[] = {'l2f'};
static const char _ABSTRACTION[] = {'l2d'};
static const char _ABSTRACTION[] = {'f2i'};
static const char _ABSTRACTION[] = {'f2l'}; // 140
static const char _ABSTRACTION[] = {'f2d'};
static const char _ABSTRACTION[] = {'d2i'};
static const char _ABSTRACTION[] = {'d2l'};
static const char _ABSTRACTION[] = {'d2f'};
static const char _ABSTRACTION[] = {'int2byte'};
static const char _ABSTRACTION[] = {'int2char'};
static const char _ABSTRACTION[] = {'int2short'};

//
// Comparison instructions.
//

static const char _ABSTRACTION[] = {'lcmp'};
static const char _ABSTRACTION[] = {'fcmpl'};
static const char _ABSTRACTION[] = {'fcmpg'}; // 150
static const char _ABSTRACTION[] = {'dcmpl'};
static const char _ABSTRACTION[] = {'dcmpg'};

//
// Branch instructions.
//

static const char _ABSTRACTION[] = {'ifeq'};
static const char _ABSTRACTION[] = {'ifne'};
static const char _ABSTRACTION[] = {'iflt'};
static const char _ABSTRACTION[] = {'ifge'};
static const char _ABSTRACTION[] = {'ifgt'};
static const char _ABSTRACTION[] = {'ifle'};
static const char _ABSTRACTION[] = {'if_icmpeq'};
static const char _ABSTRACTION[] = {'if_icmpne'}; // 160
static const char _ABSTRACTION[] = {'if_icmplt'};
static const char _ABSTRACTION[] = {'if_icmpge'};
static const char _ABSTRACTION[] = {'if_icmpgt'};
static const char _ABSTRACTION[] = {'if_icmple'};
static const char _ABSTRACTION[] = {'if_acmpeq'};
static const char _ABSTRACTION[] = {'if_acmpne'};
static const char _ABSTRACTION[] = {'goto_'};
static const char _ABSTRACTION[] = {'jsr'};
static const char _ABSTRACTION[] = {'ret'};

//
// Table jumping.
//

static const char _ABSTRACTION[] = {'tableswitch'}; // 170
static const char _ABSTRACTION[] = {'lookupswitch'};

//
// Function return.
//

static const char _ABSTRACTION[] = {'ireturn'};
static const char _ABSTRACTION[] = {'lreturn'};
static const char _ABSTRACTION[] = {'freturn'};
static const char _ABSTRACTION[] = {'dreturn'};
static const char _ABSTRACTION[] = {'areturn'};
static const char _ABSTRACTION[] = {'return_'};

//
// Manipulating object fields.
//

static const char _ABSTRACTION[] = {'getstatic'};
static const char _ABSTRACTION[] = {'putstatic'};
static const char _ABSTRACTION[] = {'getfield'}; // 180
static const char _ABSTRACTION[] = {'putfield'};

//
// Method invocation.
//

static const char _ABSTRACTION[] = {'invokevirtual'};
static const char _ABSTRACTION[] = {'invokespecial'}; // was nonvirtual
static const char _ABSTRACTION[] = {'invokestatic'};
static const char _ABSTRACTION[] = {'invokeinterface'};

//
// Miscellaneous object operations.
//

static const char _ABSTRACTION[] = {'newfromname'};
static const char _ABSTRACTION[] = {'new_'};
static const char _ABSTRACTION[] = {'newarray'};
static const char _ABSTRACTION[] = {'anewarray'};
static const char _ABSTRACTION[] = {'arraylength'}; // 190
static const char _ABSTRACTION[] = {'athrow'};
static const char _ABSTRACTION[] = {'checkcast'};
static const char _ABSTRACTION[] = {'instanceof'};

//
// Monitors.
//

static const char _ABSTRACTION[] = {'monitorenter'};
static const char _ABSTRACTION[] = {'monitorexit'};

//
// Debugging.
//

static const char _ABSTRACTION[] = {'verifystack'};
// breakpoint;
// breakpoint is in the documentation; but the compiler does not use it
// ... multianewarray moves up one place to take breakpoint's place

//
// More arrays.
//

static const char _ABSTRACTION[] = {'multianewarray'};

//
// Undocumented java class stuff.
//

static const char _ABSTRACTION[] = {'ifnull'};
static const char _ABSTRACTION[] = {'ifnonnull'};

//
// Optimisations.
//

static const char _ABSTRACTION[] = {'ldc1_quick'}; // 200
static const char _ABSTRACTION[] = {'ldc2_quick'};
static const char _ABSTRACTION[] = {'ldc2w_quick'};

static const char _ABSTRACTION[] = {'getfield_quick'};
static const char _ABSTRACTION[] = {'putfield_quick'};
static const char _ABSTRACTION[] = {'getfield2_quick'};
static const char _ABSTRACTION[] = {'putfield2_quick'};

//
// Short-cuts for when the current class is not the same as the static field's class.
//

static const char _ABSTRACTION[] = {'getstatic_quick'};
static const char _ABSTRACTION[] = {'putstatic_quick'};
static const char _ABSTRACTION[] = {'getstatic2_quick'};
static const char _ABSTRACTION[] = {'putstatic2_quick'}; // 210

static const char _ABSTRACTION[] = {'invokevirtual_quick'};
static const char _ABSTRACTION[] = {'invokespecial_quick'}; // was nonvirtual
static const char _ABSTRACTION[] = {'invokestatic_quick'};
static const char _ABSTRACTION[] = {'invokeinterface_quick'};
static const char _ABSTRACTION[] = {'invokevirtualobject_quick'}; //?? I can't understand this!

static const char _ABSTRACTION[] = {'new_quick'};
static const char _ABSTRACTION[] = {'anewarray_quick'};
static const char _ABSTRACTION[] = {'checkcast_quick'};
static const char _ABSTRACTION[] = {'instanceof_quick'};

//
// Shortcuts for when the current class is the same as the static field's class.
//

static const char _ABSTRACTION[] = {'putstaticcurrclass_quick'}; // 220
static const char _ABSTRACTION[] = {'putstatic2currclass_quick'};
static const char _ABSTRACTION[] = {'getstaticcurrclass_quick'};
static const char _ABSTRACTION[] = {'getstatic2currclass_quick'};

static const char _ABSTRACTION[] = {'invokenonvirtualcurrclass_quick'};
static const char _ABSTRACTION[] = {'invokestaticcurrclass_quick'};

//
// Used for preloaded classes in ROM because we can't overwrite the operand with a guess.
//

static const char _ABSTRACTION[] = {'invokeinterface_noguess'}; // +- 226

//
// Special instructions to invoke optimised methods.
//

static const char _ABSTRACTION[] = {'invokevirtual_quick_optimised'};
*/

/* ABSTRACTION_CONSTANTS_SOURCE */
#endif
