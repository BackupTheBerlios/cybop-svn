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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ASSIGNER_SOURCE
#define ASSIGNER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Assign the character memory area.
 *
 * @param p0 the destination element
 * @param p1 the source element
 */
void assign_character_area(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        char* se = (char*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            char* de = (char*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign character area.");

            // Assign source- to destination element.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign character area. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign character area. The source element is null.");
    }
}

/**
 * Assign the double memory area.
 *
 * @param p0 the destination element
 * @param p1 the source element
 */
void assign_double_area(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        double* se = (double*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            double* de = (double*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign double area.");

            // Assign source- to destination element.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign double area. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign double area. The source element is null.");
    }
}

/**
 * Assign the integer memory area.
 *
 * @param p0 the destination element
 * @param p1 the source element
 */
void assign_integer_area(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* se = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            int* de = (int*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign integer area.");

            // Assign source- to destination element.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign integer area. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign integer area. The source element is null.");
    }
}

/**
 * Assign the pointer memory area.
 *
 * @param p0 the destination element
 * @param p1 the source element
 */
void assign_pointer_area(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        void** se = (void**) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            void** de = (void**) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign pointer area.");

            // Assign source- to destination element.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign pointer area. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign pointer area. The source element is null.");
    }
}

/**
 * Assign the unsigned long memory area.
 *
 * @param p0 the destination element
 * @param p1 the source element
 */
void assign_unsigned_long_area(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        unsigned long* se = (unsigned long*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            unsigned long* de = (unsigned long*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign unsigned long area.");

            // Assign source- to destination element.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign unsigned long area. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign unsigned long area. The source element is null.");
    }
}

/**
 * Assign the wide character memory area.
 *
 * @param p0 the destination element
 * @param p1 the source element
 */
void assign_wide_character_area(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        wchar_t* se = (wchar_t*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* de = (wchar_t*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign wide character area.");

            // Assign source- to destination element.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign wide character area. The destination element is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign wide character area. The source element is null.");
    }
}

/**
 * Assigns the element depending on the given primitive type.
 *
 * @param p0 the destination base
 * @param p1 the element
 * @param p2 the offset
 * @param p3 the array type
 */
void assign_area(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* o = (int*) p2;

            // Determine destination element.
            void* de = p0 + *o;
            // Determine source element.
            void* se = p1 + *o;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Assign area.");

            if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

                assign_character_area(de, se);

            } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

                assign_double_area(de, se);

            } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

                assign_integer_area(de, se);

            } else if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

                assign_pointer_area(de, se);

            } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

                assign_unsigned_long_area(de, se);

            } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

                assign_wide_character_area(de, se);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign area. The offset is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not assign area. The type is null.");
    }
}

/**
 * Assigns the element depending on the given primitive type.
 *
 * @param p0 the destination
 * @param p1 the source
 * @param p2 the index
 * @param p3 the type
 */
void assign_area_with_offset(void* p0, void* p1, void* p2, void* p3) {

    // The offset.
    int o = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Calculate offset depending on given array type.
    calculate_area((void*) &o, p2, p3);

    // Assign source- to destination memory area.
    assign_area(p0, p1, (void*) &o, p3);
}

/* ASSIGNER_SOURCE */
#endif
