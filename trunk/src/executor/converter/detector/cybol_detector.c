/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: cybol_detector.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_DETECTOR_SOURCE
#define CYBOL_DETECTOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

/**
 * Detects the root node.
 *
 * @param p0 the root node flag
 * @param p1 the name (Hand over as reference!)
 * @param p2 the name count
 * @param p3 the channel (Hand over as reference!)
 * @param p4 the channel count
 * @param p5 the abstraction (Hand over as reference!)
 * @param p6 the abstraction count
 * @param p7 the model (Hand over as reference!)
 * @param p8 the model count
 */
void detect_cybol_root_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect cybol root node.");

        if ((p1 == *NULL_POINTER_MEMORY_MODEL) && (p2 == *NULL_POINTER_MEMORY_MODEL)
            && (p3 == *NULL_POINTER_MEMORY_MODEL) && (p4 == *NULL_POINTER_MEMORY_MODEL)
            && (p5 == *NULL_POINTER_MEMORY_MODEL) && (p6 == *NULL_POINTER_MEMORY_MODEL)
            && (p7 == *NULL_POINTER_MEMORY_MODEL) && (p8 == *NULL_POINTER_MEMORY_MODEL)) {

            *r = *NUMBER_1_INTEGER_MEMORY_MODEL;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol node model. The source details count is null.");
    }
}

/* CYBOL_DETECTOR_SOURCE */
#endif
