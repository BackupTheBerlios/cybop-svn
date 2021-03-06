/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: abstraction_getting_memoriser.c,v $ $Revision: 1.7 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ABSTRACTION_GETTING_MEMORISER_SOURCE
#define ABSTRACTION_GETTING_MEMORISER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/communicator/receiver.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/decoder.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"

/**
 * Gets the abstraction as description (meta information) of the part at the given index.
 *
 * @param p0 the result
 * @param p1 the result count
 * @param p2 the result size
 * @param p3 the compound
 * @param p4 the compound count
 * @param p5 the index
 * @param p6 the index count
 */
void memorise_getting_abstraction(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The temporary result.
    void** r = NULL_POINTER_MEMORY_MODEL;
    void** rc = NULL_POINTER_MEMORY_MODEL;
    void** rs = NULL_POINTER_MEMORY_MODEL;

    // Get temporary result.
    get_compound_element_abstraction_by_index(p3, p4, p5, (void*) &r, (void*) &rc, (void*) &rs);

    // Copy temporary result to actual result variable.
    memorise_copying_character_vector(p0, p1, p2, *r, *rc);
}

/* ABSTRACTION_GETTING_MEMORISER_SOURCE */
#endif
