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
 * @version $RCSfile: interface_cybol_abstraction.c,v $ $Revision: 1.3 $ $Date: 2008-09-08 21:28:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERFACE_CYBOL_ABSTRACTION_SOURCE
#define INTERFACE_CYBOL_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// This MIME type was taken from/ inspired by the KDE desktop.
// It is used for text- and graphical user interfaces in CYBOI.
//

/**
 * The interface/gnu-linux-console cybol abstraction.
 */
static wchar_t GNU_LINUX_CONSOLE_INTERFACE_CYBOL_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'f', L'a', L'c', L'e', L'/', L'g', L'n', L'u', L'-', L'l', L'i', L'n', L'u', L'x', L'-', L'c', L'o', L'n', L's', L'o', L'l', L'e'};
static wchar_t* GNU_LINUX_CONSOLE_INTERFACE_CYBOL_ABSTRACTION = GNU_LINUX_CONSOLE_INTERFACE_CYBOL_ABSTRACTION_ARRAY;
static int* GNU_LINUX_CONSOLE_INTERFACE_CYBOL_ABSTRACTION_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The interface/x-winamp-skin cybol abstraction.
 */
static wchar_t X_WINAMP_INTERFACE_CYBOL_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'f', L'a', L'c', L'e', L'/', L'x', L'-', L'w', L'i', L'n', L'a', L'm', L'p', L'-', L's', L'k', L'i', L'n'};
static wchar_t* X_WINAMP_INTERFACE_CYBOL_ABSTRACTION = X_WINAMP_INTERFACE_CYBOL_ABSTRACTION_ARRAY;
static int* X_WINAMP_INTERFACE_CYBOL_ABSTRACTION_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The interface/x-window-system cybol abstraction.
 */
static wchar_t X_WINDOW_SYSTEM_INTERFACE_CYBOL_ABSTRACTION_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'f', L'a', L'c', L'e', L'/', L'x', L'-', L'w', L'i', L'n', L'd', L'o', L'w', L'-', L's', L'y', L's', L't', L'e', L'm'};
static wchar_t* X_WINDOW_SYSTEM_INTERFACE_CYBOL_ABSTRACTION = X_WINDOW_SYSTEM_INTERFACE_CYBOL_ABSTRACTION_ARRAY;
static int* X_WINDOW_SYSTEM_INTERFACE_CYBOL_ABSTRACTION_COUNT = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/* INTERFACE_CYBOL_ABSTRACTION_SOURCE */
#endif
