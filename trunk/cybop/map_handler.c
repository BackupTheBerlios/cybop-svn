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

#include "array_handler.c"

/**
 * This is a map handler.
 *
 * Map elements are accessed over their name or index.
 *
 * @version $Revision: 1.3 $ $Date: 2003-09-23 23:43:21 $ $Author: christian $
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
void initialize_map(int p0) {

    struct map* m = (struct map*) p0;

    if (m != NULL) {

        log(INFO_LOG_LEVEL, "Initialize map.");

        m->names = (int[]*) malloc(sizeof(int[0]));
        m->references = (int[]*) malloc(sizeof(int[0]));

    } else {

        log(ERROR_LOG_LEVEL, "Could not initialize map. The map is NULL.");
    }
}

/**
 * Finalizes the map.
 *
 * @param p0 the map
 */
void finalize_map(int p0) {

    struct map* m = (struct map*) p0;
    
    if (m != NULL) {

        log(INFO_LOG_LEVEL, "Finalize map.");

        free(m->references);
        free(m->names);

    } else {

        log(ERROR_LOG_LEVEL, "Could not finalize map. The map is NULL.");
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

    if (m != NULL) {

        s = sizeof(m->names);

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map size. The map is NULL.");
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
void add_map_element(int p0, int p1, int p2) {

    int n = determine_map_element_name(p0, p1);
    set_map_element(p0, n, p2);
}

/**
 * Sets the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the element
 */
void set_map_element(int p0, int p1, int p2) {

    struct map* m = (struct map*) p0;
    
    if (m != NULL) {
        
        int i = determine_next_map_element_index(m, p1);

        m->names = set_array_element(m->names, i, p1);
        m->references = set_array_element(m->references, i, p2);

    } else {

        log(ERROR_LOG_LEVEL, "Could not set map element. The map is NULL.");
    }
}

/**
 * Removes the map element with the index.
 *
 * @param p0 the map
 * @param p1 the index
 */
void remove_map_element(int p0, int p1) {

    struct map* m = (struct map*) p0;
    
    if (m != NULL) {

        remove_array_element(m->names, p1);
        remove_array_element(m->references, p1);

    } else {

        log(ERROR_LOG_LEVEL, "Could not remove map element. The map is NULL.");
    }
}

/**
 * Removes the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 */
void remove_map_element(int p0, int p1) {

    int i = get_map_element_index(p0, p1);

    remove_map_element(p0, i);
}

/**
 * Returns the map element with the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @return the element
 */
int get_map_element(int p0, int p1) {

    int e = NULL;
    struct map* m = (struct map*) p0;

    if (m != NULL) {

        e = get_array_element(m->references, p1);

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map element. The map is NULL.");
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
int get_map_element(int p0, int p1) {

    int i = get_map_element_index(p0, p1);

    return get_map_element(p0, i);
}

/**
 * Returns the map element index.
 *
 * @param p0 the map
 * @param p1 the name
 * @return the index
 */
int get_map_element_index(int p0, int p1) {

    int index = -1;
    struct map* m = (struct map*) p0;

    if (m != NULL) {
        
        int a = m->names;
        int i = index + 1;
        int size = sizeof(a);
        int name = NULL;

        while (i < size) {

            name = get_array_element(a, i);

            // If a NULL name is reached, then the name was not found.
            // In this case, reset index to -1.
            if (name == NULL) {

                index = -1;
                break;
            
            } else {

                // If a name equal to the searched one is found,
                // then its index is the one to be returned.
                if (name.equals((char[]) p1)) {

                    index = i;
                    break;
                }
            }

            i++;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get map element index. The map is NULL.");
    }

    return index;
}

/**
 * Returns the next index that can be used to set a map element.
 *
 * If an element with the given name is found, then its index will be returned
 * so that the element can be replaced.
 * If a NULL element is reached, then the corresponding index marks the next
 * available place and will be returned.
 * If neither an element matches nor a NULL element is reached, then the
 * map is full and its size will be returned as next available index.
 *
 * @param p0 the map
 * @param p1 the name
 * @return the next index
 */
int determine_next_map_element_index(int p0, int p1) {

    int index = -1;
    struct map* m = (struct map*) p0;

    if (m != NULL) {

        int a = m->names;
        int i = index + 1;
        int size = sizeof(a);
        int name = NULL;

        while (i < size) {

            name = get_array_element(a, i);

            // If a NULL name is reached, then the name was not found.
            // In this case, the current value of i is the next free index.
            if (name == NULL) {

                index = i;
                break;

            } else {

                // If a name equal to the searched one is found,
                // then its index is the one to be returned since
                // this element will have to be replaced.
                if (name.equals((char[]) p1)) {

                    index = i;
                    break;
                }
            }

            i++;
        }

        // Neither element matched, nor was a NULL element found.
        // The map is full and such its size will be the next index to be used.
        if (index == -1) {

            index = size;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get next map element index. The map is NULL.");
    }

    return index;
}

/**
 * Determines the map element name.
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
int determine_map_element_name(int p0, int p1) {

    int n = NULL;
    char* index = java.lang.String.valueOf(get_map_element_count(p0, p1));

    if (p1 != NULL) {

        if (index != NULL) {

            n = p1 + "_" + index;

        } else {

            log(ERROR_LOG_LEVEL, "Could not determine map element name. The index string is NULL.");
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not determine map element name. The name is NULL.");
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
int get_map_element_count(int p0, int p1) {

    int count = 0;
    struct map* m = (struct map*) p0;

    if (m != NULL) {

        int a = m->names;
        int i = 0;
        int size = sizeof(a);
        int name = NULL;

        while (i < size) {

            name = get_array_element(a, i);

            if (name != NULL) {

                if ((name).startsWith(p1)) {

/*??
                    int begin = 0;
                    char[] sub = NULL;
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

                // Reached last valid name. Only NULL entries left.
                break;
            }

            i++;
        }

    } else {

        log(ERROR_LOG_LEVEL, "Could not get element count. The map is NULL.");
    }

    return count;
}

