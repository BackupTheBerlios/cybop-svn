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
 * @version $RCSfile: http_response_processor.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_RESPONSE_PROCESSOR_SOURCE
#define HTTP_RESPONSE_PROCESSOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"

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

/* HTTP_RESPONSE_PROCESSOR_SOURCE */
#endif
