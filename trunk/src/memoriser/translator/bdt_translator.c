/*
 * $RCSfile: bdt_translator.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-02-07 00:13:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BDT_TRANSLATOR_SOURCE
#define BDT_TRANSLATOR_SOURCE

#include <string.h>
#include <libxml/tree.h>
#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/channel_constants.c"
#include "../../globals/constants/cybol_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/name_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"
#include "../../memoriser/allocator.c"

/**
 * Decodes the bdt model into a compound.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source bdt model
 * @param p4 the source count
 */
void decode_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Encodes the compound into a bdt model.
 *
 * @param p0 the destination bdt model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound
 * @param p4 the source count
 */
void encode_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* BDT_TRANSLATOR_SOURCE */
#endif
