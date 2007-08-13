/*
 * $RCSfile: text_file_extension_constants.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-08-03 17:10:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEXT_FILE_EXTENSION_CONSTANTS_SOURCE
#define TEXT_FILE_EXTENSION_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The html file extension. */
static char HTML_FILE_EXTENSION_ARRAY[] = {'h', 't', 'm', 'l'};
static char* HTML_FILE_EXTENSION = HTML_FILE_EXTENSION_ARRAY;
static int* HTML_FILE_EXTENSION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The htm file extension. */
static char HTM_FILE_EXTENSION_ARRAY[] = {'h', 't', 'm'};
static char* HTM_FILE_EXTENSION = HTM_FILE_EXTENSION_ARRAY;
static int* HTM_FILE_EXTENSION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The shtml file extension. */
static char SHTML_FILE_EXTENSION_ARRAY[] = {'s', 'h', 't', 'm', 'l'};
static char* SHTML_FILE_EXTENSION = SHTML_FILE_EXTENSION_ARRAY;
static int* SHTML_FILE_EXTENSION_COUNT = NUMBER_5_INTEGER_ARRAY;

/* TEXT_FILE_EXTENSION_CONSTANTS_SOURCE */
#endif