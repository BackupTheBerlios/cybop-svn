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
 */

#ifndef LANGUAGES_SOURCE
#define LANGUAGES_SOURCE

/**
 * This is the languages.
 *
 * It defines constants for languages that systems can use to communicate.
 *
 * @version $Revision: 1.1 $ $Date: 2004-02-29 16:26:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// Languages.
//

/** The cybol language. */
static const char* CYBOL_LANGUAGE = "cybol";

/** The inline (serialized) language. */
static const char* INLINE_LANGUAGE = "inline";

//?? The following languages are not used yet.

/** The textual user interface (tui) language. */
static const char* TUI_LANGUAGE = "tui";

/** The mouse language. */
static const char* MOUSE_LANGUAGE = "mouse";

/** The x windows language. */
static const char* X_WINDOWS_LANGUAGE = "x_windows";

/** The socket language. */
static const char* SOCKET_LANGUAGE = "socket";

/** The structured query language (sql). */
static const char* SQ_LANGUAGE = "sq";

/** The java messaging service (jms) language. */
static const char* JMS_LANGUAGE = "jms";

/** The remote method invocation (rmi) language. */
static const char* RMI_LANGUAGE = "rmi";

/** The common object request broker architecture (corba) language. */
static const char* CORBA_LANGUAGE = "corba";

/** The extensible markup language (xml). */
static const char* XML_LANGUAGE = "xml";

/** The simple object access protocol (soap) language. */
static const char* SOAP_LANGUAGE = "soap";

/** The file language. */
static const char* FILE_LANGUAGE = "file";

/** The floppy language. */
static const char* FLOPPY_LANGUAGE = "floppy";

/** The ftp language. */
static const char* FTP_LANGUAGE = "ftp";

/** The sftp language. */
static const char* SFTP_LANGUAGE = "sftp";

/** The imap language. */
static const char* IMAP_LANGUAGE = "imap";

/** The imaps language. */
static const char* IMAPS_LANGUAGE = "imaps";

/** The ldap language. */
static const char* LDAP_LANGUAGE = "ldap";

/** The nfs language. */
static const char* NFS_LANGUAGE = "nfs";

/** The nntp language. */
static const char* NNTP_LANGUAGE = "nntp";

/** The smb language. */
static const char* SMB_LANGUAGE = "smb";

/** The smtp language. */
static const char* SMTP_LANGUAGE = "smtp";

/** The smtps language. */
static const char* SMTPS_LANGUAGE = "smtps";

/** The tar language. */
static const char* TAR_LANGUAGE = "tar";

/** The zip language. */
static const char* ZIP_LANGUAGE = "zip";

/* LANGUAGES_SOURCE */
#endif
