/*
 * Copyright (C) 1999-2010. Christian Heller.
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

#ifndef ASSEMBLER_TESTER
#define ASSEMBLER_TESTER

#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Tests the assembler register handling.
 */
void test_assembler_register() {

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
 * Tests the inline assembler code.
 */
void test_assembler() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test assembler.");

//    test_assembler_register();
}

/* ASSEMBLER_TESTER */
#endif
