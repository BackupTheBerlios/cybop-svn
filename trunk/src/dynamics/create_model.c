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
 * @version $Revision: 1.22 $ $Date: 2004-05-13 08:24:10 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

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

    // 1 read location --> call according procedure, e.g. read_from_file
    // 2 read byte data from location://model or inline:/model into array
    // 3 create transient model
    //   (use and rename current "create_model" procedure for this)
    // 4 interpret data in array according to abstraction ("initialize"),
    //   that is parse array and copy/set data in transient model
    // 5 check if name exists in whole; if yes, add "_0" or "_1" or "_2" etc.
    //   to name, taking first non-existing suffix
    // 6 add transient model to whole with procedure:
    //   set_model_part_by_name(whole_model, name, name_size, ...)

                void* m = NULL_POINTER;
                int ms = 0;

                // TODO: Move reading from: inline, file, ftp etc.
                // out of compound::initialize into general create_model procedure!
                // Reason: also a boolean or integer value may be read from file,
                // and not only inline.
                // --> add additional "location" parameter to create_model procedure!

/*??
                // Add to whole model (for example statics).
                set_model_part_by_name(p1, (void*) &param1, (void*) &param1s,
                    (void*) &param2, (void*) &param2s, (void*) &param3, (void*) &param3s, (void*) &param4, (void*) &param4s,
                    (void*) &param5, (void*) &param5s, (void*) &param6, (void*) &param6s, (void*) &param7, (void*) &param7s,
                    (void*) &param8, (void*) &param8s, (void*) &param9, (void*) &param9s, (void*) &param10, (void*) &param10s);
*/
/*??
}
*/

/**
 * Creates a transient model from a persistent model.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 * @param p4 the abstraction
 * @param p5 the abstraction size
 */
void create_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p5 != NULL_POINTER) {

        int* s = (int*) p5;

        if (p3 != NULL_POINTER) {

            int* ps = (int*) p3;

            // Only proceed, if persistent model is not empty.
            if (*ps > 0) {

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

                    if (*s == COMPOUND_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            create_compound(p0);
                            initialize_compound(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                //
                // Logic and Dynamics.
                //

                if (d == 0) {

                    if (*s == OPERATION_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_SIZE, (void*) &r);

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

                    if (*s == STRING_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            initialize_string(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == BOOLEAN_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_boolean(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == INTEGER_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_integer(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == VECTOR_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            create_vector(p0);
                            initialize_vector(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == DOUBLE_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_double(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == FRACTION_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            create_fraction(p0);
                            initialize_fraction(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == COMPLEX_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            create_complex(p0);
                            initialize_complex(p0, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*s == TIME_ABSTRACTION_SIZE) {

                        compare_array_elements(p4, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_SIZE, (void*) &r);

                        if (r == 1) {

                            create_time(p0);
                            initialize_time(p0, p2, p3);

                            d = 1;
                        }
                    }
                }
            }

        } else {

            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create model. The persistent model size is null.");
        }

    } else {

        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not create model. The abstraction size is null.");
    }
}

/* CREATE_MODEL_SOURCE */
#endif
