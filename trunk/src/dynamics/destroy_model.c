/*
 * $RCSfile: destroy_model.c,v $
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
 * This file destroys a transient model to a persistent model.
 *
 * @version $Revision: 1.20 $ $Date: 2004-05-27 13:52:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_MODEL_SOURCE
#define DESTROY_MODEL_SOURCE

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
 * Writes a persistent model from an array.
 *
 * Possible model locations are:
 * - inline
 * - file
 * - ftp
 * - http
 *
 * @param p0 the buffer array
 * @param p1 the buffer array count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 * @param p4 the location
 * @param p5 the location count
 */
void write_model(const void* p0, const void* p1, void* p2, void* p3, const void* p4, const void* p5) {

    if (p5 != NULL_POINTER) {

        int* lc = (int*) p5;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*lc == INLINE_LOCATION_COUNT) {

                compare_array_elements(p4, (void*) &INLINE_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &INLINE_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    write_inline(p0, p1, p2, p3);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == FILE_LOCATION_COUNT) {

                compare_array_elements(p4, (void*) &FILE_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &FILE_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    write_file(p0, p1, p2, p3);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == FTP_LOCATION_COUNT) {

                compare_array_elements(p4, (void*) &FTP_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &FTP_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    write_ftp(p0, p1, p2, p3);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == HTTP_LOCATION_COUNT) {

                compare_array_elements(p4, (void*) &HTTP_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &HTTP_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    write_http(p0, p1, p2, p3);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not write model. The location count is null.");
    }
}

/**
 * Serializes a transient model to a persistent model.
 *
 * Finalizes and destroys the transient model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the persistent model
 * @param p3 the persistent model count
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void serialize_model(void* p0, void* p1, void* p2, void* p3, const void* p4, const void* p5) {

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

                            finalize_compound(p0, p1, p2, p3);
                            destroy_compound(p0, p1);

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

                            finalize_operation(p0, p1, p2, p3);
                            destroy_operation(p0, p1);

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

                            finalize_string(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_boolean(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == INTEGER_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_integer(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == VECTOR_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_vector(p0, p1, p2, p3);
                            destroy_vector(p0, p1);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No destruction because primitive type.
                            finalize_double(p0, p1, p2, p3);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == FRACTION_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_fraction(p0, p1, p2, p3);
                            destroy_fraction(p0, p1);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_complex(p0, p1, p2, p3);
                            destroy_complex(p0, p1);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == TIME_ABSTRACTION_COUNT) {

                        compare_array_elements(p4, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            finalize_time(p0, p1, p2, p3);
                            destroy_time(p0, p1);

                            d = 1;
                        }
                    }
                }
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not serialize model. The persistent model count is null.");
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not serialize model. The abstraction count is null.");
    }
}

/**
 * Destroys a model.
 *
 * @param p0 the transient model
 * @param p1 the transient model size
 * @param p2 the persistent model
 * @param p3 the persistent model size
 * @param p4 the abstraction
 * @param p5 the abstraction size
 * @param p6 the location
 * @param p7 the location size
 */
void destroy_model(void* p0, void* p1, const void* p2, const void* p3, const void* p4, const void* p5, const void* p6, const void* p7) {

    // The buffer array.
    void* b = NULL_POINTER;
    // The buffer array count.
    int bc = 0;

    // Create buffer array.
    create_array((void*) &b, (void*) &INTEGER_ARRAY, (void*) &bc);

    // Finalize transient model to buffer array and destroy it.
    serialize_model(p0, p1, (void*) &b, (void*) &bc, p4, p5);

    // Write buffer array as persistent model to location.
//??    write_model((void*) &b, (void*) &bc, p2, p3, p6, p7);

    // Destroy buffer array.
    destroy_array((void*) &b, (void*) &INTEGER_ARRAY, (void*) &bc);
}

/* DESTROY_MODEL_SOURCE */
#endif
