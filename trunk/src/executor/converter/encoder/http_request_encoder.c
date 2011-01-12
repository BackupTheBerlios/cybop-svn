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
 * @version $RCSfile: http_request_converter.c,v $ $Revision: 1.24 $ $Date: 2009-02-22 19:09:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_REQUEST_ENCODER_SOURCE
#define HTTP_REQUEST_ENCODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

//
// Since http is a stateless protocol, it does not provide a possibility to
// find out whether or not several consequent http requests belong together.
//
// Therefore, the application on the next higher level of abstraction has to
// care about that, by opening a "session" for each request from an unknown user.
// Every such session gets a unique identifier called "session id".
//
// Whenever the client now sends an http request to the server,
// it also sends the session id, so that data already stored on the
// server can be assigned to the correct user.
//
// There are several ways to transfer a session id:
// 1 as cookie
// 2 within the uri
// 2.1 GET
// 2.1.1 in the query, e.g.:
// http://domain.tld/index.php?sid=3Dedb0e8665db4e9042fe0176a89aade16
// 2.1.2 in the path
// http://domain.tld/edb0e8665db4e9042fe0176a89aade16/index.php
// 2.2 POST (within html forms, using input elements of type ?hidden")
//
// Problems:
// 1 Many users have cookies deactivated in their browsers.
//   However, an application may request to activate cookies.
// 2 Each uri of a (generated) webpage has to be modified to contain the session id.
// 2.2 All navigation has to occur via html forms (buttons etc.); simple links do not suffice
//
// In order to avoid users manipulating and using the session id of another user,
// a session id has to be generated from a range of values that is large enough
// to minimise the probability of guessing another user's session id.
//

/**
 * Encodes the compound into an http request.
 *
 * @param p0 the destination wide character array (Hand over as reference!)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source compound
 * @param p4 the source compound count
 * @param p5 the source compound
 * @param p6 the source compound count
 */
void encode_http_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode http request.");
}

/* HTTP_REQUEST_ENCODER_SOURCE */
#endif
