/*
 * $Id: stack.h,v 1.21.6.6 Broadcom SDK $
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

#ifndef __BCM_STACK_H__
#define __BCM_STACK_H__

#include <bcm/types.h>

#define BCM_STK_MAX_MODULES     (72)       /* Maximum number of modules in
                                              stack. */
#define BCM_MODULE_FABRIC_BASE  (10000)    /* Base for SBX Node id. */
#define BCM_STK_MOD_IS_NODE(modid)  (((modid) >= BCM_MODULE_FABRIC_BASE) && ((modid) < (BCM_MODULE_FABRIC_BASE+BCM_STK_MAX_MODULES))) /* Modid to Nodeid mapping. */
#define BCM_STK_MOD_TO_NODE(modid)  ((modid) - BCM_MODULE_FABRIC_BASE) 
#define BCM_STK_NODE_TO_MOD(nodeid)  ((nodeid) + BCM_MODULE_FABRIC_BASE) 

typedef enum bcm_module_protocol_e {
    bcmModuleProtocolNone = 1, 
    bcmModuleProtocol1, 
    bcmModuleProtocol2, 
    bcmModuleProtocol3 
} bcm_module_protocol_t;

/* Initialize the Stack Control subsystem. */
extern int bcm_stk_init(
    int unit);

/* Gets the list of ports currently in SL stack mode. */
extern int bcm_stk_pbmp_get(
    int unit, 
    bcm_pbmp_t *cur_pbm, 
    bcm_pbmp_t *inactive_pbm);

/* Set/Get SL stack flags for a port. */
extern int bcm_stk_port_set(
    int unit, 
    bcm_port_t port, 
    uint32 flags);

/* Set/Get SL stack flags for a port. */
extern int bcm_stk_port_get(
    int unit, 
    bcm_port_t port, 
    uint32 *flags);

/* bcm_stk_cb_f */
typedef void (*bcm_stk_cb_f)(
    int unit, 
    bcm_port_t port, 
    uint32 flags, 
    void *cookie);

/* Register a function for stack port updates. */
extern int bcm_stk_update_callback_register(
    int unit, 
    bcm_stk_cb_f cb, 
    void *cookie);

/* Unregister a function for stack port updates. */
extern int bcm_stk_update_callback_unregister(
    int unit, 
    bcm_stk_cb_f cb, 
    void *cookie);

/* Flags for bcm_stk_port_set/get. */
#define BCM_STK_CAPABLE         0x00000001 /* The port is stack capable, but may
                                              not be stacked currently (e.g.
                                              Dynamic SL front panel). */
#define BCM_STK_ENABLE          0x00000002 /* The port is in stacking mode. */
#define BCM_STK_INACTIVE        0x00000004 /* Explicitly set inactive to avoid
                                              undirected traffic to flow on this
                                              link. */
#define BCM_STK_DUPLEX          0x00000008 /* This is a duplex connection. */
#define BCM_STK_SIMPLEX         0x00000010 /* This is a simplex connection
                                              (exclusive to _DUPLEX) */
#define BCM_STK_NONE            0x00000020 /* Not a stackable port (currently
                                              ignored). */
#define BCM_STK_SL              0x00000040 /* Port is an SL (front panel) stack
                                              port (currently ignored). */
#define BCM_STK_HG              0x00000080 /* Port is a HiGig stack port
                                              (currently ignored). */
#define BCM_STK_INTERNAL        0x00000100 /* Port is an on-board device
                                              connection (set only; currently
                                              ignored). */
#define BCM_STK_NO_LINK         0x00000200 /* Port does not have link. Not
                                              recorded; provided for callbacks.
                                              (set only; currently ignored). */
#define BCM_STK_CUT             0x00000400 /* Port is a "cut" port that blocks
                                              multicast and broadcast traffic.
                                              (currently ignored). */
#define BCM_STK_FLAGS_MASK      0x000007ff 

#define BCM_STK_FLAGS_STR       \
{ \
    "capable", \
    "enable", \
    "inactive", \
    "duplex", \
    "simplex", \
    "none", \
    "sl", \
    "hg", \
    "internal", \
    "no_link", \
    "cut", \
    "" \
} 

/* bcm_stk_flags_str */
extern char *bcm_stk_flags_str[];

/* 
 * Pass this as the port parameter to set/get to use the unique IPIC_PORT
 * if present.
 */
#define BCM_STK_USE_HG_IF       -1         

/* Set/Get SL stack mode status. */
extern int bcm_stk_mode_set(
    int unit, 
    uint32 flags);

/* Set/Get SL stack mode status. */
extern int bcm_stk_mode_get(
    int unit, 
    uint32 *flags);

/* Get or set the module ID of the local device. */
extern int bcm_stk_my_modid_set(
    int unit, 
    int my_modid);

/* Get or set the module ID of the local device. */
extern int bcm_stk_my_modid_get(
    int unit, 
    int *my_modid);

/* Get or set the module ID of the local device. */
extern int bcm_stk_modid_set(
    int unit, 
    int modid);

/* Get or set the module ID of the local device. */
extern int bcm_stk_modid_get(
    int unit, 
    int *modid);

/* Number of module identifiers used by device. */
extern int bcm_stk_modid_count(
    int unit, 
    int *num_modid);

/* Control module steering. */
extern int bcm_stk_modport_set(
    int unit, 
    int modid, 
    int port);

/* Control module steering. */
extern int bcm_stk_modport_get(
    int unit, 
    int modid, 
    int *port);

/* Clear module steering. */
extern int bcm_stk_modport_clear(
    int unit, 
    int modid);

/* Clear module steering. */
extern int bcm_stk_modport_clear_all(
    int unit);

/* Add or delete more than one path for a given destination module. */
extern int bcm_stk_modport_add(
    int unit, 
    int modid, 
    bcm_port_t port);

/* Add or delete more than one path for a given destination module. */
extern int bcm_stk_modport_delete(
    int unit, 
    int modid, 
    bcm_port_t port);

/* Set, get, or delete Fabric unicast table entries. */
extern int bcm_stk_ucbitmap_set(
    int unit, 
    int port, 
    int modid, 
    bcm_pbmp_t pbmp);

/* Set, get, or delete Fabric unicast table entries. */
extern int bcm_stk_ucbitmap_get(
    int unit, 
    int port, 
    int modid, 
    bcm_pbmp_t *pbmp);

/* Set, get, or delete Fabric unicast table entries. */
extern int bcm_stk_ucbitmap_del(
    int unit, 
    bcm_port_t port, 
    int modid, 
    bcm_pbmp_t pbmp);

/* Set or get a fabric mapping between fabric and local space. */
extern int bcm_stk_fmod_lmod_mapping_set(
    int unit, 
    bcm_port_t port, 
    bcm_module_t fmod, 
    bcm_module_t lmod);

/* Set or get a fabric mapping between fabric and local space. */
extern int bcm_stk_fmod_lmod_mapping_get(
    int unit, 
    bcm_port_t port, 
    bcm_module_t *fmod, 
    bcm_module_t *lmod);

/* Set or get a fabric mapping between fabric and switch space. */
extern int bcm_stk_fmod_smod_mapping_set(
    int unit, 
    bcm_port_t port, 
    bcm_module_t fmod, 
    bcm_module_t smod, 
    bcm_port_t sport, 
    uint32 nports);

/* Set or get a fabric mapping between fabric and switch space. */
extern int bcm_stk_fmod_smod_mapping_get(
    int unit, 
    bcm_port_t port, 
    bcm_module_t fmod, 
    bcm_module_t *smod, 
    bcm_port_t *sport, 
    uint32 *nports);

/* Assign or get fabric port to a module mapping group. */
extern int bcm_stk_port_modmap_group_set(
    int unit, 
    bcm_port_t port, 
    int group);

/* Assign or get fabric port to a module mapping group. */
extern int bcm_stk_port_modmap_group_get(
    int unit, 
    bcm_port_t port, 
    int *group);

/* Retrieve the maximum module mapping group on a fabric. */
extern int bcm_stk_port_modmap_group_max_get(
    int unit, 
    int *max_group);

/* Enable/Disable or get module mapping on a fabric port. */
extern int bcm_stk_modmap_enable_set(
    int unit, 
    bcm_port_t port, 
    int enable);

/* Enable/Disable or get module mapping on a fabric port. */
extern int bcm_stk_modmap_enable_get(
    int unit, 
    bcm_port_t port, 
    int *enable);

/* Switch module mapping. */
#define BCM_STK_MODMAP_SET      1          /* Global to local. */
#define BCM_STK_MODMAP_GET      2          /* Local to global. */

/* bcm_stk_modmap_cb_t */
typedef int (*bcm_stk_modmap_cb_t)(
    int unit, 
    int setget, 
    bcm_module_t mod_in, 
    bcm_port_t port_in, 
    bcm_module_t *mod_out, 
    bcm_port_t *port_out);

/* Register a Module Mapping callback. */
extern int bcm_stk_modmap_register(
    int unit, 
    bcm_stk_modmap_cb_t func);

/* Register a Module Mapping callback. */
extern int bcm_stk_modmap_unregister(
    int unit);

/* Map or unmap a module identifier. */
extern int bcm_stk_modmap_map(
    int unit, 
    int setget, 
    bcm_module_t mod_in, 
    bcm_port_t port_in, 
    bcm_module_t *mod_out, 
    bcm_port_t *port_out);

/* Set or get SL stacking simplex mode hop count. */
extern int bcm_stk_sl_simplex_count_set(
    int unit, 
    int count);

/* Set or get SL stacking simplex mode hop count. */
extern int bcm_stk_sl_simplex_count_get(
    int unit, 
    int *count);

/* 
 * Enable or disable arbitration and failover/redundancy algorithm for
 * the module
 */
extern int bcm_stk_module_enable(
    int unit, 
    bcm_module_t modid, 
    int nports, 
    int enable);

/* Set module type */
extern int bcm_stk_module_protocol_set(
    int unit, 
    bcm_module_t modid, 
    bcm_module_protocol_t protocol);

/* Get module type */
extern int bcm_stk_module_protocol_get(
    int unit, 
    bcm_module_t modid, 
    bcm_module_protocol_t *protocol);

/* Port map set */
extern int bcm_stk_fabric_map_set(
    int unit, 
    bcm_gport_t switch_port, 
    bcm_gport_t fabric_port);

/* Port map get */
extern int bcm_stk_fabric_map_get(
    int unit, 
    bcm_gport_t switch_port, 
    bcm_gport_t *fabric_port);

#endif /* __BCM_STACK_H__ */
