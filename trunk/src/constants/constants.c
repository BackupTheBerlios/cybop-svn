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
 * This file defines global constants for:
 * - null pointers
 * - arrays
 * - compounds:
 *   - fraction
 *   - vector
 *   - time
 *   - complex
 *   - operation
 *   - model
 *   - signal memory
 * - signal priorities
 * - signal languages
 * - cybol file
 * - cybol tags
 * - cybol attributes
 * - cybol abstraction values:
 *   - compound
 *   - statics
 *   - dynamics
 * - cybol location values:
 *   - model locations
 *   - location separators
 * - cybol model values:
 *   - model separators
 *   - boolean
 * - logging:
 *   - log levels
 *   - log level names
 *   - log messages
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * Systems would then be written solely in cybol. Dreaming ...
 *
 * @version $Revision: 1.8 $ $Date: 2004-05-27 13:52:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANTS_SOURCE
#define CONSTANTS_SOURCE

//
// Null pointers.
//

/** The null pointer. */
static void* NULL_POINTER = (void*) 0;

/** The pointer null pointer. */
static void** POINTER_NULL_POINTER = (void**) 0;

/** The integer null pointer. */
static int* INTEGER_NULL_POINTER = (int*) 0;

/** The character null pointer. */
static char* CHARACTER_NULL_POINTER = (char*) 0;

/** The double null pointer. */
static double* DOUBLE_NULL_POINTER = (double*) 0;

//
// ASCII characters (0 - 127).
//

/** The colon character. */
static char COLON_CHARACTER = ':';

/** The space character. */
static char SPACE_CHARACTER = ' ';

/** The new line character. */
static char NEW_LINE_CHARACTER = '\n';

//
// ANSI characters (128 - 255).
//

//
// UNICODE characters (256 - ??).
//

//
// Special characters.
//

/** The null character, used as string termination in the c programming language. */
static char NULL_CHARACTER = '\0';

//
// Arrays.
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

//
// Compounds:
// - fraction
// - vector
// - time
// - complex
// - operation
// - model
// - signal memory
//

//
// Fraction.
//

/** The fraction count. */
static const int FRACTION_COUNT = 2;

/** The numerator index. */
static const int NUMERATOR_INDEX = 0;

/** The denominator index. */
static const int DENOMINATOR_INDEX = 1;

//
// Vector.
//

/** The vector count. */
static const int VECTOR_COUNT = 3;

/** The x index. */
static const int X_INDEX = 0;

/** The y index. */
static const int Y_INDEX = 1;

/** The z index. */
static const int Z_INDEX = 2;

//
// Time.
//

/** The time count. */
static const int TIME_COUNT = 6;

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
// Complex.
//

/** The complex count. */
static const int COMPLEX_COUNT = 2;

/** The real index. */
static const int REAL_INDEX = 0;

/** The imaginary index. */
static const int IMAGINARY_INDEX = 1;

//
// Operation.
//

/** The operation count. */
static const int OPERATION_COUNT = 3;

/** The parameters count index. */
static const int PARAMETERS_COUNT_INDEX = 0;

/** The parameters index. */
static const int PARAMETERS_INDEX = 1;

/** The parameters counts index. */
static const int PARAMETERS_COUNTS_INDEX = 2;

//
// Model.
//

/** The model count. */
static const int MODEL_COUNT = 22;

/** The parts size index. */
static const int PARTS_SIZE_INDEX = 0;

/** The parts count index. */
static const int PARTS_COUNT_INDEX = 1;

/** The names index. */
static const int NAMES_INDEX = 2;

/** The names counts index. */
static const int NAMES_COUNTS_INDEX = 3;

/** The part abstractions index. */
static const int PART_ABSTRACTIONS_INDEX = 4;

/** The part abstractions counts index. */
static const int PART_ABSTRACTIONS_COUNTS_INDEX = 5;

/** The part locations index. */
static const int PART_LOCATIONS_INDEX = 6;

/** The part locations counts index. */
static const int PART_LOCATIONS_COUNTS_INDEX = 7;

/** The part models index. */
static const int PART_MODELS_INDEX = 8;

/** The part models counts index. */
static const int PART_MODELS_COUNTS_INDEX = 9;

/** The position abstractions index. */
static const int POSITION_ABSTRACTIONS_INDEX = 10;

/** The position abstractions counts index. */
static const int POSITION_ABSTRACTIONS_COUNTS_INDEX = 11;

/** The position locations index. */
static const int POSITION_LOCATIONS_INDEX = 12;

/** The position locations counts index. */
static const int POSITION_LOCATIONS_COUNTS_INDEX = 13;

/** The position models index. */
static const int POSITION_MODELS_INDEX = 14;

/** The position models counts index. */
static const int POSITION_MODELS_COUNTS_INDEX = 15;

/** The constraint abstractions index. */
static const int CONSTRAINT_ABSTRACTIONS_INDEX = 16;

/** The constraint abstractions counts index. */
static const int CONSTRAINT_ABSTRACTIONS_COUNTS_INDEX = 17;

/** The constraint locations index. */
static const int CONSTRAINT_LOCATIONS_INDEX = 18;

/** The constraint locations counts index. */
static const int CONSTRAINT_LOCATIONS_COUNTS_INDEX = 19;

/** The constraint models index. */
static const int CONSTRAINT_MODELS_INDEX = 20;

/** The constraint models counts index. */
static const int CONSTRAINT_MODELS_COUNTS_INDEX = 21;

//
// Signal memory.
//

/** The signal memory count. */
static const int SIGNAL_MEMORY_COUNT = 6;

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

/** The abstractions counts index. */
static const int ABSTRACTIONS_COUNTS_INDEX = 5;

//
// Signal priorities.
//

/** The normal priority. */
static const int NORMAL_PRIORITY = 0;

//
// Signal languages.
//

/** The cybol language array. */
static const char CYBOL_LANGUAGE_ARRAY[] = {'c', 'y', 'b', 'o', 'l'};

/** The cybol language. */
static const char* CYBOL_LANGUAGE = CYBOL_LANGUAGE_ARRAY;

/** The cybol language count. */
static const int CYBOL_LANGUAGE_COUNT = 5;

/** The inline language array. */
static const char INLINE_LANGUAGE_ARRAY[] = {'i', 'n', 'l', 'i', 'n', 'e'};

/** The inline language. */
static const char* INLINE_LANGUAGE = INLINE_LANGUAGE_ARRAY;

/** The inline language count. */
static const int INLINE_LANGUAGE_COUNT = 6;

/** The textual user interface (tui) language array. */
static const char TUI_LANGUAGE_ARRAY[] = {'t', 'u', 'i'};

/** The textual user interface (tui) language. */
static const char* TUI_LANGUAGE = TUI_LANGUAGE_ARRAY;

/** The textual user interface (tui) language count. */
static const int TUI_LANGUAGE_COUNT = 3;

/** The mouse language array. */
static const char MOUSE_LANGUAGE_ARRAY[] = {'m', 'o', 'u', 's', 'e'};

/** The mouse language. */
static const char* MOUSE_LANGUAGE = MOUSE_LANGUAGE_ARRAY;

/** The mouse language count. */
static const int MOUSE_LANGUAGE_COUNT = 5;

/** The x windows language array. */
static const char X_WINDOWS_LANGUAGE_ARRAY[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', 's'};

/** The x windows language. */
static const char* X_WINDOWS_LANGUAGE = X_WINDOWS_LANGUAGE_ARRAY;

/** The x windows language count. */
static const int X_WINDOWS_LANGUAGE_COUNT = 9;

/** The socket language array. */
static const char SOCKET_LANGUAGE_ARRAY[] = {'s', 'o', 'c', 'k', 'e', 't'};

/** The socket language. */
static const char* SOCKET_LANGUAGE = SOCKET_LANGUAGE_ARRAY;

/** The socket language count. */
static const int SOCKET_LANGUAGE_COUNT = 6;

/** The structured query language (sql) array. */
static const char SQ_LANGUAGE_ARRAY[] = {'s', 'q'};

/** The structured query language (sql). */
static const char* SQ_LANGUAGE = SQ_LANGUAGE_ARRAY;

/** The structured query language (sql) count. */
static const int SQ_LANGUAGE_COUNT = 2;

/** The java messaging service (jms) language array. */
static const char JMS_LANGUAGE_ARRAY[] = {'j', 'm', 's'};

/** The java messaging service (jms) language. */
static const char* JMS_LANGUAGE = JMS_LANGUAGE_ARRAY;

/** The java messaging service (jms) language count. */
static const int JMS_LANGUAGE_COUNT = 3;

/** The remote method invocation (rmi) language array. */
static const char RMI_LANGUAGE_ARRAY[] = {'r', 'm', 'i'};

/** The remote method invocation (rmi) language. */
static const char* RMI_LANGUAGE = RMI_LANGUAGE_ARRAY;

/** The remote method invocation (rmi) language count. */
static const int RMI_LANGUAGE_COUNT = 3;

/** The common object request broker architecture (corba) language array. */
static const char CORBA_LANGUAGE_ARRAY[] = {'c', 'o', 'r', 'b', 'a'};

/** The common object request broker architecture (corba) language. */
static const char* CORBA_LANGUAGE = CORBA_LANGUAGE_ARRAY;

/** The common object request broker architecture (corba) language count. */
static const int CORBA_LANGUAGE_COUNT = 5;

/** The extensible markup language (xml) array. */
static const char XML_LANGUAGE_ARRAY[] = {'x', 'm', 'l'};

/** The extensible markup language (xml). */
static const char* XML_LANGUAGE = XML_LANGUAGE_ARRAY;

/** The extensible markup language (xml) count. */
static const int XML_LANGUAGE_COUNT = 3;

/** The simple object access protocol (soap) language array. */
static const char SOAP_LANGUAGE_ARRAY[] = {'s', 'o', 'a', 'p'};

/** The simple object access protocol (soap) language. */
static const char* SOAP_LANGUAGE = SOAP_LANGUAGE_ARRAY;

/** The simple object access protocol (soap) language count. */
static const int SOAP_LANGUAGE_COUNT = 4;

/** The file language array. */
static const char FILE_LANGUAGE_ARRAY[] = {'f', 'i', 'l', 'e'};

/** The file language. */
static const char* FILE_LANGUAGE = FILE_LANGUAGE_ARRAY;

/** The file language count. */
static const int FILE_LANGUAGE_COUNT = 4;

/** The floppy language array. */
static const char FLOPPY_LANGUAGE_ARRAY[] = {'f', 'l', 'o', 'p', 'p', 'y'};

/** The floppy language. */
static const char* FLOPPY_LANGUAGE = FLOPPY_LANGUAGE_ARRAY;

/** The floppy language count. */
static const int FLOPPY_LANGUAGE_COUNT = 6;

/** The ftp language array. */
static const char FTP_LANGUAGE_ARRAY[] = {'f', 't', 'p'};

/** The ftp language. */
static const char* FTP_LANGUAGE = FTP_LANGUAGE_ARRAY;

/** The ftp language count. */
static const int FTP_LANGUAGE_COUNT = 3;

/** The sftp language array. */
static const char SFTP_LANGUAGE_ARRAY[] = {'s', 'f', 't', 'p'};

/** The sftp language. */
static const char* SFTP_LANGUAGE = SFTP_LANGUAGE_ARRAY;

/** The sftp language count. */
static const int SFTP_LANGUAGE_COUNT = 4;

/** The imap language array. */
static const char IMAP_LANGUAGE_ARRAY[] = {'i', 'm', 'a', 'p'};

/** The imap language. */
static const char* IMAP_LANGUAGE = IMAP_LANGUAGE_ARRAY;

/** The imap language count. */
static const int IMAP_LANGUAGE_COUNT = 4;

/** The imaps language array. */
static const char IMAPS_LANGUAGE_ARRAY[] = {'i', 'm', 'a', 'p', 's'};

/** The imaps language. */
static const char* IMAPS_LANGUAGE = IMAPS_LANGUAGE_ARRAY;

/** The imaps language count. */
static const int IMAPS_LANGUAGE_COUNT = 5;

/** The ldap language array. */
static const char LDAP_LANGUAGE_ARRAY[] = {'l', 'd', 'a', 'p'};

/** The ldap language. */
static const char* LDAP_LANGUAGE = LDAP_LANGUAGE_ARRAY;

/** The ldap language count. */
static const int LDAP_LANGUAGE_COUNT = 4;

/** The nfs language array. */
static const char NFS_LANGUAGE_ARRAY[] = {'n', 'f', 's'};

/** The nfs language. */
static const char* NFS_LANGUAGE = NFS_LANGUAGE_ARRAY;

/** The nfs language count. */
static const int NFS_LANGUAGE_COUNT = 3;

/** The nntp language array. */
static const char NNTP_LANGUAGE_ARRAY[] = {'n', 'n', 't', 'p'};

/** The nntp language. */
static const char* NNTP_LANGUAGE = NNTP_LANGUAGE_ARRAY;

/** The nntp language count. */
static const int NNTP_LANGUAGE_COUNT = 4;

/** The smb language array. */
static const char SMB_LANGUAGE_ARRAY[] = {'s', 'm', 'b'};

/** The smb language. */
static const char* SMB_LANGUAGE = SMB_LANGUAGE_ARRAY;

/** The smb language count. */
static const int SMB_LANGUAGE_COUNT = 3;

/** The smtp language array. */
static const char SMTP_LANGUAGE_ARRAY[] = {'s', 'm', 't', 'p'};

/** The smtp language. */
static const char* SMTP_LANGUAGE = SMTP_LANGUAGE_ARRAY;

/** The smtp language count. */
static const int SMTP_LANGUAGE_COUNT = 4;

/** The smtps language array. */
static const char SMTPS_LANGUAGE_ARRAY[] = {'s', 'm', 't', 'p', 's'};

/** The smtps language. */
static const char* SMTPS_LANGUAGE = SMTPS_LANGUAGE_ARRAY;

/** The smtps language count. */
static const int SMTPS_LANGUAGE_COUNT = 5;

/** The tar language array. */
static const char TAR_LANGUAGE_ARRAY[] = {'t', 'a', 'r'};

/** The tar language. */
static const char* TAR_LANGUAGE = TAR_LANGUAGE_ARRAY;

/** The tar language count. */
static const int TAR_LANGUAGE_COUNT = 3;

/** The zip language array. */
static const char ZIP_LANGUAGE_ARRAY[] = {'z', 'i', 'p'};

/** The zip language. */
static const char* ZIP_LANGUAGE = ZIP_LANGUAGE_ARRAY;

/** The zip language count. */
static const int ZIP_LANGUAGE_COUNT = 3;

//
// Cybol file.
//

/** The cybol path. */
//?? static const char CYBOL_PATH[] = {'/home/cybop/lib/cybop/'};

/** The cybol file suffix. */
//?? static const char FILE_SUFFIX[] = {'.cybol'};

/** The null model. */
//?? static const char NULL_MODEL[] = {'null'};

//
// Cybol tags.
//

/** The model tag array. */
static const char MODEL_TAG_ARRAY[] = {'m', 'o', 'd', 'e', 'l'};

/** The model tag. */
static const char* MODEL_TAG = MODEL_TAG_ARRAY;

/** The model tag count. */
static const int MODEL_TAG_COUNT = 5;

/** The part tag array. */
static const char PART_TAG_ARRAY[] = {'p', 'a', 'r', 't'};

/** The part tag. */
static const char* PART_TAG = PART_TAG_ARRAY;

/** The part tag count. */
static const int PART_TAG_COUNT = 4;

/** The super tag array. */
static const char SUPER_TAG_ARRAY[] = {'s', 'u', 'p', 'e', 'r'};

/** The super tag. */
static const char* SUPER_TAG = SUPER_TAG_ARRAY;

/** The super tag count. */
static const int SUPER_TAG_COUNT = 5;

//
// Cybol attributes.
//

/** The name attribute array. */
static const char NAME_ATTRIBUTE_ARRAY[] = {'n', 'a', 'm', 'e'};

/** The name attribute. */
static const char* NAME_ATTRIBUTE = NAME_ATTRIBUTE_ARRAY;

/** The name attribute count. */
static const int NAME_ATTRIBUTE_COUNT = 4;

/** The part abstraction attribute array. */
static const char PART_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'p', 'a', 'r', 't', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The part abstraction attribute. */
static const char* PART_ABSTRACTION_ATTRIBUTE = PART_ABSTRACTION_ATTRIBUTE_ARRAY;

/** The part abstraction attribute count. */
static const int PART_ABSTRACTION_ATTRIBUTE_COUNT = 16;

/** The part location attribute array. */
static const char PART_LOCATION_ATTRIBUTE_ARRAY[] = {'p', 'a', 'r', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The part location attribute. */
static const char* PART_LOCATION_ATTRIBUTE = PART_LOCATION_ATTRIBUTE_ARRAY;

/** The part location attribute count. */
static const int PART_LOCATION_ATTRIBUTE_COUNT = 13;

/** The part model attribute array. */
static const char PART_MODEL_ATTRIBUTE_ARRAY[] = {'p', 'a', 'r', 't', '_', 'm', 'o', 'd', 'e', 'l'};

/** The part model attribute. */
static const char* PART_MODEL_ATTRIBUTE = PART_MODEL_ATTRIBUTE_ARRAY;

/** The part model attribute count. */
static const int PART_MODEL_ATTRIBUTE_COUNT = 10;

/** The position abstraction attribute array. */
static const char POSITION_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The position abstraction attribute. */
static const char* POSITION_ABSTRACTION_ATTRIBUTE = POSITION_ABSTRACTION_ATTRIBUTE_ARRAY;

/** The position abstraction attribute count. */
static const int POSITION_ABSTRACTION_ATTRIBUTE_COUNT = 20;

/** The position location attribute array. */
static const char POSITION_LOCATION_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The position location attribute. */
static const char* POSITION_LOCATION_ATTRIBUTE = POSITION_LOCATION_ATTRIBUTE_ARRAY;

/** The position location attribute count. */
static const int POSITION_LOCATION_ATTRIBUTE_COUNT = 17;

/** The position model attribute array. */
static const char POSITION_MODEL_ATTRIBUTE_ARRAY[] = {'p', 'o', 's', 'i', 't', 'i', 'o', 'n', '_', 'm', 'o', 'd', 'e', 'l'};

/** The position model attribute. */
static const char* POSITION_MODEL_ATTRIBUTE = POSITION_MODEL_ATTRIBUTE_ARRAY;

/** The position model attribute count. */
static const int POSITION_MODEL_ATTRIBUTE_COUNT = 14;

/** The constraint abstraction attribute array. */
static const char CONSTRAINT_ABSTRACTION_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The constraint abstraction attribute. */
static const char* CONSTRAINT_ABSTRACTION_ATTRIBUTE = CONSTRAINT_ABSTRACTION_ATTRIBUTE_ARRAY;

/** The constraint abstraction attribute count. */
static const int CONSTRAINT_ABSTRACTION_ATTRIBUTE_COUNT = 22;

/** The constraint location attribute array. */
static const char CONSTRAINT_LOCATION_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'l', 'o', 'c', 'a', 't', 'i', 'o', 'n'};

/** The constraint location attribute. */
static const char* CONSTRAINT_LOCATION_ATTRIBUTE = CONSTRAINT_LOCATION_ATTRIBUTE_ARRAY;

/** The constraint location attribute count. */
static const int CONSTRAINT_LOCATION_ATTRIBUTE_COUNT = 19;

/** The constraint model attribute array. */
static const char CONSTRAINT_MODEL_ATTRIBUTE_ARRAY[] = {'c', 'o', 'n', 's', 't', 'r', 'a', 'i', 'n', 't', '_', 'm', 'o', 'd', 'e', 'l'};

/** The constraint model attribute. */
static const char* CONSTRAINT_MODEL_ATTRIBUTE = CONSTRAINT_MODEL_ATTRIBUTE_ARRAY;

/** The constraint model attribute count. */
static const int CONSTRAINT_MODEL_ATTRIBUTE_COUNT = 16;

//
// Cybol abstraction values:
// - compound
// - statics
// - dynamics
//

//
// Compound abstraction.
//
// Compound models consist of other compound or primitive models.
//

/** The compound abstraction array. */
static const char COMPOUND_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd'};

/** The compound abstraction. */
static const char* COMPOUND_ABSTRACTION = COMPOUND_ABSTRACTION_ARRAY;

/** The compound abstraction count. */
static const int COMPOUND_ABSTRACTION_COUNT = 8;

//
// Statics abstractions.
//
// There are compound and primitive statics models.
// The compound abstraction constant is defined above.
// Primitive models as defined below are the final abstraction in software.
//

//
// Operation abstraction.
//

/** The operation abstraction array. */
static const char OPERATION_ABSTRACTION_ARRAY[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

/** The operation abstraction. */
static const char* OPERATION_ABSTRACTION = OPERATION_ABSTRACTION_ARRAY;

/** The operation abstraction count. */
static const int OPERATION_ABSTRACTION_COUNT = 9;

//
// Primitive abstractions.
//

/** The boolean abstraction array. */
static const char BOOLEAN_ABSTRACTION_ARRAY[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};

/** The boolean abstraction. */
static const char* BOOLEAN_ABSTRACTION = BOOLEAN_ABSTRACTION_ARRAY;

/** The boolean abstraction count. */
static const int BOOLEAN_ABSTRACTION_COUNT = 7;

/** The integer abstraction array. */
static const char INTEGER_ABSTRACTION_ARRAY[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};

/** The integer abstraction. */
static const char* INTEGER_ABSTRACTION = INTEGER_ABSTRACTION_ARRAY;

/** The integer abstraction count. */
static const int INTEGER_ABSTRACTION_COUNT = 7;

/** The double abstraction array. */
static const char DOUBLE_ABSTRACTION_ARRAY[] = {'d', 'o', 'u', 'b', 'l', 'e'};

/** The double abstraction. */
static const char* DOUBLE_ABSTRACTION = DOUBLE_ABSTRACTION_ARRAY;

/** The double abstraction count. */
static const int DOUBLE_ABSTRACTION_COUNT = 6;

/** The fraction abstraction array. */
static const char FRACTION_ABSTRACTION_ARRAY[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The fraction abstraction. */
static const char* FRACTION_ABSTRACTION = FRACTION_ABSTRACTION_ARRAY;

/** The fraction abstraction count. */
static const int FRACTION_ABSTRACTION_COUNT = 8;

/** The complex abstraction array. */
static const char COMPLEX_ABSTRACTION_ARRAY[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};

/** The complex abstraction. */
static const char* COMPLEX_ABSTRACTION = COMPLEX_ABSTRACTION_ARRAY;

/** The complex abstraction count. */
static const int COMPLEX_ABSTRACTION_COUNT = 7;

/** The vector abstraction array. */
static const char VECTOR_ABSTRACTION_ARRAY[] = {'v', 'e', 'c', 't', 'o', 'r'};

/** The vector abstraction. */
static const char* VECTOR_ABSTRACTION = VECTOR_ABSTRACTION_ARRAY;

/** The vector abstraction count. */
static const int VECTOR_ABSTRACTION_COUNT = 6;

/** The string abstraction array. */
static const char STRING_ABSTRACTION_ARRAY[] = {'s', 't', 'r', 'i', 'n', 'g'};

/** The string abstraction. */
static const char* STRING_ABSTRACTION = STRING_ABSTRACTION_ARRAY;

/** The string abstraction count. */
static const int STRING_ABSTRACTION_COUNT = 6;

/** The time abstraction array. */
static const char TIME_ABSTRACTION_ARRAY[] = {'t', 'i', 'm', 'e'};

/** The time abstraction. */
static const char* TIME_ABSTRACTION = TIME_ABSTRACTION_ARRAY;

/** The time abstraction count. */
static const int TIME_ABSTRACTION_COUNT = 4;

//
// Audio abstractions.
//

/** The mp3 abstraction array. */
static const char MP3_MODEL_ARRAY[] = {'m', 'p', '3'};

/** The mp3 abstraction. */
static const char* MP3_MODEL = MP3_MODEL_ARRAY;

/** The mp3 abstraction count. */
static const int MP3_ABSTRACTION_COUNT = 3;

//
// Image abstractions.
//

/** The jpeg abstraction array. */
static const char JPEG_ABSTRACTION_ARRAY[] = {'j', 'p', 'e', 'g'};

/** The jpeg abstraction. */
static const char* JPEG_ABSTRACTION = JPEG_ABSTRACTION_ARRAY;

/** The jpeg abstraction count. */
static const int JPEG_ABSTRACTION_COUNT = 4;

/** The gif abstraction array. */
static const char GIF_ABSTRACTION_ARRAY[] = {'g', 'i', 'f'};

/** The gif abstraction. */
static const char* GIF_ABSTRACTION = GIF_ABSTRACTION_ARRAY;

/** The gif abstraction count. */
static const int GIF_ABSTRACTION_COUNT = 3;

/** The bmp abstraction array. */
static const char BMP_ABSTRACTION_ARRAY[] = {'b', 'm', 'p'};

/** The bmp abstraction. */
static const char* BMP_ABSTRACTION = BMP_ABSTRACTION_ARRAY;

/** The bmp abstraction count. */
static const int BMP_ABSTRACTION_COUNT = 3;

//
// Text abstractions.
//

/** The sgml abstraction array. */
static const char SGML_ABSTRACTION_ARRAY[] = {'s', 'g', 'm', 'l'};

/** The sgml abstraction. */
static const char* SGML_ABSTRACTION = SGML_ABSTRACTION_ARRAY;

/** The sgml abstraction count. */
static const int SGML_ABSTRACTION_COUNT = 4;

/** The xml abstraction array. */
static const char XML_ABSTRACTION_ARRAY[] = {'x', 'm', 'l'};

/** The xml abstraction. */
static const char* XML_ABSTRACTION = XML_ABSTRACTION_ARRAY;

/** The xml abstraction count. */
static const int XML_ABSTRACTION_COUNT = 3;

/** The html abstraction array. */
static const char HTML_ABSTRACTION_ARRAY[] = {'h', 't', 'm', 'l'};

/** The html abstraction. */
static const char* HTML_ABSTRACTION = HTML_ABSTRACTION_ARRAY;

/** The html abstraction count. */
static const int HTML_ABSTRACTION_COUNT = 4;

/** The rtf abstraction array. */
static const char RTF_ABSTRACTION_ARRAY[] = {'r', 't', 'f'};

/** The rtf abstraction. */
static const char* RTF_ABSTRACTION = RTF_ABSTRACTION_ARRAY;

/** The rtf abstraction count. */
static const int RTF_ABSTRACTION_COUNT = 3;

/** The tex abstraction array. */
static const char TEX_ABSTRACTION_ARRAY[] = {'t', 'e', 'x'};

/** The tex abstraction. */
static const char* TEX_ABSTRACTION = TEX_ABSTRACTION_ARRAY;

/** The tex abstraction count. */
static const int TEX_ABSTRACTION_COUNT = 3;

//
// Video abstractions.
//

/** The mpeg abstraction array. */
static const char MPEG_ABSTRACTION_ARRAY[] = {'m', 'p', 'e', 'g'};

/** The mpeg abstraction. */
static const char* MPEG_ABSTRACTION = MPEG_ABSTRACTION_ARRAY;

/** The mpeg abstraction count. */
static const int MPEG_ABSTRACTION_COUNT = 4;

/** The quicktime abstraction array. */
static const char QT_ABSTRACTION_ARRAY[] = {'q', 't'};

/** The quicktime abstraction. */
static const char* QT_ABSTRACTION = QT_ABSTRACTION_ARRAY;

/** The quicktime abstraction count. */
static const int QT_ABSTRACTION_COUNT = 2;

//
// Application abstractions.
//

/** The koffice kword abstraction array. */
static const char KWD_ABSTRACTION_ARRAY[] = {'k', 'w', 'd'};

/** The koffice kword abstraction. */
static const char* KWD_ABSTRACTION = KWD_ABSTRACTION_ARRAY;

/** The koffice kword abstraction count. */
static const int KWORD_ABSTRACTION_COUNT = 5;

/** The open office writer abstraction array. */
static const char SXW_ABSTRACTION_ARRAY[] = {'s', 'x', 'w'};

/** The open office writer abstraction. */
static const char* SXW_ABSTRACTION = SXW_ABSTRACTION_ARRAY;

/** The open office writer abstraction count. */
static const int SXW_ABSTRACTION_COUNT = 3;

//
// Dynamics abstractions.
//
// There are compound and primitive dynamics models.
// The compound abstraction constant is defined above.
// Primitive models as defined below are the final abstraction in software.
//

//
// Logics abstractions.
//

/** The and abstraction array. */
static const char AND_ABSTRACTION_ARRAY[] = {'a', 'n', 'd'};

/** The and abstraction. */
static const char* AND_ABSTRACTION = AND_ABSTRACTION_ARRAY;

/** The and abstraction count. */
static const int AND_ABSTRACTION_COUNT = 3;

/** The or abstraction array. */
static const char OR_ABSTRACTION_ARRAY[] = {'o', 'r'};

/** The or abstraction. */
static const char* OR_ABSTRACTION = OR_ABSTRACTION_ARRAY;

/** The or abstraction count. */
static const int OR_ABSTRACTION_COUNT = 2;

//
// Comparison abstractions.
//

/** The equal abstraction array. */
static const char EQUAL_ABSTRACTION_ARRAY[] = {'e', 'q', 'u', 'a', 'l'};

/** The equal abstraction. */
static const char* EQUAL_ABSTRACTION = EQUAL_ABSTRACTION_ARRAY;

/** The equal abstraction count. */
static const int EQUAL_ABSTRACTION_COUNT = 5;

/** The smaller abstraction array. */
static const char SMALLER_ABSTRACTION_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r'};

/** The smaller abstraction. */
static const char* SMALLER_ABSTRACTION = SMALLER_ABSTRACTION_ARRAY;

/** The smaller abstraction count. */
static const int SMALLER_ABSTRACTION_COUNT = 7;

/** The greater abstraction array. */
static const char GREATER_ABSTRACTION_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r'};

/** The greater abstraction. */
static const char* GREATER_ABSTRACTION = GREATER_ABSTRACTION_ARRAY;

/** The greater abstraction count. */
static const int GREATER_ABSTRACTION_COUNT = 7;

/** The smaller or equal abstraction array. */
static const char SMALLER_OR_EQUAL_ABSTRACTION_ARRAY[] = {'s', 'm', 'a', 'l', 'l', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};

/** The smaller or equal abstraction. */
static const char* SMALLER_OR_EQUAL_ABSTRACTION = SMALLER_OR_EQUAL_ABSTRACTION_ARRAY;

/** The smaller or equal abstraction count. */
static const int SMALLER_OR_EQUAL_ABSTRACTION_COUNT = 16;

/** The greater or equal abstraction array. */
static const char GREATER_OR_EQUAL_ABSTRACTION_ARRAY[] = {'g', 'r', 'e', 'a', 't', 'e', 'r', '_', 'o', 'r', '_', 'e', 'q', 'u', 'a', 'l'};

/** The greater or equal abstraction. */
static const char* GREATER_OR_EQUAL_ABSTRACTION = GREATER_OR_EQUAL_ABSTRACTION_ARRAY;

/** The greater or equal abstraction count. */
static const int GREATER_OR_EQUAL_ABSTRACTION_COUNT = 16;

//
// Arithmetic abstractions.
//

/** The add abstraction array. */
static const char ADD_ABSTRACTION_ARRAY[] = {'a', 'd', 'd'};

/** The add abstraction. */
static const char* ADD_ABSTRACTION = ADD_ABSTRACTION_ARRAY;

/** The add abstraction count. */
static const int ADD_ABSTRACTION_COUNT = 3;

/** The subtract abstraction array. */
static const char SUBTRACT_ABSTRACTION_ARRAY[] = {'s', 'u', 'b', 't', 'r', 'a', 'c', 't'};

/** The subtract abstraction. */
static const char* SUBTRACT_ABSTRACTION = SUBTRACT_ABSTRACTION_ARRAY;

/** The subtract abstraction count. */
static const int SUBTRACT_ABSTRACTION_COUNT = 8;

/** The multiply abstraction array. */
static const char MULTIPLY_ABSTRACTION_ARRAY[] = {'m', 'u', 'l', 't', 'i', 'p', 'l', 'y'};

/** The multiply abstraction. */
static const char* MULTIPLY_ABSTRACTION = MULTIPLY_ABSTRACTION_ARRAY;

/** The multiply abstraction count. */
static const int MULTIPLY_ABSTRACTION_COUNT = 8;

/** The divide abstraction array. */
static const char DIVIDE_ABSTRACTION_ARRAY[] = {'d', 'i', 'v', 'i', 'd', 'e'};

/** The divide abstraction. */
static const char* DIVIDE_ABSTRACTION = DIVIDE_ABSTRACTION_ARRAY;

/** The divide abstraction count. */
static const int DIVIDE_ABSTRACTION_COUNT = 6;

//
// Memory management abstractions.
//

/** The create model abstraction array. */
static const char CREATE_MODEL_ABSTRACTION_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e', '_', 's', 't', 'a', 't', 'i', 'c', 's'};

/** The create model abstraction. */
static const char* CREATE_MODEL_ABSTRACTION = CREATE_MODEL_ABSTRACTION_ARRAY;

/** The create model abstraction count. */
static const int CREATE_MODEL_ABSTRACTION_COUNT = 14;

/** The destroy model abstraction array. */
static const char DESTROY_MODEL_ABSTRACTION_ARRAY[] = {'d', 'e', 's', 't', 'r', 'o', 'y', '_', 's', 't', 'a', 't', 'i', 'c', 's'};

/** The destroy model abstraction. */
static const char* DESTROY_MODEL_ABSTRACTION = DESTROY_MODEL_ABSTRACTION_ARRAY;

/** The destroy model abstraction count. */
static const int DESTROY_MODEL_ABSTRACTION_COUNT = 15;

//
// Input output abstractions.
//

/** The send abstraction array. */
static const char SEND_ABSTRACTION_ARRAY[] = {'s', 'e', 'n', 'd'};

/** The send abstraction. */
static const char* SEND_ABSTRACTION = SEND_ABSTRACTION_ARRAY;

/** The send abstraction count. */
static const int SEND_ABSTRACTION_COUNT = 4;

/** The receive abstraction array. */
static const char RECEIVE_ABSTRACTION_ARRAY[] = {'r', 'e', 'c', 'e', 'i', 'v', 'e'};

/** The receive abstraction. */
static const char* RECEIVE_ABSTRACTION = RECEIVE_ABSTRACTION_ARRAY;

/** The receive abstraction count. */
static const int RECEIVE_ABSTRACTION_COUNT = 7;

//
// Lifecycle step abstractions.
//

/** The exit abstraction array. */
static const char EXIT_ABSTRACTION_ARRAY[] = {'e', 'x', 'i', 't'};

/** The exit abstraction. */
static const char* EXIT_ABSTRACTION = EXIT_ABSTRACTION_ARRAY;

/** The exit abstraction count. */
static const int EXIT_ABSTRACTION_COUNT = 4;

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

//
// Cybol location values:
// - model locations
// - location separators
//

//
// Model locations.
//

/** The inline location array. */
static const char INLINE_LOCATION_ARRAY[] = {'i', 'n', 'l', 'i', 'n', 'e'};

/** The inline location. */
static const char* INLINE_LOCATION = INLINE_LOCATION_ARRAY;

/** The inline location count. */
static const int INLINE_LOCATION_COUNT = 6;

/** The file location array. */
static const char FILE_LOCATION_ARRAY[] = {'f', 'i', 'l', 'e'};

/** The file location. */
static const char* FILE_LOCATION = FILE_LOCATION_ARRAY;

/** The file location count. */
static const int FILE_LOCATION_COUNT = 4;

/** The http location array. */
static const char HTTP_LOCATION_ARRAY[] = {'h', 't', 't', 'p'};

/** The http location. */
static const char* HTTP_LOCATION = HTTP_LOCATION_ARRAY;

/** The http location count. */
static const int HTTP_LOCATION_COUNT = 4;

/** The ftp location array. */
static const char FTP_LOCATION_ARRAY[] = {'f', 't', 'p'};

/** The ftp location. */
static const char* FTP_LOCATION = FTP_LOCATION_ARRAY;

/** The ftp location count. */
static const int FTP_LOCATION_COUNT = 3;

//
// Location separators.
//

/** The model location separator array. */
static const char MODEL_LOCATION_SEPARATOR_ARRAY[] = {':'};

/** The model location separator. */
static const char* MODEL_LOCATION_SEPARATOR = MODEL_LOCATION_SEPARATOR_ARRAY;

/** The model location separator count. */
static const int MODEL_LOCATION_SEPARATOR_COUNT = 1;

//
// Cybol model values:
// - model separators
// - boolean
//

//
// Model separators.
//

/** The operation parameter separator. */
static const char OPERATION_PARAMETER_SEPARATOR = ',';

/** The model part separator. */
static const char MODEL_PART_SEPARATOR = '.';

//
// Boolean.
//

/** The true boolean array. */
static const char TRUE_BOOLEAN_ARRAY[] = {'t', 'r', 'u', 'e'};

/** The true boolean. */
static const char* TRUE_BOOLEAN = TRUE_BOOLEAN_ARRAY;

/** The true boolean count. */
static const int TRUE_BOOLEAN_COUNT = 4;

/** The false boolean array. */
static const char FALSE_BOOLEAN_ARRAY[] = {'f', 'a', 'l', 's', 'e'};

/** The false boolean. */
static const char* FALSE_BOOLEAN = FALSE_BOOLEAN_ARRAY;

/** The false boolean count. */
static const int FALSE_BOOLEAN_COUNT = 5;

//
// Logging:
// - log levels
// - log level names
// - log messages
//

//
// Log levels.
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
// Log level names.
//

/** The error log level name array. */
static const char ERROR_LOG_LEVEL_NAME_ARRAY[] = {'E', 'r', 'r', 'o', 'r'};

/** The error log level name. */
static const char* ERROR_LOG_LEVEL_NAME = ERROR_LOG_LEVEL_NAME_ARRAY;

/** The error log level name count. */
static const int ERROR_LOG_LEVEL_NAME_COUNT = 5;

/** The warning log level name array. */
static const char WARNING_LOG_LEVEL_NAME_ARRAY[] = {'W', 'a', 'r', 'n', 'i', 'n', 'g'};

/** The warning log level name. */
static const char* WARNING_LOG_LEVEL_NAME = WARNING_LOG_LEVEL_NAME_ARRAY;

/** The warning log level name count. */
static const int WARNING_LOG_LEVEL_NAME_COUNT = 7;

/** The info log level name array. */
static const char INFO_LOG_LEVEL_NAME_ARRAY[] = {'I', 'n', 'f', 'o'};

/** The info log level name. */
static const char* INFO_LOG_LEVEL_NAME = INFO_LOG_LEVEL_NAME_ARRAY;

/** The info log level name count. */
static const int INFO_LOG_LEVEL_NAME_COUNT = 4;

//
// Logger log messages.
//

//
// Pointer array log messages.
//

/** The "Create pointer array." message array. */
static const char CREATE_POINTER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create pointer array." message. */
static const char* CREATE_POINTER_ARRAY_MESSAGE = CREATE_POINTER_ARRAY_MESSAGE_ARRAY;

/** The "Create pointer array." message count. */
static const int CREATE_POINTER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create pointer array. The array is null." message array. */
static const char COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create pointer array. The array is null." message. */
static const char* COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create pointer array. The array is null." message count. */
static const int COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create pointer array. The count is null." message array. */
static const char COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create pointer array. The count is null." message. */
static const char* COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create pointer array. The count is null." message count. */
static const int COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy pointer array." message array. */
static const char DESTROY_POINTER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy pointer array." message. */
static const char* DESTROY_POINTER_ARRAY_MESSAGE = DESTROY_POINTER_ARRAY_MESSAGE_ARRAY;

/** The "Destroy pointer array." message count. */
static const int DESTROY_POINTER_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy pointer array. The array is null." message array. */
static const char COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy pointer array. The array is null." message. */
static const char* COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy pointer array. The array is null." message count. */
static const int COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy pointer array. The count is null." message array. */
static const char COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy pointer array. The count is null." message. */
static const char* COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy pointer array. The count is null." message count. */
static const int COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize pointer array." message array. */
static const char RESIZE_POINTER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize pointer array." message. */
static const char* RESIZE_POINTER_ARRAY_MESSAGE = RESIZE_POINTER_ARRAY_MESSAGE_ARRAY;

/** The "Resize pointer array." message count. */
static const int RESIZE_POINTER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize pointer array. The array is null." message array. */
static const char COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize pointer array. The array is null." message. */
static const char* COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize pointer array. The array is null." message count. */
static const int COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize pointer array. The count is null." message array. */
static const char COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize pointer array. The count is null." message. */
static const char* COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize pointer array. The count is null." message count. */
static const int COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare pointer array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare pointer array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare pointer array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare pointer array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set pointer array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set pointer array elements. The index is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The index is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The index is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set pointer array elements. The source array is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The source array is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The source array is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set pointer array elements. The count is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The count is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The count is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove pointer array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove pointer array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove pointer array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove pointer array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get pointer array elements. The source array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The source array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The source array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get pointer array elements. The index is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The index is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The index is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get pointer array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get pointer array elements. The count is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The count is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The count is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get pointer array element index. The array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get pointer array element index. The size is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The size is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The size is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get pointer array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get pointer array element index. The count is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The count is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The count is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get pointer array element index. The index is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The index is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The index is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Integer array log messages.
//

/** The "Create integer array." message array. */
static const char CREATE_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create integer array." message. */
static const char* CREATE_INTEGER_ARRAY_MESSAGE = CREATE_INTEGER_ARRAY_MESSAGE_ARRAY;

/** The "Create integer array." message count. */
static const int CREATE_INTEGER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create integer array. The array is null." message array. */
static const char COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create integer array. The array is null." message. */
static const char* COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create integer array. The array is null." message count. */
static const int COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create integer array. The count is null." message array. */
static const char COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create integer array. The count is null." message. */
static const char* COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create integer array. The count is null." message count. */
static const int COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy integer array." message array. */
static const char DESTROY_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy integer array." message. */
static const char* DESTROY_INTEGER_ARRAY_MESSAGE = DESTROY_INTEGER_ARRAY_MESSAGE_ARRAY;

/** The "Destroy integer array." message count. */
static const int DESTROY_INTEGER_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy integer array. The array is null." message array. */
static const char COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy integer array. The array is null." message. */
static const char* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy integer array. The array is null." message count. */
static const int COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy integer array. The count is null." message array. */
static const char COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy integer array. The count is null." message. */
static const char* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy integer array. The count is null." message count. */
static const int COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize integer array." message array. */
static const char RESIZE_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize integer array." message. */
static const char* RESIZE_INTEGER_ARRAY_MESSAGE = RESIZE_INTEGER_ARRAY_MESSAGE_ARRAY;

/** The "Resize integer array." message count. */
static const int RESIZE_INTEGER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize integer array. The array is null." message array. */
static const char COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize integer array. The array is null." message. */
static const char* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize integer array. The array is null." message count. */
static const int COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize integer array. The count is null." message array. */
static const char COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize integer array. The count is null." message. */
static const char* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize integer array. The count is null." message count. */
static const int COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare integer array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare integer array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare integer array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare integer array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set integer array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set integer array elements. The index is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The index is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The index is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set integer array elements. The source array is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The source array is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The source array is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set integer array elements. The count is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The count is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The count is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove integer array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove integer array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove integer array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove integer array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get integer array elements. The source array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The source array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The source array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get integer array elements. The index is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The index is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The index is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get integer array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get integer array elements. The count is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The count is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The count is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get integer array element index. The array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get integer array element index. The size is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The size is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The size is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get integer array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get integer array element index. The count is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The count is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The count is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get integer array element index. The index is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The index is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The index is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Character array log messages.
//

/** The "Create character array." message array. */
static const char CREATE_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create character array." message. */
static const char* CREATE_CHARACTER_ARRAY_MESSAGE = CREATE_CHARACTER_ARRAY_MESSAGE_ARRAY;

/** The "Create character array." message count. */
static const int CREATE_CHARACTER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create character array. The array is null." message array. */
static const char COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create character array. The array is null." message. */
static const char* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create character array. The array is null." message count. */
static const int COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create character array. The count is null." message array. */
static const char COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create character array. The count is null." message. */
static const char* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create character array. The count is null." message count. */
static const int COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy character array." message array. */
static const char DESTROY_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy character array." message. */
static const char* DESTROY_CHARACTER_ARRAY_MESSAGE = DESTROY_CHARACTER_ARRAY_MESSAGE_ARRAY;

/** The "Destroy character array." message count. */
static const int DESTROY_CHARACTER_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy character array. The array is null." message array. */
static const char COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy character array. The array is null." message. */
static const char* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy character array. The array is null." message count. */
static const int COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy character array. The count is null." message array. */
static const char COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy character array. The count is null." message. */
static const char* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy character array. The count is null." message count. */
static const int COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize character array." message array. */
static const char RESIZE_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize character array." message. */
static const char* RESIZE_CHARACTER_ARRAY_MESSAGE = RESIZE_CHARACTER_ARRAY_MESSAGE_ARRAY;

/** The "Resize character array." message count. */
static const int RESIZE_CHARACTER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize character array. The array is null." message array. */
static const char COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize character array. The array is null." message. */
static const char* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize character array. The array is null." message count. */
static const int COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize character array. The count is null." message array. */
static const char COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize character array. The count is null." message. */
static const char* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize character array. The count is null." message count. */
static const int COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare character array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare character array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare character array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare character array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set character array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set character array elements. The index is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The index is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The index is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set character array elements. The source array is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The source array is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The source array is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set character array elements. The count is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The count is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The count is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove character array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove character array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove character array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove character array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get character array elements. The source array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The source array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The source array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get character array elements. The index is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The index is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The index is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get character array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get character array elements. The count is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The count is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The count is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get character array element index. The array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get character array element index. The size is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The size is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The size is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get character array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get character array element index. The count is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The count is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The count is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get character array element index. The index is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The index is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The index is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Double array log messages.
//

/** The "Create double array." message array. */
static const char CREATE_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create double array." message. */
static const char* CREATE_DOUBLE_ARRAY_MESSAGE = CREATE_DOUBLE_ARRAY_MESSAGE_ARRAY;

/** The "Create double array." message count. */
static const int CREATE_DOUBLE_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create double array. The array is null." message array. */
static const char COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create double array. The array is null." message. */
static const char* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create double array. The array is null." message count. */
static const int COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create double array. The count is null." message array. */
static const char COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create double array. The count is null." message. */
static const char* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create double array. The count is null." message count. */
static const int COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy double array." message array. */
static const char DESTROY_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy double array." message. */
static const char* DESTROY_DOUBLE_ARRAY_MESSAGE = DESTROY_DOUBLE_ARRAY_MESSAGE_ARRAY;

/** The "Destroy double array." message count. */
static const int DESTROY_DOUBLE_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy double array. The array is null." message array. */
static const char COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy double array. The array is null." message. */
static const char* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy double array. The array is null." message count. */
static const int COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy double array. The count is null." message array. */
static const char COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy double array. The count is null." message. */
static const char* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy double array. The count is null." message count. */
static const int COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize double array." message array. */
static const char RESIZE_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize double array." message. */
static const char* RESIZE_DOUBLE_ARRAY_MESSAGE = RESIZE_DOUBLE_ARRAY_MESSAGE_ARRAY;

/** The "Resize double array." message count. */
static const int RESIZE_DOUBLE_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize double array. The array is null." message array. */
static const char COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize double array. The array is null." message. */
static const char* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize double array. The array is null." message count. */
static const int COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize double array. The count is null." message array. */
static const char COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize double array. The count is null." message. */
static const char* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize double array. The count is null." message count. */
static const int COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare double array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare double array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare double array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare double array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set double array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set double array elements. The index is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The index is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The index is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set double array elements. The source array is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The source array is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The source array is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set double array elements. The count is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The count is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The count is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove double array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove double array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove double array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove double array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get double array elements. The source array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The source array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The source array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get double array elements. The index is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The index is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The index is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get double array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get double array elements. The count is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The count is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The count is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get double array element index. The array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get double array element index. The size is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The size is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The size is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get double array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get double array element index. The count is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The count is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The count is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get double array element index. The index is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The index is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The index is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Array log messages.
//

/** The "Could not create array. The type is null." message array. */
static const char COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create array. The type is null." message. */
static const char* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create array. The type is null." message count. */
static const int COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = 41;

/** The "Could not destroy array. The type is null." message array. */
static const char COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy array. The type is null." message. */
static const char* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy array. The type is null." message count. */
static const int COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = 42;

/** The "Could not resize array. The type is null." message array. */
static const char COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize array. The type is null." message. */
static const char* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize array. The type is null." message count. */
static const int COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = 41;

/** The "Could not compare array elements. The type is null." message array. */
static const char COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare array elements. The type is null." message. */
static const char* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare array elements. The type is null." message count. */
static const int COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not set array elements. The type is null." message array. */
static const char COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set array elements. The type is null." message. */
static const char* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set array elements. The type is null." message count. */
static const int COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 47;

/** The "Could not remove array elements. The type is null." message array. */
static const char COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove array elements. The type is null." message. */
static const char* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove array elements. The type is null." message count. */
static const int COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not get array elements. The type is null." message array. */
static const char COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get array elements. The type is null." message. */
static const char* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get array elements. The type is null." message count. */
static const int COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 47;

/** The "Could not get array elements index. The type is null." message array. */
static const char COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get array elements index. The type is null." message. */
static const char* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get array elements index. The type is null." message count. */
static const int COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_COUNT = 53;

//
// File log messages.
//

/*??
"Read file."
"Could not read file. The file is null."
"Could not read file. The array size is null."
"Could not read file. The array count is null."
"Could not read file. The file name count is null."
//?? copy the same for write, plus:
"Could not write file. A write error occured."
*/

//
// Cybol log messages.
//

//
// Boolean log messages.
//

/*??
"Initialize boolean."
"Could not initialize boolean. The transient model is null."
"Could not initialize boolean. The persistent model count is null."
"Finalize boolean."
"Could not finalize boolean. The transient model is null."
"Could not finalize boolean. The persistent model is null."
"Could not finalize boolean. The persistent model count is null."
*/

//
// Integer log messages.
//

/*??
"Initialize integer."
"Finalize integer."
*/

//
// Fraction log messages.
//

/*??
"Create fraction."
"Destroy fraction."
"Initialize fraction."
"Finalize fraction."
*/

//
// Vector log messages.
//

/*??
"Create vector."
"Destroy vector."
"Initialize vector."
"Finalize vector."
*/

//
// Time log messages.
//

/*??
"Create time."
"Destroy time."
"Initialize time."
"Finalize time."
*/

//
// Double log messages.
//

/*??
"Initialize double."
"Finalize double."
*/

//
// Complex log messages.
//

/*??
"Create complex."
"Destroy complex."
"Initialize complex."
"Finalize complex."
*/

//
// String log messages.
//

/*??
"Initialize string."
"Could not initialize string. The transient model is null."
"Could not initialize string. The transient model count is null."
"Could not initialize string. The persistent model is null."
"Could not initialize string. The persistent model count is null."

//?? copy the same 5 lines for finalize string!
*/

//
// Operation log messages.
//

/*??
"Create operation."
"Destroy operation."
"Initialize operation."
"Could not initialize operation. There are no remaining parameters after the separator."
"Could not initialize operation. The index exceeds the count."
"Could not initialize operation. There is no parameter before the separator."
"Could not initialize operation. The transient model is null."
"Could not initialize operation. The transient model count is null."
"Could not initialize operation. The persistent model is null."
"Could not initialize operation. The persistent model count is null."

//?? copy the same 8 lines for finalize operation!
*/

//
// Compound log messages.
//

/*??
"Create compound."
"Destroy compound."
"Get model part index."
"Could not get model part index. The name size is null."
"Could not get model part index. The index is null."
"Set model part by index."
"Could not set model part by index. The index exceeds the size."
"Could not set model part by index. The index is negativ."
"Could not set model part by index. The index is null."
"Could not set model part by name. A part with that name does not exist."
"Could not set model part by name. The full name ends with a separator."
"Could not set model part by name. The full name starts with a separator."
"Could not set model part by name. The separator index exceeds the full name size."
"Could not set model part by name. The separator index is negative."
"Could not set model part by name. The name is null."
"Could not set model part by name. The name size is null."
"Set model part by name."
"Add model part by name."
"Remove model part by index."
"Could not remove model part by index. The index exceeds the size."
"Could not remove model part by index. The index is negativ."
"Could not remove model part by index. The index is null."
"Could not remove model part by name. A part with that name does not exist."
"Could not remove model part by name. The full name ends with a separator."
"Could not remove model part by name. The full name starts with a separator."
"Could not remove model part by name. The separator index exceeds the full name size."
"Could not remove model part by name. The separator index is negative."
"Could not remove model part by name. The name is null."
"Could not remove model part by name. The name size is null."
"Remove model part by name."
"Could not remove model part by name. A part with that name does not exist."
"Get model part by index."
"Could not get model part by index. The index exceeds the size."
"Could not get model part by index. The index is negativ."
"Could not get model part by index. The index is null."
"Could not get model part by name. A part with that name does not exist."
"Could not get model part by name. The full name ends with a separator."
"Could not get model part by name. The full name starts with a separator."
"Could not get model part by name. The separator index exceeds the full name size."
"Could not get model part by name. The separator index is negative."
"Could not get model part by name. The name is null."
"Could not get model part by name. The name size is null."
"Get model part by name."
"Could not get model part by name. A part with that name does not exist."
*/

//
// Create model log messages.
//

/*??
"Could not read model. The location count is null."
"Could not interpret model. The persistent model count is null."
"Could not interpret model. The abstraction count is null."
*/

//
// Destroy model log messages.
//

/*??
"Could not write model. The location count is null."
"Could not serialize model. The persistent model count is null."
"Could not serialize model. The abstraction count is null."
*/

//
// Add log messages.
//

//
// Signal memory log messages.
//

/*??
"Create signal memory."
"Destroy signal memory."
"Could not set signal. The index exceeds the size."
"Could not set signal. The index is negativ."
"Could not remove signal. The index exceeds the count."
"Could not remove signal. The index is negativ."
"Could not remove signal. The index is null."
"Could not get signal. The index exceeds the count."
"Could not get signal. The index is negativ."
"Could not get signal. The index is null."
"Could not get highest priority index. The index is null."
"Handle compound signal."
"Handle operation signal."
"Set shutdown flag."
*/

//
// Internals log messages.
//

//
// Character screen log messages.
//

//
// X Windows log messages.
//

//
// Cyboi log messages.
//

/** The "Wait for signals." message array. */
static const char WAIT_FOR_SIGNALS_MESSAGE_ARRAY[] = {'W', 'a', 'i', 't', ' ', 'f', 'o', 'r', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', '.'};

/** The "Wait for signals." message. */
static const char* WAIT_FOR_SIGNALS_MESSAGE = WAIT_FOR_SIGNALS_MESSAGE_ARRAY;

/** The "Wait for signals." message count. */
static const int WAIT_FOR_SIGNALS_MESSAGE_COUNT = 17;

/** The "Could not handle signal. The signal abstraction is unknown." message array. */
static const char COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'h', 'a', 'n', 'd', 'l', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n', ' ', 'i', 's', ' ', 'u', 'n', 'k', 'n', 'o', 'w', 'n', '.'};

/** The "Could not handle signal. The signal abstraction is unknown." message. */
static const char* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE = COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_ARRAY;

/** The "Could not handle signal. The signal abstraction is unknown." message count. */
static const int COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT = 59;

/** The "Could not wait for signals. The internals is null." message array. */
static const char COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'w', 'a', 'i', 't', ' ', 'f', 'o', 'r', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', 's', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not wait for signals. The internals is null." message. */
static const char* COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE = COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_ARRAY;

/** The "Could not wait for signals. The internals is null." message count. */
static const int COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_COUNT = 50;

/** The "Exit CYBOI normally." message array. */
static const char EXIT_CYBOI_NORMALLY_MESSAGE_ARRAY[] = {'E', 'x', 'i', 't', ' ', 'C', 'Y', 'B', 'O', 'I', ' ', 'n', 'o', 'r', 'm', 'a', 'l', 'l', 'y', '.'};

/** The "Exit CYBOI normally." message. */
static const char* EXIT_CYBOI_NORMALLY_MESSAGE = EXIT_CYBOI_NORMALLY_MESSAGE_ARRAY;

/** The "Exit CYBOI normally." message count. */
static const int EXIT_CYBOI_NORMALLY_MESSAGE_COUNT = 20;

/** The "Could not execute CYBOI. The command line argument number is incorrect." message array. */
static const char COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'e', 'x', 'e', 'c', 'u', 't', 'e', ' ', 'C', 'Y', 'B', 'O', 'I', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'l', 'i', 'n', 'e', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'i', 's', ' ', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c', 't', '.'};

/** The "Could not execute CYBOI. The command line argument number is incorrect." message. */
static const char* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE = COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_ARRAY;

/** The "Could not execute CYBOI. The command line argument number is incorrect." message count. */
static const int COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT = 71;

/** The "Usage: " message array. */
static const char USAGE_MESSAGE_ARRAY[] = {'\n', 'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 's', 'i', 'g', 'n', 'a', 'l', '\n', 'E', 'x', 'a', 'm', 'p', 'l', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'c', 'y', 'b', 'o', 'p', '.', 's', 'a', 'm', 'p', 'l', 'e', '.', 'h', 'e', 'l', 'l', 'o', '_', 'w', 'o', 'r', 'l', 'd', '.', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 's', '.', 's', 't', 'a', 'r', 't', 'u', 'p'};

/** The "Usage: " message. */
static const char* USAGE_MESSAGE = USAGE_MESSAGE_ARRAY;

/** The "Usage: " message count. */
static const int USAGE_MESSAGE_COUNT = 77;

/** The "Could not execute CYBOI. The command line argument vector is null." message array. */
static const char COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'e', 'x', 'e', 'c', 'u', 't', 'e', ' ', 'C', 'Y', 'B', 'O', 'I', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'l', 'i', 'n', 'e', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', ' ', 'v', 'e', 'c', 't', 'o', 'r', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not execute CYBOI. The command line argument vector is null." message. */
static const char* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE = COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_ARRAY;

/** The "Could not execute CYBOI. The command line argument vector is null." message count. */
static const int COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT = 66;

/* CONSTANTS_SOURCE */
#endif
