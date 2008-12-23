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
 * @version $RCSfile: cybol_processor.c,v $ $Revision: 1.1 $ $Date: 2008-12-23 22:37:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_PROCESSOR_SOURCE
#define CYBOL_PROCESSOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/xml_cybol_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/selector/xml_selector.c"

//
// Forward declarations.
//

void communicate_receiving_with_parameters(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23);

/**
 * Decodes a cybol property.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count
 * @param p2 the name size
 * @param p3 the channel (Hand over as reference!)
 * @param p4 the channel count
 * @param p5 the channel size
 * @param p6 the abstraction (Hand over as reference!)
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model (Hand over as reference!)
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the property value
 * @param p13 the name
 * @param p14 the name count
 */
/*??
void decode_cybol_cybol_property(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode compound cybol property.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) NAME_ATTRIBUTE_AS_CHAR, (void*) NAME_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source name.
                    decode_utf_8_unicode_character_vector(p0, p1, p2, (void*) pv->content, (void*) &tmpc);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) CHANNEL_ATTRIBUTE_AS_CHAR, (void*) CHANNEL_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source channel.
                    decode_utf_8_unicode_character_vector(p3, p4, p5, (void*) pv->content, (void*) &tmpc);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) ABSTRACTION_ATTRIBUTE_AS_CHAR, (void*) ABSTRACTION_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source abstraction.
                    decode_utf_8_unicode_character_vector(p6, p7, p8, (void*) pv->content, (void*) &tmpc);
                }
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                compare_arrays(p13, p14, (void*) MODEL_ATTRIBUTE_AS_CHAR, (void*) MODEL_ATTRIBUTE_AS_CHAR_COUNT, (void*) &r, (void*) CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Determine temporary character array count.
                    int tmpc = strlen((char*) pv->content);

                    // Get source model.
                    decode_utf_8_unicode_character_vector(p9, p10, p11, (void*) pv->content, (void*) &tmpc);
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol property. The CASTED property value is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode compound cybol property. The property value is null.");
    }
}
*/

/**
 * Processes the cybol node model.
 *
 * @param p0 the destination whole model (Hand over as reference!)
 * @param p1 the destination whole model count
 * @param p2 the destination whole model size
 * @param p6 the source name
 * @param p7 the source name count
 * @param p8 the source channel
 * @param p9 the source channel count
 * @param p6 the source abstraction
 * @param p7 the source abstraction count
 * @param p6 the source model
 * @param p7 the source model count
 */
void process_cybol_node_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p3;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process cybol node model.");

/*??
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

                // Allocate destination name.
                allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                    (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) sa, (void*) sac);

                // Decode destination part name.
                // CAUTION! The pre-defined constant "part" is used as name here!
                // The "add_compound_element_by_name" function below will automatically
                // add a number as suffix, to make the name unique.
                decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) sn, (void*) snc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

                // CAUTION! A destination channel is not created,
                // since that is only needed temporarily for model loading.

                // Decode destination part abstraction.
                // A source's cybol abstraction is most often not equal to its runtime abstraction.
                // For example, an "xdt" file is converted into a compound.
                decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) sa, (void*) sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) ABSTRACTION_CYBOL_ABSTRACTION, (void*) ABSTRACTION_CYBOL_ABSTRACTION_COUNT);

                // Receive and decode destination part model and details.
                communicate_receiving_with_parameters(*NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    (void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    sm, smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    sa, sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sc, scc);

                // Add part to whole (compound) model.
                // CAUTION! Hand over the name as reference!
                add_compound_element_by_name(*dd, p1, p2, (void*) &n, (void*) nc, (void*) ns, a, ac, as, m, mc, ms, d, dc, ds);
*/

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element. The remaining count is null.");
    }
}

/**
 * Processes cybol node.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source model
 * @param p7 the source model count
 * @param p8 the source details
 * @param p9 the source details count
 */
void process_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* smc = (int*) p7;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process cybol node.");

        // The part model name, abstraction, model, details.
        void* mn = *NULL_POINTER_MEMORY_MODEL;
        int mnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int mns = *NUMBER_0_INTEGER_MEMORY_MODEL;
        void* ma = *NULL_POINTER_MEMORY_MODEL;
        int mac = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int mas = *NUMBER_0_INTEGER_MEMORY_MODEL;
        void* mm = *NULL_POINTER_MEMORY_MODEL;
        int mmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int mms = *NUMBER_0_INTEGER_MEMORY_MODEL;
        void* md = *NULL_POINTER_MEMORY_MODEL;
        int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The part details name, abstraction, model, details.
        void* dn = *NULL_POINTER_MEMORY_MODEL;
        int dnc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int dns = *NUMBER_0_INTEGER_MEMORY_MODEL;
        void* da = *NULL_POINTER_MEMORY_MODEL;
        int dac = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int das = *NUMBER_0_INTEGER_MEMORY_MODEL;
        void* dm = *NULL_POINTER_MEMORY_MODEL;
        int dmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int dms = *NUMBER_0_INTEGER_MEMORY_MODEL;
        void* dd = *NULL_POINTER_MEMORY_MODEL;
        int ddc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int dds = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // The model flag.
        int mf = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The part flag.
        int pf = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The property flag.
        int prf = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *smc) {

                break;
            }

            // Get part model.
            get_compound_element_by_index(p6, p7, (void*) &j, (void*) &mn, (void*) &mnc, (void*) &mns, (void*) &ma, (void*) &mac, (void*) &mas, (void*) &mm, (void*) &mmc, (void*) &mms, (void*) &md, (void*) &mdc, (void*) &mds);
            // Get part details.
            get_compound_element_by_index(p8, p9, (void*) &j, (void*) &dn, (void*) &dnc, (void*) &dns, (void*) &da, (void*) &dac, (void*) &das, (void*) &dm, (void*) &dmc, (void*) &dms, (void*) &dd, (void*) &ddc, (void*) &dds);

            detect_cybol_node_type((void*) &mf, (void*) &pf, (void*) &prf, md, (void*) &mdc);

            if (mf != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // This is a cybol root node indicated by a tag called "model".

                // Process the root node's content.
                process_cybol_root_content(p0, p1, p2, p3, p4, p5, mm, (void*) &mmc, md, (void*) &mdc);

                // Break this loop, since one root node is allowed at most!
                break;

            } else if (pf != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // This is a cybol part node indicated by a tag called "part".

                detect_cybol_node_details(nn, nnc, nns, na, nac, nas, nm, nmc, nms, nd, ndc, nds,
                    cn, cnc, cns, ca, cac, cas, cm, cmc, cms, cd, cdc, cds,
                    an, anc, ans, aa, aac, aas, am, amc, ams, ad, adc, ads,
                    mn, mnc, mns, ma, mac, mas, mm, mmc, mms, md, mdc, mds,
                    p8, p9);

                // The model.
                void* m = *NULL_POINTER_MEMORY_MODEL;
                int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;

                process_cybol_node_model((void*) &m, (void*) &mc, (void*) &ms, nm, nmc, cm, cmc, am, amc, mm, mmc);
                process_cybol_node_details();

            } else if (prf != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // This is a cybol meta node indicated by a tag called "property".

            } else {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not process cybol root. The cybol node type is unknown.");
            }

            // Increment loop variable.
            j++;
        }
*/

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol root. The source count is null.");
    }
}

//?? ===================================

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
/*??
void process_xml_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xml element content.");

        // The break flag.
        int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is zero or smaller.");

                break;
            }

            select_xml_element_content(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

            if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                break;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xml element content. The remaining count is null.");
    }
}
*/

/* CYBOL_PROCESSOR_SOURCE */
#endif
