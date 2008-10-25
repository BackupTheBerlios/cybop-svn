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
 * @version $RCSfile: application_cybol_abstraction.c,v $ $Revision: 1.4 $ $Date: 2008-10-25 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef APPLICATION_CYBOL_ABSTRACTION_SOURCE
#define APPLICATION_CYBOL_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

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
 * The application/pdf cybol abstraction.
 */
static wchar_t PDF_APPLICATION_CYBOL_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'p', L'd', L'f'};
static wchar_t* PDF_APPLICATION_CYBOL_ABSTRACTION = PDF_APPLICATION_CYBOL_ABSTRACTION_ARRAY;
static int* PDF_APPLICATION_CYBOL_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The application/zip cybol abstraction.
 *
 * ZIP archive files.
 * Registered.
 * Suffixes: zip
 */
static wchar_t ZIP_APPLICATION_CYBOL_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'z', L'i', L'p'};
static wchar_t* ZIP_APPLICATION_CYBOL_ABSTRACTION = ZIP_APPLICATION_CYBOL_ABSTRACTION_ARRAY;
static int* ZIP_APPLICATION_CYBOL_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The application/xhtml+xml cybol abstraction.
 *
 * XHTML archive files. Defined by RFC 3236.
 * Registered.
 * Suffixes: xhtml
 */
static wchar_t XHTML_APPLICATION_CYBOL_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'h', L't', L'm', L'l'};
static wchar_t* XHTML_APPLICATION_CYBOL_ABSTRACTION = XHTML_APPLICATION_CYBOL_ABSTRACTION_ARRAY;
static int* XHTML_APPLICATION_CYBOL_ABSTRACTION_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/*??
application/xml-dtd: DTD files; Defined by RFC 3023
*/

/* APPLICATION_CYBOL_ABSTRACTION_SOURCE */
#endif
