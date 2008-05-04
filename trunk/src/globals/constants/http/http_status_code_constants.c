/*
 * $RCSfile: http_status_code_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.5 $ $Date: 2008-05-04 00:18:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_STATUS_CODE_CONSTANTS_SOURCE
#define HTTP_STATUS_CODE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// These constants represent http 1.1 status codes (server response codes),
// which are sent from a server back to the client that had sent the request.
//

//
// 1xx - informational
//
// This class of status code indicates a provisional response, consisting only of
// the Status-Line and optional headers, and is terminated by an empty line.
// There are no required headers for this class of status code. Since HTTP/1.0
// did not define any 1xx status codes, servers must not send a 1xx response to an
// HTTP/1.0 client except under experimental conditions.
//
// A client must be prepared to accept one or more 1xx status responses prior to a
// regular response, even if the client does not expect a 100 (Continue) status message.
// Unexpected 1xx status responses may be ignored by a user agent.
//
// Proxies must forward 1xx responses, unless the connection between the proxy and its client
// has been closed, or unless the proxy itself requested the generation of the 1xx response.
// (For example, if a proxy adds a "Expect: 100-continue" field when it forwards a request,
// then it need not forward the corresponding 100 (Continue) response(s).)
//

/** The 100 continue status code. */
static char HTTP_100_CONTINUE_STATUS_CODE_ARRAY[] = {'1', '0', '0', ' ', 'C', 'o', 'n', 't', 'i', 'n', 'u', 'e'};
static char* HTTP_100_CONTINUE_STATUS_CODE = HTTP_100_CONTINUE_STATUS_CODE_ARRAY;
static int* HTTP_100_CONTINUE_STATUS_CODE_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The 101 switching protocols status code. */
static char HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE_ARRAY[] = {'1', '0', '1', ' ', 'S', 'w', 'i', 't', 'c', 'h', 'i', 'n', 'g', ' ', 'P', 'r', 'o', 't', 'o', 'c', 'o', 'l', 's'};
static char* HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE = HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE_ARRAY;
static int* HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE_COUNT = NUMBER_23_INTEGER_ARRAY;

/**
 * The 102 processing status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_102_PROCESSING_STATUS_CODE_ARRAY[] = {'1', '0', '2', ' ', 'P', 'r', 'o', 'c', 'e', 's', 's', 'i', 'n', 'g'};
static char* HTTP_102_PROCESSING_STATUS_CODE = HTTP_102_PROCESSING_STATUS_CODE_ARRAY;
static int* HTTP_102_PROCESSING_STATUS_CODE_COUNT = NUMBER_14_INTEGER_ARRAY;
*/

//
// 2xx - successful
//
// This class of status code indicates that the client's request was successfully
// received, understood, and accepted.
//

/** The 200 ok status code. */
static char HTTP_200_OK_STATUS_CODE_ARRAY[] = {'2', '0', '0', ' ', 'O', 'K'};
static char* HTTP_200_OK_STATUS_CODE = HTTP_200_OK_STATUS_CODE_ARRAY;
static int* HTTP_200_OK_STATUS_CODE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The 201 created status code. */
static char HTTP_201_CREATED_STATUS_CODE_ARRAY[] = {'2', '0', '1', ' ', 'C', 'r', 'e', 'a', 't', 'e', 'd'};
static char* HTTP_201_CREATED_STATUS_CODE = HTTP_201_CREATED_STATUS_CODE_ARRAY;
static int* HTTP_201_CREATED_STATUS_CODE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The 202 accepted status code. */
static char HTTP_202_ACCEPTED_STATUS_CODE_ARRAY[] = {'2', '0', '2', ' ', 'A', 'c', 'c', 'e', 'p', 't', 'e', 'd'};
static char* HTTP_202_ACCEPTED_STATUS_CODE = HTTP_202_ACCEPTED_STATUS_CODE_ARRAY;
static int* HTTP_202_ACCEPTED_STATUS_CODE_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The 203 non-authoritative information status code. */
static char HTTP_203_NON_AUTHORITATIVE_STATUS_CODE_ARRAY[] = {'2', '0', '3', ' ', 'N', 'o', 'n', '-', 'A', 'u', 't', 'h', 'o', 'r', 'i', 't', 'a', 't', 'i', 'v', 'e', ' ', 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n'};
static char* HTTP_203_NON_AUTHORITATIVE_STATUS_CODE = HTTP_203_NON_AUTHORITATIVE_STATUS_CODE_ARRAY;
static int* HTTP_203_NON_AUTHORITATIVE_STATUS_CODE_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The 204 no content status code. */
static char HTTP_204_NO_CONTENT_STATUS_CODE_ARRAY[] = {'2', '0', '4', ' ', 'N', 'o', ' ', 'C', 'o', 'n', 't', 'e', 'n', 't'};
static char* HTTP_204_NO_CONTENT_STATUS_CODE = HTTP_204_NO_CONTENT_STATUS_CODE_ARRAY;
static int* HTTP_204_NO_CONTENT_STATUS_CODE_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The 205 reset content status code. */
static char HTTP_205_RESET_CONTENT_STATUS_CODE_ARRAY[] = {'2', '0', '5', ' ', 'R', 'e', 's', 'e', 't', ' ', 'C', 'o', 'n', 't', 'e', 'n', 't'};
static char* HTTP_205_RESET_CONTENT_STATUS_CODE = HTTP_205_RESET_CONTENT_STATUS_CODE_ARRAY;
static int* HTTP_205_RESET_CONTENT_STATUS_CODE_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The 206 partial content status code. */
static char HTTP_206_PARTIAL_CONTENT_STATUS_CODE_ARRAY[] = {'2', '0', '6', ' ', 'P', 'a', 'r', 't', 'i', 'a', 'l', ' ', 'C', 'o', 'n', 't', 'e', 'n', 't'};
static char* HTTP_206_PARTIAL_CONTENT_STATUS_CODE = HTTP_206_PARTIAL_CONTENT_STATUS_CODE_ARRAY;
static int* HTTP_206_PARTIAL_CONTENT_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/**
 * The 207 multi-status status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_207_MULTI_STATUS_STATUS_CODE_ARRAY[] = {'2', '0', '7', ' ', 'M', 'u', 'l', 't', 'i', '-', 'S', 't', 'a', 't', 'u', 's'};
static char* HTTP_207_MULTI_STATUS_STATUS_CODE = HTTP_207_MULTI_STATUS_STATUS_CODE_ARRAY;
static int* HTTP_207_MULTI_STATUS_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;
*/

//
// 3xx - redirection
//
// This class of status code indicates that further action needs to be taken by the
// user agent in order to fulfill the request. The action required may be carried
// out by the user agent without interaction with the user if and only if the method
// used in the second request is GET or HEAD. A client should detect infinite
// redirection loops, since such loops generate network traffic for each redirection.
//
// Note: previous versions of this specification recommended a maximum of five
// redirections. Content developers should be aware that there might be clients
// that implement such a fixed limitation.
//

/** The 300 multiple choices status code. */
static char HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE_ARRAY[] = {'3', '0', '0', ' ', 'M', 'u', 'l', 't', 'i', 'p', 'l', 'e', ' ', 'C', 'h', 'o', 'i', 'c', 'e', 's'};
static char* HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE = HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE_ARRAY;
static int* HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The 301 moved permanently status code. */
static char HTTP_301_MOVED_PERMANENTLY_STATUS_CODE_ARRAY[] = {'3', '0', '1', ' ', 'M', 'o', 'v', 'e', 'd', ' ', 'P', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', 'l', 'y'};
static char* HTTP_301_MOVED_PERMANENTLY_STATUS_CODE = HTTP_301_MOVED_PERMANENTLY_STATUS_CODE_ARRAY;
static int* HTTP_301_MOVED_PERMANENTLY_STATUS_CODE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The 302 found status code. */
static char HTTP_302_FOUND_STATUS_CODE_ARRAY[] = {'3', '0', '2', ' ', 'F', 'o', 'u', 'n', 'd'};
static char* HTTP_302_FOUND_STATUS_CODE = HTTP_302_FOUND_STATUS_CODE_ARRAY;
static int* HTTP_302_FOUND_STATUS_CODE_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The 303 see other status code. */
static char HTTP_303_SEE_OTHER_STATUS_CODE_ARRAY[] = {'3', '0', '3', ' ', 'S', 'e', 'e', ' ', 'O', 't', 'h', 'e', 'r'};
static char* HTTP_303_SEE_OTHER_STATUS_CODE = HTTP_303_SEE_OTHER_STATUS_CODE_ARRAY;
static int* HTTP_303_SEE_OTHER_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The 304 not modified status code. */
static char HTTP_304_NOT_MODIFIED_STATUS_CODE_ARRAY[] = {'3', '0', '4', ' ', 'N', 'o', 't', ' ', 'M', 'o', 'd', 'i', 'f', 'i', 'e', 'd'};
static char* HTTP_304_NOT_MODIFIED_STATUS_CODE = HTTP_304_NOT_MODIFIED_STATUS_CODE_ARRAY;
static int* HTTP_304_NOT_MODIFIED_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The 305 use proxy status code. */
static char HTTP_305_USE_PROXY_STATUS_CODE_ARRAY[] = {'3', '0', '5', ' ', 'U', 's', 'e', ' ', 'P', 'r', 'o', 'x', 'y'};
static char* HTTP_305_USE_PROXY_STATUS_CODE = HTTP_305_USE_PROXY_STATUS_CODE_ARRAY;
static int* HTTP_305_USE_PROXY_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/**
 * The 306 switch proxy status code.
 *
 * This status code is reserved but NOT used anymore in HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_306_SWITCH_PROXY_STATUS_CODE_ARRAY[] = {'3', '0', '6', ' ', 'S', 'w', 'i', 't', 'c', 'h', ' ', 'P', 'r', 'o', 'x', 'y'};
static char* HTTP_306_SWITCH_PROXY_STATUS_CODE = HTTP_306_SWITCH_PROXY_STATUS_CODE_ARRAY;
static int* HTTP_306_SWITCH_PROXY_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;
*/

/** The 307 temporary redirect (moved temporarily) status code. */
static char HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE_ARRAY[] = {'3', '0', '7', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'a', 'r', 'y', ' ', 'R', 'e', 'd', 'i', 'r', 'e', 'c', 't'};
static char* HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE = HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE_ARRAY;
static int* HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE_COUNT = NUMBER_22_INTEGER_ARRAY;

//
// 4xx - client error
//
// The 4xx class of status code is intended for cases in which the client seems to have erred.
// Except when responding to a HEAD request, the server should include an entity containing an
// explanation of the error situation, and whether it is a temporary or permanent condition.
// These status codes are applicable to any request method. User agents should display any
// included entity to the user.
//
// If the client is sending data, a server implementation using TCP should be careful to
// ensure that the client acknowledges receipt of the packet(s) containing the response,
// before the server closes the input connection. If the client continues sending data
// to the server after the close, the server's TCP stack will send a reset packet to the
// client, which may erase the client's unacknowledged input buffers before they can be
// read and interpreted by the HTTP application.
//

/** The 400 bad request status code. */
static char HTTP_400_BAD_REQUEST_STATUS_CODE_ARRAY[] = {'4', '0', '0', ' ', 'B', 'a', 'd', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't'};
static char* HTTP_400_BAD_REQUEST_STATUS_CODE = HTTP_400_BAD_REQUEST_STATUS_CODE_ARRAY;
static int* HTTP_400_BAD_REQUEST_STATUS_CODE_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The 401 unauthorized status code. */
static char HTTP_401_UNAUTHORIZED_STATUS_CODE_ARRAY[] = {'4', '0', '1', ' ', 'U', 'n', 'a', 'u', 't', 'h', 'o', 'r', 'i', 'z', 'e', 'd'};
static char* HTTP_401_UNAUTHORIZED_STATUS_CODE = HTTP_401_UNAUTHORIZED_STATUS_CODE_ARRAY;
static int* HTTP_401_UNAUTHORIZED_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The 402 payment required status code. */
static char HTTP_402_PAYMENT_REQUIRED_STATUS_CODE_ARRAY[] = {'4', '0', '2', ' ', 'P', 'a', 'y', 'm', 'e', 'n', 't', ' ', 'R', 'e', 'q', 'u', 'i', 'r', 'e', 'd'};
static char* HTTP_402_PAYMENT_REQUIRED_STATUS_CODE = HTTP_402_PAYMENT_REQUIRED_STATUS_CODE_ARRAY;
static int* HTTP_402_PAYMENT_REQUIRED_STATUS_CODE_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The 403 forbidden status code. */
static char HTTP_403_FORBIDDEN_STATUS_CODE_ARRAY[] = {'4', '0', '3', ' ', 'F', 'o', 'r', 'b', 'i', 'd', 'd', 'e', 'n'};
static char* HTTP_403_FORBIDDEN_STATUS_CODE = HTTP_403_FORBIDDEN_STATUS_CODE_ARRAY;
static int* HTTP_403_FORBIDDEN_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The 404 not found status code. */
static char HTTP_404_NOT_FOUND_STATUS_CODE_ARRAY[] = {'4', '0', '4', ' ', 'N', 'o', 't', ' ', 'F', 'o', 'u', 'n', 'd'};
static char* HTTP_404_NOT_FOUND_STATUS_CODE = HTTP_404_NOT_FOUND_STATUS_CODE_ARRAY;
static int* HTTP_404_NOT_FOUND_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The 405 method not allowed status code. */
static char HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE_ARRAY[] = {'4', '0', '5', ' ', 'M', 'e', 't', 'h', 'o', 'd', ' ', 'N', 'o', 't', ' ', 'A', 'l', 'l', 'o', 'w', 'e', 'd'};
static char* HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE = HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE_ARRAY;
static int* HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The 406 not acceptable status code. */
static char HTTP_406_NOT_ACCEPTABLE_STATUS_CODE_ARRAY[] = {'4', '0', '6', ' ', 'N', 'o', 't', ' ', 'A', 'c', 'c', 'e', 'p', 't', 'a', 'b', 'l', 'e'};
static char* HTTP_406_NOT_ACCEPTABLE_STATUS_CODE = HTTP_406_NOT_ACCEPTABLE_STATUS_CODE_ARRAY;
static int* HTTP_406_NOT_ACCEPTABLE_STATUS_CODE_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The 407 proxy authentication required status code. */
static char HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE_ARRAY[] = {'4', '0', '7', ' ', 'P', 'r', 'o', 'x', 'y', ' ', 'A', 'u', 't', 'h', 'e', 'n', 't', 'i', 'c', 'a', 't', 'i', 'o', 'n', ' ', 'R', 'e', 'q', 'u', 'i', 'r', 'e', 'd'};
static char* HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE = HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE_ARRAY;
static int* HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The 408 request timeout status code. */
static char HTTP_408_REQUEST_TIMEOUT_STATUS_CODE_ARRAY[] = {'4', '0', '8', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', ' ', 'T', 'i', 'm', 'e', 'o', 'u', 't'};
static char* HTTP_408_REQUEST_TIMEOUT_STATUS_CODE = HTTP_408_REQUEST_TIMEOUT_STATUS_CODE_ARRAY;
static int* HTTP_408_REQUEST_TIMEOUT_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 409 conflict status code. */
static char HTTP_409_CONFLICT_STATUS_CODE_ARRAY[] = {'4', '0', '9', ' ', 'C', 'o', 'n', 'f', 'l', 'i', 'c', 't'};
static char* HTTP_409_CONFLICT_STATUS_CODE = HTTP_409_CONFLICT_STATUS_CODE_ARRAY;
static int* HTTP_409_CONFLICT_STATUS_CODE_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The 410 gone status code. */
static char HTTP_410_GONE_STATUS_CODE_ARRAY[] = {'4', '1', '0', ' ', 'G', 'o', 'n', 'e'};
static char* HTTP_410_GONE_STATUS_CODE = HTTP_410_GONE_STATUS_CODE_ARRAY;
static int* HTTP_410_GONE_STATUS_CODE_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The 411 length required status code. */
static char HTTP_411_LENGTH_REQUIRED_STATUS_CODE_ARRAY[] = {'4', '1', '1', ' ', 'L', 'e', 'n', 'g', 't', 'h', ' ', 'R', 'e', 'q', 'u', 'i', 'r', 'e', 'd'};
static char* HTTP_411_LENGTH_REQUIRED_STATUS_CODE = HTTP_411_LENGTH_REQUIRED_STATUS_CODE_ARRAY;
static int* HTTP_411_LENGTH_REQUIRED_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 412 precondition failed status code. */
static char HTTP_412_PRECONDITION_FAILED_STATUS_CODE_ARRAY[] = {'4', '1', '2', ' ', 'P', 'r', 'e', 'c', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', ' ', 'F', 'a', 'i', 'l', 'e', 'd'};
static char* HTTP_412_PRECONDITION_FAILED_STATUS_CODE = HTTP_412_PRECONDITION_FAILED_STATUS_CODE_ARRAY;
static int* HTTP_412_PRECONDITION_FAILED_STATUS_CODE_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The 413 request entity too large status code. */
static char HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE_ARRAY[] = {'4', '1', '3', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', ' ', 'E', 'n', 't', 'i', 't', 'y', ' ', 'T', 'o', 'o', ' ', 'L', 'a', 'r', 'g', 'e'};
static char* HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE = HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE_ARRAY;
static int* HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The 414 request-uri too long status code. */
static char HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE_ARRAY[] = {'4', '1', '4', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', '-', 'U', 'R', 'I', ' ', 'T', 'o', 'o', ' ', 'L', 'o', 'n', 'g'};
static char* HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE = HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE_ARRAY;
static int* HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The 415 unsupported media type status code. */
static char HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE_ARRAY[] = {'4', '1', '5', ' ', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd', ' ', 'M', 'e', 'd', 'i', 'a', ' ', 'T', 'y', 'p', 'e'};
static char* HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE = HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE_ARRAY;
static int* HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The 416 requested range not satisfiable status code. */
static char HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE_ARRAY[] = {'4', '1', '6', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', 'e', 'd', ' ', 'R', 'a', 'n', 'g', 'e', ' ', 'N', 'o', 't', ' ', 'S', 'a', 't', 'i', 's', 'f', 'i', 'a', 'b', 'l', 'e'};
static char* HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE = HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE_ARRAY;
static int* HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE_COUNT = NUMBER_35_INTEGER_ARRAY;

/** The 417 expectation failed status code. */
static char HTTP_417_EXPECTATION_FAILED_STATUS_CODE_ARRAY[] = {'4', '1', '7', ' ', 'E', 'x', 'p', 'e', 'c', 't', 'a', 't', 'i', 'o', 'n', ' ', 'F', 'a', 'i', 'l', 'e', 'd'};
static char* HTTP_417_EXPECTATION_FAILED_STATUS_CODE = HTTP_417_EXPECTATION_FAILED_STATUS_CODE_ARRAY;
static int* HTTP_417_EXPECTATION_FAILED_STATUS_CODE_COUNT = NUMBER_22_INTEGER_ARRAY;

/**
 * The 422 unprocessable entity status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE_ARRAY[] = {'4', '2', '2', ' ', 'U', 'n', 'p', 'r', 'o', 'c', 'e', 's', 's', 'a', 'b', 'l', 'e', ' ', 'E', 'n', 't', 'i', 't', 'y'};
static char* HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE = HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE_ARRAY;
static int* HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE_COUNT = NUMBER_24_INTEGER_ARRAY;
*/

/**
 * The 423 locked status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_423_LOCKED_STATUS_CODE_ARRAY[] = {'4', '2', '3', ' ', 'L', 'o', 'c', 'k', 'e', 'd'};
static char* HTTP_423_LOCKED_STATUS_CODE = HTTP_423_LOCKED_STATUS_CODE_ARRAY;
static int* HTTP_423_LOCKED_STATUS_CODE_COUNT = NUMBER_10_INTEGER_ARRAY;
*/

/**
 * The 424 failed dependency (site too ugly) status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_424_FAILED_DEPENDENCY_STATUS_CODE_ARRAY[] = {'4', '2', '4', ' ', 'F', 'a', 'i', 'l', 'e', 'd', ' ', 'D', 'e', 'p', 'e', 'n', 'd', 'e', 'n', 'c', 'y'};
static char* HTTP_424_FAILED_DEPENDENCY_STATUS_CODE = HTTP_424_FAILED_DEPENDENCY_STATUS_CODE_ARRAY;
static int* HTTP_424_FAILED_DEPENDENCY_STATUS_CODE_COUNT = NUMBER_21_INTEGER_ARRAY;
*/

//
// 5xx - server error
//
// Response status codes beginning with the digit "5" indicate cases in which the server is
// aware that it has erred or is incapable of performing the request. Except when responding
// to a HEAD request, the server should include an entity containing an explanation of the
// error situation, and whether it is a temporary or permanent condition. User agents should
// display any included entity to the user. These response codes are applicable to any request method.
//

/** The 500 internal server error status code. */
static char HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE_ARRAY[] = {'5', '0', '0', ' ', 'I', 'n', 't', 'e', 'r', 'n', 'a', 'l', ' ', 'S', 'e', 'r', 'v', 'e', 'r', ' ', 'E', 'r', 'r', 'o', 'r'};
static char* HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE = HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE_ARRAY;
static int* HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The 501 not implemented status code. */
static char HTTP_501_NOT_IMPLEMENTED_STATUS_CODE_ARRAY[] = {'5', '0', '1', ' ', 'N', 'o', 't', ' ', 'I', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd'};
static char* HTTP_501_NOT_IMPLEMENTED_STATUS_CODE = HTTP_501_NOT_IMPLEMENTED_STATUS_CODE_ARRAY;
static int* HTTP_501_NOT_IMPLEMENTED_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 502 bad gateway status code. */
static char HTTP_502_BAD_GATEWAY_STATUS_CODE_ARRAY[] = {'5', '0', '2', ' ', 'B', 'a', 'd', ' ', 'G', 'a', 't', 'e', 'w', 'a', 'y'};
static char* HTTP_502_BAD_GATEWAY_STATUS_CODE = HTTP_502_BAD_GATEWAY_STATUS_CODE_ARRAY;
static int* HTTP_502_BAD_GATEWAY_STATUS_CODE_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The 503 service unavailable status code. */
static char HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE_ARRAY[] = {'5', '0', '3', ' ', 'S', 'e', 'r', 'v', 'i', 'c', 'e', ' ', 'U', 'n', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e'};
static char* HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE = HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE_ARRAY;
static int* HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The 504 gateway timeout status code. */
static char HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE_ARRAY[] = {'5', '0', '4', ' ', 'G', 'a', 't', 'e', 'w', 'a', 'y', ' ', 'T', 'i', 'm', 'e', 'o', 'u', 't'};
static char* HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE = HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE_ARRAY;
static int* HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 505 http version not supported status code. */
static char HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE_ARRAY[] = {'5', '0', '5', ' ', 'H', 'T', 'T', 'P', ' ', 'V', 'e', 'r', 's', 'i', 'o', 'n', ' ', 'N', 'o', 't', ' ', 'S', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd'};
static char* HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE = HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE_ARRAY;
static int* HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE_COUNT = NUMBER_30_INTEGER_ARRAY;

/**
 * The 507 insufficient storage status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE_ARRAY[] = {'5', '0', '7', ' ', 'I', 'n', 's', 'u', 'f', 'f', 'i', 'c', 'i', 'e', 'n', 't', ' ', 'S', 't', 'o', 'r', 'a', 'g', 'e'};
static char* HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE = HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE_ARRAY;
static int* HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE_COUNT = NUMBER_24_INTEGER_ARRAY;
*/

/**
 * The 509 bandwidth limit exceeded status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE_ARRAY[] = {'5', '0', '9', ' ', 'B', 'a', 'n', 'd', 'w', 'i', 'd', 't', 'h', ' ', 'L', 'i', 'm', 'i', 't', ' ', 'E', 'x', 'c', 'e', 'e', 'd', 'e', 'd'};
static char* HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE = HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE_ARRAY;
static int* HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE_COUNT = NUMBER_28_INTEGER_ARRAY;
*/

/* HTTP_STATUS_CODE_CONSTANTS_SOURCE */
#endif
