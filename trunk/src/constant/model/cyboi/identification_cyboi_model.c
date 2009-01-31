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
 * @version $RCSfile: identification_cyboi_model.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef IDENTIFICATION_CYBOI_MODEL_SOURCE
#define IDENTIFICATION_CYBOI_MODEL_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

/** The name identification cyboi model. */
static wchar_t NAME_IDENTIFICATION_CYBOI_MODEL_ARRAY[] = {L'C', L'y', L'b', L'e', L'r', L'n', L'e', L't', L'i', L'c', L's', L' ', L'O', L'r', L'i', L'e', L'n', L't', L'e', L'd', L' ', L'I', L'n', L't', L'e', L'r', L'p', L'r', L'e', L't', L'e', L'r', L' ', L'(', L'C', L'Y', L'B', L'O', L'I', L')'};
static wchar_t* NAME_IDENTIFICATION_CYBOI_MODEL = NAME_IDENTIFICATION_CYBOI_MODEL_ARRAY;
static int* NAME_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_40_INTEGER_MEMORY_MODEL_ARRAY;

/** The version identification cyboi model. */
static wchar_t VERSION_IDENTIFICATION_CYBOI_MODEL_ARRAY[] = {L'0', L'.', L'9', L'.', L'0'};
static wchar_t* VERSION_IDENTIFICATION_CYBOI_MODEL = VERSION_IDENTIFICATION_CYBOI_MODEL_ARRAY;
static int* VERSION_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The copyright identification cyboi model. */
static wchar_t COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_ARRAY[] = {L'C', L'o', L'p', L'y', L'r', L'i', L'g', L'h', L't', L' ', L'(', L'C', L')', L' ', L'1', L'9', L'9', L'9', L'-', L'2', L'0', L'0', L'9', L'.', L' ', L'C', L'h', L'r', L'i', L's', L't', L'i', L'a', L'n', L' ', L'H', L'e', L'l', L'l', L'e', L'r', L'.'};
static wchar_t* COPYRIGHT_IDENTIFICATION_CYBOI_MODEL = COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_ARRAY;
static int* COPYRIGHT_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

/** The licence identification cyboi model. */
static wchar_t LICENCE_IDENTIFICATION_CYBOI_MODEL_ARRAY[] = {L'C', L'Y', L'B', L'O', L'I', L' ', L'c', L'o', L'm', L'e', L's', L' ', L'w', L'i', L't', L'h', L' ', L'N', L'O', L' ', L'W', L'A', L'R', L'R', L'A', L'N', L'T', L'Y', L',', L'\n',
    't', L'o', L' ', L't', L'h', L'e', L' ', L'e', L'x', L't', L'e', L'n', L't', L' ', L'p', L'e', L'r', L'm', L'i', L't', L't', L'e', L'd', L' ', L'b', L'y', L' ', L'l', L'a', L'w', L'.', L'\n',
    'Y', L'o', L'u', L' ', L'm', L'a', L'y', L' ', L'r', L'e', L'd', L'i', L's', L't', L'r', L'i', L'b', L'u', L't', L'e', L' ', L'c', L'o', L'p', L'i', L'e', L's', L' ', L'o', L'f', L' ', L'C', L'Y', L'B', L'O', L'I', L'\n',
    'u', L'n', L'd', L'e', L'r', L' ', L't', L'h', L'e', L' ', L't', L'e', L'r', L'm', L's', L' ', L'o', L'f', L' ', L't', L'h', L'e', L' ', L'G', L'N', L'U', L' ', L'G', L'e', L'n', L'e', L'r', L'a', L'l', L' ', L'P', L'u', L'b', L'l', L'i', L'c', L' ', L'L', L'i', L'c', L'e', L'n', L's', L'e', L'.', L'\n',
    'F', L'o', L'r', L' ', L'm', L'o', L'r', L'e', L' ', L'i', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'b', L'o', L'u', L't', L' ', L't', L'h', L'e', L's', L'e', L' ', L'm', L'a', L't', L't', L'e', L'r', L's', L',', L'\n',
    's', L'e', L'e', L' ', L't', L'h', L'e', L' ', L'f', L'i', L'l', L'e', L's', L' ', L'n', L'a', L'm', L'e', L'd', L' ', L'C', L'O', L'P', L'Y', L'I', L'N', L'G', L'.'};
static wchar_t* LICENCE_IDENTIFICATION_CYBOI_MODEL = LICENCE_IDENTIFICATION_CYBOI_MODEL_ARRAY;
static int* LICENCE_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_220_INTEGER_MEMORY_MODEL_ARRAY;

/** The help identification cyboi model. */
static wchar_t HELP_IDENTIFICATION_CYBOI_MODEL_ARRAY[] = {
    'P', L'a', L'r', L'a', L'm', L'e', L't', L'e', L'r', L's', L' ', L'h', L'a', L'v', L'e', L' ', L't', L'o', L' ', L'b', L'e', L' ', L'g', L'i', L'v', L'e', L'n', L'!', L'\n',
    'U', L's', L'a', L'g', L'e', L':', L' ', L'c', L'y', L'b', L'o', L'i', L' ', L'[', L'-', L'-', L'v', L'e', L'r', L's', L'i', L'o', L'n', L']', L' ', L'[', L'-', L'-', L'h', L'e', L'l', L'p', L']', L' ', L'[', L'-', L'-', L't', L'e', L's', L't', L']', L' ', L'[', L'-', L'-', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L' ', L'A', L'R', L'G', L']', L' ', L'[', L'-', L'-', L'l', L'o', L'g', L'l', L'e', L'v', L'e', L'l', L' ', L'A', L'R', L'G', L']', L' ', L'[', L'-', L'-', L'l', L'o', L'g', L'f', L'i', L'l', L'e', L' ', L'A', L'R', L'G', L']', L'\n',
    ' ', L' ', L' ', L' ', L'-', L'-', L'v', L'e', L'r', L's', L'i', L'o', L'n', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'D', L'i', L's', L'p', L'l', L'a', L'y', L's', L' ', L't', L'h', L'e', L' ', L'c', L'u', L'r', L'r', L'e', L'n', L't', L' ', L'v', L'e', L'r', L's', L'i', L'o', L'n', L'.', L'\n',
    ' ', L' ', L' ', L' ', L'-', L'-', L'h', L'e', L'l', L'p', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'D', L'i', L's', L'p', L'l', L'a', L'y', L's', L' ', L't', L'h', L'i', L's', L' ', L'h', L'e', L'l', L'p', L' ', L'm', L'e', L's', L's', L'a', L'g', L'e', L'.', L'\n',
    ' ', L' ', L' ', L' ', L'-', L'-', L't', L'e', L's', L't', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L' ', L'S', L't', L'a', L'r', L't', L's', L' ', L'c', L'y', L'b', L'o', L'i', L' ', L'i', L'n', L' ', L't', L'e', L's', L't', L' ', L'm', L'o', L'd', L'e', L'.', L'\n',
    ' ', L' ', L' ', L' ', L'-', L'-', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L' ', L'A', L'R', L'G', L' ', L'S', L't', L'a', L'r', L't', L's', L' ', L'c', L'y', L'b', L'o', L'i', L' ', L'i', L'n', L' ', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L' ', L'm', L'o', L'd', L'e', L'.', L' ', L'T', L'a', L'k', L'e', L's', L' ', L'A', L'R', L'G', L' ', L'a', L's', L' ', L'c', L'y', L'b', L'o', L'l', L' ', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L' ', L'f', L'i', L'l', L'e', L'.', L' ', L'T', L'h', L'i', L's', L' ', L'i', L's', L' ', L't', L'h', L'e', L' ', L's', L't', L'a', L'n', L'd', L'a', L'r', L'd', L' ', L'w', L'a', L'y', L' ', L't', L'o', L' ', L'u', L's', L'e', L' ', L'c', L'y', L'b', L'o', L'i', L'.', L'\n',
    ' ', L' ', L' ', L' ', L'-', L'-', L'l', L'o', L'g', L'l', L'e', L'v', L'e', L'l', L' ', L'A', L'R', L'G', L' ', L' ', L'S', L'e', L't', L's', L' ', L't', L'h', L'e', L' ', L'l', L'o', L'g', L' ', L'l', L'e', L'v', L'e', L'l', L'.', L' ', L'T', L'h', L'e', L' ', L'A', L'R', L'G', L' ', L'm', L'a', L'y', L' ', L'b', L'e', L' ', L'o', L'n', L'e', L' ', L'o', L'f', L':', L' ', L'o', L'f', L'f', L',', L' ', L'e', L'r', L'r', L'o', L'r', L',', L' ', L'w', L'a', L'r', L'n', L'i', L'n', L'g', L',', L' ', L'i', L'n', L'f', L'o', L'r', L'm', L'a', L't', L'i', L'o', L'n', L',', L' ', L'd', L'e', L'b', L'u', L'g', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L'f', L'a', L'u', L'l', L't', L' ', L'i', L's', L' ', L'o', L'f', L'f', L'.', L'\n',
    ' ', L' ', L' ', L' ', L'-', L'-', L'l', L'o', L'g', L'f', L'i', L'l', L'e', L' ', L'A', L'R', L'G', L' ', L' ', L' ', L'L', L'o', L'g', L's', L' ', L'm', L'e', L's', L's', L'a', L'g', L'e', L's', L' ', L't', L'o', L' ', L't', L'h', L'e', L' ', L'f', L'i', L'l', L'e', L' ', L's', L'p', L'e', L'c', L'i', L'f', L'i', L'e', L'd', L' ', L'b', L'y', L' ', L'A', L'R', L'G', L'.', L'\n',
    'E', L'x', L'a', L'm', L'p', L'l', L'e', L':', L' ', L'c', L'y', L'b', L'o', L'i', L' ', L'-', L'-', L'k', L'n', L'o', L'w', L'l', L'e', L'd', L'g', L'e', L' ', L'r', L'e', L's', L'm', L'e', L'd', L'i', L'c', L'i', L'n', L'a', L'e', L'/', L'r', L'u', L'n', L'.', L'c', L'y', L'b', L'o', L'l', L'\n',
    'R', L'e', L'p', L'o', L'r', L't', L' ', L'b', L'u', L'g', L's', L' ', L't', L'o', L' ',
    '<', L'c', L'y', L'b', L'o', L'p', L'-', L'd', L'e', L'v', L'e', L'l', L'o', L'p', L'e', L'r', L's', L'@', L'l', L'i', L's', L't', L's', L'.', L'b', L'e', L'r', L'l', L'i', L'o', L's', L'.', L'd', L'e', L'>', L' ',
    'o', L'r', L' ', L'<', L'c', L'h', L'r', L'i', L's', L't', L'i', L'a', L'n', L'.', L'h', L'e', L'l', L'l', L'e', L'r', L'@', L't', L'u', L'x', L't', L'a', L'x', L'.', L'd', L'e', L'>', L'.'};
static wchar_t* HELP_IDENTIFICATION_CYBOI_MODEL = HELP_IDENTIFICATION_CYBOI_MODEL_ARRAY;
static int* HELP_IDENTIFICATION_CYBOI_MODEL_COUNT = NUMBER_715_INTEGER_MEMORY_MODEL_ARRAY;

/* IDENTIFICATION_CYBOI_MODEL_SOURCE */
#endif
