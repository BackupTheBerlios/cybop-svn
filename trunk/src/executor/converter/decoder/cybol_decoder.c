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

void decode_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Decodes the cybol model elements.
 *
 * It represents the new part's details (meta) hierarchy.
 *
 * CAUTION! What is the details in a parsed xml/cybol file
 * becomes the model in the cyboi-internal knowledge tree;
 * what is the model hierarchy in a parsed xml/cybol file
 * becomes the details (meta data) in the cyboi-internal knowledge tree.
 *
 * @param p0 the destination item (Hand over as item, since size may change!)
 * @param p1 the source data
 * @param p2 the source index
 * @param p3 the source part model tree root node flag
 */
void decode_cybol_model_elements(void* p0, void* p1, void* p2, void* p3) {

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

    // Get source meta part with given index from source part model.
    get_part_element((void*) &m, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p2, (void*) MODEL_PART_MEMORY_NAME);
    // Get source meta part model, details.
    copy_array_forward((void*) &mm, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get source meta part model, details data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mdd, md, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mdc, md, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    decode_cybol_elementp0, mmd, mmc, mdd, mdc, p3);
}

/**
 * Decodes the cybol model.
 *
 * It represents the new part's details (meta) hierarchy.
 *
 * CAUTION! What is the details in a parsed xml/cybol file
 * becomes the model in the cyboi-internal knowledge tree;
 * what is the model hierarchy in a parsed xml/cybol file
 * becomes the details (meta data) in the cyboi-internal knowledge tree.
 *
 * @param p0 the destination item (Hand over as item, since size may change!)
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the source part model tree root node flag
 */
void decode_cybol_model(void* p0, void* p1, void* p2, void* p3) {

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        decode_cybol_model_elements(p0, p1, (void*) &j, p3);

        // Increment loop variable.
        j++;
    }
}

/**
 * Decodes the cybol standard node.
 *
 * @param p0 the destination item (Hand over as item, since size may change!)
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the source part details data
 * @param p4 the source part details count
 * @param p5 the source part model tree root node flag
 */
void decode_cybol_node_standard(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode cybol node standard.");

    //
    // Identify source part details parametres.
    //

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
    get_name_array((void*) &sn, p3, (void*) NAME_CYBOP_NAME, (void*) NAME_CYBOP_NAME_COUNT, p4);
    get_name_array((void*) &sc, p3, (void*) CHANNEL_CYBOP_NAME, (void*) CHANNEL_CYBOP_NAME_COUNT, p4);
    get_name_array((void*) &sa, p3, (void*) ABSTRACTION_CYBOP_NAME, (void*) ABSTRACTION_CYBOP_NAME_COUNT, p4);
    get_name_array((void*) &sm, p3, (void*) MODEL_CYBOP_NAME, (void*) MODEL_CYBOP_NAME_COUNT, p4);
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

    // The runtime channel.
    int rc = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The runtime abstraction.
    // CAUTION! It is needed to retrieve the abstraction of the part to be created.
    // Otherwise, it would not be known which part model to create.
    // The source abstraction cannot be converted directly into the part's abstraction,
    // because the part model has not been allocated yet when reading the abstraction
    // for the first time.
    int ra = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The runtime model.
    // CAUTION! Certain operations expect well-defined parametres,
    // which are defined as constant inside cyboi.
    int rm = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    //
    // Decode cybol source abstraction into cyboi runtime abstraction constant.
    //
    decode_channel((void*) &rc, scmd, scmc);
    //
    // Decode cybol source abstraction into cyboi runtime abstraction constant.
    //
    // (1) A cybol abstraction is of type "wchar_t";
    //     a cyboi-internal abstraction of type "int".
    // (2) Both are not always equal in their meaning.
    //     For example, an "xdt" file is converted into a "part".
    //     Therefore, the abstraction has to be converted here.
    //
    decode_abstraction((void*) &ra, samd, samc);

    //
    // Create new part.
    //
    // CAUTION! This may only be done AFTER having retrieved the source
    // abstraction, since that is needed for allocating the new part.
    //

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part name, abstraction, model, details.
    void* pn = *NULL_POINTER_MEMORY_MODEL;
    void* pa = *NULL_POINTER_MEMORY_MODEL;
    void* pm = *NULL_POINTER_MEMORY_MODEL;
    void* pd = *NULL_POINTER_MEMORY_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &ra);
    // Get part name, abstraction, model, details.
    copy_array_forward((void*) &pn, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &pa, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    //
    // Process source part details.
    //
    // CAUTION! What is the details in a parsed xml/cybol file,
    // becomes the model in the cyboi-internal knowledge tree.
    //

    // Fill part name.
    overwrite_item_element(pn, snmd, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, snmc, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
    // Fill part abstraction.
    // CAUTION! Use the cyboi RUNTIME abstraction constant as source here!
    overwrite_item_element(pa, (void*) &ra, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);

    //
    // Sometimes, a cybol model represents an abstraction, e.g. when creating a part.
    // This is indicated by an abstraction with value "text/abstraction".
    // In such cases, the cybol model's character string value has to be converted into
    // an integer value, since cyboi processes abstractions in this form internally.
    //
    // Example (see the "abstraction" property's "model" attribute):
    //
    // <part name="create_counter" channel="inline" abstraction="operation/plain" model="create">
    //     <property name="name" channel="inline" abstraction="text/plain" model="counter"/>
    //     <property name="abstraction" channel="inline" abstraction="text/abstraction" model="memory/compound"/>
    //     <property name="element" channel="inline" abstraction="text/plain" model="part"/>
    // </part>
    //

    // The cyboi model flag indicating whether or not
    // the given model is a cyboi-internal constant.
    int f = *FALSE_BOOLEAN_MEMORY_MODEL;

    compare_integer_equal((void*) &f, (void*) &ra, (void*) ABSTRACTION_PRIMITIVE_MEMORY_ABSTRACTION);

    if (f != *FALSE_BOOLEAN_MEMORY_MODEL) {

        // Decode cybol source model (representing an abstraction)
        // into cyboi runtime abstraction constant.
        decode_abstraction((void*) &rm, smmd, smmc);

        // Fill part model.
        // CAUTION! Use the cyboi RUNTIME model constant as source here!
        overwrite_item_element(pm, (void*) &rm, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);

    } else {

        // Fill part model and details.
        // Receive and decode source model, details into part model, details.
        receive_message(pm, pd, smmd, smmc, (void*) &ra, (void*) &rc);
    }

    //
    // Process source part model.
    //
    // CAUTION! What is the model hierarchy in a parsed xml/cybol file,
    // becomes the details (meta data) in the cyboi-internal knowledge tree.
    //

    // Fill part details.
    // Decode the new part's meta information,
    // by recursively calling this function itself.
    decode_cybol_model(pd, p1, p2, p5);

    //
    // Add part to destination.
    //

    append_item_element(p0, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/**
 * Decodes the cybol root node.
 *
 * @param p0 the destination item (Hand over as item, since size may change!)
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the source part model tree root node flag
 */
void decode_cybol_node_root(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode cybol node root.");

    // Reset root node flag, so that
    // child nodes are processed normally.
    copy_integer(p3, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    //
    // Process source part model.
    //

    // Decode the new part's meta information,
    // by recursively calling this function itself.
    decode_cybol_model(p0, p1, p2, p3);
}

/**
 * Decodes the cybol element.
 *
 * @param p0 the destination item (Hand over as item, since size may change!)
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the source part details data
 * @param p4 the source part details count
 * @param p5 the source part model tree root node flag
 */
void decode_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode cybol element.");

    // The root node flag.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    compare_integer_unequal((void*) &r, p5, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        // This is a standard part node and NOT the root node.

        decode_cybol_node_standard(p0, p1, p2, p3, p4);

    } else {

        // This IS the root node.

        // Add the meta node model and details directly
        // to destination whole (root).
        decode_cybol_node_root(p0, p1, p2, p5);
    }
}

/**
 * Decodes the cybol knowledge model.
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
 * | #- | wide_character | model [This is the xml tag name.]
 *
 * @param p0 the destination item (Hand over as item, since size may change!)
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the source part details data
 * @param p4 the source part details count
 */
void decode_cybol(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode cybol.");

    // The source part model tree root node flag.
    // CAUTION! It is necessary to identify the root node.
    int f = *TRUE_BOOLEAN_MEMORY_MODEL;

    decode_cybol_element(p0, p1, p2, p3, p4, (void*) &f);
}

/* CYBOL_DECODER_SOURCE */
#endif
