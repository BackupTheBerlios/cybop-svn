/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: converter.c,v $ $Revision: 1.50 $ $Date: 2008-09-04 20:31:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONVERTER_SOURCE
#define CONVERTER_SOURCE

#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/abstraction/memory/memory_abstraction.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../memoriser/converter/character/ascii_character_vector_converter.c"
#include "../memoriser/converter/character/utf_16_unicode_character_converter.c"
#include "../memoriser/converter/character/utf_8_unicode_character_converter.c"
#include "../memoriser/converter/boolean_converter.c"
#include "../memoriser/converter/complex_converter.c"
#include "../memoriser/converter/compound_converter.c"
#include "../memoriser/converter/date_time_converter.c"
#include "../memoriser/converter/double_vector_converter.c"
#include "../memoriser/converter/fraction_converter.c"
#include "../memoriser/converter/http_request_converter.c"
#include "../memoriser/converter/http_response_converter.c"
#include "../memoriser/converter/integer_converter.c"
#include "../memoriser/converter/integer_vector_converter.c"
#include "../memoriser/converter/latex_converter.c"
#include "../memoriser/converter/gnu_linux_console_converter.c"
#include "../memoriser/converter/model_diagram_converter.c"
#include "../memoriser/converter/terminal_background_converter.c"
#include "../memoriser/converter/terminal_foreground_converter.c"
#include "../memoriser/converter/x_window_system_converter.c"
#include "../memoriser/converter/xdt_converter.c"
#include "../memoriser/converter/xhtml_converter.c"
#include "../memoriser/array.c"

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

        compare_arrays(p10, p11, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_compound(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
//??            decode_utf_8_unicode_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
//??            decode_utf_8_unicode_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
//??            decode_utf_8_unicode_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! For cybol files, only the abstraction "character" is defined.
        // No distinction is made between "character" and "wide character", in other words:
        // a cybol abstraction named "wide_character" does not exist.
        // Similarly, all cybol files are expected to be encoded as utf-8.
        //
        // When decoding a value of abstraction "character" from cybol into cyboi,
        // it is assumed to be a multibyte utf-8 encoded character string (CHARACTER_VECTOR_ABSTRACTION)
        // and gets converted into a "wchar_t" (WIDE_CHARACTER_VECTOR_ABSTRACTION) array internally.
        //
        // When encoding a value of abstraction "wide_character" from cyboi into cybol,
        // it is assumed to be a "wchar_t" array of (WIDE_CHARACTER_VECTOR_ABSTRACTION)
        // and gets converted into a multibyte utf-8 encoded character string (CHARACTER_VECTOR_ABSTRACTION).
        //
        // Therefore, the comparison here only considers "CHARACTER_VECTOR_ABSTRACTION",
        // but not "WIDE_CHARACTER_VECTOR_ABSTRACTION".
        compare_arrays(p10, p11, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
//??            decode_utf_8_unicode_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            set(p0, p1, p2, p6, p7, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_boolean(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_integer_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_double_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_fraction(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_complex(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) DATE_TIME_ABSTRACTION, (void*) DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_date_time(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_ddmmyyyy_date_time(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_gnu_linux_console(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_x_window_system(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) XHTML_ABSTRACTION, (void*) XHTML_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_xhtml(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) HTTP_REQUEST_ABSTRACTION, (void*) HTTP_REQUEST_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_http_request(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) HTTP_RESPONSE_ABSTRACTION, (void*) HTTP_RESPONSE_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_http_response(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) MODEL_DIAGRAM_ABSTRACTION, (void*) MODEL_DIAGRAM_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_model_diagram(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_xdt(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) LATEX_ABSTRACTION, (void*) LATEX_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_latex(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_terminal_background(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_terminal_foreground(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION, (void*) UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_utf_8_unicode_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION, (void*) UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            decode_utf_16_unicode_character_stream(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode. The language is unknown.");
    }
}

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

        compare_arrays(p13, p14, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_compound(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_utf_8_unicode_character_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // CAUTION! For cybol files, only the abstraction "character" is defined.
        // No distinction is made between "character" and "wide character", in other words:
        // a cybol abstraction named "wide_character" does not exist.
        // Similarly, all cybol files are expected to be encoded as utf-8.
        //
        // When decoding a value of abstraction "character" from cybol into cyboi,
        // it is assumed to be a multibyte utf-8 encoded character string (CHARACTER_VECTOR_ABSTRACTION)
        // and gets converted into a "wchar_t" (WIDE_CHARACTER_VECTOR_ABSTRACTION) array internally.
        //
        // When encoding a value of abstraction "wide_character" from cyboi into cybol,
        // it is assumed to be a "wchar_t" array of (WIDE_CHARACTER_VECTOR_ABSTRACTION)
        // and gets converted into a multibyte utf-8 encoded character string (CHARACTER_VECTOR_ABSTRACTION).
        //
        // Therefore, the comparison here only considers "WIDE_CHARACTER_VECTOR_ABSTRACTION",
        // but not "CHARACTER_VECTOR_ABSTRACTION".
        compare_arrays(p13, p14, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_utf_8_unicode_character_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_boolean(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_integer_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_double_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_fraction(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_complex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) DATE_TIME_ABSTRACTION, (void*) DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_ddmmyyyy_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            encode_gnu_linux_console(p0, p1, p2, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_x_window_system(p0, p1, p2, p7, p8, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) XHTML_ABSTRACTION, (void*) XHTML_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_xhtml(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) HTTP_REQUEST_ABSTRACTION, (void*) HTTP_REQUEST_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_http_request(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) HTTP_RESPONSE_ABSTRACTION, (void*) HTTP_RESPONSE_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_http_response(p0, p1, p2, p7, p8, p9, p10);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) MODEL_DIAGRAM_ABSTRACTION, (void*) MODEL_DIAGRAM_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_model_diagram(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_xdt(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) LATEX_ABSTRACTION, (void*) LATEX_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_latex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) TERMINAL_BACKGROUND_ABSTRACTION, (void*) TERMINAL_BACKGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_terminal_background(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) TERMINAL_FOREGROUND_ABSTRACTION, (void*) TERMINAL_FOREGROUND_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_terminal_foreground(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION, (void*) UTF_8_UNICODE_CHARACTER_ENCODING_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_utf_8_unicode_character_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p13, p14, (void*) UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION, (void*) UTF_16_UNICODE_CHARACTER_ENCODING_ABSTRACTION_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            encode_utf_16_unicode_character_stream(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not encode. The language is unknown.");
    }
}

/* CONVERTER_SOURCE */
#endif
