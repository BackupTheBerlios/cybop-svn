/*
 * $RCSfile: http_request_converter.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-08-13 16:37:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_CONVERTER_SOURCE
#define HTTP_REQUEST_CONVERTER_SOURCE

#include "../../globals/constants/http/http_request_method_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/logger/logger.c"

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
void parse_http_request_get_method(char* req, int* req_count, char** req_method, int* req_method_count) {

    *req_method_count = *NUMBER_0_INTEGER;

    // The element.
    char* e = (char*) *NULL_POINTER;

    while (*NUMBER_1_INTEGER) {

        if (*req_method_count >= *req_count) {

            break;
        }

        get_array_elements(req, req_method_count, (void*) &e, (void*) CHARACTER_ARRAY);

        if (*e == *SPACE_ASCII_CHARACTER) {

            // Reached end of request method.
            break;
        }

        int max_count = *req_method_count + *NUMBER_1_INTEGER;

        reallocate_array((void*) req_method, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
        set_array_elements(*req_method, req_method_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

        *req_method_count = *req_method_count + *NUMBER_1_INTEGER;
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
void parse_http_request_url(char* req, int* req_count, char** urlbase, int* urlbase_count) {

    *urlbase_count = *NUMBER_0_INTEGER;
    int req_index = *NUMBER_0_INTEGER;
    int start_urlbase_flag = *NUMBER_0_INTEGER;
    int max_count = *NUMBER_0_INTEGER;
    // The element.
    char* e = (char*) *NULL_POINTER;

    while (*NUMBER_1_INTEGER) {

        if (req_index >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of ending the paramaters.
        if ((start_urlbase_flag == *NUMBER_1_INTEGER) && ((*e == *SPACE_ASCII_CHARACTER) || (*e == *QUESTION_MARK_ASCII_CHARACTER))) {

            break;
        }

        // Complete the parameters.
        if (start_urlbase_flag == *NUMBER_1_INTEGER) {

            max_count = *urlbase_count + *NUMBER_1_INTEGER;

            reallocate_array((void*) urlbase, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
            set_array_elements(*urlbase, urlbase_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            *urlbase_count = *urlbase_count + *NUMBER_1_INTEGER;
        }

        // Check of beginning the paramaters.
        if (*e == *SOLIDUS_ASCII_CHARACTER) {

            // Begin from the parameters.
            start_urlbase_flag = *NUMBER_1_INTEGER;
        }

        req_index++;
    }
}

/**
 * Extract parameters from "get" request method url.
 *
 * Example request :
 * GET /lib/ausgabe.cybol?param1=value1&param2=value2 HTTP/1.1 ...
 *
 * The result of the function is:
 * param1=value1&param2=value2
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count
 * @param p8 the url without "get" request method prefix
 * @param p9 the url count
 */
void parse_http_request_get(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

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
    *param_count = *NUMBER_0_INTEGER;
    int req_index = *NUMBER_0_INTEGER;
    int start_param_flag = *NUMBER_0_INTEGER;
    int max_count = *NUMBER_0_INTEGER;
    // The element.
    char* e = (char*) *NULL_POINTER;

    while (*NUMBER_1_INTEGER) {

        if (req_index >= *req_count) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of ending the paramaters.
        if ((start_param_flag == *NUMBER_1_INTEGER) && (*e == *SPACE_ASCII_CHARACTER)) {

            break;
        }

        // Complete the parameters.
        if (start_param_flag == *NUMBER_1_INTEGER) {

            max_count = *param_count + *NUMBER_1_INTEGER;

            reallocate_array((void*) param, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
            set_array_elements(*param, param_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            *param_count = *param_count + *NUMBER_1_INTEGER;
        }

        // Check of beginning the paramaters.
        if (*e == *QUESTION_MARK_ASCII_CHARACTER) {

            // Begin from the parameters.
            start_param_flag = *NUMBER_1_INTEGER;
        }

        req_index++;
    }
*/
}

/**
 * Extract parameters from "post" request method url.
 *
 * @param p0 the name (Hand over as reference!)
 * @param p1 the name count
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count
 * @param p8 the url without "post" request method prefix
 * @param p9 the url count
 */
void parse_http_request_post(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

/*??
    *param_count = *NUMBER_0_INTEGER;
    int req_index = *req_count - *NUMBER_1_INTEGER;
    int req_last_count = *NUMBER_0_INTEGER;
    int start_param_index = *NUMBER_MINUS_1_INTEGER;
    int max_count = *NUMBER_0_INTEGER;
    // The element.
    char* e = (char*) *NULL_POINTER;

    //get the index for beginning the paramaters
    while (*NUMBER_1_INTEGER) {

        if (req_index < *NUMBER_0_INTEGER) {

            break;
        }

        get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);

        // Check of beginning  the paramaters.
        if ((*e == *LINE_FEED_CONTROL_ASCII_CHARACTER)) {

            start_param_index = req_index + *NUMBER_1_INTEGER;
            break;
        }

        req_index = req_index - *NUMBER_1_INTEGER;
    }

    // set the parameters from the request
    if (start_param_index > *NUMBER_0_INTEGER) {

        req_index = start_param_index;

        while (*NUMBER_1_INTEGER) {

            if (req_index >= *req_count ) {

                break;
            }

            max_count = *param_count + *NUMBER_1_INTEGER;

            reallocate_array((void*) param, (void*) &max_count, (void*) &max_count, (void*) CHARACTER_ARRAY);
            get_array_elements(req, (void*) &req_index, (void*) &e, (void*) CHARACTER_ARRAY);
            set_array_elements(*param, param_count, (void*) e, (void*) NUMBER_1_INTEGER, (void*) CHARACTER_ARRAY);

            *param_count = *param_count + *NUMBER_1_INTEGER;
            req_index = req_index + *NUMBER_1_INTEGER;
        }
    }
*/
}

/**
 * Translate uniform resource identifier (uri).
 *
 * URIs have been known by many names (synonyms):
 * - WWW addresses
 * - Universal Document Identifiers
 * - Universal Resource Identifiers
 * - Uniform Resource Locators (URL)
 * - Uniform Resource Names (URN)
 *
 * As far as HTTP is concerned, Uniform Resource Identifiers are simply
 * formatted strings which identify -- via name, location, or any other
 * characteristic -- a resource.
 *
 * The "http" scheme is used to locate network resources via the HTTP protocol.
 *
 * http_URL = "http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
 *
 * If the port is empty or not given, port 80 is assumed.
 * The semantics are that the identified resource is located at the server
 * listening for TCP connections on that port of that host, and the Request-URI
 * for the resource is abs_path.
 * The use of IP addresses in URLs SHOULD be avoided whenever possible!
 * If the abs_path is not present in the URL, it MUST be given as "/" when
 * used as a Request-URI for a resource.
 * If a proxy receives a host name which is not a fully qualified domain name,
 * it MAY add its domain to the host name it received. If a proxy receives a
 * fully qualified domain name, the proxy MUST NOT change the host name.
 *
 * URI Comparison
 *
 * When comparing two URIs to decide if they match or not, a client SHOULD use a
 * case-sensitive octet-by-octet comparison of the entire URIs, with these exceptions:
 * - A port that is empty or not given is equivalent to the default port for that URI-reference;
 * - Comparisons of host names MUST be case-insensitive;
 * - Comparisons of scheme names MUST be case-insensitive;
 * - An empty abs_path is equivalent to an abs_path of "/".
 *
 * Characters other than those in the "reserved" and "unsafe" sets are equivalent
 * to their ""%" HEX HEX" encoding. For example, the following three URIs are equivalent:
 * http://abc.com:80/~smith/home.html
 * http://ABC.com/%7Esmith/home.html
 * http://ABC.com:/%7esmith/home.html
 *
 * HTTP Message
 *
 * Request and Response messages use a generic message format for transferring
 * entities (the payload of the message). Both types of message consist of a:
 * - start-line
 * - zero or more header fields (also known as "headers")
 * - an empty line (i.e., a line with nothing preceding the CRLF)
 *   indicating the end of the header fields
 * - possibly a message-body
 *
 * generic-message = start-line
 *                   *(message-header CRLF)
 *                   CRLF
 *                   [ message-body ]
 * start-line      = Request-Line | Status-Line
 *
 * In the interest of robustness, servers SHOULD ignore any empty line(s)
 * received where a Request-Line is expected. In other words, if the server
 * is reading the protocol stream at the beginning of a message and receives
 * a CRLF first, it should ignore the CRLF.
 *
 * --
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
 * @param p1 the name count
 * @param p2 the channel (Hand over as reference!)
 * @param p3 the channel count
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count
 * @param p8 the url
 * @param p9 the url count
 */
void parse_http_request_method(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p9 != *NULL_POINTER) {

        int* urlc = (int*) p9;

        log_message_debug("Information: Receive socket request method.");

        // The remaining url.
        void* u = *NULL_POINTER;
        int uc = *NUMBER_0_INTEGER;

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p8, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) HTTP_GET_REQUEST_METHOD, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set remaining url.
                //
                // To the original pointer are added the length of the "get"
                // string and one place for the "space" character after "get".
                u = p8 + *HTTP_GET_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT;
                uc = *urlc - *HTTP_GET_REQUEST_METHOD_COUNT - *PRIMITIVE_COUNT;

//??    fprintf(stderr, "TEST get request remaining url: %s\n", (char*) u);

                parse_http_request_get(p0, p1, p2, p3, p4, p5, p6, p7, u, (void*) &uc);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p8, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) HTTP_POST_REQUEST_METHOD, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Set remaining url.
                //
                // To the original pointer are added the length of the "post"
                // string and one place for the "space" character after "post".
                u = p8 + *HTTP_POST_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT;
                uc = *urlc - *HTTP_POST_REQUEST_METHOD_COUNT - *PRIMITIVE_COUNT;

//??    fprintf(stderr, "TEST post request remaining url: %s\n", (char*) u);

                parse_http_request_post(p0, p1, p2, p3, p4, p5, p6, p7, u, (void*) &uc);
            }
        }

    } else {

        log_message_debug("Error: Could not receive socket request method. The url count is null.");
    }
}

/**
 * Parses an http request into a compound.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source http request
 * @param p4 the source http request count
 */
void parse_http_request(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Information: Parse http request.");
}

/**
 * Serialises a compound into an http request.
 *
 * @param p0 the destination http request (Hand over as reference!)
 * @param p1 the destination http request count
 * @param p2 the destination http request size
 * @param p3 the source compound abstraction
 * @param p4 the source compound abstraction count
 * @param p5 the source compound model
 * @param p6 the source compound model count
 * @param p7 the source compound details
 * @param p8 the source compound details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 */
void serialise_http_request(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_debug("Information: Serialise http request.");
}

/* HTTP_REQUEST_CONVERTER_SOURCE */
#endif
