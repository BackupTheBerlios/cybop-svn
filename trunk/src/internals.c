/*
 * $RCSfile: internals.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 */

#ifndef INTERNALS_SOURCE
#define INTERNALS_SOURCE

/**
 * This is the internals.
 *
 * These are internal data and flags for legacy stuff and
 * handling of various platforms and graphical user interfaces
 * such as X-Windows, Macintosh or MS Windows.
 *
 * @version $Revision: 1.2 $ $Date: 2004-02-08 12:39:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct internals {

    /** The x windows flag. */
    int x_windows_flag;

    /** The x windows. */
    void* x_windows;

    /** The macintosh flag. */
    int macintosh_flag;

    /** The macintosh. */
    void* macintosh;

    /** The ms windows flag. */
    int ms_windows_flag;

    /** The ms windows. */
    void* ms_windows;
};

/* INTERNALS_SOURCE */
#endif
