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
 **** Last build date: Mon Mar  4 14:51:38 2002
 **** from files:
 ****  Rfc1213.mib, Rfc1447-SNMPv2-PARTY.mib, Rfc1450-SNMPv2.mib,
 ****  Rfc2096-IP-FORWARD.mib, rfc2096.ctl
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_2096_H
#define  LEAF_2096_H

#define LEAF_ipForwardNumber	1
#define LEAF_ipCidrRouteNumber	3
#define LEAF_ipCidrRouteDest	1
#define LEAF_ipCidrRouteMask	2
#define LEAF_ipCidrRouteTos	3
#define LEAF_ipCidrRouteNextHop	4
#define LEAF_ipCidrRouteIfIndex	5
#define LEAF_ipCidrRouteType	6
#define VAL_ipCidrRouteType_other	1L
#define VAL_ipCidrRouteType_reject	2L
#define VAL_ipCidrRouteType_local	3L
#define VAL_ipCidrRouteType_remote	4L
#define LEAF_ipCidrRouteProto	7
#define VAL_ipCidrRouteProto_other	1L
#define VAL_ipCidrRouteProto_local	2L
#define VAL_ipCidrRouteProto_netmgmt	3L
#define VAL_ipCidrRouteProto_icmp	4L
#define VAL_ipCidrRouteProto_egp	5L
#define VAL_ipCidrRouteProto_ggp	6L
#define VAL_ipCidrRouteProto_hello	7L
#define VAL_ipCidrRouteProto_rip	8L
#define VAL_ipCidrRouteProto_isIs	9L
#define VAL_ipCidrRouteProto_esIs	10L
#define VAL_ipCidrRouteProto_ciscoIgrp	11L
#define VAL_ipCidrRouteProto_bbnSpfIgp	12L
#define VAL_ipCidrRouteProto_ospf	13L
#define VAL_ipCidrRouteProto_bgp	14L
#define VAL_ipCidrRouteProto_idpr	15L
#define VAL_ipCidrRouteProto_ciscoEigrp	16L
#define LEAF_ipCidrRouteAge	8
#define LEAF_ipCidrRouteInfo	9
#define LEAF_ipCidrRouteNextHopAS	10
#define LEAF_ipCidrRouteMetric1	11
#define VAL_ipCidrRouteMetric_default   -1
#define LEAF_ipCidrRouteMetric2	12
#define LEAF_ipCidrRouteMetric3	13
#define LEAF_ipCidrRouteMetric4	14
#define LEAF_ipCidrRouteMetric5	15
#define LEAF_ipCidrRouteStatus	16
#define VAL_ipCidrRouteStatus_active	1L
#define VAL_ipCidrRouteStatus_notInService	2L
#define VAL_ipCidrRouteStatus_notReady	3L
#define VAL_ipCidrRouteStatus_createAndGo	4L
#define VAL_ipCidrRouteStatus_createAndWait	5L
#define VAL_ipCidrRouteStatus_destroy	6L

#endif /* end of #ifndef  LEAF_2096_H */
