/*
 * $RCSfile: map_handler.c,v $
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

#ifndef MAP_HANDLER_SOURCE
#define MAP_HANDLER_SOURCE

#include <string.h>
#include "../logger/log_handler.c"
#include "../model/array_handler.c"

/**
 * This is the map handler.
 *
 * A map is like a table. One column (array) contains the element names.
 * A second column (array) contains the actual element references.
 *
 * The map itself is an array consisting of:
 * - array size
 * - names array
 * - names sizes array
 * - references array
 * - references sizes array
 *
 * A map's elements can such be accessed over their name or index.
 *
 * @version $Revision: 1.17 $ $Date: 2004-03-29 08:15:05 $ $Author: christian $
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

    log_message((void*) &INFO_LOG_LEVEL, "Initialize map.");

    // The map size.
    int s = 4;
    // The map.
    initialize_array(p0, (void*) &s);
    // The index.
    int i;

    //?? Actually, the array size should be stored in an own integer_array.
    //?? But since probably in the future, only the integer_array will
    //?? stay and a pointer in the end is also an integer, the array size
    //?? is just added at first, before the names and references arrays,
    //?? to the pointer array which represents the map.
    //?? Caution! INTEGER_ARRAY needs to be given as type for the array size.

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    set_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    initialize_array((void*) &n, (void*) &as);
    set_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);

    // The names sizes array.
    i = 2;
    void* ns = (void*) 0;
    initialize_array((void*) &ns, (void*) &as);
    set_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &ns);

    // The references array.
    i = 3;
    void* r = (void*) 0;
    initialize_array((void*) &r, (void*) &as);
    set_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &r);
}

/**
 * Finalizes the map.
 *
 * @param p0 the map
 */
void finalize_map(void* p0) {

    log_message((void*) &INFO_LOG_LEVEL, "Finalize map.");

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The references array.
    i = 3;
    void* r = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &r);
    remove_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i);
    finalize_array((void*) &r, (void*) &as);

    // The names sizes array.
    i = 2;
    void* ns = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &ns);
    remove_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i);
    finalize_array((void*) &sn, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);
    remove_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i);
    finalize_array((void*) &n, (void*) &as);

    //?? Actually, the array size should be stored in an own integer_array.
    //?? Caution! INTEGER_ARRAY needs to be given as type for the array size.
    //?? The remove procedure moves all pointer elements and deletes the
    //?? last element. Since the size is the last remaining element,
    //?? no pointer elements are found which would be wrongly casted to (int*).

    // The array size which is always equal for both arrays.
    i = 0;
    remove_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i);

    // The map.
    finalize_array(p0, (void*) &s);
}

//
// Map element.
//

/**
 * Gets the map element index.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the index
 */
void get_map_element_index(const void* p0, const void* p1, const void* p2, void* p3) {

    int* index = (int*) p3;

    if (index != (void*) 0) {

        // The map size.
        int s = 4;
        // The index.
        int i;

        // The array size which is always equal for both arrays.
        i = 0;
        int as = 0;
        get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

        // The names array.
        i = 1;
        void* n = (void*) 0;
        get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);

        // The names sizes array.
        i = 2;
        void* ns = (void*) 0;
        get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &ns);

        // The comparison loop.
        int j = 0;
        void* name = (void*) 0;
        int size = 0;
        int r = 0;

        while (1) {

            if (j >= as) {

                break;
            }

            get_array_element((void*) &n, (void*) &as, (void*) &POINTER_ARRAY, (void*) &j, (void*) &name);
            get_array_element((void*) &ns, (void*) &as, (void*) &POINTER_ARRAY, (void*) &j, (void*) &size);
            compare_arrays(p1, p2, (void*) &CHARACTER_ARRAY, name, size, (void*) &CHARACTER_ARRAY, (void*) &r);

            if (r == 1) {

                *index = j;
                break;
            }
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, "Could not get map element index. The index is null.");
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
 * @param p0 the names array
 * @param p1 the name
 * @return the next index
 */
/*??
int get_next_map_element_index(const void* p0, const void* p1) {

    int index = INVALID_INDEX;
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
    if (index == INVALID_INDEX) {

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
/*??
int get_map_element_count(const void* p0, const void* p1) {

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
/*??
void build_next_map_element_name(const void* p0, const void* p1, void* p2) {

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

/**
 * Sets the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @param p2 the name
 * @param p3 the name size
 * @param p4 the element
 */
void set_map_element_at_index(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);
    set_array_element((void*) &n, (void*) &as, (void*) &POINTER_ARRAY, p1, p2);

    // Store the new array size here after it was incremented once.
    // The size gets possibly manipulated again and again below,
    // so that it has to be stored and set here.
    i = 0;
    set_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names sizes array.
    i = 2;
    void* ns = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &ns);
    set_array_element((void*) &ns, (void*) &as, (void*) &INTEGER_ARRAY, p1, p3);

    // The references array.
    i = 3;
    void* r = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &r);
    set_array_element((void*) &r, (void*) &as, (void*) &POINTER_ARRAY, p1, p4);
}

/**
 * Adds the map element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the element
 */
void add_map_element(void* p0, const void* p1, const void* p2, const void* p3) {

/*??
    // This element name will get destroyed (free) in remove_map_element.
    void* n = malloc(0);

    // Extend name with next free index.
    build_next_map_element_name(m->names, p1, n);
    set_map_element_with_name(p0, n, p3);

    int i = -1;

    get_map_size(p0, (void*) &i);

    if (i != -1) {

        set_map_element_at_index(p0, (void*) &i, p1, p3);
    }
*/
}

/**
 * Sets the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the element
 */
void set_map_element_with_name(void* p0, const void* p1, const void* p2, const void* p3) {

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);

    // The index of the given name.
    int index = -1;
    get_map_element_index(p0, p1, p2, index);

    if (index != -1) {

        set_map_element_at_index(p0, (void*) &index, p1, p2, p3);

    } else {

        add_map_element(p0, p1, p2, p3);
    }
}

/**
 * Removes the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 */
void remove_map_element_at_index(void* p0, const void* p1) {

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);
    remove_array_element((void*) &n, (void*) &as, (void*) &POINTER_ARRAY, p1);

    // Store the new array size here after it was decremented once.
    // The size gets possibly manipulated again and again below,
    // so that it has to be stored and set here.
    i = 0;
    set_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names sizes array.
    i = 2;
    void* ns = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &ns);
    remove_array_element((void*) &ns, (void*) &as, (void*) &INTEGER_ARRAY, p1);

    // The references array.
    i = 3;
    void* r = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &r);
    remove_array_element((void*) &r, (void*) &as, (void*) &POINTER_ARRAY, p1);
}

/**
 * Removes the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 */
void remove_map_element_with_name(void* p0, const void* p1, const void* p2) {

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);

    // The index of the given name.
    int index = -1;
    get_map_element_index(p0, p1, p2, index);

    if (index != -1) {

        remove_map_element_at_index(p0, (void*) &index);
    }

    // This element name was created (malloc) in add_map_element.
//??    free(p1);
}

/**
 * Gets the map element at the index.
 *
 * @param p0 the map
 * @param p1 the index
 * @param p2 the element
 */
void get_map_element_at_index(const void* p0, const void* p1, void* p2) {

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The references array.
    i = 3;
    void* r = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &r);
    get_array_element((void*) &r, (void*) &as, (void*) &POINTER_ARRAY, p1, p2);
}

/**
 * Gets the map element with the name.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the element
 */
void get_map_element_with_name(const void* p0, const void* p1, const void* p2, void* p3) {

    // The map size.
    int s = 4;
    // The index.
    int i;

    // The array size which is always equal for both arrays.
    i = 0;
    int as = 0;
    get_array_element(p0, (void*) &s, (void*) &INTEGER_ARRAY, (void*) &i, (void*) &as);

    // The names array.
    i = 1;
    void* n = (void*) 0;
    get_array_element(p0, (void*) &s, (void*) &POINTER_ARRAY, (void*) &i, (void*) &n);

    // The index of the given name.
    int index = -1;
    get_map_element_index(p0, p1, p2, index);

    if (index != -1) {

        get_map_element_at_index(p0, (void*) &index, p3);
    }
}

/* MAP_HANDLER_SOURCE */
#endif
