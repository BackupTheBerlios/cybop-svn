/*
 * $RCSfile: http_response_converter.c,v $
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

#ifndef HTTP_RESPONSE_CONVERTER_SOURCE
#define HTTP_RESPONSE_CONVERTER_SOURCE

#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Parses an http response into a compound.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source http response
 * @param p4 the source http response count
 */
void parse_http_response(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Information: Parse http response.");
}

/**
 * Serialises a compound into an http response.
 *
 * @param p0 the destination http response (Hand over as reference!)
 * @param p1 the destination http response count
 * @param p2 the destination http response size
 * @param p3 the source compound abstraction
 * @param p4 the source compound abstraction count
 * @param p5 the source compound model
 * @param p6 the source compound model count
 * @param p7 the source compound details
 * @param p8 the source compound details count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 */
void serialise_http_response(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_debug("Information: Serialise http response.");
}

/* HTTP_RESPONSE_CONVERTER_SOURCE */
#endif
