/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: date_time_converter.c,v $ $Revision: 1.21 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATE_TIME_DECODER_SOURCE
#define DATE_TIME_DECODER_SOURCE

#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/datetime_memory_name.c"
#include "../../logger/logger.c"
#include "../../executor/memoriser/allocator.c"
#include "../../variable/reallocation_factor.c"

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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_MEMORY_MODEL) {

            void* s = (void*) p3;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                void** d = (void**) p0;

                log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode date time.");

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode date time. The destination is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode date time. The source is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode date time. The source count is null.");
    }
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

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    if (*sc == *NUMBER_8_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode ddmmyyyy date time.");

                        // The temporary null-terminated day string.
                        wchar_t* tmpd = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
                        int tmpds = *NUMBER_2_INTEGER_MEMORY_MODEL + *NUMBER_1_INTEGER_MEMORY_MODEL;
                        // The temporary null-terminated month string.
                        wchar_t* tmpm = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
                        int tmpms = *NUMBER_2_INTEGER_MEMORY_MODEL + *NUMBER_1_INTEGER_MEMORY_MODEL;
                        // The temporary null-terminated year string.
                        wchar_t* tmpy = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
                        int tmpys = *NUMBER_4_INTEGER_MEMORY_MODEL + *NUMBER_1_INTEGER_MEMORY_MODEL;

                        // Create temporary null-terminated day string.
                        allocate_array((void*) &tmpd, (void*) &tmpds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Create temporary null-terminated month string.
                        allocate_array((void*) &tmpm, (void*) &tmpms, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Create temporary null-terminated year string.
                        allocate_array((void*) &tmpy, (void*) &tmpys, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                        // The index.
                        int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
                        // The source day index.
                        void* sdi = p3 + (*NUMBER_0_INTEGER_MEMORY_MODEL * *WIDE_CHARACTER_PRIMITIVE_SIZE);
                        // The source month index.
                        void* smi = p3 + (*NUMBER_2_INTEGER_MEMORY_MODEL * *WIDE_CHARACTER_PRIMITIVE_SIZE);
                        // The source year index.
                        void* syi = p3 + (*NUMBER_4_INTEGER_MEMORY_MODEL * *WIDE_CHARACTER_PRIMITIVE_SIZE);

                        // Copy original string to temporary null-terminated day string.
                        set_array_elements((void*) tmpd, (void*) &i, sdi, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Copy original string to temporary null-terminated month string.
                        set_array_elements((void*) tmpm, (void*) &i, smi, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Copy original string to temporary null-terminated year string.
                        set_array_elements((void*) tmpy, (void*) &i, syi, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                        // The day termination character index.
                        int dti = *NUMBER_2_INTEGER_MEMORY_MODEL;
                        // The month termination character index.
                        int mti = *NUMBER_2_INTEGER_MEMORY_MODEL;
                        // The year termination character index.
                        int yti = *NUMBER_4_INTEGER_MEMORY_MODEL;

                        // Add string termination to temporary null-terminated day string.
                        set_array_elements((void*) tmpd, (void*) &dti, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Add string termination to temporary null-terminated month string.
                        set_array_elements((void*) tmpm, (void*) &mti, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Add string termination to temporary null-terminated year string.
                        set_array_elements((void*) tmpy, (void*) &yti, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                        // The tail variable is useless here and only needed for the string
                        // transformation function. If the whole string array consists of
                        // many sub strings, separated by space characters, then each sub
                        // string gets interpreted as integer number.
                        // The tail variable in this case points to the remaining sub string.
                        wchar_t* tail = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;

                        // Transform string to day integer value.
                        // The third parameter is the number base:
                        // 0 - tries to automatically identify the correct number base
                        // 8 - octal
                        // 10 - decimal
                        // 16 - hexadecimal
                        int dv = wcstol(tmpd, &tail, *NUMBER_10_INTEGER_MEMORY_MODEL);
                        // Transform string to month integer value.
                        // The third parameter is the number base:
                        // 0 - tries to automatically identify the correct number base
                        // 8 - octal
                        // 10 - decimal
                        // 16 - hexadecimal
                        int mv = wcstol(tmpm, &tail, *NUMBER_10_INTEGER_MEMORY_MODEL);
                        // Transform string to year integer value.
                        // The third parameter is the number base:
                        // 0 - tries to automatically identify the correct number base
                        // 8 - octal
                        // 10 - decimal
                        // 16 - hexadecimal
                        int yv = wcstol(tmpy, &tail, *NUMBER_10_INTEGER_MEMORY_MODEL);

                        // Check date time size.
                        if (*dc >= *ds) {

                            // Calculate new date time size.
                            *ds = *ds * *INTEGER_VECTOR_REALLOCATION_FACTOR + *NUMBER_1_INTEGER_MEMORY_MODEL;

                            // Reallocate date time.
                            reallocate(p0, p1, p2, (void*) INTEGER_VECTOR_MEMORY_ABSTRACTION);
                        }

                        // Set date time integer values.
                        set_array_elements(*d, (void*) YEAR_DATETIME_MEMORY_NAME, (void*) &yv, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
                        set_array_elements(*d, (void*) MONTH_DATETIME_MEMORY_NAME, (void*) &mv, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
                        set_array_elements(*d, (void*) DAY_DATETIME_MEMORY_NAME, (void*) &dv, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION);
                        set_array_elements(*d, (void*) HOUR_DATETIME_MEMORY_NAME, *NULL_POINTER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);
                        set_array_elements(*d, (void*) MINUTE_DATETIME_MEMORY_NAME, *NULL_POINTER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);
                        set_array_elements(*d, (void*) SECOND_DATETIME_MEMORY_NAME, *NULL_POINTER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);

                        // Increase date time count by one, because of new element.
                        (*dc)++;

                        // Destroy temporary null-terminated day string.
                        deallocate_array((void*) &tmpd, (void*) &tmpds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Destroy temporary null-terminated month string.
                        deallocate_array((void*) &tmpm, (void*) &tmpms, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
                        // Destroy temporary null-terminated year string.
                        deallocate_array((void*) &tmpy, (void*) &tmpys, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

                    } else {

                        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ddmmyyyy date time. The source count is unequal eight characters.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ddmmyyyy date time. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ddmmyyyy date time. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ddmmyyyy date time. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode ddmmyyyy date time. The source count is null.");
    }
}

/* DATE_TIME_DECODER_SOURCE */
#endif
