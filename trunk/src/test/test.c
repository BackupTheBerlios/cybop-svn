/*
 * $RCSfile: test.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 * This is the main testing file.
 *
 * From here all tests can be activated or deactivated.
 *
 * @version $Revision: 1.31 $ $Date: 2005-01-08 19:55:18 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../parser/parser.c"

/**
 * Tests the standard output and error stream.
 */
void test_stdout_stderr() {

    fputs("test stdout ok\n", stdout);
    fputs("test stderr ok\n", stderr);
}

/**
 * Tests the character array with termination.
 */
void test_character_array_with_termination() {

    // The brackets indicating an array cannot be avoided or replaced by a pointer.
    // The following line does not work:
    // char* test = {'t', 'e', 's', 't', '\n', '\0'};

    // The '\n' character is a new line.
    // The character array (string) termination '\0' is necessary when using
    // GNU C library functions such as "fputs".
    char test[] = {'t', 'e', 's', 't', ' ', 'c', 'h', 'a', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'o', 'k', '\n', '\0'};

    fputs(test, stdout);
}

/**
 * Tests the pointer cast.
 */
void test_pointer_cast() {

    // Assign a test character array.
    char* test_char = "test pointer cast ok\n";

    // The & operator makes a char** from char*, in other words a pointer pointer.
    // The char** is then casted to a normal void* which is used to hand
    // over parameters in all procedures of cyboi.
    void* test_void = (void*) &test_char;

    // The void* which was for example retrieved as parameter of a procedure
    // has to be casted back to the original char**.
    char** test_back = (char**) test_void;

    // The char** has to be dereferenced using the * operator,
    // because the fputs function expects a char*.
    fputs(*test_back, stdout);
}

/**
 * Tests the character array with a single element.
 */
void test_character_array_single_element() {

    fputs("Test character array:\n", stdout);

    // The character array size.
    int* cas = INTEGER_NULL_POINTER;
    create_integer((void*) &cas);
    *cas = 5;

    // The character array.
    void* ca = NULL_POINTER;
    create_array((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &cas);

    int* ca1i = INTEGER_NULL_POINTER;
    create_integer((void*) &ca1i);
    *ca1i = 0;

    int* ca2i = INTEGER_NULL_POINTER;
    create_integer((void*) &ca2i);
    *ca2i = 1;

    int* ca3i = INTEGER_NULL_POINTER;
    create_integer((void*) &ca3i);
    *ca3i = 2;

    int* ca4i = INTEGER_NULL_POINTER;
    create_integer((void*) &ca4i);
    *ca4i = 3;

    int* ca5i = INTEGER_NULL_POINTER;
    create_integer((void*) &ca5i);
    *ca5i = 4;

    set_array_elements((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca1i, (void*) &LATIN_CAPITAL_LETTER_A_CHARACTER, (void*) &LATIN_CAPITAL_LETTER_A_CHARACTER_COUNT);
    set_array_elements((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca2i, (void*) &LATIN_CAPITAL_LETTER_B_CHARACTER, (void*) &LATIN_CAPITAL_LETTER_B_CHARACTER_COUNT);
    set_array_elements((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca3i, (void*) &LATIN_CAPITAL_LETTER_C_CHARACTER, (void*) &LATIN_CAPITAL_LETTER_C_CHARACTER_COUNT);
    set_array_elements((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca4i, (void*) &LINE_FEED_CONTROL_CHARACTER, (void*) &LINE_FEED_CONTROL_CHARACTER_COUNT);
    set_array_elements((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca5i, (void*) &NULL_CONTROL_CHARACTER, (void*) &NULL_CONTROL_CHARACTER_COUNT);

    destroy_integer((void*) &ca5i);
    destroy_integer((void*) &ca4i);
    destroy_integer((void*) &ca3i);
    destroy_integer((void*) &ca2i);
    destroy_integer((void*) &ca1i);

    // Print out array contents.
    fputs((char*) ca, stdout);

    int i = 0;
    char* catest = CHARACTER_NULL_POINTER;

    while (1) {

        if (i >= *cas) {

            break;
        }

        catest = (char*) (ca + i);
        fprintf(stderr, "ca: %c\n", *catest);

        i++;
    }

    // Destroy character array.
    destroy_array((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &cas);
    destroy_integer((void*) &cas);
}

/**
 * Tests the character array with multiple elements.
 */
void test_character_array_multiple_elements() {

    // The destination array size.
    int* ds = INTEGER_NULL_POINTER;
    create_integer((void*) &ds);
    *ds = 20;

    // The destination array.
    void* d = NULL_POINTER;
    create_array((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ds);

    // The constant source array and the pointer to it.
    char a[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.', '\n', '\0'};
    char* s = a;
    int ssa[] = {17};
    int* ss = ssa;

    // The destination index to which to copy the source array.
    int* i = INTEGER_NULL_POINTER;
    create_integer((void*) &i);
    *i = 0;

    set_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &s, (void*) &ss);

    destroy_integer((void*) &i);

    fputs((char*) d, stdout);

    // The constant source array for overwriting and the pointer to it.
    char oa[] = {'o', 'v', 'e', 'r', 'w', 'r', 'i', 't', 't', 'e', 'n', '.', '\n', '\0'};
    char* os = oa;
    int ossa[] = {14};
    int* oss = ossa;

    // The destination index to which to copy the source array for overwriting.
    int* oi = INTEGER_NULL_POINTER;
    create_integer((void*) &oi);
    *oi = 8;

    set_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &oi, (void*) &os, (void*) &oss);

    destroy_integer((void*) &oi);

    fputs((char*) d, stdout);

    // The remove index.
    int* ri = INTEGER_NULL_POINTER;
    create_integer((void*) &ri);
    *ri = 12;

    // The remove count.
    int* rc = INTEGER_NULL_POINTER;
    create_integer((void*) &rc);
    *rc = 7;

    remove_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ds, (void*) &ri, (void*) &rc);

    destroy_integer((void*) &rc);
    destroy_integer((void*) &ri);
    destroy_integer((void*) &ds);

    fputs((char*) d, stdout);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int* ns = INTEGER_NULL_POINTER;
    create_integer((void*) &ns);
    *ns = 15;

    resize_array((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ns);

    fputs((char*) d, stdout);

    // Destroy destination array.
    destroy_array((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ns);
    destroy_integer((void*) &ns);
}

/**
 * Tests the file read.
 */
void test_file_read() {

    // A file named "/home/cybop/tmp/test.cybol" needs to be created
    // in a text editor, for this test to work.

/*??
    // The array.
    void* a = NULL_POINTER;
    // The array size.
    int as = 0;
    // The array count.
    int ac = 0;
    // The file name array.
    char fna[] = {'/', 'h', 'o', 'm', 'e', '/', 'c', 'y', 'b', 'o', 'p', '/', 't', 'm', 'p', '/', 't', 'e', 's', 't', '.', 'c', 'y', 'b', 'o', 'l'};
    // The file name.
    char* fn = fna;
    // The file name count.
    int fnc = 26;

    create_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
//??    read_file((void*) &a, (void*) &as, (void*) &ac, (void*) &fn, (void*) &fnc);

    fprintf(stderr, "a: %i\n", a);
    fprintf(stderr, "as: %i\n", as);
    fprintf(stderr, "ac: %i\n", ac);
    fprintf(stderr, "fn: %i\n", fn);
    fprintf(stderr, "fnc: %i\n", fnc);

    int j = 0;
    char* c = NULL_POINTER;
    int* cc = 1;

    while (1) {

        if (j >= ac) {

            break;
        }

        get_array_elements((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &j, (void*) &c, (void*) &cc);
        fputs(c, stdout);

        j++;
    }

    destroy_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
*/
}

/**
 * Tests the file write.
 */
void test_file_write() {

    // The character array.
    char aa[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\n'};
    // The array.
    void* a = aa;
    // The array size.
    int as = 14;
    // The array count.
    int ac = 14;
    // The file name array.
    char fna[] = {'/', 'h', 'o', 'm', 'e', '/', 'c', 'y', 'b', 'o', 'p', '/', 't', 'm', 'p', '/', 't', 'e', 's', 't', '.', 'c', 'y', 'b', 'o', 'l'};
    // The file name.
    char* fn = fna;
    // The file name count.
    int fnc = 26;

//??    write_file((void*) &a, (void*) &as, (void*) &ac, (void*) &fn, (void*) &fnc);
}

/**
 * Tests the console.
 */
void test_console() {

    if (strcmp("linux", getenv("TERM")) == 0) {

//        // This is a linux console.
//        fputs("This is a linux console.\n", stdout);
//
//        // Determine device name of controlling terminal.
//        int n = ttyname();
//        fprintf(stdout, "The terminal device name is: %i\n", n);
//
//        // Declare test string.
//        char* s;
//
//        // Beep \007 twice with system loudspeaker.
//        s = "Beep:\n\007";
//        fputs(s, stdout);
//
//        //
//        // Start ESCAPE CSI sequence with: \033[
//        //
//
//        // Print bold word.
//        fputs("This is a \033[1mbold\033[0m word.\n", stdout);
//
//        // Set colours.
//        // CAUTION! The "m" has to stand after the colour number
//        // and it must NOT be a capital letter.
//        fputs("Set colour to \033[32mgreen\033[0m.\n", stdout);
//        fputs("Set colour to \033[32myellow\041[0m.\n", stdout);
//        fputs("Set colour to \033[32mred\031[0m.\n", stdout);

    } else {

        // This is a normal serial terminal.
        fputs("This is a normal serial terminal.\n", stdout);
    }
}

/**
 * Tests the integer parser.
 */
void test_integer_parser() {

/*??
    // The source string.
    char ssa[] = {'1', '9', '7', '1'};
    void* ss = ssa;
    int ssc = 4;

    // The destination integer.
    int di = -1;
    int dic = -1;
    int dis = -1;

    parse((void*) &di, (void*) &dic, (void*) &dis, (void*) &ss, (void*) &ssc,
        (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_COUNT);

    fprintf(stderr, "Parsed source string results in destination integer: %i\n", di);

    // The source integer.
    int si = 1980;
    int sic = -1;

    // The destination string.
    char* ds = NULL_POINTER;
    int dsc = 0;
    int dss = 0;

    // Create destination string.
    create_array((void*) &ds, (void*) &CHARACTER_ARRAY, (void*) &dss);

    serialize((void*) &ds, (void*) &dsc, (void*) &dss, (void*) &si, (void*) &sic,
        (void*) &INTEGER_ABSTRACTION, (void*) &INTEGER_ABSTRACTION_COUNT);

    fprintf(stderr, "Serialized source integer results in destination string: %s\n", ds);

    // Destroy destination string.
    destroy_array((void*) &ds, (void*) &CHARACTER_ARRAY, (void*) &dss);
*/
}

/**
 * Tests the knowledge model.
 *
 * The knowledge model is the root of a compound (tree).
 * But also a part of the knowledge model can be handed over,
 * in which case that part and its parts will be printed on screen.
 *
 * @param p0 the knowledge model
 * @param p1 the knowledge model count
 */
void test_knowledge_model(const void* p0, const void* p1) {

    if (p1 != NULL_POINTER) {

        int** c = (int**) p1;

        // The loop index.
        int* i = INTEGER_NULL_POINTER;
        create_integer((void*) &i);
        *i = 0;
        // The element name.
        char* n = CHARACTER_NULL_POINTER;
        int* nc = INTEGER_NULL_POINTER;
        int* ns = INTEGER_NULL_POINTER;
        // The element abstraction.
        char* a = CHARACTER_NULL_POINTER;
        int* ac = INTEGER_NULL_POINTER;
        int* as = INTEGER_NULL_POINTER;
        // The element model.
        void* m = NULL_POINTER;
        int* mc = INTEGER_NULL_POINTER;
        int* ms = INTEGER_NULL_POINTER;
        // The element details.
        void* d = NULL_POINTER;
        int* dc = INTEGER_NULL_POINTER;
        int* ds = INTEGER_NULL_POINTER;
        // The comparison result.
        int* r = INTEGER_NULL_POINTER;
        create_integer((void*) &r);
        *r = 0;

        while (1) {

            if (*i >= **c) {

                break;
            }

            // Get element name.
            get_compound_element_name_by_index(p0, p1, (void*) &i, (void*) &n, (void*) &nc, (void*) &ns);

            // Get element.
            get_compound_element_by_index(p0, p1, (void*) &i, (void*) &a, (void*) &ac, (void*) &as, (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds);

            // Print element name.
            fprintf(stderr, "name:              %s\n", n);
            fprintf(stderr, "name count:        %i\n", *nc);
            fprintf(stderr, "name size:         %i\n", *ns);

            // Print element abstraction.
            fprintf(stderr, "abstraction:       %s\n", a);
            fprintf(stderr, "abstraction count: %i\n", *ac);
            fprintf(stderr, "abstraction size:  %i\n", *as);

            // Handle element model.
            if (*r == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &COMPOUND_ABSTRACTION, (void*) &COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    fprintf(stderr, "model: %s\n", "");
                    test_knowledge_model((void*) &m, (void*) &mc);
                }
            }

            if (*r == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &OPERATION_ABSTRACTION, (void*) &OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    fprintf(stderr, "model:         %i\n", m);
                    fprintf(stderr, "model count:   %i\n", *mc);
                    fprintf(stderr, "model size:    %i\n", *ms);
                }
            }

            if (*r == 0) {

                compare_arrays((void*) &a, (void*) &ac, (void*) &STRING_ABSTRACTION, (void*) &STRING_ABSTRACTION_COUNT, (void*) &r, (void*) &CHARACTER_ARRAY);

                if (*r == 1) {

                    fprintf(stderr, "model:             %i\n", m);
                    fprintf(stderr, "model count:       %i\n", *mc);
                    fprintf(stderr, "model size:        %i\n", *ms);
                }
            }

            // Handle element details.
            if (d != NULL_POINTER) {

                fprintf(stderr, "details: %s\n", "");
                test_knowledge_model((void*) &d, (void*) &dc);
            }

            // Reset element name.
            n = NULL_POINTER;
            *nc = 0;
            *ns = 0;
            // Reset element abstraction.
            a = NULL_POINTER;
            *ac = 0;
            *as = 0;
            // Reset element model.
            m = NULL_POINTER;
            *mc = 0;
            *ms = 0;
            // Reset element details.
            d = NULL_POINTER;
            *dc = 0;
            *ds = 0;
            // Reset comparison result.
            *r = 0;

            (*i)++;
        }

        destroy_integer((void*) &r);
        destroy_integer((void*) &i);

    } else {

        fputs("ERROR: Could not test knowledge model. The knowledge model is null.", stdout);
    }
}

/**
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

    // How to use printf to check parameter values.
    // The printf function uses stdout for output, but nothing appears on console.
    // Therefore, fprintf is used and stderr is given for output.
    // Example:
    // int x = 2;
    // fprintf(stderr, "The value of x is: %d\n", x);

//    test_stdout_stderr();
//    test_character_array_with_termination();
//    test_pointer_cast();
//    test_character_array_single_element();
//    test_character_array_multiple_elements();
//    test_file_read();
//    test_file_write();
//    test_console();
//    test_integer_parser();
}

/* TEST_SOURCE */
#endif
