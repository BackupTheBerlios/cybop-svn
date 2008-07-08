/*
 * $RCSfile: date_time_converter.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.11 $ $Date: 2008-07-08 07:11:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATE_TIME_CONVERTER_SOURCE
#define DATE_TIME_CONVERTER_SOURCE

#include "../../globals/constants/character/code/character_code_constants.c"
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../globals/variables/reallocation_factor_variables.c"
#include "../../memoriser/allocator.c"

/**
 * Decodes the byte stream and creates a date time model from it.
 *
 * ISO time format:
 * YYYY-MM-DDThh:mm:ss
 * [YYYY]-[MM]-[DD]T[hh]:[mm]:[ss][hh]:[mm]
 *
 * Examples:
 * 2008-12-29
 * 13:47:30
 * 2008-12-29T13:47:30
 * 1981-04-05T14:30:30-05:00
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_date_time(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER) {

            void* s = (void*) p3;

            if (p0 != *NULL_POINTER) {

                void** d = (void**) p0;

                log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode date time.");

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode date time. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode date time. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode date time. The source count is null.");
    }
}

/**
 * Encodes the date time model and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_date_time(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/**
 * Decodes the ddmmyyyy byte stream and creates a date time model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void decode_ddmmyyyy_date_time(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** d = (void**) p0;

                    if (*sc == *NUMBER_8_INTEGER) {

                        log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) L"Decode ddmmyyyy date time.");

                        // The temporary null-terminated day string.
                        wchar_t* tmpd = (wchar_t*) *NULL_POINTER;
                        int tmpds = *NUMBER_2_INTEGER + *NUMBER_1_INTEGER;
                        // The temporary null-terminated month string.
                        wchar_t* tmpm = (wchar_t*) *NULL_POINTER;
                        int tmpms = *NUMBER_2_INTEGER + *NUMBER_1_INTEGER;
                        // The temporary null-terminated year string.
                        wchar_t* tmpy = (wchar_t*) *NULL_POINTER;
                        int tmpys = *NUMBER_4_INTEGER + *NUMBER_1_INTEGER;

                        // Create temporary null-terminated day string.
                        allocate_array((void*) &tmpd, (void*) &tmpds, (void*) WIDE_CHARACTER_ARRAY);
                        // Create temporary null-terminated month string.
                        allocate_array((void*) &tmpm, (void*) &tmpms, (void*) WIDE_CHARACTER_ARRAY);
                        // Create temporary null-terminated year string.
                        allocate_array((void*) &tmpy, (void*) &tmpys, (void*) WIDE_CHARACTER_ARRAY);

                        // The index.
                        int i = *NUMBER_0_INTEGER;
                        // The source day index.
                        void* sdi = p3 + (*NUMBER_0_INTEGER * *WIDE_CHARACTER_PRIMITIVE_SIZE);
                        // The source month index.
                        void* smi = p3 + (*NUMBER_2_INTEGER * *WIDE_CHARACTER_PRIMITIVE_SIZE);
                        // The source year index.
                        void* syi = p3 + (*NUMBER_4_INTEGER * *WIDE_CHARACTER_PRIMITIVE_SIZE);

                        // Copy original string to temporary null-terminated day string.
                        set_array_elements((void*) tmpd, (void*) &i, sdi, (void*) NUMBER_2_INTEGER, (void*) WIDE_CHARACTER_ARRAY);
                        // Copy original string to temporary null-terminated month string.
                        set_array_elements((void*) tmpm, (void*) &i, smi, (void*) NUMBER_2_INTEGER, (void*) WIDE_CHARACTER_ARRAY);
                        // Copy original string to temporary null-terminated year string.
                        set_array_elements((void*) tmpy, (void*) &i, syi, (void*) NUMBER_4_INTEGER, (void*) WIDE_CHARACTER_ARRAY);

                        // The day termination character index.
                        int dti = *NUMBER_2_INTEGER;
                        // The month termination character index.
                        int mti = *NUMBER_2_INTEGER;
                        // The year termination character index.
                        int yti = *NUMBER_4_INTEGER;

                        // Add string termination to temporary null-terminated day string.
                        set_array_elements((void*) tmpd, (void*) &dti, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                        // Add string termination to temporary null-terminated month string.
                        set_array_elements((void*) tmpm, (void*) &mti, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
                        // Add string termination to temporary null-terminated year string.
                        set_array_elements((void*) tmpy, (void*) &yti, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);

                        // The tail variable is useless here and only needed for the string
                        // transformation function. If the whole string array consists of
                        // many sub strings, separated by space characters, then each sub
                        // string gets interpreted as integer number.
                        // The tail variable in this case points to the remaining sub string.
                        wchar_t* tail = (wchar_t*) *NULL_POINTER;

                        // Transform string to day integer value.
                        // The third parameter is the number base:
                        // 0 - tries to automatically identify the correct number base
                        // 8 - octal
                        // 10 - decimal
                        // 16 - hexadecimal
                        int dv = wcstol(tmpd, &tail, *NUMBER_10_INTEGER);
                        // Transform string to month integer value.
                        // The third parameter is the number base:
                        // 0 - tries to automatically identify the correct number base
                        // 8 - octal
                        // 10 - decimal
                        // 16 - hexadecimal
                        int mv = wcstol(tmpm, &tail, *NUMBER_10_INTEGER);
                        // Transform string to year integer value.
                        // The third parameter is the number base:
                        // 0 - tries to automatically identify the correct number base
                        // 8 - octal
                        // 10 - decimal
                        // 16 - hexadecimal
                        int yv = wcstol(tmpy, &tail, *NUMBER_10_INTEGER);

                        // Check date time size.
                        if (*dc >= *ds) {

                            // Calculate new date time size.
                            *ds = *ds * *INTEGER_VECTOR_REALLOCATION_FACTOR + *NUMBER_1_INTEGER;

                            // Reallocate date time.
                            reallocate(p0, p1, p2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                        }

                        // Set date time integer values.
                        set_array_elements(*d, (void*) DATE_TIME_YEAR_INDEX, (void*) &yv, (void*) PRIMITIVE_COUNT, (void*) INTEGER_ARRAY);
                        set_array_elements(*d, (void*) DATE_TIME_MONTH_INDEX, (void*) &mv, (void*) PRIMITIVE_COUNT, (void*) INTEGER_ARRAY);
                        set_array_elements(*d, (void*) DATE_TIME_DAY_INDEX, (void*) &dv, (void*) PRIMITIVE_COUNT, (void*) INTEGER_ARRAY);
                        set_array_elements(*d, (void*) DATE_TIME_HOUR_INDEX, *NULL_POINTER, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ARRAY);
                        set_array_elements(*d, (void*) DATE_TIME_MINUTE_INDEX, *NULL_POINTER, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ARRAY);
                        set_array_elements(*d, (void*) DATE_TIME_SECOND_INDEX, *NULL_POINTER, (void*) NUMBER_0_INTEGER, (void*) INTEGER_ARRAY);

                        // Increase date time count by one, because of new element.
                        (*dc)++;

                        // Destroy temporary null-terminated day string.
                        deallocate_array((void*) &tmpd, (void*) &tmpds, (void*) WIDE_CHARACTER_ARRAY);
                        // Destroy temporary null-terminated month string.
                        deallocate_array((void*) &tmpm, (void*) &tmpms, (void*) WIDE_CHARACTER_ARRAY);
                        // Destroy temporary null-terminated year string.
                        deallocate_array((void*) &tmpy, (void*) &tmpys, (void*) WIDE_CHARACTER_ARRAY);

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode ddmmyyyy date time. The source count is unequal eight characters.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode ddmmyyyy date time. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode ddmmyyyy date time. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode ddmmyyyy date time. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not decode ddmmyyyy date time. The source count is null.");
    }
}

/**
 * Encodes the date time model and creates a ddmmyyyy byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void encode_ddmmyyyy_date_time(void* p0, void* p1, void* p2, void* p3, void* p4) {
}

/* DATE_TIME_CONVERTER_SOURCE */
#endif
