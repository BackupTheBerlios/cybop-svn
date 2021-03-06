/*
 * $RCSfile: cybol_translator.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.2 $ $Date: 2004-09-12 18:51:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_TRANSLATOR_SOURCE
#define CYBOL_TRANSLATOR_SOURCE

#include <libxml/tree.h>
#include <string.h>
#include "../array/array.c"
#include "../creator/compound_creator.c"
#include "../creator/xml_node_creator.c"
#include "../creator/xml_property_creator.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/character_constants.c"
#include "../global/cybol_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

//
// Forward declarations.
//

/**
 * Creates a model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8);

//
// Cybol property.
//

/**
 * Decodes the cybol properties.
 *
 * @param p0 the child node
 * @param p1 the name
 * @param p2 the name count
 * @param p3 the channel
 * @param p4 the channel count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 * @param p7 the model
 * @param p8 the model count
 */
void decode_cybol_property(const void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != NULL_POINTER) {

        int* mc = (int*) p8;

        if (p7 != NULL_POINTER) {

            void** m = (void**) p7;

            if (p6 != NULL_POINTER) {

                int* ac = (int*) p6;

                if (p5 != NULL_POINTER) {

                    void** a = (void**) p5;

                    if (p4 != NULL_POINTER) {

                        int* cc = (int*) p4;

                        if (p3 != NULL_POINTER) {

                            void** c = (void**) p3;

                            if (p2 != NULL_POINTER) {

                                int* nc = (int*) p2;

                                if (p1 != NULL_POINTER) {

                                    void** n = (void**) p1;

                                    if (p0 != NULL_POINTER) {

                                        xmlNode** cn = (xmlNode**) p0;

                                        if ((*cn) != NULL_POINTER) {

                                            // Determine first child node property.
                                            xmlAttr* p = (*cn)->properties;
                                            // The property name.
                                            char* pn = NULL_POINTER;
                                            int pnc = 0;
                                            // The property value.
                                            xmlNode* pv = NULL_POINTER;

                                            // The done flag.
                                            int d = 0;
                                            // The comparison result.
                                            int r = 0;

                                            while (1) {

                                                if (p == NULL_POINTER) {

                                                    break;
                                                }

                                                // Get property value.
                                                pv = p->children;

                                                if (pv != NULL_POINTER) {

                                                    // Get property name.
                                                    pn = (char*) p->name;
                                                    pnc = strlen(pn);

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &NAME_ATTRIBUTE, (void*) &NAME_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (r == 1) {

                                                            // Get source name.
                                                            *n = pv->content;
                                                            *nc = strlen((char*) *n);

                                                            d = 1;
                                                        }
                                                    }

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &CHANNEL_ATTRIBUTE, (void*) &CHANNEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (r == 1) {

                                                            // Get source channel.
                                                            *c = pv->content;
                                                            *cc = strlen((char*) *c);

                                                            d = 1;
                                                        }
                                                    }

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &ABSTRACTION_ATTRIBUTE, (void*) &ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (r == 1) {

                                                            // Get source abstraction.
                                                            *a = pv->content;
                                                            *ac = strlen((char*) *a);

                                                            d = 1;
                                                        }
                                                    }

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &MODEL_ATTRIBUTE, (void*) &MODEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (r == 1) {

                                                            // Get source model.
                                                            *m = pv->content;
                                                            *mc = strlen((char*) *m);

                                                            d = 1;
                                                        }
                                                    }

                                                    // Reset property name.
                                                    pn = NULL_POINTER;
                                                    pnc = 0;
                                                    // Reset property value.
                                                    pv = NULL_POINTER;
                                                    // Reset done flag.
                                                    d = 0;
                                                    // Reset comparison result.
                                                    r = 0;

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
void encode_cybol_property(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

//
// Cybol node.
//

/**
 * Decodes the cybol node into a compound.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_cybol_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            xmlNode** s = (xmlNode**) p3;

            if ((*s) != NULL_POINTER) {

                // Determine first child node.
                xmlNode* c = (*s)->children;
                int cc = 0;

                // The source name.
                void* sn = NULL_POINTER;
                int snc = 0;
                // The source channel.
                void* sc = NULL_POINTER;
                int scc = 0;
                // The source abstraction.
                void* sa = NULL_POINTER;
                int sac = 0;
                // The source model.
                void* sm = NULL_POINTER;
                int smc = 0;

                // The destination name.
                void* dn = NULL_POINTER;
                int dnc = 0;
                int dns = 0;
                // The destination abstraction.
                void* da = NULL_POINTER;
                int dac = 0;
                int das = 0;
                // The destination model.
                void* dm = NULL_POINTER;
                int dmc = 0;
                int dms = 0;
                // The destination details.
                void* dd = NULL_POINTER;
                int ddc = 0;
                int dds = 0;

                while (1) {

                    if (c == NULL_POINTER) {

                        break;
                    }

                    if (c->type == XML_ELEMENT_NODE) {

                        // Decode child node properties.
                        decode_cybol_property((void*) &c,
                            (void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc,
                            (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc);

                        // Create destination name.
                        create_model((void*) &dn, (void*) &dnc, (void*) &dns,
                            (void*) &sn, (void*) &snc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                            (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

                        // CAUTION! A (transient) destination channel is not created,
                        // since that is only needed temporarily for model loading.

                        // Create destination abstraction.
                        create_model((void*) &da, (void*) &dac, (void*) &das,
                            (void*) &sa, (void*) &sac,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                            (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);

                        // Create destination model.
                        create_model((void*) &dm, (void*) &dmc, (void*) &dms,
                            (void*) &sm, (void*) &smc,
                            (void*) &sa, (void*) &sac,
                            (void*) &sc, (void*) &scc);

                        // If child node has children, then create details model for it.
                        if (c->children != NULL_POINTER) {

                            // Create details model.
                            create((void*) &dd, (void*) &dds,
                                (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);

                            // Decode child node children.
                            decode_cybol_node((void*) &dd, (void*) &ddc, (void*) &dds,
                                (void*) &c, (void*) &cc);

                            //?? Read details??
                            // Filter out all tags with name attribute value "super" and
                            // hand over model to create parts of super model.
                            // Add all details to details model.
                            // Do NOT add super tags to details model!
                        }

                        // Add model to compound.
                        set_compound_element_by_name(p0, p1, p2,
                            (void*) &dn, (void*) &dnc, (void*) &dns,
                            (void*) &da, (void*) &dac, (void*) &das,
                            (void*) &dm, (void*) &dmc, (void*) &dms,
                            (void*) &dd, (void*) &ddc, (void*) &dds);

                        //?? If "add", then first check if name exists in whole;
                        //?? if yes, add "_0" or "_1" or "_2" etc.
                        //?? to name, taking first non-existing suffix!
                        //?? If "set", then just replace the model
                        //?? with equal name; but where to destroy it if
                        //?? no whole keeps a reference to it anymore?

                        // Reset source name.
                        sn = NULL_POINTER;
                        snc = 0;
                        // Reset source channel.
                        sc = NULL_POINTER;
                        scc = 0;
                        // Reset source abstraction.
                        sa = NULL_POINTER;
                        sac = 0;
                        // Reset source model.
                        sm = NULL_POINTER;
                        smc = 0;

                        // Reset destination name.
                        dn = NULL_POINTER;
                        dnc = 0;
                        dns = 0;
                        // Reset destination abstraction.
                        da = NULL_POINTER;
                        dac = 0;
                        das = 0;
                        // Reset destination model.
                        dm = NULL_POINTER;
                        dmc = 0;
                        dms = 0;
                        // Reset destination details.
                        dd = NULL_POINTER;
                        ddc = 0;
                        dds = 0;
                    }

                    c = c->next;
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter count is null.");
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
void encode_cybol_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

//
// Cybol model.
//

/**
 * Decodes the cybol model into a compound.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_cybol(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //??
    //?? BEGIN of temporary workaround for using the libxml2 parser.
    //?? The strings contained in the xml tree are terminated by a null character
    //?? which must be deleted for the cyboi model,
    //?? or neglected in the "count" number!
    //??

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                // Get root element node.
                xmlNode* r = xmlDocGetRootElement((xmlDoc*) *s);

                decode_cybol_node(p0, p1, p2, (void*) &r, p4);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The destination is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The source is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml. The source count is null.");
    }

    //??
    //?? END of temporary workaround for using the libxml2 parser.
    //??
}

/**
 * Encodes the compound into a cybol model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_cybol(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/* CYBOL_TRANSLATOR_SOURCE */
#endif
