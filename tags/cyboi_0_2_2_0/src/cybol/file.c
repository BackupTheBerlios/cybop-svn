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
 * @version $Revision: 1.11 $ $Date: 2004-06-23 21:48:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SOURCE
#define FILE_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../logger/logger.c"

/**
 * Reads the file into the array.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the array count
 * @param p3 the file name
 * @param p4 the file name count
 */
/*??
void read_file(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* fnc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ac = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* as = (int*) p1;

                log_message((void*) &INFO_LOG_LEVEL, (void*) &"Read file.");

                // The file name.
                void* n = NULL_POINTER;
                // The new file name count.
                int nc = *fnc + 1;
                // The index for the original file name.
                int oi = 0;

                // Create temporary file name with extended size
                // for string termination character.
                create_array((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &nc);
                // Add original file name.
                set_array_elements((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &oi, p3, p4);
                // Add string termination character using file name count as index.
                set_array_element((void*) &n, (void*) &CHARACTER_ARRAY, p4, (void*) &NULL_CHARACTER);

                FILE* f = fopen((char*) n, "r");

                if (f != NULL_POINTER) {

                    char c = fgetc(f);
                    int j = 0;

                    while (1) {

                        if (c == EOF) {

                            break;
                        }

                        if (j >= *as) {

                            *as = *as * 2 + 1;
                            resize_array(p0, (void*) &CHARACTER_ARRAY, p1);
                        }

                        set_array_element(p0, (void*) &CHARACTER_ARRAY, (void*) &j, (void*) &c);

                        c = fgetc(f);
                        j++;
                    }

                    // Set array count to last valid index incremented by one.
                    *ac = j;

                    fclose(f);

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file is null.");
                }

                // Destroy temporary file name.
                destroy_array((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &nc);

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The array size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The array count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name count is null.");
    }
}
*/

/**
 * Writes the array into the file.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the array count
 * @param p3 the file name
 * @param p4 the file name count
 */
/*??
void write_file(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* fnc = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* ac = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* as = (int*) p1;

                log_message((void*) &INFO_LOG_LEVEL, (void*) &"Write file.");

                // The file name.
                void* n = NULL_POINTER;
                // The new file name count.
                int nc = *fnc + 1;
                // The index for the original file name.
                int oi = 0;

                // Create temporary file name with extended size
                // for string termination character.
                create_array((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &nc);
                // Add original file name.
                set_array_elements((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &oi, p3, p4);
                // Add string termination character using file name count as index.
                set_array_element((void*) &n, (void*) &CHARACTER_ARRAY, p4, (void*) &NULL_CHARACTER);

                FILE* f = fopen((char*) n, "w");

                if (f != NULL_POINTER) {

                    char r = NULL_CHARACTER;
                    int j = 0;
                    char c = NULL_CHARACTER;

                    while (1) {

                        if (j >= *as) {

                            break;
                        }

                        if (r == EOF) {

                            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. A write error occured.");

                            break;
                        }

                        get_array_element(p0, (void*) &CHARACTER_ARRAY, (void*) &j, (void*) &c);

                        r = fputc(c, f);
                        j++;
                    }

                    fclose(f);

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. The file is null.");
                }

                // Destroy temporary file name.
                destroy_array((void*) &n, (void*) &CHARACTER_ARRAY, (void*) &nc);

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. The array size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. The array count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write file. The file name count is null.");
    }
}
*/

/**
 * Reads inline.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the inline byte stream
 * @param p4 the inline byte stream count
 */
void read_inline(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* ic = (int*) p4;

        if (p2 != NULL_POINTER) {

            int* as = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* ac = (int*) p1;

                // Set new array size.
                *as = *ic;

                // Resize array.
                resize_array(p0, (void*) &CHARACTER_ARRAY, p2);

                // The array index to start writing at.
                int i = 0;

                set_array_elements(p0, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);

                // Set new array count.
                *ac = *ic;

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read inline. The array count is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read inline. The array size is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read inline. The inline byte stream count is null.");
    }
}

/**
 * Writes inline.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the inline byte stream
 * @param p4 the inline byte stream count
 */
void write_inline(const void* p0, const void* p1, const void* p2, void* p3, void* p4) {
}

/**
 * Reads file.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the file name
 * @param p4 the file name count
 */
void read_file(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    if (p4 != NULL_POINTER) {

        int* nc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void** n = (void**) p3;

            if (p2 != NULL_POINTER) {

                int* as = (int*) p2;

                if (p1 != NULL_POINTER) {

                    int* ac = (int*) p1;

                    // Initialize terminated file name and its size.
                    char* tn = CHARACTER_NULL_POINTER;
                    int tns = *nc + 1;

                    // Create terminated file name.
                    create_array((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &tns);

                    // Initialize destination array index.
                    int i = 0;

                    // Set terminated file name by first copying the actual name and then
                    // adding the null termination character.
                    set_array_elements((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &i, p3, p4);
                    set_array_element((void*) &tn, (void*) &CHARACTER_ARRAY, p4, (void*) &NULL_CHARACTER);

    fprintf(stderr, "read file name: %s\n", tn);
    fprintf(stderr, "read file name size: %i\n", tns);

                    // Open file.
                    // CAUTION! The file name cannot be handed over as is.
                    // CYBOI strings are NOT terminated with the null character '\0'.
                    // Since 'fopen' expects a null terminated string, the termination character
                    // must be added to the string before that is used to open the file.
                    FILE* f = fopen(tn, "r");

                    if (f != NULL_POINTER) {

                        // Read first character.
                        char c = fgetc(f);

                        while (1) {

                            if (c == EOF) {

                                break;
                            }

                            if (*ac == *as) {

                                // Increase size.
                                *as = *as * FILE_RESIZE_FACTOR + 1;

                                // Resize array.
                                resize_array(p0, (void*) &CHARACTER_ARRAY, p2);
                            }

                            if (*ac < *as) {

                                // Set character in destination array.
                                // The array count serves as index for setting the character.
                                set_array_element(p0, (void*) &CHARACTER_ARRAY, p1, (void*) &c);

                                // Increase array count.
                                (*ac)++;

                            } else {

//??                                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The index exceeds the array size.");
                            }

                            // Read next character.
                            c = fgetc(f);
                        }

                        // Close file.
                        fclose(f);

                        // Destroy terminated file name.
                        destroy_array((void*) &tn, (void*) &CHARACTER_ARRAY, (void*) &tns);

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file is null.");
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The array count is null.");
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The array size is null.");
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read file. The file name count is null.");
    }
}

/**
 * Writes file.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the file name
 * @param p4 the file name count
 */
void write_file(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {
}

/**
 * Reads ftp.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the ftp url
 * @param p4 the ftp url count
 * ?? login
 * ?? password
 */
void read_ftp(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Writes ftp.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the ftp url
 * @param p4 the ftp url count
 * ?? login
 * ?? password
 */
void write_ftp(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {
}

/**
 * Reads http.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the http url
 * @param p4 the http url count
 */
void read_http(void* p0, void* p1, void* p2, const void* p3, const void* p4) {
}

/**
 * Writes http.
 *
 * @param p0 the array
 * @param p1 the array count
 * @param p2 the array size
 * @param p3 the http url
 * @param p4 the http url count
 */
void write_http(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {
}

/* FILE_SOURCE */
#endif
