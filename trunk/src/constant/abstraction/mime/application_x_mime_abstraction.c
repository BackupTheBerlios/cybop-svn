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
 * @version $RCSfile: application_x_mime_abstraction.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef APPLICATION_X_MIME_ABSTRACTION_SOURCE
#define APPLICATION_X_MIME_ABSTRACTION_SOURCE

#include <stddef.h>
#include "../../../constant/model/memory/integer_memory_model.c"

//
// The Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//

//
// Application (non-standard).
//
// IANA media type: application/x-
//

/*??
application/x-dvi: Digital Videfiles in DVI format
application/x-httpd-php: PHP files
application/x-httpd-php-source: PHP source files
*/

/**
 * The application/x-latex cybol abstraction.
 *
 * LaTeX files.
 * Suffixes: tex
 */
static wchar_t LATEX_APPLICATION_X_MIME_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'l', L'a', L't', L'e', L'x'};
static wchar_t* LATEX_APPLICATION_X_MIME_ABSTRACTION = LATEX_APPLICATION_X_MIME_ABSTRACTION_ARRAY;
static int* LATEX_APPLICATION_X_MIME_ABSTRACTION_COUNT = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/*??
application/x-shockwave-flash: Adobe Flash files; Documented in Adobe TechNote tn_4151 and Adobe TechNote tn_16509
application/x-stuffit: StuffIt archive files
application/x-rar-compressed: RAR archive files
*/

/**
 * The application/x-tar cybol abstraction.
 *
 * Tarball files.
 * Suffixes: tar
 */
static wchar_t TAR_APPLICATION_X_MIME_ABSTRACTION_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'a', L'r'};
static wchar_t* TAR_APPLICATION_X_MIME_ABSTRACTION = TAR_APPLICATION_X_MIME_ABSTRACTION_ARRAY;
static int* TAR_APPLICATION_X_MIME_ABSTRACTION_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/* APPLICATION_X_MIME_ABSTRACTION_SOURCE */
#endif
