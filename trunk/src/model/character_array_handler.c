/*
 * $RCSfile: character_array_handler.c,v $
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
 * This file handles a character array.
 *
 * An array is a reserved (allocated) area in the computer memory.
 * A programming language like C provides primitive data types whose size
 * is defined, for example: pointer, integer, double, character.
 * It is therefore possible to create and destroy arrays based on primitive types.
 *
 * The syntax of an array mostly looks like: type[size]
 * Example: char[10]
 *
 * When working with an array, it is referenced by a pointer like: type* variable
 * Example: char* array
 *
 * The array can be dereferenced accordingly: *variable
 * Example: *array
 *
 * Array elements are accessed over their index (array base pointer + index).
 *
 * @version $Revision: 1.14 $ $Date: 2004-04-21 11:10:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_ARRAY_HANDLER_SOURCE
#define CHARACTER_ARRAY_HANDLER_SOURCE

#include "../constants.c"
#include "../logger/log_handler.c"

/**
 * Compares the character array elements.
 *
 * Returns 1 if the character elements are equal.
 * The given result remains unchanged if the array elements are unequal.
 *
 * @param p0 the first array
 * @param p1 the second array
 * @param p2 the count
 * @param p3 the result
 */
void compare_character_array_elements(const void* p0, const void* p1, const void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* r = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* c = (int*) p2;

            if (p1 != NULL_POINTER) {

                char** a1 = (char**) p1;

                if (p0 != NULL_POINTER) {

                    char** a0 = (char**) p0;

                    int j = 0;
                    char* e0 = NULL_CHARACTER_POINTER;
                    char* e1 = NULL_CHARACTER_POINTER;

                    while (1) {

                        if (j >= *c) {

                            // All elements have been compared and are equal.
                            *r = 1;

                            break;
                        }

                        // Determine the next elements at array plus index.
                        e0 = (char*) (*a0 + j);
                        e1 = (char*) (*a1 + j);

                        if (*e0 != *e1) {

                            // Stop comparison if two elements are not equal.
                            break;
                        }

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare character array elements. The first array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare character array elements. The second array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare character array elements. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not compare character array elements. The result is null.");
    }
}

/**
 * Sets the character array elements.
 *
 * @param p0 the destination array
 * @param p1 the index
 * @param p2 the source array
 * @param p3 the count
 */
void set_character_array_elements(void* p0, const void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            char** s = (char**) p2;

            if (p1 != NULL_POINTER) {

                int* i = (int*) p1;

                if (p0 != NULL_POINTER) {

                    char** d = (char**) p0;

                    // The loop variable.
                    int j = 0;
                    // The destination base to start copying to.
                    char* db = (char*) (*d + *i);
                    // The source element.
                    char* se = NULL_CHARACTER_POINTER;
                    // The destination element.
                    char* de = NULL_CHARACTER_POINTER;

                    while (1) {

                        if (j >= *c) {

                            break;
                        }

                        // Determine source and destination element.
                        se = (char*) (*s + j);
                        de = (char*) (db + j);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set character array elements. The destination array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set character array elements. The index is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set character array elements. The source array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not set character array elements. The count is null.");
    }
}

/**
 * Removes the character array elements.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the index
 * @param p3 the count
 */
void remove_character_array_elements(void* p0, const void* p1, const void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* i = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* s = (int*) p1;

                if (p0 != NULL_POINTER) {

                    char** a = (char**) p0;

                    // The loop variable.
                    int j = 0;
                    // The remaining elements size.
                    int r = *s - (*i + *c);
                    // The destination base.
                    char* db = (char*) (*a + *i);
                    // The source base.
                    char* sb = (char*) (*a + *i + *c);
                    // The source element.
                    char* se = NULL_CHARACTER_POINTER;
                    // The destination element.
                    char* de = NULL_CHARACTER_POINTER;

                    // Starting from the given index, move all remaining elements
                    // one place towards the beginning of the elements.
                    // Example: "test..array"
                    // size = 11
                    // index = 4 (remove "..")
                    // count = 2
                    // rest = 11 - (4 + 2) = 11 - 6 = 5
                    while (1) {

                        if (j >= r) {

                            break;
                        }

                        // Determine source and destination element.
                        de = (char*) (db + j);
                        se = (char*) (sb + j);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                    // Set former last elements to ''. The ASCII of '' is 0.
                    // This is disabled for now, since when creating an array,
                    // its elements are also NOT initialized with ''.
                    // The calling procedure may just cut off the remaining
                    // elements by decreasing the array size (resizing).

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove character array elements. The array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove character array elements. The size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove character array elements. The index is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not remove character array elements. The count is null.");
    }
}

/**
 * Gets the character array elements.
 *
 * @param p0 the source array
 * @param p1 the index
 * @param p2 the destination array
 * @param p3 the count
 */
void get_character_array_elements(const void* p0, const void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* c = (int*) p3;

        if (p2 != NULL_POINTER) {

            char** d = (char**) p2;

            if (p1 != NULL_POINTER) {

                int* i = (int*) p1;

                if (p0 != NULL_POINTER) {

                    char** s = (char**) p0;

                    // The loop variable.
                    int j = 0;
                    // The source base to start copying from.
                    char* sb = (char*) (*s + *i);
                    // The source element.
                    char* se = NULL_CHARACTER_POINTER;
                    // The destination element.
                    char* de = NULL_CHARACTER_POINTER;

                    while (1) {

                        if (j >= *c) {

                            break;
                        }

                        // Determine source and destination element.
                        se = (char*) (sb + j);
                        de = (char*) (*d + j);

                        // Set destination element.
                        *de = *se;

                        j++;
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array elements. The source array is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array elements. The index is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array elements. The destination array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array elements. The count is null.");
    }
}

/**
 * Gets the character array elements index.
 *
 * The first occurence of the element will be considered.
 * The given index remains unchanged if no element is found.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the comparison array
 * @param p3 the count
 * @param p4 the index
 */
void get_character_array_elements_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* c = (int*) p3;

            if (p2 != NULL_POINTER) {

                char** ca = (char**) p2;

                if (p1 != NULL_POINTER) {

                    int* s = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        char** a = (char**) p0;

                        // The loop variable.
                        int j = 0;
                        // The iteration limit.
                        int l = *s - *c;
                        // The element.
                        char* e = NULL_CHARACTER_POINTER;
                        // The comparison result.
                        int r = 0;

                        while (1) {

                            if (j >= l) {

                                // The element has not been found.
                                break;
                            }

                            // Determine element.
                            e = (char*) (*a + j);

                            compare_character_array_elements((void*) &e, p2, p3, (void*) &r);

                            if (r == 1) {

                                // The element has been found.
                                *i = j;

                                break;
                            }

                            j++;
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array element index. The array is null.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array element index. The size is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array element index. The comparison array is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array element index. The count is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not get character array element index. The index is null.");
    }
}

/* CHARACTER_ARRAY_HANDLER_SOURCE */
#endif
