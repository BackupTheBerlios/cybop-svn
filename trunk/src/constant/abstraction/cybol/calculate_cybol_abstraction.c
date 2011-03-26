/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: operation_cybol_abstraction.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CALCULATE_CYBOL_ABSTRACTION_CONSTANTS_SOURCE
#define CALCULATE_CYBOL_ABSTRACTION_CONSTANTS_SOURCE

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
// Calculate (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: calculate
// This media type is a CYBOL extension.
//

/**
 * The calculate/add cybol abstraction.
 *
 * Arithmetic operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t ADD_CALCULATE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'a', L'l', L'c', L'u', L'l', L'a', L't', L'e', L'/', L'a', L'd', L'd'};
static wchar_t* ADD_CALCULATE_CYBOL_ABSTRACTION = ADD_CALCULATE_CYBOL_ABSTRACTION_ARRAY;
static int* ADD_CALCULATE_CYBOL_ABSTRACTION_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The calculate/divide cybol abstraction.
 *
 * Arithmetic operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t DIVIDE_CALCULATE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'a', L'l', L'c', L'u', L'l', L'a', L't', L'e', L'/', L'd', L'i', L'v', L'i', L'd', L'e'};
static wchar_t* DIVIDE_CALCULATE_CYBOL_ABSTRACTION = DIVIDE_CALCULATE_CYBOL_ABSTRACTION_ARRAY;
static int* DIVIDE_CALCULATE_CYBOL_ABSTRACTION_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The calculate/multiply cybol abstraction.
 *
 * Arithmetic operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t MULTIPLY_CALCULATE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'a', L'l', L'c', L'u', L'l', L'a', L't', L'e', L'/', L'm', L'u', L'l', L't', L'i', L'p', L'l', L'y'};
static wchar_t* MULTIPLY_CALCULATE_CYBOL_ABSTRACTION = MULTIPLY_CALCULATE_CYBOL_ABSTRACTION_ARRAY;
static int* MULTIPLY_CALCULATE_CYBOL_ABSTRACTION_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The calculate/subtract cybol abstraction.
 *
 * Arithmetic operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t SUBTRACT_CALCULATE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'a', L'l', L'c', L'u', L'l', L'a', L't', L'e', L'/', L's', L'u', L'b', L't', L'r', L'a', L'c', L't'};
static wchar_t* SUBTRACT_CALCULATE_CYBOL_ABSTRACTION = SUBTRACT_CALCULATE_CYBOL_ABSTRACTION_ARRAY;
static int* SUBTRACT_CALCULATE_CYBOL_ABSTRACTION_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/* CALCULATE_CYBOL_ABSTRACTION_CONSTANTS_SOURCE */
#endif
