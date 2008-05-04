/*
 * $RCSfile: latex_converter.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2008-05-04 00:18:14 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LATEX_CONVERTER_SOURCE
#define LATEX_CONVERTER_SOURCE

#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/logger/logger.c"

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

/**
 * Encodes the latex model and creates a byte stream from it.
 *
 * @param p0 the destination byte stream (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source latex model
 * @param p4 the source count
 */
void encode_latex(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* LATEX_CONVERTER_SOURCE */
#endif
