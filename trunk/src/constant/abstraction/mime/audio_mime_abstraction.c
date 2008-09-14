/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: audio_mime_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef AUDIO_MIME_ABSTRACTION_SOURCE
#define AUDIO_MIME_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//

//
// Audio.
//
// IANA media type: audio
//

/**
 * The audio/mpeg cybol abstraction.
 *
 * MP3 or other MPEG audio.
 * Defined in RFC 3003.
 * Suffixes: mpeg
 */
static wchar_t MPEG_AUDIO_MIME_ABSTRACTION_ARRAY[] = {L'a', L'u', L'd', L'i', L'o', L'/', L'm', L'p', L'e', L'g'};
static wchar_t* MPEG_AUDIO_MIME_ABSTRACTION = MPEG_AUDIO_MIME_ABSTRACTION_ARRAY;
static int* MPEG_AUDIO_MIME_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/*??
audio/x-ms-wma: Windows Media Audio; Documented in Microsoft KB 288102
audio/vnd.rn-realaudio: RealAudio; Documented in RealPlayer Customer Support Answer 2559
audio/x-wav: WAV audio
*/

/**
 * The audio/vorbis cybol abstraction.
 */
static wchar_t VORBIS_AUDIO_MIME_ABSTRACTION_ARRAY[] = {L'a', L'u', L'd', L'i', L'o', L'/', L'v', L'o', L'r', L'b', L'i', L's'};
static wchar_t* VORBIS_AUDIO_MIME_ABSTRACTION = VORBIS_AUDIO_MIME_ABSTRACTION_ARRAY;
static int* VORBIS_AUDIO_MIME_ABSTRACTION_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/* AUDIO_MIME_ABSTRACTION_SOURCE */
#endif
