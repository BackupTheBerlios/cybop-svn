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
 * @version $RCSfile: cybol_processor.c,v $ $Revision: 1.2 $ $Date: 2008-12-26 16:19:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_PROCESSOR_SOURCE
#define CYBOL_PROCESSOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybop/cybop_name.c"
#include "../../logger/logger.c"

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
 * Processes the cybol node.
 *
 * The source details handed over contain one node each for
 * name, channel, abstraction, model.
 *
 * Example:
 *
 * | | +-node_$0 | compound
 * | | | #- | wide_character_vector | property
 * | | | #-name | wide_character_vector | type
 * | | | #-channel | wide_character_vector | inline
 * | | | #-abstraction | wide_character_vector | text/plain
 * | | | #-model | wide_character_vector | sending
 *
 * @param p0 the destination whole model (Hand over as reference!)
 * @param p1 the destination whole model count
 * @param p2 the destination whole model size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source details
 * @param p6 the source details count
 */
void process_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* ssmc = (int*) p4;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** dd = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process cybol node model.");

            // The source part name, channel, abstraction, model.
            void** sn = NULL_POINTER_MEMORY_MODEL;
            void** snc = NULL_POINTER_MEMORY_MODEL;
            void** sc = NULL_POINTER_MEMORY_MODEL;
            void** scc = NULL_POINTER_MEMORY_MODEL;
            void** sa = NULL_POINTER_MEMORY_MODEL;
            void** sac = NULL_POINTER_MEMORY_MODEL;
            void** sm = NULL_POINTER_MEMORY_MODEL;
            void** smc = NULL_POINTER_MEMORY_MODEL;

            // Detect source part name, channel, abstraction, model.
            //
            // They are contained in the details.
            //
            // Example:
            //
            // | | +-node_$0 | compound
            // | | | #- | wide_character_vector | property
            // | | | #-name | wide_character_vector | type
            // | | | #-channel | wide_character_vector | inline
            // | | | #-abstraction | wide_character_vector | text/plain
            // | | | #-model | wide_character_vector | sending
            //
            // TODO: REPLACE p5, p6, with source details
//??            detect_cybol_node_details((void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc, (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc, p5, p6);

            // Get source part name, channel, abstraction, model.
            get_compound_element_by_name(p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) NAME_CYBOP_NAME, (void*) NAME_CYBOP_NAME_COUNT,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) &sn, (void*) &snc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
            get_compound_element_by_name(p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) CHANNEL_CYBOP_NAME, (void*) CHANNEL_CYBOP_NAME_COUNT,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) &sc, (void*) &scc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
            get_compound_element_by_name(p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) ABSTRACTION_CYBOP_NAME, (void*) ABSTRACTION_CYBOP_NAME_COUNT,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) &sa, (void*) &sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);
            get_compound_element_by_name(p5, p6, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) MODEL_CYBOP_NAME, (void*) MODEL_CYBOP_NAME_COUNT,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) &sm, (void*) &smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

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

            // Allocate destination part.
            allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                (void*) NUMBER_0_INTEGER_MEMORY_MODEL, sa, (void*) &sac);

            // Decode destination part name.
            decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sn, (void*) &snc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

            // Decode destination part abstraction.
            // A source's cybol abstraction is most often not equal to its runtime abstraction.
            // For example, an "xdt" file is converted into a compound.
            decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sa, (void*) &sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION_COUNT);

            // Receive and decode destination part model and details.
            communicate_receiving_with_parameters(*NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                sm, (void*) &smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                sa, (void*) &sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, sc, (void*) &scc);

            // The meta node name, abstraction, model, details.
            void** mn = NULL_POINTER_MEMORY_MODEL;
            void** mnc = NULL_POINTER_MEMORY_MODEL;
            void** mns = NULL_POINTER_MEMORY_MODEL;
            void** ma = NULL_POINTER_MEMORY_MODEL;
            void** mac = NULL_POINTER_MEMORY_MODEL;
            void** mas = NULL_POINTER_MEMORY_MODEL;
            void** mm = NULL_POINTER_MEMORY_MODEL;
            void** mmc = NULL_POINTER_MEMORY_MODEL;
            void** mms = NULL_POINTER_MEMORY_MODEL;
            void** md = NULL_POINTER_MEMORY_MODEL;
            void** mdc = NULL_POINTER_MEMORY_MODEL;
            void** mds = NULL_POINTER_MEMORY_MODEL;

            //?? TODO: WHAT TO USE HERE: void** or normal void* ??
            //?? CHECK ALL POINTERS IN THIS FUNCTION!

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *ssmc) {

                    break;
                }

                // Get meta node model.
                get_compound_element_by_index(p3, p4, (void*) &j, (void*) &mn, (void*) &mnc, (void*) &mns, (void*) &ma, (void*) &mac, (void*) &mas, (void*) &mm, (void*) &mmc, (void*) &mms, (void*) &md, (void*) &mdc, (void*) &mds);

                // Process the node's meta information (details).
                process_cybol_node((void*) &d, dc, ds, mm, mmc, md, mdc);

                // Increment loop variable.
                j++;
            }

            // Add part to whole (compound) model.
            // CAUTION! Hand over the name as reference!
            add_compound_element_by_name(*dd, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol node model. The destination whole model is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol node model. The source details count is null.");
    }
}

/**
 * Processes cybol node.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source details
 * @param p6 the source details count
 */
/*??
void process_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process cybol node.");

    // The model flag.
    int mf = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The part flag.
    int pf = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The property flag.
    int prf = *NUMBER_0_INTEGER_MEMORY_MODEL;

    detect_cybol_node_type((void*) &mf, (void*) &pf, (void*) &prf, md, (void*) &mdc);

    if (mf != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // This is a cybol root node indicated by a tag called "model".

        // Process the root node's content.
        process_cybol_root_content(p0, p1, p2, mm, (void*) &mmc, md, (void*) &mdc);

        // Break this loop, since one root node is allowed at most!
        break;

    } else if (pf != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // This is a cybol part node indicated by a tag called "part".

        detect_cybol_node_details(nn, nnc, nns, na, nac, nas, nm, nmc, nms, nd, ndc, nds,
            cn, cnc, cns, ca, cac, cas, cm, cmc, cms, cd, cdc, cds,
            an, anc, ans, aa, aac, aas, am, amc, ams, ad, adc, ads,
            mn, mnc, mns, ma, mac, mas, mm, mmc, mms, md, mdc, mds,
            p5, p6);

        process_cybol_node_model(p0, p1, p2, nm, nmc, cm, cmc, am, amc, mm, mmc, p3, p4);

    } else {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not process cybol root. The cybol node type is unknown.");
    }
}
*/

/* CYBOL_PROCESSOR_SOURCE */
#endif
