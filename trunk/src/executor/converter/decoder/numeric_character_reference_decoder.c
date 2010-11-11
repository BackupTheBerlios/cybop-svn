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
 * @version $RCSfile: numeric_character_reference_converter.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NUMERIC_CHARACTER_REFERENCE_DECODER_SOURCE
#define NUMERIC_CHARACTER_REFERENCE_DECODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/character/character_constants.c"
#include "../../../constant/character/numeric_character_reference_constants.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Decodes a numeric character reference (html escape code) into a character.
 *
 * @param p0 the destination character (Hand over as reference!)
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source numeric character reference (html escape code)
 * @param p4 the source numeric character reference (html escape code) count
 */
void decode_numeric_character_reference(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                //
                // The references &#00; to &#08; are unused.
                //

/*??
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                LINE_FEED_NUMERIC_CHARACTER_REFERENCE = LINE_FEED_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                //
                // The references &#11; to &#12; are unused.
                //

                CARRIAGE_RETURN_NUMERIC_CHARACTER_REFERENCE = CARRIAGE_RETURN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                //
                // The references &#14; to &#31; are unused.
                //

                SPACE_NUMERIC_CHARACTER_REFERENCE = SPACE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                EXCLAMATION_MARK_NUMERIC_CHARACTER_REFERENCE = EXCLAMATION_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                QUOTATION_MARK_NUMERIC_CHARACTER_REFERENCE = QUOTATION_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                NUMBER_SIGN_NUMERIC_CHARACTER_REFERENCE = NUMBER_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DOLLAR_SIGN_NUMERIC_CHARACTER_REFERENCE = DOLLAR_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                PERCENT_SIGN_NUMERIC_CHARACTER_REFERENCE = PERCENT_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                AMPERSAND_NUMERIC_CHARACTER_REFERENCE = AMPERSAND_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                APOSTROPHE_NUMERIC_CHARACTER_REFERENCE = APOSTROPHE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                LEFT_PARENTHESIS_NUMERIC_CHARACTER_REFERENCE = LEFT_PARENTHESIS_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_PARENTHESIS_NUMERIC_CHARACTER_REFERENCE = RIGHT_PARENTHESIS_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                ASTERISK_NUMERIC_CHARACTER_REFERENCE = ASTERISK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                PLUS_SIGN_NUMERIC_CHARACTER_REFERENCE = PLUS_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                COMMA_NUMERIC_CHARACTER_REFERENCE = COMMA_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                HYPHEN_NUMERIC_CHARACTER_REFERENCE = HYPHEN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                PERIOD_NUMERIC_CHARACTER_REFERENCE = PERIOD_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SOLIDUS_NUMERIC_CHARACTER_REFERENCE = SOLIDUS_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_0_NUMERIC_CHARACTER_REFERENCE = DIGIT_0_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_1_NUMERIC_CHARACTER_REFERENCE = DIGIT_1_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_2_NUMERIC_CHARACTER_REFERENCE = DIGIT_2_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_3_NUMERIC_CHARACTER_REFERENCE = DIGIT_3_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_4_NUMERIC_CHARACTER_REFERENCE = DIGIT_4_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_5_NUMERIC_CHARACTER_REFERENCE = DIGIT_5_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_6_NUMERIC_CHARACTER_REFERENCE = DIGIT_6_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_7_NUMERIC_CHARACTER_REFERENCE = DIGIT_7_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_8_NUMERIC_CHARACTER_REFERENCE = DIGIT_8_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_9_NUMERIC_CHARACTER_REFERENCE = DIGIT_9_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                COLON_NUMERIC_CHARACTER_REFERENCE = COLON_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SEMICOLON_NUMERIC_CHARACTER_REFERENCE = SEMICOLON_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                LESS_THAN_NUMERIC_CHARACTER_REFERENCE = LESS_THAN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                EQUALS_SIGN_NUMERIC_CHARACTER_REFERENCE = EQUALS_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                GREATER_THAN_NUMERIC_CHARACTER_REFERENCE = GREATER_THAN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                QUESTION_MARK_NUMERIC_CHARACTER_REFERENCE = QUESTION_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                COMMERCIAL_AT_NUMERIC_CHARACTER_REFERENCE = COMMERCIAL_AT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_A_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_A_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_B_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_B_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_C_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_C_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_D_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_D_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_E_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_E_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_F_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_F_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_G_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_G_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_H_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_H_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_I_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_I_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_J_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_J_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_K_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_K_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_L_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_L_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_M_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_M_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_N_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_N_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_O_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_O_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_P_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_P_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_Q_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_Q_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_R_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_R_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_S_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_S_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_T_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_T_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_U_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_U_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_V_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_V_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_W_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_W_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_X_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_X_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_Y_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_Y_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_Z_NUMERIC_CHARACTER_REFERENCE = CAPITAL_LETTER_Z_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                LEFT_SQUARE_BRACKET_NUMERIC_CHARACTER_REFERENCE = LEFT_SQUARE_BRACKET_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                REVERSE_SOLIDUS_NUMERIC_CHARACTER_REFERENCE = REVERSE_SOLIDUS_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_SQUARE_BRACKET_NUMERIC_CHARACTER_REFERENCE = RIGHT_SQUARE_BRACKET_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CARET_NUMERIC_CHARACTER_REFERENCE = CARET_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                HORIZONTAL_BAR_NUMERIC_CHARACTER_REFERENCE = HORIZONTAL_BAR_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_A_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_A_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_B_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_B_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_C_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_C_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_D_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_D_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_E_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_E_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_F_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_F_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_G_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_G_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_H_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_H_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_I_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_I_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_J_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_J_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_K_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_K_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_L_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_L_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_M_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_M_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_N_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_N_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_O_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_O_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_P_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_P_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_Q_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_Q_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_R_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_R_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_S_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_S_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_T_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_T_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_U_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_U_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_V_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_V_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_W_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_W_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_X_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_X_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_Y_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_Y_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_Z_NUMERIC_CHARACTER_REFERENCE = SMALL_LETTER_Z_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                LEFT_CURLY_BRACE_NUMERIC_CHARACTER_REFERENCE = LEFT_CURLY_BRACE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                VERTICAL_BAR_NUMERIC_CHARACTER_REFERENCE = VERTICAL_BAR_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_CURLY_BRACE_NUMERIC_CHARACTER_REFERENCE = RIGHT_CURLY_BRACE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                TILDE_NUMERIC_CHARACTER_REFERENCE = TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                //
                // The references &#127; to &#159; are unused.
                //

                NON_BREAKING_SPACE_NUMERIC_CHARACTER_REFERENCE = NON_BREAKING_SPACE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                INVERTED_EXCLAMATION_NUMERIC_CHARACTER_REFERENCE = INVERTED_EXCLAMATION_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CENT_SIGN_NUMERIC_CHARACTER_REFERENCE = CENT_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                POUND_STERLING_NUMERIC_CHARACTER_REFERENCE = POUND_STERLING_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                GENERAL_CURRENCY_NUMERIC_CHARACTER_REFERENCE = GENERAL_CURRENCY_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                YEN_SIGN_NUMERIC_CHARACTER_REFERENCE = YEN_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                BROKEN_VERTICAL_BAR_NUMERIC_CHARACTER_REFERENCE = BROKEN_VERTICAL_BAR_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SECTION_SIGN_NUMERIC_CHARACTER_REFERENCE = SECTION_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                UMLAUT_NUMERIC_CHARACTER_REFERENCE = UMLAUT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                COPYRIGHT_NUMERIC_CHARACTER_REFERENCE = COPYRIGHT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                FEMININE_ORDINAL_NUMERIC_CHARACTER_REFERENCE = FEMININE_ORDINAL_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                LEFT_ANGLE_QUOTE_NUMERIC_CHARACTER_REFERENCE = LEFT_ANGLE_QUOTE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                NOT_SIGN_NUMERIC_CHARACTER_REFERENCE = NOT_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SOFT_HYPHEN_NUMERIC_CHARACTER_REFERENCE = SOFT_HYPHEN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                REGISTERED_TRADEMARK_NUMERIC_CHARACTER_REFERENCE = REGISTERED_TRADEMARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                MACRON_ACCENT_NUMERIC_CHARACTER_REFERENCE = MACRON_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DEGREE_SIGN_NUMERIC_CHARACTER_REFERENCE = DEGREE_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                PLUS_OR_MINUS_NUMERIC_CHARACTER_REFERENCE = PLUS_OR_MINUS_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SUPERSCRIPT_TWO_NUMERIC_CHARACTER_REFERENCE = SUPERSCRIPT_TWO_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SUPERSCRIPT_THREE_NUMERIC_CHARACTER_REFERENCE = SUPERSCRIPT_THREE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                MICRO_SIGN_NUMERIC_CHARACTER_REFERENCE = MICRO_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                PARAGRAPH_SIGN_NUMERIC_CHARACTER_REFERENCE = PARAGRAPH_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                MIDDLE_DOT_NUMERIC_CHARACTER_REFERENCE = MIDDLE_DOT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CEDILLA_NUMERIC_CHARACTER_REFERENCE = CEDILLA_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SUPERSCRIPT_ONE_NUMERIC_CHARACTER_REFERENCE = SUPERSCRIPT_ONE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                MASCULINE_ORDINAL_NUMERIC_CHARACTER_REFERENCE = MASCULINE_ORDINAL_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_NUMERIC_CHARACTER_REFERENCE = RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                FRACTION_ONE_FOURTH_NUMERIC_CHARACTER_REFERENCE = FRACTION_ONE_FOURTH_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                FRACTION_ONE_HALF_NUMERIC_CHARACTER_REFERENCE = FRACTION_ONE_HALF_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                FRACTION_THREE_FOURTHS_NUMERIC_CHARACTER_REFERENCE = FRACTION_THREE_FOURTHS_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                INVERTED_QUESTION_MARK_NUMERIC_CHARACTER_REFERENCE = INVERTED_QUESTION_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_A_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_A_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_A_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_TILDE_NUMERIC_CHARACTER_REFERENCE = CAPITAL_A_TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = CAPITAL_A_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_RING_NUMERIC_CHARACTER_REFERENCE = CAPITAL_A_RING_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_AE_DIPTHONG_NUMERIC_CHARACTER_REFERENCE = CAPITAL_AE_DIPTHONG_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_C_CEDILLA_NUMERIC_CHARACTER_REFERENCE = CAPITAL_C_CEDILLA_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_E_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_E_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_E_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = CAPITAL_E_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_I_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_I_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_I_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = CAPITAL_I_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_ETH_ICELANDIC_NUMERIC_CHARACTER_REFERENCE = CAPITAL_ETH_ICELANDIC_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_N_TILDE_NUMERIC_CHARACTER_REFERENCE = CAPITAL_N_TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_O_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_O_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_O_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_TILDE_NUMERIC_CHARACTER_REFERENCE = CAPITAL_O_TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = CAPITAL_O_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                MULTIPLY_SIGN_NUMERIC_CHARACTER_REFERENCE = MULTIPLY_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_SLASH_NUMERIC_CHARACTER_REFERENCE = CAPITAL_O_SLASH_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_U_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_U_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_U_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = CAPITAL_U_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_Y_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = CAPITAL_Y_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_THORN_ICELANDIC_NUMERIC_CHARACTER_REFERENCE = CAPITAL_THORN_ICELANDIC_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_SHARP_S_GERMAN_NUMERIC_CHARACTER_REFERENCE = SMALL_SHARP_S_GERMAN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_A_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_A_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_A_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_TILDE_NUMERIC_CHARACTER_REFERENCE = SMALL_A_TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = SMALL_A_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_RING_NUMERIC_CHARACTER_REFERENCE = SMALL_A_RING_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_AE_DIPTHONG_NUMERIC_CHARACTER_REFERENCE = SMALL_AE_DIPTHONG_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_C_CEDILLA_NUMERIC_CHARACTER_REFERENCE = SMALL_C_CEDILLA_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_E_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_E_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_E_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = SMALL_E_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_I_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_I_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_I_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = SMALL_I_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_ETH_ICELANDIC_NUMERIC_CHARACTER_REFERENCE = SMALL_ETH_ICELANDIC_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_N_TILDE_NUMERIC_CHARACTER_REFERENCE = SMALL_N_TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_O_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_O_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_O_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_TILDE_NUMERIC_CHARACTER_REFERENCE = SMALL_O_TILDE_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = SMALL_O_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                DIVISION_SIGN_NUMERIC_CHARACTER_REFERENCE = DIVISION_SIGN_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_SLASH_NUMERIC_CHARACTER_REFERENCE = SMALL_O_SLASH_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_U_GRAVE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_U_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_U_CIRCUMFLEX_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = SMALL_U_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_Y_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE = SMALL_Y_ACUTE_ACCENT_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_THORN_ICELANDIC_NUMERIC_CHARACTER_REFERENCE = SMALL_THORN_ICELANDIC_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }

                SMALL_Y_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE = SMALL_Y_UMLAUT_MARK_NUMERIC_CHARACTER_REFERENCE_ARRAY;
                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    compare_equal_arrays((void*) &r, p3, p4, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE, (void*) HORIZONTAL_TAB_NUMERIC_CHARACTER_REFERENCE_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

                    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_MEMORY_MODEL_COUNT;
                        ts = tc;
                    }
                }
*/

                //
                // Set actual destination, using the temporary value.
                //

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    if ((*dc + tc) > *ds) {

                        // Calculate destination size.
                        *ds = (*WIDE_CHARACTER_VECTOR_REALLOCATION_FACTOR * (*dc)) + tc;

                        // Reallocate destination.
                        reallocate(p0, p1, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
                    }

                    // Add temporary value to destination.
                    set(p0, p1, (void*) t, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

                    // Increase destination count.
                    *dc = *dc + tc;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode numeric character reference. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode numeric character reference. The destination count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode numeric character reference. The destination size is null.");
    }
}

/* NUMERIC_CHARACTER_REFERENCE_DECODER_SOURCE */
#endif
