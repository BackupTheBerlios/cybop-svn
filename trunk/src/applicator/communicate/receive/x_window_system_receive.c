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
 * @version $RCSfile: x_window_system_receiving_communicator.c,v $ $Revision: 1.7 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_RECEIVE_SOURCE
#define X_WINDOW_SYSTEM_RECEIVE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include "../../../constant/model/log/level_log_model.c"
#include "../../../logger/logger.c"

/**
 * Receives an x window system message.
 *
 * @param p0 the internal memory
 * @param p1 the temporary user interface root internal
 * @param p2 the temporary user interface root count internal
 * @param p3 the temporary user interface root size internal
 * @param p4 the temporary user interface commands internal
 * @param p5 the temporary user interface commands count internal
 * @param p6 the temporary user interface commands size internal
 */
void apply_receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply receive x window system.");

    //?? receive_x_window_system();
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* X_WINDOW_SYSTEM_RECEIVE_SOURCE */
#endif
