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
 * @version $Revision: 1.6 $ $Date: 2004-11-16 16:49:22 $ $Author: rholzmueller $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONFIG_INTO_INTERNALS_SOURCE
#define CONFIG_INTO_INTERNALS_SOURCE

#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

#include "../cyboi/internals.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/variable.c"
#include "../logger/logger.c"

/**
 * set the internals for the section start
 * 
 * @param root_element      pointer of the xmlNode 
 * @param pp_internal       pointer of die internals 
 * @return                  error code
*/
int initialize_internals_start( xmlNode* root_element, void** pp_internal ) {
 
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

                int comp_result;

                //channel
                comp_result = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CHANNEL_NAME_ABSTRACTION,
                                (void*) &CHANNEL_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "Modellvalue channel gefunden" );
                    set_internal( pp_internal, (void*) &sm,
                                  (void*) &INTERNAL_TYPE_CHARACTER, 
                                  (void*) &smc, 
                                  (void*) &CHARACTER_PRIMITIVE_SIZE,
                                  (void*) &INTERNAL_START_CHANNEL_INDEX );
                }

                //abstraction
                comp_result = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &ABSTRACTION_NAME_ABSTRACTION,
                                (void*) &ABSTRACTION_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "Modellvalue abstraction gefunden" );
                    set_internal( pp_internal, (void*) &sm,
                                  (void*) &INTERNAL_TYPE_CHARACTER, 
                                  (void*) &smc, 
                                  (void*) &CHARACTER_PRIMITIVE_SIZE,
                                  (void*) &INTERNAL_START_ABSTRACTION_INDEX );
                }

                //model
                comp_result = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &MODEL_NAME_ABSTRACTION,
                                (void*) &MODEL_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "Modellvalue model gefunden" );
                    set_internal( pp_internal, (void*) &sm,
                                  (void*) &INTERNAL_TYPE_CHARACTER, 
                                  (void*) &smc, 
                                  (void*) &CHARACTER_PRIMITIVE_SIZE,
                                  (void*) &INTERNAL_START_MODEL_INDEX );
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
int initialize_internals_tcp_socket( xmlNode* root_element, void** pp_internal ) {

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

                int comp_result;

                //port
                comp_result = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CONFIG_TCP_SOCKET_PORT_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_PORT_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "found the model value port" );

                    // The destination integer.
                    int dis = -1;
                    
                    void* pIntArray = NULL_POINTER;
                    create_array( (void*) &pIntArray, 
                                  (void*) &INTEGER_ARRAY, 
                                  (void*) &INTEGER_COUNT );

                    parse( (void*) &pIntArray, (void*) &INTEGER_COUNT, (void*) &dis,
                           (void*) &sm, (void*) &smc,
                           (void*) &INTEGER_ABSTRACTION,
                           (void*) &INTEGER_ABSTRACTION_COUNT );

                    int port = 0;
                    int* p_port = &port;
                    get_array_element( (void*) &pIntArray,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_VALUE_INDEX, 
                                       (void*) &port );
                                       
                    int port_count = 1;    
                    set_internal( pp_internal, (void*) &p_port,
                                  (void*) &INTERNAL_TYPE_INTEGER, 
                                  (void*) &port_count,
                                  (void*) &INTEGER_PRIMITIVE_SIZE,
                                  (void*) &INTERNAL_TCPSOCKET_PORT_INDEX );
                }

                //active
                comp_result = 0;
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CONFIG_TCP_SOCKET_ACTIVE_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_ACTIVE_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "found the model value active" );

                    // The destination integer.
                    int dis = -1;
                    
                    void* pIntArray = NULL_POINTER;
                    create_array( (void*) &pIntArray, 
                                  (void*) &INTEGER_ARRAY, 
                                  (void*) &INTEGER_COUNT );

                    parse( (void*) &pIntArray, (void*) &INTEGER_COUNT, (void*) &dis,
                           (void*) &sm, (void*) &smc,
                           (void*) &INTEGER_ABSTRACTION,
                           (void*) &INTEGER_ABSTRACTION_COUNT );

                    int active = 0;
                    int* p_active = &active;    
                    get_array_element( (void*) &pIntArray,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_VALUE_INDEX, 
                                       (void*) &active );
                    int active_count=1;
                    set_internal( pp_internal, ((void*) &p_active),
                                  (void*) &INTERNAL_TYPE_INTEGER, 
                                  (void*) &active_count,
                                  (void*) &INTEGER_PRIMITIVE_SIZE,
                                  (void*) &INTERNAL_TCPSOCKET_ACTIVE_INDEX );
                }

            }  // if (cur_node->type == XML_ELEMENT_NODE)

        }  //for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER
    
    return 0;
}

/**
 * 
 *  set the internals for all section
 * 
 * @param p_configfile      pointer of the config file 
 *                          this is a null terminated string
 * @param pp_internal       pointer of die internals 
 * @return                  errorcode (-1 configfile no parse)
*/
int initialize_internals( char* p_configfile, void** pp_internal ) {

    log_message_debug("initialize_internals s started test 6" );

    if ( p_configfile == NULL_POINTER ) {

        log_message_debug("p_configfile is a NULL POINTER" );
        return -2;
    }
    else if ( pp_internal == NULL_POINTER ) {

        log_message_debug("pp_internal is a NULL POINTER" );
        return -3;
    }
    else {

        xmlDoc *doc = NULL;
        xmlNode *root_element = NULL;
        xmlNode *cur_node = NULL;

        /*parse the file and get the DOM */
        doc = xmlParseFile( p_configfile );
        if (doc == NULL) {

           log_message_debug("configfile not parse");
           return -1;
        }
        log_message_debug("configfile parse");
        

        root_element = xmlDocGetRootElement( doc )->children;

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

                int comp_result = 0;

                compare_arrays( (void*) &sm, (void*) &smc,
                                (void*) &CONFIG_START_NAME_ABSTRACTION,
                                 (void*) &CONFIG_START_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "Model start gefunden" );
                    initialize_internals_start( cur_node->children,
                                                pp_internal );

                }

                compare_arrays( (void*) &sm, (void*) &smc,
                                (void*) &CONFIG_TCP_SOCKET_NAME_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    log_message_debug( "Model tcp_socket gefunden" );
                    initialize_internals_tcp_socket( cur_node->children,
                                                     pp_internal );
                }

            }  //if (cur_node->type == XML_ELEMENT_NODE) {

        }  // for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER

    return 0;
}

/* CONFIG_INTO_INTERNALS_SOURCE */
#endif
