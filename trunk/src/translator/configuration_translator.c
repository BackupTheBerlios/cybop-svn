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
 * @version $Revision: 1.3 $ $Date: 2005-01-07 00:06:42 $ $Author: christian $
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
#include "../logic/create.c"
#include "../test/test.c"
#include "../translator/cybol_translator.c"

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
// Configuration node.
//

/**
 * Decodes the configuration node into a compound.
 *
 * @param p0 the destination (internals memory)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (libxml2 xml node)
 * @param p4 the source count
 */
void decode_configuration_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

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

            // The destination model.
            void* dm = NULL_POINTER;
            void* dmc = NULL_POINTER;
            void* dms = NULL_POINTER;

            while (1) {

                if (c == NULL_POINTER) {

                    break;
                }

                if (c->type == XML_ELEMENT_NODE) {

                    // Decode child node properties.
                    decode_cybol_property((void*) &c,
                        (void*) &sn, (void*) &snc, (void*) &sc, (void*) &scc,
                        (void*) &sa, (void*) &sac, (void*) &sm, (void*) &smc);

                    if (r == 0) {

                        compare_arrays((void*) &sn, (void*) &snc, (void*) &CHANNEL_NAME_ABSTRACTION, (void*) &CHANNEL_NAME_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                        if (r == 1) {

                            log_message_debug("Found channel.");

                            // create the internals
                            char** pp_channel = NULL_POINTER;
                            int* p_channel_count = NULL_POINTER;
                            int* p_channel_size = NULL_POINTER;

                            // Create destination model.
                            create_model((void*) &dm, (void*) &dmc, (void*) &dms,
                                (void*) &sm, (void*) &smc,
                                (void*) &sa, (void*) &sac,
                                (void*) &sc, (void*) &scc);

                            create_internal( (void*) &pp_channel, (void*) &INTERNAL_TYPE_POINTER );
                            create_internal( (void*) &p_channel_count, (void*) &INTERNAL_TYPE_INTEGER );
                            create_internal( (void*) &p_channel_size, (void*) &INTERNAL_TYPE_INTEGER );

                            //parse the internals
                            *p_channel_count = 0;
                            *p_channel_size = 0;
                            parse(pp_channel, p_channel_count, p_channel_size, (void*) &sm, (void*) &smc,
                                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

                            // Set configuration parameter in internals memory.
                            set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &INTERNALS_STARTUP_CHANNEL, (void*) &dm, (void*) &ONE_ELEMENT_COUNT);
                        }
                    }

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

                    // Reset destination model.
                    dm = NULL_POINTER;
                    dmc = NULL_POINTER;
                    dms = NULL_POINTER;
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
 * Encodes the internals memory into a configuration node.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_configuration_node(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

//
// Configuration model.
//

/**
 * Decodes the configuration model into an internals memory.
 *
 * @param p0 the destination (internals memory)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (parsed cybol/xml model)
 * @param p4 the source count
 */
void decode_configuration(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //??
    //?? BEGIN of temporary workaround for using the libxml2 parser.
    //?? The strings contained in the xml tree are terminated by a null character
    //?? which must be deleted for the cyboi model,
    //?? or neglected in the "count" number!
    //??

    if (p4 != NULL_POINTER) {

        int** sc = (int**) p4;

        if (p3 != NULL_POINTER) {

            void** s = (void**) p3;

            if (p0 != NULL_POINTER) {

                void** d = (void**) p0;

                log_message_debug("Decode configuration.");

                // Get root element node.
                xmlNode* r = xmlDocGetRootElement((xmlDoc*) *s);

                decode_configuration_node(p0, p1, p2, (void*) &r, p4);

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
 * Encodes the internals memory into a configuration model.
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_configuration(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    //
    // CONFIGURATION_ABSTRACTION
    //
    // CAUTION! Parameters of the internals memory MUST NOT be written
    // to the configuration file which was given at command line!
    // The CYBOI configuration file can only be edited MANUALLY.
    //
}

/* CONFIGURATION_TRANSLATOR_SOURCE */
#endif
