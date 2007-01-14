/*
 * $RCSfile: channel_constants.c,v $
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
 * @version $Revision: 1.9 $ $Date: 2007-01-14 22:06:48 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHANNEL_CONSTANTS_SOURCE
#define CHANNEL_CONSTANTS_SOURCE

#include "../../globals/constants/integer_constants.c"

/** The inline channel. */
static char INLINE_CHANNEL_ARRAY[] = {'i', 'n', 'l', 'i', 'n', 'e'};
static char* INLINE_CHANNEL = INLINE_CHANNEL_ARRAY;
static int* INLINE_CHANNEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The file channel. */
static char FILE_CHANNEL_ARRAY[] = {'f', 'i', 'l', 'e'};
static char* FILE_CHANNEL = FILE_CHANNEL_ARRAY;
static int* FILE_CHANNEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The http location. */
static char HTTP_CHANNEL_ARRAY[] = {'h', 't', 't', 'p'};
static char* HTTP_CHANNEL = HTTP_CHANNEL_ARRAY;
static int* HTTP_CHANNEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The ftp channel. */
static char FTP_CHANNEL_ARRAY[] = {'f', 't', 'p'};
static char* FTP_CHANNEL = FTP_CHANNEL_ARRAY;
static int* FTP_CHANNEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The sftp channel. */
static char SFTP_CHANNEL_ARRAY[] = {'s', 'f', 't', 'p'};
static char* SFTP_CHANNEL = SFTP_CHANNEL_ARRAY;
static int* SFTP_CHANNEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/* CHANNEL_CONSTANTS_SOURCE */
#endif
