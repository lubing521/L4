/******************************************************************************
 ******************************************************************************
 **** This file was automatically generated by Epilogue Technology's
 **** Emissary SNMP MIB Compiler, version 6.3.
 **** This file was generated using the -leaf switch.
 **** 
 **** This file #defines C preprocessor macros providing a variety of
 **** information for the leaf objects in the MIB.
 **** 
 **** The file includes a LEAF_xxx macro for each leaf object in the
 **** MIB (xxx is replaced by the object's name).  The value of the
 **** LEAF_xxx macro is the final component of the object's object
 **** identifier.
 **** 
 **** If the object's SYNTAX clause included named INTEGER values,
 **** then there is a VAL_xxx_yyy macro for each named value (xxx is
 **** replaced by the object's name and yyy by the value's name).  The
 **** value of the VAL_xxx_yyy macro is the value associated with the
 **** named value.
 **** 
 **** If the object's SYNTAX clause specified a set of range limitations
 **** for the value of the object, then there are one or more sets of
 **** MIN_xxx and MAX_xxx macros specifying the lower and upper bound of
 **** each range limitation.
 **** 
 **** If the object's SYNTAX clause specified a set of size constraints
 **** for the value of the object, then there are one or more sets of
 **** MINSIZE_xxx and MAXSIZE_xxx macros specifying the lower and upper
 **** bound of each size constraint.  (If the size constraint is a single
 **** value rather than a range then the MINSIZE_xxx and MAXSIZE_xxx
 **** macros are replaced by a single SIZE_xxx macro.)
 **** 
 **** DO NOT MODIFY THIS FILE BY HAND.
 **** 
 **** Last build date: Tue Jan 14 17:28:30 2003
 **** from files:
 ****  ..\StdMib\Rfc1213.mib, ctl\Rfc1213.ctl,
 ****  ..\StdMib\IanaIfType_Rfc1573.mib, ..\StdMib\SnmpV2_Rfc1907.mib,
 ****  ctl\SnmpV2_Rfc1907.ctl, ..\StdMib\If_Rfc2863.mib, ctl\If_Rfc2863.ctl,
 ****  ..\StdMib\Vrrp_Rfc2787.mib
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_2787_H
#define  LEAF_2787_H

#define LEAF_vrrpNodeVersion	1
#define LEAF_vrrpNotificationCntl	2
#define VAL_vrrpNotificationCntl_enabled	1L
#define VAL_vrrpNotificationCntl_disabled	2L
#define LEAF_vrrpOperVrId	1
#define MIN_vrrpOperVrId	1L
#define MAX_vrrpOperVrId	255L
#define LEAF_vrrpOperVirtualMacAddr	2
#define SIZE_vrrpOperVirtualMacAddr	6L
#define LEAF_vrrpOperState	3
#define VAL_vrrpOperState_initialize	1L
#define VAL_vrrpOperState_backup	2L
#define VAL_vrrpOperState_master	3L
#define LEAF_vrrpOperAdminState	4
#define VAL_vrrpOperAdminState_up	1L
#define VAL_vrrpOperAdminState_down	2L
#define LEAF_vrrpOperPriority	5
#define MIN_vrrpOperPriority	0L
#define MAX_vrrpOperPriority	255L
#define LEAF_vrrpOperIpAddrCount	6
#define MIN_vrrpOperIpAddrCount	0L
#define MAX_vrrpOperIpAddrCount	255L
#define LEAF_vrrpOperMasterIpAddr	7
#define LEAF_vrrpOperPrimaryIpAddr	8
#define LEAF_vrrpOperAuthType	9
#define VAL_vrrpOperAuthType_noAuthentication	1L
#define VAL_vrrpOperAuthType_simpleTextPassword	2L
#define VAL_vrrpOperAuthType_ipAuthenticationHeader	3L
#define LEAF_vrrpOperAuthKey	10
#define MINSIZE_vrrpOperAuthKey	0L
#define MAXSIZE_vrrpOperAuthKey	16L
#define LEAF_vrrpOperAdvertisementInterval	11
#define MIN_vrrpOperAdvertisementInterval	1L
#define MAX_vrrpOperAdvertisementInterval	255L
#define LEAF_vrrpOperPreemptMode	12
#define VAL_vrrpOperPreemptMode_true	1L
#define VAL_vrrpOperPreemptMode_false	2L
#define LEAF_vrrpOperVirtualRouterUpTime	13
#define LEAF_vrrpOperProtocol	14
#define VAL_vrrpOperProtocol_ip	1L
#define VAL_vrrpOperProtocol_bridge	2L
#define VAL_vrrpOperProtocol_decnet	3L
#define VAL_vrrpOperProtocol_other	4L
#define LEAF_vrrpOperRowStatus	15
#define VAL_vrrpOperRowStatus_active	1L
#define VAL_vrrpOperRowStatus_notInService	2L
#define VAL_vrrpOperRowStatus_notReady	3L
#define VAL_vrrpOperRowStatus_createAndGo	4L
#define VAL_vrrpOperRowStatus_createAndWait	5L
#define VAL_vrrpOperRowStatus_destroy	6L
#define LEAF_vrrpAssoIpAddr	1
#define LEAF_vrrpAssoIpAddrRowStatus	2
#define VAL_vrrpAssoIpAddrRowStatus_active	1L
#define VAL_vrrpAssoIpAddrRowStatus_notInService	2L
#define VAL_vrrpAssoIpAddrRowStatus_notReady	3L
#define VAL_vrrpAssoIpAddrRowStatus_createAndGo	4L
#define VAL_vrrpAssoIpAddrRowStatus_createAndWait	5L
#define VAL_vrrpAssoIpAddrRowStatus_destroy	6L
#define LEAF_vrrpTrapPacketSrc	5
#define LEAF_vrrpTrapAuthErrorType	6
#define VAL_vrrpTrapAuthErrorType_invalidAuthType	1L
#define VAL_vrrpTrapAuthErrorType_authTypeMismatch	2L
#define VAL_vrrpTrapAuthErrorType_authFailure	3L
#define LEAF_vrrpRouterChecksumErrors	1
#define LEAF_vrrpRouterVersionErrors	2
#define LEAF_vrrpRouterVrIdErrors	3
#define LEAF_vrrpStatsBecomeMaster	1
#define LEAF_vrrpStatsAdvertiseRcvd	2
#define LEAF_vrrpStatsAdvertiseIntervalErrors	3
#define LEAF_vrrpStatsAuthFailures	4
#define LEAF_vrrpStatsIpTtlErrors	5
#define LEAF_vrrpStatsPriorityZeroPktsRcvd	6
#define LEAF_vrrpStatsPriorityZeroPktsSent	7
#define LEAF_vrrpStatsInvalidTypePktsRcvd	8
#define LEAF_vrrpStatsAddressListErrors	9
#define LEAF_vrrpStatsInvalidAuthType	10
#define LEAF_vrrpStatsAuthTypeMismatch	11
#define LEAF_vrrpStatsPacketLengthErrors	12
#define LEAF_snmpTrapOID	1
#define LEAF_snmpTrapEnterprise	3

#endif /* end of #ifndef  LEAF_2787_H */