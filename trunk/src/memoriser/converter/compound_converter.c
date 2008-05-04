/*
 * $RCSfile: compound_converter.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.16 $ $Date: 2008-05-04 00:18:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_CONVERTER_SOURCE
#define COMPOUND_CONVERTER_SOURCE

//?? Use libxml2 parser as temporary workaround. Later, self-written parsing functions should be used.
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/allocator/xml_node_allocator.c"
#include "../../memoriser/allocator/xml_property_allocator.c"
#include "../../memoriser/converter/abstraction_converter.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/communicator.c"

//
// Forward declarations.
//

/**
 * Decodes the source into the destination, according to the given language.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source
 * @param p7 the source count
 * @param p8 the knowledge memory
 * @param p9 the knowledge memory count
 * @param p10 the language
 * @param p11 the language count
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Sets the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void set_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

/**
 * Decodes the compound cybol node.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode*)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_compound_cybol_nodes(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Decodes the xml stream until an xml comment end tag is reached.
 *
 * This procedure only counts up the stream pointer and
 * changes nothing in the xml model.
 *
 * @param p0 the xml stream
 * @param p1 the xml stream count
 */
/*??
void decode_compound_comment_tag(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* sc = (int*) p1;

        // The leave flag.
        int l = *NUMBER_0_INTEGER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;
        // The current byte within the stream.
        void* b = p0;
        // The remaining bytes count.
        int bc = *sc;

        while (*NUMBER_1_INTEGER) {

            if ((l == *NUMBER_1_INTEGER) || (bc <= *NUMBER_0_INTEGER)) {

                break;
            }

            if (r == *NUMBER_0_INTEGER) {

                if (bc >= *END_COMMENT_TAG_COUNT) {

                    compare_array_elements((void*) b, (void*) END_COMMENT_TAG, (void*) END_COMMENT_TAG_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *END_COMMENT_TAG_COUNT;
                        bc = bc - *END_COMMENT_TAG_COUNT;

                        // Set leave flag.
                        l = *NUMBER_1_INTEGER;
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                if (bc >= *SHORT_END_COMMENT_TAG_COUNT) {

                    compare_array_elements((void*) b, (void*) SHORT_END_COMMENT_TAG, (void*) SHORT_END_COMMENT_TAG_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *SHORT_END_COMMENT_TAG_COUNT;
                        bc = bc - *SHORT_END_COMMENT_TAG_COUNT;

                        // Set leave flag.
                        l = *NUMBER_1_INTEGER;
                    }
                }
            }

            // If this block is reached, then no known term was found before.
            // The current byte pointer will just be incremented by one so
            // that new characters are read and compared in the next loop cycle.
            if (r != *NUMBER_1_INTEGER) {

                // Increment current byte within persistent model.
                b++;
                // Decrement remaining bytes count.
                bc--;
            }

            // Reset comparison result.
            r = *NUMBER_0_INTEGER;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialise compound. The persistent model count is null.");
    }
}
*/

/**
 * Decodes the xml stream into an xml tag.
 *
 * @param p0 the xml model
 * @param p1 the xml model count
 * @param p2 the xml model size
 * @param p3 the xml stream
 * @param p4 the xml stream count
 */
/*??
void decode_compound_tag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        // The leave flag.
        int l = *NUMBER_0_INTEGER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;
        // The current byte within the stream.
        void* b = (void*) p3;
        // The remaining bytes count.
        int bc = *sc;

        while (*NUMBER_1_INTEGER) {

            if ((l == *NUMBER_1_INTEGER) || (bc <= *NUMBER_0_INTEGER)) {

                break;
            }

            if (r == *NUMBER_0_INTEGER) {

                if (bc >= *EMPTY_TAG_END_COUNT) {

                    compare_array_elements((void*) b, (void*) EMPTY_TAG_END, (void*) EMPTY_TAG_END_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *EMPTY_TAG_END_COUNT;
                        bc = bc - *EMPTY_TAG_END_COUNT;

                        // Set leave flag.
                        l = *NUMBER_1_INTEGER;
                    }
                }
            }

            if (r == *NUMBER_0_INTEGER) {

                if (bc >= *TAG_END_COUNT) {

                    compare_array_elements((void*) b, (void*) TAG_END, (void*) TAG_END_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                    if (r != *NUMBER_0_INTEGER) {

                        // Move current byte pointer
                        // and remaining bytes count.
                        b = b + *TAG_END_COUNT;
                        bc = bc - *TAG_END_COUNT;

                        // Decode xml value.
//??                        decode_xml_value((void*) &b, (void*) &bc);
                    }
                }
            }

            // Reset comparison result.
            r = *NUMBER_0_INTEGER;
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not initialise compound. The persistent model count is null.");
    }
}
*/

/**
 * Decodes a cybol property.
 *
 * @param p0 the name
 * @param p1 the name count
 * @param p2 the channel
 * @param p3 the channel count
 * @param p4 the abstraction
 * @param p5 the abstraction count
 * @param p6 the model
 * @param p7 the model count
 * @param p8 the property value
 * @param p9 the name
 * @param p10 the name count
 */
void decode_compound_cybol_property(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p8 != *NULL_POINTER) {

        xmlNode* pv = (xmlNode*) p8;

        if (p7 != *NULL_POINTER) {

            int* mc = (int*) p7;

            if (p6 != *NULL_POINTER) {

                void** m = (void**) p6;

                if (p5 != *NULL_POINTER) {

                    int* ac = (int*) p5;

                    if (p4 != *NULL_POINTER) {

                        void** a = (void**) p4;

                        if (p3 != *NULL_POINTER) {

                            int* cc = (int*) p3;

                            if (p2 != *NULL_POINTER) {

                                void** c = (void**) p2;

                                if (p1 != *NULL_POINTER) {

                                    int* nc = (int*) p1;

                                    if (p0 != *NULL_POINTER) {

                                        void** n = (void**) p0;

                                        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Decode compound cybol property.");

                                        // The comparison result.
                                        int r = *NUMBER_0_INTEGER;

                                        if (pv != *NULL_POINTER) {

                                            if (r == *NUMBER_0_INTEGER) {

                                                compare_arrays(p9, p10, (void*) NAME_ATTRIBUTE, (void*) NAME_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                if (r != *NUMBER_0_INTEGER) {

                                                    // Get source name.
                                                    *n = pv->content;
                                                    *nc = strlen((char*) *n);
                                                }
                                            }

                                            if (r == *NUMBER_0_INTEGER) {

                                                compare_arrays(p9, p10, (void*) CHANNEL_ATTRIBUTE, (void*) CHANNEL_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                if (r != *NUMBER_0_INTEGER) {

                                                    // Get source channel.
                                                    *c = pv->content;
                                                    *cc = strlen((char*) *c);
                                                }
                                            }

                                            if (r == *NUMBER_0_INTEGER) {

                                                compare_arrays(p9, p10, (void*) ABSTRACTION_ATTRIBUTE, (void*) ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                if (r != *NUMBER_0_INTEGER) {

                                                    // Get source abstraction.
                                                    *a = pv->content;
                                                    *ac = strlen((char*) *a);
                                                }
                                            }

                                            if (r == *NUMBER_0_INTEGER) {

                                                compare_arrays(p9, p10, (void*) MODEL_ATTRIBUTE, (void*) MODEL_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                if (r != *NUMBER_0_INTEGER) {

                                                    // Get source model.
                                                    *m = pv->content;
                                                    *mc = strlen((char*) *m);
                                                }
                                            }

                                        } else {

                                    //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source property value is null.");
                                        }
                                    } else {

//??                                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
                                    }

                                } else {

//??                                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
                                }

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
                            }

                        } else {

//??                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
                        }

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
    }
}

/**
 * Decodes the cybol properties.
 *
 * @param p0 the name
 * @param p1 the name count
 * @param p2 the channel
 * @param p3 the channel count
 * @param p4 the abstraction
 * @param p5 the abstraction count
 * @param p6 the model
 * @param p7 the model count
 * @param p8 the child node
 */
void decode_compound_cybol_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER) {

        xmlNode* cn = (xmlNode*) p8;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Decode compound cybol properties.");

        if (cn != *NULL_POINTER) {

            // Determine first child node property.
            xmlAttr* p = cn->properties;
            // The property name.
            void* pn = *NULL_POINTER;
            int pnc = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                if (p == *NULL_POINTER) {

                    break;
                }

                // Get property name.
                pn = (void*) p->name;
                pnc = strlen(pn);

                // Decode property.
                decode_compound_cybol_property(p0, p1, p2, p3, p4, p5, p6, p7, p->children, pn, (void*) &pnc);

                // Get next child node property.
                p = p->next;
            }

        } else {

    //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
    }
}

/**
 * Decodes the compound cybol node.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode*)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_compound_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER) {

        xmlNode* s = (xmlNode*) p3;

        if (p0 != *NULL_POINTER) {

            void** d = (void**) p0;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Decode compound cybol node.");

            // The source name, channel, abstraction, model.
            void* sn = *NULL_POINTER;
            int snc = *NUMBER_0_INTEGER;
            void* sc = *NULL_POINTER;
            int scc = *NUMBER_0_INTEGER;
            void* sa = *NULL_POINTER;
            int sac = *NUMBER_0_INTEGER;
            void* sm = *NULL_POINTER;
            int smc = *NUMBER_0_INTEGER;
            // The destination name, abstraction, model, details.
            void* dn = *NULL_POINTER;
            int* dnc = (int*) *NULL_POINTER;
            int* dns = (int*) *NULL_POINTER;
            void* da = *NULL_POINTER;
            int* dac = (int*) *NULL_POINTER;
            int* das = (int*) *NULL_POINTER;
            void* dm = *NULL_POINTER;
            int* dmc = (int*) *NULL_POINTER;
            int* dms = (int*) *NULL_POINTER;
            void* dd = *NULL_POINTER;
            int* ddc = (int*) *NULL_POINTER;
            int* dds = (int*) *NULL_POINTER;

            // Decode child node properties.
            decode_compound_cybol_properties((void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc, (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc, p3);

/*??
            fwprintf(stderr, L"sn: %s\n", (char*) sn);
            fwprintf(stderr, L"snc: %i\n", snc);
            fwprintf(stderr, L"sc: %s\n", (char*) sc);
            fwprintf(stderr, L"scc: %i\n", scc);
            fwprintf(stderr, L"sa: %s\n", (char*) sa);
            fwprintf(stderr, L"sac: %i\n", sac);
            fwprintf(stderr, L"sm: %s\n", (char*) sm);
            fwprintf(stderr, L"smc: %i\n", smc);
*/

            //
            // Name.
            //

            // Allocate destination name.
            allocate((void*) &dnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dnc = *NUMBER_0_INTEGER;
            allocate((void*) &dns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dns = *NUMBER_0_INTEGER;
            allocate((void*) &dn, (void*) dns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

            // Decode destination name.
            decode((void*) &dn, (void*) dnc, (void*) dns, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, sn, (void*) &snc, *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

            //
            // Channel.
            //
            // CAUTION! A (transient) destination channel is not created,
            // since that is only needed temporarily for model loading.
            //

            //
            // Abstraction.
            //

            // Allocate destination abstraction.
            allocate((void*) &dac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dac = *NUMBER_0_INTEGER;
            allocate((void*) &das, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *das = *NUMBER_0_INTEGER;
            allocate((void*) &da, (void*) das, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

            // Decode destination abstraction.
            decode((void*) &da, (void*) dac, (void*) das, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, sa, (void*) &sac, *NULL_POINTER, *NULL_POINTER, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

            //
            // Model.
            //

            // The workaround flags for channel- and abstraction comparison.
            // If these are set, the libxml2 parser is used.
            int w1 = *NUMBER_0_INTEGER;
            int w2 = *NUMBER_0_INTEGER;

            compare_arrays(sc, (void*) &scc, (void*) FILE_CHANNEL, (void*) FILE_CHANNEL_COUNT, (void*) &w1, (void*) CHARACTER_ARRAY);
            // CAUTION! Use the original source abstraction and NOT the mapped runtime memory abstraction here!
            // This is necessary because not only the CYBOL abstraction is mapped to COMPOUND,
            // but also other abstractions like XDT are.
            compare_arrays(sa, (void*) &sac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &w2, (void*) CHARACTER_ARRAY);

            if ((w1 != *NUMBER_0_INTEGER) && (w2 != *NUMBER_0_INTEGER)) {

                // Allocate destination model.
                allocate((void*) &dmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dmc = *NUMBER_0_INTEGER;
                allocate((void*) &dms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dms = *NUMBER_0_INTEGER;
                allocate((void*) &dm, (void*) dms, sa, (void*) &sac);

                // CAUTION! If a cybol file is to be read, then the libxml2 parser is used.
                // This is just a workaround, until cyboi posesses its own cybol parsing functions.
                // This source code block can then be deleted completely.
                decode((void*) &dm, (void*) dmc, (void*) dms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, sm, (void*) &smc, *NULL_POINTER, *NULL_POINTER, sa, (void*) &sac);

            } else {

                // The runtime abstraction.
                void* ra = *NULL_POINTER;
                int rac = *NUMBER_0_INTEGER;

                // Decode source abstraction into runtime abstraction, since a decoded
                // message does not always have the same runtime abstraction.
                // For example, an "xdt" file is converted into a compound.
                decode_abstraction((void*) &ra, (void*) &rac, *NULL_POINTER, sa, (void*) &sac);

                // The read model.
                void* rm = *NULL_POINTER;
                int rmc = *NUMBER_0_INTEGER;
                int rms = *NUMBER_0_INTEGER;

                // Allocate read model of type character, to read single bytes.
                allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Read read model as persistent byte stream over channel.
                read_data((void*) &rm, (void*) &rmc, (void*) &rms, sm, (void*) &smc, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, sc, (void*) &scc);

                // Allocate destination model.
                allocate((void*) &dmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dmc = *NUMBER_0_INTEGER;
                allocate((void*) &dms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dms = *NUMBER_0_INTEGER;
                allocate((void*) &dm, (void*) dms, ra, (void*) &rac);

                // Decode destination model.
                //
                // CAUTION! Use the original source abstraction and NOT the mapped runtime memory abstraction here!
                // This is necessary so that the correct parsing function is called.
                decode((void*) &dm, (void*) dmc, (void*) dms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, rm, (void*) &rmc, *NULL_POINTER, *NULL_POINTER, sa, (void*) &sac);

                // Deallocate read model.
                deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            }

            //
            // Details.
            //

            // Allocate and decode destination details.
            //
            // CAUTION! Do ALWAYS allocate the details, even if it has no entries!
            // This is because at runtime, properties may be assigned to the details.
            // So, it MUST NOT be null.
            allocate((void*) &ddc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *ddc = *NUMBER_0_INTEGER;
            allocate((void*) &dds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            *dds = *NUMBER_0_INTEGER;
            allocate((void*) &dd, (void*) dds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

            // If child node has children, then decode it for destination details.
            if (s->children != *NULL_POINTER) {

                // Decode destination details child node children.
                decode_compound_cybol_nodes((void*) &dd, (void*) ddc, (void*) dds, p3, p4);
            }

            // Add model to compound.
            set_compound_element_by_name(*d, p1, p2,
                dn, (void*) dnc, (void*) dns,
                da, (void*) dac, (void*) das,
                dm, (void*) dmc, (void*) dms,
                dd, (void*) ddc, (void*) dds);

            //?? CAUTION! TODO:
            //?? If "add", then first check if name exists in whole;
            //?? if yes, add "_0" or "_1" or "_2" etc.
            //?? to name, taking first non-existing suffix!
            //?? If "set", then just replace the model
            //?? with equal name.
            //?? PROBLEM: Where to destroy the model if
            //?? no whole keeps a reference to it anymore?

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode compound cybol node. The destination compound is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode compound cybol node. The source xml node is null.");
    }
}

/**
 * Decodes the compound cybol node.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode*)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_compound_cybol_nodes(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER) {

        xmlNode* s = (xmlNode*) p3;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Decode compound cybol nodes.");

        // Determine first child node.
        xmlNode* c = s->children;
        // The child count.
        int cc = *NUMBER_0_INTEGER;

        while (*NUMBER_1_INTEGER) {

            if (c == *NULL_POINTER) {

                break;
            }

            if (c->type == XML_ELEMENT_NODE) {

                decode_compound_cybol_node(p0, p1, p2, (void*) c, (void*) &cc);
            }

            c = c->next;
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode compound cybol nodes. The source xml node is null.");
    }
}

/**
 * Decodes the byte stream and creates an xml model from it.
 *
 * CAUTION! This function is a temporary WORKAROUND, to be used until CYBOL-specific
 * parsing functions are written! CYBOL is completely XML-conform, with one exception:
 * XML attributes will not just be demarcated by "", but some special characters which
 * identify the beginning and end of an attribute value. It is not decided yet which
 * character sequence to use, but it might be something like e.g.:
 * attribute="@CYBOLBEGIN@here_comes_the_actual_value@CYBOLEND@"
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source xml file name
 * @param p4 the source count
 */
void decode_compound_libxml2_parser_workaround(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                // Following is a special check to avoid:
                // I/O warning : failed to load external entity ""
                // messages of the xml parser.
                if (*sc > *NUMBER_0_INTEGER) {

                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) L"Decode compound libxml2 parser workaround.");

                    // The temporary null-terminated file name.
                    void* tmp = *NULL_POINTER;
                    int tmps = *sc + *NUMBER_1_INTEGER;

                    // Create temporary null-terminated file name.
                    allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

                    // Set terminated file name by first copying the actual name
                    // and then adding the null termination character.
                    set_array_elements(tmp, (void*) NUMBER_0_INTEGER, p3, p4, (void*) CHARACTER_ARRAY);
                    set_array_elements(tmp, p4, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);

                    // Initialise the library.
                    // Check potential ABI mismatches between the version
                    // it was compiled for and the actual shared library used.
                    LIBXML_TEST_VERSION

                    // Decode file and get xml document.
                    // This function returns a pointer to type: xmlDoc*
                    xmlDoc* doc = (void*) xmlParseFile((char*) tmp);

                    // Free global variables that may have been allocated by the parser.
                    xmlCleanupParser();

                    // Destroy temporary null-terminated file name.
                    deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_ARRAY);

                    // Get root element node.
                    xmlNode* r = xmlDocGetRootElement(doc);

                    // Decode cybol.
                    decode_compound_cybol_nodes(p0, p1, p2, (void*) r, *NULL_POINTER);

                    if (doc != *NULL_POINTER) {

                        // Deallocate xml dom document.
                        //
                        // CAUTION! This has to be done only AFTER parsing the document nodes!
                        // Otherwise, the document would not exist anymore, so that no nodes could be found.
//??                        xmlFreeDoc((xmlDoc*) *((void**) *d));
                        xmlFreeDoc(doc);

                    } else {

                        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) L"Could not deallocate xml document. Probably, the given cybol file name was empty.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode xml. The file name count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode xml. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode xml. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode xml. The source count is null.");
    }
}

/**
 * Decodes the byte stream message and creates a compound from it.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source message
 * @param p4 the source message count
 */
void decode_compound(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode compound.");

    decode_compound_libxml2_parser_workaround(p0, p1, p2, p3, p4);

/*??
    // The comparison result.
    int* r = (int*) *NULL_POINTER;
    allocate((void*) &r, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *r = *NUMBER_0_INTEGER;
    // The current byte within the stream.
    void* b = *s;
    // The remaining bytes count.
    int bc = *sc;

    while (*NUMBER_1_INTEGER) {

        if (bc <= *NUMBER_0_INTEGER) {

            break;
        }

        //
        // Zero decode/parse mode.
        //
        // CAUTION!
        // The order of comparisons is important.
        // Comment tags have to be found before other tags.
        // Otherwise, a comment tag is treated wrongly as normal tag.
        //

        if (d == *NUMBER_0_INTEGER) {

            if (bc >= BEGIN_COMMENT_TAG_COUNT) {

                compare_array_elements((void*) &b, (void*) &BEGIN_COMMENT_TAG, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_COMMENT_TAG_COUNT, (void*) &r);

                if (r != *NUMBER_0_INTEGER) {

                    // Move current byte pointer
                    // and remaining bytes count.
                    b = b + BEGIN_COMMENT_TAG_COUNT;
                    bc = bc - BEGIN_COMMENT_TAG_COUNT;

                    // Decode xml comment tag.
                    decode_xml_comment_tag((void*) &b, (void*) &bc);
                }
            }
        }

        if (d == *NUMBER_0_INTEGER) {

            if (bc >= BEGIN_TAG_BEGIN_COUNT) {

                compare_array_elements((void*) &b, (void*) &BEGIN_TAG_BEGIN, (void*) &CHARACTER_ARRAY, (void*) &BEGIN_TAG_BEGIN_COUNT, (void*) &r);

                if (r != *NUMBER_0_INTEGER) {

                    // Move current byte pointer
                    // and remaining bytes count.
                    b = b + BEGIN_TAG_BEGIN_COUNT;
                    bc = bc - BEGIN_TAG_BEGIN_COUNT;

                    // Initialise xml tag.
                    void* t = *NULL_POINTER;
                    int tc = *NUMBER_0_INTEGER;
                    int ts = *NUMBER_0_INTEGER;

                    // Exceptionally do NOT create and add a new xml tag.
                    // The first tag of an xml file is the root tag.
                    // The corresponding transient xml root tag model
                    // to be used was already handed over to this procedure.
                    // So, use this model instead of creating a new one!
                    // For any other part tags of root, however,
                    // new transient xml tag models have to be created!

                    // Create xml tag.
//??                    allocate_xml_tag((void*) &t, (void*) &ts);

                    // Decode xml tag.
                    decode_xml_tag((void*) &t, (void*) &tc, (void*) &ts,
                        (void*) &b, (void*) &bc);

                    //?? Exit sub procedure above when end tag is reached!

                    // Add xml tag.
//??                    add_xml_tag();
                }
            }
        }

        // If this block is reached, then no known term was found before.
        // The current byte pointer will just be incremented by one so
        // that new characters are read and compared in the next loop cycle.
        if (d == *NUMBER_0_INTEGER) {

            // Increment current byte within persistent model.
            b++;
            // Decrement remaining bytes count.
            bc--;
        }

        // Reset comparison result.
        *r = *NUMBER_0_INTEGER;
    }
*/
}

/**
 * Encodes the compound into a byte stream message.
 *
 * @param p0 the destination message (Hand over as reference!)
 * @param p1 the destination message count
 * @param p2 the destination message size
 * @param p3 the source compound
 * @param p4 the source compound count
 */
void encode_compound(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Encode compound.");
}

/* COMPOUND_CONVERTER_SOURCE */
#endif
