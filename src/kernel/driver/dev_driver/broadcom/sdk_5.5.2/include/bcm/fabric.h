/*
 * $Id: fabric.h,v 1.2.6.3 Broadcom SDK $
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

#ifndef __BCM_FABRIC_H__
#define __BCM_FABRIC_H__

#include <bcm/types.h>
#include <bcm/port.h>

/* bcm_fabric_control_t */
typedef enum bcm_fabric_control_e {
    bcmFabricArbiterId,             /* Arbiter Identifier */
    bcmFabricActiveArbiterId,       /* Active Arbiter Identifier */
    bcmFabricArbiterConfig,         /* Arbiter NULL Grant Mechanism */
    bcmFabricMaximumFailedLinks,    /* Maximum Failed Links for load shared data
                                       plane redundancy mode */
    bcmFabricActiveId,              /* retreives actual(versus provisioned)
                                       Active Arbiter Identifier */
    bcmFabricRedundancyMode,        /* Fabric Redundancy Mode */
    bcmFabricMode,                  /* Fabric Mode (fabric, TME) */
    bcmFabricMcGroupSourceKnockout  /* Multicast Group Source Knockout
                                       Configuration. For get operation the arg
                                       parameter direction In/Out */
} bcm_fabric_control_t;

/* bcm_fabric_redundancy_mode_t */
typedef enum bcm_fabric_redundancy_mode_e {
    bcmFabricRedManual,     /* Manual Mode */
    bcmFabricRed1Plus1Both, /* 1+1 Control Plane and 1+1 Data Plane */
    bcmFabricRed1Plus1LS,   /* 1+1 Control Plane and Load Sharing Data Plane */
    bcmFabricRed1Plus1ELS,  /* 1+1 Control Planeand Enhanced Load Sharing Data
                               Plane */
    bcmFabricRedLS,         /* Load Sharing Data Plane */
    bcmFabricRedELS         /* Enhanced Load Sharing Data Plane */
} bcm_fabric_redundancy_mode_t;

/* Information passed back during callback of redundancy state change */
typedef struct bcm_fabric_control_redundancy_info_s {
    int active_arbiter_id;  /* Active Arbiter Identifier. */
    uint64 xbars;           /* xbar links that are being used. */
} bcm_fabric_control_redundancy_info_t;

/* BCM_FABRIC_DISTRIBUTION_* flags. */
#define BCM_FABRIC_DISTRIBUTION_WITH_ID 0x00000001 /* flag to create
                                                      distributionId that is
                                                      passed */

/* Reference bcm_fabric_control_t, bcmFabricMcGroupSourceKnockout type. */
#define BCM_FABRIC_MC_GROUP_SOURCE_KNOCKOUT_ENABLE 0x40000000 /* Indicates if source
                                                          knockout is enabled on
                                                          a multicast group */
#define BCM_FABRIC_MC_GROUP_MASK            0x3FFFFFFF /* multicast group mask */

/* bcm_fabric_control_redundancy_handler_t */
typedef void (*bcm_fabric_control_redundancy_handler_t)(
    int unit, 
    bcm_fabric_control_redundancy_info_t *redundancy_info);

/* Initialize the BCM Fabric subsystem. */
extern int bcm_fabric_init(
    int unit);

/* defines connection setup between two nodes. */
extern int bcm_fabric_crossbar_connection_set(
    int unit, 
    int xbar, 
    int src_modid, 
    bcm_port_t src_xbport, 
    int dst_modid, 
    bcm_port_t dst_xbport);

/* retreives connection setup between two nodes. */
extern int bcm_fabric_crossbar_connection_get(
    int unit, 
    int xbar, 
    int src_modid, 
    bcm_port_t src_xbport, 
    int dst_modid, 
    bcm_port_t *dst_xbport);

/* defines SFI link remap. */
extern int bcm_fabric_crossbar_mapping_set(
    int unit, 
    int modid, 
    int switch_fabric_arbiter_id, 
    int xbar, 
    bcm_port_t port);

/* retreive SFI link remap. */
extern int bcm_fabric_crossbar_mapping_get(
    int unit, 
    int modid, 
    int switch_fabric_arbiter_id, 
    int xbar, 
    bcm_port_t *port);

/* configure Link enable. */
extern int bcm_fabric_crossbar_enable_set(
    int unit, 
    uint64 xbars);

/* retreive Link enable. */
extern int bcm_fabric_crossbar_enable_get(
    int unit, 
    uint64 *xbars);

/* retreive runtime Link enable configuration. */
extern int bcm_fabric_crossbar_status_get(
    int unit, 
    uint64 *xbars);

/* set packet length adjustment. */
extern int bcm_fabric_packet_adjust_set(
    int unit, 
    int pkt_adjust_selector, 
    int pkt_adjust_len);

/* retreive packet length adjustment. */
extern int bcm_fabric_packet_adjust_get(
    int unit, 
    int pkt_adjust_selector, 
    int *pkt_adjust_len);

/* set failover/APS configuration. */
extern int bcm_fabric_port_failover_set(
    int unit, 
    bcm_gport_t port, 
    bcm_failover_t failover_id, 
    bcm_gport_t failover_port);

/* retreive failover/APS configuration. */
extern int bcm_fabric_port_failover_get(
    int unit, 
    bcm_gport_t port, 
    bcm_failover_t *failover_id, 
    bcm_gport_t *failover_port);

/* set fabric control attributes. */
extern int bcm_fabric_control_set(
    int unit, 
    bcm_fabric_control_t type, 
    int arg);

/* get fabric control attributes. */
extern int bcm_fabric_control_get(
    int unit, 
    bcm_fabric_control_t type, 
    int *arg);

/* Register user callback for redundancy state changes. */
extern int bcm_fabric_control_redundancy_register(
    int unit, 
    bcm_fabric_control_redundancy_handler_t f);

/* Unregister user callback for redundancy state changes. */
extern int bcm_fabric_control_redundancy_unregister(
    int unit, 
    bcm_fabric_control_redundancy_handler_t f);

/* Create Distribution Group. Reference BCM_FABRIC_DISTRIBUTION_* flags. */
extern int bcm_fabric_distribution_create(
    int unit, 
    uint32 flags, 
    bcm_fabric_distribution_t *ds_id);

/* Destroy Distribution Group. */
extern int bcm_fabric_distribution_destroy(
    int unit, 
    bcm_fabric_distribution_t ds_id);

/* Configure Distribution Group. */
extern int bcm_fabric_distribution_set(
    int unit, 
    bcm_fabric_distribution_t ds_id, 
    int modid_count, 
    int *dist_modids);

/* Retreive Distribution Group. */
extern int bcm_fabric_distribution_get(
    int unit, 
    bcm_fabric_distribution_t ds_id, 
    int max_count, 
    int *dist_modids, 
    int *count);

#endif /* __BCM_FABRIC_H__ */
