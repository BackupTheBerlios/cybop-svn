/*
 * $RCSfile: file.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * This file handles a file.
 *
 * @version $Revision: 1.1 $ $Date: 2004-05-11 06:15:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SOURCE
#define FILE_SOURCE

#include <stdio.h>
#include "../constants/constants.c"
#include "../logger/logger.c"

/**
 * Reads the file into the array.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the file name
 * @param p3 the file name size
 */
void read_file(void* p0, void* p1, const void* p2, const void* p3) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read file.");

    // The string termination index.
    int* i = (int*) p3;
    // The file name count.
    int c = *i + 1;
    // The file name.
    void* n = NULL_POINTER;

    // Create new file name with extended size for string termination character.
    create_array((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &c);
    // Add string termination character.
    set_array_element((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &STRING_TERMINATION_CHARACTER);

    FILE* f = fopen((char*) n, "r");

    if (f != NULL_POINTER) {

        int j = 0;

        while (1) {

            j++;
        }

        fclose(f);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file is null.");
    }

    // Destroy file name.
    destroy_array((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &c);
}

/**
 * Writes the array into the file.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the file name
 * @param p3 the file name size
 */
void write_file(const void* p0, const void* p1, void* p2, void* p3) {

    log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read file.");
}

/* FILE_SOURCE */
#endif
