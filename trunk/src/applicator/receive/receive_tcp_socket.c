/*
 * $RCSfile: receive_tcp_socket.c,v $
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
 * @version $Revision: 1.25 $ $Date: 2006-02-20 16:17:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef RECEIVE_TCP_SOCKET_SOURCE
#define RECEIVE_TCP_SOCKET_SOURCE

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "../../applicator/create.c"
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/character_constants.c"
#include "../../globals/constants/constant.c"
#include "../../globals/constants/escape_code_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/model_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/constants/structure_constants.c"
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
void create(void* p0, void* p1, void* p2, void* p3, void* p4,
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
void get_url_basename_from_request(char* req, int* req_count, char** urlbase, int* urlbase_count) {

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
void get_parameter_from_request_for_post(char* req, int* req_count, char** param, int* param_count) {

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
void get_parameter_from_request_for_get(char* req, int* req_count, char** param, int* param_count) {

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
void get_parameter_from_request(char* req, int* req_count, char** param, int* param_count) {

    // Check the request method ( post or get );
    int req_meth_post_res = 0;

    compare_arrays(req, REQEUST_METHOD_POST_COUNT, REQEUST_METHOD_POST, REQEUST_METHOD_POST_COUNT, &req_meth_post_res, CHARACTER_ARRAY);

    if (req_meth_post_res == 0) {

        get_parameter_from_request_for_get(req, req_count, param, param_count);

    } else {

        get_parameter_from_request_for_post(req, req_count, param, param_count);
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
        create((void*) &sa, (void*) sac, (void*) sas,
            (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create signal model.
        allocate(&smc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *smc = 0;
        allocate(&sms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sms = 0;
        create((void*) &sm, (void*) smc, (void*) sms,
            (void*) COPY_MODEL, (void*) COPY_MODEL_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create signal detail.
        allocate(&sdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sdc = 0;
        allocate(&sds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *sds = 0;
        create((void*) &sd, (void*) sdc, (void*) sds,
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
        create((void*) &pdn, (void*) pdnc, (void*) pdns,
            (void*) DESTINATION_NAME,
            (void*) DESTINATION_NAME_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property destination abstraction.
        allocate(&pdac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdac = 0;
        allocate(&pdas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdas = 0;
        create((void*) &pda, (void*) pdac, (void*) pdas,
            (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property destination model.
        allocate(&pdmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdmc = 0;
        allocate(&pdms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *pdms = 0;
        create((void*) &pdm, (void*) pdmc, (void*) pdms,
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
        create((void*) &psn, (void*) psnc, (void*) psns,
            (void*) SOURCE_NAME,
            (void*) SOURCE_NAME_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);


        // Create property source abstraction.
        allocate(&psac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psac = 0;
        allocate(&psas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psas = 0;
        create((void*) &psa, (void*) psac, (void*) psas,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property source model.
        // todo: expansion for other types
        allocate(&psmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psmc = 0;
        allocate(&psms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        *psms = 0;
        create((void*) &psm, (void*) psmc, (void*) psms,
            (void*) source, (void*) source_count,
            (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
            (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

        // Create property source detail.
        // is empty

        // Add property source to the signal detail compound.
        set_compound_element_by_name(sd, sdc, sds,
            psn, (void*) psnc, (void*) psns,
            psa, (void*) psac, (void*) psas,
            psm, (void*) psmc, (void*) psms,
            psd, (void*) psdc, (void*) psds);

        // Add property destination to the detail compound.
        set_compound_element_by_name(sd, sdc, sds,
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

        // The signal id.
        int* id = NULL_POINTER;
        allocate(&id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
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
 * Handles a tcp socket request.
 *
 * The http request must be parsed for parameters.
 * A signal is created and added to the signal memory, for each parameter.
 *
 * @param p0 the internal memory
 * @param p1 the client socket
 */
void handle_tcp_socket_request(void* p0, void* p1) {

/*??
    For web frontend testing, use:
    http://localhost:3456/resadmin/logic/send_name.cybol
*/

    if (p1 != NULL_POINTER) {

        int* cs = (int*) p1;

        log_message_debug("Handle tcp socket request.");

        // The message.
        char* msg = NULL_POINTER;
        // The maximum message count.
        int max_msg_count = 2048;

        // Create message.
        allocate_array((void*) &msg, (void*) &max_msg_count, (void*) CHARACTER_ARRAY);

        // Receive message from client.
        int msg_count = recv(*cs, msg, max_msg_count, 0);

        if (msg_count != -1) {

            // The url basename.
            char* url_basename = NULL_POINTER;
            int url_basename_count = 0;

            // Create url basename.
            allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) CHARACTER_ARRAY);

            // Get url base name.
            get_url_basename_from_request(msg, &msg_count, &url_basename, &url_basename_count);

            // The parameter.
            char* param = NULL_POINTER;
            int param_count = 0;

            // Create paramater.
            allocate_array((void*) &param, (void*) &param_count, (void*) CHARACTER_ARRAY);

            // Get parameters.
            get_parameter_from_request(msg, &msg_count, &param, &param_count);

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

                log_message_debug("Allocate destination abstraction, model, details.");

                // The source channel.
                char c_sc[] = "file";
                char* sc = &c_sc[0];
                int* scc = NULL_POINTER;
                allocate(&scc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *scc = 4;

                // The source abstraction.
                char c_sa[] = "cybol";
                char* sa = &c_sa[0];
                int* sac = NULL_POINTER;
                allocate(&sac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *sac = 5;

                // The source model.
                char* sm = url_basename;
                int* smc = NULL_POINTER;
                allocate(&smc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *smc = url_basename_count;

                // The destination abstraction.
                void* da = NULL_POINTER;
                int* dac = NULL_POINTER;
                allocate(&dac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dac = 0;
                int* das = NULL_POINTER;
                allocate(&das, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *das = 0;

                // The destination model.
                void* dm = NULL_POINTER;
                int* dmc = NULL_POINTER;
                allocate(&dmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dmc = 0;
                int* dms = NULL_POINTER;
                allocate(&dms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dms = 0;

                // The destination details.
                void* dd = NULL_POINTER;
                int* ddc = NULL_POINTER;
                allocate(&ddc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *ddc = 0;
                int* dds = NULL_POINTER;
                allocate(&dds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                *dds = 0;

                // Create destination abstraction.
                create((void*) &da, (void*) dac, (void*) das,
                    (void*) sa, (void*) sac,
                    (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                    (void*) INLINE_CHANNEL, (void*) INLINE_CHANNEL_COUNT);

                // Create destination model.
                create((void*) &dm, (void*) dmc, (void*) dms,
                    (void*) sm, (void*) smc,
                    (void*) sa, (void*) sac,
                    (void*) sc, (void*) scc);

                //
                // Signal.
                //

                log_message_debug("Set start signal.");

                // The signal memory.
                void** m = &NULL_POINTER;
                void** mc = &NULL_POINTER;
                void** ms = &NULL_POINTER;

                // Get signal memory.
                get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ms, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                // The signal id.
                int* id = NULL_POINTER;
                allocate(&id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
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
 * Runs the tcp socket server for one accept.
 *
 * @param p0 the internal memory
 */
void run_tcp_socket(void* p0) {

    // The tcp server socket.
    void** s = &NULL_POINTER;

    // Get tcp server socket.
    get(p0, (void*) TCP_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    if (s != NULL_POINTER) {

        if (*s != NULL_POINTER) {

            log_message_debug("Run tcp socket.");

            // The client socket address.
            struct sockaddr_in ca;

            // Determine client socket address size.
            int cas = sizeof(ca);

            // Accept client socket request and store client socket.
            int cs = accept(**((int**) s), (struct sockaddr*) &ca, (socklen_t*) &cas);

            if (cs >= 0) {

                log_message_debug("DEBUG: Accepted tcp client socket request.");
                handle_tcp_socket_request(p0, (void*) &cs);

            } else {

                fprintf(stderr, "Could not run tcp socket. The accept failed.");
                pthread_exit(NULL_POINTER);
            }

        } else {

            log_message_debug("Could not run tcp socket. The socket is null.");
        }

    } else {

        log_message_debug("Could not run tcp socket. The socket is null.");
    }
}

/**
 * Runs a thread listening on the tcp socket.
 *
 * It is to avoid blocking of the main signal checker loop.
 * The thread exits if the active flag is false.
 *
 * @param p0 the internal memory
 */
void run_tcp_socket_server(void* p0) {

    // The interrupt flag.
    int** f = (int**) &NULL_POINTER;

    get(p0, (void*) TCP_SOCKET_INTERRUPT_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    while (1) {

        if (**f == *NUMBER_1_INTEGER) {

            break;
        }

        run_tcp_socket(p0);
    }

    pthread_exit(NULL_POINTER);
}

/**
 * Receives via tcp socket.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param blocking_abstr the blocking abtsraction
 * @param blocking_abstr_count the blocking abtsraction count
 * @param blocking_model the blocking model
 * @param blocking_model_count the blocking model count
 */
void receive_tcp_socket(void* p0, void* p1, void* p2, void* p3,
    void* blocking_abstr, void* blocking_abstr_count, void* blocking_model, void* blocking_model_count) {

    log_message_debug("Receive via tcp socket.");

    if (p0 != NULL_POINTER) {

        if ((blocking_abstr != NULL_POINTER)
            && (blocking_abstr_count != NULL_POINTER)
            && (blocking_model != NULL_POINTER)
            && (blocking_model_count != NULL_POINTER)) {

            int r = 0;

            compare_arrays((void*) blocking_abstr, (void*) blocking_abstr_count, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == 1) {

                if (*((int*) blocking_model) == *NUMBER_0_INTEGER) {

                    // The thread.
                    pthread_t t;

                    // Create thread returning an error value.
/*??
                    int e = pthread_create(&t, NULL_POINTER, (void*) &run_tcp_socket_server, p0);

                    if (e != 0) {

                        log_message_debug("Could not receive tcp socket. An error occured while creating the thread.");
                    }
*/
                }

                // The interrupt flag.
                int** f = (int**) &NULL_POINTER;

                get(p0, (void*) TCP_SOCKET_INTERRUPT_INTERNAL, (void*) &f, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                if ((f != NULL_POINTER) && (*f != NULL_POINTER)) {

                    // Deactivate interrupt flag, since tcp socket service is now running.
                    **f = 0;
                }

                // The blocking flag.
                int** b = (int**) &NULL_POINTER;

                get(p0, (void*) TCP_SOCKET_BLOCKING_INTERNAL, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

                if ((b != NULL_POINTER) && (*b != NULL_POINTER)) {

                    **b = *((int*) blocking_model);
                }
            }

        } else {

            log_message_debug("Could not receive via tcp socket. The blocking flag is null.");
        }

    } else {

        log_message_debug("Could not receive via tcp socket. The internal memory is null.");
    }
}

/* RECEIVE_TCP_SOCKET_SOURCE */
#endif
