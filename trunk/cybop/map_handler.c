/*
 * $RCSfile: map_handler.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
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

#ifndef MAP_HANDLER_SOURCE
#define MAP_HANDLER_SOURCE

#include <string.h>
#include "array_handler.c"
#include "map.c"

/**
 * This is the map handler.
 *
 * Map elements are accessed over their name or index.
 *
 * @version $Revision: 1.11 $ $Date: 2003-10-07 23:07:40 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Map.
//

/**
 * Initializes the map.
 *
 * @param p0 the map
 */
static void initialize_map(void* p0) {

    struct map* m = (struct map*) p0;

    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Initialize map.");

        m->names = (void**) malloc(0);
        m->references = (void**) malloc(0);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not initialize map. The map is null.");
    }
}

/**
 * Finalizes the map.
 *
 * @param p0 the map
 */
static void finalize_map(void* p0) {

    struct map* m = (struct map*) p0;
    
    if (m != 0) {

        log((void*) &INFO_LOG_LEVEL, "Finalize map.");

        free(m->references);
        free(m->names);
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not finalize map. The map is null.");
    }
}

/**
 * Returns the map size.
 *
 * @param p0 the map
 * @param p1 the map size
 */
static void get_map_size(void* p0, void* p1) {

    struct map* m = (struct map*) p0;

    if (m != 0) {

        int* s = (int*) p1;
        *s = sizeof(m->names);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get map size. The map is null.");
    }
}

//
// Helper functions.
//

/**
 * Returns the map element index.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the index
 */
static void get_map_element_index(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;

    if (m != 0) {
        
        void* a = m->names;
        int* index = (int*) p2;
        *index = -1;
        int i = 0;
        int size = sizeof(a);
        void* name = malloc(0);

        while (i < size) {

            get_array_element(a, (void*) &i, name);

            // If a 0 name is reached, then the name was not found.
            // In this case, reset index to -1.
            if (name == 0) {

                *index = -1;

                break;
            
            } else {

                // If a name equal to the searched one is found,
                // then its index is the one to be returned.
                if (strcmp((char*) name, (char*) p1) == 0) {

                    *index = i;

                    break;
                }
            }

            i++;
        }

        free(name);
        
    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get map element index. The map is null.");
    }
}

/**
 * Returns the next index that can be used to set a map element.
 *
 * If an element with the given name is found, then its index will be returned
 * so that the element can be replaced.
 * If a 0 element is reached, then the corresponding index marks the next
 * available place and will be returned.
 * If neither an element matches nor a 0 element is reached, then the
 * map is full and its size will be returned as next available index.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the next index
 */
static void get_next_map_element_index(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;

    if (m != 0) {

        void* a = m->names;
        int* index = (int*) p2;
        *index = -1;
        int i = 0;
        int size = sizeof(a);
        void* name = malloc(0);

        while (i < size) {

            get_array_element(a, (void*) &i, name);

            // If a 0 name is reached, then the name was not found.
            // In this case, the current value of i is the next free index.
            if (name == 0) {

                *index = i;

                break;

            } else {

                // If a name equal to the searched one is found,
                // then its index is the one to be returned since
                // this element will have to be replaced.
                if (strcmp((char*) name, (char*) p1) == 0) {

                    *index = i;

                    break;
                }
            }

            i++;
        }
        
        free(name);

        // Neither element matched, nor was a 0 element found.
        // The map is full and such its size will be the next index to be used.
        if (*index == -1) {

            *index = size;
        }

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get next map element index. The map is null.");
    }
}

/**
 * Returns the number of map elements whose name starts with the given name.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the number of map elements whose name starts with the given name
 */
static void get_map_element_count(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;

    if (m != 0) {

        void* a = m->names;
        int* count = (int*) p2;
        *count = 0;
        int i = 0;
        int size = sizeof(a);
        void* name = malloc(0);

        while (i < size) {

            get_array_element(a, (void*) &i, name);

            if (name != 0) {

                if (strncmp((char*) name, (char*) p1, strlen((char*) p1)) == 0) {

                    char* separation = "_";
                    char* suffix = strchr(name, separation);
                    char* begin = suffix[1];
                    char* check = strchr(begin, separation);

                    // If no second separation is found, the name really matches.                    
                    if (check == 0) {
                        
                        int number = atoi(begin);
    
                        if (number > *count) {
    
                            *count = number;
                        }
                    }
                }

            } else {

                // Reached last valid name. Only null entries left.
                break;
            }

            i++;
        }

        free(name);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get element count. The map is null.");
    }
}

/**
 * Returns the map element name.
 *
 * The given name is used as a word base for the new extended name.
 * Additionally, the new name will receive a number suffix.
 * It is determined by the current number of names containing the given
 * word base and finally increasing the highest index by one.
 *
 * @param p0 the map
 * @param p1 the base name
 * @param p2 the name
 */
static void get_map_element_name(void* p0, void* p1, void* p2) {

    int* count = (int*) malloc(0);
    *count = -1;
    char* suffix = (char*) malloc(0);

    get_map_element_count(p0, p1, (void*) count);
    get_value_string((void*) count, (void*) suffix);

    p2 = (void*) strcat(strcat((char*) p1, "_"), suffix);
    
    free(suffix);
    free(count);
}

//
// Map element.
//

/**
 * Sets the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
static void set_map_element(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;
    
    if (m != 0) {
        
        int* i = (int*) malloc(0);
        
        get_next_map_element_index(p0, p1, (void*) i);
        set_array_element(m->names, (void*) i, p1);
        set_array_element(m->references, (void*) i, p2);

        free(i);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not set map element. The map is null.");
    }
}

/**
 * Adds the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
static void add_map_element(void* p0, void* p1, void* p2) {

    void* n = malloc(0);

    // Get name extended by next index.
    get_map_element_name(p0, p1, n);
    set_map_element(p0, n, p2);
    
    free(n);
}

/**
 * Removes the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 */
static void remove_map_element_at_index(void* p0, void* p1) {

    struct map* m = (struct map*) p0;
    
    if (m != 0) {

        remove_array_element(m->names, p1);
        remove_array_element(m->references, p1);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not remove map element. The map is null.");
    }
}

/**
 * Removes the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 */
static void remove_map_element_with_name(void* p0, void* p1) {

    void* i = malloc(0);
    
    get_map_element_index(p0, p1, i);
    remove_map_element_at_index(p0, i);
    
    free(i);
}

/**
 * Returns the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @param p2 the element
 */
static void get_map_element_at_index(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;

    if (m != 0) {

        get_array_element(m->references, p1, p2);

    } else {

        log((void*) &ERROR_LOG_LEVEL, "Could not get map element. The map is null.");
    }
}

/**
 * Returns the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
static void get_map_element_with_name(void* p0, void* p1, void* p2) {

    void* i = malloc(0);
    
    get_map_element_index(p0, p1, i);
    get_map_element_at_index(p0, i, p2);
    
    free(i);
}

/* MAP_HANDLER_SOURCE */
#endif

