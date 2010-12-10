/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef URI_DECODER_SOURCE
#define URI_DECODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/converter/processor/uri/scheme_uri_processor.c"
#include "../../../logger/logger.c"

//
// The generic URI syntax consists of a hierarchical sequence of components:
//
// URI          = scheme ":" hier-part [ "?" query ] [ "#" fragment ]
//
// hier-part    = "//" authority path-abempty
//                / path-absolute
//                / path-rootless
//                / path-empty
//
// One can have a scheme ":" with path-absolute, path-rootless
// or path-empty and no "//" after the scheme ":".
//
// - path-empty is 0<pchar>, no slashes in sight, next stop "?"
// - path-absolute is "/" segment-nz etc.; segment-nz is 1*pchar;
//   there is precisely one slash after the scheme ":"
// - path-rootless starts with segment-nz, no "/" after the scheme ":"
//
// That leaves "//" authority path-abempty to get an interesting
// number of slashes after the scheme ":".
// Ignoring optional parts, <authority> is at least a <host>
// and <host> is IP-literal / IPv4addrss / reg-name.
// They shouldn't be empty, but <reg-name> can be empty.
//
// - path-abempty is zero or more "/" segment
// - segment is zero or more pchar
//
// So one can have three slashes like:
// file:///etc
// and in theory also more slashes if the segments are "empty".
// In practice, however, file: is the only URI scheme known to
// allow an empty reg-name (in that case instead of localhost).
//
// Example URIs and their component parts:
//
// foo://username:password@example.com:8042/over/there/index.dtb?type=animal&name=ferret#nose
// \__/\__________________/\_________/\___/\__________/\___/\__/\__________/\__________/\___/
//  |            |              |       |      |         |    |          |       |        |
//  |         userinfo      hostname  port    dir  filename extension   parametre(s)      |
//  |  \__________________________________/\___________________/\______________________/  |
//  |                    |                            |                     |             |
//  |                authority                       path                   |             |
//  |  \_______________________________________________________/            |             |
//  |                                     |                                 |             |
// scheme                             hierarchy                           query       fragment
//
// The scheme and path components are required, though the path may be
// empty (no characters). When authority is present, the path must
// either be empty or begin with a slash ("/") character. When authority
// is not present, the path cannot begin with two slash characters ("//").
//
// In cyboi, the uri parts are translated into the following compound hierarchy:
//
// (the root is the destination compound that was handed over)
// +-scheme
// +-authority
// | +-username
// | +-password
// | +-hostname
// | +-port
// +-path
// +-query
// | +-param1
// | +-param2
// | +-...
// +-fragment
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
// Although not defined by IETF's uri specification rfc3986, it has become
// usual to use the characters ";" and "&" as parameter separators in a uri.
// These are commonly found in both, the "path" and "query" component part.
// For cyboi, however, it is defined that parameters may only be given in the
// "query" component part, and that parameters are separated by ampersand "&".
//
// Examples:
//
// http://localhost:1971/?exit
// http://127.0.0.1:1971?name=close&channel=inline&abstraction=knowledge&model=.residenz.logic.exit_program
// http://de.wikipedia.org/w/index.php?title=Uniform_Resource_Locator&action=edit
//
// There are a number of reserved characters, to which belong:
// ! # $ % & ' ( )// + , / : ; = ? @ [ ]
// The following url contains the reserved # character:
// http://www.example.net/index.html?session=A54C6FE2#info
// which should be encoded as %23 like:
// http://www.example.net/index.html?session=A54C6FE2%23info
//
// See:
// http://tools.ietf.org/html/rfc1630
// http://tools.ietf.org/html/rfc3986
//

/**
 * Decodes the uri into a compound model and -details.
 *
 * CAUTION! The source character array MUST NOT be given
 * as percent-encoded octets. In other words, it has to
 * have been decoded before being handed over to this function.
 *
 * CAUTION! The source character array MUST NOT be given
 * as sequence of wide characters. Standard octets are expected.
 * The detected parts will get converted to wide characters inside,
 * yet before being added to the destination.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source character array
 * @param p7 the source character array count
 */
void decode_uri(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode uri.");

    process_uri_scheme(p0, p1, p2, p3, p4, p5, (void*) &p6, p7);
}

/* URI_DECODER_SOURCE */
#endif
