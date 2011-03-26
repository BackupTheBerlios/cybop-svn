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

#ifndef COMPARE_CYBOL_ABSTRACTION_CONSTANTS_SOURCE
#define COMPARE_CYBOL_ABSTRACTION_CONSTANTS_SOURCE

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
// Compare (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: compare
// This media type is a CYBOL extension.
//

/**
 * The compare/equal cybol abstraction.
 *
 * Comparison operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t EQUAL_COMPARE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e', L'/', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* EQUAL_COMPARE_CYBOL_ABSTRACTION = EQUAL_COMPARE_CYBOL_ABSTRACTION_ARRAY;
static int* EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The compare/greater cybol abstraction.
 *
 * Comparison operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t GREATER_COMPARE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e', L'/', L'g', L'r', L'e', L'a', L't', L'e', L'r'};
static wchar_t* GREATER_COMPARE_CYBOL_ABSTRACTION = GREATER_COMPARE_CYBOL_ABSTRACTION_ARRAY;
static int* GREATER_COMPARE_CYBOL_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The compare/greater-or-equal cybol abstraction.
 *
 * Comparison operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t GREATER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e', L'/', L'g', L'r', L'e', L'a', L't', L'e', L'r', L'-', L'o', L'r', L'-', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* GREATER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION = GREATER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_ARRAY;
static int* GREATER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The compare/smaller cybol abstraction.
 *
 * Comparison operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t SMALLER_COMPARE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e', L'/', L's', L'm', L'a', L'l', L'l', L'e', L'r'};
static wchar_t* SMALLER_COMPARE_CYBOL_ABSTRACTION = SMALLER_COMPARE_CYBOL_ABSTRACTION_ARRAY;
static int* SMALLER_COMPARE_CYBOL_ABSTRACTION_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The compare/smaller-or-equal cybol abstraction.
 *
 * Comparison operation to be processed by the Central Processing Unit (CPU).
 *
 * This is a CYBOL extension.
 */
static wchar_t SMALLER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'm', L'p', L'a', L'r', L'e', L'/', L's', L'm', L'a', L'l', L'l', L'e', L'r', L'-', L'o', L'r', L'-', L'e', L'q', L'u', L'a', L'l'};
static wchar_t* SMALLER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION = SMALLER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_ARRAY;
static int* SMALLER_OR_EQUAL_COMPARE_CYBOL_ABSTRACTION_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/* COMPARE_CYBOL_ABSTRACTION_CONSTANTS_SOURCE */
#endif
