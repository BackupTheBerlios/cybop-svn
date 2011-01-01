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
 * @version $RCSfile: http_response_converter.c,v $ $Revision: 1.21 $ $Date: 2009-02-22 19:09:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_RESPONSE_DECODER_SOURCE
#define HTTP_RESPONSE_DECODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

//
// Many Web servers supply incorrect Content-Type headers with their
// HTTP responses.  In order to be compatible with these Web servers,
// Web browsers must consider the content of HTTP responses as well as
// the Content-Type header when determining the effective mime type of
// the response. The following document describes an algorithm for
// determining the effective mime type of HTTP responses that balances
// security and compatibility considerations:
//
// http://tools.ietf.org/html/draft-abarth-mime-sniff-00
//
// CAUTION! This is a draft document that, by the rules of IETF,
// has to be referenced as "work in progress", which is hereby done.
//

/**
 * Decodes the http response into a compound model and -details.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source wide character array
 * @param p7 the source wide character array count
 */
void decode_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode http response.");

//??    decode_http_response_xx(p0, p1, p2, p3, p4, p5, (void*) &p6, p7);
}

/* HTTP_RESPONSE_DECODER_SOURCE */
#endif
