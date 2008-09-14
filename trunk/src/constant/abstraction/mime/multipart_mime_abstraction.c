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
 * @version $RCSfile: multipart_mime_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MULTIPART_MIME_ABSTRACTION_SOURCE
#define MULTIPART_MIME_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
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
static wchar_t MIXED_MULTIPART_MIME_ABSTRACTION_ARRAY[] = {L'm', L'u', L'l', L't', L'i', L'p', L'a', L'r', L't', L'/', L'm', L'i', L'x', L'e', L'd'};
static wchar_t* MIXED_MULTIPART_MIME_ABSTRACTION = MIXED_MULTIPART_MIME_ABSTRACTION_ARRAY;
static int* MIXED_MULTIPART_MIME_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/*??
multipart/alternative: MIME E-mail; Defined in RFC 2045 and RFC 2046
multipart/related: MIME E-mail; Defined in RFC 2387 and used by MHTML (HTML mail)
multipart/form-data: MIME Webform; Defined in RFC 2388
*/

/* MULTIPART_MIME_ABSTRACTION_SOURCE */
#endif
