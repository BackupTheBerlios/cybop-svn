/*
 * $RCSfile: test.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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
 * @version $Revision: 1.20 $ $Date: 2004-07-31 10:57:05 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <stdio.h>
#include "../array/array.c"
#include "../global/constant.c"
#include "../global/variable.c"
#include "../transfer/file.c"
#include "../transfer/ftp.c"
#include "../transfer/http.c"
#include "../transfer/inline.c"

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

    // Character array.
    fputs("Character array:\n", stdout);

    void* ca = NULL_POINTER;
    int cas = 5;
    create_array((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &cas);

    int ca1i = 0;
    char ca1 = 'a';
    int ca2i = 1;
    char ca2 = 'b';
    int ca3i = 2;
    char ca3 = 'c';
    int ca4i = 3;
    char ca4 = '\n';
    int ca5i = 4;
    char ca5 = '\0';

    set_array_element((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca1i, (void*) &ca1);
    set_array_element((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca2i, (void*) &ca2);
    set_array_element((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca3i, (void*) &ca3);
    set_array_element((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca4i, (void*) &ca4);
    set_array_element((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &ca5i, (void*) &ca5);

    // Print out array contents.
    fputs((char*) ca, stdout);

    int i = 0;
    char* catest = CHARACTER_NULL_POINTER;

    while (1) {

        if (i >= cas) {

            break;
        }

        catest = (char*) (ca + i);
        fprintf(stderr, "ca: %c\n", *catest);

        i++;
    }

    destroy_array((void*) &ca, (void*) &CHARACTER_ARRAY, (void*) &cas);

    // Integer array.
    fputs("Integer array:\n", stdout);

    void* ia = NULL_POINTER;
    int ias = 5 * INTEGER_PRIMITIVE_SIZE;
    create_array((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ias);

    int ia1i = 0 * INTEGER_PRIMITIVE_SIZE;
    int ia1 = 9;
    int ia2i = 1 * INTEGER_PRIMITIVE_SIZE;
    int ia2 = 8;
    int ia3i = 2 * INTEGER_PRIMITIVE_SIZE;
    int ia3 = 7;
    int ia4i = 3 * INTEGER_PRIMITIVE_SIZE;
    int ia4 = 6;
    int ia5i = 4 * INTEGER_PRIMITIVE_SIZE;
    int ia5 = 5;

    set_array_element((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ia1i, (void*) &ia1);
    set_array_element((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ia2i, (void*) &ia2);
    set_array_element((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ia3i, (void*) &ia3);
    set_array_element((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ia4i, (void*) &ia4);
    set_array_element((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ia5i, (void*) &ia5);

    // Print out array contents.
    int j = 0;
    int* iatest = INTEGER_NULL_POINTER;

    while (1) {

        if (j * INTEGER_PRIMITIVE_SIZE >= ias) {

            break;
        }

        iatest = (int*) (ia + j * INTEGER_PRIMITIVE_SIZE);
        fprintf(stderr, "ia: %d\n", *iatest);

        j++;
    }

    destroy_array((void*) &ia, (void*) &INTEGER_ARRAY, (void*) &ias);

    //
    // Caution! In any case consider the size of the type, for all array!
    // Example: index * INTEGER_PRIMITIVE_SIZE
    //
}

/**
 * Tests the character array with multiple elements.
 */
void test_character_array_multiple_elements() {

    // The destination array.
    void* d = NULL_POINTER;
    int ds = 20;
    create_array((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ds);

    // The constant source array and the pointer to it.
    char a[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.', '\n', '\0'};
    char* s = a;
    int ss = 17;

    // The destination index to which to copy the source array.
    int i = 0;

    set_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &s, (void*) &ss);

    fputs((char*) d, stdout);

    // The constant source array for overwriting and the pointer to it.
    char oa[] = {'o', 'v', 'e', 'r', 'w', 'r', 'i', 't', 't', 'e', 'n', '.', '\n', '\0'};
    char* os = oa;
    int oss = 14;

    // The destination index to which to copy the source array for overwriting.
    int oi = 8;

    set_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &oi, (void*) &os, (void*) &oss);

    fputs((char*) d, stdout);

    // The remove index.
    int ri = 12;
    // The remove count.
    int rc = 7;
    remove_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ds, (void*) &ri, (void*) &rc);

    fputs((char*) d, stdout);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = 15;
    resize_array((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ns);

    fputs((char*) d, stdout);

    destroy_array((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ns);
}

/**
 * Tests the file read.
 */
void test_file_read() {

    // A file named "/home/cybop/tmp/test.cybol" needs to be created
    // in a text editor, for this test to work.

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
    char c = NULL_CHARACTER;

    while (1) {

        if (j >= ac) {

            break;
        }

        get_array_element((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &j, (void*) &c);
        fputc(c, stdout);

        j++;
    }

    destroy_array((void*) &a, (void*) &CHARACTER_ARRAY, (void*) &as);
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

        // This is a linux console.
        fputs("This is a linux console.\n", stdout);

        // Determine device name of controlling terminal.
        int n = ttyname();
        fprintf(stdout, "The terminal device name is: %i\n", n);

        // Declare test string.
        char* s;

        // Beep \007 twice with system loudspeaker.
        s = "This test beeps twice:\n\007";
        fputs(s, stdout);

        //
        // Start ESCAPE CSI sequence with: \033[
        //

        // Print bold word.
        fputs("This is a \033[1mbold\033[0m word.\n", stdout);

        // Set colours.
        // CAUTION! The "m" has to stand after the colour number
        // and it must NOT be a capital letter.
        fputs("Set colour to \033[32mgreen\033[0m.\n", stdout);
        fputs("Set colour to \033[32myellow\041[0m.\n", stdout);
        fputs("Set colour to \033[32mred\031[0m.\n", stdout);

    } else {

        // This is a normal serial terminal.
        fputs("This is a normal serial terminal.\n", stdout);
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
    test_console();
}

/* TEST_SOURCE */
#endif
