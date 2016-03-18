/*
 * $Id: stat.h,v 1.25.6.1 Broadcom SDK $
 * 
 * $Copyright: Copyright 2008 Broadcom Corporation.
 * This program is the proprietary software of Broadcom Corporation
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.  
 *  
 * Except as expressly set forth in the Authorized License,
 *  
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *  
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 * 
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#ifndef __BCM_STAT_H__
#define __BCM_STAT_H__

#include <bcm/types.h>

/* 
 * Statistics counters.
 * 
 * Note: the following RFC 2465 MIBs are not supported:
 * 
 *   snmpIpv6IfStatsInTooBigErrors,
 *   snmpIpv6IfStatsInNoRoutes,
 *   snmpIpv6IfStatsInUnknownProtos,
 *   snmpIpv6IfStatsInTruncatedPkts,
 *   snmpIpv6IfStatsInDelivers,
 *   snmpIpv6IfStatsOutRequests,
 *   snmpIpv6IfStatsOutFragOKs,
 *   snmpIpv6IfStatsOutFragFails,
 *   snmpIpv6IfStatsOutFragCreates,
 *   snmpIpv6IfStatsReasmReqds,
 *   snmpIpv6IfStatsReasmOKs,
 *   snmpIpv6IfStatsReasmFails,
 */
typedef enum bcm_stat_val_e {
    snmpIfInOctets,                     /* RFC 1213 */
    snmpIfInUcastPkts,                  /* RFC 1213 */
    snmpIfInNUcastPkts,                 /* RFC 1213 */
    snmpIfInDiscards,                   /* RFC 1213 */
    snmpIfInErrors,                     /* RFC 1213 */
    snmpIfInUnknownProtos,              /* RFC 1213 */
    snmpIfOutOctets,                    /* RFC 1213 */
    snmpIfOutUcastPkts,                 /* RFC 1213 */
    snmpIfOutNUcastPkts,                /* RFC 1213 */
    snmpIfOutDiscards,                  /* RFC 1213 */
    snmpIfOutErrors,                    /* RFC 1213 */
    snmpIfOutQLen,                      /* RFC 1213 */
    snmpIpInReceives,                   /* RFC 1213 */
    snmpIpInHdrErrors,                  /* RFC 1213 */
    snmpIpForwDatagrams,                /* RFC 1213 */
    snmpIpInDiscards,                   /* RFC 1213 */
    snmpDot1dBasePortDelayExceededDiscards, /* RFC 1493 */
    snmpDot1dBasePortMtuExceededDiscards, /* RFC 1493 */
    snmpDot1dTpPortInFrames,            /* RFC 1493 */
    snmpDot1dTpPortOutFrames,           /* RFC 1493 */
    snmpDot1dPortInDiscards,            /* RFC 1493 */
    snmpEtherStatsDropEvents,           /* RFC 1757 (EtherStat) */
    snmpEtherStatsMulticastPkts,        /* RFC 1757 (EtherStat) */
    snmpEtherStatsBroadcastPkts,        /* RFC 1757 (EtherStat) */
    snmpEtherStatsUndersizePkts,        /* RFC 1757 (EtherStat) */
    snmpEtherStatsFragments,            /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts64Octets,         /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts65to127Octets,    /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts128to255Octets,   /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts256to511Octets,   /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts512to1023Octets,  /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts1024to1518Octets, /* RFC 1757 (EtherStat) */
    snmpEtherStatsOversizePkts,         /* RFC 1757 (EtherStat) */
    snmpEtherStatsJabbers,              /* RFC 1757 (EtherStat) */
    snmpEtherStatsOctets,               /* RFC 1757 (EtherStat) */
    snmpEtherStatsPkts,                 /* RFC 1757 (EtherStat) */
    snmpEtherStatsCollisions,           /* RFC 1757 (EtherStat) */
    snmpEtherStatsCRCAlignErrors,       /* RFC 1757 (EtherStat) */
    snmpEtherStatsTXNoErrors,           /* RFC 1757 (EtherStat) */
    snmpEtherStatsRXNoErrors,           /* RFC 1757 (EtherStat) */
    snmpDot3StatsAlignmentErrors,       /* RFC 2665 */
    snmpDot3StatsFCSErrors,             /* RFC 2665 */
    snmpDot3StatsSingleCollisionFrames, /* RFC 2665 */
    snmpDot3StatsMultipleCollisionFrames, /* RFC 2665 */
    snmpDot3StatsSQETTestErrors,        /* RFC 2665 */
    snmpDot3StatsDeferredTransmissions, /* RFC 2665 */
    snmpDot3StatsLateCollisions,        /* RFC 2665 */
    snmpDot3StatsExcessiveCollisions,   /* RFC 2665 */
    snmpDot3StatsInternalMacTransmitErrors, /* RFC 2665 */
    snmpDot3StatsCarrierSenseErrors,    /* RFC 2665 */
    snmpDot3StatsFrameTooLongs,         /* RFC 2665 */
    snmpDot3StatsInternalMacReceiveErrors, /* RFC 2665 */
    snmpDot3StatsSymbolErrors,          /* RFC 2665 */
    snmpDot3ControlInUnknownOpcodes,    /* RFC 2665 */
    snmpDot3InPauseFrames,              /* RFC 2665 */
    snmpDot3OutPauseFrames,             /* RFC 2665 */
    snmpIfHCInOctets,                   /* RFC 2233 */
    snmpIfHCInUcastPkts,                /* RFC 2233 */
    snmpIfHCInMulticastPkts,            /* RFC 2233 */
    snmpIfHCInBroadcastPkts,            /* RFC 2233 */
    snmpIfHCOutOctets,                  /* RFC 2233 */
    snmpIfHCOutUcastPkts,               /* RFC 2233 */
    snmpIfHCOutMulticastPkts,           /* RFC 2233 */
    snmpIfHCOutBroadcastPckts,          /* RFC 2233 */
    snmpIpv6IfStatsInReceives,          /* RFC 2465 */
    snmpIpv6IfStatsInHdrErrors,         /* RFC 2465 */
    snmpIpv6IfStatsInAddrErrors,        /* RFC 2465 */
    snmpIpv6IfStatsInDiscards,          /* RFC 2465 */
    snmpIpv6IfStatsOutForwDatagrams,    /* RFC 2465 */
    snmpIpv6IfStatsOutDiscards,         /* RFC 2465 */
    snmpIpv6IfStatsInMcastPkts,         /* RFC 2465 */
    snmpIpv6IfStatsOutMcastPkts,        /* RFC 2465 */
    snmpBcmIPMCBridgedPckts,            /* Broadcom-specific */
    snmpBcmIPMCRoutedPckts,             /* Broadcom-specific */
    snmpBcmIPMCInDroppedPckts,          /* Broadcom-specific */
    snmpBcmIPMCOutDroppedPckts,         /* Broadcom-specific */
    snmpBcmEtherStatsPkts1519to1522Octets, /* Broadcom-specific */
    snmpBcmEtherStatsPkts1522to2047Octets, /* Broadcom-specific */
    snmpBcmEtherStatsPkts2048to4095Octets, /* Broadcom-specific */
    snmpBcmEtherStatsPkts4095to9216Octets, /* Broadcom-specific */
    snmpBcmCustomReceive0,              /* Broadcom-specific */
    snmpBcmCustomReceive1,              /* Broadcom-specific */
    snmpBcmCustomReceive2,              /* Broadcom-specific */
    snmpBcmCustomReceive3,              /* Broadcom-specific */
    snmpBcmCustomReceive4,              /* Broadcom-specific */
    snmpBcmCustomReceive5,              /* Broadcom-specific */
    snmpBcmCustomReceive6,              /* Broadcom-specific */
    snmpBcmCustomReceive7,              /* Broadcom-specific */
    snmpBcmCustomReceive8,              /* Broadcom-specific */
    snmpBcmCustomTransmit0,             /* Broadcom-specific */
    snmpBcmCustomTransmit1,             /* Broadcom-specific */
    snmpBcmCustomTransmit2,             /* Broadcom-specific */
    snmpBcmCustomTransmit3,             /* Broadcom-specific */
    snmpBcmCustomTransmit4,             /* Broadcom-specific */
    snmpBcmCustomTransmit5,             /* Broadcom-specific */
    snmpBcmCustomTransmit6,             /* Broadcom-specific */
    snmpBcmCustomTransmit7,             /* Broadcom-specific */
    snmpBcmCustomTransmit8,             /* Broadcom-specific */
    snmpBcmCustomTransmit9,             /* Broadcom-specific */
    snmpBcmCustomTransmit10,            /* Broadcom-specific */
    snmpBcmCustomTransmit11,            /* Broadcom-specific */
    snmpBcmCustomTransmit12,            /* Broadcom-specific */
    snmpBcmCustomTransmit13,            /* Broadcom-specific */
    snmpBcmCustomTransmit14,            /* Broadcom-specific */
    snmpValCount 
} bcm_stat_val_t;

#define BCM_STAT_NAME_INITIALIZER \
{ \
    "snmpIfInOctets", \
    "snmpIfInUcastPkts", \
    "snmpIfInNUcastPkts", \
    "snmpIfInDiscards", \
    "snmpIfInErrors", \
    "snmpIfInUnknownProtos", \
    "snmpIfOutOctets", \
    "snmpIfOutUcastPkts", \
    "snmpIfOutNUcastPkts", \
    "snmpIfOutDiscards", \
    "snmpIfOutErrors", \
    "snmpIfOutQLen", \
    "snmpIpInReceives", \
    "snmpIpInHdrErrors", \
    "snmpIpForwDatagrams", \
    "snmpIpInDiscards", \
    "snmpDot1dBasePortDelayExceededDiscards", \
    "snmpDot1dBasePortMtuExceededDiscards", \
    "snmpDot1dTpPortInFrames", \
    "snmpDot1dTpPortOutFrames", \
    "snmpDot1dPortInDiscards", \
    "snmpEtherStatsDropEvents", \
    "snmpEtherStatsMulticastPkts", \
    "snmpEtherStatsBroadcastPkts", \
    "snmpEtherStatsUndersizePkts", \
    "snmpEtherStatsFragments", \
    "snmpEtherStatsPkts64Octets", \
    "snmpEtherStatsPkts65to127Octets", \
    "snmpEtherStatsPkts128to255Octets", \
    "snmpEtherStatsPkts256to511Octets", \
    "snmpEtherStatsPkts512to1023Octets", \
    "snmpEtherStatsPkts1024to1518Octets", \
    "snmpEtherStatsOversizePkts", \
    "snmpEtherStatsJabbers", \
    "snmpEtherStatsOctets", \
    "snmpEtherStatsPkts", \
    "snmpEtherStatsCollisions", \
    "snmpEtherStatsCRCAlignErrors", \
    "snmpEtherStatsTXNoErrors", \
    "snmpEtherStatsRXNoErrors", \
    "snmpDot3StatsAlignmentErrors", \
    "snmpDot3StatsFCSErrors", \
    "snmpDot3StatsSingleCollisionFrames", \
    "snmpDot3StatsMultipleCollisionFrames", \
    "snmpDot3StatsSQETTestErrors", \
    "snmpDot3StatsDeferredTransmissions", \
    "snmpDot3StatsLateCollisions", \
    "snmpDot3StatsExcessiveCollisions", \
    "snmpDot3StatsInternalMacTransmitErrors", \
    "snmpDot3StatsCarrierSenseErrors", \
    "snmpDot3StatsFrameTooLongs", \
    "snmpDot3StatsInternalMacReceiveErrors", \
    "snmpDot3StatsSymbolErrors", \
    "snmpDot3ControlInUnknownOpcodes", \
    "snmpDot3InPauseFrames", \
    "snmpDot3OutPauseFrames", \
    "snmpIfHCInOctets", \
    "snmpIfHCInUcastPkts", \
    "snmpIfHCInMulticastPkts", \
    "snmpIfHCInBroadcastPkts", \
    "snmpIfHCOutOctets", \
    "snmpIfHCOutUcastPkts", \
    "snmpIfHCOutMulticastPkts", \
    "snmpIfHCOutBroadcastPckts", \
    "snmpIpv6IfStatsInReceives", \
    "snmpIpv6IfStatsInHdrErrors", \
    "snmpIpv6IfStatsInAddrErrors", \
    "snmpIpv6IfStatsInDiscards", \
    "snmpIpv6IfStatsOutForwDatagrams", \
    "snmpIpv6IfStatsOutDiscards", \
    "snmpIpv6IfStatsInMcastPkts", \
    "snmpIpv6IfStatsOutMcastPkts", \
    "snmpBcmIPMCBridgedPckts", \
    "snmpBcmIPMCRoutedPckts", \
    "snmpBcmIPMCInDroppedPckts", \
    "snmpBcmIPMCOutDroppedPckts", \
    "snmpBcmEtherStatsPkts1519to1522Octets", \
    "snmpBcmEtherStatsPkts1522to2047Octets", \
    "snmpBcmEtherStatsPkts2048to4095Octets", \
    "snmpBcmEtherStatsPkts4095to9216Octets", \
    "snmpBcmCustomReceive0", \
    "snmpBcmCustomReceive1", \
    "snmpBcmCustomReceive2", \
    "snmpBcmCustomReceive3", \
    "snmpBcmCustomReceive4", \
    "snmpBcmCustomReceive5", \
    "snmpBcmCustomReceive6", \
    "snmpBcmCustomReceive7", \
    "snmpBcmCustomReceive8", \
    "snmpBcmCustomTransmit0", \
    "snmpBcmCustomTransmit1", \
    "snmpBcmCustomTransmit2", \
    "snmpBcmCustomTransmit3", \
    "snmpBcmCustomTransmit4", \
    "snmpBcmCustomTransmit5", \
    "snmpBcmCustomTransmit6", \
    "snmpBcmCustomTransmit7", \
    "snmpBcmCustomTransmit8", \
    "snmpBcmCustomTransmit9", \
    "snmpBcmCustomTransmit10", \
    "snmpBcmCustomTransmit11", \
    "snmpBcmCustomTransmit12", \
    "snmpBcmCustomTransmit13", \
    "snmpBcmCustomTransmit14"  \
}

/* bcm_custom_stat_trigger_e */
typedef enum bcm_custom_stat_trigger_e {
    bcmDbgCntRIPD4,                 /* Rx: IPv4 L3 discard packets. */
    bcmDbgCntRIPC4,                 /* Rx: Good L3 (V4 packets) includes
                                       tunneled. */
    bcmDbgCntRIPHE4,                /* Rx: IPv4 header error packets. */
    bcmDbgCntIMRP4,                 /* Rx: Routed IPv4 multicast packets. */
    bcmDbgCntRIPD6,                 /* Rx: IPv6 L3 discard packets. */
    bcmDbgCntRIPC6,                 /* Rx: Good L3 (V6 packets) includes
                                       tunneled. */
    bcmDbgCntRIPHE6,                /* Rx: IPv6 header error packets. */
    bcmDbgCntIMRP6,                 /* Rx: Routed IPv6 multicast packets. */
    bcmDbgCntRDISC,                 /* Rx: IBP discard and CBP full. */
    bcmDbgCntRUC,                   /* Rx: Good unicast (L2+L3) packets. */
    bcmDbgCntRPORTD,                /* Rx: Packets droppped when ingress port is
                                       not in forwarding state. */
    bcmDbgCntPDISC,                 /* Rx: policy discard - DST_DISCARD,
                                       SRC_DISCARD, RATE_CONTROL... */
    bcmDbgCntIMBP,                  /* Rx: Bridged multicast packets. */
    bcmDbgCntRFILDR,                /* Rx: Packets dropped by FP. */
    bcmDbgCntRIMDR,                 /* Rx: Multicast (L2+L3) packets that are
                                       dropped. */
    bcmDbgCntRDROP,                 /* Rx: Port bitmap zero drop condition. */
    bcmDbgCntIRPSE,                 /* Rx: HiGig IPIC pause packets. */
    bcmDbgCntIRHOL,                 /* Rx: HiGig End-to-End HOL packets
                                       (BCM56504/56700/56800/56580). */
    bcmDbgCntIRIBP,                 /* Rx: HiGig End-to-End IBP packets
                                       (BCM56504/56700/56800/56580). */
    bcmDbgCntDSL3HE,                /* Rx: DOS L3 header error packets. */
    bcmDbgCntIUNKHDR,               /* Rx: Unknown HiGig header type packet
                                       (BCM56700/56800/56580). */
    bcmDbgCntDSL4HE,                /* Rx: DOS L4 header error packets. */
    bcmDbgCntIMIRROR,               /* Rx: HiGig mirror packet
                                       (BCM56700/56800/56580). */
    bcmDbgCntDSICMP,                /* Rx: DOS ICMP error packets. */
    bcmDbgCntDSFRAG,                /* Rx: DOS fragment error packets. */
    bcmDbgCntMTUERR,                /* Rx: Packets trapped to CPU due to egress
                                       L3 MTU violation. */
    bcmDbgCntRTUN,                  /* Rx: Tunnel packets. */
    bcmDbgCntRTUNE,                 /* Rx: tunnel error packets. */
    bcmDbgCntVLANDR,                /* Rx: VLAN drops. */
    bcmDbgCntRHGUC,                 /* Rx: HiGig lookup UC cases (BCM56504 B0). */
    bcmDbgCntRHGMC,                 /* Rx: HiGig lookup MC cases (BCM56504 B0). */
    bcmDbgCntMPLS,                  /* Rx: MPLS packets (BCM5660x only). */
    bcmDbgCntMACLMT,                /* Rx: packets dropped due to MAC Limit is
                                       hit. */
    bcmDbgCntMPLSERR,               /* Rx: MPLS packets with error (BCM5660x
                                       only). */
    bcmDbgCntURPFERR,               /* Rx: L3 source URPF check Fail (BCM5660x
                                       only). */
    bcmDbgCntHGHDRE,                /* Rx: Higig Header error packets
                                       (BCM56700/56800/56580/56514). */
    bcmDbgCntMCIDXE,                /* Rx: Multicast Index error packets
                                       (BCM56700/56800/56580). */
    bcmDbgCntLAGLUP,                /* Rx: LAG failover loopback packets
                                       (BCM56700/56800/56580). */
    bcmDbgCntLAGLUPD,               /* Rx: LAG backup port down
                                       (BCM56700/56800/56580). */
    bcmDbgCntPARITYD,               /* Rx: Parity error packets
                                       (BCM56700/56800/56580). */
    bcmDbgCntVFPDR,                 /* Rx: VLAN FP drop case (BCM56514). */
    bcmDbgCntURPF,                  /* Rx: Unicast RPF drop case (BCM56514). */
    bcmDbgCntDSTDISCARDDROP,        /* Rx: L2/L3 lookup DST_DISCARD drop. */
    bcmDbgCntCLASSBASEDMOVEDROP,    /* Rx: Class based learning drop. */
    bcmDbgCntMACLMT_NODROP,         /* Rx: Mac limit exceeded and packet not
                                       dropped. */
    bcmDbgCntMACSAEQUALMACDA,       /* Rx: Dos Attack L2 Packets MACSA equals to
                                       MACDA. */
    bcmDbgCntMACLMT_DROP,           /* Rx: Mac limit exceeded and packet
                                       dropped. */
    bcmDbgCntTGIP4,                 /* Tx: Good IPv4 L3 UC packets. */
    bcmDbgCntTIPD4,                 /* Tx: IPv4 L3 UC Aged and Drop packets. */
    bcmDbgCntTGIPMC4,               /* Tx: Good IPv4 IPMC packets. */
    bcmDbgCntTIPMCD4,               /* Tx: IPv4 IPMC Aged and Drop packets. */
    bcmDbgCntTGIP6,                 /* Tx: Good IPv6 L3 UC packets. */
    bcmDbgCntTIPD6,                 /* Tx: IPv6 L3 UC Aged and Drop Packets. */
    bcmDbgCntTGIPMC6,               /* Tx: Good IPv6 IPMC packets. */
    bcmDbgCntTIPMCD6,               /* Tx: IPv6 IPMC Aged and Drop packets. */
    bcmDbgCntTTNL,                  /* Tx: Tunnel packets. */
    bcmDbgCntTTNLE,                 /* Tx: Tunnel error packets. */
    bcmDbgCntTTTLD,                 /* Tx: Packets dropped due to TTL threshold
                                       counter. */
    bcmDbgCntTCFID,                 /* Tx: Packets dropped when CFI set & pket
                                       is untagged or L3 switched for IPMC. */
    bcmDbgCntTVLAN,                 /* Tx: VLAN tagged packets. */
    bcmDbgCntTVLAND,                /* Tx: Packets dropped due to invalid VLAN
                                       counter. */
    bcmDbgCntTVXLTMD,               /* Tx: Packets dropped due to miss in VXLT
                                       table counter. */
    bcmDbgCntTSTGD,                 /* Tx: Packets dropped due to Spanning Tree
                                       State not in forwarding state. */
    bcmDbgCntTAGED,                 /* Tx: Packets dropped due to packet aged
                                       counter. */
    bcmDbgCntTL2MCD,                /* Tx: L2 MC packets. */
    bcmDbgCntTPKTD,                 /* Tx: Packets dropped due to any condition. */
    bcmDbgCntTMIRR,                 /* Tx: Packets with mirroring flag. */
    bcmDbgCntTSIPL,                 /* Tx: Packets with SIP Link Local Drop flag
                                       (BCM56504/56700/56800/56580). */
    bcmDbgCntTHGUC,                 /* Tx: Higig Looked-up L3UC packets
                                       (BCM56504_B0/56700/56800/56580). */
    bcmDbgCntTHGMC,                 /* Tx: Higig Looked-up L3MC packets
                                       (BCM56504_B0/56700/56800/56580). */
    bcmDbgCntTHIGIG2,               /* Tx: Unknown HiGig2 Drops
                                       (BCM56700/56800/56580). */
    bcmDbgCntTHGI,                  /* Tx: Unknown HiGig drops
                                       (BCM56700/56800/56580). */
    bcmDbgCntTL2_MTU,               /* Tx: L2 MTU fail drops
                                       (BCM56700/56800/56580). */
    bcmDbgCntTPARITY_ERR,           /* Tx: Parity error drops
                                       (BCM56700/56800/56580). */
    bcmDbgCntTIP_LEN_FAIL,          /* Tx: IP Length check fail drops
                                       (BCM56700/56800/56580). */
    bcmDbgCntTMTUD,                 /* Tx: EBAD_MTU_drops (BCM5660x only). */
    bcmDbgCntTSLLD,                 /* Tx: ESIP_LINK_LOCAL (BCM5660x only). */
    bcmDbgCntTL2MPLS,               /* Tx: L2_MPLS_ENCAP_TX (BCM5660x only). */
    bcmDbgCntTL3MPLS,               /* Tx: L3_MPLS_ENCAP_TX (BCM5660x only). */
    bcmDbgCntTMPLS,                 /* Tx: MPLS_TX (BCM5660x only). */
    bcmDbgCntTMODIDTOOLARGEDROP,    /* Tx: MODID greater than 31 drop counter. */
    bcmDbgCntPKTMODTOOLARGEDROP,    /* Tx: Byte additions too large drop
                                       counter. */
    bcmDbgCntNum                    /* Must be last one. */
} bcm_custom_stat_trigger_t;

/* Custom receive flags. */
#define BCM_DBG_CNT_RIPD4       0x00000001 /* Rx IPv4 L3 discard packets. */
#define BCM_DBG_CNT_RIPC4       0x00000002 /* Good rx L3 (V4 packets) includes
                                              tunneled. */
#define BCM_DBG_CNT_RIPHE4      0x00000004 /* Rx IPv4 header error packets. */
#define BCM_DBG_CNT_IMRP4       0x00000008 /* Routed IPv4 multicast packets. */
#define BCM_DBG_CNT_RIPD6       0x00000010 /* Rx IPv6 L3 discard packet. */
#define BCM_DBG_CNT_RIPC6       0x00000020 /* Good rx L3 (V6 packets) includes
                                              tunneled. */
#define BCM_DBG_CNT_RIPHE6      0x00000040 /* Rx IPv6 header error packets. */
#define BCM_DBG_CNT_IMRP6       0x00000080 /* Routed IPv6 multicast packets. */
#define BCM_DBG_CNT_RDISC       0x00000100 /* IBP discard and CBP full. */
#define BCM_DBG_CNT_RUC         0x00000200 /* Good rx unicast (L2+L3) packets. */
#define BCM_DBG_CNT_RPORTD      0x00000400 /* Packets droppped when ingress port
                                              is not in forwarding state. */
#define BCM_DBG_CNT_PDISC       0x00000800 /* Rx policy discard - DST_DISCARD,
                                              SRC_DISCARD, RATE_CONTROL... */
#define BCM_DBG_CNT_IMBP        0x00001000 /* Bridged multicast packets. */
#define BCM_DBG_CNT_RFILDR      0x00002000 /* Packets dropped by FP. */
#define BCM_DBG_CNT_RIMDR       0x00004000 /* Multicast (L2+L3) packets that are
                                              dropped. */
#define BCM_DBG_CNT_RDROP       0x00008000 /* Port bitmap zero drop condition. */
#define BCM_DBG_CNT_IRPSE       0x00010000 /* HiGig IPIC pause rx. */
#define BCM_DBG_CNT_IRHOL       0x00020000 /* HiGig End-to-End HOL rx packets
                                              (BCM56504/56700/56800/56580). */
#define BCM_DBG_CNT_IRIBP       0x00040000 /* HiGig End-to-End IBP rx packets
                                              (BCM56504/56700/56800/56580). */
#define BCM_DBG_CNT_DSL3HE      0x00080000 /* DOS L3 header error packets. */
#define BCM_DBG_CNT_IUNKHDR     0x00080000 /* Unknown HiGig header type packet
                                              (BCM56700/56800/56580). */
#define BCM_DBG_CNT_DSL4HE      0x00100000 /* DOS L4 header error packets. */
#define BCM_DBG_CNT_IMIRROR     0x00100000 /* HiGig mirror packet
                                              (BCM56700/56800/56580). */
#define BCM_DBG_CNT_DSICMP      0x00200000 /* DOS ICMP error packets. */
#define BCM_DBG_CNT_DSFRAG      0x00400000 /* DOS fragment error packets. */
#define BCM_DBG_CNT_MTUERR      0x00800000 /* Packets trapped to CPU due to
                                              egress L3 MTU violation. */
#define BCM_DBG_CNT_RTUN        0x01000000 /* Number of tunnel packets received. */
#define BCM_DBG_CNT_RTUNE       0x02000000 /* Rx tunnel error packets. */
#define BCM_DBG_CNT_VLANDR      0x04000000 /* Rx VLAN drops. */
#define BCM_DBG_CNT_RHGUC       0x08000000 /* Rx HiGig lookup UC cases (BCM56504
                                              B0 only). */
#define BCM_DBG_CNT_RHGMC       0x10000000 /* Rx HiGig lookup MC cases (BCM56504
                                              B0 only). */
#define BCM_DBG_CNT_MPLS        0x20000000 /* Received MPLS Packets (BCM5660x
                                              only). */
#define BCM_DBG_CNT_MACLMT      0x20000000 /* packets dropped due to MAC Limit
                                              is hit. */
#define BCM_DBG_CNT_MPLSERR     0x40000000 /* Received MPLS Packets with Error
                                              (BCM5660x only). */
#define BCM_DBG_CNT_URPFERR     0x80000000 /* L3 src URPF check Fail (BCM5660x
                                              only). */
#define BCM_DBG_CNT_HGHDRE      0x08000000 /* Higig Header error packets
                                              (BCM56700/56800/56580). */
#define BCM_DBG_CNT_MCIDXE      0x10000000 /* Multicast Index error packets
                                              (BCM56700/56800/56580). */
#define BCM_DBG_CNT_LAGLUP      0x20000000 /* LAG failover loopback packets
                                              (BCM56700/56800/56580). */
#define BCM_DBG_CNT_LAGLUPD     0x40000000 /* LAG backup port down
                                              (BCM56700/56800/56580). */
#define BCM_DBG_CNT_PARITYD     0x80000000 /* Parity error packets
                                              (BCM56700/56800/56580). */
#define BCM_FB_DBG_CNT_RMASK    0x07ffffff /* Internal. */
#define BCM_RP_DBG_CNT_RMASK    0x27ffffff /* Internal. */
#define BCM_FB_B0_DBG_CNT_RMASK 0x1fffffff /* Internal. */
#define BCM_HB_DBG_CNT_RMASK    0xffffffff /* Internal. */

/* Custom transmit flags. */
#define BCM_DBG_CNT_TGIP4               0x00000001 /* Tx Good IPv4 L3 UC
                                                      packets. */
#define BCM_DBG_CNT_TIPD4               0x00000002 /* Tx IPv4 L3 UC Aged and
                                                      Drop packets. */
#define BCM_DBG_CNT_TGIPMC4             0x00000004 /* Tx Good IPv4 IPMC packets. */
#define BCM_DBG_CNT_TIPMCD4             0x00000008 /* Tx IPv4 IPMC Aged and Drop
                                                      packets. */
#define BCM_DBG_CNT_TGIP6               0x00000010 /* Tx Good IPv6 L3 UC
                                                      packets. */
#define BCM_DBG_CNT_TIPD6               0x00000020 /* Tx IPv6 L3 UC Aged and
                                                      Drop Packets. */
#define BCM_DBG_CNT_TGIPMC6             0x00000040 /* Tx Good IPv6 IPMC packets. */
#define BCM_DBG_CNT_TIPMCD6             0x00000080 /* Tx IPv6 IPMC Aged and Drop
                                                      packets. */
#define BCM_DBG_CNT_TTNL                0x00000100 /* Tx Tunnel packets. */
#define BCM_DBG_CNT_TTNLE               0x00000200 /* Tx Tunnel error packets. */
#define BCM_DBG_CNT_TTTLD               0x00000400 /* Pkts dropped due to TTL
                                                      threshold counter. */
#define BCM_DBG_CNT_TCFID               0x00000800 /* Pkts dropped when CFI set
                                                      & pket is untagged or L3
                                                      switched for IPMC. */
#define BCM_DBG_CNT_TVLAN               0x00001000 /* Tx VLAN tagged packets. */
#define BCM_DBG_CNT_TVLAND              0x00002000 /* Pkts dropped due to
                                                      invalid VLAN counter. */
#define BCM_DBG_CNT_TVXLTMD             0x00004000 /* Pkts dropped due to miss
                                                      in VXLT table counter. */
#define BCM_DBG_CNT_TSTGD               0x00008000 /* Pkts dropped due to
                                                      Spanning Tree State not in
                                                      forwarding state. */
#define BCM_DBG_CNT_TAGED               0x00010000 /* Pkts dropped due to packet
                                                      aged counter. */
#define BCM_DBG_CNT_TL2MCD              0x00020000 /* L2 MC packet drop counter. */
#define BCM_DBG_CNT_TPKTD               0x00040000 /* Pkts dropped due to any
                                                      condition. */
#define BCM_DBG_CNT_TMIRR               0x00080000 /* mirroring flag. */
#define BCM_DBG_CNT_TSIPL               0x00100000 /* SIP Link Local Drop flag
                                                      (BCM56504/56700/56800/56580). */
#define BCM_DBG_CNT_THGUC               0x00200000 /* Higig Lookedup L3UC Pkts
                                                      (BCM56504_B0/56700/56800/56580). */
#define BCM_DBG_CNT_THGMC               0x00400000 /* Higig Lookedup L3MC Pkts
                                                      (BCM56504_B0/56700/56800/56580). */
#define BCM_DBG_CNT_THIGIG2             0x00800000 /* Unknown HiGig2 Drop
                                                      (BCM56700/56800/56580). */
#define BCM_DBG_CNT_THGI                0x01000000 /* Unknown HiGig drop
                                                      (BCM56700/56800/56580). */
#define BCM_DBG_CNT_TL2_MTU             0x02000000 /* L2 MTU fail drop
                                                      (BCM56700/56800/56580). */
#define BCM_DBG_CNT_TPARITY_ERR         0x04000000 /* Parity Error drop
                                                      (BCM56700/56800/56580). */
#define BCM_DBG_CNT_TIP_LEN_FAIL        0x08000000 /* IP Length check fail drop
                                                      (BCM56700/56800/56580). */
#define BCM_DBG_CNT_TMTUD               0x01000000 /* EBAD_MTU_DROP (BCM5660x
                                                      only). */
#define BCM_DBG_CNT_TSLLD               0x10000000 /* ESIP_LINK_LOCAL (BCM5660x
                                                      only). */
#define BCM_DBG_CNT_TL2MPLS             0x20000000 /* L2_MPLS_ENCAP_TX (BCM5660x
                                                      only). */
#define BCM_DBG_CNT_TL3MPLS             0x40000000 /* L3_MPLS_ENCAP_TX (BCM5660x
                                                      only). */
#define BCM_DBG_CNT_TMPLS               0x80000000 /* MPLS_TX (BCM5660x only). */
#define BCM_DBG_CNT_MODIDTOOLARGEDROP   0x10000000 /* MODID greater than 31 drop
                                                      counter. */
#define BCM_DBG_CNT_PKTMODTOOLARGEDROP  0x20000000 /* Byte additions too large
                                                      drop counter. */
#define BCM_FB_DBG_CNT_TMASK            0x001fffff /* Internal. */
#define BCM_RP_DBG_CNT_TMASK            0x001fffff /* Internal. */
#define BCM_FB_B0_DBG_CNT_TMASK         0x007fffff /* Internal. */
#define BCM_HB_DBG_CNT_TMASK            0x0fffffff /* Internal. */
#define BCM_TRX_DBG_CNT_TMASK           0x3fffffff /* Internal. */

/* Initialize the BCM statistics module. */
extern int bcm_stat_init(
    int unit);

#define bcm_stat_enable_set(unit, port, enable)             /* Gone */
#define bcm_stat_enable_get(unit, port, enable_ptr)             /* Gone */

/* Clear the port-based statistics for the indicated device port. */
extern int bcm_stat_clear(
    int unit, 
    bcm_port_t port);

/* Synchronize software counters with hardware. */
extern int bcm_stat_sync(
    int unit);

/* Get the specified statistics from the device. */
extern int bcm_stat_get(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    uint64 *value);

/* Get the specified statistics from the device. */
extern int bcm_stat_get32(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    uint32 *value);

/* Set/get debug counter to count certain packet types. */
extern int bcm_stat_custom_set(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    uint32 flags);

/* Set/get debug counter to count certain packet types. */
extern int bcm_stat_custom_get(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    uint32 *flags);

/* Add a certain packet type to debug counter to count. */
extern int bcm_stat_custom_add(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    bcm_custom_stat_trigger_t trigger);

/* Delete the specified packet type from debug counter. */
extern int bcm_stat_custom_delete(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    bcm_custom_stat_trigger_t trigger);

/* Delete all packet types from debug counter. */
extern int bcm_stat_custom_delete_all(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type);

/* Check if specified packet types is part of debug counter. */
extern int bcm_stat_custom_check(
    int unit, 
    bcm_port_t port, 
    bcm_stat_val_t type, 
    bcm_custom_stat_trigger_t trigger, 
    int *result);

#endif /* __BCM_STAT_H__ */
