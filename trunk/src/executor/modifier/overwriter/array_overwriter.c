/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_OVERWRITER_SOURCE
#define ARRAY_OVERWRITER_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/integer_comparator.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/modifier/copier/value_copier.c"
#include "../../../logger/logger.c"

/**
 * Overwrites the destination- with the source array,
 * starting from the given index.
 *
 * The count and size are adjusted automatically.
 *
 * Example:
 *
 * destination array: "Hello ABCXYZ!"
 * source array: "blubla, World blubla"
 * count: 7
 * destination array index: 5
 * source array index: 6
 * destination array count: 13
 * ==> result: "Hello, World!"
 *
 * It is also allowed to assign elements far behind
 * the end of the original array. This is similar
 * to random access of an arbitrary byte of a file.
 *
 * Example:
 *
 * destination array: "Hello, World"
 * source array: "blubla!!! blubla"
 * count: 3
 * destination array index: 20
 * source array index: 6
 * destination array count: 12
 * ==> result: "Hello, World        !!!"
 *
 * @param p0 the destination array (Hand over as reference!)
 * @param p1 the source array
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the destination array count
 * @param p7 the destination array size
 * @param p8 the adjust flag
 */
void overwrite_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** d = (void**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Overwrite array.");

        // The new size.
        int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // CAUTION! The destination array count is NOT considered here,
        // because an element may be added far behind the end of the array.
        // This is similar to random access of an arbitrary byte of a file.
        // In such a case, the destination index plus number of elements
        // to be added will deliver the new size of the destination array.

        // Add destination index.
        calculate_integer_add((void*) &n, p4);
        // Add count of new elements to be written over old elements.
        calculate_integer_add((void*) &n, p3);

        // The comparison result.
        int r = *FALSE_BOOLEAN_MEMORY_MODEL;

        compare_integer_greater((void*) &r, (void*) &n, p7);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // The new destination size is greater than the old.

            // Multiply new size with factor.
            // CAUTION! This multiplication has to be done AFTER the comparison
            // of new size and old size since otherwise, the new size is falsified,
            // which would lead to runtime errors.
            multiply_with_integer((void*) &n, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

            // Enlarge array using new count as size.
            reallocate_array(p0, p6, (void*) &n, p2);

            // Adjust new size.
            copy_integer(p7, (void*) &n);
        }

        // Copy source to destination.
        copy_array_forward(*d, p1, p2, p3, p4, p5);

        // Reset comparison result.
        r = *FALSE_BOOLEAN_MEMORY_MODEL;

        compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //
            // Adjust destination array COUNT only if "adjust" flag was set.
            //
            // The destination size does not really matter here.
            // It got extended above, if necessary.
            // For the destination count, there are two possibilities:
            //
            // 1 The adjust flag is FALSE:
            //
            // In this case, the original destination count REMAINS AS IS.
            //
            // Example:
            //
            // - destination array: "Today is a rainy day."
            // - source array: "sunny"
            // - abstraction: (wide_character given as special integer constant)
            // - count: 5
            // - destination index: 11
            // - source index: 0
            // - destination array count: 21
            // - destination array size: 21 (or greater, does not matter)
            // - adjust flag: 0
            //
            // --> destination array: "Today is a sunny day."
            // --> destination array count: 21
            //
            // 2 The adjust flag is TRUE:
            //
            // In this case, the original destination count GETS ADJUSTED.
            //
            // Example:
            //
            // - destination array: "green"
            // - source array: "red"
            // - abstraction: (wide_character given as special integer constant)
            // - count: 3
            // - destination index: 0
            // - source index: 0
            // - destination array count: 5
            // - destination array size: 5 (or greater, does not matter)
            // - adjust flag: 1
            //
            // --> destination array: "red"
            // --> destination array count: 3
            //
            // If the destination count hadn't been adjusted, the result would have been:
            // --> destination array: "reden"
            // --> destination array count: 5
            // ... which is clearly wrong, since this colour value does not exist.
            //
            // Therefore, the destination array count has to get adjusted
            // not only if the number of elements increases (extension),
            // but also if the number of elements decreases (shrinking).
            // If this was not done, false results would occur.
            //
            copy_integer(p6, (void*) &n);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not overwrite array. The destination array is null.");
    }
}

/* ARRAY_OVERWRITER_SOURCE */
#endif
