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
 * @version $RCSfile: level_log_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LEVEL_LOG_MODEL_SOURCE
#define LEVEL_LOG_MODEL_SOURCE

#include "../../../constant/model/memory/integer_model.c"

/** The off level log model. */
static int* OFF_LEVEL_LOG_MODEL = NUMBER_0_INTEGER_ARRAY;

/** The error level log model. */
static int* ERROR_LEVEL_LOG_MODEL = NUMBER_1_INTEGER_ARRAY;

/** The warning level log model. */
static int* WARNING_LEVEL_LOG_MODEL = NUMBER_2_INTEGER_ARRAY;

/** The info level log model. */
static int* INFORMATION_LEVEL_LOG_MODEL = NUMBER_3_INTEGER_ARRAY;

/** The debug level log model. */
static int* DEBUG_LEVEL_LOG_MODEL = NUMBER_4_INTEGER_ARRAY;

/* LEVEL_LOG_MODEL_SOURCE */
#endif
