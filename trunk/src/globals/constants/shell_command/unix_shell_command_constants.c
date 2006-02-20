/*
 * $RCSfile: unix_shell_command_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2006-02-20 16:17:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_SHELL_COMMAND_CONSTANTS_SOURCE
#define UNIX_SHELL_COMMAND_CONSTANTS_SOURCE

#include "../../../globals/constants/integer_constants.c"

//
// File system commands.
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
