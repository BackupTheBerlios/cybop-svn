/*
 * $RCSfile: shutdown_opengl.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2007-08-13 16:37:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTDOWN_OPENGL_SOURCE
#define SHUTDOWN_OPENGL_SOURCE

#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/variables/variables.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"

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

    log_message_debug("Shutdown opengl.");

#ifdef GNU_LINUX_OPERATING_SYSTEM

    // Shutdown x window system AT LAST.
    // The opengl environment needed its windows to have something to paint on.
    shutdown_x_window_system(p0, p1, p2, p3);

/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/* SHUTDOWN_OPENGL_SOURCE */
#endif
