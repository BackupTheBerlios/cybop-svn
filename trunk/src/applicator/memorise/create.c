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
 * @version $RCSfile: creating_memoriser.c,v $ $Revision: 1.13 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/cybol/compound_element_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/create_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/communicator/receiver.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../executor/converter/decoder.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"

/**
 * Creates an empty part consisting of name and abstraction only.
 *
 * The model and details may get filled with data using a "decode" operation,
 * which is called when a "receive" logic operation is found in cybol.
 *
 * The new knowledge model gets added to either of:
 * - whole model's part hierarchy
 * - whole model's meta hierarchy
 * - knowledge memory's root directly, if no whole element is given
 *
 * Expected parametres:
 * - name (required): the name of the part to be created
 * - abstraction (required): the abstraction (type) of the part to be created
 * - element (optional; if null, the new part will be added to the whole- or knowledge memory MODEL and NOT details):
 *   the kind of element (knowledge model) to be created (part, meta);
 *   a part element will be added to the whole model's part hierarchy;
 *   a meta element to the whole model's details hierarchy;
 *   this parametre is optional, but recommended for faster processing
 * - whole (optional; if null, the new part will be added to the knowledge memory root):
 *   the compound to which to add to the new part
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_create(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply create.");

    // The name part.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    // The abstraction part.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The element part.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    // The whole part.
    void* w = *NULL_POINTER_MEMORY_MODEL;

    // The name part model.
    void* nm = *NULL_POINTER_MEMORY_MODEL;
    // The abstraction part model.
    void* am = *NULL_POINTER_MEMORY_MODEL;
    // The element part model.
    void* em = *NULL_POINTER_MEMORY_MODEL;

    // The name part model data, count.
    void* nmd = *NULL_POINTER_MEMORY_MODEL;
    void* nmc = *NULL_POINTER_MEMORY_MODEL;
    // The abstraction part model data, count.
    void* amd = *NULL_POINTER_MEMORY_MODEL;
    // The element part model data, count.
    void* emd = *NULL_POINTER_MEMORY_MODEL;

    // Get name part.
    get_name_array((void*) &n, p0, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get abstraction part.
    get_name_array((void*) &a, p0, (void*) ABSTRACTION_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ABSTRACTION_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get element part.
    get_name_array((void*) &e, p0, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get whole part.
    get_name_array((void*) &w, p0, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get name part model.
    copy_array_forward((void*) &nm, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get abstraction part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get element part model.
    copy_array_forward((void*) &em, e, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get name part model data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get abstraction part model data, count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get element part model data, count.
    copy_array_forward((void*) &emd, em, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, amd);

    // Fill part.
    overwrite_part_element(p, nmd, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, nmc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p, amd, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, emd, (void*) PART_COMPOUND_ELEMENT_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            if (w != *NULL_POINTER_MEMORY_MODEL) {

                // A whole part exists.

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part to whole model.");

                // Append part (handed over as array reference) to whole model (being a part itself).
                // CAUTION! Do NOT use PART_PRIMITIVE_MEMORY_ABSTRACTION here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(w, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

            } else {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part to knowledge memory root.");

                // The whole part is null.
                //
                // CAUTION! The new part allocated above HAS TO BE added to the
                // knowledge memory tree, so that it can be deallocated properly at
                // system shutdown and is not lost somewhere in Random Access Memory (RAM).
                // Therefore, if the whole part is null, the knowledge memory is used instead.

                // Append part (handed over as array reference) to knowledge memory root model (being a part itself).
                // CAUTION! Do NOT use PART_PRIMITIVE_MEMORY_ABSTRACTION here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(p2, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            }
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer((void*) &r, emd, (void*) META_COMPOUND_ELEMENT_CYBOL_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            if (w != *NULL_POINTER_MEMORY_MODEL) {

                // A whole part exists.

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part to whole details.");

                // Append part (handed over as array reference) to whole details (being a part itself).
                // CAUTION! Do NOT use PART_PRIMITIVE_MEMORY_ABSTRACTION here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(w, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

            } else {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part to knowledge memory root details.");

                // The whole part is null.
                //
                // CAUTION! The new part allocated above HAS TO BE added to the
                // knowledge memory tree, so that it can be deallocated properly at
                // system shutdown and is not lost somewhere in Random Access Memory (RAM).
                // Therefore, if the whole part is null, the knowledge memory is used instead.

                // Append part (handed over as array reference) to knowledge memory root details (being a part itself).
                // CAUTION! Do NOT use PART_PRIMITIVE_MEMORY_ABSTRACTION here!
                // The reason is that deep copying would be used to assign the part inside,
                // instead of just assigning the part reference in a shallow copying manner.
                append_part_element(p2, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
            }
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        // The kind of element is null, i.e. it was NOT given as parametre.
        // Therefore, add part to whole- or knowledge memory MODEL, by default.

        if (w != *NULL_POINTER_MEMORY_MODEL) {

            // A whole part exists.

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part to whole model.");

            // Append part (handed over as array reference) to whole model (being a part itself).
            // CAUTION! Do NOT use PART_PRIMITIVE_MEMORY_ABSTRACTION here!
            // The reason is that deep copying would be used to assign the part inside,
            // instead of just assigning the part reference in a shallow copying manner.
            append_part_element(w, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

        } else {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add part to knowledge memory root.");

            // The whole part is null.
            //
            // CAUTION! The new part allocated above HAS TO BE added to the
            // knowledge memory tree, so that it can be deallocated properly at
            // system shutdown and is not lost somewhere in Random Access Memory (RAM).
            // Therefore, if the whole part is null, the knowledge memory is used instead.

            // Append part (handed over as array reference) to knowledge memory root model (being a part itself).
            // CAUTION! Do NOT use PART_PRIMITIVE_MEMORY_ABSTRACTION here!
            // The reason is that deep copying would be used to assign the part inside,
            // instead of just assigning the part reference in a shallow copying manner.
            append_part_element(p2, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
        }
    }
}

/* CREATE_SOURCE */
#endif
