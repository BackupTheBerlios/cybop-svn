/*
 * $RCSfile: character_escape_code_mapper.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2005-07-21 08:02:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ESCAPE_CODE_MAPPER_SOURCE
#define CHARACTER_ESCAPE_CODE_MAPPER_SOURCE

/**
 * Gets the escape code for the given character.
 *
 * @param p0 the destination escape code
 * @param p1 the destination escape code count
 * @param p2 the destination escape code size
 * @param p3 the source character
 * @param p4 the source character count
 */
void get_escape_code(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p1 != NULL_POINTER) {

        int* dc = (int*) p1;

        if (p0 != NULL_POINTER) {

            void** d = (void**) p0;

            // The comparison result.
            int r = 0;

            if (r == 0) {

                compare_arrays(p3, p4, SPACE_CHARACTER, SPACE_CHARACTER_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    *d = SPACE_CHARACTER_ESCAPE_CODE;
                    *dc = SPACE_CHARACTER_ESCAPE_CODE_COUNT;
                }
            }

            if (r == 0) {

                compare_arrays(p3, p4, SPACE_CHARACTER, SPACE_CHARACTER_COUNT, &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    *d = SPACE_CHARACTER_ESCAPE_CODE;
                    *dc = SPACE_CHARACTER_ESCAPE_CODE_COUNT;
                }
            }

        } else {

            log_message_debug("Could not get escape code. The destination is null.");
        }

    } else {

        log_message_debug("Could not get escape code. The destination count is null.");
    }
}

/* CHARACTER_ESCAPE_CODE_MAPPER_SOURCE */
#endif