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
 **** Last build date: Tue Sep 23 12:00:32 2003
 **** from files:
 ****  ..\MibFiles\DiffServDscpTc_Rfc3289.mib, ..\MibFiles\Rfc1213.mib,
 ****  ctl\Rfc1213.ctl, ..\MibFiles\IanaIfType_Rfc1573.mib,
 ****  ..\MibFiles\SnmpV2_Rfc1907.mib, ctl\SnmpV2_Rfc1907.ctl,
 ****  ..\MibFiles\If_Rfc2863.mib, ctl\If_Rfc2863.ctl,
 ****  ..\MibFiles\IntegratedServices_Rfc2213.mib,
 ****  ctl\IntegratedServices_Rfc2213.ctl, ..\MibFiles\InetAddress_Rfc3291.mib,
 ****  ..\MibFiles\DiffServ_Rfc3289.mib
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_3289_H
#define  LEAF_3289_H

#define LEAF_diffServDataPathIfDirection	1
#define VAL_diffServDataPathIfDirection_inbound	1L
#define VAL_diffServDataPathIfDirection_outbound	2L
#define LEAF_diffServDataPathStart	2
#define LEAF_diffServDataPathStorage	3
#define VAL_diffServDataPathStorage_other	1L
#define VAL_diffServDataPathStorage_volatile	2L
#define VAL_diffServDataPathStorage_nonVolatile	3L
#define VAL_diffServDataPathStorage_permanent	4L
#define VAL_diffServDataPathStorage_readOnly	5L
#define LEAF_diffServDataPathStatus	4
#define VAL_diffServDataPathStatus_active	1L
#define VAL_diffServDataPathStatus_notInService	2L
#define VAL_diffServDataPathStatus_notReady	3L
#define VAL_diffServDataPathStatus_createAndGo	4L
#define VAL_diffServDataPathStatus_createAndWait	5L
#define VAL_diffServDataPathStatus_destroy	6L
#define LEAF_diffServClfrNextFree	1
#define MIN_diffServClfrNextFree	0L
#define MAX_diffServClfrNextFree	4294967295L
#define LEAF_diffServClfrId	1
#define MIN_diffServClfrId	1L
#define MAX_diffServClfrId	4294967295L
#define LEAF_diffServClfrStorage	2
#define VAL_diffServClfrStorage_other	1L
#define VAL_diffServClfrStorage_volatile	2L
#define VAL_diffServClfrStorage_nonVolatile	3L
#define VAL_diffServClfrStorage_permanent	4L
#define VAL_diffServClfrStorage_readOnly	5L
#define LEAF_diffServClfrStatus	3
#define VAL_diffServClfrStatus_active	1L
#define VAL_diffServClfrStatus_notInService	2L
#define VAL_diffServClfrStatus_notReady	3L
#define VAL_diffServClfrStatus_createAndGo	4L
#define VAL_diffServClfrStatus_createAndWait	5L
#define VAL_diffServClfrStatus_destroy	6L
#define LEAF_diffServClfrElementNextFree	3
#define MIN_diffServClfrElementNextFree	0L
#define MAX_diffServClfrElementNextFree	4294967295L
#define LEAF_diffServClfrElementId	1
#define MIN_diffServClfrElementId	1L
#define MAX_diffServClfrElementId	4294967295L
#define LEAF_diffServClfrElementPrecedence	2
#define MIN_diffServClfrElementPrecedence	1L
#define MAX_diffServClfrElementPrecedence	4294967295L
#define LEAF_diffServClfrElementNext	3
#define LEAF_diffServClfrElementSpecific	4
#define LEAF_diffServClfrElementStorage	5
#define VAL_diffServClfrElementStorage_other	1L
#define VAL_diffServClfrElementStorage_volatile	2L
#define VAL_diffServClfrElementStorage_nonVolatile	3L
#define VAL_diffServClfrElementStorage_permanent	4L
#define VAL_diffServClfrElementStorage_readOnly	5L
#define LEAF_diffServClfrElementStatus	6
#define VAL_diffServClfrElementStatus_active	1L
#define VAL_diffServClfrElementStatus_notInService	2L
#define VAL_diffServClfrElementStatus_notReady	3L
#define VAL_diffServClfrElementStatus_createAndGo	4L
#define VAL_diffServClfrElementStatus_createAndWait	5L
#define VAL_diffServClfrElementStatus_destroy	6L
#define LEAF_diffServMultiFieldClfrNextFree	5
#define MIN_diffServMultiFieldClfrNextFree	0L
#define MAX_diffServMultiFieldClfrNextFree	4294967295L
#define LEAF_diffServMultiFieldClfrId	1
#define MIN_diffServMultiFieldClfrId	1L
#define MAX_diffServMultiFieldClfrId	4294967295L
#define LEAF_diffServMultiFieldClfrAddrType	2
#define VAL_diffServMultiFieldClfrAddrType_unknown	0L
#define VAL_diffServMultiFieldClfrAddrType_ipv4	1L
#define VAL_diffServMultiFieldClfrAddrType_ipv6	2L
#define VAL_diffServMultiFieldClfrAddrType_ipv4z	3L
#define VAL_diffServMultiFieldClfrAddrType_ipv6z	4L
#define VAL_diffServMultiFieldClfrAddrType_dns	16L
#define LEAF_diffServMultiFieldClfrDstAddr	3
#define MINSIZE_diffServMultiFieldClfrDstAddr	0L
#define MAXSIZE_diffServMultiFieldClfrDstAddr	255L
#define LEAF_diffServMultiFieldClfrDstPrefixLength	4
#define LEAF_diffServMultiFieldClfrSrcAddr	5
#define MINSIZE_diffServMultiFieldClfrSrcAddr	0L
#define MAXSIZE_diffServMultiFieldClfrSrcAddr	255L
#define LEAF_diffServMultiFieldClfrSrcPrefixLength	6
#define LEAF_diffServMultiFieldClfrDscp	7
#define MIN_diffServMultiFieldClfrDscp	-1L
#define MAX_diffServMultiFieldClfrDscp	63L
#define LEAF_diffServMultiFieldClfrFlowId	8
#define MIN_diffServMultiFieldClfrFlowId	0L
#define MAX_diffServMultiFieldClfrFlowId	1048575L
#define LEAF_diffServMultiFieldClfrProtocol	9
#define MIN_diffServMultiFieldClfrProtocol	0L
#define MAX_diffServMultiFieldClfrProtocol	255L
#define LEAF_diffServMultiFieldClfrDstL4PortMin	10
#define MIN_diffServMultiFieldClfrDstL4PortMin	0L
#define MAX_diffServMultiFieldClfrDstL4PortMin	65535L
#define LEAF_diffServMultiFieldClfrDstL4PortMax	11
#define MIN_diffServMultiFieldClfrDstL4PortMax	0L
#define MAX_diffServMultiFieldClfrDstL4PortMax	65535L
#define LEAF_diffServMultiFieldClfrSrcL4PortMin	12
#define MIN_diffServMultiFieldClfrSrcL4PortMin	0L
#define MAX_diffServMultiFieldClfrSrcL4PortMin	65535L
#define LEAF_diffServMultiFieldClfrSrcL4PortMax	13
#define MIN_diffServMultiFieldClfrSrcL4PortMax	0L
#define MAX_diffServMultiFieldClfrSrcL4PortMax	65535L
#define LEAF_diffServMultiFieldClfrStorage	14
#define VAL_diffServMultiFieldClfrStorage_other	1L
#define VAL_diffServMultiFieldClfrStorage_volatile	2L
#define VAL_diffServMultiFieldClfrStorage_nonVolatile	3L
#define VAL_diffServMultiFieldClfrStorage_permanent	4L
#define VAL_diffServMultiFieldClfrStorage_readOnly	5L
#define LEAF_diffServMultiFieldClfrStatus	15
#define VAL_diffServMultiFieldClfrStatus_active	1L
#define VAL_diffServMultiFieldClfrStatus_notInService	2L
#define VAL_diffServMultiFieldClfrStatus_notReady	3L
#define VAL_diffServMultiFieldClfrStatus_createAndGo	4L
#define VAL_diffServMultiFieldClfrStatus_createAndWait	5L
#define VAL_diffServMultiFieldClfrStatus_destroy	6L
#define LEAF_diffServMeterNextFree	1
#define MIN_diffServMeterNextFree	0L
#define MAX_diffServMeterNextFree	4294967295L
#define LEAF_diffServMeterId	1
#define MIN_diffServMeterId	1L
#define MAX_diffServMeterId	4294967295L
#define LEAF_diffServMeterSucceedNext	2
#define LEAF_diffServMeterFailNext	3
#define LEAF_diffServMeterSpecific	4
#define LEAF_diffServMeterStorage	5
#define VAL_diffServMeterStorage_other	1L
#define VAL_diffServMeterStorage_volatile	2L
#define VAL_diffServMeterStorage_nonVolatile	3L
#define VAL_diffServMeterStorage_permanent	4L
#define VAL_diffServMeterStorage_readOnly	5L
#define LEAF_diffServMeterStatus	6
#define VAL_diffServMeterStatus_active	1L
#define VAL_diffServMeterStatus_notInService	2L
#define VAL_diffServMeterStatus_notReady	3L
#define VAL_diffServMeterStatus_createAndGo	4L
#define VAL_diffServMeterStatus_createAndWait	5L
#define VAL_diffServMeterStatus_destroy	6L
#define LEAF_diffServTBParamNextFree	1
#define MIN_diffServTBParamNextFree	0L
#define MAX_diffServTBParamNextFree	4294967295L
#define LEAF_diffServTBParamId	1
#define MIN_diffServTBParamId	1L
#define MAX_diffServTBParamId	4294967295L
#define LEAF_diffServTBParamType	2
#define LEAF_diffServTBParamRate	3
#define MIN_diffServTBParamRate	1L
#define MAX_diffServTBParamRate	4294967295L
#define LEAF_diffServTBParamBurstSize	4
#define MIN_diffServTBParamBurstSize	0L
#define MAX_diffServTBParamBurstSize	2147483647L
#define LEAF_diffServTBParamInterval	5
#define MIN_diffServTBParamInterval	1L
#define MAX_diffServTBParamInterval	4294967295L
#define LEAF_diffServTBParamStorage	6
#define VAL_diffServTBParamStorage_other	1L
#define VAL_diffServTBParamStorage_volatile	2L
#define VAL_diffServTBParamStorage_nonVolatile	3L
#define VAL_diffServTBParamStorage_permanent	4L
#define VAL_diffServTBParamStorage_readOnly	5L
#define LEAF_diffServTBParamStatus	7
#define VAL_diffServTBParamStatus_active	1L
#define VAL_diffServTBParamStatus_notInService	2L
#define VAL_diffServTBParamStatus_notReady	3L
#define VAL_diffServTBParamStatus_createAndGo	4L
#define VAL_diffServTBParamStatus_createAndWait	5L
#define VAL_diffServTBParamStatus_destroy	6L
#define LEAF_diffServActionNextFree	1
#define MIN_diffServActionNextFree	0L
#define MAX_diffServActionNextFree	4294967295L
#define LEAF_diffServActionId	1
#define MIN_diffServActionId	1L
#define MAX_diffServActionId	4294967295L
#define LEAF_diffServActionInterface	2
#define MIN_diffServActionInterface	0L
#define MAX_diffServActionInterface	2147483647L
#define LEAF_diffServActionNext	3
#define LEAF_diffServActionSpecific	4
#define LEAF_diffServActionStorage	5
#define VAL_diffServActionStorage_other	1L
#define VAL_diffServActionStorage_volatile	2L
#define VAL_diffServActionStorage_nonVolatile	3L
#define VAL_diffServActionStorage_permanent	4L
#define VAL_diffServActionStorage_readOnly	5L
#define LEAF_diffServActionStatus	6
#define VAL_diffServActionStatus_active	1L
#define VAL_diffServActionStatus_notInService	2L
#define VAL_diffServActionStatus_notReady	3L
#define VAL_diffServActionStatus_createAndGo	4L
#define VAL_diffServActionStatus_createAndWait	5L
#define VAL_diffServActionStatus_destroy	6L
#define LEAF_diffServDscpMarkActDscp	1
#define MIN_diffServDscpMarkActDscp	0L
#define MAX_diffServDscpMarkActDscp	63L
#define LEAF_diffServCountActNextFree	4
#define MIN_diffServCountActNextFree	0L
#define MAX_diffServCountActNextFree	4294967295L
#define LEAF_diffServCountActId	1
#define MIN_diffServCountActId	1L
#define MAX_diffServCountActId	4294967295L
#define LEAF_diffServCountActOctets	2
#define LEAF_diffServCountActPkts	3
#define LEAF_diffServCountActStorage	4
#define VAL_diffServCountActStorage_other	1L
#define VAL_diffServCountActStorage_volatile	2L
#define VAL_diffServCountActStorage_nonVolatile	3L
#define VAL_diffServCountActStorage_permanent	4L
#define VAL_diffServCountActStorage_readOnly	5L
#define LEAF_diffServCountActStatus	5
#define VAL_diffServCountActStatus_active	1L
#define VAL_diffServCountActStatus_notInService	2L
#define VAL_diffServCountActStatus_notReady	3L
#define VAL_diffServCountActStatus_createAndGo	4L
#define VAL_diffServCountActStatus_createAndWait	5L
#define VAL_diffServCountActStatus_destroy	6L
#define LEAF_diffServAlgDropNextFree	1
#define MIN_diffServAlgDropNextFree	0L
#define MAX_diffServAlgDropNextFree	4294967295L
#define LEAF_diffServAlgDropId	1
#define MIN_diffServAlgDropId	1L
#define MAX_diffServAlgDropId	4294967295L
#define LEAF_diffServAlgDropType	2
#define VAL_diffServAlgDropType_other	1L
#define VAL_diffServAlgDropType_tailDrop	2L
#define VAL_diffServAlgDropType_headDrop	3L
#define VAL_diffServAlgDropType_randomDrop	4L
#define VAL_diffServAlgDropType_alwaysDrop	5L
#define LEAF_diffServAlgDropNext	3
#define LEAF_diffServAlgDropQMeasure	4
#define LEAF_diffServAlgDropQThreshold	5
#define MIN_diffServAlgDropQThreshold	1L
#define MAX_diffServAlgDropQThreshold	4294967295L
#define LEAF_diffServAlgDropSpecific	6
#define LEAF_diffServAlgDropOctets	7
#define LEAF_diffServAlgDropPkts	8
#define LEAF_diffServAlgRandomDropOctets	9
#define LEAF_diffServAlgRandomDropPkts	10
#define LEAF_diffServAlgDropStorage	11
#define VAL_diffServAlgDropStorage_other	1L
#define VAL_diffServAlgDropStorage_volatile	2L
#define VAL_diffServAlgDropStorage_nonVolatile	3L
#define VAL_diffServAlgDropStorage_permanent	4L
#define VAL_diffServAlgDropStorage_readOnly	5L
#define LEAF_diffServAlgDropStatus	12
#define VAL_diffServAlgDropStatus_active	1L
#define VAL_diffServAlgDropStatus_notInService	2L
#define VAL_diffServAlgDropStatus_notReady	3L
#define VAL_diffServAlgDropStatus_createAndGo	4L
#define VAL_diffServAlgDropStatus_createAndWait	5L
#define VAL_diffServAlgDropStatus_destroy	6L
#define LEAF_diffServRandomDropNextFree	3
#define MIN_diffServRandomDropNextFree	0L
#define MAX_diffServRandomDropNextFree	4294967295L
#define LEAF_diffServRandomDropId	1
#define MIN_diffServRandomDropId	1L
#define MAX_diffServRandomDropId	4294967295L
#define LEAF_diffServRandomDropMinThreshBytes	2
#define MIN_diffServRandomDropMinThreshBytes	1L
#define MAX_diffServRandomDropMinThreshBytes	4294967295L
#define LEAF_diffServRandomDropMinThreshPkts	3
#define MIN_diffServRandomDropMinThreshPkts	1L
#define MAX_diffServRandomDropMinThreshPkts	4294967295L
#define LEAF_diffServRandomDropMaxThreshBytes	4
#define MIN_diffServRandomDropMaxThreshBytes	1L
#define MAX_diffServRandomDropMaxThreshBytes	4294967295L
#define LEAF_diffServRandomDropMaxThreshPkts	5
#define MIN_diffServRandomDropMaxThreshPkts	1L
#define MAX_diffServRandomDropMaxThreshPkts	4294967295L
#define LEAF_diffServRandomDropProbMax	6
#define MIN_diffServRandomDropProbMax	0L
#define MAX_diffServRandomDropProbMax	1000L
#define LEAF_diffServRandomDropWeight	7
#define MIN_diffServRandomDropWeight	0L
#define MAX_diffServRandomDropWeight	65536L
#define LEAF_diffServRandomDropSamplingRate	8
#define MIN_diffServRandomDropSamplingRate	0L
#define MAX_diffServRandomDropSamplingRate	1000000L
#define LEAF_diffServRandomDropStorage	9
#define VAL_diffServRandomDropStorage_other	1L
#define VAL_diffServRandomDropStorage_volatile	2L
#define VAL_diffServRandomDropStorage_nonVolatile	3L
#define VAL_diffServRandomDropStorage_permanent	4L
#define VAL_diffServRandomDropStorage_readOnly	5L
#define LEAF_diffServRandomDropStatus	10
#define VAL_diffServRandomDropStatus_active	1L
#define VAL_diffServRandomDropStatus_notInService	2L
#define VAL_diffServRandomDropStatus_notReady	3L
#define VAL_diffServRandomDropStatus_createAndGo	4L
#define VAL_diffServRandomDropStatus_createAndWait	5L
#define VAL_diffServRandomDropStatus_destroy	6L
#define LEAF_diffServQNextFree	1
#define MIN_diffServQNextFree	0L
#define MAX_diffServQNextFree	4294967295L
#define LEAF_diffServQId	1
#define MIN_diffServQId	1L
#define MAX_diffServQId	4294967295L
#define LEAF_diffServQNext	2
#define LEAF_diffServQMinRate	3
#define LEAF_diffServQMaxRate	4
#define LEAF_diffServQStorage	5
#define VAL_diffServQStorage_other	1L
#define VAL_diffServQStorage_volatile	2L
#define VAL_diffServQStorage_nonVolatile	3L
#define VAL_diffServQStorage_permanent	4L
#define VAL_diffServQStorage_readOnly	5L
#define LEAF_diffServQStatus	6
#define VAL_diffServQStatus_active	1L
#define VAL_diffServQStatus_notInService	2L
#define VAL_diffServQStatus_notReady	3L
#define VAL_diffServQStatus_createAndGo	4L
#define VAL_diffServQStatus_createAndWait	5L
#define VAL_diffServQStatus_destroy	6L
#define LEAF_diffServSchedulerNextFree	1
#define MIN_diffServSchedulerNextFree	0L
#define MAX_diffServSchedulerNextFree	4294967295L
#define LEAF_diffServSchedulerId	1
#define MIN_diffServSchedulerId	1L
#define MAX_diffServSchedulerId	4294967295L
#define LEAF_diffServSchedulerNext	2
#define LEAF_diffServSchedulerMethod	3
#define LEAF_diffServSchedulerMinRate	4
#define LEAF_diffServSchedulerMaxRate	5
#define LEAF_diffServSchedulerStorage	6
#define VAL_diffServSchedulerStorage_other	1L
#define VAL_diffServSchedulerStorage_volatile	2L
#define VAL_diffServSchedulerStorage_nonVolatile	3L
#define VAL_diffServSchedulerStorage_permanent	4L
#define VAL_diffServSchedulerStorage_readOnly	5L
#define LEAF_diffServSchedulerStatus	7
#define VAL_diffServSchedulerStatus_active	1L
#define VAL_diffServSchedulerStatus_notInService	2L
#define VAL_diffServSchedulerStatus_notReady	3L
#define VAL_diffServSchedulerStatus_createAndGo	4L
#define VAL_diffServSchedulerStatus_createAndWait	5L
#define VAL_diffServSchedulerStatus_destroy	6L
#define LEAF_diffServMinRateNextFree	3
#define MIN_diffServMinRateNextFree	0L
#define MAX_diffServMinRateNextFree	4294967295L
#define LEAF_diffServMinRateId	1
#define MIN_diffServMinRateId	1L
#define MAX_diffServMinRateId	4294967295L
#define LEAF_diffServMinRatePriority	2
#define MIN_diffServMinRatePriority	1L
#define MAX_diffServMinRatePriority	4294967295L
#define LEAF_diffServMinRateAbsolute	3
#define MIN_diffServMinRateAbsolute	1L
#define MAX_diffServMinRateAbsolute	4294967295L
#define LEAF_diffServMinRateRelative	4
#define MIN_diffServMinRateRelative	1L
#define MAX_diffServMinRateRelative	4294967295L
#define LEAF_diffServMinRateStorage	5
#define VAL_diffServMinRateStorage_other	1L
#define VAL_diffServMinRateStorage_volatile	2L
#define VAL_diffServMinRateStorage_nonVolatile	3L
#define VAL_diffServMinRateStorage_permanent	4L
#define VAL_diffServMinRateStorage_readOnly	5L
#define LEAF_diffServMinRateStatus	6
#define VAL_diffServMinRateStatus_active	1L
#define VAL_diffServMinRateStatus_notInService	2L
#define VAL_diffServMinRateStatus_notReady	3L
#define VAL_diffServMinRateStatus_createAndGo	4L
#define VAL_diffServMinRateStatus_createAndWait	5L
#define VAL_diffServMinRateStatus_destroy	6L
#define LEAF_diffServMaxRateNextFree	5
#define MIN_diffServMaxRateNextFree	0L
#define MAX_diffServMaxRateNextFree	4294967295L
#define LEAF_diffServMaxRateId	1
#define MIN_diffServMaxRateId	1L
#define MAX_diffServMaxRateId	4294967295L
#define LEAF_diffServMaxRateLevel	2
#define MIN_diffServMaxRateLevel	1L
#define MAX_diffServMaxRateLevel	32L
#define LEAF_diffServMaxRateAbsolute	3
#define MIN_diffServMaxRateAbsolute	1L
#define MAX_diffServMaxRateAbsolute	4294967295L
#define LEAF_diffServMaxRateRelative	4
#define MIN_diffServMaxRateRelative	1L
#define MAX_diffServMaxRateRelative	4294967295L
#define LEAF_diffServMaxRateThreshold	5
#define MIN_diffServMaxRateThreshold	0L
#define MAX_diffServMaxRateThreshold	2147483647L
#define LEAF_diffServMaxRateStorage	6
#define VAL_diffServMaxRateStorage_other	1L
#define VAL_diffServMaxRateStorage_volatile	2L
#define VAL_diffServMaxRateStorage_nonVolatile	3L
#define VAL_diffServMaxRateStorage_permanent	4L
#define VAL_diffServMaxRateStorage_readOnly	5L
#define LEAF_diffServMaxRateStatus	7
#define VAL_diffServMaxRateStatus_active	1L
#define VAL_diffServMaxRateStatus_notInService	2L
#define VAL_diffServMaxRateStatus_notReady	3L
#define VAL_diffServMaxRateStatus_createAndGo	4L
#define VAL_diffServMaxRateStatus_createAndWait	5L
#define VAL_diffServMaxRateStatus_destroy	6L
#define LEAF_snmpTrapOID	1
#define LEAF_snmpTrapEnterprise	3

#endif /* end of #ifndef  LEAF_3289_H */

