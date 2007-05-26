/*
 * $RCSfile: send_latex.c,v $
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
 * @version $Revision: 1.6 $ $Date: 2007-05-26 21:19:57 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_LATEX_SOURCE
#define SEND_LATEX_SOURCE

#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/variables.c"

/**
 * Sends a knowledge model in latex format.
 *
 * @param p0 the internal memory
 * @param p1 the source compound model
 * @param p2 the source count
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 */
void send_latex(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Send latex message.");
}

/* SEND_LATEX_SOURCE */
#endif
