/*
 * $RCSfile: compound_accessor.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
 *
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
 * @version $Revision: 1.20 $ $Date: 2006-06-02 06:03:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ACCESSOR_SOURCE
#define COMPOUND_ACCESSOR_SOURCE

#include "../../globals/constants/abstraction_constants.c"
#include "../../globals/constants/cybol_constants.c"
#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

//
// Forward declarations.
//

/**
 * Parses the byte stream according to the given document type
 * and creates a document model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void parse(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// Hierarchical name handling.
//

/**
 * Gets the compound element name without prefix.
 *
 * CAUTION! Only call this procedure if a prefix was found,
 * that is the full name is not empty.
 * Otherwise, pointers will be set pointing to wrong places.
 *
 * @param p0 the element name without prefix (Hand over as reference!)
 * @param p1 the element name count (Hand over as reference!)
 * @param p2 the full name
 * @param p3 the full name count
 * @param p4 the separator count
 */
void get_compound_element_name_without_prefix(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            int* fc = (int*) p3;

            if (p2 != NULL_POINTER) {

                if (p1 != NULL_POINTER) {

                    int* ec = (int*) p1;

                    if (p0 != NULL_POINTER) {

                        void** e = (void**) p0;

                        log_message_debug("Get compound element name without prefix.");

                        // Let the name begin behind the separator element.
                        // Example:
                        // .resmedicinae.tui.menu.entry#background
                        // is now only:
                        // resmedicinae.tui.menu.entry#background
                        *e = p2 + *sc;

                        // Reduce the name's length by separator element in turn.
                        *ec = *fc - *sc;

                    } else {

                        log_message_debug("Could not get compound element name without prefix. The element name is null.");
                    }

                } else {

                    log_message_debug("Could not get compound element name without prefix. The element name count is null.");
                }

            } else {

                log_message_debug("Could not get compound element name without prefix. The full name is null.");
            }

        } else {

            log_message_debug("Could not get compound element name without prefix. The full name count is null.");
        }

    } else {

        log_message_debug("Could not get compound element name without prefix. The separator count is null.");
    }
}

/**
 * Gets the compound element name length.
 *
 * @param p0 the name
 * @param p1 the name count
 * @param p2 the name length (Hand over as reference!)
 */
void get_compound_element_name_length(void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* l = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* nc = (int*) p1;

            log_message_debug("Get compound element name length.");

            // The part separator index.
            int p = -1;
            // The meta separator index.
            int m = -1;

            get_array_elements_index(p0, p1, (void*) COMPOUND_PART_SEPARATOR, (void*) COMPOUND_PART_SEPARATOR_COUNT, (void*) &p, (void*) CHARACTER_ARRAY);
            get_array_elements_index(p0, p1, (void*) COMPOUND_META_SEPARATOR, (void*) COMPOUND_META_SEPARATOR_COUNT, (void*) &m, (void*) CHARACTER_ARRAY);

            if ((p >= 0) && (m == -1)) {

                // The name contains one or more part separator(s).
                // The next separator is a part separator.
                // Its index marks the end of an element name.
                *l = p;

            } else if ((p == -1) && (m >= 0)) {

                // The name contains one or more meta separator(s).
                // The next separator is a meta separator.
                // Its index marks the end of an element name.
                *l = m;

            } else if ((p >= 0) && (m >= 0)) {

                // The name contains part- as well as meta separator(s).

                if (p < m) {

                    // The next separator is a part separator.
                    // Its index marks the end of an element name.
                    *l = p;

                } else {

                    // The next separator is a meta separator.
                    // Its index marks the end of an element name.
                    *l = m;
                }

            } else {

                // The name does NOT contain any separators.
                // Its count (length) marks the end of an element name.
                *l = *nc;
            }

        } else {

            log_message_debug("Could not get compound element name length. The name count is null.");
        }

    } else {

        log_message_debug("Could not get compound element name length. The separator index is null.");
    }
}

/**
 * Gets the compound element name and remaining name.
 *
 * @param p0 the full name
 * @param p1 the full name count
 * @param p2 the element name (Hand over as reference!)
 * @param p3 the element name count (Hand over as reference!)
 * @param p4 the remaining name (Hand over as reference!)
 * @param p5 the remaining name count (Hand over as reference!)
 * @param p6 the meta hierarchy flag with the following meanings:
 *     -1: not a compound knowledge hierarchy
 *     0: part hierarchy
 *     1: meta hierarchy
 */
void get_compound_element_name_and_remaining_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != NULL_POINTER) {

        int* f = (int*) p6;

        if (p5 != NULL_POINTER) {

            int* rc = (int*) p5;

            if (p4 != NULL_POINTER) {

                void** r = (void**) p4;

                if (p3 != NULL_POINTER) {

                    int* ec = (int*) p3;

                    if (p2 != NULL_POINTER) {

                        void** e = (void**) p2;

                        if (p1 != NULL_POINTER) {

                            int* fc = (int*) p1;

                            if (p0 != NULL_POINTER) {

                                log_message_debug("Get compound element name and remaining name.");

                                // Check if full name starts with either a
                                // part separator "." or a meta separator "#".
                                // Examples:
                                // .resmedicinae.tui.menu.entry#background
                                // #system_properties.colour

                                // The part separator index.
                                int p = -1;
                                // The meta separator index.
                                int m = -1;

                                // Get position of part separator.
                                get_array_elements_index(p0, p1, (void*) COMPOUND_PART_SEPARATOR, (void*) COMPOUND_PART_SEPARATOR_COUNT, (void*) &p, (void*) CHARACTER_ARRAY);
                                // Get position of meta separator.
                                get_array_elements_index(p0, p1, (void*) COMPOUND_META_SEPARATOR, (void*) COMPOUND_META_SEPARATOR_COUNT, (void*) &m, (void*) CHARACTER_ARRAY);

                                // The name without prefix.
                                void* n = NULL_POINTER;
                                int nc = 0;

                                if (p == 0) {

                                    // The full name starts with a part separator ".".

                                    // Set meta hierarchy flag to zero, because this is a part element.
                                    *f = 0;

                                    // Get compound element name without prefix.
                                    // Example:
                                    // .resmedicinae.tui.menu.entry#background
                                    // is now only:
                                    // resmedicinae.tui.menu.entry#background
                                    // CAUTION! Only call this procedure if a prefix was found!
                                    get_compound_element_name_without_prefix((void*) &n, (void*) &nc, p0, p1, (void*) COMPOUND_PART_SEPARATOR_COUNT);

    fprintf(stderr, "TEST part f %i\n", *f);

                                } else if (m == 0) {

                                    // The full name starts with a meta separator "#".

                                    // Set meta hierarchy flag to one, because this is a meta element.
                                    *f = 1;

                                    // Get compound element name without prefix.
                                    // Example:
                                    // .resmedicinae.tui.menu.entry#background
                                    // is now only:
                                    // resmedicinae.tui.menu.entry#background
                                    // CAUTION! Only call this procedure if a prefix was found!
                                    get_compound_element_name_without_prefix((void*) &n, (void*) &nc, p0, p1, (void*) COMPOUND_META_SEPARATOR_COUNT);

    fprintf(stderr, "TEST meta f %i\n", *f);
                                }

                                if ((*f == 0) || (*f == 1)) {

                                    // A part separator "." or meta separator "#" has been found.

                                    // The compound element name length.
                                    int l = 0;

                                    get_compound_element_name_length(n, (void*) &nc, (void*) &l);

    fprintf(stderr, "TEST length %i\n", l);

                                    // Determine element name.
                                    // It equals the name without prefix.
                                    *e = n;

                                    // Determine element name count.
                                    // It equals the element name length determined above.
                                    *ec = l;

                                    // Determine remaining name.
                                    // It starts with the separator.
                                    // Example: "hello.test"
                                    // The index of the separator is 5.
                                    // The starting index of the remaining name ".test" is likewise 5.
                                    *r = (void*) (n + l);

                                    // The remaining name count is the full name count
                                    // decreased by the separator index.
                                    // Example: "hello.test"
                                    // The full name count is 10.
                                    // The separator index is 5.
                                    // The count of the remaining name ".test" is 10 - 5 = 5.
                                    *rc = nc - l;

                                } else {

                                    // No part separator "." or meta separator "#" has been found.

/*??
                                    log_message_debug("Could not get the compound element name and remaining name. The hierarchical name does not start with a prefix (part separator '.' or meta separator '#')." \
                                        "This does not necessarily have to be an error, since property (meta) names are given without prefix. Therefore, the element name is set to the full name now.");
*/

                                    // Set element name to full name.
                                    *e = p0;

                                    // Set element name count to full name count.
                                    *ec = *fc;
                                }

                            } else {

                                log_message_debug("Could not get the compound element name and remaining name. The full name is null.");
                            }

                        } else {

                            log_message_debug("Could not get the compound element name and remaining name. The full name count is null.");
                        }

                    } else {

                        log_message_debug("Could not get the compound element name and remaining name. The element name is null.");
                    }

                } else {

                    log_message_debug("Could not get the compound element name and remaining name. The element name count is null.");
                }

            } else {

                log_message_debug("Could not get the compound element name and remaining name. The remaining name is null.");
            }

        } else {

            log_message_debug("Could not get the compound element name and remaining name. The remaining name count is null.");
        }

    } else {

        log_message_debug("Could not get the compound element name and remaining name. The meta hierarchy flag is null.");
    }
}

/**
 * Gets the compound part element.
 *
 * @param p0 the compound
 * @param p1 the index
 * @param p2 the part element (Hand over as reference!)
 * @param p3 the part element count (Hand over as reference!)
 * @param p4 the part element size (Hand over as reference!)
 */
void get_compound_part_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Get compound part element.");

    // The models.
    void** m = &NULL_POINTER;
    void** mc = &NULL_POINTER;
    void** ms = &NULL_POINTER;

    // Get models.
    get_array_elements(p0, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);

    if (*m != NULL_POINTER) {

        if (*mc != NULL_POINTER) {

            if (*ms != NULL_POINTER) {

                // Get part element model.
                get_array_elements(*m, p1, p2, (void*) POINTER_ARRAY);
                get_array_elements(*mc, p1, p3, (void*) POINTER_ARRAY);
                get_array_elements(*ms, p1, p4, (void*) POINTER_ARRAY);

            } else {

                log_message_debug("Could not get compound part element. The models sizes is null.");
            }

        } else {

            log_message_debug("Could not get compound part element. The models counts is null.");
        }

    } else {

        log_message_debug("Could not get compound part element. The models is null.");
    }
}

/**
 * Gets the compound meta element.
 *
 * @param p0 the compound
 * @param p1 the index
 * @param p2 the meta element (Hand over as reference!)
 * @param p3 the meta element count (Hand over as reference!)
 * @param p4 the meta element size (Hand over as reference!)
 */
void get_compound_meta_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Get compound meta element.");

    // The details.
    void** d = &NULL_POINTER;
    void** dc = &NULL_POINTER;
    void** ds = &NULL_POINTER;

    // Get details.
    get_array_elements(p0, (void*) DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
    get_array_elements(p0, (void*) DETAILS_SIZES_INDEX, (void*) &ds, (void*) POINTER_ARRAY);

    if (*d != NULL_POINTER) {

        if (*dc != NULL_POINTER) {

            if (*ds != NULL_POINTER) {

                // Get meta element model.
                get_array_elements(*d, p1, p2, (void*) POINTER_ARRAY);
                get_array_elements(*dc, p1, p3, (void*) POINTER_ARRAY);
                get_array_elements(*ds, p1, p4, (void*) POINTER_ARRAY);

            } else {

                log_message_debug("Could not get compound meta element. The details sizes is null.");
            }

        } else {

            log_message_debug("Could not get compound meta element. The details counts is null.");
        }

    } else {

        log_message_debug("Could not get compound meta element. The details is null.");
    }
}

/**
 * Gets the compound element index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the element name
 * @param p3 the element name count
 * @param p4 the index (Hand over as reference!)
 */
void get_compound_element_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* i = (int*) p4;

        if (p1 != NULL_POINTER) {

            int* cc = (int*) p1;

            log_message_debug("Get compound element index.");

            // The element names.
            void** n = &NULL_POINTER;
            void** nc = &NULL_POINTER;

            // Get element names.
            get_array_elements(p0, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
            get_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);

            if (*n != NULL_POINTER) {

                if (*nc != NULL_POINTER) {

                    // The loop variable.
                    int j = 0;
                    // The name.
                    void** n1 = &NULL_POINTER;
                    void** nc1 = &NULL_POINTER;
                    // The comparison result.
                    int r = 0;

                    while (1) {

                        if (j >= *cc) {

                            break;
                        }

                        // Get element name.
                        get_array_elements(*n, (void*) &j, (void*) &n1, (void*) POINTER_ARRAY);
                        get_array_elements(*nc, (void*) &j, (void*) &nc1, (void*) POINTER_ARRAY);

                        if (*n1 != NULL_POINTER) {

                            if (*nc1 != NULL_POINTER) {

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
                        n1 = &NULL_POINTER;
                        nc1 = &NULL_POINTER;

                        j++;
                    }

                } else {

                    log_message_debug("Could not get compound element index. The part names counts is null.");
                }

            } else {

                log_message_debug("Could not get compound element index. The part names is null.");
            }

        } else {

            log_message_debug("Could not get compound element index. The compound count is null.");
        }

    } else {

        log_message_debug("Could not get compound element index. The index is null.");
    }
}

//
// Set.
//

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
void set_compound_element_by_index(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12,
    void* p13, void* p14, void* p15) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* cs = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* cc = (int*) p1;

                if (*i >= 0) {

                    log_message_debug("Set compound part by index.");

                    // The names, abstractions, models, details.
                    void** n = &NULL_POINTER;
                    void** nc = &NULL_POINTER;
                    void** ns = &NULL_POINTER;
                    void** a = &NULL_POINTER;
                    void** ac = &NULL_POINTER;
                    void** as = &NULL_POINTER;
                    void** m = &NULL_POINTER;
                    void** mc = &NULL_POINTER;
                    void** ms = &NULL_POINTER;
                    void** d = &NULL_POINTER;
                    void** dc = &NULL_POINTER;
                    void** ds = &NULL_POINTER;

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

                    if (*n != NULL_POINTER) {

                        if (*nc != NULL_POINTER) {

                            if (*ns != NULL_POINTER) {

                                if (*a != NULL_POINTER) {

                                    if (*ac != NULL_POINTER) {

                                        if (*as != NULL_POINTER) {

                                            if (*m != NULL_POINTER) {

                                                if (*mc != NULL_POINTER) {

                                                    if (*ms != NULL_POINTER) {

                                                        if (*d != NULL_POINTER) {

                                                            if (*dc != NULL_POINTER) {

                                                                if (*ds != NULL_POINTER) {

                                                                    if (*i == *cs) {

                                                                        // Increase size.
                                                                        *cs = (*cs * *COMPOUND_REALLOCATE_FACTOR) + 1;

                                                                        // Reallocate names, abstractions, models, details.
                                                                        reallocate_array(n, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(nc, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(ns, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(a, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(ac, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(as, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(m, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(mc, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(ms, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(d, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(dc, p1, p2, (void*) POINTER_ARRAY);
                                                                        reallocate_array(ds, p1, p2, (void*) POINTER_ARRAY);

                                                                        // Set new array reference.
                                                                        // CAUTION! If an array gets reallocated, a new array is
                                                                        // created and the contents of the old array gets copied.
                                                                        // Therefore, the new array reference needs to be set.
                                                                        // The old array gets destroyed automatically by reallocate.
                                                                        set_array_elements(p0, (void*) NAMES_INDEX, (void*) n, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) nc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) NAMES_SIZES_INDEX, (void*) ns, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_INDEX, (void*) a, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) ac, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) as, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) MODELS_INDEX, (void*) m, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) MODELS_COUNTS_INDEX, (void*) mc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) MODELS_SIZES_INDEX, (void*) ms, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) DETAILS_INDEX, (void*) d, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) DETAILS_COUNTS_INDEX, (void*) dc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(p0, (void*) DETAILS_SIZES_INDEX, (void*) ds, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                    }

                                                                    if (*i < *cs) {


                                                                        // Set name, abstraction, model, details.
                                                                        set_array_elements(*n, p3, (void*) &p4, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*nc, p3, (void*) &p5, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ns, p3, (void*) &p6, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*a, p3, (void*) &p7, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ac, p3, (void*) &p8, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*as, p3, (void*) &p9, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*m, p3, (void*) &p10, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*mc, p3, (void*) &p11, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ms, p3, (void*) &p12, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*d, p3, (void*) &p13, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*dc, p3, (void*) &p14, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        set_array_elements(*ds, p3, (void*) &p15, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

                                                                        // Increment count.
                                                                        (*cc)++;

                                                                    } else {

                                                                        log_message_debug("Could not set compound part by index. The index exceeds the size.");
                                                                    }

                                                                } else {

                                                                    log_message_debug("Could not set compound part by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_message_debug("Could not set compound part by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_message_debug("Could not set compound part by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not set compound part by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not set compound part by index. The models counts is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not set compound part by index. The models is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not set compound part by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not set compound part by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_message_debug("Could not set compound part by index. The abstractions is null.");
                                }

                            } else {

                                log_message_debug("Could not set compound part by index. The names sizes is null.");
                            }

                        } else {

                            log_message_debug("Could not set compound part by index. The names counts is null.");
                        }

                    } else {

                        log_message_debug("Could not set compound part by index. The names is null.");
                    }

                } else {

                    log_message_debug("Could not set compound part by index. The index is negative.");
                }

            } else {

                log_message_debug("Could not set compound part by index. The compound count is null.");
            }

        } else {

            log_message_debug("Could not set compound part by index. The compound sizes is null.");
        }

    } else {

        log_message_debug("Could not set compound part by index. The index is null.");
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
    void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14) {

    log_message_debug("Set compound element by name.");
    log_message_debug((char*) p3);

    // The element name.
    void* e = NULL_POINTER;
    int ec = 0;
    int es = 0;
    // The remaining name.
    void* r = NULL_POINTER;
    int rc = 0;
    int rs = 0;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = -1;
    // The element name index.
    int i = -1;

    get_compound_element_name_and_remaining_name(p3, p4, (void*) &e, (void*) &ec, (void*) &r, (void*) &rc, (void*) &f);
    get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

    if (i >= 0) {

        if (rc > 0) {

            // A remaining name exists.
            // The compound element hierarchy is processed further.

            // The element model or details.
            void** md = &NULL_POINTER;
            void** mdc = &NULL_POINTER;
            void** mds = &NULL_POINTER;

            if (f == 0) {

                // Get part element.
                get_compound_part_element(p0, (void*) &i, (void*) &md, (void*) &mdc, (void*) &mds);

            } else if (f == 1) {

                // Get meta element.
                get_compound_meta_element(p0, (void*) &i, (void*) &md, (void*) &mdc, (void*) &mds);

            } else {

                log_message_debug("Could not get compound element by name. The name does not represent a compound knowledge hierarchy.");
            }

            // Recursively continue to process along the hierarchical name.
            rs = rc;
            set_compound_element_by_name(*md, *mdc, *mds, r, (void*) &rc, (void*) &rs, p6, p7, p8, p9, p10, p11, p12, p13, p14);

        } else {

            // No remaining name exists. A separator could NOT be found.
            // The name is NOT hierarchical and represents an element name directly.
            // The given compound contains elements which are primitive models.

/*??
            //?? TODO:
            //?? - Do NOT just replace existing parts; otherwise the reference
            //??   to them is lost and they can not be destroyed properly.
            //?? - Allow replacement for primitive types (integer, double) that
            //??   do not have to be destroyed!
            //?? - Check the abstraction of the model to be set:
            //??   If it is compound, then do NOT replace --> error message; otherwise DO replace!

            // Replace already existing element.
            set_compound_element_by_index(p0, p1, p2, (void*) &i,
                p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
*/
        }

    } else {

        // Could not get compound element by name. An element with that name does not exist.
        // Therefore, add compound element by name.
        log_message_debug((char*) e);

        // CAUTION! Use compound count as index for adding new elements.
        // CAUTION! Do NOT use e, ec and es as name parameters!
        // These were created only locally in this procedure and
        // will thus be destroyed when the procedure is left.
        // DO USE the name, name count and name size that were
        // handed over as parameters to this procedure!
        // They were allocated by a translator while parsing CYBOL files.
        set_compound_element_by_index(p0, p1, p2, p1,
            p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    }
}

//
// Remove.
//

/**
 * Removes the compound element by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the compound size
 * @param p3 the index
 */
void remove_compound_element_by_index(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != NULL_POINTER) {

        int* i = (int*) p3;

        if (p2 != NULL_POINTER) {

            int* cs = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* cc = (int*) p1;

                if (*i >= 0) {

                    log_message_debug("Remove compound part by index.");

                    // The names, abstractions, models, details.
                    void** n = &NULL_POINTER;
                    void** nc = &NULL_POINTER;
                    void** ns = &NULL_POINTER;
                    void** a = &NULL_POINTER;
                    void** ac = &NULL_POINTER;
                    void** as = &NULL_POINTER;
                    void** m = &NULL_POINTER;
                    void** mc = &NULL_POINTER;
                    void** ms = &NULL_POINTER;
                    void** d = &NULL_POINTER;
                    void** dc = &NULL_POINTER;
                    void** ds = &NULL_POINTER;

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

                    if (*n != NULL_POINTER) {

                        if (*nc != NULL_POINTER) {

                            if (*ns != NULL_POINTER) {

                                if (*a != NULL_POINTER) {

                                    if (*ac != NULL_POINTER) {

                                        if (*as != NULL_POINTER) {

                                            if (*m != NULL_POINTER) {

                                                if (*mc != NULL_POINTER) {

                                                    if (*ms != NULL_POINTER) {

                                                        if (*d != NULL_POINTER) {

                                                            if (*dc != NULL_POINTER) {

                                                                if (*ds != NULL_POINTER) {

                                                                    if (*i < *cc) {

                                                                        // Remove part name, abstraction, model, details.
                                                                        remove_array_elements(*n, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*nc, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ns, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*a, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ac, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*as, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*m, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*mc, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ms, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*d, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*dc, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
                                                                        remove_array_elements(*ds, p1, p3, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

                                                                        // Decrement count.
                                                                        (*cc)--;

                                                                        //?? TODO: Decrease array size, if count is smaller than
                                                                        //?? half the current size.

                                                                    } else {

                                                                        log_message_debug("Could not remove compound part by index. The index exceeds the count.");
                                                                    }

                                                                } else {

                                                                    log_message_debug("Could not remove compound part by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_message_debug("Could not remove compound part by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_message_debug("Could not remove compound part by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_message_debug("Could not remove compound part by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not remove compound part by index. The models counts is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not remove compound part by index. The models is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not remove compound part by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not remove compound part by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_message_debug("Could not remove compound part by index. The abstractions is null.");
                                }

                            } else {

                                log_message_debug("Could not remove compound part by index. The names sizes is null.");
                            }

                        } else {

                            log_message_debug("Could not remove compound part by index. The names counts is null.");
                        }

                    } else {

                        log_message_debug("Could not remove compound part by index. The names is null.");
                    }

                } else {

                    log_message_debug("Could not remove compound part by index. The index is negativ.");
                }

            } else {

                log_message_debug("Could not remove compound part by index. The compound count is null.");
            }

        } else {

            log_message_debug("Could not remove compound part by index. The compound size is null.");
        }

    } else {

        log_message_debug("Could not remove compound part by index. The index is null.");
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
void get_compound_element_name_by_index(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* cc = (int*) p1;

            if (*i >= 0) {

                log_message_debug("Get compound element name by index.");

                // The names.
                void** n = &NULL_POINTER;
                void** nc = &NULL_POINTER;
                void** ns = &NULL_POINTER;

                // Get names.
                get_array_elements(p0, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);
                get_array_elements(p0, (void*) NAMES_SIZES_INDEX, (void*) &ns, (void*) POINTER_ARRAY);

                if (*n != NULL_POINTER) {

                    if (*nc != NULL_POINTER) {

                        if (*ns != NULL_POINTER) {

                            if (*i < *cc) {

                                // Get part name.
                                get_array_elements(*n, p2, p3, (void*) POINTER_ARRAY);
                                get_array_elements(*nc, p2, p4, (void*) POINTER_ARRAY);
                                get_array_elements(*ns, p2, p5, (void*) POINTER_ARRAY);

                            } else {

                                log_message_debug("Could not get compound part name by index. The index exceeds the count.");
                            }

                        } else {

                            log_message_debug("Could not get compound part name by index. The names sizes is null.");
                        }

                    } else {

                        log_message_debug("Could not get compound part name by index. The names counts is null.");
                    }

                } else {

                    log_message_debug("Could not get compound part name by index. The names is null.");
                }

            } else {

                log_message_debug("Could not get compound part name by index. The index is negativ.");
            }

        } else {

            log_message_debug("Could not get compound part name by index. The compound count is null.");
        }

    } else {

        log_message_debug("Could not get compound part name by index. The index is null.");
    }
}

/**
 * Reindex those parts of the compound, which represent a common list.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the base name equal to all parts of the compound representing a list
 * @param p3 the base name count
 */
void reindex_compound_elements_forming_list(void* p0, void* p1, void* p2, int* p3) {

    if ((p0 != NULL_POINTER) && (p1 != NULL_POINTER)
        && (p2 != NULL_POINTER) && (p3 != NULL_POINTER)) {

        log_message_debug("Reindex compound elements representing a list.");

        // The compound counter.
        int cc = 0;
        // The index counter.
        int ic = 0;

        // The compund part name.
        void** n = &NULL_POINTER;
        void** nc = &NULL_POINTER;
        void** ns = &NULL_POINTER;

        // The prefix equal to all parts of the compound representing a list.
        char* p = NULL_POINTER;
        int pc = *((int*) p3) + *LIST_SEPARATOR_COUNT;

        // Allocate prefix.
        allocate_array((void*) &p, (void*) &pc, (void*) CHARACTER_ARRAY);

        // Set prefix as concatenation of base name and list separator.
        set_array_elements(p, (void*) NUMBER_0_INTEGER, p2, p3, (void*) CHARACTER_ARRAY);
        set_array_elements(p, p3, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, (void*) CHARACTER_ARRAY);

        //create integer model for the index
        void* indexstr = NULL_POINTER;
        int indexstr_count = 0;
        int indexstr_size = 10;

        allocate_array((void*) &indexstr, (void*) &indexstr_size, (void*) CHARACTER_ARRAY);

        // The comparison result.
        int r = 0;

        while (1) {

            if (cc >= *((int*) p1)) {

                break;
            }

            get_compound_element_name_by_index(p0, p1, &cc, &n, &nc, &ns);

            if ((*n != NULL_POINTER) && (*nc != NULL_POINTER) && (*ns != NULL_POINTER)) {

                if (*((int*) *nc) > pc) {

                    // Reset comparison result.
                    r = 0;

                    compare_arrays(p, &pc, *n, &pc, &r, CHARACTER_ARRAY);

                    if (r == 1) {

                        // The beginning of the two arrays are identical.
                        // The compound part belongs to the list.

                        *((int*) *nc) = 0;

                        //parse the basisname
                        parse(n, *nc, *ns, p2, p3, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                        //parse the list separator
                        parse(n, *nc, *ns, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                        //parse the index
                        indexstr_count = snprintf(indexstr, indexstr_size, "%i", ic);
                        parse(n, *nc, *ns, indexstr, &indexstr_count, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                        ic = ic + 1;
                    }
                }
            }

            cc++;
        }

        // Deallocate prefix.
        deallocate_array((void*) &p, (void*) &pc, (void*) CHARACTER_ARRAY);
        // Deallocate index string.
        deallocate_array((void*) &indexstr, (void*) &indexstr_count, (void*) CHARACTER_ARRAY);
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
void remove_compound_element_by_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Remove compound element by name.");

    // The element name.
    void* e = NULL_POINTER;
    int ec = 0;
    // The remaining name.
    void* r = NULL_POINTER;
    int rc = 0;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = -1;
    // The element name index.
    int i = -1;

    get_compound_element_name_and_remaining_name(p3, p4, (void*) &e, (void*) &ec, (void*) &r, (void*) &rc, (void*) &f);
    get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

    if (i >= 0) {

        if (rc > 0) {

            // A remaining name exists.
            // The compound element hierarchy is processed further.

            // The element model or details.
            void** md = &NULL_POINTER;
            void** mdc = &NULL_POINTER;
            void** mds = &NULL_POINTER;

            if (f == 0) {

                // Get part element.
                get_compound_part_element(p0, (void*) &i, (void*) &md, (void*) &mdc, (void*) &mds);

            } else if (f == 1) {

                // Get meta element.
                get_compound_meta_element(p0, (void*) &i, (void*) &md, (void*) &mdc, (void*) &mds);

            } else {

                log_message_debug("Could not remove compound element by name. The name does not represent a compound knowledge hierarchy.");
            }

            // Recursively continue to process along the hierarchical name.
            remove_compound_element_by_name(*md, *mdc, *mds, r, (void*) &rc);

        } else {

            // No remaining name exists. A separator could NOT be found.
            // The name is NOT hierarchical and represents an element name directly.
            // The given compound contains elements which are primitive models.

            // The list element separator.
            int s = -1;

            get_index_in_array(p3, p4, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, &s, CHARACTER_ARRAY);

            remove_compound_element_by_index(p0, p1, p2, (void*) &i);

            if (s > 0) {

                // If element is part of a list, reindex list after element removal.
                reindex_compound_elements_forming_list(p0, p1, p3, &s);
            }
        }

    } else {

        log_message_debug("Could not remove compound element by name. An element with that name does not exist.");
    }
}

//
// Get.
//

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
void get_compound_element_by_index(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    if (p2 != NULL_POINTER) {

        int* i = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* cc = (int*) p1;

            if (*i >= 0) {

                log_message_debug("Get compound element by index.");

                // The abstractions, models, details.
                void** a = &NULL_POINTER;
                void** ac = &NULL_POINTER;
                void** as = &NULL_POINTER;
                void** m = &NULL_POINTER;
                void** mc = &NULL_POINTER;
                void** ms = &NULL_POINTER;
                void** d = &NULL_POINTER;
                void** dc = &NULL_POINTER;
                void** ds = &NULL_POINTER;

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

                if (*a != NULL_POINTER) {

                    if (*ac != NULL_POINTER) {

                        if (*as != NULL_POINTER) {

                            if (*m != NULL_POINTER) {

                                if (*mc != NULL_POINTER) {

                                    if (*ms != NULL_POINTER) {

                                        if (*d != NULL_POINTER) {

                                            if (*dc != NULL_POINTER) {

                                                if (*ds != NULL_POINTER) {

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

                                                        log_message_debug("Could not get compound part by index. The index exceeds the count.");
                                                    }

                                                } else {

                                                    log_message_debug("Could not get compound part by index. The details sizes is null.");
                                                }

                                            } else {

                                                log_message_debug("Could not get compound part by index. The details counts is null.");
                                            }

                                        } else {

                                            log_message_debug("Could not get compound part by index. The details is null.");
                                        }

                                    } else {

                                        log_message_debug("Could not get compound part by index. The models sizes is null.");
                                    }

                                } else {

                                    log_message_debug("Could not get compound part by index. The models counts is null.");
                                }

                            } else {

                                log_message_debug("Could not get compound part by index. The models is null.");
                            }

                        } else {

                            log_message_debug("Could not get compound part by index. The abstractions sizes is null.");
                        }

                    } else {

                        log_message_debug("Could not get compound part by index. The abstractions counts is null.");
                    }

                } else {

                    log_message_debug("Could not get compound part by index. The abstractions is null.");
                }

            } else {

                log_message_debug("Could not get compound part by index. The index is negativ.");
            }

        } else {

            log_message_debug("Could not get compound part by index. The compound count is null.");
        }

    } else {

        log_message_debug("Could not get compound part by index. The index is null.");
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
void get_compound_element_by_name(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_debug("Get compound element by name.");
    log_message_debug((char*) p2);

    // The element name.
    void* e = NULL_POINTER;
    int ec = 0;
    // The remaining name.
    void* r = NULL_POINTER;
    int rc = 0;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = -1;
    // The element name index.
    int i = -1;

    get_compound_element_name_and_remaining_name(p2, p3, (void*) &e, (void*) &ec, (void*) &r, (void*) &rc, (void*) &f);
    get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

    fprintf(stderr, "TEST index %i\n", i);
    fprintf(stderr, "TEST f %i\n", f);

    if (i >= 0) {

    fprintf(stderr, "TEST r %s\n", (char*) r);
    fprintf(stderr, "TEST rc %i\n", rc);

        if (rc > 0) {

            // A remaining name exists.
            // The compound element hierarchy is processed further.

            // The element model or details.
            void** md = &NULL_POINTER;
            void** mdc = &NULL_POINTER;
            void** mds = &NULL_POINTER;

            if (f == 0) {

    fprintf(stderr, "TEST part %i\n", i);

                // Get part element.
                get_compound_part_element(p0, (void*) &i, (void*) &md, (void*) &mdc, (void*) &mds);

            } else if (f == 1) {

    fprintf(stderr, "TEST meta %i\n", i);

                // Get meta element.
                get_compound_meta_element(p0, (void*) &i, (void*) &md, (void*) &mdc, (void*) &mds);

            } else {

                log_message_debug("Could not get compound element by name. The name does not represent a compound knowledge hierarchy.");
            }

            // Recursively continue to process along the hierarchical name.
            get_compound_element_by_name(*md, *mdc, r, (void*) &rc, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        } else {

            log_message_debug("Get the following compound element by index.");
            log_message_debug((char*) e);

            // No remaining name exists. A separator could NOT be found.
            // The name is NOT hierarchical and represents an element name directly.
            // The given compound contains elements which are primitive models.
            get_compound_element_by_index(p0, p1, (void*) &i, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }

    } else {

        log_message_debug("Could not get compound element by name. An element with that name does not exist.");
    }
}

/**
 * Gets the compound element identified by the given name.
 *
 * The model may specify:
 * - the element directly (e.g.: an integer or character value)
 * - the hierarchical name of the element (e.g.: application.gui.window.title)
 * - the hierarchical name of the name of the element (e.g.: application.name)
 *   where application.name itself contains a hierarchical name
 *   that points to an element;
 *   at first, the part name needs to be determined within the parameters;
 *   only then, that name can be used to determine the actual compound part
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
void get_universal_compound_element_by_name(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12,
    void* p13, void* p14) {

    log_message_debug("Get universal compound element by name.");

    // The part abstraction, model, details.
    void** a = &NULL_POINTER;
    void** ac = &NULL_POINTER;
    void** as = &NULL_POINTER;
    void** m = &NULL_POINTER;
    void** mc = &NULL_POINTER;
    void** ms = &NULL_POINTER;
    void** d = &NULL_POINTER;
    void** dc = &NULL_POINTER;
    void** ds = &NULL_POINTER;

    // The encapsulated part abstraction, model, details.
    void** ea = &NULL_POINTER;
    void** eac = &NULL_POINTER;
    void** eas = &NULL_POINTER;
    void** em = &NULL_POINTER;
    void** emc = &NULL_POINTER;
    void** ems = &NULL_POINTER;
    void** ed = &NULL_POINTER;
    void** edc = &NULL_POINTER;
    void** eds = &NULL_POINTER;

    // Get compound element.
    get_compound_element_by_name(p0, p1,
        p2, p3,
        (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms,
        (void*) &d, (void*) &dc, (void*) &ds);

    // The comparison result.
    int r = 0;

    //
    // The following comparisons do, in this order, get a part as:
    // - encapsulated knowledge (a model pointing to another model containing a part name)
    // - knowledge (a model containing a hierarchical part name)
    // - direct model
    //

    if (r == 0) {

        compare_arrays(*a, *ac, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            log_message_debug("Get universal compound element as encapsulated knowledge.");

            // Get compound element as double-encapsulated model.
            //
            // CAUTION!
            // The abstraction of an encapsulated name must always be "character".
            // The details are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model pointing to another model containing a part name:
            // model="application.record.name"
            //
            get_compound_element_by_name(p13, p14, *m, *mc,
                (void*) &ea, (void*) &eac, (void*) &eas,
                (void*) &em, (void*) &emc, (void*) &ems,
                (void*) &ed, (void*) &edc, (void*) &eds);

            get_compound_element_by_name(p13, p14, *em, *emc,
                p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == 0) {

        compare_arrays(*a, *ac, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            log_message_debug("Get universal compound element as knowledge.");

            // Get compound element as encapsulated model.
            //
            // CAUTION!
            // The abstraction of an encapsulated name must always be "character".
            // The details are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model containing a hierarchical part name:
            // model="application.communication.partners.hostname"
            //
            get_compound_element_by_name(p13, p14, *m, *mc,
                p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == 0) {

        log_message_debug("Get universal compound element as inline.");

        // Get compound element as direct model.
        get_compound_element_by_name(p0, p1, p2, p3,
            p4, p5, p6, p7, p8, p9, p10, p11, p12);
    }
}

/* COMPOUND_ACCESSOR_SOURCE */
#endif
