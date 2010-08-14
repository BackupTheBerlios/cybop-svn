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
 * @version $RCSfile: url_escape_code_converter.c,v $ $Revision: 1.12 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URL_ESCAPE_CODE_ENCODER_SOURCE
#define URL_ESCAPE_CODE_ENCODER_SOURCE

#include "../../../globals/constants/character/character_constants.c"
#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../globals/constants/http/url_escape_code_constants.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

//
// RFC 3986 does not determine which character set to use for decoding
// non-ASCII characters (e.g. Umlauts like �, �, �). Since a two-digit
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
 * Encodes the character into a url escape code.
 *
 * @param p0 the destination escape code
 * @param p1 the destination escape code count
 * @param p2 the destination escape code size
 * @param p3 the source character
 * @param p4 the source character count
 */
void encode_url_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* ds = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* dc = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** d = (void**) p0;

                // The temporary value.
                void** t = NULL_POINTER_MEMORY_MODEL;
                int tc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int ts = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The comparison result.
                int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) NUMBER_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &NUMBER_SIGN_URL_ESCAPE_CODE;
                        tc = *NUMBER_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) DOLLAR_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &DOLLAR_SIGN_URL_ESCAPE_CODE;
                        tc = *DOLLAR_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) PERCENT_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &PERCENT_SIGN_URL_ESCAPE_CODE;
                        tc = *PERCENT_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) AMPERSAND_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &AMPERSAND_URL_ESCAPE_CODE;
                        tc = *AMPERSAND_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) SOLIDUS_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &SOLIDUS_URL_ESCAPE_CODE;
                        tc = *SOLIDUS_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) COLON_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &COLON_URL_ESCAPE_CODE;
                        tc = *COLON_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) SEMICOLON_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &SEMICOLON_URL_ESCAPE_CODE;
                        tc = *SEMICOLON_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) LESS_THAN_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &LESS_THAN_SIGN_URL_ESCAPE_CODE;
                        tc = *LESS_THAN_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) EQUALS_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &EQUALS_SIGN_URL_ESCAPE_CODE;
                        tc = *EQUALS_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) GREATER_THAN_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &GREATER_THAN_SIGN_URL_ESCAPE_CODE;
                        tc = *GREATER_THAN_SIGN_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) QUESTION_MARK_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &QUESTION_MARK_URL_ESCAPE_CODE;
                        tc = *QUESTION_MARK_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) COMMERCIAL_AT_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &COMMERCIAL_AT_URL_ESCAPE_CODE;
                        tc = *COMMERCIAL_AT_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) LEFT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE;
                        tc = *LEFT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) REVERSE_SOLIDUS_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &REVERSE_SOLIDUS_URL_ESCAPE_CODE;
                        tc = *REVERSE_SOLIDUS_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) RIGHT_SQUARE_BRACKET_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE;
                        tc = *RIGHT_SQUARE_BRACKET_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) CIRCUMFLEX_ACCENT_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &CARET_URL_ESCAPE_CODE;
                        tc = *CARET_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) GRAVE_ACCENT_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &GRAVE_ACCENT_URL_ESCAPE_CODE;
                        tc = *GRAVE_ACCENT_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) LEFT_CURLY_BRACKET_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &LEFT_CURLY_BRACE_URL_ESCAPE_CODE;
                        tc = *LEFT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) VERTICAL_LINE_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &VERTICAL_BAR_URL_ESCAPE_CODE;
                        tc = *VERTICAL_BAR_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) RIGHT_CURLY_BRACKET_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &RIGHT_CURLY_BRACE_URL_ESCAPE_CODE;
                        tc = *RIGHT_CURLY_BRACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) TILDE_WIDE_CHARACTER, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &TILDE_URL_ESCAPE_CODE;
                        tc = *TILDE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                    }

                    // Add temporary value to destination.
                    set(*d, p1, (void*) t, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode url escape code. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode url escape code. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode url escape code. The destination size is null.");
    }
}

/* URL_ESCAPE_CODE_ENCODER_SOURCE */
#endif
