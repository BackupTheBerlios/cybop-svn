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
 * @version $Revision: 1.5 $ $Date: 2004-03-11 22:44:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Operation models.
//

/** The operation model. */
static const char* OPERATION_MODEL = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

//
// Primitive models.
//

/** The boolean model. */
static const char* BOOLEAN_MODEL = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};

/** The integer model. */
static const char* INTEGER_MODEL = {'i', 'n', 't', 'e', 'g', 'e', 'r'};

/** The fraction model. */
static const char* FRACTION_MODEL = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The complex model. */
static const char* COMPLEX_MODEL = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};

/** The vector model. */
static const char* VECTOR_MODEL = {'v', 'e', 'c', 't', 'o', 'r'};

/** The string model. */
static const char* STRING_MODEL = {'s', 't', 'r', 'i', 'n', 'g'};

/** The time model. */
static const char* TIME_MODEL = {'t', 'i', 'm', 'e'};

//
// Audio models.
//

/** The mp3 model. */
static const char* MP3_MODEL = {'m', 'p', '3'};

//
// Image models.
//

/** The jpeg model. */
static const char* JPEG_MODEL = {'j', 'p', 'e', 'g'};

/** The gif model. */
static const char* GIF_MODEL = {'g', 'i', 'f'};

/** The bmp model. */
static const char* BMP_MODEL = {'b', 'm', 'p'};

//
// Text models.
//

/** The sgml model. */
static const char* SGML_MODEL = {'s', 'g', 'm', 'l'};

/** The xml model. */
static const char* XML_MODEL = {'x', 'm', 'l'};

/** The html model. */
static const char* HTML_MODEL = {'h', 't', 'm', 'l'};

/** The rtf model. */
static const char* RTF_MODEL = {'r', 't', 'f'};

/** The tex model. */
static const char* TEX_MODEL = {'t', 'e', 'x'};

//
// Video models.
//

/** The mpeg model. */
static const char* MPEG_MODEL = {'m', 'p', 'e', 'g'};

/** The quicktime model. */
static const char* QUICKTIME_MODEL = {'q', 't'};

//
// Application models.
//

/** The koffice kword model. */
static const char* KWORD_MODEL = {'k', 'w', 'o', 'r', 'd'};

/** The open office writer model. */
static const char* SXW_MODEL = {'s', 'x', 'w'};

/* STATICS_MODELS_SOURCE */
#endif
