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
 * @version $RCSfile: cybol_processor.c,v $ $Revision: 1.10 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_PROCESSOR_SOURCE
#define CYBOL_PROCESSOR_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybop/cybop_name.c"
#include "../../../executor/accessor/appender/compound_appender.c"
#include "../../../executor/converter/detector/cybol_detector.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void communicate_receiving_with_parameters(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16,
    void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23);

void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

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

            // The source details name, channel, abstraction, model.
            void** sn = NULL_POINTER_MEMORY_MODEL;
            void** snc = NULL_POINTER_MEMORY_MODEL;
            void** sc = NULL_POINTER_MEMORY_MODEL;
            void** scc = NULL_POINTER_MEMORY_MODEL;
            void** sa = NULL_POINTER_MEMORY_MODEL;
            void** sac = NULL_POINTER_MEMORY_MODEL;
            void** sm = NULL_POINTER_MEMORY_MODEL;
            void** smc = NULL_POINTER_MEMORY_MODEL;

            // Get source details name, channel, abstraction, model.
            //
            // They belong to the part to be created.
            //
            // Example:
            //
            // | | +-node_$0 | compound
            // | | | #- | wide_character_vector | property
            // | | | #-name | wide_character_vector | type
            // | | | #-channel | wide_character_vector | inline
            // | | | #-abstraction | wide_character_vector | text/plain
            // | | | #-model | wide_character_vector | sending
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

            // The root node flag.
            int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

            detect_cybol_root_node((void*) &r, *sn, *snc, *sc, *scc, *sa, *sac, *sm, *smc);

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // This is NOT the root node.
                // Therefore, the node's details are processed.

                // The temporary runtime abstraction.
                // CAUTION! It is needed to retrieve the abstraction of the part to be created.
                // Otherwise, it would not be known which part model to create.
                // The source abstraction cannot be converted directly into the part's abstraction,
                // because the part model has not been allocated yet when reading the abstraction
                // for the first time.
                void* ra = *NULL_POINTER_MEMORY_MODEL;
                int rac = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int ras = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Allocate temporary runtime abstraction.
                allocate_array((void*) &ra, (void*) &ras, (void*) INTEGER_MEMORY_ABSTRACTION);

                // Decode source- into temporary runtime abstraction.
                // A cybol abstraction is NOT equal to the runtime cyboi abstraction.
                // For example, an "xdt" file is converted into a compound.
                // Therefore, the abstraction has to be converted here.
                decode((void*) &ra, (void*) &rac, (void*) &ras, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *sa, *sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION_COUNT);

                // Allocate destination part.
                // CAUTION! Use the temporary RUNTIME abstraction as source here!
                allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                    (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                    (void*) NUMBER_0_INTEGER_MEMORY_MODEL, ra, (void*) &rac);

                // Decode destination part name.
                decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *sn, *snc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

                // Decode destination part abstraction.
                // CAUTION! The temporary runtime abstraction may also have been used as source here.
                // In this case, its (integer) value would have had to be copied to the part abstraction.
                // However, to be more consistent, the "decode" function is called a second time.
                decode((void*) &a, (void*) &ac, (void*) &as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *sa, *sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION_COUNT);

                // Deallocate temporary runtime abstraction.
                deallocate_array((void*) &ra, (void*) &ras, (void*) INTEGER_MEMORY_ABSTRACTION);

                // Receive and decode destination part model and details.
                // CAUTION! Use the ORIGINAL CYBOL abstraction as source here
                // (not the temporary runtime abstraction)!
                communicate_receiving_with_parameters(*NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    (void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    *sm, *smc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                    *sa, *sac, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *sc, *scc);
            }

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

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *ssmc) {

                    break;
                }

                // Get meta node model.
                get_compound_element_by_index(p3, p4, (void*) &j, (void*) &mn, (void*) &mnc, (void*) &mns, (void*) &ma, (void*) &mac, (void*) &mas, (void*) &mm, (void*) &mmc, (void*) &mms, (void*) &md, (void*) &mdc, (void*) &mds);

                if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // This is a standard part node and NOT the root node.

                    // Process the node's meta information (details),
                    // by recursively calling this function itself.
                    process_cybol_node((void*) &d, dc, ds, *mm, *mmc, *md, *mdc);

                } else {

                    // This IS the root node.
                    // Add the meta node model and details directly to the
                    // destination whole node (root).

                    // Process the node's meta information (details),
                    // by recursively calling this function itself.
                    process_cybol_node(p0, p1, p2, *mm, *mmc, *md, *mdc);
                }

                // Increment loop variable.
                j++;
            }

            if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // This is NOT the root node.

                // Add part to whole (compound) model.
                // CAUTION! Hand over the name as reference!
                append_compound_element_by_name(*dd, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol node model. The destination whole model is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process cybol node model. The source details count is null.");
    }
}

/* CYBOL_PROCESSOR_SOURCE */
#endif
