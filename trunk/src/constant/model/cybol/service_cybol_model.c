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
 * @version $RCSfile: service_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_CYBOL_MODEL_SOURCE
#define SERVICE_CYBOL_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The signal service cybol model. */
static wchar_t SIGNAL_SERVICE_CYBOL_MODEL_ARRAY[] = {L's', L'i', L'g', L'n', L'a', L'l'};
static wchar_t* SIGNAL_SERVICE_CYBOL_MODEL = SIGNAL_SERVICE_CYBOL_MODEL_ARRAY;
static int* SIGNAL_SERVICE_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The shell service cybol model. */
static wchar_t SHELL_SERVICE_CYBOL_MODEL_ARRAY[] = {L's', L'h', L'e', L'l', L'l'};
static wchar_t* SHELL_SERVICE_CYBOL_MODEL = SHELL_SERVICE_CYBOL_MODEL_ARRAY;
static int* SHELL_SERVICE_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The standard output service cybol model. */
static wchar_t STANDARD_OUTPUT_SERVICE_CYBOL_MODEL_ARRAY[] = {L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L'_', L'o', L'u', L't', L'p', L'u', L't'};
static wchar_t* STANDARD_OUTPUT_SERVICE_CYBOL_MODEL = STANDARD_OUTPUT_SERVICE_CYBOL_MODEL_ARRAY;
static int* STANDARD_OUTPUT_SERVICE_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The gnu linux console service cybol model. */
static wchar_t GNU_LINUX_CONSOLE_SERVICE_CYBOL_MODEL_ARRAY[] = {L'g', L'n', L'u', L'_', L'l', L'i', L'n', L'u', L'x', L'_', L'c', L'o', L'n', L's', L'o', L'l', L'e'};
static wchar_t* GNU_LINUX_CONSOLE_SERVICE_CYBOL_MODEL = GNU_LINUX_CONSOLE_SERVICE_CYBOL_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_SERVICE_CYBOL_MODEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The x window system service cybol model. */
static wchar_t X_WINDOW_SYSTEM_SERVICE_CYBOL_MODEL_ARRAY[] = {L'x', L'_', L'w', L'i', L'n', L'd', L'o', L'w', L'_', L's', L'y', L's', L't', L'e', L'm'};
static wchar_t* X_WINDOW_SYSTEM_SERVICE_CYBOL_MODEL = X_WINDOW_SYSTEM_SERVICE_CYBOL_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_SERVICE_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The world wide web (www) service cybol model. */
static wchar_t WWW_SERVICE_CYBOL_MODEL_ARRAY[] = {L'w', L'w', L'w'};
static wchar_t* WWW_SERVICE_CYBOL_MODEL = WWW_SERVICE_CYBOL_MODEL_ARRAY;
static int* WWW_SERVICE_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The cybernetics oriented interpreter (cyboi) service cybol model. */
static wchar_t CYBOI_SERVICE_CYBOL_MODEL_ARRAY[] = {L'c', L'y', L'b', L'o', L'i'};
static wchar_t* CYBOI_SERVICE_CYBOL_MODEL = CYBOI_SERVICE_CYBOL_MODEL_ARRAY;
static int* CYBOI_SERVICE_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* SERVICE_CYBOL_MODEL_SOURCE */
#endif
