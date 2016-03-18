/*
 * $Id: vlan.h,v 1.67.2.9 Broadcom SDK $
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

#ifndef __BCM_VLAN_H__
#define __BCM_VLAN_H__

#include <bcm/types.h>
#include <bcm/policer.h>
#include <bcm/port.h>

#define BCM_VLAN_VID_DISABLE    BCM_VLAN_INVALID 

/* Initialize a VLAN data information structure. */
typedef struct bcm_vlan_data_s {
    bcm_vlan_t vlan_tag; 
    bcm_pbmp_t port_bitmap; 
    bcm_pbmp_t ut_port_bitmap; 
} bcm_vlan_data_t;

/* Backward compatibility: Do not use. */
typedef bcm_vlan_data_t vlan_data_t;

/* Initialize the VLAN module. */
extern int bcm_vlan_init(
    int unit);

/* Allocate and configure a VLAN on the BCM device. */
extern int bcm_vlan_create(
    int unit, 
    bcm_vlan_t vid);

/* Deallocate VLAN from the BCM device. */
extern int bcm_vlan_destroy(
    int unit, 
    bcm_vlan_t vid);

/* Destroy all VLANs except the default VLAN. */
extern int bcm_vlan_destroy_all(
    int unit);

/* Add ports to the specified vlan. */
extern int bcm_vlan_port_add(
    int unit, 
    bcm_vlan_t vid, 
    bcm_pbmp_t pbmp, 
    bcm_pbmp_t ubmp);

/* Remove ports from a specified vlan. */
extern int bcm_vlan_port_remove(
    int unit, 
    bcm_vlan_t vid, 
    bcm_pbmp_t pbmp);

/* Retrieves a list of the member ports of an existing VLAN. */
extern int bcm_vlan_port_get(
    int unit, 
    bcm_vlan_t vid, 
    bcm_pbmp_t *pbmp, 
    bcm_pbmp_t *ubmp);

/* 
 * Returns an array of defined VLANs and their port bitmaps. If by pbmp,
 * only VLANs which contain at least one of the specified ports are
 * listed.
 */
extern int bcm_vlan_list(
    int unit, 
    bcm_vlan_data_t **listp, 
    int *countp);

/* 
 * Returns an array of defined VLANs and their port bitmaps. If by pbmp,
 * only VLANs which contain at least one of the specified ports are
 * listed.
 */
extern int bcm_vlan_list_by_pbmp(
    int unit, 
    bcm_pbmp_t ports, 
    bcm_vlan_data_t **listp, 
    int *countp);

/* Destroy a list returned by bcm_vlan_list. */
extern int bcm_vlan_list_destroy(
    int unit, 
    bcm_vlan_data_t *list, 
    int count);

/* Get the default VLAN ID. */
extern int bcm_vlan_default_get(
    int unit, 
    bcm_vlan_t *vid_ptr);

/* Set the default VLAN ID. */
extern int bcm_vlan_default_set(
    int unit, 
    bcm_vlan_t vid);

/* Retrieve the VTABLE STG for the specified vlan. */
extern int bcm_vlan_stg_get(
    int unit, 
    bcm_vlan_t vid, 
    bcm_stg_t *stg_ptr);

/* Update the VTABLE STG for the specified vlan. */
extern int bcm_vlan_stg_set(
    int unit, 
    bcm_vlan_t vid, 
    bcm_stg_t stg);

/* 
 * Set/get the spanning tree state for a port in the whole spanning tree
 * group that contains the specified VLAN.
 */
extern int bcm_vlan_stp_get(
    int unit, 
    bcm_vlan_t vid, 
    bcm_port_t port, 
    int *stp_state);

/* 
 * Set/get the spanning tree state for a port in the whole spanning tree
 * group that contains the specified VLAN.
 */
extern int bcm_vlan_stp_set(
    int unit, 
    bcm_vlan_t vid, 
    bcm_port_t port, 
    int stp_state);

/* VLAN Action definitions. */
typedef enum bcm_vlan_action_e {
    bcmVlanActionNone,      /* Do not modify. */
    bcmVlanActionAdd,       /* Add VLAN tag. */
    bcmVlanActionReplace,   /* Replace VLAN tag. */
    bcmVlanActionDelete     /* Delete VLAN tag. */
} bcm_vlan_action_t;

/* Initialize a VLAN tag action set structure. */
typedef struct bcm_vlan_action_set_s {
    bcm_vlan_t new_outer_vlan;          /* New outer VLAN for Add/Replace
                                           actions. */
    bcm_vlan_t new_inner_vlan;          /* New inner VLAN for Add/Replace
                                           actions. */
    int priority;                       /* Internal or packet priority. */
    bcm_vlan_action_t dt_outer;         /* Outer-tag action for double-tagged
                                           packets. */
    bcm_vlan_action_t dt_outer_prio;    /* Outer-priority-tag actionfor
                                           double-tagged packets. */
    bcm_vlan_action_t dt_inner;         /* Inner-tag actionfor double-tagged
                                           packets. */
    bcm_vlan_action_t dt_inner_prio;    /* Inner-priority-tag action for
                                           double-tagged packets. */
    bcm_vlan_action_t ot_outer;         /* Outer-tag action for
                                           single-outer-tagged packets. */
    bcm_vlan_action_t ot_outer_prio;    /* Outer-priority-tag action for
                                           single-outer-tagged packets. */
    bcm_vlan_action_t ot_inner;         /* Inner-tag action for
                                           single-outer-tagged packets. */
    bcm_vlan_action_t it_outer;         /* Outer-tag action for
                                           single-inner-tagged packets. */
    bcm_vlan_action_t it_inner;         /* Inner-tag action for
                                           single-inner-tagged packets. */
    bcm_vlan_action_t it_inner_prio;    /* Inner-priority-tag action for
                                           single-inner-tagged packets. */
    bcm_vlan_action_t ut_outer;         /* Outer-tag action for untagged
                                           packets. */
    bcm_vlan_action_t ut_inner;         /* Inner-tag action for untagged
                                           packets. */
} bcm_vlan_action_set_t;

/* Initialize a VLAN tag action set structure. */
extern void bcm_vlan_action_set_t_init(
    bcm_vlan_action_set_t *action);

/* Get or set the port's default VLAN tag actions. */
extern int bcm_vlan_port_default_action_get(
    int unit, 
    bcm_port_t port, 
    bcm_vlan_action_set_t *action);

/* Get or set the port's default VLAN tag actions. */
extern int bcm_vlan_port_default_action_set(
    int unit, 
    bcm_port_t port, 
    bcm_vlan_action_set_t *action);

/* Get or set the egress default VLAN tag actions. */
extern int bcm_vlan_port_egress_default_action_get(
    int unit, 
    bcm_port_t port, 
    bcm_vlan_action_set_t *action);

/* Get or set the egress default VLAN tag actions. */
extern int bcm_vlan_port_egress_default_action_set(
    int unit, 
    bcm_port_t port, 
    bcm_vlan_action_set_t *action);

/* 
 * Add protocol based VLAN with specified action. If the entry already
 * exists, update the action.
 */
extern int bcm_vlan_port_protocol_action_add(
    int unit, 
    bcm_port_t port, 
    bcm_port_frametype_t frame, 
    bcm_port_ethertype_t ether, 
    bcm_vlan_action_set_t *action);

/* 
 * Add an association from MAC address to VLAN to use for assigning a
 * VLAN tag to untagged packets.
 */
extern int bcm_vlan_mac_add(
    int unit, 
    bcm_mac_t mac, 
    bcm_vlan_t vid, 
    int prio);

/* Remove an association from MAC address to VLAN. */
extern int bcm_vlan_mac_delete(
    int unit, 
    bcm_mac_t mac);

/* Remove all associations from MAC addresses to VLAN. */
extern int bcm_vlan_mac_delete_all(
    int unit);

/* 
 * Add an association from MAC address to VLAN actions to use for
 * assigning VLAN tag actions to untagged packets.
 */
extern int bcm_vlan_mac_action_add(
    int unit, 
    bcm_mac_t mac, 
    bcm_vlan_action_set_t *action);

/* 
 * VLAN translation selection
 * 
 * For chips supporting VLAN translation on a HiGig port, use the
 * following to construct a value to pass to
 * bcm_vlan_translate_add/delete routines as "port."
 */
#define BCM_VLAN_TRANSLATE_PORTMOD_MOD_SHIFT 16         
#define BCM_VLAN_TRANSLATE_PORTMOD_PORT_MASK \
    ((1 << BCM_VLAN_TRANSLATE_PORTMOD_MOD_SHIFT) - 1) 
#define BCM_VLAN_TRANSLATE_PORTMOD(port, mod_id)  \
    ((port) | (((mod_id) + 1) << BCM_VLAN_TRANSLATE_PORTMOD_MOD_SHIFT)) 

/* Add an entry to the VLAN Translation table. */
extern int bcm_vlan_translate_add(
    int unit, 
    int port, 
    bcm_vlan_t old_vid, 
    bcm_vlan_t new_vid, 
    int prio);

/* Add an entry to the VLAN Translation table. */
extern int bcm_vlan_translate_get(
    int unit, 
    int port, 
    bcm_vlan_t old_vid, 
    bcm_vlan_t *new_vid, 
    int *prio);

/* Delete an entry or entries from the VLAN Translation table. */
extern int bcm_vlan_translate_delete(
    int unit, 
    int port, 
    bcm_vlan_t old_vid);

/* Remove all entries from the VLAN Translation table. */
extern int bcm_vlan_translate_delete_all(
    int unit);

/* Key types for vlan translation lookup. */
typedef enum bcm_vlan_translate_key_e {
    bcmVlanTranslateKeyInvalid,         /* Invalid Key Type. */
    bcmVlanTranslateKeyDouble,          /* Use O-VID[11:0] and I-VID[11:0]. */
    bcmVlanTranslateKeyOuter,           /* Use O-VID[11:0] */
    bcmVlanTranslateKeyInner,           /* Use I-VID[11:0] */
    bcmVlanTranslateKeyOuterTag,        /* Use O-TAG[15:0] */
    bcmVlanTranslateKeyInnerTag,        /* Use I-TAG[15:0] */
    bcmVlanTranslateKeyPortDouble,      /* Use Port, O-VID[11:0] and
                                           I-VID[11:0]. */
    bcmVlanTranslateKeyPortOuter,       /* Use Port, O-VID[11:0] */
    bcmVlanTranslateKeyPortInner,       /* Use Port, I-VID[11:0] */
    bcmVlanTranslateKeyPortOuterTag,    /* Use Port, O-TAG[15:0] */
    bcmVlanTranslateKeyPortInnerTag     /* Use Port, I-TAG[15:0] */
} bcm_vlan_translate_key_t;

/* Add an entry to the VLAN Translation table and assign VLAN actions. */
extern int bcm_vlan_translate_action_add(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_translate_key_t key_type, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_vlan_action_set_t *action);

/* Get an entry to the VLAN Translation table and assign VLAN actions. */
extern int bcm_vlan_translate_action_get(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_translate_key_t key_type, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_vlan_action_set_t *action);

/* Delete an entry from the VLAN Translation table. */
extern int bcm_vlan_translate_action_delete(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_translate_key_t key_type, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan);

/* Add an entry to the egress VLAN Translation table. */
extern int bcm_vlan_translate_egress_add(
    int unit, 
    int port, 
    bcm_vlan_t old_vid, 
    bcm_vlan_t new_vid, 
    int prio);

/* Get an entry to the egress VLAN Translation table. */
extern int bcm_vlan_translate_egress_get(
    int unit, 
    int port, 
    bcm_vlan_t old_vid, 
    bcm_vlan_t *new_vid, 
    int *prio);

/* Remove an entry or entries from the VLAN egress Translation table. */
extern int bcm_vlan_translate_egress_delete(
    int unit, 
    int port, 
    bcm_vlan_t old_vid);

/* Remove all entries from the egress VLAN Translation table. */
extern int bcm_vlan_translate_egress_delete_all(
    int unit);

/* 
 * Add an entry to the egress VLAN Translation table and assign VLAN
 * actions.
 */
extern int bcm_vlan_translate_egress_action_add(
    int unit, 
    int port_class, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_vlan_action_set_t *action);

/* 
 * Get an entry to the egress VLAN Translation table and assign VLAN
 * actions.
 */
extern int bcm_vlan_translate_egress_action_get(
    int unit, 
    int port_class, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_vlan_action_set_t *action);

/* Delete an entry from the egress VLAN Translation table. */
extern int bcm_vlan_translate_egress_action_delete(
    int unit, 
    int port_class, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan);

/* Add an entry to the VLAN Translation table for double-tagging. */
extern int bcm_vlan_dtag_add(
    int unit, 
    int port, 
    bcm_vlan_t old_vid, 
    bcm_vlan_t new_vid, 
    int prio);

/* Get an entry to the VLAN Translation table for double-tagging. */
extern int bcm_vlan_dtag_get(
    int unit, 
    int port, 
    bcm_vlan_t old_vid, 
    bcm_vlan_t *new_vid, 
    int *prio);

/* Remove an entry from the VLAN Translation table for double-tagging. */
extern int bcm_vlan_dtag_delete(
    int unit, 
    int port, 
    bcm_vlan_t old_vid);

/* Remove all entries from the VLAN Translation table for double-tagging. */
extern int bcm_vlan_dtag_delete_all(
    int unit);

/* Add a VLAN range to the VLAN Translation table. */
extern int bcm_vlan_translate_range_add(
    int unit, 
    int port, 
    bcm_vlan_t old_vid_low, 
    bcm_vlan_t old_vid_high, 
    bcm_vlan_t new_vid, 
    int int_prio);

/* Get a VLAN range to the VLAN Translation table. */
extern int bcm_vlan_translate_range_get(
    int unit, 
    int port, 
    bcm_vlan_t old_vid_low, 
    bcm_vlan_t old_vid_high, 
    bcm_vlan_t *new_vid, 
    int *int_prio);

/* Delete a VLAN range from the VLAN Translation table. */
extern int bcm_vlan_translate_range_delete(
    int unit, 
    int port, 
    bcm_vlan_t old_vid_low, 
    bcm_vlan_t old_vid_high);

/* Remove all VLAN ranges from the VLAN Translation table. */
extern int bcm_vlan_translate_range_delete_all(
    int unit);

/* Add VLAN range to the VLAN Translation table for double-tagging. */
extern int bcm_vlan_dtag_range_add(
    int unit, 
    int port, 
    bcm_vlan_t old_vid_low, 
    bcm_vlan_t old_vid_high, 
    bcm_vlan_t new_vid, 
    int int_prio);

/* Get VLAN range to the VLAN Translation table for double-tagging. */
extern int bcm_vlan_dtag_range_get(
    int unit, 
    int port, 
    bcm_vlan_t old_vid_low, 
    bcm_vlan_t old_vid_high, 
    bcm_vlan_t *new_vid, 
    int *prio);

/* 
 * Remove a VLAN range from the VLAN Translation table for
 * double-tagging.
 */
extern int bcm_vlan_dtag_range_delete(
    int unit, 
    int port, 
    bcm_vlan_t old_vid_low, 
    bcm_vlan_t old_vid_high);

/* 
 * Remove all VLAN ranges from the VLAN Translation table for
 * double-tagging.
 */
extern int bcm_vlan_dtag_range_delete_all(
    int unit);

/* bcm_vlan_translate_action_range_add */
extern int bcm_vlan_translate_action_range_add(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t outer_vlan_low, 
    bcm_vlan_t outer_vlan_high, 
    bcm_vlan_t inner_vlan_low, 
    bcm_vlan_t inner_vlan_high, 
    bcm_vlan_action_set_t *action);

/* bcm_vlan_translate_action_range_get */
extern int bcm_vlan_translate_action_range_get(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t outer_vlan_low, 
    bcm_vlan_t outer_vlan_high, 
    bcm_vlan_t inner_vlan_low, 
    bcm_vlan_t inner_vlan_high, 
    bcm_vlan_action_set_t *action);

/* bcm_vlan_translate_action_range_delete */
extern int bcm_vlan_translate_action_range_delete(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t outer_vlan_low, 
    bcm_vlan_t outer_vlan_high, 
    bcm_vlan_t inner_vlan_low, 
    bcm_vlan_t inner_vlan_high);

/* bcm_vlan_translate_action_range_delete_all */
extern int bcm_vlan_translate_action_range_delete_all(
    int unit);

/* vlan_translate_egress_action_traverse_cb */
typedef int (*bcm_vlan_translate_egress_action_traverse_cb)(
    int unit, 
    bcm_gport_t port_class, 
    bcm_vlan_translate_key_t key_type, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_vlan_action_set_t *action, 
    void *user_data);

/* Traverse vlan translate egress table */
extern int bcm_vlan_translate_egress_action_traverse(
    int unit, 
    bcm_vlan_translate_egress_action_traverse_cb cb, 
    void *user_data);

/* vlan_translate_action_traverse_cb */
typedef int (*bcm_vlan_translate_action_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_translate_key_t key_type, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_vlan_action_set_t *action, 
    void *user_data);

/* Traverse vlan translate table */
extern int bcm_vlan_translate_action_traverse(
    int unit, 
    bcm_vlan_translate_action_traverse_cb cb, 
    void *user_data);

/* vlan_translate_traverse_cb */
typedef int (*bcm_vlan_translate_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t old_vlan, 
    bcm_vlan_t new_vlan, 
    int prio, 
    void *user_data);

/* Traverse vlan translate table */
extern int bcm_vlan_translate_traverse(
    int unit, 
    bcm_vlan_translate_traverse_cb cb, 
    void *user_data);

/* vlan_translate_egress_traverse_cb */
typedef int (*bcm_vlan_translate_egress_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t old_vlan, 
    bcm_vlan_t new_vlan, 
    int prio, 
    void *user_data);

/* Traverse vlan egress translate table */
extern int bcm_vlan_translate_egress_traverse(
    int unit, 
    bcm_vlan_translate_egress_traverse_cb cb, 
    void *user_data);

/* vlan_dtag_traverse_cb */
typedef int (*bcm_vlan_dtag_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t old_vlan, 
    bcm_vlan_t new_vlan, 
    int prio, 
    void *user_data);

/* Traverse vlan translate table */
extern int bcm_vlan_dtag_traverse(
    int unit, 
    bcm_vlan_dtag_traverse_cb cb, 
    void *user_data);

/* vlan_translate_action_range_traverse_cb */
typedef int (*bcm_vlan_translate_action_range_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t outer_vlan_low, 
    bcm_vlan_t outer_vlan_high, 
    bcm_vlan_t inner_vlan_low, 
    bcm_vlan_t inner_vlan_high, 
    bcm_vlan_action_set_t *action, 
    void *user_data);

/* Traverse vlan translate range table */
extern int bcm_vlan_translate_action_range_traverse(
    int unit, 
    bcm_vlan_translate_action_range_traverse_cb cb, 
    void *user_data);

/* bcm_vlan_translate_range_traverse_cb */
typedef int (*bcm_vlan_translate_range_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t old_vlan_low, 
    bcm_vlan_t old_vlan_high, 
    bcm_vlan_t new_vlan, 
    int prio, 
    void *user_data);

/* Traverse vlan translate range table */
extern int bcm_vlan_translate_range_traverse(
    int unit, 
    bcm_vlan_translate_range_traverse_cb cb, 
    void *user_data);

/* bcm_vlan_dtag_range_traverse_cb */
typedef int (*bcm_vlan_dtag_range_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    bcm_vlan_t old_vlan_low, 
    bcm_vlan_t old_vlan_high, 
    bcm_vlan_t new_vlan, 
    int prio, 
    void *user_data);

/* Traverse vlan translate range table */
extern int bcm_vlan_dtag_range_traverse(
    int unit, 
    bcm_vlan_dtag_range_traverse_cb cb, 
    void *user_data);

/* 
 * Add an association from IP subnet to VLAN to use for assigning a VLAN
 * tag to untagged packets.
 */
extern int bcm_vlan_ip4_add(
    int unit, 
    bcm_ip_t ipaddr, 
    bcm_ip_t netmask, 
    bcm_vlan_t vid, 
    int prio);

/* Remove an association from IP subnet to VLAN. */
extern int bcm_vlan_ip4_delete(
    int unit, 
    bcm_ip_t ipaddr, 
    bcm_ip_t netmask);

/* Remove all associations from IP subnet to VLAN. */
extern int bcm_vlan_ip4_delete_all(
    int unit);

/* Flags for the unified IPv4/IPv6 bcm_vlan_ip_t type. */
#define BCM_VLAN_SUBNET_IP6     (1 << 14)  

/* Unified IPv4/IPv6 type. */
typedef struct bcm_vlan_ip_s {
    uint32 flags; 
    bcm_ip_t ip4; 
    bcm_ip_t mask; 
    bcm_ip6_t ip6; 
    int prefix; 
    bcm_vlan_t vid; 
    int prio; 
} bcm_vlan_ip_t;

/* Initialize the bcm_vlan_ip_t structure. */
extern void bcm_vlan_ip_t_init(
    bcm_vlan_ip_t *vlan_ip);

/* 
 * Add an association from IP subnet to VLAN to use for assigning a VLAN
 * tag to untagged packets.
 */
extern int bcm_vlan_ip_add(
    int unit, 
    bcm_vlan_ip_t *vlan_ip);

/* Remove an association from IP subnet to VLAN. */
extern int bcm_vlan_ip_delete(
    int unit, 
    bcm_vlan_ip_t *vlan_ip);

/* Remove all associations from IP subnet to VLAN. */
extern int bcm_vlan_ip_delete_all(
    int unit);

/* 
 * Add an association from IP subnet to VLAN actions to use for assigning
 * VLAN tag actions to untagged packets.
 */
extern int bcm_vlan_ip_action_add(
    int unit, 
    bcm_vlan_ip_t *vlan_ip, 
    bcm_vlan_action_set_t *action);

/* bcm_vlan_control_t */
typedef enum bcm_vlan_control_e {
    bcmVlanDropUnknown,             /* Drop unknown/FFF VLAN pkts or send to
                                       CPU. */
    bcmVlanPreferIP4,               /* Prefer IP Subnet VLAN selection. */
    bcmVlanPreferMAC,               /* Prefer MAC VLAN selection. */
    bcmVlanShared,                  /* Shared vs. Independent VLAN Learning. */
    bcmVlanSharedID,                /* Shared Learning VLAN ID. */
    bcmVlanTranslate,               /* Chip is in VLAN translate mode. */
    bcmVlanIgnorePktTag,            /* Ignore Packet VLAN tag. Treat packet as
                                       untagged. */
    bcmVlanPreferEgressTranslate    /* Do egress translation even if ingress FP
                                       changes the outer/inner VLAN tag(s). */
} bcm_vlan_control_t;

/* Set/get miscellaneous VLAN-specific chip options. */
extern int bcm_vlan_control_get(
    int unit, 
    bcm_vlan_control_t type, 
    int *arg);

/* Set/get miscellaneous VLAN-specific chip options. */
extern int bcm_vlan_control_set(
    int unit, 
    bcm_vlan_control_t type, 
    int arg);

/* bcm_vlan_control_port_t */
typedef enum bcm_vlan_control_port_e {
    bcmVlanPortPreferIP4, 
    bcmVlanPortPreferMAC, 
    bcmVlanTranslateIngressEnable, 
    bcmVlanTranslateIngressMissDrop, 
    bcmVlanTranslateEgressEnable, 
    bcmVlanTranslateEgressMissDrop, 
    bcmVlanTranslateEgressMissUntaggedDrop, 
    bcmVlanLookupMACEnable, 
    bcmVlanLookupIPEnable, 
    bcmVlanPortUseInnerPri, 
    bcmVlanPortUseOuterPri, 
    bcmVlanPortVerifyOuterTpid, 
    bcmVlanPortOuterTpidSelect, 
    bcmVlanPortTranslateKeyFirst, 
    bcmVlanPortTranslateKeySecond, 
    bcmVlanTranslateEgressMissUntag 
} bcm_vlan_control_port_t;

/* Selectors for bcmVlanPortOuterTpidSelect */
#define BCM_PORT_OUTER_TPID     0          /* Use egress port TPID as outer
                                              TPID. */
#define BCM_VLAN_OUTER_TPID     1          /* Use VLAN TPID as outer TPID. */

/* Set/get miscellaneous port-specific VLAN options. */
extern int bcm_vlan_control_port_get(
    int unit, 
    int port, 
    bcm_vlan_control_port_t type, 
    int *arg);

/* Set/get miscellaneous port-specific VLAN options. */
extern int bcm_vlan_control_port_set(
    int unit, 
    int port, 
    bcm_vlan_control_port_t type, 
    int arg);

/* VLAN multicast flood modes. */
typedef enum bcm_vlan_mcast_flood_e {
    BCM_VLAN_MCAST_FLOOD_ALL = _SHR_PORT_MCAST_FLOOD_ALL, 
    BCM_VLAN_MCAST_FLOOD_UNKNOWN = _SHR_PORT_MCAST_FLOOD_UNKNOWN, 
    BCM_VLAN_MCAST_FLOOD_NONE = _SHR_PORT_MCAST_FLOOD_NONE, 
    BCM_VLAN_MCAST_FLOOD_COUNT = _SHR_PORT_MCAST_FLOOD_COUNT 
} bcm_vlan_mcast_flood_t;

#define BCM_VLAN_MCAST_FLOOD_STR \
{ \
    "MCAST_FLOOD_ALL", \
    "MCAST_FLOOD_UNKNOWN", \
    "MCAST_FLOOD_NONE", \
    ""  \
}

/* Set or retrieve the current vlan multicast flood behavior. */
extern int bcm_vlan_mcast_flood_get(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_vlan_mcast_flood_t *mode);

/* Set or retrieve the current vlan multicast flood behavior. */
extern int bcm_vlan_mcast_flood_set(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_vlan_mcast_flood_t mode);

/* Per VLAN forwarding behavior. */
typedef enum bcm_vlan_forward_e {
    bcmVlanForwardBridging,             /* Switching based on MAC and VLAN. */
    bcmVlanForwardSingleCrossConnect,   /* Switching based on outer VLAN. */
    bcmVlanForwardDoubleCrossConnect    /* Switching based on outer+inner VLAN. */
} bcm_vlan_forward_t;

#define BCM_VLAN_LEARN_DISABLE              0x00000001 
#define BCM_VLAN_UNKNOWN_IP6_MCAST_TOCPU    0x00000002 
#define BCM_VLAN_UNKNOWN_IP4_MCAST_TOCPU    0x00000004 
#define BCM_VLAN_IP4_DISABLE                0x00000008 
#define BCM_VLAN_IP6_DISABLE                0x00000010 
#define BCM_VLAN_IP4_MCAST_DISABLE          0x00000020 
#define BCM_VLAN_IP6_MCAST_DISABLE          0x00000040 
#define BCM_VLAN_IP4_MCAST_L2_DISABLE       0x00000080 
#define BCM_VLAN_IP6_MCAST_L2_DISABLE       0x00000100 
#define BCM_VLAN_MPLS_DISABLE               0x00000200 
#define BCM_VLAN_COSQ_ENABLE                0x00000400 
#define BCM_VLAN_IGMP_SNOOP_DISABLE         0x00000800 
#define BCM_VLAN_PIM_SNOOP_DISABLE          0x00001000 
#define BCM_VLAN_USE_FABRIC_DISTRIBUTION    0x00002000 
#define BCM_VLAN_ICMP_REDIRECT_TOCPU        0x00004000 

/* This structure contains the configuration of a VLAN. */
typedef struct bcm_vlan_control_vlan_s {
    bcm_vrf_t vrf; 
    bcm_vlan_t forwarding_vlan;         /* Shared VLAN ID. */
    uint16 outer_tpid; 
    uint32 flags; 
    bcm_vlan_mcast_flood_t ip6_mcast_flood_mode; 
    bcm_vlan_mcast_flood_t ip4_mcast_flood_mode; 
    bcm_vlan_mcast_flood_t l2_mcast_flood_mode; 
    int if_class; 
    bcm_vlan_forward_t forwarding_mode; 
    bcm_cos_queue_t cosq; 
    bcm_fabric_distribution_t distribution_class; /* Fabric Distribution Class. */
} bcm_vlan_control_vlan_t;

/* Initialize the bcm_vlan_control_vlan_t structure. */
extern void bcm_vlan_control_vlan_t_init(
    bcm_vlan_control_vlan_t *data);

/* Set or retrieve current vlan properties. */
extern int bcm_vlan_control_vlan_get(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_vlan_control_vlan_t *control);

/* Set or retrieve current vlan properties. */
extern int bcm_vlan_control_vlan_set(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_vlan_control_vlan_t control);

/* Initialize a VLAN data information structure. */
extern void bcm_vlan_data_t_init(
    bcm_vlan_data_t *vlan_data);

/* bcm_vlan_cross_connect_add */
extern int bcm_vlan_cross_connect_add(
    int unit, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_gport_t port_1, 
    bcm_gport_t port_2);

/* bcm_vlan_cross_connect_delete */
extern int bcm_vlan_cross_connect_delete(
    int unit, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan);

/* bcm_vlan_cross_connect_delete_all */
extern int bcm_vlan_cross_connect_delete_all(
    int unit);

/* bcm_vlan_cross_connect_traverse_cb */
typedef int (*bcm_vlan_cross_connect_traverse_cb)(
    int unit, 
    bcm_vlan_t outer_vlan, 
    bcm_vlan_t inner_vlan, 
    bcm_gport_t port_1, 
    bcm_gport_t port_2, 
    void *user_data);

/* bcm_vlan_cross_connect_traverse */
extern int bcm_vlan_cross_connect_traverse(
    int unit, 
    bcm_vlan_cross_connect_traverse_cb cb, 
    void *user_data);

/* Types of statistics that are maintained per VLAN. */
typedef enum bcm_vlan_stat_e {
    bcmVlanStatPackets,                 /* Packets that have hit the VLAN
                                           (forward/drop, L2/L3,
                                           unicast/multicast/broadcast/flood) */
    bcmVlanStatBytes,                   /* Bytes that have hit the VLAN
                                           (forward/drop, L2/L3,
                                           unicast/multicast/broadcast/flood) */
    bcmVlanStatForwardedPackets,        /* Packets forwarded on the VLAN (L2/L3,
                                           unicast/multicast/broadcast/flood) */
    bcmVlanStatForwardedBytes,          /* Bytes forwarded on the VLAN (L2/L3,
                                           unicast/multicast/broadcast/flood) */
    bcmVlanStatDropPackets,             /* Packets dropped on the VLAN (L2/L3,
                                           unicast/multicast/broadcast/flood) */
    bcmVlanStatDropBytes,               /* Bytes dropped on the VLAN (L2/L3,
                                           unicast/multicast/broadcast/flood) */
    bcmVlanStatUnicastPackets,          /* L2 unicast packets forwarded on the
                                           VLAN */
    bcmVlanStatUnicastBytes,            /* L2 unicast bytes forwarded on the
                                           VLAN */
    bcmVlanStatUnicastDropPackets,      /* L2 unicast packets dropped on the
                                           VLAN */
    bcmVlanStatUnicastDropBytes,        /* L2 unicast bytes dropped on the VLAN */
    bcmVlanStatNonUnicastPackets,       /* L2 multicast packets forwarded on the
                                           VLAN */
    bcmVlanStatNonUnicastBytes,         /* L2 multicast bytes forwarded on the
                                           VLAN */
    bcmVlanStatNonUnicastDropPackets,   /* L2 non-unicast packets dropped on the
                                           VLAN */
    bcmVlanStatNonUnicastDropBytes,     /* L2 non-unicast bytes dropped on the
                                           VLAN */
    bcmVlanStatL3Packets,               /* Packets delivered to L3 for
                                           forwarding on the VLAN */
    bcmVlanStatL3Bytes,                 /* Bytes delivered to L3 for forwarding
                                           on the VLAN */
    bcmVlanStatL3DropPackets,           /* Packets delivered to L3 for dropping
                                           on the VLAN */
    bcmVlanStatL3DropBytes,             /* Bytes delivered to L3 for dropping on
                                           the VLAN */
    bcmVlanStatFloodPackets,            /* L2 flood packets forwarded on the
                                           VLAN */
    bcmVlanStatFloodBytes,              /* L2 flood bytes forwarded on the VLAN */
    bcmVlanStatFloodDropPackets,        /* L2 flood packets dropped on the VLAN */
    bcmVlanStatFloodDropBytes,          /* L2 flood bytes dropped on the VLAN */
    bcmVlanStatGreenPackets,            /* Green packets forwarded on the VLAN */
    bcmVlanStatGreenBytes,              /* Green bytes forwarded on the VLAN */
    bcmVlanStatYellowPackets,           /* Yellow packets forwarded on the VLAN */
    bcmVlanStatYellowBytes,             /* Yellow bytes forwared on the VLAN */
    bcmVlanStatRedPackets,              /* Red packets forwarded on the VLAN */
    bcmVlanStatRedBytes,                /* Red bytes forwarded on the VLAN */
    bcmVlanStatCount                    /* Always last. Not a usable value. */
} bcm_vlan_stat_t;

/* Extract per-VLAN statistics from the chip. */
extern int bcm_vlan_stat_get(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_cos_t cos, 
    bcm_vlan_stat_t stat, 
    uint64 *val);

/* Extract per-VLAN statistics from the chip. */
extern int bcm_vlan_stat_get32(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_cos_t cos, 
    bcm_vlan_stat_t stat, 
    uint32 *val);

/* 
 * Set the specified statistic to the indicated value for the specified
 * VLAN.
 */
extern int bcm_vlan_stat_set(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_cos_t cos, 
    bcm_vlan_stat_t stat, 
    uint64 val);

/* 
 * Set the specified statistic to the indicated value for the specified
 * VLAN.
 */
extern int bcm_vlan_stat_set32(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_cos_t cos, 
    bcm_vlan_stat_t stat, 
    uint32 val);

/* Enable/disable collection of statistics on the indicated VLAN. */
extern int bcm_vlan_stat_enable_set(
    int unit, 
    bcm_vlan_t vlan, 
    int enable);

/* Retrieve the Policer ID accociated with the specified VLAN. */
extern int bcm_vlan_policer_get(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_policer_t *policer_id);

/* Set the Policer ID accociated with the specified VLAN. */
extern int bcm_vlan_policer_set(
    int unit, 
    bcm_vlan_t vlan, 
    bcm_policer_t policer_id);

/* Flags for logical layer 2 port. */
#define BCM_VLAN_PORT_REPLACE               0x00000001 /* Replace existing
                                                          entry. */
#define BCM_VLAN_PORT_WITH_ID               0x00000002 /* Add using the
                                                          specified ID. */
#define BCM_VLAN_PORT_INNER_VLAN_PRESERVE   0x00000004 /* Preserve the inner
                                                          VLAN tag (by default
                                                          it is stripped). */
#define BCM_VLAN_PORT_EGRESS_UNTAGGED       0x00000008 

/* Logical layer 2 port match criteria */
typedef enum bcm_vlan_port_match_e {
    BCM_VLAN_PORT_MATCH_INVALID,        /* Illegal. */
    BCM_VLAN_PORT_MATCH_NONE,           /* No source match criteria. */
    BCM_VLAN_PORT_MATCH_PORT,           /* {Module, Port} or Trunk. */
    BCM_VLAN_PORT_MATCH_PORT_VLAN,      /* Mod/port/trunk + outer VLAN. */
    BCM_VLAN_PORT_MATCH_PORT_VLAN_STACKED, /* Mod/port/trunk + outer/inner VLAN. */
    BCM_VLAN_PORT_MATCH_COUNT           /* Must be last. */
} bcm_vlan_port_match_t;

/* Layer 2 Logical port type */
typedef struct bcm_vlan_port_s {
    bcm_vlan_port_match_t criteria; /* Match criteria. */
    uint32 flags;                   /* BCM_VLAN_PORT_xxx. */
    bcm_vlan_t vsi;                 /* Populated for bcm_vlan_port_get only */
    bcm_vlan_t match_vlan;          /* Outer VLAN ID to match. */
    bcm_vlan_t match_inner_vlan;    /* Inner VLAN ID to match. */
    bcm_port_t phys_port;           /* Physical port. */
    bcm_vlan_t egress_vlan;         /* Egress Outer VLAN. */
    bcm_vlan_t egress_inner_vlan;   /* Egress Inner VLAN. */
    bcm_if_t encap_id;              /* Encapsulation Index. */
    bcm_policer_t policer_id;       /* Policer ID */
    bcm_vlan_t untagged_vlan;       /* Egress default VLAN. */
    uint8 untagged_pkt_prio;        /* Egress default priority value. */
} bcm_vlan_port_t;

/* Create a layer 2 logical port. */
extern int bcm_vlan_port_create(
    int unit, 
    uint32 flags, 
    bcm_vlan_port_t vlan_port, 
    bcm_gport_t *gport);

/* Destroy a layer 2 logical port. */
extern int bcm_vlan_port_destroy(
    int unit, 
    bcm_gport_t gport);

#endif /* __BCM_VLAN_H__ */
