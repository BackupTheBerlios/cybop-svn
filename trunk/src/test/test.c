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
 * @version $Revision: 1.37 $ $Date: 2005-01-19 19:31:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../creator/integer_creator.c"
#include "../global/structure_constants.c"
#include "../global/variables.c"
#include "../parser/parser.c"

/**
 * Tests the standard output and error stream.
 */
void test_stdout_stderr() {

    fputs("Test stdout stderr:\n", stdout);

    fputs("test stdout ok\n", stdout);
    fputs("test stderr ok\n", stderr);
}

/**
 * Tests the character array with termination.
 */
void test_character_array_with_termination() {

    fputs("Test character array with termination:\n", stdout);

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

    fputs("Test pointer cast:\n", stdout);

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

    fputs("Test character array single element:\n", stdout);

    // The character array.
    void* c = NULL_POINTER;
    int cs = 5;

    // Create character array.
    create_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);

    set_character_array_elements(c, (void*) ZERO_NUMBER, (void*) LATIN_CAPITAL_LETTER_A_CHARACTER, (void*) LATIN_CAPITAL_LETTER_A_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) ONE_NUMBER, (void*) LATIN_CAPITAL_LETTER_B_CHARACTER, (void*) LATIN_CAPITAL_LETTER_B_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) TWO_NUMBER, (void*) LATIN_CAPITAL_LETTER_C_CHARACTER, (void*) LATIN_CAPITAL_LETTER_C_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) THREE_NUMBER, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) LINE_FEED_CONTROL_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) FOUR_NUMBER, (void*) NULL_CONTROL_CHARACTER, (void*) NULL_CONTROL_CHARACTER_COUNT);

    // Print out array contents.
    fputs((char*) c, stdout);

    int i = 0;
    char* catest = CHARACTER_NULL_POINTER;

    while (1) {

        if (i >= cs) {

            break;
        }

        catest = (char*) (c + i);
        fprintf(stderr, "ca: %c\n", *catest);

        i++;
    }

    // Destroy character array.
    destroy_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);
}

/**
 * Tests the character array with multiple elements.
 */
void test_character_array_multiple_elements() {

    fputs("Test character array multiple elements:\n", stdout);

    // The destination array.
    void* d = NULL_POINTER;
    int ds = 22;

    // Create destination array.
    create_array((void*) &d, (void*) &ds, (void*) CHARACTER_ARRAY);

    // The source array.
    char a[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.', '\n', '\0'};
    char* s = a;
    int ssa[] = {17};
    int* ss = ssa;

    // The destination index to which to copy the source array.
    set_character_array_elements(d, (void*) ZERO_NUMBER, (void*) s, (void*) ss);

    fputs((char*) d, stdout);

    // The source array for overwriting.
    char oa[] = {'o', 'v', 'e', 'r', 'w', 'r', 'i', 't', 't', 'e', 'n', '.', '\n', '\0'};
    char* os = oa;
    int ossa[] = {14};
    int* oss = ossa;

    set_character_array_elements(d, (void*) EIGHT_NUMBER, (void*) os, (void*) oss);

    fputs((char*) d, stdout);

    // The remove index.
    int ri = 12;

    remove_character_array_elements(d, (void*) &ds, (void*) &ri, (void*) SEVEN_NUMBER);

    fputs((char*) d, stdout);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = 15;

    resize_array((void*) &d, (void*) &ns, (void*) CHARACTER_ARRAY);

    fputs((char*) d, stdout);

    // The result array.
    void* r = NULL_POINTER;

    // Test getting a reference.
    get_character_array_elements(d, (void*) EIGHT_NUMBER, (void*) &r);

    fputs((char*) r, stdout);

    // Destroy destination array.
    destroy_array((void*) &d, (void*) &ns, (void*) CHARACTER_ARRAY);
}

/**
 * Tests the pointer return.
 *
 * In other words, if an array element is returned correctly,
 * when using a null pointer.
 */
void test_pointer_return() {

    fputs("Test pointer return:\n", stdout);

    // The character array (including new line and null termination character).
    void* c = NULL_POINTER;
    int* cs = INTEGER_NULL_POINTER;

    // Create character array.
    c = (void*) "Hello World!";
    create_integer((void*) &cs);
    *cs = 13;

    // THIS is the important part of the test.
    // A simple null pointer can be declared and passed to a procedure (as reference &).
    // The procedure can then dereference the pointer (*parameter) and store the result.
    // Since this works, one can avoid allocating extra local result variables,
    // and use just a null pointer to initialize the result variable.

    // The result array.
    void* r = NULL_POINTER;

    // Get character from character array.
    get_array_elements(c, (void*) SIX_NUMBER, (void*) &r, (void*) CHARACTER_ARRAY);

    // Print result (character array).
    fprintf(stderr, "r: %s\n", (char*) r);

    // Destroy character array.
    destroy_integer((void*) &cs);
}

/**
 * Tests the pointer array.
 */
void test_pointer_array() {

    fputs("Test pointer array:\n", stdout);

    //
    // Creation.
    //

    // The character array (including new line and null termination character).
    void* c = (void*) "Hello World!";
    int cs = 13;

    fprintf(stderr, "c: %s\n", (char*) c);

    // The pointer array.
    void** p = POINTER_NULL_POINTER;
    int ps = 1;

    // Create pointer array.
    create_array((void*) &p, (void*) &ps, (void*) POINTER_ARRAY);

    fprintf(stderr, "p: %i\n", p);

    // The result array.
    void** r = NULL_POINTER;

    //
    // Testing.
    //

    fprintf(stderr, "p[0] before set: %i\n", p[0]);
    fprintf(stderr, "p[1] before set: %i\n", p[1]);

    // Set character array in pointer array.
    // Hand over character array as reference, because pointer array is expected!
    set_array_elements(p, (void*) ZERO_NUMBER, (void*) &c, (void*) ONE_NUMBER, (void*) POINTER_ARRAY);

    fprintf(stderr, "p[0] after set: %i\n", p[0]);
    fprintf(stderr, "p[1] after set: %i\n", p[1]);

    // Get character array from pointer array.
    get_array_elements(p, (void*) ZERO_NUMBER, (void*) &r, (void*) POINTER_ARRAY);

    // Print result (character array).
    fprintf(stderr, "r pointer: %i\n", *r);
    fprintf(stderr, "r string: %s\n", (char*) *r);

    //
    // Destruction.
    //

    // Destroy pointer array.
    destroy_array((void*) &p, (void*) &ps, (void*) POINTER_ARRAY);
}

/**
 * Tests the file read.
 */
void test_file_read() {

    fputs("Test file read:\n", stdout);

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

    fputs("Test file write:\n", stdout);

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

    fputs("Test console:\n", stdout);

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

    fputs("Test integer parser:\n", stdout);

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

    fputs("Test knowledge model:\n", stdout);

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

//??    test_stdout_stderr();
//??    test_character_array_with_termination();
//??    test_pointer_cast();
//??    test_character_array_single_element();
//??    test_character_array_multiple_elements();
//??    test_pointer_return();
    test_pointer_array();
//??    test_file_read();
//??    test_file_write();
//??    test_console();
//??    test_integer_parser();
}

/* TEST_SOURCE */
#endif
