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
 * @version $Revision: 1.24 $ $Date: 2007-06-22 07:07:14 $ $Author: christian $
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
#include "../../applicator/receive/receive_file_system.c"
#include "../../globals/constants/http/http_request_method_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/console/console_escape_code_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/cybol/cybol_model_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/constants/system_constants.c"
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
    char* e = (char*) *NULL_POINTER;

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
void receive_socket_url(char* req, int* req_count, char** urlbase, int* urlbase_count) {

    *urlbase_count = 0;
    int req_index = 0;
    int start_urlbase_flag = 0;
    int max_count = 0;
    // The element.
    char* e = (char*) *NULL_POINTER;

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

    if ((source != *NULL_POINTER) && (source_count != *NULL_POINTER) && (dest != *NULL_POINTER)) {

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
 * Extract parameters from url without "get" request method prefix.
 *
 * Example request :
 * GET /lib/ausgabe.cybol?param1=value1&param2=value2 HTTP/1.1 ...
 *
 * The result of the function is:
 * param1=value1&param2=value2
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count (Hand over as reference!)
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count (Hand over as reference!)
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count (Hand over as reference!)
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count (Hand over as reference!)
 * @param p8 the url (source) (Hand over as reference!)
 * @param p9 the url count (Hand over as reference!)
--
 * @param req the request
 * @param req_count the request count
 * @param param the parameter
 * @param param_count the paramater count
 */
void receive_socket_get_parameters_get_request(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {
//?? (char* req, int* req_count, char** param, int* param_count) {

    if (p9 != *NULL_POINTER) {

        int* urlc = (int*) p9;

        if (p8 != *NULL_POINTER) {

            void** url = (void**) p8;

            if (p1 != *NULL_POINTER) {

                int* nc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** n = (void**) p0;

                    log_message_debug("Information: Receive socket get parameters get request.");

                    *n = *url;
                    *nc = *urlc;

                } else {

                    log_message_debug("Error: Could not receive socket get parameters get request. The name is null.");
                }

            } else {

                log_message_debug("Error: Could not receive socket get parameters get request. The name count is null.");
            }

        } else {

            log_message_debug("Error: Could not receive socket get parameters get request. The url is null.");
        }

    } else {

        log_message_debug("Error: Could not receive socket get parameters get request. The url count is null.");
    }

/*??
    *param_count = 0;
    int req_index = 0;
    int start_param_flag = 0;
    int max_count = 0;
    // The element.
    char* e = (char*) *NULL_POINTER;

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
*/
}

/**
 * Extract parameters from url without "post" request method prefix.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count (Hand over as reference!)
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count (Hand over as reference!)
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count (Hand over as reference!)
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count (Hand over as reference!)
 * @param p8 the url (source) (Hand over as reference!)
 * @param p9 the url count (Hand over as reference!)
--
 * @param req the request
 * @param req_count the request count
 * @param param the parameter
 * @param param_count the paramater count
 */
void receive_socket_get_parameters_post_request(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {
//?? (char* req, int* req_count, char** param, int* param_count) {

/*??
    *param_count = 0;
    int req_index = *req_count-1;
    int req_last_count = 0;
    int start_param_index = -1;
    int max_count = 0;
    // The element.
    char* e = (char*) *NULL_POINTER;

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
*/
}

/**
 * Translate uniform resource locator (url).
 *
 * A uniform resource locator (url) consists of the following components:
 * - schema
 * - host
 * - port
 * - path
 * - parameters
 * - query
 * - fragment (an anchor pointing to a special section within the document specified by "path")
 *
 * Its structure is defined as follows:
 * schema://host:port/path;parameter_one;parameter_two;parameter_n?query#fragment
 * The ";" is often replaced with "&".
 *
 * Example:
 * http://127.0.0.1:1971?name=close&channel=inline&abstraction=knowledge&model=.residenz.logic.exit_program
 * http://de.wikipedia.org/w/index.php?title=Uniform_Resource_Locator&action=edit
 *
 * Quoting:
 * There are a number of reserved characters, to which belong:
 * ! # $ % & ' ( ) * + , / : ; = ? @ [ ]
 * The following url contains the reserved # character:
 * http://www.example.net/index.html?session=A54C6FE2#info
 * which should be encoded as %23 like:
 * http://www.example.net/index.html?session=A54C6FE2%23info
 *
 * Example:
 * GET /residenz/test.html HTTP/1.1
 * User-Agent: Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Debian)
 * Accept: text/html, image/jpeg, image/png, text/*, image/*, * /*
 * Accept-Encoding: x-gzip, x-deflate, gzip, deflate
 * Accept-Charset: utf-8, utf-8;q=0.5, *;q=0.5
 * Accept-Language: en, de, pl
 * Host: 127.0.0.1:1971
 * Connection: Keep-Alive
 *
 * The url path specified by the client is relative to the
 * server's root directory. Consider the following url as it
 * would be requested by a client:
 * http://www.example.com/path/file.html
 * The client's web browser will translate it into a connection
 * to www.example.com with the following http 1.1 request:
 * GET /path/file.html HTTP/1.1
 * Host: www.example.com
 * The Web server on www.example.com will append the given path
 * to the path of its root directory. On Unix machines, this is
 * commonly /var/www/htdocs.
 * The result is the local file system resource:
 * /var/www/htdocs/path/file.html
 * The Web server will then read the file, if it exists, and
 * send a response to the client's web browser. The response
 * will describe the content of the file and contain the file itself.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count (Hand over as reference!)
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count (Hand over as reference!)
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count (Hand over as reference!)
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count (Hand over as reference!)
 * @param p8 the url (source) (Hand over as reference!)
 * @param p9 the url count (Hand over as reference!)
 */
void receive_socket_get_parameters(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p9 != *NULL_POINTER) {

        int* urlc = (int*) p9;

        if (p8 != *NULL_POINTER) {

            void** url = (void**) p8;

            log_message_debug("Information: Receive socket get parameters.");

            // The comparison result.
            int r = 0;
            // The content pointer.
            void* c = *NULL_POINTER;
            int cc = *NUMBER_0_INTEGER;

            if (r == 0) {

                compare_arrays(*url, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) HTTP_GET_REQUEST_METHOD, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    // Set content pointer.
                    // To the original pointer are added the length of the "get"
                    // string and one place for the "space" character after "get".
//??                    c = *url + *HTTP_GET_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT;
//??                    cc = *urlc - *HTTP_GET_REQUEST_METHOD_COUNT - *PRIMITIVE_COUNT;

                    //?? TEST with placeholders for / and ?
                    c = *url + *HTTP_GET_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT + 1 + 1;
                    //?? The "close" signal is of length 5.
                    cc = 5;

        fprintf(stderr, "TEST: %s\n", (char*) c);

                    receive_socket_get_parameters_get_request(p0, p1, p2, p3, p4, p5, p6, p7, (void*) &c, (void*) &cc);
                }
            }

            if (r == 0) {

                compare_arrays(*url, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) HTTP_POST_REQUEST_METHOD, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    // Set content pointer.
                    // To the original pointer are added the length of the "post"
                    // string and one place for the "space" character after "post".
                    c = *url + *HTTP_POST_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT;
                    cc = *urlc - *HTTP_POST_REQUEST_METHOD_COUNT - *PRIMITIVE_COUNT;

                    receive_socket_get_parameters_post_request(p0, p1, p2, p3, p4, p5, p6, p7, (void*) &c, (void*) &cc);
                }
            }

        } else {

            log_message_debug("Error: Could not receive socket get parameters. The url is null.");
        }

    } else {

        log_message_debug("Error: Could not receive socket get parameters. The url count is null.");
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
    if ((p0 != *NULL_POINTER) && (p1 != *NULL_POINTER) && (p2 != *NULL_POINTER)) {

        int query_counter = 0;

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
        int r = 0;

        //elements from the array
        void* element = *NULL_POINTER;
        //elements from the array
        void* decode_element = *NULL_POINTER;
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
 * Receives socket signal.
 *
 * The http request must be parsed for parameters!
 * A cyboi-internal signal is created and added to the signal memory, for each parameter.
 *
 * @param p0 the internal memory
 * @param p1 the command name
 * @param p2 the command name count
 * @param p3 the base internal
 */
void receive_socket_signal(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER) {

        int* base = (int*) p3;

        log_message_debug("Information: Receive socket signal.");

    fprintf(stderr, "TEST: receive socket command name: %s \n", (char*) p1);
    fprintf(stderr, "TEST: receive socket command name count: %i \n", *((int*) p2));

        // The knowledge memory.
        void** k = NULL_POINTER;
        void** kc = NULL_POINTER;
        void** ks = NULL_POINTER;
        // The signal memory.
        void** s = NULL_POINTER;
        void** sc = NULL_POINTER;
        void** ss = NULL_POINTER;
        // The interrupt request flag.
        sig_atomic_t** irq = (sig_atomic_t**) NULL_POINTER;
        // The signal memory mutex.
        pthread_mutex_t** smt = (pthread_mutex_t**) NULL_POINTER;
        // The internal memory index.
        int i = *INVALID_VALUE;
        // The socket mutex.
        pthread_mutex_t** somt = (pthread_mutex_t**) NULL_POINTER;
        // The commands.
        void** c = NULL_POINTER;
        void** cc = NULL_POINTER;
        void** cs = NULL_POINTER;
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
        // The signal id.
        int* id = (int*) *NULL_POINTER;

        // Get knowledge memory internal.
        get(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory internal.
        get(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        get(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get interrupt request internal.
        get(p0, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get signal memory mutex.
        get(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &smt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get(p0, (void*) &i, (void*) &somt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Lock socket mutex.
        //
        // CAUTION! A mutex is needed here to ensure that the commands internal
        // and its associated count and size are retrieved at once and belong together.
        // Otherwise, a commands internal might be got in this "receive" thread,
        // then the "main" thread of cyboi might set a new commands internal, count
        // and size, and finally this "receive" thread would get a wrong count or size
        // (of the new commands internal), not belonging to the commands internal got before.
        pthread_mutex_lock(*somt);

        // Get commands internal.
        i = *base + *SOCKET_COMMANDS_INTERNAL;
        get(p0, (void*) &i, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMANDS_COUNT_INTERNAL;
        get(p0, (void*) &i, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

        // Unlock socket mutex.
        pthread_mutex_unlock(*somt);

        // Get actual command belonging to the command name.
        // If the name is not known, the command parameter is left untouched.
        get_universal_compound_element_by_name(*c, *cc,
            p1, p2,
            (void*) &cn, (void*) &cnc, (void*) &cns,
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

    } else {

        log_message_debug("Error: Could not receive socket signal. The base internal is null.");
    }
}

/**
 * Receives stream socket messages in an own thread.
 *
 * For web frontend testing, use for example:
 * http://localhost:3456/residenz.logic.send_name
 * http://127.0.0.1:1971/residenz.logic.send_name
 *
 * @param p0 the internal memory
 * @param p1 the base internal
 */
void receive_socket_thread(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        int* base = (int*) p1;

        // The internal memory index.
        int i = *INVALID_VALUE;
        // The communication style.
        void** st = NULL_POINTER;
        void** stc = NULL_POINTER;
        // The socket mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;
        // The socket of this system.
        int** s = (int**) NULL_POINTER;
        // The socket address of this system.
        void** a = NULL_POINTER;
        void** as = NULL_POINTER;
        // The partner-connected socket of this system.
        int** ps = (int**) NULL_POINTER;
        // The communication partner socket address.
        void** pa = NULL_POINTER;
        void** pas = NULL_POINTER;
        // The character buffer.
        void** b = NULL_POINTER;
        int** bc = (int**) NULL_POINTER;
        // The maximum buffer size.
        // CAUTION! A message MUST NOT be longer!
        int** bs = (int**) NULL_POINTER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;
        // The error number.
        // CAUTION! This extra error number (besides "errno") is necessary
        // to remember "errno" values of the "recv" and "recvfrom" procedures,
        // across the various if-else sections.
        int e = *NUMBER_0_INTEGER;
        // The name.
        void* name = *NULL_POINTER;
        int namec = *NUMBER_0_INTEGER;
        // The channel.
        void* channel = *NULL_POINTER;
        int channelc = *NUMBER_0_INTEGER;
        // The abstraction.
        void* abstraction = *NULL_POINTER;
        int abstractionc = *NUMBER_0_INTEGER;
        // The model.
        void* model = *NULL_POINTER;
        int modelc = *NUMBER_0_INTEGER;

        // Get communication style.
        i = *base + *SOCKET_STYLE_INTERNAL;
        get(p0, (void*) &i, (void*) &st, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_STYLE_COUNT_INTERNAL;
        get(p0, (void*) &i, (void*) &stc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get socket mutex.
        i = *base + *SOCKET_MUTEX_INTERNAL;
        get(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get socket of this system.
        i = *base + *SOCKET_INTERNAL;
        get(p0, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get socket address of this system.
        i = *base + *SOCKET_ADDRESS_INTERNAL;
        get(p0, (void*) &i, (void*) &a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_ADDRESS_SIZE_INTERNAL;
        get(p0, (void*) &i, (void*) &as, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_INTERNAL;
        get(p0, (void*) &i, (void*) &ps, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get communication partner socket address.
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL;
        get(p0, (void*) &i, (void*) &pa, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL;
        get(p0, (void*) &i, (void*) &pas, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        // Get character buffer.
        i = *base + *SOCKET_CHARACTER_BUFFER_INTERNAL;
        get(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL;
        get(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
        i = *base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL;
        get(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST: receive socket thread server socket: %i \n", **s);

        while (1) {

            // A break condition does not exist here because the loop
            // is blocking neverendingly while waiting for signals.
            // The loop and this thread can only be exited by an external signal
            // which is sent in the corresponding interrupt service procedure
            // (situated in the applicator/interrupt/ directory)
            // and processed in the system signal handler procedure
            // (situated in the controller/checker.c module).

            if (r == 0) {

                compare_arrays(*st, *stc, (void*) STREAM_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER;

                    // Lock socket mutex.
                    pthread_mutex_lock(*mt);

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
                    // socket by calling "accept" again -- therefore this loop!
                    //
                    // The address "pa" returns information about the name of the
                    // communication partner socket that initiated the connection.
                    **ps = accept(**s, (struct sockaddr*) *pa, (socklen_t*) *pas);

                    if (**ps >= *NUMBER_0_INTEGER) {

                        // Initialise error number.
                        // It is a global variable/ function and other operations
                        // may have set some value that is not wanted here.
                        //
                        // CAUTION! Initialise the error number BEFORE calling the procedure
                        // that might cause an error.
                        errno = *NUMBER_0_INTEGER;

                        // Receive message from client.
                        //
                        // If the flags argument (fourth one) is zero, then one can
                        // just as well use the "read" instead of the "recv" procedure.
                        // Normally, "recv" blocks until there is input available to be read.
                        // Not so here, as the socket was set to "non-blocking" mode at startup.
                        //
                        // CAUTION! A message MUST NOT be longer than the given buffer size!
                        **bc = recv(**ps, *b, **bs, *NUMBER_0_INTEGER);

                        // Remember error number.
                        e = errno;

    fprintf(stderr, "TEST: receive socket thread client socket: %i \n", **ps);

                        // CAUTION! Do NOT close client socket here!
                        // It is stored in the internal memory and only closed in
                        // the "send_socket" operation, when replying to the client.
                        // close(**ps);

                    } else {

                        if (errno == EBADF) {

                            log_message_debug("Error: Could not receive socket thread. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            log_message_debug("Error: Could not receive socket thread. The descriptor socket argument is not a socket.");

                        } else if (errno == EOPNOTSUPP) {

                            log_message_debug("Error: Could not receive socket thread. The descriptor socket does not support this operation.");

                        } else if (errno == EWOULDBLOCK) {

                            // CAUTION! Do NOT log the following error:
                            // log_message_debug("Error: Could not receive socket thread. The socket has nonblocking mode set, and there are no pending connections immediately available.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established,
                            // which would unnecessarily fill up the log file.

                        } else {

                            log_message_debug("Error: Could not receive socket thread. An unknown error occured while accepting a socket connection.");
                        }
                    }

                    // Unlock socket mutex.
                    pthread_mutex_unlock(*mt);
                }
            }

            if (r == 0) {

                compare_arrays(*st, *stc, (void*) DATAGRAM_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER;

                    // Lock socket mutex.
                    pthread_mutex_lock(*mt);

                    // Receive message from client.
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" procedure.
                    // Normally, "recv" blocks until there is input available to be read.
                    // Not so here, as the socket was set to "non-blocking" mode at startup.
                    //
                    // CAUTION! A message MUST NOT be longer than the given buffer size!
                    **bc = recvfrom(**s, *b, **bs, *NUMBER_0_INTEGER, (struct sockaddr*) *a, (socklen_t*) *as);

                    // Unlock socket mutex.
                    pthread_mutex_unlock(*mt);

                    // Remember error number.
                    e = errno;
                }
            }

            if (r == 0) {

                compare_arrays(*st, *stc, (void*) RAW_COMMUNICATION_STYLE_MODEL, (void*) STREAM_COMMUNICATION_STYLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != 0) {

                    // Not implemented.
                }
            }

            if (**bc > *NUMBER_0_INTEGER) {

                // Translate uniform resource locator (url).
                receive_socket_get_parameters((void*) &name, (void*) &namec,
                    (void*) &channel, (void*) &channelc,
                    (void*) &abstraction, (void*) &abstractionc,
                    (void*) &model, (void*) &modelc,
                    (void*) b, (void*) *bc);

/*??
                // The url basename.
                char* url_basename = (char*) *NULL_POINTER;
                int url_basename_count = 0;
                // Create url basename.
                allocate_array((void*) &url_basename, (void*) &url_basename_count, (void*) CHARACTER_ARRAY);
                // Get url base name.
                receive_socket_url(msg, &msg_count, &url_basename, &url_basename_count);

                // The parameter.
                char* param = (char*) *NULL_POINTER;
                int param_count = 0;
                // Create paramater.
                allocate_array((void*) &param, (void*) &param_count, (void*) CHARACTER_ARRAY);
                // Get parameters.
                receive_socket_parameter(msg, &msg_count, &param, &param_count);

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

                    close(**ps);
                }
*/

                // Receive socket signal.
                receive_socket_signal(p0, name, (void*) &namec, p1);

    fprintf(stderr, "TEST: receive socket after signal: %i \n", i);
    //?? CAUTION! This sleep procedure is temporarily necessary for testing!
    //?? Otherwise, the loop runs into the next cycle and the socket mutex
    //?? gets locked, so that the "send_socket" procedure in the main thread
    //?? cannot send its message.
//??    sleep(30);

            } else if (**bc = *NUMBER_0_INTEGER) {

                log_message_debug("Error: Could not receive socket thread. No data could be received.");

            } else {

                if (e == EBADF) {

                    log_message_debug("Error: Could not receive socket thread. The socket argument is not a valid file descriptor.");

                } else if (e == ENOTSOCK) {

                    log_message_debug("Error: Could not receive socket thread. The descriptor socket is not a socket.");

                } else if (e == EWOULDBLOCK) {

                    log_message_debug("Error: Could not receive socket thread. The read operation would block even though nonblocking mode has been set on the socket.");

                } else if (e == EINTR) {

                    log_message_debug("Error: Could not receive socket thread. The operation was interrupted by a signal before any data was read.");

                } else if (e == ENOTCONN) {

                    log_message_debug("Error: Could not receive socket thread. The socket was never connected.");

                } else {

                    // CAUTION! Do NOT log the following error:
                    // log_message_debug("Error: Could not receive socket thread. An unknown error occured while receiving data.");
                    //
                    // The reason is that the socket is non-blocking,
                    // so that the "accept" procedure returns always,
                    // even if no connection was established.
                    // But if no connection and client socket are there,
                    // then the "recv" or "recvfrom" procedure returns an error,
                    // which would unnecessarily fill up the log file.
                }
            }

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

            // Reset communication partner socket.
            //
            // CAUTION! This is NOT necessary, since in each new loop cycle,
            // the "accept" function returns a new value.
            // **ps = *INVALID_VALUE;

            // Reset character buffer.
            //
            // CAUTION! Do NOT deallocate the character buffer!
            // It was allocated at socket startup and must remain unchanged.
            // Therefore, its elements are just set to null pointers here.
            //
            // CAUTION! Do NOT reset the maximum buffer size!
            // It was allocated and initialised at socket startup
            // and must remain unchanged.
            memset(*b, 0, **bs);
            **bc = *NUMBER_0_INTEGER;
            // Reset comparison result.
            r = *NUMBER_0_INTEGER;
            // Reset error number.
            e = *NUMBER_0_INTEGER;

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
void receive_socket_thread_www(void* p0) {

    log_message_debug("Receive www messages via socket.");

    receive_socket_thread(p0, (void*) WWW_BASE_INTERNAL);
}

/**
 * Receives cyboi messages via socket.
 *
 * @param p0 the internal memory
 */
void receive_socket_thread_cyboi(void* p0) {

    log_message_debug("Receive cyboi messages via socket.");

    receive_socket_thread(p0, (void*) CYBOI_BASE_INTERNAL);
}

/**
 * Receives messages via socket.
 *
 * @param p0 the internal memory
 * @param p1 the commands model
 * @param p2 the commands model count
 * @param p3 the communication style model
 * @param p4 the communication style model count
 * @param p5 the base internal
 * @param p6 the receive socket thread procedure
 * @param p7 the service thread
 */
void receive_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER) {

        int* t = (int*) p7;

        if (p5 != *NULL_POINTER) {

            int* b = (int*) p5;

            // The internal memory index.
            int i = *INVALID_VALUE;
            // The socket mutex.
            pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;

            // Get socket mutex.
            i = *b + *SOCKET_MUTEX_INTERNAL;
            get(p0, (void*) &i, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

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

            // Set commands internal.
            i = *b + *SOCKET_COMMANDS_INTERNAL;
            set(p0, (void*) &i, (void*) &p1, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_COMMANDS_COUNT_INTERNAL;
            set(p0, (void*) &i, (void*) &p2, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Set communication style internal.
            i = *b + *SOCKET_STYLE_INTERNAL;
            set(p0, (void*) &i, (void*) &p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
            i = *b + *SOCKET_STYLE_COUNT_INTERNAL;
            set(p0, (void*) &i, (void*) &p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            // Unlock socket mutex.
            pthread_mutex_unlock(*mt);

            // Only create thread, if not existent.
            // The "pthread_t" type is an integer, so both can be compared.
            if (*t == *INVALID_VALUE) {

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
                pthread_create((pthread_t*) t, *NULL_POINTER, p6, p0);
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
