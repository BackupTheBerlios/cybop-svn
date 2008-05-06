/*
 * $RCSfile: cybol_channel_constants.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.3 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOL_CHANNEL_CONSTANTS_SOURCE
#define CYBOL_CHANNEL_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The inline channel. */
static wchar_t INLINE_CHANNEL_ARRAY[] = {L'i', L'n', L'l', L'i', L'n', L'e'};
static wchar_t* INLINE_CHANNEL = INLINE_CHANNEL_ARRAY;
static int* INLINE_CHANNEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The file channel. */
static wchar_t FILE_CHANNEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_CHANNEL = FILE_CHANNEL_ARRAY;
static int* FILE_CHANNEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The shell channel. */
static wchar_t SHELL_CHANNEL_ARRAY[] = {L's', L'h', L'e', L'l', L'l'};
static wchar_t* SHELL_CHANNEL = SHELL_CHANNEL_ARRAY;
static int* SHELL_CHANNEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The http location. */
static wchar_t HTTP_CHANNEL_ARRAY[] = {L'h', L't', L't', L'p'};
static wchar_t* HTTP_CHANNEL = HTTP_CHANNEL_ARRAY;
static int* HTTP_CHANNEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The ftp channel. */
static wchar_t FTP_CHANNEL_ARRAY[] = {L'f', L't', L'p'};
static wchar_t* FTP_CHANNEL = FTP_CHANNEL_ARRAY;
static int* FTP_CHANNEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The sftp channel. */
static wchar_t SFTP_CHANNEL_ARRAY[] = {L's', L'f', L't', L'p'};
static wchar_t* SFTP_CHANNEL = SFTP_CHANNEL_ARRAY;
static int* SFTP_CHANNEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/* CYBOL_CHANNEL_CONSTANTS_SOURCE */
#endif
