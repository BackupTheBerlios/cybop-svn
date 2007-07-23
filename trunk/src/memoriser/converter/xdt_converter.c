/*
 * $RCSfile: xdt_converter.c,v $
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
 * @version $Revision: 1.12 $ $Date: 2007-07-23 23:47:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_CONVERTER_SOURCE
#define XDT_CONVERTER_SOURCE

#include "../../globals/constants/xdt/xdt_field_constants.c"
#include "../../globals/constants/xdt/xdt_record_constants.c"
#include "../../globals/constants/xdt/xdt_field_name_constants.c"
#include "../../globals/constants/character/character_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_abstraction_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/converter/character_vector_converter.c"
#include "../../memoriser/converter/date_time_converter.c"
#include "../../memoriser/converter/integer_vector_converter.c"
#include "../../memoriser/array.c"

//
// Forward declarations.
//

/**
 * Parses the byte stream according to the given document type
 * and creates a document model from it.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count
 * @param p2 the destination model size
 * @param p3 the destination details (Hand over as reference!)
 * @param p4 the destination details count
 * @param p5 the destination details size
 * @param p6 the source
 * @param p7 the source count
 * @param p8 the type
 * @param p9 the type count
 */
void parse(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

/**
 * Parses an xdt field.
 *
 * @param p0 the destination field size (Hand over as reference!)
 * @param p1 the destination field identification (Hand over as reference!)
 * @param p2 the destination field content (Hand over as reference!)
 * @param p3 the destination field content count (Hand over as reference!)
 * @param p4 the destination verification flag
 * @param p5 the source byte array (Hand over as reference!)
 * @param p6 the source byte array count
 */
void parse_xdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER) {

        int* sc = (int*) p6;

        if (p5 != *NULL_POINTER) {

            void** s = (void**) p5;

            if (p4 != *NULL_POINTER) {

                int* v = (int*) p4;

                if (p3 != *NULL_POINTER) {

                    int* fcc = (int*) p3;

                    if (p2 != *NULL_POINTER) {

                        void** fc = (void**) p2;

                        if (p0 != *NULL_POINTER) {

                            int* fs = (int*) p0;

                            log_message_debug("Information: Parse xdt field.");

                            // The remaining bytes in the source byte array.
                            // They are used to check that the array border is not crossed.
                            int rem = *sc;

                            if (rem >= *XDT_FIELD_SIZE_COUNT) {

                                // Parse xdt field size.
                                parse_integer(p0, *NULL_POINTER, *NULL_POINTER, *s, (void*) XDT_FIELD_SIZE_COUNT);

                                // Increment source xdt byte array index.
                                *s = *s + *XDT_FIELD_SIZE_COUNT;
                                rem = rem - *XDT_FIELD_SIZE_COUNT;
                            }

                            if (rem >= *XDT_FIELD_IDENTIFICATION_COUNT) {

                                // Parse xdt field identification.
                                parse_integer(p1, *NULL_POINTER, *NULL_POINTER, *s, (void*) XDT_FIELD_IDENTIFICATION_COUNT);

                                // Increment source xdt byte array index.
                                *s = *s + *XDT_FIELD_IDENTIFICATION_COUNT;
                                rem = rem - *XDT_FIELD_IDENTIFICATION_COUNT;
                            }

                            if (*fs >= (*XDT_FIELD_SIZE_COUNT + *XDT_FIELD_IDENTIFICATION_COUNT + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT)) {

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
                                *fcc = *fs - *XDT_FIELD_SIZE_COUNT - *XDT_FIELD_IDENTIFICATION_COUNT - *PRIMITIVE_COUNT - *PRIMITIVE_COUNT;

                                if (rem >= *fcc) {

                                    // Store xdt field content, to be returned.
                                    *fc = *s;

                                    // Increment source xdt byte array index.
                                    *s = *s + *fcc;
                                    rem = rem - *fcc;
                                }

                            } else {

                                // Store xdt field content, to be returned.
                                *fc = *NULL_POINTER;
                                *fcc = *NUMBER_0_INTEGER;
                            }

                            if (rem >= (*PRIMITIVE_COUNT + *PRIMITIVE_COUNT)) {

                                // Verify if field end is reached (carriage return and line feed).

                                if (*((char*) *s) == *CARRIAGE_RETURN_CONTROL_CHARACTER) {

                                    // Increment source xdt byte array index.
                                    *s = *s + *PRIMITIVE_COUNT;

                                    if (*((char*) *s) == *LINE_FEED_CONTROL_CHARACTER) {

                                        // Increment source xdt byte array index.
                                        *s = *s + *PRIMITIVE_COUNT;

                                        // Set verification flag indicating that
                                        // the xdt field was parsed correctly.
                                        *v = *NUMBER_1_INTEGER;
                                    }
                                }
                            }

                        } else {

                            log_message_debug("Error: Could not parse xdt field. The field size is null.");
                        }

                    } else {

                        log_message_debug("Error: Could not parse xdt field. The field content is null.");
                    }

                } else {

                    log_message_debug("Error: Could not parse xdt field. The field content count is null.");
                }

            } else {

                log_message_debug("Error: Could not parse xdt field. The verification flag is null.");
            }

        } else {

            log_message_debug("Error: Could not parse xdt field. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse xdt field. The source count is null.");
    }
}

/**
 * Parses for the next xdt field.
 *
 * @param p0 the next field count = number of bytes to the next field (Hand over as reference!)
 * @param p1 the byte array
 * @param p2 the byte array count
 */
void parse_xdt_next_field(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER) {

        int* ac = (int*) p2;

        if (p1 != *NULL_POINTER) {

            char* a = (char*) p1;

            if (p0 != *NULL_POINTER) {

                int* nc = (int*) p0;

                log_message_debug("Information: Parse for next xdt field.");

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

                        if (*(a + j) == *CARRIAGE_RETURN_CONTROL_CHARACTER) {

                            if (*(a + j + *PRIMITIVE_COUNT) == *LINE_FEED_CONTROL_CHARACTER) {

                                // Set next field count to the first character following
                                // the carriage return plus line feed characters.
                                *nc = j + *PRIMITIVE_COUNT + *PRIMITIVE_COUNT;

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

                log_message_debug("Error: Could not parse for next xdt field. The next field count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse for next xdt field. The byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse for next xdt field. The byte array count is null.");
    }
}

/**
 * Parses an xdt record.
 *
 * @param p0 the record size (Hand over as reference!)
 * @param p1 the record identification (Hand over as reference!)
 * @param p2 the record content (Hand over as reference!)
 * @param p3 the record content count (Hand over as reference!)
 * @param p4 the source byte array (Hand over as reference!)
 * @param p5 the source byte array count
 */
void parse_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER) {

        int* sc = (int*) p5;

        if (p4 != *NULL_POINTER) {

            void** s = (void**) p4;

            if (p3 != *NULL_POINTER) {

                int* rcc = (int*) p3;

                if (p2 != *NULL_POINTER) {

                    void** rc = (void**) p2;

                    if (p0 != *NULL_POINTER) {

                        int* rs = (int*) p0;

                        log_message_debug("Information: Parse xdt record.");

                        // Reset record size.
                        *rs = *NUMBER_0_INTEGER;
                        // The remaining bytes in the source byte array.
                        // They are used to check that the array border is not crossed.
                        int rem = *sc;
                        // The field size.
                        int fs = *NUMBER_0_INTEGER;
                        // The field identification.
                        int fid = *NUMBER_0_INTEGER;
                        // The field content.
                        void* fc = *NULL_POINTER;
                        int fcc = *NUMBER_0_INTEGER;
                        // The verification flag.
                        int v = *NUMBER_0_INTEGER;
                        // The next field count.
                        int nc = *NUMBER_0_INTEGER;
                        // The parse mode:
                        // 0 - looking for the begin of a record
                        // 1 - within a record, looking for the begin of the next
                        //     record, which demarcates the end of this record
                        int m = *NUMBER_0_INTEGER;

                        while (*NUMBER_1_INTEGER) {

                            if (rem <= *NUMBER_0_INTEGER) {

                                break;
                            }

                            // Parse xdt field (size, identification, content).
                            parse_xdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, p4, (void*) &rem);

/*??
                            // Test values.
                            fprintf(stderr, "Test: Parse xdt record. Field size fs: %i\n", fs);
                            fprintf(stderr, "Test: Parse xdt record. Field identification id: %i\n", fid);
                            fprintf(stderr, "Test: Parse xdt record. Field content count fcc: %i\n", fcc);
*/

                            if (v == *NUMBER_1_INTEGER) {

                                // The verification flag is set, which means that
                                // the xdt field was parsed correctly and the carriage
                                // return plus line feed characters were reached.

                                // Decrement remaining bytes in the source byte array.
                                rem = rem - fs;

                                // Increment record size.
                                *rs = *rs + fs;
                                // Increment record content count.
                                *rcc = *rcc + fs;

                                if (fid == *RECORD_IDENTIFICATION_XDT_FIELD) {

                                    if (m == *NUMBER_0_INTEGER) {

                                        // Set parse mode to "1".
                                        // This is the begin of a record.
                                        m = *NUMBER_1_INTEGER;

                                        // Parse xdt record identification.
                                        parse_integer(p1, *NULL_POINTER, *NULL_POINTER, fc, (void*) &fcc);

                                    } else {

                                        // The current parse mode is "1", which means that
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
                                        rem = *NUMBER_0_INTEGER;
                                    }

                                } else if (fid == *RECORD_SIZE_XDT_FIELD) {

                                    // Parse xdt record size.
                                    //
                                    // CAUTION! Do NOT use the following line:
                                    // parse_integer(p0, *NULL_POINTER, *NULL_POINTER, fc, (void*) &fcc);
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
                                    *rcc = *NUMBER_0_INTEGER;
                                }

                            } else {

                                // The verification flag is NOT set, which means
                                // that the xdt field was NOT parsed correctly.

                                log_message_debug("Error: Could not parse xdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                                // Reset next field count.
                                nc = *NUMBER_0_INTEGER;

                                // Count the number of bytes to the next carriage return-
                                // plus line feed character.
                                parse_xdt_next_field((void*) &nc, *s, (void*) &rem);

                                // Increment source xdt byte array index, so that following
                                // fields may be found in the next loop cycle.
                                *s = *s + nc;
                                rem = rem - nc;

                                // Increment record size.
                                *rs = *rs + *NUMBER_1_INTEGER;

                                // Increment record content count.
                                *rcc = *rcc + *NUMBER_1_INTEGER;
                            }
                        }

                    } else {

                        log_message_debug("Error: Could not parse xdt record. The record size is null.");
                    }

                } else {

                    log_message_debug("Error: Could not parse xdt record. The record content is null.");
                }

            } else {

                log_message_debug("Error: Could not parse xdt record. The record content count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse xdt record. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse xdt record. The source byte array count is null.");
    }
}

/**
 * Parses an xdt package.
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
void parse_xdt_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER) {

        int* sc = (int*) p8;

        if (p7 != *NULL_POINTER) {

            void** s = (void**) p7;

            if (p6 != *NULL_POINTER) {

                int* pcc = (int*) p6;

                if (p5 != *NULL_POINTER) {

                    void** pc = (void**) p5;

                    if (p4 != *NULL_POINTER) {

                        int* pfc = (int*) p4;

                        if (p3 != *NULL_POINTER) {

                            void** pf = (void**) p3;

                            if (p2 != *NULL_POINTER) {

                                int* phc = (int*) p2;

                                if (p1 != *NULL_POINTER) {

                                    void** ph = (void**) p1;

                                    if (p0 != *NULL_POINTER) {

                                        int* ps = (int*) p0;

                                        log_message_debug("Information: Parse xdt package.");

                                        // Reset package size.
                                        *ps = *NUMBER_0_INTEGER;
                                        // The remaining bytes in the source byte array.
                                        // They are used to check that the array border
                                        // is not crossed, and to leave the loop.
                                        int rem = *sc;
                                        // The record size.
                                        int rs = *NUMBER_0_INTEGER;
                                        // The record identification.
                                        int rid = *NUMBER_0_INTEGER;
                                        // The loop variable.
                                        int j = *NUMBER_0_INTEGER;

                                        while (*NUMBER_1_INTEGER) {

                                            if (rem <= *NUMBER_0_INTEGER) {

                                                break;
                                            }

                                            // Parse xdt record (size, identification, content).
                                            //
                                            // CAUTION! The package header and -footer count are
                                            // handed over as parameters to get the record content.
                                            // A local variable defined in this function may NOT
                                            // be used as its value is lost when returning from
                                            // this function. But a valid value has to be
                                            // returned to the calling function.
                                            parse_xdt_record((void*) &rs, (void*) &rid, p3, p4, p7, (void*) &rem);

/*??
                                            // Test values.
                                            fprintf(stderr, "Test: Parse xdt package. Record size rs: %i\n", rs);
                                            fprintf(stderr, "Test: Parse xdt package. Record identification id: %i\n", rid);
                                            fprintf(stderr, "Test: Parse xdt package. Record content count pfc: %i\n\n", *pfc);
*/

                                            if (rs > *NUMBER_0_INTEGER) {

                                                // Decrement remaining bytes in the source byte array.
                                                rem = rem - rs;

                                                // Increment package size.
                                                *ps = *ps + rs;

                                                // Increment loop variable.
                                                j = j + rs;

                                                if (rid == *DATA_PACKAGE_HEADER_XDT_RECORD) {

                                                    // Store xdt package header.
                                                    //
                                                    // CAUTION! This is only the record content
                                                    // WITHOUT the record size and -identification!
                                                    *ph = *pf;
                                                    *phc = *pfc;

/*??
                                                    // Test values.
                                                    fprintf(stderr, "Test: Parse xdt package. Package header: %i\n", *ph);
                                                    fprintf(stderr, "Test: Parse xdt package. Package header count: %i\n\n", *phc);
*/

                                                    // Store xdt package content.
                                                    //
                                                    // CAUTION! Everything following this package
                                                    // header record up to the package footer
                                                    // record belongs to the package's content.
                                                    *pc = *s;

                                                    // Reset loop variable.
                                                    j = *NUMBER_0_INTEGER;

                                                } else if (rid == *DATA_PACKAGE_FOOTER_XDT_RECORD) {

                                                    // CAUTION! The package footer does NOT
                                                    // have to be stored here explicitly.
                                                    // It was already handed over as parameter
                                                    // to the "parse_xdt_record" function,
                                                    // so that its value is already set.

/*??
                                                    // Test values.
                                                    fprintf(stderr, "Test: Parse xdt package. Package footer: %i\n", *pf);
                                                    fprintf(stderr, "Test: Parse xdt package. Package footer count: %i\n\n", *pfc);
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
                                                    rem = *NUMBER_0_INTEGER;
                                                }

                                            } else {

                                                // If the xdt record size is zero or smaller, then
                                                // increment the source xdt byte array index by one,
                                                // in order to ensure that this loop will finally
                                                // find an end.
                                                *s = *s + *NUMBER_1_INTEGER;
                                                rem = rem - *NUMBER_1_INTEGER;

                                                // Increment package size.
                                                *ps = *ps + *NUMBER_1_INTEGER;

                                                // Increment loop variable.
                                                j = j + *NUMBER_1_INTEGER;
                                            }
                                        }

                                    } else {

                                        log_message_debug("Error: Could not parse xdt package. The package size is null.");
                                    }

                                } else {

                                    log_message_debug("Error: Could not parse xdt package. The package header is null.");
                                }

                            } else {

                                log_message_debug("Error: Could not parse xdt package. The package header count is null.");
                            }

                        } else {

                            log_message_debug("Error: Could not parse xdt package. The package footer is null.");
                        }

                    } else {

                        log_message_debug("Error: Could not parse xdt package. The package footer count is null.");
                    }

                } else {

                    log_message_debug("Error: Could not parse xdt package. The package content is null.");
                }

            } else {

                log_message_debug("Error: Could not parse xdt package. The package content count is null.");
            }

        } else {

            log_message_debug("Error: Could not parse xdt package. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse xdt package. The source byte array count is null.");
    }
}

/**
 * Parses the model.
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
void parse_xdt_parse_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11,
    void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    if (p11 != *NULL_POINTER) {

        int** ds = (int**) p11;

        if (p10 != *NULL_POINTER) {

            int** dc = (int**) p10;

            if (p8 != *NULL_POINTER) {

                int** ms = (int**) p8;

                if (p7 != *NULL_POINTER) {

                    int** mc = (int**) p7;

                    if (p5 != *NULL_POINTER) {

                        int** as = (int**) p5;

                        if (p4 != *NULL_POINTER) {

                            int** ac = (int**) p4;

                            if (p2 != *NULL_POINTER) {

                                int** ns = (int**) p2;

                                if (p1 != *NULL_POINTER) {

                                    int** nc = (int**) p1;

                                    log_message_debug("Information: Parse model.");

                                    // Allocate knowledge model name.
                                    allocate(p1, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **nc = *NUMBER_0_INTEGER;
                                    allocate(p2, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **ns = *NUMBER_0_INTEGER;
                                    allocate(p0, (void*) *ns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                                    // A knowledge model channel is not received (allocated),
                                    // since that is only needed temporarily for model loading.

                                    // Allocate knowledge model abstraction.
                                    allocate(p4, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **ac = *NUMBER_0_INTEGER;
                                    allocate(p5, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **as = *NUMBER_0_INTEGER;
                                    allocate(p3, (void*) *as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

                                    // Allocate knowledge model model.
                                    allocate(p7, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **mc = *NUMBER_0_INTEGER;
                                    allocate(p8, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **ms = *NUMBER_0_INTEGER;
                                    allocate(p6, (void*) *ms, p14, p15);

                                    // Allocate knowledge model details.
                                    allocate(p10, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **dc = *NUMBER_0_INTEGER;
                                    allocate(p11, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                                    **ds = *NUMBER_0_INTEGER;
                                    allocate(p9, (void*) *ds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);

                                    // Parse name.
                                    parse_character_vector(p0, (void*) *nc, (void*) *ns, p16, p17);
                                    // Parse abstraction.
                                    parse_character_vector(p3, (void*) *ac, (void*) *as, p14, p15);
                                    // Parse model.
                                    parse(p6, (void*) *mc, (void*) *ms, p9, (void*) *dc, (void*) *ds, p12, p13, p14, p15);

                                } else {

                                    log_message_debug("Error: Could not parse model. The name count is null.");
                                }

                            } else {

                                log_message_debug("Error: Could not parse model. The name size is null.");
                            }

                        } else {

                            log_message_debug("Error: Could not parse model. The abstraction count is null.");
                        }

                    } else {

                        log_message_debug("Error: Could not parse model. The abstraction size is null.");
                    }

                } else {

                    log_message_debug("Error: Could not parse model. The model count is null.");
                }

            } else {

                log_message_debug("Error: Could not parse model. The model size is null.");
            }

        } else {

            log_message_debug("Error: Could not parse model. The details count is null.");
        }

    } else {

        log_message_debug("Error: Could not parse model. The details size is null.");
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
void parse_xdt_select_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER) {

        int* id = (int*) p5;

        log_message_debug("Information: Select xdt field.");

/*??
        // Test values.
        fprintf(stderr, "Test: Select xdt field. Field identification: %i\n", *id);
*/

        // The knowledge model name.
        void* n = *NULL_POINTER;
        void* nc = *NULL_POINTER;
        void* ns = *NULL_POINTER;
        // The knowledge model abstraction.
        void* a = *NULL_POINTER;
        void* ac = *NULL_POINTER;
        void* as = *NULL_POINTER;
        // The knowledge model model.
        void* m = *NULL_POINTER;
        void* mc = *NULL_POINTER;
        void* ms = *NULL_POINTER;
        // The knowledge model details.
        void* d = *NULL_POINTER;
        void* dc = *NULL_POINTER;
        void* ds = *NULL_POINTER;

        if (*id == *RECORD_SIZE_XDT_FIELD) {

            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT,
                (void*) RECORD_SIZE_XDT_FIELD_NAME, (void*) RECORD_SIZE_XDT_FIELD_NAME_COUNT);

        } else if (*id == *ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD) {

            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME, (void*) ADT_RECORD_SPECIFICATION_VERSION_XDT_FIELD_NAME_COUNT);

        } else if (*id == *PATIENT_IDENTIFICATION_XDT_FIELD) {

            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                (void*) PATIENT_IDENTIFICATION_XDT_FIELD_NAME, (void*) PATIENT_IDENTIFICATION_XDT_FIELD_NAME_COUNT);

        } else if (*id == *PATIENT_FIRST_NAME_XDT_FIELD) {

            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                p3, p4,
                (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT,
                (void*) PATIENT_FIRST_NAME_XDT_FIELD_NAME, (void*) PATIENT_FIRST_NAME_XDT_FIELD_NAME_COUNT);
        }

        // No further processing of the xdt field content is necessary!
        // The field represents the final logical model in the xdt format
        // and does not contain any further parts.
        // Its content is therefore parsed directly.

        // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
        if ((n != *NULL_POINTER) && (nc != *NULL_POINTER) && (ns != *NULL_POINTER)
            && (a != *NULL_POINTER) && (ac != *NULL_POINTER) && (as != *NULL_POINTER)) {

            // Add xdt field to xdt record.
            set_compound_element_by_name(p0, p1, p2, n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            // Destroy all arrays, since they were not added to the compound.
            // CAUTION! If this was not done here, they would never be deallocated!
            // CAUTION! Use DESCENDING order, as opposed to array allocation!

            // Deallocate knowledge model details.
            deallocate((void*) &d, ds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
            deallocate((void*) &dc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // Deallocate knowledge model model.
            deallocate((void*) &m, ms, a, ac);
            deallocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // Deallocate knowledge model abstraction.
            deallocate((void*) &a, as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // A knowledge model channel was not allocated.

            // Deallocate knowledge model name.
            deallocate((void*) &n, ns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &nc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        }

    } else {

        log_message_debug("Error: Could not select xdt field. The field identification is null.");
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
void parse_xdt_process_record(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void* s = (void*) p3;

            log_message_debug("Information: Process xdt record.");

            // The remaining bytes in the source byte array.
            int rem = *sc;
            // The field size.
            int fs = *NUMBER_0_INTEGER;
            // The field identification.
            int fid = *NUMBER_0_INTEGER;
            // The field content.
            void* fc = *NULL_POINTER;
            int fcc = *NUMBER_0_INTEGER;
            // The verification flag.
            int v = *NUMBER_0_INTEGER;
            // The next field count.
            int nc = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                if (rem <= *NUMBER_0_INTEGER) {

                    break;
                }

                // Parse xdt field (size, identification, content).
                parse_xdt_field((void*) &fs, (void*) &fid, (void*) &fc, (void*) &fcc, (void*) &v, (void*) &s, (void*) &rem);

/*??
                // Test values.
                fprintf(stderr, "Test: Process xdt record. Field size fs: %i\n", fs);
                fprintf(stderr, "Test: Process xdt record. Field identification id: %i\n", fid);
                fprintf(stderr, "Test: Process xdt record. Field content count fcc: %i\n", fcc);
*/

                if (v == *NUMBER_1_INTEGER) {

                    // The verification flag is set, which means that
                    // the xdt field was parsed correctly and the carriage
                    // return plus line feed characters were reached.

                    // Increment source xdt byte array index,
                    // so that following fields may be found
                    // in the next loop cycle.
//??                    s = s + fs;
                    rem = rem - fs;

                    parse_xdt_select_field(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);

                } else {

                    // The verification flag is NOT set, which means
                    // that the xdt field was NOT parsed correctly.

                    log_message_debug("Error: Could not process xdt record. An invalid field was detected. The parsing will now continue with the next valid field.");

                    // Reset next field count.
                    nc = *NUMBER_0_INTEGER;

                    // Count the number of bytes to the next carriage return-
                    // plus line feed character.
                    parse_xdt_next_field((void*) &nc, s, (void*) &rem);

                    // Increment source xdt byte array index, so that following
                    // fields may be found in the next loop cycle.
                    s = s + nc;
                    rem = rem - nc;
                }
            }

        } else {

            log_message_debug("Error: Could not process xdt record. The source record is null.");
        }

    } else {

        log_message_debug("Error: Could not process xdt record. The source record count is null.");
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
void parse_xdt_select_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER) {

        int* id = (int*) p5;

        log_message_debug("Information: Select xdt record.");

/*??
        // Test values.
        fprintf(stderr, "Test: Select xdt record. Record identification: %i\n", *id);
*/

        // The knowledge model name.
        void* n = *NULL_POINTER;
        void* nc = *NULL_POINTER;
        void* ns = *NULL_POINTER;
        // The knowledge model abstraction.
        void* a = *NULL_POINTER;
        void* ac = *NULL_POINTER;
        void* as = *NULL_POINTER;
        // The knowledge model model.
        void* m = *NULL_POINTER;
        void* mc = *NULL_POINTER;
        void* ms = *NULL_POINTER;
        // The knowledge model details.
        void* d = *NULL_POINTER;
        void* dc = *NULL_POINTER;
        void* ds = *NULL_POINTER;

        if (*id == *DATA_PACKAGE_HEADER_XDT_RECORD) {

            // Parse package header (meta data 1).
            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER, *NULL_POINTER,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) PACKAGE_HEADER_XDT_RECORD_NAME, (void*) PACKAGE_HEADER_XDT_RECORD_NAME_COUNT);

        } else if (*id == *DATA_PACKAGE_FOOTER_XDT_RECORD) {

            // Parse package footer (meta data 2).
            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER, *NULL_POINTER,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) PACKAGE_FOOTER_XDT_RECORD_NAME, (void*) PACKAGE_FOOTER_XDT_RECORD_NAME_COUNT);

        } else if (*id == *MEDICAL_PRACTICE_DATA_XDT_RECORD) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER, *NULL_POINTER,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME, (void*) MEDICAL_PRACTICE_DATA_XDT_RECORD_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_XDT_RECORD) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER, *NULL_POINTER,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) MEDICAL_TREATMENT_XDT_RECORD_NAME, (void*) MEDICAL_TREATMENT_XDT_RECORD_NAME_COUNT);

        } else if (*id == *PATIENT_MASTER_DATA_XDT_RECORD) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER, *NULL_POINTER,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) PATIENT_MASTER_DATA_XDT_RECORD_NAME, (void*) PATIENT_MASTER_DATA_XDT_RECORD_NAME_COUNT);

        } else if (*id == *MEDICAL_TREATMENT_DATA_XDT_RECORD) {

            // CAUTION! Hand over a null pointer in place of the model and model count!
            // This is necessary because an EMPTY compound model is to be created.
            // The given model parameters do not represent the compound's xml file name
            // but a byte stream which gets processed further below.
            parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
                *NULL_POINTER, *NULL_POINTER,
                (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
                (void*) MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME, (void*) MEDICAL_TREATMENT_DATA_XDT_RECORD_NAME_COUNT);
        }

        // Process xdt record content.
        parse_xdt_process_record(m, mc, ms, p3, p4);

        // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
        if ((n != *NULL_POINTER) && (nc != *NULL_POINTER) && (ns != *NULL_POINTER)
            && (a != *NULL_POINTER) && (ac != *NULL_POINTER) && (as != *NULL_POINTER)) {

            // Add xdt record to xdt package.
            //
            // CAUTION! Hand over the name as reference, as it gets changed by adding
            // an index as name suffix, to uniquely identify the record within the compound.
            add_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

        } else {

            // Destroy all arrays, since they were not added to the compound.
            // CAUTION! If this was not done here, they would never be deallocated!
            // CAUTION! Use DESCENDING order, as opposed to array allocation!

            // Deallocate knowledge model details.
            deallocate((void*) &d, ds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
            deallocate((void*) &dc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // Deallocate knowledge model model.
            deallocate((void*) &m, ms, a, ac);
            deallocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // Deallocate knowledge model abstraction.
            deallocate((void*) &a, as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

            // A knowledge model channel was not allocated.

            // Deallocate knowledge model name.
            deallocate((void*) &n, ns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &nc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
            deallocate((void*) &ns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        }

    } else {

        log_message_debug("Error: Could not select xdt record. The record identification is null.");
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
void parse_xdt_process_package(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void* s = (void*) p3;

            log_message_debug("Information: Process xdt package.");

            // The remaining bytes in the source byte array.
            int rem = *sc;
            // The record size.
            int rs = *NUMBER_0_INTEGER;
            // The record identification.
            int rid = *NUMBER_0_INTEGER;
            // The record content.
            void* rc = *NULL_POINTER;
            int rcc = *NUMBER_0_INTEGER;

            while (*NUMBER_1_INTEGER) {

                if (rem <= *NUMBER_0_INTEGER) {

                    break;
                }

                // Parse xdt record (size, identification, content).
                parse_xdt_record((void*) &rs, (void*) &rid, (void*) &rc, (void*) &rcc, (void*) &s, (void*) &rem);

/*??
                // Test values.
                fprintf(stderr, "\nTest: Process xdt package. Record size rs: %i\n", rs);
                fprintf(stderr, "Test: Process xdt package. Record identification id: %i\n", rid);
                fprintf(stderr, "Test: Process xdt package. Record content count pfc: %i\n", rcc);
*/

                if (rs > *NUMBER_0_INTEGER) {

                    // Increment source xdt byte array index,
                    // so that following records may be found
                    // in the next loop cycle.
//??                    s = s + rs;
                    rem = rem - rs;

                    parse_xdt_select_record(p0, p1, p2, rc, (void*) &rcc, (void*) &rid);

                } else {

                    // If the xdt record size is zero or smaller, then
                    // increment the source xdt byte array index by one,
                    // in order to ensure that this loop will find an end.
                    s = s + *NUMBER_1_INTEGER;
                    rem = rem - *NUMBER_1_INTEGER;
                }
            }

        } else {

            log_message_debug("Error: Could not process xdt package. The source package is null.");
        }

    } else {

        log_message_debug("Error: Could not process xdt package. The source package count is null.");
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
void parse_xdt_select_package(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("Information: Select xdt package.");

    // The knowledge model name.
    void* n = *NULL_POINTER;
    void* nc = *NULL_POINTER;
    void* ns = *NULL_POINTER;
    // The knowledge model abstraction.
    void* a = *NULL_POINTER;
    void* ac = *NULL_POINTER;
    void* as = *NULL_POINTER;
    // The knowledge model model.
    void* m = *NULL_POINTER;
    void* mc = *NULL_POINTER;
    void* ms = *NULL_POINTER;
    // The knowledge model details.
    void* d = *NULL_POINTER;
    void* dc = *NULL_POINTER;
    void* ds = *NULL_POINTER;

    // Parse package content.
    // CAUTION! Hand over a null pointer in place of the model and model count!
    // This is necessary because an EMPTY compound model is to be created.
    // The given model parameters do not represent the compound's xml file name
    // but a byte stream which gets processed further below.
    parse_xdt_parse_model((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
        (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
        *NULL_POINTER, *NULL_POINTER,
        (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT,
        (void*) STANDARD_XDT_PACKAGE_NAME, (void*) STANDARD_XDT_PACKAGE_NAME_COUNT);

    // Process xdt package content.
    parse_xdt_process_package(m, mc, ms, p6, p7);
    // Parse xdt package header (meta data 1).
    parse_xdt_select_record(d, dc, ds, p8, p9, (void*) DATA_PACKAGE_HEADER_XDT_RECORD);
    // Parse xdt package footer (meta data 2).
    parse_xdt_select_record(d, dc, ds, p10, p11, (void*) DATA_PACKAGE_FOOTER_XDT_RECORD);

    // CAUTION! This check for null pointers is necessary to avoid segmentation faults!
    if ((n != *NULL_POINTER) && (nc != *NULL_POINTER) && (ns != *NULL_POINTER)
        && (a != *NULL_POINTER) && (ac != *NULL_POINTER) && (as != *NULL_POINTER)) {

        // Add xdt package to given destination compound model.
        //
        // CAUTION! Hand over the name as reference, as it gets changed by adding
        // an index as name suffix, to uniquely identify the record within the compound.
        add_compound_element_by_name(p0, p1, p2, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);

    } else {

        // Destroy all arrays, since they were not added to the compound.
        // CAUTION! If this was not done here, they would never be deallocated!
        // CAUTION! Use DESCENDING order, as opposed to array allocation!

        // Deallocate knowledge model details.
        deallocate((void*) &d, ds, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT);
        deallocate((void*) &dc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) &ds, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Deallocate knowledge model model.
        deallocate((void*) &m, ms, a, ac);
        deallocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // Deallocate knowledge model abstraction.
        deallocate((void*) &a, as, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) &ac, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) &as, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

        // A knowledge model channel was not allocated.

        // Deallocate knowledge model name.
        deallocate((void*) &n, ns, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) &nc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
        deallocate((void*) &ns, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    }
}

/**
 * Parses an xdt format byte array into a compound model.
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
 * @param p6 the source xdt byte array
 * @param p7 the source xdt byte array count
 */
void parse_xdt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER) {

        int* sc = (int*) p7;

        if (p6 != *NULL_POINTER) {

            void* s = (void*) p6;

            if (p3 != *NULL_POINTER) {

                void** dd = (void**) p3;

                if (p0 != *NULL_POINTER) {

                    void** dm = (void**) p0;

                    log_message_debug("Information: Parse xdt format into compound model.");

                    // The remaining bytes in the source byte array.
                    int rem = *sc;
                    // The xdt package size.
                    int ps = *NUMBER_0_INTEGER;
                    // The xdt package content.
                    void* pc = *NULL_POINTER;
                    int pcc = *NUMBER_0_INTEGER;
                    // The xdt package header.
                    void* ph = *NULL_POINTER;
                    int phc = *NUMBER_0_INTEGER;
                    // The xdt package footer.
                    void* pf = *NULL_POINTER;
                    int pfc = *NUMBER_0_INTEGER;

/*??
                    // Test values.
                    fprintf(stderr, "TEST xdt file source count: %i\n\n", *sc);
*/

                    while (*NUMBER_1_INTEGER) {

                        if (rem <= *NUMBER_0_INTEGER) {

                            break;
                        }

                        // CAUTION! The data package section pointer s
                        // has to be handed over as REFERENCE, because it
                        // gets manipulated in the called operations and
                        // these have to store their result in s.
                        // If temporary variables (function parameters) were used,
                        // their values would be lost when the called operation is left.
                        parse_xdt_package((void*) &ps, (void*) &ph, (void*) &phc, (void*) &pf, (void*) &pfc, (void*) &pc, (void*) &pcc, (void*) &s, (void*) &rem);

/*??
                        // Test values.
                        fprintf(stderr, "TEST package size: %i\n", ps);
                        fprintf(stderr, "TEST package header count: %i\n", phc);
                        fprintf(stderr, "TEST package footer count: %i\n", pfc);
                        fprintf(stderr, "TEST package content: %i\n", pcc);
*/

                        if (ps > *NUMBER_0_INTEGER) {

                            // Decrement remaining bytes in the source byte array.
                            rem = rem - ps;

/*??
                            // Test values.
                            fprintf(stderr, "TEST package remaining bytes: %i\n\n", rem);
*/

                            // Select xdt package.
                            parse_xdt_select_package(*dm, p1, p2, *dd, p4, p5,
                                pc, (void*) &pcc, ph, (void*) &phc, pf, (void*) &pfc);

                        } else {

                            // If the xdt package size is zero or smaller, then
                            // increment the source xdt byte array index by one,
                            // in order to ensure that this loop will finally
                            // find an end.
                            s = s + *NUMBER_1_INTEGER;
                            rem = rem - *NUMBER_1_INTEGER;
                        }

                        // Reset xdt package size.
                        ps = *NUMBER_0_INTEGER;
                        // Reset xdt package content.
                        pc = *NULL_POINTER;
                        pcc = *NUMBER_0_INTEGER;
                        // Reset xdt package header.
                        ph = *NULL_POINTER;
                        phc = *NUMBER_0_INTEGER;
                        // Reset xdt package footer.
                        pf = *NULL_POINTER;
                        pfc = *NUMBER_0_INTEGER;
                    }

                } else {

                    log_message_debug("Error: Could not parse xdt. The destination compound model is null.");
                }

            } else {

                log_message_debug("Error: Could not parse xdt. The destination compound details is null.");
            }

        } else {

            log_message_debug("Error: Could not parse xdt. The source byte array is null.");
        }

    } else {

        log_message_debug("Error: Could not parse xdt. The source byte array count is null.");
    }
}

/**
 * Serialises a compound model into an xdt format byte array.
 *
 * @param p0 the destination xdt byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void serialise_xdt(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_debug("Information: Serialise compound model into xdt format.");
}

/* XDT_CONVERTER_SOURCE */
#endif
