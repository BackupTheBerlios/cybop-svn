/*
 * $RCSfile: html_character_entity_constants.c,v $
 *
 * Copyright (c)1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option)any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.2 $ $Date: 2008-05-06 22:36:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_CHARACTER_ENTITY_CONSTANTS_SOURCE
#define HTML_CHARACTER_ENTITY_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/**
 * The quotation mark html character entity.
 *
 * Name: quot
 * Character: "
 * Unicode code point: U+0022 (34)
 * Standard: HTML 2.0
 * Description: quotation mark
 */
static wchar_t QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'q', L'u', L'o', L't'};
static wchar_t* QUOTATION_MARK_HTML_CHARACTER_ENTITY = QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The ampersand html character entity.
 *
 * Name: amp
 * Character: &
 * Unicode code point: U+0026 (38)
 * Standard: HTML 2.0
 * Description: ampersand
 */
static wchar_t AMPERSAND_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'm', L'p'};
static wchar_t* AMPERSAND_HTML_CHARACTER_ENTITY = AMPERSAND_HTML_CHARACTER_ENTITY_ARRAY;
static int* AMPERSAND_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The less-than sign html character entity.
 *
 * Name: lt
 * Character: <
 * Unicode code point: U+003C (60)
 * Standard: HTML 2.0
 * Description: less-than sign
 */
static wchar_t LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L't'};
static wchar_t* LESS_THAN_SIGN_HTML_CHARACTER_ENTITY = LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* LESS_THAN_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The greater-than sign html character entity.
 *
 * Name: gt
 * Character: >
 * Unicode code point: U+003E (62)
 * Standard: HTML 2.0
 * Description: greater-than sign
 */
static wchar_t GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'g', L't'};
static wchar_t* GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY = GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREATER_THAN_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The non-breaking space html character entity.
 *
 * Name: nbsp
 * Character:
 * Unicode code point: U+00A0 (160)
 * Standard: HTML 3.2
 * Description: non-breaking space
 */
static wchar_t NON_BREAKING_SPACE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'b', L's', L'p'};
static wchar_t* NON_BREAKING_SPACE_HTML_CHARACTER_ENTITY = NON_BREAKING_SPACE_HTML_CHARACTER_ENTITY_ARRAY;
static int* NON_BREAKING_SPACE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The inverted exclamation mark html character entity.
 *
 * Name: iexcl
 * Character: �
 * Unicode code point: U+00A1 (161)
 * Standard: HTML 3.2
 * Description: inverted exclamation mark
 */
static wchar_t INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'e', L'x', L'c', L'l'};
static wchar_t* INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY = INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* INVERTED_EXCLAMATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The cent sign html character entity.
 *
 * Name: cent
 * Character: �
 * Unicode code point: U+00A2 (162)
 * Standard: HTML 3.2
 * Description: cent sign
 */
static wchar_t CENT_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'e', L'n', L't'};
static wchar_t* CENT_SIGN_HTML_CHARACTER_ENTITY = CENT_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* CENT_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The pound sign html character entity.
 *
 * Name: pound
 * Character: �
 * Unicode code point: U+00A3 (163)
 * Standard: HTML 3.2
 * Description: pound sign
 */
static wchar_t POUND_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'o', L'u', L'n', L'd'};
static wchar_t* POUND_SIGN_HTML_CHARACTER_ENTITY = POUND_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* POUND_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The currency sign html character entity.
 *
 * Name: curren
 * Character: �
 * Unicode code point: U+00A4 (164)
 * Standard: HTML 3.2
 * Description: currency sign
 */
static wchar_t CURRENCY_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'u', L'r', L'r', L'e', L'n'};
static wchar_t* CURRENCY_SIGN_HTML_CHARACTER_ENTITY = CURRENCY_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* CURRENCY_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The yen sign html character entity.
 *
 * Name: yen
 * Character: �
 * Unicode code point: U+00A5 (165)
 * Standard: HTML 3.2
 * Description: yen sign
 */
static wchar_t YEN_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'y', L'e', L'n'};
static wchar_t* YEN_SIGN_HTML_CHARACTER_ENTITY = YEN_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* YEN_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The broken bar html character entity.
 *
 * Name: brvbar
 * Character: �
 * Unicode code point: U+00A6 (166)
 * Standard: HTML 3.2
 * Description: broken bar
 */
static wchar_t BROKEN_BAR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'b', L'r', L'v', L'b', L'a', L'r'};
static wchar_t* BROKEN_BAR_HTML_CHARACTER_ENTITY = BROKEN_BAR_HTML_CHARACTER_ENTITY_ARRAY;
static int* BROKEN_BAR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The section sign html character entity.
 *
 * Name: sect
 * Character: �
 * Unicode code point: U+00A7 (167)
 * Standard: HTML 3.2
 * Description: section sign
 */
static wchar_t SECTION_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'e', L'c', L't'};
static wchar_t* SECTION_SIGN_HTML_CHARACTER_ENTITY = SECTION_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* SECTION_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The diaeresis html character entity.
 *
 * Name: uml
 * Character: �
 * Unicode code point: U+00A8 (168)
 * Standard: HTML 3.2
 * Description: diaeresis
 */
static wchar_t DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'm', L'l'};
static wchar_t* DIAERESIS_HTML_CHARACTER_ENTITY = DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The copyright sign html character entity.
 *
 * Name: copy
 * Character: �
 * Unicode code point: U+00A9 (169)
 * Standard: HTML 3.2
 * Description: copyright sign
 */
static wchar_t COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY = COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* COPYRIGHT_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The feminine ordinal indicator html character entity.
 *
 * Name: ordf
 * Character: �
 * Unicode code point: U+00AA (170)
 * Standard: HTML 3.2
 * Description: feminine ordinal indicator
 */
static wchar_t FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'r', L'd', L'f'};
static wchar_t* FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY = FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* FEMININE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The left-pointing double angle quotation mark html character entity.
 *
 * Name: laquo
 * Character: �
 * Unicode code point: U+00AB (171)
 * Standard: HTML 3.2
 * Description: left-pointing double angle quotation mark
 */
static wchar_t LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'a', L'q', L'u', L'o'};
static wchar_t* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The not sign html character entity.
 *
 * Name: not
 * Character: �
 * Unicode code point: U+00AC (172)
 * Standard: HTML 3.2
 * Description: not sign
 */
static wchar_t NOT_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'o', L't'};
static wchar_t* NOT_SIGN_HTML_CHARACTER_ENTITY = NOT_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* NOT_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The soft hyphen html character entity.
 *
 * Name: shy
 * Character: �
 * Unicode code point: U+00AD (173)
 * Standard: HTML 3.2
 * Description: soft hyphen
 */
static wchar_t SOFT_HYPHEN_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'h', L'y'};
static wchar_t* SOFT_HYPHEN_HTML_CHARACTER_ENTITY = SOFT_HYPHEN_HTML_CHARACTER_ENTITY_ARRAY;
static int* SOFT_HYPHEN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The registered sign html character entity.
 *
 * Name: reg
 * Character: �
 * Unicode code point: U+00AE (174)
 * Standard: HTML 3.2
 * Description: registered sign
 */
static wchar_t REGISTERED_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'e', L'g'};
static wchar_t* REGISTERED_SIGN_HTML_CHARACTER_ENTITY = REGISTERED_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* REGISTERED_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The macron html character entity.
 *
 * Name: macr
 * Character: �
 * Unicode code point: U+00AF (175)
 * Standard: HTML 3.2
 * Description: macron
 */
static wchar_t MACRON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'm', L'a', L'c', L'r'};
static wchar_t* MACRON_HTML_CHARACTER_ENTITY = MACRON_HTML_CHARACTER_ENTITY_ARRAY;
static int* MACRON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The degree sign html character entity.
 *
 * Name: deg
 * Character: �
 * Unicode code point: U+00B0 (176)
 * Standard: HTML 3.2
 * Description: degree sign
 */
static wchar_t DEGREE_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'e', L'g'};
static wchar_t* DEGREE_SIGN_HTML_CHARACTER_ENTITY = DEGREE_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* DEGREE_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The plus-minus sign html character entity.
 *
 * Name: plusmn
 * Character: �
 * Unicode code point: U+00B1 (177)
 * Standard: HTML 3.2
 * Description: plus-minus sign
 */
static wchar_t PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'l', L'u', L's', L'm', L'n'};
static wchar_t* PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY = PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* PLUS_MINUS_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The superscript two html character entity.
 *
 * Name: sup2
 * Character: �
 * Unicode code point: U+00B2 (178)
 * Standard: HTML 3.2
 * Description: superscript two
 */
static wchar_t SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'p', L'2'};
static wchar_t* SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY = SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUPERSCRIPT_TWO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The superscript three html character entity.
 *
 * Name: sup3
 * Character: �
 * Unicode code point: U+00B3 (179)
 * Standard: HTML 3.2
 * Description: superscript three
 */
static wchar_t SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'p', L'3'};
static wchar_t* SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY = SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUPERSCRIPT_THREE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The acute accent html character entity.
 *
 * Name: acute
 * Character: �
 * Unicode code point: U+00B4 (180)
 * Standard: HTML 3.2
 * Description: acute accent
 */
static wchar_t ACUTE_ACCENT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'c', L'u', L't', L'e'};
static wchar_t* ACUTE_ACCENT_HTML_CHARACTER_ENTITY = ACUTE_ACCENT_HTML_CHARACTER_ENTITY_ARRAY;
static int* ACUTE_ACCENT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The micro sign html character entity.
 *
 * Name: micro
 * Character: �
 * Unicode code point: U+00B5 (181)
 * Standard: HTML 3.2
 * Description: micro sign
 */
static wchar_t MICRO_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'm', L'i', L'c', L'r', L'o'};
static wchar_t* MICRO_SIGN_HTML_CHARACTER_ENTITY = MICRO_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* MICRO_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The pilcrow sign html character entity.
 *
 * Name: para
 * Character: �
 * Unicode code point: U+00B6 (182)
 * Standard: HTML 3.2
 * Description: pilcrow sign
 */
static wchar_t PILCROW_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'a', L'r', L'a'};
static wchar_t* PILCROW_SIGN_HTML_CHARACTER_ENTITY = PILCROW_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* PILCROW_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The middle dot html character entity.
 *
 * Name: middot
 * Character: �
 * Unicode code point: U+00B7 (183)
 * Standard: HTML 3.2
 * Description: middle dot
 */
static wchar_t MIDDLE_DOT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'm', L'i', L'd', L'd', L'o', L't'};
static wchar_t* MIDDLE_DOT_HTML_CHARACTER_ENTITY = MIDDLE_DOT_HTML_CHARACTER_ENTITY_ARRAY;
static int* MIDDLE_DOT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The cedilla html character entity.
 *
 * Name: cedil
 * Character: �
 * Unicode code point: U+00B8 (184)
 * Standard: HTML 3.2
 * Description: cedilla
 */
static wchar_t CEDILLA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'e', L'd', L'i', L'l'};
static wchar_t* CEDILLA_HTML_CHARACTER_ENTITY = CEDILLA_HTML_CHARACTER_ENTITY_ARRAY;
static int* CEDILLA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The superscript one html character entity.
 *
 * Name: sup1
 * Character: �
 * Unicode code point: U+00B9 (185)
 * Standard: HTML 3.2
 * Description: superscript one
 */
static wchar_t SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'p', L'1'};
static wchar_t* SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY = SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUPERSCRIPT_ONE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The masculine ordinal indicator html character entity.
 *
 * Name: ordm
 * Character: �
 * Unicode code point: U+00BA (186)
 * Standard: HTML 3.2
 * Description: masculine ordinal indicator
 */
static wchar_t MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'r', L'd', L'm'};
static wchar_t* MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY = MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* MASCULINE_ORDINAL_INDICATOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The right-pointing double angle quotation mark html character entity.
 *
 * Name: raquo
 * Character: �
 * Unicode code point: U+00BB (187)
 * Standard: HTML 3.2
 * Description: right-pointing double angle quotation mark
 */
static wchar_t RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'a', L'q', L'u', L'o'};
static wchar_t* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The vulgar fraction one quarter html character entity.
 *
 * Name: frac14
 * Character: �
 * Unicode code point: U+00BC (188)
 * Standard: HTML 3.2
 * Description: vulgar fraction one quarter
 */
static wchar_t VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_ARRAY[] = {L'f', L'r', L'a', L'c', L'1', L'4'};
static wchar_t* VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY = VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_ARRAY;
static int* VULGAR_FRACTION_ONE_QUARTER_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The vulgar fraction one half html character entity.
 *
 * Name: frac12
 * Character: �
 * Unicode code point: U+00BD (189)
 * Standard: HTML 3.2
 * Description: vulgar fraction one half
 */
static wchar_t VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_ARRAY[] = {L'f', L'r', L'a', L'c', L'1', L'2'};
static wchar_t* VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY = VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_ARRAY;
static int* VULGAR_FRACTION_ONE_HALF_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The vulgar fraction three quarters html character entity.
 *
 * Name: frac34
 * Character: �
 * Unicode code point: U+00BE (190)
 * Standard: HTML 3.2
 * Description: vulgar fraction three quarters
 */
static wchar_t VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'f', L'r', L'a', L'c', L'3', L'4'};
static wchar_t* VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY = VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_ARRAY;
static int* VULGAR_FRACTION_THREE_QUARTERS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The inverted question mark html character entity.
 *
 * Name: iquest
 * Character: �
 * Unicode code point: U+00BF (191)
 * Standard: HTML 3.2
 * Description: inverted question mark
 */
static wchar_t INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'q', L'u', L'e', L's', L't'};
static wchar_t* INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY = INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* INVERTED_QUESTION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter a with grave html character entity.
 *
 * Name: Agrave
 * Character: �
 * Unicode code point: U+00C0 (192)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with grave
 */
static wchar_t LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter a with acute html character entity.
 *
 * Name: Aacute
 * Character: �
 * Unicode code point: U+00C1 (193)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with acute
 */
static wchar_t LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter a with circumflex html character entity.
 *
 * Name: Acirc
 * Character: �
 * Unicode code point: U+00C2 (194)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with circumflex
 */
static wchar_t LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter a with tilde html character entity.
 *
 * Name: Atilde
 * Character: �
 * Unicode code point: U+00C3 (195)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with tilde
 */
static wchar_t LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L't', L'i', L'l', L'd', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter a with diaeresis html character entity.
 *
 * Name: Auml
 * Character: �
 * Unicode code point: U+00C4 (196)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with diaeresis
 */
static wchar_t LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'u', L'm', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin capital letter a with ring above html character entity.
 *
 * Name: Aring
 * Character: �
 * Unicode code point: U+00C5 (197)
 * Standard: HTML 2.0
 * Description: Latin capital letter a with ring above
 */
static wchar_t LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'r', L'i', L'n', L'g'};
static wchar_t* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter ae html character entity.
 *
 * Name: AElig
 * Character: �
 * Unicode code point: U+00C6 (198)
 * Standard: HTML 2.0
 * Description: Latin capital letter ae
 */
static wchar_t LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'E', L'l', L'i', L'g'};
static wchar_t* LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_AE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter c with cedilla html character entity.
 *
 * Name: Ccedil
 * Character: �
 * Unicode code point: U+00C7 (199)
 * Standard: HTML 2.0
 * Description: Latin capital letter c with cedilla
 */
static wchar_t LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'C', L'c', L'e', L'd', L'i', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter e with grave html character entity.
 *
 * Name: Egrave
 * Character: �
 * Unicode code point: U+00C8 (200)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with grave
 */
static wchar_t LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter e with acute html character entity.
 *
 * Name: Eacute
 * Character: �
 * Unicode code point: U+00C9 (201)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with acute
 */
static wchar_t LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter e with circumflex html character entity.
 *
 * Name: Ecirc
 * Character: �
 * Unicode code point: U+00CA (202)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with circumflex
 */
static wchar_t LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter e with diaeresis html character entity.
 *
 * Name: Euml
 * Character: �
 * Unicode code point: U+00CB (203)
 * Standard: HTML 2.0
 * Description: Latin capital letter e with diaeresis
 */
static wchar_t LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L'u', L'm', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin capital letter i with grave html character entity.
 *
 * Name: Igrave
 * Character: �
 * Unicode code point: U+00CC (204)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with grave
 */
static wchar_t LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'I', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter i with acute html character entity.
 *
 * Name: Iacute
 * Character: �
 * Unicode code point: U+00CD (205)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with acute
 */
static wchar_t LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'I', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter i with circumflex html character entity.
 *
 * Name: Icirc
 * Character: �
 * Unicode code point: U+00CE (206)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with circumflex
 */
static wchar_t LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'I', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter i with diaeresis html character entity.
 *
 * Name: Iuml
 * Character: �
 * Unicode code point: U+00CF (207)
 * Standard: HTML 2.0
 * Description: Latin capital letter i with diaeresis
 */
static wchar_t LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'I', L'u', L'm', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin capital letter eth html character entity.
 *
 * Name: ETH
 * Character: �
 * Unicode code point: U+00D0 (208)
 * Standard: HTML 2.0
 * Description: Latin capital letter eth
 */
static wchar_t LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L'T', L'H'};
static wchar_t* LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_ETH_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Latin capital letter n with tilde html character entity.
 *
 * Name: Ntilde
 * Character: �
 * Unicode code point: U+00D1 (209)
 * Standard: HTML 2.0
 * Description: Latin capital letter n with tilde
 */
static wchar_t LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'N', L't', L'i', L'l', L'd', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter o with grave html character entity.
 *
 * Name: Ograve
 * Character: �
 * Unicode code point: U+00D2 (210)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with grave
 */
static wchar_t LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter o with acute html character entity.
 *
 * Name: Oacute
 * Character: �
 * Unicode code point: U+00D3 (211)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with acute
 */
static wchar_t LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter o with circumflex html character entity.
 *
 * Name: Ocirc
 * Character: �
 * Unicode code point: U+00D4 (212)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with circumflex
 */
static wchar_t LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter o with tilde html character entity.
 *
 * Name: Otilde
 * Character: �
 * Unicode code point: U+00D5 (213)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with tilde
 */
static wchar_t LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L't', L'i', L'l', L'd', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter o with diaeresis html character entity.
 *
 * Name: Ouml
 * Character: �
 * Unicode code point: U+00D6 (214)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with diaeresis
 */
static wchar_t LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'u', L'm', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The multiplication sign html character entity.
 *
 * Name: times
 * Character: �
 * Unicode code point: U+00D7 (215)
 * Standard: HTML 3.2
 * Description: multiplication sign
 */
static wchar_t MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'i', L'm', L'e', L's'};
static wchar_t* MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY = MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* MULTIPLICATION_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter o with stroke html character entity.
 *
 * Name: Oslash
 * Character: �
 * Unicode code point: U+00D8 (216)
 * Standard: HTML 2.0
 * Description: Latin capital letter o with stroke
 */
static wchar_t LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L's', L'l', L'a', L's', L'h'};
static wchar_t* LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter u with grave html character entity.
 *
 * Name: Ugrave
 * Character: �
 * Unicode code point: U+00D9 (217)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with grave
 */
static wchar_t LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'U', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter u with acute html character entity.
 *
 * Name: Uacute
 * Character: �
 * Unicode code point: U+00DA (218)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with acute
 */
static wchar_t LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'U', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter u with circumflex html character entity.
 *
 * Name: Ucirc
 * Character: �
 * Unicode code point: U+00DB (219)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with circumflex
 */
static wchar_t LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'U', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter u with diaeresis html character entity.
 *
 * Name: Uuml
 * Character: �
 * Unicode code point: U+00DC (220)
 * Standard: HTML 2.0
 * Description: Latin capital letter u with diaeresis
 */
static wchar_t LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'U', L'u', L'm', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin capital letter y with acute html character entity.
 *
 * Name: Yacute
 * Character: �
 * Unicode code point: U+00DD (221)
 * Standard: HTML 2.0
 * Description: Latin capital letter y with acute
 */
static wchar_t LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'Y', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter thorn html character entity.
 *
 * Name: THORN
 * Character: �
 * Unicode code point: U+00DE (222)
 * Standard: HTML 2.0
 * Description: Latin capital letter thorn
 */
static wchar_t LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'T', L'H', L'O', L'R', L'N'};
static wchar_t* LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_THORN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter sharp s (German Eszett)html character entity.
 *
 * Name: szlig
 * Character: �
 * Unicode code point: U+00DF (223)
 * Standard: HTML 2.0
 * Description: Latin small letter sharp s (German Eszett)
 */
static wchar_t LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'z', L'l', L'i', L'g'};
static wchar_t* LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_SHARP_S_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter a with grave html character entity.
 *
 * Name: agrave
 * Character: �
 * Unicode code point: U+00E0 (224)
 * Standard: HTML 2.0
 * Description: Latin small letter a with grave
 */
static wchar_t LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_A_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter a with acute html character entity.
 *
 * Name: aacute
 * Character: �
 * Unicode code point: U+00E1 (225)
 * Standard: HTML 2.0
 * Description: Latin small letter a with acute
 */
static wchar_t LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_A_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter a with circumflex html character entity.
 *
 * Name: acirc
 * Character: �
 * Unicode code point: U+00E2 (226)
 * Standard: HTML 2.0
 * Description: Latin small letter a with circumflex
 */
static wchar_t LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter a with tilde html character entity.
 *
 * Name: atilde
 * Character: �
 * Unicode code point: U+00E3 (227)
 * Standard: HTML 2.0
 * Description: Latin small letter a with tilde
 */
static wchar_t LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L't', L'i', L'l', L'd', L'e'};
static wchar_t* LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_A_WITH_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter a with diaeresis html character entity.
 *
 * Name: auml
 * Character: �
 * Unicode code point: U+00E4 (228)
 * Standard: HTML 2.0
 * Description: Latin small letter a with diaeresis
 */
static wchar_t LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'u', L'm', L'l'};
static wchar_t* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin small letter a with ring above html character entity.
 *
 * Name: aring
 * Character: �
 * Unicode code point: U+00E5 (229)
 * Standard: HTML 2.0
 * Description: Latin small letter a with ring above
 */
static wchar_t LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'r', L'i', L'n', L'g'};
static wchar_t* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin lowercase ligature ae html character entity.
 *
 * Name: aelig
 * Character: �
 * Unicode code point: U+00E6 (230)
 * Standard: HTML 2.0
 * Description: Latin lowercase ligature ae
 */
static wchar_t LATIN_LOWERCASE_LIGATURE_AE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'e', L'l', L'i', L'g'};
static wchar_t* LATIN_LOWERCASE_LIGATURE_AE_HTML_CHARACTER_ENTITY = LATIN_LOWERCASE_LIGATURE_AE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_LOWERCASE_LIGATURE_AE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter c with cedilla html character entity.
 *
 * Name: ccedil
 * Character: �
 * Unicode code point: U+00E7 (231)
 * Standard: HTML 2.0
 * Description: Latin small letter c with cedilla
 */
static wchar_t LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'c', L'e', L'd', L'i', L'l'};
static wchar_t* LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_C_WITH_CEDILLA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter e with grave html character entity.
 *
 * Name: egrave
 * Character: �
 * Unicode code point: U+00E8 (232)
 * Standard: HTML 2.0
 * Description: Latin small letter e with grave
 */
static wchar_t LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_E_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter e with acute html character entity.
 *
 * Name: eacute
 * Character: �
 * Unicode code point: U+00E9 (233)
 * Standard: HTML 2.0
 * Description: Latin small letter e with acute
 */
static wchar_t LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_E_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter e with circumflex html character entity.
 *
 * Name: ecirc
 * Character: �
 * Unicode code point: U+00EA (234)
 * Standard: HTML 2.0
 * Description: Latin small letter e with circumflex
 */
static wchar_t LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter e with diaeresis html character entity.
 *
 * Name: euml
 * Character: �
 * Unicode code point: U+00EB (235)
 * Standard: HTML 2.0
 * Description: Latin small letter e with diaeresis
 */
static wchar_t LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'u', L'm', L'l'};
static wchar_t* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin small letter i with grave html character entity.
 *
 * Name: igrave
 * Character: �
 * Unicode code point: U+00EC (236)
 * Standard: HTML 2.0
 * Description: Latin small letter i with grave
 */
static wchar_t LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_I_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter i with acute html character entity.
 *
 * Name: iacute
 * Character: �
 * Unicode code point: U+00ED (237)
 * Standard: HTML 2.0
 * Description: Latin small letter i with acute
 */
static wchar_t LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_I_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter i with circumflex html character entity.
 *
 * Name: icirc
 * Character: �
 * Unicode code point: U+00EE (238)
 * Standard: HTML 2.0
 * Description: Latin small letter i with circumflex
 */
static wchar_t LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter i with diaeresis html character entity.
 *
 * Name: iuml
 * Character: �
 * Unicode code point: U+00EF (239)
 * Standard: HTML 2.0
 * Description: Latin small letter i with diaeresis
 */
static wchar_t LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'u', L'm', L'l'};
static wchar_t* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin small letter eth html character entity.
 *
 * Name: eth
 * Character: �
 * Unicode code point: U+00F0 (240)
 * Standard: HTML 2.0
 * Description: Latin small letter eth
 */
static wchar_t LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L't', L'h'};
static wchar_t* LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_ETH_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Latin small letter n with tilde html character entity.
 *
 * Name: ntilde
 * Character: �
 * Unicode code point: U+00F1 (241)
 * Standard: HTML 2.0
 * Description: Latin small letter n with tilde
 */
static wchar_t LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L't', L'i', L'l', L'd', L'e'};
static wchar_t* LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_N_WITH_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter o with grave html character entity.
 *
 * Name: ograve
 * Character: �
 * Unicode code point: U+00F2 (242)
 * Standard: HTML 2.0
 * Description: Latin small letter o with grave
 */
static wchar_t LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_O_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter o with acute html character entity.
 *
 * Name: oacute
 * Character: �
 * Unicode code point: U+00F3 (243)
 * Standard: HTML 2.0
 * Description: Latin small letter o with acute
 */
static wchar_t LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_O_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter o with circumflex html character entity.
 *
 * Name: ocirc
 * Character: �
 * Unicode code point: U+00F4 (244)
 * Standard: HTML 2.0
 * Description: Latin small letter o with circumflex
 */
static wchar_t LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter o with tilde html character entity.
 *
 * Name: otilde
 * Character: �
 * Unicode code point: U+00F5 (245)
 * Standard: HTML 2.0
 * Description: Latin small letter o with tilde
 */
static wchar_t LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L't', L'i', L'l', L'd', L'e'};
static wchar_t* LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_O_WITH_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter o with diaeresis html character entity.
 *
 * Name: ouml
 * Character: �
 * Unicode code point: U+00F6 (246)
 * Standard: HTML 2.0
 * Description: Latin small letter o with diaeresis
 */
static wchar_t LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'u', L'm', L'l'};
static wchar_t* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The division sign html character entity.
 *
 * Name: divide
 * Character: �
 * Unicode code point: U+00F7 (247)
 * Standard: HTML 3.2
 * Description: division sign
 */
static wchar_t DIVISION_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'i', L'v', L'i', L'd', L'e'};
static wchar_t* DIVISION_SIGN_HTML_CHARACTER_ENTITY = DIVISION_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* DIVISION_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter o with stroke html character entity.
 *
 * Name: oslash
 * Character: �
 * Unicode code point: U+00F8 (248)
 * Standard: HTML 2.0
 * Description: Latin small letter o with stroke
 */
static wchar_t LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L's', L'l', L'a', L's', L'h'};
static wchar_t* LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_O_WITH_STROKE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter u with grave html character entity.
 *
 * Name: ugrave
 * Character: �
 * Unicode code point: U+00F9 (249)
 * Standard: HTML 2.0
 * Description: Latin small letter u with grave
 */
static wchar_t LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'g', L'r', L'a', L'v', L'e'};
static wchar_t* LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_U_WITH_GRAVE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter u with acute html character entity.
 *
 * Name: uacute
 * Character: �
 * Unicode code point: U+00FA (250)
 * Standard: HTML 2.0
 * Description: Latin small letter u with acute
 */
static wchar_t LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_U_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter u with circumflex html character entity.
 *
 * Name: ucirc
 * Character: �
 * Unicode code point: U+00FB (251)
 * Standard: HTML 2.0
 * Description: Latin small letter u with circumflex
 */
static wchar_t LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'c', L'i', L'r', L'c'};
static wchar_t* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter u with diaeresis html character entity.
 *
 * Name: uuml
 * Character: �
 * Unicode code point: U+00FC (252)
 * Standard: HTML 2.0
 * Description: Latin small letter u with diaeresis
 */
static wchar_t LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'u', L'm', L'l'};
static wchar_t* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin small letter y with acute html character entity.
 *
 * Name: yacute
 * Character: �
 * Unicode code point: U+00FD (253)
 * Standard: HTML 2.0
 * Description: Latin small letter y with acute
 */
static wchar_t LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'y', L'a', L'c', L'u', L't', L'e'};
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_Y_WITH_ACUTE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter thorn html character entity.
 *
 * Name: thorn
 * Character: �
 * Unicode code point: U+00FE (254)
 * Standard: HTML 2.0
 * Description: Latin small letter thorn
 */
static wchar_t LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'h', L'o', L'r', L'n'};
static wchar_t* LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_THORN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small letter y with diaeresis html character entity.
 *
 * Name: yuml
 * Character: �
 * Unicode code point: U+00FF (255)
 * Standard: HTML 2.0
 * Description: Latin small letter y with diaeresis
 */
static wchar_t LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'y', L'u', L'm', L'l'};
static wchar_t* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin capital ligature oe html character entity.
 *
 * Name: OElig
 * Character: �
 * Unicode code point: U+0152 (338)
 * Standard: HTML 4.0
 * Description: Latin capital ligature oe
 */
static wchar_t LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'E', L'l', L'i', L'g'};
static wchar_t* LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LIGATURE_OE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin small ligature oe html character entity.
 *
 * Name: oelig
 * Character: �
 * Unicode code point: U+0153 (339)
 * Standard: HTML 4.0
 * Description: Latin small ligature oe
 */
static wchar_t LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'e', L'l', L'i', L'g'};
static wchar_t* LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY = LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LIGATURE_OE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Latin capital letter s with caron html character entity.
 *
 * Name: Scaron
 * Character: �
 * Unicode code point: U+0160 (352)
 * Standard: HTML 4.0
 * Description: Latin capital letter s with caron
 */
static wchar_t LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'S', L'c', L'a', L'r', L'o', L'n'};
static wchar_t* LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin small letter s with caron html character entity.
 *
 * Name: scaron
 * Character: �
 * Unicode code point: U+0161 (353)
 * Standard: HTML 4.0
 * Description: Latin small letter s with caron
 */
static wchar_t LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'c', L'a', L'r', L'o', L'n'};
static wchar_t* LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_S_WITH_CARON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Latin capital letter y with diaeresis html character entity.
 *
 * Name: Yuml
 * Character: �
 * Unicode code point: U+0178 (376)
 * Standard: HTML 4.0
 * Description: Latin capital letter y with diaeresis
 */
static wchar_t LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'Y', L'u', L'm', L'l'};
static wchar_t* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY = LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Latin small letter f with hook html character entity.
 *
 * Name: fnof
 * Character: �
 * Unicode code point: U+0192 (402)
 * Standard: HTML 4.0
 * Description: Latin small letter f with hook
 */
static wchar_t LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'f', L'n', L'o', L'f'};
static wchar_t* LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY = LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_ARRAY;
static int* LATIN_SMALL_LETTER_F_WITH_HOOK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The modifier letter circumflex accent html character entity.
 *
 * Name: circ
 * Character: �
 * Unicode code point: U+02C6 (710)
 * Standard: HTML 4.0
 * Description: modifier letter circumflex accent
 */
static wchar_t MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'i', L'r', L'c'};
static wchar_t* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY = MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_ARRAY;
static int* MODIFIER_LETTER_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The small tilde html character entity.
 *
 * Name: tilde
 * Character: �
 * Unicode code point: U+02DC (732)
 * Standard: HTML 4.0
 * Description: small tilde
 */
static wchar_t SMALL_TILDE_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'i', L'l', L'd', L'e'};
static wchar_t* SMALL_TILDE_HTML_CHARACTER_ENTITY = SMALL_TILDE_HTML_CHARACTER_ENTITY_ARRAY;
static int* SMALL_TILDE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter alpha html character entity.
 *
 * Name: Alpha
 * Character: ?
 * Unicode code point: U+0391 (913)
 * Standard: HTML 4.0
 * Description: Greek capital letter alpha
 */
static wchar_t GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'A', L'l', L'p', L'h', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter beta html character entity.
 *
 * Name: Beta
 * Character: ?
 * Unicode code point: U+0392 (914)
 * Standard: HTML 4.0
 * Description: Greek capital letter beta
 */
static wchar_t GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'B', L'e', L't', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_BETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Greek capital letter gamma html character entity.
 *
 * Name: Gamma
 * Character: G
 * Unicode code point: U+0393 (915)
 * Standard: HTML 4.0
 * Description: Greek capital letter gamma
 */
static wchar_t GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'G', L'a', L'm', L'm', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter delta html character entity.
 *
 * Name: Delta
 * Character: ?
 * Unicode code point: U+0394 (916)
 * Standard: HTML 4.0
 * Description: Greek capital letter delta
 */
static wchar_t GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'D', L'e', L'l', L't', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_DELTA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter epsilon html character entity.
 *
 * Name: Epsilon
 * Character: ?
 * Unicode code point: U+0395 (917)
 * Standard: HTML 4.0
 * Description: Greek capital letter epsilon
 */
static wchar_t GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L'p', L's', L'i', L'l', L'o', L'n'};
static wchar_t* GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The Greek capital letter zeta html character entity.
 *
 * Name: Zeta
 * Character: ?
 * Unicode code point: U+0396 (918)
 * Standard: HTML 4.0
 * Description: Greek capital letter zeta
 */
static wchar_t GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'Z', L'e', L't', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_ZETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Greek capital letter eta html character entity.
 *
 * Name: Eta
 * Character: ?
 * Unicode code point: U+0397 (919)
 * Standard: HTML 4.0
 * Description: Greek capital letter eta
 */
static wchar_t GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'E', L't', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_ETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek capital letter theta html character entity.
 *
 * Name: Theta
 * Character: T
 * Unicode code point: U+0398 (920)
 * Standard: HTML 4.0
 * Description: Greek capital letter theta
 */
static wchar_t GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'T', L'h', L'e', L't', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_THETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter iota html character entity.
 *
 * Name: Iota
 * Character: ?
 * Unicode code point: U+0399 (921)
 * Standard: HTML 4.0
 * Description: Greek capital letter iota
 */
static wchar_t GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'I', L'o', L't', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_IOTA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Greek capital letter kappa html character entity.
 *
 * Name: Kappa
 * Character: ?
 * Unicode code point: U+039A (922)
 * Standard: HTML 4.0
 * Description: Greek capital letter kappa
 */
static wchar_t GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'K', L'a', L'p', L'p', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter lambda html character entity.
 *
 * Name: Lambda
 * Character: ?
 * Unicode code point: U+039B (923)
 * Standard: HTML 4.0
 * Description: Greek capital letter lambda
 */
static wchar_t GREEK_CAPITAL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'L', L'a', L'm', L'b', L'd', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Greek capital letter mu html character entity.
 *
 * Name: Mu
 * Character: ?
 * Unicode code point: U+039C (924)
 * Standard: HTML 4.0
 * Description: Greek capital letter mu
 */
static wchar_t GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_ARRAY[] = {L'M', L'u'};
static wchar_t* GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_MU_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek capital letter nu html character entity.
 *
 * Name: Nu
 * Character: ?
 * Unicode code point: U+039D (925)
 * Standard: HTML 4.0
 * Description: Greek capital letter nu
 */
static wchar_t GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_ARRAY[] = {L'N', L'u'};
static wchar_t* GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_NU_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek capital letter xi html character entity.
 *
 * Name: Xi
 * Character: ?
 * Unicode code point: U+039E (926)
 * Standard: HTML 4.0
 * Description: Greek capital letter xi
 */
static wchar_t GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'X', L'i'};
static wchar_t* GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_XI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek capital letter omicron html character entity.
 *
 * Name: Omicron
 * Character: ?
 * Unicode code point: U+039F (927)
 * Standard: HTML 4.0
 * Description: Greek capital letter omicron
 */
static wchar_t GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'm', L'i', L'c', L'r', L'o', L'n'};
static wchar_t* GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The Greek capital letter pi html character entity.
 *
 * Name: Pi
 * Character: ?
 * Unicode code point: U+03A0 (928)
 * Standard: HTML 4.0
 * Description: Greek capital letter pi
 */
static wchar_t GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'P', L'i'};
static wchar_t* GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_PI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek capital letter rho html character entity.
 *
 * Name: Rho
 * Character: ?
 * Unicode code point: U+03A1 (929)
 * Standard: HTML 4.0
 * Description: Greek capital letter rho
 */
static wchar_t GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'R', L'h', L'o'};
static wchar_t* GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_RHO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek capital letter sigma html character entity.
 *
 * Name: Sigma
 * Character: S
 * Unicode code point: U+03A3 (931)
 * Standard: HTML 4.0
 * Description: Greek capital letter sigma
 */
static wchar_t GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'S', L'i', L'g', L'm', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek capital letter tau html character entity.
 *
 * Name: Tau
 * Character: ?
 * Unicode code point: U+03A4 (932)
 * Standard: HTML 4.0
 * Description: Greek capital letter tau
 */
static wchar_t GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_ARRAY[] = {L'T', L'a', L'u'};
static wchar_t* GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_TAU_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek capital letter upsilon html character entity.
 *
 * Name: Upsilon
 * Character: ?
 * Unicode code point: U+03A5 (933)
 * Standard: HTML 4.0
 * Description: Greek capital letter upsilon
 */
static wchar_t GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'U', L'p', L's', L'i', L'l', L'o', L'n'};
static wchar_t* GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The Greek capital letter phi html character entity.
 *
 * Name: Phi
 * Character: F
 * Unicode code point: U+03A6 (934)
 * Standard: HTML 4.0
 * Description: Greek capital letter phi
 */
static wchar_t GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'P', L'h', L'i'};
static wchar_t* GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_PHI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek capital letter chi html character entity.
 *
 * Name: Chi
 * Character: ?
 * Unicode code point: U+03A7 (935)
 * Standard: HTML 4.0
 * Description: Greek capital letter chi
 */
static wchar_t GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'C', L'h', L'i'};
static wchar_t* GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_CHI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek capital letter psi html character entity.
 *
 * Name: Psi
 * Character: ?
 * Unicode code point: U+03A8 (936)
 * Standard: HTML 4.0
 * Description: Greek capital letter psi
 */
static wchar_t GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'P', L's', L'i'};
static wchar_t* GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_PSI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek capital letter omega html character entity.
 *
 * Name: Omega
 * Character: O
 * Unicode code point: U+03A9 (937)
 * Standard: HTML 4.0
 * Description: Greek capital letter omega
 */
static wchar_t GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'O', L'm', L'e', L'g', L'a'};
static wchar_t* GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY = GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_CAPITAL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter alpha html character entity.
 *
 * Name: alpha
 * Character: a
 * Unicode code point: U+03B1 (945)
 * Standard: HTML 4.0
 * Description: Greek small letter alpha
 */
static wchar_t GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'l', L'p', L'h', L'a'};
static wchar_t* GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_ALPHA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter beta html character entity.
 *
 * Name: beta
 * Character: �
 * Unicode code point: U+03B2 (946)
 * Standard: HTML 4.0
 * Description: Greek small letter beta
 */
static wchar_t GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'b', L'e', L't', L'a'};
static wchar_t* GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_BETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Greek small letter gamma html character entity.
 *
 * Name: gamma
 * Character: ?
 * Unicode code point: U+03B3 (947)
 * Standard: HTML 4.0
 * Description: Greek small letter gamma
 */
static wchar_t GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'g', L'a', L'm', L'm', L'a'};
static wchar_t* GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_GAMMA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter delta html character entity.
 *
 * Name: delta
 * Character: d
 * Unicode code point: U+03B4 (948)
 * Standard: HTML 4.0
 * Description: Greek small letter delta
 */
static wchar_t GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'e', L'l', L't', L'a'};
static wchar_t* GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_DELTA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter epsilon html character entity.
 *
 * Name: epsilon
 * Character: e
 * Unicode code point: U+03B5 (949)
 * Standard: HTML 4.0
 * Description: Greek small letter epsilon
 */
static wchar_t GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'p', L's', L'i', L'l', L'o', L'n'};
static wchar_t* GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_EPSILON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The Greek small letter zeta html character entity.
 *
 * Name: zeta
 * Character: ?
 * Unicode code point: U+03B6 (950)
 * Standard: HTML 4.0
 * Description: Greek small letter zeta
 */
static wchar_t GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'z', L'e', L't', L'a'};
static wchar_t* GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_ZETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Greek small letter eta html character entity.
 *
 * Name: eta
 * Character: ?
 * Unicode code point: U+03B7 (951)
 * Standard: HTML 4.0
 * Description: Greek small letter eta
 */
static wchar_t GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L't', L'a'};
static wchar_t* GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_ETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek small letter theta html character entity.
 *
 * Name: theta
 * Character: ?
 * Unicode code point: U+03B8 (952)
 * Standard: HTML 4.0
 * Description: Greek small letter theta
 */
static wchar_t GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'h', L'e', L't', L'a'};
static wchar_t* GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_THETA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter iota html character entity.
 *
 * Name: iota
 * Character: ?
 * Unicode code point: U+03B9 (953)
 * Standard: HTML 4.0
 * Description: Greek small letter iota
 */
static wchar_t GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'o', L't', L'a'};
static wchar_t* GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_IOTA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The Greek small letter kappa html character entity.
 *
 * Name: kappa
 * Character: ?
 * Unicode code point: U+03BA (954)
 * Standard: HTML 4.0
 * Description: Greek small letter kappa
 */
static wchar_t GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'k', L'a', L'p', L'p', L'a'};
static wchar_t* GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_KAPPA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter lambda html character entity.
 *
 * Name: lambda
 * Character: ?
 * Unicode code point: U+03BB (955)
 * Standard: HTML 4.0
 * Description: Greek small letter lambda
 */
static wchar_t GREEK_SMALL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'a', L'm', L'b', L'd', L'a'};
static wchar_t* GREEK_SMALL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_LAMBDA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Greek small letter mu html character entity.
 *
 * Name: mu
 * Character: �
 * Unicode code point: U+03BC (956)
 * Standard: HTML 4.0
 * Description: Greek small letter mu
 */
static wchar_t GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_ARRAY[] = {L'm', L'u'};
static wchar_t* GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_MU_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek small letter nu html character entity.
 *
 * Name: nu
 * Character: ?
 * Unicode code point: U+03BD (957)
 * Standard: HTML 4.0
 * Description: Greek small letter nu
 */
static wchar_t GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'u'};
static wchar_t* GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_NU_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek small letter xi html character entity.
 *
 * Name: xi
 * Character: ?
 * Unicode code point: U+03BE (958)
 * Standard: HTML 4.0
 * Description: Greek small letter xi
 */
static wchar_t GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'x', L'i'};
static wchar_t* GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_XI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek small letter omicron html character entity.
 *
 * Name: omicron
 * Character: ?
 * Unicode code point: U+03BF (959)
 * Standard: HTML 4.0
 * Description: Greek small letter omicron
 */
static wchar_t GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'm', L'i', L'c', L'r', L'o', L'n'};
static wchar_t* GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_OMICRON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The Greek small letter pi html character entity.
 *
 * Name: pi
 * Character: p
 * Unicode code point: U+03C0 (960)
 * Standard: HTML 4.0
 * Description: Greek small letter pi
 */
static wchar_t GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'i'};
static wchar_t* GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_PI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The Greek small letter rho html character entity.
 *
 * Name: rho
 * Character: ?
 * Unicode code point: U+03C1 (961)
 * Standard: HTML 4.0
 * Description: Greek small letter rho
 */
static wchar_t GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'h', L'o'};
static wchar_t* GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_RHO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek small letter final sigma html character entity.
 *
 * Name: sigmaf
 * Character: ?
 * Unicode code point: U+03C2 (962)
 * Standard: HTML 4.0
 * Description: Greek small letter final sigma
 */
static wchar_t GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'i', L'g', L'm', L'a', L'f'};
static wchar_t* GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_FINAL_SIGMA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The Greek small letter sigma html character entity.
 *
 * Name: sigma
 * Character: s
 * Unicode code point: U+03C3 (963)
 * Standard: HTML 4.0
 * Description: Greek small letter sigma
 */
static wchar_t GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'i', L'g', L'm', L'a'};
static wchar_t* GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_SIGMA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek small letter tau html character entity.
 *
 * Name: tau
 * Character: t
 * Unicode code point: U+03C4 (964)
 * Standard: HTML 4.0
 * Description: Greek small letter tau
 */
static wchar_t GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'a', L'u'};
static wchar_t* GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_TAU_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek small letter upsilon html character entity.
 *
 * Name: upsilon
 * Character: ?
 * Unicode code point: U+03C5 (965)
 * Standard: HTML 4.0
 * Description: Greek small letter upsilon
 */
static wchar_t GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'p', L's', L'i', L'l', L'o', L'n'};
static wchar_t* GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_UPSILON_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The Greek small letter phi html character entity.
 *
 * Name: phi
 * Character: f
 * Unicode code point: U+03C6 (966)
 * Standard: HTML 4.0
 * Description: Greek small letter phi
 */
static wchar_t GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'h', L'i'};
static wchar_t* GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_PHI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek small letter chi html character entity.
 *
 * Name: chi
 * Character: ?
 * Unicode code point: U+03C7 (967)
 * Standard: HTML 4.0
 * Description: Greek small letter chi
 */
static wchar_t GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'h', L'i'};
static wchar_t* GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_CHI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek small letter psi html character entity.
 *
 * Name: psi
 * Character: ?
 * Unicode code point: U+03C8 (968)
 * Standard: HTML 4.0
 * Description: Greek small letter psi
 */
static wchar_t GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L's', L'i'};
static wchar_t* GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_PSI_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The Greek small letter omega html character entity.
 *
 * Name: omega
 * Character: ?
 * Unicode code point: U+03C9 (969)
 * Standard: HTML 4.0
 * Description: Greek small letter omega
 */
static wchar_t GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'm', L'e', L'g', L'a'};
static wchar_t* GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY = GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_SMALL_LETTER_OMEGA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek theta symbol html character entity.
 *
 * Name: thetasym
 * Character: ?
 * Unicode code point: U+03D1 (977)
 * Standard: HTML 4.0
 * Description: Greek theta symbol
 */
static wchar_t GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'h', L'e', L't', L'a', L's', L'y', L'm'};
static wchar_t* GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY = GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_THETA_SYMBOL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_8_INTEGER_ARRAY;

/**
 * The Greek upsilon with hook symbol html character entity.
 *
 * Name: upsih
 * Character: ?
 * Unicode code point: U+03D2 (978)
 * Standard: HTML 4.0
 * Description: Greek upsilon with hook symbol
 */
static wchar_t GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'p', L's', L'i', L'h'};
static wchar_t* GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY = GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_UPSILON_WITH_HOOK_SYMBOL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The Greek pi symbol html character entity.
 *
 * Name: piv
 * Character: ?
 * Unicode code point: U+03D6 (982)
 * Standard: HTML 4.0
 * Description: Greek pi symbol
 */
static wchar_t GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'i', L'v'};
static wchar_t* GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY = GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREEK_PI_SYMBOL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The en space [1] html character entity.
 *
 * Name: ensp
 * Character:
 * Unicode code point: U+2002 (8194)
 * Standard: HTML 4.0
 * Description: en space [1]
 */
static wchar_t EN_SPACE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'n', L's', L'p'};
static wchar_t* EN_SPACE_HTML_CHARACTER_ENTITY = EN_SPACE_HTML_CHARACTER_ENTITY_ARRAY;
static int* EN_SPACE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The em space [2] html character entity.
 *
 * Name: emsp
 * Character:
 * Unicode code point: U+2003 (8195)
 * Standard: HTML 4.0
 * Description: em space [2]
 */
static wchar_t EM_SPACE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'm', L's', L'p'};
static wchar_t* EM_SPACE_HTML_CHARACTER_ENTITY = EM_SPACE_HTML_CHARACTER_ENTITY_ARRAY;
static int* EM_SPACE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The thin space [3] html character entity.
 *
 * Name: thinsp
 * Character: ?
 * Unicode code point: U+2009 (8201)
 * Standard: HTML 4.0
 * Description: thin space [3]
 */
static wchar_t THIN_SPACE_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'h', L'i', L'n', L's', L'p'};
static wchar_t* THIN_SPACE_HTML_CHARACTER_ENTITY = THIN_SPACE_HTML_CHARACTER_ENTITY_ARRAY;
static int* THIN_SPACE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The zero width non-joiner html character entity.
 *
 * Name: zwnj
 * Character: ?
 * Unicode code point: U+200C (8204)
 * Standard: HTML 4.0
 * Description: zero width non-joiner
 */
static wchar_t ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_ARRAY[] = {L'z', L'w', L'n', L'j'};
static wchar_t* ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY = ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_ARRAY;
static int* ZERO_WIDTH_NON_JOINER_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The zero width joiner html character entity.
 *
 * Name: zwj
 * Character: ?
 * Unicode code point: U+200D (8205)
 * Standard: HTML 4.0
 * Description: zero width joiner
 */
static wchar_t ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_ARRAY[] = {L'z', L'w', L'j'};
static wchar_t* ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY = ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_ARRAY;
static int* ZERO_WIDTH_JOINER_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The left-to-right mark html character entity.
 *
 * Name: lrm
 * Character: ?
 * Unicode code point: U+200E (8206)
 * Standard: HTML 4.0
 * Description: left-to-right mark
 */
static wchar_t LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'r', L'm'};
static wchar_t* LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY = LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_TO_RIGHT_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The right-to-left mark html character entity.
 *
 * Name: rlm
 * Character: ?
 * Unicode code point: U+200F (8207)
 * Standard: HTML 4.0
 * Description: right-to-left mark
 */
static wchar_t RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'l', L'm'};
static wchar_t* RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY = RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_TO_LEFT_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The en dash html character entity.
 *
 * Name: ndash
 * Character: �
 * Unicode code point: U+2013 (8211)
 * Standard: HTML 4.0
 * Description: en dash
 */
static wchar_t EN_DASH_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'd', L'a', L's', L'h'};
static wchar_t* EN_DASH_HTML_CHARACTER_ENTITY = EN_DASH_HTML_CHARACTER_ENTITY_ARRAY;
static int* EN_DASH_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The em dash html character entity.
 *
 * Name: mdash
 * Character: �
 * Unicode code point: U+2014 (8212)
 * Standard: HTML 4.0
 * Description: em dash
 */
static wchar_t EM_DASH_HTML_CHARACTER_ENTITY_ARRAY[] = {L'm', L'd', L'a', L's', L'h'};
static wchar_t* EM_DASH_HTML_CHARACTER_ENTITY = EM_DASH_HTML_CHARACTER_ENTITY_ARRAY;
static int* EM_DASH_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The left single quotation mark html character entity.
 *
 * Name: lsquo
 * Character: �
 * Unicode code point: U+2018 (8216)
 * Standard: HTML 4.0
 * Description: left single quotation mark
 */
static wchar_t LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L's', L'q', L'u', L'o'};
static wchar_t* LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The right single quotation mark html character entity.
 *
 * Name: rsquo
 * Character: �
 * Unicode code point: U+2019 (8217)
 * Standard: HTML 4.0
 * Description: right single quotation mark
 */
static wchar_t RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L's', L'q', L'u', L'o'};
static wchar_t* RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_SINGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The single low-9 quotation mark html character entity.
 *
 * Name: sbquo
 * Character: �
 * Unicode code point: U+201A (8218)
 * Standard: HTML 4.0
 * Description: single low-9 quotation mark
 */
static wchar_t SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'b', L'q', L'u', L'o'};
static wchar_t* SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY = SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* SINGLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The left double quotation mark html character entity.
 *
 * Name: ldquo
 * Character: �
 * Unicode code point: U+201C (8220)
 * Standard: HTML 4.0
 * Description: left double quotation mark
 */
static wchar_t LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'd', L'q', L'u', L'o'};
static wchar_t* LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The right double quotation mark html character entity.
 *
 * Name: rdquo
 * Character: �
 * Unicode code point: U+201D (8221)
 * Standard: HTML 4.0
 * Description: right double quotation mark
 */
static wchar_t RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'd', L'q', L'u', L'o'};
static wchar_t* RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_DOUBLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The double low-9 quotation mark html character entity.
 *
 * Name: bdquo
 * Character: �
 * Unicode code point: U+201E (8222)
 * Standard: HTML 4.0
 * Description: double low-9 quotation mark
 */
static wchar_t DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'b', L'd', L'q', L'u', L'o'};
static wchar_t* DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY = DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOUBLE_LOW_9_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The dagger html character entity.
 *
 * Name: dagger
 * Character: �
 * Unicode code point: U+2020 (8224)
 * Standard: HTML 4.0
 * Description: dagger
 */
static wchar_t DAGGER_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'a', L'g', L'g', L'e', L'r'};
static wchar_t* DAGGER_HTML_CHARACTER_ENTITY = DAGGER_HTML_CHARACTER_ENTITY_ARRAY;
static int* DAGGER_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The double dagger html character entity.
 *
 * Name: Dagger
 * Character: �
 * Unicode code point: U+2021 (8225)
 * Standard: HTML 4.0
 * Description: double dagger
 */
static wchar_t DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_ARRAY[] = {L'D', L'a', L'g', L'g', L'e', L'r'};
static wchar_t* DOUBLE_DAGGER_HTML_CHARACTER_ENTITY = DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOUBLE_DAGGER_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The bullet html character entity.
 *
 * Name: bull
 * Character: �
 * Unicode code point: U+2022 (8226)
 * Standard: HTML 4.0
 * Description: bullet
 */
static wchar_t BULLET_HTML_CHARACTER_ENTITY_ARRAY[] = {L'b', L'u', L'l', L'l'};
static wchar_t* BULLET_HTML_CHARACTER_ENTITY = BULLET_HTML_CHARACTER_ENTITY_ARRAY;
static int* BULLET_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The horizontal ellipsis html character entity.
 *
 * Name: hellip
 * Character: �
 * Unicode code point: U+2026 (8230)
 * Standard: HTML 4.0
 * Description: horizontal ellipsis
 */
static wchar_t HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'h', L'e', L'l', L'l', L'i', L'p'};
static wchar_t* HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY = HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_ARRAY;
static int* HORIZONTAL_ELLIPSIS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The per mille sign html character entity.
 *
 * Name: permil
 * Character: �
 * Unicode code point: U+2030 (8240)
 * Standard: HTML 4.0
 * Description: per mille sign
 */
static wchar_t PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'e', L'r', L'm', L'i', L'l'};
static wchar_t* PER_MILLE_SIGN_HTML_CHARACTER_ENTITY = PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* PER_MILLE_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The prime html character entity.
 *
 * Name: prime
 * Character: '
 * Unicode code point: U+2032 (8242)
 * Standard: HTML 4.0
 * Description: prime
 */
static wchar_t PRIME_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'r', L'i', L'm', L'e'};
static wchar_t* PRIME_HTML_CHARACTER_ENTITY = PRIME_HTML_CHARACTER_ENTITY_ARRAY;
static int* PRIME_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The double prime html character entity.
 *
 * Name: Prime
 * Character: ?
 * Unicode code point: U+2033 (8243)
 * Standard: HTML 4.0
 * Description: double prime
 */
static wchar_t DOUBLE_PRIME_HTML_CHARACTER_ENTITY_ARRAY[] = {L'P', L'r', L'i', L'm', L'e'};
static wchar_t* DOUBLE_PRIME_HTML_CHARACTER_ENTITY = DOUBLE_PRIME_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOUBLE_PRIME_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The single left-pointing angle quotation mark html character entity.
 *
 * Name: lsaquo
 * Character: �
 * Unicode code point: U+2039 (8249)
 * Standard: HTML 4.0
 * Description: single left-pointing angle quotation mark
 */
static wchar_t SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L's', L'a', L'q', L'u', L'o'};
static wchar_t* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The single right-pointing angle quotation mark html character entity.
 *
 * Name: rsaquo
 * Character: �
 * Unicode code point: U+203A (8250)
 * Standard: HTML 4.0
 * Description: single right-pointing angle quotation mark
 */
static wchar_t SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L's', L'a', L'q', L'u', L'o'};
static wchar_t* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY = SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_ARRAY;
static int* SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The overline html character entity.
 *
 * Name: oline
 * Character: ?
 * Unicode code point: U+203E (8254)
 * Standard: HTML 4.0
 * Description: overline
 */
static wchar_t OVERLINE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'l', L'i', L'n', L'e'};
static wchar_t* OVERLINE_HTML_CHARACTER_ENTITY = OVERLINE_HTML_CHARACTER_ENTITY_ARRAY;
static int* OVERLINE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The fraction slash html character entity.
 *
 * Name: frasl
 * Character: /
 * Unicode code point: U+2044 (8260)
 * Standard: HTML 4.0
 * Description: fraction slash
 */
static wchar_t FRACTION_SLASH_HTML_CHARACTER_ENTITY_ARRAY[] = {L'f', L'r', L'a', L's', L'l'};
static wchar_t* FRACTION_SLASH_HTML_CHARACTER_ENTITY = FRACTION_SLASH_HTML_CHARACTER_ENTITY_ARRAY;
static int* FRACTION_SLASH_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The euro sign html character entity.
 *
 * Name: euro
 * Character: �
 * Unicode code point: U+20AC (8364)
 * Standard: HTML 4.0
 * Description: euro sign
 */
static wchar_t EURO_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'u', L'r', L'o'};
static wchar_t* EURO_SIGN_HTML_CHARACTER_ENTITY = EURO_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* EURO_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The black-letter capital i html character entity.
 *
 * Name: image
 * Character: I
 * Unicode code point: U+2111 (8465)
 * Standard: HTML 4.0
 * Description: black-letter capital i
 */
static wchar_t BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'm', L'a', L'g', L'e'};
static wchar_t* BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY = BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_ARRAY;
static int* BLACK_LETTER_CAPITAL_I_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The script capital p (Weierstrass p)html character entity.
 *
 * Name: weierp
 * Character: P
 * Unicode code point: U+2118 (8472)
 * Standard: HTML 4.0
 * Description: script capital p (Weierstrass p)
 */
static wchar_t SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_ARRAY[] = {L'w', L'e', L'i', L'e', L'r', L'p'};
static wchar_t* SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY = SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_ARRAY;
static int* SCRIPT_CAPITAL_P_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The black-letter capital r html character entity.
 *
 * Name: real
 * Character: R
 * Unicode code point: U+211C (8476)
 * Standard: HTML 4.0
 * Description: black-letter capital r
 */
static wchar_t BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'e', L'a', L'l'};
static wchar_t* BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY = BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_ARRAY;
static int* BLACK_LETTER_CAPITAL_R_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The trademark sign html character entity.
 *
 * Name: trade
 * Character: �
 * Unicode code point: U+2122 (8482)
 * Standard: HTML 4.0
 * Description: trademark sign
 */
static wchar_t TRADEMARK_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'r', L'a', L'd', L'e'};
static wchar_t* TRADEMARK_SIGN_HTML_CHARACTER_ENTITY = TRADEMARK_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* TRADEMARK_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The alef symbol html character entity.
 *
 * Name: alefsym
 * Character: ?
 * Unicode code point: U+2135 (8501)
 * Standard: HTML 4.0
 * Description: alef symbol
 */
static wchar_t ALEF_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'l', L'e', L'f', L's', L'y', L'm'};
static wchar_t* ALEF_SYMBOL_HTML_CHARACTER_ENTITY = ALEF_SYMBOL_HTML_CHARACTER_ENTITY_ARRAY;
static int* ALEF_SYMBOL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_7_INTEGER_ARRAY;

/**
 * The leftwards arrow html character entity.
 *
 * Name: larr
 * Character: ?
 * Unicode code point: U+2190 (8592)
 * Standard: HTML 4.0
 * Description: leftwards arrow
 */
static wchar_t LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'a', L'r', L'r'};
static wchar_t* LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY = LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFTWARDS_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The upwards arrow html character entity.
 *
 * Name: uarr
 * Character: ?
 * Unicode code point: U+2191 (8593)
 * Standard: HTML 4.0
 * Description: upwards arrow
 */
static wchar_t UPWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'a', L'r', L'r'};
static wchar_t* UPWARDS_ARROW_HTML_CHARACTER_ENTITY = UPWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* UPWARDS_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The rightwards arrow html character entity.
 *
 * Name: rarr
 * Character: ?
 * Unicode code point: U+2192 (8594)
 * Standard: HTML 4.0
 * Description: rightwards arrow
 */
static wchar_t RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'a', L'r', L'r'};
static wchar_t* RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY = RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHTWARDS_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The downwards arrow html character entity.
 *
 * Name: darr
 * Character: ?
 * Unicode code point: U+2193 (8595)
 * Standard: HTML 4.0
 * Description: downwards arrow
 */
static wchar_t DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'a', L'r', L'r'};
static wchar_t* DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY = DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOWNWARDS_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The left right arrow html character entity.
 *
 * Name: harr
 * Character: ?
 * Unicode code point: U+2194 (8596)
 * Standard: HTML 4.0
 * Description: left right arrow
 */
static wchar_t LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'h', L'a', L'r', L'r'};
static wchar_t* LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY = LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_RIGHT_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The downwards arrow with corner leftwards html character entity.
 *
 * Name: crarr
 * Character: ?
 * Unicode code point: U+21B5 (8629)
 * Standard: HTML 4.0
 * Description: downwards arrow with corner leftwards
 */
static wchar_t DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'r', L'a', L'r', L'r'};
static wchar_t* DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY = DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The leftwards double arrow html character entity.
 *
 * Name: lArr
 * Character: ?
 * Unicode code point: U+21D0 (8656)
 * Standard: HTML 4.0
 * Description: leftwards double arrow
 */
static wchar_t LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'A', L'r', L'r'};
static wchar_t* LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY = LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The upwards double arrow html character entity.
 *
 * Name: uArr
 * Character: ?
 * Unicode code point: U+21D1 (8657)
 * Standard: HTML 4.0
 * Description: upwards double arrow
 */
static wchar_t UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'u', L'A', L'r', L'r'};
static wchar_t* UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY = UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* UPWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The rightwards double arrow html character entity.
 *
 * Name: rArr
 * Character: ?
 * Unicode code point: U+21D2 (8658)
 * Standard: HTML 4.0
 * Description: rightwards double arrow
 */
static wchar_t RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'A', L'r', L'r'};
static wchar_t* RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY = RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHTWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The downwards double arrow html character entity.
 *
 * Name: dArr
 * Character: ?
 * Unicode code point: U+21D3 (8659)
 * Standard: HTML 4.0
 * Description: downwards double arrow
 */
static wchar_t DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'A', L'r', L'r'};
static wchar_t* DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY = DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOWNWARDS_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The left right double arrow html character entity.
 *
 * Name: hArr
 * Character: ?
 * Unicode code point: U+21D4 (8660)
 * Standard: HTML 4.0
 * Description: left right double arrow
 */
static wchar_t LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY[] = {L'h', L'A', L'r', L'r'};
static wchar_t* LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY = LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_RIGHT_DOUBLE_ARROW_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The for all html character entity.
 *
 * Name: forall
 * Character: ?
 * Unicode code point: U+2200 (8704)
 * Standard: HTML 4.0
 * Description: for all
 */
static wchar_t FOR_ALL_HTML_CHARACTER_ENTITY_ARRAY[] = {L'f', L'o', L'r', L'a', L'l', L'l'};
static wchar_t* FOR_ALL_HTML_CHARACTER_ENTITY = FOR_ALL_HTML_CHARACTER_ENTITY_ARRAY;
static int* FOR_ALL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The partial differential html character entity.
 *
 * Name: part
 * Character: ?
 * Unicode code point: U+2202 (8706)
 * Standard: HTML 4.0
 * Description: partial differential
 */
static wchar_t PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'a', L'r', L't'};
static wchar_t* PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY = PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_ARRAY;
static int* PARTIAL_DIFFERENTIAL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The there exists html character entity.
 *
 * Name: exist
 * Character: ?
 * Unicode code point: U+2203 (8707)
 * Standard: HTML 4.0
 * Description: there exists
 */
static wchar_t THERE_EXISTS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'x', L'i', L's', L't'};
static wchar_t* THERE_EXISTS_HTML_CHARACTER_ENTITY = THERE_EXISTS_HTML_CHARACTER_ENTITY_ARRAY;
static int* THERE_EXISTS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The empty set html character entity.
 *
 * Name: empty
 * Character: �
 * Unicode code point: U+2205 (8709)
 * Standard: HTML 4.0
 * Description: empty set
 */
static wchar_t EMPTY_SET_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'm', L'p', L't', L'y'};
static wchar_t* EMPTY_SET_HTML_CHARACTER_ENTITY = EMPTY_SET_HTML_CHARACTER_ENTITY_ARRAY;
static int* EMPTY_SET_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The nabla html character entity.
 *
 * Name: nabla
 * Character: ?
 * Unicode code point: U+2207 (8711)
 * Standard: HTML 4.0
 * Description: nabla
 */
static wchar_t NABLA_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'a', L'b', L'l', L'a'};
static wchar_t* NABLA_HTML_CHARACTER_ENTITY = NABLA_HTML_CHARACTER_ENTITY_ARRAY;
static int* NABLA_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The element of html character entity.
 *
 * Name: isin
 * Character: ?
 * Unicode code point: U+2208 (8712)
 * Standard: HTML 4.0
 * Description: element of
 */
static wchar_t ELEMENT_OF_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L's', L'i', L'n'};
static wchar_t* ELEMENT_OF_HTML_CHARACTER_ENTITY = ELEMENT_OF_HTML_CHARACTER_ENTITY_ARRAY;
static int* ELEMENT_OF_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The not an element of html character entity.
 *
 * Name: notin
 * Character: ?
 * Unicode code point: U+2209 (8713)
 * Standard: HTML 4.0
 * Description: not an element of
 */
static wchar_t NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'o', L't', L'i', L'n'};
static wchar_t* NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY = NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_ARRAY;
static int* NOT_AN_ELEMENT_OF_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The contains as member html character entity.
 *
 * Name: ni
 * Character: ?
 * Unicode code point: U+220B (8715)
 * Standard: HTML 4.0
 * Description: contains as member
 */
static wchar_t CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'i'};
static wchar_t* CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY = CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_ARRAY;
static int* CONTAINS_AS_MEMBER_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The n-ary product html character entity.
 *
 * Name: prod
 * Character: ?
 * Unicode code point: U+220F (8719)
 * Standard: HTML 4.0
 * Description: n-ary product
 */
static wchar_t N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'r', L'o', L'd'};
static wchar_t* N_ARY_PRODUCT_HTML_CHARACTER_ENTITY = N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_ARRAY;
static int* N_ARY_PRODUCT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The n-ary summation html character entity.
 *
 * Name: sum
 * Character: ?
 * Unicode code point: U+2211 (8721)
 * Standard: HTML 4.0
 * Description: n-ary summation
 */
static wchar_t N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'm'};
static wchar_t* N_ARY_SUMMATION_HTML_CHARACTER_ENTITY = N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_ARRAY;
static int* N_ARY_SUMMATION_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The minus sign html character entity.
 *
 * Name: minus
 * Character: -
 * Unicode code point: U+2212 (8722)
 * Standard: HTML 4.0
 * Description: minus sign
 */
static wchar_t MINUS_SIGN_HTML_CHARACTER_ENTITY_ARRAY[] = {L'm', L'i', L'n', L'u', L's'};
static wchar_t* MINUS_SIGN_HTML_CHARACTER_ENTITY = MINUS_SIGN_HTML_CHARACTER_ENTITY_ARRAY;
static int* MINUS_SIGN_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The asterisk operator html character entity.
 *
 * Name: lowast
 * Character: *
 * Unicode code point: U+2217 (8727)
 * Standard: HTML 4.0
 * Description: asterisk operator
 */
static wchar_t ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'o', L'w', L'a', L's', L't'};
static wchar_t* ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY = ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* ASTERISK_OPERATOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The square root html character entity.
 *
 * Name: radic
 * Character: v
 * Unicode code point: U+221A (8730)
 * Standard: HTML 4.0
 * Description: square root
 */
static wchar_t SQUARE_ROOT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'a', L'd', L'i', L'c'};
static wchar_t* SQUARE_ROOT_HTML_CHARACTER_ENTITY = SQUARE_ROOT_HTML_CHARACTER_ENTITY_ARRAY;
static int* SQUARE_ROOT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The proportional to html character entity.
 *
 * Name: prop
 * Character: ?
 * Unicode code point: U+221D (8733)
 * Standard: HTML 4.0
 * Description: proportional to
 */
static wchar_t PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'r', L'o', L'p'};
static wchar_t* PROPORTIONAL_TO_HTML_CHARACTER_ENTITY = PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* PROPORTIONAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The infinity html character entity.
 *
 * Name: infin
 * Character: 8
 * Unicode code point: U+221E (8734)
 * Standard: HTML 4.0
 * Description: infinity
 */
static wchar_t INFINITY_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'n', L'f', L'i', L'n'};
static wchar_t* INFINITY_HTML_CHARACTER_ENTITY = INFINITY_HTML_CHARACTER_ENTITY_ARRAY;
static int* INFINITY_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The angle html character entity.
 *
 * Name: ang
 * Character: ?
 * Unicode code point: U+2220 (8736)
 * Standard: HTML 4.0
 * Description: angle
 */
static wchar_t ANGLE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'n', L'g'};
static wchar_t* ANGLE_HTML_CHARACTER_ENTITY = ANGLE_HTML_CHARACTER_ENTITY_ARRAY;
static int* ANGLE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The logical and html character entity.
 *
 * Name: and
 * Character: ?
 * Unicode code point: U+2227 (8743)
 * Standard: HTML 4.0
 * Description: logical and
 */
static wchar_t LOGICAL_AND_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L'n', L'd'};
static wchar_t* LOGICAL_AND_HTML_CHARACTER_ENTITY = LOGICAL_AND_HTML_CHARACTER_ENTITY_ARRAY;
static int* LOGICAL_AND_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The logical or html character entity.
 *
 * Name: or
 * Character: ?
 * Unicode code point: U+2228 (8744)
 * Standard: HTML 4.0
 * Description: logical or
 */
static wchar_t LOGICAL_OR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'r'};
static wchar_t* LOGICAL_OR_HTML_CHARACTER_ENTITY = LOGICAL_OR_HTML_CHARACTER_ENTITY_ARRAY;
static int* LOGICAL_OR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The intersection html character entity.
 *
 * Name: cap
 * Character: n
 * Unicode code point: U+2229 (8745)
 * Standard: HTML 4.0
 * Description: intersection
 */
static wchar_t INTERSECTION_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'a', L'p'};
static wchar_t* INTERSECTION_HTML_CHARACTER_ENTITY = INTERSECTION_HTML_CHARACTER_ENTITY_ARRAY;
static int* INTERSECTION_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The union html character entity.
 *
 * Name: cup
 * Character: ?
 * Unicode code point: U+222A (8746)
 * Standard: HTML 4.0
 * Description: union
 */
static wchar_t UNION_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'u', L'p'};
static wchar_t* UNION_HTML_CHARACTER_ENTITY = UNION_HTML_CHARACTER_ENTITY_ARRAY;
static int* UNION_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The integral html character entity.
 *
 * Name: int
 * Character: ?
 * Unicode code point: U+222B (8747)
 * Standard: HTML 4.0
 * Description: integral
 */
static wchar_t INTEGRAL_HTML_CHARACTER_ENTITY_ARRAY[] = {L'i', L'n', L't'};
static wchar_t* INTEGRAL_HTML_CHARACTER_ENTITY = INTEGRAL_HTML_CHARACTER_ENTITY_ARRAY;
static int* INTEGRAL_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The therefore html character entity.
 *
 * Name: there4
 * Character: ?
 * Unicode code point: U+2234 (8756)
 * Standard: HTML 4.0
 * Description: therefore
 */
static wchar_t THEREFORE_HTML_CHARACTER_ENTITY_ARRAY[] = {L't', L'h', L'e', L'r', L'e', L'4'};
static wchar_t* THEREFORE_HTML_CHARACTER_ENTITY = THEREFORE_HTML_CHARACTER_ENTITY_ARRAY;
static int* THEREFORE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The tilde operator html character entity.
 *
 * Name: sim
 * Character: ~
 * Unicode code point: U+223C (8764)
 * Standard: HTML 4.0
 * Description: tilde operator
 */
static wchar_t TILDE_OPERATOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'i', L'm'};
static wchar_t* TILDE_OPERATOR_HTML_CHARACTER_ENTITY = TILDE_OPERATOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* TILDE_OPERATOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The congruent to html character entity.
 *
 * Name: cong
 * Character: ?
 * Unicode code point: U+2245 (8773)
 * Standard: HTML 4.0
 * Description: congruent to
 */
static wchar_t CONGRUENT_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'o', L'n', L'g'};
static wchar_t* CONGRUENT_TO_HTML_CHARACTER_ENTITY = CONGRUENT_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* CONGRUENT_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The almost equal to html character entity.
 *
 * Name: asymp
 * Character: �
 * Unicode code point: U+2248 (8776)
 * Standard: HTML 4.0
 * Description: almost equal to
 */
static wchar_t ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'a', L's', L'y', L'm', L'p'};
static wchar_t* ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY = ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* ALMOST_EQUAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The not equal to html character entity.
 *
 * Name: ne
 * Character: ?
 * Unicode code point: U+2260 (8800)
 * Standard: HTML 4.0
 * Description: not equal to
 */
static wchar_t NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L'e'};
static wchar_t* NOT_EQUAL_TO_HTML_CHARACTER_ENTITY = NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* NOT_EQUAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The identical to (equivalent to)html character entity.
 *
 * Name: equiv
 * Character: =
 * Unicode code point: U+2261 (8801)
 * Standard: HTML 4.0
 * Description: identical to (equivalent to)
 */
static wchar_t IDENTICAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'e', L'q', L'u', L'i', L'v'};
static wchar_t* IDENTICAL_TO_HTML_CHARACTER_ENTITY = IDENTICAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* IDENTICAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The less-than or equal to html character entity.
 *
 * Name: le
 * Character: =
 * Unicode code point: U+2264 (8804)
 * Standard: HTML 4.0
 * Description: less-than or equal to
 */
static wchar_t LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'e'};
static wchar_t* LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY = LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* LESS_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The greater-than or equal to html character entity.
 *
 * Name: ge
 * Character: =
 * Unicode code point: U+2265 (8805)
 * Standard: HTML 4.0
 * Description: greater-than or equal to
 */
static wchar_t GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L'g', L'e'};
static wchar_t* GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY = GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* GREATER_THAN_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_2_INTEGER_ARRAY;

/**
 * The subset of html character entity.
 *
 * Name: sub
 * Character: ?
 * Unicode code point: U+2282 (8834)
 * Standard: HTML 4.0
 * Description: subset of
 */
static wchar_t SUBSET_OF_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'b'};
static wchar_t* SUBSET_OF_HTML_CHARACTER_ENTITY = SUBSET_OF_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUBSET_OF_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The superset of html character entity.
 *
 * Name: sup
 * Character: ?
 * Unicode code point: U+2283 (8835)
 * Standard: HTML 4.0
 * Description: superset of
 */
static wchar_t SUPERSET_OF_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'p'};
static wchar_t* SUPERSET_OF_HTML_CHARACTER_ENTITY = SUPERSET_OF_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUPERSET_OF_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The not a subset of html character entity.
 *
 * Name: nsub
 * Character: ?
 * Unicode code point: U+2284 (8836)
 * Standard: HTML 4.0
 * Description: not a subset of
 */
static wchar_t NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_ARRAY[] = {L'n', L's', L'u', L'b'};
static wchar_t* NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY = NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_ARRAY;
static int* NOT_A_SUBSET_OF_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The subset of or equal to html character entity.
 *
 * Name: sube
 * Character: ?
 * Unicode code point: U+2286 (8838)
 * Standard: HTML 4.0
 * Description: subset of or equal to
 */
static wchar_t SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'b', L'e'};
static wchar_t* SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY = SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUBSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The superset of or equal to html character entity.
 *
 * Name: supe
 * Character: ?
 * Unicode code point: U+2287 (8839)
 * Standard: HTML 4.0
 * Description: superset of or equal to
 */
static wchar_t SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'u', L'p', L'e'};
static wchar_t* SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY = SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_ARRAY;
static int* SUPERSET_OF_OR_EQUAL_TO_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The circled plus html character entity.
 *
 * Name: oplus
 * Character: ?
 * Unicode code point: U+2295 (8853)
 * Standard: HTML 4.0
 * Description: circled plus
 */
static wchar_t CIRCLED_PLUS_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L'p', L'l', L'u', L's'};
static wchar_t* CIRCLED_PLUS_HTML_CHARACTER_ENTITY = CIRCLED_PLUS_HTML_CHARACTER_ENTITY_ARRAY;
static int* CIRCLED_PLUS_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The circled times html character entity.
 *
 * Name: otimes
 * Character: ?
 * Unicode code point: U+2297 (8855)
 * Standard: HTML 4.0
 * Description: circled times
 */
static wchar_t CIRCLED_TIMES_HTML_CHARACTER_ENTITY_ARRAY[] = {L'o', L't', L'i', L'm', L'e', L's'};
static wchar_t* CIRCLED_TIMES_HTML_CHARACTER_ENTITY = CIRCLED_TIMES_HTML_CHARACTER_ENTITY_ARRAY;
static int* CIRCLED_TIMES_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The up tack (perpendicular sign in math)html character entity.
 *
 * Name: perp
 * Character: ?
 * Unicode code point: U+22A5 (8869)
 * Standard: HTML 4.0
 * Description: up tack (perpendicular sign in math)
 */
static wchar_t UP_TACK_HTML_CHARACTER_ENTITY_ARRAY[] = {L'p', L'e', L'r', L'p'};
static wchar_t* UP_TACK_HTML_CHARACTER_ENTITY = UP_TACK_HTML_CHARACTER_ENTITY_ARRAY;
static int* UP_TACK_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The dot operator html character entity.
 *
 * Name: sdot
 * Character: �
 * Unicode code point: U+22C5 (8901)
 * Standard: HTML 4.0
 * Description: dot operator
 */
static wchar_t DOT_OPERATOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'd', L'o', L't'};
static wchar_t* DOT_OPERATOR_HTML_CHARACTER_ENTITY = DOT_OPERATOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* DOT_OPERATOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The left ceiling html character entity.
 *
 * Name: lceil
 * Character: ?
 * Unicode code point: U+2308 (8968)
 * Standard: HTML 4.0
 * Description: left ceiling
 */
static wchar_t LEFT_CEILING_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'c', L'e', L'i', L'l'};
static wchar_t* LEFT_CEILING_HTML_CHARACTER_ENTITY = LEFT_CEILING_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_CEILING_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The right ceiling html character entity.
 *
 * Name: rceil
 * Character: ?
 * Unicode code point: U+2309 (8969)
 * Standard: HTML 4.0
 * Description: right ceiling
 */
static wchar_t RIGHT_CEILING_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'c', L'e', L'i', L'l'};
static wchar_t* RIGHT_CEILING_HTML_CHARACTER_ENTITY = RIGHT_CEILING_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_CEILING_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The left floor html character entity.
 *
 * Name: lfloor
 * Character: ?
 * Unicode code point: U+230A (8970)
 * Standard: HTML 4.0
 * Description: left floor
 */
static wchar_t LEFT_FLOOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'f', L'l', L'o', L'o', L'r'};
static wchar_t* LEFT_FLOOR_HTML_CHARACTER_ENTITY = LEFT_FLOOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_FLOOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The right floor html character entity.
 *
 * Name: rfloor
 * Character: ?
 * Unicode code point: U+230B (8971)
 * Standard: HTML 4.0
 * Description: right floor
 */
static wchar_t RIGHT_FLOOR_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'f', L'l', L'o', L'o', L'r'};
static wchar_t* RIGHT_FLOOR_HTML_CHARACTER_ENTITY = RIGHT_FLOOR_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_FLOOR_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The left-pointing angle bracket html character entity.
 *
 * Name: lang
 * Character: <
 * Unicode code point: U+2329 (9001)
 * Standard: HTML 4.0
 * Description: left-pointing angle bracket
 */
static wchar_t LEFT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'a', L'n', L'g'};
static wchar_t* LEFT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY = LEFT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_ARRAY;
static int* LEFT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The right-pointing angle bracket html character entity.
 *
 * Name: rang
 * Character: >
 * Unicode code point: U+232A (9002)
 * Standard: HTML 4.0
 * Description: right-pointing angle bracket
 */
static wchar_t RIGHT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_ARRAY[] = {L'r', L'a', L'n', L'g'};
static wchar_t* RIGHT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY = RIGHT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_ARRAY;
static int* RIGHT_POINTING_ANGLE_BRACKET_HTML_CHARACTER_ENTITY_COUNT = NUMBER_4_INTEGER_ARRAY;

/**
 * The lozenge html character entity.
 *
 * Name: loz
 * Character: ?
 * Unicode code point: U+25CA (9674)
 * Standard: HTML 4.0
 * Description: lozenge
 */
static wchar_t LOZENGE_HTML_CHARACTER_ENTITY_ARRAY[] = {L'l', L'o', L'z'};
static wchar_t* LOZENGE_HTML_CHARACTER_ENTITY = LOZENGE_HTML_CHARACTER_ENTITY_ARRAY;
static int* LOZENGE_HTML_CHARACTER_ENTITY_COUNT = NUMBER_3_INTEGER_ARRAY;

/**
 * The black spade suit html character entity.
 *
 * Name: spades
 * Character: ?
 * Unicode code point: U+2660 (9824)
 * Standard: HTML 4.0
 * Description: black spade suit
 */
static wchar_t BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_ARRAY[] = {L's', L'p', L'a', L'd', L'e', L's'};
static wchar_t* BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY = BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_ARRAY;
static int* BLACK_SPADE_SUIT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The black club suit html character entity.
 *
 * Name: clubs
 * Character: ?
 * Unicode code point: U+2663 (9827)
 * Standard: HTML 4.0
 * Description: black club suit
 */
static wchar_t BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'c', L'l', L'u', L'b', L's'};
static wchar_t* BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY = BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_ARRAY;
static int* BLACK_CLUB_SUIT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The black heart suit html character entity.
 *
 * Name: hearts
 * Character: ?
 * Unicode code point: U+2665 (9829)
 * Standard: HTML 4.0
 * Description: black heart suit
 */
static wchar_t BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'h', L'e', L'a', L'r', L't', L's'};
static wchar_t* BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY = BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_ARRAY;
static int* BLACK_HEART_SUIT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The black diamond suit html character entity.
 *
 * Name: diams
 * Character: ?
 * Unicode code point: U+2666 (9830)
 * Standard: HTML 4.0
 * Description: black diamond suit
 */
static wchar_t BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_ARRAY[] = {L'd', L'i', L'a', L'm', L's'};
static wchar_t* BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY = BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_ARRAY;
static int* BLACK_DIAMOND_SUIT_HTML_CHARACTER_ENTITY_COUNT = NUMBER_5_INTEGER_ARRAY;

/* HTML_CHARACTER_ENTITY_CONSTANTS_SOURCE */
#endif
