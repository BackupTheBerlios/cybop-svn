/*
 * $RCSfile: x_windows_translator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * @version $Revision: 1.1 $ $Date: 2005-03-18 09:20:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOWS_TRANSLATOR_SOURCE
#define X_WINDOWS_TRANSLATOR_SOURCE

#include "../global/includes.c"

/**
 * Decodes the x windows model into a compound.
 *
 * @param p0 the destination (compound model) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (x windows model)
 * @param p4 the source count
 */
void decode_x_windows(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Encodes the compound into an x windows model.
 *
 * @param p0 the destination (x windows model) (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source (compound model)
 * @param p4 the source count
 */
void encode_x_windows(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

    } else {

        log_message_debug("Could not encode x windows. The source count is null.");
    }
}

/* X_WINDOWS_TRANSLATOR_SOURCE */
#endif
