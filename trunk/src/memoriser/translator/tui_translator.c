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
 * @version $Revision: 1.3 $ $Date: 2005-07-29 15:48:51 $ $Author: christian $
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
#include "../../memoriser/accessor.c"

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

        if (p2 != NULL_POINTER) {

            int* des = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* dec = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** de = (void**) p0;

                    log_message_debug("Encode textual user interface.");

                    // The part abstraction, model, details.
                    void** a = NULL_POINTER;
                    void** ac = NULL_POINTER;
                    void** as = NULL_POINTER;
                    void** m = NULL_POINTER;
                    void** mc = NULL_POINTER;
                    void** ms = NULL_POINTER;
                    void** d = NULL_POINTER;
                    void** dc = NULL_POINTER;
                    void** ds = NULL_POINTER;

                    // The part position.
                    void** pa = NULL_POINTER;
                    void** pac = NULL_POINTER;
                    void** pas = NULL_POINTER;
                    void** pm = NULL_POINTER;
                    void** pmc = NULL_POINTER;
                    void** pms = NULL_POINTER;
                    void** pd = NULL_POINTER;
                    void** pdc = NULL_POINTER;
                    void** pds = NULL_POINTER;
                    // The part size.
                    void** sa = NULL_POINTER;
                    void** sac = NULL_POINTER;
                    void** sas = NULL_POINTER;
                    void** sm = NULL_POINTER;
                    void** smc = NULL_POINTER;
                    void** sms = NULL_POINTER;
                    void** sd = NULL_POINTER;
                    void** sdc = NULL_POINTER;
                    void** sds = NULL_POINTER;
                    // The part colour.
                    void** ca = NULL_POINTER;
                    void** cac = NULL_POINTER;
                    void** cas = NULL_POINTER;
                    void** cm = NULL_POINTER;
                    void** cmc = NULL_POINTER;
                    void** cms = NULL_POINTER;
                    void** cd = NULL_POINTER;
                    void** cdc = NULL_POINTER;
                    void** cds = NULL_POINTER;

                    // The part character.
                    char* c = NULL_POINTER;
                    // The part position x, y, z.
                    int* px = NULL_POINTER;
                    int* py = NULL_POINTER;
                    int* pz = NULL_POINTER;
                    // The part size x, y, z.
                    int* sx = NULL_POINTER;
                    int* sy = NULL_POINTER;
                    int* sz = NULL_POINTER;

                    // The destination tui z layer.
                    void* dz = NULL_POINTER;
                    int* dzc = NULL_POINTER;
                    int* dzs = NULL_POINTER;
                    // The destination tui y row.
                    void* dy = NULL_POINTER;
                    int* dyc = NULL_POINTER;
                    int* dys = NULL_POINTER;
                    // The destination tui x column (character).
                    void* dx = NULL_POINTER;
                    int* dxc = NULL_POINTER;
                    int* dxs = NULL_POINTER;

                    // The loop count.
                    int j = 0;
                    // The x, y, z loop counts.
                    int x = 0;
                    int y = 0;
                    int z = 0;
                    // The comparison result.
                    int r = 0;

                    // Iterate through compound parts.
                    while (1) {

                        if (j >= *sc) {

                            break;
                        }

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
                        // Get part colour from details.
                        get_compound_element_by_name(*d, *dc,
                            (void*) TUI_COLOUR_NAME, (void*) TUI_COLOUR_NAME_COUNT,
                            (void*) &ca, (void*) &cac, (void*) &cas,
                            (void*) &cm, (void*) &cmc, (void*) &cms,
                            (void*) &cd, (void*) &cdc, (void*) &cds);

                        // Get part position x, y, z.
                        get(*pm, (void*) TUI_POSITION_X_INDEX, (void*) &px, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        get(*pm, (void*) TUI_POSITION_Y_INDEX, (void*) &py, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        get(*pm, (void*) TUI_POSITION_Z_INDEX, (void*) &pz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        // Get part size x, y, z.
                        get(*sm, (void*) TUI_SIZE_X_INDEX, (void*) &sx, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        get(*sm, (void*) TUI_SIZE_Y_INDEX, (void*) &sy, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        get(*sm, (void*) TUI_SIZE_Z_INDEX, (void*) &sz, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                        // Set tui count and size to given z dimension size minus position.
                        *dec = *sz - *pz;
                        *des = *sz - *pz;

                        // Reset z loop index to first position.
                        z = *pz;

                        // Position characters in their colour and with their size.
                        while (1) {

                            if (z >= *sz) {

                                break;
                            }

                            //?? In a later version, check first if tui z dimension
                            //?? already exists, to speed up its handling!
                            //?? get(*de, (void*) &z, (void*) &dz, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                            // Allocate tui z dimension count and size.
                            allocate((void*) &dzc, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                            allocate((void*) &dzs, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                            // Set z dimension count and size to given y dimension size minus position.
                            *dzc = *sy - *py;
                            *dzs = *sy - *py;

//??                            if (dz == NULL_POINTER) {

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
                            y = *py;

                            while (1) {

                                if (y >= *sy) {

                                    break;
                                }

                                //?? In a later version, check first if tui y dimension
                                //?? already exists, to speed up its handling!
                                //?? get(dz, (void*) &y, (void*) &dy, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                // Allocate tui y dimension count and size.
                                allocate((void*) &dyc, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);
                                allocate((void*) &dys, (void*) INTEGER_COUNT, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT);

                                // Set y dimension count and size to given x dimension size minus position.
                                *dyc = *sx - *px;
                                *dys = *sx - *px;

//??                                if (dy == NULL_POINTER) {

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
                                x = *px;

                                while (1) {

                                    if (x >= *sx) {

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

//??                                    if (dx == NULL_POINTER) {

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

                                    // Add character properties to x dimension.
                                    //?? TODO: Replace all constants
                                    //?? (NUMBER_0_INTEGER, COBALT_BACKGROUND_CONTROL_SEQUENCE etc.)
                                    //?? with appropriate value from source model!
                                    set(dx, (void*) TUI_PROPERTIES_BOLD_INDEX, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    set(dx, (void*) TUI_PROPERTIES_UNDERLINE_INDEX, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    set(dx, (void*) TUI_PROPERTIES_BLINK_INDEX, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    set(dx, (void*) TUI_PROPERTIES_INVERSE_INDEX, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    set(dx, (void*) TUI_PROPERTIES_HIDDEN_INDEX, (void*) NUMBER_0_INTEGER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    set(dx, (void*) TUI_PROPERTIES_FOREGROUND_INDEX, (void*) YELLOW_FOREGROUND_CONTROL_SEQUENCE, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    set(dx, (void*) TUI_PROPERTIES_BACKGROUND_INDEX, (void*) COBALT_BACKGROUND_CONTROL_SEQUENCE, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                    // Reset comparison result.
                                    r = 0;

                                    compare_arrays(*a, *ac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                    if (r != 0) {

                                        // The part model is a character.

                                        allocate((void*) &c, (void*) CHARACTER_COUNT, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

                                        // Get part string with just one character at position x.
                                        get(*m, (void*) &x, (void*) c, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT);

                                        // Add character to x dimension.
                                        set(dx, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                                    } else {

                                        // The part model is NOT a character.

                                        // Add space character to x dimension.
                                        set(dx, (void*) TUI_PROPERTIES_CHARACTER_INDEX, (void*) SPACE_CHARACTER, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                                    }

                                    x++;
                                }

                                y++;
                            }

                            z++;
                        }

                        // Reset comparison result.
                        r = 0;

                        compare_arrays(*a, *ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                        if (r != 0) {

                            // The part model is a compound.

                            // Recursively call this procedure for compound part model.
                            encode_tui(p0, p1, p2, *m, *mc);
                        }

                        j++;
                    }

                } else {

                    log_message_debug("Could not encode textual user interface. The destination parameter is null.");
                }

            } else {

                log_message_debug("Could not encode textual user interface. The destination count parameter is null.");
            }

        } else {

            log_message_debug("Could not encode textual user interface. The destination size parameter is null.");
        }

    } else {

        log_message_debug("Could not encode textual user interface. The source count parameter is null.");
    }
}

/* TUI_TRANSLATOR_SOURCE */
#endif
