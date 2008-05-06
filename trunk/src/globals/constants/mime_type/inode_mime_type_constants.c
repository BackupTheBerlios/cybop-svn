/*
 * $RCSfile: inode_mime_type_constants.c,v $
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

#ifndef INODE_MIME_TYPE_CONSTANTS_SOURCE
#define INODE_MIME_TYPE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The socket inode mime type. */
static wchar_t SOCKET_INODE_MIME_TYPE_ARRAY[] = {L'i', L'n', L'o', L'd', L'e', L'/', L's', L'o', L'c', L'k', L'e', L't'};
static wchar_t* SOCKET_INODE_MIME_TYPE = SOCKET_INODE_MIME_TYPE_ARRAY;
static int* SOCKET_INODE_MIME_TYPE_COUNT = NUMBER_12_INTEGER_ARRAY;

/* INODE_MIME_TYPE_CONSTANTS_SOURCE */
#endif
