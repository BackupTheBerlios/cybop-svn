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
#include "../logger/log_handler.c"
#include "../model/array_handler.c"
#include "../model/map.c"

/**
 * This is the map handler.
 *
 * Map elements are accessed over their name or index.
 *
 * @version $Revision: 1.9 $ $Date: 2004-02-29 23:32:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Constants.
//

/** The separation. The ASCII code for "_" is 95. */
static const int SEPARATION = 95;

//
// Map.
//

/**
 * Initializes the map.
 *
 * @param p0 the map
 */
void initialize_map(void* p0) {

    struct map* m = (struct map*) p0;

    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Initialize map.");

        m->names = malloc(sizeof(struct array));
        initialize_array(m->names);

        m->references = malloc(sizeof(struct array));
        initialize_array(m->references);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not initialize map. The map is null.");
    }
}

/**
 * Finalizes the map.
 *
 * @param p0 the map
 */
void finalize_map(void* p0) {

    struct map* m = (struct map*) p0;
    
    if (m != (void*) 0) {

        log_message((void*) &INFO_LOG_LEVEL, "Finalize map.");

        finalize_array(m->references);
        free(m->references);

        finalize_array(m->names);
        free(m->names);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not finalize map. The map is null.");
    }
}

/**
 * Returns the map size.
 *
 * @param p0 the map
 * @param p1 the map size
 */
void get_map_size(void* p0, void* p1) {

    struct map* m = (struct map*) p0;

    if (m != (void*) 0) {

        get_array_size(m->names, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get map size. The map is null.");
    }
}

//
// Helper functions.
//

/**
 * Returns the map element index.
 *
 * @param p0 the names array
 * @param p1 the name
 * @return the index
 */
int get_map_element_index(void* p0, void* p1) {

    int index = -1;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = (void*) 0;

    while (i < count) {

        name = get_array_element(p0, (void*) &i);

        // If a name equal to the searched one is found,
        // then its index is the one to be returned.
        if (strcmp((char*) name, (char*) p1) == 0) {

            index = i;

            break;
        }

        i++;
    }
    
    return index;
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
 * @param p0 the names array
 * @param p1 the name
 * @return the next index
 */
int get_next_map_element_index(void* p0, void* p1) {

    int index = -1;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = (void*) 0;

    while (i < count) {

        name = get_array_element(p0, (void*) &i);

        // If a name equal to the searched one is found,
        // then its index is the one to be returned
        // since this element will have to be replaced.
        if (strcmp((char*) name, (char*) p1) == 0) {

            index = i;

            break;
        }

        i++;
    }
    
    // Neither element matched. The next index will be the current element count.
    if (index == -1) {

        index = count;
    }

    return index;
}

/**
 * Returns the number of map elements whose name starts with the given base name.
 *
 * @param p0 the names array
 * @param p1 the base name
 * @return the number of map elements whose name starts with the given base name
 */
int get_map_element_count(void* p0, void* p1) {

    int name_count = 0;
    int i = 0;
    int count = 0;
    get_array_count(p0, (void*) &count);
    void* name = (void*) 0;

    while (i < count) {

        name = get_array_element(p0, (void*) &i);

        if (name != (void*) 0) {

            // Compares the current element's name with the searched base name.
            if (strncmp((char*) name, (char*) p1, strlen((char*) p1)) == 0) {

                char* suffix = strchr((char*) name, SEPARATION);
                char* check = strchr(suffix + 1, SEPARATION);

                // If no second separation is found, the name really matches.
                if (check == (void*) 0) {

                    int number = atoi(suffix + 1);

                    if (number > name_count) {

                        name_count = number;
                    }
                }
            }

        } else {

            // Reached last valid name. Only null entries left.
            break;
        }

        i++;
    }

    return name_count;
}

/**
 * Builds the next map element name.
 *
 * The given name is used as a word base for the new extended name.
 * Additionally, the new name will receive a number suffix.
 * It is determined by the current number of names containing the given
 * word base and finally increasing the highest index by one.
 *
 * @param p0 the names array
 * @param p1 the base name
 * @param p2 the extended name
 */
void build_next_map_element_name(void* p0, void* p1, void* p2) {

    int count = get_map_element_count(p0, p1);

    //?? It is unclear how to convert the integer into a string!
    //?? A simple cast does not work as it is only for ASCII code
    //?? but here a normal integer number is to be converted into a string.
    char suffix = (char) count;
    p2 = (void*) strcat((char*) p2, (char*) p1);
//??    char separation = (char) SEPARATION;
//?? Use SEPARATION instead of "_"!
    p2 = (void*) strcat((char*) p2, "_");
//??    p2 = (void*) strcat((char*) p2, &suffix);
    //?? Temporary solution adds "0" instead of real suffix.
    p2 = (void*) strcat((char*) p2, "0");
}

//
// Map element.
//

/**
 * Sets the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @param p2 the name
 * @param p3 the element
 */
void set_map_element_at_index(void* p0, void* p1, void* p2, void* p3) {

    struct map* m = (struct map*) p0;
    
    if (m != (void*) 0) {
        
        set_array_element(m->names, p1, p2);
        set_array_element(m->references, p1, p3);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set map element at index. The map is null.");
    }
}

/**
 * Sets the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
void set_map_element_with_name(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;
    
    if (m != (void*) 0) {
        
        int i = get_next_map_element_index(m->names, p1);
        set_map_element_at_index(p0, (void*) &i, p1, p2);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not set map element with name. The map is null.");
    }
}

/**
 * Adds the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
void add_map_element(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;

    if (m != (void*) 0) {

        // This element name will get destroyed (free) in remove_map_element.
        void* n = malloc(0);

        // Extend name with next free index.
        build_next_map_element_name(m->names, p1, n);
        set_map_element_with_name(p0, n, p2);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not add map element. The map is null.");
    }
}

/**
 * Removes the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 */
void remove_map_element_at_index(void* p0, void* p1) {

    struct map* m = (struct map*) p0;
    
    if (m != (void*) 0) {

        remove_array_element(m->names, p1);
        remove_array_element(m->references, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove map element at index. The map is null.");
    }
}

/**
 * Removes the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 */
void remove_map_element_with_name(void* p0, void* p1) {

    struct map* m = (struct map*) p0;

    if (m != (void*) 0) {
        
        int i = get_map_element_index(m->names, p1);
        remove_map_element_at_index(p0, (void*) &i);
        
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not remove map element with name. The map is null.");
    }

    // This element name was created (malloc) in add_map_element.
    free(p1);
}

/**
 * Returns the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @return the element
 */
void* get_map_element_at_index(void* p0, void* p1) {

    void* e = (void*) 0;
    struct map* m = (struct map*) p0;

    if (m != (void*) 0) {

        e = get_array_element(m->references, p1);

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get map element at index. The map is null.");
    }
    
    return e;
}

/**
 * Returns the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 * @return the element
 */
void* get_map_element_with_name(void* p0, void* p1) {

    void* e = (void*) 0;
    struct map* m = (struct map*) p0;

    if (m != (void*) 0) {
        
        int i = get_map_element_index(m->names, p1);
        e = get_map_element_at_index(p0, (void*) &i);
    
    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get map element with name. The map is null.");
    }

    return e;
}

/* MAP_HANDLER_SOURCE */
#endif
