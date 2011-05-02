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
 * @version $RCSfile: terminal_foreground_converter.c,v $ $Revision: 1.10 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_FOREGROUND_DECODER_SOURCE
#define TERMINAL_FOREGROUND_DECODER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/cybol/colour/terminal_colour_cybol_model.c"
#include "../../../constant/model/gnu_linux_console/escape_control_sequence_gnu_linux_console_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/comparator/count_array_comparator.c"

/**
 * Decodes the control sequence code into a terminal foreground colour name.
 *
 * @param p0 the destination colour name (Hand over as reference!)
 * @param p1 the destination colour name count
 * @param p2 the destination colour name size
 * @param p3 the source control sequence code
 * @param p4 the source control sequence code count
 */
void decode_terminal_foreground(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* TERMINAL_FOREGROUND_DECODER_SOURCE */
#endif
