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

#ifndef PERCENT_ENCODING_VECTOR_DECODER_SOURCE
#define PERCENT_ENCODING_VECTOR_DECODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/converter/decoder/percent_encoding_decoder.c"
#include "../../../executor/converter/selector/percent_encoding_vector_element_selector.c"
#include "../../../logger/logger.c"

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
 * Decodes the percent-encoded character array element into
 * a non-percent-encoded character array element.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source current position (Hand over as reference!)
 * @param p4 the source remaining count
 */
void decode_percent_encoding_vector_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode percent-encoding vector element.");

            // The unreserved characters.
            void* u = *pos;
            int uc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_percent_encoding_vector_element(p0, p1, p2, (void*) &b, p3, p4);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;

                } else {

                    // Increment unreserved characters count.
                    uc++;
                }
            }

            // Append any unreserved characters found up to here,
            // no matter whether an unreserved character follows
            // or no unreserved character at all was found.
            append_array_elements(p0, p1, p2, u, (void*) &uc, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

            if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // A % sign was found that indicates a reserved character.
                decode_percent_encoding(p0, p1, p2, p3, p4);

                // Process further characters by calling decode function recursively.
                //
                // CAUTION! Only call this function if a reserved character was found.
                // Otherwise, the loop was left due to no more remaining characters,
                // so that nothing is left to be processed here.
                decode_percent_encoding_vector_element(p0, p1, p2, p3, p4);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector element. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector element. The remaining count is null.");
    }
}

/**
 * Decodes the percent-encoded character array into a non-percent-encoded character array.
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
void decode_percent_encoding_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode percent-encoding vector.");

                            //
                            // CAUTION! Do NOT operate with WIDE CHARACTERS here!
                            // The percent-encoding is based upon ASCII characters with just one byte!
                            //

                            // Adjust destination character vector size.
                            //
                            // Whilst a percent-encoded character is represented by 3 Byte
                            // (one for the % sign and two for the hexadecimal digits),
                            // the corresponding decoded ASCII character needs just 1 Byte.
                            //
                            // Therefore, the destination size is set to the source count,
                            // since it can never be larger.
                            *ds = *dc + *sc;

                            // Reallocate destination character vector.
                            reallocate_array(p0, p1, p2, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                            // CAUTION! Hand over p3 as reference.
                            decode_percent_encoding_vector_element(p0, p1, p2, (void*) &p3, p4);

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector. The destination count is negative.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector. The destination is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector. The destination count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector. The destination size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding vector. The source count is null.");
    }
}

/* PERCENT_ENCODING_VECTOR_DECODER_SOURCE */
#endif
