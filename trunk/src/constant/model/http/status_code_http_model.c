/*
 * Copyright (C) 1999-2009. Christian Heller.
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
static wchar_t CONTINUE_100_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'1', L'0', L'0', L' ', L'C', L'o', L'n', L't', L'i', L'n', L'u', L'e'};
static wchar_t* CONTINUE_100_STATUS_CODE_HTTP_MODEL = CONTINUE_100_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* CONTINUE_100_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The switching protocols 101 status code http model. */
static wchar_t SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'1', L'0', L'1', L' ', L'S', L'w', L'i', L't', L'c', L'h', L'i', L'n', L'g', L' ', L'P', L'r', L'o', L't', L'o', L'c', L'o', L'l', L's'};
static wchar_t* SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL = SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The processing 102 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t PROCESSING_102_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'1', L'0', L'2', L' ', L'P', L'r', L'o', L'c', L'e', L's', L's', L'i', L'n', L'g'};
static wchar_t* PROCESSING_102_STATUS_CODE_HTTP_MODEL = PROCESSING_102_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PROCESSING_102_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;
*/

//
// 2xx - successful
//
// This class of status code indicates that the client's request was successfully
// received, understood, and accepted.
//

/** The ok 200 status code http model. */
static wchar_t OK_200_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'0', L' ', L'O', L'K'};
static wchar_t* OK_200_STATUS_CODE_HTTP_MODEL = OK_200_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* OK_200_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The created 201 status code http model. */
static wchar_t CREATED_201_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'1', L' ', L'C', L'r', L'e', L'a', L't', L'e', L'd'};
static wchar_t* CREATED_201_STATUS_CODE_HTTP_MODEL = CREATED_201_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* CREATED_201_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The accepted 202 status code http model. */
static wchar_t ACCEPTED_202_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'2', L' ', L'A', L'c', L'c', L'e', L'p', L't', L'e', L'd'};
static wchar_t* ACCEPTED_202_STATUS_CODE_HTTP_MODEL = ACCEPTED_202_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* ACCEPTED_202_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The non-authoritative information 203 status code http model. */
static wchar_t NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'3', L' ', L'N', L'o', L'n', L'-', L'A', L'u', L't', L'h', L'o', L'r', L'i', L't', L'a', L't', L'i', L'v', L'e', L' ', L'I', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n'};
static wchar_t* NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL = NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The no content 204 status code http model. */
static wchar_t NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'4', L' ', L'N', L'o', L' ', L'C', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* NO_CONTENT_204_STATUS_CODE_HTTP_MODEL = NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The reset content 205 status code http model. */
static wchar_t RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'5', L' ', L'R', L'e', L's', L'e', L't', L' ', L'C', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL = RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The partial content 206 status code http model. */
static wchar_t PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'6', L' ', L'P', L'a', L'r', L't', L'i', L'a', L'l', L' ', L'C', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL = PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The multi-status 207 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'2', L'0', L'7', L' ', L'M', L'u', L'l', L't', L'i', L'-', L'S', L't', L'a', L't', L'u', L's'};
static wchar_t* MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL = MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL_ARRAY;
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
static wchar_t MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'0', L' ', L'M', L'u', L'l', L't', L'i', L'p', L'l', L'e', L' ', L'C', L'h', L'o', L'i', L'c', L'e', L's'};
static wchar_t* MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL = MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The moved permanently 301 status code http model. */
static wchar_t MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'1', L' ', L'M', L'o', L'v', L'e', L'd', L' ', L'P', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'l', L'y'};
static wchar_t* MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL = MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The found 302 status code http model. */
static wchar_t FOUND_302_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'2', L' ', L'F', L'o', L'u', L'n', L'd'};
static wchar_t* FOUND_302_STATUS_CODE_HTTP_MODEL = FOUND_302_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* FOUND_302_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The see other 303 status code http model. */
static wchar_t SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'3', L' ', L'S', L'e', L'e', L' ', L'O', L't', L'h', L'e', L'r'};
static wchar_t* SEE_OTHER_303_STATUS_CODE_HTTP_MODEL = SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The not modified 304 status code http model. */
static wchar_t NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'4', L' ', L'N', L'o', L't', L' ', L'M', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL = NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The use proxy 305 status code http model. */
static wchar_t USE_PROXY_305_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'5', L' ', L'U', L's', L'e', L' ', L'P', L'r', L'o', L'x', L'y'};
static wchar_t* USE_PROXY_305_STATUS_CODE_HTTP_MODEL = USE_PROXY_305_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* USE_PROXY_305_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The switch proxy 306 status code http model.
 *
 * This status code is reserved but NOT used anymore in HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'6', L' ', L'S', L'w', L'i', L't', L'c', L'h', L' ', L'P', L'r', L'o', L'x', L'y'};
static wchar_t* SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL = SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;
*/

/** The temporary redirect (moved temporarily) 307 status code http model. */
static wchar_t TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'3', L'0', L'7', L' ', L'T', L'e', L'm', L'p', L'o', L'r', L'a', L'r', L'y', L' ', L'R', L'e', L'd', L'i', L'r', L'e', L'c', L't'};
static wchar_t* TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL = TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL_ARRAY;
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
static wchar_t BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'0', L' ', L'B', L'a', L'd', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL = BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The unauthorized 401 status code http model. */
static wchar_t UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'1', L' ', L'U', L'n', L'a', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'e', L'd'};
static wchar_t* UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL = UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The payment required 402 status code http model. */
static wchar_t PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'2', L' ', L'P', L'a', L'y', L'm', L'e', L'n', L't', L' ', L'R', L'e', L'q', L'u', L'i', L'r', L'e', L'd'};
static wchar_t* PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL = PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The forbidden 403 status code http model. */
static wchar_t FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'3', L' ', L'F', L'o', L'r', L'b', L'i', L'd', L'd', L'e', L'n'};
static wchar_t* FORBIDDEN_403_STATUS_CODE_HTTP_MODEL = FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The not found 404 status code http model. */
static wchar_t NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'4', L' ', L'N', L'o', L't', L' ', L'F', L'o', L'u', L'n', L'd'};
static wchar_t* NOT_FOUND_404_STATUS_CODE_HTTP_MODEL = NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The method not allowed 405 status code http model. */
static wchar_t METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'5', L' ', L'M', L'e', L't', L'h', L'o', L'd', L' ', L'N', L'o', L't', L' ', L'A', L'l', L'l', L'o', L'w', L'e', L'd'};
static wchar_t* METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL = METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The not acceptable 406 status code http model. */
static wchar_t NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'6', L' ', L'N', L'o', L't', L' ', L'A', L'c', L'c', L'e', L'p', L't', L'a', L'b', L'l', L'e'};
static wchar_t* NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL = NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The proxy authentication required 407 status code http model. */
static wchar_t PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'7', L' ', L'P', L'r', L'o', L'x', L'y', L' ', L'A', L'u', L't', L'h', L'e', L'n', L't', L'i', L'c', L'a', L't', L'i', L'o', L'n', L' ', L'R', L'e', L'q', L'u', L'i', L'r', L'e', L'd'};
static wchar_t* PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL = PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The request timeout 408 status code http model. */
static wchar_t REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'8', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L' ', L'T', L'i', L'm', L'e', L'o', L'u', L't'};
static wchar_t* REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL = REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The conflict 409 status code http model. */
static wchar_t CONFLICT_409_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'0', L'9', L' ', L'C', L'o', L'n', L'f', L'l', L'i', L'c', L't'};
static wchar_t* CONFLICT_409_STATUS_CODE_HTTP_MODEL = CONFLICT_409_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* CONFLICT_409_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The gone 410 status code http model. */
static wchar_t GONE_410_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'0', L' ', L'G', L'o', L'n', L'e'};
static wchar_t* GONE_410_STATUS_CODE_HTTP_MODEL = GONE_410_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* GONE_410_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The length required 411 status code http model. */
static wchar_t LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'1', L' ', L'L', L'e', L'n', L'g', L't', L'h', L' ', L'R', L'e', L'q', L'u', L'i', L'r', L'e', L'd'};
static wchar_t* LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL = LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The precondition failed 412 status code http model. */
static wchar_t PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'2', L' ', L'P', L'r', L'e', L'c', L'o', L'n', L'd', L'i', L't', L'i', L'o', L'n', L' ', L'F', L'a', L'i', L'l', L'e', L'd'};
static wchar_t* PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL = PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The request entity too large 413 status code http model. */
static wchar_t REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'3', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L' ', L'E', L'n', L't', L'i', L't', L'y', L' ', L'T', L'o', L'o', L' ', L'L', L'a', L'r', L'g', L'e'};
static wchar_t* REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL = REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The request-uri too long 414 status code http model. */
static wchar_t REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'4', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L'-', L'U', L'R', L'I', L' ', L'T', L'o', L'o', L' ', L'L', L'o', L'n', L'g'};
static wchar_t* REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL = REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsupported media type 415 status code http model. */
static wchar_t UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'5', L' ', L'U', L'n', L's', L'u', L'p', L'p', L'o', L'r', L't', L'e', L'd', L' ', L'M', L'e', L'd', L'i', L'a', L' ', L'T', L'y', L'p', L'e'};
static wchar_t* UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL = UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_26_INTEGER_MEMORY_MODEL_ARRAY;

/** The requested range not satisfiable 416 status code http model. */
static wchar_t REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'6', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L'e', L'd', L' ', L'R', L'a', L'n', L'g', L'e', L' ', L'N', L'o', L't', L' ', L'S', L'a', L't', L'i', L's', L'f', L'i', L'a', L'b', L'l', L'e'};
static wchar_t* REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL = REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The expectation failed 417 status code http model. */
static wchar_t EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'1', L'7', L' ', L'E', L'x', L'p', L'e', L'c', L't', L'a', L't', L'i', L'o', L'n', L' ', L'F', L'a', L'i', L'l', L'e', L'd'};
static wchar_t* EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL = EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The unprocessable entity 422 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'2', L'2', L' ', L'U', L'n', L'p', L'r', L'o', L'c', L'e', L's', L's', L'a', L'b', L'l', L'e', L' ', L'E', L'n', L't', L'i', L't', L'y'};
static wchar_t* UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL = UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The locked 423 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t LOCKED_423_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'2', L'3', L' ', L'L', L'o', L'c', L'k', L'e', L'd'};
static wchar_t* LOCKED_423_STATUS_CODE_HTTP_MODEL = LOCKED_423_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* LOCKED_423_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The failed dependency (site too ugly) 424 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'4', L'2', L'4', L' ', L'F', L'a', L'i', L'l', L'e', L'd', L' ', L'D', L'e', L'p', L'e', L'n', L'd', L'e', L'n', L'c', L'y'};
static wchar_t* FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL = FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL_ARRAY;
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
static wchar_t INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'0', L' ', L'I', L'n', L't', L'e', L'r', L'n', L'a', L'l', L' ', L'S', L'e', L'r', L'v', L'e', L'r', L' ', L'E', L'r', L'r', L'o', L'r'};
static wchar_t* INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL = INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The not implemented 501 status code http model. */
static wchar_t NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'1', L' ', L'N', L'o', L't', L' ', L'I', L'm', L'p', L'l', L'e', L'm', L'e', L'n', L't', L'e', L'd'};
static wchar_t* NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL = NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The bad gateway 502 status code http model. */
static wchar_t BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'2', L' ', L'B', L'a', L'd', L' ', L'G', L'a', L't', L'e', L'w', L'a', L'y'};
static wchar_t* BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL = BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The service unavailable 503 status code http model. */
static wchar_t SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'3', L' ', L'S', L'e', L'r', L'v', L'i', L'c', L'e', L' ', L'U', L'n', L'a', L'v', L'a', L'i', L'l', L'a', L'b', L'l', L'e'};
static wchar_t* SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL = SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The gateway timeout 504 status code http model. */
static wchar_t GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'4', L' ', L'G', L'a', L't', L'e', L'w', L'a', L'y', L' ', L'T', L'i', L'm', L'e', L'o', L'u', L't'};
static wchar_t* GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL = GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The http version not supported 505 status code http model. */
static wchar_t HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'5', L' ', L'H', L'T', L'T', L'P', L' ', L'V', L'e', L'r', L's', L'i', L'o', L'n', L' ', L'N', L'o', L't', L' ', L'S', L'u', L'p', L'p', L'o', L'r', L't', L'e', L'd'};
static wchar_t* HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL = HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The insufficient storage 507 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'7', L' ', L'I', L'n', L's', L'u', L'f', L'f', L'i', L'c', L'i', L'e', L'n', L't', L' ', L'S', L't', L'o', L'r', L'a', L'g', L'e'};
static wchar_t* INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL = INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;
*/

/**
 * The bandwidth limit exceeded 509 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_ARRAY[] = {L'5', L'0', L'9', L' ', L'B', L'a', L'n', L'd', L'w', L'i', L'd', L't', L'h', L' ', L'L', L'i', L'm', L'i', L't', L' ', L'E', L'x', L'c', L'e', L'e', L'd', L'e', L'd'};
static wchar_t* BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL = BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_ARRAY;
static int* BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;
*/

/* STATUS_CODE_HTTP_MODEL_SOURCE */
#endif
