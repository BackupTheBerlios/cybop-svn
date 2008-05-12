/*
 * $RCSfile: xhtml_converter.c,v $
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
 * @version $Revision: 1.16 $ $Date: 2008-05-12 10:58:59 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XHTML_CONVERTER_SOURCE
#define XHTML_CONVERTER_SOURCE

#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_abstraction_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/array.c"

/**
 * Decodes an xhtml format into a compound model.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source xhtml byte array
 * @param p4 the source count
 */
void decode_xhtml(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the xhtml indentation.
 *
 * @param p0 the destination html byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the indentation level (only for beautifying the resulting xhtml code)
 */
void encode_xhtml_indentation(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* l = (int*) p3;

        // The loop variable.
        int j = *NUMBER_0_INTEGER;

        while (*NUMBER_1_INTEGER) {

            if (j >= *l) {

                break;
            }

            // Encode character tabulation character.
//??            encode_character_vector(p0, p1, p2, (void*) CHARACTER_TABULATION_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT);

            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
            // Encode space character.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);

            // Increment loop count.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode xhtml indentation. The indentation level is null.");
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

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode xhtml attributes.");

        // The source part details name, abstraction, model, details.
        void** n = NULL_POINTER;
        void** nc = NULL_POINTER;
        void** ns = NULL_POINTER;
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        void** as = NULL_POINTER;
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;

        // The loop variable.
        int j = *NUMBER_0_INTEGER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        // Iterate through details parts.
        while (*NUMBER_1_INTEGER) {

            if (j >= *sc) {

                break;
            }

            // Get details part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &n, (void*) &nc, (void*) &ns,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            compare_arrays(*n, *nc, (void*) WUI_TAG_NAME, (void*) WUI_TAG_NAME_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == *NUMBER_0_INTEGER) {

                // Only add attribute, if the details part name is NOT "tag"!

                // Encode space character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SPACE_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
                // Encode attribute name.
                encode_utf_8_unicode_character_vector(p0, p1, p2, *n, *nc);
                // Encode equals sign character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) EQUALS_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
                // Encode quotation mark character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) QUOTATION_MARK_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
                // Encode space character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, *m, *mc);
                // Encode quotation mark character.
                encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) QUOTATION_MARK_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
            }

            // Reset source part name, abstraction, model, details.
            n = NULL_POINTER;
            nc = NULL_POINTER;
            ns = NULL_POINTER;
            a = NULL_POINTER;
            ac = NULL_POINTER;
            as = NULL_POINTER;
            m = NULL_POINTER;
            mc = NULL_POINTER;
            ms = NULL_POINTER;
            d = NULL_POINTER;
            dc = NULL_POINTER;
            ds = NULL_POINTER;

            // Reset comparison result.
            r = *NUMBER_0_INTEGER;

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode xhtml attributes. The source part details count is null.");
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

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode xhtml begin tag.");

    // Encode indentation.
    encode_xhtml_indentation(p0, p1, p2, p9);
    // Encode less than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LESS_THAN_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Encode xhtml tag.
    encode_utf_8_unicode_character_vector(p0, p1, p2, p3, p4);
    // Encode html tag properties.
    encode_xhtml_attributes(p0, p1, p2, p5, p6, p7, p8);
    // Encode greater than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) GREATER_THAN_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Encode line feed character, for better source reading.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
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

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode xhtml end tag.");

    // Encode indentation.
    encode_xhtml_indentation(p0, p1, p2, p5);
    // Encode less than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LESS_THAN_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Encode solidus character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) SOLIDUS_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Encode xhtml tag.
    encode_utf_8_unicode_character_vector(p0, p1, p2, p3, p4);
    // Encode greater than character.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) GREATER_THAN_SIGN_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    // Encode line feed character, for better source reading.
    encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
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

    if (p4 != *NULL_POINTER) {

        int* mc = (int*) p4;

        if (*mc > *NUMBER_0_INTEGER) {

            // Only add tabulation, model and line feed,
            // if the source part model is NOT empty.

            // Encode indentation.
            encode_xhtml_indentation(p0, p1, p2, p5);
            // Encode source part model.
            encode_utf_8_unicode_character_vector(p0, p1, p2, p3, p4);
            // Encode line feed character, for better source reading.
            encode_utf_8_unicode_character_vector(p0, p1, p2, (void*) LINE_FEED_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode xhtml tag content. The model count is null.");
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

    if (p11 != *NULL_POINTER) {

        int* l = (int*) p11;

        if (p6 != *NULL_POINTER) {

            int* sc = (int*) p6;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Encode xhtml node.");

            // The source part name, abstraction, model, details.
            void** n = NULL_POINTER;
            void** nc = NULL_POINTER;
            void** ns = NULL_POINTER;
            void** a = NULL_POINTER;
            void** ac = NULL_POINTER;
            void** as = NULL_POINTER;
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** ms = NULL_POINTER;
            void** d = NULL_POINTER;
            void** dc = NULL_POINTER;
            void** ds = NULL_POINTER;

            // The source part tag name, abstraction, model, details.
            void** tn = NULL_POINTER;
            void** tnc = NULL_POINTER;
            void** tns = NULL_POINTER;
            void** ta = NULL_POINTER;
            void** tac = NULL_POINTER;
            void** tas = NULL_POINTER;
            void** tm = NULL_POINTER;
            void** tmc = NULL_POINTER;
            void** tms = NULL_POINTER;
            void** td = NULL_POINTER;
            void** tdc = NULL_POINTER;
            void** tds = NULL_POINTER;

            // Get source part tag from details.
            get_universal_compound_element_by_name(p7, p8,
                (void*) WUI_TAG_NAME, (void*) WUI_TAG_NAME_COUNT,
                (void*) &tn, (void*) &tnc, (void*) &tns,
                (void*) &ta, (void*) &tac, (void*) &tas,
                (void*) &tm, (void*) &tmc, (void*) &tms,
                (void*) &td, (void*) &tdc, (void*) &tds,
                p9, p10);

            // Encode xhtml begin tag.
            encode_xhtml_begin_tag(p0, p1, p2, *tm, *tmc, p7, p8, p9, p10, p11);

            // The new indentation level, which is the old incremented by one.
            int nl = *l + *NUMBER_1_INTEGER;
            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // The part model is a compound.

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER;

                    // Iterate through compound parts.
                    while (*NUMBER_1_INTEGER) {

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
                        n = NULL_POINTER;
                        nc = NULL_POINTER;
                        ns = NULL_POINTER;
                        a = NULL_POINTER;
                        ac = NULL_POINTER;
                        as = NULL_POINTER;
                        m = NULL_POINTER;
                        mc = NULL_POINTER;
                        ms = NULL_POINTER;
                        d = NULL_POINTER;
                        dc = NULL_POINTER;
                        ds = NULL_POINTER;

                        // Increment loop variable.
                        j++;
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                compare_arrays(p3, p4, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Encode xhtml tag content.
                    encode_xhtml_tag_content(p0, p1, p2, p5, p6, (void*) &nl);
                }
            }

            // Encode xhtml end tag.
            encode_xhtml_end_tag(p0, p1, p2, *tm, *tmc, p11);

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode compound model into xhtml format. The source count parameter is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not encode compound model into xhtml format. The indentation level is null.");
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

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode xhtml.");

    // The tree level.
    int l = *NUMBER_0_INTEGER;

    // Encode xhtml root node.
    encode_xhtml_node(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, (void*) &l);
}

/* XHTML_CONVERTER_SOURCE */
#endif
