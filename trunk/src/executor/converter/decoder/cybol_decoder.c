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
 * @version $RCSfile: cybol_converter.c,v $ $Revision: 1.18 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_DECODER_SOURCE
#define CYBOL_DECODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybop/cybop_name.c"
#include "../../../executor/accessor/appender/compound_appender.c"
#include "../../../executor/accessor/getter/compound_getter.c"
#include "../../../executor/converter/detector/cybol_detector.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void communicate_receiving_with_parameters(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23);

void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Decodes the cybol node.
 *
 * The source details handed over contain one node each for
 * name, channel, abstraction, model.
 *
 * Example:
 *
 *  | compound [The root node has no name.]
 * +-node_$0 | compound
 * | +-node_$0 | compound
 * | | +-node_$0 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | left
 * | | | #-channel | wide_character | inline
 * | | | #-abstraction | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.count
 * | | +-node_$1 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | right
 * | | | #-channel | wide_character | inline
 * | | | #-abstraction | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.maximum
 * | | +-node_$2 | compound
 * | | | #- | wide_character | property [This is the xml tag name.]
 * | | | #-name | wide_character | result
 * | | | #-channel | wide_character | inline
 * | | | #-abstraction | wide_character | path/knowledge
 * | | | #-model | wide_character | .counter.break
 * | | #- | wide_character | part [This is the xml tag name.]
 * | | #-name | wide_character | compare_count
 * | | #-channel | wide_character | inline
 * | | #-abstraction | wide_character | operation/plain
 * | | #-model | wide_character | greater_or_equal
 * | +-node_$1 | compound
 * ...
 *
 * @param p0 the destination whole data (Hand over as reference!)
 * @param p1 the destination whole count
 * @param p2 the destination whole size
 * @param p3 the source part model data
 * @param p4 the source part model count
 * @param p5 the source part details data
 * @param p6 the source part details count
 */
void decode_cybol(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode cybol.");

    // The source name, channel, abstraction, model part.
    void* sn = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* sa = *NULL_POINTER_MEMORY_MODEL;
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    // The source name, channel, abstraction, model part model.
    void* snm = *NULL_POINTER_MEMORY_MODEL;
    void* scm = *NULL_POINTER_MEMORY_MODEL;
    void* sam = *NULL_POINTER_MEMORY_MODEL;
    void* smm = *NULL_POINTER_MEMORY_MODEL;
    // The source name, channel, abstraction, model part model data, count.
    void* snmd = *NULL_POINTER_MEMORY_MODEL;
    void* snmc = *NULL_POINTER_MEMORY_MODEL;
    void* scmd = *NULL_POINTER_MEMORY_MODEL;
    void* scmc = *NULL_POINTER_MEMORY_MODEL;
    void* samd = *NULL_POINTER_MEMORY_MODEL;
    void* samc = *NULL_POINTER_MEMORY_MODEL;
    void* smmd = *NULL_POINTER_MEMORY_MODEL;
    void* smmc = *NULL_POINTER_MEMORY_MODEL;

    // Get source name, channel, abstraction, model part.
    get_name_array((void*) &sn, p5, (void*) NAME_CYBOP_NAME, (void*) NAME_CYBOP_NAME_COUNT, p6);
    get_name_array((void*) &sc, p5, (void*) CHANNEL_CYBOP_NAME, (void*) CHANNEL_CYBOP_NAME_COUNT, p6);
    get_name_array((void*) &sa, p5, (void*) ABSTRACTION_CYBOP_NAME, (void*) ABSTRACTION_CYBOP_NAME_COUNT, p6);
    get_name_array((void*) &sm, p5, (void*) MODEL_CYBOP_NAME, (void*) MODEL_CYBOP_NAME_COUNT, p6);
    // Get source name, channel, abstraction, model part model.
    // CAUTION! Do NOT use NAME_PART_MEMORY_NAME, CHANNEL_PART_MEMORY_NAME,
    // ABSTRACTION_PART_MEMORY_NAME, MODEL_PART_MEMORY_NAME here!
    // The corresponding parts were already retrieved above.
    // What is wanted here, is just their models containing the actual data.
    copy_array_forward((void*) &snm, sn, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &scm, sc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &sam, sa, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &smm, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get source name, channel, abstraction, model part model data, count.
    copy_array_forward((void*) &snmd, snm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &snmc, snm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &scmd, scm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &scmc, scm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &samd, sam, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &samc, sam, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smmd, smm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &smmc, smm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The root node flag.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    // This is a root node if its details (name, channel, abstraction, model) are null.
    // CAUTION! The details container itself DOES ALWAYS EXIST,
    // so that it cannot be used for comparison here!
    if ((sn == *NULL_POINTER_MEMORY_MODEL) && (sc == *NULL_POINTER_MEMORY_MODEL)
        && (sa == *NULL_POINTER_MEMORY_MODEL) && (sm == *NULL_POINTER_MEMORY_MODEL)) {

        // Set root node flag.
        copy_integer((void*) &r, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
    }

    // The source cyboi runtime abstraction.
    // CAUTION! It is needed to retrieve the abstraction of the part to be created.
    // Otherwise, it would not be known which part model to create.
    // The source abstraction cannot be converted directly into the part's abstraction,
    // because the part model has not been allocated yet when reading the abstraction
    // for the first time.
    int sra = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Decode cybol source abstraction into cyboi runtime abstraction.
    // (1) A cybol abstraction is of type "wchar_t"; a cyboi abstraction of type "int".
    // (2) Both are not always equal in their meaning.
    // For example, an "xdt" file is converted into a "part".
    // Therefore, the abstraction has to be converted here.
    decode_abstraction((void*) &sra, samd, samc);

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part model, details.
    void* pm = *NULL_POINTER_MEMORY_MODEL;
    void* pd = *NULL_POINTER_MEMORY_MODEL;
    // The part model, details data, count, size.
    void* pmd = *NULL_POINTER_MEMORY_MODEL;
    void* pmc = *NULL_POINTER_MEMORY_MODEL;
    void* pms = *NULL_POINTER_MEMORY_MODEL;
    void* pdd = *NULL_POINTER_MEMORY_MODEL;
    void* pdc = *NULL_POINTER_MEMORY_MODEL;
    void* pds = *NULL_POINTER_MEMORY_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &sra);
    // Get part model, details.
    copy_array_forward((void*) &pm, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get part model, details data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &pms, pm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIZE_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &pdd, pd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &pdc, pd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &pds, pd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIZE_ITEM_MEMORY_NAME);

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        // This is NOT the root node.
        // Therefore, the node's details are processed.

        // Fill part.
        overwrite_part_element(p, snmd, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, snmc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
        // CAUTION! Use the cyboi RUNTIME abstraction as source here!
        overwrite_part_element(p, (void*) &sra, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
        // Receive and decode source model, details into part model, details.
        receive_file_system((void*) &pmd, pmc, pms, (void*) &pdd, pdc, pds, smmd, smmc, scmd, scmc);
    }

    // The source meta part.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The source meta part model, details.
    void* mm = *NULL_POINTER_MEMORY_MODEL;
    void* md = *NULL_POINTER_MEMORY_MODEL;
    // The source meta part model, details data, count.
    void* mmd = *NULL_POINTER_MEMORY_MODEL;
    void* mmc = *NULL_POINTER_MEMORY_MODEL;
    void* mdd = *NULL_POINTER_MEMORY_MODEL;
    void* mdc = *NULL_POINTER_MEMORY_MODEL;

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p4);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        // Get source meta part with index j from source part model.
        get_part_element((void*) &m, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j, (void*) MODEL_PART_MEMORY_NAME);
        // Get source meta part model, details.
        copy_array_forward((void*) &mm, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
        copy_array_forward((void*) &md, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
        // Get source meta part model, details data, count.
        copy_array_forward((void*) &mmd, mm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
        copy_array_forward((void*) &mmc, mm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
        copy_array_forward((void*) &mdd, md, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
        copy_array_forward((void*) &mdc, md, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

        if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

            // This is a standard part node and NOT the root node.

            // Decode the node's meta information (details),
            // by recursively calling this function itself.
            decode_cybol((void*) &pdd, pdc, pds, mmd, mmc, mdd, mdc);

        } else {

            // This IS the root node.
            // Add the meta node model and details directly to the
            // destination whole (root).

            // Decode the node's meta information (details),
            // by recursively calling this function itself.
            decode_cybol(p0, p1, p2, mmd, mmc, mdd, mdc);
        }

        // Increment loop variable.
        j++;
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        // This is NOT the root node.

        // Add part to whole (compound) model.
        overwrite_array(p0, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
    }
}

/* CYBOL_DECODER_SOURCE */
#endif
