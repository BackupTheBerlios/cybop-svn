/*
 * $RCSfile: receive_tcp_socket.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.32 $ $Date: 2006-12-25 12:41:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef RECEIVE_TCP_SOCKET_SOURCE
#define RECEIVE_TCP_SOCKET_SOURCE

#ifdef LINUX_OPERATING_SYSTEM

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "../../applicator/receive/receive_file_system.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/escape_code_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/constants/system_constants.c"
#include "../../globals/constants/tcp_socket_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/internal_memory_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

//
// Forward declarations.
//

/**
 * Receives a file system model.
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
/*??
void receive_file_system_model(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8);

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
/*??
void get_request_method(char* req, int* req_count, char** req_method, int* req_method_count) {

    *req_method_count = 0;

    // The element.
    char* e = NULL_POINTER;

    while (1) {

        if (*req_method_count >= *req_count) {

            break;
        }

        get_array_elements(req, req_method_count, (void*) &e, (void*) CHARACTER_ARRAY);

        if (*e == *SPACE_ASCII_CHARACTER) {

            // Reached end of request method.
            break;
        }

        int max_count = *req_method_count + 1;

        reallocate_array((void*) req_method, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
        set_array_elements(*req_method, req_method_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

        *req_method_count = *req_method_count + 1;
    }
}

/**
 * Gets the request parameter from the request row.
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
/*??
void receive_tcp_socket_url(char* req, int* req_count, char** urlbase, int* urlbase_count) {

    *urlbase_count = 0;
    int req_index = 0;
    int start_urlbase_flag = 0;
    int max_count = 0;
    // The element.
    char* e = NULL_POINTER;

    while (1) {

        if (req_index >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of ending the paramaters.
        if ((start_urlbase_flag == 1) && ((*e == *SPACE_ASCII_CHARACTER) || (*e == *QUESTION_MARK_ASCII_CHARACTER))) {

            break;
        }

        // Complete the parameters.
        if (start_urlbase_flag == 1) {

            max_count = *urlbase_count + 1;

            reallocate_array((void*) urlbase, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
            set_array_elements(*urlbase, urlbase_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            *urlbase_count = *urlbase_count + 1;
        }

        // Check of beginning the paramaters.
        if (*e == *SOLIDUS_ASCII_CHARACTER) {

            // Begin from the parameters.
            start_urlbase_flag = 1;
        }

        req_index++;
    }
}

/**
 * Get the chracter from a escape code
 * in the first position of the source array.
 * if it is no escape code, then ist the destination
 * equal the source
 *
 * Example: %25 --> %
 *
 * @param source the source (
 * @param source_count the count of the request row
 * @param dest param the parameter from the request
 */
/*??
void* get_character_from_escape_code(void* source, int* source_count, char** dest) {

    if ((source != NULL_POINTER) && (source_count != NULL_POINTER) && (dest != NULL_POINTER)) {

        int r = 0;

        //esquape code must be 3 signs
        if (*source_count >= *ESCAPE_CODE_CHARACTER_COUNT) {

            // space character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, SPACE_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) SPACE_ASCII_CHARACTER;
                }
            }

            // less than sign character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, LESS_THAN_SIGN_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) LESS_THAN_SIGN_ASCII_CHARACTER;
                }
            }

            // greater than sign character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, GREATER_THAN_SIGN_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) GREATER_THAN_SIGN_ASCII_CHARACTER;
                }
            }

            // nummer sign character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, NUMBER_SIGN_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) NUMBER_SIGN_ASCII_CHARACTER;
                }
            }

            // percent sign character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, PERCENT_SIGN_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) PERCENT_SIGN_ASCII_CHARACTER;
                }
            }

            // left curly bracket character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, LEFT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) LEFT_CURLY_BRACKET_ASCII_CHARACTER;
                }
            }

            // right curly bracket character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, RIGHT_CURLY_BRACKET_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) RIGHT_CURLY_BRACKET_ASCII_CHARACTER;
                }
            }

            // vertical line character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, VERTICAL_LINE_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) VERTICAL_LINE_ASCII_CHARACTER;
                }
            }

            // reverse solidus character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, REVERSE_SOLIDUS_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) REVERSE_SOLIDUS_ASCII_CHARACTER;
                }
            }

            // CIRCUMFLEX_ACCENT_CHARACTER
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, CIRCUMFLEX_ACCENT_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) CIRCUMFLEX_ACCENT_ASCII_CHARACTER;
                }
            }

            // tilde character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, TILDE_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) TILDE_ASCII_CHARACTER;
                }
            }

            //left square character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, LEFT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) LEFT_SQUARE_BRACKET_ASCII_CHARACTER;
                }
            }

            // right square character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, RIGHT_SQUARE_BRACKET_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) RIGHT_SQUARE_BRACKET_ASCII_CHARACTER;
                }
            }

            // grave accent character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, GRAVE_ACCENT_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) GRAVE_ACCENT_ASCII_CHARACTER;
                }
            }

            // semikolon character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, SEMICOLON_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) SEMICOLON_ASCII_CHARACTER;
                }
            }

            // soldius character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, SOLIDUS_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) SOLIDUS_ASCII_CHARACTER;
                }
            }

            // question mark character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, QUESTION_MARK_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) QUESTION_MARK_ASCII_CHARACTER;
                }
            }

            //colon character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, COLON_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) COLON_ASCII_CHARACTER;
                }
            }

            //commercial at character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, COMMERCIAL_AT_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) COMMERCIAL_AT_ASCII_CHARACTER;
                }
            }

            // Equal sign character.
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, EQUALS_SIGN_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) EQUALS_SIGN_ASCII_CHARACTER;
                }
            }

            // Ampersand character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, AMPERSAND_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) AMPERSAND_ASCII_CHARACTER;
                }
            }

            //dollar  character
            if (r == 0) {

                compare_arrays(source, ESCAPE_CODE_CHARACTER_COUNT, DOLLAR_SIGN_CHARACTER_ESCAPE_CODE, ESCAPE_CODE_CHARACTER_COUNT, &r, CHARACTER_ARRAY);

                if (r == 1) {

                    *dest = (char*) DOLLAR_SIGN_ASCII_CHARACTER;
                }
            }
        }

        // no escape code
        if (r == 0) {

            *dest = source;
        }
    }
}

/**
 * Get the parameters from the request for the request method post.
 * The parameters are in the last row from the request
 *
 * @param req the request
 * @param req_count the request count
 * @param param the parameter
 * @param param_count the paramater count
 */
/*??
void receive_tcp_socket_parameter_for_post(char* req, int* req_count, char** param, int* param_count) {

    *param_count = 0;
    int req_index = *req_count-1;
    int req_last_count = 0;
    int start_param_index = -1;
    int max_count = 0;
    // The element.
    char* e = NULL_POINTER;

    //get the index for beginning the paramaters
    while (1) {

        if (req_index < 0 ) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of beginning  the paramaters.
        if ((*e == *LINE_FEED_CONTROL_ASCII_CHARACTER)) {

            start_param_index = req_index + 1;
            break;
        }

        req_index = req_index - 1;
    }

    // set the parameters from the request
    if (start_param_index > 0) {

        req_index = start_param_index;

        while (1) {

            if (req_index >= *req_count ) {

                break;
            }

            max_count = *param_count + 1;

            reallocate_array((void*) param, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
            get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);
            set_array_elements(*param, param_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            *param_count = *param_count + 1;
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
/*??
void receive_tcp_socket_parameter_for_get(char* req, int* req_count, char** param, int* param_count) {

    *param_count = 0;
    int req_index = 0;
    int start_param_flag = 0;
    int max_count = 0;
    // The element.
    char* e = NULL_POINTER;

    while (1) {

        if (req_index >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of ending the paramaters.
        if ((start_param_flag == 1) && (*e == *SPACE_ASCII_CHARACTER)) {

            break;
        }

        // Complete the parameters.
        if (start_param_flag == 1) {

            max_count = *param_count + 1;

            reallocate_array((void*) param, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
            set_array_elements(*param, param_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            *param_count = *param_count + 1;
        }

        // Check of beginning the paramaters.
        if (*e == *QUESTION_MARK_ASCII_CHARACTER) {

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
/*??
void receive_tcp_socket_parameter(char* req, int* req_count, char** param, int* param_count) {

    // Check the request method ( post or get );
    int req_meth_post_res = 0;

    compare_arrays(req, POST_REQUEST_METHOD_COUNT, POST_REQUEST_METHOD, POST_REQUEST_METHOD_COUNT, &req_meth_post_res, CHARACTER_ARRAY);

    if (req_meth_post_res == 0) {

        receive_tcp_socket_parameter_for_get(req, req_count, param, param_count);

    } else {

        receive_tcp_socket_parameter_for_post(req, req_count, param, param_count);
    }
}

/**
 * create a signal with the set operation
 * dest must for the abstraction a knowledge
 * source must be a string, depenc from the abstraction
 * of the source
 *
 * @param source the source
 * @param source_count the source count
 * @param dest the destination
 * @param dest_count the detsination count
 * @param p4 the internal memory
 */
/*??
void set_signal_for_parameter(void* source, int* source_count, void* dest, int* dest_count, void* p4) {

    // check of null pointer
    if ((source != NULL_POINTER) &&
        (source_count != NULL_POINTER) &&
        (dest != NULL_POINTER) &&
        (dest_count != NULL_POINTER) &&
        (p4 != NULL_POINTER)) {

        // The knowledge memory.
        void** km = &NULL_POINTER;
        void** kmc = &NULL_POINTER;
        void** kms = &NULL_POINTER;

        // Get knowledge memory.
        get(p4, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &km, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p4, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kmc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p4, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &kms, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        //
        //  the signal
        //

        // The signal abstraction.
        void* sa = NULL_POINTER;
        int* sac = NULL_POINTER;
        int* sas = NULL_POINTER;

        // The signal model.
        void* sm = NULL_POINTER;
        int* smc = NULL_POINTER;
        int* sms = NULL_POINTER;

        // The signal details.
        void* sd = NULL_POINTER;
        int* sdc = NULL_POINTER;
        int* sds = NULL_POINTER;

        // Create signal abstraction.
        allocate(&sac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sac = 0;
        allocate(&sas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sas = 0;
        receive_file_system_model((void*) &sa, (void*) sac, (void*) sas,
            (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create signal model.
        allocate(&smc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *smc = 0;
        allocate(&sms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sms = 0;
        receive_file_system_model((void*) &sm, (void*) smc, (void*) sms,
            (void*) COPY_MODEL, (void*) COPY_MODEL_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create signal detail.
        allocate(&sdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sdc = 0;
        allocate(&sds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sds = 0;
        receive_file_system_model((void*) &sd, (void*) sdc, (void*) sds,
            (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
            (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);


        //
        //  the property destination
        //

        // The property destination name.
        void* pdn = NULL_POINTER;
        int* pdnc = NULL_POINTER;
        int* pdns = NULL_POINTER;

        // The property destination abstraction.
        void* pda = NULL_POINTER;
        int* pdac = NULL_POINTER;
        int* pdas = NULL_POINTER;

        // The property destination model.
        void* pdm = NULL_POINTER;
        int* pdmc = NULL_POINTER;
        int* pdms = NULL_POINTER;

        // The property destination details.
        void* pdd = NULL_POINTER;
        int* pddc = NULL_POINTER;
        int* pdds = NULL_POINTER;

        // Create property destination name.
        allocate(&pdnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdnc = 0;
        allocate(&pdns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdns = 0;
        receive_file_system_model((void*) &pdn, (void*) pdnc, (void*) pdns,
            (void*) COPY_DESTINATION_NAME, (void*) COPY_DESTINATION_NAME_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property destination abstraction.
        allocate(&pdac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdac = 0;
        allocate(&pdas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdas = 0;
        receive_file_system_model((void*) &pda, (void*) pdac, (void*) pdas,
            (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property destination model.
        allocate(&pdmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdmc = 0;
        allocate(&pdms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdms = 0;
        receive_file_system_model((void*) &pdm, (void*) pdmc, (void*) pdms,
            (void*) dest, (void*) dest_count,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property source detail.
        // is empty

        //
        //  the property source
        //

        // The property source name.
        void* psn = NULL_POINTER;
        int* psnc = NULL_POINTER;
        int* psns = NULL_POINTER;

        // The property  source abstraction.
        void* psa = NULL_POINTER;
        int* psac = NULL_POINTER;
        int* psas = NULL_POINTER;

        // The property  source model.
        void* psm = NULL_POINTER;
        int* psmc = NULL_POINTER;
        int* psms = NULL_POINTER;

        // The property  source details.
        void* psd = NULL_POINTER;
        int* psdc = NULL_POINTER;
        int* psds = NULL_POINTER;

        // Create property source name.
        allocate(&psnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psnc = 0;
        allocate(&psns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psns = 0;
        receive_file_system_model((void*) &psn, (void*) psnc, (void*) psns,
            (void*) COPY_SOURCE_NAME, (void*) COPY_SOURCE_NAME_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);


        // Create property source abstraction.
        allocate(&psac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psac = 0;
        allocate(&psas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psas = 0;
        receive_file_system_model((void*) &psa, (void*) psac, (void*) psas,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property source model.
        // todo: expansion for other types
        allocate(&psmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psmc = 0;
        allocate(&psms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psms = 0;
        receive_file_system_model((void*) &psm, (void*) psmc, (void*) psms,
            (void*) source, (void*) source_count,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property source detail.
        // is empty

        // Add property source to the signal detail compound.
        set_compound_element_by_name(sd, sdc, sds, NULL_POINTER, NULL_POINTER, NULL_POINTER,
            psn, (void*) psnc, (void*) psns,
            psa, (void*) psac, (void*) psas,
            psm, (void*) psmc, (void*) psms,
            psd, (void*) psdc, (void*) psds);

        // Add property destination to the detail compound.
        set_compound_element_by_name(sd, sdc, sds, NULL_POINTER, NULL_POINTER, NULL_POINTER,
            pdn, (void*) pdnc, (void*) pdns,
            pda, (void*) pdac, (void*) pdas,
            pdm, (void*) pdmc, (void*) pdms,
            pdd, (void*) pddc, (void*) pdds);


        //
        // Signal.
        //

        log_message_debug("Set start signal.");

        // The signal memory.
        void** m = &NULL_POINTER;
        void** mc = &NULL_POINTER;
        void** ms = &NULL_POINTER;

        // Get signal memory.
        get(p4, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p4, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p4, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Lock signal memory mutex.
//??        pthread_mutex_lock(*mt);

        // The signal id.
        int* id = NULL_POINTER;
        allocate(&id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *id = 0;
        get_new_signal_id(*m, *mc, (void*) id);

        // Set signal.
        set_signal(*m, *mc, *ms, (void*) sa, (void*) sac, (void*) sm, (void*) smc, (void*) sd, (void*) sdc, (void*) NORMAL_PRIORITY, (void*) id);

        // Set interrupt request flag, in order to notify the signal checker
        // that a new signal has been placed in the signal memory.
//??        **irq = *NUMBER_1_INTEGER;

        // Unlock signal memory mutex.
//??        pthread_mutex_unlock(*mt);
    }
}

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
    if ((p0 != NULL_POINTER) && (p1 != NULL_POINTER) && (p2 != NULL_POINTER)) {

        int query_counter = 0;

        //paramater
        char* param = NULL_POINTER;
        int* param_count = NULL_POINTER;
        int* param_size = NULL_POINTER;

        //value for the parameter
        char* value = NULL_POINTER;
        int* value_count = NULL_POINTER;
        int* value_size = NULL_POINTER;

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
        int r = 0;

        //elements from the array
        void* element = NULL_POINTER;
        //elements from the array
        void* decode_element = NULL_POINTER;
        int last_query_count = 0;

        //temp count  for comparision
        int temp_count = 1;

        while (1) {

            if (query_counter >= *p1) {

                break;
            }

            // param
            *param_count = 0;
            r = 0;

            while (1) {

                get_array_elements((void*) p0, (void*) &query_counter, (void*) &element, CHARACTER_ARRAY);

                compare_arrays(element, &temp_count, EQUALS_SIGN_ASCII_CHARACTER, PRIMITIVE_COUNT, &r, CHARACTER_ARRAY);

                if ((query_counter >= *p1) || (r == 1)) {

                    query_counter = query_counter + 1;
                    break;
                }

                //the element must insert into the param
                last_query_count = *p1 - query_counter;

                get_character_from_escape_code(element, &last_query_count, (char**) &decode_element);
                set_array_elements(param, param_count, decode_element, &temp_count, CHARACTER_ARRAY);

                if (element == decode_element) {

                    query_counter = query_counter + 1;

                } else {

                    query_counter = query_counter + *ESCAPE_CODE_CHARACTER_COUNT;
                }

                *param_count = *param_count + 1;
            }

            //value
            *value_count = 0;
            r = 0;

            while (1) {

                get_array_elements((void*) p0, (void*) &query_counter, (void*) &element, CHARACTER_ARRAY);

                compare_arrays(element, &temp_count, AMPERSAND_ASCII_CHARACTER, PRIMITIVE_COUNT, &r, CHARACTER_ARRAY);

                if ((query_counter >= *p1) || (r == 1)) {

                    query_counter = query_counter + 1;
                    break;
                }

                //the element must insert into the value
                last_query_count = *p1 - query_counter;
                get_character_from_escape_code(element, &last_query_count, (char**) &decode_element);
                set_array_elements(value, value_count, decode_element, &temp_count, CHARACTER_ARRAY);

                if (element == decode_element) {

                    query_counter = query_counter + 1;

                } else {

                    query_counter = query_counter + *ESCAPE_CODE_CHARACTER_COUNT;
                }

                *value_count = *value_count + 1;
            }

            //set the signal for the paramater and the value
            if (*param_count > 0) {

                set_signal_for_parameter(value, value_count, param, param_count, p2);
            }
        }
    }
}

/**
 * Receives tcp socket signal.
 *
 * The http request must be parsed for parameters!
 * A cyboi-internal signal is created and added to the signal memory, for each parameter.
 *
 * @param p0 the internal memory
 * @param p1 the buffer
 * @param p2 the buffer count
 * @param p3 the client socket
 */
void receive_tcp_socket_signal(void* p0, void* p1, void* p2, void* p3) {

    log_message_debug("TEST: Receive tcp socket signal.");

fprintf(stderr, "TEST: receive tcp socket signal buffer: %s \n", (char*) p1);
fprintf(stderr, "TEST: receive tcp socket signal buffer count: %i \n", *((int*) p2));

    // The knowledge memory.
    void** k = &NULL_POINTER;
    void** kc = &NULL_POINTER;
    void** ks = &NULL_POINTER;
    // The signal memory.
    void** s = &NULL_POINTER;
    void** sc = &NULL_POINTER;
    void** ss = &NULL_POINTER;
    // The signal memory mutex.
    pthread_mutex_t** smt = (pthread_mutex_t**) &NULL_POINTER;
    // The tcp socket mutex.
    pthread_mutex_t** tmt = (pthread_mutex_t**) &NULL_POINTER;
    // The interrupt request flag.
    sig_atomic_t** irq = (sig_atomic_t**) &NULL_POINTER;
    // The user interface commands.
    void** c = &NULL_POINTER;
    void** cc = &NULL_POINTER;
    void** cs = &NULL_POINTER;

    // The command abstraction.
    void** ca = &NULL_POINTER;
    void** cac = &NULL_POINTER;
    void** cas = &NULL_POINTER;
    // The command model.
    void** cm = &NULL_POINTER;
    void** cmc = &NULL_POINTER;
    void** cms = &NULL_POINTER;
    // The command details.
    void** cd = &NULL_POINTER;
    void** cdc = &NULL_POINTER;
    void** cds = &NULL_POINTER;

    // The signal id.
    int* id = NULL_POINTER;

    // Get knowledge memory internal.
    get(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internal.
    get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get tcp socket mutex.
    get(p0, (void*) TCP_SOCKET_MUTEX_INTERNAL, (void*) &tmt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get(p0, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Lock tcp socket mutex.
    //
    // CAUTION! A mutex is needed here to ensure that the commands internal
    // and its associated count and size are retrieved at once and belong together.
    // Otherwise, a commands internal might be got in this "receive" thread,
    // then the "main" thread of cyboi might set a new commands internal, count
    // and size, and finally this "receive" thread would get a wrong count or size
    // (of the new commands internal), not belonging to the commands internal got before.
    pthread_mutex_lock(*tmt);

    // Get user interface commands internal.
    get(p0, (void*) TCP_SOCKET_THREAD_COMMANDS_INTERNAL, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_SOCKET_THREAD_COMMANDS_COUNT_INTERNAL, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_SOCKET_THREAD_COMMANDS_SIZE_INTERNAL, (void*) &cs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Unlock tcp socket mutex.
    pthread_mutex_unlock(*tmt);

    // Get actual command belonging to the command name.
    // If the name is not known, the command parameter is left untouched.
    get_universal_compound_element_by_name(*c, *cc,
        p1, p2,
        (void*) &ca, (void*) &cac, (void*) &cas,
        (void*) &cm, (void*) &cmc, (void*) &cms,
        (void*) &cd, (void*) &cdc, (void*) &cds,
        *k, *kc);

    // Lock signal memory mutex.
    pthread_mutex_lock(*smt);

    // Allocate signal id.
    allocate((void*) &id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *id = 0;
    get_new_signal_id(*s, *sc, (void*) id);

    // Add signal to signal memory.
    set_signal(*s, *sc, *ss, *ca, *cac, *cm, *cmc, *cd, *cdc, (void*) NORMAL_PRIORITY, (void*) id);

/*??
    add_signal_id(p0, (void*) id);
    add_client_socket_number(p0, (void*) cs);
*/

    // Set interrupt request flag, in order to notify the signal checker
    // that a new signal has been placed in the signal memory.
    **irq = *NUMBER_1_INTEGER;

    // Unlock signal memory mutex.
    pthread_mutex_unlock(*smt);
}

/**
 * Receives tcp socket messages (http requests) in an own thread.
 *
 * For web frontend testing, use:
 * http://localhost:3456/residenz.logic.send_name
 *
 * @param p0 the internal memory
 */
void receive_tcp_socket_thread(void* p0) {

    // The tcp server socket.
    int** s = (int**) &NULL_POINTER;
    // The client socket address.
    struct sockaddr_in ca;
    // Get client socket address size.
    socklen_t cas = sizeof(struct sockaddr_in);
    // The client socket.
    int cs = *INVALID_VALUE;
    // The character buffer.
    void** b = &NULL_POINTER;
    int** bc = (int**) &NULL_POINTER;
    // The maximum buffer size.
    // CAUTION! A message MUST NOT be longer!
    int** bs = (int**) &NULL_POINTER;

    // Get tcp server socket.
    get(p0, (void*) TCP_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get character buffer.
    get(p0, (void*) TCP_SOCKET_THREAD_CHARACTER_BUFFER_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_SOCKET_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get(p0, (void*) TCP_SOCKET_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    while (1) {

        // A break condition does not exist here because the loop
        // is blocking neverendingly while waiting for signals.
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service procedure
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

        // Accept client socket request and store client socket.
        //
        // Accepting a connection does not make the client socket part of the
        // connection. Instead, it creates a new socket which becomes connected.
        // The normal return value of "accept" is the file descriptor for the new socket.
        //
        // After "accept", the original socket socket remains open and
        // unconnected, and continues listening until it gets closed.
        // One can accept further connections with socket by calling
        // "accept" again -- therefore the loop!
        //
        // CAUTION! This function is defined as a cancellation point in
        // multi-threaded programs, so one has to be prepared for this and
        // make sure that allocated resources (like memory, files descriptors,
        // semaphores or whatever) are freed even if the thread is canceled!
fprintf(stderr, "TEST: receive tcp socket thread server socket: %i \n", **s);

fprintf(stderr, "TEST: receive tcp socket thread client socket pre: %i \n", cs);

        cs = accept(**s, (struct sockaddr*) &ca, &cas);

fprintf(stderr, "TEST: receive tcp socket thread client socket post: %i \n", cs);

        if (cs >= *NUMBER_0_INTEGER) {

            // Receive message from client.
            // If the flags argument (fourth one) is zero, then one can
            // just as well use the "read" instead of the "recv" procedure.
            // Normally, "recv" blocks until there is input available to be read.
            // CAUTION! A message MUST NOT be longer than the given buffer size!
            **bc = recv(cs, *b, **bs, *NUMBER_0_INTEGER);

            if (**bc >= *NUMBER_0_INTEGER) {

                // Receive tcp socket signal.
                receive_tcp_socket_signal(p0, *b, (void*) *bc, (void*) &cs);

/*??
                // The url basename.
                char* url_basename = NULL_POINTER;
                int url_basename_count = 0;
                // Create url basename.
                allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) CHARACTER_ARRAY);
                // Get url base name.
                receive_tcp_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

                // The parameter.
                char* param = NULL_POINTER;
                int param_count = 0;
                // Create paramater.
                allocate_array((void*) &param, (void*) &param_count, (void*) CHARACTER_ARRAY);
                // Get parameters.
                receive_tcp_socket_parameter(msg, &msg_count, &param, &param_count);

                // The firefox web browser makes a second request
                // to determine the favicon.
                char firefox_request[] = "favicon.ico";
                char* p_firefox_request = &firefox_request[0];
                int firefox_request_count = 11;

                // The comparison result.
                int r = 0;
                compare_arrays((void*) url_basename, (void*) &url_basename_count, (void*) p_firefox_request, (void*) &firefox_request_count, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 1) {

                    // query string handling
                    set_signals_for_all_parameters((void*) param, (void*) &param_count, p0);

                    //?? The OLD solution created a signal here from a cybol knowledge template.
                    //?? This is NOW easier, since the commands already exist in the knowledge tree
                    //?? and only have to be referenced from here.

                } else {

                    close(*cs);
                }
*/

            } else {

                log_message_debug("ERROR: Could not receive tcp socket thread. The receive operation failed.");
            }

        } else if (cs < *NUMBER_0_INTEGER) {

            log_message_debug("ERROR: Could not receive tcp socket thread. The client socket is invalid.");
        }
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
 * Receives web user interface (wui) messages via tcp socket.
 *
 * @param p0 the internal memory
 */
void receive_tcp_socket(void* p0) {

    log_message_debug("Receive tcp socket message.");

    // Only create thread, if not existent.
    if (*TCP_SOCKET_THREAD == *INVALID_VALUE) {

        log_message_debug("Create new tcp socket receive service thread.");

fprintf(stderr, "TEST: Create new tcp socket receive service thread: %d \n", *TCP_SOCKET_THREAD);

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
        pthread_create(TCP_SOCKET_THREAD, NULL_POINTER, (void*) &receive_tcp_socket_thread, p0);

        sleep(2);

fprintf(stderr, "TEST: After create new tcp socket receive service thread: %d \n", *TCP_SOCKET_THREAD);

//?? Following is a TEST -- delete later!

        printf("Bitte geben Sie ein Wort ein! ");
        char eingabe[sizeof(*stdin)];
//??        char eingabe[5];
        scanf("%s", eingabe);

        int socketnummer=socket(AF_INET,SOCK_STREAM,0);
        fprintf(stderr, "TEST: socketnummer: %i \n", socketnummer);

        struct sockaddr_in adressstruktur;
        adressstruktur.sin_family=AF_INET;
        adressstruktur.sin_addr.s_addr=inet_addr("127.0.0.1");
        adressstruktur.sin_port=3456; //?? 9735;
        int laenge=sizeof(adressstruktur);
        int result=connect(socketnummer, (struct sockaddr *) &adressstruktur, laenge);

        if(result== -1) {
            perror("huch der client hat einen Fehler");
            exit(1);
        } else{
            printf("Verbindung zum Server hergestellt\n");
        }

        int i=0;

        while (i<10) {

            sleep(2);
            write(socketnummer, &eingabe, 5);
            printf("sende: %s\n", eingabe);
            read(socketnummer, &eingabe, 300);
            printf("empfange: %s\n", eingabe);
            i++;
        }

        close(socketnummer);
    }
}

/* LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_TCP_SOCKET_SOURCE */
#endif
