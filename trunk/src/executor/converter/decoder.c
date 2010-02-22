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
 * @version $RCSfile: converter.c,v $ $Revision: 1.76 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DECODER_SOURCE
#define DECODER_SOURCE

#include "../constant/abstraction/cybol/application_cybol_abstraction.c"
#include "../constant/abstraction/cybol/application_x_cybol_abstraction.c"
#include "../constant/abstraction/cybol/colour_cybol_abstraction.c"
#include "../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../constant/abstraction/cybol/interface_cybol_abstraction.c"
#include "../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
#include "../constant/abstraction/cybol/message_cybol_abstraction.c"
#include "../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/channel/cybol_channel.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../memoriser/converter/character/ascii_character_vector_converter.c"
#include "../memoriser/converter/character/utf_16_unicode_character_converter.c"
#include "../memoriser/converter/character/utf_8_unicode_character_converter.c"
#include "../memoriser/converter/abstraction_converter.c"
#include "../memoriser/converter/boolean_converter.c"
#include "../memoriser/converter/complex_converter.c"
#include "../memoriser/converter/cybol_converter.c"
#include "../memoriser/converter/date_time_converter.c"
#include "../memoriser/converter/double_vector_converter.c"
#include "../memoriser/converter/fraction_converter.c"
#include "../memoriser/converter/gnu_linux_console_converter.c"
#include "../memoriser/converter/http_request_converter.c"
#include "../memoriser/converter/http_response_converter.c"
#include "../memoriser/converter/integer_converter.c"
#include "../memoriser/converter/integer_vector_converter.c"
#include "../memoriser/converter/latex_converter.c"
#include "../memoriser/converter/model_diagram_converter.c"
#include "../memoriser/converter/terminal_background_converter.c"
#include "../memoriser/converter/terminal_foreground_converter.c"
#include "../memoriser/converter/x_window_system_converter.c"
#include "../memoriser/converter/xdt_converter.c"
#include "../memoriser/converter/xhtml_converter.c"
#include "../memoriser/converter/xml_converter.c"
#include "../executor/comparator/array_equality_comparator.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../memoriser/communicator/file_communicator.c"

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
void decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_abstraction(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_boolean(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO: Implement the following function!
            //?? decode_cartesian_complex(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The temporary model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The temporary details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate temporary model.
            allocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            // Allocate temporary details.
            allocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

            // Decode source message (cybol file) into temporary compound memory model.
            decode_xml((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p6, p7);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_XML_CONVERSION_MODEL_DIAGRAM.txt";
            int fnc = *NUMBER_37_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_38_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            // Basically, structural data (tags) and meta data (attributes) are swapped in meaning.
            decode_cybol(p0, p1, p2, p3, p4, p5, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            // Deallocate temporary details.
            deallocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_CYBOL_CONVERSION_MODEL_DIAGRAM.txt";
            fnc = *NUMBER_39_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_40_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
//?? TEST END
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TEMPORARY solution!
            //?? TODO: Replace with something like "decode_decimal_fraction".
            //?? decode_double_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_gnu_linux_console(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO: Rename into "decode_hhmmss_date_time"!
            //?? decode_date_time(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) HTTP_REQUEST_MESSAGE_CYBOL_ABSTRACTION, (void*) HTTP_REQUEST_MESSAGE_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The temporary model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The temporary details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate temporary model.
            allocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            // Allocate temporary details.
            allocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

            // Decode source message into temporary compound memory model.
            decode_http_request((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p6, p7);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_REQUEST_CONVERSION_MODEL_DIAGRAM.txt";
            int fnc = *NUMBER_37_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_38_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            decode_cybol(p0, p1, p2, p3, p4, p5, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            // Deallocate temporary details.
            deallocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_REQUEST_COMPOUND_CONVERSION_MODEL_DIAGRAM.txt";
            fnc = *NUMBER_39_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_40_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
//?? TEST END
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_ABSTRACTION, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The temporary model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The temporary details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate temporary model.
            allocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            // Allocate temporary details.
            allocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

            // Decode source message into temporary compound memory model.
            decode_xml((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p6, p7);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_RESPONSE_CONVERSION_MODEL_DIAGRAM.txt";
            int fnc = *NUMBER_37_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_38_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            decode_cybol(p0, p1, p2, p3, p4, p5, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
            // Deallocate temporary details.
            deallocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_RESPONSE_COMPOUND_CONVERSION_MODEL_DIAGRAM.txt";
            fnc = *NUMBER_39_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_40_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION);
//?? TEST END
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_integer_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_latex(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_model_diagram(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_terminal_background(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_terminal_foreground(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            //?? TODO: Rename into "decode_vulgar_fraction"!
            //?? decode_fraction(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_x_window_system(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) XDT_TEXT_CYBOL_ABSTRACTION, (void*) XDT_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_xdt(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

/*??
    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) XHTML_APPLICATION_CYBOL_ABSTRACTION, (void*) XHTML_APPLICATION_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_xhtml(p0, p1, p2, p6, p7);
        }
    }
*/

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p10, p11, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_ddmmyyyy_date_time(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode. The language is unknown.");
    }
}

/* DECODER_SOURCE */
#endif
