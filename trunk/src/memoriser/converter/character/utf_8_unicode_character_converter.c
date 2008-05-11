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
 * @version $Revision: 1.2 $ $Date: 2008-05-11 23:12:13 $ $Author: christian $
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
 * Decodes an (external) UTF-8 Unicode character stream into an (internal) UTF-32 Unicode wide character vector.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source UTF-8 Unicode character stream
 * @param p4 the source UTF-8 Unicode character stream count
 */
void decode_utf_8_unicode_character_stream(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        size_t* sc = (size_t*) p4;

        if (p2 != *NULL_POINTER) {

            size_t* ds = (size_t*) p2;

            if (p1 != *NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** d = (void**) p0;

                    if (*dc >= *NUMBER_0_INTEGER) {

                        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode UTF-8 Unicode character stream.");

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
                        // There is no specific function or initializer to put the
                        // state object in any specific state. The rules are that
                        // the object should always represent the initial state
                        // before the first use and this is achieved here.
                        memset(st, '\0', sizeof(st));

                        // The number of bytes in all the multibyte character sequences
                        // stored in the destination wide character array.
                        size_t n = *NUMBER_0_INTEGER;

                        while (1) {

                            wchar_t linebuf[100];
                            const char* endp = strchr(src, '\n');

                            // Exit if there is no more line.
                            if (endp == NULL) {

                                break;
                            }

                            // Converts the null-terminated wide character string
                            // into an equivalent multibyte character string.
                            //
                            // The null wide character is also converted.
                            // The third parameter specifies how many bytes at most
                            // can be used from the multibyte character string.
                            // That is, the source multibyte character string
                            // does not have to be null-terminated.
                            // But if a null byte is found within the first bytes
                            // of the string, then the conversion stops there.
                            //
                            // A null-termination character does not need to be added,
                            // since the maximum sizes are given for source and destination.
                            n = mbsnrtowcs(*d, (void*) &s, *sc, *ds, st);

                            linebuf[n] = L'\0';
                            fprintf(fp, "line %d: \"%S\"\n", linebuf);
                        }

/*??
                        // The new destination wide character vector size.
                        // (Not exactly the size, but the destination character vector index
                        // increased by the source array count.)
                        *ds = *dc + *sc;

                        // Reallocate destination wide character vector.
                        reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY);

                        if (*dc <= (*ds - *sc)) {

                            // Set source into destination wide character vector.
                            set_array_elements(*d, p1, p3, p4, (void*) WIDE_CHARACTER_ARRAY);

                            // Increment count.
                            // Example:
                            // d = "helloworld"
                            // dc (as index) = 5
                            // s = "universe"
                            // sc = 8
                            // d (after set) = "hellouniverse"
                            // dc = dc + sc = 13
                            // CAUTION! This example presumes normal one-byte
                            // characters as source. Wide characters occupy
                            // more bytes in a file/memory, but the principle
                            // of conversion and counting is the same.
                            *dc = *dc + *sc;

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode utf-8 unicode character stream. The destination count exceeds the size.");
                        }
*/

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
 * Encodes an UTF-32 Unicode wide character vector into an UTF-8 Unicode character stream.
 *
 * @param p0 the destination UTF-8 Unicode character stream (Hand over as reference!)
 * @param p1 the destination UTF-8 Unicode character stream count
 * @param p2 the destination UTF-8 Unicode character stream size
 * @param p3 the source wide character array
 * @param p4 the source wide character array count
 */
void encode_utf_8_unicode_character_stream(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode UTF-8 Unicode character stream.");

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
                    // There is no specific function or initializer to put the
                    // state object in any specific state. The rules are that
                    // the object should always represent the initial state
                    // before the first use and this is achieved here.
                    memset(st, '\0', sizeof(st));

                    // Use state.
                    ...

                    // Test whether the current state corresponds to the initial state.
                    // This is necessary, for example, to decide whether or not to emit
                    // escape sequences to set the state to the initial state at certain
                    // sequence points. Communication protocols often require this.
                    int i = mbsinit(st);

                    if (i != *NUMBER_0_INTEGER) {

                        // Emit code to return to initial state.
                        //?? TODO: Possibly replace with EMPTY_MODEL defined in "cybol_model_constants.c"!
                        //?? Problem: The constant EMPTY_MODEL is not null-terminated.
                        const wchar_t empty[] = L"";
                        const wchar_t* srcp = empty;

                        // Determine the necessary output code.
                        wcsrtombs(outbuf, srcp, outbuflen, st);
                    }

/*??
                    if ((*dc + *sc) >= *ds) {

                        // The new destination character vector size.
                        // CAUTION! Add constant in case *dc is zero!
                        *ds = (*dc * *CHARACTER_VECTOR_REALLOCATION_FACTOR) + *sc;

                        // Reallocate destination character vector.
                        reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                    }

                    // Set source into destination character vector.
                    set_array_elements(*d, p1, p3, p4, (void*) CHARACTER_ARRAY);

                    // Increment destination count.
                    *dc = *dc + *sc;
*/

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
