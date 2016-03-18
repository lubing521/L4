/*
 * $Id: tx.h,v 1.7 Broadcom SDK $
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
 * File:        tx.h
 * Purpose:	BCMX Packet Transmit APIs
 */

#ifndef   _BCMX_TX_H_
#define   _BCMX_TX_H_

#include <bcm/pkt.h>
#include <bcmx/lplist.h>


/* bcmx_tx flags:
 *       BCMX_TX_F_L2_LOOKUP    Perform an L2 lookup on the pkt
 *       BCMX_TX_F_DLF_DISCARD  Discard pkt if the L2 lookup fails.
 *                              This only applies if L2_LOOKUP is set.
 *       BCMX_TX_F_FLOOD_PKT    Flood the packet to all ports on the packet's
 *                              VLAN.  This overrides L2 lookup.
 *       BCMX_TX_F_CRC_APPEND   Only two CRC modes are supported:  Append
 *                              and regenerate.  If set, this flag selects
 *                              append.
 *       BCMX_TX_F_CPU_TUNNEL   Force the packet to be tunneled to a remote
 *                              CPU for direct transmit
 */

#define BCMX_TX_F_L2_LOOKUP        0x1
#define BCMX_TX_F_DLF_DISCARD      0x2
#define BCMX_TX_F_FLOOD_PKT        0x4
#define BCMX_TX_F_DISCARDED        0x8    /* Internal use */
#define BCMX_TX_F_CRC_APPEND       0x10
#define BCMX_TX_F_CPU_TUNNEL       0x20

/* Return values for bcmx_tx */
#define BCMX_TX_OK             0    /* Sent normally */
#define BCMX_TX_DISCARDED      1    /* Discarded due to lookup failure */
#define BCMX_TX_FLOODED        2    /* Flooded due to lookup failure */


extern int    bcmx_tx(bcm_pkt_t *pkt, uint32 flags);
extern int    bcmx_tx_uc(bcm_pkt_t *pkt, bcmx_lport_t d_port, uint32 flags);
extern int    bcmx_tx_flood(bcm_pkt_t *pkt, uint32 flags);

extern int bcmx_tx_lplist(bcm_pkt_t *pkt, bcmx_lplist_t *tx_ports,
                          bcmx_lplist_t *untagged_ports, uint32 flags);

extern int bcmx_tx_pkt_l3_set(bcm_pkt_t *pkt, int l3);
extern int bcmx_tx_pkt_untagged_set(bcm_pkt_t *pkt, int untagged);

/* bcmx_tx_port_list is DEPRECATED.  Use bcmx_tx_lplist. */
extern int bcmx_tx_port_list(bcmx_lplist_t *lplist, bcm_pkt_t *pkt);

#endif /* _BCMX_TX_H_ */
