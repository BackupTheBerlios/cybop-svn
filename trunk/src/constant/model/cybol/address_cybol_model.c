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
 * @version $RCSfile: address_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ADDRESS_CYBOL_MODEL_SOURCE
#define ADDRESS_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The loopback address cybol model. */
static wchar_t LOOPBACK_ADDRESS_CYBOL_MODEL_ARRAY[] = {L'l', L'o', L'o', L'p', L'b', L'a', L'c', L'k'};
static wchar_t* LOOPBACK_ADDRESS_CYBOL_MODEL = LOOPBACK_ADDRESS_CYBOL_MODEL_ARRAY;
static int* LOOPBACK_ADDRESS_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The any address cybol model. */
static wchar_t ANY_ADDRESS_CYBOL_MODEL_ARRAY[] = {L'a', L'n', L'y'};
static wchar_t* ANY_ADDRESS_CYBOL_MODEL = ANY_ADDRESS_CYBOL_MODEL_ARRAY;
static int* ANY_ADDRESS_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* ADDRESS_CYBOL_MODEL_SOURCE */
#endif
