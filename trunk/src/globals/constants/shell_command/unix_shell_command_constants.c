/*
 * $RCSfile: unix_shell_command_constants.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2007-04-16 15:34:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_SHELL_COMMAND_CONSTANTS_SOURCE
#define UNIX_SHELL_COMMAND_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

//
// Archive command.
//

/** The archive command. */
static char ARCHIVE_UNIX_SHELL_COMMAND_ARRAY[] = {'a', 'r', 'c', 'h', 'i', 'v', 'e'};
static char* ARCHIVE_UNIX_SHELL_COMMAND = ARCHIVE_UNIX_SHELL_COMMAND_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_COUNT = NUMBER_7_INTEGER_ARRAY;

/** The archive command create option. */
static char ARCHIVE_UNIX_SHELL_COMMAND_CREATE_ARRAY[] = {'c', 'r', 'e', 'a', 't', 'e'};
static char* ARCHIVE_UNIX_SHELL_COMMAND_CREATE = ARCHIVE_UNIX_SHELL_COMMAND_CREATE_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_CREATE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive command update option. */
static char ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_ARRAY[] = {'u', 'p', 'd', 'a', 't', 'e'};
static char* ARCHIVE_UNIX_SHELL_COMMAND_UPDATE = ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_UPDATE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The archive command bzip2 option. */
static char ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_ARRAY[] = {'b', 'z', 'i', 'p', '2'};
static char* ARCHIVE_UNIX_SHELL_COMMAND_BZIP2 = ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_ARRAY;
static int* ARCHIVE_UNIX_SHELL_COMMAND_BZIP2_COUNT = NUMBER_5_INTEGER_ARRAY;

//
// Copy command.
//

/** The copy command. */
static char COPY_UNIX_SHELL_COMMAND_ARRAY[] = {'c', 'o', 'p', 'y'};
static char* COPY_UNIX_SHELL_COMMAND = COPY_UNIX_SHELL_COMMAND_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The copy command recursive option. */
static char COPY_UNIX_SHELL_COMMAND_RECURSIVE_ARRAY[] = {'-', 'R'};
static char* COPY_UNIX_SHELL_COMMAND_RECURSIVE = COPY_UNIX_SHELL_COMMAND_RECURSIVE_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_RECURSIVE_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The copy command source option. */
static char COPY_UNIX_SHELL_COMMAND_SOURCE_ARRAY[] = {'s', 'o', 'u', 'r', 'c', 'e'};
static char* COPY_UNIX_SHELL_COMMAND_SOURCE = COPY_UNIX_SHELL_COMMAND_SOURCE_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_SOURCE_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The copy command destination option. */
static char COPY_UNIX_SHELL_COMMAND_DESTINATION_ARRAY[] = {'d', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n'};
static char* COPY_UNIX_SHELL_COMMAND_DESTINATION = COPY_UNIX_SHELL_COMMAND_DESTINATION_ARRAY;
static int* COPY_UNIX_SHELL_COMMAND_DESTINATION_COUNT = NUMBER_11_INTEGER_ARRAY;

//
// List directory contents command.
//

/** The list directory contents command. */
static char LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ARRAY[] = {'l', 's'};
static char* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND = LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_COUNT = NUMBER_2_INTEGER_ARRAY;

/** The list directory contents command all option. */
static char LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_ARRAY[] = {'-', '-', 'a', 'l', 'l'};
static char* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL = LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_ALL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The list directory contents command long listing option. */
static char LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_ARRAY[] = {'-', 'l'};
static char* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING = LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_SHELL_COMMAND_LONG_LISTING_COUNT = NUMBER_2_INTEGER_ARRAY;

/* UNIX_SHELL_COMMAND_CONSTANTS_SOURCE */
#endif
