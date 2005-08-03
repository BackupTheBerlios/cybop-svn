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
 * @version $Revision: 1.10 $ $Date: 2005-08-03 13:20:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TUI_TRANSLATOR_SOURCE
#define TUI_TRANSLATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/control_sequence_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/mapper.c"
//?? TEST only
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
            // CAUTION! This must be int** because its value is used below.
            int** mc = NULL_POINTER;
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

            // The already existing destination tui layers.
            void** dzp = NULL_POINTER;
            void** dyp = NULL_POINTER;
            void** dxp = NULL_POINTER;
            // The destination tui layers, rows and columns (characters).
            void* dz = NULL_POINTER;
            void* dy = NULL_POINTER;
            void* dx = NULL_POINTER;
            // The destination tui count and size z, y, x coordinates.
            int** dcz = NULL_POINTER;
            int** dcy = NULL_POINTER;
            int** dcx = NULL_POINTER;
            // The destination tui sizes.
            int** dsz = NULL_POINTER;
            int** dsy = NULL_POINTER;
            int** dsx = NULL_POINTER;

            // The already existing destination tui character background property.
            void** bgp = NULL_POINTER;
            // The already existing destination tui character foreground property.
            void** fgp = NULL_POINTER;
            // The already existing destination tui character hidden property.
            void** hp = NULL_POINTER;
            // The already existing destination tui character inverse property.
            void** ip = NULL_POINTER;
            // The already existing destination tui character blink property.
            void** blp = NULL_POINTER;
            // The already existing destination tui character underline property.
            void** up = NULL_POINTER;
            // The already existing destination tui character bold property.
            void** bp = NULL_POINTER;
            // The already existing destination tui character.
            void** cp = NULL_POINTER;

            // The destination tui character background property.
            void* bg = NULL_POINTER;
            // The destination tui character foreground property.
            void* fg = NULL_POINTER;
            // The destination tui character hidden property.
            void* h = NULL_POINTER;
            // The destination tui character inverse property.
            void* i = NULL_POINTER;
            // The destination tui character blink property.
            void* bl = NULL_POINTER;
            // The destination tui character underline property.
            void* u = NULL_POINTER;
            // The destination tui character bold property.
            void* b = NULL_POINTER;
            // The destination tui character.
            void* c = NULL_POINTER;

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

                get(p1, (void*) TUI_Z_DIMENSION_INDEX, (void*) &dcz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    printf("TEST translator 0: %i\n", **sz);
                get(p1, (void*) TUI_Y_DIMENSION_INDEX, (void*) &dcy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p1, (void*) TUI_X_DIMENSION_INDEX, (void*) &dcx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_Z_DIMENSION_INDEX, (void*) &dsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_Y_DIMENSION_INDEX, (void*) &dsy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_X_DIMENSION_INDEX, (void*) &dsx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    printf("TEST translator 1: %i\n", **sz);
                if ((*pz != NULL_POINTER)
                    && (*py != NULL_POINTER)
                    && (*px != NULL_POINTER)
                    && (*sz != NULL_POINTER)
                    && (*sy != NULL_POINTER)
                    && (*sx != NULL_POINTER)) {

    printf("TEST translator 2: %i\n", **sz);
                    // The tui z position has to be smaller than the size.
                    if (**pz < **sz) {

    printf("TEST translator 3 dsz: %i\n", dsz);
    printf("TEST translator 3 *dsz: %i\n", *dsz);
    printf("TEST translator 3 **dsz: %i\n", **dsz);

                        if ((**pz + **sz) > **dsz) {

    printf("TEST translator 4: %i\n", **sz);
                            **dsz = **pz + **sz;

    printf("TEST translator 5: %i\n", **sz);
                            // Reallocate tui.
                            resize(p0, (void*) *dsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                        }

    printf("TEST translator **dsz: %i\n", **dsz);

                        // Reset z loop index to first position.
                        z = **pz;

    printf("TEST translator z: %i\n", z);

                        // Position characters in their colour and with their size.
                        while (1) {

                            if (z >= **sz) {

                                break;
                            }

                            // Check if tui z dimension already exists.
                            get(*de, (void*) &z, (void*) &dzp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            if (*dzp == NULL_POINTER) {

                                // Allocate tui z dimension.
                                allocate((void*) &dz, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // Add new z dimension to tui.
                                set(*de, (void*) &z, dz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            } else {

                                // Use already existing tui z dimension.
                                dz = *dzp;
                            }

                            // The tui y position has to be smaller than the size.
                            if (**py < **sy) {

                                if ((**py + **sy) > **dsy) {

                                    **dsy = **py + **sy;

                                    // Reallocate tui z layer.
                                    resize((void*) &dz, (void*) *dsy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                }

    printf("TEST translator **dsy: %i\n", **dsy);

                                // Reset y loop index to first position.
                                y = **py;

    printf("TEST translator y: %i\n", y);

                                while (1) {

                                    if (y >= **sy) {

                                        break;
                                    }

                                    // Check if tui y dimension already exists.
                                    get(dz, (void*) &y, (void*) &dyp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                    if (*dyp == NULL_POINTER) {

                                        // Allocate tui y dimension.
                                        allocate((void*) &dy, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                        // Add new y dimension to z dimension.
                                        set(dz, (void*) &y, dy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                    } else {

                                        // Use already existing tui y dimension.
                                        dy = *dyp;
                                    }

                                    // The tui x position has to be smaller than the size.
                                    if (**px < **sx) {

                                        if ((**px + **sx) > **dsx) {

                                            **dsx = **px + **sx;

                                            // Reallocate tui y layer.
                                            resize((void*) &dy, (void*) *dsx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                        }

    printf("TEST translator **dsx: %i\n", **dsx);

                                        // Reset y loop index to first position.
                                        x = **px;

    printf("TEST translator x: %i\n", x);

                                        while (1) {

                                            if (x >= **sx) {

                                                break;
                                            }

                                            // Check if tui x dimension already exists.
                                            get(dy, (void*) &x, (void*) &dxp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            if (*dxp == NULL_POINTER) {

                                                // Allocate tui x dimension.
                                                allocate((void*) &dx, (void*) TUI_PROPERTIES_COUNT, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                                // Add new x dimension to y dimension.
                                                set(dy, (void*) &x, dx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui x dimension.
                                                dx = *dxp;
                                            }

                                            // Check if tui character properties already exist.
                                            get(dx, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) &bgp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) &fgp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) &hp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) &ip, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) &blp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) &up, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) &bp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            get(dx, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) &cp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            if (*bgp == NULL_POINTER) {

                                                // Allocate tui character background property.
                                                allocate((void*) &bg, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character background property.
                                                set(dx, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character background property.
                                                bg = *bgp;
                                            }

                                            if (*fgp == NULL_POINTER) {

                                                // Allocate tui character foreground property.
                                                allocate((void*) &fg, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character foreground property.
                                                set(dx, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character foreground property.
                                                fg = *fgp;
                                            }

                                            if (*hp == NULL_POINTER) {

                                                // Allocate tui character hidden property.
                                                allocate((void*) &h, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character hidden property.
                                                set(dx, (void*) TUI_PROPERTIES_HIDDEN_INDEX, h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character hidden property.
                                                h = *hp;
                                            }

                                            if (*ip == NULL_POINTER) {

                                                // Allocate tui character inverse property.
                                                allocate((void*) &i, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character inverse property.
                                                set(dx, (void*) TUI_PROPERTIES_INVERSE_INDEX, i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character inverse property.
                                                i = *ip;
                                            }

                                            if (*blp == NULL_POINTER) {

                                                // Allocate tui character blink property.
                                                allocate((void*) &bl, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character blink property.
                                                set(dx, (void*) TUI_PROPERTIES_BLINK_INDEX, bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character blink property.
                                                bl = *blp;
                                            }

                                            if (*up == NULL_POINTER) {

                                                // Allocate tui character underline property.
                                                allocate((void*) &u, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character underline property.
                                                set(dx, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character underline property.
                                                u = *up;
                                            }

                                            if (*bp == NULL_POINTER) {

                                                // Allocate tui character bold property.
                                                allocate((void*) &b, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                                // Add tui character bold property.
                                                set(dx, (void*) TUI_PROPERTIES_BOLD_INDEX, b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character bold property.
                                                b = *bp;
                                            }

                                            if (*cp == NULL_POINTER) {

                                                // Allocate tui character.
                                                allocate((void*) &c, (void*) CHARACTER_COUNT, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

                                                // Add tui character.
                                                set(dx, (void*) TUI_PROPERTIES_CHARACTER_INDEX, c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            } else {

                                                // Use already existing tui character.
                                                c = *cp;
                                            }

    printf("TEST translator bgm string *bgm: %s\n", (char*) *bgm);

                                            // Get character properties.
                                            mapto((void*) &bg, (void*) INTEGER_COUNT, (void*) INTEGER_COUNT, (void*) *bgm, (void*) *bgmc, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT);
                                            mapto((void*) &fg, (void*) INTEGER_COUNT, (void*) INTEGER_COUNT, (void*) *fgm, (void*) *fgmc, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT);
                                            //?? TODO: Replace temporary test values like
                                            //?? NUMBER_0_INTEGER with real properties!
                                            set((void*) h, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                            set((void*) i, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                            set((void*) bl, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                            set((void*) u, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                            set((void*) b, (void*) INTEGER_VALUE_INDEX, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

    printf("TEST translator bgm integer *bg: %i\n", *((int*) bg));
    printf("TEST translator hidden flag *h: %i\n", *((int*) h));

                                            // Reset comparison result.
                                            r = 0;

                                            compare_arrays(*a, *ac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                            // CAUTION! The whole row may be much longer than the given string.
                                            // Therefore, only take characters if the index x is smaller than
                                            // the source string model count.
                                            if ((r != 0) && (x < **mc)) {

                                                // Get character property (part string) at position x.
                                                get(*m, (void*) &x, (void*) &c, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    printf("TEST translator part character *m: %s\n", (char*) *m);

                                            } else {

                                                // Set character property to space character,
                                                // because the part model is NOT a character,
                                                // or the string length is smaller than
                                                // the length of the row.
                                                set((void*) c, (void*) CHARACTER_VALUE_INDEX, (void*) SPACE_CHARACTER, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

    printf("TEST translator space character c: %s\n", (char*) c);
                                            }

//??    printf("TEST translator x loop count: %i\n", x);

                                            x++;
                                        }

                                    } else {

                                        log_message_debug("Could not encode textual user interface. The x position is greater or equal to the size.");
                                    }

                                    y++;
                                }

                            } else {

                                log_message_debug("Could not encode textual user interface. The y position is greater or equal to the size.");
                            }

                            z++;
                        }

                    } else {

                        log_message_debug("Could not encode textual user interface. The z position is greater or equal to the size.");
                    }

                } else {

                    log_message_debug("Could not encode textual user interface. At least one tui position or size is null.");
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
