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
 * @version $RCSfile: text_user_interface_cybol_name.c,v $ $Revision: 1.3 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEXT_USER_INTERFACE_CYBOL_NAME_SOURCE
#define TEXT_USER_INTERFACE_CYBOL_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The shape user interface cybol name. */
static wchar_t SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L's', L'h', L'a', L'p', L'e'};
static wchar_t* SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME = SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* SHAPE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The layout user interface cybol name. */
static wchar_t LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'l', L'a', L'y', L'o', L'u', L't'};
static wchar_t* LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME = LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* LAYOUT_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The cell user interface cybol name. */
static wchar_t CELL_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'c', L'e', L'l', L'l'};
static wchar_t* CELL_TEXT_USER_INTERFACE_CYBOL_NAME = CELL_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* CELL_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The position user interface cybol name. */
static wchar_t POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'p', L'o', L's', L'i', L't', L'i', L'o', L'n'};
static wchar_t* POSITION_TEXT_USER_INTERFACE_CYBOL_NAME = POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The size user interface cybol name. */
static wchar_t SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L's', L'i', L'z', L'e'};
static wchar_t* SIZE_TEXT_USER_INTERFACE_CYBOL_NAME = SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The background colour user interface cybol name. */
static wchar_t BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'b', L'a', L'c', L'k', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME = BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The foreground colour user interface cybol name. */
static wchar_t FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'f', L'o', L'r', L'e', L'g', L'r', L'o', L'u', L'n', L'd'};
static wchar_t* FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME = FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The title user interface cybol name. */
static wchar_t TITLE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L't', L'i', L't', L'l', L'e'};
static wchar_t* TITLE_TEXT_USER_INTERFACE_CYBOL_NAME = TITLE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* TITLE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The icon user interface cybol name. */
static wchar_t ICON_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'i', L'c', L'o', L'n'};
static wchar_t* ICON_TEXT_USER_INTERFACE_CYBOL_NAME = ICON_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* ICON_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The expose command user interface cybol name. */
static wchar_t EXPOSE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'e', L'x', L'p', L'o', L's', L'e'};
static wchar_t* EXPOSE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME = EXPOSE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* EXPOSE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The left mouse button press command user interface cybol name. */
static wchar_t LEFT_PRESS_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'_', L'p', L'r', L'e', L's', L's'};
static wchar_t* LEFT_PRESS_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME = LEFT_PRESS_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* LEFT_PRESS_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The left mouse button release command user interface cybol name. */
static wchar_t LEFT_RELEASE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'_', L'r', L'e', L'l', L'e', L'a', L's', L'e'};
static wchar_t* LEFT_RELEASE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME = LEFT_RELEASE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* LEFT_RELEASE_COMMAND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The border text user interface cybol name. */
static wchar_t BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'b', L'o', L'r', L'd', L'e', L'r'};
static wchar_t* BORDER_TEXT_USER_INTERFACE_CYBOL_NAME = BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The hidden text user interface cybol name. */
static wchar_t HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'h', L'i', L'd', L'd', L'e', L'n'};
static wchar_t* HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME = HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The inverse text user interface cybol name. */
static wchar_t INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'i', L'n', L'v', L'e', L'r', L's', L'e'};
static wchar_t* INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME = INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The blink text user interface cybol name. */
static wchar_t BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'b', L'l', L'i', L'n', L'k'};
static wchar_t* BLINK_TEXT_USER_INTERFACE_CYBOL_NAME = BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The underline text user interface cybol name. */
static wchar_t UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'u', L'n', L'd', L'e', L'r', L'l', L'i', L'n', L'e'};
static wchar_t* UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME = UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The bold text user interface cybol name. */
static wchar_t BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY[] = {L'b', L'o', L'l', L'd'};
static wchar_t* BOLD_TEXT_USER_INTERFACE_CYBOL_NAME = BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_ARRAY;
static int* BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/* TEXT_USER_INTERFACE_CYBOL_NAME_SOURCE */
#endif
