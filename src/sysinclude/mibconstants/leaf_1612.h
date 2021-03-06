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
 **** Last build date: Thu Jan 02 11:09:01 2003
 **** from files:
 ****  ..\StdMib\DnsServer_Rfc1611.mib, ctl\DnsServer_Rfc1611.ctl,
 ****  ..\StdMib\DnsResolver_Rfc1612.mib
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_1612_H
#define  LEAF_1612_H

#define LEAF_dnsResConfigImplementIdent	1
#define MINSIZE_dnsResConfigImplementIdent	0L
#define MAXSIZE_dnsResConfigImplementIdent	255L
#define LEAF_dnsResConfigService	2
#define VAL_dnsResConfigService_recursiveOnly	1L
#define VAL_dnsResConfigService_iterativeOnly	2L
#define VAL_dnsResConfigService_recursiveAndIterative	3L
#define LEAF_dnsResConfigMaxCnames	3
#define MIN_dnsResConfigMaxCnames	0L
#define MAX_dnsResConfigMaxCnames	2147483647L
#define LEAF_dnsResConfigSbeltAddr	1
#define LEAF_dnsResConfigSbeltName	2
#define MINSIZE_dnsResConfigSbeltName	0L
#define MAXSIZE_dnsResConfigSbeltName	255L
#define LEAF_dnsResConfigSbeltRecursion	3
#define VAL_dnsResConfigSbeltRecursion_iterative	1L
#define VAL_dnsResConfigSbeltRecursion_recursive	2L
#define VAL_dnsResConfigSbeltRecursion_recursiveAndIterative	3L
#define LEAF_dnsResConfigSbeltPref	4
#define MIN_dnsResConfigSbeltPref	0L
#define MAX_dnsResConfigSbeltPref	2147483647L
#define LEAF_dnsResConfigSbeltSubTree	5
#define MINSIZE_dnsResConfigSbeltSubTree	0L
#define MAXSIZE_dnsResConfigSbeltSubTree	255L
#define LEAF_dnsResConfigSbeltClass	6
#define MIN_dnsResConfigSbeltClass	0L
#define MAX_dnsResConfigSbeltClass	65535L
#define LEAF_dnsResConfigSbeltStatus	7
#define VAL_dnsResConfigSbeltStatus_active	1L
#define VAL_dnsResConfigSbeltStatus_notInService	2L
#define VAL_dnsResConfigSbeltStatus_notReady	3L
#define VAL_dnsResConfigSbeltStatus_createAndGo	4L
#define VAL_dnsResConfigSbeltStatus_createAndWait	5L
#define VAL_dnsResConfigSbeltStatus_destroy	6L
#define LEAF_dnsResConfigUpTime	5
#define LEAF_dnsResConfigResetTime	6
#define LEAF_dnsResConfigReset	7
#define VAL_dnsResConfigReset_other	1L
#define VAL_dnsResConfigReset_reset	2L
#define VAL_dnsResConfigReset_initializing	3L
#define VAL_dnsResConfigReset_running	4L
#define LEAF_dnsResCounterByOpcodeCode	1
#define MIN_dnsResCounterByOpcodeCode	0L
#define MAX_dnsResCounterByOpcodeCode	15L
#define LEAF_dnsResCounterByOpcodeQueries	2
#define LEAF_dnsResCounterByOpcodeResponses	3
#define LEAF_dnsResCounterByRcodeCode	1
#define MIN_dnsResCounterByRcodeCode	0L
#define MAX_dnsResCounterByRcodeCode	15L
#define LEAF_dnsResCounterByRcodeResponses	2
#define LEAF_dnsResCounterNonAuthDataResps	5
#define LEAF_dnsResCounterNonAuthNoDataResps	6
#define LEAF_dnsResCounterMartians	7
#define LEAF_dnsResCounterRecdResponses	8
#define LEAF_dnsResCounterUnparseResps	9
#define LEAF_dnsResCounterFallbacks	10
#define LEAF_dnsResLameDelegationOverflows	1
#define LEAF_dnsResLameDelegationSource	1
#define LEAF_dnsResLameDelegationName	2
#define MINSIZE_dnsResLameDelegationName	0L
#define MAXSIZE_dnsResLameDelegationName	255L
#define LEAF_dnsResLameDelegationClass	3
#define MIN_dnsResLameDelegationClass	0L
#define MAX_dnsResLameDelegationClass	65535L
#define LEAF_dnsResLameDelegationCounts	4
#define LEAF_dnsResLameDelegationStatus	5
#define VAL_dnsResLameDelegationStatus_active	1L
#define VAL_dnsResLameDelegationStatus_notInService	2L
#define VAL_dnsResLameDelegationStatus_notReady	3L
#define VAL_dnsResLameDelegationStatus_createAndGo	4L
#define VAL_dnsResLameDelegationStatus_createAndWait	5L
#define VAL_dnsResLameDelegationStatus_destroy	6L
#define LEAF_dnsResCacheStatus	1
#define VAL_dnsResCacheStatus_enabled	1L
#define VAL_dnsResCacheStatus_disabled	2L
#define VAL_dnsResCacheStatus_clear	3L
#define LEAF_dnsResCacheMaxTTL	2
#define LEAF_dnsResCacheGoodCaches	3
#define LEAF_dnsResCacheBadCaches	4
#define LEAF_dnsResCacheRRName	1
#define MINSIZE_dnsResCacheRRName	0L
#define MAXSIZE_dnsResCacheRRName	255L
#define LEAF_dnsResCacheRRClass	2
#define MIN_dnsResCacheRRClass	0L
#define MAX_dnsResCacheRRClass	65535L
#define LEAF_dnsResCacheRRType	3
#define MIN_dnsResCacheRRType	0L
#define MAX_dnsResCacheRRType	65535L
#define LEAF_dnsResCacheRRTTL	4
#define LEAF_dnsResCacheRRElapsedTTL	5
#define LEAF_dnsResCacheRRSource	6
#define LEAF_dnsResCacheRRData	7
#define LEAF_dnsResCacheRRStatus	8
#define VAL_dnsResCacheRRStatus_active	1L
#define VAL_dnsResCacheRRStatus_notInService	2L
#define VAL_dnsResCacheRRStatus_notReady	3L
#define VAL_dnsResCacheRRStatus_createAndGo	4L
#define VAL_dnsResCacheRRStatus_createAndWait	5L
#define VAL_dnsResCacheRRStatus_destroy	6L
#define LEAF_dnsResCacheRRIndex	9
#define LEAF_dnsResCacheRRPrettyName	10
#define MINSIZE_dnsResCacheRRPrettyName	0L
#define MAXSIZE_dnsResCacheRRPrettyName	255L
#define LEAF_dnsResNCacheStatus	1
#define VAL_dnsResNCacheStatus_enabled	1L
#define VAL_dnsResNCacheStatus_disabled	2L
#define VAL_dnsResNCacheStatus_clear	3L
#define LEAF_dnsResNCacheMaxTTL	2
#define LEAF_dnsResNCacheGoodNCaches	3
#define LEAF_dnsResNCacheBadNCaches	4
#define LEAF_dnsResNCacheErrQName	1
#define MINSIZE_dnsResNCacheErrQName	0L
#define MAXSIZE_dnsResNCacheErrQName	255L
#define LEAF_dnsResNCacheErrQClass	2
#define MIN_dnsResNCacheErrQClass	0L
#define MAX_dnsResNCacheErrQClass	65535L
#define LEAF_dnsResNCacheErrQType	3
#define MIN_dnsResNCacheErrQType	0L
#define MAX_dnsResNCacheErrQType	65535L
#define LEAF_dnsResNCacheErrTTL	4
#define LEAF_dnsResNCacheErrElapsedTTL	5
#define LEAF_dnsResNCacheErrSource	6
#define LEAF_dnsResNCacheErrCode	7
#define VAL_dnsResNCacheErrCode_nonexistantName	1L
#define VAL_dnsResNCacheErrCode_noData	2L
#define VAL_dnsResNCacheErrCode_other	3L
#define LEAF_dnsResNCacheErrStatus	8
#define VAL_dnsResNCacheErrStatus_active	1L
#define VAL_dnsResNCacheErrStatus_notInService	2L
#define VAL_dnsResNCacheErrStatus_notReady	3L
#define VAL_dnsResNCacheErrStatus_createAndGo	4L
#define VAL_dnsResNCacheErrStatus_createAndWait	5L
#define VAL_dnsResNCacheErrStatus_destroy	6L
#define LEAF_dnsResNCacheErrIndex	9
#define LEAF_dnsResNCacheErrPrettyName	10
#define MINSIZE_dnsResNCacheErrPrettyName	0L
#define MAXSIZE_dnsResNCacheErrPrettyName	255L
#define LEAF_dnsResOptCounterReferals	1
#define LEAF_dnsResOptCounterRetrans	2
#define LEAF_dnsResOptCounterNoResponses	3
#define LEAF_dnsResOptCounterRootRetrans	4
#define LEAF_dnsResOptCounterInternals	5
#define LEAF_dnsResOptCounterInternalTimeOuts	6

#endif /* end of #ifndef  LEAF_1612_H */
