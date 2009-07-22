/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: rule_xdt_abstraction.c,v $ $Revision: 1.5 $ $Date: 2009-07-22 17:18:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RULE_XDT_ABSTRACTION_SOURCE
#define RULE_XDT_ABSTRACTION_SOURCE

#include "../../../constant/model/memory/integer_memory_model.c"

//
// Format checking rules.
//

/**
 * The hhmm rule xdt abstraction.
 *
 * HH: Stunde
 * MM: Minute
 *
 * Possible values: 0000-2359
 */
static int* HHMM_RULE_XDT_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The hhmmhhmm rule xdt abstraction.
 *
 * HH: Stunde
 * MM: Minute
 */
static int* HHMMHHMM_RULE_XDT_ABSTRACTION = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The jjmmnnn rule xdt abstraction.
 *
 * JJ: Jahr
 * MM: Monat
 * NNN: laufende Nummer
 */
static int* JJMMNNN_RULE_XDT_ABSTRACTION = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The ttmmjjjj rule xdt abstraction.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 */
static int* TTMMJJJJ_RULE_XDT_ABSTRACTION = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The mmjj rule xdt abstraction.
 *
 * MM: Monat
 * JJ: Jahr
 */
static int* MMJJ_RULE_XDT_ABSTRACTION = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The arztname zuordnungszeichen rule xdt abstraction.
 *
 * Possible values: 0-9, A-Z, #, $, <, >, *
 */
static int* ARZTNAME_ZUORDNUNGSZEICHEN_RULE_XDT_ABSTRACTION = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The qjjjj rule xdt abstraction.
 *
 * Q: Quartal
 * JJJJ: Jahr
 */
static int* QJJJJ_RULE_XDT_ABSTRACTION = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The vknr rule xdt abstraction.
 *
 * Format: nnnnn
 */
static int* VKNR_RULE_XDT_ABSTRACTION = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The krankenkassennummer rule xdt abstraction.
 *
 * Format: nnnnnnn
 */
static int* KRANKENKASSENNUMMER_RULE_XDT_ABSTRACTION = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The ttmmjjjjttmmjjjj rule xdt abstraction.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 */
static int* TTMMJJJJTTMMJJJJ_RULE_XDT_ABSTRACTION = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The ttmmjjjj rule xdt abstraction.
 *
 * TT: Tag
 * MM: Monat
 * JJJJ: Jahr
 *
 * Possible values:
 * TT=00-31
 * MM=00-12
 * JJJJ=0000-9999
 */
static int* TTMMJJJJ_BESCHRAENKT_RULE_XDT_ABSTRACTION = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

//
// Content checking rules.
//

/**
 * The feld angekreuzt rule xdt abstraction.
 *
 * Possible values: 1
 *
 * Description:
 * 1: Feld angekreuzt/ vorhanden
 */
static int* FELD_ANGEKREUZT_RULE_XDT_ABSTRACTION = NUMBER_101_INTEGER_MEMORY_MODEL_ARRAY;

//
// Existence checking rules.
//

/**
 * The kassendatei vknr vorhanden rule xdt abstraction.
 *
 * VKNR vorhanden und 5-stellig
 */
static int* KASSENDATEI_VKNR_VORHANDEN_RULE_XDT_ABSTRACTION = NUMBER_201_INTEGER_MEMORY_MODEL_ARRAY;

//
// Context checking rules.
//

/**
 * The datum kleiner oder gleich maschinendatum rule xdt abstraction.
 */
static int* DATUM_KLEINER_ODER_GLEICH_MASCHINENDATUM_RULE_XDT_ABSTRACTION = NUMBER_304_INTEGER_MEMORY_MODEL_ARRAY;

/* RULE_XDT_ABSTRACTION_SOURCE */
#endif
