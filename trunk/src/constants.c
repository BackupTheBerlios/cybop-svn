/*
 * $RCSfile: constants.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This file defines global constants.
 *
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip for better performance. Systems would then be written solely
 * in cybol. Dreaming ...
 *
 * @version $Revision: 1.8 $ $Date: 2004-04-22 08:54:55 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANTS_SOURCE
#define CONSTANTS_SOURCE

//
// Constants.
//

/** The null pointer. */
static void* NULL_POINTER = (void*) 0;

/** The null pointer pointer. */
static void* NULL_POINTER_POINTER = (void**) 0;

/** The null integer pointer. */
static int* NULL_INTEGER_POINTER = (int*) 0;

/** The null character pointer. */
static char* NULL_CHARACTER_POINTER = (char*) 0;

/** The null double pointer. */
static double* NULL_DOUBLE_POINTER = (double*) 0;

//
// Message constants.
//

// The usage message array.
static const char USAGE_MESSAGE_ARRAY[] = {'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 's', 'i', 'g', 'n', 'a', 'l'};

// The usage message.
static const char* USAGE_MESSAGE = USAGE_MESSAGE_ARRAY;

// The usage message size.
static const int USAGE_MESSAGE_SIZE = 19;

// The example message array.
static const char EXAMPLE_MESSAGE_ARRAY[] = {'E', 'x', 'a', 'm', 'p', 'l', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'c', 'y', 'b', 'o', 'p', '.', 's', 'a', 'm', 'p', 'l', 'e', '.', 'h', 'e', 'l', 'l', 'o', '_', 'w', 'o', 'r', 'l', 'd', '.', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's', '.', 's', 't', 'a', 'r', 't', 'u', 'p'};

// The example message.
static const char* EXAMPLE_MESSAGE = EXAMPLE_MESSAGE_ARRAY;

// The example message size.
static const int EXAMPLE_MESSAGE_SIZE = 56;

/*??
log_message((void*) &INFO_LOG_LEVEL, (void*) &"Wait for signals.");
log_message((void*) &WARNING_LOG_LEVEL, (void*) &"Could not handle signal. The signal abstraction is unknown.");
log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not wait for signals. The internals is null.");
log_message((void*) &INFO_LOG_LEVEL, (void*) &"Exit CYBOI normally.");
log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not execute CYBOI. The command line argument number is incorrect.");
log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not execute CYBOI. The command line argument vector is null.");
*/

//
// Cybol.
//

/** The cybol path. */
//?? static const char CYBOL_PATH[] = {'/home/cybop/lib/cybop/'};

/** The open office writer model size. */
//?? static const int SXW_MODEL_SIZE = 3;

/** The cybol file suffix. */
//?? static const char FILE_SUFFIX[] = {'.cybol'};

/** The open office writer model size. */
//?? static const int SXW_MODEL_SIZE = 3;

/** The null model. */
//?? static const char NULL_MODEL[] = {'null'};

/** The open office writer model size. */
//?? static const int SXW_MODEL_SIZE = 3;

/** The model tag array. */
static const char MODEL_TAG_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};

/** The model tag. */
static const char* MODEL_TAG = MODEL_TAG_ARRAY;

/** The model tag size. */
static const int MODEL_TAG_SIZE = 5;

/** The part tag array. */
static const char PART_TAG_ARRAY[] = {'p', 'a', 'r', 't'};

/** The part tag. */
static const char* PART_TAG = PART_TAG_ARRAY;

/** The part tag size. */
static const int PART_TAG_SIZE = 4;

/** The super tag array. */
static const char SUPER_TAG_ARRAY[] = {'s', 'u', 'p', 'e', 'r'};

/** The super tag. */
static const char* SUPER_TAG = SUPER_TAG_ARRAY;

/** The super tag size. */
static const int SUPER_TAG_SIZE = 5;

/** The name attribute array. */
static const char NAME_ATTRIBUTE_ARRAY[] = {'n', 'a', 'm', 'e'};

/** The name attribute. */
static const char NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;

/** The name attribute size. */
static const int NAME_ATTRIBUTE_SIZE = 4;

/** The part abstraction attribute array. */
static const char PART_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'p', 'a', 'r', 't', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The part abstraction attribute. */
static const char PART_ABSTRACTION_ATTRIBUTE = PART_ABSTRACTION_ATTRIBUTE_ARRAY;

/** The part abstraction attribute size. */
static const int PART_ABSTRACTION_ATTRIBUTE_SIZE = 16;

/** The part location attribute array. */
static const char PART_LOCATION_ATTRIBUTE_ARRAY[] = {'p', 'a', 'r', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The part location attribute. */
static const char PART_LOCATION_ATTRIBUTE = PART_LOCATION_ATTRIBUTE_ARRAY;

/** The part location attribute size. */
static const int PART_LOCATION_ATTRIBUTE_SIZE = 13;

/** The part model attribute array. */
static const char PART_MODEL_ATTRIBUTE_ARRAY[] = {'p', 'a', 'r', 't', '_', 'm', 'o', 'd', 'e', 'l'};

/** The part model attribute. */
static const char PART_MODEL_ATTRIBUTE = PART_MODEL_ATTRIBUTE_ARRAY;

/** The part model attribute size. */
static const int PART_MODEL_ATTRIBUTE_SIZE = 10;

/** The position abstraction attribute array. */
static const char POSITION_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The position abstraction attribute. */
static const char POSITION_ABSTRACTION_ATTRIBUTE = POSITION_ABSTRACTION_ATTRIBUTE_ARRAY;

/** The position abstraction attribute size. */
static const int POSITION_ABSTRACTION_ATTRIBUTE_SIZE = 20;

/** The position location attribute array. */
static const char POSITION_LOCATION_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The position location attribute. */
static const char POSITION_LOCATION_ATTRIBUTE = POSITION_LOCATION_ATTRIBUTE_ARRAY;

/** The position location attribute size. */
static const int POSITION_LOCATION_ATTRIBUTE_SIZE = 17;

/** The position model attribute array. */
static const char POSITION_MODEL_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'm', 'o', 'd', 'e', 'l'};

/** The position model attribute. */
static const char POSITION_MODEL_ATTRIBUTE = POSITION_MODEL_ATTRIBUTE_ARRAY;

/** The position model attribute size. */
static const int POSITION_MODEL_ATTRIBUTE_SIZE = 14;

/** The constraint abstraction attribute array. */
static const char CONSTRAINT_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The constraint abstraction attribute. */
static const char CONSTRAINT_ABSTRACTION_ATTRIBUTE = CONSTRAINT_ABSTRACTION_ATTRIBUTE_ARRAY;

/** The constraint abstraction attribute size. */
static const int CONSTRAINT_ABSTRACTION_ATTRIBUTE_SIZE = 22;

/** The constraint location attribute array. */
static const char CONSTRAINT_LOCATION_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The constraint location attribute. */
static const char CONSTRAINT_LOCATION_ATTRIBUTE = CONSTRAINT_LOCATION_ATTRIBUTE_ARRAY;

/** The constraint location attribute size. */
static const int CONSTRAINT_LOCATION_ATTRIBUTE_SIZE = 19;

/** The constraint model attribute array. */
static const char CONSTRAINT_MODEL_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'm', 'o', 'd', 'e', 'l'};

/** The constraint model attribute. */
static const char CONSTRAINT_MODEL_ATTRIBUTE = CONSTRAINT_MODEL_ATTRIBUTE_ARRAY;

/** The constraint model attribute size. */
static const int CONSTRAINT_MODEL_ATTRIBUTE_SIZE = 16;

//
// Log level constants.
//

/** The off log level. */
static const int OFF_LOG_LEVEL = 0;

/** The error log level. */
static const int ERROR_LOG_LEVEL = 1;

/** The warning log level. */
static const int WARNING_LOG_LEVEL = 2;

/** The info log level. */
static const int INFO_LOG_LEVEL = 3;

//
// Log level name constants.
//

/** The error log level name array. */
static const char ERROR_LOG_LEVEL_NAME_ARRAY[] = {'E', 'r', 'r', 'o', 'r'};

/** The error log level name. */
static const char* ERROR_LOG_LEVEL_NAME = ERROR_LOG_LEVEL_NAME_ARRAY;

/** The warning log level name array. */
static const char WARNING_LOG_LEVEL_NAME_ARRAY[] = {'W', 'a', 'r', 'n', 'i', 'n', 'g'};

/** The warning log level name. */
static const char* WARNING_LOG_LEVEL_NAME = WARNING_LOG_LEVEL_NAME_ARRAY;

/** The info log level name array. */
static const char INFO_LOG_LEVEL_NAME_ARRAY[] = {'I', 'n', 'f', 'o'};

/** The info log level name. */
static const char* INFO_LOG_LEVEL_NAME = INFO_LOG_LEVEL_NAME_ARRAY;

//
// Vector constants.
//

/** The vector size. */
static const int VECTOR_SIZE = 3;

/** The x index. */
static const int X_INDEX = 0;

/** The y index. */
static const int Y_INDEX = 1;

/** The z index. */
static const int Z_INDEX = 2;

//
// Time constants.
//

/** The time size. */
static const int TIME_SIZE = 6;

/** The year index. */
static const int YEAR_INDEX = 0;

/** The month index. */
static const int MONTH_INDEX = 1;

/** The day index. */
static const int DAY_INDEX = 2;

/** The hour index. */
static const int HOUR_INDEX = 3;

/** The minute index. */
static const int MINUTE_INDEX = 4;

/** The second index. */
static const int SECOND_INDEX = 5;

//
// Operation constants.
//

/** The operation size. */
static const int OPERATION_SIZE = 3;

/** The parameters size index. */
static const int PARAMETERS_SIZE_INDEX = 0;

/** The parameters index. */
static const int PARAMETERS_INDEX = 1;

/** The parameters sizes index. */
static const int PARAMETERS_SIZES_INDEX = 2;

/** The operation parameter separator. */
static const char OPERATION_PARAMETER_SEPARATOR = ',';

//
// Fraction constants.
//

/** The fraction size. */
static const int FRACTION_SIZE = 2;

/** The numerator index. */
static const int NUMERATOR_INDEX = 0;

/** The denominator index. */
static const int DENOMINATOR_INDEX = 1;

//
// Complex constants.
//

/** The complex size. */
static const int COMPLEX_SIZE = 2;

/** The real index. */
static const int REAL_INDEX = 0;

/** The imaginary index. */
static const int IMAGINARY_INDEX = 1;

//
// Boolean constants.
//

/** The true boolean. */
static const char TRUE_BOOLEAN[] = {'t', 'r', 'u', 'e'};

/** The true boolean size. */
static const int TRUE_BOOLEAN_SIZE = 4;

/** The false boolean. */
static const char FALSE_BOOLEAN[] = {'f', 'a', 'l', 's', 'e'};

/** The false boolean size. */
static const int FALSE_BOOLEAN_SIZE = 5;

//
// Signal memory constants.
//

/** The signal memory size. */
static const int SIGNAL_MEMORY_SIZE = 6;

/** The signals size index. */
static const int SIGNALS_SIZE_INDEX = 0;

/** The signals count index. */
static const int SIGNALS_COUNT_INDEX = 1;

/** The signals index. */
static const int SIGNALS_INDEX = 2;

/** The priorities index. */
static const int PRIORITIES_INDEX = 3;

/** The abstractions index. */
static const int ABSTRACTIONS_INDEX = 4;

/** The abstractions sizes index. */
static const int ABSTRACTIONS_SIZES_INDEX = 5;

//
// Signal priorities.
//

/** The normal priority. */
static const int NORMAL_PRIORITY = 0;

//
// Signal languages.
//

/** The cybol language. */
static const char CYBOL_LANGUAGE[] = {'c', 'y', 'b', 'o', 'l'};

/** The cybol language size. */
static const int CYBOL_LANGUAGE_SIZE = 5;

/** The inline (serialized) language. */
static const char INLINE_LANGUAGE[] = {'i', 'n', 'l', 'i', 'n', 'e'};

/** The inline (serialized) language size. */
static const int INLINE_LANGUAGE_SIZE = 6;

//?? ---------- The following languages are not used yet. ----------

/** The textual user interface (tui) language. */
static const char TUI_LANGUAGE[] = {'t', 'u', 'i'};

/** The mouse language. */
static const char MOUSE_LANGUAGE[] = {'m', 'o', 'u', 's', 'e'};

/** The x windows language. */
static const char X_WINDOWS_LANGUAGE[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', 's'};

/** The socket language. */
static const char SOCKET_LANGUAGE[] = {'s', 'o', 'c', 'k', 'e', 't'};

/** The structured query language (sql). */
static const char SQ_LANGUAGE[] = {'s', 'q'};

/** The java messaging service (jms) language. */
static const char JMS_LANGUAGE[] = {'j', 'm', 's'};

/** The remote method invocation (rmi) language. */
static const char RMI_LANGUAGE[] = {'r', 'm', 'i'};

/** The common object request broker architecture (corba) language. */
static const char CORBA_LANGUAGE[] = {'c', 'o', 'r', 'b', 'a'};

/** The extensible markup language (xml). */
static const char XML_LANGUAGE[] = {'x', 'm', 'l'};

/** The simple object access protocol (soap) language. */
static const char SOAP_LANGUAGE[] = {'s', 'o', 'a', 'p'};

/** The file language. */
static const char FILE_LANGUAGE[] = {'f', 'i', 'l', 'e'};

/** The floppy language. */
static const char FLOPPY_LANGUAGE[] = {'f', 'l', 'o', 'p', 'p', 'y'};

/** The ftp language. */
static const char FTP_LANGUAGE[] = {'f', 't', 'p'};

/** The sftp language. */
static const char SFTP_LANGUAGE[] = {'s', 'f', 't', 'p'};

/** The imap language. */
static const char IMAP_LANGUAGE[] = {'i', 'm', 'a', 'p'};

/** The imaps language. */
static const char IMAPS_LANGUAGE[] = {'i', 'm', 'a', 'p', 's'};

/** The ldap language. */
static const char LDAP_LANGUAGE[] = {'l', 'd', 'a', 'p'};

/** The nfs language. */
static const char NFS_LANGUAGE[] = {'n', 'f', 's'};

/** The nntp language. */
static const char NNTP_LANGUAGE[] = {'n', 'n', 't', 'p'};

/** The smb language. */
static const char SMB_LANGUAGE[] = {'s', 'm', 'b'};

/** The smtp language. */
static const char SMTP_LANGUAGE[] = {'s', 'm', 't', 'p'};

/** The smtps language. */
static const char SMTPS_LANGUAGE[] = {'s', 'm', 't', 'p', 's'};

/** The tar language. */
static const char TAR_LANGUAGE[] = {'t', 'a', 'r'};

/** The zip language. */
static const char ZIP_LANGUAGE[] = {'z', 'i', 'p'};

//
// Compound models.
//

/** The compound abstraction array. */
static const char COMPOUND_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};

/** The compound abstraction. */
static const char* COMPOUND_ABSTRACTION = COMPOUND_ABSTRACTION_ARRAY;

/** The compound abstraction size. */
static const int COMPOUND_ABSTRACTION_SIZE = 8;

 * This file defines constants for static models.
 *
 * There are complex and primitive static models.
 * Complex models consist of other complex models and primitive models.
 * Primitive models are the final abstraction in software.
 *

//
// Operation models.
//

/** The operation abstraction array. */
static const char OPERATION_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

/** The operation abstraction. */
static const char* OPERATION_ABSTRACTION = OPERATION_ABSTRACTION_ARRAY;

/** The operation abstraction size. */
static const int OPERATION_ABSTRACTION_SIZE = 9;

//
// Primitive models.
//

/** The boolean abstraction. */
static const char BOOLEAN_ABSTRACTION[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};

/** The boolean abstraction size. */
static const int BOOLEAN_ABSTRACTION_SIZE = 7;

/** The integer abstraction. */
static const char INTEGER_ABSTRACTION[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};

/** The integer abstraction size. */
static const int INTEGER_ABSTRACTION_SIZE = 7;

/** The double abstraction. */
static const char DOUBLE_ABSTRACTION[] = {'d', 'o', 'u', 'b', 'l', 'e'};

/** The double abstraction size. */
static const int DOUBLE_ABSTRACTION_SIZE = 6;

/** The fraction abstraction. */
static const char FRACTION_ABSTRACTION[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The fraction abstraction size. */
static const int FRACTION_ABSTRACTION_SIZE = 8;

/** The complex abstraction. */
static const char COMPLEX_ABSTRACTION[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};

/** The complex abstraction size. */
static const int COMPLEX_ABSTRACTION_SIZE = 7;

/** The vector abstraction. */
static const char VECTOR_ABSTRACTION[] = {'v', 'e', 'c', 't', 'o', 'r'};

/** The vector abstraction size. */
static const int VECTOR_ABSTRACTION_SIZE = 6;

/** The string abstraction. */
static const char STRING_ABSTRACTION[] = {'s', 't', 'r', 'i', 'n', 'g'};

/** The string abstraction size. */
static const int STRING_ABSTRACTION_SIZE = 6;

/** The time abstraction. */
static const char TIME_ABSTRACTION[] = {'t', 'i', 'm', 'e'};

/** The time abstraction size. */
static const int TIME_ABSTRACTION_SIZE = 4;

//
// Audio models.
//

/** The mp3 model. */
static const char MP3_MODEL[] = {'m', 'p', '3'};

/** The mp3 model size. */
static const int MP3_MODEL_SIZE = 3;

//
// Image models.
//

/** The jpeg model. */
static const char JPEG_MODEL[] = {'j', 'p', 'e', 'g'};

/** The jpeg model size. */
static const int JPEG_MODEL_SIZE = 4;

/** The gif model. */
static const char GIF_MODEL[] = {'g', 'i', 'f'};

/** The gif model size. */
static const int GIF_MODEL_SIZE = 3;

/** The bmp model. */
static const char BMP_MODEL[] = {'b', 'm', 'p'};

/** The bmp model size. */
static const int BMP_MODEL_SIZE = 3;

//
// Text models.
//

/** The sgml model. */
static const char SGML_MODEL[] = {'s', 'g', 'm', 'l'};

/** The sgml model size. */
static const int SGML_MODEL_SIZE = 4;

/** The xml model. */
static const char XML_MODEL[] = {'x', 'm', 'l'};

/** The xml model size. */
static const int XML_MODEL_SIZE = 3;

/** The html model. */
static const char HTML_MODEL[] = {'h', 't', 'm', 'l'};

/** The html model size. */
static const int HTML_MODEL_SIZE = 4;

/** The rtf model. */
static const char RTF_MODEL[] = {'r', 't', 'f'};

/** The rtf model size. */
static const int RTF_MODEL_SIZE = 3;

/** The tex model. */
static const char TEX_MODEL[] = {'t', 'e', 'x'};

/** The tex model size. */
static const int TEX_MODEL_SIZE = 3;

//
// Video models.
//

/** The mpeg model. */
static const char MPEG_MODEL[] = {'m', 'p', 'e', 'g'};

/** The mpeg model size. */
static const int MPEG_MODEL_SIZE = 4;

/** The quicktime model. */
static const char QT_MODEL[] = {'q', 't'};

/** The quicktime model size. */
static const int QT_MODEL_SIZE = 2;

//
// Application models.
//

/** The koffice kword model. */
static const char KWD_MODEL[] = {'k', 'w', 'd'};

/** The koffice kword model size. */
static const int KWORD_MODEL_SIZE = 5;

/** The open office writer model. */
static const char SXW_MODEL[] = {'s', 'x', 'w'};

/** The open office writer model size. */
static const int SXW_MODEL_SIZE = 3;

 * This file defines constants for dynamic models.
 *
 * Some knowledge about function pointers in the C programming language
 * is needed. See for instance the (German) tutorials:
 * http://www.fh-wedel.de/~si/vorlesungen/c/funktionen/
 * http://home.arcor.de/cpp_kurs/cpp/le07/le07_01_d1.htm
 * http://home.arcor.de/cpp_kurs/cpp/le07/k2_09_d1.htm
 * ... or try a Google search.
 *
//
// Logics models.
//

/** The and model. */
static const char AND_MODEL[] = {'a', 'n', 'd'};

/** The and model size. */
static const int AND_MODEL_SIZE = 3;

/** The or model. */
static const char OR_MODEL[] = {'o', 'r'};

/** The or model size. */
static const int OR_MODEL_SIZE = 2;

//
// Comparison models.
//

/** The equal model. */
static const char EQUAL_MODEL[] = {'e', 'q', 'u', 'a', 'l'};

/** The equal model size. */
static const int EQUAL_MODEL_SIZE = 5;

/** The smaller model. */
static const char SMALLER_MODEL[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r'};

/** The smaller model size. */
static const int SMALLER_MODEL_SIZE = 7;

/** The greater model. */
static const char GREATER_MODEL[] = {'g', 'r', 'e', 'a', 't', 'e', 'r'};

/** The greater model size. */
static const int GREATER_MODEL_SIZE = 7;

/** The smaller or equal model. */
static const char SMALLER_OR_EQUAL_MODEL[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};

/** The smaller or equal model size. */
static const int SMALLER_OR_EQUAL_MODEL_SIZE = 16;

/** The greater or equal model. */
static const char GREATER_OR_EQUAL_MODEL[] = {'g', 'r', 'e', 'a', 't', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};

/** The greater or equal model size. */
static const int GREATER_OR_EQUAL_MODEL_SIZE = 16;

//
// Arithmetic models.
//

/** The add model. */
static const char ADD_MODEL[] = {'a', 'd', 'd'};

/** The add model size. */
static const int ADD_MODEL_SIZE = 3;

/** The subtract model. */
static const char SUBTRACT_MODEL[] = {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'};

/** The subtract model size. */
static const int SUBTRACT_MODEL_SIZE = 8;

/** The multiply model. */
static const char MULTIPLY_MODEL[] = {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'};

/** The multiply model size. */
static const int MULTIPLY_MODEL_SIZE = 8;

/** The divide model. */
static const char DIVIDE_MODEL[] = {'d', 'i', 'v', 'i', 'd', 'e'};

/** The divide model size. */
static const int DIVIDE_MODEL_SIZE = 6;

//
// Memory management models.
//

/** The create statics model. */
static const char CREATE_STATICS_MODEL[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 's', 't', 'a', 't', 'i', 'c', 's'};

/** The create statics model size. */
static const int CREATE_STATICS_MODEL_SIZE = 14;

/** The destroy statics model. */
static const char DESTROY_STATICS_MODEL[] = {'d', 'e', 's', 't', 'r', 'o', 'y', '_', 's', 't', 'a', 't', 'i', 'c', 's'};

/** The destroy statics model size. */
static const int DESTROY_STATICS_MODEL_SIZE = 15;

/** The create dynamics model. */
static const char CREATE_DYNAMICS_MODEL[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's'};

/** The create dynamics model size. */
static const int CREATE_DYNAMICS_MODEL_SIZE = 15;

/** The destroy dynamics model. */
static const char DESTROY_DYNAMICS_MODEL[] = {'d', 'e', 's', 't', 'r', 'o', 'y', '_', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's'};

/** The destroy dynamics model size. */
static const int DESTROY_DYNAMICS_MODEL_SIZE = 16;

//
// Input output models.
//

/** The send model. */
static const char SEND_MODEL[] = {'s', 'e', 'n', 'd'};

/** The send model size. */
static const int SEND_MODEL_SIZE = 4;

/** The receive model. */
static const char RECEIVE_MODEL[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e'};

/** The receive model size. */
static const int RECEIVE_MODEL_SIZE = 7;

//
// Lifecycle step models.
//

/** The exit model. */
static const char EXIT_MODEL[] = {'e', 'x', 'i', 't'};

/** The exit model size. */
static const int EXIT_MODEL_SIZE = 4;

/*??
//
// Nop opcode.
//

static java.lang.String NOP[] = {'nop'};

//
// Pushing constants.
//

static java.lang.String CATEGORY = {'aconst_null'};
static java.lang.String CATEGORY = {'iconst_m1'};
static java.lang.String CATEGORY = {'iconst_0'};
static java.lang.String CATEGORY = {'iconst_1'};
static java.lang.String CATEGORY = {'iconst_2'};
static java.lang.String CATEGORY = {'iconst_3'};
static java.lang.String CATEGORY = {'iconst_4'};
static java.lang.String CATEGORY = {'iconst_5'};
static java.lang.String CATEGORY = {'lconst_0'};
static java.lang.String CATEGORY = {'lconst_1'}; // 10
static java.lang.String CATEGORY = {'fconst_0'};
static java.lang.String CATEGORY = {'fconst_1'};
static java.lang.String CATEGORY = {'fconst_2'};
static java.lang.String CATEGORY = {'dconst_0'};
static java.lang.String CATEGORY = {'dconst_1'};
static java.lang.String CATEGORY = {'bipush'};
static java.lang.String CATEGORY = {'sipush'};
static java.lang.String CATEGORY = {'ldc'}; //or ldc
static java.lang.String CATEGORY = {'ldc_w'}; //or ldc_w was ldc2
static java.lang.String CATEGORY = {'ldc2_w'};//or ldc2_w was ldc2w // 20

//
// Loading local variables.
//

static java.lang.String CATEGORY = {'iload'};
static java.lang.String CATEGORY = {'lload'};
static java.lang.String CATEGORY = {'fload'};
static java.lang.String CATEGORY = {'dload'};
static java.lang.String CATEGORY = {'aload'};
static java.lang.String CATEGORY = {'iload_0'};
static java.lang.String CATEGORY = {'iload_1'};
static java.lang.String CATEGORY = {'iload_2'};
static java.lang.String CATEGORY = {'iload_3'};
static java.lang.String CATEGORY = {'lload_0'}; // 30
static java.lang.String CATEGORY = {'lload_1'};
static java.lang.String CATEGORY = {'lload_2'};
static java.lang.String CATEGORY = {'lload_3'};
static java.lang.String CATEGORY = {'fload_0'};
static java.lang.String CATEGORY = {'fload_1'};
static java.lang.String CATEGORY = {'fload_2'};
static java.lang.String CATEGORY = {'fload_3'};
static java.lang.String CATEGORY = {'dload_0'};
static java.lang.String CATEGORY = {'dload_1'};
static java.lang.String CATEGORY = {'dload_2'}; // 40
static java.lang.String CATEGORY = {'dload_3'};
static java.lang.String CATEGORY = {'aload_0'};
static java.lang.String CATEGORY = {'aload_1'};
static java.lang.String CATEGORY = {'aload_2'};
static java.lang.String CATEGORY = {'aload_3'};

//
// Loading array elements.
//

static java.lang.String CATEGORY = {'iaload'};
static java.lang.String CATEGORY = {'laload'};
static java.lang.String CATEGORY = {'faload'};
static java.lang.String CATEGORY = {'daload'};
static java.lang.String CATEGORY = {'aaload'}; // 50
static java.lang.String CATEGORY = {'baload'};
static java.lang.String CATEGORY = {'caload'};
static java.lang.String CATEGORY = {'saload'};

//
// Storing to local variables.
//

static java.lang.String CATEGORY = {'istore'};
static java.lang.String CATEGORY = {'lstore'};
static java.lang.String CATEGORY = {'fstore'};
static java.lang.String CATEGORY = {'dstore'};
static java.lang.String CATEGORY = {'astore'};
static java.lang.String CATEGORY = {'istore_0'};
static java.lang.String CATEGORY = {'istore_1'}; // 60
static java.lang.String CATEGORY = {'istore_2'};
static java.lang.String CATEGORY = {'istore_3'};
static java.lang.String CATEGORY = {'lstore_0'};
static java.lang.String CATEGORY = {'lstore_1'};
static java.lang.String CATEGORY = {'lstore_2'};
static java.lang.String CATEGORY = {'lstore_3'};
static java.lang.String CATEGORY = {'fstore_0'};
static java.lang.String CATEGORY = {'fstore_1'};
static java.lang.String CATEGORY = {'fstore_2'};
static java.lang.String CATEGORY = {'fstore_3'}; // 70
static java.lang.String CATEGORY = {'dstore_0'};
static java.lang.String CATEGORY = {'dstore_1'};
static java.lang.String CATEGORY = {'dstore_2'};
static java.lang.String CATEGORY = {'dstore_3'};
static java.lang.String CATEGORY = {'astore_0'};
static java.lang.String CATEGORY = {'astore_1'};
static java.lang.String CATEGORY = {'astore_2'};
static java.lang.String CATEGORY = {'astore_3'};

//
// Storing to array elements.
//

static java.lang.String CATEGORY = {'iastore'};
static java.lang.String CATEGORY = {'lastore'}; // 80
static java.lang.String CATEGORY = {'fastore'};
static java.lang.String CATEGORY = {'dastore'};
static java.lang.String CATEGORY = {'aastore'};
static java.lang.String CATEGORY = {'bastore'};
static java.lang.String CATEGORY = {'castore'};
static java.lang.String CATEGORY = {'sastore'};

//
// Stack instructions.
//

static java.lang.String CATEGORY = {'pop'};
static java.lang.String CATEGORY = {'pop2'};
static java.lang.String CATEGORY = {'dup_'};
static java.lang.String CATEGORY = {'dup_x1'}; // 90
static java.lang.String CATEGORY = {'dup_x2'};
static java.lang.String CATEGORY = {'dup2_'};
static java.lang.String CATEGORY = {'dup2_x1'};
static java.lang.String CATEGORY = {'dup2_x2'};
static java.lang.String CATEGORY = {'swap'};

//
// Arithmetic instructions.
//

static java.lang.String CATEGORY = {'iadd'};
static java.lang.String CATEGORY = {'ladd'};
static java.lang.String CATEGORY = {'fadd'};
static java.lang.String CATEGORY = {'dadd'};
static java.lang.String CATEGORY = {'isub'}; // 100
static java.lang.String CATEGORY = {'lsub'};
static java.lang.String CATEGORY = {'fsub'};
static java.lang.String CATEGORY = {'dsub'};
static java.lang.String CATEGORY = {'imul'};
static java.lang.String CATEGORY = {'lmul'};
static java.lang.String CATEGORY = {'fmul'};
static java.lang.String CATEGORY = {'dmul'};
static java.lang.String CATEGORY = {'idiv'};
static java.lang.String CATEGORY = {'ldiv_'};
static java.lang.String CATEGORY = {'fdiv'}; // 110
static java.lang.String CATEGORY = {'ddiv'};
static java.lang.String CATEGORY = {'imod'};
static java.lang.String CATEGORY = {'lmod'};
static java.lang.String CATEGORY = {'fmod_'};
static java.lang.String CATEGORY = {'dmod'};
static java.lang.String CATEGORY = {'ineg'};
static java.lang.String CATEGORY = {'lneg'};
static java.lang.String CATEGORY = {'fneg'};
static java.lang.String CATEGORY = {'dneg'};

//
// Logical instructions.
//

static java.lang.String CATEGORY = {'ishl'}; // 120
static java.lang.String CATEGORY = {'lshl'};
static java.lang.String CATEGORY = {'ishr'};
static java.lang.String CATEGORY = {'lshr'};
static java.lang.String CATEGORY = {'iushr'};
static java.lang.String CATEGORY = {'lushr'};
static java.lang.String CATEGORY = {'iand'};
static java.lang.String CATEGORY = {'land'};
static java.lang.String CATEGORY = {'ior'};
static java.lang.String CATEGORY = {'lor'};
static java.lang.String CATEGORY = {'ixor'}; // 130
static java.lang.String CATEGORY = {'lxor'};

//
// Increment.
//

static java.lang.String CATEGORY = {'iinc'};

//
// Conversion operations.
//

static java.lang.String CATEGORY = {'i2l'}; // 133 here ... was 132 in spec
static java.lang.String CATEGORY = {'i2f'}; // 134 here... was 133 in spec
static java.lang.String CATEGORY = {'i2d'}; // 135 here... was 134 in spec
static java.lang.String CATEGORY = {'l2i'};
static java.lang.String CATEGORY = {'l2f'};
static java.lang.String CATEGORY = {'l2d'};
static java.lang.String CATEGORY = {'f2i'};
static java.lang.String CATEGORY = {'f2l'}; // 140
static java.lang.String CATEGORY = {'f2d'};
static java.lang.String CATEGORY = {'d2i'};
static java.lang.String CATEGORY = {'d2l'};
static java.lang.String CATEGORY = {'d2f'};
static java.lang.String CATEGORY = {'int2byte'};
static java.lang.String CATEGORY = {'int2char'};
static java.lang.String CATEGORY = {'int2short'};

//
// Comparison instructions.
//

static java.lang.String CATEGORY = {'lcmp'};
static java.lang.String CATEGORY = {'fcmpl'};
static java.lang.String CATEGORY = {'fcmpg'}; // 150
static java.lang.String CATEGORY = {'dcmpl'};
static java.lang.String CATEGORY = {'dcmpg'};

//
// Branch instructions.
//

static java.lang.String CATEGORY = {'ifeq'};
static java.lang.String CATEGORY = {'ifne'};
static java.lang.String CATEGORY = {'iflt'};
static java.lang.String CATEGORY = {'ifge'};
static java.lang.String CATEGORY = {'ifgt'};
static java.lang.String CATEGORY = {'ifle'};
static java.lang.String CATEGORY = {'if_icmpeq'};
static java.lang.String CATEGORY = {'if_icmpne'}; // 160
static java.lang.String CATEGORY = {'if_icmplt'};
static java.lang.String CATEGORY = {'if_icmpge'};
static java.lang.String CATEGORY = {'if_icmpgt'};
static java.lang.String CATEGORY = {'if_icmple'};
static java.lang.String CATEGORY = {'if_acmpeq'};
static java.lang.String CATEGORY = {'if_acmpne'};
static java.lang.String CATEGORY = {'goto_'};
static java.lang.String CATEGORY = {'jsr'};
static java.lang.String CATEGORY = {'ret'};

//
// Table jumping.
//

static java.lang.String CATEGORY = {'tableswitch'}; // 170
static java.lang.String CATEGORY = {'lookupswitch'};

//
// Function return.
//

static java.lang.String CATEGORY = {'ireturn'};
static java.lang.String CATEGORY = {'lreturn'};
static java.lang.String CATEGORY = {'freturn'};
static java.lang.String CATEGORY = {'dreturn'};
static java.lang.String CATEGORY = {'areturn'};
static java.lang.String CATEGORY = {'return_'};

//
// Manipulating object fields.
//

static java.lang.String CATEGORY = {'getstatic'};
static java.lang.String CATEGORY = {'putstatic'};
static java.lang.String CATEGORY = {'getfield'}; // 180
static java.lang.String CATEGORY = {'putfield'};

//
// Method invocation.
//

static java.lang.String CATEGORY = {'invokevirtual'};
static java.lang.String CATEGORY = {'invokespecial'}; // was nonvirtual
static java.lang.String CATEGORY = {'invokestatic'};
static java.lang.String CATEGORY = {'invokeinterface'};

//
// Miscellaneous object operations.
//

static java.lang.String CATEGORY = {'newfromname'};
static java.lang.String CATEGORY = {'new_'};
static java.lang.String CATEGORY = {'newarray'};
static java.lang.String CATEGORY = {'anewarray'};
static java.lang.String CATEGORY = {'arraylength'}; // 190
static java.lang.String CATEGORY = {'athrow'};
static java.lang.String CATEGORY = {'checkcast'};
static java.lang.String CATEGORY = {'instanceof'};

//
// Monitors.
//

static java.lang.String CATEGORY = {'monitorenter'};
static java.lang.String CATEGORY = {'monitorexit'};

//
// Debugging.
//

static java.lang.String CATEGORY = {'verifystack'};
// breakpoint;
// breakpoint is in the documentation; but the compiler does not use it
// ... multianewarray moves up one place to take breakpoint's place

//
// More arrays.
//

static java.lang.String CATEGORY = {'multianewarray'};

//
// Undocumented java class stuff.
//

static java.lang.String CATEGORY = {'ifnull'};
static java.lang.String CATEGORY = {'ifnonnull'};

//
// Optimisations.
//

static java.lang.String CATEGORY = {'ldc1_quick'}; // 200
static java.lang.String CATEGORY = {'ldc2_quick'};
static java.lang.String CATEGORY = {'ldc2w_quick'};

static java.lang.String CATEGORY = {'getfield_quick'};
static java.lang.String CATEGORY = {'putfield_quick'};
static java.lang.String CATEGORY = {'getfield2_quick'};
static java.lang.String CATEGORY = {'putfield2_quick'};

//
// Short-cuts for when the current class is not the same as the static field's class.
//

static java.lang.String CATEGORY = {'getstatic_quick'};
static java.lang.String CATEGORY = {'putstatic_quick'};
static java.lang.String CATEGORY = {'getstatic2_quick'};
static java.lang.String CATEGORY = {'putstatic2_quick'}; // 210

static java.lang.String CATEGORY = {'invokevirtual_quick'};
static java.lang.String CATEGORY = {'invokespecial_quick'}; // was nonvirtual
static java.lang.String CATEGORY = {'invokestatic_quick'};
static java.lang.String CATEGORY = {'invokeinterface_quick'};
static java.lang.String CATEGORY = {'invokevirtualobject_quick'}; //?? I can't understand this!

static java.lang.String CATEGORY = {'new_quick'};
static java.lang.String CATEGORY = {'anewarray_quick'};
static java.lang.String CATEGORY = {'checkcast_quick'};
static java.lang.String CATEGORY = {'instanceof_quick'};

//
// Shortcuts for when the current class is the same as the static field's class.
//

static java.lang.String CATEGORY = {'putstaticcurrclass_quick'}; // 220
static java.lang.String CATEGORY = {'putstatic2currclass_quick'};
static java.lang.String CATEGORY = {'getstaticcurrclass_quick'};
static java.lang.String CATEGORY = {'getstatic2currclass_quick'};

static java.lang.String CATEGORY = {'invokenonvirtualcurrclass_quick'};
static java.lang.String CATEGORY = {'invokestaticcurrclass_quick'};

//
// Used for preloaded classes in ROM because we can't overwrite the operand with a guess.
//

static java.lang.String CATEGORY = {'invokeinterface_noguess'}; // +- 226

//
// Special instructions to invoke optimised methods.
//

static java.lang.String CATEGORY = {'invokevirtual_quick_optimised'};
*/

//
// Model size constants.
//

/** The model size. */
static const int MODEL_SIZE = 22;

//
// Model index constants.
//

/** The parts size index. */
static const int PARTS_SIZE_INDEX = 0;

/** The parts count index. */
static const int PARTS_COUNT_INDEX = 1;

/** The names index. */
static const int NAMES_INDEX = 2;

/** The names sizes index. */
static const int NAMES_SIZES_INDEX = 3;

/** The part abstractions index. */
static const int PART_ABSTRACTIONS_INDEX = 4;

/** The part abstractions sizes index. */
static const int PART_ABSTRACTIONS_SIZES_INDEX = 5;

/** The part locations index. */
static const int PART_LOCATIONS_INDEX = 6;

/** The part locations sizes index. */
static const int PART_LOCATIONS_SIZES_INDEX = 7;

/** The part models index. */
static const int PART_MODELS_INDEX = 8;

/** The part models sizes index. */
static const int PART_MODELS_SIZES_INDEX = 9;

/** The position abstractions index. */
static const int POSITION_ABSTRACTIONS_INDEX = 10;

/** The position abstractions sizes index. */
static const int POSITION_ABSTRACTIONS_SIZES_INDEX = 11;

/** The position locations index. */
static const int POSITION_LOCATIONS_INDEX = 12;

/** The position locations sizes index. */
static const int POSITION_LOCATIONS_SIZES_INDEX = 13;

/** The position models index. */
static const int POSITION_MODELS_INDEX = 14;

/** The position models sizes index. */
static const int POSITION_MODELS_SIZES_INDEX = 15;

/** The constraint abstractions index. */
static const int CONSTRAINT_ABSTRACTIONS_INDEX = 16;

/** The constraint abstractions sizes index. */
static const int CONSTRAINT_ABSTRACTIONS_SIZES_INDEX = 17;

/** The constraint locations index. */
static const int CONSTRAINT_LOCATIONS_INDEX = 18;

/** The constraint locations sizes index. */
static const int CONSTRAINT_LOCATIONS_SIZES_INDEX = 19;

/** The constraint models index. */
static const int CONSTRAINT_MODELS_INDEX = 20;

/** The constraint models sizes index. */
static const int CONSTRAINT_MODELS_SIZES_INDEX = 21;

//
// Model separator constants.
//

/** The model part separator. */
static const char MODEL_PART_SEPARATOR = '.';

//
// Model location constants.
//

/** The inline location. */
static const char INLINE_LOCATION[] = {'i', 'n', 'l', 'i', 'n', 'e', ':', '/'};

/** The inline location size. */
static const int INLINE_LOCATION_SIZE = 8;

/** The file location. */
static const char FILE_LOCATION[] = {'f', 'i', 'l', 'e', ':', '/'};

/** The file location size. */
static const int FILE_LOCATION_SIZE = 6;

/** The http location. */
static const char HTTP_LOCATION[] = {'h', 't', 't', 'p', ':', '/', '/'};

/** The http location size. */
static const int HTTP_LOCATION_SIZE = 7;

/** The ftp location. */
static const char FTP_LOCATION[] = {'f', 't', 'p', ':', '/', '/'};

/** The ftp location size. */
static const int FTP_LOCATION_SIZE = 6;

//
// Array type constants.
//

//?? Possibly remove pointer array, if a pointer is really identical to an integer.

/** The pointer array constant. */
static const int POINTER_ARRAY = 0;

/** The integer array constant. */
static const int INTEGER_ARRAY = 1;

//?? Possibly remove character array, if a character primitive is really
//?? identical to an integer primitive. Are they?

/** The character array constant. */
static const int CHARACTER_ARRAY = 2;

//?? Possibly remove double array, if a double primitive can be replaced by
//?? a compound structure like "fraction". How would this effect performance
//?? when ALU will not work with doubles but they rather get transformed into
//?? integers first?

/** The double array constant. */
static const int DOUBLE_ARRAY = 3;

/* CONSTANTS_SOURCE */
#endif
