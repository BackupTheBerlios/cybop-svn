/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: cybol_channel.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_CHANNEL_SOURCE
#define CYBOI_CHANNEL_SOURCE

#include <stddef.h>

#include "../../constant/model/memory/integer_memory_model.c"

/** The file system cyboi channel. */
static int* FILE_SYSTEM_CYBOI_CHANNEL = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The gnu linux console cyboi channel. */
static int* GNU_LINUX_CONSOLE_CYBOI_CHANNEL = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The inline cyboi channel. */
static int* INLINE_CYBOI_CHANNEL = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The shell cyboi channel. */
static int* SHELL_CYBOI_CHANNEL = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The socket cyboi channel. */
static int* SOCKET_CYBOI_CHANNEL = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The world wide web (www) cyboi channel. */
static int* WWW_CYBOI_CHANNEL = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The x window system cyboi channel. */
static int* X_WINDOW_SYSTEM_CYBOI_CHANNEL = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOI_CHANNEL_SOURCE */
#endif
