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
 * @version $RCSfile: service_port_model.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_PORT_MODEL_SOURCE
#define SERVICE_PORT_MODEL_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"

//
// IANA assigned ports.
//
// Sorted here by their assigned number.
//

/** The tcp service multiplexer service port model. */
static int* TCP_MUX_SERVICE_PORT_MODEL = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp echo service port model. */
static int* TCP_ECHO_SERVICE_PORT_MODEL = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp echo service port model. */
static int* UDP_ECHO_SERVICE_PORT_MODEL = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp discard (sink null) service port model. */
static int* TCP_DISCARD_SERVICE_PORT_MODEL = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp discard (sink null) service port model. */
static int* UDP_DISCARD_SERVICE_PORT_MODEL = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp systat (user) service port model. */
static int* TCP_SYSTAT_SERVICE_PORT_MODEL = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp daytime service port model. */
static int* TCP_DAYTIME_SERVICE_PORT_MODEL = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp daytime service port model. */
static int* UDP_DAYTIME_SERVICE_PORT_MODEL = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp netstat service port model. */
static int* TCP_NETSTAT_SERVICE_PORT_MODEL = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp qotd (quote) service port model. */
static int* TCP_QOTD_SERVICE_PORT_MODEL = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp message send protocol service port model. */
static int* TCP_MSP_SERVICE_PORT_MODEL = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp message send protocol service port model. */
static int* UDP_MSP_SERVICE_PORT_MODEL = NUMBER_18_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp ttytst source service port model. */
static int* TCP_CHARGEN_SERVICE_PORT_MODEL = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp ttytst service port model. */
static int* UDP_CHARGEM_SERVICE_PORT_MODEL = NUMBER_19_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp file transfer protocol (ftp) data service port model. */
static int* TCP_FTP_DATA_SERVICE_PORT_MODEL = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp file transfer protocol (ftp) service port model. */
static int* TCP_FTP_SERVICE_PORT_MODEL = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp fspd service port model. */
static int* UDP_FSP_SERVICE_PORT_MODEL = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp secure shell (ssh) remote login protocol service port model. */
static int* TCP_SSH_SERVICE_PORT_MODEL = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp secure shell (ssh) remote login protocol service port model. */
static int* UDP_SSH_SERVICE_PORT_MODEL = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp telnet service port model. */
static int* TCP_TELNET_SERVICE_PORT_MODEL = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp mail transfer protocol (smtp) service port model. */
static int* TCP_SMTP_SERVICE_PORT_MODEL = NUMBER_25_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp timeserver protocol service port model. */
static int* TCP_TIME_SERVICE_PORT_MODEL = NUMBER_37_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp timeserver protocol service port model. */
static int* UDP_TIME_SERVICE_PORT_MODEL = NUMBER_37_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp ressource location service port model. */
static int* TCP_RLP_SERVICE_PORT_MODEL = NUMBER_39_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp nameserver service port model. */
static int* TCP_NAMESERVER_SERVICE_PORT_MODEL = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp nicname service port model. */
static int* TCP_WHOIS_SERVICE_PORT_MODEL = NUMBER_43_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp login host protocol (tacacs) service port model. */
static int* TCP_TACACS_SERVICE_PORT_MODEL = NUMBER_49_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp login host protocol (tacacs) service port model. */
static int* UDP_TACACS_SERVICE_PORT_MODEL = NUMBER_49_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp remote mail checking protocol service port model. */
static int* TCP_RE_MAIL_CK_SERVICE_PORT_MODEL = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp remote mail checking protocol service port model. */
static int* UDP_RE_MAIL_CK_SERVICE_PORT_MODEL = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp name domain server service port model. */
static int* TCP_DOMAIN_SERVICE_PORT_MODEL = NUMBER_53_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp remote mail checking protocol service port model. */
static int* UDP_DOMAIN_SERVICE_PORT_MODEL = NUMBER_53_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp mtp service model. (deprecated) */
static int* TCP_MTP_SERVICE_PORT_MODEL = NUMBER_57_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp tacacs database service port model. */
static int* TCP_TACACS_DS_SERVICE_PORT_MODEL = NUMBER_65_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp tacacs database service port model. */
static int* UDP_TACACS_DS_SERVICE_PORT_MODEL = NUMBER_65_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp bootp server service port model. */
static int* TCP_BOOTPS_SERVICE_PORT_MODEL = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp bootp server service port model. */
static int* UDP_BOOTPS_SERVICE_PORT_MODEL = NUMBER_67_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp bootp client service port model. */
static int* TCP_BOOTPC_SERVICE_PORT_MODEL = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp bootp client service port model. */
static int* UDP_BOOTPC_SERVICE_PORT_MODEL = NUMBER_68_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp file transfer protocol service port model. */
static int* UDP_TFTP_SERVICE_PORT_MODEL = NUMBER_69_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp internet gopher service port model. */
static int* TCP_GOPHER_SERVICE_PORT_MODEL = NUMBER_70_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp internet gopher service port model. */
static int* UDP_GOPHER_SERVICE_PORT_MODEL = NUMBER_70_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp net rjs service port model. */
static int* TCP_RJE_SERVICE_PORT_MODEL = NUMBER_77_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp finger service port model. */
static int* TCP_FINGER_SERVICE_PORT_MODEL = NUMBER_79_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp world wide web (www) hypertext transfer protocol (http) service port model. */
static int* TCP_WWW_SERVICE_PORT_MODEL = NUMBER_80_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp world wide web (www) hypertext transfer protocol (http) service port model. */
static int* UDP_WWW_SERVICE_PORT_MODEL = NUMBER_80_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp tty link service port model. */
static int* TCP_LINK_SERVICE_PORT_MODEL = NUMBER_87_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp kerberos service port model. */
static int* TCP_KERBEROS_SERVICE_PORT_MODEL = NUMBER_88_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp kerberos service port model. */
static int* UDP_KERBEROS_SERVICE_PORT_MODEL = NUMBER_88_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp supdup service port model. */
static int* TCP_SUPDUP_SERVICE_PORT_MODEL = NUMBER_95_INTEGER_MEMORY_MODEL_ARRAY;

/** The hostname service port model. */
static int* TCP_HOSTNAME_SERVICE_PORT_MODEL = NUMBER_101_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp iso-tsap as part of the ISODE service port model. */
static int* TCP_ISO_TSAP_SERVICE_PORT_MODEL = NUMBER_102_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp acr-nema of the company Digital Imag. & Comm. 300 service port model. */
static int* TCP_ACR_NEMA_SERVICE_PORT_MODEL = NUMBER_104_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp acr-nema of the company Digital Imag. & Comm. 300 service port model. */
static int* UDP_ACR_NEMA_SERVICE_PORT_MODEL = NUMBER_104_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp csnet nameserver service port model. */
static int* TCP_CSNET_NS_SERVICE_PORT_MODEL = NUMBER_105_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp csnet nameserver service port model. */
static int* UDP_CSNET_NS_SERVICE_PORT_MODEL = NUMBER_105_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp remote telnet service port model. */
static int* TCP_RTELNET_SERVICE_PORT_MODEL = NUMBER_107_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp remote telnet service port model. */
static int* UDP_RTELNET_SERVICE_PORT_MODEL = NUMBER_107_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp postoffice pop 2 service port model. */
static int* TCP_POP2_SERVICE_PORT_MODEL = NUMBER_109_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp postoffice pop 2 service port model. */
static int* UDP_POP2_SERVICE_PORT_MODEL = NUMBER_109_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp post office protocol version 3 (pop3) service port model. */
static int* TCP_POP3_SERVICE_PORT_MODEL = NUMBER_110_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp post office protocol version 3 (pop3) service port model. */
static int* UDP_POP3_SERVICE_PORT_MODEL = NUMBER_110_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp rpc 4.0 portmapper service port model. */
static int* TCP_SUNRPC_SERVICE_PORT_MODEL = NUMBER_111_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp rpc 4.0 portmapper service port model. */
static int* UDP_SUNRPC_SERVICE_PORT_MODEL = NUMBER_111_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp authentication tap ident service port model. */
static int* TCP_AUTH_SERVICE_PORT_MODEL = NUMBER_113_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp secure file transfer protocol service port model. */
static int* TCP_SFTP_SERVICE_PORT_MODEL = NUMBER_115_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp uucp-path service port model. */
static int* TCP_UUCP_PATH_SERVICE_PORT_MODEL = NUMBER_117_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp usenet new transfer protocol service port model. */
static int* TCP_NNTP_SERVICE_PORT_MODEL = NUMBER_119_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp network time protocol service port model. */
static int* TCP_NTP_SERVICE_PORT_MODEL = NUMBER_123_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp network time protocol service port model. */
static int* UDP_NTP_SERVICE_PORT_MODEL = NUMBER_123_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp pwdgen service port model. */
static int* TCP_PWDGEN_SERVICE_PORT_MODEL = NUMBER_129_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp pwdgen service port model. */
static int* UDP_PWDGEN_SERVICE_PORT_MODEL = NUMBER_129_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp location service port model. */
static int* TCP_LOC_SRV_SERVICE_PORT_MODEL = NUMBER_135_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp location service port model. */
static int* UDP_LOC_SRV_SERVICE_PORT_MODEL = NUMBER_135_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp netbios name service port model. */
static int* TCP_NETBIOS_NS_SERVICE_PORT_MODEL = NUMBER_137_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp netbios name service port model. */
static int* UDP_NETBIOS_NS_SERVICE_PORT_MODEL = NUMBER_137_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp netbios datagram service port model. */
static int* TCP_NETBIOS_DGM_SERVICE_PORT_MODEL = NUMBER_138_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp netbios datagram service port model. */
static int* UDP_NETBIOS_DGM_SERVICE_PORT_MODEL = NUMBER_138_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp netbios session service port model. */
static int* TCP_NETBIOS_SSN_SERVICE_PORT_MODEL = NUMBER_139_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp netbios session service port model. */
static int* UDP_NETBIOS_SSN_SERVICE_PORT_MODEL = NUMBER_139_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp interim mail access protocol 2 and 4 service port model. */
static int* TCP_IMAP2_SERVICE_PORT_MODEL = NUMBER_143_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp interim mail access protocol 2 and 4 service port model. */
static int* UDP_IMAP2_SERVICE_PORT_MODEL = NUMBER_143_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp single net managment protocol service port model. */
static int* TCP_SNMP_SERVICE_PORT_MODEL = NUMBER_161_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp single net managment protocol service port model. */
static int* UDP_SNMP_SERVICE_PORT_MODEL = NUMBER_161_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp traps for snmp service port model. */
static int* TCP_SNMP_TRAP_SERVICE_PORT_MODEL = NUMBER_162_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp traps for snmp service port model. */
static int* UDP_SNMP_TRAP_SERVICE_PORT_MODEL = NUMBER_162_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp iso managment over ip service port model. */
static int* TCP_CMIP_MAN_SERVICE_PORT_MODEL = NUMBER_163_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp iso managment over ip service port model. */
static int* UDP_CMIP_MAN_SERVICE_PORT_MODEL = NUMBER_163_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp iso managment over ip agent service port model. */
static int* TCP_CMIP_AGENT_SERVICE_PORT_MODEL = NUMBER_164_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp iso managment over ip agent service port model. */
static int* UDP_CMIP_AGENT_SERVICE_PORT_MODEL = NUMBER_164_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp mailer transport queue for zmailer service port model. */
static int* TCP_MAILQ_SERVICE_PORT_MODEL = NUMBER_174_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp mailer transport queue for zmailer service port model. */
static int* UDP_MAILQ_SERVICE_PORT_MODEL = NUMBER_174_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp x display manager control protocol service port model. */
static int* TCP_XDMCP_SERVICE_PORT_MODEL = NUMBER_177_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp x display manager control protocol service port model. */
static int* UDP_XDMCP_SERVICE_PORT_MODEL = NUMBER_177_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp nextstep window service port model. */
static int* TCP_NEXTSTEP_SERVICE_PORT_MODEL = NUMBER_178_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp nextstep window service port model. */
static int* UDP_NEXTSTEP_SERVICE_PORT_MODEL = NUMBER_178_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp border gateway protocol service port model. */
static int* TCP_BGP_SERVICE_PORT_MODEL = NUMBER_179_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp border gateway protocol service port model. */
static int* UDP_BGP_SERVICE_PORT_MODEL = NUMBER_179_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp cliff neuman's prospero service port model. */
static int* TCP_PROSPERO_SERVICE_PORT_MODEL = NUMBER_191_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp cliff neuman's prospero service port model. */
static int* UDP_PROSPERO_SERVICE_PORT_MODEL = NUMBER_191_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp internet relay chat service port model. */
static int* TCP_IRC_SERVICE_PORT_MODEL = NUMBER_194_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp internet relay chat service port model. */
static int* UDP_IRC_SERVICE_PORT_MODEL = NUMBER_194_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp snmp unix multiplexer service port model. */
static int* TCP_SMUX_SERVICE_PORT_MODEL = NUMBER_199_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp snmp unix multiplexer service port model. */
static int* UDP_SMUX_SERVICE_PORT_MODEL = NUMBER_199_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp appletalk routing service port model. */
static int* TCP_AT_RTMP_SERVICE_PORT_MODEL = NUMBER_201_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp appletalk routing service port model. */
static int* UDP_AT_RTMP_SERVICE_PORT_MODEL = NUMBER_201_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp appletalk name binding service port model. */
static int* TCP_AT_NBP_SERVICE_PORT_MODEL = NUMBER_202_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp appletalk name binding service port model. */
static int* UDP_AT_NBP_SERVICE_PORT_MODEL = NUMBER_202_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp appletalk echo service port model. */
static int* TCP_AT_ECHO_SERVICE_PORT_MODEL = NUMBER_204_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp appletalk echo service port model. */
static int* UDP_AT_ECHO_SERVICE_PORT_MODEL = NUMBER_204_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp appletalk zone information service port model. */
static int* TCP_AT_ZIS_SERVICE_PORT_MODEL = NUMBER_206_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp appletalk zone information service port model. */
static int* UDP_AT_ZIS_SERVICE_PORT_MODEL = NUMBER_206_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp quick mail transfer protocol service port model. */
static int* TCP_QMTP_SERVICE_PORT_MODEL = NUMBER_209_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp quick mail transfer protocol service port model. */
static int* UDP_QMTP_SERVICE_PORT_MODEL = NUMBER_209_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp niso z39.50 database service port model. */
static int* TCP_Z3950_SERVICE_PORT_MODEL = NUMBER_210_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp niso z39.50 database service port model. */
static int* UDP_Z3950_SERVICE_PORT_MODEL = NUMBER_210_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp icp service port model. */
static int* TCP_IPX_SERVICE_PORT_MODEL = NUMBER_213_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp icp service port model. */
static int* UDP_IPX_SERVICE_PORT_MODEL = NUMBER_213_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp interactive mail access service port model. */
static int* TCP_IMAP3_SERVICE_PORT_MODEL = NUMBER_220_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp interactive mail access service port model. */
static int* UDP_IMAP3_SERVICE_PORT_MODEL = NUMBER_220_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp perf analysis workbench service port model. */
static int* TCP_PAWSERV_SERVICE_PORT_MODEL = NUMBER_345_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp perf analysis workbench service port model. */
static int* UDP_PAWSERV_SERVICE_PORT_MODEL = NUMBER_345_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp zebra server service port model. */
static int* TCP_ZSERV_SERVICE_PORT_MODEL = NUMBER_346_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp zebra server service port model. */
static int* UDP_ZSERV_SERVICE_PORT_MODEL = NUMBER_346_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp fatmen server service port model. */
static int* TCP_FATSERV_SERVICE_PORT_MODEL = NUMBER_347_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp fatmen server service port model. */
static int* UDP_FATSERV_SERVICE_PORT_MODEL = NUMBER_347_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp coda portmapper service port model. */
static int* TCP_RPC2PORTMAP_SERVICE_PORT_MODEL = NUMBER_369_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp coda portmapper service port model. */
static int* UDP_RPC2PORTMAP_SERVICE_PORT_MODEL = NUMBER_369_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp coda authentication server service port model. */
static int* TCP_CODAAUTH2_SERVICE_PORT_MODEL = NUMBER_370_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp coda authentication server service port model. */
static int* UDP_CODAAUTH2_SERVICE_PORT_MODEL = NUMBER_370_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp clearcase service port model. */
static int* TCP_CLEARCASE_SERVICE_PORT_MODEL = NUMBER_371_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp clearcase service port model. */
static int* UDP_CLEARCASE_SERVICE_PORT_MODEL = NUMBER_371_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp unix listserv service port model. */
static int* TCP_ULISTSERV_SERVICE_PORT_MODEL = NUMBER_371_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp unix listserv service port model. */
static int* UDP_ULISTSERV_SERVICE_PORT_MODEL = NUMBER_371_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp lightweight directory access protocol service port model. */
static int* TCP_LDAP_SERVICE_PORT_MODEL = NUMBER_389_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp lightweight directory access protocol service port model. */
static int* UDP_LDAP_SERVICE_PORT_MODEL = NUMBER_389_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp interactive mail support protocol service port model. */
static int* TCP_IMSP_SERVICE_PORT_MODEL = NUMBER_406_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp interactive mail support protocol service port model. */
static int* UDP_IMSP_SERVICE_PORT_MODEL = NUMBER_406_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp server location service port model. */
static int* TCP_SVRLOC_SERVICE_PORT_MODEL = NUMBER_427_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp server location service port model. */
static int* UDP_SVRLOC_SERVICE_PORT_MODEL = NUMBER_427_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp hypertext transfer protocol over tls/ ssl (https) service port model. */
static int* TCP_HTTPS_SERVICE_PORT_MODEL = NUMBER_443_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp hypertext transfer protocol over tls/ ssl (https) service port model. */
static int* UDP_HTTPS_SERVICE_PORT_MODEL = NUMBER_443_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp simple network paging protocol service port model. */
static int* TCP_SNPP_SERVICE_PORT_MODEL = NUMBER_444_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp simple network paging protocol service port model. */
static int* UDP_SNPP_SERVICE_PORT_MODEL = NUMBER_444_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp microsoft naked cifs service port model. */
static int* TCP_MICROSOFT_DS_SERVICE_PORT_MODEL = NUMBER_445_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp microsoft naked cifs service port model. */
static int* UDP_MICROSOFT_DS_SERVICE_PORT_MODEL = NUMBER_445_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp kpasswd service port model. */
static int* TCP_KPASSWD_SERVICE_PORT_MODEL = NUMBER_464_INTEGER_MEMORY_MODEL_ARRAY;

/** The udü kpasswd service port model. */
static int* UDP_KPASSWD_SERVICE_PORT_MODEL = NUMBER_464_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp simple asynchronous file transfer service port model. */
static int* TCP_SAFT_SERVICE_PORT_MODEL = NUMBER_487_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp simple asynchronous file transfer service port model. */
static int* UDP_SAFT_SERVICE_PORT_MODEL = NUMBER_487_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp ipsec internet security association service port model. */
static int* TCP_ISAKMP_SERVICE_PORT_MODEL = NUMBER_500_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp ipsec internet security association service port model. */
static int* UDP_ISAKMP_SERVICE_PORT_MODEL = NUMBER_500_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp real time stream control protocol service port model. */
static int* TCP_RTSP_SERVICE_PORT_MODEL = NUMBER_554_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp real time stream control protocol service port model. */
static int* UDP_RTSP_SERVICE_PORT_MODEL = NUMBER_554_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp network queuing system service port model. */
static int* TCP_NQS_SERVICE_PORT_MODEL = NUMBER_607_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp network queuing system service port model. */
static int* UDP_NQS_SERVICE_PORT_MODEL = NUMBER_607_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp npmp local DQS service port model. */
static int* TCP_NPMP_LOCAL_SERVICE_PORT_MODEL = NUMBER_610_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp npmp local DQS service port model. */
static int* UDP_NPMP_LOCAL_SERVICE_PORT_MODEL = NUMBER_610_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp npmp gui DQS service port model. */
static int* TCP_NPMP_GUI_SERVICE_PORT_MODEL = NUMBER_611_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp npmp gui DQS service port model. */
static int* UDP_NPMP_GUI_SERVICE_PORT_MODEL = NUMBER_611_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp hmmp indication DQS service port model. */
static int* TCP_HMMP_IND_SERVICE_PORT_MODEL = NUMBER_612_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp hmmp indication DQS service port model. */
static int* UDP_HMMP_IND_SERVICE_PORT_MODEL = NUMBER_612_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp qmqp service port model. */
static int* TCP_QMQP_SERVICE_PORT_MODEL = NUMBER_628_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp qmqp service port model. */
static int* UDP_QMQP_SERVICE_PORT_MODEL = NUMBER_628_INTEGER_MEMORY_MODEL_ARRAY;

/** The internet printing protocol service port model. */
static int* TCP_IPP_SERVICE_PORT_MODEL = NUMBER_631_INTEGER_MEMORY_MODEL_ARRAY;

//
// UNIX specific services
//

/** The tcp exec service port model. */
static int* TCP_EXEC_SERVICE_PORT_MODEL = NUMBER_512_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp comsat biff service port model. */
static int* UDP_BIFF_SERVICE_PORT_MODEL = NUMBER_512_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp login service port model. */
static int* TCP_LOGIN_SERVICE_PORT_MODEL = NUMBER_513_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp who service port model. */
static int* UDP_WHO_SERVICE_PORT_MODEL = NUMBER_513_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp shell service port model. */
static int* TCP_SHELL_SERVICE_PORT_MODEL = NUMBER_514_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp syslog service port model. */
static int* UDP_SYSLOG_SERVICE_PORT_MODEL = NUMBER_514_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp line printer spooler service port model. */
static int* TCP_PRINTER_SERVICE_PORT_MODEL = NUMBER_515_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp talk service port model. */
static int* UDP_TALK_SERVICE_PORT_MODEL = NUMBER_517_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp ntalk service port model. */
static int* UDP_NTALK_SERVICE_PORT_MODEL = NUMBER_518_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp route service port model. */
static int* UDP_ROUTE_SERVICE_PORT_MODEL = NUMBER_520_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp time server service port model. */
static int* UDP_TIMED_SERVICE_PORT_MODEL = NUMBER_525_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp tempo service port model. */
static int* TCP_TEMPO_SERVICE_PORT_MODEL = NUMBER_526_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp rpc courier service port model. */
static int* TCP_COURIER_SERVICE_PORT_MODEL = NUMBER_530_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp conference chat service port model. */
static int* TCP_CONFERENCE_SERVICE_PORT_MODEL = NUMBER_531_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp readnews netnews service port model. */
static int* TCP_NETNEWS_SERVICE_PORT_MODEL = NUMBER_532_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp netwall for emergency broadcasts service port model. */
static int* UDP_NETWALL_SERVICE_PORT_MODEL = NUMBER_533_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp gnustep distributed objects service port model. */
static int* TCP_GDOMAP_SERVICE_PORT_MODEL = NUMBER_538_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp gnustep distributed objects service port model. */
static int* UDP_GDOMAP_SERVICE_PORT_MODEL = NUMBER_538_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp uucp daemon service port model. */
static int* TCP_UUCP_SERVICE_PORT_MODEL = NUMBER_540_INTEGER_MEMORY_MODEL_ARRAY;

/** The kerberized rlogin v5 service port model. */
static int* TCP_KLOGIN_SERVICE_PORT_MODEL = NUMBER_543_INTEGER_MEMORY_MODEL_ARRAY;

/** The kerberized rsh v5 service port model. */
static int* TCP_KSHELL_SERVICE_PORT_MODEL = NUMBER_544_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp dhcp v6 client service port model. */
static int* TCP_DHCPV6_CLIENT_SERVICE_PORT_MODEL = NUMBER_546_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp dhcp v6 client service port model. */
static int* UDP_DHCPV6_CLIENT_SERVICE_PORT_MODEL = NUMBER_546_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp dhcp v6 server service port model. */
static int* TCP_DHCP6_SERVER_SERVICE_PORT_MODEL = NUMBER_547_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp dhcp v6 server service port model. */
static int* UDP_DHCP6_SERVER_SERVICE_PORT_MODEL = NUMBER_547_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp afp over tcp service port model. */
static int* TCP_AFPOVERTCP_SERVICE_PORT_MODEL = NUMBER_548_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp afp over tcp service port model. */
static int* UDP_AFPOVERTCP_SERVICE_PORT_MODEL = NUMBER_548_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp idfp service port model. */
static int* TCP_IDFP_SERVICE_PORT_MODEL = NUMBER_549_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp idfp service port model. */
static int* UDP_IDFP_SERVICE_PORT_MODEL = NUMBER_549_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp brunhoff remote filesystem service port model. */
static int* TCP_REMOTEFS_SERVICE_PORT_MODEL = NUMBER_556_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp nntp over ssl service port model. */
static int* TCP_NNTPS_SERVICE_PORT_MODEL = NUMBER_563_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp nntp over ssl service port model. */
static int* UDP_NNTPS_SERVICE_PORT_MODEL = NUMBER_563_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp submission service port model. */
static int* TCP_SUBMISSION_SERVICE_PORT_MODEL = NUMBER_587_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp submission service port model. */
static int* UDP_SUBMISSION_SERVICE_PORT_MODEL = NUMBER_587_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp ldap over ssl service port model. */
static int* TCP_LDAPS_SERVICE_PORT_MODEL = NUMBER_636_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp ldap over ssl service port model. */
static int* UDP_LDAPS_SERVICE_PORT_MODEL = NUMBER_636_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp tinc control port service port model. */
static int* TCP_TINC_SERVICE_PORT_MODEL = NUMBER_655_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp tinc control port service port model. */
static int* UDP_TINC_SERVICE_PORT_MODEL = NUMBER_655_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp silc service port model. */
static int* TCP_SILC_SERVICE_PORT_MODEL = NUMBER_706_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp silc service port model. */
static int* UDP_SILC_SERVICE_PORT_MODEL = NUMBER_706_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp kerberos kadmin v5 service port model. */
static int* TCP_KERBEROS_ADM_SERVICE_PORT_MODEL = NUMBER_749_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp network dictionary webster service port model. */
static int* TCP_WEBSTER_SERVICE_PORT_MODEL = NUMBER_765_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp network dictionary webster service port model. */
static int* UDP_WEBSTER_SERVICE_PORT_MODEL = NUMBER_765_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp rsync service port model. */
static int* TCP_RSYNC_SERVICE_PORT_MODEL = NUMBER_873_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp rsync service port model. */
static int* UDP_RSYNC_SERVICE_PORT_MODEL = NUMBER_873_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp ftp over ssl data service port model. */
static int* TCP_FTPS_DATA_SERVICE_PORT_MODEL = NUMBER_989_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp ftp over ssl service port model. */
static int* TCP_FTPS_SERVICE_PORT_MODEL = NUMBER_990_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp telnet over ssl service port model. */
static int* TCP_TELNETS_SERVICE_PORT_MODEL = NUMBER_992_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp telnet over ssl service port model. */
static int* UDP_TELNETS_SERVICE_PORT_MODEL = NUMBER_992_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp imap over ssl service port model. */
static int* TCP_IMAPS_SERVICE_PORT_MODEL = NUMBER_993_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp imap over ssl service port model. */
static int* UDP_IMAPS_SERVICE_PORT_MODEL = NUMBER_993_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp irc over sll service port model. */
static int* TCP_IRCS_SERVICE_PORT_MODEL = NUMBER_994_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp irc over sll service port model. */
static int* UDP_IRCS_SERVICE_PORT_MODEL = NUMBER_994_INTEGER_MEMORY_MODEL_ARRAY;

/** The tcp pop3 over ssl service port model. */
static int* TCP_POP3S_SERVICE_PORT_MODEL = NUMBER_995_INTEGER_MEMORY_MODEL_ARRAY;

/** The udp pop3 over ssl service port model. */
static int* UDP_POP3S_SERVICE_PORT_MODEL = NUMBER_995_INTEGER_MEMORY_MODEL_ARRAY;

/** The cybernetics oriented interpreter (cyboi) service port model. */
static int* CYBOI_SERVICE_PORT_MODEL = NUMBER_1971_INTEGER_MEMORY_MODEL_ARRAY;

/* SERVICE_PORT_MODEL_SOURCE */
#endif
