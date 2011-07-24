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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef KNOWLEDGE_PART_GETTER_SOURCE
#define KNOWLEDGE_PART_GETTER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/http/cyboi_http_name.c"
#include "../../../executor/accessor/appender/part_appender.c"
#include "../../../executor/comparator/all/part_all_comparator.c"
#include "../../../executor/converter/selector/http_request/method_http_request_selector.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Gets the knowledge part by hierarchical name,
 * whereby the name may also be given as encapsulated name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
 *
 * The model may specify:
 * - the element directly (e.g.: an integer or character value)
 * - the hierarchical name of the element (e.g.: application.gui.window.title)
 * - the hierarchical name of the name of the element (e.g.: application.name)
 *   where application.name itself contains a hierarchical name
 *   that points to an element;
 *   at first, the part name needs to be determined within the parameters;
 *   only then, that name can be used to determine the actual compound element
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source whole part
 * @param p2 the hierarchical part name current position (Hand over as reference!)
 * @param p3 the hierarchical part name remaining count
 */
void get_part_knowledge(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get part knowledge.");

/*??
    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part abstraction, model.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The part abstraction, model data, count.
    void* ad = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* md = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    // The encapsulated part.
    void* ep = *NULL_POINTER_MEMORY_MODEL;
    // The encapsulated part model.
    void* em = *NULL_POINTER_MEMORY_MODEL;
    // The encapsulated part model data, count.
    void* emd = *NULL_POINTER_MEMORY_MODEL;
    void* emc = *NULL_POINTER_MEMORY_MODEL;

    // Get part.
    // CAUTION! This IS necessary to find out about the abstraction.
    get_part_branch((void*) &p, p1, p2, p3);
    // Get part abstraction item.
    copy_array_forward((void*) &a, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Get part abstraction data, count array.
    copy_array_forward((void*) &ad, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ac, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // The following comparisons do, in this order, get a part as:
    // - encapsulated knowledge (a model pointing to another model containing a part name)
    // - knowledge (a model containing a hierarchical part name)
    // - direct model
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, ad, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, ac, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //
            // Get part as double-encapsulated knowledge.
            //
            // CAUTION! The "abstraction" of an encapsulated name must always be "character"
            // (which is processed as wide character wchar_t inside of cyboi, of course).
            // The "details" are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model pointing to another model containing a part name:
            // model="application.record.name"
            //

            get_part_branch((void*) &ep, p1, md, mc);
            get_part_branch((void*) &p, p1, emd, emc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_all_array((void*) &r, ad, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, ac, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //
            // Get part as encapsulated model.
            //
            // CAUTION! The "abstraction" of an encapsulated name must always be "character"
            // (which is processed as wide character wchar_t inside of cyboi, of course).
            // The "details" are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model containing a hierarchical part name:
            // model="application.communication.partners.hostname"
            //

            get_part_branch((void*) &p, p1, md, mc);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        //
        // Get part as direct model (inline).
        //
        // It would actually be possible to remember the values of
        // the first call to "get_part_branch" above,
        // and assign these to the parameters here, which might lead to
        // some optimisation and better performance.
        // For reasons of clearity of code, however, the introduction and
        // usage of those many additional local variables was avoided
        // and the "get_part_branch" procedure
        // is called here a second time instead.
        //
        get_part_branch((void*) &p, p1, p2, p3);
    }
*/
}

/* KNOWLEDGE_PART_GETTER_SOURCE */
#endif
