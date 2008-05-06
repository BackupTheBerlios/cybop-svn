/*
 * $RCSfile: unix_shell_command_constants.c,v $
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
 * @version $Revision: 1.7 $ $Date: 2008-05-06 22:36:53 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_SHELL_COMMAND_CONSTANTS_SOURCE
#define UNIX_SHELL_COMMAND_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Archive command.
//

/** The archive command. */
static wchar_t ARCHIVE_UNIX_SHELL_COMMAND_ARRAY[] = {L'a', L'r', L'c', L'h', L'i', L'v', L'e'};
static wchar_t* ARCHIVE_UNIX_SHELL_COMMAND = ARCHIVE_UNIX_SHELL_COMMAND_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The archive command create option. */
static wchar_t ARCHIVE_UNIX_SHELL_COMMAND_CREATE_ARRAY[] = {L'c', L'r', L'e', L'a', L't', L'e'};
static wchar_t* ARCHIVE_UNIX_SHELL_COMMAND_CREATE = ARCHIVE_UNIX_SHELL_COMMAND_CREATE_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive command update option. */
static wchar_t ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_ARRAY[] = {L'u', L'p', L'd', L'a', L't', L'e'};
static wchar_t* ARCHIVE_UNIX_SHELL_COMMAND_UPDATE = ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive command bzip2 option. */
static wchar_t ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_ARRAY[] = {L'b', L'z', L'i', L'p', L'2'};
static wchar_t* ARCHIVE_UNIX_SHELL_COMMAND_BZIP2 = ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Copy command.
//

/** The copy command. */
static wchar_t COPY_UNIX_SHELL_COMMAND_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_UNIX_SHELL_COMMAND = COPY_UNIX_SHELL_COMMAND_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The copy command recursive option. */
static wchar_t COPY_UNIX_SHELL_COMMAND_RECURSIVE_ARRAY[] = {L'-', L'R'};
static wchar_t* COPY_UNIX_SHELL_COMMAND_RECURSIVE = COPY_UNIX_SHELL_COMMAND_RECURSIVE_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The copy command source option. */
static wchar_t COPY_UNIX_SHELL_COMMAND_SOURCE_ARRAY[] = {L's', L'o', L'u', L'r', L'c', L'e'};
static wchar_t* COPY_UNIX_SHELL_COMMAND_SOURCE = COPY_UNIX_SHELL_COMMAND_SOURCE_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copy command destination option. */
static wchar_t COPY_UNIX_SHELL_COMMAND_DESTINATION_ARRAY[] = {L'd', L'e', L's', L't', L'i', L'n', L'a', L't', L'i', L'o', L'n'};
static wchar_t* COPY_UNIX_SHELL_COMMAND_DESTINATION = COPY_UNIX_SHELL_COMMAND_DESTINATION_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// List directory contents command.
//

/** The list directory contents command. */
static wchar_t LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ARRAY[] = {L'l', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND = LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The list directory contents command all option. */
static wchar_t LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_ARRAY[] = {L'-', L'-', L'a', L'l', L'l'};
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL = LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The list directory contents command long listing option. */
static wchar_t LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_ARRAY[] = {L'-', L'l'};
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING = LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT = NUMBER_2_INTEGER_ARRAY;

/* UNIX_SHELL_COMMAND_CONSTANTS_SOURCE */
#endif
