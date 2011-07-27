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
 * @version $RCSfile: utf_8_unicode_character_converter.c,v $ $Revision: 1.12 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PERCENT_ENCODING_DECODER_SOURCE
#define PERCENT_ENCODING_DECODER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../executor/searcher/detector/array_detector.c"
#include "../../../executor/searcher/mover/position_mover.c"
#include "../../../logger/logger.c"

//
// A percent-encoding mechanism is used to represent a data octet in a
// component when that octet's corresponding character is outside the
// allowed set or is being used as a delimiter of, or within, the component.
// A percent-encoded octet is encoded as a character triplet,
// consisting of the percent character "%" followed by the two
// hexadecimal digits representing that octet's numeric value.
//
// Example:
//
// percent-encoding: %20
// binary octet: 00100000
// ABNF: %x20
// US-ASCII: space character (SP)
//

/**
 * Decodes a percent-encoded character array into a non-percent-encoded character array.
 *
 * All percent-encoded (escaped) characters are resolved,
 * no matter whether or not they are reserved characters
 * according to the URI specification.
 *
 * @param p0 the destination character array (Hand over as reference!)
 * @param p1 the destination character array count
 * @param p2 the destination character array size
 * @param p3 the source current position (Hand over as reference!)
 * @param p4 the source remaining count
 */
void decode_percent_encoding(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        void** pos = (void**) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode percent-encoding.");

        // The character value.
        unsigned char v = *NUMBER_0_INTEGER_MEMORY_MODEL;

        /*??
        // Decode integer.
        // A percent-encoding is a hexadecimal value consisting of two digits.
        // Therefore, a size of two is handed over as parameter here.
        decode_integer((void*) &v, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *pos, (void*) NUMBER_2_INTEGER_MEMORY_MODEL);
        */

        //
        //?? --- The following code is temporary and should be moved into an own file!
        //

        // The temporary null-terminated string.
        void* tmp = *NULL_POINTER_MEMORY_MODEL;
        void* tmpc = *NULL_POINTER_MEMORY_MODEL;
        void* tmps = *NULL_POINTER_MEMORY_MODEL;

        // Create temporary null-terminated string.
        allocate_model((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

        // Copy original string to temporary null-terminated string.
        overwrite_array((void*) &tmp, *pos, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, tmpc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, tmpc, tmps);
        // Add string termination to temporary null-terminated string.
        // The source count is used as index for the termination character.
        overwrite_array((void*) &tmp, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, tmpc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, tmpc, tmps);

        // The tail variable is useless here and only needed for the string
        // transformation function. If the whole string array consists of
        // many sub strings, separated by space characters, then each sub
        // string gets interpreted as integer number.
        // The tail variable in this case points to the remaining sub string.
        char* tail = (char*) *NULL_POINTER_MEMORY_MODEL;

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        errno = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Set integer value.
        //
        // Transform string to integer value.
        // The third parameter is the number base:
        // 0 - tries to automatically identify the correct number base
        // 8 - octal, e.g. 083
        // 10 - decimal, e.g. 1234
        // 16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
        v = strtol((char*) tmp, &tail, *NUMBER_16_INTEGER_MEMORY_MODEL);

//??    fwprintf(stdout, L"TEST tmp: %s\n", (char*) tmp);
//??    fwprintf(stdout, L"TEST v: %i\n", v);

        if (errno != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode integer. An error (probably overflow) occured.");
        }

        // Destroy temporary null-terminated string.
        deallocate_model((void*) &tmp, (void*) &tmpc, (void*) &tmps, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

        //
        //?? --- The code above is temporary and should be moved into an own file!
        //

        overwrite_array(p0, (void*) &v, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, p2);

        move_position(p3, p4, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode percent-encoding. The current position is null.");
    }
}

/* PERCENT_ENCODING_DECODER_SOURCE */
#endif
