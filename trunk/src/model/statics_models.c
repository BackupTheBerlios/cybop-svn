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
 *
 * This file defines constants for static models.
 *
 * There are complex and primitive static models.
 * Complex models consist of other complex models and primitive models.
 * Primitive models are the final abstraction in software.
 *
 * @version $Revision: 1.8 $ $Date: 2004-04-07 15:47:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATICS_MODELS_SOURCE
#define STATICS_MODELS_SOURCE

//
// Operation models.
//

/** The operation model. */
static const char OPERATION_MODEL[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

/** The operation model size. */
static const int OPERATION_MODEL_SIZE = 9;

//
// Primitive models.
//

/** The boolean model. */
static const char BOOLEAN_MODEL[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};

/** The boolean model size. */
static const int BOOLEAN_MODEL_SIZE = 7;

/** The integer model. */
static const char INTEGER_MODEL[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};

/** The integer model size. */
static const int INTEGER_MODEL_SIZE = 7;

/** The fraction model. */
static const char FRACTION_MODEL[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The fraction model size. */
static const int FRACTION_MODEL_SIZE = 8;

/** The complex model. */
static const char COMPLEX_MODEL[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};

/** The complex model size. */
static const int COMPLEX_MODEL_SIZE = 7;

/** The vector model. */
static const char VECTOR_MODEL[] = {'v', 'e', 'c', 't', 'o', 'r'};

/** The vector model size. */
static const int VECTOR_MODEL_SIZE = 6;

/** The string model. */
static const char STRING_MODEL[] = {'s', 't', 'r', 'i', 'n', 'g'};

/** The string model size. */
static const int STRING_MODEL_SIZE = 6;

/** The time model. */
static const char TIME_MODEL[] = {'t', 'i', 'm', 'e'};

/** The time model size. */
static const int TIME_MODEL_SIZE = 4;

//
// Audio models.
//

/** The mp3 model. */
static const char MP3_MODEL[] = {'m', 'p', '3'};

/** The mp3 model size. */
static const int MP3_MODEL_SIZE = 3;

//
// Image models.
//

/** The jpeg model. */
static const char JPEG_MODEL[] = {'j', 'p', 'e', 'g'};

/** The jpeg model size. */
static const int JPEG_MODEL_SIZE = 4;

/** The gif model. */
static const char GIF_MODEL[] = {'g', 'i', 'f'};

/** The gif model size. */
static const int GIF_MODEL_SIZE = 3;

/** The bmp model. */
static const char BMP_MODEL[] = {'b', 'm', 'p'};

/** The bmp model size. */
static const int BMP_MODEL_SIZE = 3;

//
// Text models.
//

/** The sgml model. */
static const char SGML_MODEL[] = {'s', 'g', 'm', 'l'};

/** The sgml model size. */
static const int SGML_MODEL_SIZE = 4;

/** The xml model. */
static const char XML_MODEL[] = {'x', 'm', 'l'};

/** The xml model size. */
static const int XML_MODEL_SIZE = 3;

/** The html model. */
static const char HTML_MODEL[] = {'h', 't', 'm', 'l'};

/** The html model size. */
static const int HTML_MODEL_SIZE = 4;

/** The rtf model. */
static const char RTF_MODEL[] = {'r', 't', 'f'};

/** The rtf model size. */
static const int RTF_MODEL_SIZE = 3;

/** The tex model. */
static const char TEX_MODEL[] = {'t', 'e', 'x'};

/** The tex model size. */
static const int TEX_MODEL_SIZE = 3;

//
// Video models.
//

/** The mpeg model. */
static const char MPEG_MODEL[] = {'m', 'p', 'e', 'g'};

/** The mpeg model size. */
static const int MPEG_MODEL_SIZE = 4;

/** The quicktime model. */
static const char QT_MODEL[] = {'q', 't'};

/** The quicktime model size. */
static const int QT_MODEL_SIZE = 2;

//
// Application models.
//

/** The koffice kword model. */
static const char KWD_MODEL[] = {'k', 'w', 'd'};

/** The koffice kword model size. */
static const int KWORD_MODEL_SIZE = 5;

/** The open office writer model. */
static const char SXW_MODEL[] = {'s', 'x', 'w'};

/** The open office writer model size. */
static const int SXW_MODEL_SIZE = 3;

/* STATICS_MODELS_SOURCE */
#endif
