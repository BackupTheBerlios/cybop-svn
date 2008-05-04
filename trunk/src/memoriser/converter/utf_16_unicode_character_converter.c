/*
 * $RCSfile: utf_16_unicode_character_converter.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2008-05-04 00:18:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UTF_16_UNICODE_CHARACTER_CONVERTER_SOURCE
#define UTF_16_UNICODE_CHARACTER_CONVERTER_SOURCE

#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/logger/logger.c"

//
// In computing, UTF-16 (16-bit Unicode Transformation Format) is a variable-
// length character encoding for Unicode, capable of encoding the entire
// Unicode repertoire.
//
// The encoding form maps code points (characters) into a sequence of 16-bit
// words, called code units. For characters in the Basic Multilingual Plane (BMP),
// the resulting encoding is a single 16-bit word. For characters in the other
// planes, the encoding will result in a pair of 16-bit words, together called
// a surrogate pair. All possible code points from U+0000 through U+10FFFF, except
// for the surrogate code points U+D800�U+DFFF, are uniquely mapped by UTF-16
// regardless of the code point's current or future character assignment or use.
//
// As many uses in computing require units of bytes (octets), there are three
// related encoding schemes which map to octet sequences instead of words:
// namely UTF-16, UTF-16BE, and UTF-16LE. They differ only in the byte order
// chosen to represent each 16-bit unit and whether they make use of a
// Byte Order Mark (BOM). All of the schemes will result in either a 2 or 4-byte
// sequence for any given character.
//
// UTF-16 is officially defined in Annex Q of the international standard
// ISO/IEC 10646-1. It is also described in The Unicode Standard version 3.0
// and higher, as well as in the IETF's RFC 2781.
//
// UCS-2 (2-byte Universal Character Set) is an obsolete character encoding
// which is a predecessor to UTF-16. The UCS-2 encoding form is nearly
// identical to that of UTF-16, except that it does not support surrogate pairs
// and therefore can only encode characters in the BMP range U+0000 through U+FFFF.
// As a consequence it is a fixed-length encoding that always encodes characters
// into a single 16-bit value. As with UTF-16, there are three related encoding schemes:
// UCS-2, UCS-2BE, UCS-2LE, that map characters to a specific byte sequence.
//
// Because of the technical similarities and upwards compatibility from UCS-2
// to UTF-16, the two encodings are often erroneously conflated and used as if
// interchangeable, so that strings encoded in UTF-16 are sometimes misidentified
// as being encoded in UCS-2.
//
// For both UTF-16 and UCS-2, all 65,536 code points contained within the BMP
// (Plane 0), excluding the 2,048 special surrogate code points, are assigned
// to code units in a one-to-one correspondence with the 16-bit non-negative
// integers with the same values. Thus code point U+0000 is encoded as the
// number 0, and U+FFFF is encoded as 65535 (which is FFFF16 in hexadecimal).
//

/**
 * Decodes an UTF-16 Unicode character stream into an UTF-32 Unicode wide character array.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source UTF-16 Unicode character stream
 * @param p4 the source UTF-16 Unicode character stream count
 */
void decode_utf_16_unicode_character_stream(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode UTF-16 Unicode character stream.");
}

/**
 * Encodes an UTF-32 Unicode wide character array into an UTF-16 Unicode character stream.
 *
 * @param p0 the destination UTF-16 Unicode character stream (Hand over as reference!)
 * @param p1 the destination UTF-16 Unicode character stream count
 * @param p2 the destination UTF-16 Unicode character stream size
 * @param p3 the source wide character array
 * @param p4 the source wide character array count
 */
void encode_utf_16_unicode_character_stream(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode UTF-16 Unicode character stream.");
}

/* UTF_16_UNICODE_CHARACTER_CONVERTER_SOURCE */
#endif
