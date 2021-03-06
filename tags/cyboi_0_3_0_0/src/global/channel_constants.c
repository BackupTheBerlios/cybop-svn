/*
 * $RCSfile: channel_constants.c,v $
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
 * This file defines global communication channel constants.
 *
 * It was decided to keep them bundled in this place to ease their maintenance.
 * One day, they can be burnt together with the cyboi implementation into a
 * hardware chip, just like operation codes of a central processing unit (cpu).
 * This would tremendously increase performance.
 *
 * @version $Revision: 1.1 $ $Date: 2004-08-13 07:22:35 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHANNEL_CONSTANTS_SOURCE
#define CHANNEL_CONSTANTS_SOURCE

//
// Communication channels.
//

/** The internal channel array, pointer, count. */
static const char INTERNAL_CHANNEL_ARRAY[] = {'i', 'n', 't', 'e', 'r', 'n', 'a', 'l'};
static const char* INTERNAL_CHANNEL = INTERNAL_CHANNEL_ARRAY;
static const int INTERNAL_CHANNEL_COUNT = 8;

/** The inline channel array, pointer, count. */
static const char INLINE_CHANNEL_ARRAY[] = {'i', 'n', 'l', 'i', 'n', 'e'};
static const char* INLINE_CHANNEL = INLINE_CHANNEL_ARRAY;
static const int INLINE_CHANNEL_COUNT = 6;

/** The file channel array, pointer, count. */
static const char FILE_CHANNEL_ARRAY[] = {'f', 'i', 'l', 'e'};
static const char* FILE_CHANNEL = FILE_CHANNEL_ARRAY;
static const int FILE_CHANNEL_COUNT = 4;

/** The http location array, pointer, count. */
static const char HTTP_CHANNEL_ARRAY[] = {'h', 't', 't', 'p'};
static const char* HTTP_CHANNEL = HTTP_CHANNEL_ARRAY;
static const int HTTP_CHANNEL_COUNT = 4;

/** The ftp channel array, pointer, count. */
static const char FTP_CHANNEL_ARRAY[] = {'f', 't', 'p'};
static const char* FTP_CHANNEL = FTP_CHANNEL_ARRAY;
static const int FTP_CHANNEL_COUNT = 3;

/** The sftp channel array, pointer, count. */
static const char SFTP_CHANNEL_ARRAY[] = {'s', 'f', 't', 'p'};
static const char* SFTP_CHANNEL = SFTP_CHANNEL_ARRAY;
static const int SFTP_CHANNEL_COUNT = 4;

/** The unix socket channel array, pointer, count. */
static const char UNIX_SOCKET_CHANNEL_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'o', 'c', 'k', 'e', 't'};
static const char* UNIX_SOCKET_CHANNEL = UNIX_SOCKET_CHANNEL_ARRAY;
static const int UNIX_SOCKET_CHANNEL_COUNT = 11;

/** The java messaging service (jms) channel array, pointer, count. */
static const char JMS_CHANNEL_ARRAY[] = {'j', 'm', 's'};
static const char* JMS_CHANNEL = JMS_CHANNEL_ARRAY;
static const int JMS_CHANNEL_COUNT = 3;

/** The remote method invocation (rmi) channel array, pointer, count. */
static const char RMI_CHANNEL_ARRAY[] = {'r', 'm', 'i'};
static const char* RMI_CHANNEL = RMI_CHANNEL_ARRAY;
static const int RMI_CHANNEL_COUNT = 3;

/** The common object request broker architecture (corba) channel array, pointer, count. */
static const char CORBA_CHANNEL_ARRAY[] = {'c', 'o', 'r', 'b', 'a'};
static const char* CORBA_CHANNEL = CORBA_CHANNEL_ARRAY;
static const int CORBA_CHANNEL_COUNT = 5;

/** The simple object access protocol (soap) channel array, pointer, count. */
static const char SOAP_CHANNEL_ARRAY[] = {'s', 'o', 'a', 'p'};
static const char* SOAP_CHANNEL = SOAP_CHANNEL_ARRAY;
static const int SOAP_CHANNEL_COUNT = 4;

/** The floppy channel array, pointer, count. */
static const char FLOPPY_CHANNEL_ARRAY[] = {'f', 'l', 'o', 'p', 'p', 'y'};
static const char* FLOPPY_CHANNEL = FLOPPY_CHANNEL_ARRAY;
static const int FLOPPY_CHANNEL_COUNT = 6;

/** The imap channel array, pointer, count. */
static const char IMAP_CHANNEL_ARRAY[] = {'i', 'm', 'a', 'p'};
static const char* IMAP_CHANNEL = IMAP_CHANNEL_ARRAY;
static const int IMAP_CHANNEL_COUNT = 4;

/** The imaps channel array, pointer, count. */
static const char IMAPS_CHANNEL_ARRAY[] = {'i', 'm', 'a', 'p', 's'};
static const char* IMAPS_CHANNEL = IMAPS_CHANNEL_ARRAY;
static const int IMAPS_CHANNEL_COUNT = 5;

/** The ldap channel array, pointer, count. */
static const char LDAP_CHANNEL_ARRAY[] = {'l', 'd', 'a', 'p'};
static const char* LDAP_CHANNEL = LDAP_CHANNEL_ARRAY;
static const int LDAP_CHANNEL_COUNT = 4;

/** The nfs channel array, pointer, count. */
static const char NFS_CHANNEL_ARRAY[] = {'n', 'f', 's'};
static const char* NFS_CHANNEL = NFS_CHANNEL_ARRAY;
static const int NFS_CHANNEL_COUNT = 3;

/** The nntp channel array, pointer, count. */
static const char NNTP_CHANNEL_ARRAY[] = {'n', 'n', 't', 'p'};
static const char* NNTP_CHANNEL = NNTP_CHANNEL_ARRAY;
static const int NNTP_CHANNEL_COUNT = 4;

/** The smb channel array, pointer, count. */
static const char SMB_CHANNEL_ARRAY[] = {'s', 'm', 'b'};
static const char* SMB_CHANNEL = SMB_CHANNEL_ARRAY;
static const int SMB_CHANNEL_COUNT = 3;

/** The smtp channel array, pointer, count. */
static const char SMTP_CHANNEL_ARRAY[] = {'s', 'm', 't', 'p'};
static const char* SMTP_CHANNEL = SMTP_CHANNEL_ARRAY;
static const int SMTP_CHANNEL_COUNT = 4;

/** The smtps channel array, pointer, count. */
static const char SMTPS_CHANNEL_ARRAY[] = {'s', 'm', 't', 'p', 's'};
static const char* SMTPS_CHANNEL = SMTPS_CHANNEL_ARRAY;
static const int SMTPS_CHANNEL_COUNT = 5;

/* CHANNEL_CONSTANTS_SOURCE */
#endif
