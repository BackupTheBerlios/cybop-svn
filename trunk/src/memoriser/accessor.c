/*
 * $RCSfile: accessor.c,v $
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
 * @version $Revision: 1.4 $ $Date: 2005-08-04 15:20:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ACCESSOR_SOURCE
#define ACCESSOR_SOURCE

#include "../globals/constants/abstraction_constants.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/accessor/double_vector_accessor.c"
#include "../memoriser/accessor/integer_accessor.c"
#include "../memoriser/accessor/integer_vector_accessor.c"
#include "../memoriser/accessor/internal_memory_accessor.c"
#include "../memoriser/accessor/pointer_vector_accessor.c"
#include "../memoriser/accessor/signal_memory_accessor.c"
#include "../memoriser/accessor/string_accessor.c"
#include "../memoriser/array.c"

/**
 * Sets the model element.
 *
 * @param p0 the model
 * @param p1 the index
 * @param p2 the element
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void set(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p3, p4, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            set_compound_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            set_integer_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            set_integer_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            set_double_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            set_string_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            set_pointer_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            set_internal_memory_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            set_signal_memory_element(p0, p1, p2);
        }
    }
}

/**
 * Removes the model element.
 *
 * CAUTION! Do NOT rename this procedure to "remove",
 * as that name is already used by libc functionality stdio.h:152.
 *
 * @param p0 the model
 * @param p1 the size
 * @param p2 the index
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void remove_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p3, p4, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            remove_compound_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            remove_integer_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            remove_integer_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            remove_double_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            remove_string_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            remove_pointer_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            remove_internal_memory_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            remove_signal_memory_element(p0, p1, p2);
        }
    }
}

/**
 * Gets the model element.
 *
 * @param p0 the model
 * @param p1 the index
 * @param p2 the model element (Hand over as reference!)
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void get(void* p0, void* p1, void* p2, void* p3, void* p4) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p3, p4, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            get_compound_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            get_integer_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            get_integer_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            get_double_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            get_string_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            get_pointer_vector_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) INTERNAL_MEMORY_ABSTRACTION, (void*) INTERNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            get_internal_memory_element(p0, p1, p2);
        }
    }

    if (r == 0) {

        compare_arrays(p3, p4, (void*) SIGNAL_MEMORY_ABSTRACTION, (void*) SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

//??            get_signal_memory_element(p0, p1, p2);
        }
    }
}

/* ACCESSOR_SOURCE */
#endif
