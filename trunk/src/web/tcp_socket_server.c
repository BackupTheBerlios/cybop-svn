/*
 * $RCSfile: tcp_socket_server.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * This file handles a server TCP socket.
 *
 * @version $Revision: 1.23 $ $Date: 2005-04-08 15:34:41 $ $Author: rholzmueller $
 * @author Marcel Kiesling <makie2001@web.de>
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TCP_SOCKET_SERVER_SOURCE
#define TCP_SOCKET_SERVER_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include "../accessor/compound_accessor.c"
#include "../accessor/signal_memory_accessor.c"
#include "../array/array.c"
#include "../creator/creator.c"
#include "../global/abstraction_constants.c"
#include "../global/channel_constants.c"
#include "../global/character_constants.c"
#include "../global/constant.c"
#include "../global/escape_code_constants.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"
#include "../logic/create.c"
#include "../web/socket_number_accessor.c"

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

/**
 * Creates the tcp server socket.
 *
 * @param p0 the internals memory
 */
void create_tcp_server_socket(void* p0) {

    // The tcp server socket port.
    void** p = POINTER_NULL_POINTER;

    // Get tcp server socket port.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_PORT_INTERNAL, (void*) &p, (void*) POINTER_ARRAY);

    if (p != POINTER_NULL_POINTER) {
      
        if ( *p!=NULL_POINTER ) {

            log_message_debug("Create tcp server socket.");
    
            fprintf(stderr, "DEBUG: The port is: %d \n", *p);
    
            // The tcp server socket.
            int* s = INTEGER_NULL_POINTER;
            // The tcp client sockets.
            void* cs = NULL_POINTER;
            int* csc = INTEGER_NULL_POINTER;
            int* css = INTEGER_NULL_POINTER;
            // The tcp signal ids.
            void* id = NULL_POINTER;
            int* idc = INTEGER_NULL_POINTER;
            int* ids = INTEGER_NULL_POINTER;
    
            // Create tcp server socket.
            create_integer((void*) &s);
            *s = socket(PF_INET, SOCK_STREAM, 0);
            // Create tcp client sockets.
            create_integer((void*) &csc);
            *csc = 0;
            create_integer((void*) &css);
            *css = 0;
            create_array((void*) &cs, (void*) css, (void*) INTEGER_ARRAY);
            // Create tcp signal ids.
            create_integer((void*) &idc);
            *idc = 0;
            create_integer((void*) &ids);
            *ids = 0;
            create_array((void*) &id, (void*) ids, (void*) INTEGER_ARRAY);
    
            // Set tcp server socket.
            set_array_elements(p0, (void*) TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            // Set tcp client sockets.
            set_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(p0, (void*) TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            // Set tcp signal ids.
            set_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
            set_array_elements(p0, (void*) TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
    
            if (*s >= 0) {
    
                fprintf(stderr, "DEBUG: The tcp server socket is: %d \n", *s);
    
                // The socket address.
                struct sockaddr_in a;
    
                // Set address format.
                a.sin_family = AF_INET;
                a.sin_addr.s_addr = INADDR_ANY;
                a.sin_port = htons(*((int*)*p) );
    
                // Determine socket address size.
                int as = sizeof(struct sockaddr_in);
    
                // Bind number to address.
                if (bind(*s, (struct sockaddr*) &a, as) >= 0) {
    
                    // Set the number of possible pending client connection requests.
                    // The maximum number is usually 5.
                    // It is NOT necessary to use this function, but it's good practice.
                    listen(*s, 1);
    
                } else {
    
                    log_message_debug("Could not create tcp server socket. The socket could not be bound to the address.");
                }
    
            } else {
    
                log_message_debug("Could not create tcp server socket. The socket is smaller than zero.");
            }

        } else {
    
            log_message_debug("Could not create tcp server socket. The port is null.");
        }
    } else {

        log_message_debug("Could not create tcp server socket. The port is null.");
    }
}

/**
 * Destroys the tcp server socket.
 *
 * @param p0 the internals memory
 */
void destroy_tcp_server_socket(void* p0) {

    // The tcp server socket port.
    int* p = INTEGER_NULL_POINTER;

    // Get tcp server socket port.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_PORT_INTERNAL, (void*) &p, (void*) POINTER_ARRAY);

    if (p != INTEGER_NULL_POINTER) {

        // The tcp server socket.
        int* s = INTEGER_NULL_POINTER;

        // Get tcp server socket.
        get_array_elements(p0, (void*) UNIX_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);

        if (s != INTEGER_NULL_POINTER) {

            log_message_debug("Destroy tcp server socket.");

/*?? TODO: Rolf Holzmueller

            // Close socket.
            close(*s);

            // Unlink socket.
            unlink((char*) *f);
*/

            // Destroy unix server socket.
            destroy_integer((void*) &s);

        } else {

            log_message_debug("Could not destroy tcp server socket. The socket is null.");
        }

    } else {

        log_message_debug("Could not destroy tcp server socket. The port is null.");
    }
}

/**
 * Get the request method from the complet request msg
 * example for a request row: GET /paramater HTTP/1.1
 * the request method is the first name in the request
 * is it endning with a space
 *
 * @param req the request method
 * @param req_count the count from the request method
 * @param req_row return the request row
 * @param reg_row_count return the count of the request row
 */
void get_request_method( char* req, int* req_count, 
                         char** req_method, int* req_method_count) {

    *req_method_count = 0;
    // The element.
    char* e = CHARACTER_NULL_POINTER;

    while (1) {

        if (*req_method_count >= *req_count) {

            break;
        }

        get_array_elements(req, req_method_count, (void*) &e, (void*) CHARACTER_ARRAY);

        if (*e == *SPACE_CHARACTER) {

            // Reached end of request method.
            break;
        }

        int max_count = *req_method_count + 1;

        resize_array((void*) req_method, (void*) &max_count, (void*) CHARACTER_ARRAY);

        set_array_elements(*req_method, req_method_count, (void*) e, (void*) ONE_NUMBER, (void*) CHARACTER_ARRAY);

        *req_method_count = *req_method_count + 1;
    }
}

/**
 * Gets the request paramater from the request row.
 *
 * Example request row:
 * GET /lib/ausgabe.cybol HTTP/1.1
 *
 * The result of the function is:
 * lib/ausgabe.cybol
 *
 * @param req_row the request row
 * @param reg_row_count the count of the request row
 * @param param the parameter from the request
 * @param param_count the count from the parameter
 */
void get_url_basename_from_request( char* req, int* req_count, 
                                        char** urlbase, int* urlbase_count) {

    *urlbase_count = 0;
    int req_index = 0;
    int start_urlbase_flag = 0;
    int max_count = 0;
    // The element.
    char* e = CHARACTER_NULL_POINTER;

    while (1) {

        if (req_index >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of ending the paramaters.
        if ( (start_urlbase_flag == 1) && 
             ( (*e == *SPACE_CHARACTER) || (*e == *QUESTION_MARK_CHARACTER) ) ) {

            break;
        }

        // Complete the parameters.
        if (start_urlbase_flag == 1) {

            //?? ROLF: Nehme diese Initialisierung bitte VOR die Schleife,
            //?? da sonst bei jedem Schleifendurchlauf Speicherplatz fuer
            //?? eine neue lokale Variable belegt wird!
            max_count = *urlbase_count + 1;

            resize_array((void*) urlbase, (void*) &max_count, (void*) CHARACTER_ARRAY);

            set_array_elements(*urlbase, urlbase_count, (void*) e, (void*) ONE_NUMBER, (void*) CHARACTER_ARRAY);

            *urlbase_count = *urlbase_count + 1;
        }

        // Check of beginning the paramaters.
        if (*e == *SOLIDUS_CHARACTER) {

            // Begin from the parameters.
            start_urlbase_flag = 1;
        }

        req_index++;
    }
}

void* get_character_from_escape_code( void* source, int* source_count, 
                                      char** dest ) {
 
    if (    (source != NULL_POINTER) 
         && (source_count != NULL_POINTER)
         && (dest != NULL_POINTER) )
    {

        int r = 0;
        
        //esquape code must be 3 signs
        if ( *source_count>= *ESCAPE_CODE_CHARACTER_COUNT ) {
         
            // space character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_SPACE_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) SPACE_CHARACTER;
                }                                
            }
            
            // less than sign character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_LESS_THAN_SIGN_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) LESS_THAN_SIGN_CHARACTER;
                }                                
            }
            
            // greater than sign character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_GREATER_THAN_SIGN_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) GREATER_THAN_SIGN_CHARACTER;
                }                                
            }
            
            // nummer sign character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_NUMBER_SIGN_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) NUMBER_SIGN_CHARACTER;
                }                                
            }
            
            // percent sign character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_PERCENT_SIGN_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) PERCENT_SIGN_CHARACTER;
                }                                
            }
            
            // left curly bracket  character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_LEFT_CURLY_BRACKET_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) LEFT_CURLY_BRACKET_CHARACTER;
                }                                
            }
            
            // right curly bracket  character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_RIGHT_CURLY_BRACKET_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) RIGHT_CURLY_BRACKET_CHARACTER;
                }                                
            }
            
            // vertical line character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_VERTICAL_LINE_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) VERTICAL_LINE_CHARACTER;
                }                                
            }
            
            // reverse solidus character            
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_REVERSE_SOLIDUS_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) REVERSE_SOLIDUS_CHARACTER;
                }                                
            }
            
            //CIRCUMFLEX_ACCENT_CHARACTER
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_CIRCUMFLEX_ACCENT_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) CIRCUMFLEX_ACCENT_CHARACTER;
                }                                
            }

            //tilde character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_TILDE_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) TILDE_CHARACTER;
                }                                
            }

            //left square character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_LEFT_SQUARE_BRACKET_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) LEFT_SQUARE_BRACKET_CHARACTER;
                }                                
            }

            //right square character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_RIGHT_SQUARE_BRACKET_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) RIGHT_SQUARE_BRACKET_CHARACTER;
                }                                
            }

            //grave accent character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_GRAVE_ACCENT_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) GRAVE_ACCENT_CHARACTER;
                }                                
            }

            //semikolon character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_SEMICOLON_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) SEMICOLON_CHARACTER;
                }                                
            }

            //soldius character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_SOLIDUS_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) SOLIDUS_CHARACTER;
                }                                
            }

            //question mark character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_QUESTION_MARK_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) QUESTION_MARK_CHARACTER;
                }                                
            }

            //colon character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_COLON_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) COLON_CHARACTER;
                }                                
            }

            //commercial at character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_COMMERCIAL_AT_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) COMMERCIAL_AT_CHARACTER;
                }                                
            }

            //equal sign character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_EQUALS_SIGN_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) EQUALS_SIGN_CHARACTER;
                }                                
            }

            //ampersand character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_AMPERSAND_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) AMPERSAND_CHARACTER;
                }                                
            }

            //dollar  character
            if ( r == 0) {
    
                compare_arrays( source, ESCAPE_CODE_CHARACTER_COUNT,
                                ESCAPE_CODE_DOLLAR_SIGN_CHARACTER,
                                ESCAPE_CODE_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY );
                                
                if ( r == 1 ) {
                    *dest  = (char*) DOLLAR_SIGN_CHARACTER;
                }                                
            }

        }

        // no escape code
        if ( r == 0 ) {
         
            *dest = source;  
        }
    }
}

/**
 * Get the parameters from the request for the request method post.
 * the parameters are in the last row from the request
 *
 * @param req the request
 * @param req_count the request count
 * @param param the parameter
 * @param param_count the paramater count
 */
void get_parameter_from_request_for_post( char* req, int* req_count, 
                                          char** param, int* param_count) {

    *param_count = 0;
    int req_index = *req_count-1;
    int req_last_count = 0;
    int start_param_index = -1;
    int max_count = 0;
    // The element.
    char* e = CHARACTER_NULL_POINTER;
  //  char* c = CHARACTER_NULL_POINTER;

    //get the index for beginning the paramaters
    while (1) {

        if (req_index < 0 ) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of beginning  the paramaters.
        if ( (*e == *LINE_FEED_CONTROL_CHARACTER) ) {

            start_param_index = req_index + 1;
            break;
        }
        
        req_index = req_index - 1;
    }
    
    if ( start_param_index > 0 ) {
        
        req_index = start_param_index;

        while (1) {
           
            if (req_index >= *req_count ) {
    
                break;
            }

            max_count = *param_count + 1;

            resize_array((void*) param, (void*) &max_count, (void*) CHARACTER_ARRAY);

            get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);
            
            //req_last_count = *req_count - req_index;
            //get_character_from_escape_code( e, &req_last_count, &c );

            set_array_elements(*param, param_count, (void*) e, (void*) ONE_NUMBER, (void*) CHARACTER_ARRAY);

            *param_count = *param_count + 1;
//            if ( c != e ) {
//
//                req_index = req_index + *ESCAPE_CODE_CHARACTER_COUNT;
//            }
//            else {

            req_index = req_index + 1;
  
        }

    }
}

/**
 * Get the parameters from the request for the request method get.
 *
 * Example request :
 * GET /lib/ausgabe.cybol?param1=value1&param2=value2 HTTP/1.1 ...
 *
 * The result of the function is:
 * param1=value1&param2=value2
 *
 * @param req the request
 * @param req_count the request count
 * @param param the parameter
 * @param param_count the paramater count
 */
void get_parameter_from_request_for_get( char* req, int* req_count, 
                                         char** param, int* param_count) {

    *param_count = 0;
    int req_index = 0;
    int start_param_flag = 0;
    int max_count = 0;
    // The element.
    char* e = CHARACTER_NULL_POINTER;

    while (1) {

        if (req_index >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of ending the paramaters.
        if ( (start_param_flag == 1) && (*e == *SPACE_CHARACTER) ) {

            break;
        }

        // Complete the parameters.
        if (start_param_flag == 1) {

            max_count = *param_count + 1;

            resize_array((void*) param, (void*) &max_count, (void*) CHARACTER_ARRAY);

            set_array_elements(*param, param_count, (void*) e, (void*) ONE_NUMBER, (void*) CHARACTER_ARRAY);

            *param_count = *param_count + 1;
        }

        // Check of beginning the paramaters.
        if (*e == *QUESTION_MARK_CHARACTER) {

            // Begin from the parameters.
            start_param_flag = 1;
        }

        req_index++;
    }
}

/**
 * Get the paramaters from the request
 *
 * @param req the request
 * @param req_count the request count
 * @param param the parameter
 * @param param_count the paramater count
 */
void get_parameter_from_request( char* req, int* req_count, 
                                 char** param, int* param_count) {

    //Check the request method ( post or get );
    int req_meth_post_res = 0;
    
    compare_arrays( req, REQEUST_METHOD_POST_COUNT,
                    REQEUST_METHOD_POST, REQEUST_METHOD_POST_COUNT, 
                    &req_meth_post_res, CHARACTER_ARRAY );

    if ( req_meth_post_res == 0 ) {
     
        get_parameter_from_request_for_get( req, req_count,
                                            param, param_count );  
    }
    else {
        
        get_parameter_from_request_for_post( req, req_count,
                                             param, param_count );  
    }

}

/**
 * create a signal with the set operation
 * dest must for the abstraction a knowledge
 * source must be a string, depenc from the abstraction
 * of the source 
 * 
 * Bsp.
 * dest zeigt auf eine Model from typ Integer, so ist 
 * source als Integer zu interprtieren, d.b. der übergebene String ist 
 * in eine Integer umzuwandeln. 
 * 
 * 
 */
void set_signal_for_parameter( void* source, int* source_count, 
                               void* dest, int* dest_count,
                               void* internal ){

    //check of null pointer
    if ( (source != NULL_POINTER) &&
         (source_count != NULL_POINTER) &&
         (dest != NULL_POINTER) &&
         (dest_count != NULL_POINTER) &&
         (internal != NULL_POINTER) )
    {

            // The knowledge memory.
            void** km = POINTER_NULL_POINTER;
            void** kmc = POINTER_NULL_POINTER;
            void** kms = POINTER_NULL_POINTER;
        
            // Get knowledge memory.
            get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_ARRAY);
            get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_ARRAY);
            get_array_elements(internal, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_ARRAY);


            //
            //  the signal 
            //

            // The signal abstraction.
            void* sa = NULL_POINTER;
            int* sac = INTEGER_NULL_POINTER;
            int* sas = INTEGER_NULL_POINTER;

            // The signal model.
            void* sm = NULL_POINTER;
            int* smc = INTEGER_NULL_POINTER;
            int* sms = INTEGER_NULL_POINTER;

            // The signal details.
            void* sd = NULL_POINTER;
            int* sdc = INTEGER_NULL_POINTER;
            int* sds = INTEGER_NULL_POINTER;

            // Create signal abstraction.
            create_integer( &sac );
            *sac = 0;
            create_integer( &sas );
            *sas = 0;
            create_model((void*) &sa, (void*) sac, (void*) sas,
                (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT,
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create signal model.
            create_integer( &smc );
            *smc = 0;
            create_integer( &sms );
            *sms = 0;
            create_model((void*) &sm, (void*) smc, (void*) sms,
                (void*) SET_ABSTRACTION, (void*) SET_ABSTRACTION_COUNT,
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create signal detail.
            create_integer( &sdc );
            *sdc = 0;
            create_integer( &sds );
            *sds = 0;
            create_model((void*) &sd, (void*) sdc, (void*) sds,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);


            //
            //  the property destination
            //

            // The property destination name.
            void* pdn = NULL_POINTER;
            int* pdnc = INTEGER_NULL_POINTER;
            int* pdns = INTEGER_NULL_POINTER;

            // The property destination abstraction.
            void* pda = POINTER_NULL_POINTER;
            int* pdac = INTEGER_NULL_POINTER;
            int* pdas = INTEGER_NULL_POINTER;

            // The property destination model.
            void* pdm = POINTER_NULL_POINTER;
            int* pdmc = INTEGER_NULL_POINTER;
            int* pdms = INTEGER_NULL_POINTER;

            // The property destination details.
            void* pdd = POINTER_NULL_POINTER;
            int* pddc = INTEGER_NULL_POINTER;
            int* pdds = INTEGER_NULL_POINTER;

            // Create property destination name.
            create_integer( &pdnc );
            *pdnc = 0;
            create_integer( &pdns );
            *pdns = 0;
            create_model((void*) &pdn, (void*) pdnc, (void*) pdns,
                (void*) SET_DESTINATION_NAME_ABSTRACTION, 
                (void*) SET_DESTINATION_NAME_ABSTRACTION_COUNT, 
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create property destination abstraction.
            create_integer( &pdac );
            *pdac = 0;
            create_integer( &pdas );
            *pdas = 0;
            create_model((void*) &pda, (void*) pdac, (void*) pdas,
                (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, 
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create property destination model.
            create_integer( &pdmc );
            *pdmc = 0;
            create_integer( &pdms );
            *pdms = 0;
            create_model((void*) &pdm, (void*) pdmc, (void*) pdms,
                (void*) dest, (void*) dest_count,
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create property source detail.
            // is empty

//            get_compound_element_by_name( *km, *kmc,
//                (void*) dest, 
//                (void*) dest_count,
//                (void*) &pda, (void*) &pdac, (void*) &pdas,
//                (void*) &pdm, (void*) &pdmc, (void*) &pdms,
//                (void*) &pdd, (void*) &pddc, (void*) &pdds );

            //
            //  the property source
            //

            // The property source name.
            void* psn = NULL_POINTER;
            int* psnc = INTEGER_NULL_POINTER;
            int* psns = INTEGER_NULL_POINTER;

            // The property  source abstraction.
            void* psa = NULL_POINTER;
            int* psac = INTEGER_NULL_POINTER;
            int* psas = INTEGER_NULL_POINTER;

            // The property  source model.
            void* psm = NULL_POINTER;
            int* psmc = INTEGER_NULL_POINTER;
            int* psms = INTEGER_NULL_POINTER;

            // The property  source details.
            void* psd = NULL_POINTER;
            int* psdc = INTEGER_NULL_POINTER;
            int* psds = INTEGER_NULL_POINTER;

            // Create property source name.
            create_integer( &psnc );
            *psnc = 0;
            create_integer( &psns );
            *psns = 0;
            create_model((void*) &psn, (void*) psnc, (void*) psns,
                (void*) SET_SOURCE_NAME_ABSTRACTION, 
                (void*) SET_SOURCE_NAME_ABSTRACTION_COUNT, 
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);


            // Create property source abstraction.
            create_integer( &psac );
            *psac = 0;
            create_integer( &psas );
            *psas = 0;
            create_model((void*) &psa, (void*) psac, (void*) psas,
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, 
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create property source model.
            // todo: expansion for other types
            create_integer( &psmc );
            *psmc = 0;
            create_integer( &psms );
            *psms = 0;
            create_model((void*) &psm, (void*) psmc, (void*) psms,
                (void*) source, (void*) source_count,
                (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

            // Create property source detail.
            // is empty

            // Add property source to the signal detail compound.
            set_compound_element_by_name( sd, sdc, sds,
                psn, (void*) psnc, (void*) psns,
                psa, (void*) psac, (void*) psas,
                psm, (void*) psmc, (void*) psms,
                psd, (void*) psdc, (void*) psds);

            // Add property destination to the detail compound.
            set_compound_element_by_name( sd, sdc, sds,
                pdn, (void*) pdnc, (void*) pdns,
                pda, (void*) pdac, (void*) pdas,
                pdm, (void*) pdmc, (void*) pdms,
                pdd, (void*) pddc, (void*) pdds);


            //
            // Signal.
            //

            log_message_debug("Set start signal.");

            // The signal memory.
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** ms = NULL_POINTER;

            // Get signal memory.
            get_array_elements(internal, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) POINTER_ARRAY);
            get_array_elements(internal, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_ARRAY);
            get_array_elements(internal, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) POINTER_ARRAY);

            // The signal id.
            int* id = INTEGER_NULL_POINTER;
            create_integer( &id);
            *id = 0;
            get_new_signal_id(*m, *mc, (void*) id);

            // Set signal.
            set_signal(*m, *mc, *ms,
                (void*) sa, (void*) sac,
                (void*) sm, (void*) smc,
                (void*) sd, (void*) sdc,
                (void*) NORMAL_PRIORITY, (void*) id);
                
    }         
    
}


/**
 *  Zerlegt den Querystring in die einzelnen Elemenet 
 *  und erzeugt frür alle Parameter ein Signal
 * 
 * ein Qruery ist z.B. domain.teststring1=Hallo&domain.teststring2=Rolf
 * 
 */
void set_signals_for_all_parameters( void* query, int* query_count, 
                                     void* internal ){

    //check of null pointer
    if ( (query != NULL_POINTER) &&
         (query_count != NULL_POINTER) &&
         (internal != NULL_POINTER) )
    {
     
        int query_counter=0;
        
        char* param = CHARACTER_NULL_POINTER;
        int* param_count = INTEGER_NULL_POINTER;
        int* param_size = INTEGER_NULL_POINTER;
     
        char* value = CHARACTER_NULL_POINTER;
        int* value_count = INTEGER_NULL_POINTER;
        int* value_size = INTEGER_NULL_POINTER;
        
        create_integer( &param_count );
        *param_count = *query_count;
        create_integer( &param_size );
        *param_size = *query_count;
        create_string( &param, param_size );

        create_integer( &value_count );
        *value_count = *query_count;
        create_integer( &value_size );
        *value_size = *query_count;
        create_string( &value, value_size );
        
        //result flag fpor comparision
        int r = 0;
        
        //elements from the array
        void* element = NULL_POINTER;
        //elements from the array
        void* decode_element = NULL_POINTER;
        int last_query_count = 0;
        
        //temp count  for comparision
        int temp_count= 1;

        while (1) {
           
            if ( query_counter >= *query_count ) {
                
                break;
            }
            
            //param
            *param_count = 0;
            r = 0;
            
            while ( 1 ) {
             
                get_array_elements( (void*) query, (void*) &query_counter, 
                                    (void*) &element, CHARACTER_ARRAY );
             
                compare_arrays( element, &temp_count, 
                                EQUALS_SIGN_CHARACTER, 
                                EQUALS_SIGN_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY ); 
                                
                if ( (query_counter >= *query_count) ||
                     (r==1) ) 
                {
                
                    query_counter = query_counter + 1;
                    break;       
                }
                
                //the element must insert into the param
                last_query_count = *query_count - query_counter;
                get_character_from_escape_code( element, &last_query_count, 
                                                (char**) &decode_element );
                set_array_elements( param, param_count,
                                    decode_element, &temp_count,
                                    CHARACTER_ARRAY );
                
                if ( element == decode_element ) {
                    query_counter = query_counter + 1;
                }
                else {
                    query_counter = query_counter + *ESCAPE_CODE_CHARACTER_COUNT;
                }
                *param_count = *param_count + 1;
            }

            //value
            *value_count = 0;
            r = 0;

            while ( 1 ) {
             
                get_array_elements( (void*) query, (void*) &query_counter, 
                                    (void*) &element, CHARACTER_ARRAY );
             
                compare_arrays( element, &temp_count, 
                                AMPERSAND_CHARACTER, 
                                AMPERSAND_CHARACTER_COUNT,
                                &r, CHARACTER_ARRAY ); 
                                
                if ( (query_counter >= *query_count) ||
                     (r==1) ) 
                {
                
                    query_counter = query_counter + 1;
                    break;       
                }
                
                //the element must insert into the value
                last_query_count = *query_count - query_counter;
                get_character_from_escape_code( element, &last_query_count, 
                                                (char**) &decode_element );
                set_array_elements( value, value_count,
                                    decode_element, &temp_count,
                                    CHARACTER_ARRAY );
                
                
                if ( element == decode_element ) {
                    query_counter = query_counter + 1;
                }
                else {
                    query_counter = query_counter + *ESCAPE_CODE_CHARACTER_COUNT;
                }
                *value_count = *value_count + 1;
            }
            
            
            //
            if ( *param_count > 0 ) {
             
                set_signal_for_parameter( value, value_count,
                                          param, param_count,
                                          internal );
            }
        }
        
    }         
    
}


/**
 * Handles a tcp socket request.
 *
 * The http request must be parsed for parameters.
 * A signal is created and added to the signal memory, for each parameter.
 *
 * @param p0 the internals memory
 * @param p1 the client socket
 */
void handle_tcp_socket_request(void* p0, void* p1) {

    if (p1 != NULL_POINTER) {

        int* cs = (int*) p1;

        log_message_debug("Handle tcp socket request.");

        // The message.
        char* msg = CHARACTER_NULL_POINTER;
        // The maximum message count.
        int max_msg_count = 2048;

        // Create message.
        create_array((void*) &msg, (void*) &max_msg_count, (void*) CHARACTER_ARRAY);

        // Receive message from client.
        int msg_count = recv(*cs, msg, max_msg_count, 0);

        if (msg_count != -1) {

            // The url basename.
            char* url_basename = NULL_POINTER;
            int url_basename_count = 0;

            // Create url basename.
            create_array( (void*) &url_basename, (void*) &url_basename_count, 
                          (void*) CHARACTER_ARRAY);

            // Get url base name .
            get_url_basename_from_request( msg, &msg_count, 
                                           &url_basename, 
                                           &url_basename_count );


            // The parameter.
            char* param = NULL_POINTER;
            int param_count = 0;

            // Create paramater.
            create_array((void*) &param, (void*) &param_count, (void*) CHARACTER_ARRAY);

            // Get parameters.
            get_parameter_from_request( msg, &msg_count, 
                                        &param, &param_count);

            // The firefox web browser makes a second request
            // to determine the favicon.
            char firefox_request[] = "favicon.ico";
            char* p_firefox_request = &firefox_request[0];
            int firefox_request_count = 11;

            // The comparison result.
            int r = 0;

            compare_arrays((void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != 1) {
             
                //query string handling
                set_signals_for_all_parameters( (void*) param, (void*) &param_count, p0 );

 
                log_message_debug("Create destination abstraction, model, details.");

                // The source channel.
                char c_sc[] = "file";
                char* sc = &c_sc[0];
                int* scc = INTEGER_NULL_POINTER;
                create_integer( &scc );
                *scc = 4;

                // The source abstraction.
                char c_sa[] = "cybol";
                char* sa = &c_sa[0];
                int* sac = INTEGER_NULL_POINTER;
                create_integer( &sac );
                *sac = 5;

                // The source model.
                char* sm = url_basename;
                int* smc = INTEGER_NULL_POINTER;
                create_integer( &smc );
                *smc = url_basename_count;

                // The destination abstraction.
                void* da = NULL_POINTER;
                int* dac = INTEGER_NULL_POINTER;
                create_integer( &dac );
                *dac = 0;
                int* das = INTEGER_NULL_POINTER;
                create_integer( &das );
                *das = 0;

                // The destination model.
                void* dm = NULL_POINTER;
                int* dmc = INTEGER_NULL_POINTER;
                create_integer( &dmc );
                *dmc = 0;
                int* dms = INTEGER_NULL_POINTER;
                create_integer( &dms );
                *dms = 0;

                // The destination details.
                void* dd = NULL_POINTER;
                int* ddc = INTEGER_NULL_POINTER;
                create_integer( &ddc );
                *ddc = 0;
                int* dds = INTEGER_NULL_POINTER;
                create_integer( &dds );
                *dds = 0;

                // Create destination abstraction.
                create_model((void*) &da, (void*) dac, (void*) das,
                    (void*) sa, (void*) sac,
                    (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT,
                    (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

                // Create destination model.
                create_model((void*) &dm, (void*) dmc, (void*) dms,
                    (void*) sm, (void*) smc,
                    (void*) sa, (void*) sac,
                    (void*) sc, (void*) scc);

                //
                // Signal.
                //

                log_message_debug("Set start signal.");

                // The signal memory.
                void** m = NULL_POINTER;
                void** mc = NULL_POINTER;
                void** ms = NULL_POINTER;

                // Get signal memory.
                get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) POINTER_ARRAY);

                // The signal id.
                int* id = INTEGER_NULL_POINTER;
                create_integer( &id);
                *id = 0;
                get_new_signal_id(*m, *mc, (void*) id);

                // Set signal.
                set_signal(*m, *mc,* ms,
                    (void*) da, (void*) dac,
                    (void*) dm, (void*) dmc,
                    (void*) dd, (void*) ddc,
                    (void*) NORMAL_PRIORITY, (void*) id);

                add_signal_id(p0, (void*) id);
                add_client_socket_number(p0, (void*) cs);

            } else {

                close(*cs);
            }

        } else {

            log_message_debug("ERROR: Could not handle tcp socket request. The received message is invalid.");
        }

    } else {

        log_message_debug("ERROR: Could not handle tcp socket request. The client socket is null.");
    }
}

/**
 * Runs the tcp socket server.
 *
 * The procedure is running in a thread,
 * to avoid blocking of the main signal waiting loop.
 *
 * @param p0 the internals memory
 */
void run_tcp_socket(void* p0) {

    // The tcp server socket.
    void** s = POINTER_NULL_POINTER;

    // Get tcp server socket.
    get_array_elements(p0, (void*) TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_ARRAY);

    if (s != POINTER_NULL_POINTER) {
      
        if (*s != NULL_POINTER ) {

            log_message_debug("Run tcp server socket.");
    
            // The signal memory.
            void** m = NULL_POINTER;
            void** mc = NULL_POINTER;
            void** ms = NULL_POINTER;
    
            // Get signal memory.
            get_array_elements(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) POINTER_ARRAY);
    
            // The client socket address.
            struct sockaddr_in ca;
    
            // Determine client socket address size.
            int cas = sizeof(ca);
    
    //??        while (1) {
    
            // Accept client socket request and store client socket.
            int cs = accept(**((int**)s), (struct sockaddr*) &ca, &cas);
    
            if (cs >= 0) {
    
                log_message_debug("DEBUG: Accepted tcp client socket request.");
    
                handle_tcp_socket_request(p0, (void*) &cs);
    
    
            } else {
    
                fprintf(stderr, "Could not run tcp server socket. The accept failed.");
                pthread_exit(NULL_POINTER);
            }

        }else {

            log_message_debug("Could not run tcp server socket. The socket is null.");
        
        }   
    } else {

        log_message_debug("Could not run tcp server socket. The socket is null.");
    }
}

/**
 * Receives tcp socket input.
 *
 * @param p0 the internals memory
 */
void receive_tcp_socket(void* p0) {

    log_message_debug("Receive tcp server socket.");

    // The thread.
    pthread_t t;

    // Create thread returning an error value.
    int e = pthread_create(&t, NULL_POINTER, (void*) &run_tcp_socket, p0);

    if (e != 0) {

        log_message_debug("Could not receive tcp socket. An error occured while creating the thread.");
    }
}

/**
 * Funktion liest Daten in der POST- oder GET-Methode ein.
 * R?ckgabewert: String puffer mit den Daten
 * bei Fehler  : NULL
 */
/*??
char* getdata() {

   unsigned long size;
   char *puffer = NULL;
   char *request = getenv("REQUEST_METHOD");
   char *cont_len;
   char *cgi_string;

   // Zuerst die Request-Methode ?berpr?fen
   if(  NULL == request )
      return NULL;
   else if( strcmp(request, "GET") == 0 )
      {
         // Die Methode GET -> Query String abholen
         cgi_string = getenv("QUERY_STRING");
         if( NULL == cgi_string )
            return NULL;
         else
            {
               puffer =(char *) Strdup(cgi_string);
               return puffer; // R?ckgabewert an den Aufrufer
            }
      }
   else if( strcmp(request, "POST") == 0 )
      {
         // Die Methode POST -> L?nge des Strings
         //   ermitteln (CONTENT_LENGTH)
         cont_len = getenv("CONTENT_LENGTH");
         if( NULL == cont_len)
            return NULL;
         else
            {
               // String CONTENT_LENGTH in
                  unsigned long umwandeln
               size = (unsigned long) atoi(cont_len);
               if(size <= 0)
                  return NULL; // Keine Eingabe!?!?
            }
         // Jetzt lesen wir die Daten von stdin ein
         puffer =(char *) malloc(size+1);
         if( NULL == puffer )
            return NULL;
         else
            {
               if( NULL == fgets(puffer, size+1, stdin) )
                  {
                     free(puffer);
                     return NULL;
                  }
               else  // R?ckgabewerte an den Ausrufer
                  return puffer;
            }
      }
   else // Weder GET-Methode noch die POST-Methode
        //   wurden verwendet
      return NULL;

}
*/

/* TCP_SOCKET_SERVER_SOURCE */
#endif
