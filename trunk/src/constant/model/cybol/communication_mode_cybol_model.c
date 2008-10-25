/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: communication_mode_cybol_model.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATION_MODE_CYBOL_MODEL_SOURCE
#define COMMUNICATION_MODE_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The client communication mode cybol model. */
static wchar_t CLIENT_COMMUNICATION_MODE_CYBOL_MODEL_ARRAY[] = {L'c', L'l', L'i', L'e', L'n', L't'};
static wchar_t* CLIENT_COMMUNICATION_MODE_CYBOL_MODEL = CLIENT_COMMUNICATION_MODE_CYBOL_MODEL_ARRAY;
static int* CLIENT_COMMUNICATION_MODE_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The server communication mode cybol model. */
static wchar_t SERVER_COMMUNICATION_MODE_CYBOL_MODEL_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* SERVER_COMMUNICATION_MODE_CYBOL_MODEL = SERVER_COMMUNICATION_MODE_CYBOL_MODEL_ARRAY;
static int* SERVER_COMMUNICATION_MODE_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* COMMUNICATION_MODE_CYBOL_MODEL_SOURCE */
#endif
