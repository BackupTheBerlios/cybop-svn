/*
 * $RCSfile: cybol_language_constants.c,v $
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
 * along with this program; if not, write tthe Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.1 $ $Date: 2008-07-11 23:14:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_LANGUAGE_CONSTANTS_SOURCE
#define CYBOL_LANGUAGE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// The following constants are called "languages", because they
// are used to represent and exchange data in a special format.
//
// An earlier version of CYBOL called these "abstractions".
//
// The constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//

//
// Application (multi-purpose).
//
// IANA media type: application
//

/*??
application/EDI-X12: EDI X12 data; Defined in RFC 1767
application/EDIFACT: EDI EDIFACT data; Defined in RFC 1767
application/javascript: JavaScript; Defined in RFC 4329
application/json: JavaScript Object Notation JSON; Defined in RFC 4627
application/octet-stream: Arbitrary byte stream. This is thought of as the "default" media type used by several operating systems, often used tidentify executable files, files of unknown type, or files that should be downloaded in protocols that dnot provide a separate "content disposition" header. RFC 2046 specifies this as the fallback for unrecognized subtypes of other types.
application/ogg: Ogg, a multimedia bitstream container format; Defined in RFC 3534
*/

/**
 * The application/zip language.
 *
 * ZIP archive files.
 * Registered.
 * Suffixes: zip
 */
static wchar_t APPLICATION_ZIP_LANGUAGE_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'z', L'i', L'p'};
static wchar_t* APPLICATION_ZIP_LANGUAGE = APPLICATION_ZIP_LANGUAGE_ARRAY;
static int* APPLICATION_ZIP_LANGUAGE_COUNT = NUMBER_15_INTEGER_ARRAY;

/*??
application/xhtml+xml: XHTML; Defined by RFC 3236
application/xml-dtd: DTD files; Defined by RFC 3023
*/

//
// Application (vendor-specific).
//
// IANA media type: application/vnd.
//

/**
 * The application/vnd.ms-excel language.
 *
 * Microsoft Excel files.
 * Suffixes: xls, xla
 */
static wchar_t APPLICATION_VND_MS_EXCEL_LANGUAGE_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'v', L'n', L'd', L'.', L'm', L's', L'-', L'e', L'x', L'c', L'e', L'l'};
static wchar_t* APPLICATION_VND_MS_EXCEL_LANGUAGE = APPLICATION_VND_MS_EXCEL_LANGUAGE_ARRAY;
static int* APPLICATION_VND_MS_EXCEL_LANGUAGE_COUNT = NUMBER_24_INTEGER_ARRAY;

/*??
application/vnd.ms-powerpoint: Microsoft Powerpoint files
application/msword: Microsoft Word files
application/vnd.mozilla.xul+xml: Mozilla XUL files
*/

//
// Application (non-standard).
//
// IANA media type: application/x-
//

/*??
application/x-dvi: Digital Videfiles in DVI format
application/x-httpd-php: PHP files
application/x-httpd-php-source: PHP source files
application/x-latex: LATEX files
application/x-shockwave-flash: Adobe Flash files; Documented in Adobe TechNote tn_4151 and Adobe TechNote tn_16509
application/x-stuffit: StuffIt archive files
application/x-rar-compressed: RAR archive files
*/

/**
 * The application/x-tar language.
 *
 * Tarball files.
 * Suffixes: tar
 */
static wchar_t APPLICATION_X_TAR_LANGUAGE_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'a', L'r'};
static wchar_t* APPLICATION_X_TAR_LANGUAGE = APPLICATION_X_TAR_LANGUAGE_ARRAY;
static int* APPLICATION_X_TAR_LANGUAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

//
// Audio.
//
// IANA media type: audio
//

/**
 * The audio/mpeg language.
 *
 * MP3 or other MPEG audio.
 * Defined in RFC 3003.
 * Suffixes: mpeg
 */
static wchar_t AUDIO_MPEG_LANGUAGE_ARRAY[] = {L'a', L'u', L'd', L'i', L'o', L'/', L'm', L'p', L'e', L'g'};
static wchar_t* AUDIO_MPEG_LANGUAGE = AUDIO_MPEG_LANGUAGE_ARRAY;
static int* AUDIO_MPEG_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/*??
audio/x-ms-wma: Windows Media Audio; Documented in Microsoft KB 288102
audio/vnd.rn-realaudio: RealAudio; Documented in RealPlayer Customer Support Answer 2559
audio/x-wav: WAV audio
*/

//
// Character (quality formats).
//
// IANA media type: not defined
// Self-defined media type: character
// This media type is a CYBOL extension.
//

/**
 * The character/plain language.
 *
 * Plain character (usually represented by 1 Byte in memory).
 *
 * This is a CYBOL extension.
 */
static wchar_t CHARACTER_PLAIN_LANGUAGE_ARRAY[] = {L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L'/', L'p', L'l', L'a', L'i', L'n'};
static wchar_t* CHARACTER_PLAIN_LANGUAGE = CHARACTER_PLAIN_LANGUAGE_ARRAY;
static int* CHARACTER_PLAIN_LANGUAGE_COUNT = NUMBER_15_INTEGER_ARRAY;

/**
 * The character/wide language.
 *
 * Wide character (usually represented by 4 Byte in memory).
 *
 * This is a CYBOL extension.
 */
static wchar_t CHARACTER_WIDE_LANGUAGE_ARRAY[] = {L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L'/', L'w', L'i', L'd', L'e'};
static wchar_t* CHARACTER_WIDE_LANGUAGE = CHARACTER_WIDE_LANGUAGE_ARRAY;
static int* CHARACTER_WIDE_LANGUAGE_COUNT = NUMBER_14_INTEGER_ARRAY;

//
// Colour (colour formats).
//
// IANA media type: not defined
// Self-defined media type: colour
// This media type is a CYBOL extension.
//

/**
 * The colour/cmyk language.
 *
 * Cyan, Magenta, Yellow, Key (black) (CMYK) colour model,
 * also referred to as "process color" or "four color".
 *
 * This is a CYBOL extension.
 */
static wchar_t COLOUR_CMYK_LANGUAGE_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L'c', L'm', L'y', L'k'};
static wchar_t* COLOUR_CMYK_LANGUAGE = COLOUR_CMYK_LANGUAGE_ARRAY;
static int* COLOUR_CMYK_LANGUAGE_COUNT = NUMBER_11_INTEGER_ARRAY;

/**
 * The colour/rgb language.
 *
 * Red, Green, Blue colour model.
 *
 * This is a CYBOL extension.
 */
static wchar_t COLOUR_RGB_LANGUAGE_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L'r', L'g', L'b'};
static wchar_t* COLOUR_RGB_LANGUAGE = COLOUR_RGB_LANGUAGE_ARRAY;
static int* COLOUR_RGB_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The colour/terminal-background language.
 *
 * Terminal background colour name as written word.
 *
 * This is a CYBOL extension.
 */
static wchar_t COLOUR_TERMINAL_BACKGROUND_LANGUAGE_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l', L'-', L'b', L'a', L'c', L'k', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* COLOUR_TERMINAL_BACKGROUND_LANGUAGE = COLOUR_TERMINAL_BACKGROUND_LANGUAGE_ARRAY;
static int* COLOUR_TERMINAL_BACKGROUND_LANGUAGE_COUNT = NUMBER_26_INTEGER_ARRAY;

/**
 * The colour/terminal-foreground language.
 *
 * Terminal foreground colour name as written word.
 *
 * This is a CYBOL extension.
 */
static wchar_t COLOUR_TERMINAL_FOREGROUND_LANGUAGE_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l', L'-', L'f', L'o', L'r', L'e', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* COLOUR_TERMINAL_FOREGROUND_LANGUAGE = COLOUR_TERMINAL_FOREGROUND_LANGUAGE_ARRAY;
static int* COLOUR_TERMINAL_FOREGROUND_LANGUAGE_COUNT = NUMBER_26_INTEGER_ARRAY;

//
// Date Time (calendar date and time formats).
//
// IANA media type: not defined
// Self-defined media type: datetime
// This media type is a CYBOL extension.
//

/**
 * The datetime/yyyy-mm-dd language.
 *
 * The international standard date notation is:
 * YYYY-MM-DD
 *
 * where:
 * - YYYY is the year in the usual Gregorian calendar
 * - MM is the month of the year between 01 (January) and 12 (December)
 * - DD is the day of the month between 01 and 31
 *
 * Example: The fourth day of February in the year 1995 is written as:
 * 1995-02-04
 *
 * Defined in ISO 8601.
 */
static wchar_t DATETIME_YYYY_MM_DD_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'y', L'y', L'y', L'y', L'-', L'm', L'm', L'-', L'd', L'd'};
static wchar_t* DATETIME_YYYY_MM_DD_LANGUAGE = DATETIME_YYYY_MM_DD_LANGUAGE_ARRAY;
static int* DATETIME_YYYY_MM_DD_LANGUAGE_COUNT = NUMBER_19_INTEGER_ARRAY;

/**
 * The datetime/hh-mm-ss language.
 *
 * The international standard time of day notation is:
 * hh:mm:ss
 *
 * where:
 * - hh is the number of complete hours that have passed since midnight (00-24)
 * - mm is the number of complete minutes that have passed since the start of the hour (00-59)
 * - ss is the number of complete seconds since the start of the minute (00-60)
 *
 * If the hour value is 24, then the minute and second values must be zero.
 *
 * Example: The time one second before midnight is written as:
 * 23:59:59
 *
 * Defined in ISO 8601.
 */
static wchar_t DATETIME_HH_MM_SS_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'h', L'h', L'-', L'm', L'm', L'-', L's', L's'};
static wchar_t* DATETIME_HH_MM_SS_LANGUAGE = DATETIME_HH_MM_SS_LANGUAGE_ARRAY;
static int* DATETIME_HH_MM_SS_LANGUAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

/**
 * The datetime/yyyymmddthhmmss language.
 *
 * If a date and a time are displayed on the same line,
 * then the date is always written in front of the time.
 * If a date and a time value are stored together in a single data field,
 * then ISO 8601 suggests that they should be separated by a latin capital letter T:
 * YYYYMMDDThhmmss
 *
 * Example: The fourth day of February in the year 1995 at the time one second before midnight is written as:
 * 19950204T235959
 *
 * Defined in ISO 8601.
 */
static wchar_t DATETIME_YYYYMMDDTHHMMSS_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'y', L'y', L'y', L'y', L'm', L'm', L'd', L'd', L't', L'h', L'h', L'm', L'm', L's', L's'};
static wchar_t* DATETIME_YYYYMMDDTHHMMSS_LANGUAGE = DATETIME_YYYYMMDDTHHMMSS_LANGUAGE_ARRAY;
static int* DATETIME_YYYYMMDDTHHMMSS_LANGUAGE_COUNT = NUMBER_24_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-hhmm language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_DATE_HHMM_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'h', L'h', L'm', L'm'};
static wchar_t* DATETIME_XDT_DATE_HHMM_LANGUAGE = DATETIME_XDT_DATE_HHMM_LANGUAGE_ARRAY;
static int* DATETIME_XDT_DATE_HHMM_LANGUAGE_COUNT = NUMBER_22_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-hhmmhhmm language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_DATE_HHMMHHMM_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'h', L'h', L'm', L'm', L'h', L'h', L'm', L'm'};
static wchar_t* DATETIME_XDT_DATE_HHMMHHMM_LANGUAGE = DATETIME_XDT_DATE_HHMMHHMM_LANGUAGE_ARRAY;
static int* DATETIME_XDT_DATE_HHMMHHMM_LANGUAGE_COUNT = NUMBER_26_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-yymmnnn language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_DATE_YYMMNNN_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'y', L'y', L'm', L'm', L'n', L'n', L'n'};
static wchar_t* DATETIME_XDT_DATE_YYMMNNN_LANGUAGE = DATETIME_XDT_DATE_YYMMNNN_LANGUAGE_ARRAY;
static int* DATETIME_XDT_DATE_YYMMNNN_LANGUAGE_COUNT = NUMBER_25_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-ddmmyyyy language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_DATE_DDMMYYYY_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* DATETIME_XDT_DATE_DDMMYYYY_LANGUAGE = DATETIME_XDT_DATE_DDMMYYYY_LANGUAGE_ARRAY;
static int* DATETIME_XDT_DATE_DDMMYYYY_LANGUAGE_COUNT = NUMBER_26_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-mmyy language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_DATE_MMYY_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'm', L'm', L'y', L'y'};
static wchar_t* DATETIME_XDT_DATE_MMYY_LANGUAGE = DATETIME_XDT_DATE_MMYY_LANGUAGE_ARRAY;
static int* DATETIME_XDT_DATE_MMYY_LANGUAGE_COUNT = NUMBER_22_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-ddmmyyyyddmmyyyy language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_DATE_DDMMYYYYDDMMYYYY_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* DATETIME_XDT_DATE_DDMMYYYYDDMMYYYY_LANGUAGE = DATETIME_XDT_DATE_DDMMYYYYDDMMYYYY_LANGUAGE_ARRAY;
static int* DATETIME_XDT_DATE_DDMMYYYYDDMMYYYY_LANGUAGE_COUNT = NUMBER_34_INTEGER_ARRAY;

/**
 * The datetime/xdt-time-hhmmss language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_TIME_HHMMSS_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L't', L'i', L'm', L'e', L'-', L'h', L'h', L'm', L'm', L's', L's'};
static wchar_t* DATETIME_XDT_TIME_HHMMSS_LANGUAGE = DATETIME_XDT_TIME_HHMMSS_LANGUAGE_ARRAY;
static int* DATETIME_XDT_TIME_HHMMSS_LANGUAGE_COUNT = NUMBER_24_INTEGER_ARRAY;

/**
 * The datetime/xdt-time-hhmm language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t DATETIME_XDT_TIME_HHMM_LANGUAGE_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L't', L'i', L'm', L'e', L'-', L'h', L'h', L'm', L'm'};
static wchar_t* DATETIME_XDT_TIME_HHMM_LANGUAGE = DATETIME_XDT_TIME_HHMM_LANGUAGE_ARRAY;
static int* DATETIME_XDT_TIME_HHMM_LANGUAGE_COUNT = NUMBER_22_INTEGER_ARRAY;

//
// Example.
//
// IANA media type: example
//

/**
 * The example language.
 *
 * This is just offered by IANA for testing reasons.
 */
static wchar_t EXAMPLE_LANGUAGE_ARRAY[] = {L'e', L'x', L'a', L'm', L'p', L'l', L'e'};
static wchar_t* EXAMPLE_LANGUAGE = EXAMPLE_LANGUAGE_ARRAY;
static int* EXAMPLE_LANGUAGE_COUNT = NUMBER_7_INTEGER_ARRAY;

//
// Image.
//
// IANA media type: image
//

/**
 * The image/gif language.
 *
 * GIF image.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: gif
 */
static wchar_t IMAGE_GIF_LANGUAGE_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L'g', L'i', L'f'};
static wchar_t* IMAGE_GIF_LANGUAGE = IMAGE_GIF_LANGUAGE_ARRAY;
static int* IMAGE_GIF_LANGUAGE_COUNT = NUMBER_9_INTEGER_ARRAY;

/**
 * The image/jpeg language.
 *
 * JPEG JFIF image.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: jpeg, jpg, jpe
 */
static wchar_t IMAGE_JPEG_LANGUAGE_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L'j', L'p', L'e', L'g'};
static wchar_t* IMAGE_JPEG_LANGUAGE = IMAGE_JPEG_LANGUAGE_ARRAY;
static int* IMAGE_JPEG_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The image/png language.
 *
 * Portable Network Graphics.
 * Registered.
 * Suffixes: png
 */
static wchar_t IMAGE_PNG_LANGUAGE_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L'p', L'n', L'g'};
static wchar_t* IMAGE_PNG_LANGUAGE = IMAGE_PNG_LANGUAGE_ARRAY;
static int* IMAGE_PNG_LANGUAGE_COUNT = NUMBER_9_INTEGER_ARRAY;

/**
 * The image/tiff language.
 *
 * Tag Image File Format.
 * Defined in RFC 3302.
 * Suffixes: tiff, tif
 */
static wchar_t IMAGE_TIFF_LANGUAGE_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L't', L'i', L'f', L'f'};
static wchar_t* IMAGE_TIFF_LANGUAGE = IMAGE_TIFF_LANGUAGE_ARRAY;
static int* IMAGE_TIFF_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/*??
The image/vnd.microsoft.icon language.
ICO image.
Registered.
*/

//
// Logic value.
//
// IANA media type: not defined
// Self-defined media type: logicvalue
// This media type is a CYBOL extension.
//

/**
 * The logicvalue/boolean language.
 *
 * Classical logic with the only possible truth values "true" and "false".
 *
 * This is a CYBOL extension.
 */
static wchar_t LOGICVALUE_BOOLEAN_LANGUAGE_ARRAY[] = {L'l', L'o', L'g', L'i', L'c', L'v', L'a', L'l', L'u', L'e', L'/', L'b', L'o', L'o', L'l', L'e', L'a', L'n'};
static wchar_t* LOGICVALUE_BOOLEAN_LANGUAGE = LOGICVALUE_BOOLEAN_LANGUAGE_ARRAY;
static int* LOGICVALUE_BOOLEAN_LANGUAGE_COUNT = NUMBER_18_INTEGER_ARRAY;

/*??
three-valued logic
fuzzy logic
*/

//
// Message.
//
// IANA media type: message
//

/**
 * The message/http language.
 *
 * An HTTP header message.
 */
static wchar_t MESSAGE_HTTP_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p'};
static wchar_t* MESSAGE_HTTP_LANGUAGE = MESSAGE_HTTP_LANGUAGE_ARRAY;
static int* MESSAGE_HTTP_LANGUAGE_COUNT = NUMBER_12_INTEGER_ARRAY;

/**
 * The message/http-request language.
 *
 * An HTTP request message.
 * This is a CYBOL extension.
 */
static wchar_t MESSAGE_HTTP_REQUEST_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p', L'-', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* MESSAGE_HTTP_REQUEST_LANGUAGE = MESSAGE_HTTP_REQUEST_LANGUAGE_ARRAY;
static int* MESSAGE_HTTP_REQUEST_LANGUAGE_COUNT = NUMBER_20_INTEGER_ARRAY;

/**
 * The message/http-response language.
 *
 * An HTTP response message.
 * This is a CYBOL extension.
 */
static wchar_t MESSAGE_HTTP_RESPONSE_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p', L'-', L'r', L'e', L's', L'p', L'o', L'n', L's', L'e'};
static wchar_t* MESSAGE_HTTP_RESPONSE_LANGUAGE = MESSAGE_HTTP_RESPONSE_LANGUAGE_ARRAY;
static int* MESSAGE_HTTP_RESPONSE_LANGUAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

//
// Model.
//
// IANA media type: model
//

/*??
VRML 3D model
*/

//
// Multipart (archives and other objects made of more than one part).
//
// IANA media type: multipart
//

/*??
multipart/mixed: MIME E-mail; Defined in RFC 2045 and RFC 2046
multipart/alternative: MIME E-mail; Defined in RFC 2045 and RFC 2046
multipart/related: MIME E-mail; Defined in RFC 2387 and used by MHTML (HTML mail)
multipart/form-data: MIME Webform; Defined in RFC 2388
*/

//
// Number (quantity formats).
//
// IANA media type: not defined
// Self-defined media type: number
// This media type is a CYBOL extension.
//

/**
 * The number/complex language.
 *
 * Complex number.
 *
 * This is a CYBOL extension.
 */
static wchar_t NUMBER_COMPLEX_LANGUAGE_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'c', L'o', L'm', L'p', L'l', L'e', L'x'};
static wchar_t* NUMBER_COMPLEX_LANGUAGE = NUMBER_COMPLEX_LANGUAGE_ARRAY;
static int* NUMBER_COMPLEX_LANGUAGE_COUNT = NUMBER_14_INTEGER_ARRAY;

/**
 * The number/double language.
 *
 * Double (floating point) number.
 *
 * This is a CYBOL extension.
 */
static wchar_t NUMBER_DOUBLE_LANGUAGE_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'd', L'o', L'u', L'b', L'l', L'e'};
static wchar_t* NUMBER_DOUBLE_LANGUAGE = NUMBER_DOUBLE_LANGUAGE_ARRAY;
static int* NUMBER_DOUBLE_LANGUAGE_COUNT = NUMBER_13_INTEGER_ARRAY;

/**
 * The number/fraction language.
 *
 * Fraction number consisting of numerator and denominator.
 *
 * This is a CYBOL extension.
 */
static wchar_t NUMBER_FRACTION_LANGUAGE_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'f', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* NUMBER_FRACTION_LANGUAGE = NUMBER_FRACTION_LANGUAGE_ARRAY;
static int* NUMBER_FRACTION_LANGUAGE_COUNT = NUMBER_15_INTEGER_ARRAY;

/**
 * The number/integer language.
 *
 * Integer number (integral data type).
 *
 * This is a CYBOL extension.
 */
static wchar_t NUMBER_INTEGER_LANGUAGE_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'i', L'n', L't', L'e', L'g', L'e', L'r'};
static wchar_t* NUMBER_INTEGER_LANGUAGE = NUMBER_INTEGER_LANGUAGE_ARRAY;
static int* NUMBER_INTEGER_LANGUAGE_COUNT = NUMBER_14_INTEGER_ARRAY;

/**
 * The number/pointer language.
 *
 * Pointer number. Usually represented as integer in memory.
 *
 * This is a CYBOL extension.
 */
static wchar_t NUMBER_POINTER_LANGUAGE_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'p', L'o', L'i', L'n', L't', L'e', L'r'};
static wchar_t* NUMBER_POINTER_LANGUAGE = NUMBER_POINTER_LANGUAGE_ARRAY;
static int* NUMBER_POINTER_LANGUAGE_COUNT = NUMBER_14_INTEGER_ARRAY;

/**
 * The number/unsigned-long language.
 *
 * Unsigned long number.
 *
 * This is a CYBOL extension.
 */
static wchar_t NUMBER_UNSIGNED_LONG_LANGUAGE_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L'-', L'l', L'o', L'n', L'g'};
static wchar_t* NUMBER_UNSIGNED_LONG_LANGUAGE = NUMBER_UNSIGNED_LONG_LANGUAGE_ARRAY;
static int* NUMBER_UNSIGNED_LONG_LANGUAGE_COUNT = NUMBER_20_INTEGER_ARRAY;

//
// Operation (some logic to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: operation
// This media type is a CYBOL extension.
//

/**
 * The operation/plain language.
 *
 * Operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t OPERATION_PLAIN_LANGUAGE_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'p', L'l', L'a', L'i', L'n'};
static wchar_t* OPERATION_PLAIN_LANGUAGE = OPERATION_PLAIN_LANGUAGE_ARRAY;
static int* OPERATION_PLAIN_LANGUAGE_COUNT = NUMBER_15_INTEGER_ARRAY;

//
// Path (parts in a knowledge tree accessed at runtime).
//
// IANA media type: not defined
// Self-defined media type: path
// This media type is a CYBOL extension.
//

/**
 * The path/knowledge language.
 *
 * A knowledge path pointing to an item of a knowledge tree, whereby:
 * - "part" tree node names are dot (.) separated
 * - "meta" tree node names are number sign (#) separated
 *
 * Defined in CYBOL specification:
 * http://cybop.berlios.de/books/cybol/cybol.pdf
 *
 * Example:
 * .application.gui.menu_bar.file_menu#background_colour
 * points to the meta property "background colour" of the
 * knowledge tree item ".application.gui.menu_bar.file_menu"
 */
static wchar_t PATH_KNOWLEDGE_LANGUAGE_ARRAY[] = {L'p', L'a', L't', L'h', L'/', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e'};
static wchar_t* PATH_KNOWLEDGE_LANGUAGE = PATH_KNOWLEDGE_LANGUAGE_ARRAY;
static int* PATH_KNOWLEDGE_LANGUAGE_COUNT = NUMBER_14_INTEGER_ARRAY;

/**
 * The path/encapsulated language.
 *
 * A knowledge path pointing to an item of a knowledge tree,
 * that contains a knowledge path.
 * In other words, the item pointed to just "wraps" or "encapsulates"
 * a knowledge path which in turn points to the actual item.
 *
 * Defined in CYBOL specification:
 * http://cybop.berlios.de/books/cybol/cybol.pdf
 *
 * The same rules as for the "path/knowledge" language apply here.
 */
static wchar_t PATH_ENCAPSULATED_KNOWLEDGE_LANGUAGE_ARRAY[] = {L'p', L'a', L't', L'h', L'/', L'e', L'n', L'c', L'a', L'p', L's', L'u', L'l', L'a', L't', L'e', L'd'};
static wchar_t* PATH_ENCAPSULATED_KNOWLEDGE_LANGUAGE = PATH_ENCAPSULATED_KNOWLEDGE_LANGUAGE_ARRAY;
static int* PATH_ENCAPSULATED_KNOWLEDGE_LANGUAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

//
// Text (human-readable text and source code).
//
// IANA media type: text
//

/**
 * The text/css language.
 *
 * Cascading Style Sheets.
 * Defined in RFC 2318.
 * Suffixes: css
 */
static wchar_t TEXT_CSS_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'c', L's', L's'};
static wchar_t* TEXT_CSS_LANGUAGE = TEXT_CSS_LANGUAGE_ARRAY;
static int* TEXT_CSS_LANGUAGE_COUNT = NUMBER_8_INTEGER_ARRAY;

/**
 * The text/cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://cybop.berlios.de/books/cybol/cybol.pdf
 * Suffixes: cybol
 */
static wchar_t TEXT_CYBOL_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'c', L'y', L'b', L'o', L'l'};
static wchar_t* TEXT_CYBOL_LANGUAGE = TEXT_CYBOL_LANGUAGE_ARRAY;
static int* TEXT_CYBOL_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The text/html language.
 *
 * Hypertext Markup Language (HTML) format.
 * Defined in RFC 2854.
 * Suffixes: html, htm, shtml
 */
static wchar_t TEXT_HTML_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'h', L't', L'm', L'l'};
static wchar_t* TEXT_HTML_LANGUAGE = TEXT_HTML_LANGUAGE_ARRAY;
static int* TEXT_HTML_LANGUAGE_COUNT = NUMBER_9_INTEGER_ARRAY;

/**
 * The text/hxp language.
 *
 * Healthcare Exchange Protocol (HXP) format.
 * An XML-based standard for medical data exchange.
 *
 * It was defined by a group of open source projects at:
 * http://hxp.sourceforge.net/
 * Suffixes: hxp (?? only assumed, not verified!)
 */
static wchar_t TEXT_HXP_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'h', L'x', L'p'};
static wchar_t* TEXT_HXP_LANGUAGE = TEXT_HXP_LANGUAGE_ARRAY;
static int* TEXT_HXP_LANGUAGE_COUNT = NUMBER_8_INTEGER_ARRAY;

/**
 * The text/model-diagram language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://cybop.berlios.de/books/cybol/cybol.pdf
 */
static wchar_t TEXT_MODEL_DIAGRAM_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'm', L'o', L'd', L'e', L'l', L'-', L'd', L'i', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* TEXT_MODEL_DIAGRAM_LANGUAGE = TEXT_MODEL_DIAGRAM_LANGUAGE_ARRAY;
static int* TEXT_MODEL_DIAGRAM_LANGUAGE_COUNT = NUMBER_18_INTEGER_ARRAY;

/**
 * The text/plain language.
 *
 * Textual data.
 * Defined in RFC 2046 and RFC 3676.
 * Suffixes: txt
 */
static wchar_t TEXT_PLAIN_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'p', L'l', L'a', L'i', L'n'};
static wchar_t* TEXT_PLAIN_LANGUAGE = TEXT_PLAIN_LANGUAGE_ARRAY;
static int* TEXT_PLAIN_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The text/xdt language.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: xdt, adt, bdt, gdt, ldt
 */
static wchar_t TEXT_XDT_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'x', L'd', L't'};
static wchar_t* TEXT_XDT_LANGUAGE = TEXT_XDT_LANGUAGE_ARRAY;
static int* TEXT_XDT_LANGUAGE_COUNT = NUMBER_8_INTEGER_ARRAY;

/**
 * The text/xml language.
 *
 * Extensible Markup Language.
 * Defined in RFC 3023.
 * Suffixes: xml
 */
static wchar_t TEXT_XML_LANGUAGE_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'x', L'm', L'l'};
static wchar_t* TEXT_XML_LANGUAGE = TEXT_XML_LANGUAGE_ARRAY;
static int* TEXT_XML_LANGUAGE_COUNT = NUMBER_8_INTEGER_ARRAY;

//
// Video.
//
// IANA media type: video
//

/**
 * The video/mp4 language.
 *
 * MP4 video.
 * Defined in RFC 4337.
 * Suffixes: mp4
 */
static wchar_t VIDEO_MP4_LANGUAGE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'm', L'p', L'4'};
static wchar_t* VIDEO_MP4_LANGUAGE = VIDEO_MP4_LANGUAGE_ARRAY;
static int* VIDEO_MP4_LANGUAGE_COUNT = NUMBER_9_INTEGER_ARRAY;

/**
 * The video/mpeg language.
 *
 * MPEG-1 videwith multiplexed audio.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: mpeg, mpg, mpe
 */
static wchar_t VIDEO_MPEG_LANGUAGE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'm', L'p', L'e', L'g'};
static wchar_t* VIDEO_MPEG_LANGUAGE = VIDEO_MPEG_LANGUAGE_ARRAY;
static int* VIDEO_MPEG_LANGUAGE_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The video/quicktime language.
 *
 * QuickTime video.
 * Registered.
 * Suffixes: qt, mov
 */
static wchar_t VIDEO_QUICKTIME_LANGUAGE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'q', L'u', L'i', L'c', L'k', L't', L'i', L'm', L'e'};
static wchar_t* VIDEO_QUICKTIME_LANGUAGE = VIDEO_QUICKTIME_LANGUAGE_ARRAY;
static int* VIDEO_QUICKTIME_LANGUAGE_COUNT = NUMBER_15_INTEGER_ARRAY;

/**
 * The video/x-ms-wmv language.
 *
 * Windows Media Video.
 * Documented in Microsoft KB 288102.
 * Suffixes: wmv
 */
static wchar_t VIDEO_X_MS_WMV_LANGUAGE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'x', L'-', L'm', L's', L'-', L'w', L'm', L'v'};
static wchar_t* VIDEO_X_MS_WMV_LANGUAGE = VIDEO_X_MS_WMV_LANGUAGE_ARRAY;
static int* VIDEO_X_MS_WMV_LANGUAGE_COUNT = NUMBER_14_INTEGER_ARRAY;

/* CYBOL_LANGUAGE_CONSTANTS_SOURCE */
#endif
