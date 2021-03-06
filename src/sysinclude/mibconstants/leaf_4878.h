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
 **** Last build date: Wed Aug 15 18:31:36 2007
 **** from files:
 ****  Dot3oam_Rfc4878.mib
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_4878_H
#define  LEAF_4878_H

#define LEAF_dot3OamAdminState                             1
#define VAL_dot3OamAdminState_enabled                       1L
#define VAL_dot3OamAdminState_disabled                      2L
#define LEAF_dot3OamOperStatus                             2
#define VAL_dot3OamOperStatus_disabled                      1L
#define VAL_dot3OamOperStatus_linkFault                     2L
#define VAL_dot3OamOperStatus_passiveWait                   3L
#define VAL_dot3OamOperStatus_activeSendLocal               4L
#define VAL_dot3OamOperStatus_sendLocalAndRemote            5L
#define VAL_dot3OamOperStatus_sendLocalAndRemoteOk          6L
#define VAL_dot3OamOperStatus_oamPeeringLocallyRejected     7L
#define VAL_dot3OamOperStatus_oamPeeringRemotelyRejected    8L
#define VAL_dot3OamOperStatus_operational                   9L
#define VAL_dot3OamOperStatus_nonOperHalfDuplex             10L
#define LEAF_dot3OamMode                                   3
#define VAL_dot3OamMode_passive                             1L
#define VAL_dot3OamMode_active                              2L
#define LEAF_dot3OamMaxOamPduSize                          4
#define MIN_dot3OamMaxOamPduSize                            64L
#define MAX_dot3OamMaxOamPduSize                            1518L
#define LEAF_dot3OamConfigRevision                         5
#define MIN_dot3OamConfigRevision                           0L
#define MAX_dot3OamConfigRevision                           65535L
#define LEAF_dot3OamFunctionsSupported                     6
#define VAL_dot3OamFunctionsSupported_unidirectionalSupport 0L
#define VAL_dot3OamFunctionsSupported_loopbackSupport       1L
#define VAL_dot3OamFunctionsSupported_eventSupport          2L
#define VAL_dot3OamFunctionsSupported_variableSupport       3L
#define SIZE_dot3OamFunctionsSupported                      1


#define LEAF_dot3OamPeerMacAddress                              1
#define SIZE_dot3OamPeerMacAddress                               6L
#define LEAF_dot3OamPeerVendorOui                               2
#define SIZE_dot3OamPeerVendorOui                                3L
#define LEAF_dot3OamPeerVendorInfo                              3
#define LEAF_dot3OamPeerMode                                    4
#define VAL_dot3OamPeerMode_passive                              1L
#define VAL_dot3OamPeerMode_active                               2L
#define VAL_dot3OamPeerMode_unknown                              3L
#define LEAF_dot3OamPeerMaxOamPduSize                           5
#if 0 /* XXX steven.jiang for warnings */
#define MIN_dot3OamPeerMaxOamPduSize                             0L
#define MAX_dot3OamPeerMaxOamPduSize                             0L
#endif /* 0 */
#define MIN_dot3OamPeerMaxOamPduSize                             64L
#define MAX_dot3OamPeerMaxOamPduSize                             1518L
#define LEAF_dot3OamPeerConfigRevision                          6
#define MIN_dot3OamPeerConfigRevision                            0L
#define MAX_dot3OamPeerConfigRevision                            65535L
#define LEAF_dot3OamPeerFunctionsSupported                      7
#define VAL_dot3OamPeerFunctionsSupported_unidirectionalSupport  0L
#define VAL_dot3OamPeerFunctionsSupported_loopbackSupport        1L
#define VAL_dot3OamPeerFunctionsSupported_eventSupport           2L
#define VAL_dot3OamPeerFunctionsSupported_variableSupport        3L
#define SIZE_dot3OamPeerFunctionsSupported                       1



/* dot3OamLoopbackTable */
#define DOT3OAMLOOPBACKSTATUS                                    1
#define DOT3OAMLOOPBACKIGNORERX                                  2

#define LEAF_dot3OamLoopbackStatus                               1
#define VAL_dot3OamLoopbackStatus_noLoopback                      1L
#define VAL_dot3OamLoopbackStatus_initiatingLoopback              2L
#define VAL_dot3OamLoopbackStatus_remoteLoopback                  3L
#define VAL_dot3OamLoopbackStatus_terminatingLoopback             4L
#define VAL_dot3OamLoopbackStatus_localLoopback                   5L
#define VAL_dot3OamLoopbackStatus_unknown                         6L
#define LEAF_dot3OamLoopbackIgnoreRx                             2
#define VAL_dot3OamLoopbackIgnoreRx_ignore                        1L
#define VAL_dot3OamLoopbackIgnoreRx_process                       2L



#define LEAF_dot3OamInformationTx                                1 
#define LEAF_dot3OamInformationRx                                2
#define LEAF_dot3OamUniqueEventNotificationTx                    3
#define LEAF_dot3OamUniqueEventNotificationRx                    4
#define LEAF_dot3OamDuplicateEventNotificationTx                 5
#define LEAF_dot3OamDuplicateEventNotificationRx                 6
#define LEAF_dot3OamLoopbackControlTx                            7
#define LEAF_dot3OamLoopbackControlRx                            8
#define LEAF_dot3OamVariableRequestTx                            9
#define LEAF_dot3OamVariableRequestRx                            10
#define LEAF_dot3OamVariableResponseTx                           11
#define LEAF_dot3OamVariableResponseRx                           12
#define LEAF_dot3OamOrgSpecificTx                                13
#define LEAF_dot3OamOrgSpecificRx                                14
#define LEAF_dot3OamUnsupportedCodesTx                           15
#define LEAF_dot3OamUnsupportedCodesRx                           16
#define LEAF_dot3OamFramesLostDueToOam                           17



#define LEAF_dot3OamErrSymPeriodWindowHi               1
#define LEAF_dot3OamErrSymPeriodWindowLo               2
#define LEAF_dot3OamErrSymPeriodThresholdHi            3
#define LEAF_dot3OamErrSymPeriodThresholdLo            4
#define LEAF_dot3OamErrSymPeriodEvNotifEnable          5
#define VAL_dot3OamErrSymPeriodEvNotifEnable_true       1L
#define VAL_dot3OamErrSymPeriodEvNotifEnable_false      2L
#define LEAF_dot3OamErrFramePeriodWindow               6
#define LEAF_dot3OamErrFramePeriodThreshold            7
#define LEAF_dot3OamErrFramePeriodEvNotifEnable        8
#define VAL_dot3OamErrFramePeriodEvNotifEnable_true     1L
#define VAL_dot3OamErrFramePeriodEvNotifEnable_false    2L
#define LEAF_dot3OamErrFrameWindow                     9
#define LEAF_dot3OamErrFrameThreshold                  10
#define LEAF_dot3OamErrFrameEvNotifEnable              11
#define VAL_dot3OamErrFrameEvNotifEnable_true           1L
#define VAL_dot3OamErrFrameEvNotifEnable_false          2L
#define LEAF_dot3OamErrFrameSecsSummaryWindow          12
#define MIN_dot3OamErrFrameSecsSummaryWindow            100L
#define MAX_dot3OamErrFrameSecsSummaryWindow            9000L
#define LEAF_dot3OamErrFrameSecsSummaryThreshold       13
#define MIN_dot3OamErrFrameSecsSummaryThreshold         1L
#define MAX_dot3OamErrFrameSecsSummaryThreshold         900L
#define LEAF_dot3OamErrFrameSecsEvNotifEnable          14
#define VAL_dot3OamErrFrameSecsEvNotifEnable_true       1L
#define VAL_dot3OamErrFrameSecsEvNotifEnable_false      2L
#define LEAF_dot3OamDyingGaspEnable                    15
#define VAL_dot3OamDyingGaspEnable_true                 1L
#define VAL_dot3OamDyingGaspEnable_false                2L
#define LEAF_dot3OamCriticalEventEnable                16
#define VAL_dot3OamCriticalEventEnable_true             1L
#define VAL_dot3OamCriticalEventEnable_false            2L


#define LEAF_dot3OamEventLogIndex                       1
#define MIN_dot3OamEventLogIndex                         1L
#define MAX_dot3OamEventLogIndex                         2147483647L
#define LEAF_dot3OamEventLogTimestamp                   2
#define LEAF_dot3OamEventLogOui                         3
#define SIZE_dot3OamEventLogOui                          3L
#define LEAF_dot3OamEventLogType                        4
#define VAL_dot3OamEventLogType_erroredSymbolEvent       1L
#define VAL_dot3OamEventLogType_erroredFramePeriodEvent  2L
#define VAL_dot3OamEventLogType_erroredFrameEvent        3L
#define VAL_dot3OamEventLogType_erroredFrameSecondsEvent 4L
#define VAL_dot3OamEventLogType_linkFault                256L
#define VAL_dot3OamEventLogType_dyingGaspEvent           257L
#define VAL_dot3OamEventLogType_criticalLinkEvent        258L
#define LEAF_dot3OamEventLogLocation                    5
#define VAL_dot3OamEventLogLocation_local                1L
#define VAL_dot3OamEventLogLocation_remote               2L
#define LEAF_dot3OamEventLogWindowHi                    6
#define LEAF_dot3OamEventLogWindowLo                    7
#define LEAF_dot3OamEventLogThresholdHi                 8
#define LEAF_dot3OamEventLogThresholdLo                 9
#define LEAF_dot3OamEventLogValue                       10
#define SIZE_dot3OamEventLogValue                         3L
#define LEAF_dot3OamEventLogRunningTotal                11
#define SIZE_dot3OamEventLogRunningTotal                  3L
#define LEAF_dot3OamEventLogEventTotal                  12

#endif /* end of #ifndef  LEAF_4878_H */


