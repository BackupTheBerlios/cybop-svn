/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: iso_8859_character_set_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ISO_8859_CHARACTER_SET_MODEL_SOURCE
#define ISO_8859_CHARACTER_SET_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains iso-8859 character set constants.
//

/**
 * The iso-8859-1 character set model.
 *
 * ISO 8859 part 1. Latin-1. Western European.
 *
 * Perhaps the most widely used part of ISO 8859, covering most Western European languages:
 * Danish, Dutch (partial[1]), English, Faeroese, Finnish (partial[2]), French (partial[2]),
 * German, Icelandic, Irish, Italian, Norwegian, Portuguese, Rhaeto-Romanic, Scottish Gaelic,
 * Spanish, and Swedish.
 * Languages from other parts of the world are also covered, including:
 * Eastern European Albanian, Southeast Asian Indonesian, as well as the African languages
 * Afrikaans and Swahili.
 * The missing euro sign and capital Ÿ are in the revised version ISO 8859-15.
 * The corresponding IANA-approved character set ISO-8859-1 is the default encoding
 * for legacy HTML documents and for documents transmitted via MIME messages,
 * such as HTTP responses when the document's media type is "text" (as in "text/html").
 */
static wchar_t ISO_8859_1_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1'};
static wchar_t* ISO_8859_1_CHARACTER_SET_MODEL = ISO_8859_1_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_1_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-2 character set model.
 *
 * ISO 8859 part 2. Latin-2. Central European.
 *
 * Supports those Central and Eastern European languages that use the Latin alphabet, including
 * Bosnian, Polish, Croatian, Czech, Slovak, Slovenian, Serbian, and Hungarian.
 * The missing euro sign can be found in version ISO 8859-16.
 */
static wchar_t ISO_8859_2_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'2'};
static wchar_t* ISO_8859_2_CHARACTER_SET_MODEL = ISO_8859_2_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_2_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-3 character set model.
 *
 * ISO 8859 part 3. Latin-3. South European.
 *
 * Turkish, Maltese, and Esperanto.
 * Largely superseded by ISO 8859-9 for Turkish and Unicode for Esperanto.
 */
static wchar_t ISO_8859_3_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'3'};
static wchar_t* ISO_8859_3_CHARACTER_SET_MODEL = ISO_8859_3_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_3_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-4 character set model.
 *
 * ISO 8859 part 4. Latin-4. North European.
 *
 * Estonian, Latvian, Lithuanian, Greenlandic, and Sami.
 */
static wchar_t ISO_8859_4_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'4'};
static wchar_t* ISO_8859_4_CHARACTER_SET_MODEL = ISO_8859_4_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_4_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-5 character set model.
 *
 * ISO 8859 part 5. Latin/Cyrillic.
 *
 * Covers mostly Slavic languages that use a Cyrillic alphabet, including
 * Belarusian, Bulgarian, Macedonian, Russian, Serbian, and Ukrainian (partial[3]).
 */
static wchar_t ISO_8859_5_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'5'};
static wchar_t* ISO_8859_5_CHARACTER_SET_MODEL = ISO_8859_5_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_5_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-6 character set model.
 *
 * ISO 8859 part 6. Latin/Arabic.
 *
 * Covers the most common Arabic language characters.
 * Doesn't support other languages using the Arabic script.
 * Needs to be BiDi and cursive joining processed for display.
 */
static wchar_t ISO_8859_6_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'6'};
static wchar_t* ISO_8859_6_CHARACTER_SET_MODEL = ISO_8859_6_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_6_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-7 character set model.
 *
 * ISO 8859 part 7. Latin/Greek.
 *
 * Covers the modern Greek language (monotonic orthography).
 * Can also be used for Ancient Greek written without accents or in
 * monotonic orthography, but lacks the diacritics for polytonic orthography.
 * These were introduced with Unicode.
 */
static wchar_t ISO_8859_7_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'7'};
static wchar_t* ISO_8859_7_CHARACTER_SET_MODEL = ISO_8859_7_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_7_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-8 character set model.
 *
 * ISO 8859 part 8. Latin/Hebrew.
 *
 * Covers the modern Hebrew alphabet as used in Israel.
 * In practice two different encodings exist, logical order
 * (needs to be BiDi processed for display) and visual (left-to-right)
 * order (in effect, after bidi processing and line breaking).
 */
static wchar_t ISO_8859_8_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'8'};
static wchar_t* ISO_8859_8_CHARACTER_SET_MODEL = ISO_8859_8_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_8_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-9 character set model.
 *
 * ISO 8859 part 9. Latin-5. Turkish.
 *
 * Largely the same as ISO 8859-1, replacing the rarely used Icelandic letters
 * with Turkish ones. It is also used for Kurdish.
 */
static wchar_t ISO_8859_9_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'9'};
static wchar_t* ISO_8859_9_CHARACTER_SET_MODEL = ISO_8859_9_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_9_CHARACTER_SET_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-10 character set model.
 *
 * ISO 8859 part 10. Latin-6. Nordic.
 *
 * A rearrangement of Latin-4.
 * Considered more useful for Nordic languages. Baltic languages use Latin-4 more.
 */
static wchar_t ISO_8859_10_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'0'};
static wchar_t* ISO_8859_10_CHARACTER_SET_MODEL = ISO_8859_10_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_10_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-11 character set model.
 *
 * ISO 8859 part 11. Latin/Thai.
 *
 * Contains most characters needed for the Thai language.
 * Same as TIS 620.
 */
static wchar_t ISO_8859_11_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'1'};
static wchar_t* ISO_8859_11_CHARACTER_SET_MODEL = ISO_8859_11_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_11_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-12 character set model.
 *
 * ISO 8859 part 12. Latin/Devanagari. Non-existent!
 *
 * The work in making a part of 8859 for Devanagari was officially abandoned in 1997.
 * ISCII and Unicode/ISO/IEC 10646 cover Devanagari.
 */
static wchar_t ISO_8859_12_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'2'};
static wchar_t* ISO_8859_12_CHARACTER_SET_MODEL = ISO_8859_12_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_12_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-13 character set model.
 *
 * ISO 8859 part 13. Latin-7. Baltic Rim.
 *
 * Added some characters for Baltic languages which were missing from Latin-4 and Latin-6.
 */
static wchar_t ISO_8859_13_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'3'};
static wchar_t* ISO_8859_13_CHARACTER_SET_MODEL = ISO_8859_13_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_13_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-14 character set model.
 *
 * ISO 8859 part 14. Latin-8. Celtic.
 *
 * Covers Celtic languages such as Gaelic and the Breton language.
 */
static wchar_t ISO_8859_14_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'4'};
static wchar_t* ISO_8859_14_CHARACTER_SET_MODEL = ISO_8859_14_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_14_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-15 character set model.
 *
 * ISO 8859 part 15. Latin-9.
 *
 * A revision of 8859-1 that removes some little-used symbols,
 * replacing them with the euro sign € and the letters Š, š, Ž, ž, Œ, œ, and Ÿ,
 * which completes the coverage of French, Finnish and Estonian.
 */
static wchar_t ISO_8859_15_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'5'};
static wchar_t* ISO_8859_15_CHARACTER_SET_MODEL = ISO_8859_15_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_15_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The iso-8859-16 character set model.
 *
 * ISO 8859 part 16. Latin-10. South-Eastern European.
 *
 * Intended for Albanian, Croatian, Hungarian, Italian, Polish, Romanian and Slovenian,
 * but also Finnish, French, German and Irish Gaelic (new orthography).
 * The focus lies more on letters than symbols.
 * The currency sign is replaced with the euro sign.
 */
static wchar_t ISO_8859_16_CHARACTER_SET_MODEL_ARRAY[] = {L'i', L's', L'o', L'-', L'8', L'8', L'5', L'9', L'-', L'1', L'6'};
static wchar_t* ISO_8859_16_CHARACTER_SET_MODEL = ISO_8859_16_CHARACTER_SET_MODEL_ARRAY;
static int* ISO_8859_16_CHARACTER_SET_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/* ISO_8859_CHARACTER_SET_MODEL_SOURCE */
#endif
