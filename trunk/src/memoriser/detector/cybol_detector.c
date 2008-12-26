/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: cybol_detector.c,v $ $Revision: 1.2 $ $Date: 2008-12-26 16:19:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_DETECTOR_SOURCE
#define CYBOL_DETECTOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../logger/logger.c"

/**
 * Detects the node details.
 *
 * @param p0 the element (Hand over as reference!)
 * @param p1 the element count
 * @param p2 the source details
 * @param p3 the source details count
 * @param p4 the source name
 * @param p5 the source name count
 */
/*??
void detect_cybol_node_detail(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect cybol node detail.");

    // The element name, abstraction, model, details.
    void** n = NULL_POINTER_MEMORY_MODEL;
    void** nc = NULL_POINTER_MEMORY_MODEL;
    void** ns = NULL_POINTER_MEMORY_MODEL;
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;

    // Get compound element by name.
    get_compound_element_by_name(p2, p3, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p4, p5,
        (void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as, (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds);
}
*/

/**
 * Detects the node details.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count
 * @param p8 the source details
 * @param p9 the source details count
 */
/*??
void detect_cybol_node_details(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detect cybol node details.");

/*??
    detect_cybol_node_detail(p0, p1, p8, p9, NAME, NAME_COUNT);
    detect_cybol_node_detail(p2, p3, p8, p9, CHANNEL, CHANNEL_COUNT);
    detect_cybol_node_detail(p4, p5, p8, p9, ABSTRACTION, ABSTRACTION_COUNT);
    detect_cybol_node_detail(p6, p7, p8, p9, MODEL, MODEL_COUNT);
*/

/*??
    // Get name.
    get_compound_element_by_name(p8, p9, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, NAME, NAME_COUNT,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p0, p1, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
    // Get channel.
    get_compound_element_by_name(p8, p9, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHANNEL, CHANNEL_COUNT,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p2, p3, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
    // Get abstraction.
    get_compound_element_by_name(p8, p9, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, ABSTRACTION, ABSTRACTION_COUNT,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p4, p5, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
    // Get model.
    get_compound_element_by_name(p8, p9, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, MODEL, MODEL_COUNT,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p6, p7, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
}

/* CYBOL_DETECTOR_SOURCE */
#endif
