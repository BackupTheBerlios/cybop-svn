/*
 * $RCSfile: creator.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * This file contains the functionality to:
 * - create a model in memory
 * - destroy a model in memory
 *
 * @version $Revision: 1.6 $ $Date: 2004-10-29 15:08:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATOR_SOURCE
#define CREATOR_SOURCE

#include "../array/array.c"
#include "../creator/complex_creator.c"
#include "../creator/compound_creator.c"
#include "../creator/double_creator.c"
#include "../creator/fraction_creator.c"
#include "../creator/integer_creator.c"
#include "../creator/signal_memory_creator.c"
#include "../creator/string_creator.c"
#include "../creator/time_creator.c"
#include "../creator/vector_creator.c"
#include "../creator/xml_node_creator.c"
#include "../creator/xml_property_creator.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"

/**
 * Creates the model.
 *
 * @param p0 the model
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void create(void* p0, const void* p1, const void* p2, const void* p3) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_compound(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_string(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_string(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &BOOLEAN_ABSTRACTION, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_integer(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_integer(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &VECTOR_ABSTRACTION, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_vector(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &DOUBLE_ABSTRACTION, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_double(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &FRACTION_ABSTRACTION, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_fraction(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &COMPLEX_ABSTRACTION, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_complex(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &TIME_ABSTRACTION, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_time(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &CYBOL_ABSTRACTION, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_xml_node(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &HXP_ABSTRACTION, (void*) &HXP_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_xml_node(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            create_signal_memory(p0, p1);

            d = 1;
        }
    }
}

/**
 * Destroys the model.
 *
 * @param p0 the model
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void destroy(void* p0, const void* p1, const void* p2, const void* p3) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_compound(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_string(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_string(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &BOOLEAN_ABSTRACTION, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_integer(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_integer(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &VECTOR_ABSTRACTION, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_vector(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &DOUBLE_ABSTRACTION, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_double(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &FRACTION_ABSTRACTION, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_fraction(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &COMPLEX_ABSTRACTION, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_complex(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &TIME_ABSTRACTION, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_time(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &CYBOL_ABSTRACTION, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_xml_node(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &HXP_ABSTRACTION, (void*) &HXP_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_xml_node(p0, p1);

            d = 1;
        }
    }

    if (d == 0) {

        compare_arrays(p2, p3, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

        if (r == 1) {

            destroy_signal_memory(p0, p1);

            d = 1;
        }
    }
}

/* CREATOR_SOURCE */
#endif
