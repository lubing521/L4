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

#define LEAF_pingMaxConcurrentRequests	1
#define LEAF_pingCtlOwnerIndex	1
#define MINSIZE_pingCtlOwnerIndex	0L
#define MAXSIZE_pingCtlOwnerIndex	32L
#define LEAF_pingCtlTestName	2
#define MINSIZE_pingCtlTestName	0L
#define MAXSIZE_pingCtlTestName	32L
#define LEAF_pingCtlTargetAddressType	3
#define VAL_pingCtlTargetAddressType_unknown	0L
#define VAL_pingCtlTargetAddressType_ipv4	1L
#define VAL_pingCtlTargetAddressType_ipv6	2L
#define VAL_pingCtlTargetAddressType_ipv4z	3L
#define VAL_pingCtlTargetAddressType_ipv6z	4L
#define VAL_pingCtlTargetAddressType_dns	16L
#define LEAF_pingCtlTargetAddress	4
#define MINSIZE_pingCtlTargetAddress	0L
#define MAXSIZE_pingCtlTargetAddress	255L
#define LEAF_pingCtlDataSize	5
#define MIN_pingCtlDataSize	0L
#define MAX_pingCtlDataSize	65507L
#define LEAF_pingCtlTimeOut	6
#define MIN_pingCtlTimeOut	1L
#define MAX_pingCtlTimeOut	60L
#define LEAF_pingCtlProbeCount	7
#define MIN_pingCtlProbeCount	1L
#define MAX_pingCtlProbeCount	15L
#define LEAF_pingCtlAdminStatus	8
#define VAL_pingCtlAdminStatus_enabled	1L
#define VAL_pingCtlAdminStatus_disabled	2L
#define LEAF_pingCtlDataFill	9
#define MINSIZE_pingCtlDataFill	0L
#define MAXSIZE_pingCtlDataFill	1024L
#define LEAF_pingCtlFrequency	10
#define LEAF_pingCtlMaxRows	11
#define LEAF_pingCtlStorageType	12
#define VAL_pingCtlStorageType_other	1L
#define VAL_pingCtlStorageType_volatile	2L
#define VAL_pingCtlStorageType_nonVolatile	3L
#define VAL_pingCtlStorageType_permanent	4L
#define VAL_pingCtlStorageType_readOnly	5L
#define LEAF_pingCtlTrapGeneration	13
#define VAL_pingCtlTrapGeneration_probeFailure	0L
#define VAL_pingCtlTrapGeneration_testFailure	1L
#define VAL_pingCtlTrapGeneration_testCompletion	2L
#define SIZE_pingCtlTrapGeneration 1L
#define LEAF_pingCtlTrapProbeFailureFilter	14
#define MIN_pingCtlTrapProbeFailureFilter	0L
#define MAX_pingCtlTrapProbeFailureFilter	15L
#define LEAF_pingCtlTrapTestFailureFilter	15
#define MIN_pingCtlTrapTestFailureFilter	0L
#define MAX_pingCtlTrapTestFailureFilter	15L
#define LEAF_pingCtlType	16
#define LEAF_pingCtlDescr	17
#define MINSIZE_pingCtlDescr	0L
#define MAXSIZE_pingCtlDescr	255L
#define LEAF_pingCtlSourceAddressType	18
#define VAL_pingCtlSourceAddressType_unknown	0L
#define VAL_pingCtlSourceAddressType_ipv4	1L
#define VAL_pingCtlSourceAddressType_ipv6	2L
#define VAL_pingCtlSourceAddressType_ipv4z	3L
#define VAL_pingCtlSourceAddressType_ipv6z	4L
#define VAL_pingCtlSourceAddressType_dns	16L
#define LEAF_pingCtlSourceAddress	19
#define MINSIZE_pingCtlSourceAddress	0L
#define MAXSIZE_pingCtlSourceAddress	255L
#define LEAF_pingCtlIfIndex	20
#define MIN_pingCtlIfIndex	0L
#define MAX_pingCtlIfIndex	2147483647L
#define LEAF_pingCtlByPassRouteTable	21
#define VAL_pingCtlByPassRouteTable_true	1L
#define VAL_pingCtlByPassRouteTable_false	2L
#define LEAF_pingCtlDSField	22
#define MIN_pingCtlDSField	0L
#define MAX_pingCtlDSField	255L
#define LEAF_pingCtlRowStatus	23
#define VAL_pingCtlRowStatus_active	1L
#define VAL_pingCtlRowStatus_notInService	2L
#define VAL_pingCtlRowStatus_notReady	3L
#define VAL_pingCtlRowStatus_createAndGo	4L
#define VAL_pingCtlRowStatus_createAndWait	5L
#define VAL_pingCtlRowStatus_destroy	6L
#define LEAF_pingResultsOperStatus	1
#define VAL_pingResultsOperStatus_enabled	1L
#define VAL_pingResultsOperStatus_disabled	2L
#define LEAF_pingResultsIpTargetAddressType	2
#define VAL_pingResultsIpTargetAddressType_unknown	0L
#define VAL_pingResultsIpTargetAddressType_ipv4	1L
#define VAL_pingResultsIpTargetAddressType_ipv6	2L
#define VAL_pingResultsIpTargetAddressType_ipv4z	3L
#define VAL_pingResultsIpTargetAddressType_ipv6z	4L
#define VAL_pingResultsIpTargetAddressType_dns	16L
#define LEAF_pingResultsIpTargetAddress	3
#define MINSIZE_pingResultsIpTargetAddress	0L
#define MAXSIZE_pingResultsIpTargetAddress	255L
#define LEAF_pingResultsMinRtt	4
#define LEAF_pingResultsMaxRtt	5
#define LEAF_pingResultsAverageRtt	6
#define LEAF_pingResultsProbeResponses	7
#define LEAF_pingResultsSentProbes	8
#define LEAF_pingResultsRttSumOfSquares	9
#define LEAF_pingResultsLastGoodProbe	10
#define SIZE_pingResultsLastGoodProbe_1	8L
#define SIZE_pingResultsLastGoodProbe_2	11L
#define LEAF_pingProbeHistoryIndex	1
#define MIN_pingProbeHistoryIndex	1L
#define MAX_pingProbeHistoryIndex	4294967295L
#define LEAF_pingProbeHistoryResponse	2
#define LEAF_pingProbeHistoryStatus	3
#define VAL_pingProbeHistoryStatus_responseReceived	1L
#define VAL_pingProbeHistoryStatus_unknown	2L
#define VAL_pingProbeHistoryStatus_internalError	3L
#define VAL_pingProbeHistoryStatus_requestTimedOut	4L
#define VAL_pingProbeHistoryStatus_unknownDestinationAddress	5L
#define VAL_pingProbeHistoryStatus_noRouteToTarget	6L
#define VAL_pingProbeHistoryStatus_interfaceInactiveToTarget	7L
#define VAL_pingProbeHistoryStatus_arpFailure	8L
#define VAL_pingProbeHistoryStatus_maxConcurrentLimitReached	9L
#define VAL_pingProbeHistoryStatus_unableToResolveDnsName	10L
#define VAL_pingProbeHistoryStatus_invalidHostAddress	11L
#define LEAF_pingProbeHistoryLastRC	4
#define LEAF_pingProbeHistoryTime	5
#define SIZE_pingProbeHistoryTime_1	8L
#define SIZE_pingProbeHistoryTime_2	11L
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


