/*
 * $RCSfile: create_model.c,v $
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
 * This file creates a transient model from a persistent model.
 *
 * @version $Revision: 1.26 $ $Date: 2004-05-29 15:15:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

#include "../cybol/file.c"
#include "../logger/logger.c"
#include "../statics/boolean.c"
#include "../statics/complex.c"
#include "../statics/compound.c"
#include "../statics/double.c"
#include "../statics/fraction.c"
#include "../statics/integer.c"
#include "../statics/operation.c"
#include "../statics/string.c"
#include "../statics/time.c"
#include "../statics/vector.c"

/**
 * Reads a persistent model into an array.
 *
 * Possible model locations are:
 * - inline
 * - file
 * - ftp
 * - http
 *
 * @param p0 the buffer array
 * @param p1 the buffer array count
 * @param p2 the buffer array size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 * @param p5 the location
 * @param p6 the location count
 */
void read_model(void* p0, void* p1, void* p2, const void* p3, const void* p4, const void* p5, const void* p6) {

    if (p6 != NULL_POINTER) {

        int* lc = (int*) p6;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*lc == INLINE_LOCATION_COUNT) {

                compare_array_elements(p5, (void*) &INLINE_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &INLINE_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_inline(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == FILE_LOCATION_COUNT) {

                compare_array_elements(p5, (void*) &FILE_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &FILE_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_file(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == FTP_LOCATION_COUNT) {

                compare_array_elements(p5, (void*) &FTP_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &FTP_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_ftp(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == HTTP_LOCATION_COUNT) {

                compare_array_elements(p5, (void*) &HTTP_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &HTTP_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_http(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not read model. The location count is null.");
    }
}

/**
 * Interprets a persistent model to create a transient model.
 *
 * Creates and initializes the transient model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void interpret_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p5 != NULL_POINTER) {

        int* ac = (int*) p5;

        if (p3 != NULL_POINTER) {

            int* pc = (int*) p3;

            // Only proceed, if persistent model is not empty.
            if (*pc > 0) {

                //
                // Three comparisons are done:
                // 1 done flag (no further processing if an abstraction already matched)
                // 2 abstraction size
                // 3 abstraction characters
                //
                // The order is important!
                // The size needs to be checked before the arrays are handed over to the
                // comparison procedure. Otherwise, array boundaries might get crossed.
                //

                //
                // Compound.
                //

                if (d == 0) {

                    if (*ac == COMPOUND_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_compound(p0, p1);
                            initialize_compound(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                //
                // Logic and Dynamics.
                //

                if (d == 0) {

                    if (*ac == OPERATION_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_operation(p0, p1);
                            initialize_operation(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                //
                // Statics.
                //

                if (d == 0) {

                    if (*ac == STRING_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            initialize_string(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_boolean(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == INTEGER_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_integer(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == VECTOR_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_vector(p0, p1);
                            initialize_vector(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_double(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == FRACTION_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_fraction(p0, p1);
                            initialize_fraction(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_complex(p0, p1);
                            initialize_complex(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == TIME_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_time(p0, p1);
                            initialize_time(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret model. The persistent model count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret model. The abstraction count is null.");
    }
}

/**
 * Creates a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 * @param p4 the abstraction
 * @param p5 the abstraction count
 * @param p6 the location
 * @param p7 the location count
 */
void create_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6, const void* p7) {

    // The buffer array.
    void* b = NULL_POINTER;
    // The buffer array count.
    int bc = 0;
    // The buffer array size.
    int bs = 0;

    // Create buffer array.
    create_array((void*) &b, (void*) &INTEGER_ARRAY, (void*) &bs);

    // Read persistent model from location into buffer array.
    read_model((void*) &b, (void*) &bc, (void*) &bs, p2, p3, p6, p7);

    // Create and initialize transient model from buffer array.
    interpret_model(p0, p1, (void*) &b, (void*) &bc, p4, p5);

    // Destroy buffer array.
    destroy_array((void*) &b, (void*) &INTEGER_ARRAY, (void*) &bs);
}

/**
 * OLD DOCUMENTATION --> delete when not needed anymore!
 *
 * Creates a transient model from a persistent model.
 *
 * Structure of part_model for create_model or destroy_model operation:
 * - operation
 * - whole model of created/destroyed part model
 * - name
 * - part_abstraction
 * - part_location
 * - part_model
 * - position_abstraction
 * - position_location
 * - position_model
 * - constraint_abstraction
 * - constraint_location
 * - constraint_model
 *
 * Not all of these parameters are needed. Those at the end
 * (for example for position and constraint) can be left out.
 * Caution:
 * It is not possible to leave out parameters in between,
 * because then the order of parameters will get mixed up!
 *
 * Example:
 * <part name="create_find_dialog"
 *     part_abstraction="operation"
 *     part_location="inline"
 *     part_model="
 *         create_model,
 *         application.gui,
 *         find_dialog,
 *         compound,
 *         file,
 *         application/find_dialog.cybol"/>
 *
 * @param p0 the whole
 * @param p1 the ??
 * @param p2 the name
 * @param p3 the name size
 * @param p4 the part abstraction
 * @param p5 the part abstraction size
 * @param p6 the part location
 * @param p7 the part location size
 * @param p8 the part model
 * @param p9 the part model size
 * @param p10 the position abstraction
 * @param p11 the position abstraction size
 * @param p12 the position location
 * @param p13 the position location size
 * @param p14 the position model
 * @param p15 the position model size
 * @param p16 the constraint abstraction
 * @param p17 the constraint abstraction size
 * @param p18 the constraint location
 * @param p19 the constraint location size
 * @param p20 the constraint model
 * @param p21 the constraint model size
 */
/*??
void create_model(void* p0, void* p1,
    const void* p2, const void* p3,
    const void* p4, const void* p5, const void* p6, const void* p7, const void* p8, const void* p9,
    const void* p10, const void* p11, const void* p12, const void* p13, const void* p14, const void* p15,
    const void* p16, const void* p17, const void* p18, const void* p19, const void* p20, const void* p21) {

    // 5 check if name exists in whole; if yes, add "_0" or "_1" or "_2" etc.
    //   to name, taking first non-existing suffix
    // 6 add transient model to whole with procedure:
    //   set_model_part_by_name(whole_model, name, name_size, ...)

    // Add to whole model (for example statics).
    set_model_part_by_name(p1, (void*) &param1, (void*) &param1s,
        (void*) &param2, (void*) &param2s, (void*) &param3, (void*) &param3s, (void*) &param4, (void*) &param4s,
        (void*) &param5, (void*) &param5s, (void*) &param6, (void*) &param6s, (void*) &param7, (void*) &param7s,
        (void*) &param8, (void*) &param8s, (void*) &param9, (void*) &param9s, (void*) &param10, (void*) &param10s);
}
*/

/* CREATE_MODEL_SOURCE */
#endif
