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
 * @version $Revision: 1.3 $ $Date: 2004-04-21 11:10:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <stdio.h>
#include "../constants.c"
#include "../model/array_handler.c"

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

    char* m = NULL_CHARACTER_POINTER;
    int s = 5;
    create_array((void*) &m, (void*) &s);

    int i1 = 0;
    char c1 = 'a';
    int i2 = 1;
    char c2 = 'b';
    int i3 = 2;
    char c3 = 'c';
    int i4 = 3;
    char c4 = '\n';
    int i5 = 4;
    char c5 = '\0';

    set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &i1, (void*) &c1);
    set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &i2, (void*) &c2);
    set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &i3, (void*) &c3);
    set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &i4, (void*) &c4);
    set_array_element((void*) &m, (void*) &CHARACTER_ARRAY, (void*) &i5, (void*) &c5);

    fputs(m, stdout);

    destroy_array((void*) &m, (void*) &s);
}

/**
 * Tests the character array with multiple elements.
 */
void test_character_array_multiple_elements() {

    // The destination array.
    char* d = NULL_CHARACTER_POINTER;
    int ds = 20;
    create_array((void*) &d, (void*) &ds);

    // The constant source array and the pointer to it.
    char a[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.', '\n', '\0'};
    char* s = a;
    int ss = 17;

    // The destination index to which to copy the source array.
    int i = 0;

    set_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &i, (void*) &s, (void*) &ss);

    fputs(d, stdout);

    // The constant source array for overwriting and the pointer to it.
    char oa[] = {'o', 'v', 'e', 'r', 'w', 'r', 'i', 't', 't', 'e', 'n', '.', '\n', '\0'};
    char* os = oa;
    int oss = 14;

    // The destination index to which to copy the source array for overwriting.
    int oi = 8;

    set_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &oi, (void*) &os, (void*) &oss);

    fputs(d, stdout);

    // The remove index.
    int ri = 12;
    // The remove count.
    int rc = 7;
    remove_array_elements((void*) &d, (void*) &CHARACTER_ARRAY, (void*) &ds, (void*) &ri, (void*) &rc);

    fputs(d, stdout);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = 15;
    resize_array((void*) &d, (void*) &ns);

    fputs(d, stdout);

    destroy_array((void*) &d, (void*) &ns);
}

/**
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

//    test_stdout_stderr();
//    test_character_array_with_termination();
//    test_pointer_cast();
//    test_character_array_single_element();
    test_character_array_multiple_elements();
}

/* TEST_SOURCE */
#endif
