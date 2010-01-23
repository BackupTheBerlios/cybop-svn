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

#ifndef UTF_8_UNICODE_CHARACTER_DECODER_SOURCE
#define UTF_8_UNICODE_CHARACTER_DECODER_SOURCE

#include <errno.h>
#include <locale.h>
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

//
// Reflexions on character set conversion.
//
// A Unix C library such as the GNU C library contains three different sets
// of functions in two families to handle character set conversion:
//
// 1 First Family
// - specified in the ISO C90 standard
// - portable even beyond the Unix world
// - most commonly used but the least useful one;
//   its functions should be avoided whenever possible
// - the wide character set is fixed by the implementation
//   (in the case of GNU C library it is always UCS-4 encoded ISO 10646)
// - if neither the source nor the destination character set is the character set used
//   for wchar_t representation, there is at least a two-step conversion process necessary
// - character set assumed for multibyte encoding is not specified as an argument to the functions;
//   instead, the character set specified by the LC_CTYPE category of the current locale is used;
//   for every conversion where neither the source nor the destination character set is the character set
//   of the locale for the LC_CTYPE category, one has to change the LC_CTYPE locale using "setlocale";
//   parallel conversions to and from different character sets are not possible,
//   since the LC_CTYPE selection is global and shared by all threads
// - self-made observation (not taken from the GNU C library manual):
//   not all Unicode characters are contained in one of the standard locales;
//   e.g. special Unicode Box drawing characters are useful when creating a Text User Interfaces (TUI);
//   but unfortunately, they are missing in the existing locales;
//   an example for such a missing Unicode character is this one:
//   U+2570 box drawings light arc up and right
//
// 1.1 First Function Set "Non-reentrant Conversion"
// - defined in original ISO C90 standard
// - almost entirely useless
// - one cannot first convert single characters and then strings
//   since one cannot tell the conversion functions which state to use
// - usable only in a very limited set of situations
// - one must complete converting the entire string before starting a new one
// - each string/text must be converted with the same function
// - highly requested that the "Restartable Multibyte Conversion" functions
//   be used in place of non-reentrant conversion functions
//
// 1.2 Second Function Set "Restartable Multibyte Conversion"
// - defined in Amendment 1 to ISO C90 standard
// - convert strings from a multibyte representation to wide character strings
// - functions handling more than one character at a time require NUL terminated strings as the argument
//   (converting blocks of text does not work unless one can add a NUL byte at an appropriate place);
//   the GNU C library contains some extensions to the standard that allow specifying a size,
//   but basically they also expect terminated strings
// - can be used in many contexts, e.g. if the text itself comes from a file with
//   translations and the user can decide about the current locale, which determines
//   the translation and therefore also the external encoding used
//
// 2 Second Family
// - third function set: generic charset conversion
// - introduced in the early Unix standards (XPG2)
// - still part of the latest and greatest Unix standard: Unix 98
// - defines a completely new set of most powerful and useful functions
//
// 2.1 Third Function Set "Generic Charset Conversion"
// - defines "iconv" functions as interface; does not provide an implementation
// - provide more freedom while performing the conversion
// - not at all coupled to the selected locales;
//   has no constraints on the character sets selected for source and destination;
//   only limited by the set of available conversions;
//   does not specify that any conversion at all must be available
// - problems with the specification of the iconv functions can lead to portability issues
// - since it is not practical to encode the conversions directly in the C library,
//   the conversion information must come from files outside the C library:
//
// a Loading Conversion Tables from Data Files
// - C library contains a set of generic conversion functions
// - data files are loaded when necessary
// - requires a great deal of effort to apply to all character sets (potentially an infinite set)
// - differences in the structure of the different character sets is so large,
//   that many different variants of the table-processing functions must be developed
// - the generic nature of these functions make them slower than specifically implemented functions
//
// b Dynamically Loading Object Files
// - execute the conversion functions contained in object files
// - provides much more flexibility
// - with documented interface, third parties may extend the set of available conversion modules
// - dynamic loading must be available
// - design is limiting on platforms (outside ELF) that do not support dynamic loading in statically linked programs
// - number of available conversions in iconv implementations is often very limited
// - most problematic point, that the way the iconv conversion functions are implemented on all known Unix systems:
//   the availability of the conversion functions from character set A to B and
//   the conversion from B to C does not imply that the conversion from A to C is available
//
// Because of these drawbacks of all of the three function sets described above, it seems
// inevitable to -- one day -- write "self-made", CYBOI-internal conversion functions.
//

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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            char* s = (char*) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                int* ds = (int*) p2;

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* dc = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        wchar_t** d = (wchar_t**) p0;

                        if (*dc >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode UTF-8 Unicode character vector.");

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
                            reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                            // Set locale.
                            //
                            // Possible locales are: LANG, LC_CTYPE, ..., LC_ALL
                            // where LANG has the lowest and LC_ALL the highest priority.
                            // That is, if LC_ALL is specified, it overwrites e.g. the LC_CTYPE setting.
                            // If no value "" is given, the default will be used.
                            // Note, that LC_CTYPE suffices for the purpose of character conversion,
                            // since it is the category that applies to classification and conversion
                            // of characters, and to multibyte and wide characters.
                            //
                            // CAUTION! This setting is necessary for UTF-8 Unicode character conversion
                            // with restartable multibyte conversion functions like "mbsnrtowcs"
                            // and "wcsnrtombs" to work correctly.
                            // The return value is not used; this is a global setting.
                            char* loc = setlocale(LC_CTYPE, "");

                            // The state of the conversion.
                            //
                            // Certain character sets use a stateful encoding.
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
//??                            mbstate_t st;

                            // Clear the whole conversion state variable.
                            //
                            // There is no specific function or initializer to put the
                            // state object in any specific state. The rules are that
                            // the object should always represent the initial state
                            // before the first use and this is achieved here.
//??                            memset((void*) &st, '\0', sizeof(st));

                            // Initialise error number.
                            // It is a global variable/ function and other operations
                            // may have set some value that is not wanted here.
                            //
                            // CAUTION! Initialise the error number BEFORE calling the function
                            // that might cause an error.
                            errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

                            // Converts the multibyte character string into a wide character string.
                            //
                            // Returns the number of wide characters converted.
//??                            int n = mbsnrtowcs(*d, &s, *sc, *ds, &st);
                            int n = mbsnrtowcs(*d, &s, *sc, *ds, *NULL_POINTER_MEMORY_MODEL);

                            if (n >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // Increment destination count by the number of wide characters converted.
                                *dc = *dc + n;

                            } else {

                                if (errno == EILSEQ) {

        fwprintf(stdout, L"TEST ERROR EILSEQ errno: %i\n", errno);
                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The input string contains an invalid multibyte sequence.");

                                } else {

        fwprintf(stdout, L"TEST ERROR UNKNOWN errno: %i\n", errno);
                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. An unknown error occured.");
                                }
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The destination count is negative.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The destination is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The destination count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The destination size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode utf-8 unicode character stream. The source count is null.");
    }
}

/* UTF_8_UNICODE_CHARACTER_DECODER_SOURCE */
#endif
