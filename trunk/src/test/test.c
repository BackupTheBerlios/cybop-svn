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
 * @version $Revision: 1.1 $ $Date: 2004-04-21 11:06:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_SOURCE
#define TEST_SOURCE

#include <stdio.h>

/**
 * Tests the standard output and error stream.
 */
void test_stdout_stderr() {

    fputs("test stdout\n", stdout);
    fputs("test stderr\n", stderr);
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
    char test[] = {'t', 'e', 's', 't', '\n', '\0'};

    fputs(test, stdout);
}

/**
 * Tests the pointer cast.
 */
void test_pointer_cast() {

    // Assign a test character array.
    char* test_char = "test\n";

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
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

    test_stdout_stderr();
    test_character_array_with_termination();
    test_pointer_cast();
}

/* TEST_SOURCE */
#endif
