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
 * @version $RCSfile: package_xdt_name.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PACKAGE_XDT_NAME_SOURCE
#define PACKAGE_XDT_NAME_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The standard package xdt name. */
static wchar_t STANDARD_PACKAGE_XDT_NAME_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd'};
static wchar_t* STANDARD_PACKAGE_XDT_NAME = STANDARD_PACKAGE_XDT_NAME_ARRAY;
static int* STANDARD_PACKAGE_XDT_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/* PACKAGE_XDT_NAME_SOURCE */
#endif
