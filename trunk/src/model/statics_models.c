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
 * @version $Revision: 1.9 $ $Date: 2004-04-21 11:06:15 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATICS_MODELS_SOURCE
#define STATICS_MODELS_SOURCE

//
// Operation models.
//

/** The operation abstraction. */
static const char OPERATION_ABSTRACTION[] = {'o', 'p', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

/** The operation abstraction size. */
static const int OPERATION_ABSTRACTION_SIZE = 9;

//
// Primitive models.
//

/** The boolean abstraction. */
static const char BOOLEAN_ABSTRACTION[] = {'b', 'o', 'o', 'l', 'e', 'a', 'n'};

/** The boolean abstraction size. */
static const int BOOLEAN_ABSTRACTION_SIZE = 7;

/** The integer abstraction. */
static const char INTEGER_ABSTRACTION[] = {'i', 'n', 't', 'e', 'g', 'e', 'r'};

/** The integer abstraction size. */
static const int INTEGER_ABSTRACTION_SIZE = 7;

/** The double abstraction. */
static const char DOUBLE_ABSTRACTION[] = {'d', 'o', 'u', 'b', 'l', 'e'};

/** The double abstraction size. */
static const int DOUBLE_ABSTRACTION_SIZE = 6;

/** The fraction abstraction. */
static const char FRACTION_ABSTRACTION[] = {'f', 'r', 'a', 'c', 't', 'i', 'o', 'n'};

/** The fraction abstraction size. */
static const int FRACTION_ABSTRACTION_SIZE = 8;

/** The complex abstraction. */
static const char COMPLEX_ABSTRACTION[] = {'c', 'o', 'm', 'p', 'l', 'e', 'x'};

/** The complex abstraction size. */
static const int COMPLEX_ABSTRACTION_SIZE = 7;

/** The vector abstraction. */
static const char VECTOR_ABSTRACTION[] = {'v', 'e', 'c', 't', 'o', 'r'};

/** The vector abstraction size. */
static const int VECTOR_ABSTRACTION_SIZE = 6;

/** The string abstraction. */
static const char STRING_ABSTRACTION[] = {'s', 't', 'r', 'i', 'n', 'g'};

/** The string abstraction size. */
static const int STRING_ABSTRACTION_SIZE = 6;

/** The time abstraction. */
static const char TIME_ABSTRACTION[] = {'t', 'i', 'm', 'e'};

/** The time abstraction size. */
static const int TIME_ABSTRACTION_SIZE = 4;

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
