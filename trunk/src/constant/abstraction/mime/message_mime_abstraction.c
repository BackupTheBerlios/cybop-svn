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
 * @version $RCSfile: message_mime_abstraction.c,v $ $Revision: 1.2 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_MIME_ABSTRACTION_SOURCE
#define MESSAGE_MIME_ABSTRACTION_SOURCE

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
// Message.
//
// IANA media type: message
//

/**
 * The message/http cybol abstraction.
 *
 * An HTTP header message.
 */
static wchar_t HTTP_MESSAGE_MIME_ABSTRACTION_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p'};
static wchar_t* HTTP_MESSAGE_MIME_ABSTRACTION = HTTP_MESSAGE_MIME_ABSTRACTION_ARRAY;
static int* HTTP_MESSAGE_MIME_ABSTRACTION_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The message/news cybol abstraction.
 */
static wchar_t NEWS_MESSAGE_MIME_ABSTRACTION_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'n', L'e', L'w', L's'};
static wchar_t* NEWS_MESSAGE_MIME_ABSTRACTION = NEWS_MESSAGE_MIME_ABSTRACTION_ARRAY;
static int* NEWS_MESSAGE_MIME_ABSTRACTION_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/* MESSAGE_MIME_ABSTRACTION_SOURCE */
#endif
