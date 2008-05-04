/*
 * $RCSfile: orienter.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2008-05-04 00:18:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ORIENTER_SOURCE
#define ORIENTER_SOURCE

#include "../globals/constants/pointer/pointer_constants.c"

/**
 * Deoptionalises the given command line argument options.
 *
 * @param p0 the orientation (positive value: wide character; negative value: narrow character)
 */
void orient(void* p0) {

    if (p0 != *NULL_POINTER) {

        int* o = (int*) p0;

        // Set stdout stream orientation.
        fwide(stdout, *o);
        // Set stdin stream orientation.
        fwide(stdin, *o);
        // Set stderr stream orientation.
        fwide(stderr, *o);

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        fputws(L"Error: Could not orient streams. The orientation is null.\n", stdout);
    }
}

/* ORIENTER_SOURCE */
#endif
