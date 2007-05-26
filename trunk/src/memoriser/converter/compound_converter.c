/*
 * $RCSfile: compound_converter.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_CONVERTER_SOURCE
#define COMPOUND_CONVERTER_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Parses the source content and creates a compound from it.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count (Hand over as reference!)
 * @param p2 the destination compound size (Hand over as reference!)
 * @param p3 the source content
 * @param p4 the source content count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source name
 * @param p8 the source name count
 */
void parse_compound(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Information: Parse compound.");

/*??
    // Parse name.
    parse_character_vector((void*) &n, (void*) nc, (void*) ns, p7, p8);
    // Parse abstraction.
    parse_character_vector((void*) &a, (void*) ac, (void*) as, p5, p6);
    // Parse model.
    parse((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds, p3, p4, p5, p6);

    // The new destination character vector size.
    // (Not exactly the size, but the destination character vector index
    // increased by the source array count.)
    *ds = *dc + *sc;

    // Reallocate destination character vector.
    reallocate_array(p0, p1, p2, ...

    if (*dc <= (*ds - *sc)) {

        // Add field to knowledge memory.
        set_compound_element_by_name(*d, p1, p2, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
            n, (void*) nc, (void*) ns,
            a, (void*) ac, (void*) as,
            m, (void*) mc, (void*) ms,
            d, (void*) dc, (void*) ds);

        // Increment count.
        *dc = *dc + *sc;

    } else {

        log_message_debug("Could not parse compound. The destination count exceeds the size.");
    }
*/
}

/**
 * Serialises the compound into the single elements: name, abstraction, model.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void serialise_compound(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Serialise compound.");
}

/* COMPOUND_CONVERTER_SOURCE */
#endif
