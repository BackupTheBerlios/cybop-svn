/*
 * $RCSfile: channel_constants.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2005-07-22 07:29:46 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHANNEL_CONSTANTS_SOURCE
#define CHANNEL_CONSTANTS_SOURCE

/** The inline channel. */
static const char INLINE_CHANNEL_ARRAY[] = {'i', 'n', 'l', 'i', 'n', 'e'};
static const char* INLINE_CHANNEL = INLINE_CHANNEL_ARRAY;
static const int INLINE_CHANNEL_COUNT_ARRAY[] = {6};
static const int* INLINE_CHANNEL_COUNT = INLINE_CHANNEL_COUNT_ARRAY;

/** The terminal channel. */
static const char TERMINAL_CHANNEL_ARRAY[] = {'t', 'e', 'r', 'm', 'i', 'n', 'a', 'l'};
static const char* TERMINAL_CHANNEL = TERMINAL_CHANNEL_ARRAY;
static const int TERMINAL_CHANNEL_COUNT_ARRAY[] = {8};
static const int* TERMINAL_CHANNEL_COUNT = TERMINAL_CHANNEL_COUNT_ARRAY;

/** The file channel. */
static const char FILE_CHANNEL_ARRAY[] = {'f', 'i', 'l', 'e'};
static const char* FILE_CHANNEL = FILE_CHANNEL_ARRAY;
static const int FILE_CHANNEL_COUNT_ARRAY[] = {4};
static const int* FILE_CHANNEL_COUNT = FILE_CHANNEL_COUNT_ARRAY;

/** The http location. */
static const char HTTP_CHANNEL_ARRAY[] = {'h', 't', 't', 'p'};
static const char* HTTP_CHANNEL = HTTP_CHANNEL_ARRAY;
static const int HTTP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* HTTP_CHANNEL_COUNT = HTTP_CHANNEL_COUNT_ARRAY;

/** The ftp channel. */
static const char FTP_CHANNEL_ARRAY[] = {'f', 't', 'p'};
static const char* FTP_CHANNEL = FTP_CHANNEL_ARRAY;
static const int FTP_CHANNEL_COUNT_ARRAY[] = {3};
static const int* FTP_CHANNEL_COUNT = FTP_CHANNEL_COUNT_ARRAY;

/** The sftp channel. */
static const char SFTP_CHANNEL_ARRAY[] = {'s', 'f', 't', 'p'};
static const char* SFTP_CHANNEL = SFTP_CHANNEL_ARRAY;
static const int SFTP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* SFTP_CHANNEL_COUNT = SFTP_CHANNEL_COUNT_ARRAY;

/** The unix socket channel. */
static const char UNIX_SOCKET_CHANNEL_ARRAY[] = {'u', 'n', 'i', 'x', '_', 's', 'o', 'c', 'k', 'e', 't'};
static const char* UNIX_SOCKET_CHANNEL = UNIX_SOCKET_CHANNEL_ARRAY;
static const int UNIX_SOCKET_CHANNEL_COUNT_ARRAY[] = {11};
static const int* UNIX_SOCKET_CHANNEL_COUNT = UNIX_SOCKET_CHANNEL_COUNT_ARRAY;

/** The tcp socket channel. */
static const char TCP_SOCKET_CHANNEL_ARRAY[] = {'t', 'c', 'p', '_', 's', 'o', 'c', 'k', 'e', 't'};
static const char* TCP_SOCKET_CHANNEL = TCP_SOCKET_CHANNEL_ARRAY;
static const int TCP_SOCKET_CHANNEL_COUNT_ARRAY[] = {10};
static const int* TCP_SOCKET_CHANNEL_COUNT = TCP_SOCKET_CHANNEL_COUNT_ARRAY;

/** The java messaging service (jms) channel. */
static const char JMS_CHANNEL_ARRAY[] = {'j', 'm', 's'};
static const char* JMS_CHANNEL = JMS_CHANNEL_ARRAY;
static const int JMS_CHANNEL_COUNT_ARRAY[] = {3};
static const int* JMS_CHANNEL_COUNT = JMS_CHANNEL_COUNT_ARRAY;

/** The remote method invocation (rmi) channel. */
static const char RMI_CHANNEL_ARRAY[] = {'r', 'm', 'i'};
static const char* RMI_CHANNEL = RMI_CHANNEL_ARRAY;
static const int RMI_CHANNEL_COUNT_ARRAY[] = {3};
static const int* RMI_CHANNEL_COUNT = RMI_CHANNEL_COUNT_ARRAY;

/** The common object request broker architecture (corba) channel. */
static const char CORBA_CHANNEL_ARRAY[] = {'c', 'o', 'r', 'b', 'a'};
static const char* CORBA_CHANNEL = CORBA_CHANNEL_ARRAY;
static const int CORBA_CHANNEL_COUNT_ARRAY[] = {5};
static const int* CORBA_CHANNEL_COUNT = CORBA_CHANNEL_COUNT_ARRAY;

/** The simple object access protocol (soap) channel. */
static const char SOAP_CHANNEL_ARRAY[] = {'s', 'o', 'a', 'p'};
static const char* SOAP_CHANNEL = SOAP_CHANNEL_ARRAY;
static const int SOAP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* SOAP_CHANNEL_COUNT = SOAP_CHANNEL_COUNT_ARRAY;

/** The floppy channel. */
static const char FLOPPY_CHANNEL_ARRAY[] = {'f', 'l', 'o', 'p', 'p', 'y'};
static const char* FLOPPY_CHANNEL = FLOPPY_CHANNEL_ARRAY;
static const int FLOPPY_CHANNEL_COUNT_ARRAY[] = {6};
static const int* FLOPPY_CHANNEL_COUNT = FLOPPY_CHANNEL_COUNT_ARRAY;

/** The imap channel. */
static const char IMAP_CHANNEL_ARRAY[] = {'i', 'm', 'a', 'p'};
static const char* IMAP_CHANNEL = IMAP_CHANNEL_ARRAY;
static const int IMAP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* IMAP_CHANNEL_COUNT = IMAP_CHANNEL_COUNT_ARRAY;

/** The imaps channel. */
static const char IMAPS_CHANNEL_ARRAY[] = {'i', 'm', 'a', 'p', 's'};
static const char* IMAPS_CHANNEL = IMAPS_CHANNEL_ARRAY;
static const int IMAPS_CHANNEL_COUNT_ARRAY[] = {5};
static const int* IMAPS_CHANNEL_COUNT = IMAPS_CHANNEL_COUNT_ARRAY;

/** The ldap channel. */
static const char LDAP_CHANNEL_ARRAY[] = {'l', 'd', 'a', 'p'};
static const char* LDAP_CHANNEL = LDAP_CHANNEL_ARRAY;
static const int LDAP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* LDAP_CHANNEL_COUNT = LDAP_CHANNEL_COUNT_ARRAY;

/** The nfs channel. */
static const char NFS_CHANNEL_ARRAY[] = {'n', 'f', 's'};
static const char* NFS_CHANNEL = NFS_CHANNEL_ARRAY;
static const int NFS_CHANNEL_COUNT_ARRAY[] = {3};
static const int* NFS_CHANNEL_COUNT = NFS_CHANNEL_COUNT_ARRAY;

/** The nntp channel. */
static const char NNTP_CHANNEL_ARRAY[] = {'n', 'n', 't', 'p'};
static const char* NNTP_CHANNEL = NNTP_CHANNEL_ARRAY;
static const int NNTP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* NNTP_CHANNEL_COUNT = NNTP_CHANNEL_COUNT_ARRAY;

/** The smb channel. */
static const char SMB_CHANNEL_ARRAY[] = {'s', 'm', 'b'};
static const char* SMB_CHANNEL = SMB_CHANNEL_ARRAY;
static const int SMB_CHANNEL_COUNT_ARRAY[] = {3};
static const int* SMB_CHANNEL_COUNT = SMB_CHANNEL_COUNT_ARRAY;

/** The smtp channel. */
static const char SMTP_CHANNEL_ARRAY[] = {'s', 'm', 't', 'p'};
static const char* SMTP_CHANNEL = SMTP_CHANNEL_ARRAY;
static const int SMTP_CHANNEL_COUNT_ARRAY[] = {4};
static const int* SMTP_CHANNEL_COUNT = SMTP_CHANNEL_COUNT_ARRAY;

/** The smtps channel. */
static const char SMTPS_CHANNEL_ARRAY[] = {'s', 'm', 't', 'p', 's'};
static const char* SMTPS_CHANNEL = SMTPS_CHANNEL_ARRAY;
static const int SMTPS_CHANNEL_COUNT_ARRAY[] = {5};
static const int* SMTPS_CHANNEL_COUNT = SMTPS_CHANNEL_COUNT_ARRAY;

/* CHANNEL_CONSTANTS_SOURCE */
#endif
