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
 * @version $Revision: 1.4 $ $Date: 2007-02-19 21:46:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BDT_CONVERTER_SOURCE
#define BDT_CONVERTER_SOURCE

#include "../../globals/constants/xdt/bdt_field_constants.c"
#include "../../globals/constants/xdt/bdt_record_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"
#include "../../memoriser/converter/character_vector_converter.c"
#include "../../memoriser/converter/integer_vector_converter.c"

/**
 * Parses the bdt record.
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
void parse_bdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record. The parse mode is null.");
    }
}

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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record medical treatment. The parse mode is null.");
    }
}

/**
 * Parses the bdt record patient master data.
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
void parse_bdt_record_patient_master_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt record patient master data.");

        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) PATIENT_LAST_NAME_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse patient master data last name count: %i\n\n", *((int*) p6));
//??    fprintf(stderr, "TEST parse patient master data last name: %s\n", (char*) p5);

                // The last name array.
                void* ln = NULL_POINTER;
                int lnc = *NUMBER_0_INTEGER;
                int lns = *NUMBER_0_INTEGER;

                // Allocate last name array.
                allocate((void*) &ln, (void*) &lns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                // Parse last name.
                parse_character_vector((void*) &ln, (void*) &lnc, (void*) &lns, p5, p6);
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) PATIENT_FIRST_NAME_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse patient master data first name count: %i\n\n", *((int*) p6));
//??    fprintf(stderr, "TEST first name: %s\n", (char*) p5);

                //?? TODO: Do something with the patient first name!
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) PATIENT_BIRTH_DATE_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse patient master data birth date count: %i\n\n", *((int*) p6));
//??    fprintf(stderr, "TEST birth date: %s\n", (char*) p5);

                //?? TODO: Do something with the patient birth date!
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) PATIENT_SEX_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse patient master data sex count: %i\n\n", *((int*) p6));
//??    fprintf(stderr, "TEST sex: %s\n", (char*) p5);

                //?? TODO: Do something with the patient sex!
            }
        }

        if (r == *NUMBER_0_INTEGER) {

            compare_arrays(p3, p4, (void*) RECORD_IDENTIFICATION_BDT_FIELD, (void*) BDT_FIELD_IDENTIFICATION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r != *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST parse bdt record patient master data content count: %i\n\n", *((int*) p6));

                // Set data record identification as parse mode.
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
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
                parse_integer((void*) &m, NULL_POINTER, NULL_POINTER, p5, p6);
            }
        }

    } else {

        log_message_debug("Error: Could not parse bdt record medical treatment data. The parse mode is null.");
    }
}

/**
 * Parses a bdt field.
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
void parse_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != NULL_POINTER) {

        int* m = (int*) p7;

        log_message_debug("Information: Parse bdt field.");

//??    fprintf(stderr, "TEST field content: %s\n", (char*) p5);
    fprintf(stderr, "TEST field content count: %i\n\n", *((int*) p6));

        if (*m == *NUMBER_0_INTEGER) {

            parse_bdt_record(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *MEDICAL_PRACTICE_DATA_BDT_RECORD) {

            parse_bdt_record_medical_practice_data(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *DATA_MEDIUM_HEADER_BDT_RECORD) {

            parse_bdt_record_data_medium_header(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *DATA_MEDIUM_FOOTER_BDT_RECORD) {

            parse_bdt_record_data_medium_footer(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *DATA_PACKAGE_HEADER_BDT_RECORD) {

            parse_bdt_record_data_package_header(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *DATA_PACKAGE_FOOTER_BDT_RECORD) {

            parse_bdt_record_data_package_footer(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *MEDICAL_TREATMENT_BDT_RECORD) {

            parse_bdt_record_medical_treatment(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *PATIENT_MASTER_DATA_BDT_RECORD) {

            parse_bdt_record_patient_master_data(p0, p1, p2, p3, p4, p5, p6, p7);

        } else if (*m == *MEDICAL_TREATMENT_DATA_BDT_RECORD) {

            parse_bdt_record_medical_treatment_data(p0, p1, p2, p3, p4, p5, p6, p7);
        }

    } else {

        log_message_debug("Error: Could not parse bdt field. The parse mode is null.");
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
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source bdt byte array
 * @param p4 the source count
 */
void parse_bdt(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != NULL_POINTER) {

        int* sc = (int*) p4;

        log_message_debug("Information: Parse bdt format into compound model.");

        // The source bdt byte array index.
        void* i = p3;
        int ic = *sc;
        // The moved flag indicating whether or not the source
        // bdt byte array index was moved (increased).
        int f = *NUMBER_0_INTEGER;
        // The field size.
        int* fs = NULL_POINTER;
        // The field identification.
        void* fid = NULL_POINTER;
        int fidc = *NUMBER_0_INTEGER;
        // The field content.
        void* fc = NULL_POINTER;
        int fcc = *NUMBER_0_INTEGER;
        // The parse mode.
        int m = *NUMBER_0_INTEGER;

        // Allocate field size.
        allocate((void*) &fs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Initialise field size.
        *fs = *NUMBER_0_INTEGER;

        // Iterate through source bdt byte array.
        while (*NUMBER_1_INTEGER) {

            if (ic <= *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST BREAK ic: %i\n\n", ic);

                break;
            }

            if (ic >= *BDT_FIELD_SIZE_COUNT) {

                // Parse bdt field size.
                parse_integer((void*) &fs, NULL_POINTER, NULL_POINTER, i, (void*) BDT_FIELD_SIZE_COUNT);

                // Increment source bdt byte array index.
                i = i + *BDT_FIELD_SIZE_COUNT;
                ic = ic - *BDT_FIELD_SIZE_COUNT;

                // Set moved flag.
                f = *NUMBER_1_INTEGER;
            }

            if (ic >= *BDT_FIELD_IDENTIFICATION_COUNT) {

                // Parse bdt field identification.
                fid = i;
                fidc = *BDT_FIELD_IDENTIFICATION_COUNT;

                // Increment source bdt byte array index.
                i = i + *BDT_FIELD_IDENTIFICATION_COUNT;
                ic = ic - *BDT_FIELD_IDENTIFICATION_COUNT;

                // Set moved flag.
                f = *NUMBER_1_INTEGER;
            }

            // Calculate bdt field content size.
            //
            // CAUTION! The bdt field size comprises all characters:
            // - field size (3 bytes)
            // - field identification (4 bytes)
            // - field content (VARIABLE!)
            // - carriage return (1 byte)
            // - line feed (1 byte)
            //
            // It therefore has to be decremented here, so that only the
            // actual bdt field content size remains.
            *fs = *fs - *BDT_FIELD_SIZE_COUNT - *BDT_FIELD_IDENTIFICATION_COUNT - *PRIMITIVE_COUNT - *PRIMITIVE_COUNT;

            if (ic >= *fs) {

                // Parse bdt field content.
                fc = i;
                fcc = *fs;

                // Increment source bdt byte array index.
                i = i + *fs;
                ic = ic - *fs;

                // Set moved flag.
                f = *NUMBER_1_INTEGER;
            }

            if (ic >= (*PRIMITIVE_COUNT + *PRIMITIVE_COUNT)) {

                // Parse bdt field carriage return and line feed.

                // Increment source bdt byte array index.
                i = i + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT;
                ic = ic - *PRIMITIVE_COUNT - *PRIMITIVE_COUNT;

                // Set moved flag.
                f = *NUMBER_1_INTEGER;
            }

            // Process the field.
            parse_bdt_field(p0, p1, p2, fid, (void*) &fidc, fc, (void*) &fcc, (void*) &m);

            if (f == *NUMBER_0_INTEGER) {

                // CAUTION! If the moved flag is false (zero), then the
                // bdt byte array index was not incremented at all.
                // Probably, the remaining byte array count was too small,
                // so that none of the sections above was entered.
                // Therefore, the bdt byte array index is incremented by one
                // here, so that the loop will eventually find an end.

    fprintf(stderr, "TEST INCREMENT MANUALLY flag f: %i\n\n", f);

                // Increment source bdt byte array index.
                i++;
                ic--;
            }

            // Reset field size.
            *fs = *NUMBER_0_INTEGER;
            // Reset field identification.
            fid = NULL_POINTER;
            fidc = *NUMBER_0_INTEGER;
            // Reset field content.
            fc = NULL_POINTER;
            fcc = *NUMBER_0_INTEGER;
            // Reset moved flag.
            // CAUTION! It has to be reset BELOW the comparison above!
            f = *NUMBER_0_INTEGER;
        }

        // Deallocate field size.
        deallocate((void*) &fs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    } else {

        log_message_debug("Error: Could not parse bdt format into compound model. The source count is null.");
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
