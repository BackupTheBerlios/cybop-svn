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
 * @version $RCSfile: xml_converter.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ATTRIBUTE_XML_DECODER_SOURCE
#define ATTRIBUTE_XML_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../executor/accessor/appender/compound_appender.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/decoder/xml/attribute_name_xml_decoder.c"
#include "../../../../executor/converter/decoder/xml/attribute_value_xml_decoder.c"
#include "../../../../executor/converter/selector/xml/attribute_begin_or_tag_end_xml_selector.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the xml attribute.
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the has content flag
 * @param p4 the is empty flag
 * @param p5 the current position (Hand over as reference!)
 * @param p6 the remaining count
 */
void decode_xml_attribute(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p6;

        if (p5 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p5;

            if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                int* ie = (int*) p4;

                if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                    int* hc = (int*) p3;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        void** dd = (void**) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xml attribute.");

                        // The source attribute name.
                        void* an = *NULL_POINTER_MEMORY_MODEL;
                        int anc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The source attribute value.
                        void* av = *NULL_POINTER_MEMORY_MODEL;
                        int avc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        decode_xml_attribute_name((void*) &an, (void*) &anc, p5, p6);
                        decode_xml_attribute_value((void*) &av, (void*) &avc, p5, p6);

                        append_part(p0, p1, p2, an, (void*) &anc,
                            (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                            av, (void*) &avc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                        // The has attribute flag.
                        // CAUTION! This HAS TO BE a local variable, because the function
                        // may be called recursively and if the flag were handed over
                        // as argument to this function, then it would have an initial value
                        // from a previous call of this function, which might lead to wrong results.
                        int ha = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute. The remaining count is zero or smaller.");

                                break;
                            }

                            select_xml_attribute_begin_or_tag_end((void*) &ha, p3, p4, p5, p6);

                            if (ha != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                // A space character as indicator of subsequent attributes was detected.

                                // Call this function itself recursively.
                                decode_xml_attribute(p0, p1, p2, p3, p4, p5, p6);
                            }

                            if ((*hc != *NUMBER_0_INTEGER_MEMORY_MODEL) || (*ie != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                                // A tag end character as indicator of subsequent element content or
                                // an empty tag end character was detected.

                                break;
                            }
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute. The destination details is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute. The has content flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute. The is empty flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xml attribute. The remaining count is null.");
    }
}

/* ATTRIBUTE_XML_DECODER_SOURCE */
#endif
