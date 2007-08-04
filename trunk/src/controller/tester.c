/*
 * $RCSfile: tester.c,v $
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
 * This is the main testing file.
 *
 * From here all tests can be activated or deactivated.
 *
 * @version $Revision: 1.9 $ $Date: 2007-08-04 23:24:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM
#include <termios.h>
/* GNU_LINUX_OPERATING_SYSTEM */
#endif

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

// The opengl library OpenGL32.
#include <GL/gl.h>
// The opengl utility library GLu32.
#include <GL/glu.h>
// The opengl tools library.
#include <GL/glut.h>
//?? Didier Link <didier@famille-link.fr> said that glut.h would suffice
//?? and freeglut.h would not be needed.
//?? #include <GL/freeglut.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include "../globals/constants/float/double_constants.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/character/wide_character_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/variables/variables.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/array.c"
#include "../memoriser/converter.c"
#include "../memoriser/converter/integer_converter.c"

/**
 * Tests the inline assembler code.
 */
void test_inline_assembler_code() {

    fputs("Test inline assembler code:\n", stdout);

    // Gegeben ist ein zusammenh�gender Block von Worten im RAM.
    // Die Startadresse des Blockes ist im Register ESI angegeben,
    // die Anzahl der Werte im Register ECX.
    // Schreiben Sie ein Programmstck, welches die Anzahl der Worte
    // in diesem Block z�lt, deren Wert gleich dem ist, welcher im
    // Register DI vorgegeben ist.
    // Das Ergebnis soll nach Abarbeitung des Programms im Register EAX stehen.
    //
    // - block of words in RAM
    // - ESI = start address
    // - ECX = number of values
    // - count number of words in RAM block with value == DI
    // - write result to EAX

/*??
            MOV EAX, 0; initial word count
            MOV EDX, 0; loop count
    loop:   CMP ECX, 0
            JZ end
            DEC ECX
            MOV EBX, [ESI + EDX * 2]
            CMP EBX, DI
            JNZ loop
            INC EAX
            JMP loop
    end:    NOP
*/
}

/**
 * Tests the preprocessor directives.
 */
void test_preprocessor_directives() {

    fputs("Test preprocessor directives:\n", stdout);

#ifdef GNU_LINUX_OPERATING_SYSTEM
    fputs("GNU_LINUX\n", stdout);
#elif WINDOWS_OPERATING_SYSTEM
    fputs("WINDOWS\n", stdout);
#else
    fputs("OTHER\n", stdout);
/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/**
 * Tests the standard output and error stream.
 */
void test_stdout_stderr() {

    fputs("Test stdout stderr:\n", stdout);

    fputs("test stdout ok\n", stdout);
    fputs("test stderr ok\n", stderr);
}

/**
 * Tests the integer array.
 */
void test_type_sizes() {

    fputs("Test type sizes:\n", stdout);

    fprintf(stderr, "null: %i\n", *NULL_POINTER);
    fprintf(stderr, "int size: %i\n", *INTEGER_PRIMITIVE_SIZE);
    fprintf(stderr, "char size: %i\n", *CHARACTER_PRIMITIVE_SIZE);
    fprintf(stderr, "wchar_t size: %i\n", *WIDE_CHARACTER_PRIMITIVE_SIZE);
    fprintf(stderr, "unsigned long size: %i\n", *UNSIGNED_LONG_PRIMITIVE_SIZE);
    fprintf(stderr, "void* size: %i\n", *POINTER_PRIMITIVE_SIZE);
    fprintf(stderr, "double size: %i\n", *DOUBLE_PRIMITIVE_SIZE);
}

/**
 * Tests the pointer addition.
 *
 * CAUTION! The following two lines calculate DIFFERENT results!
 * void* b = (void*) (m + (*NUMBER_0_INTEGER * *INTEGER_PRIMITIVE_SIZE));
 * void* b = (void*) m + (*NUMBER_0_INTEGER * *INTEGER_PRIMITIVE_SIZE);
 * The first line is wrong and adds 16 instead of just 4.
 * The problem are the parentheses.
 *
 * The following addition adds 8 instead of just 2.
 * int* m = (int*) *NULL_POINTER;
 * allocate((void*) &m, (void*) NUMBER_1_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
 * set_element(m, (void*) NUMBER_0_INTEGER, (void*) NUMBER_10_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
 * int* c = m + 2;
 * should be: = 10 + 2 = 12
 * but it is: = 10 + (2 * sizeof(int)) = 10 + 8 = 18
 */
void test_pointer_addition() {

    fputs("Test pointer addition:\n", stdout);

    // Allocate arrays of an arbitrary size.
    void* v = (void*) malloc(*NUMBER_10_INTEGER);
    int* i = (int*) malloc(*NUMBER_10_INTEGER);
    double* d = (double*) malloc(*NUMBER_10_INTEGER);
    char* c = (char*) malloc(*NUMBER_10_INTEGER);
    wchar_t* wc = (wchar_t*) malloc(*NUMBER_10_INTEGER);
    unsigned long* ul = (unsigned long*) malloc(*NUMBER_10_INTEGER);

    // Calculate void pointer addresses using various formulas and casts.
    void* v0 = v; // unchanged
    void* v1 = v + *NUMBER_1_INTEGER; // increased by 1
    void* v2 = (void*) v + *NUMBER_1_INTEGER; // increased by 1
    void* v3 = ((void*) v) + *NUMBER_1_INTEGER; // increased by 1
    void* v4 = (void*) (v + *NUMBER_1_INTEGER); // increased by 1
    void* v5 = (void*) v + *NUMBER_1_INTEGER; // increased by 1
    void* v6 = ((void*) v) + *NUMBER_1_INTEGER; // increased by 1
    void* v7 = (void*) (v + *NUMBER_1_INTEGER); // increased by 1

    fprintf(stderr, "void pointer v0: %i\n", v0);
    fprintf(stderr, "void pointer v1: %i\n", v1);
    fprintf(stderr, "void pointer v2: %i\n", v2);
    fprintf(stderr, "void pointer v3: %i\n", v3);
    fprintf(stderr, "void pointer v4: %i\n", v4);
    fprintf(stderr, "void pointer v5: %i\n", v5);
    fprintf(stderr, "void pointer v6: %i\n", v6);
    fprintf(stderr, "void pointer v7: %i\n", v7);

    // Calculate int pointer addresses using various formulas and casts.
    int* i0 = i; // unchanged
    int* i1 = i + *NUMBER_1_INTEGER; // increased by 4
    int* i2 = (int*) i + *NUMBER_1_INTEGER; // increased by 4
    int* i3 = ((int*) i) + *NUMBER_1_INTEGER; // increased by 4
    int* i4 = (int*) (i + *NUMBER_1_INTEGER); // increased by 4
    int* i5 = (void*) i + *NUMBER_1_INTEGER; // increased by 1
    int* i6 = ((void*) i) + *NUMBER_1_INTEGER; // increased by 1
    int* i7 = (void*) (i + *NUMBER_1_INTEGER); // increased by 4

    fprintf(stderr, "int pointer i0: %i\n", i0);
    fprintf(stderr, "int pointer i1: %i\n", i1);
    fprintf(stderr, "int pointer i2: %i\n", i2);
    fprintf(stderr, "int pointer i3: %i\n", i3);
    fprintf(stderr, "int pointer i4: %i\n", i4);
    fprintf(stderr, "int pointer i5: %i\n", i5);
    fprintf(stderr, "int pointer i6: %i\n", i6);
    fprintf(stderr, "int pointer i7: %i\n", i7);

    // Calculate double pointer addresses using various formulas and casts.
    double* d0 = d; // unchanged
    double* d1 = d + *NUMBER_1_INTEGER; // increased by 8
    double* d2 = (double*) d + *NUMBER_1_INTEGER; // increased by 8
    double* d3 = ((double*) d) + *NUMBER_1_INTEGER; // increased by 8
    double* d4 = (double*) (d + *NUMBER_1_INTEGER); // increased by 8
    double* d5 = (void*) d + *NUMBER_1_INTEGER; // increased by 1
    double* d6 = ((void*) d) + *NUMBER_1_INTEGER; // increased by 1
    double* d7 = (void*) (d + *NUMBER_1_INTEGER); // increased by 8

    fprintf(stderr, "double pointer d0: %i\n", d0);
    fprintf(stderr, "double pointer d1: %i\n", d1);
    fprintf(stderr, "double pointer d2: %i\n", d2);
    fprintf(stderr, "double pointer d3: %i\n", d3);
    fprintf(stderr, "double pointer d4: %i\n", d4);
    fprintf(stderr, "double pointer d5: %i\n", d5);
    fprintf(stderr, "double pointer d6: %i\n", d6);
    fprintf(stderr, "double pointer d7: %i\n", d7);

    // Calculate char pointer addresses using various formulas and casts.
    char* c0 = c; // unchanged
    char* c1 = c + *NUMBER_1_INTEGER; // increased by 1
    char* c2 = (char*) c + *NUMBER_1_INTEGER; // increased by 1
    char* c3 = ((char*) c) + *NUMBER_1_INTEGER; // increased by 1
    char* c4 = (char*) (c + *NUMBER_1_INTEGER); // increased by 1
    char* c5 = (void*) c + *NUMBER_1_INTEGER; // increased by 1
    char* c6 = ((void*) c) + *NUMBER_1_INTEGER; // increased by 1
    char* c7 = (void*) (c + *NUMBER_1_INTEGER); // increased by 1

    fprintf(stderr, "char pointer c0: %i\n", c0);
    fprintf(stderr, "char pointer c1: %i\n", c1);
    fprintf(stderr, "char pointer c2: %i\n", c2);
    fprintf(stderr, "char pointer c3: %i\n", c3);
    fprintf(stderr, "char pointer c4: %i\n", c4);
    fprintf(stderr, "char pointer c5: %i\n", c5);
    fprintf(stderr, "char pointer c6: %i\n", c6);
    fprintf(stderr, "char pointer c7: %i\n", c7);

    // Calculate wchar_t pointer addresses using various formulas and casts.
    wchar_t* wc0 = wc; // unchanged
    wchar_t* wc1 = wc + *NUMBER_1_INTEGER; // increased by 4
    wchar_t* wc2 = (wchar_t*) wc + *NUMBER_1_INTEGER; // increased by 4
    wchar_t* wc3 = ((wchar_t*) wc) + *NUMBER_1_INTEGER; // increased by 4
    wchar_t* wc4 = (wchar_t*) (wc + *NUMBER_1_INTEGER); // increased by 4
    wchar_t* wc5 = (void*) wc + *NUMBER_1_INTEGER; // increased by 1
    wchar_t* wc6 = ((void*) wc) + *NUMBER_1_INTEGER; // increased by 1
    wchar_t* wc7 = (void*) (wc + *NUMBER_1_INTEGER); // increased by 4

    fprintf(stderr, "wchar_t pointer wc0: %i\n", wc0);
    fprintf(stderr, "wchar_t pointer wc1: %i\n", wc1);
    fprintf(stderr, "wchar_t pointer wc2: %i\n", wc2);
    fprintf(stderr, "wchar_t pointer wc3: %i\n", wc3);
    fprintf(stderr, "wchar_t pointer wc4: %i\n", wc4);
    fprintf(stderr, "wchar_t pointer wc5: %i\n", wc5);
    fprintf(stderr, "wchar_t pointer wc6: %i\n", wc6);
    fprintf(stderr, "wchar_t pointer wc7: %i\n", wc7);

    // Calculate unsigned long pointer addresses using various formulas and casts.
    unsigned long* ul0 = ul; // unchanged
    unsigned long* ul1 = ul + *NUMBER_1_INTEGER; // increased by 4
    unsigned long* ul2 = (unsigned long*) ul + *NUMBER_1_INTEGER; // increased by 4
    unsigned long* ul3 = ((unsigned long*) ul) + *NUMBER_1_INTEGER; // increased by 4
    unsigned long* ul4 = (unsigned long*) (ul + *NUMBER_1_INTEGER); // increased by 4
    unsigned long* ul5 = (void*) ul + *NUMBER_1_INTEGER; // increased by 1
    unsigned long* ul6 = ((void*) ul) + *NUMBER_1_INTEGER; // increased by 1
    unsigned long* ul7 = (void*) (ul + *NUMBER_1_INTEGER); // increased by 4

    fprintf(stderr, "unsigned long pointer ul0: %i\n", ul0);
    fprintf(stderr, "unsigned long pointer ul1: %i\n", ul1);
    fprintf(stderr, "unsigned long pointer ul2: %i\n", ul2);
    fprintf(stderr, "unsigned long pointer ul3: %i\n", ul3);
    fprintf(stderr, "unsigned long pointer ul4: %i\n", ul4);
    fprintf(stderr, "unsigned long pointer ul5: %i\n", ul5);
    fprintf(stderr, "unsigned long pointer ul6: %i\n", ul6);
    fprintf(stderr, "unsigned long pointer ul7: %i\n", ul7);

    // Free arrays.
    free(v);
    free(i);
    free(d);
    free(c);
    free(wc);
    free(ul);
}

/**
 * Tests the integer array.
 */
void test_integer_array() {

    fputs("Test integer array:\n", stdout);

    // The test value.
    char* test = "2,3,4";
    int testc = *NUMBER_5_INTEGER;

    // The test knowledge model.
    int* m = (int*) *NULL_POINTER;
    int* mc = (int*) *NULL_POINTER;
    int* ms = (int*) *NULL_POINTER;

    // Allocate test knowledge model.
    allocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *mc = *NUMBER_0_INTEGER;
    allocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ms = *NUMBER_0_INTEGER;
    allocate((void*) &m, (void*) ms, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "pre mc: %i\n", *mc);
    fprintf(stderr, "pre ms: %i\n", *ms);
    fprintf(stderr, "pre m: %i\n", *m);

    //
    // Use either the "parse" function or the three "set" functions below.
    // Both possibilities should have the same functionality and results.
    //

/*??
    // Parse test value and assign to test knowledge model.
    parse((void*) &m, (void*) mc, (void*) ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
        (void*) test, (void*) &testc, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
*/

    // Set test values.
    set_element(m, (void*) NUMBER_0_INTEGER, (void*) NUMBER_2_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set_element(m, (void*) NUMBER_1_INTEGER, (void*) NUMBER_3_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set_element(m, (void*) NUMBER_2_INTEGER, (void*) NUMBER_4_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    // The result values read out from the integer vector.
    int* result0 = (int*) *NULL_POINTER;
    int* result1 = (int*) *NULL_POINTER;
    int* result2 = (int*) *NULL_POINTER;

    // Get result values.
    get_element(m, (void*) NUMBER_0_INTEGER, (void*) &result0, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(m, (void*) NUMBER_1_INTEGER, (void*) &result1, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(m, (void*) NUMBER_2_INTEGER, (void*) &result2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "post mc: %i\n", *mc);
    fprintf(stderr, "post ms: %i\n", *ms);
    fprintf(stderr, "post m: %i\n", *m);
    fprintf(stderr, "post result0: %i\n", *result0);
    fprintf(stderr, "post result1: %i\n", *result1);
    fprintf(stderr, "post result2: %i\n", *result2);

    // Deallocate test knowledge model.
    deallocate((void*) &m, (void*) ms, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
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
 * Tests the character array with termination.
 */
void test_array_resizing() {

    fputs("Test array resizing:\n", stdout);

    // The text.
    char ta[] = {'t', 'e', 's', 't', '\n', '\0'};
    char* t = ta;
    int* tc = NUMBER_6_INTEGER_ARRAY;

    // The original array.
    void* o = *NULL_POINTER;
    int oc = 0;
    int os = *tc;
    // The copied array.
    void* c = *NULL_POINTER;
    int cc = 0;
    int cs = 0;

    // Allocate original array.
    allocate_array((void*) &o, (void*) &os, (void*) CHARACTER_ARRAY);
    // Allocate copied array.
    allocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);

    // Fill original array with text.
    set_array_elements(o, (void*) &oc, (void*) t, (void*) tc, (void*) CHARACTER_ARRAY);
    oc = oc + *tc;

    // Print original array content.
    fputs(t, stdout);

    // Reallocate copied array.
    os = os + 10;
    reallocate_array((void*) &o, (void*) &oc, (void*) &os, (void*) CHARACTER_ARRAY);

    // Print original array content.
    fputs(t, stdout);

    // Deallocate original array.
    deallocate_array((void*) &o, (void*) &os, (void*) CHARACTER_ARRAY);
    // Deallocate copied array.
    deallocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);
}

/**
 * Tests the wide character output on gnu/linux console,
 * in between escape control sequences.
 */
void test_wide_character_output() {

    fputs("Test wide character array with termination:\n", stdout);

#ifdef GNU_LINUX_OPERATING_SYSTEM
    // Possible locales are: LANG, LC_CTYPE, LC_ALL.
    // CAUTION! This setting is necessary for UTF-8 Unicode characters to work.
    char* loc = setlocale(LC_ALL, "");

    // The terminal (device name).
    FILE* t = (FILE*) *NULL_POINTER;
    // The original termios interface.
    struct termios* to = (struct termios*) *NULL_POINTER;
    // The working termios interface.
    struct termios* tw = (struct termios*) *NULL_POINTER;

    // Create gnu/linux console internals.
//??        allocate((void*) &t, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    to = (struct termios*) malloc(sizeof(struct termios));
    tw = (struct termios*) malloc(sizeof(struct termios));

    // Initialise gnu/linux console internals.
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
    void* ts = *NULL_POINTER;
    int tsc = 0;
    int tss = 100;

    // Create terminated control sequences string.
    allocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY);

    // Set terminated control sequences string by first copying the actual
    // control sequences and then adding the null termination character.
    // (Termination character does not seem to be necessary for wide character strings.)
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;

    // printf("\033[32mgreen colour\033[0mswitched off.")

    // \033
    wchar_t wc = 0x001B;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    // [
    wc = 0x005B;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    // 3
    wc = 0x0033;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    // 2
    wc = 0x0032;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    // m
    wc = 0x006d;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;

    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY);
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
#endif
}

/**
 * Tests the integer-to-wide character conversion.
 */
void test_integer_to_wide_character_conversion() {

    fputs("Test integer-to-wide character conversion:\n", stdout);

    // The test wide character array.
    void* t = *NULL_POINTER;
    int tc = *NUMBER_0_INTEGER;
    // One byte for the wide character and another for the trailing null.
    size_t ts = *NUMBER_2_INTEGER;

    // Allocate test wide character array.
    allocate((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Transform source integer to destination string.
    // A null wide character is written to mark the end of the string.
    // The return value is the number of characters generated
    // for the given input, excluding the trailing null.
    // If not all output fits into the provided buffer,
    // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
    tc = wsprintfW((wchar_t*) t, L"%i", *NUMBER_2_INTEGER);
/* CYGWIN_ENVIRONMENT */
#else
    tc = swprintf((wchar_t*) t, ts, L"%i", *NUMBER_2_INTEGER);
/* CYGWIN_ENVIRONMENT */
#endif

    fprintf(stdout, "TEST tc %i\n", tc);

    // Deallocate test wide character array.
    deallocate((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the ascii character - wide character equality.
 */
void test_ascii_character_wide_character_equality() {

    fputs("Test ascii character - wide character equality:\n", stdout);

    char test = 'a';

    if (test = *LATIN_SMALL_LETTER_A_WIDE_CHARACTER) {

        fputs("Characters ARE equal.\n", stdout);

    } else {

        fputs("Characters are NOT equal.\n", stdout);
    }
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
    void* c = *NULL_POINTER;
    int cs = 5;

    // Create character array.
    allocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);

    set_character_array_elements(c, (void*) NUMBER_0_INTEGER, (void*) LATIN_CAPITAL_LETTER_A_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_1_INTEGER, (void*) LATIN_CAPITAL_LETTER_B_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_2_INTEGER, (void*) LATIN_CAPITAL_LETTER_C_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_3_INTEGER, (void*) LINE_FEED_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);
    set_character_array_elements(c, (void*) NUMBER_4_INTEGER, (void*) NULL_CONTROL_WIDE_CHARACTER, (void*) PRIMITIVE_COUNT);

    // Print out array contents.
    fputs((char*) c, stdout);

    int i = 0;
    char* catest = (char*) *NULL_POINTER;

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
    void* d = *NULL_POINTER;
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
    void* r = *NULL_POINTER;

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
    void* c = *NULL_POINTER;
    int* cs = (int*) *NULL_POINTER;

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
    void* r = *NULL_POINTER;

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
    void** p = NULL_POINTER;
    int ps = 1;

    // Create pointer array.
    allocate_array((void*) &p, (void*) &ps, (void*) POINTER_ARRAY);

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
 * Tests the pointer array with null values.
 */
void test_pointer_array_with_null_values() {

    fputs("Test pointer array with null values:\n", stdout);

    // The pointer array.
    void* a = *NULL_POINTER;
    int as = *NUMBER_5_INTEGER;

    allocate_pointer_array((void*) &a, (void*) &as);

    set_pointer_array_elements(a, (void*) NUMBER_0_INTEGER, (void*) &COMMERCIAL_AT_CHARACTER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_1_INTEGER, (void*) &NUMBER_333_INTEGER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_2_INTEGER, (void*) NULL_POINTER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_3_INTEGER, (void*) NULL_POINTER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_4_INTEGER, (void*) &COMMERCIAL_AT_CHARACTER, (void*) NUMBER_1_INTEGER);

    // The result values.
    char** r0 = (char**) NULL_POINTER;
    int** r1 = (int**) NULL_POINTER;
    void** r2 = (void**) NULL_POINTER;
    void* r3 = *NULL_POINTER;
    char** r4 = (char**) NULL_POINTER;

    get_pointer_array_elements(a, (void*) NUMBER_0_INTEGER, (void*) &r0);
    get_pointer_array_elements(a, (void*) NUMBER_1_INTEGER, (void*) &r1);
    get_pointer_array_elements(a, (void*) NUMBER_2_INTEGER, (void*) &r2);
    get_pointer_array_elements(a, (void*) NUMBER_3_INTEGER, (void*) &r3);
    get_pointer_array_elements(a, (void*) NUMBER_4_INTEGER, (void*) &r4);

    fprintf(stdout, "Result pointer as string r0: %s\n", *r0);
    fprintf(stdout, "Result pointer as integer r1: %i\n", **r1);
    fprintf(stdout, "Result pointer as pointer r2: %i\n", *r2);
    fprintf(stdout, "Result pointer as simple pointer r3: %i\n", r3);
    fprintf(stdout, "Result pointer as characterr4: %c\n", **r4);

    fprintf(stderr, "NULL_POINTER: %i \n", NULL_POINTER);
    fprintf(stderr, "*NULL_POINTER: %i \n", *NULL_POINTER);

    deallocate_pointer_array((void*) &a, (void*) &as);
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
    void* a = *NULL_POINTER;
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
    char* c = (char*) *NULL_POINTER;
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

//        // This is a gnu/linux console.
//        fputs("This is a gnu/linux console.\n", stdout);
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
 * Tests the mesa opengl library functionality.
 */
/*??
void test_mesa_opengl() {

    fputs("Test mesa opengl:\n", stdout);

    // This example will draw a green square on the screen.
    // OpenGL has several ways to accomplish this task, but this is the easiest to understand.

    // This statement clears the color buffer, so that the screen will start blank.
    glClear(GL_COLOR_BUFFER_BIT);

    // These statements initialize the projection matrix,
    // setting a 3d frustum matrix that represents the viewable area.
    // This matrix transforms objects from camera-relative space to OpenGL's projection space.
    glMatrixMode( GL_PROJECTION );      /* Subsequent matrix commands will affect the projection matrix */
/*??
    glLoadIdentity();                   /* Initialise the projection matrix to identity */
/*??
    glFrustum( -1, 1, -1, 1, 1, 1000 ); /* Apply a perspective-projection matrix */

    // These statements initialize the modelview matrix.
    // This matrix defines a transform from model-relative coordinates to camera space.
    // The combination of the modelview matrix and the projection matrix
    // transforms objects from model-relative space to projection screen space.
/*??
    glMatrixMode( GL_MODELVIEW );       /* Subsequent matrix commands will affect the modelview matrix */
/*??
    glLoadIdentity();                   /* Initialise the modelview to identity */
/*??
    glTranslatef( 0, 0, -3 );           /* Translate the modelview 3 units along the Z axis */

    // These commands draw a green square in the XY plane.
/*??
    glBegin( GL_POLYGON );              /* Begin issuing a polygon */
/*??
    glColor3f( 0, 1, 0 );               /* Set the current color to green */
/*??
    glVertex3f( -1, -1, 0 );            /* Issue a vertex */
/*??
    glVertex3f( -1, 1, 0 );             /* Issue a vertex */
/*??
    glVertex3f( 1, 1, 0 );              /* Issue a vertex */
/*??
    glVertex3f( 1, -1, 0 );             /* Issue a vertex */
/*??
    glEnd();                            /* Finish issuing the polygon */
//?? }

/**
 * Tests the parse integer vector function.
 */
void test_parse_integer_vector() {

    fputs("Test parse integer vector:\n", stdout);

    // The source character array.
    char sa[] = {'1', ',', '2', ',', '3', ',', '4', ',', '5'};
    void* s = sa;
    int sc = *NUMBER_5_INTEGER;

    // The destination integer vector.
    void* d = *NULL_POINTER;
    int dc = *NUMBER_0_INTEGER;
    int ds = *NUMBER_0_INTEGER;

    // Allocate integer vector.
    allocate((void*) &d, (void*) &ds, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    // Parse character array into integer vector.
    parse_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    // The integer values.
    int* i0 = (int*) *NULL_POINTER;
    int* i1 = (int*) *NULL_POINTER;
    int* i2 = (int*) *NULL_POINTER;

    // Get integer at index 0 from integer vector.
    get_element(d, (void*) NUMBER_0_INTEGER, (void*) &i0, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Get integer at index 1 from integer vector.
    get_element(d, (void*) NUMBER_1_INTEGER, (void*) &i1, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Get integer at index 2 from integer vector.
    get_element(d, (void*) NUMBER_2_INTEGER, (void*) &i2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fprintf(stderr, "Integer 0: %i\n", *i0);
    fprintf(stderr, "Integer 1: %i\n", *i1);
    fprintf(stderr, "Integer 2: %i\n", *i2);

    // Deallocate integer vector.
    deallocate((void*) &d, (void*) &ds, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the serialise integer vector function.
 */
void test_serialise_integer_vector() {

    fputs("Test serialise integer vector:\n", stdout);

    // The source integer array.
    int sa[] = {'1', '2', '3'};
    void* s = sa;
    int sc = *NUMBER_3_INTEGER;

    // The destination character array.
    char* d = (char*) *NULL_POINTER;
    int dc = *NUMBER_0_INTEGER;
    int ds = *NUMBER_0_INTEGER;

    // Allocate destination character vector.
    allocate((void*) &d, (void*) &ds, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    serialise_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    fprintf(stdout, "Serialised character array: %s\n", d);
    fprintf(stdout, "Serialised character array count: %i\n", dc);
    fprintf(stdout, "Serialised character array size: %i\n", ds);

    // Deallocate destination character vector.
    deallocate((void*) &d, (void*) &ds, (void*) CHARACTER_VECTOR_ABSTRACTION, (void*) CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the serialise integer function.
 */
void test_serialise_integer() {

    fputs("Test serialise integer:\n", stdout);

    // The destination character array.
    char* d = (char*) *NULL_POINTER;
    int dc = *NUMBER_0_INTEGER;
    int ds = *NUMBER_0_INTEGER;

    // An arbitrary source integer value.
    int s = *NUMBER_18_INTEGER;

    // Allocate destination character array.
    allocate_array((void*) &d, (void*) &ds, (void*) CHARACTER_ARRAY);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    serialise_integer((void*) &d, (void*) &dc, (void*) &ds, (void*) &s, (void*) PRIMITIVE_COUNT);

    fprintf(stdout, "Test: Destination character array: %s\n", d);
    fprintf(stdout, "Test: Destination character array count: %i\n", dc);
    fprintf(stdout, "Test: Destination character array size: %i\n", ds);

    // Deallocate destination character array.
    deallocate_array((void*) &d, (void*) &ds, (void*) CHARACTER_ARRAY);
}

/**
 * Tests the float constants.
 */
void test_float_constants() {

    fputs("Test float constants:\n", stdout);

    fprintf(stdout, "Test base of natural logarithms: %f\n", *E_DOUBLE);
    fprintf(stdout, "Test logarithm to base 2 of M_E: %f\n", *LOG_2_E_DOUBLE);
    fprintf(stdout, "Test logarithm to base 10 of M_E: %f\n", *LOG_10_E_DOUBLE);
    fprintf(stdout, "Test natural logarithm of 2: %f\n", *LN_2_DOUBLE);
    fprintf(stdout, "Test natural logarithm of 10: %f\n", *LN_10_DOUBLE);
    fprintf(stdout, "Test ratio of a circle's circumference to its diameter, called pi: %f\n", *PI_DOUBLE);
    fprintf(stdout, "Test pi divided by 2: %f\n", *PI_DIVIDED_BY_2_DOUBLE);
    fprintf(stdout, "Test pi divided by 4: %f\n", *PI_DIVIDED_BY_4_DOUBLE);
    fprintf(stdout, "Test reciprocal of pi (1/pi): %f\n", *RECIPROCAL_OF_PI_DOUBLE);
    fprintf(stdout, "Test two times the reciprocal of pi: %f\n", *TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE);
    fprintf(stdout, "Test two times the reciprocal of the square root of pi: %f\n", *TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE);
    fprintf(stdout, "Test square root of 2: %f\n", *SQUARE_ROOT_OF_2_DOUBLE);
    fprintf(stdout, "Test reciprocal of the square root of 2: %f\n", *RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE);
}

//?? ========================================================================================

void display(void) {

/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
 */
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();

/* don't wait!
 * start processing buffered OpenGL routines
 */
   glFlush ();
}

void init(void) {

/* select clearing color        */
   glClearColor(0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int test_mesa_opengl(int argc, char **argv) {

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (250, 250);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
}

//?? ========================================================================================

/**
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

    log_message_debug("Information: Test cyboi.");

    // How to use printf to check parameter values.
    // The printf function uses stdout for output, but nothing appears on console.
    // Therefore, fprintf is used and stderr is given for output.
    // Example:
    // int x = 2;
    // fprintf(stderr, "The value of x is: %d\n", x);

//??    test_inline_assembler_code();
//??    test_preprocessor_directives();
//??    test_stdout_stderr();
//??    test_type_sizes();
//??    test_pointer_addition();
    test_integer_array();
//??    test_character_array_with_termination();
//??    test_array_resizing();
//??    test_wide_character_output();
//??    test_integer_to_wide_character_conversion();
//??    test_ascii_character_wide_character_equality();
//??    test_pointer_cast();
//??    test_character_array_single_element();
//??    test_character_array_multiple_elements();
//??    test_pointer_return();
//??    test_pointer_array();
//??    test_pointer_array_with_null_values();
//??    test_file_read();
//??    test_file_write();
//??    test_console();
//??    test_mesa_opengl(*NUMBER_0_INTEGER, (char**) NULL_POINTER);
//??    test_parse_integer_vector();
//??    test_serialise_integer_vector();
//??    test_serialise_integer();
//??    test_float_constants();
}

/* TEST_SOURCE */
#endif
