/*
 * $RCSfile: get_name.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2008-05-04 00:18:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GET_NAME_SOURCE
#define GET_NAME_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
#include "../../memoriser/communicator.c"
#include "../../memoriser/converter.c"

/**
 * Gets the name as description (meta information) of the part at the given index.
 *
 * @param p0 the result (Hand over as reference!)
 * @param p1 the result count
 * @param p2 the result size
 * @param p3 the compound
 * @param p4 the compound count
 * @param p5 the index
 * @param p6 the index count
 */
void get_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The temporary result.
    void** r = NULL_POINTER;
    void** rc = NULL_POINTER;
    void** rs = NULL_POINTER;

    // Get temporary result.
    get_compound_element_name_by_index(p3, p4, p5, (void*) &r, (void*) &rc, (void*) &rs);

    // Copy temporary result to actual result variable.
    copy_character_vector(p0, p1, p2, *r, *rc);
}

/* GET_NAME_SOURCE */
#endif
