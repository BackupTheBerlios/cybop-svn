/*
 * $RCSfile: utf_8_unicode_character_converter.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2008-05-16 23:15:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UTF_8_UNICODE_CHARACTER_CONVERTER_SOURCE
#define UTF_8_UNICODE_CHARACTER_CONVERTER_SOURCE

#include "../../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../../globals/constants/integer/integer_constants.c"
#include "../../../globals/constants/log/log_message_constants.c"
#include "../../../globals/constants/memory_structure/array_constants.c"
#include "../../../globals/constants/pointer/pointer_constants.c"
#include "../../../globals/logger/logger.c"

//
// UTF-8 (8-bit UCS/Unicode Transformation Format) is a variable-length
// character encoding for Unicode.
//
// It is able to represent any character in the Unicode standard, yet the
// initial encoding of byte codes and character assignments for UTF-8 is
// backwards compatible with ASCII. For these reasons, it is steadily becoming
// the preferred encoding for e-mail, web pages, and other places where
// characters are stored or streamed.
//
// UTF-8 encodes each character in one to four octets (8-bit bytes):
// 1 One byte is needed to encode the 128 US-ASCII characters
//   (Unicode range U+0000 to U+007F)
// 2 Two bytes are needed for Latin letters with diacritics and for characters
//   from Greek, Cyrillic, Armenian, Hebrew, Arabic, Syriac and Thaana alphabets
//   (Unicode range U+0080 to U+07FF)
// 3 Three bytes are needed for the rest of the Basic Multilingual Plane
//   (which contains virtually all characters in common use)
// 4 Four bytes are needed for characters in the other planes of Unicode,
//   which are rarely used in practice
//
// Four bytes may seem like a lot for one character (code point). However,
// code points outside the Basic Multilingual Plane are generally very rare.
// Furthermore, UTF-16 (the main alternative to UTF-8) also needs four bytes
// for these code points. Whether UTF-8 or UTF-16 is more efficient depends
// on the range of code points being used. However, the differences between
// different encoding schemes can become negligible with the use of
// traditional compression systems like DEFLATE. For short items of text
// where traditional algorithms do not perform well and size is important,
// the Standard Compression Scheme for Unicode could be considered instead.
//
// The Internet Engineering Task Force (IETF) requires all Internet protocols
// to identify the encoding used for character data with UTF-8 as at least one
// supported encoding. The Internet Mail Consortium (IMC) recommends that all
// email programs be able to display and create mail using UTF-8.
//

/**
 * Decodes an (external) UTF-8 Unicode multibyte character stream into an (internal) UTF-32 Unicode wide character vector.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source UTF-8 Unicode multibyte character stream
 * @param p4 the source UTF-8 Unicode multibyte character stream count
 */
void decode_utf_8_unicode_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        size_t* sc = (size_t*) p4;

        if (p2 != *NULL_POINTER) {

            size_t* ds = (size_t*) p2;

            if (p1 != *NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    wchar_t** d = (wchar_t**) p0;

                    if (*dc >= *NUMBER_0_INTEGER) {

                        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode UTF-8 Unicode character vector.");

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
                        *ds = *dc + (*sc * *NUMBER_1_INTEGER);

                        // Reallocate destination wide character vector.
                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);

                        if (*dc <= (*ds - (*sc * *NUMBER_1_INTEGER))) {

                            // The state of the conversion.
                            //
                            // In the introduction of this chapter it was said that
                            // certain character sets use a stateful encoding.
                            // That is, the encoded values depend in some way
                            // on the previous bytes in the text.
                            //
                            // Since the conversion functions allow converting a text
                            // in more than one step, there must be a way to pass this
                            // information from one call of the functions to another.
                            //
                            // A variable of type mbstate_t can contain all the
                            // information about the shift state needed from one call
                            // to a conversion function to another.
                            mbstate_t st;

                            // Clear the whole conversion state variable.
                            //
                            // There is no specific function or initializer to put the
                            // state object in any specific state. The rules are that
                            // the object should always represent the initial state
                            // before the first use and this is achieved here.
                            memset((void*) &st, '\0', sizeof(st));

                            // Converts the multibyte character string into a wide character string.
                            //
                            // Returns the number of wide characters converted.
                            int n = mbsnrtowcs(*d, (void*) &p3, *sc, *ds, st);

                            if (n >= *NUMBER_0_INTEGER) {

                                // Increment destination count by the number of wide characters converted.
                                *dc = *dc + n;

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The conversion failed, possibly due to an invalid multibyte sequence.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The destination count exceeds the size.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The destination count is negative.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The source count is null.");
    }
}

/**
 * Encodes an UTF-32 Unicode wide character vector into an UTF-8 Unicode multibyte character stream.
 *
 * @param p0 the destination UTF-8 Unicode multibyte character stream (Hand over as reference!)
 * @param p1 the destination UTF-8 Unicode multibyte character stream count
 * @param p2 the destination UTF-8 Unicode multibyte character stream size
 * @param p3 the source wide character array
 * @param p4 the source wide character array count
 */
void encode_utf_8_unicode_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode UTF-8 Unicode character vector.");

                    // The new destination wide character vector size.
                    //
                    // CAUTION! The "worst case" is assumed, i.e. that each source wide character
                    // represents a non-ascii character encoded by utf-8 with FOUR single bytes.
                    // Therefore, the destination size is adjusted accordingly.
                    // In case some source wide characters are ascii characters -- even better,
                    // since then less than four destination characters are used for encoding,
                    // and the destination character array will have LESS entries (count)
                    // than the destination size that was set before.
                    // In this case, the destination size will be too big, but can be reduced
                    // to the actual destination count below, if so wanted.
                    *ds = (*dc * *CHARACTER_VECTOR_REALLOCATION_FACTOR) + (*sc * *NUMBER_4_INTEGER);

                    // Reallocate destination character vector.
                    reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);

                    if (*dc <= (*ds - (*sc * *NUMBER_4_INTEGER))) {

                        // The state of the conversion.
                        //
                        // In the introduction of this chapter it was said that
                        // certain character sets use a stateful encoding.
                        // That is, the encoded values depend in some way
                        // on the previous bytes in the text.
                        //
                        // Since the conversion functions allow converting a text
                        // in more than one step, there must be a way to pass this
                        // information from one call of the functions to another.
                        //
                        // A variable of type mbstate_t can contain all the
                        // information about the shift state needed from one call
                        // to a conversion function to another.
                        mbstate_t st;

                        // Clear the whole conversion state variable.
                        //
                        // There is no specific function or initializer to put the
                        // state object in any specific state. The rules are that
                        // the object should always represent the initial state
                        // before the first use and this is achieved here.
                        memset((void*) &st, '\0', sizeof(st));

                        // Converts the wide character string into a multibyte character string.
                        //
                        // Returns the number of multibyte characters converted.
                        int n = wcsnrtombs(*d, (void*) &p3, *sc, *ds, st);

                        if (n >= *NUMBER_0_INTEGER) {

                            // Increment destination count by the number of multibyte characters converted.
                            *dc = *dc + n;

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode utf-8 unicode character stream. The conversion failed, possibly because one of the wide characters in the input string has no valid multibyte character equivalent.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode utf-8 unicode character stream. The destination count exceeds the size.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode utf-8 unicode character stream. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode utf-8 unicode character stream. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode utf-8 unicode character stream. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode utf-8 unicode character stream. The source count is null.");
    }
}

/* UTF_8_UNICODE_CHARACTER_CONVERTER_SOURCE */
#endif
