/*
 * $RCSfile: unicode_character_encoding_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
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
 * @version $Revision: 1.4 $ $Date: 2008-05-06 22:36:52 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNICODE_CHARACTER_ENCODING_CONSTANTS_SOURCE
#define UNICODE_CHARACTER_ENCODING_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/**
 * The utf-7 unicode character encoding.
 *
 * An older, relatively unpopular 7-bit encoding, often considered obsolete.
 * It was meant to be used for transmitting Unicode texts via 7 Bit channels
 * (e.g. email or usenet).
 *
 * UTF-7 is not part of The Unicode Standard, but rather an RFC.
 */
static wchar_t UTF_7_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'U', L'T', L'F', L'-', L'7'};
static wchar_t* UTF_7_UNICODE_CHARACTER_ENCODING = UTF_7_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* UTF_7_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The utf-8 unicode character encoding.
 *
 * An 8-bit, variable-width encoding, which maximises compatibility with ASCII.
 * UTF-8 uses one to four bytes per code point and, being compact for Latin
 * scripts and ASCII-compatible, provides the de facto standard encoding for
 * interchange of Unicode text.
 * Its first 7 Bits are used as in the ASCII character set. The 8th Bit can
 * commence a longer Unicode character, which extends to either 2, 3 or 4 Byte.
 *
 * It is popular in UNIX-like operating system environments and also used by
 * most recent GNU/Linux distributions as a direct replacement for legacy
 * encodings in general text handling.
 */
static wchar_t UTF_8_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'U', L'T', L'F', L'-', L'8'};
static wchar_t* UTF_8_UNICODE_CHARACTER_ENCODING = UTF_8_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* UTF_8_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_5_INTEGER_ARRAY;

/**
 * The cesu-8 unicode character encoding.
 *
 * The Unicode areas U+D800�U+DBFF and U+DC00�U+DFFF are explicitly no characters,
 * and only used in UTF-16 to encode characters outside the Basic Multilingual Plane.
 * They were formerly also called "Low-" und "High surrogates".
 * Hence, byte orders that correspond to these areas, are NOT valid UTF-8.
 * For example, U+10400 is represented as D801,DC00 in UTF-16, but should be
 * expressed as F0,90,90,80 and NOT ED,A0,81,ED,B0,80 in UTF-8.
 *
 * Java supports this since version 1.5. But due to the wide spread of the
 * encoding, especially in databases, it was standardised as "CESU-8".
 */
static wchar_t CESU_8_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'C', L'E', L'S', L'U', L'-', L'8'};
static wchar_t* CESU_8_UNICODE_CHARACTER_ENCODING = CESU_8_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* CESU_8_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The utf-16 unicode character encoding.
 *
 * A 16-bit, variable-width encoding.
 *
 * The UCS-2 and UTF-16 encodings specify the Unicode Byte Order Mark (BOM) for
 * use at the beginnings of text files, which may be used for byte ordering
 * detection (or byte endianness detection).
 * Some software developers have adopted it for other encodings, including UTF-8,
 * which does not need an indication of byte order. In this case it attempts to
 * mark the file as containing Unicode text. The BOM, code point U+FEFF has the
 * important property of unambiguity on byte reorder, regardless of the Unicode
 * encoding used; U+FFFE (the result of byte-swapping U+FEFF) does not equate
 * to a legal character, and U+FEFF in other places, other than the beginning
 * of text, conveys the zero-width no-break space (a character with no
 * appearance and no effect other than preventing the formation of ligatures).
 * Also, the units FE and FF never appear in UTF-8.
 * The same character converted to UTF-8 becomes the byte sequence EF BB BF.
 */
static wchar_t UTF_16_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'U', L'T', L'F', L'-', L'1', L'6'};
static wchar_t* UTF_16_UNICODE_CHARACTER_ENCODING = UTF_16_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* UTF_16_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The utf-32 unicode character encoding.
 *
 * A 32-bit, fixed-width encoding, that is easy to use.
 *
 * In UTF-32 and UCS-4, one 32-bit code value serves as a fairly direct
 * representation of any character's code point (although the endianness,
 * which varies across different platforms, affects how the code value actually
 * manifests as an octet sequence). In the other cases, each code point may be
 * represented by a variable number of code values.
 *
 * UTF-32 is widely used as internal representation of text in programs
 * (as opposed to stored or transmitted text), since every Unix operating
 * system which uses the gcc compilers to generate software uses it as the
 * standard "wide character" encoding.
 * Recent versions of the python programming language (beginning with 2.2) may
 * also be configured to use UTF-32 as the representation for unicode strings,
 * effectively disseminating such encoding in high-level coded software.
 */
static wchar_t UTF_32_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'U', L'T', L'F', L'-', L'3', L'2'};
static wchar_t* UTF_32_UNICODE_CHARACTER_ENCODING = UTF_32_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* UTF_32_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_6_INTEGER_ARRAY;

/**
 * The utf-ebcdic unicode character encoding.
 *
 * An 8-bit variable-width encoding, and Unicode extension.
 * It is based on and maximises compatibility with the proprietary EBCDIC
 * format of IBM mainframe computers, as it was developed in order to ease the
 * processing of Unicode data on existing mainframe applications.
 *
 * However, it is rarely used in practice, on mainframe computers either. IBM
 * EBCDIC-based mainframe operating systems like z/OS normally use UTF-16.
 * Moreover, UTF-16 is supported by components like DB2 UDB, COBOL, PL/I, Java
 * and the IBM XML Toolkit.
 *
 * UTF-EBCDIC is not part of The Unicode Standard.
 */
static wchar_t UTF_EBCDIC_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'U', L'T', L'F', L'-', L'E', L'B', L'C', L'D', L'I', L'C'};
static wchar_t* UTF_EBCDIC_UNICODE_CHARACTER_ENCODING = UTF_EBCDIC_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* UTF_EBCDIC_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_10_INTEGER_ARRAY;

/**
 * The utf-scsu unicode character encoding.
 *
 * The Standard Compression Scheme for Unicode (SCSU) is a Unicode Technical
 * Standard for reducing the number of bytes needed to represent Unicode text,
 * especially if that text uses mostly characters from one or a small number of
 * per-language character blocks. It does so by dynamically mapping values in
 * the range 128�255 to offsets within particular blocks of 128 characters.
 *
 * The initial conditions of the encoder mean that existing strings in ASCII
 * and ISO-8859-1 that do not contain C0 control codes other than NULL TAB CR
 * and LF can be treated as SCSU strings. Since most alphabets do reside in
 * blocks of contiguous Unicode codepoints, texts that use small alphabets and
 * either ascii punctuation or punctuation that fits within the window for the
 * main alphabet can be encoded at one byte per character (plus setup overhead,
 * which for common languages is often only 1 byte), most other punctuation can
 * be encoded at 2 bytes per symbol through non-locking shifts.
 *
 * SCSU can also switch to UTF-16 internally to handle non-alphabetic languages.
 *
 * Reuters, the organization that floated the first draft of SCSU, is believed
 * to use SCSU internally.
 *
 * SCSU has not been a resounding success. Few applications need to compress so
 * much Unicode text that it's worth using a special-purpose compression scheme
 * which (so far) does not have widespread support. Also, while it can be used
 * as a text encoding, it can be difficult to handle internally.
 *
 * Treated purely as a compression algorithm, SCSU is inferior to most
 * commonly-used general-purpose algorithms for texts of over a few kilobytes.
 * The real problem with SCSU is then that the savings of SCSU versus UTF-16 or
 * UTF-8 drop after external compression[citation needed], often dramatically so.
 *
 * SCSU does have the advantage that it can usefully compress texts that are
 * only a few characters long, whereas most full-scale compressors need a few
 * kilobytes of data to break even against their own overhead.
 */
static wchar_t UTF_SCSU_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'U', L'T', L'F', L'-', L'S', L'C', L'S', L'U'};
static wchar_t* UTF_SCSU_UNICODE_CHARACTER_ENCODING = UTF_SCSU_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* UTF_SCSU_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_8_INTEGER_ARRAY;

/**
 * The punycode unicode character encoding.
 *
 * Punycode enables the encoding of Unicode strings into the limited character
 * set supported by the ASCII-based Domain Name System.
 *
 * The encoding is used as part of IDNA, which is a system enabling the use of
 * Internationalized Domain Names in all languages that are supported by Unicode.
 */
static wchar_t PUNYCODE_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'P', L'u', L'n', L'y', L'c', L'o', L'd', L'e'};
static wchar_t* PUNYCODE_UNICODE_CHARACTER_ENCODING = PUNYCODE_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* PUNYCODE_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_8_INTEGER_ARRAY;

/**
 * The gb18030 unicode character encoding.
 *
 * GB18030 is defined by the Standardization Administration of China.
 * It is the official character set of the People's Republic of China (PRC).
 */
static wchar_t GB18030_UNICODE_CHARACTER_ENCODING_ARRAY[] = {L'G', L'B', L'1', L'8', L'0', L'3', L'0'};
static wchar_t* GB18030_UNICODE_CHARACTER_ENCODING = GB18030_UNICODE_CHARACTER_ENCODING_ARRAY;
static int* GB18030_UNICODE_CHARACTER_ENCODING_COUNT = NUMBER_7_INTEGER_ARRAY;

/* UNICODE_CHARACTER_ENCODING_CONSTANTS_SOURCE */
#endif
