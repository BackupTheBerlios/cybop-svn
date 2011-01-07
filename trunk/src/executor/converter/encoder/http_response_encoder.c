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

#ifndef HTTP_RESPONSE_ENCODER_SOURCE
#define HTTP_RESPONSE_ENCODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

/**
 * Encodes the compound into an http response.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source message abstraction
 * @param p4 the source message abstraction count
 * @param p5 the source message model
 * @param p6 the source message model count
 * @param p7 the source message details
 * @param p8 the source message details count
 * @param p9 the source message abstraction
 * @param p10 the source message abstraction count
 * @param p11 the source message model
 * @param p12 the source message model count
 * @param p13 the source message details
 * @param p14 the source message details count
 */
void encode_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode http response.");
}

/* HTTP_RESPONSE_ENCODER_SOURCE */
#endif
