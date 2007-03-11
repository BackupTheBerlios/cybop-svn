/*
 * $RCSfile: bdt_converter.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.9 $ $Date: 2007-03-11 20:09:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BDT_CONVERTER_SOURCE
#define BDT_CONVERTER_SOURCE

#include "../../globals/constants/xdt/bdt_field_constants.c"
#include "../../globals/constants/xdt/bdt_record_constants.c"
#include "../../globals/constants/xdt/xdt_field_name_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"
#include "../../memoriser/converter/character_vector_converter.c"
#include "../../memoriser/converter/date_time_converter.c"
#include "../../memoriser/converter/integer_vector_converter.c"

/**
 * Parses the bdt record medical practice data.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_medical_practice_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record medical practice data.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record medical practice data content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record medical practice data. The parse mode is null.");
    }
}

/**
 * Parses the bdt record data medium header.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_data_medium_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record data medium header.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record data medium header content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record data medium header. The parse mode is null.");
    }
}

/**
 * Parses the bdt record data medium footer.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_data_medium_footer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record data medium footer.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record data medium footer content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record data medium footer. The parse mode is null.");
    }
}

/**
 * Parses the bdt record data package header.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_data_package_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record data package header.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record data package header content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record data package header. The parse mode is null.");
    }
}

/**
 * Parses the bdt record data package footer.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_data_package_footer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record data package footer.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record data package footer content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record data package footer. The parse mode is null.");
    }
}

/**
 * Parses the bdt record medical treatment.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_medical_treatment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record medical treatment.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record medical treatment content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record medical treatment. The parse mode is null.");
    }
}

/**
 * Parses the bdt record patient master data.
 *
 * @param p0 the destination knowledge model name (Hand over as reference!)
 * @param p1 the destination knowledge model name count
 * @param p2 the destination knowledge model name size
 * @param p3 the destination knowledge model abstraction (Hand over as reference!)
 * @param p4 the destination knowledge model abstraction count
 * @param p5 the destination knowledge model abstraction size
 * @param p6 the destination knowledge model model (Hand over as reference!)
 * @param p7 the destination knowledge model model count
 * @param p8 the destination knowledge model model size
 * @param p9 the field identification
 * @param p10 the field identification count
 * @param p11 the field content
 * @param p12 the field content count
 * @param p13 the parse mode
 */
void parse_bdt_record_patient_master_data(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13) {

    if (p13 != NULL_POINTER) {

        int* m = (int*) p13;

        log_message_debug("Information: Parse bdt record patient master data.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p9, p10, (void*) PATIENT_LAST_NAME_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Parse name.
                parse_character_vector(p0, p1, p2, PATIENT_LAST_NAME_XDT_FIELD_NAME, PATIENT_LAST_NAME_XDT_FIELD_NAME_COUNT);

                // Parse abstraction.
                parse_character_vector(p3, p4, p5, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Allocate model.
                allocate(p6, p8, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Parse model.
                parse_character_vector(p6, p7, p8, p11, p12);

    fprintf(stderr, "TEST parse patient master data last name: %s\n", *((char**) p6));
    fprintf(stderr, "TEST parse patient master data last name count: %i\n\n", *((int*) p7));
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p9, p10, (void*) PATIENT_FIRST_NAME_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Parse name.
                parse_character_vector(p0, p1, p2, PATIENT_FIRST_NAME_XDT_FIELD_NAME, PATIENT_FIRST_NAME_XDT_FIELD_NAME_COUNT);

                // Parse abstraction.
                parse_character_vector(p3, p4, p5, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Allocate model.
                allocate(p6, p8, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Parse model.
                parse_character_vector(p6, p7, p8, p11, p12);

    fprintf(stderr, "TEST parse patient master data first name: %s\n", *((char**) p6));
    fprintf(stderr, "TEST parse patient master data first name count: %i\n\n", *((int*) p7));
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p9, p10, (void*) PATIENT_BIRTH_DATE_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Parse name.
                parse_character_vector(p0, p1, p2, PATIENT_BIRTH_DATE_XDT_FIELD_NAME, PATIENT_BIRTH_DATE_XDT_FIELD_NAME_COUNT);

                // Parse abstraction.
                parse_character_vector(p3, p4, p5, (void*) DATE_TIME_ABSTRACTION, (void*) DATE_TIME_ABSTRACTION_COUNT);

                // Allocate model.
                allocate(p6, p8, (void*) DATE_TIME_ABSTRACTION, (void*) DATE_TIME_ABSTRACTION_COUNT);

                // Parse model.
                parse_ddmmyyyy_date_time(p6, p7, p8, p11, p12);

    fprintf(stderr, "TEST parse patient master data date: %i\n", **((int**) p6));
    fprintf(stderr, "TEST parse patient master data date count: %i\n\n", *((int*) p7));
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p9, p10, (void*) PATIENT_SEX_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

                // Parse name.
                parse_character_vector(p0, p1, p2, PATIENT_SEX_XDT_FIELD_NAME, PATIENT_SEX_XDT_FIELD_NAME_COUNT);

                // Parse abstraction.
                parse_character_vector(p3, p4, p5, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                // Allocate model.
                allocate(p6, p8, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

                // Parse model.
                parse_integer_vector(p6, p7, p8, p11, p12);

    fprintf(stderr, "TEST parse patient master data sex: %i\n", **((int**) p6));
    fprintf(stderr, "TEST parse patient master data sex count: %i\n\n", *((int*) p7));
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p9, p10, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record patient master data content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p11, p12);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record patient master data. The parse mode is null.");
    }
}

/**
 * Parses the bdt record medical treatment data.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the field identification
 * @param p4 the field identification count
 * @param p5 the field content
 * @param p6 the field content count
 * @param p7 the parse mode
 */
void parse_bdt_record_medical_treatment_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record medical treatment data.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record medical treatment data content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record medical treatment data. The parse mode is null.");
    }
}

/*??
        } else {

            // The valid flag is false, which means that no valid parse mode was
            // found and the knowledge model was left empty.
            // The empty knowledge model is therefore deallocated again.

            // Deallocate knowledge model name.
            deallocate((void*) &kmn, (void*) kmns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &kmnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &kmns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // A knowledge model channel is not received (deallocated),
            // since that is only needed temporarily for model loading.

            // Deallocate knowledge model abstraction.
            deallocate((void*) &kma, (void*) kmas, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &kmac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &kmas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // Deallocate knowledge model model.
            // CAUTION! If no valid parse mode was found, then no knowledge model model
            // was created, as this would have been done in one of the "parse" operations.
            // Therefore, the model does NOT have to get deallocated here.
            deallocate((void*) &kmmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &kmms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // The knowledge model details are set to null.
            // All data received are stored only in the knowledge model.
        }
*/

/**
 * Parses a bdt field.
 *
 * @param p0 the destination field size (Hand over as reference!)
 * @param p1 the destination field identification (Hand over as reference!)
 * @param p2 the destination field content (Hand over as reference!)
 * @param p3 the destination field content count (Hand over as reference!)
 * @param p4 the verification flag
 * @param p5 the source byte array
 * @param p6 the source byte array count
 */
void parse_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != NULL_POINTER) {

        int* sc = (int*) p6;

        if (p5 != NULL_POINTER) {

            char* s = (char*) p5;

            if (p4 != NULL_POINTER) {

                int* v = (int*) p4;

                if (p3 != NULL_POINTER) {

                    int* fcc = (int*) p3;

                    if (p2 != NULL_POINTER) {

                        void** fc = (void**) p2;

                        if (p0 != NULL_POINTER) {

                            int* fs = (int*) p0;

                            log_message_debug("Information: Parse bdt field.");

                            // The remaining bytes in the source byte array.
                            int rc = *sc;

                            if (rc >= *BDT_FIELD_SIZE_COUNT) {

                                // Parse bdt field size.
                                parse_integer(p0, NULL_POINTER, NULL_POINTER, s, (void*) BDT_FIELD_SIZE_COUNT);

                                // Increment source bdt byte array index.
                                s = s + *BDT_FIELD_SIZE_COUNT;
                                rc = rc - *BDT_FIELD_SIZE_COUNT;
                            }

                            if (rc >= *BDT_FIELD_IDENTIFICATION_COUNT) {

                                // Parse bdt field identification.
                                parse_integer(p1, NULL_POINTER, NULL_POINTER, s, (void*) BDT_FIELD_IDENTIFICATION_COUNT);

                                // Increment source bdt byte array index.
                                s = s + *BDT_FIELD_IDENTIFICATION_COUNT;
                                rc = rc - *BDT_FIELD_IDENTIFICATION_COUNT;
                            }

                            // Calculate bdt field content count.
                            //
                            // CAUTION! The bdt field size comprises all characters:
                            // - field size (3 bytes)
                            // - field identification (4 bytes)
                            // - field content (VARIABLE!)
                            // - carriage return (1 byte)
                            // - line feed (1 byte)
                            //
                            // It therefore has to be decremented here, so that
                            // only the actual bdt field content count remains.
                            *fcc = *fs - *BDT_FIELD_SIZE_COUNT - *BDT_FIELD_IDENTIFICATION_COUNT - *PRIMITIVE_COUNT - *PRIMITIVE_COUNT;

                            if (rc >= *fcc) {

                                // Store bdt field content, to be returned.
                                *fc = s;

                                // Increment source bdt byte array index.
                                s = s + *fcc;
                                rc = rc - *fcc;
                            }

                            if (rc >= (*PRIMITIVE_COUNT + *PRIMITIVE_COUNT)) {

                                // Verify if field end is reached (carriage return and line feed).

                                if (*s == *CARRIAGE_RETURN_CONTROL_ASCII_CHARACTER) {

                                    // Increment source bdt byte array index.
                                    s = s + *PRIMITIVE_COUNT;

                                    if (*s == *LINE_FEED_CONTROL_ASCII_CHARACTER) {

                                        *v = *NUMBER_1_INTEGER;
                                    }
                                }
                            }

                        } else {

                            log_message_debug("Error: Could not parse bdt field. The field size is null.");
                        }

                    } else {

                        log_message_debug("Error: Could not parse bdt field. The field content is null.");
                    }

                } else {

                    log_message_debug("Error: Could not parse bdt field. The field content count is null.");
                }

            } else {

                log_message_debug("Error: Could not parse bdt field. The verification flag is null.");
            }

        } else {

            log_message_debug("Error: Could not parse bdt field. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt field. The source count is null.");
    }
}

/**
 * Parses for the next bdt field.
 *
 * @param p0 the next field count = number of bytes to the next field (Hand over as reference!)
 * @param p1 the byte array
 * @param p2 the byte array count
 */
void parse_bdt_next_field(void* p0, void* p1, void* p2) {

    if (p2 != NULL_POINTER) {

        int* ac = (int*) p2;

        if (p1 != NULL_POINTER) {

            char* a = (char*) p1;

            if (p0 != NULL_POINTER) {

                int* nc = (int*) p0;

                log_message_debug("Information: Parse bdt next field.");

                // The loop variable.
                int j = *NUMBER_0_INTEGER;

                while (*NUMBER_1_INTEGER) {

                    if (j >= *ac) {

                        // Set next field count to the end, that is to the
                        // full array count, as the carriage return plus
                        // line feed characters have not been found or
                        // the remaining array count was too small.
                        *nc = *ac;

                        break;
                    }

                    if ((j + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT) <= *ac) {

                        if (*(a + j) == *CARRIAGE_RETURN_CONTROL_ASCII_CHARACTER) {

                            if (*(a + j + *PRIMITIVE_COUNT) == *LINE_FEED_CONTROL_ASCII_CHARACTER) {

                                // Set next field count to the first character following
                                // the carriage return plus line feed characters.
                                *nc = j + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT;

                                // The next field has been found, so that
                                // the loop can be left.
                                break;
                            }
                        }
                    }

                    // Increment loop variable.
                    j++;
                }

            } else {

                log_message_debug("Error: Could not parse for next bdt field. The next field count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse for next bdt field. The byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse for next bdt field. The byte array count is null.");
    }
}

/**
 * Processes the bdt field.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count (Hand over as reference!)
 * @param p2 the destination compound size (Hand over as reference!)
 * @param p3 the field content
 * @param p4 the field content count
 * @param p5 the field abstraction
 * @param p6 the field abstraction count
 * @param p7 the field name
 * @param p8 the field name count
 */
void parse_bdt_record_process_field(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Information: Parse bdt record process field.");

    // The knowledge model name.
    void* n = NULL_POINTER;
    int* nc = NULL_POINTER;
    int* ns = NULL_POINTER;
    // The knowledge model abstraction.
    void* a = NULL_POINTER;
    int* ac = NULL_POINTER;
    int* as = NULL_POINTER;
    // The knowledge model model.
    void* m = NULL_POINTER;
    int* mc = NULL_POINTER;
    int* ms = NULL_POINTER;
    // The knowledge model details.
    void* d = NULL_POINTER;
    int* dc = NULL_POINTER;
    int* ds = NULL_POINTER;

    // Allocate knowledge model name.
    allocate((void*) &nc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *nc = *NUMBER_0_INTEGER;
    allocate((void*) &ns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ns = *NUMBER_0_INTEGER;
    allocate((void*) &n, (void*) ns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // A knowledge model channel is not received (allocated),
    // since that is only needed temporarily for model loading.

    // Allocate knowledge model abstraction.
    allocate((void*) &ac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ac = *NUMBER_0_INTEGER;
    allocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *as = *NUMBER_0_INTEGER;
    allocate((void*) &a, (void*) as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Allocate knowledge model model.
    allocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *mc = *NUMBER_0_INTEGER;
    allocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ms = *NUMBER_0_INTEGER;
    allocate((void*) &m, (void*) ms, p5, p6);

    // Allocate knowledge model details.
    allocate((void*) &dc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *dc = *NUMBER_0_INTEGER;
    allocate((void*) &ds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ds = *NUMBER_0_INTEGER;
    allocate((void*) &d, (void*) ds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    // Parse name.
    parse_character_vector((void*) &n, (void*) nc, (void*) ns, p7, p8);
    // Parse abstraction.
    parse_character_vector((void*) &a, (void*) ac, (void*) as, p5, p6);
    // Parse model.
    parse((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds, p3, p4, p5, p6);

    // Add knowledge model to knowledge memory.
    set_compound_element_by_name(p0, p1, p2, NULL_POINTER, NULL_POINTER, NULL_POINTER,
        n, (void*) nc, (void*) ns,
        a, (void*) ac, (void*) as,
        m, (void*) mc, (void*) ms,
        d, (void*) dc, (void*) ds);
}

/**
 * Selects the bdt field.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count (Hand over as reference!)
 * @param p2 the destination compound size (Hand over as reference!)
 * @param p3 the field content
 * @param p4 the field content count
 * @param p5 the field identification
 */
void parse_bdt_record_select_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != NULL_POINTER) {

        int* id = (int*) p5;

        log_message_debug("Information: Parse bdt record select field.");

        if (*id == *RECORD_SIZE_BDT_FIELD) {

            parse_bdt_record_process_field(p0, p1, p2, p3, p4,
                (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT,
                (void*) RECORD_SIZE_XDT_FIELD_NAME, (void*) RECORD_SIZE_XDT_FIELD_NAME_COUNT);

        } else if (*id == *ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD) {

            parse_bdt_record_process_field(p0, p1, p2, p3, p4,
                (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME, (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_COUNT);
        }

    } else {

        log_message_debug("Error: Could not select bdt field. The field identification is null.");
    }
}

/**
 * Parses the bdt record.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count (Hand over as reference!)
 * @param p2 the destination compound size (Hand over as reference!)
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void parse_bdt_record(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            log_message_debug("Information: Parse bdt record.");

            // The remaining bytes in the source byte array.
            int rc = *sc;
            // The field size.
            int fs = *NUMBER_0_INTEGER;
            // The field identification.
            int fid = *NUMBER_0_INTEGER;
            // The field content.
            void* fc = NULL_POINTER;
            int fcc = *NUMBER_0_INTEGER;
            // The verification flag.
            int v = *NUMBER_0_INTEGER;
            // The next field count.
            int nc = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                if (rc <= *NUMBER_0_INTEGER) {

                    break;
                }

                // Parse bdt field (size, identification, content).
                parse_bdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, s, (void*) &rc);

                if (v == *NUMBER_1_INTEGER) {

                    // The verification flag is set, which means that
                    // the bdt field was parsed correctly and the carriage
                    // return plus line feed characters were reached.

                    // Increment source bdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + fs;
                    rc = rc - fs;

                    parse_bdt_record_select_field(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

                } else {

                    // The verification flag is NOT set, which means that
                    // the bdt field was NOT parsed correctly.

                    // Reset next field count.
                    nc = *NUMBER_0_INTEGER;

                    // Count the number of bytes to the next carriage return-
                    // plus line feed character.
                    parse_bdt_next_field((void*) &nc, s, (void*) &rc);

                    // Increment source bdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + nc;
                    rc = rc - nc;

                    log_message_debug("Error: Could not parse bdt record. An invalid field was detected. The parsing will now continue with the next valid field.");
                }
            }

        } else {

            log_message_debug("Error: Could not parse bdt record. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt record. The source count is null.");
    }
}

/**
 * Parses the bdt package.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count (Hand over as reference!)
 * @param p2 the destination model size (Hand over as reference!)
 * @param p3 the source bdt package byte stream
 * @param p4 the source bdt package byte stream count
 */
void parse_bdt_package(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            log_message_debug("Information: Parse bdt package.");

            // The remaining bytes in the source byte array.
            int rc = *sc;
            // The field size.
            int fs = *NUMBER_0_INTEGER;
            // The field identification.
            int fid = *NUMBER_0_INTEGER;
            // The field content.
            void* fc = NULL_POINTER;
            int fcc = *NUMBER_0_INTEGER;
            // The verification flag.
            int v = *NUMBER_0_INTEGER;
            // The record identification.
            int rid = *NUMBER_0_INTEGER;
            // The next field count.
            int nc = *NUMBER_0_INTEGER;
            // The parse mode.
            int m = *NUMBER_0_INTEGER;
            // The data package.
            void* p = NULL_POINTER;
            int pc = *NUMBER_0_INTEGER;

            // The knowledge model name.
            void* kmn = NULL_POINTER;
            int* kmnc = NULL_POINTER;
            int* kmns = NULL_POINTER;
            // The knowledge model abstraction.
            void* kma = NULL_POINTER;
            int* kmac = NULL_POINTER;
            int* kmas = NULL_POINTER;
            // The knowledge model model.
            void* kmm = NULL_POINTER;
            int* kmmc = NULL_POINTER;
            int* kmms = NULL_POINTER;
            // The knowledge model details.
            void* kmd = NULL_POINTER;
            int* kmdc = NULL_POINTER;
            int* kmds = NULL_POINTER;

/*??
            while (*NUMBER_1_INTEGER) {

                if (rc <= *NUMBER_0_INTEGER) {

                    break;
                }

                // Parse bdt field (size, identification, content).
                parse_bdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, s, (void*) &rc);

                if (v == *NUMBER_1_INTEGER) {

                    // The verification flag is set, which means that
                    // the bdt field was parsed correctly and the carriage
                    // return plus line feed characters were reached.

                    // Increment source bdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + fs;
                    rc = rc - fs;

                    // Increment data package count.
                    // It is reset to zero when a data package header is found.
                    pc = pc + fs;

                    if (fid == *RECORD_IDENTIFICATION_BDT_FIELD) {

                        // Parse bdt field content containing a record identification.
                        parse_integer((void*) &rid, NULL_POINTER, NULL_POINTER, fc, (void*) &fcc);

                        if (m == *MEDICAL_PRACTICE_DATA_BDT_RECORD) {

                            parse_bdt_record_medical_practice_data(p0, p1, p2, p3, p4, p5, p6, p7);

                        } else if (m == *DATA_MEDIUM_HEADER_BDT_RECORD) {

                            parse_bdt_record_data_medium_header(p0, p1, p2, p3, p4, p5, p6, p7);

                        } else if (m == *DATA_MEDIUM_FOOTER_BDT_RECORD) {

                            parse_bdt_record_data_medium_footer(p0, p1, p2, p3, p4, p5, p6, p7);

                        } else if (m == *DATA_PACKAGE_HEADER_BDT_RECORD) {

                            parse_bdt_record_data_package_header(p0, p1, p2, p3, p4, p5, p6, p7);

                        } else if (m == *DATA_PACKAGE_FOOTER_BDT_RECORD) {

                            parse_bdt_record_data_package_footer(p0, p1, p2, p3, p4, p5, p6, p7);

                        } else if (m == *MEDICAL_TREATMENT_BDT_RECORD) {

                            parse_bdt_record_medical_treatment(p0, p1, p2, p3, p4, p5, p6, p7);

                        } else if (m == *PATIENT_MASTER_DATA_BDT_RECORD) {
*/

/*??
                            parse_bdt_record_patient_master_data(
                                (void*) &kmn, (void*) kmnc, (void*) kmns,
                                (void*) &kma, (void*) kmac, (void*) kmas,
                                (void*) &kmm, (void*) kmmc, (void*) kmms,
                                p3, p4, p5, p6, p7);
*/

/*??
                        } else if (m == *MEDICAL_TREATMENT_DATA_BDT_RECORD) {

                            parse_bdt_record_medical_treatment_data(p0, p1, p2, p3, p4, p5, p6, p7);
*/

/*??
                            // Allocate knowledge model name.
                            allocate((void*) &kmnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmnc = *NUMBER_0_INTEGER;
                            allocate((void*) &kmns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmns = *NUMBER_0_INTEGER;
                            allocate((void*) &kmn, (void*) kmns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                            // A knowledge model channel is not received (allocated),
                            // since that is only needed temporarily for model loading.

                            // Allocate knowledge model abstraction.
                            allocate((void*) &kmac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmac = *NUMBER_0_INTEGER;
                            allocate((void*) &kmas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmas = *NUMBER_0_INTEGER;
                            allocate((void*) &kma, (void*) kmas, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                            // Allocate knowledge model model.
                            allocate((void*) &kmmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmmc = *NUMBER_0_INTEGER;
                            allocate((void*) &kmms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmms = *NUMBER_0_INTEGER;
                            // CAUTION! The knowledge model model may be of different abstractions,
                            // such as "character", "integer", "double", "date" etc.
                            // Since the abstraction is still unknown here, the model does NOT get
                            // allocated here, but only later, in one of the "parse" operations below!

                            // The knowledge model details are set to null.
                            // All data received are stored only in the knowledge model.

                            // Parse bdt package.
                            parse_bdt_package((void*) &kmm, (void*) kmmc, (void*) kmms, p, (void*) &pc);

                            // Add knowledge model to knowledge memory.
                            set_compound_element_by_name(p0, p1, p2, NULL_POINTER, NULL_POINTER, NULL_POINTER,
                                kmn, (void*) kmnc, (void*) kmns,
                                kma, (void*) kmac, (void*) kmas,
                                kmm, (void*) kmmc, (void*) kmms,
                                kmd, (void*) kmdc, (void*) kmds);
*/

/*??
                        } else if (rid == *DATA_PACKAGE_HEADER_BDT_RECORD) {

    fprintf(stderr, "TEST package header rid: %i\n", rid);

                            // Store data package begin pointer.
                            p = s;
                            pc = *NUMBER_0_INTEGER;

                            // Set parse mode.
                            m = *DATA_PACKAGE_HEADER_BDT_RECORD;
                        }
                    }

                } else {

                    // The verification flag is NOT set, which means that
                    // the bdt field was NOT parsed correctly.

                    // Reset next field count.
                    nc = *NUMBER_0_INTEGER;

                    // Count the number of bytes to the next carriage return-
                    // plus line feed character.
                    parse_bdt_next_field((void*) &nc, s, (void*) &rc);

                    // Increment source bdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + nc;
                    rc = rc - nc;

                    // Increment data package count.
                    // It is reset to zero when a data package header is found.
                    pc = pc + nc;

    fprintf(stderr, "TEST package verification failed nc: %i\n\n", nc);
                }
            }
*/

        } else {

            log_message_debug("Error: Could not parse bdt package. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt package. The source count is null.");
    }
}

/**
 * Parses a bdt format byte array into a compound model.
 *
 * The "x DatenTransfer" (xDT) is the German version of
 * "Electronic Data Interchange" (EDI) for medical practices.
 * Here is an extract from xDT documentation, issued by the
 * "Kassenaerztliche Bundesvereinigung" (KBV) at:
 * http://www.kbv.de/ita/4274.html
 *
 * Aufbau und Struktur des "AbrechnungsDatenTransfer" (ADT)
 *
 * Der ADT ist eine Datenschnittstelle, die aufgrund ihrer fruehen Entstehung,
 * Mitte der achtziger Jahre, wenig Anknuepfungspunkte zu den erst spaeter im
 * Zusammenhang mit der zunehmenden EDI-Etablierung bekannten Standards besitzt.
 * Natuerlich gibt es Parallelen, beispielsweise zu
 * "EDI for Administration, Commerce and Transport" (EDIFACT),
 * die in der artverwandten Zielsetzung begruendet liegen.
 * Die ADT-Syntax ist der von "Abstract Syntax Notation" (ASN) ASN.1 aehnlich.
 *
 * Eine wesentliche Besonderheit des ADT besteht darin, dass jedes Feld im
 * Grunde einen eigenen Satz darstellt. Das heisst, es enthaelt in sich wieder
 * die Elemente Laenge, Feldkennung, Feldinhalt und Feldende.
 *
 * Die einzelnen Felder haben alle einen eindeutigen Namen in Form einer
 * numerischen Feldkennung. Es gibt wenige Felder mit in der Groesse
 * feststehenden Feldinhalten, die meisten sind variabel, was sich mit einer
 * vorlaufenden Feldlaenge leicht bewerkstelligen laesst. Darueber hinaus
 * werden als Endemarkierung eines Feldes die ASCII-Werte 13 und 10,
 * gleichbedeutend mit Carriage return und Linefeed, verlangt.
 *
 * Jedes Feld hat die gleiche Struktur. Alle Informationen sind als
 * ASCII-Zeichen dargestellt. Gemaess der Feldkennung wird der zugehoerige
 * Eintrag der Feldtabelle herangezogen.
 *
 * Fuer die Laengenberechnung eines Feldes gilt die Regel: Feldinhalt + 9
 *
 * Struktur eines Datenfeldes
 *
 * -----------------------------------------------------------------------------
 * Feldteil         Laenge [Byte]       Bedeutung
 * -----------------------------------------------------------------------------
 * Laenge           3                   Feldlaenge in Bytes
 * Kennung          4                   Feldkennung
 * Inhalt           variabel            Abrechnungsinformationen
 * Ende             2                   ASCII-Wert 13 = CR (Wagenruecklauf)
 *                                      ASCII-Wert 10 = LF (Zeilenvorschub)
 * -----------------------------------------------------------------------------
 *
 * Here is an extract from the German "Arztpraxis Wiegand" (APW) documentation,
 * available at:
 * http://www.apw-wiegand.de/
 *
 * Patientennummerkonvertierung:
 * Beim BDT ... werden die Patientennummern nach folgender Formel konvertiert:
 * Stelle 1: immer 1
 * Stelle 2-3: Parallelabrechnungsnummer (meist 01)
 * Stelle 4-5: 1. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge (z.B. a->01, z->26)
 * Stelle 6-7: 2. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge
 * ab Stelle 8: ab Stelle 3 der APW-PatNr
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination compound model count
 * @param p2 the destination compound model size
 * @param p3 the destination compound details (Hand over as reference!)
 * @param p4 the destination compound details count
 * @param p5 the destination compound details size
 * @param p6 the source bdt byte array
 * @param p7 the source bdt byte arraycount
 */
void parse_bdt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* sc = (int*) p7;

        if (p6 != NULL_POINTER) {

            void* s = (void*) p6;

            log_message_debug("Information: Parse bdt format into compound model.");

            // The remaining bytes in the source byte array.
            int rc = *sc;
            // The field size.
            int fs = *NUMBER_0_INTEGER;
            // The field identification.
            int fid = *NUMBER_0_INTEGER;
            // The field content.
            void* fc = NULL_POINTER;
            int fcc = *NUMBER_0_INTEGER;
            // The verification flag.
            int v = *NUMBER_0_INTEGER;
            // The record identification.
            int rid = *NUMBER_0_INTEGER;
            // The next field count.
            int nc = *NUMBER_0_INTEGER;
            // The parse mode.
            int m = *NUMBER_0_INTEGER;
            // The loop variable.
            int j = *NUMBER_0_INTEGER;
            // The old loop variable.
            // It is needed by some code sections below, that do NOT want to
            // count the record identification field of the next record.
            int o = j;
            // The data package model.
            void* pm = NULL_POINTER;
            int pmc = *NUMBER_0_INTEGER;
            // The data package details 1.
            void* pd1 = NULL_POINTER;
            int pd1c = *NUMBER_0_INTEGER;
            // The data package details 2.
            void* pd2 = NULL_POINTER;
            int pd2c = *NUMBER_0_INTEGER;

            // The knowledge model name.
            void* kmn = NULL_POINTER;
            int* kmnc = NULL_POINTER;
            int* kmns = NULL_POINTER;
            // The knowledge model abstraction.
            void* kma = NULL_POINTER;
            int* kmac = NULL_POINTER;
            int* kmas = NULL_POINTER;
            // The knowledge model model.
            void* kmm = NULL_POINTER;
            int* kmmc = NULL_POINTER;
            int* kmms = NULL_POINTER;
            // The knowledge model details.
            void* kmd = NULL_POINTER;
            int* kmdc = NULL_POINTER;
            int* kmds = NULL_POINTER;

            while (*NUMBER_1_INTEGER) {

                if (rc <= *NUMBER_0_INTEGER) {

                    break;
                }

                // Parse bdt field (size, identification, content).
                parse_bdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, s, (void*) &rc);

                if (v == *NUMBER_1_INTEGER) {

                    // The verification flag is set, which means that
                    // the bdt field was parsed correctly and the carriage
                    // return plus line feed characters were reached.

                    // Increment source bdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + fs;
                    rc = rc - fs;

                    // Store old loop variable.
                    o = j;
                    // Increment loop variable.
                    j = j + fs;

                    if (fid == *RECORD_IDENTIFICATION_BDT_FIELD) {

                        // The following parse modes are defined:
                        // 0: start mode (no record found yet)
                        // 1: header mode (data package header had been found)
                        // 2: content mode (first record after the data package header appeared)
                        // 3: footer mode (data package footer had been found)

                        if (m == *NUMBER_0_INTEGER) {

                            // This is the header parse mode.

                            // Parse bdt field content containing a record identification.
                            parse_integer((void*) &rid, NULL_POINTER, NULL_POINTER, fc, (void*) &fcc);

                            if (rid == *DATA_PACKAGE_HEADER_BDT_RECORD) {

                                // Set header parse mode.
                                m = *NUMBER_1_INTEGER;
                                // Store data package header details (meta data 1) begin pointer.
                                pd1 = s;
                                // Reset loop variable.
                                j = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST set header mode rid: %i\n", rid);
                            }

                        } else if (m == *NUMBER_1_INTEGER) {

                            // This is the header parse mode.
                            // This is the begin of the first record following
                            // the data package header record.
                            // Therefore, all bytes counted to here contain
                            // meta data about the data package.

                            // Set content parse mode.
                            m = *NUMBER_2_INTEGER;
                            // Store data package header details (meta data 1) count.
                            pd1c = o;
                            // Store data package model begin pointer.
                            pm = s;
                            // Reset loop variable.
                            j = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST set content mode pd1c: %i\n", pd1c);

                        } else if (m == *NUMBER_2_INTEGER) {

                            // This is the content parse mode.
                            // It means that a data package header
                            // had been found before and all meta information
                            // of the data package have been parsed.
                            // The actual data package content is following now.

                            // Parse bdt field content containing a record identification.
                            parse_integer((void*) &rid, NULL_POINTER, NULL_POINTER, fc, (void*) &fcc);

                            if (rid == *DATA_PACKAGE_FOOTER_BDT_RECORD) {

                                // Set footer parse mode.
                                m = *NUMBER_3_INTEGER;
                                // Store data package model count.
                                pmc = o;
                                // Store data package footer details (meta data 2) begin pointer.
                                pd2 = s;
                                // Reset loop variable.
                                j = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST footer mode pmc: %i\n", pmc);
                            }

                        } else if (m == *NUMBER_3_INTEGER) {

                            // This is the footer parse mode.

                            // Set start parse mode, so that new data
                            // package headers may be found.
                            m = *NUMBER_0_INTEGER;
                            // Store data package footer details (meta data 2) count.
                            pd2c = o;
                            // Reset loop variable.
                            j = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST start mode pd2c: %i\n", pd2c);

                            // Allocate knowledge model name.
                            allocate((void*) &kmnc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmnc = *NUMBER_0_INTEGER;
                            allocate((void*) &kmns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmns = *NUMBER_0_INTEGER;
                            allocate((void*) &kmn, (void*) kmns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                            // A knowledge model channel is not received (allocated),
                            // since that is only needed temporarily for model loading.

                            // Allocate knowledge model abstraction.
                            allocate((void*) &kmac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmac = *NUMBER_0_INTEGER;
                            allocate((void*) &kmas, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmas = *NUMBER_0_INTEGER;
                            allocate((void*) &kma, (void*) kmas, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                            // Allocate knowledge model model.
                            allocate((void*) &kmmc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmmc = *NUMBER_0_INTEGER;
                            allocate((void*) &kmms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmms = *NUMBER_0_INTEGER;
                            allocate((void*) &kmm, (void*) kmms, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

                            // Allocate knowledge model details.
                            allocate((void*) &kmdc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmdc = *NUMBER_0_INTEGER;
                            allocate((void*) &kmds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                            *kmds = *NUMBER_0_INTEGER;
                            allocate((void*) &kmd, (void*) kmds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

    fprintf(stderr, "TEST s: %i\n", s);
    fprintf(stderr, "TEST rc: %i\n", rc);
    fprintf(stderr, "TEST pm: %i\n", pm);
    fprintf(stderr, "TEST pmc: %i\n", pmc);
    fprintf(stderr, "TEST pd1: %i\n", pd1);
    fprintf(stderr, "TEST pd1c: %i\n", pd1c);
    fprintf(stderr, "TEST pd2: %i\n", pd2);
    fprintf(stderr, "TEST pd2c: %i\n", pd2c);

                            // Parse bdt package.
                            parse_bdt_package((void*) &kmm, (void*) kmmc, (void*) kmms, pm, (void*) &pmc);

                            // Parse bdt package header details (meta data 1).
                            parse_bdt_record((void*) &kmd, (void*) kmdc, (void*) kmds, pd1, (void*) &pd1c);

                            // Parse bdt package footer details (meta data 2).
                            parse_bdt_record((void*) &kmd, (void*) kmdc, (void*) kmds, pd2, (void*) &pd2c);

                            // Add knowledge model to knowledge memory.
                            set_compound_element_by_name(p0, p1, p2, p3, p4, p5,
                                kmn, (void*) kmnc, (void*) kmns,
                                kma, (void*) kmac, (void*) kmas,
                                kmm, (void*) kmmc, (void*) kmms,
                                kmd, (void*) kmdc, (void*) kmds);

    fprintf(stderr, "TEST 2 s: %i\n", s);
                        }
                    }

                } else {

                    // The verification flag is NOT set, which means that
                    // the bdt field was NOT parsed correctly.

                    // Reset next field count.
                    nc = *NUMBER_0_INTEGER;

                    // Count the number of bytes to the next carriage return-
                    // plus line feed character.
                    parse_bdt_next_field((void*) &nc, s, (void*) &rc);

                    // Increment source bdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + nc;
                    rc = rc - nc;

                    // Store old loop variable.
                    o = j;
                    // Increment loop variable.
                    j = j + nc;

                    log_message_debug("Error: Could not parse bdt. An invalid field was detected. The parsing will now continue with the next valid field.");
                }
            }

        } else {

            log_message_debug("Error: Could not parse bdt. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt. The source count is null.");
    }
}

/**
 * Serialises a compound model into a bdt format byte array.
 *
 * @param p0 the destination bdt byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void serialise_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* BDT_CONVERTER_SOURCE */
#endif
