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
 * @version $RCSfile: primitive_type_size.c,v $ $Revision: 1.2 $ $Date: 2009-01-31 16:06:34 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGRAL_PRIMITIVE_TYPE_SIZE_SOURCE
#define INTEGRAL_PRIMITIVE_TYPE_SIZE_SOURCE

//
// CAUTION! Do NOT try to assign any values here!
// Otherwise, the compiler shows the following error:
// "error: initializer element is not constant"
// Therefore, the variables are only initialised in module "globaliser.c".
//

//
// The standard header "limits.h" defines the minimum and maximum values
// of the integral primitive data types, amongst other limits.
//

//
// The integral types come in different sizes, with varying
// amounts of memory usage and range of representable numbers.
// Modifiers are used to designate the size: short, long and long long.
//

//
// The C standard does not require that any of the type sizes
// be necessarily different. It is perfectly valid, for example,
// if all types are 64 bits long.
//
// In order to allow a simple and concise description of the sizes
// a compiler will apply to each of the four types, a simple
// naming scheme has been devised. See 64-Bit Programming Models.
// Two popular schemes are:
// - ILP32: int, long int and pointer types are 32 bits long
// - LP64: long int and pointers are 64 bits, and int are 32 bits
// Most implementations under these schemes use 16-bit short ints.
//

//
// All C integer types have signed and unsigned variants.
// If "signed" or "unsigned" is not specified explicitly,
// in most circumstances "signed" is assumed.
//
// However, for historic reasons plain "char" is a type
// distinct from both "signed char" and "unsigned char".
// It may be a signed type or an unsigned type, depending on
// the compiler and the character set (C guarantees that
// members of the C basic character set have positive values).
//
// Also, bit field types specified as plain "int" may be
// signed or unsigned, depending on the compiler.
//
// In cyboi, ONLY explicit specifiers should be used, e.g.:
// "signed int" or "unsigned int" BUT NOT "int".
//

/**
 * The signed char integral primitive type size.
 *
 * Minimum allowed range: -127..+127
 * Typical allowed range: -128..+127
 * Typical size [Byte]: 1
 * Typical size [Bit]: 8
 */
static int* SIGNED_CHARACTER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The unsigned char primitive type size.
 *
 * Minimum allowed range: 0..+255
 * Typical allowed range: 0..+255
 * Typical size [Byte]: 1
 * Typical size [Bit]: 8
 */
static int* UNSIGNED_CHARACTER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The signed short int primitive type size.
 *
 * Minimum allowed range: -32767..+32767
 * Typical allowed range: -32768..+32767
 * Typical size [Byte]: 2
 * Typical size [Bit]: 16
 */
static int* SIGNED_SHORT_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The unsigned short int primitive type size.
 *
 * Minimum allowed range: 0..+65535
 * Typical allowed range: 0..+65535
 * Typical size [Byte]: 2
 * Typical size [Bit]: 16
 */
static int* UNSIGNED_SHORT_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The signed int primitive type size.
 *
 * Minimum allowed range: -32767..+32767
 * Typical allowed range: -32768..+32767 (antique systems) or -2147483648..+2147483647
 * Typical size [Byte]: 2 (antique systems) or 4
 * Typical size [Bit]: 16 (antique systems) or 32
 */
static int* SIGNED_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The unsigned int primitive type size.
 *
 * Minimum allowed range: 0..+65535
 * Typical allowed range: 0..+65535 (antique systems) or 0..+4294967295
 * Typical size [Byte]: 2 (antique systems) or 4
 * Typical size [Bit]: 16 (antique systems) or 32
 */
static int* UNSIGNED_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The signed long int primitive type size.
 *
 * Minimum allowed range: -2147483647..+2147483647
 * Typical allowed range: -2147483648..+2147483647 or -9223372036854775808..+9223372036854775807 (64-Bit systems)
 * Typical size [Byte]: 4 or 8 (64-Bit systems)
 * Typical size [Bit]: 32 or 64 (64-Bit systems)
 */
static int* SIGNED_LONG_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The unsigned long int primitive type size.
 *
 * Minimum allowed range: 0..+4294967295
 * Typical allowed range: 0..+4294967295 or 0..+18446744073709551615 (64-Bit systems)
 * Typical size [Byte]: 4 or 8 (64-Bit systems)
 * Typical size [Bit]: 32 or 64 (64-Bit systems)
 */
static int* UNSIGNED_LONG_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The signed long long int primitive type size.
 *
 * Minimum allowed range: -9223372036854775807..+9223372036854775807
 * Typical allowed range: -9223372036854775808..+9223372036854775807
 * Typical size [Byte]: 8
 * Typical size [Bit]: 64
 */
static int* SIGNED_LONG_LONG_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The unsigned long long int primitive type size.
 *
 * Minimum allowed range: 0..+18446744073709551615
 * Typical allowed range: 0..+18446744073709551615
 * Typical size [Byte]: 8
 * Typical size [Bit]: 64
 */
static int* UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/**
 * The wchar_t primitive type size.
 *
 * This type is defined in the headers <stdlib.h> and <wchar.h>
 * as a typedef of a 32 Bit signed integer.
 *
 * Minimum allowed range: -127..+127 (capable of storing all elements of the basic character set)
 * Typical allowed range: -128..+127 or -32768..+32767 or -2147483648..+2147483647 (capable of representing all Unicode / UCS-4 / ISO 10646 values)
 * Typical size [Byte]: 1 (some embedded systems) or 2 (some Unix systems, Java, Win32, Win64, .NET) or 4 (GNU systems)
 * Typical size [Bit]: 8 (some embedded systems) or 16 (some Unix systems, Java, Win32, Win64, .NET) or 32 (GNU systems)
 */
static int* WIDE_CHARACTER_INTEGRAL_PRIMITIVE_TYPE_SIZE;

/* INTEGRAL_PRIMITIVE_TYPE_SIZE_SOURCE */
#endif
