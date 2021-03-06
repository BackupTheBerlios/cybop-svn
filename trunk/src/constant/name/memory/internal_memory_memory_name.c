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
 * @version $RCSfile: internal_memory_memory_name.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERNAL_MEMORY_MEMORY_NAME_SOURCE
#define INTERNAL_MEMORY_MEMORY_NAME_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

/** The knowledge memory. */
static int* KNOWLEDGE_MEMORY_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The signal memory. */
static int* SIGNAL_MEMORY_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;
static int* SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;
static int* SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;
static int* SIGNAL_MEMORY_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The gnu linux console. */
static int* GNU_LINUX_CONSOLE_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_100_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_101_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_ORIGINAL_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_105_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_WORKING_ATTRIBUTES_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_106_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_110_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_111_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_112_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_HANDLER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_113_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_120_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_121_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_122_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_ROOT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_190_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_ROOT_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_191_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_ROOT_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_192_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_COMMANDS_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_193_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_COMMANDS_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_194_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_COMMANDS_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_195_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_196_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_197_INTEGER_MEMORY_MODEL_ARRAY;
static int* GNU_LINUX_CONSOLE_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_198_INTEGER_MEMORY_MODEL_ARRAY;

/** The x window system. */
static int* X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_200_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_201_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_SCREEN_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_202_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_203_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_204_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_205_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_206_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_HANDLER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_210_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_230_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_231_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_240_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_BACKGROUND_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_241_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_FOREGROUND_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_242_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_250_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_251_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_252_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_253_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_TOP_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_254_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_255_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_FONT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_256_INTEGER_MEMORY_MODEL_ARRAY;
//?? static int* X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_257_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_ROOT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_290_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_ROOT_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_291_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_ROOT_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_292_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_COMMANDS_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_293_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_COMMANDS_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_294_INTEGER_MEMORY_MODEL_ARRAY;
static int* X_WINDOW_SYSTEM_THREAD_COMMANDS_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_295_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The server socket base numbers (segment).
 * There is one for each service.
 * The difference between base numbers (offset) depends on the amount of index numbers.
 * It currently has a value of 25. See further below!
 */
static int* TCP_MUX_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_500_INTEGER_MEMORY_MODEL_ARRAY;
static int* FTP_DATA_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_525_INTEGER_MEMORY_MODEL_ARRAY;
static int* FTP_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_550_INTEGER_MEMORY_MODEL_ARRAY;
static int* FSP_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_575_INTEGER_MEMORY_MODEL_ARRAY;
static int* SSH_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_600_INTEGER_MEMORY_MODEL_ARRAY;
static int* TELNET_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_625_INTEGER_MEMORY_MODEL_ARRAY;
static int* SMTP_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_650_INTEGER_MEMORY_MODEL_ARRAY;
static int* WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_675_INTEGER_MEMORY_MODEL_ARRAY;
static int* POP3_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_700_INTEGER_MEMORY_MODEL_ARRAY;
static int* HTTPS_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_725_INTEGER_MEMORY_MODEL_ARRAY;
static int* CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_750_INTEGER_MEMORY_MODEL_ARRAY;

/** The server socket index numbers, to be added on top of a base number. */
static int* SOCKET_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_ADDRESS_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_HANDLER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/*??
static int* SOCKET_COMMANDS_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_COMMANDS_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_LANGUAGE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_LANGUAGE_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_STYLE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_STYLE_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;
*/
static int* SOCKET_CHARACTER_BUFFER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_40_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_41_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_COMMUNICATION_PARTNER_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_COMMUNICATION_PARTNER_ADDRESS_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;
static int* SOCKET_COMMUNICATION_PARTNER_ADDRESS_SIZE_INTERNAL_MEMORY_MEMORY_NAME = NUMBER_52_INTEGER_MEMORY_MODEL_ARRAY;

/* INTERNAL_MEMORY_MEMORY_NAME_SOURCE */
#endif
