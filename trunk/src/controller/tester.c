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
 * @version $RCSfile: tester.c,v $ $Revision: 1.24 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
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
//?? #include <GL/gl.h>
// The opengl utility library GLu32.
//?? #include <GL/glu.h>
// The opengl tools library.
//?? #include <GL/glut.h>
//?? Didier Link <didier@famille-link.fr> said that glut.h would suffice
//?? and freeglut.h would not be needed.
//?? #include <GL/freeglut.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include "../globals/constants/character/code/wide_character_code_constants.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/float/double_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../globals/variables/primitive_type_size_variables.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/allocator.c"
#include "../memoriser/array.c"
#include "../memoriser/converter.c"
#include "../memoriser/converter/integer_converter.c"

/**
 * Tests the logger.
 */
void test_logger() {

    log_write_terminated_message((void*) stdout, L"Test logger:\n");
    log_write_terminated_message((void*) stdout, L"CAUTION! A log level other than 'OFF' needs to be set for testing!\n");
    log_write_terminated_message((void*) stdout, L"For the logging test result, see the corresponding log file that was given as command line argument!\n");

    /** The log message as constant. */
    static wchar_t TEST_LOG_MESSAGE_ARRAY[] = {L'T', L'E', L'S', L'T', L' ', L'l', L'o', L'g', L' ', L'm', L'e', L's', L's', L'a', L'g', L'e', L'.'};
    static wchar_t* TEST_LOG_MESSAGE = TEST_LOG_MESSAGE_ARRAY;
    static int* TEST_LOG_MESSAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) TEST_LOG_MESSAGE, (void*) TEST_LOG_MESSAGE_COUNT);

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"TEST terminated log message.");
}

/**
 * Tests the inline assembler code.
 */
void test_inline_assembler_code() {

    log_write_terminated_message((void*) stdout, L"Test inline assembler code:\n");

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

    log_write_terminated_message((void*) stdout, L"Test preprocessor directives:\n");

#ifdef GNU_LINUX_OPERATING_SYSTEM
    log_write_terminated_message((void*) stdout, L"GNU_LINUX\n");
#elif WINDOWS_OPERATING_SYSTEM
    log_write_terminated_message((void*) stdout, L"WINDOWS\n");
#else
    log_write_terminated_message((void*) stdout, L"OTHER\n");
/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/**
 * Tests the standard output and error stream.
 */
void test_stdout_stderr() {

    log_write_terminated_message((void*) stdout, L"Test stdout stderr:\n");

    log_write_terminated_message((void*) stdout, L"test stdout ok\n");
    log_write_terminated_message((void*) stderr, L"test stderr ok\n");
}

/**
 * Tests the integer array.
 */
void test_type_sizes() {

    log_write_terminated_message((void*) stdout, L"Test type sizes:\n");

    fwprintf(stderr, L"null: %i\n", *NULL_POINTER_MEMORY_MODEL);
    fwprintf(stderr, L"int size: %i\n", *INTEGER_PRIMITIVE_SIZE);
    fwprintf(stderr, L"char size: %i\n", *CHARACTER_PRIMITIVE_SIZE);
    fwprintf(stderr, L"wchar_t size: %i\n", *WIDE_CHARACTER_PRIMITIVE_SIZE);
    fwprintf(stderr, L"unsigned long size: %i\n", *UNSIGNED_LONG_PRIMITIVE_SIZE);
    fwprintf(stderr, L"void* size: %i\n", *POINTER_PRIMITIVE_SIZE);
    fwprintf(stderr, L"double size: %i\n", *DOUBLE_PRIMITIVE_SIZE);
}

/**
 * Tests the pointer addition.
 *
 * CAUTION! The following two lines calculate DIFFERENT results!
 * void* b = (void*) (m + (*NUMBER_0_INTEGER_MEMORY_MODEL * *INTEGER_PRIMITIVE_SIZE));
 * void* b = (void*) m + (*NUMBER_0_INTEGER_MEMORY_MODEL * *INTEGER_PRIMITIVE_SIZE);
 * The first line is wrong and adds 16 instead of just 4.
 * The problem are the parentheses.
 *
 * The following addition adds 8 instead of just 2.
 * int* m = (int*) *NULL_POINTER_MEMORY_MODEL;
 * allocate((void*) &m, (void*) NUMBER_1_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
 * set_element(m, (void*) NUMBER_0_INTEGER, (void*) NUMBER_10_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
 * int* c = m + 2;
 * should be: = 10 + 2 = 12
 * but it is: = 10 + (2 * sizeof(int)) = 10 + 8 = 18
 */
void test_pointer_addition() {

    log_write_terminated_message((void*) stdout, L"Test pointer addition:\n");

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

    fwprintf(stderr, L"void pointer v0: %i\n", v0);
    fwprintf(stderr, L"void pointer v1: %i\n", v1);
    fwprintf(stderr, L"void pointer v2: %i\n", v2);
    fwprintf(stderr, L"void pointer v3: %i\n", v3);
    fwprintf(stderr, L"void pointer v4: %i\n", v4);
    fwprintf(stderr, L"void pointer v5: %i\n", v5);
    fwprintf(stderr, L"void pointer v6: %i\n", v6);
    fwprintf(stderr, L"void pointer v7: %i\n", v7);

    // Calculate int pointer addresses using various formulas and casts.
    int* i0 = i; // unchanged
    int* i1 = i + *NUMBER_1_INTEGER; // increased by 4
    int* i2 = (int*) i + *NUMBER_1_INTEGER; // increased by 4
    int* i3 = ((int*) i) + *NUMBER_1_INTEGER; // increased by 4
    int* i4 = (int*) (i + *NUMBER_1_INTEGER); // increased by 4
    int* i5 = (void*) i + *NUMBER_1_INTEGER; // increased by 1
    int* i6 = ((void*) i) + *NUMBER_1_INTEGER; // increased by 1
    int* i7 = (void*) (i + *NUMBER_1_INTEGER); // increased by 4

    fwprintf(stderr, L"int pointer i0: %i\n", i0);
    fwprintf(stderr, L"int pointer i1: %i\n", i1);
    fwprintf(stderr, L"int pointer i2: %i\n", i2);
    fwprintf(stderr, L"int pointer i3: %i\n", i3);
    fwprintf(stderr, L"int pointer i4: %i\n", i4);
    fwprintf(stderr, L"int pointer i5: %i\n", i5);
    fwprintf(stderr, L"int pointer i6: %i\n", i6);
    fwprintf(stderr, L"int pointer i7: %i\n", i7);

    // Calculate double pointer addresses using various formulas and casts.
    double* d0 = d; // unchanged
    double* d1 = d + *NUMBER_1_INTEGER; // increased by 8
    double* d2 = (double*) d + *NUMBER_1_INTEGER; // increased by 8
    double* d3 = ((double*) d) + *NUMBER_1_INTEGER; // increased by 8
    double* d4 = (double*) (d + *NUMBER_1_INTEGER); // increased by 8
    double* d5 = (void*) d + *NUMBER_1_INTEGER; // increased by 1
    double* d6 = ((void*) d) + *NUMBER_1_INTEGER; // increased by 1
    double* d7 = (void*) (d + *NUMBER_1_INTEGER); // increased by 8

    fwprintf(stderr, L"double pointer d0: %i\n", d0);
    fwprintf(stderr, L"double pointer d1: %i\n", d1);
    fwprintf(stderr, L"double pointer d2: %i\n", d2);
    fwprintf(stderr, L"double pointer d3: %i\n", d3);
    fwprintf(stderr, L"double pointer d4: %i\n", d4);
    fwprintf(stderr, L"double pointer d5: %i\n", d5);
    fwprintf(stderr, L"double pointer d6: %i\n", d6);
    fwprintf(stderr, L"double pointer d7: %i\n", d7);

    // Calculate char pointer addresses using various formulas and casts.
    char* c0 = c; // unchanged
    char* c1 = c + *NUMBER_1_INTEGER; // increased by 1
    char* c2 = (char*) c + *NUMBER_1_INTEGER; // increased by 1
    char* c3 = ((char*) c) + *NUMBER_1_INTEGER; // increased by 1
    char* c4 = (char*) (c + *NUMBER_1_INTEGER); // increased by 1
    char* c5 = (void*) c + *NUMBER_1_INTEGER; // increased by 1
    char* c6 = ((void*) c) + *NUMBER_1_INTEGER; // increased by 1
    char* c7 = (void*) (c + *NUMBER_1_INTEGER); // increased by 1

    fwprintf(stderr, L"char pointer c0: %i\n", c0);
    fwprintf(stderr, L"char pointer c1: %i\n", c1);
    fwprintf(stderr, L"char pointer c2: %i\n", c2);
    fwprintf(stderr, L"char pointer c3: %i\n", c3);
    fwprintf(stderr, L"char pointer c4: %i\n", c4);
    fwprintf(stderr, L"char pointer c5: %i\n", c5);
    fwprintf(stderr, L"char pointer c6: %i\n", c6);
    fwprintf(stderr, L"char pointer c7: %i\n", c7);

    // Calculate wchar_t pointer addresses using various formulas and casts.
    wchar_t* wc0 = wc; // unchanged
    wchar_t* wc1 = wc + *NUMBER_1_INTEGER; // increased by 4
    wchar_t* wc2 = (wchar_t*) wc + *NUMBER_1_INTEGER; // increased by 4
    wchar_t* wc3 = ((wchar_t*) wc) + *NUMBER_1_INTEGER; // increased by 4
    wchar_t* wc4 = (wchar_t*) (wc + *NUMBER_1_INTEGER); // increased by 4
    wchar_t* wc5 = (void*) wc + *NUMBER_1_INTEGER; // increased by 1
    wchar_t* wc6 = ((void*) wc) + *NUMBER_1_INTEGER; // increased by 1
    wchar_t* wc7 = (void*) (wc + *NUMBER_1_INTEGER); // increased by 4

    fwprintf(stderr, L"wchar_t pointer wc0: %i\n", wc0);
    fwprintf(stderr, L"wchar_t pointer wc1: %i\n", wc1);
    fwprintf(stderr, L"wchar_t pointer wc2: %i\n", wc2);
    fwprintf(stderr, L"wchar_t pointer wc3: %i\n", wc3);
    fwprintf(stderr, L"wchar_t pointer wc4: %i\n", wc4);
    fwprintf(stderr, L"wchar_t pointer wc5: %i\n", wc5);
    fwprintf(stderr, L"wchar_t pointer wc6: %i\n", wc6);
    fwprintf(stderr, L"wchar_t pointer wc7: %i\n", wc7);

    // Calculate unsigned long pointer addresses using various formulas and casts.
    unsigned long* ul0 = ul; // unchanged
    unsigned long* ul1 = ul + *NUMBER_1_INTEGER; // increased by 4
    unsigned long* ul2 = (unsigned long*) ul + *NUMBER_1_INTEGER; // increased by 4
    unsigned long* ul3 = ((unsigned long*) ul) + *NUMBER_1_INTEGER; // increased by 4
    unsigned long* ul4 = (unsigned long*) (ul + *NUMBER_1_INTEGER); // increased by 4
    unsigned long* ul5 = (void*) ul + *NUMBER_1_INTEGER; // increased by 1
    unsigned long* ul6 = ((void*) ul) + *NUMBER_1_INTEGER; // increased by 1
    unsigned long* ul7 = (void*) (ul + *NUMBER_1_INTEGER); // increased by 4

    fwprintf(stderr, L"unsigned long pointer ul0: %i\n", ul0);
    fwprintf(stderr, L"unsigned long pointer ul1: %i\n", ul1);
    fwprintf(stderr, L"unsigned long pointer ul2: %i\n", ul2);
    fwprintf(stderr, L"unsigned long pointer ul3: %i\n", ul3);
    fwprintf(stderr, L"unsigned long pointer ul4: %i\n", ul4);
    fwprintf(stderr, L"unsigned long pointer ul5: %i\n", ul5);
    fwprintf(stderr, L"unsigned long pointer ul6: %i\n", ul6);
    fwprintf(stderr, L"unsigned long pointer ul7: %i\n", ul7);

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

    log_write_terminated_message((void*) stdout, L"Test integer array:\n");

    // The test value.
    wchar_t* test = L"2,3,4";
    int testc = *NUMBER_5_INTEGER;

    // The test knowledge model.
    int* m = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* mc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ms = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Allocate test knowledge model.
    allocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    allocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
    allocate((void*) &m, (void*) ms, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"pre mc: %i\n", *mc);
    fwprintf(stderr, L"pre ms: %i\n", *ms);
    fwprintf(stderr, L"pre m: %i\n", *m);

    //
    // Use either the "decode" function or the three "set" functions below.
    // Both possibilities should have the same functionality and results.
    //

/*??
    // Decode (parse) test value and assign to test knowledge model.
    decode((void*) &m, (void*) mc, (void*) ms, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, (void*) test, (void*) &testc,
        *NULL_POINTER, *NULL_POINTER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
*/

    // Set test values.
    set_element(m, (void*) NUMBER_0_INTEGER, (void*) NUMBER_2_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set_element(m, (void*) NUMBER_1_INTEGER, (void*) NUMBER_3_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    set_element(m, (void*) NUMBER_2_INTEGER, (void*) NUMBER_4_INTEGER, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    // The result values read out from the integer vector.
    int* result0 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* result1 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* result2 = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Get result values.
    get_element(m, (void*) NUMBER_0_INTEGER, (void*) &result0, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(m, (void*) NUMBER_1_INTEGER, (void*) &result1, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    get_element(m, (void*) NUMBER_2_INTEGER, (void*) &result2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"post mc: %i\n", *mc);
    fwprintf(stderr, L"post ms: %i\n", *ms);
    fwprintf(stderr, L"post m: %i\n", *m);
    fwprintf(stderr, L"post result0: %i\n", *result0);
    fwprintf(stderr, L"post result1: %i\n", *result1);
    fwprintf(stderr, L"post result2: %i\n", *result2);

    // Deallocate test knowledge model.
    deallocate((void*) &m, (void*) ms, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &mc, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    deallocate((void*) &ms, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the character array with termination.
 */
void test_character_array_with_termination() {

    log_write_terminated_message((void*) stdout, L"Test character array with termination:\n");

    // The brackets indicating an array cannot be avoided or replaced by a pointer.
    // The following line does not work:
    // wchar_t* test = {L't', L'e', L's', L't', L'\n', L'\0'};

    // The '\n' character is a new line.
    // The character array (string) termination '\0' is necessary when using
    // GNU C library functions such as "fputs".
    wchar_t test[] = {L't', L'e', L's', L't', L' ', L'c', L'h', L'a', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'o', L'k', L'\n', L'\0'};

    log_write_terminated_message((void*) stdout, test);
}

/**
 * Tests the character array with termination.
 */
void test_array_resizing() {

    log_write_terminated_message((void*) stdout, L"Test array resizing:\n");

    // The text.
    wchar_t ta[] = {L't', L'e', L's', L't', L'\n', L'\0'};
    wchar_t* t = ta;
    int* tc = NUMBER_6_INTEGER_ARRAY;

    // The original array.
    void* o = *NULL_POINTER_MEMORY_MODEL;
    int oc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int os = *tc;
    // The copied array.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cs = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate original array.
    allocate_array((void*) &o, (void*) &os, (void*) CHARACTER_ARRAY);
    // Allocate copied array.
    allocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_ARRAY);

    // Fill original array with text.
    set_array_elements(o, (void*) &oc, (void*) t, (void*) tc, (void*) CHARACTER_ARRAY);
    oc = oc + *tc;

    // Print original array content.
    log_write_terminated_message((void*) stdout, t);

    // Reallocate copied array.
    os = os + *NUMBER_10_INTEGER;
    reallocate_array((void*) &o, (void*) &oc, (void*) &os, (void*) CHARACTER_ARRAY);

    // Print original array content.
    log_write_terminated_message((void*) stdout, t);

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

    log_write_terminated_message((void*) stdout, L"Test wide character array with termination:\n");

#ifdef GNU_LINUX_OPERATING_SYSTEM
    // Possible locales are: LANG, LC_CTYPE, LC_ALL.
    // CAUTION! This setting is necessary for UTF-8 Unicode characters to work.
    char* loc = setlocale(LC_ALL, "");

    // The terminal (device name).
    FILE* t = (FILE*) *NULL_POINTER_MEMORY_MODEL;
    // The original termios interface.
    struct termios* to = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
    // The working termios interface.
    struct termios* tw = (struct termios*) *NULL_POINTER_MEMORY_MODEL;

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
    void* ts = *NULL_POINTER_MEMORY_MODEL;
    int tsc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int tss = *NUMBER_1000_INTEGER;

    // Create terminated control sequences string.
    allocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Set terminated control sequences string by first copying the actual
    // control sequences and then adding the null termination character.
    // (Termination character does not seem to be necessary for wide character strings.)
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;

    wprintf(L"\033[32mgreen colour\033[0mswitched off.");

    // \033
    wchar_t wc = 0x001B;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    // [
    wc = 0x005B;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    // 3
    wc = 0x0033;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    // 2
    wc = 0x0032;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    // m
    wc = 0x006d;
    set_array_elements(ts, (void*) &tsc, (void*) &wc, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;

    set_array_elements(ts, (void*) &tsc, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;
    set_array_elements(ts, (void*) &tsc, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
    tsc++;

    // Write to terminal.
//??    fwprintf(t, L"%s\n", ts);
    fwprintf(t, L"%ls\n", (wchar_t*) ts);
//??    log_write_terminated_message((void*) stdout, (wchar_t*) ts, t);

    // Destroy terminated control sequences.
    deallocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

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
 * Tests the wide character output function "fwprintf".
 *
 * CAUTION! Some wide characters are not recognised by the gnu/linux console yet,
 * so that only question marks appear on the place of the corresponding character, e.g.:
 * - U+70BA CJK UNIFIED IDEOGRAPH-70BA 為
 * - U+256D BOX DRAWINGS LIGHT ARC DOWN AND RIGHT ╭
 *
 * The ASCII characters and the following wide characters are recognised properly:
 * - U+2500 BOX DRAWINGS LIGHT HORIZONTAL ─
 *
 * Results:
 * - if defining wide character array elements as symbol:
 *       use L before EACH single character to convert it into a wide character,
 *       since otherwise, it is interpreted as "normal" character and not displayed properly
 * - if defining wide character array elements as number/ code:
 *       use the UTF-16 encoding and NOT UTF-8, since UTF-8 may offer more than one number to be written
 *       and writing them one after the other into the array, separated by commata or not, brings wrong results
 * - a termination is NOT necessary for array definition, as the array count is given as usual in CYBOI
 * - the %s placeholder is not enough, since the wide character strings are not printed;
 *       a letter "l" HAS TO BE added to make output work, e.g.: %ls
 * - a cast to (wchar_t*) is NOT necessary, since the L before a string already does that
 *       and self-defined constants are of type wchar_t anyway
 */
void test_wide_character_wprintf() {

    /** The test wide character string. */
//??    static wchar_t TEST_WIDE_CHARACTER_STRING_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', 0xE7, 0x82, 0xBA, 'l', 'e'};
    static wchar_t TEST_WIDE_CHARACTER_STRING_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', 0xE2, 0x94, 0x80, 'l', 'e'};
    static wchar_t* TEST_WIDE_CHARACTER_STRING = TEST_WIDE_CHARACTER_STRING_ARRAY;

//??    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_TERMINATION_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', '為', 'l', 'e', '\0'};
    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_TERMINATION_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', '─', 'l', 'e', '\0'};
    static wchar_t* TEST_WIDE_CHARACTER_STRING_WITH_TERMINATION = TEST_WIDE_CHARACTER_STRING_WITH_TERMINATION_ARRAY;

//??    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_L_ARRAY[] = {L'r', L'e', L'c', L't', L'a', L'n', L'為', L'l', L'e'};
    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_L_ARRAY[] = {L'r', L'e', L'c', L't', L'a', L'n', L'─', L'l', L'e'};
    static wchar_t* TEST_WIDE_CHARACTER_STRING_WITH_L = TEST_WIDE_CHARACTER_STRING_WITH_L_ARRAY;

//??    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_L_AND_TERMINATION_ARRAY[] = {L'r', L'e', L'c', L't', L'a', L'n', L'為', L'l', L'e', 0x0000};
    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_L_AND_TERMINATION_ARRAY[] = {L'r', L'e', L'c', L't', L'a', L'n', L'─', L'l', L'e', 0x0000};
    static wchar_t* TEST_WIDE_CHARACTER_STRING_WITH_L_AND_TERMINATION = TEST_WIDE_CHARACTER_STRING_WITH_L_AND_TERMINATION_ARRAY;

//??    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION_ARRAY[] = {0x0072, 0x0065, 0x0063, 0x0074, 0x0061, 0x006E, 0xE7, 0x82, 0xBA, 0x006C, 0x0065, 0x0000};
    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION_ARRAY[] = {0x0072, 0x0065, 0x0063, 0x0074, 0x0061, 0x006E, 0xE2, 0x94, 0x80, 0x006C, 0x0065, 0x0000};
    static wchar_t* TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION = TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION_ARRAY;

//??    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION_ARRAY[] = {0x0072, 0x0065, 0x0063, 0x0074, 0x0061, 0x006E, 0x70BA, 0x006C, 0x0065, 0x0000};
    static wchar_t TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION_ARRAY[] = {0x0072, 0x0065, 0x0063, 0x0074, 0x0061, 0x006E, 0x2500, 0x006C, 0x0065, 0x0000};
    static wchar_t* TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION = TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION_ARRAY;

    // Set stream orientation to wide character mode.
    // The second function argument has the following meaning:
    // - positive value: wide character mode
    // - negative value: (narrow) character mode
    fwide(stdout, *NUMBER_1_INTEGER);

    log_write_terminated_message((void*) stdout, L"Test fputws.\n");
    log_write_terminated_message((void*) stdout, (wchar_t*) TEST_WIDE_CHARACTER_STRING);
    wprintf(L"Test wprintf without stream argument.\n");

    // Test wide character constants.
    fwprintf(stdout, L"Test hello world ls: %10ls \n", "hello world");
    fwprintf(stdout, L"Test hello world s: %10s \n", "hello world");
    fwprintf(stdout, L"Test hello world L ls with cast: %10ls \n", (wchar_t*) L"hello world");
    fwprintf(stdout, L"Test hello world L s with cast: %10s \n", (wchar_t*) L"hello world");
    fwprintf(stdout, L"Test hello world L ls without cast: %10ls\n", L"hello world");
    fwprintf(stdout, L"Test hello world L s without cast: %10s\n", L"hello world");

    fwprintf(stdout, L"Test wide character string ls: %5ls \n", TEST_WIDE_CHARACTER_STRING);
    fwprintf(stdout, L"Test wide character string s: %5s \n", TEST_WIDE_CHARACTER_STRING);
    fwprintf(stdout, L"Test wide character string with termination: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_TERMINATION);

    fwprintf(stdout, L"Test wide character string L ls: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_L);
    fwprintf(stdout, L"Test wide character string L s: %5s \n", TEST_WIDE_CHARACTER_STRING_WITH_L);
    fwprintf(stdout, L"Test wide character string L and termination: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_L_AND_TERMINATION);

    fwprintf(stdout, L"Test wide character string with UTF-8 codes and termination ls: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION);
    fwprintf(stdout, L"Test wide character string with UTF-8 codes and termination s: %5s \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION);
    fwprintf(stdout, L"Test wide character string with UTF-16 codes and termination ls: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION);
    fwprintf(stdout, L"Test wide character string with UTF-16 codes and termination s: %5s \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION);

    fwprintf(stdout, L"Test wide character string fourth letter with cast: %lc \n", (wchar_t*) TEST_WIDE_CHARACTER_STRING[3]);
    fwprintf(stdout, L"Test wide character string fourth letter without cast: %lc \n", TEST_WIDE_CHARACTER_STRING[3]);

    log_write_terminated_message((void*) stdout, L"Test END.\n");
}

/**
 * Tests the integer-to-wide character conversion.
 */
void test_integer_to_wide_character_conversion() {

    log_write_terminated_message((void*) stdout, L"Test integer-to-wide character conversion:\n");

    // The test wide character array.
    void* t = *NULL_POINTER_MEMORY_MODEL;
    int tc = *NUMBER_0_INTEGER_MEMORY_MODEL;
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

    fwprintf(stdout, L"TEST tc %i\n", tc);

    // Deallocate test wide character array.
    deallocate((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the ascii character - wide character equality.
 */
void test_ascii_character_wide_character_equality() {

    log_write_terminated_message((void*) stdout, L"Test ascii character - wide character equality:\n");

    char test = 'a';

    if (test = *LATIN_SMALL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL) {

        log_write_terminated_message((void*) stdout, L"Characters ARE equal.\n");

    } else {

        log_write_terminated_message((void*) stdout, L"Characters are NOT equal.\n");
    }
}

/**
 * Tests the pointer cast.
 */
void test_pointer_cast() {

    log_write_terminated_message((void*) stdout, L"Test pointer cast:\n");

    // Assign a test character array.
    wchar_t* test_char = L"test pointer cast ok\n";

    // The & operator makes a wchar_t** from wchar_t*, in other words a pointer pointer.
    // The wchar_t** is then casted to a normal void* which is used to hand
    // over parameters in all procedures of cyboi.
    void* test_void = (void*) &test_char;

    // The void* which was for example retrieved as parameter of a procedure
    // has to be casted back to the original wchar_t**.
    wchar_t** test_back = (wchar_t**) test_void;

    // The wchar_t** has to be dereferenced using the * operator,
    // because the fputs function expects a wchar_t*.
    log_write_terminated_message((void*) stdout, *test_back);
}

/**
 * Tests the character array with a single element.
 */
void test_character_array_single_element() {

    log_write_terminated_message((void*) stdout, L"Test character array single element:\n");

    // The character array.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    int cs = *NUMBER_5_INTEGER;

    // Create character array.
    allocate_array((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    set_wide_character_array_elements(c, (void*) NUMBER_0_INTEGER, (void*) LATIN_CAPITAL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT);
    set_wide_character_array_elements(c, (void*) NUMBER_1_INTEGER, (void*) LATIN_CAPITAL_LETTER_B_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT);
    set_wide_character_array_elements(c, (void*) NUMBER_2_INTEGER, (void*) LATIN_CAPITAL_LETTER_C_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT);
    set_wide_character_array_elements(c, (void*) NUMBER_3_INTEGER, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT);
    set_wide_character_array_elements(c, (void*) NUMBER_4_INTEGER, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_COUNT);

    // Print out array contents.
    log_write_terminated_message((void*) stdout, (wchar_t*) c);

    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
    wchar_t* catest = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER) {

        if (i >= cs) {

            break;
        }

        catest = (wchar_t*) (c + i);
        fwprintf(stderr, L"ca: %c\n", *catest);

        i++;
    }

    // Destroy character array.
    deallocate_array((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Tests the character array with multiple elements.
 */
void test_character_array_multiple_elements() {

    log_write_terminated_message((void*) stdout, L"Test character array multiple elements:\n");

    // The destination array.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    int ds = *NUMBER_22_INTEGER;

    // Create destination array.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // The source array.
    wchar_t a[] = {L'T', L'h', L'i', L's', L' ', L'i', L's', L' ', L'a', L' ', L't', L'e', L's', L't', L'.', L'\n', L'\0'};
    wchar_t* s = a;
    int ssa[] = {17};
    int* ss = ssa;

    // The destination index to which to copy the source array.
    set_wide_character_array_elements(d, (void*) NUMBER_0_INTEGER, (void*) s, (void*) ss);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The source array for overwriting.
    wchar_t oa[] = {L'o', L'v', L'e', L'r', L'w', L'r', L'i', L't', L't', L'e', L'n', L'.', L'\n', L'\0'};
    wchar_t* os = oa;
    int ossa[] = {14};
    int* oss = ossa;

    set_wide_character_array_elements(d, (void*) NUMBER_8_INTEGER, (void*) os, (void*) oss);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The remove index.
    int ri = *NUMBER_12_INTEGER;

    remove_character_array_elements(d, (void*) &ds, (void*) &ri, (void*) NUMBER_7_INTEGER);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = *NUMBER_15_INTEGER;

    reallocate_array((void*) &d, (void*) &ns, (void*) &ns, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The result array.
    void* r = *NULL_POINTER_MEMORY_MODEL;

    // Test getting a reference.
    get_wide_character_array_elements(d, (void*) NUMBER_8_INTEGER, (void*) &r);

    log_write_terminated_message((void*) stdout, (wchar_t*) r);

    // Destroy destination array.
    deallocate_array((void*) &d, (void*) &ns, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Tests the pointer return.
 *
 * In other words, if an array element is returned correctly,
 * when using a null pointer.
 */
void test_pointer_return() {

    log_write_terminated_message((void*) stdout, L"Test pointer return:\n");

    // The character array (including new line and null termination character).
    void* c = *NULL_POINTER_MEMORY_MODEL;
    int* cs = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Create character array.
    c = (void*) L"Hello World!";
    allocate((void*) &cs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    *cs = *NUMBER_13_INTEGER;

    // THIS is the important part of the test.
    // A simple null pointer can be declared and passed to a procedure (as reference &).
    // The procedure can then dereference the pointer (*parameter) and store the result.
    // Since this works, one can avoid allocating extra local result variables,
    // and use just a null pointer to initialise the result variable.

    // The result array.
    void* r = *NULL_POINTER_MEMORY_MODEL;

    // Get character from character array.
    get_array_elements(c, (void*) NUMBER_6_INTEGER, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Print result (character array).
    fwprintf(stderr, L"r: %ls\n", (wchar_t*) r);

    // Destroy character array.
    deallocate((void*) &cs, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the pointer array.
 */
void test_pointer_array() {

    log_write_terminated_message((void*) stdout, L"Test pointer array:\n");

    //
    // Creation.
    //

    // The character array (including new line and null termination character).
    void* c = (void*) L"Hello World!";
    int cs = *NUMBER_13_INTEGER;

    fwprintf(stderr, L"c: %ls\n", (wchar_t*) c);

    // The pointer array.
    void** p = NULL_POINTER;
    int ps = *NUMBER_1_INTEGER;

    // Create pointer array.
    allocate_array((void*) &p, (void*) &ps, (void*) POINTER_ARRAY);

    fwprintf(stderr, L"p: %i\n", p);

    // The result array.
    void** r = NULL_POINTER;

    //
    // Testing.
    //

    fwprintf(stderr, L"p[0] before set: %i\n", p[0]);
    fwprintf(stderr, L"p[1] before set: %i\n", p[1]);

    // Set character array in pointer array.
    // Hand over character array as reference, because pointer array is expected!
    set_array_elements(p, (void*) NUMBER_0_INTEGER, (void*) &c, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

    fwprintf(stderr, L"p[0] after set: %i\n", p[0]);
    fwprintf(stderr, L"p[1] after set: %i\n", p[1]);

    // Get character array from pointer array.
    get_array_elements(p, (void*) NUMBER_0_INTEGER, (void*) &r, (void*) POINTER_ARRAY);

    // Print result (character array).
    fwprintf(stderr, L"r pointer: %i\n", *r);
    fwprintf(stderr, L"r string: %ls\n", (wchar_t*) *r);

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

    log_write_terminated_message((void*) stdout, L"Test pointer array with null values:\n");

    // The pointer array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int as = *NUMBER_5_INTEGER;

    allocate_pointer_array((void*) &a, (void*) &as);

    set_pointer_array_elements(a, (void*) NUMBER_0_INTEGER, (void*) &COMMERCIAL_AT_CHARACTER_CODE, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_1_INTEGER, (void*) &NUMBER_333_INTEGER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_2_INTEGER, (void*) NULL_POINTER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_3_INTEGER, (void*) NULL_POINTER, (void*) NUMBER_1_INTEGER);
    set_pointer_array_elements(a, (void*) NUMBER_4_INTEGER, (void*) &COMMERCIAL_AT_CHARACTER_CODE, (void*) NUMBER_1_INTEGER);

    // The result values.
    char** r0 = (char**) NULL_POINTER;
    int** r1 = (int**) NULL_POINTER;
    void** r2 = (void**) NULL_POINTER;
    void* r3 = *NULL_POINTER_MEMORY_MODEL;
    char** r4 = (char**) NULL_POINTER;

    get_pointer_array_elements(a, (void*) NUMBER_0_INTEGER, (void*) &r0);
    get_pointer_array_elements(a, (void*) NUMBER_1_INTEGER, (void*) &r1);
    get_pointer_array_elements(a, (void*) NUMBER_2_INTEGER, (void*) &r2);
    get_pointer_array_elements(a, (void*) NUMBER_3_INTEGER, (void*) &r3);
    get_pointer_array_elements(a, (void*) NUMBER_4_INTEGER, (void*) &r4);

    fwprintf(stdout, L"Result pointer as string r0: %s\n", *r0);
    fwprintf(stdout, L"Result pointer as integer r1: %i\n", **r1);
    fwprintf(stdout, L"Result pointer as pointer r2: %i\n", *r2);
    fwprintf(stdout, L"Result pointer as simple pointer r3: %i\n", r3);
    fwprintf(stdout, L"Result pointer as character r4: %c\n", **r4);

    fwprintf(stderr, L"NULL_POINTER: %i \n", NULL_POINTER);
    fwprintf(stderr, L"*NULL_POINTER: %i \n", *NULL_POINTER_MEMORY_MODEL);

    deallocate_pointer_array((void*) &a, (void*) &as);
}

/**
 * Tests the file read.
 */
void test_file_read() {

    log_write_terminated_message((void*) stdout, L"Test file read:\n");

    // A file named "/home/cybop/tmp/test.cybol" needs to be created
    // in a text editor, for this test to work.

/*??
    // The array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The array size.
    int as = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The array count.
    int ac = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The file name array.
    char fna[] = {'/', 'h', 'o', 'm', 'e', '/', 'c', 'y', 'b', 'o', 'p', '/', 't', 'm', 'p', '/', 't', 'e', 's', 't', '.', 'c', 'y', 'b', 'o', 'l'};
    // The file name.
    char* fn = fna;
    // The file name count.
    int fnc = *NUMBER_26_INTEGER;

    allocate_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
//??    read_file((void*) &a, (void*) &as, (void*) &ac, (void*) &fn, (void*) &fnc);

    fwprintf(stderr, L"a: %i\n", a);
    fwprintf(stderr, L"as: %i\n", as);
    fwprintf(stderr, L"ac: %i\n", ac);
    fwprintf(stderr, L"fn: %i\n", fn);
    fwprintf(stderr, L"fnc: %i\n", fnc);

    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    char* c = (char*) *NULL_POINTER_MEMORY_MODEL;
    int* cc = *NUMBER_1_INTEGER;

    while (*NUMBER_1_INTEGER) {

        if (j >= ac) {

            break;
        }

        get_array_elements((void*) &a, (void*) CHARACTER_ARRAY, (void*) &j, (void*) &c, (void*) &cc);
        fputs(c);

        j++;
    }

    deallocate_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
*/
}

/**
 * Tests the file write.
 */
void test_file_write() {

    log_write_terminated_message((void*) stdout, L"Test file write:\n");

    // The character array.
    char aa[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\n'};
    // The array.
    void* a = aa;
    // The array size.
    int as = *NUMBER_14_INTEGER;
    // The array count.
    int ac = *NUMBER_14_INTEGER;
    // The file name array.
    char fna[] = {'/', 'h', 'o', 'm', 'e', '/', 'c', 'y', 'b', 'o', 'p', '/', 't', 'm', 'p', '/', 't', 'e', 's', 't', '.', 'c', 'y', 'b', 'o', 'l'};
    // The file name.
    char* fn = fna;
    // The file name count.
    int fnc = *NUMBER_26_INTEGER;

//??    write_file((void*) &a, (void*) &as, (void*) &ac, (void*) &fn, (void*) &fnc);
}

/**
 * Tests the console.
 */
void test_console() {

    log_write_terminated_message((void*) stdout, L"Test console:\n");

    if (strcmp("linux", getenv("TERM")) == *NUMBER_0_INTEGER_MEMORY_MODEL) {

//        // This is a gnu/linux console.
//        log_write_terminated_message((void*) stdout, L"This is a gnu/linux console.\n");
//
//        // Determine device name of controlling terminal.
//        int n = ttyname();
//        fwprintf(stdout, L"The terminal device name is: %i\n", n);
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
//        log_write_terminated_message((void*) stdout, L"This is a \033[1mbold\033[0m word.\n");
//
//        // Set colours.
//        // CAUTION! The "m" has to stand after the colour number
//        // and it must NOT be a capital letter.
//        log_write_terminated_message((void*) stdout, L"Set colour to \033[32mgreen\033[0m.\n");
//        log_write_terminated_message((void*) stdout, L"Set colour to \033[32myellow\041[0m.\n");
//        log_write_terminated_message((void*) stdout, L"Set colour to \033[32mred\031[0m.\n");

    } else {

        // This is a normal serial terminal.
        log_write_terminated_message((void*) stdout, L"This is a normal serial terminal.\n");
    }
}

/**
 * Tests the mesa opengl library functionality.
 */
/*??
void test_mesa_opengl() {

    log_write_terminated_message((void*) stdout, L"Test mesa opengl:\n");

    // This example will draw a green square on the screen.
    // OpenGL has several ways to accomplish this task, but this is the easiest to understand.

    // This statement clears the color buffer, so that the screen will start blank.
    glClear(GL_COLOR_BUFFER_BIT);

    // These statements initialize the projection matrix,
    // setting a 3d frustum matrix that represents the viewable area.
    // This matrix transforms objects from camera-relative space to OpenGL's projection space.
    glMatrixMode(GL_PROJECTION);      /* Subsequent matrix commands will affect the projection matrix */
/*??
    glLoadIdentity();                   /* Initialise the projection matrix to identity */
/*??
    glFrustum(-1, 1, -1, 1, 1, 1000); /* Apply a perspective-projection matrix */

    // These statements initialize the modelview matrix.
    // This matrix defines a transform from model-relative coordinates to camera space.
    // The combination of the modelview matrix and the projection matrix
    // transforms objects from model-relative space to projection screen space.
/*??
    glMatrixMode(GL_MODELVIEW);       /* Subsequent matrix commands will affect the modelview matrix */
/*??
    glLoadIdentity();                   /* Initialise the modelview to identity */
/*??
    glTranslatef(0, 0, -3);           /* Translate the modelview 3 units along the Z axis */

    // These commands draw a green square in the XY plane.
/*??
    glBegin(GL_POLYGON);              /* Begin issuing a polygon */
/*??
    glColor3f(0, 1, 0);               /* Set the current color to green */
/*??
    glVertex3f(-1, -1, 0);            /* Issue a vertex */
/*??
    glVertex3f(-1, 1, 0);             /* Issue a vertex */
/*??
    glVertex3f(1, 1, 0);              /* Issue a vertex */
/*??
    glVertex3f(1, -1, 0);             /* Issue a vertex */
/*??
    glEnd();                            /* Finish issuing the polygon */
//?? }

/**
 * Tests the decode integer vector function.
 */
void test_decode_integer_vector() {

    log_write_terminated_message((void*) stdout, L"Test decode integer vector:\n");

    // The source character array.
    wchar_t sa[] = {L'1', L',', L'2', L',', L'3', L',', L'4', L',', L'5'};
    void* s = sa;
    int sc = *NUMBER_5_INTEGER;

    // The destination integer vector.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate integer vector.
    allocate((void*) &d, (void*) &ds, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    // Decode character array into integer vector.
    decode_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    // The integer values.
    int* i0 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* i1 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* i2 = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Get integer at index 0 from integer vector.
    get_element(d, (void*) NUMBER_0_INTEGER, (void*) &i0, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Get integer at index 1 from integer vector.
    get_element(d, (void*) NUMBER_1_INTEGER, (void*) &i1, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
    // Get integer at index 2 from integer vector.
    get_element(d, (void*) NUMBER_2_INTEGER, (void*) &i2, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);

    fwprintf(stderr, L"Integer 0: %i\n", *i0);
    fwprintf(stderr, L"Integer 1: %i\n", *i1);
    fwprintf(stderr, L"Integer 2: %i\n", *i2);

    // Deallocate integer vector.
    deallocate((void*) &d, (void*) &ds, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the encode integer vector function.
 */
void test_encode_integer_vector() {

    log_write_terminated_message((void*) stdout, L"Test encode integer vector:\n");

    // The source integer array.
    //?? TODO: Shouldn't this be WITHOUT apostrophes, i.e.:
    //?? int sa[] = {1, 2, 3};
    int sa[] = {'1', '2', '3'};
    void* s = sa;
    int sc = *NUMBER_3_INTEGER;

    // The destination character array.
    wchar_t* d = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate destination character vector.
    allocate((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    encode_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    fwprintf(stdout, L"Encoded character array: %ls\n", d);
    fwprintf(stdout, L"Encoded character array count: %i\n", dc);
    fwprintf(stdout, L"Encoded character array size: %i\n", ds);

    // Deallocate destination character vector.
    deallocate((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION, (void*) WIDE_CHARACTER_VECTOR_ABSTRACTION_COUNT);
}

/**
 * Tests the encode integer function.
 */
void test_encode_integer() {

    log_write_terminated_message((void*) stdout, L"Test encode integer:\n");

    // The destination character array.
    wchar_t* d = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // An arbitrary source integer value.
    int s = *NUMBER_18_INTEGER;

    // Allocate destination character array.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    encode_integer((void*) &d, (void*) &dc, (void*) &ds, (void*) &s, (void*) PRIMITIVE_COUNT);

    fwprintf(stdout, L"Test: Destination character array: %ls\n", d);
    fwprintf(stdout, L"Test: Destination character array count: %i\n", dc);
    fwprintf(stdout, L"Test: Destination character array size: %i\n", ds);

    // Deallocate destination character array.
    deallocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);
}

/**
 * Tests the float constants.
 */
void test_float_constants() {

    log_write_terminated_message((void*) stdout, L"Test float constants:\n");

    fwprintf(stdout, L"Test base of natural logarithms: %f\n", *E_DOUBLE);
    fwprintf(stdout, L"Test logarithm to base 2 of M_E: %f\n", *LOG_2_E_DOUBLE);
    fwprintf(stdout, L"Test logarithm to base 10 of M_E: %f\n", *LOG_10_E_DOUBLE);
    fwprintf(stdout, L"Test natural logarithm of 2: %f\n", *LN_2_DOUBLE);
    fwprintf(stdout, L"Test natural logarithm of 10: %f\n", *LN_10_DOUBLE);
    fwprintf(stdout, L"Test ratio of a circle's circumference to its diameter, called pi: %f\n", *PI_DOUBLE);
    fwprintf(stdout, L"Test pi divided by 2: %f\n", *PI_DIVIDED_BY_2_DOUBLE);
    fwprintf(stdout, L"Test pi divided by 4: %f\n", *PI_DIVIDED_BY_4_DOUBLE);
    fwprintf(stdout, L"Test reciprocal of pi (1/pi): %f\n", *RECIPROCAL_OF_PI_DOUBLE);
    fwprintf(stdout, L"Test two times the reciprocal of pi: %f\n", *TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE);
    fwprintf(stdout, L"Test two times the reciprocal of the square root of pi: %f\n", *TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE);
    fwprintf(stdout, L"Test square root of 2: %f\n", *SQUARE_ROOT_OF_2_DOUBLE);
    fwprintf(stdout, L"Test reciprocal of the square root of 2: %f\n", *RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE);
}

//?? ========================================================================================

/*??
void display(void) {

    // clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    // draw white polygon (rectangle) with corners at
    // (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();

    // don't wait!
    // start processing buffered OpenGL routines
   glFlush();
}

void init(void) {

    // select clearing color
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
*/

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
/*??
int test_mesa_opengl(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (*NUMBER_250_INTEGER, *NUMBER_250_INTEGER);
    glutInitWindowPosition (*NUMBER_100_INTEGER, *NUMBER_100_INTEGER);
    glutCreateWindow ("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
*/

//?? ========================================================================================

/**
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test cyboi.");

    // How to use printf to check parameter values.
    // The printf function uses stdout for output, but nothing appears on console.
    // Therefore, fprintf is used and stderr is given for output.
    // Example:
    // int x = *NUMBER_2_INTEGER;
    // fwprintf(stderr, L"The value of x is: %d\n", x);

//??    test_logger();
//??    test_inline_assembler_code();
//??    test_preprocessor_directives();
//??    test_stdout_stderr();
//??    test_type_sizes();
//??    test_pointer_addition();
//??    test_integer_array();
//??    test_character_array_with_termination();
//??    test_array_resizing();
    test_wide_character_output();
//??    test_wide_character_wprintf();
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
//??    test_decode_integer_vector();
//??    test_encode_integer_vector();
//??    test_encode_integer();
//??    test_float_constants();
}

/* TEST_SOURCE */
#endif
