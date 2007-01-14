/*
 * $RCSfile: x_windows_allocator.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2007-01-14 22:06:49 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description
 *
 * A session (display) manager shows a graphical user login,
 * in which it offers a list of window managers to chose from.
 *
 * A window manager cares about all windows displayed on a screen.
 * This includes the resizing, moving, stacking or tiling of windows.
 *
 * CYBOI aims to become both at the same time,
 * a session- (display-) as well as a window manager.
 */

#ifndef X_WINDOW_SYSTEM_ALLOCATOR_SOURCE
#define X_WINDOW_SYSTEM_ALLOCATOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"

/**
 * Allocates an x window system window.
 *
 * @param p0 the internals memory
 */
void allocate_x_window_system_window(void* p0) {
}

/**
 * Deallocates the x window system window.
 *
 * @param p0 the internals memory
 */
void deallocate_x_window_system_window(void* p0) {
}

/* X_WINDOW_SYSTEM_ALLOCATOR_SOURCE */
#endif
