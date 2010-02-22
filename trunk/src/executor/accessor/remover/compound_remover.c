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

#ifndef COMPOUND_REMOVER_SOURCE
#define COMPOUND_REMOVER_SOURCE

#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/path_cybol_abstraction.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/separator_cybol_name.c"
#include "../../constant/name/memory/compound_memory_name.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"
#include "../../executor/memoriser/allocator.c"
#include "../../executor/comparator/array_equality_comparator.c"

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
                    get_array_elements(p0, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) &ns, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &a, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &ac, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) &as, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &m, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &mc, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ms, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &d, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &dc, (void*) POINTER_MEMORY_ABSTRACTION);
                    get_array_elements(p0, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ds, (void*) POINTER_MEMORY_ABSTRACTION);

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
                                                                        remove_array_elements(*n, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*nc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ns, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*a, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ac, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*as, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*m, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*mc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ms, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*d, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*dc, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);
                                                                        remove_array_elements(*ds, p1, p3, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_MEMORY_ABSTRACTION);

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
        int pc = *((int*) p3) + *LIST_SEPARATOR_CYBOL_NAME_COUNT;

        // Allocate prefix.
        allocate_array((void*) &p, (void*) &pc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        // Set prefix as concatenation of base name and list separator.
        set_array_elements(p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p2, p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        set_array_elements(p, p3, LIST_SEPARATOR_CYBOL_NAME, LIST_SEPARATOR_CYBOL_NAME_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        //create integer model for the index
        void* indexstr = *NULL_POINTER_MEMORY_MODEL;
        int indexstr_count = *NUMBER_0_INTEGER_MEMORY_MODEL;
        int indexstr_size = *NUMBER_10_INTEGER_MEMORY_MODEL;

        allocate_array((void*) &indexstr, (void*) &indexstr_size, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

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

                    compare_equal_arrays(p, &pc, *n, &pc, &r, WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    if (r == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                        // The beginning of the two arrays are identical.
                        // The compound element belongs to the list.

                        *((int*) *nc) = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        // Decode the basisname
                        decode(n, *nc, *ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p2, p3, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHARACTER_MEMORY_ABSTRACTION);

                        // Decode the list separator
                        decode(n, *nc, *ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, LIST_SEPARATOR_CYBOL_NAME, LIST_SEPARATOR_CYBOL_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHARACTER_MEMORY_ABSTRACTION);

                        // Decode the index
                        indexstr_count = snprintf(indexstr, indexstr_size, "%i", ic);
                        decode(n, *nc, *ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, indexstr, &indexstr_count, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, CHARACTER_MEMORY_ABSTRACTION);

                        ic = ic + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    }
                }
            }

            cc++;
        }

        // Deallocate prefix.
        deallocate_array((void*) &p, (void*) &pc, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        // Deallocate index string.
        deallocate_array((void*) &indexstr, (void*) &indexstr_count, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
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

//??    fwprintf(stdout, L"TEST r %s\n", (char*) r);
//??    fwprintf(stdout, L"TEST rc %i\n", rc);
//??    fwprintf(stdout, L"TEST f %i\n", f);

    if (f == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Get compound element index.
        //
        // CAUTION! The name is given WITHOUT prefix here!
        // Correct example: "patient"
        // Incorrect examples: ".patient", "#patient"
        get_compound_element_index(p0, p1, e, (void*) &ec, (void*) &i);

//??    fwprintf(stdout, L"TEST part index %i\n", i);

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

                get_array_elements_index(p6, p7, LIST_SEPARATOR_CYBOL_NAME, LIST_SEPARATOR_CYBOL_NAME_COUNT, &s, WIDE_CHARACTER_MEMORY_ABSTRACTION);

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

//??    fwprintf(stdout, L"TEST meta index %i\n", i);

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

                get_array_elements_index(p6, p7, LIST_SEPARATOR_CYBOL_NAME, LIST_SEPARATOR_CYBOL_NAME_COUNT, &s, WIDE_CHARACTER_MEMORY_ABSTRACTION);

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

/* COMPOUND_REMOVER_SOURCE */
#endif
