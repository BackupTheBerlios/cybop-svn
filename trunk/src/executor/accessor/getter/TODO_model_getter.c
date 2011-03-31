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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_GETTER_SOURCE
#define MODEL_GETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder/integer_integer_adder.c"
#include "../../../executor/arithmetiser/integer_adder/pointer_integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/comparator/equality/array_equality_comparator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Gets the destination array from the source model at index.
 *
 * @param p0 the destination pointer array (Hand over as array reference!)
 * @param p1 the destination count array (Hand over as array reference!)
 * @param p2 the destination size array (Hand over as array reference!)
 * @param p3 the source model
 * @param p4 the array abstraction
 */
void get_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

    get_array(p0, p3, (void*) POINTER_MODEL_MEMORY_NAME, p5);
    get_array(p1, p3, (void*) COUNT_MODEL_MEMORY_NAME, p5);
    get_array(p2, p3, (void*) SIZE_MODEL_MEMORY_NAME, p5);
}

/* MODEL_GETTER_SOURCE */
#endif
