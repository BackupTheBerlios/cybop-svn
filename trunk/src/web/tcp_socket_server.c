/*
 * $RCSfile: tcp_socket_server.c,v $
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
 * This file handles a server TCP socket.
 *
 * @version $Revision: 1.14 $ $Date: 2005-01-08 19:55:19 $ $Author: christian $
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
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../logger/logger.c"
#include "../web/socket_number_accessor.c"

/**
 * Creates the tcp server socket.
 *
 * @param p0 the internals memory
 */
void create_tcp_server_socket(void* p0) {

    // The tcp server socket port.
    int* p = POINTER_NULL_POINTER;

    // Get tcp server socket port.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_PORT_INTERNAL, (void*) &p, (void*) &ONE_ELEMENT_COUNT);

    if (p != INTEGER_NULL_POINTER) {

        log_message_debug("Create tcp server socket.");

        fprintf(stderr, "DEBUG: The port is: %d \n", *p);

        // The tcp server socket, client sockets, signal ids.
        int* s = INTEGER_NULL_POINTER;
        int* csc = INTEGER_NULL_POINTER;
        int* css = INTEGER_NULL_POINTER;
        int* idc = INTEGER_NULL_POINTER;
        int* ids = INTEGER_NULL_POINTER;

        // Create tcp server socket, client sockets, signal ids.
        create_integer((void*) &s);
        create_integer((void*) &csc);
        create_integer((void*) &css);
        create_integer((void*) &idc);
        create_integer((void*) &ids);

        // Initialize tcp server socket, client sockets, signal ids.
        *s = socket(PF_INET, SOCK_STREAM, 0);
        *csc = 0;
        *css = 0;
        *idc = 0;
        *ids = 0;

        // The tcp client sockets, signal ids.
        void* cs = NULL_POINTER;
        void* id = NULL_POINTER;

        // Create tcp client sockets, signal ids.
        create_array((void*) &cs, (void*) &INTEGER_ARRAY, css);
        create_array((void*) &id, (void*) &ids);

        // Set tcp server socket, client sockets, signal ids.
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_CLIENT_SOCKETS_INTERNAL, (void*) &cs, (void*) &ONE_ELEMENT_COUNT);
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_CLIENT_SOCKETS_COUNT_INTERNAL, (void*) &csc, (void*) &ONE_ELEMENT_COUNT);
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_CLIENT_SOCKETS_SIZE_INTERNAL, (void*) &css, (void*) &ONE_ELEMENT_COUNT);
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_CLIENT_SOCKET_SIGNAL_IDS_INTERNAL, (void*) &id, (void*) &ONE_ELEMENT_COUNT);
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_CLIENT_SOCKET_SIGNAL_IDS_COUNT_INTERNAL, (void*) &idc, (void*) &ONE_ELEMENT_COUNT);
        set_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_CLIENT_SOCKET_SIGNAL_IDS_SIZE_INTERNAL, (void*) &ids, (void*) &ONE_ELEMENT_COUNT);

        if (*s >= 0) {

            fprintf(stderr, "DEBUG: The tcp server socket is: %d \n", *s);

            // The socket address.
            struct sockaddr_in a;

            if (a != NULL_POINTER) {

                // Set address format.
                a.sin_family = AF_INET;
                a.sin_addr.s_addr = INADDR_ANY;
                a.sin_port = htons(*p);

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

                log_message_debug("Could not create unix server socket. The address is null.");
            }

        } else {

            log_message_debug("Could not create tcp server socket. The socket is smaller than zero.");
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
    int* p = POINTER_NULL_POINTER;

    // Get tcp server socket port.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_PORT_INTERNAL, (void*) &p, (void*) &ONE_ELEMENT_COUNT);

    if (p != INTEGER_NULL_POINTER) {

        // The tcp server socket.
        int* s = INTEGER_NULL_POINTER;

        // Get tcp server socket.
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &UNIX_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);

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
 * Get the request row from the complet request
 * example for a request row: GET /paramater HTTP/1.1
 * the request row end with the character \r\n
 *
 * @param req the complet request
 * @param req_count the count from the complet request
 * @param req_row return the request row
 * @param reg_row_count return the count of the request row
 */
void get_request_row(char** req, int* req_count, char** req_row, int* req_row_count) {

    *req_row_count = 0;

    // The element.
    char* e = NULL_POINTER;

    while (1) {

        if (*req_row_count >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &CHARACTER_ARRAY, req_row_count, (void*) &e, (void*) &ONE_ELEMENT_COUNT);

        if (*e == *CARRIAGE_RETURN_CONTROL_CHARACTER) {

            // Reached end of request line.
            break;
        }

        int max_count = *req_row_count + 1;

        resize_array(req_row, (void*) &CHARACTER_ARRAY, (void*) &max_count);

        set_array_elements(req_row, (void*) &CHARACTER_ARRAY, req_row_count, (void*) &e, (void*) &ONE_ELEMENT_COUNT);

        *req_row_count = *req_row_count + 1;
    }
}

/**
 * get the request paramater from the request row
 * example for a request row: GET /lib/ausgabe.cybol HTTP/1.1
 *      the result for the function is
 *      lib/ausgabe.cybol
 *
 * @param req_row the request row
 * @param reg_row_count the count of the request row
 * @param param the parameter from the request
 * @param param_count the count from the parameter
 */
void get_param_from_request_row(char** req_row, int* req_row_count, char** param, int* param_count) {

    int req_row_index = 0;
    int start_param_flag = 0;

    // The element.
    char* e = NULL_POINTER;

    *param_count = 0;

    while (1) {

        if (req_row_index >= *req_row_count) {

            break;
        }

        get_array_elements(req_row, (void*) &CHARACTER_ARRAY, (void*) &req_row_index, (void*) &e, (void*) &ONE_ELEMENT_COUNT);

        // Check of ending the paramaters.
        if ((start_param_flag == 1) && (*e == *CARRIAGE_RETURN_CONTROL_CHARACTER)) {

            break;
        }

        // Complete the parameters.
        if (start_param_flag == 1) {

            int max_count = *param_count + 1;

            resize_array(param, (void*) &CHARACTER_ARRAY, (void*) &max_count);

            set_array_elements(param, (void*) &CHARACTER_ARRAY, param_count, (void*) &e, (void*) &ONE_ELEMENT_COUNT);

            *param_count = *param_count + 1;
        }

        // Check of beginning the paramaters
        if (*e == *SOLIDUS_CHARACTER) {

            // Begin from the parameters.
            start_param_flag = 1;
        }

        req_row_index = req_row_index + 1;
    }
}

/**
 * Handles a tcp socket request.
 *
 * This is a http request.
 * The http request must be parsed for parameters.
 * A signal is created and added to the signal memory, for each parameter.
 *
 * @param p0 the internals memory
 * @param cs the client socket
 */
void handle_tcp_socket_request(void* p0, int* cs) {

    log_message_debug("Handle tcp socket request.");

    if (cs == NULL_POINTER) {

        log_message_debug("p_client_socketnumber is a NULL POINTER");

    } else {

        char *request = getenv("PATH");
        char* msg;
        int max_msg_count = 1024;
        create_array( (void*) &msg, (void*) &CHARACTER_ARRAY, (void*) &max_msg_count);
        int msg_count = 0;

        msg_count = recv(*cs, msg, max_msg_count, 0);

        // Read message from client.
        if (msg_count == -1) {

            log_message_debug("error while receiving reply");
            exit(1);
        }

        //:todo auf get prüfen
        //:todo parameter aus empfangenen Daten ermitteln
        char* msg_row = NULL_POINTER;
        int msg_row_count = 0;
        create_array((void*) &msg_row, (void*) &CHARACTER_ARRAY, (void*) &msg_row_count);
        get_request_row(&msg, &msg_count, &msg_row, &msg_row_count);

        char* param = NULL_POINTER;
        int param_count = 0;
        create_array((void*) &param, (void*) &CHARACTER_ARRAY, (void*) &param_count);

        get_param_from_request_row(&msg_row, &msg_row_count, &param, &param_count);

        // Firefox make als secon request a request for favicon
        // this request must no handle.
        char firefox_request[] = "favicon.ico";
        char* p_firefox_request = &firefox_request[0];
        int firefox_request_count = 11;
        int comp_res = 0;

        compare_arrays((void*) &param, (void*) &param_count, (void*) &p_firefox_request, (void*) &firefox_request_count, (void*) &comp_res, (void*) &CHARACTER_ARRAY);

        if (comp_res == 1) {

            close(*cs);

        } else {

            /* write the answer to the client  */
    //        if(send(*p_client_socketnumber, msg, msg_count, 0) == -1) {
    //
    //            log_message_debug("error while replying");
    //            exit(1);
    //        }

            void** m = NULL_POINTER;
            int* mc = NULL_POINTER;
            int* ms = NULL_POINTER;

            get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) &ONE_ELEMENT_COUNT);
            get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) &ONE_ELEMENT_COUNT);

            // The source channel.
            char c_sc[] = "inline";
            char* sc = &c_sc[0];
            int scc = 6;
            // The source abstraction.
            char c_sa[] = "cybol";
            char* sa = &c_sa[0];
            int sac = 5;
            // The source model.
            char* sm = param;
            int smc = param_count;

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

            // Create destination abstraction.
            create_model((void*) &da, (void*) &dac, (void*) &das,
                (void*) &sa, (void*) &sac,
                (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT,
                (void*) &INLINE_CHANNEL, (void*) &INLINE_CHANNEL_COUNT);
            log_message_debug("create destination abstraction");

            // Create destination model.
            create_model((void*) &dm, (void*) &dmc, (void*) &dms,
                (void*) &sm, (void*) &smc,
                (void*) &sa, (void*) &sac,
                (void*) &sc, (void*) &scc);
            log_message_debug("create destination model");

            //
            // set the signal
            //

            int main_sig_id = 0;

            get_new_signal_id(m, mc, (void*) &main_sig_id);

            set_signal(m, mc, ms,
                (void*) &da, (void*) &dac,
                (void*) &dm, (void*) &dmc,
                (void*) &dd, (void*) &ddc,
                (void*) &NORMAL_PRIORITY,
                (void*) &main_sig_id);

            log_message_debug("set start signals");

            add_main_signal_id(p0, (void*) &main_sig_id);
            add_client_socket_number(p0, cs);
        }  // comp_res<>1  favicon must ignoried
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
    int* s = INTEGER_NULL_POINTER;

    // Get tcp server socket.
    get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &TCP_SERVER_SOCKET_INTERNAL, (void*) &s, (void*) &ONE_ELEMENT_COUNT);

    if (s != INTEGER_NULL_POINTER) {

        log_message_debug("Run tcp server socket.");

        // The signal memory.
        void* m = NULL_POINTER;
        void* mc = NULL_POINTER;
        void* ms = NULL_POINTER;

        // Get signal memory.
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) &ONE_ELEMENT_COUNT);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) &ONE_ELEMENT_COUNT);
        get_array_elements(p0, (void*) &POINTER_ARRAY, (void*) &SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) &ONE_ELEMENT_COUNT);

        // The client socket address.
        struct sockaddr_in ca;

        // Determine client socket address size.
        int cas = sizeof(ca);

//??        while (1) {

        // Accept client socket request and store client socket.
        int cs = accept(*s, (struct sockaddr*) &ca, &cas);

        if (cs >= 0) {

            log_message_debug("DEBUG: Accepted tcp client socket request.");

//??            char ausgabe[] = "Hello World";
//??            send(cs, ausgabe, strlen(ausgabe), 0);

            handle_tcp_socket_request(p0, &cs);

//??            // Close socket connection.
//??            close(cs);

        } else {

            fprintf(stderr, "Could not run tcp server socket. The accept failed.");
            pthread_exit(NULL_POINTER);
        }

//??        }

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
    // The error value.
    int e = 0;

    // Create thread.
    e = pthread_create(&t, NULL_POINTER, (void*) &run_tcp_socket, p0);

    if (e != 0) {

        log_message_debug("Could not receive tcp socket. An error occured while creating the thread.");
    }
}

/**
 * Funktion liest Daten in der POST- oder GET-Methode ein.
 * Rückgabewert: String puffer mit den Daten
 * bei Fehler  : NULL
 */
/*??
char* getdata() {

   unsigned long size;
   char *puffer = NULL;
   char *request = getenv("REQUEST_METHOD");
   char *cont_len;
   char *cgi_string;

   // Zuerst die Request-Methode überprüfen
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
               return puffer; // Rückgabewert an den Aufrufer
            }
      }
   else if( strcmp(request, "POST") == 0 )
      {
         // Die Methode POST -> Länge des Strings
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
               else  // Rückgabewerte an den Ausrufer
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
