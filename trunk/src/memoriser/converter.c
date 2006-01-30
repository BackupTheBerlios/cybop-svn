/*
 * $RCSfile: converter.c,v $
 *
 * Copyright (c) 2002-2004. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.14 $ $Date: 2006-01-30 21:30:12 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONVERTER_SOURCE
#define CONVERTER_SOURCE

#include "../globals/constants/model_constants.c"
#include "../memoriser/array.c"
#include "../memoriser/converter/boolean_converter.c"
#include "../memoriser/converter/character_vector_converter.c"
#include "../memoriser/converter/complex_converter.c"
#include "../memoriser/converter/double_vector_converter.c"
#include "../memoriser/converter/fraction_converter.c"
#include "../memoriser/converter/integer_vector_converter.c"
#include "../memoriser/converter/latex_converter.c"
#include "../memoriser/converter/linux_console_converter.c"
#include "../memoriser/converter/time_converter.c"
#include "../memoriser/converter/x_window_system_converter.c"
#include "../memoriser/converter/xml_converter.c"

/**
 * Parses the byte stream according to the given document type
 * and creates a document model from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 */
void parse(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_character_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION, (void*) ENCAPSULATED_KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_character_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_xml(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_character_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_character_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_boolean(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_integer_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_double_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_fraction(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_complex(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_time(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) LATEX_ABSTRACTION, (void*) LATEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_latex(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_linux_console(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            parse_x_window_system(p0, p1, p2, p3, p4);
        }
    }

/*??
    //?? Later, distinguish file types according to abstraction,
    //?? for example xml, html, sxi, txt, rtf,
    //?? adl (from OpenEHR), KIF, ODL etc.!
    //?? For now, only the cybol file format is considered.

    if (r == 0) {

        compare_arrays(p5, p6, (void*) SXW_ABSTRACTION, (void*) SXW_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            //?? For other kinds of file (stream) formats,
            //?? for example from special applications like Open Office,
            //?? use a similar handling like for compound above!

            //?? Images possibly also have to be handled that way.
            //?? At first, the single image parameters have to be parsed
            //?? and written into a special parameter model in memory;
            //?? then that model has to be decoded into a knowledge model!
            //?? May be this idea is rubbish and will not work!
            //?? For the beginning, better handle images as primitve types.
        }
    }
*/
}

/**
 * Serialises the document model according to the given document type
 * and creates a byte stream from it.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 * @param p5 the type
 * @param p6 the type count
 * @param p7 the knowledge memory
 * @param p8 the knowledge memory count
 */
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8) {

    // The comparison result.
    int r = 0;

    if (r == 0) {

        compare_arrays(p5, p6, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_xml(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_character_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_character_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) BOOLEAN_ABSTRACTION, (void*) BOOLEAN_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_boolean(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_integer_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) DOUBLE_VECTOR_ABSTRACTION, (void*) DOUBLE_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_double_vector(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) FRACTION_ABSTRACTION, (void*) FRACTION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_fraction(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) COMPLEX_ABSTRACTION, (void*) COMPLEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_complex(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) TIME_ABSTRACTION, (void*) TIME_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_time(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) LATEX_ABSTRACTION, (void*) LATEX_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_latex(p0, p1, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_linux_console(p0, p1, p2, p3, p4, NULL_POINTER, NULL_POINTER, p7, p8);
        }
    }

    if (r == 0) {

        compare_arrays(p5, p6, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            serialise_x_window_system(p0, p1, p2, p3, p4, NULL_POINTER, NULL_POINTER, p7, p8);
        }
    }

    //?? Later, distinguish file types according to abstraction,
    //?? for example xml, html, sxi, txt, rtf,
    //?? adl (from OpenEHR), KIF, ODL etc.!
    //?? For now, only the cybol file format is considered.
}

/* CONVERTER_SOURCE */
#endif
