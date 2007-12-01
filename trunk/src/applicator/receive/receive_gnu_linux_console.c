/*
 * $RCSfile: receive_gnu_linux_console.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_GNU_LINUX_CONSOLE_SOURCE
#define RECEIVE_GNU_LINUX_CONSOLE_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include "../../globals/constants/log/log_level_constants.c"
#include "../../globals/logger/logger.c"
/*??
#include "../../globals/constants/cyboi/cyboi_signal_priority_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/character/wide_character_constants.c"
#include "../../globals/constants/console/console_control_sequence_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../memoriser/accessor/compound_accessor.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"
*/

/**
 * Receives textual user interface (tui) message via gnu/linux console.
 *
 * @param p0 the internal memory
 * @param p1 the temporary user interface commands internal
 * @param p2 the temporary user interface commands count internal
 * @param p3 the temporary user interface commands size internal
 */
void receive_gnu_linux_console(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Receive gnu/linux console message.");
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* RECEIVE_GNU_LINUX_CONSOLE_SOURCE */
#endif
