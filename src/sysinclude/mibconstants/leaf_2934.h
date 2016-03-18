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
 **** Last build date: Fri Nov  9 22:57:23 2001
 **** from files:
 ****  Rfc1213.mib, Rfc2271-SNMP-FRAMEWORK.mib, Rfc1447-SNMPv2-PARTY.mib,
 ****  Rfc1450-SNMPv2.mib, E-Rfc1573-IANAifType.mib, Rfc2863-IF.mib,
 ****  E-IANA-RTPROTO.mib, Rfc2932-IPMROUTE-STD.mib, Rfc2934-PIM.mib,
 ****  rfc2934.ctl
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_2934_H
#define  LEAF_2934_H

#define LEAF_pimJoinPruneInterval	1
#define LEAF_pimInterfaceIfIndex	1
#define MIN_pimInterfaceIfIndex	1L
#define MAX_pimInterfaceIfIndex	2147483647L
#define LEAF_pimInterfaceAddress	2
#define LEAF_pimInterfaceNetMask	3
#define LEAF_pimInterfaceMode	4
#define VAL_pimInterfaceMode_dense	1L
#define VAL_pimInterfaceMode_sparse	2L
#define VAL_pimInterfaceMode_sparseDense	3L
#define LEAF_pimInterfaceDR	5
#define LEAF_pimInterfaceHelloInterval	6
#define LEAF_pimInterfaceStatus	7
#define VAL_pimInterfaceStatus_active	1L
#define VAL_pimInterfaceStatus_notInService	2L
#define VAL_pimInterfaceStatus_notReady	3L
#define VAL_pimInterfaceStatus_createAndGo	4L
#define VAL_pimInterfaceStatus_createAndWait	5L
#define VAL_pimInterfaceStatus_destroy	6L
#define LEAF_pimInterfaceJoinPruneInterval	8
#define LEAF_pimInterfaceCBSRPreference	9
#define MIN_pimInterfaceCBSRPreference	-1L
#define MAX_pimInterfaceCBSRPreference	255L
#define LEAF_pimNeighborAddress	1
#define LEAF_pimNeighborIfIndex	2
#define MIN_pimNeighborIfIndex	1L
#define MAX_pimNeighborIfIndex	2147483647L
#define LEAF_pimNeighborUpTime	3
#define LEAF_pimNeighborExpiryTime	4
#define LEAF_pimNeighborMode	5
#define VAL_pimNeighborMode_dense	1L
#define VAL_pimNeighborMode_sparse	2L
#define LEAF_pimIpMRouteUpstreamAssertTimer	1
#define LEAF_pimIpMRouteAssertMetric	2
#define LEAF_pimIpMRouteAssertMetricPref	3
#define LEAF_pimIpMRouteAssertRPTBit	4
#define VAL_pimIpMRouteAssertRPTBit_true	1L
#define VAL_pimIpMRouteAssertRPTBit_false	2L
#define LEAF_pimIpMRouteFlags	5
#define VAL_pimIpMRouteFlags_rpt	0L
#define VAL_pimIpMRouteFlags_spt	1L
#define LEAF_pimRPGroupAddress	1
#define LEAF_pimRPAddress	2
#define LEAF_pimRPState	3
#define VAL_pimRPState_up	1L
#define VAL_pimRPState_down	2L
#define LEAF_pimRPStateTimer	4
#define LEAF_pimRPLastChange	5
#define LEAF_pimRPRowStatus	6
#define VAL_pimRPRowStatus_active	1L
#define VAL_pimRPRowStatus_notInService	2L
#define VAL_pimRPRowStatus_notReady	3L
#define VAL_pimRPRowStatus_createAndGo	4L
#define VAL_pimRPRowStatus_createAndWait	5L
#define VAL_pimRPRowStatus_destroy	6L
#define LEAF_pimRPSetGroupAddress	1
#define LEAF_pimRPSetGroupMask	2
#define LEAF_pimRPSetAddress	3
#define LEAF_pimRPSetHoldTime	4
#define MIN_pimRPSetHoldTime	0L
#define MAX_pimRPSetHoldTime	255L
#define LEAF_pimRPSetExpiryTime	5
#define LEAF_pimRPSetComponent	6
#define MIN_pimRPSetComponent	1L
#define MAX_pimRPSetComponent	255L
#define LEAF_pimIpMRouteNextHopPruneReason	2
#define VAL_pimIpMRouteNextHopPruneReason_other	1L
#define VAL_pimIpMRouteNextHopPruneReason_prune	2L
#define VAL_pimIpMRouteNextHopPruneReason_assert	3L
#define LEAF_pimCandidateRPGroupAddress	1
#define LEAF_pimCandidateRPGroupMask	2
#define LEAF_pimCandidateRPAddress	3
#define LEAF_pimCandidateRPRowStatus	4
#define VAL_pimCandidateRPRowStatus_active	1L
#define VAL_pimCandidateRPRowStatus_notInService	2L
#define VAL_pimCandidateRPRowStatus_notReady	3L
#define VAL_pimCandidateRPRowStatus_createAndGo	4L
#define VAL_pimCandidateRPRowStatus_createAndWait	5L
#define VAL_pimCandidateRPRowStatus_destroy	6L
#define LEAF_pimComponentIndex	1
#define MIN_pimComponentIndex	1L
#define MAX_pimComponentIndex	255L
#define LEAF_pimComponentBSRAddress	2
#define LEAF_pimComponentBSRExpiryTime	3
#define LEAF_pimComponentCRPHoldTime	4
#define MIN_pimComponentCRPHoldTime	0L
#define MAX_pimComponentCRPHoldTime	255L
#define LEAF_pimComponentStatus	5
#define VAL_pimComponentStatus_active	1L
#define VAL_pimComponentStatus_notInService	2L
#define VAL_pimComponentStatus_notReady	3L
#define VAL_pimComponentStatus_createAndGo	4L
#define VAL_pimComponentStatus_createAndWait	5L
#define VAL_pimComponentStatus_destroy	6L

#endif /* end of #ifndef  LEAF_2934_H */

