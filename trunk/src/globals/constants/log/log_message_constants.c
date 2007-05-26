/*
 * $RCSfile: log_message_constants.c,v $
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
 * @version $Revision: 1.2 $ $Date: 2007-05-26 21:19:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_MESSAGE_CONSTANTS_SOURCE
#define LOG_MESSAGE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Pointer array log messages.
//

/** The "Create pointer array." message. */
static char CREATE_POINTER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* CREATE_POINTER_ARRAY_MESSAGE = CREATE_POINTER_ARRAY_MESSAGE_ARRAY;
static int* CREATE_POINTER_ARRAY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Could not create pointer array. The array is null." message. */
static char COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not create pointer array. The count is null." message. */
static char COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Destroy pointer array." message. */
static char DESTROY_POINTER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* DESTROY_POINTER_ARRAY_MESSAGE = DESTROY_POINTER_ARRAY_MESSAGE_ARRAY;
static int* DESTROY_POINTER_ARRAY_MESSAGE_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The "Could not destroy pointer array. The array is null." message. */
static char COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Could not destroy pointer array. The count is null." message. */
static char COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Resize pointer array." message. */
static char RESIZE_POINTER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* RESIZE_POINTER_ARRAY_MESSAGE = RESIZE_POINTER_ARRAY_MESSAGE_ARRAY;
static int* RESIZE_POINTER_ARRAY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Could not resize pointer array. The array is null." message. */
static char COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not resize pointer array. The count is null." message. */
static char COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not compare pointer array elements. The first array is null." message. */
static char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The "Could not compare pointer array elements. The second array is null." message. */
static char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not compare pointer array elements. The count is null." message. */
static char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not compare pointer array elements. The result is null." message. */
static char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not set pointer array elements. The destination array is null." message. */
static char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_68_INTEGER_ARRAY;

/** The "Could not set pointer array elements. The index is null." message. */
static char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not set pointer array elements. The source array is null." message. */
static char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not set pointer array elements. The count is null." message. */
static char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not remove pointer array elements. The array is null." message. */
static char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove pointer array elements. The size is null." message. */
static char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_58_INTEGER_ARRAY;

/** The "Could not remove pointer array elements. The index is null." message. */
static char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove pointer array elements. The count is null." message. */
static char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not get pointer array elements. The source array is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not get pointer array elements. The index is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get pointer array elements. The destination array is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_68_INTEGER_ARRAY;

/** The "Could not get pointer array elements. The count is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get pointer array element index. The array is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get pointer array element index. The size is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not get pointer array element index. The comparison array is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_72_INTEGER_ARRAY;

/** The "Could not get pointer array element index. The count is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get pointer array element index. The index is null." message. */
static char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

//
// Integer array log messages.
//

/** The "Create integer array." message. */
static char CREATE_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* CREATE_INTEGER_ARRAY_MESSAGE = CREATE_INTEGER_ARRAY_MESSAGE_ARRAY;
static int* CREATE_INTEGER_ARRAY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Could not create integer array. The array is null." message. */
static char COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not create integer array. The count is null." message. */
static char COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Destroy integer array." message. */
static char DESTROY_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* DESTROY_INTEGER_ARRAY_MESSAGE = DESTROY_INTEGER_ARRAY_MESSAGE_ARRAY;
static int* DESTROY_INTEGER_ARRAY_MESSAGE_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The "Could not destroy integer array. The array is null." message. */
static char COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Could not destroy integer array. The count is null." message. */
static char COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Resize integer array." message. */
static char RESIZE_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* RESIZE_INTEGER_ARRAY_MESSAGE = RESIZE_INTEGER_ARRAY_MESSAGE_ARRAY;
static int* RESIZE_INTEGER_ARRAY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Could not resize integer array. The array is null." message. */
static char COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not resize integer array. The count is null." message. */
static char COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not compare integer array elements. The first array is null." message. */
static char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The "Could not compare integer array elements. The second array is null." message. */
static char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not compare integer array elements. The count is null." message. */
static char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not compare integer array elements. The result is null." message. */
static char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not set integer array elements. The destination array is null." message. */
static char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_68_INTEGER_ARRAY;

/** The "Could not set integer array elements. The index is null." message. */
static char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not set integer array elements. The source array is null." message. */
static char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not set integer array elements. The count is null." message. */
static char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not remove integer array elements. The array is null." message. */
static char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove integer array elements. The size is null." message. */
static char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_58_INTEGER_ARRAY;

/** The "Could not remove integer array elements. The index is null." message. */
static char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove integer array elements. The count is null." message. */
static char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not get integer array elements. The source array is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not get integer array elements. The index is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get integer array elements. The destination array is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_68_INTEGER_ARRAY;

/** The "Could not get integer array elements. The count is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get integer array element index. The array is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get integer array element index. The size is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not get integer array element index. The comparison array is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_72_INTEGER_ARRAY;

/** The "Could not get integer array element index. The count is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get integer array element index. The index is null." message. */
static char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

//
// Unsigned long array log messages.
//

/** The "Create unsigned long array." message. */
static char CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* CREATE_UNSIGNED_LONG_ARRAY_MESSAGE = CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_ARRAY;
static int* CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The "Could not create unsigned long array. The array is null." message. */
static char COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not create unsigned long array. The count is null." message. */
static char COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Destroy unsigned long array." message. */
static char DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE = DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_ARRAY;
static int* DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_COUNT = NUMBER_28_INTEGER_ARRAY;

/** The "Could not destroy unsigned long array. The array is null." message. */
static char COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_57_INTEGER_ARRAY;

/** The "Could not destroy unsigned long array. The count is null." message. */
static char COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_57_INTEGER_ARRAY;

/** The "Resize unsigned long array." message. */
static char RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE = RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_ARRAY;
static int* RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_COUNT = NUMBER_27_INTEGER_ARRAY;

/** The "Could not resize unsigned long array. The array is null." message. */
static char COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not resize unsigned long array. The count is null." message. */
static char COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not compare unsigned long array elements. The first array is null." message. */
static char COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_72_INTEGER_ARRAY;

/** The "Could not compare unsigned long array elements. The second array is null." message. */
static char COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_73_INTEGER_ARRAY;

/** The "Could not compare unsigned long array elements. The count is null." message. */
static char COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The "Could not compare unsigned long array elements. The result is null." message. */
static char COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not set unsigned long array elements. The destination array is null." message. */
static char COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_74_INTEGER_ARRAY;

/** The "Could not set unsigned long array elements. The index is null." message. */
static char COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_62_INTEGER_ARRAY;

/** The "Could not set unsigned long array elements. The source array is null." message. */
static char COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_69_INTEGER_ARRAY;

/** The "Could not set unsigned long array elements. The count is null." message. */
static char COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_62_INTEGER_ARRAY;

/** The "Could not remove unsigned long array elements. The array is null." message. */
static char COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_65_INTEGER_ARRAY;

/** The "Could not remove unsigned long array elements. The size is null." message. */
static char COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_64_INTEGER_ARRAY;

/** The "Could not remove unsigned long array elements. The index is null." message. */
static char COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_65_INTEGER_ARRAY;

/** The "Could not remove unsigned long array elements. The count is null." message. */
static char COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_65_INTEGER_ARRAY;

/** The "Could not get unsigned long array elements. The source array is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_69_INTEGER_ARRAY;

/** The "Could not get unsigned long array elements. The index is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_62_INTEGER_ARRAY;

/** The "Could not get unsigned long array elements. The destination array is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_74_INTEGER_ARRAY;

/** The "Could not get unsigned long array elements. The count is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_62_INTEGER_ARRAY;

/** The "Could not get unsigned long array element index. The array is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not get unsigned long array element index. The size is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The "Could not get unsigned long array element index. The comparison array is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_78_INTEGER_ARRAY;

/** The "Could not get unsigned long array element index. The count is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not get unsigned long array element index. The index is null." message. */
static char COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'u', 'n', 's', 'i', 'g', 'n', 'e', 'd', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

//
// Character array log messages.
//

/** The "Create character array." message. */
static char CREATE_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* CREATE_CHARACTER_ARRAY_MESSAGE = CREATE_CHARACTER_ARRAY_MESSAGE_ARRAY;
static int* CREATE_CHARACTER_ARRAY_MESSAGE_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The "Could not create character array. The array is null." message. */
static char COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not create character array. The count is null." message. */
static char COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Destroy character array." message. */
static char DESTROY_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* DESTROY_CHARACTER_ARRAY_MESSAGE = DESTROY_CHARACTER_ARRAY_MESSAGE_ARRAY;
static int* DESTROY_CHARACTER_ARRAY_MESSAGE_COUNT = NUMBER_24_INTEGER_ARRAY;

/** The "Could not destroy character array. The array is null." message. */
static char COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Could not destroy character array. The count is null." message. */
static char COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Resize character array." message. */
static char RESIZE_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* RESIZE_CHARACTER_ARRAY_MESSAGE = RESIZE_CHARACTER_ARRAY_MESSAGE_ARRAY;
static int* RESIZE_CHARACTER_ARRAY_MESSAGE_COUNT = NUMBER_23_INTEGER_ARRAY;

/** The "Could not resize character array. The array is null." message. */
static char COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not resize character array. The count is null." message. */
static char COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not compare character array elements. The first array is null." message. */
static char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The "Could not compare character array elements. The second array is null." message. */
static char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not compare character array elements. The count is null." message. */
static char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not compare character array elements. The result is null." message. */
static char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not set character array elements. The destination array is null." message. */
static char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_70_INTEGER_ARRAY;

/** The "Could not set character array elements. The index is null." message. */
static char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not set character array elements. The source array is null." message. */
static char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_65_INTEGER_ARRAY;

/** The "Could not set character array elements. The count is null." message. */
static char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not remove character array elements. The array is null." message. */
static char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove character array elements. The size is null." message. */
static char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_58_INTEGER_ARRAY;

/** The "Could not remove character array elements. The index is null." message. */
static char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove character array elements. The count is null." message. */
static char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not get character array elements. The source array is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not get character array elements. The index is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get character array elements. The destination array is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_70_INTEGER_ARRAY;

/** The "Could not get character array elements. The count is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get character array element index. The array is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get character array element index. The size is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not get character array element index. The comparison array is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_72_INTEGER_ARRAY;

/** The "Could not get character array element index. The count is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get character array element index. The index is null." message. */
static char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

//
// Double array log messages.
//

/** The "Create double array." message. */
static char CREATE_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* CREATE_DOUBLE_ARRAY_MESSAGE = CREATE_DOUBLE_ARRAY_MESSAGE_ARRAY;
static int* CREATE_DOUBLE_ARRAY_MESSAGE_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The "Could not create double array. The array is null." message. */
static char COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not create double array. The count is null." message. */
static char COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Destroy double array." message. */
static char DESTROY_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* DESTROY_DOUBLE_ARRAY_MESSAGE = DESTROY_DOUBLE_ARRAY_MESSAGE_ARRAY;
static int* DESTROY_DOUBLE_ARRAY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Could not destroy double array. The array is null." message. */
static char COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Could not destroy double array. The count is null." message. */
static char COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Resize double array." message. */
static char RESIZE_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static char* RESIZE_DOUBLE_ARRAY_MESSAGE = RESIZE_DOUBLE_ARRAY_MESSAGE_ARRAY;
static int* RESIZE_DOUBLE_ARRAY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Could not resize double array. The array is null." message. */
static char COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not resize double array. The count is null." message. */
static char COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not compare double array elements. The first array is null." message. */
static char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The "Could not compare double array elements. The second array is null." message. */
static char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not compare double array elements. The count is null." message. */
static char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not compare double array elements. The result is null." message. */
static char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not set double array elements. The destination array is null." message. */
static char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not set double array elements. The index is null." message. */
static char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not set double array elements. The source array is null." message. */
static char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not set double array elements. The count is null." message. */
static char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not remove double array elements. The array is null." message. */
static char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove double array elements. The size is null." message. */
static char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_58_INTEGER_ARRAY;

/** The "Could not remove double array elements. The index is null." message. */
static char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not remove double array elements. The count is null." message. */
static char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not get double array elements. The source array is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_63_INTEGER_ARRAY;

/** The "Could not get double array elements. The index is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get double array elements. The destination array is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_67_INTEGER_ARRAY;

/** The "Could not get double array elements. The count is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_56_INTEGER_ARRAY;

/** The "Could not get double array element index. The array is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get double array element index. The size is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = NUMBER_60_INTEGER_ARRAY;

/** The "Could not get double array element index. The comparison array is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = NUMBER_72_INTEGER_ARRAY;

/** The "Could not get double array element index. The count is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

/** The "Could not get double array element index. The index is null." message. */
static char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = NUMBER_61_INTEGER_ARRAY;

//
// Array log messages.
//

/** The "Could not create array. The type is null." message. */
static char COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_41_INTEGER_ARRAY;

/** The "Could not destroy array. The type is null." message. */
static char COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_42_INTEGER_ARRAY;

/** The "Could not resize array. The type is null." message. */
static char COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_41_INTEGER_ARRAY;

/** The "Could not compare array elements. The type is null." message. */
static char COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_51_INTEGER_ARRAY;

/** The "Could not set array elements. The type is null." message. */
static char COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_47_INTEGER_ARRAY;

/** The "Could not remove array elements. The type is null." message. */
static char COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Could not get array elements. The type is null." message. */
static char COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_47_INTEGER_ARRAY;

/** The "Could not get array elements index. The type is null." message. */
static char COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_COUNT = NUMBER_53_INTEGER_ARRAY;

//
// Operation log messages.
//

/** The "Create operation." message. */
static char CREATE_OPERATION_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static char* CREATE_OPERATION_MESSAGE = CREATE_OPERATION_MESSAGE_ARRAY;
static int* CREATE_OPERATION_MESSAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The "Destroy operation." message. */
static char DESTROY_OPERATION_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static char* DESTROY_OPERATION_MESSAGE = DESTROY_OPERATION_MESSAGE_ARRAY;
static int* DESTROY_OPERATION_MESSAGE_COUNT = NUMBER_18_INTEGER_ARRAY;

/** The "Initialise operation." message. */
static char INITIALIZE_OPERATION_MESSAGE_ARRAY[] = {'I', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static char* INITIALIZE_OPERATION_MESSAGE = INITIALIZE_OPERATION_MESSAGE_ARRAY;
static int* INITIALIZE_OPERATION_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Finalise operation." message. */
static char FINALIZE_OPERATION_MESSAGE_ARRAY[] = {'F', 'i', 'n', 'a', 'l', 'i', 'z', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static char* FINALIZE_OPERATION_MESSAGE = FINALIZE_OPERATION_MESSAGE_ARRAY;
static int* FINALIZE_OPERATION_MESSAGE_COUNT = NUMBER_19_INTEGER_ARRAY;

//
// Signal memory log messages.
//

/** The "Create signal memory." message. */
static char CREATE_SIGNAL_MEMORY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'm', 'e', 'm', 'o', 'r', 'y', '.'};
static char* CREATE_SIGNAL_MEMORY_MESSAGE = CREATE_SIGNAL_MEMORY_MESSAGE_ARRAY;
static int* CREATE_SIGNAL_MEMORY_MESSAGE_COUNT = NUMBER_21_INTEGER_ARRAY;

/** The "Destroy signal memory." message. */
static char DESTROY_SIGNAL_MEMORY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'm', 'e', 'm', 'o', 'r', 'y', '.'};
static char* DESTROY_SIGNAL_MEMORY_MESSAGE = DESTROY_SIGNAL_MEMORY_MESSAGE_ARRAY;
static int* DESTROY_SIGNAL_MEMORY_MESSAGE_COUNT = NUMBER_22_INTEGER_ARRAY;

/** The "Handle compound." message. */
static char HANDLE_COMPOUND_MESSAGE_ARRAY[] = {'H', 'a', 'n', 'd', 'l', 'e', ' ', 'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd', '.'};
static char* HANDLE_COMPOUND_MESSAGE = HANDLE_COMPOUND_MESSAGE_ARRAY;
static int* HANDLE_COMPOUND_MESSAGE_COUNT = NUMBER_16_INTEGER_ARRAY;

/** The "Handle operation." message. */
static char HANDLE_OPERATION_MESSAGE_ARRAY[] = {'H', 'a', 'n', 'd', 'l', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static char* HANDLE_OPERATION_MESSAGE = HANDLE_OPERATION_MESSAGE_ARRAY;
static int* HANDLE_OPERATION_MESSAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The "Set shutdown flag." message. */
static char SET_SHUTDOWN_FLAG_MESSAGE_ARRAY[] = {'S', 'e', 't', ' ', 's', 'h', 'u', 't', 'd', 'o', 'w', 'n', ' ', 'f', 'l', 'a', 'g', '.'};
static char* SET_SHUTDOWN_FLAG_MESSAGE = SET_SHUTDOWN_FLAG_MESSAGE_ARRAY;
static int* SET_SHUTDOWN_FLAG_MESSAGE_COUNT = NUMBER_18_INTEGER_ARRAY;

//
// Cyboi log messages.
//

/** The "Check for signals." message. */
static char CHECK_FOR_SIGNALS_MESSAGE_ARRAY[] = {'C', 'h', 'e', 'c', 'k', ' ', 'f', 'o', 'r', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', '.'};
static char* CHECK_FOR_SIGNALS_MESSAGE = CHECK_FOR_SIGNALS_MESSAGE_ARRAY;
static int* CHECK_FOR_SIGNALS_MESSAGE_COUNT = NUMBER_17_INTEGER_ARRAY;

/** The "Could not handle signal. The signal abstraction is unknown." message. */
static char COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'h', 'a', 'n', 'd', 'l', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n', ' ', 'i', 's', ' ', 'u', 'n', 'k', 'n', 'o', 'w', 'n', '.'};
static char* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE = COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_ARRAY;
static int* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT = NUMBER_59_INTEGER_ARRAY;

/** The "Could not check for signals. The internal is null." message. */
static char COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'h', 'e', 'c', 'k', ' ', 'f', 'o', 'r', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE = COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_COUNT = NUMBER_50_INTEGER_ARRAY;

/** The "Exit CYBOI normally." message. */
static char EXIT_CYBOI_NORMALLY_MESSAGE_ARRAY[] = {'E', 'x', 'i', 't', ' ', 'C', 'Y', 'B', 'O', 'I', ' ', 'n', 'o', 'r', 'm', 'a', 'l', 'l', 'y', '.'};
static char* EXIT_CYBOI_NORMALLY_MESSAGE = EXIT_CYBOI_NORMALLY_MESSAGE_ARRAY;
static int* EXIT_CYBOI_NORMALLY_MESSAGE_COUNT = NUMBER_20_INTEGER_ARRAY;

/** The "Could not execute CYBOI. The command line argument vector is null." message. */
static char COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'e', 'x', 'e', 'c', 'u', 't', 'e', ' ', 'C', 'Y', 'B', 'O', 'I', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'l', 'i', 'n', 'e', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', ' ', 'v', 'e', 'c', 't', 'o', 'r', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static char* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE = COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_ARRAY;
static int* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT = NUMBER_66_INTEGER_ARRAY;

/** The cyboi version log message. */
static char CYBOI_VERSION_LOG_MESSAGE_ARRAY[] = {'C', 'y', 'b', 'e', 'r', 'n', 'e', 't', 'i', 'c', 's', ' ', 'O', 'r', 'i', 'e', 'n', 't', 'e', 'd', ' ', 'I', 'n', 't', 'e', 'r', 'p', 'r', 'e', 't', 'e', 'r', ' ', '(', 'C', 'Y', 'B', 'O', 'I', ')', ' ', '0', '.', '8', '.', '0', '\n',
    'C', 'o', 'p', 'y', 'r', 'i', 'g', 'h', 't', ' ', '(', 'C', ')', ' ', '1', '9', '9', '9', '-', '2', '0', '0', '7', '.', ' ', 'C', 'h', 'r', 'i', 's', 't', 'i', 'a', 'n', ' ', 'H', 'e', 'l', 'l', 'e', 'r', ' ', 'a', 'n', 'd', ' ', 't', 'h', 'e', ' ', 'C', 'Y', 'B', 'O', 'P', ' ', 'd', 'e', 'v', 'e', 'l', 'o', 'p', 'e', 'r', 's', '.', '\n',
    'C', 'Y', 'B', 'O', 'I', ' ', 'c', 'o', 'm', 'e', 's', ' ', 'w', 'i', 't', 'h', ' ', 'N', 'O', ' ', 'W', 'A', 'R', 'R', 'A', 'N', 'T', 'Y', ',', '\n',
    't', 'o', ' ', 't', 'h', 'e', ' ', 'e', 'x', 't', 'e', 'n', 't', ' ', 'p', 'e', 'r', 'm', 'i', 't', 't', 'e', 'd', ' ', 'b', 'y', ' ', 'l', 'a', 'w', '.', '\n',
    'Y', 'o', 'u', ' ', 'm', 'a', 'y', ' ', 'r', 'e', 'd', 'i', 's', 't', 'r', 'i', 'b', 'u', 't', 'e', ' ', 'c', 'o', 'p', 'i', 'e', 's', ' ', 'o', 'f', ' ', 'C', 'Y', 'B', 'O', 'I', '\n',
    'u', 'n', 'd', 'e', 'r', ' ', 't', 'h', 'e', ' ', 't', 'e', 'r', 'm', 's', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'G', 'N', 'U', ' ', 'G', 'e', 'n', 'e', 'r', 'a', 'l', ' ', 'P', 'u', 'b', 'l', 'i', 'c', ' ', 'L', 'i', 'c', 'e', 'n', 's', 'e', '.', '\n',
    'F', 'o', 'r', ' ', 'm', 'o', 'r', 'e', ' ', 'i', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'b', 'o', 'u', 't', ' ', 't', 'h', 'e', 's', 'e', ' ', 'm', 'a', 't', 't', 'e', 'r', 's', ',', '\n',
    's', 'e', 'e', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'l', 'e', 's', ' ', 'n', 'a', 'm', 'e', 'd', ' ', 'C', 'O', 'P', 'Y', 'I', 'N', 'G', '.', '\n'};
static char* CYBOI_VERSION_LOG_MESSAGE = CYBOI_VERSION_LOG_MESSAGE_ARRAY;
static int* CYBOI_VERSION_LOG_MESSAGE_COUNT = NUMBER_336_INTEGER_ARRAY;

/** The cyboi help log message. */
static char CYBOI_HELP_LOG_MESSAGE_ARRAY[] = {
    'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', ' ', 'h', 'a', 'v', 'e', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'g', 'i', 'v', 'e', 'n', '!', '\n',
    'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', '[', '-', '-', 'v', 'e', 'r', 's', 'i', 'o', 'n', ']', ' ', '[', '-', '-', 'h', 'e', 'l', 'p', ']', ' ', '[', '-', '-', 't', 'e', 's', 't', ']', ' ', '[', '-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'A', 'R', 'G', ']', ' ', '[', '-', '-', 'l', 'o', 'g', 'l', 'e', 'v', 'e', 'l', ' ', 'A', 'R', 'G', ']', ' ', '[', '-', '-', 'l', 'o', 'g', 'f', 'i', 'l', 'e', ' ', 'A', 'R', 'G', ']', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'v', 'e', 'r', 's', 'i', 'o', 'n', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', 'i', 's', 'p', 'l', 'a', 'y', 's', ' ', 't', 'h', 'e', ' ', 'c', 'u', 'r', 'r', 'e', 'n', 't', ' ', 'v', 'e', 'r', 's', 'i', 'o', 'n', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'h', 'e', 'l', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', 'i', 's', 'p', 'l', 'a', 'y', 's', ' ', 't', 'h', 'i', 's', ' ', 'h', 'e', 'l', 'p', ' ', 'm', 'e', 's', 's', 'a', 'g', 'e', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 't', 'e', 's', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'S', 't', 'a', 'r', 't', 's', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'i', 'n', ' ', 't', 'e', 's', 't', ' ', 'm', 'o', 'd', 'e', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'A', 'R', 'G', ' ', 'S', 't', 'a', 'r', 't', 's', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'i', 'n', ' ', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'm', 'o', 'd', 'e', '.', ' ', 'T', 'a', 'k', 'e', 's', ' ', 'A', 'R', 'G', ' ', 'a', 's', ' ', 'c', 'y', 'b', 'o', 'l', ' ', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'f', 'i', 'l', 'e', '.', ' ', 'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', ' ', 'w', 'a', 'y', ' ', 't', 'o', ' ', 'u', 's', 'e', ' ', 'c', 'y', 'b', 'o', 'i', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'l', 'o', 'g', 'l', 'e', 'v', 'e', 'l', ' ', 'A', 'R', 'G', ' ', ' ', 'S', 'e', 't', 's', ' ', 't', 'h', 'e', ' ', 'l', 'o', 'g', ' ', 'l', 'e', 'v', 'e', 'l', '.', ' ', 'T', 'h', 'e', ' ', 'A', 'R', 'G', ' ', 'm', 'a', 'y', ' ', 'b', 'e', ' ', 'o', 'n', 'e', ' ', 'o', 'f', ':', ' ', 'o', 'f', 'f', ',', ' ', 'e', 'r', 'r', 'o', 'r', ',', ' ', 'w', 'a', 'r', 'n', 'i', 'n', 'g', ',', ' ', 'i', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', ',', ' ', 'd', 'e', 'b', 'u', 'g', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 'f', 'a', 'u', 'l', 't', ' ', 'i', 's', ' ', 'o', 'f', 'f', '.', '\n',
    ' ', ' ', ' ', ' ', '-', '-', 'l', 'o', 'g', 'f', 'i', 'l', 'e', ' ', 'A', 'R', 'G', ' ', ' ', ' ', 'L', 'o', 'g', 's', ' ', 'm', 'e', 's', 's', 'a', 'g', 'e', 's', ' ', 't', 'o', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'l', 'e', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'b', 'y', ' ', 'A', 'R', 'G', '.', '\n',
    'E', 'x', 'a', 'm', 'p', 'l', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', '-', '-', 'k', 'n', 'o', 'w', 'l', 'e', 'd', 'g', 'e', ' ', 'r', 'e', 's', 'm', 'e', 'd', 'i', 'c', 'i', 'n', 'a', 'e', '/', 'r', 'u', 'n', '.', 'c', 'y', 'b', 'o', 'l', '\n',
    'R', 'e', 'p', 'o', 'r', 't', ' ', 'b', 'u', 'g', 's', ' ', 't', 'o', ' ',
    '<', 'c', 'y', 'b', 'o', 'p', '-', 'd', 'e', 'v', 'e', 'l', 'o', 'p', 'e', 'r', 's', '@', 'l', 'i', 's', 't', 's', '.', 'b', 'e', 'r', 'l', 'i', 'o', 's', '.', 'd', 'e', '>', ' ',
    'o', 'r', ' ', '<', 'c', 'h', 'r', 'i', 's', 't', 'i', 'a', 'n', '.', 'h', 'e', 'l', 'l', 'e', 'r', '@', 't', 'u', 'x', 't', 'a', 'x', '.', 'd', 'e', '>', '.', '\n'};
static char* CYBOI_HELP_LOG_MESSAGE = CYBOI_HELP_LOG_MESSAGE_ARRAY;
static int* CYBOI_HELP_LOG_MESSAGE_COUNT = NUMBER_716_INTEGER_ARRAY;

/* LOG_MESSAGE_CONSTANTS_SOURCE */
#endif
