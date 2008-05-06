/*
 * $RCSfile: audio_mime_type_constants.c,v $
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

#ifndef AUDIO_MIME_TYPE_CONSTANTS_SOURCE
#define AUDIO_MIME_TYPE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The vorbis audio mime type. */
static wchar_t VORBIS_AUDIO_MIME_TYPE_ARRAY[] = {L'a', L'u', L'd', L'i', L'o', L'/', L'v', L'o', L'r', L'b', L'i', L's'};
static wchar_t* VORBIS_AUDIO_MIME_TYPE = VORBIS_AUDIO_MIME_TYPE_ARRAY;
static int* VORBIS_AUDIO_MIME_TYPE_COUNT = NUMBER_12_INTEGER_ARRAY;

/* AUDIO_MIME_TYPE_CONSTANTS_SOURCE */
#endif
