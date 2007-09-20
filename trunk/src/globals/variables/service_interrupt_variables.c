/*
 * $RCSfile: service_interrupt_variables.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-09-20 08:00:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_INTERRUPT_VARIABLES_SOURCE
#define SERVICE_INTERRUPT_VARIABLES_SOURCE

#include "../../globals/constants/pointer/pointer_constants.c"

// The gnu linux console interrupt flag.
static int* GNU_LINUX_CONSOLE_THREAD_INTERRUPT = NUMBER_0_INTEGER_ARRAY;
// The x window system interrupt flag.
static int* X_WINDOW_SYSTEM_THREAD_INTERRUPT = NUMBER_0_INTEGER_ARRAY;
// The www service interrupt flag.
static int* WWW_SERVICE_THREAD_INTERRUPT = NUMBER_0_INTEGER_ARRAY;
// The cyboi service interrupt flag.
static int* CYBOI_SERVICE_THREAD_INTERRUPT = NUMBER_0_INTEGER_ARRAY;

/* SERVICE_INTERRUPT_VARIABLES_SOURCE */
#endif
