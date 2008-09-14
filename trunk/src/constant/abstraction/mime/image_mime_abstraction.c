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
 * @version $RCSfile: image_mime_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef IMAGE_MIME_ABSTRACTION_SOURCE
#define IMAGE_MIME_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//

//
// Image.
//
// IANA media type: image
//

/**
 * The image/gif cybol abstraction.
 *
 * GIF image.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: gif
 */
static wchar_t GIF_IMAGE_MIME_ABSTRACTION_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L'g', L'i', L'f'};
static wchar_t* GIF_IMAGE_MIME_ABSTRACTION = GIF_IMAGE_MIME_ABSTRACTION_ARRAY;
static int* GIF_IMAGE_MIME_ABSTRACTION_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The image/jpeg cybol abstraction.
 *
 * JPEG JFIF image.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: jpeg, jpg, jpe
 */
static wchar_t JPEG_IMAGE_MIME_ABSTRACTION_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L'j', L'p', L'e', L'g'};
static wchar_t* JPEG_IMAGE_MIME_ABSTRACTION = JPEG_IMAGE_MIME_ABSTRACTION_ARRAY;
static int* JPEG_IMAGE_MIME_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The image/png cybol abstraction.
 *
 * Portable Network Graphics.
 * Registered.
 * Suffixes: png
 */
static wchar_t PNG_IMAGE_MIME_ABSTRACTION_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L'p', L'n', L'g'};
static wchar_t* PNG_IMAGE_MIME_ABSTRACTION = PNG_IMAGE_MIME_ABSTRACTION_ARRAY;
static int* PNG_IMAGE_MIME_ABSTRACTION_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The image/tiff cybol abstraction.
 *
 * Tag Image File Format.
 * Defined in RFC 3302.
 * Suffixes: tiff, tif
 */
static wchar_t TIFF_IMAGE_MIME_ABSTRACTION_ARRAY[] = {L'i', L'm', L'a', L'g', L'e', L'/', L't', L'i', L'f', L'f'};
static wchar_t* TIFF_IMAGE_MIME_ABSTRACTION = TIFF_IMAGE_MIME_ABSTRACTION_ARRAY;
static int* TIFF_IMAGE_MIME_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/*??
The image/vnd.microsoft.icon language.
ICO image.
Registered.
*/

/* IMAGE_MIME_ABSTRACTION_SOURCE */
#endif
