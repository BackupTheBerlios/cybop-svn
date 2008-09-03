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
 * @version $RCSfile: communication_style_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATION_STYLE_CYBOL_MODEL_SOURCE
#define COMMUNICATION_STYLE_CYBOL_MODEL_SOURCE

#include "../../../constant/model/memory/integer_model.c"

/** The stream communication style cybol model. */
static wchar_t STREAM_COMMUNICATION_STYLE_CYBOL_MODEL_ARRAY[] = {L's', L't', L'r', L'e', L'a', L'm'};
static wchar_t* STREAM_COMMUNICATION_STYLE_CYBOL_MODEL = STREAM_COMMUNICATION_STYLE_CYBOL_MODEL_ARRAY;
static int* STREAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The datagram communication style cybol model. */
static wchar_t DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL_ARRAY[] = {L'd', L'a', L't', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL = DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL_ARRAY;
static int* DATAGRAM_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_ARRAY;

/** The raw communication style cybol model. */
static wchar_t RAW_COMMUNICATION_STYLE_CYBOL_MODEL_ARRAY[] = {L'r', L'a', L'w'};
static wchar_t* RAW_COMMUNICATION_STYLE_CYBOL_MODEL = RAW_COMMUNICATION_STYLE_CYBOL_MODEL_ARRAY;
static int* RAW_COMMUNICATION_STYLE_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/* COMMUNICATION_STYLE_CYBOL_MODEL_SOURCE */
#endif
