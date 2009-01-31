/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: application_vnd_cybol_abstraction.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef APPLICATION_VND_CYBOL_ABSTRACTION_SOURCE
#define APPLICATION_VND_CYBOL_ABSTRACTION_SOURCE

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
// Application (vendor-specific).
//
// IANA media type: application/vnd.
//

/**
 * The application/vnd.ms-excel cybol abstraction.
 *
 * Microsoft Excel files.
 * Suffixes: xls, xla
 */
static wchar_t MS_EXCEL_APPLICATION_VND_CYBOL_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'v', L'n', L'd', L'.', L'm', L's', L'-', L'e', L'x', L'c', L'e', L'l'};
static wchar_t* MS_EXCEL_APPLICATION_VND_CYBOL_ABSTRACTION = MS_EXCEL_APPLICATION_VND_CYBOL_ABSTRACTION_ARRAY;
static int* MS_EXCEL_APPLICATION_VND_CYBOL_ABSTRACTION_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/*??
application/vnd.ms-powerpoint: Microsoft Powerpoint files
application/msword: Microsoft Word files
application/vnd.mozilla.xul+xml: Mozilla XUL files
*/

/* APPLICATION_VND_CYBOL_ABSTRACTION_SOURCE */
#endif
