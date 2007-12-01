/*
 * $RCSfile: receive_x_window_system.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.32 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 */

#ifndef RECEIVE_X_WINDOW_SYSTEM_SOURCE
#define RECEIVE_X_WINDOW_SYSTEM_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include "../globals/constants/log/log_level_constants.c"
#include "../globals/logger/logger.c"
/*??
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
*/

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
void receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Receive x window system message.");
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_X_WINDOW_SYSTEM_SOURCE */
#endif
