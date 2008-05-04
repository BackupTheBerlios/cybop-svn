/*
 * $RCSfile: receive_latex.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.11 $ $Date: 2008-05-04 00:18:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_LATEX_SOURCE
#define RECEIVE_LATEX_SOURCE

#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"

/**
 * Receives a knowledge model in latex format.
 *
 * @param p0 the internal memory
 * @param p1 the source latex format
 * @param p2 the source count
 */
void receive_latex(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Receive latex.");
}

/* RECEIVE_LATEX_SOURCE */
#endif
