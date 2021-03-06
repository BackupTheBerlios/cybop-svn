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
 * @version $RCSfile: opengl_starting_maintainer.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPENGL_STARTER_SOURCE
#define OPENGL_STARTER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"

/**
 * Starts up the opengl system.
 *
 * @param p0 the internal memory array
 */
void startup_opengl(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup opengl.");

#ifdef GNU_LINUX_OPERATING_SYSTEM

    // Startup x window system AT FIRST.
    // The opengl environment needs its windows to have something to paint on.
    startup_x_window_system(p0);

/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/* OPENGL_STARTER_SOURCE */
#endif
