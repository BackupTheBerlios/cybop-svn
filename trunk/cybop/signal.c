/*
 * $RCSfile: signal.c,v $
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

/**
 * This is a signal.
 *
 * A signal transports an input state through a system to an output state.
 *
 * Signals can be stored in a memory.
 * 
 * @version $Revision: 1.6 $ $Date: 2003-09-27 00:22:23 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
struct signal {

    /** The priority. */
    void* priority;

    /** The language. */
    void* language;

    /** The subject. */
    void* subject;

    /** The predicate. */
    void* predicate;

    /** The owner. */
    void* owner;

    /** The sender. */
    void* sender;

    /** The object. */
    void* object;

    /** The adverbial. */
    void* adverbial;

    /** The condition. */
    void* condition;
};

