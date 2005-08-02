/*
 * $RCSfile: tui_translator.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2005-08-02 16:27:07 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TUI_TRANSLATOR_SOURCE
#define TUI_TRANSLATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
//?? TODO: Possibly delete the following line,
//?? if constants are not used here directly!
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/mapper.c"
#include "../../tester/tester.c"

/**
 * Decodes the tui model into a compound model.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source tui model
 * @param p4 the source count
 */
void decode_tui(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the compound model into a tui model.
 *
 * @param p0 the destination tui model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void encode_tui(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p0 != NULL_POINTER) {

            void** de = (void**) p0;

            log_message_debug("Encode compound into textual user interface.");

            // The source part abstraction, model, details.
            void** a = NULL_POINTER;
            void** ac = NULL_POINTER;
            void** as = NULL_POINTER;
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** ms = NULL_POINTER;
            void** d = NULL_POINTER;
            void** dc = NULL_POINTER;
            void** ds = NULL_POINTER;

            // The source part position.
            void** pa = NULL_POINTER;
            void** pac = NULL_POINTER;
            void** pas = NULL_POINTER;
            void** pm = NULL_POINTER;
            void** pmc = NULL_POINTER;
            void** pms = NULL_POINTER;
            void** pd = NULL_POINTER;
            void** pdc = NULL_POINTER;
            void** pds = NULL_POINTER;
            // The source part size.
            void** sa = NULL_POINTER;
            void** sac = NULL_POINTER;
            void** sas = NULL_POINTER;
            void** sm = NULL_POINTER;
            void** smc = NULL_POINTER;
            void** sms = NULL_POINTER;
            void** sd = NULL_POINTER;
            void** sdc = NULL_POINTER;
            void** sds = NULL_POINTER;
            // The source part background colour.
            void** bga = NULL_POINTER;
            void** bgac = NULL_POINTER;
            void** bgas = NULL_POINTER;
            void** bgm = NULL_POINTER;
            void** bgmc = NULL_POINTER;
            void** bgms = NULL_POINTER;
            void** bgd = NULL_POINTER;
            void** bgdc = NULL_POINTER;
            void** bgds = NULL_POINTER;
            // The source part foreground colour.
            void** fga = NULL_POINTER;
            void** fgac = NULL_POINTER;
            void** fgas = NULL_POINTER;
            void** fgm = NULL_POINTER;
            void** fgmc = NULL_POINTER;
            void** fgms = NULL_POINTER;
            void** fgd = NULL_POINTER;
            void** fgdc = NULL_POINTER;
            void** fgds = NULL_POINTER;

            // The source part position x, y, z.
            int** px = NULL_POINTER;
            int** py = NULL_POINTER;
            int** pz = NULL_POINTER;
            // The source part size x, y, z.
            int** sx = NULL_POINTER;
            int** sy = NULL_POINTER;
            int** sz = NULL_POINTER;

            // The source character background property.
            int* bg = NULL_POINTER;
            // The source character foreground property.
            int* fg = NULL_POINTER;
            // The source character hidden property.
            int* h = NULL_POINTER;
            // The source character inverse property.
            int* i = NULL_POINTER;
            // The source character blink property.
            int* bl = NULL_POINTER;
            // The source character underline property.
            int* u = NULL_POINTER;
            // The source character bold property.
            int* b = NULL_POINTER;
            // The source character.
            char* c = NULL_POINTER;

            // The destination tui z layer.
            void* dz = NULL_POINTER;
            int** dzc = NULL_POINTER;
            int** dzs = NULL_POINTER;
            // The destination tui y row.
            void* dy = NULL_POINTER;
            int** dyc = NULL_POINTER;
            int** dys = NULL_POINTER;
            // The destination tui x column (character).
            void* dx = NULL_POINTER;
            int** dxc = NULL_POINTER;
            int** dxs = NULL_POINTER;

            // The loop count.
            int j = 0;
            // The loop counts.
            int z = 0;
            int y = 0;
            int x = 0;
            // The comparison result.
            int r = 0;

            // Iterate through compound parts.
            while (1) {

                if (j >= *sc) {

                    break;
                }

    test_knowledge_model(p3, p4, 2);

                // Get part at index j.
                get_compound_element_by_index(p3, p4, (void*) &j,
                    (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms,
                    (void*) &d, (void*) &dc, (void*) &ds);

    printf("TEST translator char a: %s\n", (char*) *a);
    printf("TEST translator int ac: %i\n", *((int*) *ac));
    printf("TEST translator mp: %i\n", *m);
    printf("TEST translator m: %s\n", (char*) *m);
    printf("TEST translator mc: %i\n", *((int*) *mc));
    printf("TEST translator d: %i\n", d);
    printf("TEST translator dc: %i\n", *((int*) *dc));

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

    printf("TEST translator pa: %s\n", (char*) *pa);
    printf("TEST translator pac: %i\n", *((int*) *pac));
    printf("TEST translator pm pointer 1: %i\n", *pm);
    printf("TEST translator pmc: %i\n", *((int*) *pmc));

                // Get part position x, y, z.
                get(*pm, (void*) TUI_POSITION_X_INDEX, (void*) &px, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(*pm, (void*) TUI_POSITION_Y_INDEX, (void*) &py, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(*pm, (void*) TUI_POSITION_Z_INDEX, (void*) &pz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                // Get part size x, y, z.
                get(*sm, (void*) TUI_SIZE_X_INDEX, (void*) &sx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(*sm, (void*) TUI_SIZE_Y_INDEX, (void*) &sy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(*sm, (void*) TUI_SIZE_Z_INDEX, (void*) &sz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    printf("TEST translator *pz: %i\n", *pz);
    printf("TEST translator **pz: %i\n", **pz);
    printf("TEST translator *sz: %i\n", *sz);
    printf("TEST translator **sz: %i\n", **sz);

                get(p1, (void*) TUI_Z_DIMENSION_INDEX, (void*) &dzc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_Z_DIMENSION_INDEX, (void*) &dzs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p1, (void*) TUI_Y_DIMENSION_INDEX, (void*) &dyc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_Y_DIMENSION_INDEX, (void*) &dys, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p1, (void*) TUI_X_DIMENSION_INDEX, (void*) &dxc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_X_DIMENSION_INDEX, (void*) &dxs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                if (*pz != NULL_POINTER) {

                    // Set tui count and size to given z dimension size minus position.
                    *dec = **sz - **pz;
                    *des = **sz - **pz;

    printf("TEST translator *dec: %i\n", *dec);
    printf("TEST translator *des: %i\n", *des);

                    // Reset z loop index to first position.
                    z = **pz;

    printf("TEST translator z: %i\n", z);

                    // Position characters in their colour and with their size.
                    while (1) {

                        if (z >= **sz) {

                            break;
                        }

                        //?? In a later version, check first if tui z dimension
                        //?? already exists, to speed up its handling!
                        //?? get(*de, (void*) &z, (void*) &dz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        // Allocate tui z dimension count and size.
                        allocate((void*) &dzc, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                        allocate((void*) &dzs, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                        // Set z dimension count and size to given y dimension size minus position.
                        *dzc = **sy - **py;
                        *dzs = **sy - **py;

    printf("TEST translator **py: %i\n", **py);
    printf("TEST translator **sy: %i\n", **sy);

/*??
                        if (dz == NULL_POINTER) {
*/

                            // Allocate tui z dimension.
                            allocate((void*) &dz, (void*) dzs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

/*??
                        } else {

                            // Resize tui z dimension.
                            // The resizing happens in either case, that is if the
                            // new size is greater and if it is smaller than the old size.
                            // If the new size is equal to the old size,
                            // the z dimension pointer remains unchanged.
                            resize((void*) &dz, (void*) dzs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        }
*/

                        // Add new z dimension to destination tui.
                        set(*de, (void*) &z, dz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        // Reset y loop index to first position.
                        y = **py;

                        while (1) {

                            if (y >= **sy) {

                                break;
                            }

                            //?? In a later version, check first if tui y dimension
                            //?? already exists, to speed up its handling!
                            //?? get(dz, (void*) &y, (void*) &dy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            // Allocate tui y dimension count and size.
                            allocate((void*) &dyc, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                            allocate((void*) &dys, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                            // Set y dimension count and size to given x dimension size minus position.
                            *dyc = **sx - **px;
                            *dys = **sx - **px;

    printf("TEST translator **px: %i\n", **px);
    printf("TEST translator **sx: %i\n", **sx);

/*??
                            if (dy == NULL_POINTER) {
*/

                                // Allocate tui y dimension.
                                allocate((void*) &dy, (void*) dys, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

/*??
                            } else {

                                // Resize tui y dimension.
                                // The resizing happens in either case, that is if the
                                // new size is greater and if it is smaller than the old size.
                                // If the new size is equal to the old size,
                                // the y dimension pointer remains unchanged.
                                resize((void*) &dy, (void*) dys, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                            }
*/

                            // Add new y dimension to z dimension.
                            set(dz, (void*) &y, dy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            // Reset x loop index to first position.
                            x = **px;

                            while (1) {

                                if (x >= **sx) {

                                    break;
                                }

                                //?? In a later version, check first if tui x dimension
                                //?? already exists, to speed up its handling!
                                //?? get(dy, (void*) &x, (void*) &dx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // Allocate tui x dimension count and size.
                                allocate((void*) &dxc, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &dxs, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                // Set x dimension count and size to character properties size.
                                *dxc = *TUI_PROPERTIES_COUNT;
                                *dxs = *TUI_PROPERTIES_COUNT;

    printf("TEST translator dxc: %i\n", *dxc);
    printf("TEST translator dxs: %i\n", *dxs);

/*??
                                if (dx == NULL_POINTER) {
*/

                                    // Allocate tui x dimension.
                                    allocate((void*) &dx, (void*) dxs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

/*??
                                } else {

                                    // Resize tui x dimension.
                                    // The resizing happens in either case, that is if the
                                    // new size is greater and if it is smaller than the old size.
                                    // If the new size is equal to the old size,
                                    // the x dimension pointer remains unchanged.
                                    resize((void*) &dx, (void*) dxs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                }
*/

                                // Add new x dimension to y dimension.
                                set(dy, (void*) &x, dx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // Allocate character properties.
                                allocate((void*) &bg, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &fg, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &h, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &i, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &bl, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &u, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &b, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &c, (void*) CHARACTER_COUNT, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    printf("TEST translator bgm string: %s\n", (char*) *bgm);

                                // Get character properties.
                                mapto((void*) &bg, (void*) INTEGER_COUNT, (void*) INTEGER_COUNT, (void*) *bgm, (void*) *bgmc, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT);
                                mapto((void*) &fg, (void*) INTEGER_COUNT, (void*) INTEGER_COUNT, (void*) *fgm, (void*) *fgmc, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT);
                                set((void*) h, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                set((void*) i, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                set((void*) bl, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                set((void*) u, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                set((void*) b, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

    printf("TEST translator bgm integer: %i\n", *bg);
    printf("TEST translator hidden flag: %i\n", *h);

                                // Reset comparison result.
                                r = 0;

                                compare_arrays(*a, *ac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                if (r != 0) {

                                    // Get character property (part string) at position x.
                                    get(*m, (void*) &x, (void*) c, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    printf("TEST translator part character: %s\n", (char*) *m);

                                } else {

                                    // Set character property to space character,
                                    // because the part model is NOT a character.
                                    set((void*) c, (void*) CHARACTER_VALUE_INDEX, (void*) SPACE_CHARACTER, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    printf("TEST translator space character: %s\n", (char*) c);
                                }

                                // Add character properties to x dimension.
                                set(dx, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                set(dx, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    printf("TEST translator x loop count: %i\n", x);

                                x++;
                            }

                            y++;
                        }

                        z++;
                    }

                } else {

                    log_message_debug("Could not encode textual user interface. The tui position is null.");
                }

                // Reset comparison result.
                r = 0;

                compare_arrays(a, ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

    printf("TEST translator recursive call follows r: %i\n", r);

                    // The part model is a compound.

                    // Recursively call this procedure for compound part model.
                    encode_tui(p0, p1, p2, m, mc);
                }

                j++;
            }

        } else {

            log_message_debug("Could not encode textual user interface. The destination parameter is null.");
        }

    } else {

        log_message_debug("Could not encode textual user interface. The source count parameter is null.");
    }
}

/* TUI_TRANSLATOR_SOURCE */
#endif
