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
 * @version $Revision: 1.3 $ $Date: 2004-09-08 19:44:44 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATOR_SOURCE
#define CREATOR_SOURCE

#include "../array/array.c"
#include "../creator/boolean_creator.c"
#include "../creator/complex_creator.c"
#include "../creator/compound_creator.c"
#include "../creator/double_creator.c"
#include "../creator/fraction_creator.c"
#include "../creator/integer_creator.c"
#include "../creator/operation_creator.c"
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

    if (p3 != NULL_POINTER) {

        int* ac = (int*) p3;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*ac == COMPOUND_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_compound(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == CYBOL_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &CYBOL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_xml_node(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == OPERATION_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_operation(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == STRING_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_string(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_boolean(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == INTEGER_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_integer(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == VECTOR_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_vector(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_double(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == FRACTION_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_fraction(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_complex(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == TIME_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_time(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == HXP_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &HXP_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &HXP_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_xml_node(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == SIGNAL_MEMORY_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_signal_memory(p0, p1);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create. The abstraction count is null.");
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

    if (p3 != NULL_POINTER) {

        int* ac = (int*) p3;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*ac == COMPOUND_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_compound(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == CYBOL_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &CYBOL_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &CYBOL_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_xml_node(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == OPERATION_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_operation(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == STRING_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_string(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_boolean(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == INTEGER_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_integer(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == VECTOR_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_vector(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_double(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == FRACTION_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_fraction(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_complex(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == TIME_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_time(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == HXP_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &HXP_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &HXP_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_xml_node(p0, p1);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == SIGNAL_MEMORY_ABSTRACTION_COUNT) {

                compare_array_elements(p2, (void*) &SIGNAL_MEMORY_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SIGNAL_MEMORY_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    destroy_signal_memory(p0, p1);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not destroy. The abstraction count is null.");
    }
}

/* CREATOR_SOURCE */
#endif
