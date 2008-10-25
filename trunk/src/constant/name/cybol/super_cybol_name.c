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
 * @version $RCSfile: super_cybol_name.c,v $ $Revision: 1.3 $ $Date: 2008-10-25 23:20:04 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SUPER_CYBOL_NAME_SOURCE
#define SUPER_CYBOL_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The super cybol name. */
static wchar_t SUPER_CYBOL_NAME_ARRAY[] = {L's', L'u', L'p', L'e', L'r'};
static wchar_t* SUPER_CYBOL_NAME = SUPER_CYBOL_NAME_ARRAY;
static int* SUPER_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* SUPER_CYBOL_NAME_SOURCE */
#endif
