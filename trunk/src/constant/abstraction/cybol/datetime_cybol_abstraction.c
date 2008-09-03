/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: datetime_cybol_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATETIME_CYBOL_ABSTRACTION_SOURCE
#define DATETIME_CYBOL_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_model.c"

//
// The CYBOL abstraction constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//
// Since the MIME standard does not offer media types for certain data,
// CYBOL had to invent new languages (media types), e.g. for dates, numbers etc.
// This is not meant to pollute the MIME standard, just to fill a gap!
// In case IANA adopts these extensions one day -- fine.
// If, however, other media type values replacing ours are proposed,
// we are open to adapt the CYBOL language specification accordingly.
//

//
// Date Time (calendar date and time formats).
//
// IANA media type: not defined
// Self-defined media type: datetime
// This media type is a CYBOL extension.
//

/**
 * The datetime/yyyy-mm-dd cybol abstraction.
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
static wchar_t YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'y', L'y', L'y', L'y', L'-', L'm', L'm', L'-', L'd', L'd'};
static wchar_t* YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION = YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_19_INTEGER_ARRAY;

/**
 * The datetime/hh-mm-ss cybol abstraction.
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
static wchar_t HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'h', L'h', L'-', L'm', L'm', L'-', L's', L's'};
static wchar_t* HH_MM_SS_DATETIME_CYBOL_ABSTRACTION = HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_17_INTEGER_ARRAY;

/**
 * The datetime/yyyymmddthhmmss cybol abstraction.
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
static wchar_t YYYYMMDDTHHMMSS_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'y', L'y', L'y', L'y', L'm', L'm', L'd', L'd', L't', L'h', L'h', L'm', L'm', L's', L's'};
static wchar_t* YYYYMMDDTHHMMSS_DATETIME_CYBOL_ABSTRACTION = YYYYMMDDTHHMMSS_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* YYYYMMDDTHHMMSS_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_24_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-hhmm cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_DATE_HHMM_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'h', L'h', L'm', L'm'};
static wchar_t* XDT_DATE_HHMM_DATETIME_CYBOL_ABSTRACTION = XDT_DATE_HHMM_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_DATE_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_22_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-hhmmhhmm cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_HHMMHHMM_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'h', L'h', L'm', L'm', L'h', L'h', L'm', L'm'};
static wchar_t* XDT_HHMMHHMM_DATETIME_CYBOL_ABSTRACTION = XDT_HHMMHHMM_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_HHMMHHMM_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_26_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-yymmnnn cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_YYMMNNN_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'y', L'y', L'm', L'm', L'n', L'n', L'n'};
static wchar_t* XDT_YYMMNNN_DATETIME_CYBOL_ABSTRACTION = XDT_YYMMNNN_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_YYMMNNN_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_25_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-ddmmyyyy cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION = XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_26_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-mmyy cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_MMYY_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'm', L'm', L'y', L'y'};
static wchar_t* XDT_MMYY_DATETIME_CYBOL_ABSTRACTION = XDT_MMYY_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_MMYY_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_22_INTEGER_ARRAY;

/**
 * The datetime/xdt-date-ddmmyyyyddmmyyyy cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_DDMMYYYYDDMMYYYY_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L'd', L'a', L't', L'e', L'-', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* XDT_DDMMYYYYDDMMYYYY_DATETIME_CYBOL_ABSTRACTION = XDT_DDMMYYYYDDMMYYYY_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_DDMMYYYYDDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_34_INTEGER_ARRAY;

/**
 * The datetime/xdt-time-hhmmss cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L't', L'i', L'm', L'e', L'-', L'h', L'h', L'm', L'm', L's', L's'};
static wchar_t* XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION = XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_24_INTEGER_ARRAY;

/**
 * The datetime/xdt-time-hhmm cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 */
static wchar_t XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'x', L'd', L't', L'-', L't', L'i', L'm', L'e', L'-', L'h', L'h', L'm', L'm'};
static wchar_t* XDT_HHMM_DATETIME_CYBOL_ABSTRACTION = XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT = NUMBER_22_INTEGER_ARRAY;

/* DATETIME_CYBOL_ABSTRACTION_SOURCE */
#endif
