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
 * @version $RCSfile: example_mime_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EXAMPLE_MIME_ABSTRACTION_SOURCE
#define EXAMPLE_MIME_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//

//
// Example.
//
// IANA media type: example
//

/**
 * The example cybol abstraction.
 *
 * This is just offered by IANA for testing reasons.
 */
static wchar_t EXAMPLE_MIME_ABSTRACTION_ARRAY[] = {L'e', L'x', L'a', L'm', L'p', L'l', L'e'};
static wchar_t* EXAMPLE_MIME_ABSTRACTION = EXAMPLE_MIME_ABSTRACTION_ARRAY;
static int* EXAMPLE_MIME_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* EXAMPLE_MIME_ABSTRACTION_SOURCE */
#endif
