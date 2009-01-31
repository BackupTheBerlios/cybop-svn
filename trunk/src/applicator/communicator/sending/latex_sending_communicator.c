/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: latex_sending_communicator.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LATEX_SENDING_COMMUNICATOR_SOURCE
#define LATEX_SENDING_COMMUNICATOR_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

/**
 * Sends a knowledge model in latex format.
 *
 * @param p0 the internal memory
 * @param p1 the source compound model
 * @param p2 the source count
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 */
void communicate_sending_latex(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send latex message.");
}

/* LATEX_SENDING_COMMUNICATOR_SOURCE */
#endif
