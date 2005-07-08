/*
 * $RCSfile: tester.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * This is the main testing file.
 *
 * From here all tests can be activated or deactivated.
 *
 * @version $Revision: 1.3 $ $Date: 2005-07-08 16:24:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <stdio.h>
#include "../controller/converter/converter.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/variables/variables.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array/array.c"
#include "../memoriser/creator/integer_creator.c"

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

    set_character_array_elements(c, (void*) ZERO_INTEGER, (void*) LATIN_CAPITAL_LETTER_A_CHARACTER, (void*) LATIN_CAPITAL_LETTER_A_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) ONE_INTEGER, (void*) LATIN_CAPITAL_LETTER_B_CHARACTER, (void*) LATIN_CAPITAL_LETTER_B_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) TWO_INTEGER, (void*) LATIN_CAPITAL_LETTER_C_CHARACTER, (void*) LATIN_CAPITAL_LETTER_C_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) THREE_INTEGER, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) LINE_FEED_CONTROL_CHARACTER_COUNT);
    set_character_array_elements(c, (void*) FOUR_INTEGER, (void*) NULL_CONTROL_CHARACTER, (void*) NULL_CONTROL_CHARACTER_COUNT);

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
    set_character_array_elements(d, (void*) ZERO_INTEGER, (void*) s, (void*) ss);

    fputs((char*) d, stdout);

    // The source array for overwriting.
    char oa[] = {'o', 'v', 'e', 'r', 'w', 'r', 'i', 't', 't', 'e', 'n', '.', '\n', '\0'};
    char* os = oa;
    int ossa[] = {14};
    int* oss = ossa;

    set_character_array_elements(d, (void*) EIGHT_INTEGER, (void*) os, (void*) oss);

    fputs((char*) d, stdout);

    // The remove index.
    int ri = 12;

    remove_character_array_elements(d, (void*) &ds, (void*) &ri, (void*) SEVEN_INTEGER);

    fputs((char*) d, stdout);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = 15;

    resize_array((void*) &d, (void*) &ns, (void*) CHARACTER_ARRAY);

    fputs((char*) d, stdout);

    // The result array.
    void* r = NULL_POINTER;

    // Test getting a reference.
    get_character_array_elements(d, (void*) EIGHT_INTEGER, (void*) &r);

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
    get_array_elements(c, (void*) SIX_INTEGER, (void*) &r, (void*) CHARACTER_ARRAY);

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
    set_array_elements(p, (void*) ZERO_INTEGER, (void*) &c, (void*) ONE_INTEGER, (void*) POINTER_ARRAY);

    fprintf(stderr, "p[0] after set: %i\n", p[0]);
    fprintf(stderr, "p[1] after set: %i\n", p[1]);

    // Get character array from pointer array.
    get_array_elements(p, (void*) ZERO_INTEGER, (void*) &r, (void*) POINTER_ARRAY);

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

        get_array_elements((void*) &a, (void*) CHARACTER_ARRAY, (void*) &j, (void*) &c, (void*) &cc);
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
 * @param level the level for the tree
 */
void test_knowledge_model(const void* p0, const void* p1, int level) {

    fputs("Test knowledge model:\n", stdout);

    char prefix[level * 3 + 1];
    int level_count;
    int char_count;

    for (level_count = 0; level_count < level; level_count++) {

        for (char_count = 0; char_count <= 2; char_count++) {

            prefix[level_count * 3 + char_count] = '_';
        }
    }

    prefix[level * 3] = '\0';
    level++;

    if (p1 != NULL_POINTER) {

        int* c = (int*) p1;

        // The loop index.
        int i = 0;
        // The element name.
        void** n = POINTER_NULL_POINTER;
        void** nc = POINTER_NULL_POINTER;
        void** ns = POINTER_NULL_POINTER;
        // The element abstraction.
        void** a = POINTER_NULL_POINTER;
        void** ac = POINTER_NULL_POINTER;
        void** as = POINTER_NULL_POINTER;
        // The element model.
        void** m = POINTER_NULL_POINTER;
        void** mc = POINTER_NULL_POINTER;
        void** ms = POINTER_NULL_POINTER;
        // The element details.
        void** d = POINTER_NULL_POINTER;
        void** dc = POINTER_NULL_POINTER;
        void** ds = POINTER_NULL_POINTER;
        // The comparison result.
        int r = 0;

        while (1) {

            if (i >= *c) {

                break;
            }

            // Get element name.
            get_compound_element_name_by_index(p0, p1, (void*) &i,
                (void*) &n, (void*) &nc, (void*) &ns);

            // Get element.
            get_compound_element_by_index(p0, p1, (void*) &i,
                (void*) &a, (void*) &ac, (void*) &as,
                (void*) &m, (void*) &mc, (void*) &ms,
                (void*) &d, (void*) &dc, (void*) &ds);

            // Print element name.
            fprintf(stderr, "name:              %s%s\n", prefix, *n);
            fprintf(stderr, "name count:        %s%i\n", prefix, **((int**) nc));
            fprintf(stderr, "name size:         %s%i\n", prefix, **((int**) ns));

            // Print element abstraction.
            fprintf(stderr, "abstraction:       %s%s\n", prefix, *a);
            fprintf(stderr, "abstraction count: %s%i\n", prefix, **((int**) ac));
            fprintf(stderr, "abstraction size:  %s%i\n", prefix, **((int**) as));

            // Handle element model.
            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) COMPOUND_ABSTRACTION, (void*) COMPOUND_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (compound): %s\n", "hierarchical, see below");
                    test_knowledge_model((void*) *m, (void*) *mc, level);
                }
            }

            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) OPERATION_ABSTRACTION, (void*) OPERATION_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (operation):         %s\n", (char*) *m);
                    fprintf(stderr, "model (operation) count:   %i\n", **((int**) mc));
                    fprintf(stderr, "model (operation) size:    %i\n", **((int**) ms));
                }
            }

            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (string):             %s\n", (char*) *m);
                    fprintf(stderr, "model (string) count:       %i\n", **((int**) mc));
                    fprintf(stderr, "model (string) size:        %i\n", **((int**) ms));
                }
            }

            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) INTEGER_ABSTRACTION, (void*) INTEGER_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (integer):            %i\n", **((int**) m));
                }
            }

            // Handle element details.
            if (d != NULL_POINTER) {

                fprintf(stderr, "details: %s\n", "hierarchical, see below");
                test_knowledge_model((void*) *d, (void*) *dc, level);
            }

            // Reset element name.
            n = POINTER_NULL_POINTER;
            nc = POINTER_NULL_POINTER;
            ns = POINTER_NULL_POINTER;
            // Reset element abstraction.
            a = POINTER_NULL_POINTER;
            ac = POINTER_NULL_POINTER;
            as = POINTER_NULL_POINTER;
            // Reset element model.
            m = POINTER_NULL_POINTER;
            mc = POINTER_NULL_POINTER;
            ms = POINTER_NULL_POINTER;
            // Reset element details.
            d = POINTER_NULL_POINTER;
            dc = POINTER_NULL_POINTER;
            ds = POINTER_NULL_POINTER;
            // Reset comparison result.
            r = 0;

            i++;
        }

    } else {

        fputs("ERROR: Could not test knowledge model. The knowledge model is null.", stdout);
    }
}

/**
 * Tests the compound.
 *
 * @param p0 the compound
 * @param p1 the compound count
 * @param p2 the index
 */
void test_compound(void* comp, int* comp_count, int* index) {

    void** n = POINTER_NULL_POINTER;
    void** nc = POINTER_NULL_POINTER;
    void** ns = POINTER_NULL_POINTER;
    void** a = POINTER_NULL_POINTER;
    void** ac = POINTER_NULL_POINTER;
    void** as = POINTER_NULL_POINTER;
    void** m = POINTER_NULL_POINTER;
    void** mc = POINTER_NULL_POINTER;
    void** ms = POINTER_NULL_POINTER;
    void** d = POINTER_NULL_POINTER;
    void** dc = POINTER_NULL_POINTER;
    void** ds = POINTER_NULL_POINTER;

    get_compound_element_name_by_index(comp, comp_count, index,
        &n, &nc, &ns);
    get_compound_element_by_index(comp, comp_count, index,
        &a, &ac, &as, &m, &mc, &ms, &d, &dc, &ds);

    fprintf(stderr, "compound name:              %s\n", (char*) *n);
    fprintf(stderr, "compound name count:        %i\n", *((int*) *nc));
    fprintf(stderr, "compound abstraction:       %s\n", (char*) *a);
    fprintf(stderr, "compound abstraction count: %i\n", *((int*) *ac));
    fprintf(stderr, "compound model:             %s\n", (char*) *m);
    fprintf(stderr, "compound model count:       %i\n", *((int*) *mc));
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
