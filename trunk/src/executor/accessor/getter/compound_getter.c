/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_GETTER_SOURCE
#define COMPOUND_GETTER_SOURCE

#include "../../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/compound_memory_name.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/memoriser/allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

//
// Forward declarations.
//

void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

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
 * @param p2 the element name size (Hand over as reference!)
 * @param p3 the full name
 * @param p4 the full name count
 * @param p5 the separator count
 */
void get_compound_element_name_without_prefix(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* fc = (int*) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                    int* es = (int*) p2;

                    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                        int* ec = (int*) p1;

                        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                            void** e = (void**) p0;

                            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element name without prefix.");

                            // Set compound element name without prefix.
                            //
                            // Let the name begin behind the separator element.
                            // Example:
                            // .resmedicinae.tui.menu.entry#background
                            // is now only:
                            // resmedicinae.tui.menu.entry#background
                            *e = p3 + (*sc * *WIDE_CHARACTER_PRIMITIVE_SIZE);
                            *ec = *fc - *sc;
                            *es = *ec * *WIDE_CHARACTER_PRIMITIVE_SIZE;

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The element name is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The element name count is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The element name size is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The full name is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The full name count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The separator count is null.");
    }
}

/**
 * Gets the compound element name count and size.
 *
 * @param p0 the compound element name count
 * @param p1 the compound element name size
 * @param p2 the name
 * @param p3 the name count
 */
void get_compound_element_name_count_and_size(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* nc = (int*) p3;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* ens = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* enc = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element name length.");

                // The part separator index.
                int p = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
                // The meta separator index.
                int m = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                get_array_elements_index((void*) &p, p2, p3, (void*) PART_SEPARATOR_CYBOL_NAME, (void*) PART_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                get_array_elements_index((void*) &m, p2, p3, (void*) META_SEPARATOR_CYBOL_NAME, (void*) META_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                if ((p >= *NUMBER_0_INTEGER_MEMORY_MODEL) && (m == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL)) {

                    // The name contains one or more part separator(s).
                    // The next separator is a part separator.
                    // Its index marks the end of an element name.
                    *enc = p;
                    *ens = p * *WIDE_CHARACTER_PRIMITIVE_SIZE;

                } else if ((p == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) && (m >= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                    // The name contains one or more meta separator(s).
                    // The next separator is a meta separator.
                    // Its index marks the end of an element name.
                    *enc = m;
                    *ens = m * *WIDE_CHARACTER_PRIMITIVE_SIZE;

                } else if ((p >= *NUMBER_0_INTEGER_MEMORY_MODEL) && (m >= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                    // The name contains part- as well as meta separator(s).

                    if (p < m) {

                        // The next separator is a part separator.
                        // Its index marks the end of an element name.
                        *enc = p;
                        *ens = p * *WIDE_CHARACTER_PRIMITIVE_SIZE;

                    } else {

                        // The next separator is a meta separator.
                        // Its index marks the end of an element name.
                        *enc = m;
                        *ens = m * *WIDE_CHARACTER_PRIMITIVE_SIZE;
                    }

                } else {

                    // The name does NOT contain any separators.
                    // Its count (length) marks the end of an element name.
                    *enc = *nc;
                    *ens = *nc * *WIDE_CHARACTER_PRIMITIVE_SIZE;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name length. The compound element name count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name length. The compound element name size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name length. The name count is null.");
    }
}

/**
 * Gets the compound element name and remaining name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
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

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* f = (int*) p6;

        if (p5 != *NULL_POINTER_MEMORY_MODEL) {

            int* rc = (int*) p5;

            if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                void** r = (void**) p4;

                if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                    int* ec = (int*) p3;

                    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                        void** e = (void**) p2;

                        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                            int* fc = (int*) p1;

                            // CAUTION! Do NOT remove this check for null pointer!
                            // Otherwise, the "get_array_elements_index" function below
                            // might crash with a segmentation fault!
                            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element name and remaining name.");

                                // Check if full name starts with either a
                                // part separator "." or a meta separator "#".
                                // Examples:
                                // .resmedicinae.tui.menu.entry#background
                                // #system_properties.colour

                                // The part separator index.
                                int p = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
                                // The meta separator index.
                                int m = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                                // Get position of part separator.
                                get_array_elements_index((void*) &p, p0, p1, (void*) PART_SEPARATOR_CYBOL_NAME, (void*) PART_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                                // Get position of meta separator.
                                get_array_elements_index((void*) &m, p0, p1, (void*) META_SEPARATOR_CYBOL_NAME, (void*) META_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

/*??
    fwprintf(stdout, L"TEST compound full nc: %i\n", *((int*) p1));
    fwprintf(stdout, L"TEST compound full n: %ls\n", (wchar_t*) p0);
*/

                                // The name without prefix.
                                void* n = *NULL_POINTER_MEMORY_MODEL;
                                int nc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                int ns = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                if (p == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    // The full name starts with a part separator ".".

                                    // Set meta hierarchy flag to zero, because this is a part element.
                                    *f = *NUMBER_0_INTEGER_MEMORY_MODEL;

//??    fwprintf(stdout, L"TEST part hierarchy flag f %i\n", *f);

                                    // Get compound element name without prefix.
                                    // Example:
                                    // .resmedicinae.tui.menu.entry#background
                                    // is now only:
                                    // resmedicinae.tui.menu.entry#background
                                    // CAUTION! Only call this procedure if a prefix was found!
                                    get_compound_element_name_without_prefix((void*) &n, (void*) &nc, (void*) &ns, p0, p1, (void*) PART_SEPARATOR_CYBOL_NAME_COUNT);

/*??
    fwprintf(stdout, L"TEST compound without prefix nc: %i\n", nc);
    fwprintf(stdout, L"TEST compound without prefix n: %ls\n", (wchar_t*) n);
*/

                                } else if (m == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    // The full name starts with a meta separator "#".

                                    // Set meta hierarchy flag to one, because this is a meta element.
                                    *f = *NUMBER_1_INTEGER_MEMORY_MODEL;

                                    // Get compound element name without prefix.
                                    // Example:
                                    // .resmedicinae.tui.menu.entry#background
                                    // is now only:
                                    // resmedicinae.tui.menu.entry#background
                                    // CAUTION! Only call this procedure if a prefix was found!
                                    get_compound_element_name_without_prefix((void*) &n, (void*) &nc, (void*) &ns, p0, p1, (void*) META_SEPARATOR_CYBOL_NAME_COUNT);

//??    fwprintf(stdout, L"TEST meta f %i\n", *f);
                                }

                                if ((*f == *NUMBER_0_INTEGER_MEMORY_MODEL) || (*f == *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                                    // A part separator "." or meta separator "#" has been found.

                                    // The compound element name count and size.
                                    int enc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    int ens = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    get_compound_element_name_count_and_size((void*) &enc, (void*) &ens, n, (void*) &nc);

/*??
    fwprintf(stdout, L"TEST compound enc %i\n", enc);
    fwprintf(stdout, L"TEST compound ens %i\n", ens);
*/

                                    // Determine element name.
                                    // It equals the name without prefix.
                                    *e = n;

                                    // Determine element name count.
                                    // It equals the element name count determined above.
                                    *ec = enc;

                                    // Determine remaining name.
                                    // It starts with the separator.
                                    // Example: "hello.test"
                                    // The index of the separator is 5.
                                    // The starting index of the remaining name ".test" is (5 * *WIDE_CHARACTER_PRIMITIVE_SIZE).
                                    *r = (void*) (n + ens);

                                    // The remaining name count is the full name count
                                    // decreased by the separator index.
                                    // Example: "hello.test"
                                    // The full name count is 10.
                                    // The separator index is 5.
                                    // The count of the remaining name ".test" is 10 - 5 = 5.
                                    *rc = nc - enc;

                                } else {

                                    // The hierarchical name does not start with a prefix
                                    // (part separator '.' or meta separator '#').
                                    // This does not necessarily have to be an error,
                                    // since property (meta) names are given without prefix.
                                    // Therefore, the element name is set to the full name below.

                                    // Set meta hierarchy flag to zero, because the
                                    // element name did not have a prefix and is thus
                                    // assumed to be a part element, by default.
                                    //
                                    // Example:
                                    // A CYBOL property name is given without
                                    // prefix and is a part element of the
                                    // corresponding CYBOL details container.
                                    *f = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Set element name to full name.
                                    *e = p0;

                                    // Set element name count to full name count.
                                    *ec = *fc;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The full name is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The full name count is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The element name is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The element name count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The remaining name is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The remaining name count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get the compound element name and remaining name. The meta hierarchy flag is null.");
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
void get_compound_element_name_by_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* cc = (int*) p1;

            if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element name by index.");

                // The names.
                void** n = NULL_POINTER_MEMORY_MODEL;
                void** nc = NULL_POINTER_MEMORY_MODEL;
                void** ns = NULL_POINTER_MEMORY_MODEL;

                // Get names.
                get_array_elements((void*) &n, p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &nc, p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &ns, p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

                if (*n != *NULL_POINTER_MEMORY_MODEL) {

                    if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                        if (*ns != *NULL_POINTER_MEMORY_MODEL) {

                            if (*i < *cc) {

                                // Get part name.
                                get_array_elements(p3, *n, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                get_array_elements(p4, *nc, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                get_array_elements(p5, *ns, p2, (void*) POINTER_MEMORY_ABSTRACTION);

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The index exceeds the count.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The names sizes is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The names counts is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The names is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The index is negativ.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The compound count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name by index. The index is null.");
    }
}

/**
 * Gets the compound element abstraction by index.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the index
 * @param p3 the abstraction (Hand over as reference!)
 * @param p4 the abstraction count
 * @param p5 the abstraction size
 */
void get_compound_element_abstraction_by_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* cc = (int*) p1;

            if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element abstraction by index.");

                // The abstractions.
                void** a = NULL_POINTER_MEMORY_MODEL;
                void** ac = NULL_POINTER_MEMORY_MODEL;
                void** as = NULL_POINTER_MEMORY_MODEL;

                // Get abstractions.
                get_array_elements((void*) &a, p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &ac, p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &as, p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

                if (*a != *NULL_POINTER_MEMORY_MODEL) {

                    if (*ac != *NULL_POINTER_MEMORY_MODEL) {

                        if (*as != *NULL_POINTER_MEMORY_MODEL) {

                            if (*i < *cc) {

                                // Get part abstraction.
                                get_array_elements(p3, *a, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                get_array_elements(p4, *ac, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                get_array_elements(p5, *as, p2, (void*) POINTER_MEMORY_ABSTRACTION);

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The index exceeds the count.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The abstractions sizes is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The abstractions counts is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The abstractions is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The index is negativ.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The compound count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element abstraction by index. The index is null.");
    }
}

/**
 * Gets the compound element model.
 *
 * @param p0 the compound
 * @param p1 the index
 * @param p2 the compound element model (Hand over as reference!)
 * @param p3 the compound element model count (Hand over as reference!)
 * @param p4 the compound element model size (Hand over as reference!)
 */
void get_compound_element_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element model.");

    // The models.
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;

    // Get models.
    get_array_elements((void*) &m, p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
    get_array_elements((void*) &mc, p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
    get_array_elements((void*) &ms, p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

    if (*m != *NULL_POINTER_MEMORY_MODEL) {

        if (*mc != *NULL_POINTER_MEMORY_MODEL) {

            if (*ms != *NULL_POINTER_MEMORY_MODEL) {

                // Get compound element model.
                get_array_elements(p2, *m, p1, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements(p3, *mc, p1, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements(p4, *ms, p1, (void*) POINTER_MEMORY_ABSTRACTION);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element model. The models sizes is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element model. The models counts is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element model. The models is null.");
    }
}

/**
 * Gets the compound element details.
 *
 * @param p0 the compound
 * @param p1 the index
 * @param p2 the compound element details (Hand over as reference!)
 * @param p3 the compound element details count (Hand over as reference!)
 * @param p4 the compound element details size (Hand over as reference!)
 */
void get_compound_element_details(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element details.");

    // The details.
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;

    // Get details.
    get_array_elements((void*) &d, p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
    get_array_elements((void*) &dc, p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
    get_array_elements((void*) &ds, p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

    if (*d != *NULL_POINTER_MEMORY_MODEL) {

        if (*dc != *NULL_POINTER_MEMORY_MODEL) {

            if (*ds != *NULL_POINTER_MEMORY_MODEL) {

                // Get compound element details.
                get_array_elements(p2, *d, p1, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements(p3, *dc, p1, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements(p4, *ds, p1, (void*) POINTER_MEMORY_ABSTRACTION);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element details. The details sizes is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound elementn details. The details counts is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element details. The details is null.");
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p4;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* cc = (int*) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element index.");

            // The element names.
            void** n = NULL_POINTER_MEMORY_MODEL;
            void** nc = NULL_POINTER_MEMORY_MODEL;

            // Get element names.
            get_array_elements((void*) &n, p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
            get_array_elements((void*) &nc, p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

            if (*n != *NULL_POINTER_MEMORY_MODEL) {

                if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The name.
                    void** n1 = NULL_POINTER_MEMORY_MODEL;
                    void** nc1 = NULL_POINTER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
    fwprintf(stdout, L"\n\nTEST cc: %i\n", *cc);
    fwprintf(stdout, L"TEST p2: %ls\n", (wchar_t*) p2);
    fwprintf(stdout, L"TEST p3: %i\n", *((int*) p3));
*/

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *cc) {

                            break;
                        }

                        // Get element name.
                        get_array_elements((void*) &n1, *n, (void*) &j, (void*) POINTER_MEMORY_ABSTRACTION);
                        get_array_elements((void*) &nc1, *nc, (void*) &j, (void*) POINTER_MEMORY_ABSTRACTION);

/*??
    fwprintf(stdout, L"TEST j: %i\n", j);
    fwprintf(stdout, L"TEST n1: %ls\n", (wchar_t*) *n1);
    fwprintf(stdout, L"TEST nc1: %i\n", **((int**) nc1));
*/

                        if (*n1 != *NULL_POINTER_MEMORY_MODEL) {

                            if (*nc1 != *NULL_POINTER_MEMORY_MODEL) {

                                compare_equal_arrays((void*) &r, p2, p3, *n1, *nc1, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                                if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                    *i = j;
//??    fwprintf(stdout, L"\n\nTEST INDEX SET to: %i\n\n", *i);

                                    break;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element index. The name count is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element index. The name is null.");
                        }

                        // Reset name and name count.
                        n1 = NULL_POINTER_MEMORY_MODEL;
                        nc1 = NULL_POINTER_MEMORY_MODEL;

                        j++;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element index. The part names counts is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element index. The part names is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element index. The compound count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element index. The index is null.");
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
 * @param p3 the name (Hand over as reference!)
 * @param p4 the name count (Hand over as reference!)
 * @param p5 the name size (Hand over as reference!)
 * @param p6 the abstraction (Hand over as reference!)
 * @param p7 the abstraction count (Hand over as reference!)
 * @param p8 the abstraction size (Hand over as reference!)
 * @param p9 the model (Hand over as reference!)
 * @param p10 the model count (Hand over as reference!)
 * @param p11 the model size (Hand over as reference!)
 * @param p12 the details (Hand over as reference!)
 * @param p13 the details count (Hand over as reference!)
 * @param p14 the details size (Hand over as reference!)
 */
void get_compound_element_by_index(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* cc = (int*) p1;

            if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element by index.");

                // The names, abstractions, models, details.
                void** n = NULL_POINTER_MEMORY_MODEL;
                void** nc = NULL_POINTER_MEMORY_MODEL;
                void** ns = NULL_POINTER_MEMORY_MODEL;
                void** a = NULL_POINTER_MEMORY_MODEL;
                void** ac = NULL_POINTER_MEMORY_MODEL;
                void** as = NULL_POINTER_MEMORY_MODEL;
                void** m = NULL_POINTER_MEMORY_MODEL;
                void** mc = NULL_POINTER_MEMORY_MODEL;
                void** ms = NULL_POINTER_MEMORY_MODEL;
                void** d = NULL_POINTER_MEMORY_MODEL;
                void** dc = NULL_POINTER_MEMORY_MODEL;
                void** ds = NULL_POINTER_MEMORY_MODEL;

                // Get names, abstractions, models, details.
                get_array_elements((void*) &n, p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &nc, p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &ns, p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &a, p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &ac, p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &as, p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &m, p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &mc, p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &ms, p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &d, p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &dc, p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);
                get_array_elements((void*) &ds, p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION);

                if (*n != *NULL_POINTER_MEMORY_MODEL) {

                    if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                        if (*ns != *NULL_POINTER_MEMORY_MODEL) {

                            if (*a != *NULL_POINTER_MEMORY_MODEL) {

                                if (*ac != *NULL_POINTER_MEMORY_MODEL) {

                                    if (*as != *NULL_POINTER_MEMORY_MODEL) {

                                        if (*m != *NULL_POINTER_MEMORY_MODEL) {

                                            if (*mc != *NULL_POINTER_MEMORY_MODEL) {

                                                if (*ms != *NULL_POINTER_MEMORY_MODEL) {

                                                    if (*d != *NULL_POINTER_MEMORY_MODEL) {

                                                        if (*dc != *NULL_POINTER_MEMORY_MODEL) {

                                                            if (*ds != *NULL_POINTER_MEMORY_MODEL) {

                                                                if (*i < *cc) {

                                                                    // Get name, abstraction, model, details.
                                                                    get_array_elements(p3, *n, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p4, *nc, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p5, *ns, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p6, *a, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p7, *ac, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p8, *as, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p9, *m, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p10, *mc, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p11, *ms, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p12, *d, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p13, *dc, p2, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                    get_array_elements(p14, *ds, p2, (void*) POINTER_MEMORY_ABSTRACTION);

                                                                } else {

                                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The index exceeds the count.");
                                                                }

                                                            } else {

                                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The details sizes is null.");
                                                            }

                                                        } else {

                                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The details counts is null.");
                                                        }

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The details is null.");
                                                    }

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The models sizes is null.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The models counts is null.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The models is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The abstractions sizes is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The abstractions counts is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The abstractions is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The names sizes is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The names counts is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The names is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The index is negativ.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The compound count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by index. The index is null.");
    }
}

/**
 * Gets the compound element by name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
 *
 * @param p0 the compound model
 * @param p1 the compound model count
 * @param p2 the compound details
 * @param p3 the compound details count
 * @param p4 the identifier name
 * @param p5 the identifier name count
 * @param p6 the name (Hand over as reference!)
 * @param p7 the name count (Hand over as reference!)
 * @param p8 the name size (Hand over as reference!)
 * @param p9 the abstraction (Hand over as reference!)
 * @param p10 the abstraction count (Hand over as reference!)
 * @param p11 the abstraction size (Hand over as reference!)
 * @param p12 the model (Hand over as reference!)
 * @param p13 the model count (Hand over as reference!)
 * @param p14 the model size (Hand over as reference!)
 * @param p15 the details (Hand over as reference!)
 * @param p16 the details count (Hand over as reference!)
 * @param p17 the details size (Hand over as reference!)
 */
void get_compound_element_by_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get compound element by name.");

    // The element name.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The remaining name.
    void* r = *NULL_POINTER_MEMORY_MODEL;
    int rc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The meta hierarchy flag with the following meanings:
    // -1: not a compound knowledge hierarchy
    // 0: part hierarchy
    // 1: meta hierarchy
    int f = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The element name index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The compound element model.
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    // The compound element details.
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;

    // Get compound element name and remaining name,
    // as well as the flag indicating a part- or meta element.
    get_compound_element_name_and_remaining_name(p4, p5, (void*) &e, (void*) &ec, (void*) &r, (void*) &rc, (void*) &f);

/*??
    fwprintf(stdout, L"TEST e: %ls\n", (wchar_t*) e);
    fwprintf(stdout, L"TEST ec: %i\n", ec);
    fwprintf(stdout, L"TEST r: %ls\n", (wchar_t*) r);
    fwprintf(stdout, L"TEST rc: %i\n", rc);
    fwprintf(stdout, L"TEST f: %i\n", f);
*/

    if (f == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Get compound element index.
        //
        // CAUTION! The name is given WITHOUT prefix here!
        // Correct example: "patient"
        // Incorrect examples: ".patient", "#patient"
        get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

//??    fwprintf(stdout, L"TEST part index: %i\n", i);

        if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (rc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST remaining name: %i\n", i);

                // A remaining name exists.
                // The compound element hierarchy is processed further.

                // Get compound element model.
                get_compound_element_model(p0, (void*) &i, (void*) &m, (void*) &mc, (void*) &ms);

                // Get compound element details.
                get_compound_element_details(p0, (void*) &i, (void*) &d, (void*) &dc, (void*) &ds);

                // Recursively continue to process along the hierarchical name.
                get_compound_element_by_name(*m, *mc, *d, *dc, r, (void*) &rc, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

            } else {

//??    fwprintf(stdout, L"TEST call get_compound_element_by_index: %i\n", i);

                // No remaining name exists. A separator could NOT be found.
                // The name is NOT hierarchical and represents an element name directly.
                // The given compound contains elements which are primitive models.
                get_compound_element_by_index(p0, p1, (void*) &i, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
            }

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by name. A part element with that name does not exist.");
        }

    } else if (f == *NUMBER_1_INTEGER_MEMORY_MODEL) {

        // Get compound element index.
        //
        // CAUTION! The name is given WITHOUT prefix here!
        // Correct example: "patient"
        // Incorrect examples: ".patient", "#patient"
        get_compound_element_index(p2, p3, e, (void*) &ec, (void*) &i);

//??    fwprintf(stdout, L"TEST meta index: %i\n", i);

        if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (rc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // A remaining name exists.
                // The compound element hierarchy is processed further.

                // Get compound element model.
                get_compound_element_model(p2, (void*) &i, (void*) &m, (void*) &mc, (void*) &ms);

                // Get compound element details.
                get_compound_element_details(p2, (void*) &i, (void*) &d, (void*) &dc, (void*) &ds);

                // Recursively continue to process along the hierarchical name.
                get_compound_element_by_name(*m, *mc, *d, *dc, r, (void*) &rc, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

            } else {

                // No remaining name exists. A separator could NOT be found.
                // The name is NOT hierarchical and represents an element name directly.
                // The given compound contains elements which are primitive models.
                get_compound_element_by_index(p2, p3, (void*) &i, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
            }

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by name. A meta element with that name does not exist.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element by name. The name does not represent a compound knowledge element or -hierarchy.");
    }
}

/**
 * Gets the compound element identified by the given name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
 *
 * The model may specify:
 * - the element directly (e.g.: an integer or character value)
 * - the hierarchical name of the element (e.g.: application.gui.window.title)
 * - the hierarchical name of the name of the element (e.g.: application.name)
 *   where application.name itself contains a hierarchical name
 *   that points to an element;
 *   at first, the part name needs to be determined within the parameters;
 *   only then, that name can be used to determine the actual compound element
 *
 * @param p0 the compound model
 * @param p1 the compound model count
 * @param p2 the identifier name
 * @param p3 the identifier name count
 * @param p4 the name (Hand over as reference!)
 * @param p5 the name count (Hand over as reference!)
 * @param p6 the name size (Hand over as reference!)
 * @param p7 the abstraction (Hand over as reference!)
 * @param p8 the abstraction count (Hand over as reference!)
 * @param p9 the abstraction size (Hand over as reference!)
 * @param p10 the model (Hand over as reference!)
 * @param p11 the model count (Hand over as reference!)
 * @param p12 the model size (Hand over as reference!)
 * @param p13 the details (Hand over as reference!)
 * @param p14 the details count (Hand over as reference!)
 * @param p15 the details size (Hand over as reference!)
 * @param p16 the knowledge
 * @param p17 the knowledge count
 */
void get_universal_compound_element_by_name(void* p0, void* p1, void* p2, void* p3,
    void* p4, void* p5, void* p6, void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get universal compound element by name.");

    // The part name, abstraction, model, details.
    void** n = NULL_POINTER_MEMORY_MODEL;
    void** nc = NULL_POINTER_MEMORY_MODEL;
    void** ns = NULL_POINTER_MEMORY_MODEL;
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;

    // The encapsulated part name, abstraction, model, details.
    void** en = NULL_POINTER_MEMORY_MODEL;
    void** enc = NULL_POINTER_MEMORY_MODEL;
    void** ens = NULL_POINTER_MEMORY_MODEL;
    void** ea = NULL_POINTER_MEMORY_MODEL;
    void** eac = NULL_POINTER_MEMORY_MODEL;
    void** eas = NULL_POINTER_MEMORY_MODEL;
    void** em = NULL_POINTER_MEMORY_MODEL;
    void** emc = NULL_POINTER_MEMORY_MODEL;
    void** ems = NULL_POINTER_MEMORY_MODEL;
    void** ed = NULL_POINTER_MEMORY_MODEL;
    void** edc = NULL_POINTER_MEMORY_MODEL;
    void** eds = NULL_POINTER_MEMORY_MODEL;

    // Get compound element.
    get_compound_element_by_name(p0, p1, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        p2, p3,
        (void*) &n, (void*) &nc, (void*) &ns,
        (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms,
        (void*) &d, (void*) &dc, (void*) &ds);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    //
    // The following comparisons do, in this order, get a part as:
    // - encapsulated knowledge (a model pointing to another model containing a part name)
    // - knowledge (a model containing a hierarchical part name)
    // - direct model
    //

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, *a, *ac, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get universal compound element as encapsulated knowledge.");

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
            // The knowledge root does not have a details container with meta
            // information, which is why a null pointer is handed over here twice.
            get_compound_element_by_name(p16, p17, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                *m, *mc,
                (void*) &en, (void*) &enc, (void*) &ens,
                (void*) &ea, (void*) &eac, (void*) &eas,
                (void*) &em, (void*) &emc, (void*) &ems,
                (void*) &ed, (void*) &edc, (void*) &eds);

            // The knowledge root does not have a details container with meta
            // information, which is why a null pointer is handed over here twice.
            get_compound_element_by_name(p16, p17, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                *em, *emc, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, *a, *ac, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get universal compound element as knowledge.");

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
            // The knowledge root does not have a details container with meta
            // information, which is why a null pointer is handed over here twice.
            get_compound_element_by_name(p16, p17, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                *m, *mc, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get universal compound element as inline.");

        // Get compound element as direct model.
        //
        // It would actually be possible to remember the values of
        // the first call to "get_compound_element_by_name" above,
        // and assign these to the parameters here, which might lead to
        // some optimisation and better performance.
        // For reasons of clearity of code, however, the introduction and
        // usage of those many additional local variables was avoided
        // and the "get_compound_element_by_name" procedure
        // is called here a second time instead.
        get_compound_element_by_name(p0, p1, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
    }
}

/* COMPOUND_GETTER_SOURCE */
#endif
