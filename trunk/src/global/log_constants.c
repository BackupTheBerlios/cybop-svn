/*
 * $RCSfile: log_constants.c,v $
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
 * This file defines global log constants.
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-13 07:22:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_CONSTANTS_SOURCE
#define LOG_CONSTANTS_SOURCE

//
// Log levels.
//

/** The off log level. */
static const int OFF_LOG_LEVEL = 0;

/** The error log level. */
static const int ERROR_LOG_LEVEL = 1;

/** The warning log level. */
static const int WARNING_LOG_LEVEL = 2;

/** The info log level. */
static const int INFO_LOG_LEVEL = 3;

//
// Log level names.
//

/** The error log level name array, pointer, count. */
static const char ERROR_LOG_LEVEL_NAME_ARRAY[] = {'E', 'r', 'r', 'o', 'r'};
static const char* ERROR_LOG_LEVEL_NAME = ERROR_LOG_LEVEL_NAME_ARRAY;
static const int ERROR_LOG_LEVEL_NAME_COUNT = 5;

/** The warning log level name array, pointer, count. */
static const char WARNING_LOG_LEVEL_NAME_ARRAY[] = {'W', 'a', 'r', 'n', 'i', 'n', 'g'};
static const char* WARNING_LOG_LEVEL_NAME = WARNING_LOG_LEVEL_NAME_ARRAY;
static const int WARNING_LOG_LEVEL_NAME_COUNT = 7;

/** The info log level name array, pointer, count. */
static const char INFO_LOG_LEVEL_NAME_ARRAY[] = {'I', 'n', 'f', 'o'};
static const char* INFO_LOG_LEVEL_NAME = INFO_LOG_LEVEL_NAME_ARRAY;
static const int INFO_LOG_LEVEL_NAME_COUNT = 4;

//
// Logger log messages.
//

//
// Pointer array log messages.
//

/** The "Create pointer array." message array, pointer, count. */
static const char CREATE_POINTER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};
static const char* CREATE_POINTER_ARRAY_MESSAGE = CREATE_POINTER_ARRAY_MESSAGE_ARRAY;
static const int CREATE_POINTER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create pointer array. The array is null." message array, pointer, count. */
static const char COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static const char* COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;
static const int COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create pointer array. The count is null." message array. */
static const char COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create pointer array. The count is null." message. */
static const char* COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create pointer array. The count is null." message count. */
static const int COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy pointer array." message array. */
static const char DESTROY_POINTER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy pointer array." message. */
static const char* DESTROY_POINTER_ARRAY_MESSAGE = DESTROY_POINTER_ARRAY_MESSAGE_ARRAY;

/** The "Destroy pointer array." message count. */
static const int DESTROY_POINTER_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy pointer array. The array is null." message array. */
static const char COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy pointer array. The array is null." message. */
static const char* COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy pointer array. The array is null." message count. */
static const int COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy pointer array. The count is null." message array. */
static const char COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy pointer array. The count is null." message. */
static const char* COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy pointer array. The count is null." message count. */
static const int COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize pointer array." message array. */
static const char RESIZE_POINTER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize pointer array." message. */
static const char* RESIZE_POINTER_ARRAY_MESSAGE = RESIZE_POINTER_ARRAY_MESSAGE_ARRAY;

/** The "Resize pointer array." message count. */
static const int RESIZE_POINTER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize pointer array. The array is null." message array. */
static const char COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize pointer array. The array is null." message. */
static const char* COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize pointer array. The array is null." message count. */
static const int COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize pointer array. The count is null." message array. */
static const char COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize pointer array. The count is null." message. */
static const char* COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize pointer array. The count is null." message count. */
static const int COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare pointer array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare pointer array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare pointer array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare pointer array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare pointer array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare pointer array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set pointer array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set pointer array elements. The index is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The index is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The index is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set pointer array elements. The source array is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The source array is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The source array is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set pointer array elements. The count is null." message array. */
static const char COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set pointer array elements. The count is null." message. */
static const char* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set pointer array elements. The count is null." message count. */
static const int COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove pointer array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove pointer array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove pointer array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove pointer array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove pointer array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove pointer array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get pointer array elements. The source array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The source array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The source array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get pointer array elements. The index is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The index is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The index is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get pointer array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get pointer array elements. The count is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array elements. The count is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array elements. The count is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get pointer array element index. The array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get pointer array element index. The size is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The size is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The size is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get pointer array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get pointer array element index. The count is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The count is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The count is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get pointer array element index. The index is null." message array. */
static const char COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'p', 'o', 'i', 'n', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get pointer array element index. The index is null." message. */
static const char* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get pointer array element index. The index is null." message count. */
static const int COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Integer array log messages.
//

/** The "Create integer array." message array. */
static const char CREATE_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create integer array." message. */
static const char* CREATE_INTEGER_ARRAY_MESSAGE = CREATE_INTEGER_ARRAY_MESSAGE_ARRAY;

/** The "Create integer array." message count. */
static const int CREATE_INTEGER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create integer array. The array is null." message array. */
static const char COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create integer array. The array is null." message. */
static const char* COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create integer array. The array is null." message count. */
static const int COULD_NOT_CREATE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create integer array. The count is null." message array. */
static const char COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create integer array. The count is null." message. */
static const char* COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create integer array. The count is null." message count. */
static const int COULD_NOT_CREATE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy integer array." message array. */
static const char DESTROY_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy integer array." message. */
static const char* DESTROY_INTEGER_ARRAY_MESSAGE = DESTROY_INTEGER_ARRAY_MESSAGE_ARRAY;

/** The "Destroy integer array." message count. */
static const int DESTROY_INTEGER_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy integer array. The array is null." message array. */
static const char COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy integer array. The array is null." message. */
static const char* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy integer array. The array is null." message count. */
static const int COULD_NOT_DESTROY_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy integer array. The count is null." message array. */
static const char COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy integer array. The count is null." message. */
static const char* COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy integer array. The count is null." message count. */
static const int COULD_NOT_DESTROY_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize integer array." message array. */
static const char RESIZE_INTEGER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize integer array." message. */
static const char* RESIZE_INTEGER_ARRAY_MESSAGE = RESIZE_INTEGER_ARRAY_MESSAGE_ARRAY;

/** The "Resize integer array." message count. */
static const int RESIZE_INTEGER_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize integer array. The array is null." message array. */
static const char COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize integer array. The array is null." message. */
static const char* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize integer array. The array is null." message count. */
static const int COULD_NOT_RESIZE_INTEGER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize integer array. The count is null." message array. */
static const char COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize integer array. The count is null." message. */
static const char* COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize integer array. The count is null." message count. */
static const int COULD_NOT_RESIZE_INTEGER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare integer array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare integer array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare integer array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare integer array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare integer array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare integer array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_INTEGER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set integer array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set integer array elements. The index is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The index is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The index is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set integer array elements. The source array is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The source array is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The source array is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set integer array elements. The count is null." message array. */
static const char COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set integer array elements. The count is null." message. */
static const char* COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set integer array elements. The count is null." message count. */
static const int COULD_NOT_SET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove integer array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove integer array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove integer array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove integer array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove integer array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove integer array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get integer array elements. The source array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The source array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The source array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get integer array elements. The index is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The index is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The index is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get integer array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get integer array elements. The count is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array elements. The count is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array elements. The count is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get integer array element index. The array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get integer array element index. The size is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The size is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The size is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get integer array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get integer array element index. The count is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The count is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The count is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get integer array element index. The index is null." message array. */
static const char COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get integer array element index. The index is null." message. */
static const char* COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get integer array element index. The index is null." message count. */
static const int COULD_NOT_GET_INTEGER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Character array log messages.
//

/** The "Create character array." message array. */
static const char CREATE_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create character array." message. */
static const char* CREATE_CHARACTER_ARRAY_MESSAGE = CREATE_CHARACTER_ARRAY_MESSAGE_ARRAY;

/** The "Create character array." message count. */
static const int CREATE_CHARACTER_ARRAY_MESSAGE_COUNT = 23;

/** The "Could not create character array. The array is null." message array. */
static const char COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create character array. The array is null." message. */
static const char* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create character array. The array is null." message count. */
static const int COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create character array. The count is null." message array. */
static const char COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create character array. The count is null." message. */
static const char* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create character array. The count is null." message count. */
static const int COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy character array." message array. */
static const char DESTROY_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy character array." message. */
static const char* DESTROY_CHARACTER_ARRAY_MESSAGE = DESTROY_CHARACTER_ARRAY_MESSAGE_ARRAY;

/** The "Destroy character array." message count. */
static const int DESTROY_CHARACTER_ARRAY_MESSAGE_COUNT = 24;

/** The "Could not destroy character array. The array is null." message array. */
static const char COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy character array. The array is null." message. */
static const char* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy character array. The array is null." message count. */
static const int COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy character array. The count is null." message array. */
static const char COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy character array. The count is null." message. */
static const char* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy character array. The count is null." message count. */
static const int COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize character array." message array. */
static const char RESIZE_CHARACTER_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize character array." message. */
static const char* RESIZE_CHARACTER_ARRAY_MESSAGE = RESIZE_CHARACTER_ARRAY_MESSAGE_ARRAY;

/** The "Resize character array." message count. */
static const int RESIZE_CHARACTER_ARRAY_MESSAGE_COUNT = 23;

/** The "Could not resize character array. The array is null." message array. */
static const char COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize character array. The array is null." message. */
static const char* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize character array. The array is null." message count. */
static const int COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize character array. The count is null." message array. */
static const char COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize character array. The count is null." message. */
static const char* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize character array. The count is null." message count. */
static const int COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare character array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare character array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare character array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare character array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare character array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare character array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set character array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set character array elements. The index is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The index is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The index is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set character array elements. The source array is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The source array is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The source array is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set character array elements. The count is null." message array. */
static const char COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set character array elements. The count is null." message. */
static const char* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set character array elements. The count is null." message count. */
static const int COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove character array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove character array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove character array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove character array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove character array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove character array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get character array elements. The source array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The source array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The source array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get character array elements. The index is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The index is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The index is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get character array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get character array elements. The count is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array elements. The count is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array elements. The count is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get character array element index. The array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get character array element index. The size is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The size is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The size is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get character array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get character array element index. The count is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The count is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The count is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get character array element index. The index is null." message array. */
static const char COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'c', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get character array element index. The index is null." message. */
static const char* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get character array element index. The index is null." message count. */
static const int COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Double array log messages.
//

/** The "Create double array." message array. */
static const char CREATE_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Create double array." message. */
static const char* CREATE_DOUBLE_ARRAY_MESSAGE = CREATE_DOUBLE_ARRAY_MESSAGE_ARRAY;

/** The "Create double array." message count. */
static const int CREATE_DOUBLE_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not create double array. The array is null." message array. */
static const char COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create double array. The array is null." message. */
static const char* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create double array. The array is null." message count. */
static const int COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not create double array. The count is null." message array. */
static const char COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create double array. The count is null." message. */
static const char* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create double array. The count is null." message count. */
static const int COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Destroy double array." message array. */
static const char DESTROY_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Destroy double array." message. */
static const char* DESTROY_DOUBLE_ARRAY_MESSAGE = DESTROY_DOUBLE_ARRAY_MESSAGE_ARRAY;

/** The "Destroy double array." message count. */
static const int DESTROY_DOUBLE_ARRAY_MESSAGE_COUNT = 22;

/** The "Could not destroy double array. The array is null." message array. */
static const char COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy double array. The array is null." message. */
static const char* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy double array. The array is null." message count. */
static const int COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not destroy double array. The count is null." message array. */
static const char COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy double array. The count is null." message. */
static const char* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy double array. The count is null." message count. */
static const int COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 51;

/** The "Resize double array." message array. */
static const char RESIZE_DOUBLE_ARRAY_MESSAGE_ARRAY[] = {'R', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.'};

/** The "Resize double array." message. */
static const char* RESIZE_DOUBLE_ARRAY_MESSAGE = RESIZE_DOUBLE_ARRAY_MESSAGE_ARRAY;

/** The "Resize double array." message count. */
static const int RESIZE_DOUBLE_ARRAY_MESSAGE_COUNT = 21;

/** The "Could not resize double array. The array is null." message array. */
static const char COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize double array. The array is null." message. */
static const char* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize double array. The array is null." message count. */
static const int COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not resize double array. The count is null." message array. */
static const char COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize double array. The count is null." message. */
static const char* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize double array. The count is null." message count. */
static const int COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not compare double array elements. The first array is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The first array is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The first array is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_COUNT = 66;

/** The "Could not compare double array elements. The second array is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'e', 'c', 'o', 'n', 'd', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The second array is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The second array is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_COUNT = 67;

/** The "Could not compare double array elements. The count is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The count is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The count is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not compare double array elements. The result is null." message array. */
static const char COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'r', 'e', 's', 'u', 'l', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare double array elements. The result is null." message. */
static const char* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare double array elements. The result is null." message count. */
static const int COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not set double array elements. The destination array is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The destination array is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The destination array is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not set double array elements. The index is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The index is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The index is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not set double array elements. The source array is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The source array is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The source array is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not set double array elements. The count is null." message array. */
static const char COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set double array elements. The count is null." message. */
static const char* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set double array elements. The count is null." message count. */
static const int COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not remove double array elements. The array is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The array is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The array is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove double array elements. The size is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The size is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The size is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_COUNT = 58;

/** The "Could not remove double array elements. The index is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The index is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The index is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not remove double array elements. The count is null." message array. */
static const char COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove double array elements. The count is null." message. */
static const char* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove double array elements. The count is null." message count. */
static const int COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 59;

/** The "Could not get double array elements. The source array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 's', 'o', 'u', 'r', 'c', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The source array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The source array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_COUNT = 63;

/** The "Could not get double array elements. The index is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The index is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The index is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get double array elements. The destination array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The destination array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The destination array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_COUNT = 68;

/** The "Could not get double array elements. The count is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array elements. The count is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array elements. The count is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_COUNT = 56;

/** The "Could not get double array element index. The array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get double array element index. The size is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'z', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The size is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The size is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_COUNT = 60;

/** The "Could not get double array element index. The comparison array is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'i', 's', 'o', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The comparison array is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The comparison array is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_COUNT = 72;

/** The "Could not get double array element index. The count is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'u', 'n', 't', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The count is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The count is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_COUNT = 61;

/** The "Could not get double array element index. The index is null." message array. */
static const char COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'd', 'o', 'u', 'b', 'l', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get double array element index. The index is null." message. */
static const char* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get double array element index. The index is null." message count. */
static const int COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_COUNT = 61;

//
// Array log messages.
//

/** The "Could not create array. The type is null." message array. */
static const char COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'r', 'e', 'a', 't', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not create array. The type is null." message. */
static const char* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not create array. The type is null." message count. */
static const int COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = 41;

/** The "Could not destroy array. The type is null." message array. */
static const char COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'd', 'e', 's', 't', 'r', 'o', 'y', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not destroy array. The type is null." message. */
static const char* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not destroy array. The type is null." message count. */
static const int COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = 42;

/** The "Could not resize array. The type is null." message array. */
static const char COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 's', 'i', 'z', 'e', ' ', 'a', 'r', 'r', 'a', 'y', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not resize array. The type is null." message. */
static const char* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not resize array. The type is null." message count. */
static const int COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_COUNT = 41;

/** The "Could not compare array elements. The type is null." message array. */
static const char COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'c', 'o', 'm', 'p', 'a', 'r', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not compare array elements. The type is null." message. */
static const char* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not compare array elements. The type is null." message count. */
static const int COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 51;

/** The "Could not set array elements. The type is null." message array. */
static const char COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 's', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not set array elements. The type is null." message. */
static const char* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not set array elements. The type is null." message count. */
static const int COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 47;

/** The "Could not remove array elements. The type is null." message array. */
static const char COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'r', 'e', 'm', 'o', 'v', 'e', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not remove array elements. The type is null." message. */
static const char* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not remove array elements. The type is null." message count. */
static const int COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 50;

/** The "Could not get array elements. The type is null." message array. */
static const char COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get array elements. The type is null." message. */
static const char* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get array elements. The type is null." message count. */
static const int COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_COUNT = 47;

/** The "Could not get array elements index. The type is null." message array. */
static const char COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'g', 'e', 't', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'e', 'l', 'e', 'm', 'e', 'n', 't', 's', ' ', 'i', 'n', 'd', 'e', 'x', '.', ' ', 'T', 'h', 'e', ' ', 't', 'y', 'p', 'e', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};

/** The "Could not get array elements index. The type is null." message. */
static const char* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE = COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_ARRAY;

/** The "Could not get array elements index. The type is null." message count. */
static const int COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_COUNT = 53;

//
// File log messages.
//

/*??
"Read file."
"Could not read file. The file is null."
"Could not read file. The array size is null."
"Could not read file. The array count is null."
"Could not read file. The file name count is null."
//?? copy the same for write, plus:
"Could not write file. A write error occured."
*/

//
// Cybol log messages.
//

//
// Boolean log messages.
//

/*??
"Initialize boolean."
"Could not initialize boolean. The transient model is null."
"Could not initialize boolean. The persistent model count is null."
"Finalize boolean."
"Could not finalize boolean. The transient model is null."
"Could not finalize boolean. The persistent model is null."
"Could not finalize boolean. The persistent model count is null."
*/

//
// Integer log messages.
//

/*??
"Initialize integer."
"Finalize integer."
*/

//
// Fraction log messages.
//

/*??
"Create fraction."
"Destroy fraction."
"Initialize fraction."
"Finalize fraction."
*/

//
// Vector log messages.
//

/*??
"Create vector."
"Destroy vector."
"Initialize vector."
"Finalize vector."
*/

//
// Time log messages.
//

/*??
"Create time."
"Destroy time."
"Initialize time."
"Finalize time."
*/

//
// Double log messages.
//

/*??
"Initialize double."
"Finalize double."
*/

//
// Complex log messages.
//

/*??
"Create complex."
"Destroy complex."
"Initialize complex."
"Finalize complex."
*/

//
// String log messages.
//

/*??
"Initialize string."
"Could not initialize string. The transient model is null."
"Could not initialize string. The transient model count is null."
"Could not initialize string. The persistent model is null."
"Could not initialize string. The persistent model count is null."

//?? copy the same 5 lines for finalize string!
*/

//
// Operation log messages.
//

/** The "Create operation." message array, pointer, count. */
static const char CREATE_OPERATION_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static const char* CREATE_OPERATION_MESSAGE = CREATE_OPERATION_MESSAGE_ARRAY;
static const int CREATE_OPERATION_MESSAGE_COUNT = 17;

/** The "Destroy operation." message array, pointer, count. */
static const char DESTROY_OPERATION_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static const char* DESTROY_OPERATION_MESSAGE = DESTROY_OPERATION_MESSAGE_ARRAY;
static const int DESTROY_OPERATION_MESSAGE_COUNT = 18;

/** The "Initialize operation." message array, pointer, count. */
static const char INITIALIZE_OPERATION_MESSAGE_ARRAY[] = {'I', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static const char* INITIALIZE_OPERATION_MESSAGE = INITIALIZE_OPERATION_MESSAGE_ARRAY;
static const int INITIALIZE_OPERATION_MESSAGE_COUNT = 21;

/*??
"Could not initialize operation. There are no remaining parameters after the separator."
"Could not initialize operation. The index exceeds the count."
"Could not initialize operation. There is no parameter before the separator."
"Could not initialize operation. The transient model is null."
"Could not initialize operation. The transient model count is null."
"Could not initialize operation. The persistent model is null."
"Could not initialize operation. The persistent model count is null."
*/

//?? copy the same 8 lines for finalize operation!

/** The "Finalize operation." message array, pointer, count. */
static const char FINALIZE_OPERATION_MESSAGE_ARRAY[] = {'F', 'i', 'n', 'a', 'l', 'i', 'z', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', '.'};
static const char* FINALIZE_OPERATION_MESSAGE = FINALIZE_OPERATION_MESSAGE_ARRAY;
static const int FINALIZE_OPERATION_MESSAGE_COUNT = 19;

//
// Compound log messages.
//

/*??
"Create compound."
"Destroy compound."
"Get model part index."
"Could not get model part index. The name size is null."
"Could not get model part index. The index is null."
"Set model part by index."
"Could not set model part by index. The index exceeds the size."
"Could not set model part by index. The index is negativ."
"Could not set model part by index. The index is null."
"Could not set model part by name. A part with that name does not exist."
"Could not set model part by name. The full name ends with a separator."
"Could not set model part by name. The full name starts with a separator."
"Could not set model part by name. The separator index exceeds the full name size."
"Could not set model part by name. The separator index is negative."
"Could not set model part by name. The name is null."
"Could not set model part by name. The name size is null."
"Set model part by name."
"Add model part by name."
"Remove model part by index."
"Could not remove model part by index. The index exceeds the size."
"Could not remove model part by index. The index is negativ."
"Could not remove model part by index. The index is null."
"Could not remove model part by name. A part with that name does not exist."
"Could not remove model part by name. The full name ends with a separator."
"Could not remove model part by name. The full name starts with a separator."
"Could not remove model part by name. The separator index exceeds the full name size."
"Could not remove model part by name. The separator index is negative."
"Could not remove model part by name. The name is null."
"Could not remove model part by name. The name size is null."
"Remove model part by name."
"Could not remove model part by name. A part with that name does not exist."
"Get model part by index."
"Could not get model part by index. The index exceeds the size."
"Could not get model part by index. The index is negativ."
"Could not get model part by index. The index is null."
"Could not get model part by name. A part with that name does not exist."
"Could not get model part by name. The full name ends with a separator."
"Could not get model part by name. The full name starts with a separator."
"Could not get model part by name. The separator index exceeds the full name size."
"Could not get model part by name. The separator index is negative."
"Could not get model part by name. The name is null."
"Could not get model part by name. The name size is null."
"Get model part by name."
"Could not get model part by name. A part with that name does not exist."
*/

//
// Create model log messages.
//

/*??
"Could not read model. The location count is null."
"Could not interpret model. The persistent model count is null."
"Could not interpret model. The abstraction count is null."
*/

//
// Destroy model log messages.
//

/*??
"Could not write model. The location count is null."
"Could not serialize model. The persistent model count is null."
"Could not serialize model. The abstraction count is null."
*/

//
// Add log messages.
//

//
// Signal memory log messages.
//

/** The "Create signal memory." message array, pointer, count. */
static const char CREATE_SIGNAL_MEMORY_MESSAGE_ARRAY[] = {'C', 'r', 'e', 'a', 't', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'm', 'e', 'm', 'o', 'r', 'y', '.'};
static const char* CREATE_SIGNAL_MEMORY_MESSAGE = CREATE_SIGNAL_MEMORY_MESSAGE_ARRAY;
static const int CREATE_SIGNAL_MEMORY_MESSAGE_COUNT = 21;

/** The "Destroy signal memory." message array, pointer, count. */
static const char DESTROY_SIGNAL_MEMORY_MESSAGE_ARRAY[] = {'D', 'e', 's', 't', 'r', 'o', 'y', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'm', 'e', 'm', 'o', 'r', 'y', '.'};
static const char* DESTROY_SIGNAL_MEMORY_MESSAGE = DESTROY_SIGNAL_MEMORY_MESSAGE_ARRAY;
static const int DESTROY_SIGNAL_MEMORY_MESSAGE_COUNT = 22;

/*??
"Could not set signal. The index exceeds the size."
"Could not set signal. The index is negativ."
"Could not remove signal. The index exceeds the count."
"Could not remove signal. The index is negativ."
"Could not remove signal. The index is null."
"Could not get signal. The index exceeds the count."
"Could not get signal. The index is negativ."
"Could not get signal. The index is null."
"Could not get highest priority index. The index is null."
*/

/** The "Handle compound signal." message array, pointer, count. */
static const char HANDLE_COMPOUND_SIGNAL_MESSAGE_ARRAY[] = {'H', 'a', 'n', 'd', 'l', 'e', ' ', 'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd', ' ', 's', 'i', 'g', 'n', 'a', 'l', '.'};
static const char* HANDLE_COMPOUND_SIGNAL_MESSAGE = HANDLE_COMPOUND_SIGNAL_MESSAGE_ARRAY;
static const int HANDLE_COMPOUND_SIGNAL_MESSAGE_COUNT = 23;

/** The "Handle operation signal." message array, pointer, count. */
static const char HANDLE_OPERATION_SIGNAL_MESSAGE_ARRAY[] = {'H', 'a', 'n', 'd', 'l', 'e', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 's', 'i', 'g', 'n', 'a', 'l', '.'};
static const char* HANDLE_OPERATION_SIGNAL_MESSAGE = HANDLE_OPERATION_SIGNAL_MESSAGE_ARRAY;
static const int HANDLE_OPERATION_SIGNAL_MESSAGE_COUNT = 24;

/** The "Set shutdown flag." message array, pointer, count. */
static const char SET_SHUTDOWN_FLAG_MESSAGE_ARRAY[] = {'S', 'e', 't', ' ', 's', 'h', 'u', 't', 'd', 'o', 'w', 'n', ' ', 'f', 'l', 'a', 'g', '.'};
static const char* SET_SHUTDOWN_FLAG_MESSAGE = SET_SHUTDOWN_FLAG_MESSAGE_ARRAY;
static const int SET_SHUTDOWN_FLAG_MESSAGE_COUNT = 18;

//
// Internals log messages.
//

//
// Character screen log messages.
//

//
// X Windows log messages.
//

//
// Cyboi log messages.
//

/** The "Wait for signals." message array, pointer, count. */
static const char WAIT_FOR_SIGNALS_MESSAGE_ARRAY[] = {'W', 'a', 'i', 't', ' ', 'f', 'o', 'r', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', '.'};
static const char* WAIT_FOR_SIGNALS_MESSAGE = WAIT_FOR_SIGNALS_MESSAGE_ARRAY;
static const int WAIT_FOR_SIGNALS_MESSAGE_COUNT = 17;

/** The "Could not handle signal. The signal abstraction is unknown." message array, pointer, count. */
static const char COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'h', 'a', 'n', 'd', 'l', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', '.', ' ', 'T', 'h', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'a', 'b', 's', 't', 'r', 'a', 'c', 't', 'i', 'o', 'n', ' ', 'i', 's', ' ', 'u', 'n', 'k', 'n', 'o', 'w', 'n', '.'};
static const char* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE = COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_ARRAY;
static const int COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_COUNT = 59;

/** The "Could not wait for signals. The internals is null." message array, pointer, count. */
static const char COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'w', 'a', 'i', 't', ' ', 'f', 'o', 'r', ' ', 's', 'i', 'g', 'n', 'a', 'l', 's', '.', ' ', 'T', 'h', 'e', ' ', 'i', 'n', 't', 'e', 'r', 'n', 'a', 'l', 's', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static const char* COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE = COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_ARRAY;
static const int COULD_NOT_WAIT_FOR_SIGNALS_THE_INTERNALS_IS_NULL_MESSAGE_COUNT = 50;

/** The "Exit CYBOI normally." message array, pointer, count. */
static const char EXIT_CYBOI_NORMALLY_MESSAGE_ARRAY[] = {'E', 'x', 'i', 't', ' ', 'C', 'Y', 'B', 'O', 'I', ' ', 'n', 'o', 'r', 'm', 'a', 'l', 'l', 'y', '.'};
static const char* EXIT_CYBOI_NORMALLY_MESSAGE = EXIT_CYBOI_NORMALLY_MESSAGE_ARRAY;
static const int EXIT_CYBOI_NORMALLY_MESSAGE_COUNT = 20;

/** The "Could not execute CYBOI. The command line argument number is incorrect." message array, pointer, count. */
static const char COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'e', 'x', 'e', 'c', 'u', 't', 'e', ' ', 'C', 'Y', 'B', 'O', 'I', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'l', 'i', 'n', 'e', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', ' ', 'n', 'u', 'm', 'b', 'e', 'r', ' ', 'i', 's', ' ', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c', 't', '.'};
static const char* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE = COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_ARRAY;
static const int COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_NUMBER_IS_INCORRECT_MESSAGE_COUNT = 71;

/** The "Usage: " message array, pointer, count. */
static const char USAGE_MESSAGE_ARRAY[] = {
    'P', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', 's', ' ', 'h', 'a', 'v', 'e', ' ', 't', 'o', ' ', 'b', 'e', ' ', 'g', 'i', 'v', 'e', 'n', '!', '\n',
    'U', 's', 'a', 'g', 'e', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd', '|', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'l', 'i', 'n', 'e', '|', 'f', 'i', 'l', 'e', '|', 'f', 't', 'p', '|', 'h', 't', 't', 'p', ' ', 'm', 'o', 'd', 'e', 'l', '.', 's', 'u', 'b', 'm', 'o', 'd', 'e', 'l', '\n',
    'E', 'x', 'a', 'm', 'p', 'l', 'e', ' ', '1', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', 'i', 'n', 'l', 'i', 'n', 'e', ' ', 'e', 'x', 'i', 't', '\n',
    'E', 'x', 'a', 'm', 'p', 'l', 'e', ' ', '2', ':', ' ', 'c', 'y', 'b', 'o', 'i', ' ', 'c', 'o', 'm', 'p', 'o', 'u', 'n', 'd', ' ', 'f', 'i', 'l', 'e', ' ', '/', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', '/', 'l', 'o', 'g', 'i', 'c', '/', 's', 't', 'a', 'r', 't', 'u', 'p', '.', 'c', 'y', 'b', 'o', 'l'};
static const char* USAGE_MESSAGE = USAGE_MESSAGE_ARRAY;
static const int USAGE_MESSAGE_COUNT = 199;

/** The "Could not execute CYBOI. The command line argument vector is null." message array, pointer, count. */
static const char COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_ARRAY[] = {'C', 'o', 'u', 'l', 'd', ' ', 'n', 'o', 't', ' ', 'e', 'x', 'e', 'c', 'u', 't', 'e', ' ', 'C', 'Y', 'B', 'O', 'I', '.', ' ', 'T', 'h', 'e', ' ', 'c', 'o', 'm', 'm', 'a', 'n', 'd', ' ', 'l', 'i', 'n', 'e', ' ', 'a', 'r', 'g', 'u', 'm', 'e', 'n', 't', ' ', 'v', 'e', 'c', 't', 'o', 'r', ' ', 'i', 's', ' ', 'n', 'u', 'l', 'l', '.'};
static const char* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE = COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_ARRAY;
static const int COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_COUNT = 66;

/* LOG_CONSTANTS_SOURCE */
#endif
