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
 * @version $Revision: 1.10 $ $Date: 2004-09-11 22:19:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include "../array/array.c"
#include "../creator/creator.c"
#include "../communicator/communicator.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../logger/logger.c"
#include "../parser/parser.c"
#include "../translator/translator.c"

/**
 * Checks for primitive model.
 *
 * @param p0 the primitive flag (1 if primitive; 0 otherwise)
 * @param p1 the abstraction
 * @param p2 the abstraction count
 */
void check_primitive_model(void* p0, const void* p1, const void* p2) {

    if (p0 != NULL_POINTER) {

        int* p = (int*) p0;

        // The done flag.
        int d = 0;

        // The following comparisons could also be done one after the other,
        // without "done" flag. But the done flag avoids unnecessary comparisons.

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &DOUBLE_ABSTRACTION, (void*) &DOUBLE_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &BOOLEAN_ABSTRACTION, (void*) &BOOLEAN_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &VECTOR_ABSTRACTION, (void*) &VECTOR_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &FRACTION_ABSTRACTION, (void*) &FRACTION_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &TIME_ABSTRACTION, (void*) &TIME_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

        if (d == 0) {

            compare_arrays(p1, p2, (void*) &COMPLEX_ABSTRACTION, (void*) &COMPLEX_ABSTRACTION_COUNT, p0, (void*) &CHARACTER_ARRAY);

            if (*p == 1) {

                d = 1;
            }
        }

    } else {

//??        log_message((void*) &ERROR_LOG_LEVEL, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE, (void*) &COULD_NOT_HANDLE_CREATE_MODEL_SIGNAL_THE_KNOWLEDGE_SIZE_IS_NULL_MESSAGE_COUNT);
    }
}

/**
 * Creates a primitive model.
 *
 * The creation happens in 2 steps and 3 models are involved.
 *
 * 1 source code: persistent, probably stored in files, for example cybol/xml
 * 2 receive model: transient byte/character stream, as read from channel/location
 * 3 parse model: transient model that cyboi works with, that is cyboi internal model
 *
 * The "received model" and "parsed model" are temporary helper models;
 * they get created and destroyed during creation handling.
 *
 *                receive                           parse
 * source code  ----------> received/read model  ----------> parsed model
 * (persistent)             (transient)                      (transient)
 *
 * The counterparts of the creation procedures are:
 * - receive <--> send (read <--> write)
 * - parse <--> serialize
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_primitive_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    create((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

    // Receive persistent byte stream over channel.
    receive_general((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // Create parse model of type given as abstraction.
    create(p0, p2, p5, p6);

    // Parse byte stream according to given document type.
    parse(p0, p1, p2, (void*) &rm, (void*) &rmc, p5, p6);

    // Destroy receive model.
    destroy((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);
}

/**
 * Creates a model.
 *
 * The creation happens in 3 steps and 4 models are involved.
 *
 * 1 source code: persistent, probably stored in files, for example cybol/xml
 * 2 receive model: transient byte/character stream, as read from channel/location
 * 3 parse model: transient model representing the structure of the parsed document,
 *   for example xml dom tree
 * 4 decode model: transient model that cyboi works with, that is cyboi internal model
 *
 * The "received model" and "parsed model" are temporary helper models;
 * they get created and destroyed during creation handling.
 *
 *                receive                           parse                   decode
 * source code  ----------> received/read model  ----------> parsed model ----------> decoded model
 * (persistent)             (transient)                      (transient)              (transient)
 *
 * The counterparts of the creation procedures are:
 * - receive <--> send (read <--> write)
 * - parse <--> serialize
 * - decode <--> encode
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_compound_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    // The temporary workaround flag to use the libxml2 parser.
    //?? Later, when an own xml parser is implemented in cyboi,
    //?? delete this flag and change the corresponding blocks below!
    int w = 0;

    compare_arrays(p5, p6, (void*) &XML_ABSTRACTION, (void*) &XML_ABSTRACTION_COUNT,
        (void*) &w, (void*) &CHARACTER_ARRAY);

    //
    // Receive.
    //

    // The receive model.
    void* rm = NULL_POINTER;
    int rmc = 0;
    int rms = 0;

    // Create receive model of type character, to read single bytes.
    create((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

    // Receive persistent byte stream over channel.
    receive_general((void*) &rm, (void*) &rmc, (void*) &rms, p3, p4, p7, p8);

    //
    // Parse.
    //

    // The parse model.
    void* pm = NULL_POINTER;
    int pmc = 0;
    int pms = 0;

    if (w == 0) {

        // Create parse model of type given as abstraction.
        create((void*) &pm, (void*) &pms, p5, p6);

        // Parse byte stream according to given document type.
        parse((void*) &pm, (void*) &pmc, (void*) &pms,
            (void*) &rm, (void*) &rmc, p5, p6);

    } else {

        parse((void*) &pm, (void*) &pmc, (void*) &pms, p3, p4, p5, p6);
    }

    // Destroy receive model.
    destroy((void*) &rm, (void*) &rms,
        (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT);

    //
    // Decode.
    //

    // Create compound decode model.
    create(p0, p2, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT);

    // Decode document model according to given document type.
    decode(p0, p1, p2, (void*) &pm, (void*) &pmc, p5, p6);

    if (w == 0) {

        // Destroy parsed model.
        destroy((void*) &pm, (void*) &pms, p5, p6);

    } else {

        // Free xml dom document.
        xmlFreeDoc((xmlDoc*) pm);
    }
}

/**
 * Creates a transient destination model from a persistent source model.
 *
 * Primitive models need a different creation than compound models.
 *
 * persistent:
 * - stored permanently
 * - outside CYBOI
 * - longer than CYBOI lives
 *
 * transient:
 * - stored in computer memory (RAM)
 * - only accessible from within CYBOI
 * - created and destroyed by CYBOI
 * - not available anymore after CYBOI has been destroyed
 *
 * @param p0 the destination
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source model
 * @param p4 the source model count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source channel
 * @param p8 the source channel count
 */
void create_model(void* p0, void* p1, void* p2, const void* p3, const void* p4,
    const void* p5, const void* p6, const void* p7, const void* p8) {

    // The primitive flag.
    int p = 0;

    // Check for primitive model.
    check_primitive_model((void*) &p, p5, p6);

    if (p == 1) {

        create_primitive_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    } else {

        create_compound_model(p0, p1, p2, p3, p4, p5, p6, p7, p8);
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
void handle_create(const void* p0, const void* p1, const void* p2, const void* p3,
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

                        // The persistent whole name.
                        void* pwn = NULL_POINTER;
                        int pwnc = 0;
                        int pwns = 0;

                        // Initialize persistent part name,
                        // part abstraction, location, model, constraint.
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
                            }

                            j++;
                        }

                        // The transient whole model.
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

/*??
                            // If a persistent whole model name exists, the transient
                            // whole model is determined within the knowledge root.
                            // Abstraction and constraints as well as the model's
                            // position within the knowledge root are not of interest.
                            get_compound_element_by_name(p4, p5, p6,
                                (void*) &pwn, (void*) &pwnc, (void*) &pwns,
                                (void*) &twm, (void*) &twmc, (void*) &twms,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER,
                                (void*) &NULL_POINTER, (void*) &NULL_POINTER, (void*) &NULL_POINTER);
*/
                        }

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
