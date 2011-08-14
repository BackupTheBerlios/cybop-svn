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
 * @version $RCSfile: cybol_channel.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CHANNEL_SOURCE
#define CYBOL_CHANNEL_SOURCE

#include <stddef.h>
#include "../../constant/model/memory/integer_memory_model.c"

/** The cyboi cybol channel. */
static wchar_t CYBOI_CYBOL_CHANNEL_ARRAY[] = {L'c', L'y', L'b', L'o', L'i'};
static wchar_t* CYBOI_CYBOL_CHANNEL = CYBOI_CYBOL_CHANNEL_ARRAY;
static int* CYBOI_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The file system cybol channel. */
static wchar_t FILE_SYSTEM_CYBOL_CHANNEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_SYSTEM_CYBOL_CHANNEL = FILE_SYSTEM_CYBOL_CHANNEL_ARRAY;
static int* FILE_SYSTEM_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The file transfer protocol (ftp) cybol channel. */
static wchar_t FTP_CYBOL_CHANNEL_ARRAY[] = {L'f', L't', L'p'};
static wchar_t* FTP_CYBOL_CHANNEL = FTP_CYBOL_CHANNEL_ARRAY;
static int* FTP_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The gnu linux console cybol channel. */
static wchar_t GNU_LINUX_CONSOLE_CYBOL_CHANNEL_ARRAY[] = {L'g', L'n', L'u', L'-', L'l', L'i', L'n', L'u', L'x', L'-', L'c', L'o', L'n', L's', L'o', L'l', L'e'};
static wchar_t* GNU_LINUX_CONSOLE_CYBOL_CHANNEL = GNU_LINUX_CONSOLE_CYBOL_CHANNEL_ARRAY;
static int* GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The hypertext transfer protocol (http) location. */
static wchar_t HTTP_CYBOL_CHANNEL_ARRAY[] = {L'h', L't', L't', L'p'};
static wchar_t* HTTP_CYBOL_CHANNEL = HTTP_CYBOL_CHANNEL_ARRAY;
static int* HTTP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The inline cybol channel. */
static wchar_t INLINE_CYBOL_CHANNEL_ARRAY[] = {L'i', L'n', L'l', L'i', L'n', L'e'};
static wchar_t* INLINE_CYBOL_CHANNEL = INLINE_CYBOL_CHANNEL_ARRAY;
static int* INLINE_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The lamport tex (latex) cybol channel. */
static wchar_t LATEX_CYBOL_CHANNEL_ARRAY[] = {L'l', L'a', L't', L'e', L'x'};
static wchar_t* LATEX_CYBOL_CHANNEL = LATEX_CYBOL_CHANNEL_ARRAY;
static int* LATEX_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The secure file transfer protocol (sftp) cybol channel. */
static wchar_t SFTP_CYBOL_CHANNEL_ARRAY[] = {L's', L'f', L't', L'p'};
static wchar_t* SFTP_CYBOL_CHANNEL = SFTP_CYBOL_CHANNEL_ARRAY;
static int* SFTP_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The shell cybol channel. */
static wchar_t SHELL_CYBOL_CHANNEL_ARRAY[] = {L's', L'h', L'e', L'l', L'l'};
static wchar_t* SHELL_CYBOL_CHANNEL = SHELL_CYBOL_CHANNEL_ARRAY;
static int* SHELL_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The socket cybol channel. */
static wchar_t SOCKET_CYBOL_CHANNEL_ARRAY[] = {L's', L'o', L'c', L'k', L'e', L't'};
static wchar_t* SOCKET_CYBOL_CHANNEL = SOCKET_CYBOL_CHANNEL_ARRAY;
static int* SOCKET_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The world wide web (www) cybol channel. */
static wchar_t WWW_CYBOL_CHANNEL_ARRAY[] = {L'w', L'w', L'w'};
static wchar_t* WWW_CYBOL_CHANNEL = WWW_CYBOL_CHANNEL_ARRAY;
static int* WWW_CYBOL_CHANNEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The x window system cybol channel. */
static wchar_t X_WINDOW_SYSTEM_CYBOL_CHANNEL_ARRAY[] = {L'x', L'-', L'w', L'i', L'n', L'd', L'o', L'w', L'-', L's', L'y', L's', L't', L'e', L'm'};
static wchar_t* X_WINDOW_SYSTEM_CYBOL_CHANNEL = X_WINDOW_SYSTEM_CYBOL_CHANNEL_ARRAY;
static int* X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/* CYBOL_CHANNEL_SOURCE */
#endif
