/*
 * $RCSfile: statics.c,v $
 *
 * Copyright (c) 1999-2003. Christian Heller. All rights reserved.
 *
 * This software is published under the GPL GNU General Public License.
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
 */

#ifndef STATICS_SOURCE
#define STATICS_SOURCE

/**
 * This is the statics.
 *
 * It defines constants for static operators.
 *
 * There are complex and primitive static models.
 * Complex models consist of other complex models and primitive models.
 * Primitive models are the final abstraction in software.
 *
 * @version $Revision: 1.1 $ $Date: 2003-12-01 12:33:58 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Compound model.
//

/** The statics compound. */
static const char* STATICS_COMPOUND = "compound";

//
// Primitive models.
//

/** The boolean primitive. */
static const char* BOOLEAN_PRIMITIVE = "boolean";

/** The integer primitive. */
static const char* INTEGER_PRIMITIVE = "integer";

/** The fraction primitive. */
static const char* FRACTION_PRIMITIVE = "fraction";

/** The complex primitive. */
static const char* COMPLEX_PRIMITIVE = "complex";

/** The vector primitive. */
static const char* VECTOR_PRIMITIVE = "vector";

/** The string primitive. */
static const char* STRING_PRIMITIVE = "string";

/** The time primitive. */
static const char* TIME_PRIMITIVE = "time";

//
// Application models.
//

/** The koffice kword application. */
static const char* KWORD_APPLICATION = "kword_application";

/** The open office writer application. */
static const char* SXW_APPLICATION = "sxw_application";

//
// Audio models.
//

/** The mp3 audio. */
static const char* MP3_AUDIO = "mp3_audio";

//
// Image models.
//

/** The jpeg image. */
static const char* JPEG_IMAGE = "jpeg_image";

/** The gif image. */
static const char* GIF_IMAGE = "gif_image";

/** The bmp image. */
static const char* BMP_IMAGE = "bmp_image";

//
// Text models.
//

/** The sgml text. */
static const char* SGML_TEXT = "sgml_text";

/** The xml text. */
static const char* XML_TEXT = "xml_text";

/** The html text. */
static const char* HTML_TEXT = "html_text";

/** The rtf text. */
static const char* RTF_TEXT = "rtf_text";

/** The tex text. */
static const char* TEX_TEXT = "tex_text";

//
// Video models.
//

/** The mpeg video. */
static const char* MPEG_VIDEO = "mpeg_video";

/** The quicktime video. */
static const char* QUICKTIME_VIDEO = "quicktime_video";

/* STATICS_SOURCE */
#endif

