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
 * @version $RCSfile: xml_converter.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_XML_DECODER_SOURCE
#define ELEMENT_XML_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/accessor/appender/compound_appender.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/decoder/xml/attribute_xml_decoder.c"
//?? #include "../../../../executor/converter/decoder/xml/element_content_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/tag_name_xml_decoder.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void decode_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Decodes the xml element.
 *
 * @param p0 the destination whole model (Hand over as reference!)
 * @param p1 the destination whole model count
 * @param p2 the destination whole model size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void decode_xml_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** dd = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xml element.");

        // The part name, abstraction, model, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ns = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* as = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* ms = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* ds = *NULL_POINTER_MEMORY_MODEL;

        // Allocate destination part.
        allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
            (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

        // Decode destination part name.
        // CAUTION! The pre-defined constant "part" is used as name here!
        // The "append_compound_element_by_name" function below will automatically
        // add a number as suffix, to make the name unique.
        decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) NODE_XML_CYBOL_NAME, (void*) NODE_XML_CYBOL_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        // Decode destination part abstraction.
        // CAUTION! All xml elements (parts) are of the abstraction "compound",
        // as internally used by the function "allocate_part" above.
        // If an xml element is empty, the compound will just not contain any parts.
        decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        // The destination part model and details are decoded further below,
        // depending on the source wide character array.

        // The has attribute flag.
        int ha = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The has content flag.
        int hc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The is empty flag.
        int ie = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Decode tag name.
        decode_xml_tag_name((void*) &d, (void*) dc, (void*) ds, (void*) &ha, (void*) &hc, (void*) &ie, p3, p4);

        if (ha != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Reset has attributes flag.
            ha = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Decode attribute.
            decode_xml_attribute((void*) &d, (void*) dc, (void*) ds, (void*) &hc, (void*) &ie, p3, p4);
        }

        if (hc != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Decode the element's content.
            decode_xml_element_content((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds, p3, p4);
        }

        // Add part to whole (compound) model.
        // CAUTION! Hand over the name as reference!
        // Storing many parts with identical tag name is not a problem,
        // since the tag name of a part is added to its details compound.
        append_compound_element_by_name_with_suffix(*dd, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml element. The destination is null.");
    }
}

/* ELEMENT_XML_DECODER_SOURCE */
#endif
