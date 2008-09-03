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
 * @version $RCSfile: multipart_cybol_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MULTIPART_CYBOL_ABSTRACTION_SOURCE
#define MULTIPART_CYBOL_ABSTRACTION_SOURCE

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
// Multipart (archives and other objects made of more than one part).
//
// IANA media type: multipart
//

/**
 * The multipart/mixed cybol abstraction.
 *
 * multipart/mixed: MIME E-mail; Defined in RFC 2045 and RFC 2046
 */
static wchar_t MIXED_MULTIPART_CYBOL_ABSTRACTION_ARRAY[] = {L'm', L'u', L'l', L't', L'i', L'p', L'a', L'r', L't', L'/', L'm', L'i', L'x', L'e', L'd'};
static wchar_t* MIXED_MULTIPART_CYBOL_ABSTRACTION = MIXED_MULTIPART_CYBOL_ABSTRACTION_ARRAY;
static int* MIXED_MULTIPART_CYBOL_ABSTRACTION_COUNT = NUMBER_15_INTEGER_ARRAY;

/*??
multipart/alternative: MIME E-mail; Defined in RFC 2045 and RFC 2046
multipart/related: MIME E-mail; Defined in RFC 2387 and used by MHTML (HTML mail)
multipart/form-data: MIME Webform; Defined in RFC 2388
*/

/* MULTIPART_CYBOL_ABSTRACTION_SOURCE */
#endif
