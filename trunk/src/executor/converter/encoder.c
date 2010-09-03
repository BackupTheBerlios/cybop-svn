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

#ifndef ENCODER_SOURCE
#define ENCODER_SOURCE

#include "../../constant/abstraction/cybol/application_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/application_x_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/colour_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/interface_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/message_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../executor/converter/encoder/boolean_encoder.c"
#include "../../executor/converter/encoder/complex_encoder.c"
#include "../../executor/converter/encoder/cybol_encoder.c"
#include "../../executor/converter/encoder/date_time_encoder.c"
#include "../../executor/converter/encoder/double_vector_encoder.c"
#include "../../executor/converter/encoder/fraction_encoder.c"
#include "../../executor/converter/encoder/gnu_linux_console_encoder.c"
#include "../../executor/converter/encoder/http_request_encoder.c"
#include "../../executor/converter/encoder/http_response_encoder.c"
#include "../../executor/converter/encoder/integer_encoder.c"
#include "../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../executor/converter/encoder/latex_encoder.c"
#include "../../executor/converter/encoder/model_diagram_encoder.c"
#include "../../executor/converter/encoder/terminal_background_encoder.c"
#include "../../executor/converter/encoder/terminal_foreground_encoder.c"
#include "../../executor/converter/encoder/utf_16_unicode_character_encoder.c"
#include "../../executor/converter/encoder/utf_8_unicode_character_encoder.c"
#include "../../executor/converter/encoder/xdt_encoder.c"
#include "../../executor/converter/encoder/xhtml_encoder.c"
#include "../../executor/converter/encoder/xml_encoder.c"
#include "../../executor/converter/encoder/x_window_system_encoder.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../../executor/communicator/sender/file_sender.c"

/**
 * Encodes the source into the destination, according to the given language.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 * @param p11 the knowledge memory
 * @param p12 the knowledge memory count
 * @param p13 the language
 * @param p14 the language count
 */
void encode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_boolean(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_complex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_cybol(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_double_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            encode_gnu_linux_console(p0, p1, p2, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_date_time(p0, p1, p2, p7, p8);
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
            allocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Allocate temporary details.
            allocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

            // Decode source message into temporary compound memory model.
            decode_xml((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p6, p7);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_REQUEST_CONVERSION_MODEL_DIAGRAM.txt";
            int fnc = *NUMBER_37_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_38_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            decode_cybol(p0, p1, p2, p3, p4, p5, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Deallocate temporary details.
            deallocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_REQUEST_COMOUND_CONVERSION_MODEL_DIAGRAM.txt";
            fnc = *NUMBER_39_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_40_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
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
            allocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Allocate temporary details.
            allocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

            // Decode source message into temporary compound memory model.
            decode_xml((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p6, p7);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_RESPONSE_CONVERSION_MODEL_DIAGRAM.txt";
            int fnc = *NUMBER_37_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_38_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            decode_cybol(p0, p1, p2, p3, p4, p5, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Deallocate temporary details.
            deallocate((void*) &d, (void*) &ds, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_RESPONSE_COMPOUND_CONVERSION_MODEL_DIAGRAM.txt";
            fnc = *NUMBER_39_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_40_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            write_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
//?? TEST END
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_integer_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_latex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_model_diagram(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            append(p0, p1, p2, p7, p8, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_terminal_background(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_terminal_foreground(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_fraction(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_x_window_system(p0, p1, p2, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) XDT_TEXT_CYBOL_ABSTRACTION, (void*) XDT_TEXT_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_xdt(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) XHTML_APPLICATION_CYBOL_ABSTRACTION, (void*) XHTML_APPLICATION_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_xhtml(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, p13, p14, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_ddmmyyyy_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not encode. The language is unknown.");
    }
}

/* ENCODER_SOURCE */
#endif
