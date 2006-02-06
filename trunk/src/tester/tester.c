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
 * @version $Revision: 1.19 $ $Date: 2006-02-06 23:41:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <locale.h>
#include <stdio.h>
#include <termios.h>
#include <wchar.h>
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/variables/variables.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/array.c"
#include "../memoriser/converter.c"

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
 * Tests the wide character output on linux console,
 * in between escape control sequences.
 */
void test_wide_character_output() {

    fputs("Test wide character array with termination:\n", stdout);

    // Possible locales are: LANG, LC_CTYPE, LC_ALL.
    // CAUTION! This setting is necessary for UTF-8 Unicode characters to work.
    char* loc = setlocale(LC_ALL, "");

    // The terminal (device name).
    FILE* t = NULL_POINTER;
    // The original termios interface.
    struct termios* to = NULL_POINTER;
    // The working termios interface.
    struct termios* tw = NULL_POINTER;

    // Create linux console internals.
//??        allocate((void*) &t, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    to = (struct termios*) malloc(sizeof(struct termios));
    tw = (struct termios*) malloc(sizeof(struct termios));

    // Initialise linux console internals.
    // Set file stream.
    // CAUTION! Possibly, stdin must be used instead of stdout here!
    t = stdout;

    // Get file descriptor for file stream.
    int d = fileno(t);
    // Copy termios attributes from file descriptor.
    tcgetattr(d, (void*) to);
    tcgetattr(d, (void*) tw);
    // Manipulate termios attributes.
    tw->c_lflag &= ~ICANON;
    tw->c_lflag &= ~ECHO;
    // Set termios attributes.
    tcsetattr(d, TCSANOW, (void*) tw);

    // The terminated control sequences string.
    void* ts = NULL_POINTER;
    int tsc = 0;
    int tss = 100;

    // Create terminated control sequences string.
    allocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY);

    // Set terminated control sequences string by first copying the actual
    // control sequences and then adding the null termination character.
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;

    // Write to terminal.
    fprintf(t, "%ls", (wchar_t*) ts);
//??    fputws((wchar_t*) ts, t);

    // Destroy terminated control sequences.
    deallocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY);

    // UTF-8 still allows you to use C1 control characters such as CSI, even
    // though UTF-8 also uses bytes in the range 0x80-0x9F. It is important to
    // understand that a terminal emulator in UTF-8 mode must apply the UTF-8
    // decoder to the incoming byte stream before interpreting any control
    // characters. C1 characters are UTF-8 decoded just like any other character
    // above U+007F.
    // VT100 terminal emulators accept ISO 2022 (=ECMA-35) ESC sequences in
    // order to switch between different character sets.

/*??
    char c = 67;

    if (c < 0x80) {

        putchar(c);

    } else if (c < 0x800) {

        putchar(0xC0 | c >> 6);
        putchar(0x80 | c & 0x3F);

    } else if (c < 0x10000) {

        putchar(0xE0 | c >> 12);
        putchar(0x80 | c >> 6 & 0x3F);
        putchar(0x80 | c & 0x3F);

    } else if (c < 0x200000) {

        putchar(0xF0 | c >> 18);
        putchar(0x80 | c >> 12 & 0x3F);
        putchar(0x80 | c >> 6 & 0x3F);
        putchar(0x80 | c & 0x3F);
    }
*/

/*??
    wchar_t c = 9584;
    char new = 65;

    if (c < 0x80) {

        new = (char) c;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;

    } else if (c < 0x800) {

        new = 0xC0 | c >> 6;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
        new = 0x80 | c & 0x3F;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;

    } else if (c < 0x10000) {

        new = 0xE0 | c >> 12;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
        new = 0x80 | c >> 6 & 0x3F;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
        new = 0x80 | c & 0x3F;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;

    } else if (c < 0x200000) {

        new = 0xF0 | c >> 18;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
        new = 0x80 | c >> 12 & 0x3F;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
        new = 0x80 | c >> 6 & 0x3F;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
        new = 0x80 | c & 0x3F;
        set_array_elements(ts, &tsc, (void*) &new, (void*) PRIMITIVE_COUNT, (void*) CHARACTER_ARRAY);
        tsc++;
    }
*/

/*??
    A function to convert a multibyte string into a wide character string and
    display it could be written like this (this is not a really useful example):

    void showmbs(const char *src, FILE *fp) {

        mbstate_t state;
        int cnt = 0;
        memset (state, '\0', sizeof (state));

        while (1) {

            wchar_t linebuf[100];
            const char *endp = strchr (src, '\n');
            size_t n;

            // Exit if there is no more line.
            if (endp == NULL)
                break;

            n = mbsnrtowcs(linebuf, src, endp - src, 99, state);
            linebuf[n] = L'\0';
            fprintf(fp, "line %d: \"%S\"\n", linebuf);
        }
    }
*/
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
    allocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);

    set_character_array_elements(c, (void*) NUMBER_0_INTEGER, (void*) LATIN_CAPITAL_LETTER_A_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_1_INTEGER, (void*) LATIN_CAPITAL_LETTER_B_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_2_INTEGER, (void*) LATIN_CAPITAL_LETTER_C_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_3_INTEGER, (void*) LINE_FEED_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_4_INTEGER, (void*) NULL_CONTROL_CHARACTER, (void*) PRIMITIVE_COUNT);

    // Print out array contents.
    fputs((char*) c, stdout);

    int i = 0;
    char* catest = NULL_POINTER;

    while (1) {

        if (i >= cs) {

            break;
        }

        catest = (char*) (c + i);
        fprintf(stderr, "ca: %c\n", *catest);

        i++;
    }

    // Destroy character array.
    deallocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);
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
    allocate_array((void*) &d, (void*) &ds, (void*) CHARACTER_ARRAY);

    // The source array.
    char a[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.', '\n', '\0'};
    char* s = a;
    int ssa[] = {17};
    int* ss = ssa;

    // The destination index to which to copy the source array.
    set_character_array_elements(d, (void*) NUMBER_0_INTEGER, (void*) s, (void*) ss);

    fputs((char*) d, stdout);

    // The source array for overwriting.
    char oa[] = {'o', 'v', 'e', 'r', 'w', 'r', 'i', 't', 't', 'e', 'n', '.', '\n', '\0'};
    char* os = oa;
    int ossa[] = {14};
    int* oss = ossa;

    set_character_array_elements(d, (void*) NUMBER_8_INTEGER, (void*) os, (void*) oss);

    fputs((char*) d, stdout);

    // The remove index.
    int ri = 12;

    remove_character_array_elements(d, (void*) &ds, (void*) &ri, (void*) NUMBER_7_INTEGER);

    fputs((char*) d, stdout);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = 15;

    reallocate_array((void*) &d, (void*) &ns, (void*) &ns, (void*) CHARACTER_ARRAY);

    fputs((char*) d, stdout);

    // The result array.
    void* r = NULL_POINTER;

    // Test getting a reference.
    get_character_array_elements(d, (void*) NUMBER_8_INTEGER, (void*) &r);

    fputs((char*) r, stdout);

    // Destroy destination array.
    deallocate_array((void*) &d, (void*) &ns, (void*) CHARACTER_ARRAY);
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
    int* cs = NULL_POINTER;

    // Create character array.
    c = (void*) "Hello World!";
    allocate((void*) &cs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *cs = 13;

    // THIS is the important part of the test.
    // A simple null pointer can be declared and passed to a procedure (as reference &).
    // The procedure can then dereference the pointer (*parameter) and store the result.
    // Since this works, one can avoid allocating extra local result variables,
    // and use just a null pointer to initialise the result variable.

    // The result array.
    void* r = NULL_POINTER;

    // Get character from character array.
    get_array_elements(c, (void*) NUMBER_6_INTEGER, (void*) &r, (void*) CHARACTER_ARRAY);

    // Print result (character array).
    fprintf(stderr, "r: %s\n", (char*) r);

    // Destroy character array.
    deallocate((void*) &cs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
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
    void** p = &NULL_POINTER;
    int ps = 1;

    // Create pointer array.
    allocate_array((void*) &p, (void*) &ps, (void*) POINTER_ARRAY);

    fprintf(stderr, "p: %i\n", p);

    // The result array.
    void** r = &NULL_POINTER;

    //
    // Testing.
    //

    fprintf(stderr, "p[0] before set: %i\n", p[0]);
    fprintf(stderr, "p[1] before set: %i\n", p[1]);

    // Set character array in pointer array.
    // Hand over character array as reference, because pointer array is expected!
    set_array_elements(p, (void*) NUMBER_0_INTEGER, (void*) &c, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

    fprintf(stderr, "p[0] after set: %i\n", p[0]);
    fprintf(stderr, "p[1] after set: %i\n", p[1]);

    // Get character array from pointer array.
    get_array_elements(p, (void*) NUMBER_0_INTEGER, (void*) &r, (void*) POINTER_ARRAY);

    // Print result (character array).
    fprintf(stderr, "r pointer: %i\n", *r);
    fprintf(stderr, "r string: %s\n", (char*) *r);

    //
    // Destruction.
    //

    // Destroy pointer array.
    deallocate_array((void*) &p, (void*) &ps, (void*) POINTER_ARRAY);
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

    allocate_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
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

    deallocate_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
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
        (void*) &INTEGER_VECTOR_ABSTRACTION, (void*) &INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "Parsed source string results in destination integer: %i\n", di);

    // The source integer.
    int si = 1980;
    int sic = -1;

    // The destination string.
    char* ds = NULL_POINTER;
    int dsc = 0;
    int dss = 0;

    // Create destination string.
    allocate_array((void*) &ds, (void*) &CHARACTER_ARRAY, (void*) &dss);

    serialise((void*) &ds, (void*) &dsc, (void*) &dss, (void*) &si, (void*) &sic,
        (void*) &INTEGER_VECTOR_ABSTRACTION, (void*) &INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "Serialised source integer results in destination string: %s\n", ds);

    // Destroy destination string.
    deallocate_array((void*) &ds, (void*) &CHARACTER_ARRAY, (void*) &dss);
*/
}

/**
 * Tests the knowledge memory.
 *
 * The knowledge memory is the root of a compound (tree).
 * But also a part of the knowledge memory can be handed over,
 * in which case that part and its parts will be printed on screen.
 *
 * @param p0 the knowledge memory
 * @param p1 the knowledge memory count
 * @param p2 the tree depth to be displayed
 */
void test_knowledge_memory(void* p0, void* p1, int p2) {

    if (p1 != NULL_POINTER) {

        int* kc = (int*) p1;

        fputs("Test knowledge memory:\n", stdout);

        // Create prefix.
        char prefix[p2 * 2 + 1];
        int level_count;
        int char_count;

        // Add underscores to prefix.
        for (level_count = 0; level_count < p2; level_count++) {

            for (char_count = 0; char_count <= 2; char_count++) {

                prefix[level_count * 3 + char_count] = '_';
            }
        }

        // Terminate prefix.
        prefix[p2 * 2] = '\0';
        p2++;

        // The loop index.
        int i = 0;
        // The element name.
        void** n = &NULL_POINTER;
        void** nc = &NULL_POINTER;
        void** ns = &NULL_POINTER;
        // The element abstraction.
        void** a = &NULL_POINTER;
        void** ac = &NULL_POINTER;
        void** as = &NULL_POINTER;
        // The element model.
        void** m = &NULL_POINTER;
        void** mc = &NULL_POINTER;
        void** ms = &NULL_POINTER;
        // The element details.
        void** d = &NULL_POINTER;
        void** dc = &NULL_POINTER;
        void** ds = &NULL_POINTER;
        // The comparison result.
        int r = 0;

        while (1) {

            if (i >= *kc) {

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
                    test_knowledge_memory((void*) *m, (void*) *mc, p2);
                }
            }

            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) CYBOL_ABSTRACTION, (void*) CYBOL_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (cybol): %s\n", "hierarchical, see below");
                    test_knowledge_memory((void*) *m, (void*) *mc, p2);
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

                compare_arrays((void*) *a, (void*) *ac, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (knowledge):             %s\n", (char*) *m);
                    fprintf(stderr, "model (knowledge) count:       %i\n", **((int**) mc));
                    fprintf(stderr, "model (knowledge) size:        %i\n", **((int**) ms));
                }
            }

            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (string):             %s\n", (char*) *m);
                    fprintf(stderr, "model (string) count:       %i\n", **((int**) mc));
                    fprintf(stderr, "model (string) size:        %i\n", **((int**) ms));
                }
            }

            if (r != 1) {

                compare_arrays((void*) *a, (void*) *ac, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

                if (r == 1) {

                    fprintf(stderr, "model (integer):            %i\n", **((int**) m));
                }
            }

            // Handle element details.
            if (d != NULL_POINTER) {

                fprintf(stderr, "details: %s\n", "hierarchical, see below");
                test_knowledge_memory((void*) *d, (void*) *dc, p2);
            }

            // Reset element name.
            n = &NULL_POINTER;
            nc = &NULL_POINTER;
            ns = &NULL_POINTER;
            // Reset element abstraction.
            a = &NULL_POINTER;
            ac = &NULL_POINTER;
            as = &NULL_POINTER;
            // Reset element model.
            m = &NULL_POINTER;
            mc = &NULL_POINTER;
            ms = &NULL_POINTER;
            // Reset element details.
            d = &NULL_POINTER;
            dc = &NULL_POINTER;
            ds = &NULL_POINTER;
            // Reset comparison result.
            r = 0;

            i++;
        }

    } else {

        fputs("ERROR: Could not test knowledge memory. The knowledge memory is null.\n", stdout);
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
    test_wide_character_output();
//??    test_pointer_cast();
//??    test_character_array_single_element();
//??    test_character_array_multiple_elements();
//??    test_pointer_return();
//??    test_pointer_array();
//??    test_file_read();
//??    test_file_write();
//??    test_console();
//??    test_integer_parser();
}

/* TEST_SOURCE */
#endif
