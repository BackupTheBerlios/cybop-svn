/*
 * $RCSfile: configuration_translator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.2 $ $Date: 2005-01-06 17:21:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONFIGURATION_TRANSLATOR_SOURCE
#define CONFIGURATION_TRANSLATOR_SOURCE

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
#include "../test/test.c"

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

        int** mc = (int**) p8;

        if (p7 != NULL_POINTER) {

            void** m = (void**) p7;

            if (p6 != NULL_POINTER) {

                int** ac = (int**) p6;

                if (p5 != NULL_POINTER) {

                    void** a = (void**) p5;

                    if (p4 != NULL_POINTER) {

                        int** cc = (int**) p4;

                        if (p3 != NULL_POINTER) {

                            void** c = (void**) p3;

                            if (p2 != NULL_POINTER) {

                                int** nc = (int**) p2;

                                if (p1 != NULL_POINTER) {

                                    void** n = (void**) p1;

                                    if (p0 != NULL_POINTER) {

                                        xmlNode** cn = (xmlNode**) p0;

                                        if ((*cn) != NULL_POINTER) {

                                            // Determine first child node property.
                                            xmlAttr* p = (*cn)->properties;
                                            // The property name.
                                            char* pn = NULL_POINTER;
                                            // The property name count.
                                            int* pnc = INTEGER_NULL_POINTER;
                                            create_integer((void*) &pnc);
                                            *pnc = 0;
                                            // The property value.
                                            xmlNode* pv = NULL_POINTER;
                                            // The done flag.
                                            int d = 0;
                                            // The comparison result.
                                            int* r = INTEGER_NULL_POINTER;
                                            create_integer((void*) &r);
                                            *r = 0;

                                            while (1) {

                                                if (p == NULL_POINTER) {

                                                    break;
                                                }

                                                // Get property value.
                                                pv = p->children;

                                                if (pv != NULL_POINTER) {

                                                    // Get property name.
                                                    pn = (char*) p->name;
                                                    *pnc = strlen(pn);

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &NAME_ATTRIBUTE, (void*) &NAME_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (*r == 1) {

                                                            // Get source name.
                                                            *n = pv->content;
                                                            **nc = strlen((char*) *n);

                                                            d = 1;
                                                        }
                                                    }

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &CHANNEL_ATTRIBUTE, (void*) &CHANNEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (*r == 1) {

                                                            // Get source channel.
                                                            *c = pv->content;
                                                            **cc = strlen((char*) *c);

                                                            d = 1;
                                                        }
                                                    }

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &ABSTRACTION_ATTRIBUTE, (void*) &ABSTRACTION_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (*r == 1) {

                                                            // Get source abstraction.
                                                            *a = pv->content;
                                                            **ac = strlen((char*) *a);

                                                            d = 1;
                                                        }
                                                    }

                                                    if (d == 0) {

                                                        compare_arrays((void*) &pn, (void*) &pnc, (void*) &MODEL_ATTRIBUTE, (void*) &MODEL_ATTRIBUTE_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                                                        if (*r == 1) {

                                                            // Get source model.
                                                            *m = pv->content;
                                                            **mc = strlen((char*) *m);

                                                            d = 1;
                                                        }
                                                    }

                                                    // Reset property name.
                                                    pn = NULL_POINTER;
                                                    *pnc = 0;
                                                    // Reset property value.
                                                    pv = NULL_POINTER;
                                                    // Reset done flag.
                                                    d = 0;
                                                    // Reset comparison result.
                                                    *r = 0;

                                                } else {

                                            //??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source property value is null.");
                                                }

                                                p = p->next;
                                            }

                                            destroy_integer((void*) &r);
                                            destroy_integer((void*) &pnc);

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
 * @param p0 the destination (a compound model void**)
 * @param p1 the destination count (the count for coumpound model void*)
 * @param p2 the destination size (the size for compound model void*)
 * @param p3 the source (xmlNode**)
 * @param p4 the source count (for this function not relevant void*)
 */
void decode_cybol_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p3 != NULL_POINTER) {

        xmlNode** s = (xmlNode**) p3;

        if ((*s) != NULL_POINTER) {

            // Determine first child node.
            xmlNode* c = (*s)->children;

            // The child count.
            int* cc = INTEGER_NULL_POINTER;
            create_integer((void*) &cc);
            *cc = 0;

            // The source name.
            void* sn = NULL_POINTER;
            int* snc = INTEGER_NULL_POINTER;
            create_integer((void*) &snc);
            *snc = 0;
            // The source channel.
            void* sc = NULL_POINTER;
            int* scc = INTEGER_NULL_POINTER;
            create_integer((void*) &scc);
            *scc = 0;
            // The source abstraction.
            void* sa = NULL_POINTER;
            int* sac = INTEGER_NULL_POINTER;
            create_integer((void*) &sac);
            *sac = 0;
            // The source model.
            void* sm = NULL_POINTER;
            int* smc = INTEGER_NULL_POINTER;
            create_integer((void*) &smc);
            *smc = 0;

            // The destination name.
            void* dn = NULL_POINTER;
            void* dnc = NULL_POINTER;
            void* dns = NULL_POINTER;
            // The destination abstraction.
            void* da = NULL_POINTER;
            void* dac = NULL_POINTER;
            void* das = NULL_POINTER;
            // The destination model.
            void* dm = NULL_POINTER;
            void* dmc = NULL_POINTER;
            void* dms = NULL_POINTER;
            // The destination details.
            void* dd = NULL_POINTER;
            void* ddc = NULL_POINTER;
            void* dds = NULL_POINTER;

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
                    *snc = 0;
                    // Reset source channel.
                    sc = NULL_POINTER;
                    *scc = 0;
                    // Reset source abstraction.
                    sa = NULL_POINTER;
                    *sac = 0;
                    // Reset source model.
                    sm = NULL_POINTER;
                    *smc = 0;

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

            destroy_integer((void*) &smc);
            destroy_integer((void*) &sac);
            destroy_integer((void*) &scc);
            destroy_integer((void*) &snc);
            destroy_integer((void*) &cc);

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not translate xml node. The source parameter is null.");
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

=== begin ============================

/**
 * set the internals for the section start
 *
 * @param root_element      pointer of the xmlNode
 * @param pp_internal       pointer of die internals
 * @return                  error code
 */
void initialize_internals_start(xmlNode* root_element, void** pp_internal) {

    if ( root_element == NULL_POINTER ) {

        log_message_debug("root_element is a NULL POINTER" );
        return -2;
    }
    else if ( pp_internal == NULL_POINTER ) {

        log_message_debug("pp_internal is a NULL POINTER" );
        return -3;
    }
    else {

        xmlNode* cur_node = NULL;

        for (cur_node = root_element; cur_node; cur_node = cur_node->next) {

            /* jeden Part durchgehen */
            if (cur_node->type == XML_ELEMENT_NODE) {

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
                decode_cybol_property( (void*) &cur_node,
                                       (void*) &sn, (void*) &snc,
                                       (void*) &sc, (void*) &scc,
                                       (void*) &sa, (void*) &sac,
                                       (void*) &sm, (void*) &smc );

                int r;

                //channel
                r = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CHANNEL_NAME_ABSTRACTION,
                                (void*) &CHANNEL_NAME_ABSTRACTION_COUNT,
                                (void*) &r, (void*) &CHARACTER_ARRAY);

                if ( r==1 ) {

                    log_message_debug( "Modellvalue channel gefunden" );

                    //create the internals
                    char** pp_channel = NULL_POINTER;
                    create_internal( (void*) &pp_channel,
                                     (void*) &INTERNAL_TYPE_POINTER );
                    int* p_channel_count = NULL_POINTER;
                    create_internal( (void*) &p_channel_count,
                                     (void*) &INTERNAL_TYPE_INTEGER );
                    int* p_channel_size = NULL_POINTER;
                    create_internal( (void*) &p_channel_size,
                                     (void*) &INTERNAL_TYPE_INTEGER );

                    //parse the internals
                    *p_channel_count = 0;
                    *p_channel_size = 0;
                    parse( pp_channel, p_channel_count, p_channel_size,
                           (void*) &sm, (void*) &smc,
                           (void*) &STRING_ABSTRACTION,
                           (void*) &STRING_ABSTRACTION_COUNT );

                    //set the internals
                    set_internal( pp_internal, (void*) &pp_channel,
                                  (void*) &INTERNAL_TYPE_CHARACTER,
                                  (void*) &INTERNAL_START_CHANNEL_INDEX );
                    set_internal( pp_internal, (void*) &p_channel_count,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_START_CHANNEL_COUNT_INDEX );
                    set_internal( pp_internal, (void*) &p_channel_size,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_START_CHANNEL_SIZE_INDEX );
                }

                //abstraction
                r = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &ABSTRACTION_NAME_ABSTRACTION,
                                (void*) &ABSTRACTION_NAME_ABSTRACTION_COUNT,
                                (void*) &r, (void*) &CHARACTER_ARRAY);

                if ( r==1 ) {

                    log_message_debug( "Modellvalue abstraction gefunden" );

                    // create the internals
                    char** pp_abst = NULL_POINTER;
                    create_internal( (void*) &pp_abst,
                                     (void*) &INTERNAL_TYPE_POINTER );
                    int* p_abst_count = NULL_POINTER;
                    create_internal( (void*) &p_abst_count,
                                     (void*) &INTERNAL_TYPE_INTEGER );
                    int* p_abst_size = NULL_POINTER;
                    create_internal( (void*) &p_abst_size,
                                     (void*) &INTERNAL_TYPE_INTEGER );

                    //parse the internals
                    *p_abst_count = 0;
                    *p_abst_size = 0;
                    parse( pp_abst, p_abst_count, p_abst_size,
                           (void*) &sm, (void*) &smc,
                           (void*) &STRING_ABSTRACTION,
                           (void*) &STRING_ABSTRACTION_COUNT );

                    // set the internals
                    set_internal( pp_internal, (void*) &pp_abst,
                                  (void*) &INTERNAL_TYPE_POINTER,
                                  (void*) &INTERNAL_START_ABSTRACTION_INDEX );
                    set_internal( pp_internal, (void*) &p_abst_count,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_START_ABSTRACTION_COUNT_INDEX );
                    set_internal( pp_internal, (void*) &p_abst_size,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_START_ABSTRACTION_SIZE_INDEX );
                }

                //model
                r = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &MODEL_NAME_ABSTRACTION,
                                (void*) &MODEL_NAME_ABSTRACTION_COUNT,
                                (void*) &r, (void*) &CHARACTER_ARRAY);

                if ( r==1 ) {

                    log_message_debug( "Modellvalue model gefunden" );

                    // create the internals
                    char** pp_model = NULL_POINTER;
                    create_internal( (void*) &pp_model,
                                     (void*) &INTERNAL_TYPE_POINTER );
                    int* p_model_count = NULL_POINTER;
                    create_internal( (void*) &p_model_count,
                                     (void*) &INTERNAL_TYPE_INTEGER );
                    int* p_model_size = NULL_POINTER;
                    create_internal( (void*) &p_model_size,
                                     (void*) &INTERNAL_TYPE_INTEGER );

                    //parse the internal
                    *p_model_count = 0;
                    *p_model_size = 0;
                    parse( pp_model, p_model_count, p_model_size,
                           (void*) &sm, (void*) &smc,
                           (void*) &STRING_ABSTRACTION,
                           (void*) &STRING_ABSTRACTION_COUNT );

                    // set the inernals
                    set_internal( pp_internal, (void*) &pp_model,
                                  (void*) &INTERNAL_TYPE_POINTER,
                                  (void*) &INTERNAL_START_MODEL_INDEX );
                    set_internal( pp_internal, (void*) &p_model_count,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_START_MODEL_COUNT_INDEX );
                    set_internal( pp_internal, (void*) &p_model_size,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_START_MODEL_SIZE_INDEX );

                }

            }  // if (cur_node->type == XML_ELEMENT_NODE)

        }  //for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER

    return 0;
}

/**
 * set the internals for the section tcp socket
 *
 * @param root_element      pointer of the xmlNode
 * @param pp_internal       pointer of die internals
 * @return                  error code
 */
void initialize_internals_tcp_socket( xmlNode* root_element, void** pp_internal ) {

    if ( root_element == NULL_POINTER ) {

        log_message_debug("root_element is a NULL POINTER" );
        return -2;
    }
    else if ( pp_internal == NULL_POINTER ) {

        log_message_debug("pp_internal is a NULL POINTER" );
        return -3;
    }
    else {

        xmlNode* cur_node = NULL;

        for (cur_node = root_element; cur_node; cur_node = cur_node->next) {

            /* jeden Part durchgehen */
            if (cur_node->type == XML_ELEMENT_NODE) {

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
                decode_cybol_property( (void*) &cur_node,
                                       (void*) &sn, (void*) &snc,
                                       (void*) &sc, (void*) &scc,
                                       (void*) &sa, (void*) &sac,
                                       (void*) &sm, (void*) &smc );

                int r;

                //port
                r = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CONFIG_TCP_SOCKET_PORT_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_PORT_ABSTRACTION_COUNT,
                                (void*) &r, (void*) &CHARACTER_ARRAY);

                if ( r==1 ) {

                    log_message_debug( "found the model value port" );

                    // The destination integer.
                    int dis = -1;

                    void* p_port = NULL_POINTER;
                    create_internal( (void*) &p_port,
                                     (void*) &INTERNAL_TYPE_INTEGER );

                    parse( (void*) &p_port, (void*) &INTEGER_COUNT, (void*) &dis,
                           (void*) &sm, (void*) &smc,
                           (void*) &INTEGER_ABSTRACTION,
                           (void*) &INTEGER_ABSTRACTION_COUNT );
                    set_internal( pp_internal, (void*) &p_port,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_TCPSOCKET_PORT_INDEX );
                }

                //active
                r = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CONFIG_TCP_SOCKET_ACTIVE_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_ACTIVE_ABSTRACTION_COUNT,
                                (void*) &r, (void*) &CHARACTER_ARRAY);

                if ( r==1 ) {

                    log_message_debug( "found the model value active" );

                    // The destination integer.
                    int dis = -1;

                    void* p_active = NULL_POINTER;
                    create_internal( (void*) &p_active,
                                     (void*) &INTERNAL_TYPE_INTEGER );

                    parse( (void*) &p_active, (void*) &INTEGER_COUNT, (void*) &dis,
                           (void*) &sm, (void*) &smc,
                           (void*) &INTEGER_ABSTRACTION,
                           (void*) &INTEGER_ABSTRACTION_COUNT );
                    set_internal( pp_internal, (void*) &p_active,
                                  (void*) &INTERNAL_TYPE_INTEGER,
                                  (void*) &INTERNAL_TCPSOCKET_ACTIVE_INDEX );
                }

            }  // if (cur_node->type == XML_ELEMENT_NODE)

        }  //for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER

    return 0;
}

//
// Configuration model.
//

/**
 * Decodes the configuration model into internals memory parameters.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_cybol(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

/**
 * Decodes the configuration.
 *
 * @param p0 the configuration file name
 * @param p1 the internals memory
 */
void decode_configuration(void* p0, void* p1) {

    //??
    //?? BEGIN of temporary workaround for using the libxml2 parser.
    //?? The strings contained in the xml tree are terminated by a null character
    //?? which must be deleted for the cyboi model,
    //?? or neglected in the "count" number!
    //??

    if (p0 != NULL_POINTER) {

        char** f = (char**) p0;

        log_message_debug("Create startup parameters.");

        // Parse file to get the DOM.
        xmlDoc* doc = xmlParseFile(*f);

        // Determine root element.
        xmlNode* root_element = xmlDocGetRootElement(doc)->children;

        // The current node.
        xmlNode* cur_node = NULL_POINTER;

        // The comparison result.
        int r = 0;

        for (cur_node = root_element; cur_node; cur_node = cur_node->next) {

            // Go through each part.
            if (cur_node->type == XML_ELEMENT_NODE) {

                // The source name.
                void* sn = NULL_POINTER;
                void* snc = NULL_POINTER;
                // The source channel.
                void* sc = NULL_POINTER;
                void* scc = NULL_POINTER;
                // The source abstraction.
                void* sa = NULL_POINTER;
                void* sac = NULL_POINTER;
                // The source model.
                void* sm = NULL_POINTER;
                void* smc = NULL_POINTER;

                decode_cybol_property((void*) &cur_node, (void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc, (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc);

                if (r == 0) {

                    compare_arrays((void*) &sm, (void*) &smc, (void*) &CONFIG_START_NAME_ABSTRACTION, (void*) &CONFIG_START_NAME_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                    if (r == 1) {

                        log_message_debug("Found model start.");

                        initialize_internals_start(cur_node->children, p1);
                    }
                }

                if (r == 0) {

                compare_arrays((void*) &sm, (void*) &smc, (void*) &CONFIG_TCP_SOCKET_NAME_ABSTRACTION, (void*) &CONFIG_TCP_SOCKET_NAME_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (r == 1) {

                    log_message_debug("Found tcp socket model.");

                    initialize_internals_tcp_socket(cur_node->children, p1);
                }

                // Reset comparison result.
                r = 0;
            }
        }
    }
}

=== end =======================

    if (p4 != NULL_POINTER) {

        int** sc = (int**) p4;

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
 * Destroys the configuration parameters.
 *
 * @param p0 the internals memory
 * @param p1 the internals memory count
 */
void destroy_configuration_parameters(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int** c = (int**) p1;

        // The loop variable.
        int* j = INTEGER_NULL_POINTER;
        create_integer((void*) &j);
        *j = 0;

        // The configuration parameter.
        void* p = NULL_POINTER;

        while (1) {

            if (*j >= **c) {

                break;
            }

            // Get all configuration parameters from internals memory and
            // destroy those which are existent (unequal NULL_POINTER).

            get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &j, (void*) &p, (void*) &ONE_ELEMENT_COUNT);

            // CAUTION! Do not try to remove the parameters!
            // Each configuration parameter has a fixed position within the
            // internals memory and CANNOT be removed.

            if (p != NULL_POINTER) {

                // The internals memory is a simple pointer array and does not
                // hold type information about its stored configuration parameters.
                // This is possible because the type information is known in
                // context, wherever a configuration parameter is used.
                // In order to call the correct array desctruction procedure,
                // all configuration parameters need to be distinguished here,
                // via conditional if-else statements.

                if (*j == INTERNALS_STARTUP_CHANNEL) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_CHANNEL_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_CHANNEL_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_ABSTRACTION) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_ABSTRACTION_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_ABSTRACTION_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_MODEL) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_MODEL_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_MODEL_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_SIGNAL_MEMORY) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_SIGNAL_MEMORY_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_SIGNAL_MEMORY_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_PORT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_ACTIVE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_SERVERSOCKETNUMBER) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID) {

                    destroy_array((void*) &p, (void*) &POINTER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID_COUNT) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID_SIZE) {

                    destroy_array((void*) &p, (void*) &INTEGER_ARRAY, (void*) &ONE_ELEMENT_COUNT);
                }
            }

            (*j)++;
        }

        destroy_integer((void*) &j);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
    }
}

/* CONFIGURATION_TRANSLATOR_SOURCE */
#endif
