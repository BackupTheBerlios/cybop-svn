/*
 * $RCSfile: html_character_converter.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-08-17 04:06:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTML_CHARACTER_CONVERTER_SOURCE
#define HTML_CHARACTER_CONVERTER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/html_character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/reallocation_factor_variables.c"

/**
 * Decodes an html character (escape code) into a character.
 *
 * @param p0 the destination character
 * @param p1 the destination character count
 * @param p2 the destination character size
 * @param p3 the source html character (escape code)
 * @param p4 the source html character (escape code) count
 */
void decode_html_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

                //
                // The references &#00; to &#08; are unused.
                //

/*??
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                LINE_FEED_HTML_CHARACTER = LINE_FEED_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                //
                // The references &#11; to &#12; are unused.
                //

                CARRIAGE_RETURN_HTML_CHARACTER = CARRIAGE_RETURN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                //
                // The references &#14; to &#31; are unused.
                //

                SPACE_HTML_CHARACTER = SPACE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                EXCLAMATION_MARK_HTML_CHARACTER = EXCLAMATION_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                QUOTATION_MARK_HTML_CHARACTER = QUOTATION_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                NUMBER_SIGN_HTML_CHARACTER = NUMBER_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DOLLAR_SIGN_HTML_CHARACTER = DOLLAR_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                PERCENT_SIGN_HTML_CHARACTER = PERCENT_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                AMPERSAND_HTML_CHARACTER = AMPERSAND_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                APOSTROPHE_HTML_CHARACTER = APOSTROPHE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                LEFT_PARENTHESIS_HTML_CHARACTER = LEFT_PARENTHESIS_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_PARENTHESIS_HTML_CHARACTER = RIGHT_PARENTHESIS_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                ASTERISK_HTML_CHARACTER = ASTERISK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                PLUS_SIGN_HTML_CHARACTER = PLUS_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                COMMA_HTML_CHARACTER = COMMA_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                HYPHEN_HTML_CHARACTER = HYPHEN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                PERIOD_HTML_CHARACTER = PERIOD_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SOLIDUS_HTML_CHARACTER = SOLIDUS_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_0_HTML_CHARACTER = DIGIT_0_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_1_HTML_CHARACTER = DIGIT_1_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_2_HTML_CHARACTER = DIGIT_2_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_3_HTML_CHARACTER = DIGIT_3_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_4_HTML_CHARACTER = DIGIT_4_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_5_HTML_CHARACTER = DIGIT_5_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_6_HTML_CHARACTER = DIGIT_6_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_7_HTML_CHARACTER = DIGIT_7_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_8_HTML_CHARACTER = DIGIT_8_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIGIT_9_HTML_CHARACTER = DIGIT_9_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                COLON_HTML_CHARACTER = COLON_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SEMICOLON_HTML_CHARACTER = SEMICOLON_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                LESS_THAN_HTML_CHARACTER = LESS_THAN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                EQUALS_SIGN_HTML_CHARACTER = EQUALS_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                GREATER_THAN_HTML_CHARACTER = GREATER_THAN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                QUESTION_MARK_HTML_CHARACTER = QUESTION_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                COMMERCIAL_AT_HTML_CHARACTER = COMMERCIAL_AT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_A_HTML_CHARACTER = CAPITAL_LETTER_A_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_B_HTML_CHARACTER = CAPITAL_LETTER_B_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_C_HTML_CHARACTER = CAPITAL_LETTER_C_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_D_HTML_CHARACTER = CAPITAL_LETTER_D_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_E_HTML_CHARACTER = CAPITAL_LETTER_E_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_F_HTML_CHARACTER = CAPITAL_LETTER_F_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_G_HTML_CHARACTER = CAPITAL_LETTER_G_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_H_HTML_CHARACTER = CAPITAL_LETTER_H_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_I_HTML_CHARACTER = CAPITAL_LETTER_I_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_J_HTML_CHARACTER = CAPITAL_LETTER_J_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_K_HTML_CHARACTER = CAPITAL_LETTER_K_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_L_HTML_CHARACTER = CAPITAL_LETTER_L_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_M_HTML_CHARACTER = CAPITAL_LETTER_M_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_N_HTML_CHARACTER = CAPITAL_LETTER_N_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_O_HTML_CHARACTER = CAPITAL_LETTER_O_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_P_HTML_CHARACTER = CAPITAL_LETTER_P_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_Q_HTML_CHARACTER = CAPITAL_LETTER_Q_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_R_HTML_CHARACTER = CAPITAL_LETTER_R_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_S_HTML_CHARACTER = CAPITAL_LETTER_S_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_T_HTML_CHARACTER = CAPITAL_LETTER_T_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_U_HTML_CHARACTER = CAPITAL_LETTER_U_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_V_HTML_CHARACTER = CAPITAL_LETTER_V_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_W_HTML_CHARACTER = CAPITAL_LETTER_W_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_X_HTML_CHARACTER = CAPITAL_LETTER_X_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_Y_HTML_CHARACTER = CAPITAL_LETTER_Y_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_LETTER_Z_HTML_CHARACTER = CAPITAL_LETTER_Z_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                LEFT_SQUARE_BRACKET_HTML_CHARACTER = LEFT_SQUARE_BRACKET_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                REVERSE_SOLIDUS_HTML_CHARACTER = REVERSE_SOLIDUS_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_SQUARE_BRACKET_HTML_CHARACTER = RIGHT_SQUARE_BRACKET_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CARET_HTML_CHARACTER = CARET_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                HORIZONTAL_BAR_HTML_CHARACTER = HORIZONTAL_BAR_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                GRAVE_ACCENT_HTML_CHARACTER = GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_A_HTML_CHARACTER = SMALL_LETTER_A_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_B_HTML_CHARACTER = SMALL_LETTER_B_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_C_HTML_CHARACTER = SMALL_LETTER_C_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_D_HTML_CHARACTER = SMALL_LETTER_D_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_E_HTML_CHARACTER = SMALL_LETTER_E_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_F_HTML_CHARACTER = SMALL_LETTER_F_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_G_HTML_CHARACTER = SMALL_LETTER_G_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_H_HTML_CHARACTER = SMALL_LETTER_H_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_I_HTML_CHARACTER = SMALL_LETTER_I_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_J_HTML_CHARACTER = SMALL_LETTER_J_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_K_HTML_CHARACTER = SMALL_LETTER_K_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_L_HTML_CHARACTER = SMALL_LETTER_L_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_M_HTML_CHARACTER = SMALL_LETTER_M_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_N_HTML_CHARACTER = SMALL_LETTER_N_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_O_HTML_CHARACTER = SMALL_LETTER_O_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_P_HTML_CHARACTER = SMALL_LETTER_P_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_Q_HTML_CHARACTER = SMALL_LETTER_Q_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_R_HTML_CHARACTER = SMALL_LETTER_R_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_S_HTML_CHARACTER = SMALL_LETTER_S_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_T_HTML_CHARACTER = SMALL_LETTER_T_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_U_HTML_CHARACTER = SMALL_LETTER_U_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_V_HTML_CHARACTER = SMALL_LETTER_V_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_W_HTML_CHARACTER = SMALL_LETTER_W_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_X_HTML_CHARACTER = SMALL_LETTER_X_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_Y_HTML_CHARACTER = SMALL_LETTER_Y_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_LETTER_Z_HTML_CHARACTER = SMALL_LETTER_Z_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                LEFT_CURLY_BRACE_HTML_CHARACTER = LEFT_CURLY_BRACE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                VERTICAL_BAR_HTML_CHARACTER = VERTICAL_BAR_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_CURLY_BRACE_HTML_CHARACTER = RIGHT_CURLY_BRACE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                TILDE_HTML_CHARACTER = TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                //
                // The references &#127; to &#159; are unused.
                //

                NON_BREAKING_SPACE_HTML_CHARACTER = NON_BREAKING_SPACE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                INVERTED_EXCLAMATION_HTML_CHARACTER = INVERTED_EXCLAMATION_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CENT_SIGN_HTML_CHARACTER = CENT_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                POUND_STERLING_HTML_CHARACTER = POUND_STERLING_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                GENERAL_CURRENCY_HTML_CHARACTER = GENERAL_CURRENCY_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                YEN_SIGN_HTML_CHARACTER = YEN_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                BROKEN_VERTICAL_BAR_HTML_CHARACTER = BROKEN_VERTICAL_BAR_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SECTION_SIGN_HTML_CHARACTER = SECTION_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                UMLAUT_HTML_CHARACTER = UMLAUT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                COPYRIGHT_HTML_CHARACTER = COPYRIGHT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                FEMININE_ORDINAL_HTML_CHARACTER = FEMININE_ORDINAL_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                LEFT_ANGLE_QUOTE_HTML_CHARACTER = LEFT_ANGLE_QUOTE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                NOT_SIGN_HTML_CHARACTER = NOT_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SOFT_HYPHEN_HTML_CHARACTER = SOFT_HYPHEN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                REGISTERED_TRADEMARK_HTML_CHARACTER = REGISTERED_TRADEMARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                MACRON_ACCENT_HTML_CHARACTER = MACRON_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DEGREE_SIGN_HTML_CHARACTER = DEGREE_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                PLUS_OR_MINUS_HTML_CHARACTER = PLUS_OR_MINUS_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SUPERSCRIPT_TWO_HTML_CHARACTER = SUPERSCRIPT_TWO_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SUPERSCRIPT_THREE_HTML_CHARACTER = SUPERSCRIPT_THREE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                ACUTE_ACCENT_HTML_CHARACTER = ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                MICRO_SIGN_HTML_CHARACTER = MICRO_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                PARAGRAPH_SIGN_HTML_CHARACTER = PARAGRAPH_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                MIDDLE_DOT_HTML_CHARACTER = MIDDLE_DOT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CEDILLA_HTML_CHARACTER = CEDILLA_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SUPERSCRIPT_ONE_HTML_CHARACTER = SUPERSCRIPT_ONE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                MASCULINE_ORDINAL_HTML_CHARACTER = MASCULINE_ORDINAL_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_HTML_CHARACTER = RIGHT_ANGLE_QUOTE_GUILLEMOTRIGHT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                FRACTION_ONE_FOURTH_HTML_CHARACTER = FRACTION_ONE_FOURTH_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                FRACTION_ONE_HALF_HTML_CHARACTER = FRACTION_ONE_HALF_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                FRACTION_THREE_FOURTHS_HTML_CHARACTER = FRACTION_THREE_FOURTHS_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                INVERTED_QUESTION_MARK_HTML_CHARACTER = INVERTED_QUESTION_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_A_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_A_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_TILDE_HTML_CHARACTER = CAPITAL_A_TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_A_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_A_RING_HTML_CHARACTER = CAPITAL_A_RING_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_AE_DIPTHONG_HTML_CHARACTER = CAPITAL_AE_DIPTHONG_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_C_CEDILLA_HTML_CHARACTER = CAPITAL_C_CEDILLA_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_E_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_E_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_E_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_E_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_I_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_I_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_I_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_I_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_ETH_ICELANDIC_HTML_CHARACTER = CAPITAL_ETH_ICELANDIC_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_N_TILDE_HTML_CHARACTER = CAPITAL_N_TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_O_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_O_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_TILDE_HTML_CHARACTER = CAPITAL_O_TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_O_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                MULTIPLY_SIGN_HTML_CHARACTER = MULTIPLY_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_O_SLASH_HTML_CHARACTER = CAPITAL_O_SLASH_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_GRAVE_ACCENT_HTML_CHARACTER = CAPITAL_U_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_U_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER = CAPITAL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_U_UMLAUT_MARK_HTML_CHARACTER = CAPITAL_U_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_Y_ACUTE_ACCENT_HTML_CHARACTER = CAPITAL_Y_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                CAPITAL_THORN_ICELANDIC_HTML_CHARACTER = CAPITAL_THORN_ICELANDIC_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_SHARP_S_GERMAN_HTML_CHARACTER = SMALL_SHARP_S_GERMAN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_GRAVE_ACCENT_HTML_CHARACTER = SMALL_A_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_ACUTE_ACCENT_HTML_CHARACTER = SMALL_A_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_A_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_TILDE_HTML_CHARACTER = SMALL_A_TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_UMLAUT_MARK_HTML_CHARACTER = SMALL_A_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_A_RING_HTML_CHARACTER = SMALL_A_RING_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_AE_DIPTHONG_HTML_CHARACTER = SMALL_AE_DIPTHONG_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_C_CEDILLA_HTML_CHARACTER = SMALL_C_CEDILLA_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_GRAVE_ACCENT_HTML_CHARACTER = SMALL_E_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_ACUTE_ACCENT_HTML_CHARACTER = SMALL_E_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_E_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_E_UMLAUT_MARK_HTML_CHARACTER = SMALL_E_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_GRAVE_ACCENT_HTML_CHARACTER = SMALL_I_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_ACUTE_ACCENT_HTML_CHARACTER = SMALL_I_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_I_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_I_UMLAUT_MARK_HTML_CHARACTER = SMALL_I_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_ETH_ICELANDIC_HTML_CHARACTER = SMALL_ETH_ICELANDIC_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_N_TILDE_HTML_CHARACTER = SMALL_N_TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_GRAVE_ACCENT_HTML_CHARACTER = SMALL_O_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_ACUTE_ACCENT_HTML_CHARACTER = SMALL_O_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_O_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_TILDE_HTML_CHARACTER = SMALL_O_TILDE_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_UMLAUT_MARK_HTML_CHARACTER = SMALL_O_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                DIVISION_SIGN_HTML_CHARACTER = DIVISION_SIGN_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_O_SLASH_HTML_CHARACTER = SMALL_O_SLASH_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_GRAVE_ACCENT_HTML_CHARACTER = SMALL_U_GRAVE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_ACUTE_ACCENT_HTML_CHARACTER = SMALL_U_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER = SMALL_U_CIRCUMFLEX_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_U_UMLAUT_MARK_HTML_CHARACTER = SMALL_U_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_Y_ACUTE_ACCENT_HTML_CHARACTER = SMALL_Y_ACUTE_ACCENT_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_THORN_ICELANDIC_HTML_CHARACTER = SMALL_THORN_ICELANDIC_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }

                SMALL_Y_UMLAUT_MARK_HTML_CHARACTER = SMALL_Y_UMLAUT_MARK_HTML_CHARACTER_ARRAY;
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) HORIZONTAL_TAB_HTML_CHARACTER, (void*) HORIZONTAL_TAB_HTML_CHARACTER_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &HORIZONTAL_TAB_CHARACTER;
                        tc = *PRIMITIVE_COUNT;
                        ts = tc;
                    }
                }
*/

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

                log_message_debug("Could not decode html character. The destination is null.");
            }

        } else {

            log_message_debug("Could not decode html character. The destination count is null.");
        }

    } else {

        log_message_debug("Could not decode html character. The destination size is null.");
    }
}

/**
 * Encodes a character into an html character (escape code).
 *
 * @param p0 the destination html character (escape code)
 * @param p1 the destination html character (escape code) count
 * @param p2 the destination html character (escape code) size
 * @param p3 the source character
 * @param p4 the source character count
 */
void encode_html_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

/*??
                if (r == *NUMBER_0_INTEGER) {

                    compare_arrays(p3, p4, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        t = (void**) &SPACE_URL_ESCAPE_CODE;
                        tc = *SPACE_URL_ESCAPE_CODE_COUNT;
                        ts = tc;
                    }
                }
*/

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

                log_message_debug("Could not encode html character. The destination is null.");
            }

        } else {

            log_message_debug("Could not encode html character. The destination count is null.");
        }

    } else {

        log_message_debug("Could not encode html character. The destination size is null.");
    }
}

/* HTML_CHARACTER_CONVERTER_SOURCE */
#endif
