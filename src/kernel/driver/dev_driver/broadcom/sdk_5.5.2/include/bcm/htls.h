/*
 * $Id: htls.h,v 1.10.6.1 Broadcom SDK $
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

#ifndef __BCM_HTLS_H__
#define __BCM_HTLS_H__

#include <bcm/types.h>

#define BCM_VCLABEL_MAX         ((1 << 20) - 1) 

/* Initialize the VPLS module. */
extern int bcm_vpls_bitmap_init(
    int unit);

/* Configure the bitmap and VLAN ID for a VC label. */
extern int bcm_vpls_bitmap_add(
    int unit, 
    uint32 vc_label, 
    bcm_vlan_t vid, 
    bcm_pbmp_t pbmp);

/* Remove the bitmap and VLAN ID for a VC label. */
extern int bcm_vpls_bitmap_delete(
    int unit, 
    uint32 vc_label);

/* Clear all VPLS labels for a unit. */
extern int bcm_vpls_bitmap_delete_all(
    int unit);

/* Retrieve the bitmap and VLAN ID for a VC label. */
extern int bcm_vpls_bitmap_get(
    int unit, 
    uint32 vc_label, 
    bcm_vlan_t *vid, 
    bcm_pbmp_t *pbmp);

/* Clean up the VPLS info for a unit. */
extern int bcm_vpls_bitmap_detach(
    int unit);

/* Enable or Disable the HTLS mode for a unit. */
extern int bcm_htls_mode_set(
    int unit, 
    int enable);

/* Get the HTLS mode for a unit. */
extern int bcm_htls_mode_get(
    int unit, 
    int *enable);

/* Set the default HTLS VC label for a port. */
extern int bcm_htls_vclabel_set(
    int unit, 
    bcm_port_t port, 
    uint32 vc_label);

/* Get the default HTLS VC label for a port. */
extern int bcm_htls_vclabel_get(
    int unit, 
    bcm_port_t port, 
    uint32 *vc_label);

/* Set the uplink HTLS VC label for a port. */
extern int bcm_htls_tunnel_label_set(
    int unit, 
    bcm_port_t port, 
    uint32 tunnel_label);

/* Get the uplink HTLS VC label for a port. */
extern int bcm_htls_tunnel_label_get(
    int unit, 
    bcm_port_t port, 
    uint32 *tunnel_label);

/* Set DA for HTLS on uplink port. */
extern int bcm_htls_uplink_da_set(
    int unit, 
    bcm_port_t port, 
    bcm_mac_t dest_mac);

/* Get DA for HTLS on uplink port. */
extern int bcm_htls_uplink_da_get(
    int unit, 
    bcm_port_t port, 
    bcm_mac_t dest_mac);

/* Set SA for HTLS on uplink port. */
extern int bcm_htls_uplink_sa_set(
    int unit, 
    bcm_port_t port, 
    bcm_mac_t src_mac);

/* Get SA for HTLS on uplink port. */
extern int bcm_htls_uplink_sa_get(
    int unit, 
    bcm_port_t port, 
    bcm_mac_t src_mac);

/* HTLS flags. */
#define BCM_HTLS_USE_EXP                0x00000001 
#define BCM_HTLS_UPLINK                 0x00000002 
#define BCM_HTLS_INSERT_TUNNEL_LABEL    0x00000004 
#define BCM_HTLS_CHECK_DA               0x00000008 
#define BCM_HTLS_DLF_AS_UNICAST         0x10       

/* Configure HTLS uplink properties. */
extern int bcm_htls_egress_port_set(
    int unit, 
    bcm_port_t port, 
    int ttl, 
    uint16 mmc_type, 
    uint32 flags);

/* Retrieve HTLS uplink properties. */
extern int bcm_htls_egress_port_get(
    int unit, 
    bcm_port_t port, 
    int *ttl, 
    uint16 *mmc_type, 
    uint32 *flags);

#endif /* __BCM_HTLS_H__ */
