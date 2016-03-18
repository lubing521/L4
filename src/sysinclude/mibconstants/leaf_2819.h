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
 **** Last build date: Sun Nov 13 12:09:59 2005
 **** from files:
 ****  ..\MibFiles\Rfc1213.mib, ctl\Rfc1213.ctl,
 ****  ..\MibFiles\IanaIfType_Rfc1573.mib, ..\MibFiles\SnmpV2_Rfc1907.mib,
 ****  ctl\SnmpV2_Rfc1907.ctl, ..\MibFiles\If_Rfc2863.mib, ctl\If_Rfc2863.ctl,
 ****  ctl\Rmon_Rfc2819.ctl, ..\MibFiles\Rmon_Rfc2819.mib
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_2819_H
#define  LEAF_2819_H

#define LEAF_etherStatsIndex	1
#define MIN_etherStatsIndex	1L
#define MAX_etherStatsIndex	65535L
#define LEAF_etherStatsDataSource	2
#define LEAF_etherStatsDropEvents	3
#define LEAF_etherStatsOctets	4
#define LEAF_etherStatsPkts	5
#define LEAF_etherStatsBroadcastPkts	6
#define LEAF_etherStatsMulticastPkts	7
#define LEAF_etherStatsCRCAlignErrors	8
#define LEAF_etherStatsUndersizePkts	9
#define LEAF_etherStatsOversizePkts	10
#define LEAF_etherStatsFragments	11
#define LEAF_etherStatsJabbers	12
#define LEAF_etherStatsCollisions	13
#define LEAF_etherStatsPkts64Octets	14
#define LEAF_etherStatsPkts65to127Octets	15
#define LEAF_etherStatsPkts128to255Octets	16
#define LEAF_etherStatsPkts256to511Octets	17
#define LEAF_etherStatsPkts512to1023Octets	18
#define LEAF_etherStatsPkts1024to1518Octets	19
#define LEAF_etherStatsOwner	20
#define MINSIZE_etherStatsOwner	0L
#define MAXSIZE_etherStatsOwner	127L
#define LEAF_etherStatsStatus	21
#define VAL_etherStatsStatus_valid	1L
#define VAL_etherStatsStatus_createRequest	2L
#define VAL_etherStatsStatus_underCreation	3L
#define VAL_etherStatsStatus_invalid	4L
#define LEAF_historyControlIndex	1
#define MIN_historyControlIndex	1L
#define MAX_historyControlIndex	65535L
#define LEAF_historyControlDataSource	2
#define LEAF_historyControlBucketsRequested	3
#define MIN_historyControlBucketsRequested	1L
#define MAX_historyControlBucketsRequested	65535L
#define LEAF_historyControlBucketsGranted	4
#define MIN_historyControlBucketsGranted	1L
#define MAX_historyControlBucketsGranted	65535L
#define LEAF_historyControlInterval	5
#define MIN_historyControlInterval	1L
#define MAX_historyControlInterval	3600L
#define LEAF_historyControlOwner	6
#define MINSIZE_historyControlOwner	0L
#define MAXSIZE_historyControlOwner	127L
#define LEAF_historyControlStatus	7
#define VAL_historyControlStatus_valid	1L
#define VAL_historyControlStatus_createRequest	2L
#define VAL_historyControlStatus_underCreation	3L
#define VAL_historyControlStatus_invalid	4L
#define LEAF_etherHistoryIndex	1
#define MIN_etherHistoryIndex	1L
#define MAX_etherHistoryIndex	65535L
#define LEAF_etherHistorySampleIndex	2
#define MIN_etherHistorySampleIndex	1L
#define MAX_etherHistorySampleIndex	2147483647L
#define LEAF_etherHistoryIntervalStart	3
#define LEAF_etherHistoryDropEvents	4
#define LEAF_etherHistoryOctets	5
#define LEAF_etherHistoryPkts	6
#define LEAF_etherHistoryBroadcastPkts	7
#define LEAF_etherHistoryMulticastPkts	8
#define LEAF_etherHistoryCRCAlignErrors	9
#define LEAF_etherHistoryUndersizePkts	10
#define LEAF_etherHistoryOversizePkts	11
#define LEAF_etherHistoryFragments	12
#define LEAF_etherHistoryJabbers	13
#define LEAF_etherHistoryCollisions	14
#define LEAF_etherHistoryUtilization	15
#define MIN_etherHistoryUtilization	0L
#define MAX_etherHistoryUtilization	10000L
#define LEAF_alarmIndex	1
#define MIN_alarmIndex	1L
#define MAX_alarmIndex  65535L
#define LEAF_alarmInterval	2
#define MAX_alarmInterval    31622400
#define MIN_alarmInterval    1
#define LEAF_alarmVariable	3
#define LEAF_alarmSampleType	4
#define VAL_alarmSampleType_absoluteValue	1L
#define VAL_alarmSampleType_deltaValue	2L
#define LEAF_alarmValue	5
#define LEAF_alarmStartupAlarm	6
#define VAL_alarmStartupAlarm_risingAlarm	1L
#define VAL_alarmStartupAlarm_fallingAlarm	2L
#define VAL_alarmStartupAlarm_risingOrFallingAlarm	3L
#define LEAF_alarmRisingThreshold	7
#define LEAF_alarmFallingThreshold	8
#define LEAF_alarmRisingEventIndex	9
#define MIN_alarmRisingEventIndex	0L
#define MAX_alarmRisingEventIndex	65535L
#define LEAF_alarmFallingEventIndex	10
#define MIN_alarmFallingEventIndex	0L
#define MAX_alarmFallingEventIndex	65535L
#define LEAF_alarmOwner	11
#define MINSIZE_alarmOwner	0L
#define MAXSIZE_alarmOwner	127L
#define LEAF_alarmStatus	12
#define VAL_alarmStatus_valid	1L
#define VAL_alarmStatus_createRequest	2L
#define VAL_alarmStatus_underCreation	3L
#define VAL_alarmStatus_invalid	4L
#define LEAF_eventIndex	1
#define MIN_eventIndex	1L
#define MAX_eventIndex	65535L
#define LEAF_eventDescription	2
#define MINSIZE_eventDescription	0L
#define MAXSIZE_eventDescription	127L
#define LEAF_eventType	3
#define VAL_eventType_none	1L
#define VAL_eventType_log	2L
#define VAL_eventType_snmptrap	3L
#define VAL_eventType_logandtrap	4L
#define LEAF_eventCommunity	4
#define MINSIZE_eventCommunity	0L
#define MAXSIZE_eventCommunity	127L
#define LEAF_eventLastTimeSent	5
#define LEAF_eventOwner	6
#define MINSIZE_eventOwner	0L
#define MAXSIZE_eventOwner	127L
#define LEAF_eventStatus	7
#define VAL_eventStatus_valid	1L
#define VAL_eventStatus_createRequest	2L
#define VAL_eventStatus_underCreation	3L
#define VAL_eventStatus_invalid	4L
#define LEAF_logEventIndex	1
#define MIN_logEventIndex	1L
#define MAX_logEventIndex	65535L
#define LEAF_logIndex	2
#define MIN_logIndex	1L
#define MAX_logIndex	2147483647L
#define LEAF_logTime	3
#define LEAF_logDescription	4
#define MINSIZE_logDescription	0L
#define MAXSIZE_logDescription	255L

#endif
