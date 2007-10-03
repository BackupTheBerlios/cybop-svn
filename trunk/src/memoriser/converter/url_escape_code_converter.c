/*
 * $RCSfile: url_escape_code_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.4 $ $Date: 2007-10-03 23:40:06 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URL_ESCAPE_CODE_CONVERTER_SOURCE
#define URL_ESCAPE_CODE_CONVERTER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/http/url_escape_code_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/reallocation_factor_variables.c"

//
// RFC 3986 does not determine which character set to use for decoding
// non-ASCII characters (e.g. Umlauts like ä, ö, ü). Since a two-digit
// hexadecimal number (which corresponds to eight Bit) is used for url
// encoding, it would be theoretically possible to use an 8 Bit character
// set (e.g. ISO-8859-1 for Umlauts).
//
// However, since many languages have their own 8 Bit character sets, it
// would be rather tedious to handle all these different character sets.
// Moreover, some languages (e.g. Chinese) may not be represented using an
// 8 Bit character set. For this reason, RFC 3629 suggests to represent
// non-ASCII characters using the UTF-8 character set.
//

/**
 * Decodes the url escape code into a character.
 *
 * @param p0 the destination character
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source url escape code
 * @param p4 the source url escape code count
 */
void decode_url_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER;
                int tc = *NUMBER_0_INTEGER;
                int ts = *NUMBER_0_INTEGER;
                // The comparison result.
                int r = *NUMBER_0_INTEGER;

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SPACE_URL_ESCAPE_CODE, (void*) SPACE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SPACE_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) NUMBER_SIGN_URL_ESCAPE_CODE, (void*) NUMBER_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &NUMBER_SIGN_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &DOLLAR_SIGN_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) PERCENT_SIGN_URL_ESCAPE_CODE, (void*) PERCENT_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &PERCENT_SIGN_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) AMPERSAND_URL_ESCAPE_CODE, (void*) AMPERSAND_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &AMPERSAND_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SOLIDUS_URL_ESCAPE_CODE, (void*) SOLIDUS_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SOLIDUS_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) COLON_URL_ESCAPE_CODE, (void*) COLON_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &COLON_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SEMICOLON_URL_ESCAPE_CODE, (void*) SEMICOLON_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SEMICOLON_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE, (void*) LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &LESS_THAN_SIGN_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) EQUALS_SIGN_URL_ESCAPE_CODE, (void*) EQUALS_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &EQUALS_SIGN_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE, (void*) GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &GREATER_THAN_SIGN_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) QUESTION_MARK_URL_ESCAPE_CODE, (void*) QUESTION_MARK_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &QUESTION_MARK_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &COMMERCIAL_AT_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &LEFT_SQUARE_BRACKET_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &REVERSE_SOLIDUS_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &RIGHT_SQUARE_BRACKET_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) CARET_URL_ESCAPE_CODE, (void*) CARET_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &CIRCUMFLEX_ACCENT_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &GRAVE_ACCENT_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &LEFT_CURLY_BRACKET_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) VERTICAL_BAR_URL_ESCAPE_CODE, (void*) VERTICAL_BAR_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &VERTICAL_LINE_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &RIGHT_CURLY_BRACKET_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) TILDE_URL_ESCAPE_CODE, (void*) TILDE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &TILDE_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    }

                    // Add temporary value to destination.
                    set_element(*d, p1, (void*) t, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode url escape code. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode url escape code. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not decode url escape code. The destination size is null.");
    }
}

/**
 * Encodes the character into a url escape code.
 *
 * @param p0 the destination escape code
 * @param p1 the destination escape code count
 * @param p2 the destination escape code size
 * @param p3 the source character
 * @param p4 the source character count
 */
void encode_url_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER;
                int tc = *NUMBER_0_INTEGER;
                int ts = *NUMBER_0_INTEGER;
                // The comparison result.
                int r = *NUMBER_0_INTEGER;

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) NUMBER_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &NUMBER_SIGN_URL_ESCAPE_CODE;
                        tc = *NUMBER_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) DOLLAR_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &DOLLAR_SIGN_URL_ESCAPE_CODE;
                        tc = *DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) PERCENT_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &PERCENT_SIGN_URL_ESCAPE_CODE;
                        tc = *PERCENT_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) AMPERSAND_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &AMPERSAND_URL_ESCAPE_CODE;
                        tc = *AMPERSAND_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SOLIDUS_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SOLIDUS_URL_ESCAPE_CODE;
                        tc = *SOLIDUS_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) COLON_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &COLON_URL_ESCAPE_CODE;
                        tc = *COLON_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SEMICOLON_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SEMICOLON_URL_ESCAPE_CODE;
                        tc = *SEMICOLON_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LESS_THAN_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &LESS_THAN_SIGN_URL_ESCAPE_CODE;
                        tc = *LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) EQUALS_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &EQUALS_SIGN_URL_ESCAPE_CODE;
                        tc = *EQUALS_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) GREATER_THAN_SIGN_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &GREATER_THAN_SIGN_URL_ESCAPE_CODE;
                        tc = *GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) QUESTION_MARK_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &QUESTION_MARK_URL_ESCAPE_CODE;
                        tc = *QUESTION_MARK_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) COMMERCIAL_AT_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &COMMERCIAL_AT_URL_ESCAPE_CODE;
                        tc = *COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LEFT_SQUARE_BRACKET_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE;
                        tc = *LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) REVERSE_SOLIDUS_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &REVERSE_SOLIDUS_URL_ESCAPE_CODE;
                        tc = *REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) RIGHT_SQUARE_BRACKET_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE;
                        tc = *RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) CIRCUMFLEX_ACCENT_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &CARET_URL_ESCAPE_CODE;
                        tc = *CARET_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) GRAVE_ACCENT_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &GRAVE_ACCENT_URL_ESCAPE_CODE;
                        tc = *GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LEFT_CURLY_BRACKET_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &LEFT_CURLY_BRACE_URL_ESCAPE_CODE;
                        tc = *LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) VERTICAL_LINE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &VERTICAL_BAR_URL_ESCAPE_CODE;
                        tc = *VERTICAL_BAR_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) RIGHT_CURLY_BRACKET_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &RIGHT_CURLY_BRACE_URL_ESCAPE_CODE;
                        tc = *RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) TILDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &TILDE_URL_ESCAPE_CODE;
                        tc = *TILDE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    }

                    // Add temporary value to destination.
                    set_element(*d, p1, (void*) t, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not encode url escape code. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not encode url escape code. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not encode url escape code. The destination size is null.");
    }
}

/* URL_ESCAPE_CODE_CONVERTER_SOURCE */
#endif
