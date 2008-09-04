/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.49 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ACCESSOR_SOURCE
#define COMPOUND_ACCESSOR_SOURCE

#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/compound_memory_name.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"
#include "../../memoriser/allocator.c"
#include "../../memoriser/array.c"

//
// Forward declarations.
//

/**
 * Encodes the knowledge model according to the given knowledge type
 * and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 * @param p13 the language
 * @param p14 the language count
 */
void encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            int* fc = (int*) p3;

            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                    int* ec = (int*) p1;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        void** e = (void**) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element name without prefix.");

                        // Let the name begin behind the separator element.
                        // Example:
                        // .resmedicinae.tui.menu.entry#background
                        // is now only:
                        // resmedicinae.tui.menu.entry#background
                        *e = p2 + *sc;

                        // Reduce the name's length by separator element in turn.
                        *ec = *fc - *sc;

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The element name is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name without prefix. The element name count is null.");
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
 * Gets the compound element name length.
 *
 * @param p0 the name
 * @param p1 the name count
 * @param p2 the name length (Hand over as reference!)
 */
void get_compound_element_name_length(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* l = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* nc = (int*) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get compound element name length.");

            // The part separator index.
            int p = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // The meta separator index.
            int m = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

            get_array_elements_index(p0, p1, (void*) COMPOUND_PART_SEPARATOR, (void*) COMPOUND_PART_SEPARATOR_COUNT, (void*) &p, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements_index(p0, p1, (void*) COMPOUND_META_SEPARATOR, (void*) COMPOUND_META_SEPARATOR_COUNT, (void*) &m, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

            if ((p >= *NUMBER_0_INTEGER_MEMORY_MODEL) && (m == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL)) {

                // The name contains one or more part separator(s).
                // The next separator is a part separator.
                // Its index marks the end of an element name.
                *l = p;

            } else if ((p == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) && (m >= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                // The name contains one or more meta separator(s).
                // The next separator is a meta separator.
                // Its index marks the end of an element name.
                *l = m;

            } else if ((p >= *NUMBER_0_INTEGER_MEMORY_MODEL) && (m >= *NUMBER_0_INTEGER_MEMORY_MODEL)) {

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

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name length. The name count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get compound element name length. The separator index is null.");
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
                                get_array_elements_index(p0, p1, (void*) COMPOUND_PART_SEPARATOR, (void*) COMPOUND_PART_SEPARATOR_COUNT, (void*) &p, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                                // Get position of meta separator.
                                get_array_elements_index(p0, p1, (void*) COMPOUND_META_SEPARATOR, (void*) COMPOUND_META_SEPARATOR_COUNT, (void*) &m, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                                // The name without prefix.
                                void* n = *NULL_POINTER_MEMORY_MODEL;
                                int nc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                if (p == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                    // The full name starts with a part separator ".".

                                    // Set meta hierarchy flag to zero, because this is a part element.
                                    *f = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    // Get compound element name without prefix.
                                    // Example:
                                    // .resmedicinae.tui.menu.entry#background
                                    // is now only:
                                    // resmedicinae.tui.menu.entry#background
                                    // CAUTION! Only call this procedure if a prefix was found!
                                    get_compound_element_name_without_prefix((void*) &n, (void*) &nc, p0, p1, (void*) COMPOUND_PART_SEPARATOR_COUNT);

//??    fwprintf(stderr, L"TEST part f %i\n", *f);

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
                                    get_compound_element_name_without_prefix((void*) &n, (void*) &nc, p0, p1, (void*) COMPOUND_META_SEPARATOR_COUNT);

//??    fwprintf(stderr, L"TEST meta f %i\n", *f);
                                }

                                if ((*f == *NUMBER_0_INTEGER_MEMORY_MODEL) || (*f == *NUMBER_1_INTEGER_MEMORY_MODEL)) {

                                    // A part separator "." or meta separator "#" has been found.

                                    // The compound element name length.
                                    int l = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                    get_compound_element_name_length(n, (void*) &nc, (void*) &l);

//??    fwprintf(stderr, L"TEST length %i\n", l);

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
                get_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) &ns, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                if (*n != *NULL_POINTER_MEMORY_MODEL) {

                    if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                        if (*ns != *NULL_POINTER_MEMORY_MODEL) {

                            if (*i < *cc) {

                                // Get part name.
                                get_array_elements(*n, p2, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                get_array_elements(*nc, p2, p4, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                get_array_elements(*ns, p2, p5, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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
                get_array_elements(p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &a, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &ac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) &as, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                if (*a != *NULL_POINTER_MEMORY_MODEL) {

                    if (*ac != *NULL_POINTER_MEMORY_MODEL) {

                        if (*as != *NULL_POINTER_MEMORY_MODEL) {

                            if (*i < *cc) {

                                // Get part abstraction.
                                get_array_elements(*a, p2, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                get_array_elements(*ac, p2, p4, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                get_array_elements(*as, p2, p5, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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
    get_array_elements(p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &m, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &mc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ms, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

    if (*m != *NULL_POINTER_MEMORY_MODEL) {

        if (*mc != *NULL_POINTER_MEMORY_MODEL) {

            if (*ms != *NULL_POINTER_MEMORY_MODEL) {

                // Get compound element model.
                get_array_elements(*m, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(*mc, p1, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(*ms, p1, p4, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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
    get_array_elements(p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &d, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &dc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
    get_array_elements(p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ds, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

    if (*d != *NULL_POINTER_MEMORY_MODEL) {

        if (*dc != *NULL_POINTER_MEMORY_MODEL) {

            if (*ds != *NULL_POINTER_MEMORY_MODEL) {

                // Get compound element details.
                get_array_elements(*d, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(*dc, p1, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(*ds, p1, p4, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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
            get_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
            get_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

            if (*n != *NULL_POINTER_MEMORY_MODEL) {

                if (*nc != *NULL_POINTER_MEMORY_MODEL) {

                    // The loop variable.
                    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The name.
                    void** n1 = NULL_POINTER_MEMORY_MODEL;
                    void** nc1 = NULL_POINTER_MEMORY_MODEL;
                    // The comparison result.
                    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (j >= *cc) {

                            break;
                        }

                        // Get element name.
                        get_array_elements(*n, (void*) &j, (void*) &n1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                        get_array_elements(*nc, (void*) &j, (void*) &nc1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                        if (*n1 != *NULL_POINTER_MEMORY_MODEL) {

                            if (*nc1 != *NULL_POINTER_MEMORY_MODEL) {

                                compare_arrays(p2, p3, (void*) *n1, (void*) *nc1, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                                if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                    *i = j;

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

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* cs = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* cc = (int*) p1;

                if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set compound element by index.");

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
                    get_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) &ns, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &a, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &ac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) &as, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &m, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &mc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ms, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &d, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &dc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ds, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                    // CAUTION! If a compound model was properly allocated, then all arrays should exist!
                    // Therefore, check all arrays for null pointers here.

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

                                                                    if (*i >= *cs) {

                                                                        // Increase size.
                                                                        *cs = (*cs * *COMPOUND_REALLOCATION_FACTOR) + *NUMBER_1_INTEGER_MEMORY_MODEL;

                                                                        // Reallocate names, abstractions, models, details.
                                                                        reallocate_array(n, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(nc, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(ns, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(a, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(ac, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(as, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(m, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(mc, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(ms, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(d, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(dc, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        reallocate_array(ds, p1, p2, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                                                                        // Set new array reference.
                                                                        // CAUTION! If an array gets reallocated, a new array is
                                                                        // created and the contents of the old array gets copied.
                                                                        // Therefore, the new array reference needs to be set.
                                                                        // The old array gets destroyed automatically by reallocate.
                                                                        set_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) n, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) nc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) ns, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) ac, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) as, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) mc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) ms, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) dc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) ds, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    }

                                                                    if (*i < *cs) {

                                                                        // Set name, abstraction, model, details.
                                                                        set_array_elements(*n, p3, (void*) &p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*nc, p3, (void*) &p5, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ns, p3, (void*) &p6, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*a, p3, (void*) &p7, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ac, p3, (void*) &p8, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*as, p3, (void*) &p9, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*m, p3, (void*) &p10, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*mc, p3, (void*) &p11, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ms, p3, (void*) &p12, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*d, p3, (void*) &p13, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*dc, p3, (void*) &p14, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        set_array_elements(*ds, p3, (void*) &p15, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                                                                        // Increment count.
                                                                        (*cc)++;

                                                                    } else {

                                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The index exceeds the size.");
                                                                    }

                                                                } else {

                                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The models counts is null.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The models is null.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The abstractions is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The names sizes is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The names counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The names is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The index is negative.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The compound count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The compound sizes is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by index. The index is null.");
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
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set compound element by name.");

    // The element name index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Get compound element index.
    //
    // CAUTION! The name is given WITHOUT prefix here!
    // Correct example: "patient"
    // Incorrect examples: ".patient", "#patient"
    get_compound_element_index(p0, p1, p3, p4, (void*) &i);

//??    fwprintf(stderr, L"TEST element index %i\n", i);

    if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not set compound element by name. A compound element with that name does already exist.");

    } else {

        // Could not get compound element index.
        // An element with that name does not exist.
        // Therefore, add compound element by name here.

        // CAUTION! Use compound count as index for adding new elements.
        set_compound_element_by_index(p0, p1, p2, p1,
            p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    }
}

/**
 * Adds the compound element by name.
 *
 * @param p0 the compound model
 * @param p1 the compound model count
 * @param p2 the compound model size
 * @param p3 the name (Hand over as reference!)
 * @param p4 the name count (Hand over as reference!)
 * @param p5 the name size (Hand over as reference!)
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
void add_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* ns = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            int* nc = (int*) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** n = (void**) p3;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Add compound element by name:");

                // The name suffix.
                void* s = *NULL_POINTER_MEMORY_MODEL;
                int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                int ss = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Allocate name suffix.
                allocate_array((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // Use compound count as index to create the element name suffix,
                // because the element is added at the end of the compound container.
                encode((void*) &s, (void*) &sc, (void*) &ss, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p1, (void*) PRIMITIVE_MEMORY_MODEL_COUNT,
                    *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                // Resize name.
                if ((*nc + *LIST_SEPARATOR_COUNT + sc) >= *ns) {

                    // The new name character vector size.
                    // CAUTION! Add constant in case *nc is zero!
                    *ns = (*nc * *CHARACTER_VECTOR_REALLOCATION_FACTOR) + *LIST_SEPARATOR_COUNT + sc;

                    // Reallocate name character vector.
                    reallocate_array(p3, p4, p5, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                }

                // The element name already contains the element base name.

                // Add list element separator characters "_$" to element name.
                // Use name count as index to add the new characters.
                set_array_elements(*n, p4, (void*) LIST_SEPARATOR, (void*) LIST_SEPARATOR_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                *nc = *nc + *LIST_SEPARATOR_COUNT;

                // Set new element name by adding the index determined above.
                // Use name count as index to add the new characters.
                set_array_elements(*n, p4, s, (void*) &sc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
                *nc = *nc + sc;

                // Deallocate name suffix.
                deallocate_array((void*) &s, (void*) &ss, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                // CAUTION! Use compound count as index for adding new elements.
                // CAUTION! Use DEREFERENCED name, as it was handed over as reference!
                set_compound_element_by_index(p0, p1, p2, p1, *n, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add compound element by name. The name is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add compound element by name. The name count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not add compound element by name. The name size is null.");
    }
}

/**
 * Replaces the compound element by name.
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
void replace_compound_element_by_name(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace compound element by name.");
//??    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) (char*) p6);

/*??
    // The element name index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Get compound element index.
    //
    // CAUTION! The name is given WITHOUT prefix here!
    // Correct example: "patient"
    // Incorrect examples: ".patient", "#patient"
    get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

//??    fwprintf(stderr, L"TEST part index %i\n", i);

    if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not replace compound element by name. A compound element with that name does already exist.");

    } else {

        // Could not get compound element index. An element with that name does not exist.
        // Therefore, add compound element by name.
        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Add compound model element by name.");
        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) (char*) e);

        // CAUTION! Use compound count as index for adding new elements.
        // CAUTION! Do NOT use e, ec and es as name parameters!
        // These were created only locally in this procedure and
        // will thus be destroyed when the procedure is left.
        // DO USE the name, name count and name size that were
        // handed over as parameters to this procedure!
        // They were allocated by a translator while parsing CYBOL files.
        set_compound_element_by_index(p0, p1, p2, p1,
            p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
    }
*/
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

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* cs = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* cc = (int*) p1;

                if (*i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Remove compound element by index.");

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
                    get_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) &ns, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &a, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &ac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) &as, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &m, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &mc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ms, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &d, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &dc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ds, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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

                                                                        // Remove part name, abstraction, model, details.
                                                                        remove_array_elements(*n, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*nc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ns, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*a, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ac, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*as, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*m, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*mc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ms, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*d, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*dc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ds, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                                                                        // Decrement count.
                                                                        (*cc)--;

                                                                        //?? TODO: Decrease array size, if count is smaller than
                                                                        //?? half the current size.

                                                                    } else {

                                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The index exceeds the count.");
                                                                    }

                                                                } else {

                                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The details sizes is null.");
                                                                }

                                                            } else {

                                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The details counts is null.");
                                                            }

                                                        } else {

                                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The details is null.");
                                                        }

                                                    } else {

                                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The models sizes is null.");
                                                    }

                                                } else {

                                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The models counts is null.");
                                                }

                                            } else {

                                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The models is null.");
                                            }

                                        } else {

                                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The abstractions sizes is null.");
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The abstractions counts is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The abstractions is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The names sizes is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The names counts is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The names is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The index is negativ.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The compound count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The compound size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by index. The index is null.");
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

/*??
    if ((p0 != *NULL_POINTER_MEMORY_MODEL) && (p1 != *NULL_POINTER_MEMORY_MODEL)
        && (p2 != *NULL_POINTER_MEMORY_MODEL) && (p3 != *NULL_POINTER_MEMORY_MODEL)) {

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Reindex compound elements representing a list.");

        // The compound counter.
        int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The index counter.
        int ic = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // The compund part name.
        void** n = NULL_POINTER_MEMORY_MODEL;
        void** nc = NULL_POINTER_MEMORY_MODEL;
        void** ns = NULL_POINTER_MEMORY_MODEL;

        // The prefix equal to all parts of the compound representing a list.
        char* p = (char*) *NULL_POINTER_MEMORY_MODEL;
        int pc = *((int*) p3) + *LIST_SEPARATOR_COUNT;

        // Allocate prefix.
        allocate_array((void*) &p, (void*) &pc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        // Set prefix as concatenation of base name and list separator.
        set_array_elements(p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p2, p3, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(p, p3, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        //create integer model for the index
        void* indexstr = *NULL_POINTER_MEMORY_MODEL;
        int indexstr_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int indexstr_size = *NUMBER_10_INTEGER_MEMORY_MODEL;

        allocate_array((void*) &indexstr, (void*) &indexstr_size, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (cc >= *((int*) p1)) {

                break;
            }

            get_compound_element_name_by_index(p0, p1, &cc, &n, &nc, &ns);

            if ((*n != *NULL_POINTER_MEMORY_MODEL) && (*nc != *NULL_POINTER_MEMORY_MODEL) && (*ns != *NULL_POINTER_MEMORY_MODEL)) {

                if (*((int*) *nc) > pc) {

                    // Reset comparison result.
                    r = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    compare_arrays(p, &pc, *n, &pc, &r, WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                        // The beginning of the two arrays are identical.
                        // The compound element belongs to the list.

                        *((int*) *nc) = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Decode the basisname
                        decode(n, *nc, *ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p2, p3, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                        // Decode the list separator
                        decode(n, *nc, *ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                        // Decode the index
                        indexstr_count = snprintf(indexstr, indexstr_size, "%i", ic);
                        decode(n, *nc, *ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, indexstr, &indexstr_count, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHARACTER_VECTOR_ABSTRACTION, CHARACTER_VECTOR_ABSTRACTION_COUNT);

                        ic = ic + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }
            }

            cc++;
        }

        // Deallocate prefix.
        deallocate_array((void*) &p, (void*) &pc, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
        // Deallocate index string.
        deallocate_array((void*) &indexstr, (void*) &indexstr_count, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    }
*/
}

/**
 * Removes the compound element by name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
 *
 * @param p0 the compound model
 * @param p1 the compound model count
 * @param p2 the compound model size
 * @param p3 the compound details
 * @param p4 the compound details count
 * @param p5 the compound details size
 * @param p6 the name
 * @param p7 the name count
 */
void remove_compound_element_by_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove compound element by name.");

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
    get_compound_element_name_and_remaining_name(p6, p7, (void*) &e, (void*) &ec, (void*) &r, (void*) &rc, (void*) &f);

//??    fwprintf(stderr, L"TEST r %s\n", (char*) r);
//??    fwprintf(stderr, L"TEST rc %i\n", rc);
//??    fwprintf(stderr, L"TEST f %i\n", f);

    if (f == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Get compound element index.
        //
        // CAUTION! The name is given WITHOUT prefix here!
        // Correct example: "patient"
        // Incorrect examples: ".patient", "#patient"
        get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

//??    fwprintf(stderr, L"TEST part index %i\n", i);

        if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (rc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // A remaining name exists.
                // The compound element hierarchy is processed further.

                // Get compound element model.
                get_compound_element_model(p0, (void*) &i, (void*) &m, (void*) &mc, (void*) &ms);

                // Get compound element details.
                get_compound_element_details(p0, (void*) &i, (void*) &d, (void*) &dc, (void*) &ds);

                // Recursively continue to process along the hierarchical name.
                remove_compound_element_by_name(*m, *mc, *ms, *d, *dc, *ds, r, (void*) &rc);

            } else {

                // No remaining name exists. A separator could NOT be found.
                // The name is NOT hierarchical and represents an element name directly.
                // The given compound contains elements which are primitive models.

                // The list element separator.
                int s = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                get_array_elements_index(p6, p7, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, &s, WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                remove_compound_element_by_index(p0, p1, p2, (void*) &i);

                if (s > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // If element is part of a list, reindex list after element removal.
                    reindex_compound_elements_forming_list(p0, p1, p6, &s);
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by name. An element with that name does not exist.");
        }

    } else if (f == *NUMBER_1_INTEGER_MEMORY_MODEL) {

        // Get compound element index.
        //
        // CAUTION! The name is given WITHOUT prefix here!
        // Correct example: "patient"
        // Incorrect examples: ".patient", "#patient"
        get_compound_element_index(p3, p4, e, (void*) &ec, (void*) &i);

//??    fwprintf(stderr, L"TEST meta index %i\n", i);

        if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (rc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // A remaining name exists.
                // The compound element hierarchy is processed further.

                // Get compound element model.
                get_compound_element_model(p3, (void*) &i, (void*) &m, (void*) &mc, (void*) &ms);

                // Get compound element details.
                get_compound_element_details(p3, (void*) &i, (void*) &d, (void*) &dc, (void*) &ds);

                // Recursively continue to process along the hierarchical name.
                remove_compound_element_by_name(*m, *mc, *ms, *d, *dc, *ds, r, (void*) &rc);

            } else {

                // No remaining name exists. A separator could NOT be found.
                // The name is NOT hierarchical and represents an element name directly.
                // The given compound contains elements which are primitive models.

                // The list element separator.
                int s = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                get_array_elements_index(p6, p7, LIST_SEPARATOR, LIST_SEPARATOR_COUNT, &s, WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                remove_compound_element_by_index(p3, p4, p5, (void*) &i);

                if (s > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // If element is part of a list, reindex list after element removal.
                    reindex_compound_elements_forming_list(p3, p4, p6, &s);
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by name. An element with that name does not exist.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove compound element by name. The name does not represent a compound knowledge element or -hierarchy.");
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
                get_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) &ns, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &a, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &ac, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) &as, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &m, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &mc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ms, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &d, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &dc, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                get_array_elements(p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ds, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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
                                                                    get_array_elements(*n, p2, p3, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*nc, p2, p4, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*ns, p2, p5, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*a, p2, p6, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*ac, p2, p7, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*as, p2, p8, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*m, p2, p9, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*mc, p2, p10, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*ms, p2, p11, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*d, p2, p12, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*dc, p2, p13, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
                                                                    get_array_elements(*ds, p2, p14, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

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
    fwprintf(stderr, L"TEST r %s\n", (char*) r);
    fwprintf(stderr, L"TEST rc %i\n", rc);
    fwprintf(stderr, L"TEST f %i\n", f);
*/

    if (f == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Get compound element index.
        //
        // CAUTION! The name is given WITHOUT prefix here!
        // Correct example: "patient"
        // Incorrect examples: ".patient", "#patient"
        get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

//??    fwprintf(stderr, L"TEST part index %i\n", i);

        if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (rc > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // A remaining name exists.
                // The compound element hierarchy is processed further.

                // Get compound element model.
                get_compound_element_model(p0, (void*) &i, (void*) &m, (void*) &mc, (void*) &ms);

                // Get compound element details.
                get_compound_element_details(p0, (void*) &i, (void*) &d, (void*) &dc, (void*) &ds);

                // Recursively continue to process along the hierarchical name.
                get_compound_element_by_name(*m, *mc, *d, *dc, r, (void*) &rc, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

            } else {

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

//??    fwprintf(stderr, L"TEST meta index %i\n", i);

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

        compare_arrays(*a, *ac, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

        compare_arrays(*a, *ac, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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

/* COMPOUND_ACCESSOR_SOURCE */
#endif
