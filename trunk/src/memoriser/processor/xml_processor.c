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
 * @version $RCSfile: xml_processor.c,v $ $Revision: 1.3 $ $Date: 2008-11-03 23:16:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XML_PROCESSOR_SOURCE
#define XML_PROCESSOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/xml_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/selector/xml_selector.c"

/**
 * Processes the xml declaration.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void process_xml_declaration(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml declaration.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            select_xml_declaration(p0, p1, p2, (void*) &b, p3, p4);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml declaration. The remaining bytes count is null.");
    }
}

/**
 * Processes the xml definition.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining bytes count
 */
void process_xml_definition(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml definition.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            select_xml_definition((void*) &b, p3, p4);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml definition. The remaining bytes count is null.");
    }
}

/**
 * Processes the xml comment.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining bytes count
 */
void process_xml_comment(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml comment.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            select_xml_comment((void*) &b, p0, p1);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml comment. The remaining bytes count is null.");
    }
}

/**
 * Processes the xml element content.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the current position (Hand over as reference!)
 * @param p7 the remaining count
 */
void process_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element content.");

    fwprintf(stderr, L"TEST process element content rem: %i\n", *rem);

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is zero or smaller.");

                break;
            }

            if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }

            select_xml_element_content(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is null.");
    }
}

/**
 * Processes the xml end tag.
 *
 * @param p0 the current position (Hand over as reference!)
 * @param p1 the remaining count
 */
void process_xml_end_tag(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml end tag.");

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml end tag. The remaining count is zero or smaller.");

                    break;
                }

                select_xml_end_tag((void*) &b, p0, p1);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml end tag. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml end tag. The remaining count is null.");
    }
}

/**
 * Processes the xml tag name.
 *
 * @param p0 the destination element details (Hand over as reference!)
 * @param p1 the destination element details count
 * @param p2 the destination element details size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void process_xml_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml tag name.");

            // The destination tag name name.
            void* n = *NULL_POINTER_MEMORY_MODEL;
            void* nc = *NULL_POINTER_MEMORY_MODEL;
            void* ns = *NULL_POINTER_MEMORY_MODEL;
            // The destination tag name abstraction.
            void* a = *NULL_POINTER_MEMORY_MODEL;
            void* ac = *NULL_POINTER_MEMORY_MODEL;
            void* as = *NULL_POINTER_MEMORY_MODEL;
            // The destination tag name model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            void* mc = *NULL_POINTER_MEMORY_MODEL;
            void* ms = *NULL_POINTER_MEMORY_MODEL;
            // The destination tag name details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            void* dc = *NULL_POINTER_MEMORY_MODEL;
            void* ds = *NULL_POINTER_MEMORY_MODEL;

            // Allocate destination tag name.
            allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // The source tag name.
            void* tn = *pos;
            int tnc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The remaining count is zero or smaller.");

                    break;
                }

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_xml_tag_name((void*) &tnc, (void*) &b, p3, p4);
            }

            // Decode destination tag name name.
            // CAUTION! The pre-defined constant "tag" is used as name here!
            // The "add_compound_element_by_name" function below will automatically
            // add a number as suffix, to make the name unique.
            decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) TAG_XML_CYBOL_NAME, (void*) TAG_XML_CYBOL_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination tag name abstraction.
            // CAUTION! All xml element tag names are of the abstraction "wide_character",
            // as handed over as argument in the function "allocate_part" above.
            decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // Decode destination tag name model.
            decode((void*) &m, (void*) mc, (void*) ms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, tn, (void*) &tnc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

            // The destination tag name does not contain any details.

            //?? Extend compound size etc. before?

            // Add tag name to destination xml element (compound) details.
            // CAUTION! Hand over the tag name name as reference!
            // CAUTION! The pre-defined constant "tag" is used as name here!
            add_compound_element_by_name(p0, p1, p2, (void*) &n, (void*) &nc, (void*) &ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml tag name. The remaining count is null.");
    }
}

/**
 * Processes the xml attribute name.
 *
 * @param p0 the attribute name (Hand over as reference!)
 * @param p1 the attribute name count
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void process_xml_attribute_name(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** an = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml attribute name.");

                // Set attribute name.
                *an = *pos;

                // The break flag.
                int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The remaining count is zero or smaller.");

                        break;
                    }

                    select_xml_attribute_name(p1, (void*) &b, p2, p3);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The attribute name is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute name. The remaining count is null.");
    }
}

/**
 * Processes the xml attribute value.
 *
 * @param p0 the attribute value (Hand over as reference!)
 * @param p1 the attribute value count
 * @param p2 the current position (Hand over as reference!)
 * @param p3 the remaining count
 */
void process_xml_attribute_value(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** av = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml attribute value.");

                // Set attribute value.
                *av = *pos;

                // The break flag.
                int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The remaining count is zero or smaller.");

                        break;
                    }

                    select_xml_attribute_value(p1, (void*) &b, p2, p3);
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The attribute value is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml attribute value. The remaining count is null.");
    }
}

/**
 * Processes the xml element.
 *
 * @param p0 the destination whole model (Hand over as reference!)
 * @param p1 the destination whole model count
 * @param p2 the destination whole model size
 * @param p3 the current position (Hand over as reference!)
 * @param p4 the remaining count
 */
void process_xml_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element.");

    fwprintf(stderr, L"TEST process element rem: %i\n", *rem);

            // The part name.
            void* n = *NULL_POINTER_MEMORY_MODEL;
            void* nc = *NULL_POINTER_MEMORY_MODEL;
            void* ns = *NULL_POINTER_MEMORY_MODEL;
            // The part abstraction.
            void* a = *NULL_POINTER_MEMORY_MODEL;
            void* ac = *NULL_POINTER_MEMORY_MODEL;
            void* as = *NULL_POINTER_MEMORY_MODEL;
            // The part model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            void* mc = *NULL_POINTER_MEMORY_MODEL;
            void* ms = *NULL_POINTER_MEMORY_MODEL;
            // The part details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            void* dc = *NULL_POINTER_MEMORY_MODEL;
            void* ds = *NULL_POINTER_MEMORY_MODEL;

    fwprintf(stderr, L"TEST process element 0: %i\n", *rem);

            // Allocate destination name.
            allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST process element 1: %i\n", *rem);

            // Decode destination part name.
            // CAUTION! The pre-defined constant "part" is used as name here!
            // The "add_compound_element_by_name" function below will automatically
            // add a number as suffix, to make the name unique.
            decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_XML_CYBOL_NAME, (void*) PART_XML_CYBOL_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST process element 2: %i\n", *rem);

            // Decode destination part abstraction.
            // CAUTION! All xml elements (parts) are of the abstraction "compound",
            // as internally used by the function "allocate_part" above.
            // If an xml element is empty, the compound will just not contain any parts.
            decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST process element 3: %i\n", *rem);

            // The destination part model and details are decoded further below,
            // depending on the source byte array.

            // Decode tag name.
            process_xml_tag_name((void*) &d, (void*) dc, (void*) ds, p3, p4);

    fwprintf(stderr, L"TEST process element 4: %i\n", *rem);

            // The tag name end found may be one of: " ", "/>", ">".
            // The position now points to the next character AFTER the tag name end,
            // i.e. to the FIRST character of the attribute name or element content.

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is zero or smaller.");

                    break;
                }

    fwprintf(stderr, L"TEST process element 5: %i\n", *rem);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                // Process the element's attributes.
                select_xml_element((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds, (void*) &b, p3, p4);
            }

    fwprintf(stderr, L"TEST process element 6: %i\n", *rem);

            //?? Extend compound size etc. before?

            // Add part to whole (compound) model.
            // CAUTION! Hand over the name as reference!
            // Storing many parts with identical tag name is not a problem,
            // since the tag name of a part is added to its details compound.
            add_compound_element_by_name(p0, p1, p2, (void*) &n, (void*) &nc, (void*) &ns, a, ac, as, m, mc, ms, d, dc, ds);

    fwprintf(stderr, L"TEST process element 7: %i\n", *rem);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is null.");
    }
}

/* XML_PROCESSOR_SOURCE */
#endif
