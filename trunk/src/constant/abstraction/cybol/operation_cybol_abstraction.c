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
 * @version $RCSfile: operation_cybol_abstraction.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_OPERATION_LANGUAGE_CONSTANTS_SOURCE
#define CYBOL_OPERATION_LANGUAGE_CONSTANTS_SOURCE

#include "../../../../constant/model/memory/integer_memory_model.c"

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
// Operation (some logic to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: operation
// This media type is a CYBOL extension.
//

/**
 * The operation/plain cybol abstraction.
 *
 * Operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t PLAIN_OPERATION_CYBOL_ABSTRACTION_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'p', L'l', L'a', L'i', L'n'};
static wchar_t* PLAIN_OPERATION_CYBOL_ABSTRACTION = PLAIN_OPERATION_CYBOL_ABSTRACTION_ARRAY;
static int* PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOL_OPERATION_LANGUAGE_CONSTANTS_SOURCE */
#endif
