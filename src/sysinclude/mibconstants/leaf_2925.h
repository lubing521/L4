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
 **** Last build date: Thu Jul 03 17:32:50 2003
 **** from files:
 ****  ..\MibFiles\Rfc1213.mib, ctl\Rfc1213.ctl,
 ****  ..\MibFiles\IanaIfType_Rfc1573.mib, ..\MibFiles\SnmpV2_Rfc1907.mib,
 ****  ctl\SnmpV2_Rfc1907.ctl, ..\MibFiles\If_Rfc2863.mib, ctl\If_Rfc2863.ctl,
 ****  ..\MibFiles\SnmpFramework_Rfc2271.mib, ctl\SnmpFramework_Rfc2271.ctl,
 ****  ..\MibFiles\InetAddress_Rfc3291.mib, ..\MibFiles\DismanPing_Rfc2925.mib,
 ****  ctl\DismanPing_Rfc2925.ctl, ..\MibFiles\DismanTraceRoute_rfc2925.mib
 ******************************************************************************
 ******************************************************************************
 */

#define LEAF_traceRouteMaxConcurrentRequests	1
#define LEAF_traceRouteCtlOwnerIndex	1
#define MINSIZE_traceRouteCtlOwnerIndex	0L
#define MAXSIZE_traceRouteCtlOwnerIndex	32L
#define LEAF_traceRouteCtlTestName	2
#define MINSIZE_traceRouteCtlTestName	0L
#define MAXSIZE_traceRouteCtlTestName	32L
#define LEAF_traceRouteCtlTargetAddressType	3
#define VAL_traceRouteCtlTargetAddressType_unknown	0L
#define VAL_traceRouteCtlTargetAddressType_ipv4	1L
#define VAL_traceRouteCtlTargetAddressType_ipv6	2L
#define VAL_traceRouteCtlTargetAddressType_ipv4z	3L
#define VAL_traceRouteCtlTargetAddressType_ipv6z	4L
#define VAL_traceRouteCtlTargetAddressType_dns	16L
#define LEAF_traceRouteCtlTargetAddress	4
#define MINSIZE_traceRouteCtlTargetAddress	0L
#define MAXSIZE_traceRouteCtlTargetAddress	255L
#define LEAF_traceRouteCtlByPassRouteTable	5
#define VAL_traceRouteCtlByPassRouteTable_true	1L
#define VAL_traceRouteCtlByPassRouteTable_false	2L
#define LEAF_traceRouteCtlDataSize	6
#define MIN_traceRouteCtlDataSize	0L
#define MAX_traceRouteCtlDataSize	65507L
#define LEAF_traceRouteCtlTimeOut	7
#define MIN_traceRouteCtlTimeOut	1L
#define MAX_traceRouteCtlTimeOut	60L
#define LEAF_traceRouteCtlProbesPerHop	8
#define MIN_traceRouteCtlProbesPerHop	1L
#define MAX_traceRouteCtlProbesPerHop	10L
#define LEAF_traceRouteCtlPort	9
#define MIN_traceRouteCtlPort	1L
#define MAX_traceRouteCtlPort	65535L
#define LEAF_traceRouteCtlMaxTtl	10
#define MIN_traceRouteCtlMaxTtl	1L
#define MAX_traceRouteCtlMaxTtl	255L
#define LEAF_traceRouteCtlDSField	11
#define MIN_traceRouteCtlDSField	0L
#define MAX_traceRouteCtlDSField	255L
#define LEAF_traceRouteCtlSourceAddressType	12
#define VAL_traceRouteCtlSourceAddressType_unknown	0L
#define VAL_traceRouteCtlSourceAddressType_ipv4	1L
#define VAL_traceRouteCtlSourceAddressType_ipv6	2L
#define VAL_traceRouteCtlSourceAddressType_ipv4z	3L
#define VAL_traceRouteCtlSourceAddressType_ipv6z	4L
#define VAL_traceRouteCtlSourceAddressType_dns	16L
#define LEAF_traceRouteCtlSourceAddress	13
#define MINSIZE_traceRouteCtlSourceAddress	0L
#define MAXSIZE_traceRouteCtlSourceAddress	255L
#define LEAF_traceRouteCtlIfIndex	14
#define MIN_traceRouteCtlIfIndex	0L
#define MAX_traceRouteCtlIfIndex	2147483647L
#define LEAF_traceRouteCtlMiscOptions	15
#define MINSIZE_traceRouteCtlMiscOptions	0L
#define MAXSIZE_traceRouteCtlMiscOptions	255L
#define LEAF_traceRouteCtlMaxFailures	16
#define MIN_traceRouteCtlMaxFailures	0L
#define MAX_traceRouteCtlMaxFailures	255L
#define LEAF_traceRouteCtlDontFragment	17
#define VAL_traceRouteCtlDontFragment_true	1L
#define VAL_traceRouteCtlDontFragment_false	2L
#define LEAF_traceRouteCtlInitialTtl	18
#define MIN_traceRouteCtlInitialTtl	0L
#define MAX_traceRouteCtlInitialTtl	255L
#define LEAF_traceRouteCtlFrequency	19
#define LEAF_traceRouteCtlStorageType	20
#define VAL_traceRouteCtlStorageType_other	1L
#define VAL_traceRouteCtlStorageType_volatile	2L
#define VAL_traceRouteCtlStorageType_nonVolatile	3L
#define VAL_traceRouteCtlStorageType_permanent	4L
#define VAL_traceRouteCtlStorageType_readOnly	5L
#define LEAF_traceRouteCtlAdminStatus	21
#define VAL_traceRouteCtlAdminStatus_enabled	1L
#define VAL_traceRouteCtlAdminStatus_disabled	2L
#define LEAF_traceRouteCtlDescr	22
#define MINSIZE_traceRouteCtlDescr	0L
#define MAXSIZE_traceRouteCtlDescr	255L
#define LEAF_traceRouteCtlMaxRows	23
#define LEAF_traceRouteCtlTrapGeneration	24
#define VAL_traceRouteCtlTrapGeneration_pathChange	0L
#define VAL_traceRouteCtlTrapGeneration_testFailure	1L
#define VAL_traceRouteCtlTrapGeneration_testCompletion	2L
#define LEAF_traceRouteCtlCreateHopsEntries	25
#define VAL_traceRouteCtlCreateHopsEntries_true	1L
#define VAL_traceRouteCtlCreateHopsEntries_false	2L
#define LEAF_traceRouteCtlType	26
#define LEAF_traceRouteCtlRowStatus	27
#define VAL_traceRouteCtlRowStatus_active	1L
#define VAL_traceRouteCtlRowStatus_notInService	2L
#define VAL_traceRouteCtlRowStatus_notReady	3L
#define VAL_traceRouteCtlRowStatus_createAndGo	4L
#define VAL_traceRouteCtlRowStatus_createAndWait	5L
#define VAL_traceRouteCtlRowStatus_destroy	6L
#define LEAF_traceRouteResultsOperStatus	1
#define VAL_traceRouteResultsOperStatus_enabled	1L
#define VAL_traceRouteResultsOperStatus_disabled	2L
#define LEAF_traceRouteResultsCurHopCount	2
#define LEAF_traceRouteResultsCurProbeCount	3
#define LEAF_traceRouteResultsIpTgtAddrType	4
#define VAL_traceRouteResultsIpTgtAddrType_unknown	0L
#define VAL_traceRouteResultsIpTgtAddrType_ipv4	1L
#define VAL_traceRouteResultsIpTgtAddrType_ipv6	2L
#define VAL_traceRouteResultsIpTgtAddrType_ipv4z	3L
#define VAL_traceRouteResultsIpTgtAddrType_ipv6z	4L
#define VAL_traceRouteResultsIpTgtAddrType_dns	16L
#define LEAF_traceRouteResultsIpTgtAddr	5
#define MINSIZE_traceRouteResultsIpTgtAddr	0L
#define MAXSIZE_traceRouteResultsIpTgtAddr	255L
#define LEAF_traceRouteResultsTestAttempts	6
#define LEAF_traceRouteResultsTestSuccesses	7
#define LEAF_traceRouteResultsLastGoodPath	8
#define SIZE_traceRouteResultsLastGoodPath_1	8L
#define SIZE_traceRouteResultsLastGoodPath_2	11L
#define LEAF_traceRouteProbeHistoryIndex	1
#define MIN_traceRouteProbeHistoryIndex	1L
#define MAX_traceRouteProbeHistoryIndex	4294967295L
#define LEAF_traceRouteProbeHistoryHopIndex	2
#define MIN_traceRouteProbeHistoryHopIndex	1L
#define MAX_traceRouteProbeHistoryHopIndex	255L
#define LEAF_traceRouteProbeHistoryProbeIndex	3
#define MIN_traceRouteProbeHistoryProbeIndex	1L
#define MAX_traceRouteProbeHistoryProbeIndex	10L
#define LEAF_traceRouteProbeHistoryHAddrType	4
#define VAL_traceRouteProbeHistoryHAddrType_unknown	0L
#define VAL_traceRouteProbeHistoryHAddrType_ipv4	1L
#define VAL_traceRouteProbeHistoryHAddrType_ipv6	2L
#define VAL_traceRouteProbeHistoryHAddrType_ipv4z	3L
#define VAL_traceRouteProbeHistoryHAddrType_ipv6z	4L
#define VAL_traceRouteProbeHistoryHAddrType_dns	16L
#define LEAF_traceRouteProbeHistoryHAddr	5
#define MINSIZE_traceRouteProbeHistoryHAddr	0L
#define MAXSIZE_traceRouteProbeHistoryHAddr	255L
#define LEAF_traceRouteProbeHistoryResponse	6
#define LEAF_traceRouteProbeHistoryStatus	7
#define VAL_traceRouteProbeHistoryStatus_responseReceived	1L
#define VAL_traceRouteProbeHistoryStatus_unknown	2L
#define VAL_traceRouteProbeHistoryStatus_internalError	3L
#define VAL_traceRouteProbeHistoryStatus_requestTimedOut	4L
#define VAL_traceRouteProbeHistoryStatus_unknownDestinationAddress	5L
#define VAL_traceRouteProbeHistoryStatus_noRouteToTarget	6L
#define VAL_traceRouteProbeHistoryStatus_interfaceInactiveToTarget	7L
#define VAL_traceRouteProbeHistoryStatus_arpFailure	8L
#define VAL_traceRouteProbeHistoryStatus_maxConcurrentLimitReached	9L
#define VAL_traceRouteProbeHistoryStatus_unableToResolveDnsName	10L
#define VAL_traceRouteProbeHistoryStatus_invalidHostAddress	11L
#define LEAF_traceRouteProbeHistoryLastRC	8
#define LEAF_traceRouteProbeHistoryTime	9
#define SIZE_traceRouteProbeHistoryTime_1	8L
#define SIZE_traceRouteProbeHistoryTime_2	11L
#define LEAF_traceRouteHopsHopIndex	1
#define LEAF_traceRouteHopsIpTgtAddressType	2
#define VAL_traceRouteHopsIpTgtAddressType_unknown	0L
#define VAL_traceRouteHopsIpTgtAddressType_ipv4	1L
#define VAL_traceRouteHopsIpTgtAddressType_ipv6	2L
#define VAL_traceRouteHopsIpTgtAddressType_ipv4z	3L
#define VAL_traceRouteHopsIpTgtAddressType_ipv6z	4L
#define VAL_traceRouteHopsIpTgtAddressType_dns	16L
#define LEAF_traceRouteHopsIpTgtAddress	3
#define MINSIZE_traceRouteHopsIpTgtAddress	0L
#define MAXSIZE_traceRouteHopsIpTgtAddress	255L
#define LEAF_traceRouteHopsMinRtt	4
#define LEAF_traceRouteHopsMaxRtt	5
#define LEAF_traceRouteHopsAverageRtt	6
#define LEAF_traceRouteHopsRttSumOfSquares	7
#define LEAF_traceRouteHopsSentProbes	8
#define LEAF_traceRouteHopsProbeResponses	9
#define LEAF_traceRouteHopsLastGoodProbe	10
#define SIZE_traceRouteHopsLastGoodProbe_1	8L
#define SIZE_traceRouteHopsLastGoodProbe_2	11L
#define LEAF_traceRouteUsingUdpProbes 1
#define LEAF_snmpTrapOID	1
#define LEAF_snmpTrapEnterprise	3

/* River@May 7, 2008, add nslookup mib */
#define LEAF_dnsCtlOwnerIndex	1
#define MINSIZE_dnsCtlOwnerIndex	0L
#define MAXSIZE_dnsCtlOwnerIndex	32L
#define LEAF_dnsCtlOperationName	2
#define MINSIZE_dnsCtlOperationName	0L
#define MAXSIZE_dnsCtlOperationName	32L
#define LEAF_dnsCtlTargetAddressType	3
#define VAL_dnsCtlTargetAddressType_unknown	0L
#define VAL_dnsCtlTargetAddressType_ipv4	1L
#define VAL_dnsCtlTargetAddressType_ipv6	2L
#define VAL_dnsCtlTargetAddressType_ipv4z	3L
#define VAL_dnsCtlTargetAddressType_ipv6z	4L
#define VAL_dnsCtlTargetAddressType_dns	16L
#define LEAF_dnsCtlTargetAddress	4
#define MINSIZE_dnsCtlTargetAddress	0L
#define MAXSIZE_dnsCtlTargetAddress	255L
#define LEAF_dnsCtlRowStatus	5
#define VAL_dnsCtlRowStatus_active	1L
#define VAL_dnsCtlRowStatus_notInService	2L
#define VAL_dnsCtlRowStatus_notReady	3L
#define VAL_dnsCtlRowStatus_createAndGo	4L
#define VAL_dnsCtlRowStatus_createAndWait	5L
#define VAL_dnsCtlRowStatus_destroy	6L


#define LEAF_dnsResultsIndex	1
#define LEAF_dnsResultsAddressType	2
#define VAL_dnsResultsAddressType_unknown	0L
#define VAL_dnsResultsAddressType_ipv4	1L
#define VAL_dnsResultsAddressType_ipv6	2L
#define VAL_dnsResultsAddressType_ipv4z	3L
#define VAL_dnsResultsAddressType_ipv6z	4L
#define VAL_dnsResultsAddressType_dns	16L
#define LEAF_dnsResultsAddress	3
#define MINSIZE_dnsResultsAddress	0L
#define MAXSIZE_dnsResultsAddress	255L

