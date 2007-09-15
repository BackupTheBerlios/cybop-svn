/*
 * $RCSfile: receive_socket.c,v $
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
 * @version $Revision: 1.38 $ $Date: 2007-09-15 00:17:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_SOCKET_SOURCE
#define RECEIVE_SOCKET_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/console/console_escape_code_constants.c"
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/internal_memory_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

/**
 * Separates the query string into single parameters.
 *
 * A signal is created for each single parameter.
 *
 * Example:
 * query string: domain.teststring1=Hallo&domain.teststring2=Rolf
 * parameter one: domain.teststring1=Hallo and
 * parameter two: domain.teststring2=Rolf
 *
 * @param p0 the query
 * @param p1 the query count
 * @param p2 the internal memory
 */
/*??
void set_signals_for_all_parameters(void* p0, int* p1, void* p2) {

    //check of null pointer
    if ((p0 != *NULL_POINTER) && (p1 != *NULL_POINTER) && (p2 != *NULL_POINTER)) {

        int query_counter = *NUMBER_0_INTEGER;

        //paramater
        char* param = (char*) *NULL_POINTER;
        int* param_count = (int*) *NULL_POINTER;
        int* param_size = (int*) *NULL_POINTER;

        //value for the parameter
        char* value = (char*) *NULL_POINTER;
        int* value_count = (int*) *NULL_POINTER;
        int* value_size = (int*) *NULL_POINTER;

        allocate(&param_count, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *param_count = *p1;
        allocate(&param_size, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *param_size = *p1;
        allocate_character_vector(&param, param_size);

        allocate(&value_count, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *value_count = *p1;
        allocate(&value_size, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *value_size = *p1;
        allocate_character_vector(&value, value_size);

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        //elements from the array
        void* element = *NULL_POINTER;
        //elements from the array
        void* decode_element = *NULL_POINTER;
        int last_query_count = *NUMBER_0_INTEGER;

        //temp count  for comparision
        int temp_count = *NUMBER_1_INTEGER;

        while (*NUMBER_1_INTEGER) {

            if (query_counter >= *p1) {

                break;
            }

            // param
            *param_count = *NUMBER_0_INTEGER;
            r = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                get_array_elements((void*) p0, (void*) &query_counter, (void*) &element, CHARACTER_ARRAY);

                compare_arrays(element, &temp_count, EQUALS_SIGN_ASCII_CHARACTER, PRIMITIVE_COUNT, &r, CHARACTER_ARRAY);

                if ((query_counter >= *p1) || (r == *NUMBER_1_INTEGER)) {

                    query_counter = query_counter + *NUMBER_1_INTEGER;
                    break;
                }

                //the element must insert into the param
                last_query_count = *p1 - query_counter;

                get_character_from_escape_code(element, &last_query_count, (char**) &decode_element);
                set_array_elements(param, param_count, decode_element, &temp_count, CHARACTER_ARRAY);

                if (element == decode_element) {

                    query_counter = query_counter + *NUMBER_1_INTEGER;

                } else {

                    query_counter = query_counter + *ESCAPE_CODE_CHARACTER_COUNT;
                }

                *param_count = *param_count + *NUMBER_1_INTEGER;
            }

            //value
            *value_count = *NUMBER_0_INTEGER;
            r = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                get_array_elements((void*) p0, (void*) &query_counter, (void*) &element, CHARACTER_ARRAY);

                compare_arrays(element, &temp_count, AMPERSAND_ASCII_CHARACTER, PRIMITIVE_COUNT, &r, CHARACTER_ARRAY);

                if ((query_counter >= *p1) || (r == *NUMBER_1_INTEGER)) {

                    query_counter = query_counter + *NUMBER_1_INTEGER;
                    break;
                }

                //the element must insert into the value
                last_query_count = *p1 - query_counter;
                get_character_from_escape_code(element, &last_query_count, (char**) &decode_element);
                set_array_elements(value, value_count, decode_element, &temp_count, CHARACTER_ARRAY);

                if (element == decode_element) {

                    query_counter = query_counter + *NUMBER_1_INTEGER;

                } else {

                    query_counter = query_counter + *ESCAPE_CODE_CHARACTER_COUNT;
                }

                *value_count = *value_count + *NUMBER_1_INTEGER;
            }

            //set the signal for the paramater and the value
            if (*param_count > *NUMBER_0_INTEGER) {

                set_signal_for_parameter(value, value_count, param, param_count, p2);
            }
        }
    }
}
*/

/**
 * Receives a socket signal.
 *
 * @param p0 the knowledge memory
 * @param p1 the knowledge memory count
 * @param p2 the knowledge memory size
 * @param p3 the signal memory
 * @param p4 the signal memory count
 * @param p5 the signal memory size
 * @param p6 the signal memory mutex
 * @param p7 the interrupt request internal
 * @param p8 the model
 * @param p9 the model count
 * @param p10 the model size
 * @param p11 the details
 * @param p12 the details count
 * @param p13 the details size
 * @param p14 the commands
 * @param p15 the commands count
 * @param p16 the command name
 * @param p17 the command name count
 */
void receive_socket_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p7 != *NULL_POINTER) {

        int* irq = (int*) p7;

        log_message_debug("Debug: Receive socket signal.");

        fprintf(stderr, "TEST: receive socket signal command name: %s \n", (char*) p16);
        fprintf(stderr, "TEST: receive socket signal command name count: %i \n", *((int*) p17));

    /** The index parameter. */
    static char INDEX_PARAMETER_ARRAY[] = {'i', 'n', 'd', 'e', 'x'};
    static char* INDEX_PARAMETER = INDEX_PARAMETER_ARRAY;
    static int* INDEX_PARAMETER_COUNT = NUMBER_5_INTEGER_ARRAY;

        // The command name, abstraction, model, details.
        void** cn = NULL_POINTER;
        void** cnc = NULL_POINTER;
        void** cns = NULL_POINTER;
        void** ca = NULL_POINTER;
        void** cac = NULL_POINTER;
        void** cas = NULL_POINTER;
        void** cm = NULL_POINTER;
        void** cmc = NULL_POINTER;
        void** cms = NULL_POINTER;
        void** cd = NULL_POINTER;
        void** cdc = NULL_POINTER;
        void** cds = NULL_POINTER;

        if (p16 != *NULL_POINTER) {

            // Get actual command belonging to the command name.
            // If the name is not known, the command parameter is left untouched.
            get_universal_compound_element_by_name(p14, p15,
                p16, p17,
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                p0, p1);

        } else {

            // Get default index command, since the given command is null.
            get_universal_compound_element_by_name(p14, p15,
                INDEX_PARAMETER, INDEX_PARAMETER_COUNT,
                (void*) &cn, (void*) &cnc, (void*) &cns,
                (void*) &ca, (void*) &cac, (void*) &cas,
                (void*) &cm, (void*) &cmc, (void*) &cms,
                (void*) &cd, (void*) &cdc, (void*) &cds,
                p0, p1);
        }

        // Lock signal memory mutex.
        pthread_mutex_lock(p6);

        // The signal id.
        int* id = (int*) *NULL_POINTER;

        // Allocate signal id.
        allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *id = *NUMBER_0_INTEGER;
        get_new_signal_id(p3, p4, (void*) id);

        // Add signal to signal memory.
        set_signal(p3, p4, p5, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_CYBOI_SIGNAL_PRIORITY, (void*) id);

    /*??
        add_signal_id(p0, (void*) id);
        add_client_socket_number(p0, (void*) cs);
    */

        // Set interrupt request flag, in order to notify the signal checker
        // that a new signal has been placed in the signal memory.
        *irq = *NUMBER_1_INTEGER;

        // Unlock signal memory mutex.
        pthread_mutex_unlock(p6);

    } else {

        log_message_debug("Error: Could not receive socket signal. The interrupt request flag is null.");
    }
}

/**
 * Receives a stream socket message.
 *
 * @param p0 the buffer (Hand over as reference!)
 * @param p1 the buffer count
 * @param p2 the buffer size
 * @param p3 the communication partner-connected socket of this system
 */
void receive_socket_stream_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* ps = (int*) p3;

        if (p2 != *NULL_POINTER) {

            size_t* bs = (size_t*) p2;

            if (p1 != *NULL_POINTER) {

                int* bc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** b = (void**) p0;

                    log_message_debug("Receive stream socket message.");

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER;

                fprintf(stderr, "TEST: receive socket thread client socket: %i \n", *ps);

    fprintf(stderr, "TEST pre b: %s \n", (char*) *b);
    fprintf(stderr, "TEST pre bc: %i \n", *bc);
    fprintf(stderr, "TEST pre bs: %i \n", *bs);

                    // Receive message from client.
                    //
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" procedure.
                    // Normally, "recv" blocks until there is input available to be read.
                    // ?? Not so here, as the socket was set to "non-blocking" mode at startup. ??
                    //
                    // CAUTION! A message MUST NOT be longer than the given buffer size!
                    *bc = recv(*ps, *b, *bs, *NUMBER_0_INTEGER);

    fprintf(stderr, "TEST post b: %s \n", (char*) *b);
    fprintf(stderr, "TEST post bc: %i \n", *bc);
    fprintf(stderr, "TEST post bs: %i \n", *bs);

                    if (*bc > *NUMBER_0_INTEGER) {

                        log_message_debug("Information: Successfully received stream socket message.");

                    } else if (*bc = *NUMBER_0_INTEGER) {

                        log_message_debug("Warning: Could not receive stream socket message. No data could be received.");

                    } else {

                        if (errno == EBADF) {

                            log_message_debug("Error: Could not receive stream socket message. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_message_debug("Error: Could not receive stream socket message. The descriptor socket is not a socket.");

                        } else if (errno == EWOULDBLOCK) {

                            log_message_debug("Error: Could not receive stream socket message. The read operation would block even though nonblocking mode has been set on the socket.");

                        } else if (errno == EINTR) {

                            log_message_debug("Error: Could not receive stream socket message. The operation was interrupted by a signal before any data was read.");

                        } else if (errno == ENOTCONN) {

                            log_message_debug("Error: Could not receive stream socket message. The socket was never connected.");

                        } else {

                            // CAUTION! Do NOT log the following error:
                            // log_message_debug("Error: Could not receive stream socket message. An unknown error occured while receiving data.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established.
                            // But if no connection and client socket are there,
                            // then the "recv" or "recvfrom" procedure returns an error,
                            // which would unnecessarily fill up the log file.
                        }
                    }

                } else {

                    log_message_debug("Error: Could not receive stream socket message. The buffer is null.");
                }

            } else {

                log_message_debug("Error: Could not receive stream socket message. The buffer count is null.");
            }

        } else {

            log_message_debug("Error: Could not receive stream socket message. The buffer size is null.");
        }

    } else {

        log_message_debug("Error: Could not receive stream socket message. The partner-connected socket of this system is null.");
    }
}

/**
 * Receives via stream socket.
 *
 * @param p0 the buffer (Hand over as reference!)
 * @param p1 the buffer count
 * @param p2 the buffer size
 * @param p3 the communication partner-connected socket of this system
 * @param p4 the communication partner-connected socket address
 * @param p5 the communication partner-connected socket address size
 * @param p6 the original socket of this system
 * @param p7 the socket mutex
 */
void receive_socket_stream(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p6 != *NULL_POINTER) {

        int* os = (int*) p6;

        if (p3 != *NULL_POINTER) {

            int* ps = (int*) p3;

            log_message_debug("Receive via stream socket.");

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling the procedure
            // that might cause an error.
            errno = *NUMBER_0_INTEGER;

            // Lock socket mutex.
            pthread_mutex_lock((pthread_mutex_t*) p7);

    fprintf(stderr, "TEST: receive socket stream server socket: %i \n", *os);

            // Accept client socket request and store client socket.
            //
            // Accepting a connection does NOT make the original socket
            // part of the connection. Instead, it creates a new socket
            // which becomes connected. The normal return value of
            // "accept" is the file descriptor for the new socket.
            //
            // After "accept", the original socket remains open and
            // unconnected, and continues listening until it gets closed.
            // One can accept further connections with the original
            // socket by calling "accept" again -- best done in a loop!
            //
            // The address "pa" returns information about the name of the
            // communication partner socket that initiated the connection.
            *ps = accept(*os, (struct sockaddr*) p4, (socklen_t*) p5);

            if (*ps >= *NUMBER_0_INTEGER) {

                receive_socket_stream_message(p0, p1, p2, p3);

                // CAUTION! Do NOT close client socket here!
                // It is stored in the internal memory and only closed in
                // the "send_socket" operation, when replying to the client.
                // close(*ps);

            } else {

                if (errno == EBADF) {

                    log_message_debug("Error: Could not receive via stream socket. The socket argument is not a valid file descriptor.");

                } else if (errno == ENOTSOCK) {

                    log_message_debug("Error: Could not receive via stream socket. The descriptor socket argument is not a socket.");

                } else if (errno == EOPNOTSUPP) {

                    log_message_debug("Error: Could not receive via stream socket. The descriptor socket does not support this operation.");

                } else if (errno == EWOULDBLOCK) {

                    // CAUTION! Do NOT log the following error:
                    // log_message_debug("Error: Could not receive via stream socket. The socket has nonblocking mode set, and there are no pending connections immediately available.");
                    //
                    // The reason is that the socket is non-blocking,
                    // so that the "accept" procedure returns always,
                    // even if no connection was established,
                    // which would unnecessarily fill up the log file.

                } else {

                    log_message_debug("Error: Could not receive via stream socket. An unknown error occured while accepting a socket connection.");
                }
            }

            // Unlock socket mutex.
            pthread_mutex_unlock((pthread_mutex_t*) p7);

        } else {

            log_message_debug("Error: Could not receive via stream socket. The communication partner-connected socket of this system is null.");
        }

    } else {

        log_message_debug("Error: Could not receive via stream socket. The original socket of this system is null.");
    }
}

/**
 * Receives via datagram socket.
 *
 * @param p0 the buffer (Hand over as reference!)
 * @param p1 the buffer count
 * @param p2 the buffer size
 * @param p3 the original socket of this system
 * @param p4 the original socket address of this system
 * @param p5 the original socket address of this system size
 * @param p6 the socket mutex
 */
void receive_socket_datagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p3 != *NULL_POINTER) {

        int* os = (int*) p3;

        if (p2 != *NULL_POINTER) {

            int* bs = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* bc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** b = (void**) p0;

                    log_message_debug("Receive via datagram socket.");

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER;

                    // Lock socket mutex.
                    pthread_mutex_lock((pthread_mutex_t*) p6);

                    // Receive message from client.
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" procedure.
                    // Normally, "recv" blocks until there is input available to be read.
                    // ?? Not so here, as the socket was set to "non-blocking" mode at startup. ??
                    //
                    // CAUTION! A message MUST NOT be longer than the given buffer size!
                    *bc = recvfrom(*os, *b, *bs, *NUMBER_0_INTEGER, (struct sockaddr*) p4, (socklen_t*) p5);

                    if (*bc > *NUMBER_0_INTEGER) {

                        log_message_debug("Information: Successfully received via datagram socket.");

                        fprintf(stderr, "TEST b: %s \n", (char*) *b);
                        fprintf(stderr, "TEST bc: %i \n", *bc);
                        fprintf(stderr, "TEST bs: %i \n", *bs);

                    } else if (*bc = *NUMBER_0_INTEGER) {

                        log_message_debug("Warning: Could not receive via datagram socket. No data could be received.");

                    } else {

                        if (errno == EBADF) {

                            log_message_debug("Error: Could not receive via datagram socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_message_debug("Error: Could not receive via datagram socket. The descriptor socket is not a socket.");

                        } else if (errno == EWOULDBLOCK) {

                            log_message_debug("Error: Could not receive via datagram socket. The read operation would block even though nonblocking mode has been set on the socket.");

                        } else if (errno == EINTR) {

                            log_message_debug("Error: Could not receive via datagram socket. The operation was interrupted by a signal before any data was read.");

                        } else if (errno == ENOTCONN) {

                            log_message_debug("Error: Could not receive via datagram socket. The socket was never connected.");

                        } else {

                            // CAUTION! Do NOT log the following error:
                            // log_message_debug("Error: Could not receive stream socket message. An unknown error occured while receiving data.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established.
                            // But if no connection and client socket are there,
                            // then the "recv" or "recvfrom" procedure returns an error,
                            // which would unnecessarily fill up the log file.
                        }
                    }

                    // Unlock socket mutex.
                    pthread_mutex_unlock((pthread_mutex_t*) p6);

                } else {

                    log_message_debug("Error: Could not receive via datagram socket. The buffer is null.");
                }

            } else {

                log_message_debug("Error: Could not receive via datagram socket. The buffer count is null.");
            }

        } else {

            log_message_debug("Error: Could not receive via datagram socket. The buffer size is null.");
        }

    } else {

        log_message_debug("Error: Could not receive via datagram socket. The original socket of this system is null.");
    }
}

/**
 * Receives via raw socket.
 *
 * @param p0 the buffer (Hand over as reference!)
 * @param p1 the buffer count
 * @param p2 the buffer size
 */
void receive_socket_raw(void* p0, void* p1, void* p2) {

    log_message_debug("Receive via raw socket.");
    log_message_debug("CAUTION! Raw socket functionality is not implemented in cyboi yet.");
}

/**
 * Receives a socket message depending on the given communication style.
 *
 * @param p0 the buffer (Hand over as reference!)
 * @param p1 the buffer count
 * @param p2 the buffer size
 * @param p3 the communication partner-connected socket of this system
 * @param p4 the communication partner-connected socket address
 * @param p5 the communication partner-connected socket address size
 * @param p6 the original socket of this system
 * @param p7 the original socket address of this system
 * @param p8 the original socket address of this system size
 * @param p9 the socket mutex
 * @param p10 the communication style
 * @param p11 the communication style count
 */
void receive_socket_style(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("Receive socket message depending on communication style.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) STREAM_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            receive_socket_stream(p0, p1, p2, p3, p4, p5, p6, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            receive_socket_datagram(p0, p1, p2, p6, p7, p8, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p10, p11, (void*) RAW_COMMUNICATION_STYLE_MODEL, (void*) RAW_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            receive_socket_raw(p0, p1, p2);
        }
    }
}

/**
 * Receives a socket message.
 *
 * @param p0 the knowledge memory
 * @param p1 the knowledge memory count
 * @param p2 the knowledge memory size
 * @param p3 the signal memory
 * @param p4 the signal memory count
 * @param p5 the signal memory size
 * @param p6 the signal memory mutex
 * @param p7 the interrupt request internal
 * @param p8 the model (Hand over as reference!)
 * @param p9 the model count
 * @param p10 the model size
 * @param p11 the details (Hand over as reference!)
 * @param p12 the details count
 * @param p13 the details size
 * @param p14 the commands
 * @param p15 the commands count
 * @param p16 the language
 * @param p17 the language count
 * @param p18 the communication style
 * @param p19 the communication style count
 * @param p20 the original socket of this system
 * @param p21 the original socket address of this system
 * @param p22 the original socket address of this system size
 * @param p23 the communication partner-connected socket of this system
 * @param p24 the communication partner-connected socket address
 * @param p25 the communication partner-connected socket address size
 * @param p26 the socket mutex
 * @param p27 the buffer (Hand over as reference!)
 * @param p28 the buffer count
 * @param p29 the buffer size
 * @param p30 the prefixed key (Hand over as reference!)
 * @param p31 the prefixed key count
 * @param p32 the prefixed key size
 */
void receive_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19,
    void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26, void* p27, void* p28, void* p29, void* p30, void* p31, void* p32) {

    if (p29 != *NULL_POINTER) {

        int* bs = (int*) p29;

        if (p28 != *NULL_POINTER) {

            int* bc = (int*) p28;

            if (p27 != *NULL_POINTER) {

                void** b = (void**) p27;

                log_message_debug("Receive socket message.");

        fprintf(stderr, "TEST 0 language: %s \n", (char*) p16);
        fprintf(stderr, "TEST 0 language count: %i \n", *((int*) p17));

        fprintf(stderr, "TEST 0 bc: %i \n", *((int*) p28));
        fprintf(stderr, "TEST 0 bs: %i \n", *((int*) p29));

                // Receive socket message depending on communication style.
                receive_socket_style(p27, p28, p29, p23, p24, p25, p20, p21, p22, p26, p18, p19);

        fprintf(stderr, "TEST 1 bc: %i \n", *((int*) p28));
        fprintf(stderr, "TEST 1 bs: %i \n", *((int*) p29));

                // Decode http request and write any parameters into the
                // compound model and details being handed over as parameters.
                decode(p8, p9, p10, p11, p12, p13, *b, p28, p0, p1, p30, p31, p32, p16, p17);

        fprintf(stderr, "TEST 2 bc: %i \n", *((int*) p28));
        fprintf(stderr, "TEST 2 bs: %i \n", *((int*) p29));

    /** The action parameter. */
    static char ACTION_PARAMETER_ARRAY[] = {'a', 'c', 't', 'i', 'o', 'n'};
    static char* ACTION_PARAMETER = ACTION_PARAMETER_ARRAY;
    static int* ACTION_PARAMETER_COUNT = NUMBER_6_INTEGER_ARRAY;

        fprintf(stderr, "TEST special a: %s \n", ACTION_PARAMETER);
        fprintf(stderr, "TEST special ac: %i \n", *ACTION_PARAMETER_COUNT);

                // The action name, abstraction, model, details.
                void** an = NULL_POINTER;
                void** anc = NULL_POINTER;
                void** ans = NULL_POINTER;
                void** aa = NULL_POINTER;
                void** aac = NULL_POINTER;
                void** aas = NULL_POINTER;
                void** am = NULL_POINTER;
                void** amc = NULL_POINTER;
                void** ams = NULL_POINTER;
                void** ad = NULL_POINTER;
                void** adc = NULL_POINTER;
                void** ads = NULL_POINTER;

                // Get action.
                // It is just one of many possibly parameters that were received as
                // http request and added to the compound model above.
                // If no action parameter is found, an empty signal will be created below.
                get_universal_compound_element_by_name(p8, p9,
                    (void*) ACTION_PARAMETER, (void*) ACTION_PARAMETER_COUNT,
                    (void*) &an, (void*) &anc, (void*) &ans,
                    (void*) &aa, (void*) &aac, (void*) &aas,
                    (void*) &am, (void*) &amc, (void*) &ams,
                    (void*) &ad, (void*) &adc, (void*) &ads,
                    p0, p1);

        fprintf(stderr, "TEST 3 bc: %i \n", *((int*) p28));
        fprintf(stderr, "TEST 3 bs: %i \n", *((int*) p29));

        fprintf(stderr, "TEST special am: %s \n", (char*) *am);
        fprintf(stderr, "TEST special amc: %i \n", **((int**) amc));

                // Receive socket signal.
                receive_socket_signal(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, *am, *amc);

        fprintf(stderr, "TEST 4 bc: %i \n", *((int*) p28));
        fprintf(stderr, "TEST 4 bs: %i \n", *((int*) p29));

                //?? CAUTION! This sleep procedure is temporarily necessary for testing!
                //?? Otherwise, the loop runs into the next cycle and the socket mutex
                //?? gets locked, so that the "send_socket" procedure in the main thread
                //?? cannot send its message.
                //??    sleep(30);

/*??
                // The url basename.
                char* url_basename = (char*) *NULL_POINTER;
                int url_basename_count = *NUMBER_0_INTEGER;
                // Create url basename.
                allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) CHARACTER_ARRAY);
                // Get url base name.
                receive_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

                // The parameter.
                char* param = (char*) *NULL_POINTER;
                int param_count = *NUMBER_0_INTEGER;
                // Create paramater.
                allocate_array((void*) &param, (void*) &param_count, (void*) CHARACTER_ARRAY);
                // Get parameters.
                receive_socket_parameter(msg, &msg_count, &param, &param_count);

                // The firefox web browser makes a second request
                // to determine the favicon.
                char firefox_request[] = "favicon.ico";
                char* p_firefox_request = &firefox_request[*NUMBER_0_INTEGER];
                int firefox_request_count = *NUMBER_11_INTEGER;

                // The comparison result.
                int r = *NUMBER_0_INTEGER;

                compare_arrays((void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Close partner socket, since the request was just intended to retrieve the icon.
                    close(*ps);

                } else {

                    // query string handling
                    set_signals_for_all_parameters((void*) param, (void*) &param_count, p0);

                    //?? The OLD solution created a signal here from a cybol knowledge template.
                    //?? This is NOW easier, since the commands already exist in the knowledge tree
                    //?? and only have to be referenced from here.
                }
*/

                // Reset character buffer.
                //
                // CAUTION! The buffer and its count do ALWAYS have to be reset,
                // NOT ONLY if the message data reception (above) was successful!
                // The reason is that on failure, the buffer count is set to some
                // negative value and therefore needs to be reset in any case.
                //
                // CAUTION! Do NOT deallocate the character buffer!
                // It was allocated at socket startup and must remain unchanged,
                // since threads are not allowed to allocate any memory area.
                // Therefore, its elements are just set to null pointers here.
                //
                // CAUTION! Do NOT reset the maximum buffer size!
                // It was allocated and initialised at socket startup
                // and must remain unchanged.
                memset(*b, *NUMBER_0_INTEGER, *bs);
                *bc = *NUMBER_0_INTEGER;

        fprintf(stderr, "TEST 5 bc: %i \n", *((int*) p28));
        fprintf(stderr, "TEST 5 bs: %i \n", *((int*) p29));

            } else {

                log_message_debug("Error: Could not receive socket message. The buffer is null.");
            }

        } else {

            log_message_debug("Error: Could not receive socket message. The buffer count is null.");
        }

    } else {

        log_message_debug("Error: Could not receive socket message. The buffer size is null.");
    }
}

/**
 * Receives socket messages in an own thread.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 */
void receive_socket_thread(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* base = (int*) p1;

        log_message_debug("Receive socket messages in an own thread.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER;
        // The knowledge memory.
        void** k = NULL_POINTER;
        void** kc = NULL_POINTER;
        void** ks = NULL_POINTER;
        // The signal memory.
        void** s = NULL_POINTER;
        void** sc = NULL_POINTER;
        void** ss = NULL_POINTER;
        // The signal memory mutex.
        pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER;
        // The interrupt request flag.
        sig_atomic_t** irq = (sig_atomic_t**) NULL_POINTER;
        // The socket mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;
        // The model.
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        // The details.
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;
        // The commands.
        void** c = NULL_POINTER;
        void** cc = NULL_POINTER;
        // The language.
        void** l = NULL_POINTER;
        void** lc = NULL_POINTER;
        // The communication style.
        void** st = NULL_POINTER;
        void** stc = NULL_POINTER;
        // The original socket of this system.
        void** os = NULL_POINTER;
        // The original socket address of this system.
        void** oa = NULL_POINTER;
        void** oas = NULL_POINTER;
        // The communication partner-connected socket of this system.
        void** ps = NULL_POINTER;
        // The communication partner-connected socket address of this system.
        void** pa = NULL_POINTER;
        void** pas = NULL_POINTER;
        // The character buffer.
        void** b = NULL_POINTER;
        void** bc = NULL_POINTER;
        // The maximum buffer size.
        // CAUTION! A message MUST NOT be longer!
        void** bs = NULL_POINTER;
        // The prefixed parameter key.
        void** pk = NULL_POINTER;
        void** pkc = NULL_POINTER;
        void** pks = NULL_POINTER;

        // Get knowledge memory internal.
        get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory internal.
        get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory mutex.
        get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get interrupt request internal.
        get_element(p0, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get_element(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Lock socket mutex.
        //
        // CAUTION! A mutex is needed here to ensure that the commands- and other internals
        // and their associated count and size are retrieved at once and belong together.
        // Otherwise, e.g. a commands internal might be gotten in this "receive" thread,
        // then the "main" thread of cyboi might set a new commands internal, count
        // and size, and finally this "receive" thread would get a wrong count or size
        // (of the new commands internal), not belonging to the commands internal got before.
        pthread_mutex_lock(*mt);

        // Get model.
        i = *base + *SOCKET_MODEL_INTERNAL;
        get_element(p0, (void*) &i, (void*) &m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_MODEL_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_MODEL_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ms, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get details.
        i = *base + *SOCKET_DETAILS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_DETAILS_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_DETAILS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ds, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get commands.
        i = *base + *SOCKET_COMMANDS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMANDS_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get language.
        i = *base + *SOCKET_LANGUAGE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &l, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_LANGUAGE_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &lc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication style.
        i = *base + *SOCKET_STYLE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &st, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_STYLE_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &stc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get original socket of this system.
        i = *base + *SOCKET_INTERNAL;
        get_element(p0, (void*) &i, (void*) &os, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get original socket address of this system.
        i = *base + *SOCKET_ADDRESS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &oa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_ADDRESS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &oas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
        get_element(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket address.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get character buffer, which was set at socket startup.
        i = *base + *SOCKET_CHARACTER_BUFFER_INTERNAL;
        get_element(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get prefixed parameter key, which was set at socket startup.
        i = *base + *SOCKET_PREFIXED_PARAMETER_KEY_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pk, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_PREFIXED_PARAMETER_KEY_COUNT_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pkc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_PREFIXED_PARAMETER_KEY_SIZE_INTERNAL;
        get_element(p0, (void*) &i, (void*) &pks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Unlock socket mutex.
        pthread_mutex_unlock(*mt);

        while (*NUMBER_1_INTEGER) {

            // A break condition does not exist here because the loop
            // is blocking neverendingly while waiting for signals.
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service procedure
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

            // CAUTION! Hand over model, details and buffer as reference!
            receive_socket_message(*k, *kc, *ks, *s, *sc, *ss, *smt, *irq,
                m, *mc, *ms, d, *dc, *ds, *c, *cc, *l, *lc, *st, *stc,
                *os, *oa, *oas, *ps, *pa, *pas, *mt, b, *bc, *bs, pk, *pkc, *pks);

            // Sleep for some time to give the central processing unit (cpu)
            // time to breathe, that is to be idle or to process other signals.
            //
            // CAUTION! The "select" procedure was NOT used to make this socket
            // non-blocking, because it has some overhead in that other sockets
            // need to be considered and their file descriptors handed over as
            // parameter.
            // A simple "sleep" procedure is considered to be a more simple and
            // clean solution here.
            //
            // CAUTION! This is ONLY necessary if using a non-blocking socket!
            // sleep(1.0);

        log_message_debug("TEST: Break loop now ...");
            //?? TESTING only; delete later!
            break;
        }

    } else {

        log_message_debug("Error: Could not receive socket thread. The base internal is null.");
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the routine that was used to create it.
    // The pthread_exit() function does therefore not have to be called here.
    //
    // However, since this procedure runs an endless loop waiting for input,
    // and is NEVER left (does not have a "break" condition),
    // the loop and this thread can only be exited by an external signal
    // which is sent in the corresponding interrupt service procedure,
    // situated in the applicator/interrupt/ directory,
    // and processed in the interrupt_service_system_signal_handler procedure:
    // controller/manager/system_signal_handler_manager.c
}

/**
 * Receives www messages via socket.
 *
 * @param p0 the internal memory
 */
void receive_socket_www(void* p0) {

    log_message_debug("Receive www messages via socket.");

    receive_socket_thread(p0, (void*) WWW_BASE_INTERNAL);
}

/**
 * Receives cyboi messages via socket.
 *
 * @param p0 the internal memory
 */
void receive_socket_cyboi(void* p0) {

    log_message_debug("Receive cyboi messages via socket.");

    receive_socket_thread(p0, (void*) CYBOI_BASE_INTERNAL);
}

/**
 * Receives messages via socket.
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 * @param p2 the service thread
 * @param p3 the receive socket thread procedure
 * @param p4 the model
 * @param p5 the model count
 * @param p6 the model size
 * @param p7 the details
 * @param p8 the details count
 * @param p9 the details size
 * @param p10 the commands model
 * @param p11 the commands model count
 * @param p12 the language model
 * @param p13 the language model count
 * @param p14 the communication style model
 * @param p15 the communication style model count
 */
void receive_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    if (p2 != *NULL_POINTER) {

        int* t = (int*) p2;

        if (p1 != *NULL_POINTER) {

            int* b = (int*) p1;

            log_message_debug("Receive socket.");

            // The internal memory index.
            int i = *NUMBER_MINUS_1_INTEGER;
            // The socket mutex.
            pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;

            // Get socket mutex.
            i = *b + *SOCKET_MUTEX_INTERNAL;
            get_element(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Lock socket mutex.
            pthread_mutex_lock(*mt);

            // Adding the following parameters to the internal memory is necessary,
            // because only one parameter (the internal memory p0) can be forwarded
            // to the thread procedure further below. Thus, p0 MUST contain any others.

            // Set internals.
            //
            // CAUTION! A mutex is ACTUALLY not necessary, since the thread
            // procedures only read, but NOT write internal memory values.
            //
            // However, a mutex IS NECESSARY anyway, since the internal values
            // and their count and size should be set together, at once.
            // Otherwise, the thread procedures might read a new internal value
            // with the count or size of an old internal value, which would
            // lead to a segmentation fault and possibly system crash.

            // Set model internal.
            i = *b + *SOCKET_MODEL_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_MODEL_COUNT_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p5, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_MODEL_SIZE_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p6, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set details internal.
            i = *b + *SOCKET_DETAILS_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p7, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_DETAILS_COUNT_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p8, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_DETAILS_SIZE_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p9, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set commands internal.
            i = *b + *SOCKET_COMMANDS_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p10, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_COMMANDS_COUNT_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p11, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set language internal.
            i = *b + *SOCKET_LANGUAGE_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p12, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_LANGUAGE_COUNT_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p13, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set communication style internal.
            i = *b + *SOCKET_STYLE_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p14, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_STYLE_COUNT_INTERNAL;
            set_element(p0, (void*) &i, (void*) &p15, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Unlock socket mutex.
            pthread_mutex_unlock(*mt);

            // Only create thread, if not existent.
            // The "pthread_t" type is an integer, so both can be compared.
            if (*t == *NUMBER_MINUS_1_INTEGER) {

                // Create thread.
                //
                // CAUTION! Do NOT allocate any resources within the thread procedure!
                // The reason is that this main process thread gets forked when executing
                // external programs. A "fork" duplicates ALL resources of the parent process,
                // including ALL resources of any threads running within the parent process.
                // However, since the created child process does not have those threads running,
                // their duplicated resources will never be deallocated, which eats up memory.
                // See source code file: applicator/run/run_execute.c
                //
                // Any dynamically allocated resources needed within the thread have to be:
                // - allocated at service startup
                // - added to the internal memory
                // - handed over to the thread procedure HERE
                // - deallocated at service shutdown

                log_message_debug("Create socket receive thread.");

                // Create thread.
                // The third parameter is the procedure to be called.
                pthread_create((pthread_t*) t, *NULL_POINTER, p3, p0);
            }

        } else {

            log_message_debug("Could not receive socket. The base internal is null.");
        }

    } else {

        log_message_debug("Could not receive socket. The service thread is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_SOCKET_SOURCE */
#endif
