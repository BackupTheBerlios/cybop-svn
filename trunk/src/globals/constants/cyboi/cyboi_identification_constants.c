/*
 * $RCSfile: cyboi_identification_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.2 $ $Date: 2008-05-04 00:18:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_IDENTIFICATION_CONSTANTS_SOURCE
#define CYBOI_IDENTIFICATION_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The cyboi name. */
static char CYBOI_NAME_ARRAY[] = {'C', 'y', 'b', 'e', 'r', 'n', 'e', 't', 'i', 'c', 's', ' ', 'O', 'r', 'i', 'e', 'n', 't', 'e', 'd', ' ', 'I', 'n', 't', 'e', 'r', 'p', 'r', 'e', 't', 'e', 'r', ' ', '(', 'C', 'Y', 'B', 'O', 'I', ')'};
static char* CYBOI_NAME = CYBOI_NAME_ARRAY;
static int* CYBOI_NAME_COUNT = NUMBER_40_INTEGER_ARRAY;

/** The cyboi version. */
static char CYBOI_VERSION_ARRAY[] = {'0', '.', '9', '.', '0'};
static char* CYBOI_VERSION = CYBOI_VERSION_ARRAY;
static int* CYBOI_VERSION_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The cyboi copyright. */
static char CYBOI_COPYRIGHT_ARRAY[] = {'C', 'o', 'p', 'y', 'r', 'i', 'g', 'h', 't', ' ', '(', 'C', ')', ' ', '1', '9', '9', '9', '-', '2', '0', '0', '7', '.', ' ', 'C', 'h', 'r', 'i', 's', 't', 'i', 'a', 'n', ' ', 'H', 'e', 'l', 'l', 'e', 'r', ' ', 'a', 'n', 'd', ' ', 't', 'h', 'e', ' ', 'C', 'Y', 'B', 'O', 'P', ' ', 'd', 'e', 'v', 'e', 'l', 'o', 'p', 'e', 'r', 's', '.'};
static char* CYBOI_COPYRIGHT = CYBOI_COPYRIGHT_ARRAY;
static int* CYBOI_COPYRIGHT_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The cyboi licence. */
static char CYBOI_LICENCE_ARRAY[] = {'C', 'Y', 'B', 'O', 'I', ' ', 'c', 'o', 'm', 'e', 's', ' ', 'w', 'i', 't', 'h', ' ', 'N', 'O', ' ', 'W', 'A', 'R', 'R', 'A', 'N', 'T', 'Y', ',', '\n',
    't', 'o', ' ', 't', 'h', 'e', ' ', 'e', 'x', 't', 'e', 'n', 't', ' ', 'p', 'e', 'r', 'm', 'i', 't', 't', 'e', 'd', ' ', 'b', 'y', ' ', 'l', 'a', 'w', '.', '\n',
    'Y', 'o', 'u', ' ', 'm', 'a', 'y', ' ', 'r', 'e', 'd', 'i', 's', 't', 'r', 'i', 'b', 'u', 't', 'e', ' ', 'c', 'o', 'p', 'i', 'e', 's', ' ', 'o', 'f', ' ', 'C', 'Y', 'B', 'O', 'I', '\n',
    'u', 'n', 'd', 'e', 'r', ' ', 't', 'h', 'e', ' ', 't', 'e', 'r', 'm', 's', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'G', 'N', 'U', ' ', 'G', 'e', 'n', 'e', 'r', 'a', 'l', ' ', 'P', 'u', 'b', 'l', 'i', 'c', ' ', 'L', 'i', 'c', 'e', 'n', 's', 'e', '.', '\n',
    'F', 'o', 'r', ' ', 'm', 'o', 'r', 'e', ' ', 'i', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'b', 'o', 'u', 't', ' ', 't', 'h', 'e', 's', 'e', ' ', 'm', 'a', 't', 't', 'e', 'r', 's', ',', '\n',
    's', 'e', 'e', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'l', 'e', 's', ' ', 'n', 'a', 'm', 'e', 'd', ' ', 'C', 'O', 'P', 'Y', 'I', 'N', 'G', '.'};
static char* CYBOI_LICENCE = CYBOI_LICENCE_ARRAY;
static int* CYBOI_LICENCE_COUNT = NUMBER_220_INTEGER_ARRAY;

/** The cyboi help. */
static char CYBOI_HELP_ARRAY[] = {
    'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', ' ', 'h', 'a', 'v', 'e', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'g', 'i', 'v', 'e', 'n', '!', '\n',
    'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', '[', '-', '-', 'v', 'e', 'r', 's', 'i', 'o', 'n', ']', ' ', '[', '-', '-', 'h', 'e', 'l', 'p', ']', ' ', '[', '-', '-', 't', 'e', 's', 't', ']', ' ', '[', '-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'A', 'R', 'G', ']', ' ', '[', '-', '-', 'l', 'o', 'g', 'l', 'e', 'v', 'e', 'l', ' ', 'A', 'R', 'G', ']', ' ', '[', '-', '-', 'l', 'o', 'g', 'f', 'i', 'l', 'e', ' ', 'A', 'R', 'G', ']', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'v', 'e', 'r', 's', 'i', 'o', 'n', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', 'i', 's', 'p', 'l', 'a', 'y', 's', ' ', 't', 'h', 'e', ' ', 'c', 'u', 'r', 'r', 'e', 'n', 't', ' ', 'v', 'e', 'r', 's', 'i', 'o', 'n', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'h', 'e', 'l', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', 'i', 's', 'p', 'l', 'a', 'y', 's', ' ', 't', 'h', 'i', 's', ' ', 'h', 'e', 'l', 'p', ' ', 'm', 'e', 's', 's', 'a', 'g', 'e', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 't', 'e', 's', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'S', 't', 'a', 'r', 't', 's', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'i', 'n', ' ', 't', 'e', 's', 't', ' ', 'm', 'o', 'd', 'e', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'A', 'R', 'G', ' ', 'S', 't', 'a', 'r', 't', 's', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'i', 'n', ' ', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'm', 'o', 'd', 'e', '.', ' ', 'T', 'a', 'k', 'e', 's', ' ', 'A', 'R', 'G', ' ', 'a', 's', ' ', 'c', 'y', 'b', 'o', 'l', ' ', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'f', 'i', 'l', 'e', '.', ' ', 'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', ' ', 'w', 'a', 'y', ' ', 't', 'o', ' ', 'u', 's', 'e', ' ', 'c', 'y', 'b', 'o', 'i', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'l', 'o', 'g', 'l', 'e', 'v', 'e', 'l', ' ', 'A', 'R', 'G', ' ', ' ', 'S', 'e', 't', 's', ' ', 't', 'h', 'e', ' ', 'l', 'o', 'g', ' ', 'l', 'e', 'v', 'e', 'l', '.', ' ', 'T', 'h', 'e', ' ', 'A', 'R', 'G', ' ', 'm', 'a', 'y', ' ', 'b', 'e', ' ', 'o', 'n', 'e', ' ', 'o', 'f', ':', ' ', 'o', 'f', 'f', ',', ' ', 'e', 'r', 'r', 'o', 'r', ',', ' ', 'w', 'a', 'r', 'n', 'i', 'n', 'g', ',', ' ', 'i', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', ',', ' ', 'd', 'e', 'b', 'u', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 'f', 'a', 'u', 'l', 't', ' ', 'i', 's', ' ', 'o', 'f', 'f', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'l', 'o', 'g', 'f', 'i', 'l', 'e', ' ', 'A', 'R', 'G', ' ', ' ', ' ', 'L', 'o', 'g', 's', ' ', 'm', 'e', 's', 's', 'a', 'g', 'e', 's', ' ', 't', 'o', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'l', 'e', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'b', 'y', ' ', 'A', 'R', 'G', '.', '\n',
    'E', 'x', 'a', 'm', 'p', 'l', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', '-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'r', 'e', 's', 'm', 'e', 'd', 'i', 'c', 'i', 'n', 'a', 'e', '/', 'r', 'u', 'n', '.', 'c', 'y', 'b', 'o', 'l', '\n',
    'R', 'e', 'p', 'o', 'r', 't', ' ', 'b', 'u', 'g', 's', ' ', 't', 'o', ' ',
    '<', 'c', 'y', 'b', 'o', 'p', '-', 'd', 'e', 'v', 'e', 'l', 'o', 'p', 'e', 'r', 's', '@', 'l', 'i', 's', 't', 's', '.', 'b', 'e', 'r', 'l', 'i', 'o', 's', '.', 'd', 'e', '>', ' ',
    'o', 'r', ' ', '<', 'c', 'h', 'r', 'i', 's', 't', 'i', 'a', 'n', '.', 'h', 'e', 'l', 'l', 'e', 'r', '@', 't', 'u', 'x', 't', 'a', 'x', '.', 'd', 'e', '>', '.'};
static char* CYBOI_HELP = CYBOI_HELP_ARRAY;
static int* CYBOI_HELP_COUNT = NUMBER_715_INTEGER_ARRAY;

/* CYBOI_IDENTIFICATION_CONSTANTS_SOURCE */
#endif
