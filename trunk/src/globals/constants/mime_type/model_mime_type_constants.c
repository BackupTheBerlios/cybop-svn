/*
 * $RCSfile: model_mime_type_constants.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.1 $ $Date: 2007-08-03 17:10:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_MIME_TYPE_CONSTANTS_SOURCE
#define MODEL_MIME_TYPE_CONSTANTS_SOURCE

#include "../../../globals/constants/integer/integer_constants.c"

/** The vrml model mime type. */
static char VRML_MODEL_MIME_TYPE_ARRAY[] = {'m', 'o', 'd', 'e', 'l', '/', 'v', 'r', 'm', 'l'};
static char* VRML_MODEL_MIME_TYPE = VRML_MODEL_MIME_TYPE_ARRAY;
static int* VRML_MODEL_MIME_TYPE_COUNT = NUMBER_10_INTEGER_ARRAY;

/* MODEL_MIME_TYPE_CONSTANTS_SOURCE */
#endif
