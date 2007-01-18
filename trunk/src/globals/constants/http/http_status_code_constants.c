/*
 * $RCSfile: http_status_code_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-01-18 22:51:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_STATUS_CODE_CONSTANTS_SOURCE
#define HTTP_STATUS_CODE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer_constants.c"

//
// 1XX - information
//

/** The continue status code. */
static int* HTTP_CONTINUE_STATUS_CODE = NUMBER_100_INTEGER_ARRAY;

/** The switching protocols status code. */
static int* HTTP_SWITCHING_PROTOCOLS_STATUS_CODE = NUMBER_101_INTEGER_ARRAY;

/** The processing status code. */
static int* HTTP_PROCESSING_STATUS_CODE = NUMBER_102_INTEGER_ARRAY;

//
// 2XX - successfull operation
//

/** The ok status code. */
static int* HTTP_OK_STATUS_CODE = NUMBER_200_INTEGER_ARRAY;

/** The created status code. */
static int* HTTP_CREATED_STATUS_CODE = NUMBER_201_INTEGER_ARRAY;

/** The accepted status code. */
static int* HTTP_ACCEPTED_STATUS_CODE = NUMBER_202_INTEGER_ARRAY;

/** The non-authoritative information status code. */
static int* HTTP_NON_AUTHORITATIVE_STATUS_CODE = NUMBER_203_INTEGER_ARRAY;

/** The no content status code. */
static int* HTTP_NO_CONTENT_STATUS_CODE = NUMBER_204_INTEGER_ARRAY;

/** The reset content status code. */
static int* HTTP_RESET_CONTENT_STATUS_CODE = NUMBER_205_INTEGER_ARRAY;

/** The partial content status code. */
static int* HTTP_PARTIAL_CONTENT_STATUS_CODE = NUMBER_206_INTEGER_ARRAY;

/** The multi-status status code. */
static int* HTTP_MULTI_STATUS_STATUS_CODE = NUMBER_207_INTEGER_ARRAY;

//
// 3XX - redirection
//

/** The multiple choice status code. */
static int* HTTP_MULTIPLE_CHOICE_STATUS_CODE = NUMBER_300_INTEGER_ARRAY;

/** The moved permanently status code. */
static int* HTTP_MOVED_PERMANENTLY_STATUS_CODE = NUMBER_301_INTEGER_ARRAY;

/** The found status code. */
static int* HTTP_FOUND_STATUS_CODE = NUMBER_302_INTEGER_ARRAY;

/** The see other status code. */
static int* HTTP_SEE_OTHER_STATUS_CODE = NUMBER_303_INTEGER_ARRAY;

/** The not modified status code. */
static int* HTTP_NOT_MODIFIED_STATUS_CODE = NUMBER_304_INTEGER_ARRAY;

/** The use proxy status code. */
static int* HTTP_USE_PROXY_STATUS_CODE = NUMBER_305_INTEGER_ARRAY;

/** The switch proxy status code. */
// This status code is reserved but NOT used anymore in HTTP/1.1!
// static int* HTTP_SWITCH_PROXY_STATUS_CODE = NUMBER_306_INTEGER_ARRAY;

/** The temporary redirect status code. */
static int* HTTP_TEMPORARY_REDIRECT_STATUS_CODE = NUMBER_307_INTEGER_ARRAY;

//
// 4XX - client errors
//

/** The bad request status code. */
static int* HTTP_BAD_REQUEST_STATUS_CODE = NUMBER_400_INTEGER_ARRAY;

/** The unauthorized status code. */
static int* HTTP_UNAUTHORIZED_STATUS_CODE = NUMBER_401_INTEGER_ARRAY;

/** The payment required status code. */
static int* HTTP_PAYMENT_REQUIRED_STATUS_CODE = NUMBER_402_INTEGER_ARRAY;

/** The forbidden status code. */
static int* HTTP_FORBIDDEN_STATUS_CODE = NUMBER_403_INTEGER_ARRAY;

/** The not found status code. */
static int* HTTP_NOT_FOUND_STATUS_CODE = NUMBER_404_INTEGER_ARRAY;

/** The method not allowed status code. */
static int* HTTP_METHOD_NOT_ALLOWED_STATUS_CODE = NUMBER_405_INTEGER_ARRAY;

/** The not acceptable status code. */
static int* HTTP_NOT_ACCEPTABLE_STATUS_CODE = NUMBER_406_INTEGER_ARRAY;

/** The proxy authentication required status code. */
static int* HTTP_PROXY_AUTHENTICATION_STATUS_CODE = NUMBER_407_INTEGER_ARRAY;

/** The request time-out status code. */
static int* HTTP_REQUEST_TIME_OUT_STATUS_CODE = NUMBER_408_INTEGER_ARRAY;

/** The conflict status code. */
static int* HTTP_CONFLICT_STATUS_CODE = NUMBER_409_INTEGER_ARRAY;

/** The gone status code. */
static int* HTTP_GONE_STATUS_CODE = NUMBER_410_INTEGER_ARRAY;

/** The length required status code. */
static int* HTTP_LENGTH_REQUIRED_STATUS_CODE = NUMBER_411_INTEGER_ARRAY;

/** The precondition failed status code. */
static int* HTTP_PRECONDITION_FAILED_STATUS_CODE = NUMBER_412_INTEGER_ARRAY;

/** The request entity too large status code. */
static int* HTTP_REQUEST_ENTITY_TOO_LARGE_STATUS_CODE = NUMBER_413_INTEGER_ARRAY;

/** The request-uri too long status code. */
static int* HTTP_REQUEST_URI_TOO_LARGE_STATUS_CODE = NUMBER_414_INTEGER_ARRAY;

/** The unsupported media type status code. */
static int* HTTP_UNSUPPORTED_MEDIA_TYPE_STATUS_CODE = NUMBER_415_INTEGER_ARRAY;

/** The request range not satisfiable status code. */
static int* HTTP_REQUEST_RANGE_NOT_SATISFIABLE_STATUS_CODE = NUMBER_416_INTEGER_ARRAY;

/** The expectation failed status code. */
static int* HTTP_EXPECTATION_FAILED_STATUS_CODE = NUMBER_417_INTEGER_ARRAY;

/** The unprocessable entity status code. */
static int* HTTP_UNPROCESSABLE_ENTITY_STATUS_CODE = NUMBER_422_INTEGER_ARRAY;

/** The locked status code. */
static int* HTTP_LOCKED_STATUS_CODE = NUMBER_423_INTEGER_ARRAY;

/** The failed dependency status code. */
static int* HTTP_FAILED_DEPENDENCY_STATUS_CODE = NUMBER_424_INTEGER_ARRAY;

//
// 5XX - server errors
//

/** The internal server error status code. */
static int* HTTP_INTERNAL_SERVER_ERROR_STATUS_CODE = NUMBER_500_INTEGER_ARRAY;

/** The not implemented status code. */
static int* HTTP_NOT_IMPLEMENTED_STATUS_CODE = NUMBER_501_INTEGER_ARRAY;

/** The bad gateway status code. */
static int* HTTP_BAD_GATEWAY_STATUS_CODE = NUMBER_502_INTEGER_ARRAY;

/** The service unavailable status code. */
static int* HTTP_SERVICE_UNAVAILABLE_STATUS_CODE = NUMBER_503_INTEGER_ARRAY;

/** The gateway time-out status code. */
static int* HTTP_GATEWAY_TIME_OUT_STATUS_CODE = NUMBER_504_INTEGER_ARRAY;

/** The http version not supported status code. */
static int* HTTP_HTTP_VERSION_NOT_SUPPORTED_STATUS_CODE = NUMBER_505_INTEGER_ARRAY;

/** The insufficient storage status code. */
static int* HTTP_INSUFFICIENT_STORAGE_STATUS_CODE = NUMBER_507_INTEGER_ARRAY;

/** The bandwidth limit exceeded status code. */
static int* HTTP_BANDWIDTH_LIMIT_EXCEEDED_STATUS_CODE = NUMBER_509_INTEGER_ARRAY;

/* HTTP_STATUS_CODE_CONSTANTS_SOURCE */
#endif
