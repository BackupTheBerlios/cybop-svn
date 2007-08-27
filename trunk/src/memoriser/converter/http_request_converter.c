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
 * @version $Revision: 1.4 $ $Date: 2007-08-27 07:07:37 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_CONVERTER_SOURCE
#define HTTP_REQUEST_CONVERTER_SOURCE

#include "../../globals/constants/http/http_request_method_constants.c"
#include "../../globals/constants/http/http_separator_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/array_constants.c"
#include "../../globals/logger/logger.c"

//
// An http server request delivers message data in text format (like MIME 1.0),
// and consists of the following three parts:
// 1 request line containing request method, file path and protocol version
// 2 headers containing meta data, of which some have the form of variables
// 3 body containing optional user data (such as an encoded/serialised xhtml page)
//
// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).
// The end of the headers is demarcated by an empty line (CRLF without any space).
//
// Example:
//
// GET /infotext.html HTTP/1.1
// host: www.example.net
//
// Uniform resource identifier (URI) have been known by many names (synonyms):
// - WWW addresses
// - Universal Document Identifiers
// - Universal Resource Identifiers
// - Uniform Resource Locators (URL)
// - Uniform Resource Names (URN)
//
// As far as HTTP is concerned, Uniform Resource Identifiers are simply
// formatted strings which identify -- via name, location, or any other
// characteristic -- a resource.
//
// The "http" scheme is used to locate network resources via the HTTP protocol.
//
// http_URL = "http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
//
// If the port is empty or not given, port 80 is assumed.
// The semantics are that the identified resource is located at the server
// listening for TCP connections on that port of that host, and the Request-URI
// for the resource is abs_path.
// The use of IP addresses in URLs SHOULD be avoided whenever possible!
// If the abs_path is not present in the URL, it MUST be given as "/" when
// used as a Request-URI for a resource.
// If a proxy receives a host name which is not a fully qualified domain name,
// it MAY add its domain to the host name it received. If a proxy receives a
// fully qualified domain name, the proxy MUST NOT change the host name.
//
// URI Comparison
//
// When comparing two URIs to decide if they match or not, a client SHOULD use a
// case-sensitive octet-by-octet comparison of the entire URIs, with these exceptions:
// - A port that is empty or not given is equivalent to the default port for that URI-reference;
// - Comparisons of host names MUST be case-insensitive;
// - Comparisons of scheme names MUST be case-insensitive;
// - An empty abs_path is equivalent to an abs_path of "/".
//
// Characters other than those in the "reserved" and "unsafe" sets are equivalent
// to their ""%" HEX HEX" encoding. For example, the following three URIs are equivalent:
// http://abc.com:80/~smith/home.html
// http://ABC.com/%7Esmith/home.html
// http://ABC.com:/%7esmith/home.html
//
// HTTP Message
//
// Request and Response messages use a generic message format for transferring
// entities (the payload of the message). Both types of message consist of a:
// - start-line
// - zero or more header fields (also known as "headers")
// - an empty line (i.e., a line with nothing preceding the CRLF)
//   indicating the end of the header fields
// - possibly a message-body
//
// In the interest of robustness, servers SHOULD ignore any empty line(s)
// received where a Request-Line is expected. In other words, if the server
// is reading the protocol stream at the beginning of a message and receives
// a CRLF first, it should ignore the CRLF.
//
// --
// A uniform resource locator (url) consists of the following components:
// - schema
// - host
// - port
// - path
// - parameters
// - query
// - fragment (an anchor pointing to a special section within the document specified by "path")
//
// Its structure is defined as follows:
// schema://host:port/path;parameter_one;parameter_two;parameter_n?query#fragment
// The ";" is often replaced with "&".
//
// Example:
// http://127.0.0.1:1971?name=close&channel=inline&abstraction=knowledge&model=.residenz.logic.exit_program
// http://de.wikipedia.org/w/index.php?title=Uniform_Resource_Locator&action=edit
//
// Quoting:
// There are a number of reserved characters, to which belong:
// ! # $ % & ' ( ) * + , / : ; = ? @ [ ]
// The following url contains the reserved # character:
// http://www.example.net/index.html?session=A54C6FE2#info
// which should be encoded as %23 like:
// http://www.example.net/index.html?session=A54C6FE2%23info
//
// The url path specified by the client is relative to the
// server's root directory. Consider the following url as it
// would be requested by a client:
// http://www.example.com/path/file.html
// The client's web browser will translate it into a connection
// to www.example.com with the following http 1.1 request:
// GET /path/file.html HTTP/1.1
// host: www.example.com
// The Web server on www.example.com will append the given path
// to the path of its root directory. On Unix machines, this is
// commonly /var/www/htdocs.
// The result is the local file system resource:
// /var/www/htdocs/path/file.html
// The Web server will then read the file, if it exists, and
// send a response to the client's web browser. The response
// will describe the content of the file and contain the file itself.
//

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
void decode_http_request_get_method(char* req, int* req_count, char** req_method, int* req_method_count) {

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
void decode_http_request_url(char* req, int* req_count, char** urlbase, int* urlbase_count) {

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
 * Decode http "get" request.
 *
 * Example 1:
 *
 * GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
 * host: de.wikipedia.org
 * ...
 *
 * The value pairs (parameters) of the example are:
 *
 * -------------------------------------
 * Argument         Value
 * -------------------------------------
 * search           Katzen
 * go               Artikel
 * -------------------------------------
 *
 * Example 2:
 *
 * GET /residenz/test.html HTTP/1.1
 * user-agent: Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Debian)
 * accept: text/html, image/jpeg, image/png, text/*, image/*, * /*
 * accept-Encoding: x-gzip, x-deflate, gzip, deflate
 * accept-Charset: utf-8, utf-8;q=0.5, *;q=0.5
 * accept-Language: en, de, pl
 * host: 127.0.0.1:1971
 * connection: Keep-Alive
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source http request (starting behind the request method)
 * @param p7 the source http request (starting behind the request method) count
 */
void decode_http_request_get(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

/*??
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
*/

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
 * Decode http "post" request.
 *
 * Example:
 *
 * POST /wiki/Spezial:Search HTTP/1.1
 * host: de.wikipedia.org
 * content-type: application/x-www-form-urlencoded
 * content-length: 24
 *
 * search=Katzen&go=Artikel
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source http request (starting behind the request method)
 * @param p7 the source http request (starting behind the request method) count
 */
void decode_http_request_post(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
    // This is defined so by the Hypertext Transfer Protocol (HTTP).

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
 * Decode http request method.
 *
 * Example:
 *
 * POST /wiki/Spezial:Search HTTP/1.1
 * ...
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source http request
 * @param p7 the source http request count
 */
void decode_http_request_request_method(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER) {

        int* sc = (int*) p7;

        log_message_debug("Information: Decode http request method.");

        // The remaining source.
        void* rs = *NULL_POINTER;
        int rsc = *NUMBER_0_INTEGER;

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            // Check source count.
            // CAUTION! This is necessary to avoid a segmentation fault if one
            // array is too small, when comparing the request method arrays below!
            if (*sc >= *HTTP_GET_REQUEST_METHOD_COUNT) {

                compare_arrays(p6, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) HTTP_GET_REQUEST_METHOD, (void*) HTTP_GET_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set remaining source.
                    //
                    // To the original pointer are added the length of the "GET "
                    // string, including one place for the "space" character.
                    rs = p6 + *HTTP_GET_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT;
                    rsc = *sc - *HTTP_GET_REQUEST_METHOD_COUNT - *PRIMITIVE_COUNT;

    //??    fprintf(stderr, "TEST get request remaining source (url): %s\n", (char*) rs);

                    decode_http_request_get(p0, p1, p2, p3, p4, p5, rs, (void*) &rsc);
                }

            } else {

                log_message_debug("Warning: Could not decode http request method. The source http request count is less than the get request method count.");
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            // Check source count.
            // CAUTION! This is necessary to avoid a segmentation fault if one
            // array is too small, when comparing the request method arrays below!
            if (*sc >= *HTTP_POST_REQUEST_METHOD_COUNT) {

                compare_arrays(p6, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) HTTP_POST_REQUEST_METHOD, (void*) HTTP_POST_REQUEST_METHOD_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r != *NUMBER_0_INTEGER) {

                    // Set remaining source.
                    //
                    // To the original pointer are added the length of the "POST "
                    // string, including one place for the "space" character.
                    rs = p6 + *HTTP_POST_REQUEST_METHOD_COUNT + *PRIMITIVE_COUNT;
                    rsc = *sc - *HTTP_POST_REQUEST_METHOD_COUNT - *PRIMITIVE_COUNT;

    //??    fprintf(stderr, "TEST post request remaining source (url): %s\n", (char*) rs);

                    decode_http_request_post(p0, p1, p2, p3, p4, p5, rs, (void*) &rsc);
                }

            } else {

                log_message_debug("Warning: Could not decode http request method. The source http request count is less than the post request method count.");
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            log_message_debug("Warning: Could not decode http request method. The source http request method is unknown.");
        }

    } else {

        log_message_debug("Error: Could not decode http request method. The source http request count is null.");
    }
}

/**
 * Decodes an http request request line into the details compound.
 *
 * Example:
 *
 * POST /wiki/Spezial:Search HTTP/1.1
 * ...
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the source http request
 * @param p4 the source http request count
 */
void decode_http_request_request_line(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Debug: Decode http request request line.");

        // The source http request index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The http request separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Request method.
        //

        // The request method, initialised with current http request index.
        void* rm = i;
        int rmc = ic;
        // Reset http request separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get request method separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_REQUEST_METHOD_SEPARATOR, (void*) HTTP_REQUEST_METHOD_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set request line count.
            rmc = sep;
            // Set new http request index.
            i = i + sep + *HTTP_REQUEST_LINE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_LINE_SEPARATOR_COUNT;

        } else {

            // Set http request index to null, if separator could not be found.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

        //
        // File path.
        //

        // The file path, initialised with current http request index.
        void* fp = i;
        int fpc = ic;
        // Reset http request separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get file path separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_FILE_PATH_SEPARATOR, (void*) HTTP_FILE_PATH_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set request line count.
            fpc = sep;
            // Set new http request index.
            i = i + sep + *HTTP_REQUEST_LINE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_LINE_SEPARATOR_COUNT;

        } else {

            // Set http request index to null, if separator could not be found.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

        //
        // Protocol version.
        //

        // The protocol version, initialised with current http request index.
        void* pv = i;
        int pvc = ic;
        // No separators have to be found within the protocol version, as it comprises
        // the complete remaining http request, starting after the file path.

/*??
        decode_http_request_request_method(p0, p1, p2, rm, (void*) &rmc);
        decode_http_request_request_method(p0, p1, p2, fp, (void*) &fpc);
        decode_http_request_request_method(p0, p1, p2, pv, (void*) &pvc);
*/

    } else {

        log_message_debug("Error: Could not decode http request request line. The source http request count is null.");
    }
}

/**
 * Decodes an http request header into the details compound.
 *
 * Example:
 *
 * ...
 * content-type: text/html; charset=iso-8859-1
 * ...
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the source http request
 * @param p4 the source http request count
 */
void decode_http_request_header(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Debug: Decode http request header.");

        // The source http request index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The http request separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Argument.
        //

        // The argument, initialised with current http request index.
        void* a = i;
        int ac = ic;
        // Reset http request separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get argument separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADER_ARGUMENT_SEPARATOR, (void*) HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set argument count.
            ac = sep;

            // Set new http request index.
            i = i + sep + *HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_HEADER_ARGUMENT_SEPARATOR_COUNT;

        } else {

            // Set http request index to null, if separator could not be found.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

        //
        // Value.
        //

        // The value, initialised with current http request index.
        void* v = i;
        int vc = ic;
        // Reset http request separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get value separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADER_VALUE_SEPARATOR, (void*) HTTP_HEADER_VALUE_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set value count.
            vc = sep;

            // Set new http request index.
            i = i + sep + *HTTP_HEADER_VALUE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_HEADER_VALUE_SEPARATOR_COUNT;

        } else {

            // Set http request index to null, if separator could not be found.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

    } else {

        log_message_debug("Error: Could not decode http request header. The source http request count is null.");
    }
}

/**
 * Decodes http request headers into the details compound.
 *
 * Example:
 *
 * ...
 * host: de.wikipedia.org
 * content-type: application/x-www-form-urlencoded
 * content-length: 24
 * ...
 *
 * @param p0 the destination details (Hand over as reference!)
 * @param p1 the destination details count
 * @param p2 the destination details size
 * @param p3 the source http request
 * @param p4 the source http request count
 */
void decode_http_request_headers(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Debug: Decode http request headers.");

        // The source http request index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p3;
        int ic = *sc;
        // The http request separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;
        // The header, initialised with current http request index.
        void* h = i;
        int hc = ic;

        while (*NUMBER_1_INTEGER) {

            // Set header.
            h = i;

            // Reset http request separator index.
            sep = *NUMBER_MINUS_1_INTEGER;

            // Get header separator index.
            get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADER_SEPARATOR, (void*) HTTP_HEADER_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

            if (sep >= *NUMBER_0_INTEGER) {

                // A header separator was found. More headers exist.

                // Set header count.
                hc = sep;

                // Decode the identified header.
                decode_http_request_header(p0, p1, p2, h, (void*) &hc);

                // Set new http request index.
                i = i + sep + *HTTP_HEADER_SEPARATOR_COUNT;
                ic = ic - sep - *HTTP_HEADER_SEPARATOR_COUNT;

            } else {

                // No header separator was found. This is the last header.

                // Set header count.
                hc = ic;

                // Decode the identified header.
                decode_http_request_header(p0, p1, p2, h, (void*) &hc);

                // Break loop since no further headers are to be expected.
                break;
            }
        }

    } else {

        log_message_debug("Error: Could not decode http request headers. The source http request count is null.");
    }
}

/**
 * Decodes an http request body into the model compound.
 *
 * Example:
 *
 * search=Katzen&go=Artikel
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source http request
 * @param p4 the source http request count
 */
void decode_http_request_body(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void** s = (void**) p3;

            log_message_debug("Debug: Decode http request body.");

            // Read parameters out of body, create models and assign them
            // as parts to the given destination model.

        } else {

            log_message_debug("Error: Could not decode http request body. The source http request is null.");
        }

    } else {

        log_message_debug("Error: Could not decode http request body. The source http request count is null.");
    }
}

/**
 * Decodes an http request into a compound.
 *
 * Example:
 *
 * POST /wiki/Spezial:Search HTTP/1.1
 * host: de.wikipedia.org
 * content-type: application/x-www-form-urlencoded
 * content-length: 24
 *
 * search=Katzen&go=Artikel
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source http request
 * @param p7 the source http request count
 */
void decode_http_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER) {

        int* sc = (int*) p7;

        log_message_debug("Information: Decode http request.");

        // The source http request index.
        // CAUTION! A local variable is used instead of the parameter
        // that was handed over, because it will get manipulated below!
        void* i = p6;
        int ic = *sc;
        // The http request separator index.
        int sep = *NUMBER_MINUS_1_INTEGER;

        //
        // Request line.
        //

        // The request line, initialised with current http request index.
        void* rl = i;
        int rlc = ic;
        // Reset http request separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get request line separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_REQUEST_LINE_SEPARATOR, (void*) HTTP_REQUEST_LINE_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set request line count.
            rlc = sep;
            // Set new http request index.
            i = i + sep + *HTTP_REQUEST_LINE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_LINE_SEPARATOR_COUNT;

        } else {

            // Set http request index to null, if separator could not be found.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

        //
        // Headers.
        //

        // The headers, initialised with current http request index.
        void* h = i;
        int hc = ic;
        // Reset http request separator index.
        sep = *NUMBER_MINUS_1_INTEGER;

        // Get headers separator index.
        get_array_elements_index(i, (void*) &ic, (void*) HTTP_HEADERS_SEPARATOR, (void*) HTTP_HEADERS_SEPARATOR_COUNT, (void*) &sep, (void*) CHARACTER_ARRAY);

        if (sep >= *NUMBER_0_INTEGER) {

            // Set request line count.
            hc = sep;
            // Set new http request index.
            i = i + sep + *HTTP_REQUEST_LINE_SEPARATOR_COUNT;
            ic = ic - sep - *HTTP_REQUEST_LINE_SEPARATOR_COUNT;

        } else {

            // Set http request index to null, if separator could not be found.
            i = *NULL_POINTER;
            ic = *NUMBER_0_INTEGER;
        }

        //
        // Body.
        //

        // The body, initialised with current http request index.
        void* b = i;
        int bc = ic;
        // No separators have to be found within the body, as it comprises
        // the complete remaining http request, starting after the headers.

        // Decode request line containing request method and protocol version.
        decode_http_request_request_line(p3, p4, p5, rl, (void*) &rlc);
        // Decode headers containing meta data, of which some have the form of variables.
        decode_http_request_headers(p3, p4, p5, h, (void*) &hc);
        // Decode body containing optional user data (such as an encoded/serialised xhtml page).
        decode_http_request_body(p0, p1, p2, b, (void*) &bc);

    } else {

        log_message_debug("Error: Could not decode http request method. The source http request count is null.");
    }
}

/**
 * Encodes a compound into an http request.
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
void encode_http_request(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_debug("Information: Encode http request.");
}

/* HTTP_REQUEST_CONVERTER_SOURCE */
#endif
