/*
 * $RCSfile: config_into_internals.c,v $
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
 * This file read the congig-file and write the parameter into the internals.
 *
 * CYBOI can interpret Cybernetics Oriented Language (CYBOL) files,
 * which adhere to the Extended Markup Language (XML) syntax.
 *
 * @version $Revision: 1.10 $ $Date: 2005-01-06 12:23:39 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONFIG_INTO_INTERNALS_SOURCE
#define CONFIG_INTO_INTERNALS_SOURCE

#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "../cyboi/internals.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"

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

/**
 * Decodes the configuration.
 *
 * @param p0 the configuration file name
 * @param p1 the internals memory
 */
void decode_configuration(void* p0, void* p1) {

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

            // CAUTION! DO NOT try to remove the parameters!
            // Each configuration parameter has a fixed position within the
            // internals memory and CANNOT be removed.

            if (p != NULL_POINTER) {

                if (*j == INTERNALS_STARTUP_CHANNEL) {

                    remove_array_elements((void*) &nc, (void*) &POINTER_ARRAY, p1, p3, (void*) &ONE_ELEMENT_COUNT);

                } else if (*j == INTERNALS_STARTUP_CHANNEL_COUNT) {
                } else if (*j == INTERNALS_STARTUP_CHANNEL_SIZE) {
                } else if (*j == INTERNALS_STARTUP_ABSTRACTION) {
                } else if (*j == INTERNALS_STARTUP_ABSTRACTION_COUNT) {
                } else if (*j == INTERNALS_STARTUP_ABSTRACTION_SIZE) {
                } else if (*j == INTERNALS_STARTUP_MODEL) {
                } else if (*j == INTERNALS_STARTUP_MODEL_COUNT) {
                } else if (*j == INTERNALS_STARTUP_MODEL_SIZE) {
                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY) {
                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY_COUNT) {
                } else if (*j == INTERNALS_KNOWLEDGE_MEMORY_SIZE) {
                } else if (*j == INTERNALS_SIGNAL_MEMORY) {
                } else if (*j == INTERNALS_SIGNAL_MEMORY_COUNT) {
                } else if (*j == INTERNALS_SIGNAL_MEMORY_SIZE) {
                } else if (*j == INTERNALS_TCPSOCKET_PORT) {
                } else if (*j == INTERNALS_TCPSOCKET_ACTIVE) {
                } else if (*j == INTERNALS_TCPSOCKET_SERVERSOCKETNUMBER) {
                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER) {
                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER_COUNT) {
                } else if (*j == INTERNALS_TCPSOCKET_CLIENTSOCKETNUMBER_SIZE) {
                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID) {
                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID_COUNT) {
                } else if (*j == INTERNALS_TCPSOCKET_MAINSIGNALID_SIZE) {
                }
            }

            (*j)++;
        }

        destroy_integer((void*) &j);

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get highest priority index. The signal memory count is null.");
    }
}

/* CONFIG_INTO_INTERNALS_SOURCE */
#endif
