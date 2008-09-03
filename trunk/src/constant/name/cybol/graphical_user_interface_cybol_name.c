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
 * @version $RCSfile: graphical_user_interface_cybol_name.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GRAPHICAL_USER_INTERFACE_CYBOL_NAME_SOURCE
#define GRAPHICAL_USER_INTERFACE_CYBOL_NAME_SOURCE

#include "../../../constant/model/memory/integer_model.c"

/** The shape graphical user interface cybol name. */
static wchar_t SHAPE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L's', L'h', L'a', L'p', L'e'};
static wchar_t* SHAPE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = SHAPE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* SHAPE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The layout graphical user interface cybol name. */
static wchar_t LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'l', L'a', L'y', L'o', L'u', L't'};
static wchar_t* LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The cell graphical user interface cybol name. */
static wchar_t CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'c', L'e', L'l', L'l'};
static wchar_t* CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The position graphical user interface cybol name. */
static wchar_t POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'p', L'o', L's', L'i', L't', L'i', L'o', L'n'};
static wchar_t* POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The size graphical user interface cybol name. */
static wchar_t SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L's', L'i', L'z', L'e'};
static wchar_t* SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The background colour graphical user interface cybol name. */
static wchar_t BACKGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'b', L'a', L'c', L'k', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* BACKGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = BACKGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* BACKGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The foreground colour graphical user interface cybol name. */
static wchar_t FOREGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'f', L'o', L'r', L'e', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* FOREGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = FOREGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* FOREGROUND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The title graphical user interface cybol name. */
static wchar_t TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L't', L'i', L't', L'l', L'e'};
static wchar_t* TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The icon graphical user interface cybol name. */
static wchar_t ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'i', L'c', L'o', L'n'};
static wchar_t* ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The expose command graphical user interface cybol name. */
static wchar_t EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'e', L'x', L'p', L'o', L's', L'e'};
static wchar_t* EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* EXPOSE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The left mouse button press command graphical user interface cybol name. */
static wchar_t LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'_', L'p', L'r', L'e', L's', L's'};
static wchar_t* LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* LEFT_PRESS_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_ARRAY;

/** The left mouse button release command graphical user interface cybol name. */
static wchar_t LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'_', L'r', L'e', L'l', L'e', L'a', L's', L'e'};
static wchar_t* LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME = LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* LEFT_RELEASE_COMMAND_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_ARRAY;

/* GRAPHICAL_USER_INTERFACE_CYBOL_NAME_SOURCE */
#endif
