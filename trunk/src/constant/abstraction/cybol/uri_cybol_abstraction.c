/*
 * Copyright (C) 1999-2011. Christian Heller.
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
 * @version $RCSfile: uri_cybol_abstraction.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URI_MIME_TYPE_CONSTANTS_SOURCE
#define URI_MIME_TYPE_CONSTANTS_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// This MIME type was taken from/ inspired by the KDE desktop.
// It is not sure yet, whether it will be useful in the context of CYBOI.
//

/**
 * The uri/mms cybol abstraction.
 */
static wchar_t MMS_URI_CYBOL_ABSTRACTION_ARRAY[] = {L'u', L'r', L'i', L'/', L'm', L'm', L's'};
static wchar_t* MMS_URI_CYBOL_ABSTRACTION = MMS_URI_CYBOL_ABSTRACTION_ARRAY;
static int* MMS_URI_CYBOL_ABSTRACTION_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* URI_MIME_TYPE_CONSTANTS_SOURCE */
#endif
