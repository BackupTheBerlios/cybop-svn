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
 * @version $Revision: 1.19 $ $Date: 2005-08-10 09:38:07 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TUI_TRANSLATOR_SOURCE
#define TUI_TRANSLATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/character_constants.c"
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

            // The character value.
            void* v = NULL_POINTER;
            // The source part model index.
            int mi = 0;

            // The already existing destination tui layers, rows and columns (characters).
            void** dzp = &NULL_POINTER;
            void** dyp = &NULL_POINTER;
            void** dxp = &NULL_POINTER;
            // The destination tui layers, rows and columns (characters).
            void* dz = NULL_POINTER;
            void* dy = NULL_POINTER;
            void* dx = NULL_POINTER;
            // The old tui count z, y, x coordinates.
            int ocz = 0;
            int ocy = 0;
            int ocx = 0;
            // The destination tui count z, y, x coordinates.
            int** dcz = (int**) &NULL_POINTER;
            int** dcy = (int**) &NULL_POINTER;
            int** dcx = (int**) &NULL_POINTER;
            // The destination tui size z, y, x coordinates.
            int** dsz = (int**) &NULL_POINTER;
            int** dsy = (int**) &NULL_POINTER;
            int** dsx = (int**) &NULL_POINTER;

            // The already existing destination tui character background property.
            void** bgp = &NULL_POINTER;
            // The already existing destination tui character foreground property.
            void** fgp = &NULL_POINTER;
            // The already existing destination tui character hidden property.
            void** hp = &NULL_POINTER;
            // The already existing destination tui character inverse property.
            void** ip = &NULL_POINTER;
            // The already existing destination tui character blink property.
            void** blp = &NULL_POINTER;
            // The already existing destination tui character underline property.
            void** up = &NULL_POINTER;
            // The already existing destination tui character bold property.
            void** bp = &NULL_POINTER;
            // The already existing destination tui character.
            void** cp = &NULL_POINTER;

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

    printf("TEST translator j: %i\n", j);

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

                // Reset character value.
                v = NULL_POINTER;
                // Reset source part model index.
                mi = 0;

                // Reset destination tui count z, y, x coordinates.
                dcz = (int**) &NULL_POINTER;
                dcy = (int**) &NULL_POINTER;
                dcx = (int**) &NULL_POINTER;
                // Reset destination tui size z, y, x coordinates.
                dsz = (int**) &NULL_POINTER;
                dsy = (int**) &NULL_POINTER;
                dsx = (int**) &NULL_POINTER;

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

                get(p1, (void*) TUI_Z_DIMENSION_INDEX, (void*) &dcz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p1, (void*) TUI_Y_DIMENSION_INDEX, (void*) &dcy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p1, (void*) TUI_X_DIMENSION_INDEX, (void*) &dcx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_Z_DIMENSION_INDEX, (void*) &dsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_Y_DIMENSION_INDEX, (void*) &dsy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p2, (void*) TUI_X_DIMENSION_INDEX, (void*) &dsx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                // Store old tui count z, y, x coordinates.
                ocz = **dcz;
                ocy = **dcy;
                ocx = **dcx;

                if ((*pz != NULL_POINTER)
                    && (*py != NULL_POINTER)
                    && (*px != NULL_POINTER)
                    && (*sz != NULL_POINTER)
                    && (*sy != NULL_POINTER)
                    && (*sx != NULL_POINTER)) {

                    // The tui z position has to be smaller than the size.
                    if (**pz < **sz) {

                        if ((**pz + **sz) > **dsz) {

                            **dsz = **pz + **sz;

                            // Initialise destination z dimension count.
                            // CAUTION! It has to be set equal to the size here,
                            // so that later reallocations will not overwrite
                            // existing elements during initialisation with NULL.
                            **dcz = **dsz;
                        }

                        // Reallocate tui.
                        // CAUTION! The old count ocz is used, so that
                        // only new elements get initialised with NULL.
                        reallocate(p0, (void*) &ocz, (void*) *dsz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                        // Reset z loop index to first position.
                        z = **pz;

                        // Position characters in their colour and with their size.
                        while (1) {

    printf("TEST translator z: %i\n", z);

                            if (z >= (**pz + **sz)) {

                                break;
                            }

                            // Reset already existing destination tui layer.
                            dzp = &NULL_POINTER;
                            // Reset destination tui layer.
                            dz = NULL_POINTER;

                            // Check if tui z dimension already exists.
                            get(*de, (void*) &z, (void*) &dzp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            if (*dzp != NULL_POINTER) {

                                // Use already existing tui z dimension.
                                dz = *dzp;

                            } else {

                                // Allocate tui z dimension.
                                allocate((void*) &dz, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // Add new z dimension to tui.
                                set(*de, (void*) &z, &dz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // CAUTION! Do NOT increase z dimension count here!
                                // It is already set at reallocation above.
                            }

                            // The tui y position has to be smaller than the size.
                            if (**py < **sy) {

                                if ((**py + **sy) > **dsy) {

                                    **dsy = **py + **sy;

                                    // Initialise destination y dimension count.
                                    // CAUTION! It has to be set equal to the size here,
                                    // so that later reallocations will not overwrite
                                    // existing elements during initialisation with NULL.
                                    **dcy = **dsy;
                                }

                                // Reallocate tui z layer.
                                // CAUTION! The old count ocy is used, so that
                                // only new elements get initialised with NULL.
                                reallocate((void*) &dz, (void*) &ocy, (void*) *dsy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // Add new z dimension to tui.
                                // CAUTION! The reallocate procedure returns
                                // a different pointer, so that it has to be
                                // set again here.
                                set(*de, (void*) &z, &dz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // CAUTION! Do NOT increase destination
                                // z dimension count here, since dz already
                                // exists within de and is just reallocated!

                                // Reset y loop index to first position.
                                y = **py;

                                while (1) {

    printf("TEST translator y: %i\n", y);

                                    if (y >= (**py + **sy)) {

                                        break;
                                    }

                                    // Reset already existing row.
                                    dyp = &NULL_POINTER;
                                    // Reset destination tui row.
                                    dy = NULL_POINTER;

                                    // Check if tui y dimension already exists.
                                    get(dz, (void*) &y, (void*) &dyp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                    if (*dyp != NULL_POINTER) {

                                        // Use already existing tui y dimension.
                                        dy = *dyp;

                                    } else {

                                        // Allocate tui y dimension.
                                        allocate((void*) &dy, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                        // Add new y dimension to z dimension.
                                        set(dz, (void*) &y, &dy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                        // CAUTION! Do NOT increase y dimension count here!
                                        // It is already set at reallocation above.
                                    }

                                    // The tui x position has to be smaller than the size.
                                    if (**px < **sx) {

                                        if ((**px + **sx) > **dsx) {

                                            **dsx = **px + **sx;

                                            // Initialise destination x dimension count.
                                            // CAUTION! It has to be set equal to the size here,
                                            // so that later reallocations will not overwrite
                                            // existing elements during initialisation with NULL.
                                            **dcx = **dsx;
                                        }

                                        // Reallocate tui y layer.
                                        // CAUTION! The old count ocx is used, so that
                                        // only new elements get initialised with NULL.
                                        reallocate((void*) &dy, (void*) &ocx, (void*) *dsx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                        // Add new y dimension to z dimension.
                                        // CAUTION! The reallocate procedure returns
                                        // a different pointer, so that it has to be
                                        // set again here.
                                        set(dz, (void*) &y, &dy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                        // CAUTION! Do NOT increase destination
                                        // y dimension count here, since dy already
                                        // exists within dz and is just reallocated!

                                        // Reset y loop index to first position.
                                        x = **px;

                                        while (1) {

    printf("TEST translator x: %i\n", x);

                                            if (x >= (**px + **sx)) {

                                                break;
                                            }

                                            // Reset already existing destination tui column (character).
                                            dxp = &NULL_POINTER;
                                            // Reset destination tui column (character).
                                            dx = NULL_POINTER;

                                            // Reset already existing destination tui character background property.
                                            bgp = &NULL_POINTER;
                                            // Reset already existing destination tui character foreground property.
                                            fgp = &NULL_POINTER;
                                            // Reset already existing destination tui character hidden property.
                                            hp = &NULL_POINTER;
                                            // Reset already existing destination tui character inverse property.
                                            ip = &NULL_POINTER;
                                            // Reset already existing destination tui character blink property.
                                            blp = &NULL_POINTER;
                                            // Reset already existing destination tui character underline property.
                                            up = &NULL_POINTER;
                                            // Reset already existing destination tui character bold property.
                                            bp = &NULL_POINTER;
                                            // Reset already existing destination tui character.
                                            cp = &NULL_POINTER;

                                            // Reset destination tui character background property.
                                            bg = NULL_POINTER;
                                            // Reset destination tui character foreground property.
                                            fg = NULL_POINTER;
                                            // Reset destination tui character hidden property.
                                            h = NULL_POINTER;
                                            // Reset destination tui character inverse property.
                                            i = NULL_POINTER;
                                            // Reset destination tui character blink property.
                                            bl = NULL_POINTER;
                                            // Reset destination tui character underline property.
                                            u = NULL_POINTER;
                                            // Reset destination tui character bold property.
                                            b = NULL_POINTER;
                                            // Reset destination tui character.
                                            c = NULL_POINTER;

                                            // Check if tui x dimension already exists.
                                            get(dy, (void*) &x, (void*) &dxp, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                            if (*dxp != NULL_POINTER) {

                                                // Use already existing tui x dimension.
                                                dx = *dxp;

                                            } else {

                                                // Allocate tui x dimension.
                                                allocate((void*) &dx, (void*) TUI_PROPERTIES_COUNT, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                                // Add new x dimension to y dimension.
                                                set(dy, (void*) &x, &dx, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                                // CAUTION! Do NOT increase x dimension count here!
                                                // It is already set at reallocation above.
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

                                            if (*bgp != NULL_POINTER) {

                                                // Use already existing tui character background property.
                                                bg = *bgp;

                                            } else {

                                                // Allocate tui character background property.
                                                allocate((void*) &bg, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character background property.
                                                set(dx, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, &bg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*fgp != NULL_POINTER) {

                                                // Use already existing tui character foreground property.
                                                fg = *fgp;

                                            } else {

                                                // Allocate tui character foreground property.
                                                allocate((void*) &fg, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character foreground property.
                                                set(dx, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, &fg, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*hp != NULL_POINTER) {

                                                // Use already existing tui character hidden property.
                                                h = *hp;

                                            } else {

                                                // Allocate tui character hidden property.
                                                allocate((void*) &h, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character hidden property.
                                                set(dx, (void*) TUI_PROPERTIES_HIDDEN_INDEX, &h, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*ip != NULL_POINTER) {

                                                // Use already existing tui character inverse property.
                                                i = *ip;

                                            } else {

                                                // Allocate tui character inverse property.
                                                allocate((void*) &i, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character inverse property.
                                                set(dx, (void*) TUI_PROPERTIES_INVERSE_INDEX, &i, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*blp != NULL_POINTER) {

                                                // Use already existing tui character blink property.
                                                bl = *blp;

                                            } else {

                                                // Allocate tui character blink property.
                                                allocate((void*) &bl, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character blink property.
                                                set(dx, (void*) TUI_PROPERTIES_BLINK_INDEX, &bl, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*up != NULL_POINTER) {

                                                // Use already existing tui character underline property.
                                                u = *up;

                                            } else {

                                                // Allocate tui character underline property.
                                                allocate((void*) &u, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character underline property.
                                                set(dx, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, &u, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*bp != NULL_POINTER) {

                                                // Use already existing tui character bold property.
                                                b = *bp;

                                            } else {

                                                // Allocate tui character bold property.
                                                allocate((void*) &b, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character bold property.
                                                set(dx, (void*) TUI_PROPERTIES_BOLD_INDEX, &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            if (*cp != NULL_POINTER) {

                                                // Use already existing tui character.
                                                c = *cp;

                                            } else {

                                                // Allocate tui character.
                                                allocate((void*) &c, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                                                // Add tui character.
                                                set(dx, (void*) TUI_PROPERTIES_CHARACTER_INDEX, &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                            }

                                            // Set character properties.
                                            mapto((void*) &bg, (void*) PRIMITIVE_COUNT, (void*) PRIMITIVE_COUNT, (void*) *bgm, (void*) *bgmc, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT);
                                            mapto((void*) &fg, (void*) PRIMITIVE_COUNT, (void*) PRIMITIVE_COUNT, (void*) *fgm, (void*) *fgmc, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT);
                                            //?? TODO: Replace temporary test values like
                                            //?? NUMBER_0_INTEGER with real properties!
                                            set(h, (void*) PRIMITIVE_VALUE_INDEX, (void*) *hm, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                            set(i, (void*) PRIMITIVE_VALUE_INDEX, (void*) *im, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                            set(bl, (void*) PRIMITIVE_VALUE_INDEX, (void*) *blm, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                            set(u, (void*) PRIMITIVE_VALUE_INDEX, (void*) *um, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                            set(b, (void*) PRIMITIVE_VALUE_INDEX, (void*) *bm, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                                            // Reset comparison result.
                                            r = 0;

                                            compare_arrays(*a, *ac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                            // CAUTION! The whole row may be much longer than the given string.
                                            // Therefore, only take characters if the index x is smaller than
                                            // the source string model count.
                                            if ((r != 0) && (mi < **mc)) {

                                                // Get character value at position x.
                                                get(*m, (void*) &mi, (void*) &v, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                                                // Increase model index by one.
                                                mi++;

                                            } else {

                                                // Set character property to space character,
                                                // because the part model is NOT a character,
                                                // or the string length is smaller than
                                                // the length of the row.
                                                v = SPACE_CHARACTER;
                                            }

                                            // Set character.
                                            // CAUTION! The character has to be set,
                                            // because get returns another character pointer
                                            // than the one that was added to dx above.
                                            set(c, (void*) PRIMITIVE_VALUE_INDEX, (void*) v, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

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
