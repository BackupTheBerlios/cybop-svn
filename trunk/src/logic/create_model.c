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
 * @version $Revision: 1.4 $ $Date: 2004-06-15 11:31:08 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_MODEL_SOURCE
#define CREATE_MODEL_SOURCE

#include "../cybol/file.c"
#include "../logger/logger.c"
#include "../state/boolean.c"
#include "../state/complex.c"
#include "../state/compound.c"
#include "../state/double.c"
#include "../state/fraction.c"
#include "../state/integer.c"
#include "../state/operation.c"
#include "../state/string.c"
#include "../state/time.c"
#include "../state/vector.c"

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
 * @param p3 the persistent location
 * @param p4 the persistent location count
 * @param p5 the persistent model
 * @param p6 the persistent model count
 */
void read_model(void* p0, void* p1, void* p2, const void* p3, const void* p4, const void* p5, const void* p6) {

    if (p4 != NULL_POINTER) {

        int* lc = (int*) p4;

        // The done flag.
        int d = 0;
        // The comparison result.
        int r = 0;

        if (d == 0) {

            if (*lc == INLINE_LOCATION_COUNT) {

                compare_array_elements(p3, (void*) &INLINE_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &INLINE_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_inline(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == FILE_LOCATION_COUNT) {

                compare_array_elements(p3, (void*) &FILE_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &FILE_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_file(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == FTP_LOCATION_COUNT) {

                compare_array_elements(p3, (void*) &FTP_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &FTP_LOCATION_COUNT, (void*) &r);

                if (r == 1) {

                    read_ftp(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*lc == HTTP_LOCATION_COUNT) {

                compare_array_elements(p3, (void*) &HTTP_LOCATION, (void*) &CHARACTER_ARRAY, (void*) &HTTP_LOCATION_COUNT, (void*) &r);

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
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
void interpret_model(void* p0, void* p1, void* p2, const void* p3, const void* p4, const void* p5, const void* p6) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p6 != NULL_POINTER) {

        int* ac = (int*) p6;

        if (p4 != NULL_POINTER) {

            int* pc = (int*) p4;

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

                        compare_array_elements(p5, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_compound(p0, p2);
                            initialize_compound(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                //
                // Logic and Dynamics.
                //

                if (d == 0) {

                    if (*ac == OPERATION_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_operation(p0, p2);

    fprintf(stderr, "pa 1: %i\n", *((void**) p0));
    fprintf(stderr, "pac 1: %i\n", *((int*) p2));

                            initialize_operation(p0, p1, p2, p3, p4);

    //?? The ERROR lies in initialize_operation!!

    fprintf(stderr, "pa 2: %i\n", *((void**) p0));
    fprintf(stderr, "pac 2: %i\n", *((int*) p2));

                            d = 1;
                        }
                    }
                }

                //
                // Statics.
                //

                if (d == 0) {

                    if (*ac == STRING_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            initialize_string(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_boolean(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == INTEGER_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_integer(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == VECTOR_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_vector(p0, p2);
                            initialize_vector(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            // No creation because primitive type.
                            initialize_double(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == FRACTION_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_fraction(p0, p2);
                            initialize_fraction(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_complex(p0, p2);
                            initialize_complex(p0, p1, p2, p3, p4);

                            d = 1;
                        }
                    }
                }

                if (d == 0) {

                    if (*ac == TIME_ABSTRACTION_COUNT) {

                        compare_array_elements(p5, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                        if (r == 1) {

                            create_time(p0, p2);
                            initialize_time(p0, p1, p2, p3, p4);

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
 * @param p2 the transient model size
 * @param p3 the persistent abstraction
 * @param p4 the persistent abstraction count
 * @param p5 the persistent location
 * @param p6 the persistent location count
 * @param p7 the persistent model
 * @param p8 the persistent model count
 */
void create_model(void* p0, void* p1, void* p2,
    const void* p3, const void* p4,
    const void* p5, const void* p6,
    const void* p7, const void* p8) {

    if (p2 != NULL_POINTER) {

        int* tms = (int*) p2;

        if (p1 != NULL_POINTER) {

            int* tmc = (int*) p1;

            if (p0 != NULL_POINTER) {

                void** tm = (void**) p0;

                // Initialize buffer array and its count and size.
                void* b = NULL_POINTER;
                int bc = 0;
                int bs = 0;

                // Create buffer array of type character to read single bytes.
                create_array((void*) &b, (void*) &CHARACTER_ARRAY, (void*) &bs);

    fprintf(stderr, "pl: %s\n", *((char**) p5));
    fprintf(stderr, "plc: %i\n", *((int*) p6));
    fprintf(stderr, "pm: %s\n", *((char**) p7));
    fprintf(stderr, "pmc: %i\n", *((int*) p8));

                // Read persistent model from location into buffer array.
                read_model((void*) &b, (void*) &bc, (void*) &bs, p5, p6, p7, p8);

    fprintf(stderr, "b: %s\n", b);
    fprintf(stderr, "bs: %i\n", bs);
    fprintf(stderr, "bc: %i\n", bc);

    fprintf(stderr, "pa: %s\n", *((char**) p3));
    fprintf(stderr, "pac: %i\n", *((int*) p4));

                // Create and initialize transient model from buffer array.
                interpret_model((void*) &tm, (void*) &tmc, (void*) &tms, (void*) &b, (void*) &bc, p3, p4);

    fprintf(stderr, "tm: %i\n", tm);
    fprintf(stderr, "tms: %i\n", tms);
    fprintf(stderr, "tmc: %i\n", tmc);

                // Destroy buffer array.
                destroy_array((void*) &b, (void*) &CHARACTER_ARRAY, (void*) &bs);

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_CREATE_MODEL_THE_TRANSIENT_MODEL_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/* CREATE_MODEL_SOURCE */
#endif
