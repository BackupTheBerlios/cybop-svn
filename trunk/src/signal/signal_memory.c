/*
 * $RCSfile: signal_memory.c,v $
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

#ifndef SIGNAL_MEMORY_SOURCE
#define SIGNAL_MEMORY_SOURCE

/**
 * This is a signal memory.
 *
 * It is capable of storing signals.
 * For each signal, the following meta information is stored:
 * - priority
 * - language
 *
 * @version $Revision: 1.3 $ $Date: 2003-12-05 12:10:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct signal_memory {

    /** The signals. */
    void* signals;

    /** The abstractions. */
    void* abstractions;

    /** The priorities. */
    void* priorities;
};

/* SIGNAL_MEMORY_SOURCE */
#endif

