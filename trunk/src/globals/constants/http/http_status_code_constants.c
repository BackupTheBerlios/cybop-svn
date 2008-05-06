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
 * @version $Revision: 1.6 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
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
static wchar_t HTTP_100_CONTINUE_STATUS_CODE_ARRAY[] = {L'1', L'0', L'0', L' ', L'C', L'o', L'n', L't', L'i', L'n', L'u', L'e'};
static wchar_t* HTTP_100_CONTINUE_STATUS_CODE = HTTP_100_CONTINUE_STATUS_CODE_ARRAY;
static int* HTTP_100_CONTINUE_STATUS_CODE_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The 101 switching protocols status code. */
static wchar_t HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE_ARRAY[] = {L'1', L'0', L'1', L' ', L'S', L'w', L'i', L't', L'c', L'h', L'i', L'n', L'g', L' ', L'P', L'r', L'o', L't', L'o', L'c', L'o', L'l', L's'};
static wchar_t* HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE = HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE_ARRAY;
static int* HTTP_101_SWITCHING_PROTOCOLS_STATUS_CODE_COUNT = NUMBER_23_INTEGER_ARRAY;

/**
 * The 102 processing status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_102_PROCESSING_STATUS_CODE_ARRAY[] = {L'1', L'0', L'2', L' ', L'P', L'r', L'o', L'c', L'e', L's', L's', L'i', L'n', L'g'};
static wchar_t* HTTP_102_PROCESSING_STATUS_CODE = HTTP_102_PROCESSING_STATUS_CODE_ARRAY;
static int* HTTP_102_PROCESSING_STATUS_CODE_COUNT = NUMBER_14_INTEGER_ARRAY;
*/

//
// 2xx - successful
//
// This class of status code indicates that the client's request was successfully
// received, understood, and accepted.
//

/** The 200 ok status code. */
static wchar_t HTTP_200_OK_STATUS_CODE_ARRAY[] = {L'2', L'0', L'0', L' ', L'O', L'K'};
static wchar_t* HTTP_200_OK_STATUS_CODE = HTTP_200_OK_STATUS_CODE_ARRAY;
static int* HTTP_200_OK_STATUS_CODE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The 201 created status code. */
static wchar_t HTTP_201_CREATED_STATUS_CODE_ARRAY[] = {L'2', L'0', L'1', L' ', L'C', L'r', L'e', L'a', L't', L'e', L'd'};
static wchar_t* HTTP_201_CREATED_STATUS_CODE = HTTP_201_CREATED_STATUS_CODE_ARRAY;
static int* HTTP_201_CREATED_STATUS_CODE_COUNT = NUMBER_11_INTEGER_ARRAY;

/** The 202 accepted status code. */
static wchar_t HTTP_202_ACCEPTED_STATUS_CODE_ARRAY[] = {L'2', L'0', L'2', L' ', L'A', L'c', L'c', L'e', L'p', L't', L'e', L'd'};
static wchar_t* HTTP_202_ACCEPTED_STATUS_CODE = HTTP_202_ACCEPTED_STATUS_CODE_ARRAY;
static int* HTTP_202_ACCEPTED_STATUS_CODE_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The 203 non-authoritative information status code. */
static wchar_t HTTP_203_NON_AUTHORITATIVE_STATUS_CODE_ARRAY[] = {L'2', L'0', L'3', L' ', L'N', L'o', L'n', L'-', L'A', L'u', L't', L'h', L'o', L'r', L'i', L't', L'a', L't', L'i', L'v', L'e', L' ', L'I', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n'};
static wchar_t* HTTP_203_NON_AUTHORITATIVE_STATUS_CODE = HTTP_203_NON_AUTHORITATIVE_STATUS_CODE_ARRAY;
static int* HTTP_203_NON_AUTHORITATIVE_STATUS_CODE_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The 204 no content status code. */
static wchar_t HTTP_204_NO_CONTENT_STATUS_CODE_ARRAY[] = {L'2', L'0', L'4', L' ', L'N', L'o', L' ', L'C', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* HTTP_204_NO_CONTENT_STATUS_CODE = HTTP_204_NO_CONTENT_STATUS_CODE_ARRAY;
static int* HTTP_204_NO_CONTENT_STATUS_CODE_COUNT = NUMBER_14_INTEGER_ARRAY;

/** The 205 reset content status code. */
static wchar_t HTTP_205_RESET_CONTENT_STATUS_CODE_ARRAY[] = {L'2', L'0', L'5', L' ', L'R', L'e', L's', L'e', L't', L' ', L'C', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* HTTP_205_RESET_CONTENT_STATUS_CODE = HTTP_205_RESET_CONTENT_STATUS_CODE_ARRAY;
static int* HTTP_205_RESET_CONTENT_STATUS_CODE_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The 206 partial content status code. */
static wchar_t HTTP_206_PARTIAL_CONTENT_STATUS_CODE_ARRAY[] = {L'2', L'0', L'6', L' ', L'P', L'a', L'r', L't', L'i', L'a', L'l', L' ', L'C', L'o', L'n', L't', L'e', L'n', L't'};
static wchar_t* HTTP_206_PARTIAL_CONTENT_STATUS_CODE = HTTP_206_PARTIAL_CONTENT_STATUS_CODE_ARRAY;
static int* HTTP_206_PARTIAL_CONTENT_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/**
 * The 207 multi-status status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_207_MULTI_STATUS_STATUS_CODE_ARRAY[] = {L'2', L'0', L'7', L' ', L'M', L'u', L'l', L't', L'i', L'-', L'S', L't', L'a', L't', L'u', L's'};
static wchar_t* HTTP_207_MULTI_STATUS_STATUS_CODE = HTTP_207_MULTI_STATUS_STATUS_CODE_ARRAY;
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
static wchar_t HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE_ARRAY[] = {L'3', L'0', L'0', L' ', L'M', L'u', L'l', L't', L'i', L'p', L'l', L'e', L' ', L'C', L'h', L'o', L'i', L'c', L'e', L's'};
static wchar_t* HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE = HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE_ARRAY;
static int* HTTP_300_MULTIPLE_CHOICEs_STATUS_CODE_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The 301 moved permanently status code. */
static wchar_t HTTP_301_MOVED_PERMANENTLY_STATUS_CODE_ARRAY[] = {L'3', L'0', L'1', L' ', L'M', L'o', L'v', L'e', L'd', L' ', L'P', L'e', L'r', L'm', L'a', L'n', L'e', L'n', L't', L'l', L'y'};
static wchar_t* HTTP_301_MOVED_PERMANENTLY_STATUS_CODE = HTTP_301_MOVED_PERMANENTLY_STATUS_CODE_ARRAY;
static int* HTTP_301_MOVED_PERMANENTLY_STATUS_CODE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The 302 found status code. */
static wchar_t HTTP_302_FOUND_STATUS_CODE_ARRAY[] = {L'3', L'0', L'2', L' ', L'F', L'o', L'u', L'n', L'd'};
static wchar_t* HTTP_302_FOUND_STATUS_CODE = HTTP_302_FOUND_STATUS_CODE_ARRAY;
static int* HTTP_302_FOUND_STATUS_CODE_COUNT = NUMBER_9_INTEGER_ARRAY;

/** The 303 see other status code. */
static wchar_t HTTP_303_SEE_OTHER_STATUS_CODE_ARRAY[] = {L'3', L'0', L'3', L' ', L'S', L'e', L'e', L' ', L'O', L't', L'h', L'e', L'r'};
static wchar_t* HTTP_303_SEE_OTHER_STATUS_CODE = HTTP_303_SEE_OTHER_STATUS_CODE_ARRAY;
static int* HTTP_303_SEE_OTHER_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The 304 not modified status code. */
static wchar_t HTTP_304_NOT_MODIFIED_STATUS_CODE_ARRAY[] = {L'3', L'0', L'4', L' ', L'N', L'o', L't', L' ', L'M', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* HTTP_304_NOT_MODIFIED_STATUS_CODE = HTTP_304_NOT_MODIFIED_STATUS_CODE_ARRAY;
static int* HTTP_304_NOT_MODIFIED_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The 305 use proxy status code. */
static wchar_t HTTP_305_USE_PROXY_STATUS_CODE_ARRAY[] = {L'3', L'0', L'5', L' ', L'U', L's', L'e', L' ', L'P', L'r', L'o', L'x', L'y'};
static wchar_t* HTTP_305_USE_PROXY_STATUS_CODE = HTTP_305_USE_PROXY_STATUS_CODE_ARRAY;
static int* HTTP_305_USE_PROXY_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/**
 * The 306 switch proxy status code.
 *
 * This status code is reserved but NOT used anymore in HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_306_SWITCH_PROXY_STATUS_CODE_ARRAY[] = {L'3', L'0', L'6', L' ', L'S', L'w', L'i', L't', L'c', L'h', L' ', L'P', L'r', L'o', L'x', L'y'};
static wchar_t* HTTP_306_SWITCH_PROXY_STATUS_CODE = HTTP_306_SWITCH_PROXY_STATUS_CODE_ARRAY;
static int* HTTP_306_SWITCH_PROXY_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;
*/

/** The 307 temporary redirect (moved temporarily) status code. */
static wchar_t HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE_ARRAY[] = {L'3', L'0', L'7', L' ', L'T', L'e', L'm', L'p', L'o', L'r', L'a', L'r', L'y', L' ', L'R', L'e', L'd', L'i', L'r', L'e', L'c', L't'};
static wchar_t* HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE = HTTP_307_TEMPORARY_REDIRECT_STATUS_CODE_ARRAY;
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
static wchar_t HTTP_400_BAD_REQUEST_STATUS_CODE_ARRAY[] = {L'4', L'0', L'0', L' ', L'B', L'a', L'd', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* HTTP_400_BAD_REQUEST_STATUS_CODE = HTTP_400_BAD_REQUEST_STATUS_CODE_ARRAY;
static int* HTTP_400_BAD_REQUEST_STATUS_CODE_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The 401 unauthorized status code. */
static wchar_t HTTP_401_UNAUTHORIZED_STATUS_CODE_ARRAY[] = {L'4', L'0', L'1', L' ', L'U', L'n', L'a', L'u', L't', L'h', L'o', L'r', L'i', L'z', L'e', L'd'};
static wchar_t* HTTP_401_UNAUTHORIZED_STATUS_CODE = HTTP_401_UNAUTHORIZED_STATUS_CODE_ARRAY;
static int* HTTP_401_UNAUTHORIZED_STATUS_CODE_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The 402 payment required status code. */
static wchar_t HTTP_402_PAYMENT_REQUIRED_STATUS_CODE_ARRAY[] = {L'4', L'0', L'2', L' ', L'P', L'a', L'y', L'm', L'e', L'n', L't', L' ', L'R', L'e', L'q', L'u', L'i', L'r', L'e', L'd'};
static wchar_t* HTTP_402_PAYMENT_REQUIRED_STATUS_CODE = HTTP_402_PAYMENT_REQUIRED_STATUS_CODE_ARRAY;
static int* HTTP_402_PAYMENT_REQUIRED_STATUS_CODE_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The 403 forbidden status code. */
static wchar_t HTTP_403_FORBIDDEN_STATUS_CODE_ARRAY[] = {L'4', L'0', L'3', L' ', L'F', L'o', L'r', L'b', L'i', L'd', L'd', L'e', L'n'};
static wchar_t* HTTP_403_FORBIDDEN_STATUS_CODE = HTTP_403_FORBIDDEN_STATUS_CODE_ARRAY;
static int* HTTP_403_FORBIDDEN_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The 404 not found status code. */
static wchar_t HTTP_404_NOT_FOUND_STATUS_CODE_ARRAY[] = {L'4', L'0', L'4', L' ', L'N', L'o', L't', L' ', L'F', L'o', L'u', L'n', L'd'};
static wchar_t* HTTP_404_NOT_FOUND_STATUS_CODE = HTTP_404_NOT_FOUND_STATUS_CODE_ARRAY;
static int* HTTP_404_NOT_FOUND_STATUS_CODE_COUNT = NUMBER_13_INTEGER_ARRAY;

/** The 405 method not allowed status code. */
static wchar_t HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE_ARRAY[] = {L'4', L'0', L'5', L' ', L'M', L'e', L't', L'h', L'o', L'd', L' ', L'N', L'o', L't', L' ', L'A', L'l', L'l', L'o', L'w', L'e', L'd'};
static wchar_t* HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE = HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE_ARRAY;
static int* HTTP_405_METHOD_NOT_ALLOWED_STATUS_CODE_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The 406 not acceptable status code. */
static wchar_t HTTP_406_NOT_ACCEPTABLE_STATUS_CODE_ARRAY[] = {L'4', L'0', L'6', L' ', L'N', L'o', L't', L' ', L'A', L'c', L'c', L'e', L'p', L't', L'a', L'b', L'l', L'e'};
static wchar_t* HTTP_406_NOT_ACCEPTABLE_STATUS_CODE = HTTP_406_NOT_ACCEPTABLE_STATUS_CODE_ARRAY;
static int* HTTP_406_NOT_ACCEPTABLE_STATUS_CODE_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The 407 proxy authentication required status code. */
static wchar_t HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE_ARRAY[] = {L'4', L'0', L'7', L' ', L'P', L'r', L'o', L'x', L'y', L' ', L'A', L'u', L't', L'h', L'e', L'n', L't', L'i', L'c', L'a', L't', L'i', L'o', L'n', L' ', L'R', L'e', L'q', L'u', L'i', L'r', L'e', L'd'};
static wchar_t* HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE = HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE_ARRAY;
static int* HTTP_407_PROXY_AUTHENTICATION_STATUS_CODE_COUNT = NUMBER_33_INTEGER_ARRAY;

/** The 408 request timeout status code. */
static wchar_t HTTP_408_REQUEST_TIMEOUT_STATUS_CODE_ARRAY[] = {L'4', L'0', L'8', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L' ', L'T', L'i', L'm', L'e', L'o', L'u', L't'};
static wchar_t* HTTP_408_REQUEST_TIMEOUT_STATUS_CODE = HTTP_408_REQUEST_TIMEOUT_STATUS_CODE_ARRAY;
static int* HTTP_408_REQUEST_TIMEOUT_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 409 conflict status code. */
static wchar_t HTTP_409_CONFLICT_STATUS_CODE_ARRAY[] = {L'4', L'0', L'9', L' ', L'C', L'o', L'n', L'f', L'l', L'i', L'c', L't'};
static wchar_t* HTTP_409_CONFLICT_STATUS_CODE = HTTP_409_CONFLICT_STATUS_CODE_ARRAY;
static int* HTTP_409_CONFLICT_STATUS_CODE_COUNT = NUMBER_12_INTEGER_ARRAY;

/** The 410 gone status code. */
static wchar_t HTTP_410_GONE_STATUS_CODE_ARRAY[] = {L'4', L'1', L'0', L' ', L'G', L'o', L'n', L'e'};
static wchar_t* HTTP_410_GONE_STATUS_CODE = HTTP_410_GONE_STATUS_CODE_ARRAY;
static int* HTTP_410_GONE_STATUS_CODE_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The 411 length required status code. */
static wchar_t HTTP_411_LENGTH_REQUIRED_STATUS_CODE_ARRAY[] = {L'4', L'1', L'1', L' ', L'L', L'e', L'n', L'g', L't', L'h', L' ', L'R', L'e', L'q', L'u', L'i', L'r', L'e', L'd'};
static wchar_t* HTTP_411_LENGTH_REQUIRED_STATUS_CODE = HTTP_411_LENGTH_REQUIRED_STATUS_CODE_ARRAY;
static int* HTTP_411_LENGTH_REQUIRED_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 412 precondition failed status code. */
static wchar_t HTTP_412_PRECONDITION_FAILED_STATUS_CODE_ARRAY[] = {L'4', L'1', L'2', L' ', L'P', L'r', L'e', L'c', L'o', L'n', L'd', L'i', L't', L'i', L'o', L'n', L' ', L'F', L'a', L'i', L'l', L'e', L'd'};
static wchar_t* HTTP_412_PRECONDITION_FAILED_STATUS_CODE = HTTP_412_PRECONDITION_FAILED_STATUS_CODE_ARRAY;
static int* HTTP_412_PRECONDITION_FAILED_STATUS_CODE_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The 413 request entity too large status code. */
static wchar_t HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE_ARRAY[] = {L'4', L'1', L'3', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L' ', L'E', L'n', L't', L'i', L't', L'y', L' ', L'T', L'o', L'o', L' ', L'L', L'a', L'r', L'g', L'e'};
static wchar_t* HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE = HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE_ARRAY;
static int* HTTP_413_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The 414 request-uri too long status code. */
static wchar_t HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE_ARRAY[] = {L'4', L'1', L'4', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L'-', L'U', L'R', L'I', L' ', L'T', L'o', L'o', L' ', L'L', L'o', L'n', L'g'};
static wchar_t* HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE = HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE_ARRAY;
static int* HTTP_414_REQUEST_URI_TOO_LARGE_STATUS_CODE_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The 415 unsupported media type status code. */
static wchar_t HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE_ARRAY[] = {L'4', L'1', L'5', L' ', L'U', L'n', L's', L'u', L'p', L'p', L'o', L'r', L't', L'e', L'd', L' ', L'M', L'e', L'd', L'i', L'a', L' ', L'T', L'y', L'p', L'e'};
static wchar_t* HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE = HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE_ARRAY;
static int* HTTP_415_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE_COUNT = NUMBER_26_INTEGER_ARRAY;

/** The 416 requested range not satisfiable status code. */
static wchar_t HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE_ARRAY[] = {L'4', L'1', L'6', L' ', L'R', L'e', L'q', L'u', L'e', L's', L't', L'e', L'd', L' ', L'R', L'a', L'n', L'g', L'e', L' ', L'N', L'o', L't', L' ', L'S', L'a', L't', L'i', L's', L'f', L'i', L'a', L'b', L'l', L'e'};
static wchar_t* HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE = HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE_ARRAY;
static int* HTTP_416_REQUESTED_RANGE_NOT_SATISFIABLE_STATUS_CODE_COUNT = NUMBER_35_INTEGER_ARRAY;

/** The 417 expectation failed status code. */
static wchar_t HTTP_417_EXPECTATION_FAILED_STATUS_CODE_ARRAY[] = {L'4', L'1', L'7', L' ', L'E', L'x', L'p', L'e', L'c', L't', L'a', L't', L'i', L'o', L'n', L' ', L'F', L'a', L'i', L'l', L'e', L'd'};
static wchar_t* HTTP_417_EXPECTATION_FAILED_STATUS_CODE = HTTP_417_EXPECTATION_FAILED_STATUS_CODE_ARRAY;
static int* HTTP_417_EXPECTATION_FAILED_STATUS_CODE_COUNT = NUMBER_22_INTEGER_ARRAY;

/**
 * The 422 unprocessable entity status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE_ARRAY[] = {L'4', L'2', L'2', L' ', L'U', L'n', L'p', L'r', L'o', L'c', L'e', L's', L's', L'a', L'b', L'l', L'e', L' ', L'E', L'n', L't', L'i', L't', L'y'};
static wchar_t* HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE = HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE_ARRAY;
static int* HTTP_422_UNPROCESSABLE_ENTITY_STATUS_CODE_COUNT = NUMBER_24_INTEGER_ARRAY;
*/

/**
 * The 423 locked status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_423_LOCKED_STATUS_CODE_ARRAY[] = {L'4', L'2', L'3', L' ', L'L', L'o', L'c', L'k', L'e', L'd'};
static wchar_t* HTTP_423_LOCKED_STATUS_CODE = HTTP_423_LOCKED_STATUS_CODE_ARRAY;
static int* HTTP_423_LOCKED_STATUS_CODE_COUNT = NUMBER_10_INTEGER_ARRAY;
*/

/**
 * The 424 failed dependency (site too ugly) status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_424_FAILED_DEPENDENCY_STATUS_CODE_ARRAY[] = {L'4', L'2', L'4', L' ', L'F', L'a', L'i', L'l', L'e', L'd', L' ', L'D', L'e', L'p', L'e', L'n', L'd', L'e', L'n', L'c', L'y'};
static wchar_t* HTTP_424_FAILED_DEPENDENCY_STATUS_CODE = HTTP_424_FAILED_DEPENDENCY_STATUS_CODE_ARRAY;
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
static wchar_t HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE_ARRAY[] = {L'5', L'0', L'0', L' ', L'I', L'n', L't', L'e', L'r', L'n', L'a', L'l', L' ', L'S', L'e', L'r', L'v', L'e', L'r', L' ', L'E', L'r', L'r', L'o', L'r'};
static wchar_t* HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE = HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE_ARRAY;
static int* HTTP_500_INTERNAL_SERVER_ERROR_STATUS_CODE_COUNT = NUMBER_25_INTEGER_ARRAY;

/** The 501 not implemented status code. */
static wchar_t HTTP_501_NOT_IMPLEMENTED_STATUS_CODE_ARRAY[] = {L'5', L'0', L'1', L' ', L'N', L'o', L't', L' ', L'I', L'm', L'p', L'l', L'e', L'm', L'e', L'n', L't', L'e', L'd'};
static wchar_t* HTTP_501_NOT_IMPLEMENTED_STATUS_CODE = HTTP_501_NOT_IMPLEMENTED_STATUS_CODE_ARRAY;
static int* HTTP_501_NOT_IMPLEMENTED_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 502 bad gateway status code. */
static wchar_t HTTP_502_BAD_GATEWAY_STATUS_CODE_ARRAY[] = {L'5', L'0', L'2', L' ', L'B', L'a', L'd', L' ', L'G', L'a', L't', L'e', L'w', L'a', L'y'};
static wchar_t* HTTP_502_BAD_GATEWAY_STATUS_CODE = HTTP_502_BAD_GATEWAY_STATUS_CODE_ARRAY;
static int* HTTP_502_BAD_GATEWAY_STATUS_CODE_COUNT = NUMBER_15_INTEGER_ARRAY;

/** The 503 service unavailable status code. */
static wchar_t HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE_ARRAY[] = {L'5', L'0', L'3', L' ', L'S', L'e', L'r', L'v', L'i', L'c', L'e', L' ', L'U', L'n', L'a', L'v', L'a', L'i', L'l', L'a', L'b', L'l', L'e'};
static wchar_t* HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE = HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE_ARRAY;
static int* HTTP_503_SERVICE_UNAVAILABLE_STATUS_CODE_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The 504 gateway timeout status code. */
static wchar_t HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE_ARRAY[] = {L'5', L'0', L'4', L' ', L'G', L'a', L't', L'e', L'w', L'a', L'y', L' ', L'T', L'i', L'm', L'e', L'o', L'u', L't'};
static wchar_t* HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE = HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE_ARRAY;
static int* HTTP_504_GATEWAY_TIMEOUT_STATUS_CODE_COUNT = NUMBER_19_INTEGER_ARRAY;

/** The 505 http version not supported status code. */
static wchar_t HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE_ARRAY[] = {L'5', L'0', L'5', L' ', L'H', L'T', L'T', L'P', L' ', L'V', L'e', L'r', L's', L'i', L'o', L'n', L' ', L'N', L'o', L't', L' ', L'S', L'u', L'p', L'p', L'o', L'r', L't', L'e', L'd'};
static wchar_t* HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE = HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE_ARRAY;
static int* HTTP_505_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE_COUNT = NUMBER_30_INTEGER_ARRAY;

/**
 * The 507 insufficient storage status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE_ARRAY[] = {L'5', L'0', L'7', L' ', L'I', L'n', L's', L'u', L'f', L'f', L'i', L'c', L'i', L'e', L'n', L't', L' ', L'S', L't', L'o', L'r', L'a', L'g', L'e'};
static wchar_t* HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE = HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE_ARRAY;
static int* HTTP_507_INSUFFICIENT_STORAGE_STATUS_CODE_COUNT = NUMBER_24_INTEGER_ARRAY;
*/

/**
 * The 509 bandwidth limit exceeded status code.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static wchar_t HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE_ARRAY[] = {L'5', L'0', L'9', L' ', L'B', L'a', L'n', L'd', L'w', L'i', L'd', L't', L'h', L' ', L'L', L'i', L'm', L'i', L't', L' ', L'E', L'x', L'c', L'e', L'e', L'd', L'e', L'd'};
static wchar_t* HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE = HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE_ARRAY;
static int* HTTP_509_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE_COUNT = NUMBER_28_INTEGER_ARRAY;
*/

/* HTTP_STATUS_CODE_CONSTANTS_SOURCE */
#endif
