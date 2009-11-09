/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: wide_character_vector_accessor.c,v $ $Revision: 1.15 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIDE_CHARACTER_VECTOR_ACCESSOR_SOURCE
#define WIDE_CHARACTER_VECTOR_ACCESSOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Inserts the source- into the destination wide character vector, at the index.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the index
 */
void insert_wide_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {
}

/**
 * Overwrites the destination- with the source wide character vector,
 * starting at index with source count characters.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the index
 */
void overwrite_wide_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite wide character vector.");

                    // Set destination size.
                    *ds = *dc + *sc;

                    // Reallocate destination wide character vector.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Starting at index, move existing wide characters
                    // to the end of the destination vector.
                    //
                    // CAUTION! Do NOT set the destination count above
                    // (together with the destination size),
                    // because it is used here as index!
                    //?? set_array_elements(*d, p1, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Now copy the source- into the destination vector,
                    // starting at index.
                    //?? set_array_elements(*d, p1, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Set destination count to the same value as the -size.
                    *dc = *ds;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite wide character vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite wide character vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite wide character vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite wide character vector. The source count is null.");
    }
}

/**
 * Replace the destination- with the source wide character vector.
 *
 * The destination count AND size BOTH take the value of the source wide
 * character vector COUNT, even if the source size differs from the source count.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void replace_wide_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Replace wide character vector.");

                    // CAUTION! The destination array needs to be resized not only
                    // if the source array is greater, but also if it is smaller!
                    // If this is not done, false results may occur.
                    //
                    // Example: A colour gets copied from source to destination.
                    // The source colour is "red" with a count of 3.
                    // The destination colour is "green" with a count of 5.
                    // If the source colour gets copied to the destination,
                    // the resulting destination array is "reden" with a count of 5.
                    // This colour value does not exist and will cause errors!
                    //
                    // Therefore, the destination array count and size ALWAYS
                    // have to be adapted to the source array count and size.
                    // If this had been done in the example, the resulting
                    // destination array would have been "red" with a count of 3,
                    // which is correct.

                    // Set destination size.
                    *ds = *sc;

                    // Reallocate destination wide character vector.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Replace destination- with source wide character vector.
                    //
                    // CAUTION! Use an index with value zero, so that all characters get replaced.
                    set_array_elements(*d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Set destination count to the same value as the -size.
                    *dc = *ds;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace wide character vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace wide character vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace wide character vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not replace wide character vector. The source count is null.");
    }
}

/**
 * Appends the source- to the destination wide character vector.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void append_wide_character_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append wide character vector.");

                    // Set destination size.
                    *ds = *dc + *sc;

                    // Reallocate destination wide character vector.
                    reallocate_array(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Append source- to destination wide character vector.
                    //
                    // CAUTION! Do NOT set the destination count above
                    // (together with the destination size),
                    // because it is used here as index!
                    set_array_elements(*d, p1, p3, p4, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

                    // Set destination count to the same value as the -size.
                    *dc = *ds;

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append wide character vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append wide character vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append wide character vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not append wide character vector. The source count is null.");
    }
}

/**
 * Sets the wide character vector element.
 *
 * @param p0 the wide character vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void set_wide_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Set wide character vector element.");

    set_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Removes the wide character vector element.
 *
 * @param p0 the wide character vector
 * @param p1 the size
 * @param p2 the index
 */
void remove_wide_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove wide character vector element.");

    remove_array_elements(p0, p1, p2, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Gets the wide character vector element.
 *
 * @param p0 the wide character vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void get_wide_character_vector_element(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get wide character vector element.");

    get_array_elements(p0, p1, p2, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/* WIDE_CHARACTER_VECTOR_ACCESSOR_SOURCE */
#endif