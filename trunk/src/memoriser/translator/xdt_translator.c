/*
 * $RCSfile: xdt_translator.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-04-16 15:50:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_TRANSLATOR_SOURCE
#define XDT_TRANSLATOR_SOURCE

#include <string.h>
#include <libxml/tree.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/cybol/cybol_channel_constants.c"
#include "../../globals/constants/cybol/cybol_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/cybol/cybol_name_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

/**
 * Decodes the xdt model into a compound.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source xdt model
 * @param p4 the source count
 */
void decode_xdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the compound into a xdt model.
 *
 * @param p0 the destination xdt model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound
 * @param p4 the source count
 */
void encode_xdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* XDT_TRANSLATOR_SOURCE */
#endif
