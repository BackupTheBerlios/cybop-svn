/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: status_code_http_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATUS_CODE_HTTP_MODEL_SOURCE
#define STATUS_CODE_HTTP_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

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

/** The continue 100 status code http model. */
static char CONTINUE_100_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'1', '0', '0', ' ', 'C', 'o', 'n', 't', 'i', 'n', 'u', 'e'};
static char* CONTINUE_100_STATUS_CODE_HTTP_MODEL = CONTINUE_100_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* CONTINUE_100_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The switching protocols 101 status code http model. */
static char SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'1', '0', '1', ' ', 'S', 'w', 'i', 't', 'c', 'h', 'i', 'n', 'g', ' ', 'P', 'r', 'o', 't', 'o', 'c', 'o', 'l', 's'};
static char* SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL = SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The processing 102 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char PROCESSING_102_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'1', '0', '2', ' ', 'P', 'r', 'o', 'c', 'e', 's', 's', 'i', 'n', 'g'};
static char* PROCESSING_102_STATUS_CODE_HTTP_MODEL = PROCESSING_102_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PROCESSING_102_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;
*/

//
// 2xx - successful
//
// This class of status code indicates that the client's request was successfully
// received, understood, and accepted.
//

/** The ok 200 status code http model. */
static char OK_200_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '0', ' ', 'O', 'K'};
static char* OK_200_STATUS_CODE_HTTP_MODEL = OK_200_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* OK_200_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The created 201 status code http model. */
static char CREATED_201_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '1', ' ', 'C', 'r', 'e', 'a', 't', 'e', 'd'};
static char* CREATED_201_STATUS_CODE_HTTP_MODEL = CREATED_201_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* CREATED_201_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The accepted 202 status code http model. */
static char ACCEPTED_202_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '2', ' ', 'A', 'c', 'c', 'e', 'p', 't', 'e', 'd'};
static char* ACCEPTED_202_STATUS_CODE_HTTP_MODEL = ACCEPTED_202_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* ACCEPTED_202_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The non-authoritative information 203 status code http model. */
static char NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '3', ' ', 'N', 'o', 'n', '-', 'A', 'u', 't', 'h', 'o', 'r', 'i', 't', 'a', 't', 'i', 'v', 'e', ' ', 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n'};
static char* NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL = NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The no content 204 status code http model. */
static char NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '4', ' ', 'N', 'o', ' ', 'C', 'o', 'n', 't', 'e', 'n', 't'};
static char* NO_CONTENT_204_STATUS_CODE_HTTP_MODEL = NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The reset content 205 status code http model. */
static char RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '5', ' ', 'R', 'e', 's', 'e', 't', ' ', 'C', 'o', 'n', 't', 'e', 'n', 't'};
static char* RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL = RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The partial content 206 status code http model. */
static char PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '6', ' ', 'P', 'a', 'r', 't', 'i', 'a', 'l', ' ', 'C', 'o', 'n', 't', 'e', 'n', 't'};
static char* PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL = PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The multi-status 207 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'2', '0', '7', ' ', 'M', 'u', 'l', 't', 'i', '-', 'S', 't', 'a', 't', 'u', 's'};
static char* MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL = MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;
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

/** The multiple choices 300 status code http model. */
static char MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '0', ' ', 'M', 'u', 'l', 't', 'i', 'p', 'l', 'e', ' ', 'C', 'h', 'o', 'i', 'c', 'e', 's'};
static char* MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL = MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The moved permanently 301 status code http model. */
static char MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '1', ' ', 'M', 'o', 'v', 'e', 'd', ' ', 'P', 'e', 'r', 'm', 'a', 'n', 'e', 'n', 't', 'l', 'y'};
static char* MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL = MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The found 302 status code http model. */
static char FOUND_302_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '2', ' ', 'F', 'o', 'u', 'n', 'd'};
static char* FOUND_302_STATUS_CODE_HTTP_MODEL = FOUND_302_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* FOUND_302_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The see other 303 status code http model. */
static char SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '3', ' ', 'S', 'e', 'e', ' ', 'O', 't', 'h', 'e', 'r'};
static char* SEE_OTHER_303_STATUS_CODE_HTTP_MODEL = SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The not modified 304 status code http model. */
static char NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '4', ' ', 'N', 'o', 't', ' ', 'M', 'o', 'd', 'i', 'f', 'i', 'e', 'd'};
static char* NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL = NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The use proxy 305 status code http model. */
static char USE_PROXY_305_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '5', ' ', 'U', 's', 'e', ' ', 'P', 'r', 'o', 'x', 'y'};
static char* USE_PROXY_305_STATUS_CODE_HTTP_MODEL = USE_PROXY_305_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* USE_PROXY_305_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The switch proxy 306 status code http model.
 *
 * This status code is reserved but NOT used anymore in HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '6', ' ', 'S', 'w', 'i', 't', 'c', 'h', ' ', 'P', 'r', 'o', 'x', 'y'};
static char* SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL = SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;
*/

/** The temporary redirect (moved temporarily) 307 status code http model. */
static char TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'3', '0', '7', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'a', 'r', 'y', ' ', 'R', 'e', 'd', 'i', 'r', 'e', 'c', 't'};
static char* TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL = TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

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

/** The bad request 400 status code http model. */
static char BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '0', ' ', 'B', 'a', 'd', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't'};
static char* BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL = BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The unauthorized 401 status code http model. */
static char UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '1', ' ', 'U', 'n', 'a', 'u', 't', 'h', 'o', 'r', 'i', 'z', 'e', 'd'};
static char* UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL = UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The payment required 402 status code http model. */
static char PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '2', ' ', 'P', 'a', 'y', 'm', 'e', 'n', 't', ' ', 'R', 'e', 'q', 'u', 'i', 'r', 'e', 'd'};
static char* PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL = PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The forbidden 403 status code http model. */
static char FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '3', ' ', 'F', 'o', 'r', 'b', 'i', 'd', 'd', 'e', 'n'};
static char* FORBIDDEN_403_STATUS_CODE_HTTP_MODEL = FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The not found 404 status code http model. */
static char NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '4', ' ', 'N', 'o', 't', ' ', 'F', 'o', 'u', 'n', 'd'};
static char* NOT_FOUND_404_STATUS_CODE_HTTP_MODEL = NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The method not allowed 405 status code http model. */
static char METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '5', ' ', 'M', 'e', 't', 'h', 'o', 'd', ' ', 'N', 'o', 't', ' ', 'A', 'l', 'l', 'o', 'w', 'e', 'd'};
static char* METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL = METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The not acceptable 406 status code http model. */
static char NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '6', ' ', 'N', 'o', 't', ' ', 'A', 'c', 'c', 'e', 'p', 't', 'a', 'b', 'l', 'e'};
static char* NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL = NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The proxy authentication required 407 status code http model. */
static char PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '7', ' ', 'P', 'r', 'o', 'x', 'y', ' ', 'A', 'u', 't', 'h', 'e', 'n', 't', 'i', 'c', 'a', 't', 'i', 'o', 'n', ' ', 'R', 'e', 'q', 'u', 'i', 'r', 'e', 'd'};
static char* PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL = PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The request timeout 408 status code http model. */
static char REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '8', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', ' ', 'T', 'i', 'm', 'e', 'o', 'u', 't'};
static char* REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL = REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The conflict 409 status code http model. */
static char CONFLICT_409_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '0', '9', ' ', 'C', 'o', 'n', 'f', 'l', 'i', 'c', 't'};
static char* CONFLICT_409_STATUS_CODE_HTTP_MODEL = CONFLICT_409_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* CONFLICT_409_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The gone 410 status code http model. */
static char GONE_410_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '0', ' ', 'G', 'o', 'n', 'e'};
static char* GONE_410_STATUS_CODE_HTTP_MODEL = GONE_410_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* GONE_410_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The length required 411 status code http model. */
static char LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '1', ' ', 'L', 'e', 'n', 'g', 't', 'h', ' ', 'R', 'e', 'q', 'u', 'i', 'r', 'e', 'd'};
static char* LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL = LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The precondition failed 412 status code http model. */
static char PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '2', ' ', 'P', 'r', 'e', 'c', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', ' ', 'F', 'a', 'i', 'l', 'e', 'd'};
static char* PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL = PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The request entity too large 413 status code http model. */
static char REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '3', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', ' ', 'E', 'n', 't', 'i', 't', 'y', ' ', 'T', 'o', 'o', ' ', 'L', 'a', 'r', 'g', 'e'};
static char* REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL = REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The request-uri too long 414 status code http model. */
static char REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '4', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', '-', 'U', 'R', 'I', ' ', 'T', 'o', 'o', ' ', 'L', 'o', 'n', 'g'};
static char* REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL = REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsupported media type 415 status code http model. */
static char UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '5', ' ', 'U', 'n', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd', ' ', 'M', 'e', 'd', 'i', 'a', ' ', 'T', 'y', 'p', 'e'};
static char* UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL = UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The requested range not satisfiable 416 status code http model. */
static char REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '6', ' ', 'R', 'e', 'q', 'u', 'e', 's', 't', 'e', 'd', ' ', 'R', 'a', 'n', 'g', 'e', ' ', 'N', 'o', 't', ' ', 'S', 'a', 't', 'i', 's', 'f', 'i', 'a', 'b', 'l', 'e'};
static char* REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL = REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The expectation failed 417 status code http model. */
static char EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '1', '7', ' ', 'E', 'x', 'p', 'e', 'c', 't', 'a', 't', 'i', 'o', 'n', ' ', 'F', 'a', 'i', 'l', 'e', 'd'};
static char* EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL = EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The unprocessable entity 422 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '2', '2', ' ', 'U', 'n', 'p', 'r', 'o', 'c', 'e', 's', 's', 'a', 'b', 'l', 'e', ' ', 'E', 'n', 't', 'i', 't', 'y'};
static char* UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL = UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The locked 423 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char LOCKED_423_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '2', '3', ' ', 'L', 'o', 'c', 'k', 'e', 'd'};
static char* LOCKED_423_STATUS_CODE_HTTP_MODEL = LOCKED_423_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* LOCKED_423_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The failed dependency (site too ugly) 424 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'4', '2', '4', ' ', 'F', 'a', 'i', 'l', 'e', 'd', ' ', 'D', 'e', 'p', 'e', 'n', 'd', 'e', 'n', 'c', 'y'};
static char* FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL = FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;
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

/** The internal server error 500 status code http model. */
static char INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '0', ' ', 'I', 'n', 't', 'e', 'r', 'n', 'a', 'l', ' ', 'S', 'e', 'r', 'v', 'e', 'r', ' ', 'E', 'r', 'r', 'o', 'r'};
static char* INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL = INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The not implemented 501 status code http model. */
static char NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '1', ' ', 'N', 'o', 't', ' ', 'I', 'm', 'p', 'l', 'e', 'm', 'e', 'n', 't', 'e', 'd'};
static char* NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL = NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The bad gateway 502 status code http model. */
static char BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '2', ' ', 'B', 'a', 'd', ' ', 'G', 'a', 't', 'e', 'w', 'a', 'y'};
static char* BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL = BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The service unavailable 503 status code http model. */
static char SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '3', ' ', 'S', 'e', 'r', 'v', 'i', 'c', 'e', ' ', 'U', 'n', 'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e'};
static char* SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL = SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The gateway timeout 504 status code http model. */
static char GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '4', ' ', 'G', 'a', 't', 'e', 'w', 'a', 'y', ' ', 'T', 'i', 'm', 'e', 'o', 'u', 't'};
static char* GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL = GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The http version not supported 505 status code http model. */
static char HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '5', ' ', 'H', 'T', 'T', 'P', ' ', 'V', 'e', 'r', 's', 'i', 'o', 'n', ' ', 'N', 'o', 't', ' ', 'S', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd'};
static char* HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL = HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insufficient storage 507 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '7', ' ', 'I', 'n', 's', 'u', 'f', 'f', 'i', 'c', 'i', 'e', 'n', 't', ' ', 'S', 't', 'o', 'r', 'a', 'g', 'e'};
static char* INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL = INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The bandwidth limit exceeded 509 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static char BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_ARRAY[] = {'5', '0', '9', ' ', 'B', 'a', 'n', 'd', 'w', 'i', 'd', 't', 'h', ' ', 'L', 'i', 'm', 'i', 't', ' ', 'E', 'x', 'c', 'e', 'e', 'd', 'e', 'd'};
static char* BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL = BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;
*/

/* STATUS_CODE_HTTP_MODEL_SOURCE */
#endif
