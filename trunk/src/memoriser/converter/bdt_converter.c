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
 * @version $Revision: 1.10 $ $Date: 2007-03-14 03:11:55 $ $Author: christian $
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
/*??
void parse_bdt_process_field(void* p0, void* p1, void* p2,
    void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("Information: Process bdt field.");

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
/*??
void parse_bdt_select_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != NULL_POINTER) {

        int* id = (int*) p5;

        log_message_debug("Information: Select bdt field.");

        if (*id == *RECORD_SIZE_BDT_FIELD) {

            parse_bdt_process_field(p0, p1, p2, p3, p4,
                (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT,
                (void*) RECORD_SIZE_XDT_FIELD_NAME, (void*) RECORD_SIZE_XDT_FIELD_NAME_COUNT);

        } else if (*id == *ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD) {

            parse_bdt_process_field(p0, p1, p2, p3, p4,
                (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME, (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_COUNT);
        }

    } else {

        log_message_debug("Error: Could not select bdt field. The field identification is null.");
    }
}

/**
 * Processes the bdt record.
 *
 * @param p0 the destination compound (Hand over as reference!)
 * @param p1 the destination compound count (Hand over as reference!)
 * @param p2 the destination compound size (Hand over as reference!)
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
/*??
void parse_bdt_process_record(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != NULL_POINTER) {

            void* s = (void*) p3;

            log_message_debug("Information: Process bdt record.");

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

                    parse_bdt_select_field(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

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

                    log_message_debug("Error: Could not process bdt record. An invalid field was detected. The parsing will now continue with the next valid field.");
                }
            }

        } else {

            log_message_debug("Error: Could not process bdt record. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not process bdt record. The source count is null.");
    }
}

/**
 * Selects the bdt record.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count (Hand over as reference!)
 * @param p2 the destination model size (Hand over as reference!)
 * @param p3 the source bdt package byte stream
 * @param p4 the source bdt package byte stream count
 */
/*??
void parse_bdt_select_record(void* p0, void* p1, void* p2, void* p3, void* p4) {

/*??
    if (p5 != NULL_POINTER) {

        int* id = (int*) p5;

        log_message_debug("Information: Select bdt record.");

        if (*id == *RECORD_SIZE_BDT_FIELD) {

            parse_bdt_record_process_field(p0, p1, p2, p3, p4,
                (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT,
                (void*) RECORD_SIZE_XDT_FIELD_NAME, (void*) RECORD_SIZE_XDT_FIELD_NAME_COUNT);

        } else if (*id == *ADT_RECORD_SPECIFICATION_VERSION_BDT_FIELD) {

            parse_bdt_record_process_field(p0, p1, p2, p3, p4,
                (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME, (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_COUNT);
        }

/*??
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

            parse_bdt_record_patient_master_data(
                (void*) &kmn, (void*) kmnc, (void*) kmns,
                (void*) &kma, (void*) kmac, (void*) kmas,
                (void*) &kmm, (void*) kmmc, (void*) kmms,
                p3, p4, p5, p6, p7);

        } else if (m == *MEDICAL_TREATMENT_DATA_BDT_RECORD) {

            parse_bdt_record_medical_treatment_data(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (rid == *DATA_PACKAGE_HEADER_BDT_RECORD) {

            // Store data package begin pointer.
            p = s;
            pc = *NUMBER_0_INTEGER;

            // Set parse mode.
            m = *DATA_PACKAGE_HEADER_BDT_RECORD;
        }
    }

    } else {

        log_message_debug("Error: Could not select bdt record. The field identification is null.");
    }
*/
/*??
}

/**
 * Processes the bdt package.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count (Hand over as reference!)
 * @param p2 the destination model size (Hand over as reference!)
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count (Hand over as reference!)
 * @param p5 the destination details size (Hand over as reference!)
 * @param p6 the data package model
 * @param p7 the data package model count
 * @param p8 the data package details 1
 * @param p9 the data package details 1 count
 * @param p10 the data package details 2
 * @param p11 the data package details 2 count
 */
/*??
void parse_bdt_process_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

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

    // Process bdt package.
    parse_bdt_select_record((void*) kmm, (void*) kmmc, (void*) kmms, p6, p7);

    // Parse bdt package header details (meta data 1).
    parse_bdt_process_record((void*) kmd, (void*) kmdc, (void*) kmds, p8, p9);

    // Parse bdt package footer details (meta data 2).
    parse_bdt_process_record((void*) kmd, (void*) kmdc, (void*) kmds, p10, p11);

    // Add knowledge model to knowledge memory.
    set_compound_element_by_name(p0, p1, p2, p3, p4, p5,
        kmn, (void*) kmnc, (void*) kmns,
        kma, (void*) kmac, (void*) kmas,
        kmm, (void*) kmmc, (void*) kmms,
        kmd, (void*) kmdc, (void*) kmds);
}

/**
 * Selects the bdt package header.
 *
 * @param p0 the data package details 1
 * @param p1 the parse mode
 * @param p2 the loop variable
 * @param p3 the data package section
 * @param p4 the field content
 * @param p5 the field content count
 */
/*??
void parse_bdt_select_package_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != NULL_POINTER) {

        void** s = (void**) p3;

        if (p2 != NULL_POINTER) {

            int* j = (int*) p2;

            if (p1 != NULL_POINTER) {

                int* m = (int*) p1;

                if (p0 != NULL_POINTER) {

                    void** pd1 = (void**) p0;

                    log_message_debug("Information: Select bdt package header.");

                    // The record identification.
                    int rid = *NUMBER_0_INTEGER;

                    // Parse bdt field content containing a record identification.
                    parse_integer((void*) &rid, NULL_POINTER, NULL_POINTER, p4, p5);

                    if (rid == *DATA_PACKAGE_HEADER_BDT_RECORD) {

                        // Set header parse mode.
                        *m = *NUMBER_1_INTEGER;
                        // Store data package header details (meta data 1) begin pointer.
                        *pd1 = *s;
                        // Reset loop variable.
                        *j = *NUMBER_0_INTEGER;

                    fprintf(stderr, "TEST set header mode rid: %i\n", rid);
                    }

                } else {

                    log_message_debug("Error: Could not select bdt package header. The data package details 1 is null.");
                }

            } else {

                log_message_debug("Error: Could not select bdt package header. The parse mode is null.");
            }

        } else {

            log_message_debug("Error: Could not select bdt package header. The loop variable is null.");
        }

    } else {

        log_message_debug("Error: Could not select bdt package header. The data package section is null.");
    }
}

/**
 * Selects the bdt package header end.
 *
 * @param p0 the data package details 1 count
 * @param p1 the data package model
 * @param p2 the parse mode
 * @param p3 the loop variable
 * @param p4 the data package section
 * @param p5 the data package section count
 */
/*??
void parse_bdt_select_package_header_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != NULL_POINTER) {

        int* sc = (int*) p5;

        if (p4 != NULL_POINTER) {

            void** s = (void**) p4;

            if (p3 != NULL_POINTER) {

                int* j = (int*) p3;

                if (p2 != NULL_POINTER) {

                    int* m = (int*) p2;

                    if (p1 != NULL_POINTER) {

                        void** pm = (void**) p1;

                        if (p0 != NULL_POINTER) {

                            int* pd1c = (int*) p0;

                            log_message_debug("Information: Select bdt package header end.");

                            // Set content parse mode.
                            *m = *NUMBER_2_INTEGER;
                            // Store data package header details (meta data 1) count.
                            *pd1c = *sc;
                            // Store data package model begin pointer.
                            *pm = *s;
                            // Reset loop variable.
                            *j = *NUMBER_0_INTEGER;

                    fprintf(stderr, "TEST set content mode pd1c: %i\n", *pd1c);

                        } else {

                            log_message_debug("Error: Could not select bdt package header end. The data package details 1 count is null.");
                        }

                    } else {

                        log_message_debug("Error: Could not select bdt package header end. The data package model is null.");
                    }

                } else {

                    log_message_debug("Error: Could not select bdt package header end. The parse mode is null.");
                }

            } else {

                log_message_debug("Error: Could not select bdt package header end. The loop variable is null.");
            }

        } else {

            log_message_debug("Error: Could not select bdt package header end. The data package section is null.");
        }

    } else {

        log_message_debug("Error: Could not select bdt package header end. The data package section count is null.");
    }
}

/**
 * Selects the bdt package content.
 *
 * @param p0 the data package details 1 count
 * @param p1 the data package model
 * @param p2 the parse mode
 * @param p3 the loop variable
 * @param p4 the data package section
 * @param p5 the data package section count
 */
/*??
void parse_bdt_select_package_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

            // The record identification.
            int rid = *NUMBER_0_INTEGER;

            // Parse bdt field content containing a record identification.
            parse_integer((void*) &rid, NULL_POINTER, NULL_POINTER, fc, (void*) &fcc);

            if (rid == *DATA_PACKAGE_FOOTER_BDT_RECORD) {

                // Set footer parse mode.
                *m = *NUMBER_3_INTEGER;
                // Store data package model count.
                *pmc = *o;
                // Store data package footer details (meta data 2) begin pointer.
                *pd2 = *s;
                // Reset loop variable.
                *j = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST footer mode pmc: %i\n", *pmc);
            }
}

/**
 * Selects the bdt package footer.
 *
 * @param p0 the data package details 1 count
 * @param p1 the data package model
 * @param p2 the parse mode
 * @param p3 the loop variable
 * @param p4 the data package section
 * @param p5 the data package section count
 */
/*??
void parse_bdt_select_package_footer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

            // Set start parse mode, so that new data
            // package headers may be found.
            *m = *NUMBER_0_INTEGER;
            // Store data package footer details (meta data 2) count.
            *pd2c = *o;
            // Reset loop variable.
            *j = *NUMBER_0_INTEGER;

    fprintf(stderr, "TEST start mode pd2c: %i\n", *pd2c);

            // Process bdt package.
            parse_bdt_process_package(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);

    fprintf(stderr, "TEST 2 s: %i\n", s);
}

/**
 * Parses a bdt field.
 *
 * @param p0 the destination field size (Hand over as reference!)
 * @param p1 the destination field identification (Hand over as reference!)
 * @param p2 the destination field content (Hand over as reference!)
 * @param p3 the destination field content count (Hand over as reference!)
 * @param p4 the destination verification flag
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
                            int rem = *sc;

                            if (rem >= *BDT_FIELD_SIZE_COUNT) {

                                // Parse bdt field size.
                                parse_integer(p0, NULL_POINTER, NULL_POINTER, s, (void*) BDT_FIELD_SIZE_COUNT);

                                // Increment source bdt byte array index.
                                s = s + *BDT_FIELD_SIZE_COUNT;
                                rem = rem - *BDT_FIELD_SIZE_COUNT;
                            }

                            if (rem >= *BDT_FIELD_IDENTIFICATION_COUNT) {

                                // Parse bdt field identification.
                                parse_integer(p1, NULL_POINTER, NULL_POINTER, s, (void*) BDT_FIELD_IDENTIFICATION_COUNT);

                                // Increment source bdt byte array index.
                                s = s + *BDT_FIELD_IDENTIFICATION_COUNT;
                                rem = rem - *BDT_FIELD_IDENTIFICATION_COUNT;
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

                            if (rem >= *fcc) {

                                // Store bdt field content, to be returned.
                                *fc = s;

                                // Increment source bdt byte array index.
                                s = s + *fcc;
                                rem = rem - *fcc;
                            }

                            if (rem >= (*PRIMITIVE_COUNT + *PRIMITIVE_COUNT)) {

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

                log_message_debug("Information: Parse for next bdt field.");

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
 * Parses a bdt record.
 *
 * @param p0 the record size (Hand over as reference!)
 * @param p1 the record identification (Hand over as reference!)
 * @param p2 the record content (Hand over as reference!)
 * @param p3 the record content count (Hand over as reference!)
 * @param p4 the source byte array
 * @param p5 the source byte array count
 */
void parse_bdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != NULL_POINTER) {

        int* sc = (int*) p5;

        if (p4 != NULL_POINTER) {

            char* s = (char*) p4;

            if (p3 != NULL_POINTER) {

                int* rcc = (int*) p3;

                if (p2 != NULL_POINTER) {

                    void** rc = (void**) p2;

                    log_message_debug("Information: Parse bdt record.");

                    // The remaining bytes in the source byte array.
                    int rem = *sc;
                    // The next field count.
                    int nc = *NUMBER_0_INTEGER;
                    // The field size.
                    int fs = *NUMBER_0_INTEGER;
                    // The field identification.
                    int fid = *NUMBER_0_INTEGER;
                    // The field content.
                    void* fc = NULL_POINTER;
                    int fcc = *NUMBER_0_INTEGER;
                    // The verification flag.
                    int v = *NUMBER_0_INTEGER;

                    while (*NUMBER_1_INTEGER) {

                        if (rem <= *NUMBER_0_INTEGER) {

                            break;
                        }

                        // Parse bdt field (size, identification, content).
                        parse_bdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, s, (void*) &rem);

                        if (v == *NUMBER_1_INTEGER) {

                            // The verification flag is set, which means that
                            // the bdt field was parsed correctly and the carriage
                            // return plus line feed characters were reached.

                            // Increment source bdt byte array index,
                            // so that following fields may be found
                            // in the next loop cycle.
                            s = s + fs;
                            rem = rem - fs;

                            if (fid == *RECORD_IDENTIFICATION_BDT_FIELD) {

                                // Parse bdt record identification.
                                parse_integer(p1, NULL_POINTER, NULL_POINTER, fc, (void*) &fcc);

                            } else if (fid == *RECORD_SIZE_BDT_FIELD) {

                                // Parse bdt record size.
                                parse_integer(p0, NULL_POINTER, NULL_POINTER, fc, (void*) &fcc);

                                // Store record content.
                                //
                                // Everything following after this record size
                                // field belongs to its content.
                                //
                                // CAUTION! The pointer s was already increased above,
                                // so that the current value of s points to the beginning
                                // of the first field of the record's CONTENT.
                                // The record size- and identification field sizes
                                // were already subtracted from the record content count.
                                *rc = s;
                                *rcc = rem;

                                // Set remaining bytes to zero, as the record size field
                                // (and thus also the record content following after)
                                // has been detected and the loop can be left now.
                                rem = *NUMBER_0_INTEGER;
                            }

                        } else {

                            // The verification flag is NOT set, which means
                            // that the bdt field was NOT parsed correctly.

                            log_message_debug("Error: Could not parse bdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                            // Reset next field count.
                            nc = *NUMBER_0_INTEGER;

                            // Count the number of bytes to the next carriage return-
                            // plus line feed character.
                            parse_bdt_next_field((void*) &nc, s, (void*) &rem);

                            // Increment source bdt byte array index, so that following
                            // fields may be found in the next loop cycle.
                            s = s + nc;
                            rem = rem - nc;
                        }
                    }

                } else {

                    log_message_debug("Error: Could not parse bdt record. The record content is null.");
                }

            } else {

                log_message_debug("Error: Could not parse bdt record. The record content count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse bdt record. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt record. The source byte array count is null.");
    }
}

/**
 * Parses a bdt package.
 *
 * @param p0 the package size (Hand over as reference!)
 * @param p1 the package header (Hand over as reference!)
 * @param p2 the package header count (Hand over as reference!)
 * @param p3 the package footer (Hand over as reference!)
 * @param p4 the package footer count (Hand over as reference!)
 * @param p5 the package content (Hand over as reference!)
 * @param p6 the package content count (Hand over as reference!)
 * @param p7 the source byte array
 * @param p8 the source byte array count
 */
void parse_bdt_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != NULL_POINTER) {

        int* sc = (int*) p8;

        if (p7 != NULL_POINTER) {

            char* s = (char*) p7;

            if (p6 != NULL_POINTER) {

                int* pcc = (int*) p6;

                if (p5 != NULL_POINTER) {

                    void** pc = (void**) p5;

                    if (p4 != NULL_POINTER) {

                        int* pfc = (int*) p4;

                        if (p3 != NULL_POINTER) {

                            void** pf = (void**) p3;

                            if (p2 != NULL_POINTER) {

                                int* phc = (int*) p2;

                                if (p1 != NULL_POINTER) {

                                    void** ph = (void**) p1;

                                    if (p0 != NULL_POINTER) {

                                        int* ps = (int*) p0;

                                        log_message_debug("Information: Parse bdt package.");

                                        // The remaining bytes in the source byte array.
                                        int rem = *sc;
                                        // The record size.
                                        int rs = *NUMBER_0_INTEGER;
                                        // The record identification.
                                        int rid = *NUMBER_0_INTEGER;
                                        // The record content.
                                        void* rc = NULL_POINTER;
                                        int rcc = *NUMBER_0_INTEGER;
                                        // The loop variable.
                                        int j = *NUMBER_0_INTEGER;

                                        while (*NUMBER_1_INTEGER) {

                                            if (rem <= *NUMBER_0_INTEGER) {

                                                break;
                                            }

                                            // Parse bdt record (size, identification, content).
                                            parse_bdt_record((void*) &rs, (void*) &rid, (void*) &rc, (void*) &rcc, s, (void*) &rem);

                                            if (rs > *NUMBER_0_INTEGER) {

                                                // Increment source bdt byte array index,
                                                // so that following records may be found
                                                // in the next loop cycle.
                                                s = s + rs;
                                                rem = rem - rs;

                                                // Increment package size.
                                                *ps = *ps + rs;

                                                // Increment loop variable.
                                                j = j + rs;

                                                if (rid == *DATA_PACKAGE_HEADER_BDT_RECORD) {

                                                    // Store bdt package header.
                                                    //
                                                    // CAUTION! This is only the record content
                                                    // WITHOUT the record size and -identification!
                                                    *ph = rc;
                                                    *phc = rcc;

                                                    // Store bdt package content.
                                                    //
                                                    // CAUTION! Everything following this package header
                                                    // record up to the package footer record belongs
                                                    // to the package's content.
                                                    *pc = s;

                                                    // Reset loop variable, in order to count the
                                                    // bdt package content (size) now following.
                                                    j = *NUMBER_0_INTEGER;

                                                } else if (rid == *DATA_PACKAGE_FOOTER_BDT_RECORD) {

                                                    // Store bdt package footer.
                                                    //
                                                    // CAUTION! This is only the record content
                                                    // WITHOUT the record size and -identification!
                                                    *pf = rc;
                                                    *pfc = rcc;

                                                    // Store bdt package content count.
                                                    //
                                                    // The loop variable j was reset when the package
                                                    // header was found and steadily increased since then.
                                                    // Its current value thus represents the package
                                                    // content count.
                                                    //
                                                    // CAUTION! However, the size rs of THIS record must be
                                                    // SUBTRACTED from the loop variable j again, as it was
                                                    // added automatically (j = j + rs;) above!
                                                    *pcc = j - rs;

                                                    // Set remaining bytes to zero, as the package footer
                                                    // has been detected and the loop can be left now.
                                                    rem = *NUMBER_0_INTEGER;
                                                }

                                            } else {

                                                // If the bdt record size is zero or smaller, then
                                                // increment the source bdt byte array index by one,
                                                // in order to ensure that this loop will finally
                                                // find an end.
                                                s = s + *NUMBER_1_INTEGER;
                                                rem = rem - *NUMBER_1_INTEGER;

                                                // Increment package size.
                                                *ps = *ps + *NUMBER_1_INTEGER;

                                                // Increment loop variable.
                                                j = j + *NUMBER_1_INTEGER;
                                            }
                                        }

                                    } else {

                                        log_message_debug("Error: Could not parse bdt package. The package size is null.");
                                    }

                                } else {

                                    log_message_debug("Error: Could not parse bdt package. The package header is null.");
                                }

                            } else {

                                log_message_debug("Error: Could not parse bdt package. The package header count is null.");
                            }

                        } else {

                            log_message_debug("Error: Could not parse bdt package. The package footer is null.");
                        }

                    } else {

                        log_message_debug("Error: Could not parse bdt package. The package footer count is null.");
                    }

                } else {

                    log_message_debug("Error: Could not parse bdt package. The package content is null.");
                }

            } else {

                log_message_debug("Error: Could not parse bdt package. The package content count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse bdt package. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt package. The source byte array count is null.");
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

            if (p3 != NULL_POINTER) {

                void** dd = (void**) p3;

                if (p0 != NULL_POINTER) {

                    void** dm = (void**) p0;

                    log_message_debug("Information: Parse bdt format into compound model.");

                    // The remaining bytes in the source byte array.
                    int rem = *sc;
                    // The bdt package size.
                    int ps = *NUMBER_0_INTEGER;
                    // The bdt package content.
                    void* pc = NULL_POINTER;
                    int pcc = *NUMBER_0_INTEGER;
                    // The bdt package header.
                    void* ph = NULL_POINTER;
                    int phc = *NUMBER_0_INTEGER;
                    // The bdt package footer.
                    void* pf = NULL_POINTER;
                    int pfc = *NUMBER_0_INTEGER;

                    while (*NUMBER_1_INTEGER) {

                        if (rem <= *NUMBER_0_INTEGER) {

                            break;
                        }

                        //?? TODO: Is the following comment really true and necessary?

                        // CAUTION! The data package section pointer s
                        // has to be handed over as REFERENCE, because it
                        // gets manipulated in the called operations and
                        // these have to store their result in s.
                        // If temporary variables were used, they would
                        // be lost when the called operation is left.
                        parse_bdt_package((void*) &ps, (void*) &ph, (void*) &phc, (void*) &pf, (void*) &pfc, (void*) &pc, (void*) &pcc, s, (void*) &rem);

                        //?? CAUTION! The bdt package size gets self-calculated
                        //?? in the "parse_bdt_package" operation and might NOT
                        //?? be quite correct, as invalid fields are possibly not counted.
                        //??
                        //?? A more proper solution would be to read out the
                        //?? "package size" field in the "package footer record",
                        //?? but this is a little more effort, since all field variables
                        //?? have to be provided to store the results.

                        if (ps > *NUMBER_0_INTEGER) {

                            // Increment source bdt byte array index, so that
                            // following fields may be found in the next loop cycle.
                            s = s + ps;
                            rem = rem - ps;

/*??
                            // Process bdt package header.
                            parse_bdt_select_record(*dm, p1, p2, *dd, p4, p5,
                                (void*) &pm, (void*) &pmc, (void*) &j, (void*) &s, (void*) &o);

                            // Process bdt package footer.

                            // Process bdt package content.
*/

                        } else {

                            // If the bdt package size is zero or smaller, then
                            // increment the source bdt byte array index by one,
                            // in order to ensure that this loop will finally
                            // find an end.
                            s = s + *NUMBER_1_INTEGER;
                            rem = rem - *NUMBER_1_INTEGER;
                        }
                    }

                } else {

                    log_message_debug("Error: Could not parse bdt. The destination compound model is null.");
                }

            } else {

                log_message_debug("Error: Could not parse bdt. The destination compound details is null.");
            }

        } else {

            log_message_debug("Error: Could not parse bdt. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse bdt. The source byte array count is null.");
    }
}

/**
 * Serialises a compound model into a bdt format byte array.
 *
 * @param p0 the bdt byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void serialise_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* BDT_CONVERTER_SOURCE */
#endif
