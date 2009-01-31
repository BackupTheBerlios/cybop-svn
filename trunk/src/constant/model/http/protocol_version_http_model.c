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
 * @version $RCSfile: protocol_version_http_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROTOCOL_VERSION_HTTP_MODEL_SOURCE
#define PROTOCOL_VERSION_HTTP_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The 1.0 protocol version http model. */
static wchar_t NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL_ARRAY[] = {L'H', L'T', L'T', L'P', L'/', L'1', L'.', L'0'};
static wchar_t* NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL = NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL_ARRAY;
static int* NUMBER_1_0_PROTOCOL_VERSION_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The 1.1 protocol version http model. */
static wchar_t NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_ARRAY[] = {L'H', L'T', L'T', L'P', L'/', L'1', L'.', L'1'};
static wchar_t* NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL = NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_ARRAY;
static int* NUMBER_1_1_PROTOCOL_VERSION_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* PROTOCOL_VERSION_HTTP_MODEL_SOURCE */
#endif
