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
 * @version $RCSfile: application_vnd_mime_abstraction.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef APPLICATION_VND_MIME_ABSTRACTION_SOURCE
#define APPLICATION_VND_MIME_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
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
static wchar_t MS_EXCEL_APPLICATION_VND_MIME_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'v', L'n', L'd', L'.', L'm', L's', L'-', L'e', L'x', L'c', L'e', L'l'};
static wchar_t* MS_EXCEL_APPLICATION_VND_MIME_ABSTRACTION = MS_EXCEL_APPLICATION_VND_MIME_ABSTRACTION_ARRAY;
static int* MS_EXCEL_APPLICATION_VND_MIME_ABSTRACTION_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/*??
application/vnd.ms-powerpoint: Microsoft Powerpoint files
application/msword: Microsoft Word files
application/vnd.mozilla.xul+xml: Mozilla XUL files
*/

/* APPLICATION_VND_MIME_ABSTRACTION_SOURCE */
#endif
