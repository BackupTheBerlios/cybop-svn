/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: latex_converter.c,v $ $Revision: 1.10 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LATEX_DECODER_SOURCE
#define LATEX_DECODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

/**
 * Decodes the byte stream and creates a latex model from it.
 *
 * @param p0 the destination latex model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source byte stream
 * @param p4 the source count
 */
void decode_latex(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* LATEX_DECODER_SOURCE */
#endif
