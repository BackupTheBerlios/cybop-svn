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
 * @version $RCSfile: message_log_model.c,v $ $Revision: 1.5 $ $Date: 2008-09-09 21:17:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_LOG_MODEL_SOURCE
#define MESSAGE_LOG_MODEL_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// Pointer array log messages.
//

/** The "Create pointer array." message log model. */
static wchar_t CREATE_POINTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* CREATE_POINTER_ARRAY_MESSAGE_LOG_MODEL = CREATE_POINTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_POINTER_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create pointer array. The array is null." message log model. */
static wchar_t COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create pointer array. The count is null." message log model. */
static wchar_t COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy pointer array." message log model. */
static wchar_t DESTROY_POINTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* DESTROY_POINTER_ARRAY_MESSAGE_LOG_MODEL = DESTROY_POINTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_POINTER_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy pointer array. The array is null." message log model. */
static wchar_t COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy pointer array. The count is null." message log model. */
static wchar_t COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Resize pointer array." message log model. */
static wchar_t RESIZE_POINTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'R', L'e', L's', L'i', L'z', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* RESIZE_POINTER_ARRAY_MESSAGE_LOG_MODEL = RESIZE_POINTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* RESIZE_POINTER_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize pointer array. The array is null." message log model. */
static wchar_t COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_POINTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize pointer array. The count is null." message log model. */
static wchar_t COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_POINTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare pointer array elements. The first array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'f', L'i', L'r', L's', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare pointer array elements. The second array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'e', L'c', L'o', L'n', L'd', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare pointer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare pointer array elements. The result is null." message log model. */
static wchar_t COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'r', L'e', L's', L'u', L'l', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_POINTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set pointer array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set pointer array elements. The index is null." message log model. */
static wchar_t COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set pointer array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set pointer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove pointer array elements. The array is null." message log model. */
static wchar_t COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove pointer array elements. The size is null." message log model. */
static wchar_t COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove pointer array elements. The index is null." message log model. */
static wchar_t COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove pointer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array elements. The index is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array element index. The array is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array element index. The size is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array element index. The comparison array is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_72_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array element index. The count is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get pointer array element index. The index is null." message log model. */
static wchar_t COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'p', L'o', L'i', L'n', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_POINTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

//
// Integer array log messages.
//

/** The "Create integer array." message log model. */
static wchar_t CREATE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* CREATE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL = CREATE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create integer array. The array is null." message log model. */
static wchar_t COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create integer array. The count is null." message log model. */
static wchar_t COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy integer array." message log model. */
static wchar_t DESTROY_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* DESTROY_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL = DESTROY_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy integer array. The array is null." message log model. */
static wchar_t COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy integer array. The count is null." message log model. */
static wchar_t COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Resize integer array." message log model. */
static wchar_t RESIZE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'R', L'e', L's', L'i', L'z', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* RESIZE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL = RESIZE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* RESIZE_INTEGER_MEMORY_MODEL_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize integer array. The array is null." message log model. */
static wchar_t COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize integer array. The count is null." message log model. */
static wchar_t COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_INTEGER_MEMORY_MODEL_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare integer array elements. The first array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'f', L'i', L'r', L's', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare integer array elements. The second array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'e', L'c', L'o', L'n', L'd', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare integer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare integer array elements. The result is null." message log model. */
static wchar_t COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'r', L'e', L's', L'u', L'l', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set integer array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set integer array elements. The index is null." message log model. */
static wchar_t COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set integer array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set integer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove integer array elements. The array is null." message log model. */
static wchar_t COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove integer array elements. The size is null." message log model. */
static wchar_t COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove integer array elements. The index is null." message log model. */
static wchar_t COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove integer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array elements. The index is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array elements. The count is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array element index. The array is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array element index. The size is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array element index. The comparison array is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_72_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array element index. The count is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get integer array element index. The index is null." message log model. */
static wchar_t COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'i', L'n', L't', L'e', L'g', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_INTEGER_MEMORY_MODEL_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

//
// Unsigned long array log messages.
//

/** The "Create unsigned long array." message log model. */
static wchar_t CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL = CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create unsigned long array. The array is null." message log model. */
static wchar_t COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create unsigned long array. The count is null." message log model. */
static wchar_t COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy unsigned long array." message log model. */
static wchar_t DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL = DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_28_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy unsigned long array. The array is null." message log model. */
static wchar_t COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_57_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy unsigned long array. The count is null." message log model. */
static wchar_t COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_57_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Resize unsigned long array." message log model. */
static wchar_t RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'R', L'e', L's', L'i', L'z', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL = RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* RESIZE_UNSIGNED_LONG_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_27_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize unsigned long array. The array is null." message log model. */
static wchar_t COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize unsigned long array. The count is null." message log model. */
static wchar_t COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_UNSIGNED_LONG_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare unsigned long array elements. The first array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'f', L'i', L'r', L's', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_72_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare unsigned long array elements. The second array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'e', L'c', L'o', L'n', L'd', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_73_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare unsigned long array elements. The count is null." message log model. */
static wchar_t COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare unsigned long array elements. The result is null." message log model. */
static wchar_t COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'r', L'e', L's', L'u', L'l', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set unsigned long array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_74_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set unsigned long array elements. The index is null." message log model. */
static wchar_t COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_62_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set unsigned long array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_69_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set unsigned long array elements. The count is null." message log model. */
static wchar_t COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_62_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove unsigned long array elements. The array is null." message log model. */
static wchar_t COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_65_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove unsigned long array elements. The size is null." message log model. */
static wchar_t COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_64_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove unsigned long array elements. The index is null." message log model. */
static wchar_t COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_65_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove unsigned long array elements. The count is null." message log model. */
static wchar_t COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_65_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_69_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array elements. The index is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_62_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_74_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array elements. The count is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_62_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array element index. The array is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array element index. The size is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array element index. The comparison array is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_78_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array element index. The count is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get unsigned long array element index. The index is null." message log model. */
static wchar_t COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'u', L'n', L's', L'i', L'g', L'n', L'e', L'd', L' ', L'l', L'o', L'n', L'g', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_UNSIGNED_LONG_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

//
// Character array log messages.
//

/** The "Create character array." message log model. */
static wchar_t CREATE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* CREATE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL = CREATE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create character array. The array is null." message log model. */
static wchar_t COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create character array. The count is null." message log model. */
static wchar_t COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy character array." message log model. */
static wchar_t DESTROY_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* DESTROY_CHARACTER_ARRAY_MESSAGE_LOG_MODEL = DESTROY_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy character array. The array is null." message log model. */
static wchar_t COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy character array. The count is null." message log model. */
static wchar_t COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Resize character array." message log model. */
static wchar_t RESIZE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'R', L'e', L's', L'i', L'z', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* RESIZE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL = RESIZE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* RESIZE_CHARACTER_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize character array. The array is null." message log model. */
static wchar_t COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize character array. The count is null." message log model. */
static wchar_t COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_CHARACTER_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare character array elements. The first array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'f', L'i', L'r', L's', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare character array elements. The second array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'e', L'c', L'o', L'n', L'd', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare character array elements. The count is null." message log model. */
static wchar_t COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare character array elements. The result is null." message log model. */
static wchar_t COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'r', L'e', L's', L'u', L'l', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_CHARACTER_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set character array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_70_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set character array elements. The index is null." message log model. */
static wchar_t COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set character array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_65_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set character array elements. The count is null." message log model. */
static wchar_t COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove character array elements. The array is null." message log model. */
static wchar_t COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove character array elements. The size is null." message log model. */
static wchar_t COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove character array elements. The index is null." message log model. */
static wchar_t COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove character array elements. The count is null." message log model. */
static wchar_t COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array elements. The index is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_70_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array elements. The count is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array element index. The array is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array element index. The size is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array element index. The comparison array is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_72_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array element index. The count is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get character array element index. The index is null." message log model. */
static wchar_t COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'c', L'h', L'a', L'r', L'a', L'c', L't', L'e', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_CHARACTER_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

//
// Double array log messages.
//

/** The "Create double array." message log model. */
static wchar_t CREATE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* CREATE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL = CREATE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create double array. The array is null." message log model. */
static wchar_t COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not create double array. The count is null." message log model. */
static wchar_t COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy double array." message log model. */
static wchar_t DESTROY_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* DESTROY_DOUBLE_ARRAY_MESSAGE_LOG_MODEL = DESTROY_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy double array. The array is null." message log model. */
static wchar_t COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy double array. The count is null." message log model. */
static wchar_t COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Resize double array." message log model. */
static wchar_t RESIZE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_ARRAY[] = {L'R', L'e', L's', L'i', L'z', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.'};
static wchar_t* RESIZE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL = RESIZE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_ARRAY;
static int* RESIZE_DOUBLE_ARRAY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize double array. The array is null." message log model. */
static wchar_t COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize double array. The count is null." message log model. */
static wchar_t COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_DOUBLE_ARRAY_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare double array elements. The first array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'f', L'i', L'r', L's', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_FIRST_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare double array elements. The second array is null." message log model. */
static wchar_t COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'e', L'c', L'o', L'n', L'd', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_SECOND_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare double array elements. The count is null." message log model. */
static wchar_t COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare double array elements. The result is null." message log model. */
static wchar_t COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'r', L'e', L's', L'u', L'l', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_DOUBLE_ARRAY_ELEMENTS_THE_RESULT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set double array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set double array elements. The index is null." message log model. */
static wchar_t COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set double array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set double array elements. The count is null." message log model. */
static wchar_t COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove double array elements. The array is null." message log model. */
static wchar_t COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove double array elements. The size is null." message log model. */
static wchar_t COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove double array elements. The index is null." message log model. */
static wchar_t COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove double array elements. The count is null." message log model. */
static wchar_t COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array elements. The source array is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'o', L'u', L'r', L'c', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_SOURCE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_63_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array elements. The index is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array elements. The destination array is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_DESTINATION_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array elements. The count is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENTS_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array element index. The array is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array element index. The size is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'z', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_SIZE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array element index. The comparison array is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'i', L's', L'o', L'n', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COMPARISON_ARRAY_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_72_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array element index. The count is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'u', L'n', L't', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_COUNT_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get double array element index. The index is null." message log model. */
static wchar_t COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'd', L'o', L'u', L'b', L'l', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L'd', L'e', L'x', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_DOUBLE_ARRAY_ELEMENT_INDEX_THE_INDEX_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

//
// Array log messages.
//

/** The "Could not create array. The type is null." message log model. */
static wchar_t COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'r', L'e', L'a', L't', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CREATE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_41_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not destroy array. The type is null." message log model. */
static wchar_t COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'd', L'e', L's', L't', L'r', L'o', L'y', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_DESTROY_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not resize array. The type is null." message log model. */
static wchar_t COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L's', L'i', L'z', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_RESIZE_ARRAY_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_41_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not compare array elements. The type is null." message log model. */
static wchar_t COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'o', L'm', L'p', L'a', L'r', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_COMPARE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not set array elements. The type is null." message log model. */
static wchar_t COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L's', L'e', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_SET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_47_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not remove array elements. The type is null." message log model. */
static wchar_t COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'r', L'e', L'm', L'o', L'v', L'e', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_REMOVE_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get array elements. The type is null." message log model. */
static wchar_t COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_ARRAY_ELEMENTS_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_47_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not get array elements index. The type is null." message log model. */
static wchar_t COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'g', L'e', L't', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'e', L'l', L'e', L'm', L'e', L'n', L't', L's', L' ', L'i', L'n', L'd', L'e', L'x', L'.', L' ', L'T', L'h', L'e', L' ', L't', L'y', L'p', L'e', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_GET_ARRAY_ELEMENTS_INDEX_THE_TYPE_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_53_INTEGER_MEMORY_MODEL_ARRAY;

//
// Operation log messages.
//

/** The "Create operation." message log model. */
static wchar_t CREATE_OPERATION_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'.'};
static wchar_t* CREATE_OPERATION_MESSAGE_LOG_MODEL = CREATE_OPERATION_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_OPERATION_MESSAGE_LOG_MODEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy operation." message log model. */
static wchar_t DESTROY_OPERATION_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'.'};
static wchar_t* DESTROY_OPERATION_MESSAGE_LOG_MODEL = DESTROY_OPERATION_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_OPERATION_MESSAGE_LOG_MODEL_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Initialise operation." message log model. */
static wchar_t INITIALIZE_OPERATION_MESSAGE_LOG_MODEL_ARRAY[] = {L'I', L'n', L'i', L't', L'i', L'a', L'l', L'i', L'z', L'e', L' ', L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'.'};
static wchar_t* INITIALIZE_OPERATION_MESSAGE_LOG_MODEL = INITIALIZE_OPERATION_MESSAGE_LOG_MODEL_ARRAY;
static int* INITIALIZE_OPERATION_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Finalise operation." message log model. */
static wchar_t FINALIZE_OPERATION_MESSAGE_LOG_MODEL_ARRAY[] = {L'F', L'i', L'n', L'a', L'l', L'i', L'z', L'e', L' ', L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'.'};
static wchar_t* FINALIZE_OPERATION_MESSAGE_LOG_MODEL = FINALIZE_OPERATION_MESSAGE_LOG_MODEL_ARRAY;
static int* FINALIZE_OPERATION_MESSAGE_LOG_MODEL_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

//
// Signal memory log messages.
//

/** The "Create signal memory." message log model. */
static wchar_t CREATE_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'r', L'e', L'a', L't', L'e', L' ', L's', L'i', L'g', L'n', L'a', L'l', L' ', L'm', L'e', L'm', L'o', L'r', L'y', L'.'};
static wchar_t* CREATE_SIGNAL_MEMORY_MESSAGE_LOG_MODEL = CREATE_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_ARRAY;
static int* CREATE_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_COUNT = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Destroy signal memory." message log model. */
static wchar_t DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_ARRAY[] = {L'D', L'e', L's', L't', L'r', L'o', L'y', L' ', L's', L'i', L'g', L'n', L'a', L'l', L' ', L'm', L'e', L'm', L'o', L'r', L'y', L'.'};
static wchar_t* DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_MODEL = DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_ARRAY;
static int* DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_COUNT = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Handle compound." message log model. */
static wchar_t HANDLE_COMPOUND_MESSAGE_LOG_MODEL_ARRAY[] = {L'H', L'a', L'n', L'd', L'l', L'e', L' ', L'c', L'o', L'm', L'p', L'o', L'u', L'n', L'd', L'.'};
static wchar_t* HANDLE_COMPOUND_MESSAGE_LOG_MODEL = HANDLE_COMPOUND_MESSAGE_LOG_MODEL_ARRAY;
static int* HANDLE_COMPOUND_MESSAGE_LOG_MODEL_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Handle operation." message log model. */
static wchar_t HANDLE_OPERATION_MESSAGE_LOG_MODEL_ARRAY[] = {L'H', L'a', L'n', L'd', L'l', L'e', L' ', L'o', L'p', L'e', L'r', L'a', L't', L'i', L'o', L'n', L'.'};
static wchar_t* HANDLE_OPERATION_MESSAGE_LOG_MODEL = HANDLE_OPERATION_MESSAGE_LOG_MODEL_ARRAY;
static int* HANDLE_OPERATION_MESSAGE_LOG_MODEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Set shutdown flag." message log model. */
static wchar_t SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL_ARRAY[] = {L'S', L'e', L't', L' ', L's', L'h', L'u', L't', L'd', L'o', L'w', L'n', L' ', L'f', L'l', L'a', L'g', L'.'};
static wchar_t* SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL = SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL_ARRAY;
static int* SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL_COUNT = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

//
// Cyboi log messages.
//

/** The "Check for signals." message log model. */
static wchar_t CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'h', L'e', L'c', L'k', L' ', L'f', L'o', L'r', L' ', L's', L'i', L'g', L'n', L'a', L'l', L's', L'.'};
static wchar_t* CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL = CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL_ARRAY;
static int* CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not handle signal. The signal abstraction is unknown." message log model. */
static wchar_t COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'h', L'a', L'n', L'd', L'l', L'e', L' ', L's', L'i', L'g', L'n', L'a', L'l', L'.', L' ', L'T', L'h', L'e', L' ', L's', L'i', L'g', L'n', L'a', L'l', L' ', L'a', L'b', L's', L't', L'r', L'a', L'c', L't', L'i', L'o', L'n', L' ', L'i', L's', L' ', L'u', L'n', L'k', L'n', L'o', L'w', L'n', L'.'};
static wchar_t* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_LOG_MODEL = COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_HANDLE_SIGNAL_THE_SIGNAL_ABSTRACTION_IS_UNKNOWN_MESSAGE_LOG_MODEL_COUNT = NUMBER_59_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not check for signals. The internal is null." message log model. */
static wchar_t COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'c', L'h', L'e', L'c', L'k', L' ', L'f', L'o', L'r', L' ', L's', L'i', L'g', L'n', L'a', L'l', L's', L'.', L' ', L'T', L'h', L'e', L' ', L'i', L'n', L't', L'e', L'r', L'n', L'a', L'l', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_CHECK_FOR_SIGNALS_THE_INTERNAL_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Exit CYBOI normally." message log model. */
static wchar_t EXIT_CYBOI_NORMALLY_MESSAGE_LOG_MODEL_ARRAY[] = {L'E', L'x', L'i', L't', L' ', L'C', L'Y', L'B', L'O', L'I', L' ', L'n', L'o', L'r', L'm', L'a', L'l', L'l', L'y', L'.'};
static wchar_t* EXIT_CYBOI_NORMALLY_MESSAGE_LOG_MODEL = EXIT_CYBOI_NORMALLY_MESSAGE_LOG_MODEL_ARRAY;
static int* EXIT_CYBOI_NORMALLY_MESSAGE_LOG_MODEL_COUNT = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The "Could not execute CYBOI. The command line argument vector is null." message log model. */
static wchar_t COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_LOG_MODEL_ARRAY[] = {L'C', L'o', L'u', L'l', L'd', L' ', L'n', L'o', L't', L' ', L'e', L'x', L'e', L'c', L'u', L't', L'e', L' ', L'C', L'Y', L'B', L'O', L'I', L'.', L' ', L'T', L'h', L'e', L' ', L'c', L'o', L'm', L'm', L'a', L'n', L'd', L' ', L'l', L'i', L'n', L'e', L' ', L'a', L'r', L'g', L'u', L'm', L'e', L'n', L't', L' ', L'v', L'e', L'c', L't', L'o', L'r', L' ', L'i', L's', L' ', L'n', L'u', L'l', L'l', L'.'};
static wchar_t* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_LOG_MODEL = COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_LOG_MODEL_ARRAY;
static int* COULD_NOT_EXECUTE_CYBOI_THE_COMMAND_LINE_ARGUMENT_VECTOR_IS_NULL_MESSAGE_LOG_MODEL_COUNT = NUMBER_66_INTEGER_MEMORY_MODEL_ARRAY;

/* MESSAGE_LOG_MODEL_SOURCE */
#endif
