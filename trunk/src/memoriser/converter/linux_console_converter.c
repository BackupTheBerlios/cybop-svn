/*
 * $RCSfile: linux_console_converter.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2006-01-02 11:56:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LINUX_CONSOLE_CONVERTER_SOURCE
#define LINUX_CONSOLE_CONVERTER_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/boolean_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/mapper.c"

/**
 * Serialises the linux console model properties into a terminal model.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source linux console model z coordinate
 * @param p4 the source linux console model y coordinate
 * @param p5 the source linux console model x coordinate
 * @param p6 the source linux console model background property
 * @param p7 the source linux console model foreground property
 * @param p8 the source linux console model hidden property
 * @param p9 the source linux console model inverse property
 * @param p10 the source linux console model blink property
 * @param p11 the source linux console model underline property
 * @param p12 the source linux console model bold property
 * @param p13 the source linux console model character property
 */
void serialise_linux_console_properties(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12, void* p13) {

    if (p5 != NULL_POINTER) {

        int* sx = (int*) p5;

        if (p4 != NULL_POINTER) {

            int* sy = (int*) p4;

            if (p2 != NULL_POINTER) {

                int* ds = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* dc = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** d = (void**) p0;

                        if (p13 != NULL_POINTER) {

                            //
                            // The *CHARACTER_VECTOR_REALLOCATE_FACTOR is not necessary
                            // to calculate the new character array size.
                            // However, it is useful to faster increase the character
                            // array size, thus avoiding steady reallocation.
                            //

                            // CAUTION! The top-left terminal corner is 1:1, but the given positions
                            // start counting from 0, so that 1 has to be added to all positions!
                            // Therefore, the coordinates handed over need to be corrected.

                            // The corrected y.
                            int cy = *sy + *NUMBER_1_INTEGER;
                            // The corrected x.
                            int cx = *sx + *NUMBER_1_INTEGER;
                            // The y coordinate.
                            void* y = NULL_POINTER;
                            int yc = 0;
                            int ys = 0;
                            // The x coordinate.
                            void* x = NULL_POINTER;
                            int xc = 0;
                            int xs = 0;
                            // The background colour.
                            void* b = NULL_POINTER;
                            int bc = 0;
                            int bs = 0;
                            // The foreground colour.
                            void* f = NULL_POINTER;
                            int fc = 0;
                            int fs = 0;

                            //
                            // Position cursor.
                            //
                            // Example:
                            // printf("\033[%d;%dH", y_row, x_column)
                            //

                            serialise_integer((void*) &y, (void*) &yc, (void*) &ys, (void*) &cy, (void*) PRIMITIVE_COUNT);
                            serialise_integer((void*) &x, (void*) &xc, (void*) &xs, (void*) &cx, (void*) PRIMITIVE_COUNT);

                            if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                + yc + *CHARACTER_COUNT
                                + xc + *CHARACTER_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT
                                    + yc + *CHARACTER_COUNT
                                    + xc + *CHARACTER_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, y, (void*) &yc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + yc;
                            set_array_elements(*d, p1, (void*) SEMICOLON_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *CHARACTER_COUNT;
                            set_array_elements(*d, p1, x, (void*) &xc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + xc;
                            set_array_elements(*d, p1, (void*) LATIN_CAPITAL_LETTER_H_CHARACTER, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *CHARACTER_COUNT;

                            // Add attribute off control sequence.
                            if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE, (void*) ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT;

                            //
                            // Add background and foreground properties.
                            //
                            // Example:
                            // printf("\033[32mgreen colour\033[0mswitched off.")
                            //

                            // Serialise background colour integer into character array.
                            serialise_integer((void*) &b, (void*) &bc, (void*) &bs, p6, (void*) PRIMITIVE_COUNT);
                            // Serialise foreground colour integer into character array.
                            serialise_integer((void*) &f, (void*) &fc, (void*) &fs, p7, (void*) PRIMITIVE_COUNT);

                            if ((*dc
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + bc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + fc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, b, (void*) &bc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + bc;
                            set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                            set_array_elements(*d, p1, f, (void*) &fc, (void*) CHARACTER_ARRAY);
                            *dc = *dc + fc;
                            set_array_elements(*d, p1, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE, (void*) ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *ATTRIBUTE_SUFFIX_CONTROL_SEQUENCE_COUNT;

                            //
                            // Set character properties.
                            //
                            // Example:
                            // printf("\033[1mbold \033[0mswitched off.")
                            //

                            // Reallocate array to have capacity for all of the
                            // following properties, even if some of them are not used.
                            if ((*dc + *ESCAPE_CONTROL_SEQUENCE_COUNT + *ATTRIBUTE_OFF_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *HIDDEN_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *INVERSE_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BLINK_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *UNDERLINE_CONTROL_SEQUENCE_COUNT
                                + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BOLD_CONTROL_SEQUENCE_COUNT
                                + *CHARACTER_COUNT) >= *ds) {

                                // Set destination character array size.
                                // CAUTION! Add constant in case *dc is zero!
                                *ds = *dc * *CHARACTER_VECTOR_REALLOCATE_FACTOR
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *HIDDEN_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *INVERSE_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BLINK_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *UNDERLINE_CONTROL_SEQUENCE_COUNT
                                    + *ESCAPE_CONTROL_SEQUENCE_COUNT + *BOLD_CONTROL_SEQUENCE_COUNT
                                    + *CHARACTER_COUNT;

                                // Reallocate destination character array.
                                reallocate_array(p0, p1, p2, (void*) CHARACTER_ARRAY);
                            }

                            // The comparison result.
                            int r = 0;

                            // Compare hidden property.
                            compare_arrays(p8, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set hidden property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) HIDDEN_CONTROL_SEQUENCE, (void*) HIDDEN_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *HIDDEN_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare inverse property.
                            compare_arrays(p9, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set inverse property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) INVERSE_CONTROL_SEQUENCE, (void*) INVERSE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *INVERSE_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare blink property.
                            compare_arrays(p10, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set blink property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) BLINK_CONTROL_SEQUENCE, (void*) BLINK_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *BLINK_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare underline property.
                            compare_arrays(p11, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set underline property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) UNDERLINE_CONTROL_SEQUENCE, (void*) UNDERLINE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *UNDERLINE_CONTROL_SEQUENCE_COUNT;
                            }

                            // Reset comparison result.
                            r = 0;

                            // Compare bold property.
                            compare_arrays(p12, (void*) PRIMITIVE_COUNT, (void*) TRUE_BOOLEAN, (void*) PRIMITIVE_COUNT, (void*) &r, (void*) INTEGER_ARRAY);

                            if (r != 0) {

                                // Set bold property.
                                set_array_elements(*d, p1, (void*) ESCAPE_CONTROL_SEQUENCE, (void*) ESCAPE_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *ESCAPE_CONTROL_SEQUENCE_COUNT;
                                set_array_elements(*d, p1, (void*) BOLD_CONTROL_SEQUENCE, (void*) BOLD_CONTROL_SEQUENCE_COUNT, (void*) CHARACTER_ARRAY);
                                *dc = *dc + *BOLD_CONTROL_SEQUENCE_COUNT;
                            }

                            // Set character.
                            set_array_elements(*d, p1, p13, (void*) CHARACTER_COUNT, (void*) CHARACTER_ARRAY);
                            *dc = *dc + *CHARACTER_COUNT;

                        } else {

                            log_message_debug("WARNING: Could not serialise linux console properties. The character is null.");
                        }

                    } else {

                        log_message_debug("Could not serialise linux console properties. The destination is null.");
                    }

                } else {

                    log_message_debug("Could not serialise linux console properties. The destination count is null.");
                }

            } else {

                log_message_debug("Could not serialise linux console properties. The destination size is null.");
            }

        } else {

            log_message_debug("Could not serialise linux console properties. The source y is null.");
        }

    } else {

        log_message_debug("Could not serialise linux console properties. The source x is null.");
    }
}

/**
 * Parses the linux console terminal control sequences into a compound model.
 *
 * @param p0 the destination linux console model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source terminal control sequences
 * @param p4 the source count
 */
void parse_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Serialises the compound model into a linux console terminal control sequences.
 *
 * @param p0 the destination terminal control sequences (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source linux console model
 * @param p4 the source count
 */
void serialise_linux_console(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Serialise compound model into linux console terminal control sequences.");

        // The source part abstraction, model, details.
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        void** m = &NULL_POINTER;
        // CAUTION! This must be int** because its value is used below.
        int** mc = (int**) &NULL_POINTER;
        void** ms = &NULL_POINTER;
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;

        // The source part position.
        void** pa = &NULL_POINTER;
        void** pac = &NULL_POINTER;
        void** pas = &NULL_POINTER;
        void** pm = &NULL_POINTER;
        void** pmc = &NULL_POINTER;
        void** pms = &NULL_POINTER;
        void** pd = &NULL_POINTER;
        void** pdc = &NULL_POINTER;
        void** pds = &NULL_POINTER;
        // The source part size.
        void** sa = &NULL_POINTER;
        void** sac = &NULL_POINTER;
        void** sas = &NULL_POINTER;
        void** sm = &NULL_POINTER;
        void** smc = &NULL_POINTER;
        void** sms = &NULL_POINTER;
        void** sd = &NULL_POINTER;
        void** sdc = &NULL_POINTER;
        void** sds = &NULL_POINTER;
        // The source part background colour.
        void** bga = &NULL_POINTER;
        void** bgac = &NULL_POINTER;
        void** bgas = &NULL_POINTER;
        void** bgm = &NULL_POINTER;
        void** bgmc = &NULL_POINTER;
        void** bgms = &NULL_POINTER;
        void** bgd = &NULL_POINTER;
        void** bgdc = &NULL_POINTER;
        void** bgds = &NULL_POINTER;
        // The source part foreground colour.
        void** fga = &NULL_POINTER;
        void** fgac = &NULL_POINTER;
        void** fgas = &NULL_POINTER;
        void** fgm = &NULL_POINTER;
        void** fgmc = &NULL_POINTER;
        void** fgms = &NULL_POINTER;
        void** fgd = &NULL_POINTER;
        void** fgdc = &NULL_POINTER;
        void** fgds = &NULL_POINTER;
        // The source part hidden property.
        void** ha = &NULL_POINTER;
        void** hac = &NULL_POINTER;
        void** has = &NULL_POINTER;
        void** hm = &NULL_POINTER;
        void** hmc = &NULL_POINTER;
        void** hms = &NULL_POINTER;
        void** hd = &NULL_POINTER;
        void** hdc = &NULL_POINTER;
        void** hds = &NULL_POINTER;
        // The source part inverse property.
        void** ia = &NULL_POINTER;
        void** iac = &NULL_POINTER;
        void** ias = &NULL_POINTER;
        void** im = &NULL_POINTER;
        void** imc = &NULL_POINTER;
        void** ims = &NULL_POINTER;
        void** id = &NULL_POINTER;
        void** idc = &NULL_POINTER;
        void** ids = &NULL_POINTER;
        // The source part blink property.
        void** bla = &NULL_POINTER;
        void** blac = &NULL_POINTER;
        void** blas = &NULL_POINTER;
        void** blm = &NULL_POINTER;
        void** blmc = &NULL_POINTER;
        void** blms = &NULL_POINTER;
        void** bld = &NULL_POINTER;
        void** bldc = &NULL_POINTER;
        void** blds = &NULL_POINTER;
        // The source part underline property.
        void** ua = &NULL_POINTER;
        void** uac = &NULL_POINTER;
        void** uas = &NULL_POINTER;
        void** um = &NULL_POINTER;
        void** umc = &NULL_POINTER;
        void** ums = &NULL_POINTER;
        void** ud = &NULL_POINTER;
        void** udc = &NULL_POINTER;
        void** uds = &NULL_POINTER;
        // The source part bold property.
        void** ba = &NULL_POINTER;
        void** bac = &NULL_POINTER;
        void** bas = &NULL_POINTER;
        void** bm = &NULL_POINTER;
        void** bmc = &NULL_POINTER;
        void** bms = &NULL_POINTER;
        void** bd = &NULL_POINTER;
        void** bdc = &NULL_POINTER;
        void** bds = &NULL_POINTER;

        // The source part position x, y, z.
        int** px = (int**) &NULL_POINTER;
        int** py = (int**) &NULL_POINTER;
        int** pz = (int**) &NULL_POINTER;
        // The source part size x, y, z.
        int** sx = (int**) &NULL_POINTER;
        int** sy = (int**) &NULL_POINTER;
        int** sz = (int**) &NULL_POINTER;

        // The loop count.
        int j = 0;
        // The comparison result.
        int r = 0;

        // Iterate through compound parts.
        while (1) {

            if (j >= *sc) {

                break;
            }

            // Reset source part abstraction, model, details.
            a = &NULL_POINTER;
            ac = &NULL_POINTER;
            as = &NULL_POINTER;
            m = &NULL_POINTER;
            // CAUTION! This must be int** because its value is used below.
            mc = (int**) &NULL_POINTER;
            ms = &NULL_POINTER;
            d = &NULL_POINTER;
            dc = &NULL_POINTER;
            ds = &NULL_POINTER;

            // Reset source part position.
            pa = &NULL_POINTER;
            pac = &NULL_POINTER;
            pas = &NULL_POINTER;
            pm = &NULL_POINTER;
            pmc = &NULL_POINTER;
            pms = &NULL_POINTER;
            pd = &NULL_POINTER;
            pdc = &NULL_POINTER;
            pds = &NULL_POINTER;
            // Reset source part size.
            sa = &NULL_POINTER;
            sac = &NULL_POINTER;
            sas = &NULL_POINTER;
            sm = &NULL_POINTER;
            smc = &NULL_POINTER;
            sms = &NULL_POINTER;
            sd = &NULL_POINTER;
            sdc = &NULL_POINTER;
            sds = &NULL_POINTER;
            // Reset source part background colour.
            bga = &NULL_POINTER;
            bgac = &NULL_POINTER;
            bgas = &NULL_POINTER;
            bgm = &NULL_POINTER;
            bgmc = &NULL_POINTER;
            bgms = &NULL_POINTER;
            bgd = &NULL_POINTER;
            bgdc = &NULL_POINTER;
            bgds = &NULL_POINTER;
            // Reset source part foreground colour.
            fga = &NULL_POINTER;
            fgac = &NULL_POINTER;
            fgas = &NULL_POINTER;
            fgm = &NULL_POINTER;
            fgmc = &NULL_POINTER;
            fgms = &NULL_POINTER;
            fgd = &NULL_POINTER;
            fgdc = &NULL_POINTER;
            fgds = &NULL_POINTER;
            // Reset source part hidden property.
            ha = &NULL_POINTER;
            hac = &NULL_POINTER;
            has = &NULL_POINTER;
            hm = &NULL_POINTER;
            hmc = &NULL_POINTER;
            hms = &NULL_POINTER;
            hd = &NULL_POINTER;
            hdc = &NULL_POINTER;
            hds = &NULL_POINTER;
            // Reset source part inverse property.
            ia = &NULL_POINTER;
            iac = &NULL_POINTER;
            ias = &NULL_POINTER;
            im = &NULL_POINTER;
            imc = &NULL_POINTER;
            ims = &NULL_POINTER;
            id = &NULL_POINTER;
            idc = &NULL_POINTER;
            ids = &NULL_POINTER;
            // Reset source part blink property.
            bla = &NULL_POINTER;
            blac = &NULL_POINTER;
            blas = &NULL_POINTER;
            blm = &NULL_POINTER;
            blmc = &NULL_POINTER;
            blms = &NULL_POINTER;
            bld = &NULL_POINTER;
            bldc = &NULL_POINTER;
            blds = &NULL_POINTER;
            // Reset source part underline property.
            ua = &NULL_POINTER;
            uac = &NULL_POINTER;
            uas = &NULL_POINTER;
            um = &NULL_POINTER;
            umc = &NULL_POINTER;
            ums = &NULL_POINTER;
            ud = &NULL_POINTER;
            udc = &NULL_POINTER;
            uds = &NULL_POINTER;
            // Reset source part bold property.
            ba = &NULL_POINTER;
            bac = &NULL_POINTER;
            bas = &NULL_POINTER;
            bm = &NULL_POINTER;
            bmc = &NULL_POINTER;
            bms = &NULL_POINTER;
            bd = &NULL_POINTER;
            bdc = &NULL_POINTER;
            bds = &NULL_POINTER;

            // Reset source part position x, y, z.
            px = (int**) &NULL_POINTER;
            py = (int**) &NULL_POINTER;
            pz = (int**) &NULL_POINTER;
            // Reset source part size x, y, z.
            sx = (int**) &NULL_POINTER;
            sy = (int**) &NULL_POINTER;
            sz = (int**) &NULL_POINTER;

            // Get part at index j.
            get_compound_element_by_index(p3, p4, (void*) &j,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            // Get part position from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_POSITION_NAME, (void*) TUI_POSITION_NAME_COUNT,
                (void*) &pa, (void*) &pac, (void*) &pas,
                (void*) &pm, (void*) &pmc, (void*) &pms,
                (void*) &pd, (void*) &pdc, (void*) &pds);
            // Get part size from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_SIZE_NAME, (void*) TUI_SIZE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds);
            // Get part background colour from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_BACKGROUND_NAME, (void*) TUI_BACKGROUND_NAME_COUNT,
                (void*) &bga, (void*) &bgac, (void*) &bgas,
                (void*) &bgm, (void*) &bgmc, (void*) &bgms,
                (void*) &bgd, (void*) &bgdc, (void*) &bgds);
            // Get part foreground colour from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_FOREGROUND_NAME, (void*) TUI_FOREGROUND_NAME_COUNT,
                (void*) &fga, (void*) &fgac, (void*) &fgas,
                (void*) &fgm, (void*) &fgmc, (void*) &fgms,
                (void*) &fgd, (void*) &fgdc, (void*) &fgds);
            // Get part hidden property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_HIDDEN_NAME, (void*) TUI_HIDDEN_NAME_COUNT,
                (void*) &ha, (void*) &hac, (void*) &has,
                (void*) &hm, (void*) &hmc, (void*) &hms,
                (void*) &hd, (void*) &hdc, (void*) &hds);
            // Get part inverse property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_INVERSE_NAME, (void*) TUI_INVERSE_NAME_COUNT,
                (void*) &ia, (void*) &iac, (void*) &ias,
                (void*) &im, (void*) &imc, (void*) &ims,
                (void*) &id, (void*) &idc, (void*) &ids);
            // Get part blink property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_BLINK_NAME, (void*) TUI_BLINK_NAME_COUNT,
                (void*) &bla, (void*) &blac, (void*) &blas,
                (void*) &blm, (void*) &blmc, (void*) &blms,
                (void*) &bld, (void*) &bldc, (void*) &blds);
            // Get part underline property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_UNDERLINE_NAME, (void*) TUI_UNDERLINE_NAME_COUNT,
                (void*) &ua, (void*) &uac, (void*) &uas,
                (void*) &um, (void*) &umc, (void*) &ums,
                (void*) &ud, (void*) &udc, (void*) &uds);
            // Get part bold property from details.
            get_compound_element_by_name(*d, *dc,
                (void*) TUI_BOLD_NAME, (void*) TUI_BOLD_NAME_COUNT,
                (void*) &ba, (void*) &bac, (void*) &bas,
                (void*) &bm, (void*) &bmc, (void*) &bms,
                (void*) &bd, (void*) &bdc, (void*) &bds);

            // Get part position x, y, z.
            get(*pm, (void*) TUI_POSITION_X_INDEX, (void*) &px, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*pm, (void*) TUI_POSITION_Y_INDEX, (void*) &py, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*pm, (void*) TUI_POSITION_Z_INDEX, (void*) &pz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            // Get part size x, y, z.
            get(*sm, (void*) TUI_SIZE_X_INDEX, (void*) &sx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*sm, (void*) TUI_SIZE_Y_INDEX, (void*) &sy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            get(*sm, (void*) TUI_SIZE_Z_INDEX, (void*) &sz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            if ((*pz != NULL_POINTER)
                && (*py != NULL_POINTER)
                && (*px != NULL_POINTER)
                && (*sz != NULL_POINTER)
                && (*sy != NULL_POINTER)
                && (*sx != NULL_POINTER)) {

                // Reallocate tui.
                // CAUTION! The old count ocz is used, so that
                // only new elements get initialised with NULL.
//??                reallocate(p0, (void*) &ocz, (void*) *dsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

/*??
                // Not existing columns (characters) are skipped.
                if (*xm != NULL_POINTER) {

                    // Get properties and the character itself.
                    get(*xm, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) &h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) &bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) &u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                    get(*xm, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                    serialise_linux_console_properties(p0, p1, p2,
                        (void*) &z, (void*) &y, (void*) &x,
                        *bg, *fg, *h, *i, *bl, *u, *b, *c);

                } else {

                    log_message_debug("WARNING: Could not serialise compound model. The x column (character) is null.");
                }
*/

            } else {

                log_message_debug("Could not serialise compound model into linux console terminal control sequences. At least one tui position or size is null.");
            }

            // Reset comparison result.
            r = 0;

            compare_arrays(*a, *ac, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 0) {

                // The part model is a compound.

                // Recursively call this procedure for compound part model.
                serialise_linux_console(p0, p1, p2, *m, (void*) *mc);
            }

            j++;
        }

/*??
    // The source count z, y, x coordinates.
    int** scz = (int**) &NULL_POINTER;
    int** scy = (int**) &NULL_POINTER;
    int** scx = (int**) &NULL_POINTER;

    // Get source count z, y, x coordinates.
    get(p4, (void*) TUI_Z_DIMENSION_INDEX, (void*) &scz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p4, (void*) TUI_Y_DIMENSION_INDEX, (void*) &scy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p4, (void*) TUI_X_DIMENSION_INDEX, (void*) &scx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // The loop counts.
    int z = 0;
    int y = 0;
    int x = 0;

    // The z, y, x models.
    void** zm = &NULL_POINTER;
    void** ym = &NULL_POINTER;
    void** xm = &NULL_POINTER;

    // The background property.
    void** bg = &NULL_POINTER;
    // The background property.
    void** fg = &NULL_POINTER;
    // The hidden property.
    void** h = &NULL_POINTER;
    // The inverse property.
    void** i = &NULL_POINTER;
    // The blink property.
    void** bl = &NULL_POINTER;
    // The underline property.
    void** u = &NULL_POINTER;
    // The bold property.
    void** b = &NULL_POINTER;
    // The character.
    void** c = &NULL_POINTER;

    // Reset z loop count.
    z = 0;

    while (1) {

        if (z >= **scz) {

            break;
        }

        // Reset z model.
        zm = &NULL_POINTER;

        // Get z dimension layer.
        get(p3, (void*) &z, (void*) &zm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Not existing layers are skipped.
        if (*zm != NULL_POINTER) {

            // Reset y loop count.
            y = 0;

            while (1) {

                if (y >= **scy) {

                    break;
                }

                // Reset y model.
                ym = &NULL_POINTER;

                // Get y dimension row.
                get(*zm, (void*) &y, (void*) &ym, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                // Not existing rows are skipped.
                if (*ym != NULL_POINTER) {

                    // Reset x loop count.
                    x = 0;

                    while (1) {

                        if (x >= **scx) {

                            break;
                        }

                        // Reset x model.
                        xm = &NULL_POINTER;

                        // Get x dimension column.
                        get(*ym, (void*) &x, (void*) &xm, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        // Not existing columns (characters) are skipped.
                        if (*xm != NULL_POINTER) {

                            // Get properties and the character itself.
                            get(*xm, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) &h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) &bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) &u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            get(*xm, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            serialise_linux_console_properties(p0, p1, p2,
                                (void*) &z, (void*) &y, (void*) &x,
                                *bg, *fg, *h, *i, *bl, *u, *b, *c);

                        } else {

                            log_message_debug("WARNING: Could not serialise compound model. The x column (character) is null.");
                        }

                        x++;
                    }

                } else {

                    log_message_debug("WARNING: Could not serialise compound model. The y row is null.");
                }

                y++;
            }

        } else {

            log_message_debug("WARNING: Could not serialise compound model. The z layer is null.");
        }

        z++;
    }

    } else {

        log_message_debug("Could not serialise compound model. The source count parameter is null.");
    }
*/

    } else {

        log_message_debug("Could not serialise compound model into linux console terminal control sequences. The source count parameter is null.");
    }
}

/* LINUX_CONSOLE_CONVERTER_SOURCE */
#endif
