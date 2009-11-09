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
 * @version $RCSfile: http_communicator.c,v $ $Revision: 1.11 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_COMMUNICATOR_SOURCE
#define HTTP_COMMUNICATOR_SOURCE

#include <stdio.h>
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Reads an http stream and writes it into a byte array.
 *
 * @param p0 the destination (byte array) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (http url)
 * @param p4 the source count
 */
void read_http(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Writes an http stream that was read from a byte array.
 *
 * @param p0 the destination (http url) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (byte array)
 * @param p4 the source count
 */
void write_http(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* HTTP_COMMUNICATOR_SOURCE */
#endif