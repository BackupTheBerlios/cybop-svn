/*
 * $RCSfile: array_handler.c,v $
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
 */

#ifndef ARRAY_HANDLER_SOURCE
#define ARRAY_HANDLER_SOURCE

#include <stdlib.h>
#include "../logger/log_handler.c"
#include "../model/array.c"
#include "../model/character_array_handler.c"
#include "../model/double_array_handler.c"
#include "../model/integer_array_handler.c"
#include "../model/pointer_array_handler.c"

/**
 * This is the array handler.
 *
 * It contains procedures for handling an array and its elements.
 *
 * An array represents an allocated area in the computer's memory,
 * that can contain a number of abstract elements.
 * An abstraction simplifies and represents a real world item.
 * In the case of computer science, everything gets abstracted to 0 and 1.
 * But that also means that every abstraction has a bytecode representation.
 *
 * The C programming language provides a number of primitive data types whose
 * size is defined so that an array can be created of them. The types are:
 * - pointer
 * - integer
 * - character
 * - double
 *
 * To work with an array, this handler needs additional information, in concrete:
 * - the array size (allocated memory)
 * - the array type (of data)
 *
 * There is no extra "count" value. Arrays are always as big as the number of
 * elements they contain.
 *
 * The sizeof operation can only be used for real arrays, expressed with [].
 * Since CYBOI allocates arrays dynamically and stores them as *,
 * the array size needs to be given extra here because sizeof will not work.
 * See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
 *
 * @version $Revision: 1.18 $ $Date: 2004-03-19 16:24:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

//?? Possibly remove pointer array, if a pointer is really identical to an integer.

/** The pointer array constant. */
static const int POINTER_ARRAY = 0;

/** The integer array constant. */
static const int INTEGER_ARRAY = 1;

//?? Possibly remove character array, if a character primitive is really
//?? identical to an integer primitive. Are they?

/** The character array constant. */
static const int CHARACTER_ARRAY = 3;

//?? Possibly remove double array, if a double primitive can be replaced by
//?? a compound structure like "fraction". How would this effect performance
//?? when ALU will not work with doubles but they rather get transformed into
//?? integers first?

/** The double array constant. */
static const int DOUBLE_ARRAY = 2;

//
// Array.
//

/**
 * Initializes the array.
 *
 * @param p0 the array
 * @param p1 the size
 */
void initialize_array(void* p0, const void* p1) {

    int* s = (int*) p1;

    if (s != (void*) 0) {

        void** a = (void**) p0;

        if (a != (void*) 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Initialize array.");

            // An array CANNOT have ZERO length, so that dereferencing a pointer to
            // the first element of an array always returns a valid result.
            // There is no NULL array.
            // See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
            *a = malloc(*s);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize array. The array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize array. The size is null.");
    }
}

/**
 * Finalizes the array.
 *
 * @param p0 the array
 * @param p1 the size
 */
void finalize_array(void* p0, const void* p1) {

    int* s = (int*) p1;

    if (s != (void*) 0) {

        void** a = (void**) p0;

        if (a != (void*) 0) {

            log_message((void*) &INFO_LOG_LEVEL, "Initialize array.");

            // An array CANNOT have ZERO length, so that dereferencing a pointer to
            // the first element of an array always returns a valid result.
            // There is no NULL array.
            // See: http://pegasus.rutgers.edu/~elflord/cpp/gotchas/index.shtml
            free(*a);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize array. The array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize array. The size is null.");
    }
}

/**
 * Compares the arrays.
 *
 * Returns 1 if the arrays are equal in:
 * - size
 * - type
 * - elements
 * The given result remains unchanged if the arrays are unequal.
 *
 * @param p0 the first array
 * @param p1 the first size
 * @param p2 the first type
 * @param p3 the second array
 * @param p4 the second size
 * @param p5 the second type
 * @param p6 the result
 */
void compare_arrays(const void* p0, const void* p1, const void* p2, const void* p3, const void* p4, const void* p5, void* p6) {

    int* t2 = (int*) p5;

    if (t2 != (void*) 0) {

        int* s2 = (int*) p4;

        if (s2 != (void*) 0) {

            int* t1 = (int*) p2;

            if (t1 != (void*) 0) {

                int* s1 = (int*) p1;

                if (s1 != (void*) 0) {

                    // The size must be equal.
                    if (*s1 == *s2) {

                        // The type must be equal.
                        if (*t1 == *t2) {

                            // The elements must be equal.
                            if (*t1 == POINTER_ARRAY) {

                                compare_pointer_arrays(p0, p3, p1, p6);

                            } else if (*t1 == INTEGER_ARRAY) {

                                compare_integer_arrays(p0, p3, p1, p6);

                            } else if (*t1 == DOUBLE_ARRAY) {

                                compare_double_arrays(p0, p3, p1, p6);

                            } else if (*t1 == CHARACTER_ARRAY) {

                                compare_character_arrays(p0, p3, p1, p6);
                            }
                        }
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not compare arrays. The first size is null.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not compare arrays. The first type is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not compare arrays. The second size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not compare arrays. The second type is null.");
    }
}

/**
 * Resizes the array with the given size.
 *
 * @param p0 the array
 * @param p1 the size
 */
void resize_array(void* p0, const void* p1) {

    int* s = (int*) p1;

    if (s != (void*) 0) {

        void** a = (void**) p0;

        if (a != (void*) 0) {

            // Create a new array with extended size.
            *a = realloc(*a, *s);

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not resize array. The array is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not resize array. The size is null.");
    }
}

//
// Array element.
//

/**
 * Sets the array element.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the type
 * @param p3 the index
 * @param p4 the element
 */
void set_array_element(void* p0, void* p1, const void* p2, const void* p3, const void* p4) {

    int* i = (int*) p3;

    if (i != (void*) 0) {

        int* t = (int*) p2;

        if (t != (void*) 0) {

            int* s = (int*) p1;

            if (s != (void*) 0) {

                if (*i >= 0) {

                    if (*i = *s) {

                        // Extend array if element is added.
                        resize_array(p0, p1);
                        *s = *s + 1;
                    }

                    if (*i < *s) {

                        if (*t == POINTER_ARRAY) {

                            set_pointer_array_element(p0, p3, p4);

                        } else if (*t == INTEGER_ARRAY) {

                            set_integer_array_element(p0, p3, p4);

                        } else if (*t == DOUBLE_ARRAY) {

                            set_double_array_element(p0, p3, p4);

                        } else if (*t == CHARACTER_ARRAY) {

                            set_character_array_element(p0, p3, p4);
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, "Could not set array element. The index exceeds the size.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not set array element. The index is negativ.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not set array element. The size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not set array element. The type is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set array element. The index is null.");
    }
}

/**
 * Removes the array element.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the type
 * @param p3 the index
 */
void remove_array_element(void* p0, void* p1, const void* p2, const void* p3) {

    int* i = (int*) p3;

    if (i != (void*) 0) {

        int* t = (int*) p2;

        if (t != (void*) 0) {

            int* s = (int*) p1;

            if (s != (void*) 0) {

                if (*i >= 0) {

                    if (*i < *s) {

                        if (*t == POINTER_ARRAY) {

                            remove_pointer_array_element(p0, p1, p3);

                        } else if (*t == INTEGER_ARRAY) {

                            remove_integer_array_element(p0, p1, p3);

                        } else if (*t == DOUBLE_ARRAY) {

                            remove_double_array_element(p0, p1, p3);

                        } else if (*t == CHARACTER_ARRAY) {

                            remove_character_array_element(p0, p1, p3);
                        }

                        // Reduce array.
                        resize_array(p0, p1);
                        *s = *s - 1;

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The index exceeds the size.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The index is negativ.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The type is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove array element. The index is null.");
    }
}

/**
 * Gets the array element.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the type
 * @param p3 the index
 * @param p4 the element
 */
void get_array_element(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    int* i = (int*) p3;

    if (i != (void*) 0) {

        int* t = (int*) p2;

        if (t != (void*) 0) {

            int* s = (int*) p1;

            if (s != (void*) 0) {

                if (*i >= 0) {

                    if (*i < *s) {

                        if (*t == POINTER_ARRAY) {

                            get_pointer_array_element(p0, p3, p4);

                        } else if (*t == INTEGER_ARRAY) {

                            get_integer_array_element(p0, p3, p4);

                        } else if (*t == DOUBLE_ARRAY) {

                            get_double_array_element(p0, p3, p4);

                        } else if (*t == CHARACTER_ARRAY) {

                            get_character_array_element(p0, p3, p4);
                        }

                    } else {

                        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element. The index exceeds the size.");
                    }

                } else {

                    log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element. The index is negativ.");
                }

            } else {

                log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element. The size is null.");
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element. The type is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element. The index is null.");
    }
}

/**
 * Gets the array element index.
 *
 * @param p0 the array
 * @param p1 the size
 * @param p2 the type
 * @param p3 the element
 * @param p4 the index
 */
void get_array_element_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    int* t = (int*) p2;

    if (t != (void*) 0) {

        if (*t == POINTER_ARRAY) {

            get_pointer_array_element_index(p0, p1, p3, p4);

        } else if (*t == INTEGER_ARRAY) {

            get_integer_array_element_index(p0, p1, p3, p4);

        } else if (*t == DOUBLE_ARRAY) {

            get_double_array_element_index(p0, p1, p3, p4);

        } else if (*t == CHARACTER_ARRAY) {

            get_character_array_element_index(p0, p1, p3, p4);
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get array element index. The type is null.");
    }
}

/* ARRAY_HANDLER_SOURCE */
#endif
