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
 * @version $Revision: 1.4 $ $Date: 2004-10-29 15:08:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONFIG_INTO_INTERNALS_SOURCE
#define CONFIG_INTO_INTERNALS_SOURCE

#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

#include "../cyboi/character_internals.c"
#include "../cyboi/double_internals.c"
#include "../cyboi/integer_internals.c"
#include "../cyboi/pointer_internals.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/variable.c"
#include "../logger/logger.c"

void initialize_internals_start(xmlNode* root_element, void* pPointerInternals, void* pIntInternals) {

    if ( root_element == NULL_POINTER ) {

       }
    else if ( pPointerInternals == NULL_POINTER ) {

    }
    else if ( pIntInternals == NULL_POINTER ) {

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
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CHANNEL_NAME_ABSTRACTION,
                                (void*) &CHANNEL_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                      //printf(" Modellvalue channel gefunden \n" );
                    set_array_element( (void*) &pPointerInternals,
                                       (void*) &POINTER_ARRAY,
                                       (void*) &POINTER_INTERNALS_START_CHANNEL_INDEX,
                                       (void*) &sm );

                    set_array_element( (void*) &pIntInternals,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_INTERNALS_START_CHANNEL_COUNT_INDEX,
                                       (void*) &smc );
                }

                //abstraction
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &ABSTRACTION_NAME_ABSTRACTION,
                                (void*) &ABSTRACTION_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    //printf(" Modellvalue abstraction gefunden \n" );
                    set_array_element( (void*) &pPointerInternals,
                                       (void*) &POINTER_ARRAY,
                                       (void*) &POINTER_INTERNALS_START_ABSTRACTION_INDEX,
                                       (void*) &sm );
                    set_array_element( (void*) &pIntInternals,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_INTERNALS_START_ABSTRACTION_COUNT_INDEX,
                                       (void*) &smc );
                }

                //model
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &MODEL_NAME_ABSTRACTION,
                                (void*) &MODEL_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    //printf(" Modellvalue modelgefunden \n" );
                    set_array_element( (void*) &pPointerInternals,
                                       (void*) &POINTER_ARRAY,
                                       (void*) &POINTER_INTERNALS_START_MODEL_INDEX,
                                       (void*) &sm );
                    set_array_element( (void*) &pIntInternals,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_INTERNALS_START_MODEL_COUNT_INDEX,
                                       (void*) &smc );

                }

            }  // if (cur_node->type == XML_ELEMENT_NODE)

        }  //for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER
}

void initialize_internals_tcp_socket( xmlNode* root_element, void* pPointerInternals, void* pIntInternals) {

    if ( root_element == NULL_POINTER ) {

       }
    else if ( pPointerInternals == NULL_POINTER ) {

    }
    else if ( pIntInternals == NULL_POINTER ) {

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
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CONFIG_TCP_SOCKET_PORT_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_PORT_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                      //printf(" Modellvalue channel gefunden \n" );

                    // The destination integer.
                    int di = -1;
                    int dic = -1;
                    int dis = -1;

                    parse( (void*) &di, (void*) &dic, (void*) &dis,
                           (void*) &sm, (void*) &smc,
                           (void*) &INTEGER_ABSTRACTION,
                           (void*) &INTEGER_ABSTRACTION_COUNT );

                    int port=di;
                    set_array_element( (void*) &pIntInternals,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_INTERNALS_TCPSOCKET_PORT_INDEX,
                                       (void*) &port );
                }

                //active
                compare_arrays( (void*) &sn, (void*) &snc,
                                (void*) &CONFIG_TCP_SOCKET_ACTIVE_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_ACTIVE_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    //printf(" Modellvalue abstraction gefunden \n" );
                    // The destination integer.
                    int di = -1;
                    int dic = -1;
                    int dis = -1;

                    parse( (void*) &di, (void*) &dic, (void*) &dis,
                           (void*) &sm, (void*) &smc,
                           (void*) &INTEGER_ABSTRACTION,
                           (void*) &INTEGER_ABSTRACTION_COUNT );

                    int active = di;

                    set_array_element( (void*) &pIntInternals,
                                       (void*) &INTEGER_ARRAY,
                                       (void*) &INTEGER_INTERNALS_TCPSOCKET_ACTIVE_INDEX,
                                       (void*) &active );
                }

            }  // if (cur_node->type == XML_ELEMENT_NODE)

        }  //for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER
}

/**
 * @param pConfigFile Pointer of the config file (char[])
 * @param pPointerInternals Pointer of die pointer internals
 * @param pIntInternals Pointer of die integer internals
 * @return errorcode (-1 configfile no parse)
*/
int initialize_internals( void* pConfigFile, void* pPointerInternals, void* pIntInternals) {

    if ( pConfigFile == NULL_POINTER ) {

    }
    else if ( pPointerInternals == NULL_POINTER ) {

    }
    else if ( pIntInternals == NULL_POINTER ) {

    }
    else {

        xmlDoc *doc = NULL;
        xmlNode *root_element = NULL;
        xmlNode *cur_node = NULL;

        /*parse the file and get the DOM */
        doc = xmlParseFile( (char*)pConfigFile );
        if (doc == NULL) {

              char error[] = "Config-file not parse";
           log_message((void*) &ERROR_LOG_LEVEL, (void*) error , (void*) strlen(error));
           return -1;
        }

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
                                       &sn, (void*) &snc,
                                       &sc, (void*) &scc,
                                       &sa, (void*) &sac,
                                       &sm, (void*) &smc );

                int comp_result = 0;

                compare_arrays( (void*) &sm, (void*) &smc,
                                (void*) &CONFIG_START_NAME_ABSTRACTION,
                                 (void*) &CONFIG_START_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    //printf(" Model start gefunden" );
                      initialize_internals_start( cur_node->children,
                                                   pPointerInternals,
                                                     pIntInternals );

                }

                compare_arrays( (void*) &sm, (void*) &smc,
                                (void*) &CONFIG_TCP_SOCKET_NAME_ABSTRACTION,
                                (void*) &CONFIG_TCP_SOCKET_NAME_ABSTRACTION_COUNT,
                                (void*) &comp_result, (void*) &CHARACTER_ARRAY);

                if ( comp_result==1 ) {

                    //printf(" Model tcp_socket gefunden" );
                      initialize_internals_tcp_socket( cur_node->children,
                                                        pPointerInternals,
                                                          pIntInternals );
                }

            }  //if (cur_node->type == XML_ELEMENT_NODE) {

        }  // for (cur_node = root_element; cur_node; cur_node = cur_node->next)

    } //else Parameter == NULL_POINTER

    return 0;
}

/* CONFIG_INTO_INTERNALS_SOURCE */
#endif
