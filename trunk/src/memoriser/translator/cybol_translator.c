/*
 * $RCSfile: cybol_translator.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.18 $ $Date: 2007-05-01 19:07:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_TRANSLATOR_SOURCE
#define CYBOL_TRANSLATOR_SOURCE

#include <string.h>
#include <libxml/tree.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

//
// Forward declarations.
//

/**
 * Receives and creates a transient destination model
 * from a persistent source model.
 *
 * Primitive models need to be handled differently than compound models.
 *
 * persistent:
 * - stored permanently
 * - outside CYBOI
 * - longer than CYBOI lives
 *
 * transient:
 * - stored in computer memory (RAM)
 * - only accessible from within CYBOI
 * - created and destroyed by CYBOI
 * - not available anymore after CYBOI has been destroyed
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source model
 * @param p7 the source model count
 * @param p8 the source abstraction
 * @param p9 the source abstraction count
 * @param p10 the source channel
 * @param p11 the source channel count
 */
void receive_file_system_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

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

//
// Cybol property.
//

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
void decode_cybol_property(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != NULL_POINTER) {

        xmlNode* cn = (xmlNode*) p8;

        if (p7 != NULL_POINTER) {

            int* mc = (int*) p7;

            if (p6 != NULL_POINTER) {

                void** m = (void**) p6;

                if (p5 != NULL_POINTER) {

                    int* ac = (int*) p5;

                    if (p4 != NULL_POINTER) {

                        void** a = (void**) p4;

                        if (p3 != NULL_POINTER) {

                            int* cc = (int*) p3;

                            if (p2 != NULL_POINTER) {

                                void** c = (void**) p2;

                                if (p1 != NULL_POINTER) {

                                    int* nc = (int*) p1;

                                    if (p0 != NULL_POINTER) {

                                        void** n = (void**) p0;

                                        log_message_debug("Decode cybol property.");

                                        if (cn != NULL_POINTER) {

                                            // Determine first child node property.
                                            xmlAttr* p = cn->properties;
                                            // The property name.
                                            void* pn = NULL_POINTER;
                                            int pnc = *NUMBER_0_INTEGER;
                                            // The property value.
                                            xmlNode* pv = NULL_POINTER;
                                            // The comparison result.
                                            int r = *NUMBER_0_INTEGER;

                                            while (*NUMBER_1_INTEGER) {

                                                if (p == NULL_POINTER) {

                                                    break;
                                                }

                                                // Get property value.
                                                pv = p->children;

                                                if (pv != NULL_POINTER) {

                                                    // Get property name.
                                                    pn = (void*) p->name;
                                                    pnc = strlen(pn);

                                                    if (r != 1) {

                                                        compare_arrays(pn, (void*) &pnc, (void*) NAME_ATTRIBUTE, (void*) NAME_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                        if (r == *NUMBER_1_INTEGER) {

                                                            // Get source name.
                                                            *n = pv->content;
                                                            *nc = strlen((char*) *n);
                                                        }
                                                    }

                                                    if (r != *NUMBER_1_INTEGER) {

                                                        compare_arrays(pn, (void*) &pnc, (void*) CHANNEL_ATTRIBUTE, (void*) CHANNEL_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                        if (r == *NUMBER_1_INTEGER) {

                                                            // Get source channel.
                                                            *c = pv->content;
                                                            *cc = strlen((char*) *c);
                                                        }
                                                    }

                                                    if (r != *NUMBER_1_INTEGER) {

                                                        compare_arrays(pn, (void*) &pnc, (void*) ABSTRACTION_ATTRIBUTE, (void*) ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                        if (r == *NUMBER_1_INTEGER) {

                                                            // Get source abstraction.
                                                            *a = pv->content;
                                                            *ac = strlen((char*) *a);
                                                        }
                                                    }

                                                    if (r != *NUMBER_1_INTEGER) {

                                                        compare_arrays(pn, (void*) &pnc, (void*) MODEL_ATTRIBUTE, (void*) MODEL_ATTRIBUTE_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                                                        if (r == *NUMBER_1_INTEGER) {

                                                            // Get source model.
                                                            *m = pv->content;
                                                            *mc = strlen((char*) *m);
                                                        }
                                                    }

                                                    // Reset property name.
                                                    pn = NULL_POINTER;
                                                    pnc = *NUMBER_0_INTEGER;
                                                    // Reset property value.
                                                    pv = NULL_POINTER;
                                                    // Reset comparison result.
                                                    r = *NUMBER_0_INTEGER;

                                                } else {

                                            //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source property value is null.");
                                                }

                                                p = p->next;
                                            }

                                        } else {

//??                                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
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
 * Encodes the cybol properties.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_cybol_property(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

//
// Cybol node.
//

/**
 * Decodes the cybol node into a compound.
 *
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode**)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != NULL_POINTER) {

        xmlNode* s = (xmlNode*) p3;

        if (p0 != NULL_POINTER) {

            void** d = (void**) p0;

            log_message_debug("Decode cybol node.");

            // Determine first child node.
            xmlNode* c = s->children;
            // The child count.
            int cc = *NUMBER_0_INTEGER;
            // The source name.
            void* sn = NULL_POINTER;
            int snc = *NUMBER_0_INTEGER;
            // The source channel.
            void* sc = NULL_POINTER;
            int scc = *NUMBER_0_INTEGER;
            // The source abstraction.
            void* sa = NULL_POINTER;
            int sac = *NUMBER_0_INTEGER;
            // The source model.
            void* sm = NULL_POINTER;
            int smc = *NUMBER_0_INTEGER;
            // The destination name.
            void* dn = NULL_POINTER;
            int* dnc = NULL_POINTER;
            int* dns = NULL_POINTER;
            // The destination abstraction.
            void* da = NULL_POINTER;
            int* dac = NULL_POINTER;
            int* das = NULL_POINTER;
            // The destination model.
            void* dm = NULL_POINTER;
            int* dmc = NULL_POINTER;
            int* dms = NULL_POINTER;
            // The destination details.
            void* dd = NULL_POINTER;
            int* ddc = NULL_POINTER;
            int* dds = NULL_POINTER;

            while (*NUMBER_1_INTEGER) {

                if (c == NULL_POINTER) {

                    break;
                }

                if (c->type == XML_ELEMENT_NODE) {

                    // Decode child node properties.
                    decode_cybol_property(
                        (void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc,
                        (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc,
                        (void*) c);

//??        fprintf(stderr, "sn: %s\n", (char*) sn);
//??        fprintf(stderr, "snc: %i\n", *((int*) snc));
//??        fprintf(stderr, "sc: %s\n", (char*) sc);
//??        fprintf(stderr, "scc: %i\n", *((int*) scc));
//??        fprintf(stderr, "sa: %s\n", (char*) sa);
//??        fprintf(stderr, "sac: %i\n", *((int*) sac));
//??        fprintf(stderr, "sm: %s\n", (char*) sm);
//??        fprintf(stderr, "smc: %i\n", *((int*) smc));

                    // Create destination name.
                    allocate((void*) &dnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dnc = *NUMBER_0_INTEGER;
                    allocate((void*) &dns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dns = *NUMBER_0_INTEGER;
                    receive_file_system_model((void*) &dn, (void*) dnc, (void*) dns,
                        NULL_POINTER, NULL_POINTER, NULL_POINTER,
                        sn, (void*) &snc,
                        (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                        (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

                    // CAUTION! A (transient) destination channel is not created,
                    // since that is only needed temporarily for model loading.

                    // Create destination abstraction.
                    allocate((void*) &dac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dac = *NUMBER_0_INTEGER;
                    allocate((void*) &das, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *das = *NUMBER_0_INTEGER;
                    receive_file_system_model((void*) &da, (void*) dac, (void*) das,
                        NULL_POINTER, NULL_POINTER, NULL_POINTER,
                        sa, (void*) &sac,
                        (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                        (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

                    // Create destination model.
                    allocate((void*) &dmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dmc = *NUMBER_0_INTEGER;
                    allocate((void*) &dms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dms = *NUMBER_0_INTEGER;
                    receive_file_system_model((void*) &dm, (void*) dmc, (void*) dms,
                        NULL_POINTER, NULL_POINTER, NULL_POINTER,
                        sm, (void*) &smc,
                        sa, (void*) &sac,
                        sc, (void*) &scc);

                    // Create details model.
                    //
                    // CAUTION! Do ALWAYS allocate the details, even if it has no entries!
                    // This is because at runtime, properties may be assigned to the details
                    // so that it MUST NOT be null.
                    allocate((void*) &ddc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *ddc = *NUMBER_0_INTEGER;
                    allocate((void*) &dds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                    *dds = *NUMBER_0_INTEGER;
                    allocate((void*) &dd, (void*) dds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

                    // If child node has children, then create details model for it.
                    if (c->children != NULL_POINTER) {

                        // Decode child node children.
                        decode_cybol_node((void*) &dd, (void*) ddc, (void*) dds, (void*) c, (void*) &cc);
                    }

                    // Add model to compound.
                    set_compound_element_by_name(*d, p1, p2,
                        dn, (void*) dnc, (void*) dns,
                        da, (void*) dac, (void*) das,
                        dm, (void*) dmc, (void*) dms,
                        dd, (void*) ddc, (void*) dds);

                    //?? If "add", then first check if name exists in whole;
                    //?? if yes, add "_0" or "_1" or "_2" etc.
                    //?? to name, taking first non-existing suffix!
                    //?? If "set", then just replace the model
                    //?? with equal name; but where to destroy it if
                    //?? no whole keeps a reference to it anymore?

                    // Reset source name.
                    sn = NULL_POINTER;
                    snc = *NUMBER_0_INTEGER;
                    // Reset source channel.
                    sc = NULL_POINTER;
                    scc = *NUMBER_0_INTEGER;
                    // Reset source abstraction.
                    sa = NULL_POINTER;
                    sac = *NUMBER_0_INTEGER;
                    // Reset source model.
                    sm = NULL_POINTER;
                    smc = *NUMBER_0_INTEGER;
                    // Reset destination name.
                    dn = NULL_POINTER;
                    dnc = NULL_POINTER;
                    dns = NULL_POINTER;
                    // Reset destination abstraction.
                    da = NULL_POINTER;
                    dac = NULL_POINTER;
                    das = NULL_POINTER;
                    // Reset destination model.
                    dm = NULL_POINTER;
                    dmc = NULL_POINTER;
                    dms = NULL_POINTER;
                    // Reset destination details.
                    dd = NULL_POINTER;
                    ddc = NULL_POINTER;
                    dds = NULL_POINTER;
                }

                c = c->next;
            }

        } else {

            log_message_debug("Error: Could not decode cybol node. The destination compound is null.");
        }

    } else {

        log_message_debug("Error: Could not decode cybol node. The source xml node is null.");
    }
}

/**
 * Encodes the compound into a cybol node.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_cybol_node(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

//
// Cybol model.
//

/**
 * Decodes the cybol model into a compound.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_cybol(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //?? BEGIN of temporary workaround for using the libxml2 parser.
    //?? The strings contained in the xml tree are terminated by a null character
    //?? which must be deleted for the cyboi model,
    //?? or neglected in the "count" number!

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                log_message_debug("Decode cybol.");

                // Get root element node.
                xmlNode* r = xmlDocGetRootElement((xmlDoc*) p3);

                decode_cybol_node(p0, p1, p2, (void*) r, p4);

            } else {

                log_message_debug("Could not decode cybol. The destination is null.");
            }

        } else {

            log_message_debug("Could not decode cybol. The source is null.");
        }

    } else {

        log_message_debug("Could not decode cybol. The source count is null.");
    }

    //?? END of temporary workaround for using the libxml2 parser.
}

/**
 * Encodes the compound into a cybol model.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_cybol(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* CYBOL_TRANSLATOR_SOURCE */
#endif
