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
 * @version $RCSfile: utf_8_unicode_character_converter.c,v $ $Revision: 1.12 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PERCENT_ENCODING_VECTOR_ENCODER_SOURCE
#define PERCENT_ENCODING_VECTOR_ENCODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
/*??
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../variable/type_size/conversion_type_size.c"
*/

//
// A URI is composed from a limited set of characters consisting of
// digits, letters, and a few graphic symbols. A reserved subset of
// those characters may be used to delimit syntax components within a
// URI while the remaining characters, including both the unreserved set
// and those reserved characters not acting as delimiters, define each
// component's identifying data.
//
// A percent-encoding mechanism is used to represent a data octet in a
// component when that octet's corresponding character is outside the
// allowed set or is being used as a delimiter of, or within, the component.
// A percent-encoded octet is encoded as a character triplet,
// consisting of the percent character "%" followed by the two
// hexadecimal digits representing that octet's numeric value.
//
// Example:
//
// percent-encoding: %20
// binary octet: 00100000
// ABNF: %x20
// US-ASCII: space character (SP)
//
// The uppercase hexadecimal digits 'A' through 'F' are equivalent to
// the lowercase digits 'a' through 'f', respectively. If two URIs
// differ only in the case of hexadecimal digits used in percent-encoded
// octets, they are equivalent. For consistency, URI producers and
// normalisers should use uppercase hexadecimal digits for all
// percent-encodings.
//
// Reserved characters:
// - generic delimiters: : / ? # [ ] @
// - sub delimiters: ! $ & ' ( ) * + , ; =
//
// URI producing applications should percent-encode data octets that
// correspond to characters in the reserved set unless these characters
// are specifically allowed by the URI scheme to represent data in that
// component. If a reserved character is found in a URI component and
// no delimiting role is known for that character, then it must be
// interpreted as representing the data octet corresponding to that
// character's encoding in US-ASCII.
//
// Characters that are allowed in a URI but do not have a reserved
// purpose are called unreserved. These include uppercase and lowercase
// letters, decimal digits, hyphen, period, underscore, and tilde.
//
// Unreserved characters: ALPHA DIGIT - . _ ~
//
// URIs that differ in the replacement of an unreserved character
// with its corresponding percent-encoded US-ASCII octet are
// equivalent: they identify the same resource. However, URI
// comparison implementations do not always perform normalisation
// prior to comparison. For consistency, percent-encoded octets
// in the ranges of:
// - ALPHA (%41-%5A and %61-%7A)
// - DIGIT (%30-%39)
// - hyphen (%2D)
// - period (%2E)
// - underscore (%5F)
// - tilde (%7E)
// should NOT BE created by URI producers and, when found in a URI,
// SHOULD BE decoded to their corresponding unreserved characters.
//
// http://tools.ietf.org/html/rfc3986
// (Chapter 2 "Characters")
//

/**
 * Encodes a non-percent-encoded character array into a percent-encoded character array.
 *
 * According to the URI specification, percent-encoding (escaping)
 * should ONLY be applied to RESERVED characters:
 *
 * - generic delimiters: : / ? # [ ] @
 * - sub delimiters: ! $ & ' ( ) * + , ; =
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the percent-encoded source character array
 * @param p4 the percent-encoded source character array count
 */
void encode_percent_encoding_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT operate with WIDE CHARACTERS here!
    // The percent-encoding is based upon ASCII characters with just one byte!
    //

    // The new destination character vector size.
    //
    // CAUTION! The "worst case" is assumed, i.e. that each source character
    // represents a percent-encoded ascii character sequence with THREE bytes:
    // one for the % sign and two for the hexadecimal digits.
    // Therefore, the destination size is adjusted accordingly.
    //
    // In case not all source characters are percent-encoded -- even better,
    // since then one destination character represents one source character
    // and the destination character array will have LESS entries (count)
    // than the destination size that was set before.
    // In this case, the destination size will be too big, but can be
    // reduced to the actual destination count later, if so wanted.
    *ds = *dc + (*sc * *NUMBER_3_INTEGER_MEMORY_MODEL);

    // Reallocate destination character vector.
    reallocate_array(p0, p1, p2, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Convert percent-encoded characters into ASCII characters.

    //?? TODO: Add decoding here! Map % encoding sequences to characters!
}

/* PERCENT_ENCODING_VECTOR_ENCODER_SOURCE */
#endif
