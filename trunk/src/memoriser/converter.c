/*
 * $RCSfile: converter.c,v $
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
 * @version $Revision: 1.33 $ $Date: 2007-07-29 01:53:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONVERTER_SOURCE
#define CONVERTER_SOURCE

#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/memory_structure/memory_abstraction_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../memoriser/array.c"
#include "../memoriser/converter/boolean_converter.c"
#include "../memoriser/converter/character_vector_converter.c"
#include "../memoriser/converter/complex_converter.c"
#include "../memoriser/converter/compound_converter.c"
#include "../memoriser/converter/date_time_converter.c"
#include "../memoriser/converter/double_vector_converter.c"
#include "../memoriser/converter/fraction_converter.c"
#include "../memoriser/converter/integer_converter.c"
#include "../memoriser/converter/integer_vector_converter.c"
#include "../memoriser/converter/latex_converter.c"
#include "../memoriser/converter/gnu_linux_console_converter.c"
#include "../memoriser/converter/model_diagram_converter.c"
#include "../memoriser/converter/x_window_system_converter.c"
#include "../memoriser/converter/xdt_converter.c"
#include "../memoriser/converter/xhtml_converter.c"

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
 * @param p8 the language
 * @param p9 the language count
 */
void parse(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_debug("Information: Parse.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_compound(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_character_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_boolean(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_integer_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_double_vector(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_fraction(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_complex(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) DATE_TIME_ABSTRACTION, (void*) DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_date_time(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_ddmmyyyy_date_time(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_gnu_linux_console(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_x_window_system(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) XHTML_ABSTRACTION, (void*) XHTML_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_xhtml(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) MODEL_DIAGRAM_ABSTRACTION, (void*) MODEL_DIAGRAM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_model_diagram(p0, p1, p2, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_xdt(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p8, p9, (void*) LATEX_ABSTRACTION, (void*) LATEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            parse_latex(p0, p1, p2, p6, p7);
        }
    }
}

/**
 * Serialises the knowledge model according to the given knowledge type
 * and creates a byte stream from it.
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
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_debug("Information: Serialise.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_compound(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_character_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_character_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_boolean(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_integer_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_double_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_fraction(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_complex(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) DATE_TIME_ABSTRACTION, (void*) DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION, (void*) DDMMYYYY_DATE_TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_ddmmyyyy_date_time(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

//??            serialise_gnu_linux_console(p0, p1, p2, p7, p8, *NULL_POINTER, *NULL_POINTER, p13, p14);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_x_window_system(p0, p1, p2, p7, p8, *NULL_POINTER, *NULL_POINTER, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) XHTML_ABSTRACTION, (void*) XHTML_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_xhtml(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) MODEL_DIAGRAM_ABSTRACTION, (void*) MODEL_DIAGRAM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_model_diagram(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) XDT_ABSTRACTION, (void*) XDT_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_xdt(p0, p1, p2, p7, p8);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays(p13, p14, (void*) LATEX_ABSTRACTION, (void*) LATEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            serialise_latex(p0, p1, p2, p7, p8);
        }
    }
}

/* CONVERTER_SOURCE */
#endif
