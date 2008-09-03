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
 * @version $RCSfile: transfer_operation_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TRANSFER_OPERATION_CYBOL_MODEL_SOURCE
#define TRANSFER_OPERATION_CYBOL_MODEL_SOURCE

#include "../../../../constant/model/memory/integer_model.c"

/** The copy (set, assign) transfer operation cybol model. */
static wchar_t COPY_TRANSFER_OPERATION_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_TRANSFER_OPERATION_CYBOL_MODEL = COPY_TRANSFER_OPERATION_CYBOL_MODEL_ARRAY;
static int* COPY_TRANSFER_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The move transfer operation cybol model. */
static wchar_t MOVE_TRANSFER_OPERATION_CYBOL_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_TRANSFER_OPERATION_CYBOL_MODEL = MOVE_TRANSFER_OPERATION_CYBOL_MODEL_ARRAY;
static int* MOVE_TRANSFER_OPERATION_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/* TRANSFER_OPERATION_CYBOL_MODEL_SOURCE */
#endif
