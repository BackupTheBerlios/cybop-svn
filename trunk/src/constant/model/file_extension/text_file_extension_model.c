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
 * @version $RCSfile: text_file_extension_model.c,v $ $Revision: 1.2 $ $Date: 2008-09-04 20:31:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEXT_FILE_EXTENSION_MODEL_SOURCE
#define TEXT_FILE_EXTENSION_MODEL_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The html text file extension model. */
static wchar_t HTML_TEXT_FILE_EXTENSION_MODEL_ARRAY[] = {L'h', L't', L'm', L'l'};
static wchar_t* HTML_TEXT_FILE_EXTENSION_MODEL = HTML_TEXT_FILE_EXTENSION_MODEL_ARRAY;
static int* HTML_TEXT_FILE_EXTENSION_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The htm text file extension model. */
static wchar_t HTM_TEXT_FILE_EXTENSION_MODEL_ARRAY[] = {L'h', L't', L'm'};
static wchar_t* HTM_TEXT_FILE_EXTENSION_MODEL = HTM_TEXT_FILE_EXTENSION_MODEL_ARRAY;
static int* HTM_TEXT_FILE_EXTENSION_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The shtml text file extension model. */
static wchar_t SHTML_TEXT_FILE_EXTENSION_MODEL_ARRAY[] = {L's', L'h', L't', L'm', L'l'};
static wchar_t* SHTML_TEXT_FILE_EXTENSION_MODEL = SHTML_TEXT_FILE_EXTENSION_MODEL_ARRAY;
static int* SHTML_TEXT_FILE_EXTENSION_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* TEXT_FILE_EXTENSION_MODEL_SOURCE */
#endif
