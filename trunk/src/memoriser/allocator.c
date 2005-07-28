/*
 * $RCSfile: allocator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * This file contains the functionality to:
 * - create a model in memory
 * - destroy a model in memory
 *
 * @version $Revision: 1.8 $ $Date: 2005-07-28 23:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ALLOCATOR_SOURCE
#define ALLOCATOR_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"
#include "../memoriser/allocator/complex_allocator.c"
#include "../memoriser/allocator/compound_allocator.c"
#include "../memoriser/allocator/double_allocator.c"
#include "../memoriser/allocator/double_vector_allocator.c"
#include "../memoriser/allocator/fraction_allocator.c"
#include "../memoriser/allocator/integer_allocator.c"
#include "../memoriser/allocator/integer_vector_allocator.c"
#include "../memoriser/allocator/internal_memory_allocator.c"
#include "../memoriser/allocator/pointer_vector_allocator.c"
#include "../memoriser/allocator/signal_memory_allocator.c"
#include "../memoriser/allocator/string_allocator.c"
#include "../memoriser/allocator/time_allocator.c"
#include "../memoriser/allocator/tui_allocator.c"
#include "../memoriser/allocator/unsigned_long_allocator.c"
#include "../memoriser/allocator/unsigned_long_vector_allocator.c"
#include "../memoriser/allocator/xml_node_allocator.c"
#include "../memoriser/allocator/xml_property_allocator.c"

/**
 * Allocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void allocate(void* p0, void* p1, void* p2, void* p3) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p2, p3, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_compound(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_integer(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_integer(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_integer_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_ABSTRACTION, (void*) UNSIGNED_LONG_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_unsigned_long(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_unsigned_long_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) DOUBLE_ABSTRACTION, (void*) DOUBLE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_double(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_double_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_pointer_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_fraction(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_complex(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_time(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_xml_node(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_tui(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_xml_node(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_signal_memory(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            allocate_internal_memory(p0, p1);
        }
    }
}

/**
 * Deallocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void deallocate(void* p0, void* p1, void* p2, void* p3) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p2, p3, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_compound(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_integer(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_integer(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_integer_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_ABSTRACTION, (void*) UNSIGNED_LONG_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_unsigned_long(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_unsigned_long_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) DOUBLE_ABSTRACTION, (void*) DOUBLE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_double(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_double_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_pointer_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_fraction(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_complex(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_time(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_xml_node(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_tui(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_xml_node(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_signal_memory(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            deallocate_internal_memory(p0, p1);
        }
    }
}

/**
 * Resizes the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void resize(void* p0, void* p1, void* p2, void* p3) {

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays(p2, p3, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_compound(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_string(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_integer(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_integer(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_integer_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_ABSTRACTION, (void*) UNSIGNED_LONG_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_unsigned_long(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION, (void*) UNSIGNED_LONG_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_unsigned_long_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) DOUBLE_ABSTRACTION, (void*) DOUBLE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_double(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_double_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            resize_pointer_vector(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_fraction(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_complex(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_time(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_xml_node(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_tui(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) HXP_ABSTRACTION, (void*) HXP_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_xml_node(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_signal_memory(p0, p1);
        }
    }

    if (r != 1) {

        compare_arrays(p2, p3, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

//??            resize_internal_memory(p0, p1);
        }
    }
}

/* ALLOCATOR_SOURCE */
#endif
