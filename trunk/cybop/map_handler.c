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

#include <string.h>
#include "array_handler.c"

/**
 * This is a map handler.
 *
 * Map elements are accessed over their name or index.
 *
 * @version $Revision: 1.6 $ $Date: 2003-09-27 00:22:23 $ $Author: christian $
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
void initialize_map(void* p0) {

    struct map* m = (struct map*) p0;

    if (m != 0) {

        log(INFO_LOG_LEVEL, "Initialize map.");

        m->names = (void*) malloc(sizeof(0));
        m->references = (void*) malloc(sizeof(0));

    } else {

        log(ERROR_LOG_LEVEL, "Could not initialize map. The map is null.");
    }
}

/**
 * Finalizes the map.
 *
 * @param p0 the map
 */
void finalize_map(void* p0) {

    struct map* m = (struct map*) p0;
    
    if (m != 0) {

        log(INFO_LOG_LEVEL, "Finalize map.");

        free(m->references);
        free(m->names);

    } else {

        log(ERROR_LOG_LEVEL, "Could not finalize map. The map is null.");
    }
}

/**
 * Returns the map size.
 *
 * @param p0 the map
 * @return the map size
 */
int get_map_size(int p0) {

    int s = -1;
    struct map* m = (struct map*) p0;

    if (m != 0) {

        s = sizeof(m->names);

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map size. The map is null.");
    }

    return s;
}

//
// Map element.
//

/**
 * Adds the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
void add_map_element(void* p0, void* p1, void* p2) {

    void* n = get_map_element_name(p0, p1);
    set_map_element(p0, n, p2);
}

/**
 * Sets the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
void set_map_element(void* p0, void* p1, void* p2) {

    struct map* m = (struct map*) p0;
    
    if (m != 0) {
        
        int i = get_next_map_element_index(m, p1);

        m->names = set_array_element(m->names, i, p1);
        m->references = set_array_element(m->references, i, p2);

    } else {

        log(ERROR_LOG_LEVEL, "Could not set map element. The map is null.");
    }
}

/**
 * Removes the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 */
void remove_map_element_at_index(void* p0, int p1) {

    struct map* m = (struct map*) p0;
    
    if (m != 0) {

        remove_array_element(m->names, p1);
        remove_array_element(m->references, p1);

    } else {

        log(ERROR_LOG_LEVEL, "Could not remove map element. The map is null.");
    }
}

/**
 * Removes the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 */
void remove_map_element_with_name(void* p0, void* p1) {

    int i = get_map_element_index(p0, p1);

    remove_map_element_at_index(p0, i);
}

/**
 * Returns the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @return the element
 */
void* get_map_element_at_index(void* p0, int p1) {

    void* e = 0;
    struct map* m = (struct map*) p0;

    if (m != 0) {

        e = get_array_element(m->references, p1);

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map element. The map is null.");
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

    int i = get_map_element_index(p0, p1);

    return get_map_element_at_index(p0, i);
}

/**
 * Returns the map element index.
 *
 * @param p0 the map
 * @param p1 the name
 * @return the index
 */
int get_map_element_index(void* p0, void* p1) {

    int index = -1;
    struct map* m = (struct map*) p0;

    if (m != 0) {
        
        void* a = m->names;
        int i = index + 1;
        int size = sizeof(a);
        void* name = 0;

        while (i < size) {

            name = get_array_element(a, i);

            // If a 0 name is reached, then the name was not found.
            // In this case, reset index to -1.
            if (name == 0) {

                index = -1;
                break;
            
            } else {

                // If a name equal to the searched one is found,
                // then its index is the one to be returned.
                if (strcmp(name, p1) == 0) {

                    index = i;
                    break;
                }
            }

            i++;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map element index. The map is null.");
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
 * @param p0 the map
 * @param p1 the name
 * @return the next index
 */
int get_next_map_element_index(void* p0, void* p1) {

    int index = -1;
    struct map* m = (struct map*) p0;

    if (m != 0) {

        void* a = m->names;
        int i = index + 1;
        int size = sizeof(a);
        void* name = 0;

        while (i < size) {

            name = get_array_element(a, i);

            // If a 0 name is reached, then the name was not found.
            // In this case, the current value of i is the next free index.
            if (name == 0) {

                index = i;
                break;

            } else {

                // If a name equal to the searched one is found,
                // then its index is the one to be returned since
                // this element will have to be replaced.
                if (strcmp(name, p1) == 0) {

                    index = i;
                    break;
                }
            }

            i++;
        }

        // Neither element matched, nor was a 0 element found.
        // The map is full and such its size will be the next index to be used.
        if (index == -1) {

            index = size;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get next map element index. The map is null.");
    }

    return index;
}

/**
 * Returns the map element name.
 *
 * The given name is used as a word base for the new extended name.
 * Additionally, the new name will receive a number suffix.
 * It is determined by the current number of names containing the given word base
 * (which is the same as increasing the currently highest index by one).
 *
 * @param p0 the map
 * @param p1 the base name
 * @return the name
 */
void* get_map_element_name(void* p0, void* p1) {

    void* n = 0;
    char* index = ?? valueOf(get_map_element_count(p0, p1));

    if (p1 != 0) {

        if (index != 0) {

            n = strcat(strcat(p1, "_"), index);

        } else {

            log(ERROR_LOG_LEVEL, "Could not get map element name. The index string is null.");
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map element name. The name is null.");
    }
    
    return n;
}

/**
 * Returns the number of map elements whose name starts with the given name.
 *
 * @param p0 the map
 * @param p1 the name
 * @return the number of map elements whose name starts with the given name
 */
int get_map_element_count(void* p0, void* p1) {

    int count = 0;
    struct map* m = (struct map*) p0;

    if (m != 0) {

        void* a = m->names;
        int i = 0;
        int size = sizeof(a);
        void* name = 0;

        while (i < size) {

            name = get_array_element(a, i);

            if (name != 0) {

                if (strncmp(name, p1, strlen(p1))) {

/*??
                    int begin = 0;
                    char[] sub = 0;
                    int number = 0;
        
                    begin = ((char[]) name).indexOf("_");
                    sub = ((char[]) name).substring(begin + 1);
                    number = Integer.parseInt(sub);

                    if (number > count) {

                        count = number;
                    }
*/

                    count++;
                }

            } else {

                // Reached last valid name. Only null entries left.
                break;
            }

            i++;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get element count. The map is null.");
    }

    return count;
}

