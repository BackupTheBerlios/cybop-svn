/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: xdt_converter.c,v $ $Revision: 1.40 $ $Date: 2009-02-10 01:13:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_DECODER_SOURCE
#define XDT_DECODER_SOURCE

#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/xdt/field_xdt_name.c"
#include "../../../constant/name/xdt/package_xdt_name.c"
#include "../../../constant/name/xdt/record_xdt_name.c"
#include "../../../constant/name/xdt_model/field_xdt_model_name.c"
#include "../../../constant/name/xdt_model/record_xdt_model_name.c"
#include "../../../executor/modifier/replacer/compound_replacer.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../executor/converter/decoder/ascii_character_vector_decoder.c"
#include "../../../executor/converter/decoder/date_time_decoder.c"
#include "../../../executor/converter/decoder/integer_vector_decoder.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

//
// The "x DatenTransfer" (xDT) is the German version of
// "Electronic Data Interchange" (EDI) for medical practices.
// Here is an extract from xDT documentation, issued by the
// "Kassenaerztliche Bundesvereinigung" (KBV) at:
// http://www.kbv.de/ita/4274.html
//
// Aufbau und Struktur des "AbrechnungsDatenTransfer" (ADT)
//
// Der ADT ist eine Datenschnittstelle, die aufgrund ihrer fruehen Entstehung,
// Mitte der achtziger Jahre, wenig Anknuepfungspunkte zu den erst spaeter im
// Zusammenhang mit der zunehmenden EDI-Etablierung bekannten Standards besitzt.
// Natuerlich gibt es Parallelen, beispielsweise zu
// "EDI for Administration, Commerce and Transport" (EDIFACT),
// die in der artverwandten Zielsetzung begruendet liegen.
// Die ADT-Syntax ist der von "Abstract Syntax Notation" (ASN) ASN.1 aehnlich.
//
// Eine wesentliche Besonderheit des ADT besteht darin, dass jedes Feld im
// Grunde einen eigenen Satz darstellt. Das heisst, es enthaelt in sich wieder
// die Elemente Laenge, Feldkennung, Feldinhalt und Feldende.
//
// Die einzelnen Felder haben alle einen eindeutigen Namen in Form einer
// numerischen Feldkennung. Es gibt wenige Felder mit in der Groesse
// feststehenden Feldinhalten, die meisten sind variabel, was sich mit einer
// vorlaufenden Feldlaenge leicht bewerkstelligen laesst. Darueber hinaus
// werden als Endemarkierung eines Feldes die ASCII-Werte 13 und 10,
// gleichbedeutend mit Carriage return und Linefeed, verlangt.
//
// Jedes Feld hat die gleiche Struktur. Alle Informationen sind als
// ASCII-Zeichen dargestellt. Gemaess der Feldkennung wird der zugehoerige
// Eintrag der Feldtabelle herangezogen.
//
// Fuer die Laengenberechnung eines Feldes gilt die Regel: Feldinhalt + 9
//
// Struktur eines Datenfeldes
//
// -----------------------------------------------------------------------------
// Feldteil         Laenge [Byte]       Bedeutung
// -----------------------------------------------------------------------------
// Laenge           3                   Feldlaenge in Bytes
// Kennung          4                   Feldkennung
// Inhalt           variabel            Abrechnungsinformationen
// Ende             2                   ASCII-Wert 13 = CR (Wagenruecklauf)
//                                      ASCII-Wert 10 = LF (Zeilenvorschub)
// -----------------------------------------------------------------------------
//
// Here is an extract from the German "Arztpraxis Wiegand" (APW) documentation,
// available at:
// http://www.apw-wiegand.de/
//
// Patientennummerkonvertierung:
// Beim BDT ... werden die Patientennummern nach folgender Formel konvertiert:
// Stelle 1: immer 1
// Stelle 2-3: Parallelabrechnungsnummer (meist 01)
// Stelle 4-5: 1. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge (z.B. a->01, z->26)
// Stelle 6-7: 2. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge
// ab Stelle 8: ab Stelle 3 der APW-PatNr
//

//
// Forward declarations.
//

/**
 * Decodes the source into the destination, according to the given language.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source
 * @param p7 the source count
 * @param p8 the knowledge memory
 * @param p9 the knowledge memory count
 * @param p10 the language
 * @param p11 the language count
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

/**
 * Decodes an xdt field.
 *
 * @param p0 the destination field size (Hand over as reference!)
 * @param p1 the destination field identification (Hand over as reference!)
 * @param p2 the destination field content (Hand over as reference!)
 * @param p3 the destination field content count (Hand over as reference!)
 * @param p4 the destination verification flag
 * @param p5 the source byte array (Hand over as reference!)
 * @param p6 the source byte array count
 */
void decode_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p6;

        if (p5 != *NULL_POINTER_MEMORY_MODEL) {

            void** s = (void**) p5;

            if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                int* v = (int*) p4;

                if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                    int* fcc = (int*) p3;

                    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                        void** fc = (void**) p2;

                        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                            int* fs = (int*) p0;

                            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xdt field.");

                            // The remaining bytes in the source byte array.
                            // They are used to check that the array border is not crossed.
                            int rem = (*sc * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                            if (rem >= (*XDT_FIELD_SIZE_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Decode xdt field size.
                                decode_integer(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *s, (void*) XDT_FIELD_SIZE_COUNT);

                                // Increment source xdt byte array index.
                                *s = *s + (*XDT_FIELD_SIZE_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                                rem = rem - (*XDT_FIELD_SIZE_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                            }

                            if (rem >= (*XDT_FIELD_IDENTIFICATION_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Decode xdt field identification.
                                decode_integer(p1, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *s, (void*) XDT_FIELD_IDENTIFICATION_COUNT);

                                // Increment source xdt byte array index.
                                *s = *s + (*XDT_FIELD_IDENTIFICATION_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                                rem = rem - (*XDT_FIELD_IDENTIFICATION_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                            }

                            if (*fs >= ((*XDT_FIELD_SIZE_COUNT + *XDT_FIELD_IDENTIFICATION_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Calculate xdt field content count.
                                //
                                // CAUTION! The xdt field size comprises all characters:
                                // - field size (3 bytes)
                                // - field identification (4 bytes)
                                // - field content (VARIABLE!)
                                // - carriage return (1 byte)
                                // - line feed (1 byte)
                                //
                                // It therefore has to be decremented here, so that
                                // only the actual xdt field content count remains.
                                *fcc = *fs - ((*XDT_FIELD_SIZE_COUNT + *XDT_FIELD_IDENTIFICATION_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                                if (rem >= *fcc) {

                                    // Store xdt field content, to be returned.
                                    *fc = *s;

                                    // Increment source xdt byte array index.
                                    *s = *s + *fcc;
                                    rem = rem - *fcc;
                                }

                            } else {

                                // Store xdt field content, to be returned.
                                *fc = *NULL_POINTER_MEMORY_MODEL;
                                *fcc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                            }

                            if (rem >= ((*PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT) * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) {

                                // Verify if field end is reached (carriage return and line feed).

                                if (*((wchar_t*) *s) == *CARRIAGE_RETURN_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                                    // Increment source xdt byte array index.
                                    *s = *s + (*PRIMITIVE_MEMORY_MODEL_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                                    if (*((wchar_t*) *s) == *LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                                        // Increment source xdt byte array index.
                                        *s = *s + (*PRIMITIVE_MEMORY_MODEL_COUNT * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

                                        // Set verification flag indicating that
                                        // the xdt field was decoded correctly.
                                        *v = *NUMBER_1_INTEGER_MEMORY_MODEL;
                                    }
                                }
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt field. The field size is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt field. The field content is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt field. The field content count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt field. The verification flag is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt field. The source byte array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt field. The source count is null.");
    }
}

/**
 * Decodes the next xdt field.
 *
 * @param p0 the next field count = number of bytes to the next field (Hand over as reference!)
 * @param p1 the byte array
 * @param p2 the byte array count
 */
void decode_xdt_next_field(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* ac = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            wchar_t* a = (wchar_t*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                int* nc = (int*) p0;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode next xdt field.");

                // The loop variable.
                int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (j >= *ac) {

                        // Set next field count to the end, that is to the
                        // full array count, as the carriage return plus
                        // line feed characters have not been found or
                        // the remaining array count was too small.
                        *nc = *ac;

                        break;
                    }

                    if ((j + (*PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT)) <= *ac) {

                        if (*(a + (j * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE)) == *CARRIAGE_RETURN_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                            if (*(a + (j * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE) + *PRIMITIVE_MEMORY_MODEL_COUNT) == *LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL) {

                                // Set next field count to the first character following
                                // the carriage return plus line feed characters.
                                *nc = j + (*PRIMITIVE_MEMORY_MODEL_COUNT + *PRIMITIVE_MEMORY_MODEL_COUNT);

                                // Set loop variable to full array count ac, as the next
                                // field has been found, so that the loop can be left.
                                j = *ac;
                            }
                        }
                    }

                    // Increment loop variable.
                    j++;
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode for next xdt field. The next field count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode for next xdt field. The byte array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode for next xdt field. The byte array count is null.");
    }
}

/**
 * Decodes an xdt record.
 *
 * @param p0 the record size (Hand over as reference!)
 * @param p1 the record identification (Hand over as reference!)
 * @param p2 the record content (Hand over as reference!)
 * @param p3 the record content count (Hand over as reference!)
 * @param p4 the source byte array (Hand over as reference!)
 * @param p5 the source byte array count
 */
void decode_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p5;

        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

            void** s = (void**) p4;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                int* rcc = (int*) p3;

                if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                    void** rc = (void**) p2;

                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                        int* rs = (int*) p0;

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xdt record.");

                        // Reset record size.
                        *rs = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The remaining bytes in the source byte array.
                        // They are used to check that the array border is not crossed.
                        int rem = (*sc * *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
                        // The field size.
                        int fs = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The field identification.
                        int fid = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The field content.
                        void* fc = *NULL_POINTER_MEMORY_MODEL;
                        int fcc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The verification flag.
                        int v = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The next field count.
                        int nc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The decode/ parse mode:
                        // 0 - looking for the begin of a record
                        // 1 - within a record, looking for the begin of the next
                        //     record, which demarcates the end of this record
                        int m = *NUMBER_0_INTEGER_MEMORY_MODEL;

                        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                            if (rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                break;
                            }

                            // Decode xdt field (size, identification, content).
                            decode_xdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, p4, (void*) &rem);

/*??
                            // Test values.
                            fwprintf(stdout, L"Test: Decode xdt record. Field size fs: %i\n", fs);
                            fwprintf(stdout, L"Test: Decode xdt record. Field identification id: %i\n", fid);
                            fwprintf(stdout, L"Test: Decode xdt record. Field content count fcc: %i\n", fcc);
*/

                            if (v == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                                // The verification flag is set, which means that
                                // the xdt field was decoded correctly and the carriage
                                // return plus line feed characters were reached.

                                // Decrement remaining bytes in the source byte array.
                                rem = rem - fs;

                                // Increment record size.
                                *rs = *rs + fs;
                                // Increment record content count.
                                *rcc = *rcc + fs;

                                if (fid == *RECORD_IDENTIFICATION_FIELD_XDT_NAME) {

                                    if (m == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                        // Set decode/parse mode to "1".
                                        // This is the begin of a record.
                                        m = *NUMBER_1_INTEGER_MEMORY_MODEL;

                                        // Decode xdt record identification.
                                        decode_integer(p1, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, fc, (void*) &fcc);

                                    } else {

                                        // The current decode mode is "1", which means that
                                        // the begin of a record had been detected before.
                                        // So, this record identification field already
                                        // belongs to the next following record.
                                        // The previous record's end has thus been reached.

                                        // Decrement source xdt byte array index,
                                        // so that the record identification field
                                        // that had been detected right before
                                        // can be found once more as it represents
                                        // the beginning of the next xdt record.
                                        *s = *s - fs;

                                        // CAUTION! The record size and -content count
                                        // were reset when the record size field was
                                        // found and steadily increased since then.
                                        //
                                        // Both need to be decremented here, because
                                        // the current field size fs was added above!
                                        //
                                        // Since this record identification field
                                        // already belongs to the next record,
                                        // it MUST NOT be counted here!

                                        // Decrement record size.
                                        *rs = *rs - fs;
                                        // Decrement record content count.
                                        *rcc = *rcc - fs;

                                        // Set remaining bytes to zero, as the next record
                                        // has been detected and the loop can be left now.
                                        rem = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                    }

                                } else if (fid == *RECORD_SIZE_FIELD_XDT_NAME) {

                                    // Decode xdt record size.
                                    //
                                    // CAUTION! Do NOT use the following line:
                                    // decode_integer(p0, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, fc, (void*) &fcc);
                                    //
                                    // This is because the record content size is
                                    // counted using the loop variable j.
                                    // This is safer than relying on the given record size.

                                    // Store xdt record content.
                                    //
                                    // CAUTION! Everything following this record
                                    // size field belongs to its content.
                                    // The pointer s was already increased above,
                                    // so that the record size and -identification
                                    // are NOT included!
                                    // The current value of s points to the beginning
                                    // of the first field of the record's CONTENT.
                                    *rc = *s;

                                    // Reset record content count, in order to
                                    // count the xdt record content now following.
                                    *rcc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                }

                            } else {

                                // The verification flag is NOT set, which means
                                // that the xdt field was NOT decoded correctly.

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                                // Reset next field count.
                                nc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                // Count the number of bytes to the next carriage return-
                                // plus line feed character.
                                decode_xdt_next_field((void*) &nc, *s, (void*) &rem);

                                // Increment source xdt byte array index, so that following
                                // fields may be found in the next loop cycle.
                                *s = *s + nc;
                                rem = rem - nc;

                                // Increment record size.
                                *rs = *rs + *NUMBER_1_INTEGER_MEMORY_MODEL;

                                // Increment record content count.
                                *rcc = *rcc + *NUMBER_1_INTEGER_MEMORY_MODEL;
                            }
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt record. The record size is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt record. The record content is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt record. The record content count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt record. The source byte array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt record. The source byte array count is null.");
    }
}

/**
 * Decodes an xdt package.
 *
 * @param p0 the package size (Hand over as reference!)
 * @param p1 the package header (Hand over as reference!)
 * @param p2 the package header count (Hand over as reference!)
 * @param p3 the package footer (Hand over as reference!)
 * @param p4 the package footer count (Hand over as reference!)
 * @param p5 the package content (Hand over as reference!)
 * @param p6 the package content count (Hand over as reference!)
 * @param p7 the source byte array (Hand over as reference!)
 * @param p8 the source byte array count
 */
void decode_xdt_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p8;

        if (p7 != *NULL_POINTER_MEMORY_MODEL) {

            void** s = (void**) p7;

            if (p6 != *NULL_POINTER_MEMORY_MODEL) {

                int* pcc = (int*) p6;

                if (p5 != *NULL_POINTER_MEMORY_MODEL) {

                    void** pc = (void**) p5;

                    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                        int* pfc = (int*) p4;

                        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                            void** pf = (void**) p3;

                            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                                int* phc = (int*) p2;

                                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                                    void** ph = (void**) p1;

                                    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                                        int* ps = (int*) p0;

                                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode xdt package.");

                                        // Reset package size.
                                        *ps = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                        // The remaining bytes in the source byte array.
                                        // They are used to check that the array border
                                        // is not crossed, and to leave the loop.
                                        int rem = *sc;
                                        // The record size.
                                        int rs = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                        // The record identification.
                                        int rid = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                        // The loop variable.
                                        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                                            if (rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                                break;
                                            }

                                            // Decode xdt record (size, identification, content).
                                            //
                                            // CAUTION! The package header and -footer count are
                                            // handed over as parameters to get the record content.
                                            // A local variable defined in this function may NOT
                                            // be used as its value is lost when returning from
                                            // this function. But a valid value has to be
                                            // returned to the calling function.
                                            decode_xdt_record((void*) &rs, (void*) &rid, p3, p4, p7, (void*) &rem);

/*??
                                            // Test values.
                                            fwprintf(stdout, L"Test: Decode xdt package. Record size rs: %i\n", rs);
                                            fwprintf(stdout, L"Test: Decode xdt package. Record identification id: %i\n", rid);
                                            fwprintf(stdout, L"Test: Decode xdt package. Record content count pfc: %i\n\n", *pfc);
*/

                                            if (rs > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                                                // Decrement remaining bytes in the source byte array.
                                                rem = rem - rs;

                                                // Increment package size.
                                                *ps = *ps + rs;

                                                // Increment loop variable.
                                                j = j + rs;

                                                if (rid == *DATA_PACKAGE_HEADER_RECORD_XDT_NAME) {

                                                    // Store xdt package header.
                                                    //
                                                    // CAUTION! This is only the record content
                                                    // WITHOUT the record size and -identification!
                                                    *ph = *pf;
                                                    *phc = *pfc;

/*??
                                                    // Test values.
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package header: %i\n", *ph);
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package header count: %i\n\n", *phc);
*/

                                                    // Store xdt package content.
                                                    //
                                                    // CAUTION! Everything following this package
                                                    // header record up to the package footer
                                                    // record belongs to the package's content.
                                                    *pc = *s;

                                                    // Reset loop variable.
                                                    j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                                                } else if (rid == *DATA_PACKAGE_FOOTER_RECORD_XDT_NAME) {

                                                    // CAUTION! The package footer does NOT
                                                    // have to be stored here explicitly.
                                                    // It was already handed over as parameter
                                                    // to the "decode_xdt_record" function,
                                                    // so that its value is already set.

/*??
                                                    // Test values.
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package footer: %i\n", *pf);
                                                    fwprintf(stdout, L"Test: Decode xdt package. Package footer count: %i\n\n", *pfc);
*/

                                                    // Decrement package content count.
                                                    //
                                                    // CAUTION! The package content count pcc was
                                                    // reset when the data package header record
                                                    // was found and steadily increased since then.
                                                    //
                                                    // It needs to be decremented here, because
                                                    // the current record size rs was added above,
                                                    // but this data package footer record does
                                                    // NOT belong to the data package content
                                                    // and hence should not be counted.
                                                    *pcc = j - rs;

                                                    // CAUTION! Do NOT decrement the package
                                                    // size, as this package footer record
                                                    // DOES belong to the package!

                                                    // Set remaining bytes to zero, as the package footer
                                                    // has been detected and the loop can be left now.
                                                    rem = *NUMBER_0_INTEGER_MEMORY_MODEL;
                                                }

                                            } else {

                                                // If the xdt record size is zero or smaller, then
                                                // increment the source xdt byte array index by one,
                                                // in order to ensure that this loop will finally
                                                // find an end.
                                                *s = *s + *NUMBER_1_INTEGER_MEMORY_MODEL;
                                                rem = rem - *NUMBER_1_INTEGER_MEMORY_MODEL;

                                                // Increment package size.
                                                *ps = *ps + *NUMBER_1_INTEGER_MEMORY_MODEL;

                                                // Increment loop variable.
                                                j = j + *NUMBER_1_INTEGER_MEMORY_MODEL;
                                            }
                                        }

                                    } else {

                                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package size is null.");
                                    }

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package header is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package header count is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package footer is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package footer count is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package content is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The package content count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The source byte array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt package. The source byte array count is null.");
    }
}

/**
 * Decodes the model.
 *
 * @param p0 the destination name (Hand over as reference!)
 * @param p1 the destination name count (Hand over as reference!)
 * @param p2 the destination name size (Hand over as reference!)
 * @param p3 the destination abstraction (Hand over as reference!)
 * @param p4 the destination abstraction count (Hand over as reference!)
 * @param p5 the destination abstraction size (Hand over as reference!)
 * @param p6 the destination model (Hand over as reference!)
 * @param p7 the destination model count (Hand over as reference!)
 * @param p8 the destination model size (Hand over as reference!)
 * @param p9 the destination details (Hand over as reference!)
 * @param p10 the destination details count (Hand over as reference!)
 * @param p11 the destination details size (Hand over as reference!)
 * @param p12 the source model
 * @param p13 the source model count
 * @param p14 the source abstraction
 * @param p15 the source abstraction count
 * @param p16 the source name
 * @param p17 the source name count
 */
void decode_xdt_decode_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p11 != *NULL_POINTER_MEMORY_MODEL) {

        int** ds = (int**) p11;

        if (p10 != *NULL_POINTER_MEMORY_MODEL) {

            int** dc = (int**) p10;

            if (p8 != *NULL_POINTER_MEMORY_MODEL) {

                int** ms = (int**) p8;

                if (p7 != *NULL_POINTER_MEMORY_MODEL) {

                    int** mc = (int**) p7;

                    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

                        int** as = (int**) p5;

                        if (p4 != *NULL_POINTER_MEMORY_MODEL) {

                            int** ac = (int**) p4;

                            if (p2 != *NULL_POINTER_MEMORY_MODEL) {

                                int** ns = (int**) p2;

                                if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                                    int** nc = (int**) p1;

                                    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode model.");

                                    allocate_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p14, p15);

                                    // Decode name.
                                    decode_ascii_character_vector(p0, (void*) *nc, (void*) *ns, p16, p17);
                                    // Decode abstraction.
                                    decode_ascii_character_vector(p3, (void*) *ac, (void*) *as, p14, p15);
                                    // Decode model.
                                    decode(p6, (void*) *mc, (void*) *ms, p9, (void*) *dc, (void*) *ds, p12, p13, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p14, p15);

                                } else {

                                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The name count is null.");
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The name size is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The abstraction count is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The abstraction size is null.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The model count is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The model size is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The details count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode model. The details size is null.");
    }
}

/**
 * Selects an xdt field.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source field content
 * @param p4 the source field content count
 * @param p5 the source field identification
 */
void decode_xdt_select_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* id = (int*) p5;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xdt field.");

/*??
        // Test values.
        fwprintf(stdout, L"Test: Select xdt field. Field identification: %i\n", *id);
*/

        // The knowledge model name.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ns = *NULL_POINTER_MEMORY_MODEL;
        // The knowledge model abstraction.
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* as = *NULL_POINTER_MEMORY_MODEL;
        // The knowledge model model.
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* ms = *NULL_POINTER_MEMORY_MODEL;
        // The knowledge model details.
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* ds = *NULL_POINTER_MEMORY_MODEL;

        if (*id == *KBV_TEST_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) KBV_TEST_NUMBER_FIELD_XDT_MODEL_NAME, (void*) KBV_TEST_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *RESPONSIBLE_ENTITY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) RESPONSIBLE_ENTITY_FIELD_XDT_MODEL_NAME, (void*) RESPONSIBLE_ENTITY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SOFTWARE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SOFTWARE_FIELD_XDT_MODEL_NAME, (void*) SOFTWARE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *HARDWARE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) HARDWARE_FIELD_XDT_MODEL_NAME, (void*) HARDWARE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SOFTWARE_RELEASE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SOFTWARE_RELEASE_FIELD_XDT_MODEL_NAME, (void*) SOFTWARE_RELEASE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_PRACTICE_TYPE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_CATEGORY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_CATEGORY_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_CATEGORY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_STREET_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_STREET_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_STREET_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_POSTCODE_AND_PLACE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_WITH_SERVICE_INDICATOR_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_PHONE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_PHONE_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_PHONE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_FAX_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_FAX_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_FAX_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_MODEM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_MODEM_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_MODEM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_MODEL_NAME, (void*) PHYSICIAN_NUMBER_WITHIN_PRACTICE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_1_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_1_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_2_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_2_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_3_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_3_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_4_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_4_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_5_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_5_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_6_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_6_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_7_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_7_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_8_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_8_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_9_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_9_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_10_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_10_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_11_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_11_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_12_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_12_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_13_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_13_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_14_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_14_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_15_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_15_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_16_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_16_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_17_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_17_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_18_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_18_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_19_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_19_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_20_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_20_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_21_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_21_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_22_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_22_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_23_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_23_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_24_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_24_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_25_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_0010_CATEGORY_25_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) PATIENT_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_NAME_AFFIX_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_NAME_AFFIX_FIELD_XDT_MODEL_NAME, (void*) PATIENT_NAME_AFFIX_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_LAST_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_LAST_NAME_FIELD_XDT_MODEL_NAME, (void*) PATIENT_LAST_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_FIRST_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_FIRST_NAME_FIELD_XDT_MODEL_NAME, (void*) PATIENT_FIRST_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_BIRTH_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_BIRTH_DATE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_BIRTH_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_TITLE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_TITLE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_TITLE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_MODEL_NAME, (void*) PATIENT_HEALTH_INSURANCE_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_RESIDENCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_RESIDENCE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_RESIDENCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_STREET_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_STREET_FIELD_XDT_MODEL_NAME, (void*) PATIENT_STREET_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_HEALTH_INSURANCE_TYPE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_SEX_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_SEX_FIELD_XDT_MODEL_NAME, (void*) PATIENT_SEX_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_EMPLOYER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_EMPLOYER_FIELD_XDT_MODEL_NAME, (void*) PATIENT_EMPLOYER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_MODEL_NAME, (void*) PATIENT_ACCIDENT_INSURANCE_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INSURANT_LAST_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INSURANT_LAST_NAME_FIELD_XDT_MODEL_NAME, (void*) INSURANT_LAST_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INSURANT_FIRST_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INSURANT_FIRST_NAME_FIELD_XDT_MODEL_NAME, (void*) INSURANT_FIRST_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INSURANT_BIRTH_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) INSURANT_BIRTH_DATE_FIELD_XDT_MODEL_NAME, (void*) INSURANT_BIRTH_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INSURANT_RESIDENCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INSURANT_RESIDENCE_FIELD_XDT_MODEL_NAME, (void*) INSURANT_RESIDENCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INSURANT_STREET_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INSURANT_STREET_FIELD_XDT_MODEL_NAME, (void*) INSURANT_STREET_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INJURED_PHONE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INJURED_PHONE_FIELD_XDT_MODEL_NAME, (void*) INJURED_PHONE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INSURANT_SEX_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INSURANT_SEX_FIELD_XDT_MODEL_NAME, (void*) INSURANT_SEX_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_X_RAY_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_X_RAY_NUMBER_FIELD_XDT_MODEL_NAME, (void*) PATIENT_X_RAY_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_ARCHIVE_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_ARCHIVE_NUMBER_FIELD_XDT_MODEL_NAME, (void*) PATIENT_ARCHIVE_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_MODEL_NAME, (void*) PATIENT_EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_SINCE_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_SINCE_DATE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_SINCE_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_CHANGE_OF_INSURANCE_INCEPTION_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PROFESSION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PROFESSION_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PROFESSION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_BODY_HEIGHT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_BODY_HEIGHT_FIELD_XDT_MODEL_NAME, (void*) PATIENT_BODY_HEIGHT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_BODY_WEIGHT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_BODY_WEIGHT_FIELD_XDT_MODEL_NAME, (void*) PATIENT_BODY_WEIGHT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_MODEL_NAME, (void*) PATIENT_EMPLOYER_REDUNDANT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PHONE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PHONE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PHONE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_NATIONALITY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_NATIONALITY_FIELD_XDT_MODEL_NAME, (void*) PATIENT_NATIONALITY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_MOTHER_TONGUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_MOTHER_TONGUE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_MOTHER_TONGUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) PATIENT_GENERAL_PRACTITIONER_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_RESIDENCE_TO_MEDICAL_PRACTICE_DISTANCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PHYSICIAN_IDENTIFICATION_IN_GROUP_PRACTICE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PRESCRIPTION_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PERMANENT_DIAGNOSES_BEGIN_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PERMANENT_DIAGNOSES_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PERMANENT_DRUGS_BEGIN_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PERMANENT_DRUGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PERMANENT_DRUGS_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PERMANENT_DRUGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_RISK_FACTORS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_RISK_FACTORS_FIELD_XDT_MODEL_NAME, (void*) PATIENT_RISK_FACTORS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_ALLERGIES_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_ALLERGIES_FIELD_XDT_MODEL_NAME, (void*) PATIENT_ALLERGIES_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_ACCIDENTS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_ACCIDENTS_FIELD_XDT_MODEL_NAME, (void*) PATIENT_ACCIDENTS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_SURGERIES_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_SURGERIES_FIELD_XDT_MODEL_NAME, (void*) PATIENT_SURGERIES_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_ANAMNESIS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_ANAMNESIS_FIELD_XDT_MODEL_NAME, (void*) PATIENT_ANAMNESIS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_MODEL_NAME, (void*) PATIENT_NUMBER_OF_BIRTHS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_MODEL_NAME, (void*) PATIENT_NUMBER_OF_CHILDREN_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_MODEL_NAME, (void*) PATIENT_NUMBER_OF_PREGNANCIES_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_PERMANENT_THERAPY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_PERMANENT_THERAPY_FIELD_XDT_MODEL_NAME, (void*) PATIENT_PERMANENT_THERAPY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_MODEL_NAME, (void*) PATIENT_RECALL_APPOINTMENT_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_1_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_1_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_2_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_2_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_3_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_3_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_4_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_4_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_5_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_5_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_6_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_6_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_7_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_7_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_8_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_8_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_9_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_9_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_10_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6100_CATEGORY_10_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_QUARTER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_QUARTER_FIELD_XDT_MODEL_NAME, (void*) INVOICE_QUARTER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_ISSUANCE_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_ISSUANCE_DATE_FIELD_XDT_MODEL_NAME, (void*) INVOICE_ISSUANCE_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_VALIDITY_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_VALIDITY_DATE_FIELD_XDT_MODEL_NAME, (void*) INVOICE_VALIDITY_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_INSURANCE_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_INSURANCE_NUMBER_FIELD_XDT_MODEL_NAME, (void*) INVOICE_INSURANCE_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_INSURANCE_OFFICE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_INSURANCE_OFFICE_FIELD_XDT_MODEL_NAME, (void*) INVOICE_INSURANCE_OFFICE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_MODEL_NAME, (void*) INVOICE_INSURANCE_SUB_CATEGORY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_BILLING_CATEGORY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_BILLING_CATEGORY_FIELD_XDT_MODEL_NAME, (void*) INVOICE_BILLING_CATEGORY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_MODEL_NAME, (void*) INVOICE_INSURANCE_CARD_LAST_READ_ACCESS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_MMYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_MMYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_MODEL_NAME, (void*) INVOICE_INSURANCE_CARD_VALIDITY_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_MODEL_NAME, (void*) INVOICE_IK_INSURANCE_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_MODEL_NAME, (void*) INVOICE_VK_INSURANCE_STATUS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_MODEL_NAME, (void*) INVOICE_VK_EAST_WEST_STATUS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_BILLING_SCALE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_BILLING_SCALE_FIELD_XDT_MODEL_NAME, (void*) INVOICE_BILLING_SCALE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_BILLING_AREA_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_BILLING_AREA_FIELD_XDT_MODEL_NAME, (void*) INVOICE_BILLING_AREA_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_CAUSE_OF_PAIN_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_SUPPOSED_ACCOUCHEMENT_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_DIAGNOSIS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_DIAGNOSIS_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_DIAGNOSIS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_EXPLANATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_EXPLANATION_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_EXPLANATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_CHECK_BOX_MUVO_LSR_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_CHECK_BOX_MUVO_HAH_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_CHECK_BOX_AB0_RH_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_CHECK_BOX_AK_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_CHECK_BOX_AK_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_CHECK_BOX_AK_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_FROM_PHYSICIAN_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME, (void*) REFERRAL_TO_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_MODEL_NAME, (void*) INPATIENT_TREATMENT_REFERRAL_BY_LAW_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_MODEL_NAME, (void*) INPATIENT_TREATMENT_FROM_TO_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INPATIENT_TREATMENT_CLASS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INPATIENT_TREATMENT_CLASS_FIELD_XDT_MODEL_NAME, (void*) INPATIENT_TREATMENT_CLASS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INPATIENT_HOSPITAL_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) INPATIENT_HOSPITAL_NAME_FIELD_XDT_MODEL_NAME, (void*) INPATIENT_HOSPITAL_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INPATIENT_HOSPITAL_STAY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INPATIENT_HOSPITAL_STAY_FIELD_XDT_MODEL_NAME, (void*) INPATIENT_HOSPITAL_STAY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *INVOICE_SUB_CATEGORY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) INVOICE_SUB_CATEGORY_FIELD_XDT_MODEL_NAME, (void*) INVOICE_SUB_CATEGORY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME, (void*) EMERGENCY_SUBSEQUENT_TREATMENT_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EMERGENCY_FINDINGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) EMERGENCY_FINDINGS_FIELD_XDT_MODEL_NAME, (void*) EMERGENCY_FINDINGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EMERGENCY_SYMPTOMS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) EMERGENCY_SYMPTOMS_FIELD_XDT_MODEL_NAME, (void*) EMERGENCY_SYMPTOMS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_DATE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_TIME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_TIME_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_TIME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_ADMISSION_IN_PRACTICE_TIME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_LABOUR_TIME_BEGIN_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_LOCATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_LOCATION_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_LOCATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_EMPLOYMENT_AS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_EMPLOYMENT_SINCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_NATIONALITY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_COMPANY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_COMPANY_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_COMPANY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_COURSE_OF_EVENTS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_PATIENT_BEHAVIOUR_AFTERWARDS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_FIRST_TIME_TREATMENT_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_TREATMENT_BY_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_KIND_OF_TREATMENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_ALCOHOL_INFLUENCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_SIGNS_FOR_ALCOHOL_INFLUENCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_BLOOD_WITHDRAWAL_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_FINDINGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_FINDINGS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_FINDINGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_X_RAY_RESULT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_X_RAY_RESULT_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_X_RAY_RESULT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_KIND_OF_FIRST_TREATMENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_ABNORMAL_CHANGES_INDEPENDENT_FROM_ACCIDENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_STATEMENTS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_KIND_OF_CONCERNS_AGAINST_CLASSIFICATION_AS_ACCIDENT_AT_WORK_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_ABLE_TO_WORK_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_ABLE_TO_WORK_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_ABLE_TO_WORK_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_ABLE_TO_WORK_FROM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_UNABLE_TO_WORK_CERTIFICATE_ISSUANCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_NECESSARY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_SPECIAL_CURATIVE_TREATMENT_BY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_ADDRESS_OF_TREATING_PHYSICIAN_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_UNABLE_TO_WORK_FROM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_EXPECTED_DURATION_OF_INABILITY_TO_WORK_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_KIND_OF_BILL_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_KIND_OF_BILL_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_KIND_OF_BILL_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_GENERAL_CURATIVE_TREATMENT_BY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_UNABLE_TO_WORK_FOR_LONGER_THAN_THREE_DAYS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_UNABILITY_TO_WORK_CERTIFIED_UNTIL_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_MODEL_NAME, (void*) ACCIDENT_INSPECTION_REQUIRED_ON_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_NUMBER_FIELD_XDT_MODEL_NAME, (void*) BILLING_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_ADDRESS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_ADDRESS_FIELD_XDT_MODEL_NAME, (void*) BILLING_ADDRESS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME, (void*) BILLING_REFERRING_PHYSICIAN_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_DATE_FIELD_XDT_MODEL_NAME, (void*) BILLING_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_TOTAL_SUM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_TOTAL_SUM_FIELD_XDT_MODEL_NAME, (void*) BILLING_TOTAL_SUM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_MODEL_NAME, (void*) BILLING_ASSIGNMENT_DECLARATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_MODEL_NAME, (void*) BILLING_PHYSICIAN_SUB_ACCOUNT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_ATTACHMENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_ATTACHMENT_FIELD_XDT_MODEL_NAME, (void*) BILLING_ATTACHMENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_HEADER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_HEADER_FIELD_XDT_MODEL_NAME, (void*) BILLING_HEADER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_FOOTER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_FOOTER_FIELD_XDT_MODEL_NAME, (void*) BILLING_FOOTER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_TREATMENT_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_TREATMENT_DATE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_TREATMENT_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_GNR_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_GNR_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) SERVICE_GNR_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_MODEL_NAME, (void*) SERVICE_KIND_OF_EXAMINATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_ADDRESSEE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_ADDRESSEE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_ADDRESSEE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_MODEL_NAME, (void*) SERVICE_DISTANCE_IN_KILOMETRES_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_MULTIPLIER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_MULTIPLIER_FIELD_XDT_MODEL_NAME, (void*) SERVICE_MULTIPLIER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_TIME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_TIME_FIELD_XDT_MODEL_NAME, (void*) SERVICE_TIME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_ORDER_EXECUTION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_ORDER_EXECUTION_FIELD_XDT_MODEL_NAME, (void*) SERVICE_ORDER_EXECUTION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_DKM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_DKM_FIELD_XDT_MODEL_NAME, (void*) SERVICE_DKM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_MODEL_NAME, (void*) SERVICE_FREE_EXPLANATORY_STATEMENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_EXPLANATORY_DRUG_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_EXPLANATORY_DRUG_FIELD_XDT_MODEL_NAME, (void*) SERVICE_EXPLANATORY_DRUG_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_MODEL_NAME, (void*) SERVICE_MATERIAL_COSTS_DESCRIPTION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_MODEL_NAME, (void*) SERVICE_MATERIAL_COSTS_DPF_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_MODEL_NAME, (void*) SERVICE_PERCENT_OF_TREATMENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_ORGAN_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_ORGAN_FIELD_XDT_MODEL_NAME, (void*) SERVICE_ORGAN_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_LOCATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_LOCATION_FIELD_XDT_MODEL_NAME, (void*) SERVICE_LOCATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_ZONE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_ZONE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_ZONE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_GNR_DESCRIPTION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_GNR_DESCRIPTION_FIELD_XDT_MODEL_NAME, (void*) SERVICE_GNR_DESCRIPTION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_FEE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_FEE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_FEE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_FACTOR_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_FACTOR_FIELD_XDT_MODEL_NAME, (void*) SERVICE_FACTOR_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_SUM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_SUM_FIELD_XDT_MODEL_NAME, (void*) SERVICE_SUM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_TOTAL_SUM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_TOTAL_SUM_FIELD_XDT_MODEL_NAME, (void*) SERVICE_TOTAL_SUM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_POINT_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_POINT_VALUE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_POINT_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_FEE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_FEE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_FEE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_MODEL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_OF_CERTIFICATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_DIAGNOSIS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_DIAGNOSIS_FIELD_XDT_MODEL_NAME, (void*) BILLING_DIAGNOSIS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *BILLING_ICD_KEY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) BILLING_ICD_KEY_FIELD_XDT_MODEL_NAME, (void*) BILLING_ICD_KEY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_DATA_COLLECTION_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_DATA_COLLECTION_TIME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_CURRENT_DIAGNOSIS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_DRUG_PRESCRIBED_WITH_PRESCRIPTION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_DRUG_PRESCRIBED_WITHOUT_PRESCRIPTION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_PHYSICIAN_SAMPLE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_FINDINGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_FINDINGS_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_FINDINGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_EXTERNAL_FINDINGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_LABORATORY_FINDINGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_X_RAY_FINDINGS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_X_RAY_FINDINGS_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_X_RAY_FINDINGS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_SUBSEQUENT_LINE_COUNT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_COMMENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_COMMENT_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_COMMENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_FORMATTED_RESULT_TABLE_TEXT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_BLOOD_PRESSURE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_BLOOD_PRESSURE_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_BLOOD_PRESSURE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_SYMPTOMS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_SYMPTOMS_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_SYMPTOMS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_THERAPY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_THERAPY_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_THERAPY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_PHYSICAL_THERAPY_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_REFERRAL_CONTENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_REFERRAL_CONTENT_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_REFERRAL_CONTENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_WORK_DISABILITY_DURATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_WORK_DISABILITY_CAUSE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_HOSPITALISATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_HOSPITALISATION_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_HOSPITALISATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_MODEL_NAME, (void*) TREATMENT_HOSPITALISATION_CAUSE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_CERTIFICATE_KIND_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_CERTIFICATE_KIND_FIELD_XDT_MODEL_NAME, (void*) LETTER_CERTIFICATE_KIND_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_CERTIFICATE_CONTENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_CERTIFICATE_CONTENT_FIELD_XDT_MODEL_NAME, (void*) LETTER_CERTIFICATE_CONTENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_MODEL_NAME, (void*) LETTER_FILE_ARCHIVE_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_FILE_FORMAT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_FILE_FORMAT_FIELD_XDT_MODEL_NAME, (void*) LETTER_FILE_FORMAT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_FILE_CONTENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_FILE_CONTENT_FIELD_XDT_MODEL_NAME, (void*) LETTER_FILE_CONTENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_FILE_URL_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_FILE_URL_FIELD_XDT_MODEL_NAME, (void*) LETTER_FILE_URL_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_ATTESTATION_KIND_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_ATTESTATION_KIND_FIELD_XDT_MODEL_NAME, (void*) LETTER_ATTESTATION_KIND_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_ATTESTATION_CONTENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_ATTESTATION_CONTENT_FIELD_XDT_MODEL_NAME, (void*) LETTER_ATTESTATION_CONTENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_ADDRESSEE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_ADDRESSEE_FIELD_XDT_MODEL_NAME, (void*) LETTER_ADDRESSEE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_SALUTATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_SALUTATION_FIELD_XDT_MODEL_NAME, (void*) LETTER_SALUTATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_STREET_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_STREET_FIELD_XDT_MODEL_NAME, (void*) LETTER_STREET_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_POSTCODE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_POSTCODE_FIELD_XDT_MODEL_NAME, (void*) LETTER_POSTCODE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_RESIDENCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_RESIDENCE_FIELD_XDT_MODEL_NAME, (void*) LETTER_RESIDENCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_MODEL_NAME, (void*) LETTER_COMPLIMENTARY_CLOSE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_PHONE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_PHONE_FIELD_XDT_MODEL_NAME, (void*) LETTER_PHONE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_FAX_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_FAX_FIELD_XDT_MODEL_NAME, (void*) LETTER_FAX_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_PHYSICIAN_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_PHYSICIAN_NUMBER_FIELD_XDT_MODEL_NAME, (void*) LETTER_PHYSICIAN_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_CONTENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_CONTENT_FIELD_XDT_MODEL_NAME, (void*) LETTER_CONTENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_MODEL_NAME, (void*) LETTER_IMAGE_ARCHIVE_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_GRAPHIC_FORMAT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_GRAPHIC_FORMAT_FIELD_XDT_MODEL_NAME, (void*) LETTER_GRAPHIC_FORMAT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *LETTER_IMAGE_CONTENT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) LETTER_IMAGE_CONTENT_FIELD_XDT_MODEL_NAME, (void*) LETTER_IMAGE_CONTENT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_1_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_1_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_2_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_2_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_3_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_3_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_4_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_4_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_5_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_5_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_6_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_6_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_7_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_7_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_8_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_8_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_9_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_9_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_10_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_10_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_11_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_11_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_12_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_12_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_13_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_13_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_14_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_14_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_15_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_15_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_16_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_16_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_17_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_17_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_18_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_18_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_19_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_19_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_20_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_20_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_21_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_21_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_22_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_22_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_23_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_23_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_24_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_24_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_25_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_25_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_26_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_26_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_27_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_27_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_28_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_28_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_29_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_29_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_30_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_30_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_31_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_31_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_32_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_32_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_33_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_33_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_34_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_34_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_35_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_MODEL_NAME, (void*) FREE_RECORD_6200_CATEGORY_35_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *RECORD_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) RECORD_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) RECORD_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *RECORD_SIZE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) RECORD_SIZE_FIELD_XDT_MODEL_NAME, (void*) RECORD_SIZE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DEVICE_RECEIVER_GDT_ID_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) DEVICE_RECEIVER_GDT_ID_FIELD_XDT_MODEL_NAME, (void*) DEVICE_RECEIVER_GDT_ID_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DEVICE_SENDER_GDT_ID_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) DEVICE_SENDER_GDT_ID_FIELD_XDT_MODEL_NAME, (void*) DEVICE_SENDER_GDT_ID_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_KIND_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_KIND_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_KIND_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_DEVICE_SPECIFICS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_TEST_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_TEST_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_TEST_NAME_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_TEST_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_TEST_STATUS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_TEST_STATUS_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_TEST_STATUS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_TEST_RESULT_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_TEST_RESULT_UNIT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_LIMIT_INDICATOR_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_LIMIT_INDICATOR_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_LIMIT_INDICATOR_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_INDEX_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_MATERIAL_SPECIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_COLLECTION_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMM_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_COLLECTION_TIME_OLD_FORMAT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_DATA_STREAM_UNITS_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_DATA_STREAM_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_DATA_STREAM_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_DATA_STREAM_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_HHMMSS_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SAMPLE_COLLECTION_TIME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_GERM_IDENTIFICATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_GERM_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_GERM_NAME_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_GERM_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_GERM_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_GERM_NUMBER_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_GERM_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_RESISTANCE_METHOD_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_RESISTANCE_METHOD_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_RESISTANCE_METHOD_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_ACTIVE_SUBSTANCE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_ACTIVE_SUBSTANCE_GENERIC_NAME_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_MHK_BREAKPOINT_VALUE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_RESISTANCE_INTERPRETATION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_NORMAL_VALUE_TEXT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_NORMAL_VALUE_LOWER_LIMIT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_NORMAL_VALUE_UPPER_LIMIT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_REMARK_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_REMARK_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_REMARK_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_RESULT_TEXT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_RESULT_TEXT_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_RESULT_TEXT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_COMPLIMENTARY_CLOSE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *FINDINGS_SIGNATURE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) FINDINGS_SIGNATURE_FIELD_XDT_MODEL_NAME, (void*) FINDINGS_SIGNATURE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_MODEL_NAME, (void*) DATA_MEDIUM_SENDER_PHYSICIAN_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_MEDIUM_CREATION_DATE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION, (void*) XDT_DDMMYYYY_DATETIME_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_MEDIUM_CREATION_DATE_FIELD_XDT_MODEL_NAME, (void*) DATA_MEDIUM_CREATION_DATE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_MODEL_NAME, (void*) DATA_MEDIUM_RUNNING_NUMBER_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_MODEL_NAME, (void*) DATA_MEDIUM_CHARACTER_CODE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_SIZE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_SIZE_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_SIZE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_MEDIUMS_COUNT_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_CHARACTER_SET_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_ADT_VERSION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_ADT_VERSION_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_ADT_VERSION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_BDT_VERSION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_BDT_VERSION_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_BDT_VERSION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_GDT_VERSION_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_GDT_VERSION_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_GDT_VERSION_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_ARCHIVING_TYPE_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_STORAGE_PERIOD_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT,
                (void*) DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_MODEL_NAME, (void*) DATA_PACKAGE_TRANSFER_BEGIN_FIELD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *SYSTEM_INTERNAL_PARAMETER_FIELD_XDT_NAME) {

            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT,
                (void*) SYSTEM_INTERNAL_PARAMETER_FIELD_XDT_MODEL_NAME, (void*) SYSTEM_INTERNAL_PARAMETER_FIELD_XDT_MODEL_NAME_COUNT);
        }

        // No further processing of the xdt field content is necessary!
        // The field represents the final logical model in the xdt format
        // and does not contain any further parts.
        // Its content is therefore decoded directly.

        // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
        if ((n != *NULL_POINTER_MEMORY_MODEL) && (nc != *NULL_POINTER_MEMORY_MODEL) && (ns != *NULL_POINTER_MEMORY_MODEL)
            && (a != *NULL_POINTER_MEMORY_MODEL) && (ac != *NULL_POINTER_MEMORY_MODEL) && (as != *NULL_POINTER_MEMORY_MODEL)) {

            // Add xdt field to xdt record.
            replace_compound_by_name(p0, p1, p2, n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            // Destroy all arrays, since they were not added to the compound.
            // CAUTION! If this was not done here, they would never be deallocated!
            // CAUTION! Use DESCENDING order, as opposed to array allocation!

            // Deallocate knowledge model details.
            deallocate((void*) &d, ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            deallocate((void*) &dc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

            // Deallocate knowledge model model.
            deallocate((void*) &m, ms, a, ac);
            deallocate((void*) &mc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

            // Deallocate knowledge model abstraction.
            deallocate((void*) &a, as, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &as, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

            // A knowledge model channel was not allocated.

            // Deallocate knowledge model name.
            deallocate((void*) &n, ns, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &nc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ns, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xdt field. The field identification is null.");
    }
}

/**
 * Processes the xdt record.
 *
 * @param p0 the destination compound
 * @param p1 the destination compound count
 * @param p2 the destination compound size
 * @param p3 the source record
 * @param p4 the source record count
 */
void decode_xdt_process_record(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void* s = (void*) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xdt record.");

            // The remaining bytes in the source byte array.
            int rem = *sc;
            // The field size.
            int fs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The field identification.
            int fid = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The field content.
            void* fc = *NULL_POINTER_MEMORY_MODEL;
            int fcc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The verification flag.
            int v = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The next field count.
            int nc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                // Decode xdt field (size, identification, content).
                decode_xdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, (void*) &s, (void*) &rem);

/*??
                // Test values.
                fwprintf(stdout, L"Test: Process xdt record. Field size fs: %i\n", fs);
                fwprintf(stdout, L"Test: Process xdt record. Field identification id: %i\n", fid);
                fwprintf(stdout, L"Test: Process xdt record. Field content count fcc: %i\n", fcc);
*/

                if (v == *NUMBER_1_INTEGER_MEMORY_MODEL) {

                    // The verification flag is set, which means that
                    // the xdt field was decoded correctly and the carriage
                    // return plus line feed characters were reached.

                    // Increment source xdt byte array index,
                    // so that following fields may be found
                    // in the next loop cycle.
//??                    s = s + fs;
                    rem = rem - fs;

                    decode_xdt_select_field(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

                } else {

                    // The verification flag is NOT set, which means
                    // that the xdt field was NOT decoded correctly.

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                    // Reset next field count.
                    nc = *NUMBER_0_INTEGER_MEMORY_MODEL;

                    // Count the number of bytes to the next carriage return-
                    // plus line feed character.
                    decode_xdt_next_field((void*) &nc, s, (void*) &rem);

                    // Increment source xdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + nc;
                    rem = rem - nc;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xdt record. The source record is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xdt record. The source record count is null.");
    }
}

/**
 * Selects the xdt record.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source record content
 * @param p4 the source record content count
 * @param p5 the source record identification
 */
void decode_xdt_select_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* id = (int*) p5;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xdt record.");

/*??
        // Test values.
        fwprintf(stdout, L"Test: Select xdt record. Record identification: %i\n", *id);
*/

        // The knowledge model name.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ns = *NULL_POINTER_MEMORY_MODEL;
        // The knowledge model abstraction.
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* as = *NULL_POINTER_MEMORY_MODEL;
        // The knowledge model model.
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* ms = *NULL_POINTER_MEMORY_MODEL;
        // The knowledge model details.
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* ds = *NULL_POINTER_MEMORY_MODEL;

        if (*id == *MEDICAL_PRACTICE_DATA_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) MEDICAL_PRACTICE_DATA_RECORD_XDT_MODEL_NAME, (void*) MEDICAL_PRACTICE_DATA_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_MEDIUM_HEADER_RECORD_XDT_NAME) {

            //?? TODO

        } else if (*id == *DATA_MEDIUM_FOOTER_RECORD_XDT_NAME) {

            //?? TODO

        } else if (*id == *DATA_PACKAGE_HEADER_RECORD_XDT_NAME) {

            // Decode package header (meta data 1).
            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) PACKAGE_HEADER_RECORD_XDT_MODEL_NAME, (void*) PACKAGE_HEADER_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_FOOTER_RECORD_XDT_NAME) {

            // Decode package footer (meta data 2).
            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) PACKAGE_FOOTER_RECORD_XDT_MODEL_NAME, (void*) PACKAGE_FOOTER_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) MEDICAL_TREATMENT_RECORD_XDT_MODEL_NAME, (void*) MEDICAL_TREATMENT_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *REFERRAL_CASE_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) REFERRAL_CASE_RECORD_XDT_MODEL_NAME, (void*) REFERRAL_CASE_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_MODEL_NAME, (void*) MEDICAL_TREATMENT_WITH_COTTAGE_HOSPITAL_AFFILIATION_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_MODEL_NAME, (void*) MEDICAL_EMERGENCY_SERVICE_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PRIVATE_BILLING_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) PRIVATE_BILLING_RECORD_XDT_MODEL_NAME, (void*) PRIVATE_BILLING_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_MODEL_NAME, (void*) EMPLOYERS_LIABILITY_INSURANCE_ASSOCIATION_BILLING_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *UNSTRUCTURED_CASES_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) UNSTRUCTURED_CASES_RECORD_XDT_MODEL_NAME, (void*) UNSTRUCTURED_CASES_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) PATIENT_MASTER_DATA_RECORD_XDT_MODEL_NAME, (void*) PATIENT_MASTER_DATA_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_DATA_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) MEDICAL_TREATMENT_DATA_RECORD_XDT_MODEL_NAME, (void*) MEDICAL_TREATMENT_DATA_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_MODEL_NAME, (void*) PATIENT_MASTER_DATA_REQUEST_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_MODEL_NAME, (void*) PATIENT_MASTER_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EXAMINATION_REQUEST_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) EXAMINATION_REQUEST_RECORD_XDT_MODEL_NAME, (void*) EXAMINATION_REQUEST_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EXAMINATION_DATA_TRANSFER_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) EXAMINATION_DATA_TRANSFER_RECORD_XDT_MODEL_NAME, (void*) EXAMINATION_DATA_TRANSFER_RECORD_XDT_MODEL_NAME_COUNT);

        } else if (*id == *EXAMINATION_DATA_DISPLAY_RECORD_XDT_NAME) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
                (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                (void*) EXAMINATION_DATA_DISPLAY_RECORD_XDT_MODEL_NAME, (void*) EXAMINATION_DATA_DISPLAY_RECORD_XDT_MODEL_NAME_COUNT);
        }

        // Process xdt record content.
        decode_xdt_process_record(m, mc, ms, p3, p4);

        // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
        if ((n != *NULL_POINTER_MEMORY_MODEL) && (nc != *NULL_POINTER_MEMORY_MODEL) && (ns != *NULL_POINTER_MEMORY_MODEL)
            && (a != *NULL_POINTER_MEMORY_MODEL) && (ac != *NULL_POINTER_MEMORY_MODEL) && (as != *NULL_POINTER_MEMORY_MODEL)) {

            // Add xdt record to xdt package.
            //
            // CAUTION! Hand over the name as reference, as it gets changed by adding
            // an index as name suffix, to uniquely identify the record within the compound.
            append_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            // Destroy all arrays, since they were not added to the compound.
            // CAUTION! If this was not done here, they would never be deallocated!
            // CAUTION! Use DESCENDING order, as opposed to array allocation!

            // Deallocate knowledge model details.
            deallocate((void*) &d, ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            deallocate((void*) &dc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

            // Deallocate knowledge model model.
            deallocate((void*) &m, ms, a, ac);
            deallocate((void*) &mc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

            // Deallocate knowledge model abstraction.
            deallocate((void*) &a, as, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &as, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

            // A knowledge model channel was not allocated.

            // Deallocate knowledge model name.
            deallocate((void*) &n, ns, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &nc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
            deallocate((void*) &ns, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not select xdt record. The record identification is null.");
    }
}

/**
 * Processes the xdt package.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the source package
 * @param p4 the source package count
 */
void decode_xdt_process_package(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void* s = (void*) p3;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Process xdt package.");

            // The remaining bytes in the source byte array.
            int rem = *sc;
            // The record size.
            int rs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The record identification.
            int rid = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The record content.
            void* rc = *NULL_POINTER_MEMORY_MODEL;
            int rcc = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                // Decode xdt record (size, identification, content).
                decode_xdt_record((void*) &rs, (void*) &rid, (void*) &rc, (void*) &rcc, (void*) &s, (void*) &rem);

/*??
                // Test values.
                fwprintf(stdout, L"\nTest: Process xdt package. Record size rs: %i\n", rs);
                fwprintf(stdout, L"Test: Process xdt package. Record identification id: %i\n", rid);
                fwprintf(stdout, L"Test: Process xdt package. Record content count pfc: %i\n", rcc);
*/

                if (rs > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Increment source xdt byte array index,
                    // so that following records may be found
                    // in the next loop cycle.
//??                    s = s + rs;
                    rem = rem - rs;

                    decode_xdt_select_record(p0, p1, p2, rc, (void*) &rcc, (void*) &rid);

                } else {

                    // If the xdt record size is zero or smaller, then
                    // increment the source xdt byte array index by one,
                    // in order to ensure that this loop will find an end.
                    s = s + *NUMBER_1_INTEGER_MEMORY_MODEL;
                    rem = rem - *NUMBER_1_INTEGER_MEMORY_MODEL;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xdt package. The source package is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not process xdt package. The source package count is null.");
    }
}

/**
 * Selects the xdt package.
 *
 * @param p0 the destination model
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the package content
 * @param p7 the package content count
 * @param p8 the package header
 * @param p9 the package header count
 * @param p10 the package footer
 * @param p11 the package footer count
 */
void decode_xdt_select_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select xdt package.");

    // The knowledge model name.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* nc = *NULL_POINTER_MEMORY_MODEL;
    void* ns = *NULL_POINTER_MEMORY_MODEL;
    // The knowledge model abstraction.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;
    // The knowledge model model.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* ms = *NULL_POINTER_MEMORY_MODEL;
    // The knowledge model details.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    void* ds = *NULL_POINTER_MEMORY_MODEL;

    // Decode package content.
    // CAUTION! Hand over a null pointer in place of the model and model count!
    // This is necessary because an EMPTY compound model is to be created.
    // The given model parameters do not represent the compound's xml file name
    // but a byte stream which gets processed further below.
    decode_xdt_decode_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
        (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
        (void*) STANDARD_PACKAGE_XDT_NAME, (void*) STANDARD_PACKAGE_XDT_NAME_COUNT);

    // Process xdt package content.
    decode_xdt_process_package(m, mc, ms, p6, p7);
    // Decode xdt package header (meta data 1).
    decode_xdt_select_record(d, dc, ds, p8, p9, (void*) DATA_PACKAGE_HEADER_RECORD_XDT_NAME);
    // Decode xdt package footer (meta data 2).
    decode_xdt_select_record(d, dc, ds, p10, p11, (void*) DATA_PACKAGE_FOOTER_RECORD_XDT_NAME);

    // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
    if ((n != *NULL_POINTER_MEMORY_MODEL) && (nc != *NULL_POINTER_MEMORY_MODEL) && (ns != *NULL_POINTER_MEMORY_MODEL)
        && (a != *NULL_POINTER_MEMORY_MODEL) && (ac != *NULL_POINTER_MEMORY_MODEL) && (as != *NULL_POINTER_MEMORY_MODEL)) {

        // Add xdt package to given destination compound model.
        //
        // CAUTION! Hand over the name as reference, as it gets changed by adding
        // an index as name suffix, to uniquely identify the record within the compound.
        append_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

    } else {

        // Destroy all arrays, since they were not added to the compound.
        // CAUTION! If this was not done here, they would never be deallocated!
        // CAUTION! Use DESCENDING order, as opposed to array allocation!

        // Deallocate knowledge model details.
        deallocate((void*) &d, ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
        deallocate((void*) &dc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        deallocate((void*) &ds, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

        // Deallocate knowledge model model.
        deallocate((void*) &m, ms, a, ac);
        deallocate((void*) &mc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        deallocate((void*) &ms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

        // Deallocate knowledge model abstraction.
        deallocate((void*) &a, as, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);
        deallocate((void*) &ac, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        deallocate((void*) &as, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);

        // A knowledge model channel was not allocated.

        // Deallocate knowledge model name.
        deallocate((void*) &n, ns, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);
        deallocate((void*) &nc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
        deallocate((void*) &ns, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT);
    }
}

/**
 * Decodes an xdt format byte array into a compound model.
 *
 * @param p0 the destination compound model (Hand over as reference!)
 * @param p1 the destination compound model count
 * @param p2 the destination compound model size
 * @param p3 the destination compound details (Hand over as reference!)
 * @param p4 the destination compound details count
 * @param p5 the destination compound details size
 * @param p6 the source xdt byte array
 * @param p7 the source xdt byte array count
 */
void decode_xdt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void* s = (void*) p6;

            if (p3 != *NULL_POINTER_MEMORY_MODEL) {

                void** dd = (void**) p3;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** dm = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode xdt format into compound model.");

                    // The remaining bytes in the source byte array.
                    int rem = *sc;
                    // The xdt package size.
                    int ps = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The xdt package content.
                    void* pc = *NULL_POINTER_MEMORY_MODEL;
                    int pcc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The xdt package header.
                    void* ph = *NULL_POINTER_MEMORY_MODEL;
                    int phc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    // The xdt package footer.
                    void* pf = *NULL_POINTER_MEMORY_MODEL;
                    int pfc = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
                    // Test values.
                    fwprintf(stdout, L"TEST xdt file source count: %i\n\n", *sc);
*/

                    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                        if (rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            break;
                        }

                        // CAUTION! The data package section pointer s
                        // has to be handed over as REFERENCE, because it
                        // gets manipulated in the called operations and
                        // these have to store their result in s.
                        // If temporary variables (function parameters) were used,
                        // their values would be lost when the called operation is left.
                        decode_xdt_package((void*) &ps, (void*) &ph, (void*) &phc, (void*) &pf, (void*) &pfc, (void*) &pc, (void*) &pcc, (void*) &s, (void*) &rem);

/*??
                        // Test values.
                        fwprintf(stdout, L"TEST package size: %i\n", ps);
                        fwprintf(stdout, L"TEST package header count: %i\n", phc);
                        fwprintf(stdout, L"TEST package footer count: %i\n", pfc);
                        fwprintf(stdout, L"TEST package content: %i\n", pcc);
*/

                        if (ps > *NUMBER_0_INTEGER_MEMORY_MODEL) {

                            // Decrement remaining bytes in the source byte array.
                            rem = rem - ps;

/*??
                            // Test values.
                            fwprintf(stdout, L"TEST package remaining bytes: %i\n\n", rem);
*/

                            // Select xdt package.
                            decode_xdt_select_package(*dm, p1, p2, *dd, p4, p5,
                                pc, (void*) &pcc, ph, (void*) &phc, pf, (void*) &pfc);

                        } else {

                            // If the xdt package size is zero or smaller, then
                            // increment the source xdt byte array index by one,
                            // in order to ensure that this loop will finally
                            // find an end.
                            s = s + *NUMBER_1_INTEGER_MEMORY_MODEL;
                            rem = rem - *NUMBER_1_INTEGER_MEMORY_MODEL;
                        }

                        // Reset xdt package size.
                        ps = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // Reset xdt package content.
                        pc = *NULL_POINTER_MEMORY_MODEL;
                        pcc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // Reset xdt package header.
                        ph = *NULL_POINTER_MEMORY_MODEL;
                        phc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // Reset xdt package footer.
                        pf = *NULL_POINTER_MEMORY_MODEL;
                        pfc = *NUMBER_0_INTEGER_MEMORY_MODEL;
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt. The destination compound model is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt. The destination compound details is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt. The source byte array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode xdt. The source byte array count is null.");
    }
}

/* XDT_DECODER_SOURCE */
#endif
