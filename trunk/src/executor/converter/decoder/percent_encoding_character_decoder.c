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
 * @version $RCSfile: utf_8_unicode_character_converter.c,v $ $Revision: 1.12 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PERCENT_ENCODING_CHARACTER_DECODER_SOURCE
#define PERCENT_ENCODING_CHARACTER_DECODER_SOURCE

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
// Reflexions on character set conversion.
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
 * Decodes a percent-encoded character array into a non-percent-encoded character array.
 *
 * All percent-encoded (escaped) characters are resolved,
 * no matter whether or not they are reserved characters
 * according to the URI specification.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the percent-encoded source character array
 * @param p4 the percent-encoded source character array count
 */
void decode_percent_encoding_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            char* s = (char*) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ds = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* dc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        char** d = (char**) p0;

                        if (*dc >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode percent-encoding character vector.");

/*??
                            // The new destination wide character vector size.
                            //
                            // CAUTION! The "worst case" is assumed, i.e. that each source character
                            // represents an ascii character encoded by utf-8 with ONE single byte.
                            // Therefore, the destination size is adjusted accordingly.
                            // In case not all source characters are ascii characters -- even better,
                            // since then more than just one source character were used for encoding,
                            // and the destination wide character array will have LESS entries (count)
                            // than the destination size that was set before.
                            // In this case, the destination size will be too big, but can be reduced
                            // to the actual destination count below, if so wanted.
                            *ds = *dc + (*sc * *NUMBER_1_INTEGER_MEMORY_MODEL);

                            // Reallocate destination wide character vector.
                            reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                            // Converts the multibyte character string into a wide character string.
                            //
                            // Returns the number of wide characters converted.
//??                            int n = mbsnrtowcs(*d, &s, *sc, *ds, &st);
                            int n = mbsnrtowcs(*d, (const char**) &s, *sc, *ds, *NULL_POINTER_MEMORY_MODEL);

                            if (n >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // Increment destination count by the number of wide characters converted.
                                *dc = *dc + n;
                            }
*/

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding character stream. The destination count is negative.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding character stream. The destination is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding character stream. The destination count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding character stream. The destination size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding character stream. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding character stream. The source count is null.");
    }
}

/* PERCENT_ENCODING_CHARACTER_DECODER_SOURCE */
#endif
