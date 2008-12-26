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
 * @version $RCSfile: text_cybol_abstraction.c,v $ $Revision: 1.5 $ $Date: 2008-12-26 16:19:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_TEXT_LANGUAGE_CONSTANTS_SOURCE
#define CYBOL_TEXT_LANGUAGE_CONSTANTS_SOURCE

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
// Text (human-readable text and source code).
//
// IANA media type: text
//

/**
 * The text/abstraction cybol abstraction.
 *
 * This constant is necessary to translate cybol- into memory abstractions,
 * because both are not always identical.
 */
static wchar_t ABSTRACTION_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n'};
static wchar_t* ABSTRACTION_TEXT_CYBOL_ABSTRACTION = ABSTRACTION_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* ABSTRACTION_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/cybol cybol abstraction as ascii character string.
 *
 * CAUTION! This constant is redundant with CYBOL_TEXT_CYBOL_ABSTRACTION.
 * It is necessary, because the module "initialiser.c" needs to hand over
 * a multibyte character string as argument, which later gets decoded
 * into a wide character string.
 *
 * The "CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT" from above is used as count.
 */
static char ASCII_CYBOL_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {'t', 'e', 'x', 't', '/', 'c', 'y', 'b', 'o', 'l'};
static char* ASCII_CYBOL_TEXT_CYBOL_ABSTRACTION = ASCII_CYBOL_TEXT_CYBOL_ABSTRACTION_ARRAY;

/**
 * The text/plain cybol abstraction as ascii character string.
 *
 * CAUTION! This constant is redundant with PLAIN_TEXT_CYBOL_ABSTRACTION.
 * It is necessary, because certain pieces of source code need to hand over
 * a multibyte character string as argument, which later gets decoded
 * into a wide character string.
 *
 * The "CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT" from above is used as count.
 */
static char ASCII_PLAIN_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {'t', 'e', 'x', 't', '/', 'p', 'l', 'a', 'i', 'n'};
static char* ASCII_PLAIN_TEXT_CYBOL_ABSTRACTION = ASCII_PLAIN_TEXT_CYBOL_ABSTRACTION_ARRAY;

/**
 * The text/css cybol abstraction.
 *
 * Cascading Style Sheets.
 * Defined in RFC 2318.
 * Suffixes: css
 */
static wchar_t CSS_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'c', L's', L's'};
static wchar_t* CSS_TEXT_CYBOL_ABSTRACTION = CSS_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* CSS_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/cybol cybol abstraction.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://cybop.berlios.de/books/cybol/cybol.pdf
 * Suffixes: cybol
 */
static wchar_t CYBOL_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'c', L'y', L'b', L'o', L'l'};
static wchar_t* CYBOL_TEXT_CYBOL_ABSTRACTION = CYBOL_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/html cybol abstraction.
 *
 * Hypertext Markup Language (HTML) format.
 * Defined in RFC 2854.
 * Suffixes: html, htm, shtml
 */
static wchar_t HTML_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'h', L't', L'm', L'l'};
static wchar_t* HTML_TEXT_CYBOL_ABSTRACTION = HTML_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* HTML_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/hxp cybol abstraction.
 *
 * Healthcare Exchange Protocol (HXP) format.
 * An XML-based standard for medical data exchange.
 *
 * It was defined by a group of open source projects at:
 * http://hxp.sourceforge.net/
 * Suffixes: hxp (?? only assumed, not verified!)
 */
static wchar_t HXP_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'h', L'x', L'p'};
static wchar_t* HXP_TEXT_CYBOL_ABSTRACTION = HXP_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* HXP_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/model-diagram cybol abstraction.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://cybop.berlios.de/books/cybol/cybol.pdf
 */
static wchar_t MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'm', L'o', L'd', L'e', L'l', L'-', L'd', L'i', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION = MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/plain cybol abstraction.
 *
 * Textual data.
 * Defined in RFC 2046 and RFC 3676.
 * Suffixes: txt
 *
 * This language (media type) is also used for strings (character vectors) in CYBOL.
 */
static wchar_t PLAIN_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'p', L'l', L'a', L'i', L'n'};
static wchar_t* PLAIN_TEXT_CYBOL_ABSTRACTION = PLAIN_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/xdt cybol abstraction.
 *
 * x Daten Transfer (xDT) format.
 * A group of compatible formats for medical data exchange in Germany.
 *
 * Schnittstellen - Datensatzbeschreibungen - Specification:
 * http://www.kbv.de/ita/4201.html
 * Suffixes: xdt, adt, bdt, gdt, ldt
 */
static wchar_t XDT_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'x', L'd', L't'};
static wchar_t* XDT_TEXT_CYBOL_ABSTRACTION = XDT_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* XDT_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The text/xml cybol abstraction.
 *
 * Extensible Markup Language.
 * Defined in RFC 3023.
 * Suffixes: xml
 */
static wchar_t XML_TEXT_CYBOL_ABSTRACTION_ARRAY[] = {L't', L'e', L'x', L't', L'/', L'x', L'm', L'l'};
static wchar_t* XML_TEXT_CYBOL_ABSTRACTION = XML_TEXT_CYBOL_ABSTRACTION_ARRAY;
static int* XML_TEXT_CYBOL_ABSTRACTION_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOL_TEXT_LANGUAGE_CONSTANTS_SOURCE */
#endif
