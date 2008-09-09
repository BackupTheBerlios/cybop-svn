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
 * @version $RCSfile: opengl_shutting_maintainer.c,v $ $Revision: 1.3 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPENGL_SHUTTER_SOURCE
#define OPENGL_SHUTTER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../memoriser/accessor.c"
#include "../../../memoriser/allocator.c"

/**
 * Shuts down the opengl system.
 *
 * This is done in the reverse order that the opengl system was started up.
 *
 * @param p0 the internals memory
 * @param p1 the knowledge
 * @param p2 the knowledge count
 * @param p3 the knowledge size
 */
void shutdown_opengl(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Shutdown opengl.");

#ifdef GNU_LINUX_OPERATING_SYSTEM

    // Shutdown x window system AT LAST.
    // The opengl environment needed its windows to have something to paint on.
    shutdown_x_window_system(p0, p1, p2, p3);

/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/* OPENGL_SHUTTER_SOURCE */
#endif
