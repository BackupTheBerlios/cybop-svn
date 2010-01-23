/*
 * Copyright (C) 1999-2010. Christian Heller.
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
 * @version $RCSfile: xdt_converter.c,v $ $Revision: 1.40 $ $Date: 2009-02-10 01:13:43 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef XDT_ENCODER_SOURCE
#define XDT_ENCODER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/xdt/field_xdt_name.c"
#include "../../constant/name/xdt/package_xdt_name.c"
#include "../../constant/name/xdt/record_xdt_name.c"
#include "../../constant/name/xdt_model/field_xdt_model_name.c"
#include "../../constant/name/xdt_model/record_xdt_model_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/converter/character/ascii_character_vector_converter.c"
#include "../../memoriser/converter/date_time_converter.c"
#include "../../memoriser/converter/integer_vector_converter.c"
#include "../../memoriser/array.c"

//
// The "x DatenTransfer" (xDT) is the German version of
// "Electronic Data Interchange" (EDI) for medical practices.
// Here is an extract from xDT documentation, issued by the
// "Kassenaerztliche Bundesvereinigung" (KBV) at:
// http://www.kbv.de/ita/4274.html
//
// Aufbau und Struktur des "AbrechnungsDatenTransfer" (ADT)
//
// Der ADT ist eine Datenschnittstelle, die aufgrund ihrer fruehen Entstehung,
// Mitte der achtziger Jahre, wenig Anknuepfungspunkte zu den erst spaeter im
// Zusammenhang mit der zunehmenden EDI-Etablierung bekannten Standards besitzt.
// Natuerlich gibt es Parallelen, beispielsweise zu
// "EDI for Administration, Commerce and Transport" (EDIFACT),
// die in der artverwandten Zielsetzung begruendet liegen.
// Die ADT-Syntax ist der von "Abstract Syntax Notation" (ASN) ASN.1 aehnlich.
//
// Eine wesentliche Besonderheit des ADT besteht darin, dass jedes Feld im
// Grunde einen eigenen Satz darstellt. Das heisst, es enthaelt in sich wieder
// die Elemente Laenge, Feldkennung, Feldinhalt und Feldende.
//
// Die einzelnen Felder haben alle einen eindeutigen Namen in Form einer
// numerischen Feldkennung. Es gibt wenige Felder mit in der Groesse
// feststehenden Feldinhalten, die meisten sind variabel, was sich mit einer
// vorlaufenden Feldlaenge leicht bewerkstelligen laesst. Darueber hinaus
// werden als Endemarkierung eines Feldes die ASCII-Werte 13 und 10,
// gleichbedeutend mit Carriage return und Linefeed, verlangt.
//
// Jedes Feld hat die gleiche Struktur. Alle Informationen sind als
// ASCII-Zeichen dargestellt. Gemaess der Feldkennung wird der zugehoerige
// Eintrag der Feldtabelle herangezogen.
//
// Fuer die Laengenberechnung eines Feldes gilt die Regel: Feldinhalt + 9
//
// Struktur eines Datenfeldes
//
// -----------------------------------------------------------------------------
// Feldteil         Laenge [Byte]       Bedeutung
// -----------------------------------------------------------------------------
// Laenge           3                   Feldlaenge in Bytes
// Kennung          4                   Feldkennung
// Inhalt           variabel            Abrechnungsinformationen
// Ende             2                   ASCII-Wert 13 = CR (Wagenruecklauf)
//                                      ASCII-Wert 10 = LF (Zeilenvorschub)
// -----------------------------------------------------------------------------
//
// Here is an extract from the German "Arztpraxis Wiegand" (APW) documentation,
// available at:
// http://www.apw-wiegand.de/
//
// Patientennummerkonvertierung:
// Beim BDT ... werden die Patientennummern nach folgender Formel konvertiert:
// Stelle 1: immer 1
// Stelle 2-3: Parallelabrechnungsnummer (meist 01)
// Stelle 4-5: 1. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge (z.B. a->01, z->26)
// Stelle 6-7: 2. Stelle der APW-PatNr umgewandelt in Alphabet-Rangfolge
// ab Stelle 8: ab Stelle 3 der APW-PatNr
//

/**
 * Encodes a compound model into an xdt format byte array.
 *
 * @param p0 the destination xdt byte array (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source compound model
 * @param p4 the source count
 */
void encode_xdt(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode compound model into xdt format.");
}

/* XDT_ENCODER_SOURCE */
#endif
