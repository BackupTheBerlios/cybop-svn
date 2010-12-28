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

#ifndef AUTHORITY_DECODER_SOURCE
#define AUTHORITY_DECODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/converter/decoder/authority/userinfo_authority_decoder.c"
#include "../../../logger/logger.c"

//
// Example:
//
// username:password@example.com:8042
// \_______________/ \_________/ \__/
//         |              |       |
//     userinfo       hostname   port
//
// The hostname may be given in IPv4, IPv6 or FQDN format.
//
// In cyboi, the uri parts are translated into the following compound hierarchy:
//
// root (destination compound that was handed over)
// +-username
// +-password
// +-hostname
// +-port
//

/**
 * Decodes the authority into compound model and -details.
 *
 * CAUTION! The source character array HAS TO BE given
 * as sequence of wide characters.
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
void decode_authority(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode authority.");

    decode_authority_userinfo(p0, p1, p2, p3, p4, p5, (void*) &p6, p7);
}

/* AUTHORITY_DECODER_SOURCE */
#endif
