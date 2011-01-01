/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: tester.c,v $ $Revision: 1.35 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATOR_TESTER
#define COMMUNICATOR_TESTER

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
#include <stdio.h>
#include <termios.h>
#include <wchar.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../logger/logger.c"
#include "../../variable/type_size/terminal_type_size.c"

/**
 * Tests the standard output and error stream.
 */
void test_stdout_stdout() {

    log_write_terminated_message((void*) stdout, L"Test stdout stdout:\n");

    log_write_terminated_message((void*) stdout, L"test stdout ok\n");
    log_write_terminated_message((void*) stdout, L"test stdout ok\n");
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
    // The following does NOT work and will bring the compilation warning:
    // "cast to pointer from integer of different size"
    // The reason is that an "L" is needed before EACH character, to make it a wide character!
    // Therefore, the following three lines are commented out.
    // static wchar_t TEST_WIDE_CHARACTER_STRING_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', 0xE7, 0x82, 0xBA, 'l', 'e'};
    // static wchar_t TEST_WIDE_CHARACTER_STRING_ARRAY[] = {'r', 'e', 'c', 't', 'a', 'n', 0xE2, 0x94, 0x80, 'l', 'e'};
    // static wchar_t* TEST_WIDE_CHARACTER_STRING = TEST_WIDE_CHARACTER_STRING_ARRAY;

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
    fwide(stdout, *NUMBER_1_INTEGER_MEMORY_MODEL);

    log_write_terminated_message((void*) stdout, L"Test fputws.\n");
//??    log_write_terminated_message((void*) stdout, (wchar_t*) TEST_WIDE_CHARACTER_STRING);
    wprintf(L"Test wprintf without stream argument.\n");

    // Test wide character constants.
    fwprintf(stdout, L"Test hello world ls: %10ls \n", "hello world");
    fwprintf(stdout, L"Test hello world s: %10s \n", "hello world");
    fwprintf(stdout, L"Test hello world L ls with cast: %10ls \n", (wchar_t*) L"hello world");
    fwprintf(stdout, L"Test hello world L s with cast: %10s \n", (wchar_t*) L"hello world");
    fwprintf(stdout, L"Test hello world L ls without cast: %10ls\n", L"hello world");
    fwprintf(stdout, L"Test hello world L s without cast: %10s\n", L"hello world");

//??    fwprintf(stdout, L"Test wide character string ls: %5ls \n", TEST_WIDE_CHARACTER_STRING);
//??    fwprintf(stdout, L"Test wide character string s: %5s \n", TEST_WIDE_CHARACTER_STRING);
    fwprintf(stdout, L"Test wide character string with termination: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_TERMINATION);

    fwprintf(stdout, L"Test wide character string L ls: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_L);
    fwprintf(stdout, L"Test wide character string L s: %5s \n", TEST_WIDE_CHARACTER_STRING_WITH_L);
    fwprintf(stdout, L"Test wide character string L and termination: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_L_AND_TERMINATION);

    fwprintf(stdout, L"Test wide character string with UTF-8 codes and termination ls: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION);
    fwprintf(stdout, L"Test wide character string with UTF-8 codes and termination s: %5s \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_8_CODES_AND_TERMINATION);
    fwprintf(stdout, L"Test wide character string with UTF-16 codes and termination ls: %5ls \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION);
    fwprintf(stdout, L"Test wide character string with UTF-16 codes and termination s: %5s \n", TEST_WIDE_CHARACTER_STRING_WITH_UTF_16_CODES_AND_TERMINATION);

//??    fwprintf(stdout, L"Test wide character string fourth letter with cast: %lc \n", (wchar_t*) TEST_WIDE_CHARACTER_STRING[3]);
//??    fwprintf(stdout, L"Test wide character string fourth letter without cast: %lc \n", TEST_WIDE_CHARACTER_STRING[3]);

    log_write_terminated_message((void*) stdout, L"Test END.\n");
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
//??        allocate((void*) &t, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    to = (struct termios*) malloc(*INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);
    tw = (struct termios*) malloc(*INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);

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
    int tss = *NUMBER_1000_INTEGER_MEMORY_MODEL;

    // Create terminated control sequences string.
    allocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Set terminated control sequences string by first copying the actual
    // control sequences and then adding the null termination character.
    // (Termination character does not seem to be necessary for wide character strings.)
    set_array_elements(ts, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    set_array_elements(ts, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;

    wprintf(L"\033[32mgreen colour\033[0mswitched off.");

    // \033
    wchar_t wc = 0x001B;
    set_array_elements(ts, (void*) &wc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    // [
    wc = 0x005B;
    set_array_elements(ts, (void*) &wc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    // 3
    wc = 0x0033;
    set_array_elements(ts, (void*) &wc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    // 2
    wc = 0x0032;
    set_array_elements(ts, (void*) &wc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    // m
    wc = 0x006d;
    set_array_elements(ts, (void*) &wc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;

    set_array_elements(ts, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    set_array_elements(ts, (void*) BOX_DRAWINGS_LIGHT_HORIZONTAL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;
    set_array_elements(ts, (void*) BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &tsc, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    tsc++;

    // Write to terminal.
//??    fwprintf(t, L"%s\n", ts);
    fwprintf(t, L"%ls\n", (wchar_t*) ts);
//??    log_write_terminated_message((void*) stdout, (wchar_t*) ts, t);

    // Destroy terminated control sequences.
    deallocate_array((void*) &ts, (void*) &tss, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

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
 * Tests the communicator file read.
 */
void test_communicator_file_read() {

    log_write_terminated_message((void*) stdout, L"Test communicator file read:\n");

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
    int fnc = *NUMBER_26_INTEGER_MEMORY_MODEL;

    allocate_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
//??    receive_file((void*) &a, (void*) &as, (void*) &ac, (void*) &fn, (void*) &fnc);

    fwprintf(stdout, L"a: %i\n", a);
    fwprintf(stdout, L"as: %i\n", as);
    fwprintf(stdout, L"ac: %i\n", ac);
    fwprintf(stdout, L"fn: %i\n", fn);
    fwprintf(stdout, L"fnc: %i\n", fnc);

    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    char* c = (char*) *NULL_POINTER_MEMORY_MODEL;
    int* cc = *NUMBER_1_INTEGER_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (j >= ac) {

            break;
        }

        get_array_elements((void*) &c, (void*) &a, (void*) &j, (void*) CHARACTER_ARRAY);
        fputs(c);

        j++;
    }

    deallocate_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
*/
}

/**
 * Tests the communicator file write.
 */
void test_communicator_file_write() {

    log_write_terminated_message((void*) stdout, L"Test communicator file write:\n");

    // The character array.
    char aa[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\n'};
    // The array.
    void* a = aa;
    // The array size.
    int as = *NUMBER_14_INTEGER_MEMORY_MODEL;
    // The array count.
    int ac = *NUMBER_14_INTEGER_MEMORY_MODEL;
    // The file name array.
    char fna[] = {'/', 'h', 'o', 'm', 'e', '/', 'c', 'y', 'b', 'o', 'p', '/', 't', 'm', 'p', '/', 't', 'e', 's', 't', '.', 'c', 'y', 'b', 'o', 'l'};
    // The file name.
    char* fn = fna;
    // The file name count.
    int fnc = *NUMBER_26_INTEGER_MEMORY_MODEL;

//??    send_file((void*) &a, (void*) &as, (void*) &ac, (void*) &fn, (void*) &fnc);
}

/**
 * Tests the communicator console input.
 */
void test_communicator_console_input() {

    log_write_terminated_message((void*) stdout, L"Test communicator console input:\n");

#ifdef GNU_LINUX_OPERATING_SYSTEM
    // The terminal device name.
    FILE* t = (FILE*) *NULL_POINTER_MEMORY_MODEL;
    // The old termios settings.
    struct termios* to = (struct termios*) *NULL_POINTER_MEMORY_MODEL;
    // The new termios settings.
    struct termios* tn = (struct termios*) *NULL_POINTER_MEMORY_MODEL;

    // Allocate gnu/linux console internals.
    to = (struct termios*) malloc(*INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);
    tn = (struct termios*) malloc(*INPUT_OUTPUT_SYSTEM_TERMINAL_TYPE_SIZE);

    // Set file stream.
    t = stdin;

    // Get file descriptor for file stream.
    // CAUTION! The stream "stdin" must be used instead of "stdout" here!
    int d = fileno(t);

    // Test standard streams.
    int testin = fileno(stdin);
    int testout = fileno(stdout);
    int testerr = fileno(stderr);
    fwprintf(stdout, L"TEST in %i\n", testin);
    fwprintf(stdout, L"TEST out %i\n", testout);
    fwprintf(stdout, L"TEST err %i\n", testerr);

    // Store old termios settings.
    int e = tcgetattr(d, (void*) to);

    if (e != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

        // Initialise new termios settings.
        *tn = *to;

        // Manipulate termios attributes.
        // Set number of characters.
        tn->c_cc[VMIN] = *NUMBER_1_INTEGER_MEMORY_MODEL;
        tn->c_cc[VTIME] = *NUMBER_0_INTEGER_MEMORY_MODEL;
        tn->c_lflag &= ~ICANON;
        // Switch off echo.
        tn->c_lflag &= ~ECHO;

        // Set new termios attributes.
        tcsetattr(d, TCSANOW, (void*) tn);

        wint_t c = fgetwc(t);

        fwprintf(stdout, L"TEST c: %i\n", c);

        ungetwc(c, t);

        fwprintf(stdout, L"TEST unget c: %i\n", c);

        wint_t again = fgetwc(t);

        fwprintf(stdout, L"TEST again c: %i\n", again);

        // Reset terminal to old settings.
        tcsetattr(d, TCSANOW, (void*) to);

    } else {

        if (errno == EBADF) {

            log_write_terminated_message((void*) stdout, L"Could not store old termios settings. The filedes argument is not a valid file descriptor.\n");

        } else if (errno == ENOTTY) {

            log_write_terminated_message((void*) stdout, L"Could not store old termios settings. The filedes is not associated with a terminal.\n");

        } else {

            log_write_terminated_message((void*) stdout, L"Could not store old termios settings.\n");
        }
    }
// GNU_LINUX_OPERATING_SYSTEM
#endif
}

/**
 * Tests the communicator console output.
 */
void test_communicator_console_output() {

    log_write_terminated_message((void*) stdout, L"Test communicator console output:\n");

/*??
    if (strcmp("linux", getenv("TERM")) == *NUMBER_0_INTEGER_MEMORY_MODEL) {
*/

        // This is a gnu/linux console.
        log_write_terminated_message((void*) stdout, L"This is a gnu/linux console.\n");

/*??
        // Determine device name of controlling terminal.
        int n = ttyname();
        fwprintf(stdout, L"The terminal device name is: %i\n", n);
*/

        // Declare test string.
        char* s;

        // Beep \007 twice with system loudspeaker.
        s = "Beep:\n\007";
        fputs(s, stdout);

        //
        // Start ESCAPE CSI sequence with: \033[
        //

        // Print bold word.
        log_write_terminated_message((void*) stdout, L"This is a \033[1mbold\033[0m word.\n");

        // Set colours.
        // CAUTION! The "m" has to stand after the colour number
        // and it must NOT be a capital letter.
        log_write_terminated_message((void*) stdout, L"Set colour to \033[32mgreen\033[0m.\n");
        log_write_terminated_message((void*) stdout, L"Set colour to \033[32myellow\041[0m.\n");
        log_write_terminated_message((void*) stdout, L"Set colour to \033[32mred\031[0m.\n");

/*??
    } else {

        // This is a normal serial terminal.
        log_write_terminated_message((void*) stdout, L"This is a normal serial terminal.\n");
    }
*/
}

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
int test_communicator_mesa_opengl_standard(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (*NUMBER_250_INTEGER_MEMORY_MODEL, *NUMBER_250_INTEGER);
    glutInitWindowPosition (*NUMBER_100_INTEGER_MEMORY_MODEL, *NUMBER_100_INTEGER_MEMORY_MODEL);
    glutCreateWindow ("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
*/

/**
 * Tests the communicator mesa opengl library functionality.
 */
void test_communicator_mesa_opengl() {

    log_write_terminated_message((void*) stdout, L"Test communicator mesa opengl:\n");

/*??
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
//??
}

/**
 * Tests the communicator.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_communicator() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test communicator.");

//    test_stdout_stdout();
//    test_wide_character_wprintf();
//    test_wide_character_output();

//    test_communicator_file_read();
//    test_communicator_file_write();

//    test_communicator_console_input();
//    test_communicator_console_output();

//    test_communicator_mesa_opengl_standard(int argc, char **argv);
//    test_communicator_mesa_opengl(*NUMBER_0_INTEGER_MEMORY_MODEL, (char**) NULL_POINTER_MEMORY_MODEL);
}

/* COMMUNICATOR_TESTER */
#endif
