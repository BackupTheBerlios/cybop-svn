/*
 * $RCSfile: statics_models.c,v $
 *
 * Copyright (c) 1999-2004. Christian Heller. All rights reserved.
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

#ifndef STATICS_MODELS_SOURCE
#define STATICS_MODELS_SOURCE

/**
 * This is the statics models.
 *
 * It defines constants for static models.
 *
 * There are complex and primitive static models.
 * Complex models consist of other complex models and primitive models.
 * Primitive models are the final abstraction in software.
 *
 * @version $Revision: 1.4 $ $Date: 2004-02-29 19:55:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Operation models.
//

/** The operation model. */
static const char* OPERATION_MODEL = "operation";

//
// Primitive models.
//

/** The boolean model. */
static const char* BOOLEAN_MODEL = "boolean";

/** The integer model. */
static const char* INTEGER_MODEL = "integer";

/** The fraction model. */
static const char* FRACTION_MODEL = "fraction";

/** The complex model. */
static const char* COMPLEX_MODEL = "complex";

/** The vector model. */
static const char* VECTOR_MODEL = "vector";

/** The string model. */
static const char* STRING_MODEL = "string";

/** The time model. */
static const char* TIME_MODEL = "time";

//
// Audio models.
//

/** The mp3 model. */
static const char* MP3_MODEL = "mp3";

//
// Image models.
//

/** The jpeg model. */
static const char* JPEG_MODEL = "jpeg";

/** The gif model. */
static const char* GIF_MODEL = "gif";

/** The bmp model. */
static const char* BMP_MODEL = "bmp";

//
// Text models.
//

/** The sgml model. */
static const char* SGML_MODEL = "sgml";

/** The xml model. */
static const char* XML_MODEL = "xml";

/** The html model. */
static const char* HTML_MODEL = "html";

/** The rtf model. */
static const char* RTF_MODEL = "rtf";

/** The tex model. */
static const char* TEX_MODEL = "tex";

//
// Video models.
//

/** The mpeg model. */
static const char* MPEG_MODEL = "mpeg";

/** The quicktime model. */
static const char* QUICKTIME_MODEL = "qt";

//
// Application models.
//

/** The koffice kword model. */
static const char* KWORD_MODEL = "kword";

/** The open office writer model. */
static const char* SXW_MODEL = "sxw";

/* STATICS_MODELS_SOURCE */
#endif
