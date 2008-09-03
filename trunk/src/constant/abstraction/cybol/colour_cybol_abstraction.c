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
 * @version $RCSfile: colour_cybol_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COLOUR_CYBOL_ABSTRACTION_SOURCE
#define COLOUR_CYBOL_ABSTRACTION_SOURCE

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
// Colour (colour formats).
//
// IANA media type: not defined
// Self-defined media type: colour
// This media type is a CYBOL extension.
//

/**
 * The colour/cmyk cybol abstraction.
 *
 * Cyan, Magenta, Yellow, Key (black) (CMYK) colour model,
 * also referred to as "process color" or "four color".
 *
 * This is a CYBOL extension.
 */
static wchar_t CMYK_COLOUR_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L'c', L'm', L'y', L'k'};
static wchar_t* CMYK_COLOUR_CYBOL_ABSTRACTION = CMYK_COLOUR_CYBOL_ABSTRACTION_ARRAY;
static int* CMYK_COLOUR_CYBOL_ABSTRACTION_COUNT = NUMBER_11_INTEGER_ARRAY;

/**
 * The colour/rgb cybol abstraction.
 *
 * Red, Green, Blue colour model.
 *
 * This is a CYBOL extension.
 */
static wchar_t RGB_COLOUR_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L'r', L'g', L'b'};
static wchar_t* RGB_COLOUR_CYBOL_ABSTRACTION = RGB_COLOUR_CYBOL_ABSTRACTION_ARRAY;
static int* RGB_COLOUR_CYBOL_ABSTRACTION_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The colour/terminal-background cybol abstraction.
 *
 * Terminal background colour name as written word.
 *
 * This is a CYBOL extension.
 */
static wchar_t TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l', L'-', L'b', L'a', L'c', L'k', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION = TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION_ARRAY;
static int* TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT = NUMBER_26_INTEGER_ARRAY;

/**
 * The colour/terminal-foreground cybol abstraction.
 *
 * Terminal foreground colour name as written word.
 *
 * This is a CYBOL extension.
 */
static wchar_t TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION_ARRAY[] = {L'c', L'o', L'l', L'o', L'u', L'r', L'/', L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l', L'-', L'f', L'o', L'r', L'e', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION = TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION_ARRAY;
static int* TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT = NUMBER_26_INTEGER_ARRAY;

/* COLOUR_CYBOL_ABSTRACTION_SOURCE */
#endif
