/*
 * $RCSfile: url_escape_code_mapper.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-12 23:31:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URL_ESCAPE_CODE_MAPPER_SOURCE
#define URL_ESCAPE_CODE_MAPPER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/http/url_escape_code_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/variables.c"

/**
 * Maps from url escape code to character.
 *
 * RFC 3986 does not determine which character set to use for decoding
 * non-ASCII characters (e.g. Umlauts like ä, ö, ü). Since a two-digit
 * hexadecimal number (which corresponds to eight Bit) is used for url
 * encoding, it would be theoretically possible to use an 8 Bit character
 * set (e.g. ISO-8859-1 for Umlauts).
 *
 * However, since many languages have their own 8 Bit character sets, it
 * would be rather tedious to handle all these different character sets.
 * Moreover, some languages (e.g. Chinese) may not be represented using an
 * 8 Bit character set. For this reason, RFC 3629 suggests to represent
 * non-ASCII characters using the UTF-8 character set.
 *
 * @param p0 the destination character
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source url escape code
 * @param p4 the source url escape code count
 */
void map_from_url_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                // The character.
                void** c = NULL_POINTER;
                int cc = *NUMBER_0_INTEGER;
                int cs = *NUMBER_0_INTEGER;
                // The comparison result.
                int r = *NUMBER_0_INTEGER;

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SPACE_URL_ESCAPE_CODE, (void*) SPACE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &SPACE_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) NUMBER_SIGN_URL_ESCAPE_CODE, (void*) NUMBER_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &NUMBER_SIGN_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE, (void*) DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &DOLLAR_SIGN_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) PERCENT_SIGN_URL_ESCAPE_CODE, (void*) PERCENT_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &PERCENT_SIGN_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) AMPERSAND_URL_ESCAPE_CODE, (void*) AMPERSAND_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &AMPERSAND_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SOLIDUS_URL_ESCAPE_CODE, (void*) SOLIDUS_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &SOLIDUS_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) COLON_URL_ESCAPE_CODE, (void*) COLON_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &COLON_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SEMICOLON_URL_ESCAPE_CODE, (void*) SEMICOLON_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &SEMICOLON_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LESS_THAN_URL_ESCAPE_CODE, (void*) LESS_THAN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &LESS_THAN_SIGN_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) EQUALS_SIGN_URL_ESCAPE_CODE, (void*) EQUALS_SIGN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &EQUALS_SIGN_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) GREATER_THAN_URL_ESCAPE_CODE, (void*) GREATER_THAN_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &GREATER_THAN_SIGN_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) QUESTION_MARK_URL_ESCAPE_CODE, (void*) QUESTION_MARK_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &QUESTION_MARK_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE, (void*) COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &COMMERCIAL_AT_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &LEFT_SQUARE_BRACKET_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE, (void*) REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &REVERSE_SOLIDUS_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE, (void*) RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &RIGHT_SQUARE_BRACKET_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) CARET_URL_ESCAPE_CODE, (void*) CARET_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &CIRCUMFLEX_ACCENT_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE, (void*) GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &GRAVE_ACCENT_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &LEFT_CURLY_BRACKET_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) VERTICAL_BAR_URL_ESCAPE_CODE, (void*) VERTICAL_BAR_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &VERTICAL_LINE_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE, (void*) RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &RIGHT_CURLY_BRACKET_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) TILDE_URL_ESCAPE_CODE, (void*) TILDE_URL_ESCAPE_CODE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Set character.
                        c = (void**) &TILDE_CHARACTER;
                        cc = *PRIMITIVE_COUNT;
                        cs = *PRIMITIVE_COUNT;
                    }
                }

                //
                // Set actual destination character, using the local character variables.
                //

                if (r != *NUMBER_0_INTEGER) {

                    if (cs >= *ds) {

                        // Increase vector size.
                        // CAUTION! Add one to avoid zero size in case one of the factors is zero!
                        *ds = (*CHARACTER_VECTOR_REALLOCATE_FACTOR * (*ds)) + *NUMBER_1_INTEGER;

                        // Reallocate vector.
                        reallocate(p0, p1, p2, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    }

                    // Set character.
                    set_element(*d, p1, (void*) c, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
                    *dc = cc;
                }

            } else {

                log_message_debug("Could not map from url escape code. The destination character is null.");
            }

        } else {

            log_message_debug("Could not map from url escape code. The destination character count is null.");
        }

    } else {

        log_message_debug("Could not map from url escape code. The destination character size is null.");
    }
}

/**
 * Maps from character to url escape code.
 *
 * @param p0 the destination escape code
 * @param p1 the destination escape code count
 * @param p2 the destination escape code size
 * @param p3 the source character
 * @param p4 the source character count
 */
void map_to_url_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* URL_ESCAPE_CODE_MAPPER_SOURCE */
#endif
