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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_COPIER_SOURCE
#define PART_COPIER_SOURCE

#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/separator_cybol_name.c"
#include "../../constant/name/memory/model_memory_name.c"
#include "../../executor/comparator/count_array_comparator.c"
#include "../../executor/memoriser/reallocator/compound_reallocator.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/**
 * Copies the array to the part container element.
 *
 * @param p0 the part container
 * @param p1 the array
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the part container index
 * @param p5 the array index
 * @param p6 the part container element index
 */
void copy_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part element.");

    // The part container element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get part container element.
    copy_array_offset((void*) &e, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Set item to part container element.
    // The count is adjusted automatically.
    copy_item_element(e, p1, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Copies count source part elements into the destination part at position index.
 *
 * CAUTION! The destination already HAS TO EXIST and has to have a NAME.
 * The source name is NOT copied into the destination name.
 *
 * CAUTION! The source abstraction has to be IDENTICAL to the
 * destination abstraction. The equality of both is NOT tested here.
 * The given "operand abstraction" is used for destination and source.
 * The source abstraction is NOT copied into the destination abstraction.
 *
 * CAUTION! The size of the destination has to be adjusted BEFORE calling
 * this function. The validity of the given index is NOT tested here.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void copy_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Copy part.");

    //?? TODO: Copy name and abstraction as well, at least for all child nodes,
    //?? if these are allocated new while copying the source parts.

    // The destination model, details.
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    // The source model, details.
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    void* sd = *NULL_POINTER_MEMORY_MODEL;

    // Get destination model, details.
    copy_array_offset((void*) &dm, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_offset((void*) &dd, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get source model, details.
    copy_array_offset((void*) &sm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_offset((void*) &sd, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // Set source- to destination model, details.
    // CAUTION! The name and abstraction are NOT copied.
    copy_item(dm, sm, p2, p3, p4, p5);
    //?? TODO: Replace p3 with count?
    copy_item(dd, sd, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION, p3, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* PART_COPIER_SOURCE */
#endif
