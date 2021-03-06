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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_WIDE_CHARACTER_ASSIGNER_SOURCE
#define LOG_WIDE_CHARACTER_ASSIGNER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"

/**
 * Assigns the wide character.
 *
 * @param p0 the destination value
 * @param p1 the source value
 */
void log_assign_wide_character(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        wchar_t* se = (wchar_t*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* de = (wchar_t*) p0;

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.

            // Assign source- to destination value.
            *de = *se;

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            // "Could not assign wide character. The destination value is null."
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not assign wide character. The source value is null."
    }
}

/* LOG_WIDE_CHARACTER_ASSIGNER_SOURCE */
#endif
