/*
 * $RCSfile: text_file_extension_constants.c,v $
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

#ifndef TEXT_FILE_EXTENSION_CONSTANTS_SOURCE
#define TEXT_FILE_EXTENSION_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The html file extension. */
static wchar_t HTML_FILE_EXTENSION_ARRAY[] = {L'h', L't', L'm', L'l'};
static wchar_t* HTML_FILE_EXTENSION = HTML_FILE_EXTENSION_ARRAY;
static int* HTML_FILE_EXTENSION_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The htm file extension. */
static wchar_t HTM_FILE_EXTENSION_ARRAY[] = {L'h', L't', L'm'};
static wchar_t* HTM_FILE_EXTENSION = HTM_FILE_EXTENSION_ARRAY;
static int* HTM_FILE_EXTENSION_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The shtml file extension. */
static wchar_t SHTML_FILE_EXTENSION_ARRAY[] = {L's', L'h', L't', L'm', L'l'};
static wchar_t* SHTML_FILE_EXTENSION = SHTML_FILE_EXTENSION_ARRAY;
static int* SHTML_FILE_EXTENSION_COUNT = NUMBER_5_INTEGER_ARRAY;

/* TEXT_FILE_EXTENSION_CONSTANTS_SOURCE */
#endif
