/*
 * $RCSfile: create.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2004-07-28 22:46:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include "../logger/logger.c"
#include "../parser/xml_parser.c"
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
#include "../state/xml_tag.c"
#include "../transfer/file.c"
#include "../transfer/ftp.c"
#include "../transfer/http.c"
#include "../transfer/inline.c"
#include "../translator/xml_translator.c"

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
 * @param p5 the persistent location
 * @param p6 the persistent location count
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
 * Creates a transient model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the abstraction
 * @param p4 the abstraction count
 */
void create_model(void* p0, void* p1, void* p2, const void* p3, const void* p4) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p4 != NULL_POINTER) {

        int* ac = (int*) p4;

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

                compare_array_elements(p3, (void*) &COMPOUND_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_compound(p0, p2);

                    d = 1;
                }
            }
        }

        //
        // Logic.
        //

        if (d == 0) {

            if (*ac == OPERATION_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_operation(p0, p2);

                    d = 1;
                }
            }
        }

        //
        // State.
        //

        if (d == 0) {

            if (*ac == STRING_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &STRING_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_string(p0, p2);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == BOOLEAN_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &BOOLEAN_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &BOOLEAN_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    // No creation because primitive type.

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == INTEGER_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    // No creation because primitive type.

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == VECTOR_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_vector(p0, p2);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    // No creation because primitive type.

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == FRACTION_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_fraction(p0, p2);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_complex(p0, p2);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == TIME_ABSTRACTION_COUNT) {

                compare_array_elements(p3, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    create_time(p0, p2);

                    d = 1;
                }
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret model. The abstraction count is null.");
    }
}

/**
 * Initializes a transient model from a persistent model.
 *
 * @param p0 the transient model
 * @param p1 the transient model count
 * @param p2 the transient model size
 * @param p3 the persistent model
 * @param p4 the persistent model count
 * @param p5 the abstraction
 * @param p6 the abstraction count
 */
void initialize_model(void* p0, void* p1, void* p2, const void* p3, const void* p4, const void* p5, const void* p6) {

    // The done flag.
    int d = 0;
    // The comparison result.
    int r = 0;

    if (p6 != NULL_POINTER) {

        int* ac = (int*) p6;

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

                    // Initialize xml model
                    // and its count and size.
                    void* m = NULL_POINTER;
                    int mc = 0;
                    int ms = 0;

                    // Create xml model.
                    create_xml_tag((void*) &m, (void*) &ms);

                    // Parse persistent stream into xml model.
                    parse_xml((void*) &m, (void*) &mc, (void*) &ms, p3, p4);

                    // Decode xml model into knowledge model compound.
                    decode_xml(p0, p1, p2, (void*) &m, (void*) &mc);

                    // Destroy xml model.
                    destroy_xml_tag((void*) &m, (void*) &ms);

                    d = 1;
                }
            }
        }

        //
        // Logic.
        //

        if (d == 0) {

            if (*ac == OPERATION_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &OPERATION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_operation(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        //
        // State.
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

                    initialize_boolean(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == INTEGER_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &INTEGER_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &INTEGER_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_integer(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == VECTOR_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &VECTOR_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &VECTOR_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_vector(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == DOUBLE_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &DOUBLE_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &DOUBLE_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_double(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == FRACTION_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &FRACTION_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &FRACTION_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_fraction(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == COMPLEX_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &COMPLEX_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &COMPLEX_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_complex(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

        if (d == 0) {

            if (*ac == TIME_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &TIME_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &TIME_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    initialize_time(p0, p1, p2, p3, p4);

                    d = 1;
                }
            }
        }

/*??
        if (d == 0) {

            if (*ac == SXW_ABSTRACTION_COUNT) {

                compare_array_elements(p5, (void*) &SXW_ABSTRACTION, (void*) &CHARACTER_ARRAY, (void*) &SXW_ABSTRACTION_COUNT, (void*) &r);

                if (r == 1) {

                    //?? For other kinds of file (stream) formats,
                    //?? for example from special applications like Open Office,
                    //?? use a similar handling like for compound above!

                    //?? Images possibly also have to be handled that way.
                    //?? At first, the single image parameters have to be parsed
                    //?? and written into a special parameter model in memory;
                    //?? then that model has to be decoded into a knowledge model!
                    //?? May be this idea is rubbish and will not work!
                    //?? For the beginning better handle images as primitve types.

                    d = 1;
                }
            }
        }
*/

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &"Could not interpret model. The abstraction count is null.");
    }
}

/**
 * Creates a transient copy of a persistent source.
 *
 * CYBOL Examples:
 *
 * <!-- Operation parameters (as value of part_model tag):
 *      logic name,whole name,part name,
 *      part abstraction,part location,part model,part constraints,
 *      position abstraction,position location,position model,position constraints /-->
 *
 * <part name="create_domain" part_abstraction="operation" part_location="inline"
 *      part_model="create,,domain,compound,file,/helloworld/domain.cybol,null,null,null,null,null"/>
 *
 * <part name="create_find_dialog" part_abstraction="operation" part_location="inline"
 *      part_model="create,application.gui,find_dialog,compound,file,application/find_dialog.cybol,,
 *          vector,inline,100;100;0,x<1000;y<1000;z=0"/>
 *
 * @param p0 the signal parameters count
 * @param p1 the parameters
 * @param p2 the parameters counts
 * @param p3 the parameters sizes
 * @param p4 the knowledge
 * @param p5 the knowledge count
 * @param p6 the knowledge size
 */
void create(const void* p0, const void* p1, const void* p2, const void* p3,
    void* p4, void* p5, void* p6) {

    if (p6 != NULL_POINTER) {

        int* ks = (int*) p6;

        if (p5 != NULL_POINTER) {

            int* kc = (int*) p5;

            if (p4 != NULL_POINTER) {

                void** k = (void**) p4;

                if (p0 != NULL_POINTER) {

                    int* sc = (int*) p0;

                    if (*sc == 11) {

                        // Initialize persistent whole name and its count and size.
                        void* pwn = NULL_POINTER;
                        int pwnc = 0;
                        int pwns = 0;

                        // Initialize persistent part name,
                        // part abstraction, location, model, constraint,
                        // position abstraction, location, model, constraint,
                        // and their counts and sizes.
                        void* ppn = NULL_POINTER;
                        int ppnc = 0;
                        int ppns = 0;
                        void* ppa = NULL_POINTER;
                        int ppac = 0;
                        int ppas = 0;
                        void* ppl = NULL_POINTER;
                        int pplc = 0;
                        int ppls = 0;
                        void* ppm = NULL_POINTER;
                        int ppmc = 0;
                        int ppms = 0;
                        void* ppc = NULL_POINTER;
                        int ppcc = 0;
                        int ppcs = 0;
                        void* ppoa = NULL_POINTER;
                        int ppoac = 0;
                        int ppoas = 0;
                        void* ppol = NULL_POINTER;
                        int ppolc = 0;
                        int ppols = 0;
                        void* ppom = NULL_POINTER;
                        int ppomc = 0;
                        int ppoms = 0;
                        void* ppoc = NULL_POINTER;
                        int ppocc = 0;
                        int ppocs = 0;

                        // CAUTION! The parameter at index 0 is the logic/ operation name.
                        // Input and output parameters start with index 1.

                        // The loop variable.
                        int j = 1;

                        while (1) {

                            if (j >= *sc) {

                                break;
                            }

                            // CAUTION! The parameter at index 0 is the logic/ operation name.
                            // Input and output parameters start with index 1.

                            if (j == 1) {

                                // Get persistent whole name and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &pwn);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pwnc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pwns);

                            } else if (j == 2) {

                                // Get persistent part name and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppn);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppnc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppns);

                            } else if (j == 3) {

                                // Get persistent part abstraction and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppa);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppac);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppas);

                            } else if (j == 4) {

                                // Get persistent part location and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppl);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &pplc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppls);

                            } else if (j == 5) {

                                // Get persistent part model and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppm);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppmc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppms);

                            } else if (j == 6) {

                                // Get persistent part constraints and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppc);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppcc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppcs);

                            } else if (j == 7) {

                                // Get persistent position abstraction and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppoa);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppoac);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppoas);

                            } else if (j == 8) {

                                // Get persistent position location and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppol);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppolc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppols);

                            } else if (j == 9) {

                                // Get persistent position model and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppom);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppomc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppoms);

                            } else if (j == 10) {

                                // Get persistent position constraints and its count and size.
                                get_array_element(p1, (void*) &POINTER_ARRAY, (void*) &j, (void*) &ppoc);
                                get_array_element(p2, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppocc);
                                get_array_element(p3, (void*) &INTEGER_ARRAY, (void*) &j, (void*) &ppocs);
                            }

                            j++;
                        }

                        // Initialize transient whole model and its count and size.
                        void* twm = NULL_POINTER;
                        int twmc = 0;
                        int twms = 0;

                        // Get transient whole model.
                        if (pwn == NULL_POINTER) {

                            // If the persistent whole model name is null, the
                            // knowledge root is taken as transient whole model.
                            twm = *k;
                            twmc = *kc;
                            twms = *ks;

                        } else {

                            // If a persistent whole model name exists, the transient
                            // whole model is determined within the knowledge root.
                            // Abstraction and constraints as well as the model's
                            // position within the knowledge root are not of interest.
                            get_compound_part_by_name(p4, p5, p6,
                                (void*) &pwn, (void*) &pwnc, (void*) &pwns,
                                (void*) &twm, (void*) &twmc, (void*) &twms,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
                        }

                        // Initialize transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        // CAUTION! A transient location is not stored,
                        // since that is only needed temporarily
                        // for model loading.
                        void* tpn = NULL_POINTER;
                        int tpnc = 0;
                        int tpns = 0;
                        void* tpa = NULL_POINTER;
                        int tpac = 0;
                        int tpas = 0;
                        void* tpm = NULL_POINTER;
                        int tpmc = 0;
                        int tpms = 0;
                        void* tpc = NULL_POINTER;
                        int tpcc = 0;
                        int tpcs = 0;
                        void* tpoa = NULL_POINTER;
                        int tpoac = 0;
                        int tpoas = 0;
                        void* tpom = NULL_POINTER;
                        int tpomc = 0;
                        int tpoms = 0;
                        void* tpoc = NULL_POINTER;
                        int tpocc = 0;
                        int tpocs = 0;

                        // Create transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        create_model((void*) &tpn, (void*) &tpnc, (void*) &tpns,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        create_model((void*) &tpa, (void*) &tpac, (void*) &tpas,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        create_model((void*) &tpm, (void*) &tpmc, (void*) &tpms,
                            (void*) &ppa, (void*) &ppac);
                        create_model((void*) &tpc, (void*) &tpcc, (void*) &tpcs,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        create_model((void*) &tpoa, (void*) &tpoac, (void*) &tpoas,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        create_model((void*) &tpom, (void*) &tpomc, (void*) &tpoms,
                            (void*) &ppoa, (void*) &ppoac);
                        create_model((void*) &tpoc, (void*) &tpocc, (void*) &tpocs,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

                        // Initialize part model- and position model buffer
                        // and their counts and sizes.
                        void* pmb = NULL_POINTER;
                        int pmbc = 0;
                        int pmbs = 0;
                        void* pomb = NULL_POINTER;
                        int pombc = 0;
                        int pombs = 0;

                        // Create part model- and position model buffer
                        // of type character to read single bytes.
                        create_array((void*) &pmb, (void*) &CHARACTER_ARRAY, (void*) &pmbs);
                        create_array((void*) &pomb, (void*) &CHARACTER_ARRAY, (void*) &pombs);

                        // Read persistent model from location into
                        // part model- and position model buffer.
                        read_model((void*) &pmb, (void*) &pmbc, (void*) &pmbs,
                            (void*) &ppm, (void*) &ppmc, (void*) &ppl, (void*) &pplc);
                        read_model((void*) &pomb, (void*) &pombc, (void*) &pombs,
                            (void*) &ppom, (void*) &ppomc, (void*) &ppol, (void*) &ppolc);

                        // Initialize transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        initialize_model((void*) &tpn, (void*) &tpnc, (void*) &tpns,
                            (void*) &ppn, (void*) &ppnc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        initialize_model((void*) &tpa, (void*) &tpac, (void*) &tpas,
                            (void*) &ppa, (void*) &ppac,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        initialize_model((void*) &tpm, (void*) &tpmc, (void*) &tpms,
                            (void*) &pmb, (void*) &pmbc,
                            (void*) &ppa, (void*) &ppac);
                        initialize_model((void*) &tpc, (void*) &tpcc, (void*) &tpcs,
                            (void*) &ppc, (void*) &ppcc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        initialize_model((void*) &tpoa, (void*) &tpoac, (void*) &tpoas,
                            (void*) &ppoa, (void*) &ppoac,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
                        initialize_model((void*) &tpom, (void*) &tpomc, (void*) &tpoms,
                            (void*) &pomb, (void*) &pombc,
                            (void*) &ppoa, (void*) &ppoac);
                        initialize_model((void*) &tpoc, (void*) &tpocc, (void*) &tpocs,
                            (void*) &ppoc, (void*) &ppocc,
                            (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

                        // Destroy part model- and position model buffer.
                        destroy_array((void*) &pmb, (void*) &CHARACTER_ARRAY, (void*) &pmbs);
                        destroy_array((void*) &pomb, (void*) &CHARACTER_ARRAY, (void*) &pombs);

                        //?? If "add", then first check if name exists in whole;
                        //?? if yes, add "_0" or "_1" or "_2" etc.
                        //?? to name, taking first non-existing suffix!
                        //?? If "set", then just replace the model
                        //?? with equal name; but where to destroy it if
                        //?? no whole keeps a reference to it anymore?

                        // Set transient part name,
                        // part abstraction, model, constraint,
                        // position abstraction, model, constraint,
                        // and their counts and sizes.
                        set_compound_part_by_name((void*) &twm, (void*) &twmc, (void*) &twms,
                            (void*) &tpn, (void*) &tpnc, (void*) &tpns,
                            (void*) &tpm, (void*) &tpmc, (void*) &tpms,
                            (void*) &tpa, (void*) &tpac, (void*) &tpas,
                            (void*) &tpc, (void*) &tpcc, (void*) &tpcs,
                            (void*) &tpom, (void*) &tpomc, (void*) &tpoms,
                            (void*) &tpoa, (void*) &tpoac, (void*) &tpoas,
                            (void*) &tpoc, (void*) &tpocc, (void*) &tpocs);

                    } else {

//??                        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_DOES_NOT_MATCH_MESSAGE_COUNT);
                    }

                } else {

//??                    log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_SIGNAL_PARAMETERS_COUNT_IS_NULL_MESSAGE_COUNT);
                }

            } else {

//??                log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_IS_NULL_MESSAGE_COUNT);
            }

        } else {

//??            log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_COUNT_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_COUNT_IS_NULL_MESSAGE_COUNT);
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/* CREATE_SOURCE */
#endif
