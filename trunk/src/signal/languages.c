/*
 * $RCSfile: languages.c,v $
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
 * This file defines constants for languages that systems can use to communicate.
 *
 * @version $Revision: 1.3 $ $Date: 2004-04-01 17:35:16 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LANGUAGES_SOURCE
#define LANGUAGES_SOURCE

//
// Languages.
//

/** The cybol language. */
static const char CYBOL_LANGUAGE[] = {'c', 'y', 'b', 'o', 'l'};

/** The inline (serialized) language. */
static const char INLINE_LANGUAGE[] = {'i', 'n', 'l', 'i', 'n', 'e'};

//?? The following languages are not used yet.

/** The textual user interface (tui) language. */
static const char TUI_LANGUAGE[] = {'t', 'u', 'i'};

/** The mouse language. */
static const char MOUSE_LANGUAGE[] = {'m', 'o', 'u', 's', 'e'};

/** The x windows language. */
static const char X_WINDOWS_LANGUAGE[] = {'x', '_', 'w', 'i', 'n', 'd', 'o', 'w', 's'};

/** The socket language. */
static const char SOCKET_LANGUAGE[] = {'s', 'o', 'c', 'k', 'e', 't'};

/** The structured query language (sql). */
static const char SQ_LANGUAGE[] = {'s', 'q'};

/** The java messaging service (jms) language. */
static const char JMS_LANGUAGE[] = {'j', 'm', 's'};

/** The remote method invocation (rmi) language. */
static const char RMI_LANGUAGE[] = {'r', 'm', 'i'};

/** The common object request broker architecture (corba) language. */
static const char CORBA_LANGUAGE[] = {'c', 'o', 'r', 'b', 'a'};

/** The extensible markup language (xml). */
static const char XML_LANGUAGE[] = {'x', 'm', 'l'};

/** The simple object access protocol (soap) language. */
static const char SOAP_LANGUAGE[] = {'s', 'o', 'a', 'p'};

/** The file language. */
static const char FILE_LANGUAGE[] = {'f', 'i', 'l', 'e'};

/** The floppy language. */
static const char FLOPPY_LANGUAGE[] = {'f', 'l', 'o', 'p', 'p', 'y'};

/** The ftp language. */
static const char FTP_LANGUAGE[] = {'f', 't', 'p'};

/** The sftp language. */
static const char SFTP_LANGUAGE[] = {'s', 'f', 't', 'p'};

/** The imap language. */
static const char IMAP_LANGUAGE[] = {'i', 'm', 'a', 'p'};

/** The imaps language. */
static const char IMAPS_LANGUAGE[] = {'i', 'm', 'a', 'p', 's'};

/** The ldap language. */
static const char LDAP_LANGUAGE[] = {'l', 'd', 'a', 'p'};

/** The nfs language. */
static const char NFS_LANGUAGE[] = {'n', 'f', 's'};

/** The nntp language. */
static const char NNTP_LANGUAGE[] = {'n', 'n', 't', 'p'};

/** The smb language. */
static const char SMB_LANGUAGE[] = {'s', 'm', 'b'};

/** The smtp language. */
static const char SMTP_LANGUAGE[] = {'s', 'm', 't', 'p'};

/** The smtps language. */
static const char SMTPS_LANGUAGE[] = {'s', 'm', 't', 'p', 's'};

/** The tar language. */
static const char TAR_LANGUAGE[] = {'t', 'a', 'r'};

/** The zip language. */
static const char ZIP_LANGUAGE[] = {'z', 'i', 'p'};

/* LANGUAGES_SOURCE */
#endif
