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
 * @version $RCSfile: model_mime_abstraction.c,v $ $Revision: 1.1 $ $Date: 2008-09-14 08:25:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_MIME_ABSTRACTION_SOURCE
#define MODEL_MIME_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//

//
// Model.
//
// IANA media type: model
//

/**
 * The model/vrml cybol abstraction.
 */
static wchar_t VRML_MODEL_MIME_ABSTRACTION_ARRAY[] = {L'm', L'o', L'd', L'e', L'l', L'/', L'v', L'r', L'm', L'l'};
static wchar_t* VRML_MODEL_MIME_ABSTRACTION = VRML_MODEL_MIME_ABSTRACTION_ARRAY;
static int* VRML_MODEL_MIME_ABSTRACTION_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/* MODEL_MIME_ABSTRACTION_SOURCE */
#endif
