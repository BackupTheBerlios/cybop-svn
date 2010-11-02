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
 * @version $RCSfile: xhtml_converter.c,v $ $Revision: 1.25 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XHTML_ENCODER_SOURCE
#define XHTML_ENCODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/channel/cybol_channel.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../logger/logger.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/array_equality_comparator.c"

/**
 * Encodes the xhtml indentation.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the indentation level (only for beautifying the resulting xhtml code)
 */
void encode_xhtml_indentation(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* l = (int*) p3;

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *l) {

                break;
            }

            // Encode character tabulation character.
//??            encode_character_vector(p0, p1, p2, (void*) CHARACTER_TABULATION_CONTROL_CHARACTER_CODE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

            // Increment loop count.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode xhtml indentation. The indentation level is null.");
    }
}

/**
 * Encodes the xhtml attributes.
 *
 * @param p0 the destination xhtml byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part details
 * @param p4 the source part details count
 * @param p5 the knowledge memory
 * @param p6 the knowledge memory count
 */
void encode_xhtml_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode xhtml attributes.");

        // The source part details name, abstraction, model, details.
        void** n = NULL_POINTER_MEMORY_MODEL;
        void** nc = NULL_POINTER_MEMORY_MODEL;
        void** ns = NULL_POINTER_MEMORY_MODEL;
        void** a = NULL_POINTER_MEMORY_MODEL;
        void** ac = NULL_POINTER_MEMORY_MODEL;
        void** as = NULL_POINTER_MEMORY_MODEL;
        void** m = NULL_POINTER_MEMORY_MODEL;
        void** mc = NULL_POINTER_MEMORY_MODEL;
        void** ms = NULL_POINTER_MEMORY_MODEL;
        void** d = NULL_POINTER_MEMORY_MODEL;
        void** dc = NULL_POINTER_MEMORY_MODEL;
        void** ds = NULL_POINTER_MEMORY_MODEL;

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Iterate through details parts.
        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            // Get details part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &n, (void*) &nc, (void*) &ns,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            compare_equal_arrays((void*) &r, *n, *nc, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Only add attribute, if the details part name is NOT "tag"!

                // Encode space character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
                // Encode attribute name.
                encode_utf_8_unicode_character_vector(p0, p1, p2, *n, *nc);
                // Encode equals sign character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
                // Encode quotation mark character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
                // Encode space character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, *m, *mc);
                // Encode quotation mark character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
            }

            // Reset source part name, abstraction, model, details.
            n = NULL_POINTER_MEMORY_MODEL;
            nc = NULL_POINTER_MEMORY_MODEL;
            ns = NULL_POINTER_MEMORY_MODEL;
            a = NULL_POINTER_MEMORY_MODEL;
            ac = NULL_POINTER_MEMORY_MODEL;
            as = NULL_POINTER_MEMORY_MODEL;
            m = NULL_POINTER_MEMORY_MODEL;
            mc = NULL_POINTER_MEMORY_MODEL;
            ms = NULL_POINTER_MEMORY_MODEL;
            d = NULL_POINTER_MEMORY_MODEL;
            dc = NULL_POINTER_MEMORY_MODEL;
            ds = NULL_POINTER_MEMORY_MODEL;

            // Reset comparison result.
            r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode xhtml attributes. The source part details count is null.");
    }
}

/**
 * Encodes the xhtml begin tag.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part model
 * @param p4 the source part model count
 * @param p5 the source part details
 * @param p6 the source part details count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 * @param p9 the indentation level (only for beautifying the resulting xhtml code)
 */
void encode_xhtml_begin_tag(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode xhtml begin tag.");

    // Encode indentation.
    encode_xhtml_indentation(p0, p1, p2, p9);
    // Encode less than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    // Encode xhtml tag.
    encode_utf_8_unicode_character_vector(p0, p1, p2, p3, p4);
    // Encode html tag properties.
    encode_xhtml_attributes(p0, p1, p2, p5, p6, p7, p8);
    // Encode greater than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    // Encode line feed character, for better source reading.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
}

/**
 * Encodes the xhtml end tag.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part model
 * @param p4 the source part model count
 * @param p5 the indentation level (only for beautifying the resulting xhtml code)
 */
void encode_xhtml_end_tag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode xhtml end tag.");

    // Encode indentation.
    encode_xhtml_indentation(p0, p1, p2, p5);
    // Encode less than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LESS_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    // Encode solidus character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SOLIDUS_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    // Encode xhtml tag.
    encode_utf_8_unicode_character_vector(p0, p1, p2, p3, p4);
    // Encode greater than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    // Encode line feed character, for better source reading.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
}

/**
 * Encodes the xhtml tag content.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part model
 * @param p4 the source part model count
 * @param p5 the indentation level (only for beautifying the resulting xhtml code)
 */
void encode_xhtml_tag_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* mc = (int*) p4;

        if (*mc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Only add tabulation, model and line feed,
            // if the source part model is NOT empty.

            // Encode indentation.
            encode_xhtml_indentation(p0, p1, p2, p5);
            // Encode source part model.
            encode_utf_8_unicode_character_vector(p0, p1, p2, p3, p4);
            // Encode line feed character, for better source reading.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode xhtml tag content. The model count is null.");
    }
}

/**
 * Encodes an xhtml node.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part abstraction
 * @param p4 the source part abstraction count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part details
 * @param p8 the source part details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the indentation level (only for beautifying the resulting xhtml code)
 */
void encode_xhtml_node(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    if (p11 != *NULL_POINTER_MEMORY_MODEL) {

        int* l = (int*) p11;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            int* sc = (int*) p6;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode xhtml node.");

            // The source part name, abstraction, model, details.
            void** n = NULL_POINTER_MEMORY_MODEL;
            void** nc = NULL_POINTER_MEMORY_MODEL;
            void** ns = NULL_POINTER_MEMORY_MODEL;
            void** a = NULL_POINTER_MEMORY_MODEL;
            void** ac = NULL_POINTER_MEMORY_MODEL;
            void** as = NULL_POINTER_MEMORY_MODEL;
            void** m = NULL_POINTER_MEMORY_MODEL;
            void** mc = NULL_POINTER_MEMORY_MODEL;
            void** ms = NULL_POINTER_MEMORY_MODEL;
            void** d = NULL_POINTER_MEMORY_MODEL;
            void** dc = NULL_POINTER_MEMORY_MODEL;
            void** ds = NULL_POINTER_MEMORY_MODEL;

            // The source part tag name, abstraction, model, details.
            void** tn = NULL_POINTER_MEMORY_MODEL;
            void** tnc = NULL_POINTER_MEMORY_MODEL;
            void** tns = NULL_POINTER_MEMORY_MODEL;
            void** ta = NULL_POINTER_MEMORY_MODEL;
            void** tac = NULL_POINTER_MEMORY_MODEL;
            void** tas = NULL_POINTER_MEMORY_MODEL;
            void** tm = NULL_POINTER_MEMORY_MODEL;
            void** tmc = NULL_POINTER_MEMORY_MODEL;
            void** tms = NULL_POINTER_MEMORY_MODEL;
            void** td = NULL_POINTER_MEMORY_MODEL;
            void** tdc = NULL_POINTER_MEMORY_MODEL;
            void** tds = NULL_POINTER_MEMORY_MODEL;

            // Get source part tag from details.
            get_universal_compound_element_by_name(
                (void*) &tn, (void*) &tnc, (void*) &tns,
                (void*) &ta, (void*) &tac, (void*) &tas,
                (void*) &tm, (void*) &tmc, (void*) &tms,
                (void*) &td, (void*) &tdc, (void*) &tds,
                p7, p8,
                (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT,
                p9, p10);

            // Encode xhtml begin tag.
            encode_xhtml_begin_tag(p0, p1, p2, *tm, *tmc, p7, p8, p9, p10, p11);

            // The new indentation level, which is the old incremented by one.
            int nl = *l + *NUMBER_1_INTEGER_MEMORY_MODEL;
            // The comparison result.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_equal_arrays((void*) &r, p3, p4, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // The part model is a compound.

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Iterate through compound parts.
                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *sc) {

                            break;
                        }

                        // Get part at index j.
                        get_compound_element_by_index(p5, p6, (void*) &j,
                            (void*) &n, (void*) &nc, (void*) &ns,
                            (void*) &a, (void*) &ac, (void*) &as,
                            (void*) &m, (void*) &mc, (void*) &ms,
                            (void*) &d, (void*) &dc, (void*) &ds);

                        // Recursively call this operation for the part model.
                        encode_xhtml_node(p0, p1, p2, *a, *ac, *m, *mc, *d, *dc, p9, p10, (void*) &nl);

                        // Reset source part name, abstraction, model, details.
                        n = NULL_POINTER_MEMORY_MODEL;
                        nc = NULL_POINTER_MEMORY_MODEL;
                        ns = NULL_POINTER_MEMORY_MODEL;
                        a = NULL_POINTER_MEMORY_MODEL;
                        ac = NULL_POINTER_MEMORY_MODEL;
                        as = NULL_POINTER_MEMORY_MODEL;
                        m = NULL_POINTER_MEMORY_MODEL;
                        mc = NULL_POINTER_MEMORY_MODEL;
                        ms = NULL_POINTER_MEMORY_MODEL;
                        d = NULL_POINTER_MEMORY_MODEL;
                        dc = NULL_POINTER_MEMORY_MODEL;
                        ds = NULL_POINTER_MEMORY_MODEL;

                        // Increment loop variable.
                        j++;
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_equal_arrays((void*) &r, p3, p4, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Encode xhtml tag content.
                    encode_xhtml_tag_content(p0, p1, p2, p5, p6, (void*) &nl);
                }
            }

            // Encode xhtml end tag.
            encode_xhtml_end_tag(p0, p1, p2, *tm, *tmc, p11);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into xhtml format. The source count parameter is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode compound model into xhtml format. The indentation level is null.");
    }
}

/**
 * Encodes a compound model into xhtml format.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source part abstraction
 * @param p4 the source part abstraction count
 * @param p5 the source part model
 * @param p6 the source part model count
 * @param p7 the source part details
 * @param p8 the source part details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 */
void encode_xhtml(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode xhtml.");

    // The tree level.
    int l = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Encode xhtml root node.
    encode_xhtml_node(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, (void*) &l);
}

/* XHTML_ENCODER_SOURCE */
#endif
