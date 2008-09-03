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
 * @version $RCSfile: protocol_cybol_model.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROTOCOL_CYBOL_MODEL_SOURCE
#define PROTOCOL_CYBOL_MODEL_SOURCE

#include "../../../constant/model/memory/integer_model.c"

/** The common object request broker architecture (corba) protocol cybol model. */
static wchar_t CORBA_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'r', L'b', L'a'};
static wchar_t* CORBA_PROTOCOL_CYBOL_MODEL = CORBA_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* CORBA_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The file system protocol cybol model. */
static wchar_t FILE_SYSTEM_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_SYSTEM_PROTOCOL_CYBOL_MODEL = FILE_SYSTEM_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* FILE_SYSTEM_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The floppy protocol cybol model. */
static wchar_t FLOPPY_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'f', L'l', L'o', L'p', L'p', L'y'};
static wchar_t* FLOPPY_PROTOCOL_CYBOL_MODEL = FLOPPY_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* FLOPPY_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_ARRAY;

/** The imap protocol cybol model. */
static wchar_t IMAP_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'i', L'm', L'a', L'p'};
static wchar_t* IMAP_PROTOCOL_CYBOL_MODEL = IMAP_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* IMAP_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The imaps protocol cybol model. */
static wchar_t IMAPS_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'i', L'm', L'a', L'p', L's'};
static wchar_t* IMAPS_PROTOCOL_CYBOL_MODEL = IMAPS_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* IMAPS_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The java messaging service (jms) protocol cybol model. */
static wchar_t JMS_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'j', L'm', L's'};
static wchar_t* JMS_PROTOCOL_CYBOL_MODEL = JMS_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* JMS_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The latex protocol cybol model. */
static wchar_t LATEX_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'l', L'a', L't', L'e', L'x'};
static wchar_t* LATEX_PROTOCOL_CYBOL_MODEL = LATEX_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* LATEX_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The ldap protocol cybol model. */
static wchar_t LDAP_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'l', L'd', L'a', L'p'};
static wchar_t* LDAP_PROTOCOL_CYBOL_MODEL = LDAP_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* LDAP_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The nfs protocol cybol model. */
static wchar_t NFS_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'n', L'f', L's'};
static wchar_t* NFS_PROTOCOL_CYBOL_MODEL = NFS_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* NFS_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The nntp protocol cybol model. */
static wchar_t NNTP_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'n', L'n', L't', L'p'};
static wchar_t* NNTP_PROTOCOL_CYBOL_MODEL = NNTP_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* NNTP_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The remote method invocation (rmi) protocol cybol model. */
static wchar_t RMI_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L'r', L'm', L'i'};
static wchar_t* RMI_PROTOCOL_CYBOL_MODEL = RMI_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* RMI_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The simple object access protocol (soap) protocol cybol model. */
static wchar_t SOAP_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L's', L'o', L'a', L'p'};
static wchar_t* SOAP_PROTOCOL_CYBOL_MODEL = SOAP_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* SOAP_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The smb protocol cybol model. */
static wchar_t SMB_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L's', L'm', L'b'};
static wchar_t* SMB_PROTOCOL_CYBOL_MODEL = SMB_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* SMB_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/** The smtp protocol cybol model. */
static wchar_t SMTP_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L's', L'm', L't', L'p'};
static wchar_t* SMTP_PROTOCOL_CYBOL_MODEL = SMTP_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* SMTP_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_ARRAY;

/** The smtps protocol cybol model. */
static wchar_t SMTPS_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L's', L'm', L't', L'p', L's'};
static wchar_t* SMTPS_PROTOCOL_CYBOL_MODEL = SMTPS_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* SMTPS_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_ARRAY;

/** The structured query language (sql) protocol cybol model. */
static wchar_t SQL_PROTOCOL_CYBOL_MODEL_ARRAY[] = {L's', L'q', L'l'};
static wchar_t* SQL_PROTOCOL_CYBOL_MODEL = SQL_PROTOCOL_CYBOL_MODEL_ARRAY;
static int* SQL_PROTOCOL_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_ARRAY;

/* PROTOCOL_CYBOL_MODEL_SOURCE */
#endif
