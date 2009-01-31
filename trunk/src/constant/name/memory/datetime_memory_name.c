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
 * @version $RCSfile: datetime_memory_name.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATETIME_MEMORY_NAME_SOURCE
#define DATETIME_MEMORY_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The year (y) datetime memory name. */
static int* YEAR_DATETIME_MEMORY_NAME = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The month (m) datetime memory name. */
static int* MONTH_DATETIME_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The day (d) datetime memory name. */
static int* DAY_DATETIME_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The hour (h) datetime memory name. */
static int* HOUR_DATETIME_MEMORY_NAME = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The minute (m) datetime memory name. */
static int* MINUTE_DATETIME_MEMORY_NAME = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The second (s) datetime memory name. */
static int* SECOND_DATETIME_MEMORY_NAME = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/* DATETIME_MEMORY_NAME_SOURCE */
#endif
