/*
 * $RCSfile: compound_accessor.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.21 $ $Date: 2005-02-10 23:45:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ACCESSOR_SOURCE
#define COMPOUND_ACCESSOR_SOURCE

#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../global/constant.c"
#include "../global/integer_constants.c"
#include "../global/log_constants.c"
#include "../global/structure_constants.c"
#include "../logger/logger.c"

/**
 * Gets the compound element index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the element name
 * @param p3 the element name count
 * @param p4 the index
 */
void get_compound_element_index(const void* p0, const void* p1, const void* p2, const void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p1 != NULL_POINTER) {

            int* cc = (int*) p1;

            log_message_debug("Get compound element index.");

            // The element names.
            void** n = POINTER_NULL_POINTER;
            void** nc = POINTER_NULL_POINTER;

            // Get element names.
            get_array_elements(p0, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);

            if (n != POINTER_NULL_POINTER) {

                if (nc != POINTER_NULL_POINTER) {

                    // The loop variable.
                    int j = 0;
                    // The name.
                    void** n1 = POINTER_NULL_POINTER;
                    void** nc1 = POINTER_NULL_POINTER;
                    // The comparison result.
                    int r = 0;

                    while (1) {

                        if (j >= *cc) {

                            break;
                        }

                        // Get element name.
                        get_array_elements(*n, (void*) &j, (void*) &n1, (void*) POINTER_ARRAY);
                        get_array_elements(*nc, (void*) &j, (void*) &nc1, (void*) POINTER_ARRAY);

                        if (n1 != POINTER_NULL_POINTER) {

                            if (nc1 != POINTER_NULL_POINTER) {

                                compare_arrays(p2, p3, (void*) *n1, (void*) *nc1, (void*) &r, (void*) CHARACTER_ARRAY);

                                if (r == 1) {

                                    *i = j;

                                    break;
                                }

                            } else {

                                log_message_debug("Could not get compound element index. The name count is null.");
                            }

                        } else {

                            log_message_debug("Could not get compound element index. The name is null.");
                        }

                        // Reset name and name count.
                        n1 = POINTER_NULL_POINTER;
                        nc1 = POINTER_NULL_POINTER;

                        j++;
                    }

                } else {

                    log_message_debug("Could not get compound element index. The element names counts is null.");
                }

            } else {

                log_message_debug("Could not get compound element index. The element names is null.");
            }

        } else {

            log_message_debug("Could not get compound element index. The compound count is null.");
        }

    } else {

        log_message_debug("Could not get compound element index. The index is null.");
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
    void* name = NULL_POINTER;

    while (i < count) {

        name = get_array_element(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX);

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
    void* name = NULL_POINTER;

    while (i < count) {

        name = get_array_element(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX);

        if (name != NULL_POINTER) {

            // Compares the current element's name with the searched base name.
            if (strncmp((char*) name, (char*) p1, strlen((char*) p1)) == 0) {

                char* suffix = strchr((char*) name, SEPARATION);
                char* check = strchr(suffix + 1, SEPARATION);

                // If no second separation is found, the name really matches.
                if (check == NULL_POINTER) {

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
 * Sets the compound element by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 * @param p4 the name
 * @param p5 the name count
 * @param p6 the name size
 * @param p7 the abstraction
 * @param p8 the abstraction count
 * @param p9 the abstraction size
 * @param p10 the model
 * @param p11 the model count
 * @param p12 the model size
 * @param p13 the details
 * @param p14 the details count
 * @param p15 the details size
 */
void set_compound_element_by_index(void* p0, void* p1, void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6,
    const void* p7, const void* p8, const void* p9,
    const void* p10, const void* p11, const void* p12,
    const void* p13, const void* p14, const void* p15) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* cs = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* cc = (int*) p1;

                if (*i >= 0) {

                    log_message_debug("Set compound element by index.");

                    // The names, abstractions, models, details.
                    void** n = POINTER_NULL_POINTER;
                    void** nc = POINTER_NULL_POINTER;
                    void** ns = POINTER_NULL_POINTER;
                    void** a = POINTER_NULL_POINTER;
                    void** ac = POINTER_NULL_POINTER;
                    void** as = POINTER_NULL_POINTER;
                    void** m = POINTER_NULL_POINTER;
                    void** mc = POINTER_NULL_POINTER;
                    void** ms = POINTER_NULL_POINTER;
                    void** d = POINTER_NULL_POINTER;
                    void** dc = POINTER_NULL_POINTER;
                    void** ds = POINTER_NULL_POINTER;

                    // Get names, abstractions, models, details.
                    get_array_elements(p0, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) NAMES_SIZES_INDEX, (void*) &ns, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) &as, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) DETAILS_SIZES_INDEX, (void*) &ds, (void*) POINTER_ARRAY);

                    if (n != POINTER_NULL_POINTER) {

                        if (nc != POINTER_NULL_POINTER) {

                            if (ns != POINTER_NULL_POINTER) {

                                if (a != POINTER_NULL_POINTER) {

                                    if (ac != POINTER_NULL_POINTER) {

                                        if (as != POINTER_NULL_POINTER) {

                                            if (m != POINTER_NULL_POINTER) {

                                                if (mc != POINTER_NULL_POINTER) {

                                                    if (ms != POINTER_NULL_POINTER) {

                                                        if (d != POINTER_NULL_POINTER) {

                                                            if (dc != POINTER_NULL_POINTER) {

                                                                if (ds != POINTER_NULL_POINTER) {

                                                                    if (*i == *cs) {

                                                                        // Increase size.
                                                                        *cs = (*cs * *COMPOUND_RESIZE_FACTOR) + 1;

                                                                        // Resize names, abstractions, models, details.
                                                                        resize_array(n, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(nc, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(ns, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(a, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(ac, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(as, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(m, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(mc, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(ms, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(d, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(dc, p2, (void*) POINTER_ARRAY);
                                                                        resize_array(ds, p2, (void*) POINTER_ARRAY);

                                                                        // Set new array reference.
                                                                        // CAUTION! If an array gets resized, a new array is
                                                                        // created and the contents of the old array gets copied.
                                                                        // Therefore, the new array reference needs to be set.
                                                                        // The old array gets destroyed automatically by resize.
                                                                        set_array_elements(p0, (void*) NAMES_INDEX, (void*) n, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) nc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) NAMES_SIZES_INDEX, (void*) ns, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_INDEX, (void*) a, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) ac, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) as, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) MODELS_INDEX, (void*) m, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) mc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) ms, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) DETAILS_INDEX, (void*) d, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) dc, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) DETAILS_SIZES_INDEX, (void*) ds, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                    }

                                                                    if (*i < *cs) {


                                                                        // Set name, abstraction, model, details.
                                                                        set_array_elements(*n, p3, (void*) &p4, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*nc, p3, (void*) &p5, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ns, p3, (void*) &p6, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*a, p3, (void*) &p7, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ac, p3, (void*) &p8, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*as, p3, (void*) &p9, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*m, p3, (void*) &p10, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*mc, p3, (void*) &p11, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ms, p3, (void*) &p12, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*d, p3, (void*) &p13, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*dc, p3, (void*) &p14, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ds, p3, (void*) &p15, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

                                                                        // Increment count.
                                                                        (*cc)++;

                                                                    } else {

                                                                        log_message_debug("Could not set compound element by index. The index exceeds the size.");
                                                                    }

                                                                } else {

                                                                    log_message_debug("Could not set compound element by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_message_debug("Could not set compound element by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_message_debug("Could not set compound element by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not set compound element by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not set compound element by index. The models counts is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not set compound element by index. The models is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not set compound element by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not set compound element by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_message_debug("Could not set compound element by index. The abstractions is null.");
                                }

                            } else {

                                log_message_debug("Could not set compound element by index. The names sizes is null.");
                            }

                        } else {

                            log_message_debug("Could not set compound element by index. The names counts is null.");
                        }

                    } else {

                        log_message_debug("Could not set compound element by index. The names is null.");
                    }

                } else {

                    log_message_debug("Could not set compound element by index. The index is negative.");
                }

            } else {

                log_message_debug("Could not set compound element by index. The compound count is null.");
            }

        } else {

            log_message_debug("Could not set compound element by index. The compound sizes is null.");
        }

    } else {

        log_message_debug("Could not set compound element by index. The index is null.");
    }
}

/**
 * Sets the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 * @param p5 the name size
 * @param p6 the abstraction
 * @param p7 the abstraction count
 * @param p8 the abstraction size
 * @param p9 the model
 * @param p10 the model count
 * @param p11 the model size
 * @param p12 the details
 * @param p13 the details count
 * @param p14 the details size
 */
void set_compound_element_by_name(void* p0, void* p1, void* p2,
    const void* p3, const void* p4, const void* p5,
    const void* p6, const void* p7, const void* p8,
    const void* p9, const void* p10, const void* p11,
    const void* p12, const void* p13, const void* p14) {

    // The separator index.
    int i = -1;

    get_array_elements_index(p3, p4, (void*) COMPOUND_ELEMENT_SEPARATOR, (void*) ONE_NUMBER, (void*) &i, (void*) CHARACTER_ARRAY);

    fprintf(stderr, "TEST set_compound_element_by_name n: %s\n", (char*) p3);
    fprintf(stderr, "TEST set_compound_element_by_name nc: %i\n", *((int*) p4));
    fprintf(stderr, "TEST set_compound_element_by_name ns: %i\n", *((int*) p5));

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains elements which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                log_message_debug("Set compound element by hierarchical name.");

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (p3 + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Get index of element name.
                                // The separator index i is used as element name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the element name "hello" before the separator is likewise 5.
                                int index = -1;

                                get_compound_element_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // The models.
                                    void** m = POINTER_NULL_POINTER;
                                    void** mc = POINTER_NULL_POINTER;
                                    void** ms = POINTER_NULL_POINTER;

                                    // Get models.
                                    get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                                    get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                                    get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);

                                    if (m != POINTER_NULL_POINTER) {

                                        if (mc != POINTER_NULL_POINTER) {

                                            if (ms != POINTER_NULL_POINTER) {

                                                // The element model.
                                                void** em = POINTER_NULL_POINTER;
                                                void** emc = POINTER_NULL_POINTER;
                                                void** ems = POINTER_NULL_POINTER;

                                                // Get element model.
                                                get_array_elements(*m, (void*) &index, (void*) &em, (void*) POINTER_ARRAY);
                                                get_array_elements(*mc, (void*) &index, (void*) &emc, (void*) POINTER_ARRAY);
                                                get_array_elements(*ms, (void*) &index, (void*) &ems, (void*) POINTER_ARRAY);

                                                if (em != POINTER_NULL_POINTER) {

                                                    if (emc != POINTER_NULL_POINTER) {

                                                        if (ems != POINTER_NULL_POINTER) {

                                                            //?? TODO:
                                                            //?? For now, the remaining name count is also used as
                                                            //?? remaining name size and such handed over twice.
                                                            //?? Later implementations may use UNICODE names so that
                                                            //?? the name count and size differ.

                                                            // Recursively continue to process along the hierarchical name.
                                                            set_compound_element_by_name(*em, *emc, *ems, r, (void*) &rc, (void*) &rc,
                                                                p6, p7, p8, p9, p10, p11, p12, p13, p14);

                                                        } else {

                                                            log_message_debug("Could not set compound element by name. The element model size is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not set compound element by name. The element model count is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not set compound element by name. The element model is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not set compound element by name. The models sizes is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not set compound element by name. The models counts is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not set compound element by name. The models is null.");
                                    }

                                } else {

                                    log_message_debug("Could not set compound element by name. An element with that name does not exist.");
                                }

                            } else {

                                log_message_debug("Could not set compound element by name. The name ends with a separator.");
                            }

                        } else {

                            log_message_debug("Could not set compound element by name. The name starts with a separator.");
                        }

                    } else {

                        log_message_debug("Could not set compound element by name. The separator index exceeds the name count.");
                    }

                } else {

                    log_message_debug("Could not set compound element by name. The separator index is negative.");
                }

            } else {

                log_message_debug("Could not set compound element by name. The name is null.");
            }

        } else {

            log_message_debug("Could not set compound element by name. The name count is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the element name.
        // The given compound contains elements which are primitive models.

        // The index of the name.
        int index = -1;

        get_compound_element_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

            log_message_debug("Set compound element by name.");

            //?? TODO:
            //?? - Do NOT just replace existing elements; otherwise the reference
            //??   to them is lost and they can not be destroyed properly.
            //?? - Allow replacement for primitive types (integer, double) that
            //??   do not have to be destroyed!
            //?? - Check the abstraction of the model to be set:
            //??   If it is compound, then do NOT replace --> error message; otherwise DO replace!

/*??
            // Check if element exists.

            // Use index of the found element.
            set_compound_element_by_index(p0, p1, p2,
                (void*) &index,
                p3, p4, p5,
                p6, p7, p8, p9, p10, p11, p12, p13, p14);
*/

        } else {

            log_message_debug("Add compound element by name.");

            // Use compound count as index.
            set_compound_element_by_index(p0, p1, p2, p1,
                p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }
    }
}

/**
 * Adds the compound element.
 *
 * @param p0 the map
 * @param p1 the name
 * @param p2 the name size
 * @param p3 the reference
 * @param p4 the reference size
 */
void add_compound_element(void* p0, const void* p1, const void* p2, const void* p3, const void* p4) {

/*??
    // This element name will get destroyed (free) in remove_map_element.
    void* n = malloc(0);

    // Extend name with next free index.
    build_next_map_element_name(m->names, p1, n);
    set_map_element_with_name(p0, n, p3);

    int i = -1;

    get_map_size(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX);

    if (i != -1) {

        set_map_element_at_index(p0, (void*) &NAMES_COUNTS_ARRAY_INDEX, p1, p3);
    }
*/
}

/**
 * Removes the compound element by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 */
void remove_compound_element_by_index(void* p0, void* p1, void* p2, const void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* cs = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* cc = (int*) p1;

                if (*i >= 0) {

                    log_message_debug("Remove compound element by index.");

                    // The names, abstractions, models, details.
                    void** n = POINTER_NULL_POINTER;
                    void** nc = POINTER_NULL_POINTER;
                    void** ns = POINTER_NULL_POINTER;
                    void** a = POINTER_NULL_POINTER;
                    void** ac = POINTER_NULL_POINTER;
                    void** as = POINTER_NULL_POINTER;
                    void** m = POINTER_NULL_POINTER;
                    void** mc = POINTER_NULL_POINTER;
                    void** ms = POINTER_NULL_POINTER;
                    void** d = POINTER_NULL_POINTER;
                    void** dc = POINTER_NULL_POINTER;
                    void** ds = POINTER_NULL_POINTER;

                    // Get names, abstractions, models, details.
                    get_array_elements(p0, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) NAMES_SIZES_INDEX, (void*) &ns, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) &as, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
                    get_array_elements(p0, (void*) DETAILS_SIZES_INDEX, (void*) &ds, (void*) POINTER_ARRAY);

                    if (n != POINTER_NULL_POINTER) {

                        if (nc != POINTER_NULL_POINTER) {

                            if (ns != POINTER_NULL_POINTER) {

                                if (a != POINTER_NULL_POINTER) {

                                    if (ac != POINTER_NULL_POINTER) {

                                        if (as != POINTER_NULL_POINTER) {

                                            if (m != POINTER_NULL_POINTER) {

                                                if (mc != POINTER_NULL_POINTER) {

                                                    if (ms != POINTER_NULL_POINTER) {

                                                        if (d != POINTER_NULL_POINTER) {

                                                            if (dc != POINTER_NULL_POINTER) {

                                                                if (ds != POINTER_NULL_POINTER) {

                                                                    if (*i < *cc) {

                                                                        // Remove element name, abstraction, model, details.
                                                                        remove_array_elements(*n, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*nc, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ns, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*a, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ac, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*as, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*m, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*mc, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ms, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*d, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*dc, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ds, p1, p3, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

                                                                        // Decrement count.
                                                                        (*cc)--;

                                                                        //?? TODO: Decrease array size, if count is smaller than
                                                                        //?? half the current size.

                                                                    } else {

                                                                        log_message_debug("Could not remove compound element by index. The index exceeds the count.");
                                                                    }

                                                                } else {

                                                                    log_message_debug("Could not remove compound element by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_message_debug("Could not remove compound element by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_message_debug("Could not remove compound element by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not remove compound element by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not remove compound element by index. The models counts is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not remove compound element by index. The models is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not remove compound element by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not remove compound element by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_message_debug("Could not remove compound element by index. The abstractions is null.");
                                }

                            } else {

                                log_message_debug("Could not remove compound element by index. The names sizes is null.");
                            }

                        } else {

                            log_message_debug("Could not remove compound element by index. The names counts is null.");
                        }

                    } else {

                        log_message_debug("Could not remove compound element by index. The names is null.");
                    }

                } else {

                    log_message_debug("Could not remove compound element by index. The index is negativ.");
                }

            } else {

                log_message_debug("Could not remove compound element by index. The compound count is null.");
            }

        } else {

            log_message_debug("Could not remove compound element by index. The compound size is null.");
        }

    } else {

        log_message_debug("Could not remove compound element by index. The index is null.");
    }
}

/**
 * Removes the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the name
 * @param p4 the name count
 */
void remove_compound_element_by_name(void* p0, void* p1, void* p2,
    const void* p3, const void* p4) {

    // The separator index.
    int i = -1;

    get_array_elements_index(p3, p4, (void*) COMPOUND_ELEMENT_SEPARATOR, (void*) ONE_NUMBER, (void*) &i, (void*) CHARACTER_ARRAY);

    fprintf(stderr, "TEST remove_compound_element_by_name n: %s\n", (char*) p3);
    fprintf(stderr, "TEST remove_compound_element_by_name nc: %i\n", *((int*) p4));

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains elements which are compound models.

        if (p4 != NULL_POINTER) {

            int* nc = (int*) p4;

            if (p3 != NULL_POINTER) {

                log_message_debug("Remove compound element by hierarchical name.");

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (p3 + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Get index of element name.
                                // The separator index i is used as element name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the element name "hello" before the separator is likewise 5.
                                int index = -1;

                                get_compound_element_index(p0, p1, p3, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // The models.
                                    void** m = POINTER_NULL_POINTER;
                                    void** mc = POINTER_NULL_POINTER;
                                    void** ms = POINTER_NULL_POINTER;

                                    // Get models.
                                    get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                                    get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                                    get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);

                                    if (m != POINTER_NULL_POINTER) {

                                        if (mc != POINTER_NULL_POINTER) {

                                            if (ms != POINTER_NULL_POINTER) {

                                                // The element model.
                                                void** em = POINTER_NULL_POINTER;
                                                void** emc = POINTER_NULL_POINTER;
                                                void** ems = POINTER_NULL_POINTER;

                                                // Get element model.
                                                get_array_elements(*m, (void*) &index, (void*) &em, (void*) POINTER_ARRAY);
                                                get_array_elements(*mc, (void*) &index, (void*) &emc, (void*) POINTER_ARRAY);
                                                get_array_elements(*ms, (void*) &index, (void*) &ems, (void*) POINTER_ARRAY);

                                                if (em != POINTER_NULL_POINTER) {

                                                    if (emc != POINTER_NULL_POINTER) {

                                                        if (ems != POINTER_NULL_POINTER) {

                                                            //?? TODO:
                                                            //?? For now, the remaining name count is also used as
                                                            //?? remaining name size and such handed over twice.
                                                            //?? Later implementations may use UNICODE names so that
                                                            //?? the name count and size differ.

                                                            // Recursively continue to process along the hierarchical name.
                                                            remove_compound_element_by_name(*em, *emc, *ems, r, (void*) &rc);

                                                        } else {

                                                            log_message_debug("Could not remove compound element by name. The element model size is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not remove compound element by name. The element model count is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not remove compound element by name. The element model is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not remove compound element by name. The models sizes is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not remove compound element by name. The models counts is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not remove compound element by name. The models is null.");
                                    }

                                } else {

                                    log_message_debug("Could not remove compound element by name. An element with that name does not exist.");
                                }

                            } else {

                                log_message_debug("Could not remove compound element by name. The full name ends with a separator.");
                            }

                        } else {

                            log_message_debug("Could not remove compound element by name. The name starts with a separator.");
                        }

                    } else {

                        log_message_debug("Could not remove compound element by name. The separator index exceeds the name size.");
                    }

                } else {

                    log_message_debug("Could not remove compound element by name. The separator index is negative.");
                }

            } else {

                log_message_debug("Could not remove compound element by name. The name is null.");
            }

        } else {

            log_message_debug("Could not remove compound element by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the element name.
        // The given compound contains elements which are primitive models.

        // The index of the element name.
        int index = -1;

        get_compound_element_index(p0, p1, p3, p4, (void*) &index);

        if (index != -1) {

            log_message_debug("Remove compound element by name.");

            remove_compound_element_by_index(p0, p1, p2, (void*) &index);

        } else {

            log_message_debug("Could not remove compound element by name. An element with that name does not exist.");
        }
    }
}

/**
 * Gets the compound element by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the index
 * @param p3 the abstraction (Hand over as reference!)
 * @param p4 the abstraction count (Hand over as reference!)
 * @param p5 the abstraction size (Hand over as reference!)
 * @param p6 the model (Hand over as reference!)
 * @param p7 the model count (Hand over as reference!)
 * @param p8 the model size (Hand over as reference!)
 * @param p9 the details (Hand over as reference!)
 * @param p10 the details count (Hand over as reference!)
 * @param p11 the details size (Hand over as reference!)
 */
void get_compound_element_by_index(const void* p0, const void* p1, const void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* cc = (int*) p1;

            if (*i >= 0) {

                log_message_debug("Get compound element by index.");

                // The abstractions, models, details.
                void** a = POINTER_NULL_POINTER;
                void** ac = POINTER_NULL_POINTER;
                void** as = POINTER_NULL_POINTER;
                void** m = POINTER_NULL_POINTER;
                void** mc = POINTER_NULL_POINTER;
                void** ms = POINTER_NULL_POINTER;
                void** d = POINTER_NULL_POINTER;
                void** dc = POINTER_NULL_POINTER;
                void** ds = POINTER_NULL_POINTER;

                // Get abstractions, models, details.
                get_array_elements(p0, (void*) ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) &as, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) DETAILS_SIZES_INDEX, (void*) &ds, (void*) POINTER_ARRAY);

                if (a != POINTER_NULL_POINTER) {

                    if (ac != POINTER_NULL_POINTER) {

                        if (as != POINTER_NULL_POINTER) {

                            if (m != POINTER_NULL_POINTER) {

                                if (mc != POINTER_NULL_POINTER) {

                                    if (ms != POINTER_NULL_POINTER) {

                                        if (d != POINTER_NULL_POINTER) {

                                            if (dc != POINTER_NULL_POINTER) {

                                                if (ds != POINTER_NULL_POINTER) {

                                                    if (*i < *cc) {

                                                        // Get abstraction, model, details.
                                                        get_array_elements(*a, p2, p3, (void*) POINTER_ARRAY);
                                                        get_array_elements(*ac, p2, p4, (void*) POINTER_ARRAY);
                                                        get_array_elements(*as, p2, p5, (void*) POINTER_ARRAY);
                                                        get_array_elements(*m, p2, p6, (void*) POINTER_ARRAY);
                                                        get_array_elements(*mc, p2, p7, (void*) POINTER_ARRAY);
                                                        get_array_elements(*ms, p2, p8, (void*) POINTER_ARRAY);
                                                        get_array_elements(*d, p2, p9, (void*) POINTER_ARRAY);
                                                        get_array_elements(*dc, p2, p10, (void*) POINTER_ARRAY);
                                                        get_array_elements(*ds, p2, p11, (void*) POINTER_ARRAY);

                                                    } else {

                                                        log_message_debug("Could not get compound element by index. The index exceeds the count.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not get compound element by index. The details sizes is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not get compound element by index. The details counts is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not get compound element by index. The details is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not get compound element by index. The models sizes is null.");
                                    }

                                } else {

                                    log_message_debug("Could not get compound element by index. The models counts is null.");
                                }

                            } else {

                                log_message_debug("Could not get compound element by index. The models is null.");
                            }

                        } else {

                            log_message_debug("Could not get compound element by index. The abstractions sizes is null.");
                        }

                    } else {

                        log_message_debug("Could not get compound element by index. The abstractions counts is null.");
                    }

                } else {

                    log_message_debug("Could not get compound element by index. The abstractions is null.");
                }

            } else {

                log_message_debug("Could not get compound element by index. The index is negativ.");
            }

        } else {

            log_message_debug("Could not get compound element by index. The compound count is null.");
        }

    } else {

        log_message_debug("Could not get compound element by index. The index is null.");
    }
}

/**
 * Gets the compound element by name.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the name
 * @param p3 the name count
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count (Hand over as reference!)
 * @param p6 the abstraction size (Hand over as reference!)
 * @param p7 the model (Hand over as reference!)
 * @param p8 the model count (Hand over as reference!)
 * @param p9 the model size (Hand over as reference!)
 * @param p10 the details (Hand over as reference!)
 * @param p11 the details count (Hand over as reference!)
 * @param p12 the details size (Hand over as reference!)
 */
void get_compound_element_by_name(const void* p0, const void* p1,
    const void* p2, const void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    // The separator index.
    int i = -1;

    get_array_elements_index(p2, p3, (void*) COMPOUND_ELEMENT_SEPARATOR, (void*) ONE_NUMBER, (void*) &i, (void*) CHARACTER_ARRAY);

    fprintf(stderr, "TEST get_compound_element_by_name n: %s\n", (char*) p2);
    fprintf(stderr, "TEST get_compound_element_by_name nc: %i\n", *((int*) p3));

    if (i != -1) {

        // The separator has been found.
        // The full name is hierarchical.
        // The given compound contains elements which are compound models.

        if (p3 != NULL_POINTER) {

            int* nc = (int*) p3;

            if (p2 != NULL_POINTER) {

                log_message_debug("Get compound element by hierarchical name.");

                if (i >= 0) {

                    if (i < *nc) {

                        if (i != 0) {

                            if (i != (*nc - 1)) {

                                // The remaining name starts at the index after the separator.
                                // Example: "hello.test"
                                // The index of the separator is 5.
                                // The starting index of the remaining name "test" is 6 = 5 + 1.
                                void* r = (void*) (p2 + i + 1);

                                // The remaining name count is the full name count decreased
                                // by the separator index increased by one.
                                // Example: "hello.test"
                                // The full name count is 10.
                                // The separator index is 5.
                                // The count of the remaining name "test" is 4 = 10 - (5 + 1).
                                int rc = *nc - (i + 1);

                                // Get index of element name.
                                // The separator index i is used as element name count.
                                // Example: "hello.test"
                                // The index i of the separator is 5.
                                // The count of the element name "hello" before the separator is likewise 5.
                                int index = -1;

                                get_compound_element_index(p0, p1, p2, (void*) &i, (void*) &index);

                                if (index != -1) {

                                    // The models.
                                    void** m = POINTER_NULL_POINTER;
                                    void** mc = POINTER_NULL_POINTER;
                                    void** ms = POINTER_NULL_POINTER;

                                    // Get models.
                                    get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
                                    get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
                                    get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);

                                    if (m != POINTER_NULL_POINTER) {

                                        if (mc != POINTER_NULL_POINTER) {

                                            if (ms != POINTER_NULL_POINTER) {

                                                // The element model.
                                                void** em = POINTER_NULL_POINTER;
                                                void** emc = POINTER_NULL_POINTER;
                                                void** ems = POINTER_NULL_POINTER;

                                                // Get element model.
                                                get_array_elements(*m, (void*) &index, (void*) &em, (void*) POINTER_ARRAY);
                                                get_array_elements(*mc, (void*) &index, (void*) &emc, (void*) POINTER_ARRAY);
                                                get_array_elements(*ms, (void*) &index, (void*) &ems, (void*) POINTER_ARRAY);

                                                if (em != POINTER_NULL_POINTER) {

                                                    if (emc != POINTER_NULL_POINTER) {

                                                        if (ems != POINTER_NULL_POINTER) {

                                                            //?? TODO:
                                                            //?? For now, the remaining name count is also used as
                                                            //?? remaining name size and such handed over twice.
                                                            //?? Later implementations may use UNICODE names so that
                                                            //?? the name count and size differ.

                                                            // Recursively continue to process along the hierarchical name.
                                                            get_compound_element_by_name(*em, *emc, r, (void*) &rc,
                                                                p4, p5, p6, p7, p8, p9, p10, p11, p12);

                                                        } else {

                                                            log_message_debug("Could not get compound element by name. The element model size is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not get compound element by name. The element model count is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not get compound element by name. The element model is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not get compound element by name. The models sizes is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not get compound element by name. The models counts is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not get compound element by name. The models is null.");
                                    }

                                } else {

                                    log_message_debug("Could not get compound element by name. An element with that name does not exist.");
                                }

                            } else {

                                log_message_debug("Could not get compound element by name. The name ends with a separator.");
                            }

                        } else {

                            log_message_debug("Could not get compound element by name. The name starts with a separator.");
                        }

                    } else {

                        log_message_debug("Could not get compound element by name. The separator index exceeds the name size.");
                    }

                } else {

                    log_message_debug("Could not get compound element by name. The separator index is negative.");
                }

            } else {

                log_message_debug("Could not get compound element by name. The name is null.");
            }

        } else {

            log_message_debug("Could not get compound element by name. The name size is null.");
        }

    } else {

        // The separator could not be found.
        // The full name is not hierarchical and represents the element name.
        // The given compound contains elements which are primitive models.

        // The index of the element name.
        int index = -1;

        get_compound_element_index(p0, p1, p2, p3, (void*) &index);

        if (index != -1) {

            log_message_debug("Get compound element by name.");

            get_compound_element_by_index(p0, p1, (void*) &index,
                p4, p5, p6, p7, p8, p9, p10, p11, p12);

        } else {

            log_message_debug("Could not get compound element by name. An element with that name does not exist.");
        }
    }
}

/**
 * Gets the compound element name by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the index
 * @param p3 the name (Hand over as reference!)
 * @param p4 the name count (Hand over as reference!)
 * @param p5 the name size (Hand over as reference!)
 */
void get_compound_element_name_by_index(const void* p0, const void* p1,
    const void* p2, void* p3, void* p4, void* p5) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* cc = (int*) p1;

            if (*i >= 0) {

                log_message_debug("Get compound element name by index.");

                // The names.
                void** n = POINTER_NULL_POINTER;
                void** nc = POINTER_NULL_POINTER;
                void** ns = POINTER_NULL_POINTER;

                // Get names.
                get_array_elements(p0, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) NAMES_SIZES_INDEX, (void*) &ns, (void*) POINTER_ARRAY);

                if (n != POINTER_NULL_POINTER) {

                    if (nc != POINTER_NULL_POINTER) {

                        if (ns != POINTER_NULL_POINTER) {

                            if (*i < *cc) {

                                // Get element name.
                                get_array_elements(*n, p2, p3, (void*) POINTER_ARRAY);
                                get_array_elements(*nc, p2, p4, (void*) POINTER_ARRAY);
                                get_array_elements(*ns, p2, p5, (void*) POINTER_ARRAY);

                            } else {

                                log_message_debug("Could not get compound element name by index. The index exceeds the count.");
                            }

                        } else {

                            log_message_debug("Could not get compound element name by index. The names sizes is null.");
                        }

                    } else {

                        log_message_debug("Could not get compound element name by index. The names counts is null.");
                    }

                } else {

                    log_message_debug("Could not get compound element name by index. The names is null.");
                }

            } else {

                log_message_debug("Could not get compound element name by index. The index is negativ.");
            }

        } else {

            log_message_debug("Could not get compound element name by index. The compound count is null.");
        }

    } else {

        log_message_debug("Could not get compound element name by index. The index is null.");
    }
}

/**
 * Gets the compound element by encapsulated name.
 *
 * At first, the element name needs to be determined within the parameters.
 * Only then, it can be used to determine the actual compound element.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the name
 * @param p3 the name count
 * @param p4 the abstraction (Hand over as reference!)
 * @param p5 the abstraction count (Hand over as reference!)
 * @param p6 the abstraction size (Hand over as reference!)
 * @param p7 the model (Hand over as reference!)
 * @param p8 the model count (Hand over as reference!)
 * @param p9 the model size (Hand over as reference!)
 * @param p10 the details (Hand over as reference!)
 * @param p11 the details count (Hand over as reference!)
 * @param p12 the details size (Hand over as reference!)
 * @param p13 the knowledge
 * @param p14 the knowledge count
 */
void get_compound_element_by_encapsulated_name(const void* p0, const void* p1,
    const void* p2, const void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12,
    const void* p13, const void* p14) {

    log_message_debug("Get compound element by encapsulated name.");

    // The abstraction, model, details.
    void** a = POINTER_NULL_POINTER;
    void** ac = POINTER_NULL_POINTER;
    void** as = POINTER_NULL_POINTER;
    void** m = POINTER_NULL_POINTER;
    void** mc = POINTER_NULL_POINTER;
    void** ms = POINTER_NULL_POINTER;
    void** d = POINTER_NULL_POINTER;
    void** dc = POINTER_NULL_POINTER;
    void** ds = POINTER_NULL_POINTER;

    // Get knowledge element name.
    get_compound_element_by_name(p0, p1,
        p2, p3,
        (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms,
        (void*) &d, (void*) &dc, (void*) &ds);

    if (m != POINTER_NULL_POINTER) {

        if (mc != POINTER_NULL_POINTER) {

            //
            // CAUTION!
            // The element below must be determined within the knowledge model,
            // NOT within the logic operation's parameters as before!
            //
            // The abstraction of an encapsulated name must always be "string".
            // The details are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge element to be retrieved. This
            // hierarchical name is finally used to determine the actual element.
            //
            // Example of a hierarchical name:
            // application.communication.partners.hostname.address
            //

    fprintf(stderr, "TEST get_compound_element_by_encapsulated_name m: %s\n", (char*) *m);
    fprintf(stderr, "TEST get_compound_element_by_encapsulated_name mc: %i\n", *((int*) *mc));

            // Get knowledge element.
            get_compound_element_by_name(p13, p14, *m, *mc,
                p4, p5, p6, p7, p8, p9, p10, p11, p12);

        } else {

            log_message_debug("Could not get compound element by encapsulated name. The knowledge element name count is null.");
        }

    } else {

        log_message_debug("Could not get compound element by encapsulated name. The knowledge element name is null.");
    }
}

/* COMPOUND_ACCESSOR_SOURCE */
#endif
