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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_CALCULATOR_SOURCE
#define PART_CALCULATOR_SOURCE

#include "../../../constant/abstraction/operation/operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/integer/add_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/divide_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/multiply_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/subtract_integer_calculator.c"
#include "../../../logger/logger.c"

/**
 * Calculates left- with right part.
 *
 * Calculates only the parts' models.
 * Does NOT consider both parts' name, abstraction, details.
 *
 * This is DEEP CALCULATION, i.e. all child nodes will be calculated as well.
 *
 * @param p0 the result (left unchanged in case of an error)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 */
void calculate_part(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate part.");

    //
    // Recursively call a calculation function, which in turn
    // may call this calculation function and so forth.
    // This is necessary when processing knowledge tree hierarchies.
    //

    calculate_all_part_model(p0, p1, p2, p3);
}

/* PART_CALCULATOR_SOURCE */
#endif
